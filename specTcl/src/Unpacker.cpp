/*************************************************************************** 
   COMPACT SpecTcl . BCS Standalone version for experiments 03034 & 05028
   Eventprocessor --> UNPACKER
   
   J.Pereira. Last version 8/29/2005
   mod FM & LK 31/10/2005
   mod JPC 11/11/2005 (11:00AM)
***************************************************************************/

/* Translater pointer is included to translate data buffer 
   representation used by the daq system to the internal 
   representation used by the hostsystem */

/*
  PACKET STRUCTURE in [ 16 | 16 ] = 32 bit words: 
 ------------------------------------------------
 |  Total number of words in event-buffer       |
 |             Self-Inclusive                   |
 ------------------------------------------------
 |  Total number of words in sub-event-packet   |
 |            (Beta End-station)                |
 |             Self-Inclusive                   |
 ------------------------------------------------
 |        Packet Identifier (0x7100)            |  
 ------------------------------------------------
 |  Bit register 1     |    Bit register 2      |
 ------------------------------------------------
 |  Clock signal 1     |    Clock signal 2      |
 ------------------------------------------------
 |         ADC Header 2 words (PIN'S and Ge)    |
 ------------------------------------------------
 |       Data 2 words x hit channels            |
 ------------------------------------------------
 |                   EOB 2 words                |
 ------------------------------------------------
 |       TDC Header 2 words (PIN'S and Ge)      |
 ------------------------------------------------
 |       Data 2 words x hit channels            |
 ------------------------------------------------
 |  ADC 8 words Header (PIN's, Ge, Sci)         |
 ------------------------------------------------
 |       Data 2 words x hit channels            |
 ------------------------------------------------
 |                   EOB 2 words                |
 ------------------------------------------------
 |  ADC 1 words Header (DSSD F01-16 high-low)   |
 ------------------------------------------------
 |       Data 2 words x hit channels            |
 ------------------------------------------------
 |                   EOB 2 words                |
 ------------------------------------------------
 |  ADC 2 words Header (DSSD F17-32 High-low)   |
 ------------------------------------------------
 |       Data 2 words x hit channels            |
 ------------------------------------------------
 |                   EOB 2 words                |
 ------------------------------------------------
 |  ADC 3 words Header (DSSD F33-40 High-low)   |
 ------------------------------------------------
 |       Data 2 words x hit channels            |
 ------------------------------------------------
 |                   EOB 2 words                |
 ------------------------------------------------
 |  ADC 4 words Header (DSSD B01-16 high-low)   |
 ------------------------------------------------
 |       Data 2 words x hit channels            |
 ------------------------------------------------
 |                   EOB 2 words                |
 ------------------------------------------------
 |  ADC 5 words Header (DSSD B17-32 High-low)   |
 ------------------------------------------------
 |       Data 2 words x hit channels            |
 ------------------------------------------------
 |                   EOB 2 words                |
 ------------------------------------------------
 |  ADC 6 words Header (DSSD B33-40 High-low)   |
 ------------------------------------------------
 |       Data 2 words x hit channels            |
 ------------------------------------------------
 |                   EOB 2 words                |
 ------------------------------------------------
 |         ADC 7 words Header (SSSD1)           |
 ------------------------------------------------
 |       Data 2 words x hit channels            |
 ------------------------------------------------
 |                   EOB 2 words                |
 ------------------------------------------------
 |               SeGA1 TDC 12-bit               |
 ------------------------------------------------
 |               SeGA1 ADC 13-bit               |
 ------------------------------------------------
 |               SeGA2 TDC 12-bit               |
 ------------------------------------------------
 |               SeGA2 ADC 13-bit               |
 ------------------------------------------------
 |               SeGA3 TDC 12-bit               |
 ------------------------------------------------
 |               SeGA3 ADC 13-bit               |
 ------------------------------------------------


nodatamask (16-bit) tells which modules were NOT read:
|-|-|Sega3|Sega2|Sega1|SSSD1|ADC6|ADC5|ADC4|ADC3|ADC2|ADC1|-|-|TDC1|ADC7|

betabit (16 bit) tells which of the modules have data:
|SeGA3|SeGA2|SeGA1|Pin4|Pin3|Pin2|Pin1|Pin0|N3Scint|SSSD1=ADC 7|ADC6|ADC5|ADC4|ADC3|ADC2|ADC1|
*/



#include <config.h>
#include <Event.h> 
#include "Parameters.h"
#include "Unpacker.h" 
//#include "EventProcessor.h"
//#include "TCLAnalyzer.h"

#ifdef HAVE_STD_NAMESPACE
using namespace std;
#endif

#define BDECAY_PACKET 0x7100
#define NERO_PACKET 0x5100
#define BdecayID BDECAY_PACKET
#define NEROID NERO_PACKET
#define ERROR_CHAN 0


Bool_t
CBDecayUnpacker::operator()(const Address_t pEvent,
			    CEvent&         rEvent,
			    CAnalyzer&      rAnalyzer,
			    CBufferDecoder& rDecoder)
{
  //cout << "Start of Unpacker";

  /* Translates pointer pEvent pointing to raw data pEvent into pointer p */
  TranslatorPointer<UShort_t> p(*(rDecoder.getBufferTranslator()), pEvent);
  CTclAnalyzer&      rAna((CTclAnalyzer&)rAnalyzer);

  UShort_t  nWords = *p++; // Word counter
  rAna.SetEventSize(nWords*sizeof(UShort_t)); // Set event size
  nWords--; //Already, we are past the event size

  /* Get parameter array from analyzer */
  /* Should only be present in one of the Event processors */
  CTreeParameter::setEvent(rEvent);
  
  while(nWords) 
    {
        
      //---------------//
      ////// NERO //////
      //-------------//
      
      UShort_t nPacketWordsNERO = *p; //Number of words in subevent
      UShort_t nIdNERO = p[1];  
      if (nIdNERO == NEROID) { // Unpack the NERO chunk of data correspoding to 
	//cout << "Unpacking nero\n";
	UnpackPacketNERO(p, rEvent); // NERO
      }
      
      p += nPacketWordsNERO; // Shift pointer nPacketWordsNERO words
      nWords -= nPacketWordsNERO; // Subtract nPacketWordsNERO to Words
      
      //cout << "\n nWords =" << nWords;
      
    }
  
  //cout << "\nEnd of Unpacker";
   
  return kfTRUE;

}


//////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
//// NERO UnPacking Function ////////////////////////////////
////////////////////////////////////////////////
////////////////////////////////////////////////////////////
//////////////////////////////////////////////////


void
CBDecayUnpacker::UnpackPacketNERO(TranslatorPointer<UShort_t> pEvent,CEvent& rEvent)
{ 
  UShort_t  nWordsNERO= *pEvent;
  UShort_t  nWords2;
  UShort_t  endofevent;
  UShort_t myword;
  UShort_t flag;
  UShort_t Nero_readout;

  int check;

  /* Counter variables */
  int i,j,k,index,vmenwds;
  UInt_t channel;
  UInt_t uflow;
  UInt_t oflow;

  /* Data check variables */
  UInt_t nodata;
  UInt_t nodatamask=0;

  long bitregA = 0;
  long bitregB = 0;
  long bitregC = 0;
  long bitregD = 0;

  /*get parameter array from analyzer*/
  CTreeParameter::setEvent(rEvent);

  //cout << "Begin NERO unpacker" <<endl;
  //printf("Begin NERO Calibrator\n");
  
  pEvent++;          // Escape word with the number of words in subevent 
  nWordsNERO--;		    
   
 
  cout << "\n NEROpacketID =" << *pEvent;
  //sleep(2);

  pEvent++;        //Escape word with NERO packet ID
  nWordsNERO--;

  /*---------Main condition to check if NERO Readout was activated ------------------------*/
  Nero_readout = ((Int_t)*pEvent);
  //  if ( (Nero_readout != 0) && (nWordsNERO !=1) ) { 
  if ( (nWordsNERO !=1) ) { 


    /* START UNPACKING PROCESS */
    
    // Read from VME-ADC 1    (Quadrant A and B) ------------------------------------------------------------
        
    nodata = ((Int_t)*pEvent);
    pEvent++; 
    nWordsNERO--;
    
    
    
    
    // Check for valid ADC data 
    
    if ((nodata&512) != 0 && (nWordsNERO!= 1) && (*pEvent != 0xFFFF) )
      {
	//cout << "ADC1 reading" << endl;
	vmenwds = ((Int_t)(*pEvent>>8)&63);pEvent++; // Number of data words taken from bits 8-13 
	nWordsNERO--;
	
	for (j=0; j<vmenwds; j++)          // Unpack event block 
	  { 
	    channel = ((Int_t)*pEvent&63);pEvent++;
	    nWordsNERO--;
	    
	    uflow = ((Int_t)*pEvent&(1<<13));
	    oflow = ((Int_t)*pEvent&(1<<12));
	    
	    if ((uflow == 0) && (oflow == 0)) { 
	      if ( channel < 16 ) {
		index = channel;
		nero.quadrantA[index].energy = (*pEvent&4095);pEvent++;
		nWordsNERO--;
	      }
	      else if ( (channel >= 16) && (channel <= 31) ){
		index = channel - 16;
		nero.quadrantB[index].energy = (*pEvent&4095);pEvent++;
		nWordsNERO--;
	      }
	      else {
		pEvent++;
	      }
	    }
	  }
	pEvent += 2; // Skip 32-bit EOB word of event block 
	nWordsNERO--;
	nWordsNERO--;
	
	if (*pEvent == 0xFFFF){
	  nodatamask += 2;       //Error processing event. --> nodatamask bit 2
	}
      }
    else nodatamask +=1;    //ADC1 was nor read --> nodatamask bit 1
    
    
    
    // Read from VME-ADC 2    (Quadrant C and D) --------------------------------------------------------------
    
    nodata = ((Int_t)*pEvent);pEvent++; // Check for valid ADC data 
    nWordsNERO--;
    
    if ((nodata&512) != 0 && (nWordsNERO!= 1) && (*pEvent != 0xFFFF) )
      {
	//cout << "ADC2 reading" << endl;
	vmenwds = ((Int_t)(*pEvent>>8)&63);pEvent++; // Number of data words taken from bits 8-13 
	nWordsNERO--;
//	cout << "mem. Channels= "<<vmenwds<<endl;
	for (j=0; j<vmenwds; j++)          // Unpack event block 
	  {
	    channel = ((Int_t)*pEvent&63);pEvent++;
	    nWordsNERO--;
	    //	cout << "input in Channels= "<<channel<<endl;
	    uflow = ((Int_t)*pEvent&(1<<13));
	    oflow = ((Int_t)*pEvent&(1<<12));
	    
	    if ((uflow == 0) && (oflow == 0)) { 
	      if ( channel < 16 ) {
//      cout << channel << "\n" << coinRegQuadC[channel] << "\n"; 
		index = channel;
		nero.quadrantC[index].energy = (*pEvent&4095);pEvent++;
		nWordsNERO--;
	      }
	      else if ( (channel >= 16) && (channel <= 31) ){
		index = channel - 16;
		nero.quadrantD[index].energy = (*pEvent&4095);pEvent++;
		nWordsNERO--;
	      }
	      else {
		pEvent++;
	      }
	    }
	  }
	pEvent += 2; // Skip 32-bit EOB word of event block 
	nWordsNERO--;
	nWordsNERO--;
	
	if (*pEvent == 0xFFFF){
	  nodatamask =+ 8;    // Error processing event. --> nodatamask bit 4
	}
      }
    else nodatamask +=4;   //ADC2 was not read --> notadamask bit 3

        
    
    /*   TDC */  
    
    UInt_t TDC1slot = (Int_t)(*pEvent>>11); // top bits of header word from TDC
    UInt_t TDCcontrolbit = (Int_t)(*pEvent>>5)&3; //look for header bit
    // TDC controlbit:
    // 10 header
    // 00 data
    // 01 EOB
    // 11 not valid
    
    if ((nWordsNERO!= 1) && (*pEvent != 0xFFFF) && (TDCcontrolbit == 2)) {
      //cout << "TDC reading step0" << endl;
      
      nero.coincregister.multiplicity = 0;
      
      if (TDC1slot != 20) { //check to see if data from expected TDC
	nodatamask += 2048; // TDC in wrong position -->nodatamask bit 11
	printf("Error processing event. TDC in the WRONG POSITION!!! \n");
      } 
      
      pEvent++;  
      nWordsNERO--;
      
      UInt_t TDCeventnum = (Int_t)(*pEvent&4095); //getting event number from bottom bits of TDC header    
      
      pEvent++;
      nWordsNERO--;
      
      long starthighbits;
      long startlowbits;
      UInt_t startcheck;
      long starttime;
      UInt_t channel;
      long timehighbits;
      long timelowbits;
      long TDC1time[64];
      UInt_t TDCwordcount = 0;
      UInt_t headerbit = 0;
      int schannel;
      
      for (int i=0; i<=64; i++) {
	TDC1time[i] = 0;
      }
      
      /* For start gating mode first set of 16 bit data words corresponds to 
	 start time */
      
      TDCcontrolbit = (Int_t)(*pEvent>>5)&3;  //read controlbits 
      
      if (TDCcontrolbit == 0) {
	
	startcheck = ((Int_t)(*pEvent>>7)&1); //look for start bit
	
	if (startcheck ==1) {
	  
	  schannel = ((Int_t)(*pEvent>>8)&127);
	  
	  starthighbits = ((Int_t)*pEvent&15); //4 top bits of time measurement
	  pEvent++;
	  nWordsNERO--;
	  
	  startlowbits = ((Int_t)*pEvent); //bottom bits of time measurement 
	  pEvent++;
	  nWordsNERO--;
	  
	  TDCwordcount++;
	  starttime = (starthighbits<<16 | startlowbits); //adding top and bottom halfs of start time data word
	}
	else {
	  nodatamask =+ 128;   // no TDC start found --> nodatamask bit 8
	  TDCwordcount++;
	  pEvent++; 
	  pEvent++;
	  nWordsNERO-= 2;
	}
      }
      
      TDCcontrolbit = ((Int_t)(*pEvent>>5)&3); // read controlbits
      
      while (TDCcontrolbit == 0) { //now process data words
	channel = ((Int_t)(*pEvent>>8)&127); //channel # is bits 9 - 15 
	
	if ((channel <=63)) {
	  
	  timehighbits = ((Int_t)*pEvent&15); //4 top bits of time measurement
	  pEvent++;
	  //printf("Next Word of TDC event: 0x%x\n", *pEvent);
	  nWordsNERO--;
	  
	  timelowbits = ((Int_t)*pEvent); //bottom bits of time measurement
	  
	  pEvent++;
	  nWordsNERO--;
	  TDCwordcount++;	
	  
	  TDC1time[channel] = (timehighbits<<16 | timelowbits); //adding top and bottom halfs of time data word
	  nero.coincregister.multiplicity++;

	  //cout << "TDC reading" << endl;

	  // New feature: exclude 1's and overflows from multiplicity counter 
	  //if( TDC1time[channel] > 256. && TDC1time[channel] < 512000. ) {
	  //printf("Time in window: %ld \n",  TDC1time[channel] );
	  //}
	}
	else {
	  nodatamask += 256; //Invalid data from Nero TDC CHANNEL > 64 --> nerodatamask bit 9
	  pEvent++;
	  pEvent++;
	  nWordsNERO-= 2;
	  TDCwordcount++;	
	}
	TDCcontrolbit = ((Int_t)(*pEvent>>5)&3);
      }
      
      if (TDCcontrolbit == 1){
	UInt_t status = ((Int_t)(*pEvent>>8)&7);
	
	if (status != 0) {
	  nodatamask =+ 512; // Nero TDC EOB shows Nero TDC error --> nerodatamask bit 10
	  
	}
	
	
	pEvent++;
	nWordsNERO--;
	
	UInt_t TDCdatacount = ((Int_t)*pEvent);
	
	if (TDCdatacount != TDCwordcount){
	  nodatamask += 1024; // Nero TDC Data Counter does not match Words processed! --> nodatamask bit 11
	}
	
	pEvent++;  
	nWordsNERO--;
      }
      
      // Fill in spectra 
      
      for (int i=0; i<=15; i++) {      
	if (TDC1time[i] != 0){
	  nero.quadrantA[i].time = TDC1time[i];
	  bitregA = bitregA | (1<<i);
	}
	
	if (TDC1time[i+16] != 0){
	  nero.quadrantB[i].time = TDC1time[i+16];
	  bitregB = bitregB | (1<<i);
	}
	
	if (TDC1time[i+32] != 0) {
	  nero.quadrantC[i].time = TDC1time[i+32];
	  bitregC = bitregC | (1<<i);
	}
	
	if (TDC1time[i+48] != 0) {
	  nero.quadrantD[i].time = TDC1time[i+48];
	  bitregD = bitregD | (1<<i);
	}
      }
      
      nero.coincregister.quadAhitpattern = bitregA;
      nero.coincregister.quadBhitpattern = bitregB;
      nero.coincregister.quadChitpattern = bitregC;
      nero.coincregister.quadDhitpattern = bitregD;
      
    }
    else nodatamask += 16;    // TDC was not read --> nerodatamask bit 5
    
    
    //if ((nWordsNERO!= 1) && (*pEvent != 0xFFFF)){
    //  nodatamask += 32;//Error processing event, found data after TDC  --> nerodatamask bit 6
    //}
    
    //if ((nWordsNERO== 1) && (*pEvent == 0xFFFF)){
    //  nodatamask += 64;        //End of event encountered   --> nerodatamask bit 7
    //  pEvent++;
    //}
  

    nero.coincregister.nodatamask = nodatamask;





    // Read from QDC    (CRS)


    //    cout << "pointer1 = "<< *pEvent <<endl;


    nodata = ((Int_t)*pEvent);pEvent++; // Check for valid QDC data 
    nWordsNERO--;

    //    cout << "pointer2 = "<< *pEvent <<endl;

  
    if ((nodata&512) != 0 && (nWordsNERO!= 1) && (*pEvent != 0xFFFF) )
      {
	vmenwds = ((Int_t)(*pEvent>>8)&63);pEvent++; // Number of data words taken from bits 8-13 
	nWordsNERO--;
	//	cout << "-------mem. Channels= "<<vmenwds<<endl;

   	for (j=0; j<vmenwds; j++)          // Unpack event block 
	  {
	    channel = ((Int_t)*pEvent&63);pEvent++;
	    nWordsNERO--;
	    
	    uflow = ((Int_t)*pEvent&(1<<13));
	    oflow = ((Int_t)*pEvent&(1<<12));
	    
	    if ((uflow == 0) && (oflow == 0)) { 
	      if ( channel < 32 ) {
		index = channel;
		crs.qdc[index].energy = (*pEvent&4095);pEvent++;
		nWordsNERO--;

		//cout << "QDC data read" << endl;


		//		cout << "write to variable ch= "<<channel<<endl;
	      }
	      else {
		pEvent++;
	      }
	    }
	  }
	pEvent += 2; // Skip 32-bit EOB word of event block 
	nWordsNERO--;
	nWordsNERO--;
	
	if (*pEvent == 0xFFFF){
	  nodatamask =+ 8;    // Error processing event. --> nodatamask bit 4
	}
      }
    else nodatamask +=4;   //QDC was not read --> notadamask bit 3







  }
  //cout << "End NERO unpacker" <<endl;
  //printf("End NERO Calibrator\n");


}  
  


