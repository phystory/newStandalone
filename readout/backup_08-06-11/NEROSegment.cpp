/*************************************************************************** 
   Readout program for NERO
   Program includes:
    - Updated Production Readout Software (version nscldaq8.0/g++3.3)
    - 1 Wienner VC32 CAMAC Controllers (for DSSD, SSSD and SeGA)
    - VME Crate (number 0)
    - CAMAC Crate (number 1)

   J.Pereira G.Lorusso  Last version 1/26/2006
***************************************************************************/

/*
  Description of the setup (26 January 2006):
  -----------------------------------------------------

  CAMAC NERO:
  Branch 1, crate 2 (NERO):
   1: DD002 dataway display
   2: Pico Systems 16-ch. shaper NERO Quadr A
   3: Pico Systems 16-ch. discriminator (double-wide with slot 2)
   4: Pico Systems 16-ch. shaper NERO Quadr B
   5: Pico Systems 16-ch. discriminator (double-wide with slot 4)
   6: Pico Systems 16-ch. shaper NERO Quadr C
   7: Pico Systems 16-ch. discriminator (double-wide with slot 6)
   8: Pico Systems 16-ch. shaper NERO Quadr D
   9: Pico Systems 16-ch. discriminator (double-wide with slot 8)
  10: EMPTY 
  12: EMPTY 
  13: EMPTY 
  14: EMPTY 
  15: EMPTY 
  16: EMPTY 
  17: EMPTY 
  18: EMPTY 
  19: EMPTY 
  20: EMPTY 
  21: EMPTY 
  22: EMPTY 
  23: EMPTY 
  24: Wienner CC32 highway controller
  25: Wienner CC32 highway controller (double-wide with slot 24)

  VME NERO:
  Branch 0, crate 1 (ADC and TDC readout):
   1: SBC/Bit3 interface
   2: SIS3820 32-ch. Scaler -- QUAD A & B
   3: SIS3820 32-ch. Scaler -- QUAD C & C
   4: EMPTY
   5: EMPTY
   6: CAEN V767 VME 64-ch  TDC -- QUAD A, B, C, D
   7: EMPTY 
   8: EMPTY 
   9: CAEN V785 VME 32-ch. ADC -- QUAD A & B
  10: CAEN V785 VME 32-ch. ADC -- QUAD C & D
  11: EMPTY
  12: EMPTY
  13: EMPTY
  14: CAEN V792 VME 32-ch. QDC -- Cosmic Ray Shield Scintillators CRS
  15: EMPTY
  16: EMPTY
  17: EMPTY 
  18: EMPTY 
  19: EMPTY 
  20: EMPTY 
  21: Wienner VC32 VME-CAMAC controller

*/


#include <config.h>
#ifdef HAVE_STD_NAMESPACE
using namespace std;
#endif


#ifndef __NEROSEGMENT_H
#include "NEROSegment.h"
#endif

#define NEROPACKET 0x5100

/* Define location of VME ADCs */
#define VMEADC09_N 9  /* NERO Quad A & B */
#define VMEADC10_N 10 /* NERO Quad C & D */

/*Define location of VME TDC */
#define VMETDC02_N 20 /* NERO TDC */

/*Define location of VME QDC */
#define VMEQDC12 0x0c000000   /*CRS QDC base address*/
#define VMEQDC12_N 12         /*slot number of QDC*/

/* Define base address of General Purpose IO Register (CaenIO.h)*/
#define BASEVMEIO 0x444400 


/* Define maximun readout time of VME modules*/
#define CAENTIMEOUT 100

/* Define VME Crate number */
#define CRATENUM1 0

/* INCLUDE FILES */
/* The following include files were copied from the traditional Readout Software */

#include <string>

#include <stdio.h>

#include <Nimout.h>

#ifndef __unix__
#include "cpus.h"
#endif

#ifdef __unix__
#include <stdlib.h>
#include <daqinterface.h>
#include <spectrodaq.h>
#endif

#include <daqdatatypes.h>
#include <camac.h>
#include <macros.h>

#include "param.h"

#ifdef VME16
#undef VME16
#endif
#if CPU == MICROPROJECT
#define VME16 0	
#endif

#ifndef __unix__
#include <vme.h>
#endif
#include <buftypes.h>

/* Short circuit run time evaluation of constant BCNAF's */

#ifdef __unix__
#include <camac.h>
#else
#if CPU == IRONICS
#undef CAMBAS
#define CAMBAS(b)	0xFA800000
#endif

#if CPU == MICROPROJECT
#undef CAMBAS
#define CAMBAS(b)	0xFE800000
#endif
#endif



///* Declare functions to initialize PicoSystems 16-ch. shaper/CFD modules
//   (Marc-Jan van Goethem) */
int initwushapers_nero();
int initwucfds_nero();

/* Declare initialization variables */
int ADC09_thresh;
int ADC10_thresh;
int Readout_NERO;

static char* pPacketVersion="1.0";  // Version of the packet.


/*
  Constructor:  Initialize the documented packet.
*/
NEROSegment::NEROSegment()  :
  m_NEROPacket(NEROPACKET, 
		 string("NEROPacket"),
		 string("NERO VME-CAMAC packet"),
		 string(pPacketVersion)
		 ),
    m_pVMEADC09(0),
    m_pVMEADC10(0),
  m_pVMETDC02(0),
  m_pIOREGISTER(0),
  m_pVMEQDC12(0)   //CRS
    
{
}

void NEROSegment::Initialize()
{

  cout << "Initializing NERO" << endl;

    delete m_pVMEADC09; //NERO
    delete m_pVMEADC10;
    delete m_pVMETDC02;
    
    delete m_pIOREGISTER; //GENERAL
    
    cout << "Initializing CRS" << endl;
    delete m_pVMEQDC12;
 
  cout << "Building CAENCARD objects" << endl;

    m_pVMEADC09 = new CAENcard(VMEADC09_N, CRATENUM1); //NERO
    m_pVMEADC10 = new CAENcard(VMEADC10_N, CRATENUM1);
    m_pVMETDC02 = new CAENcard_767(VMETDC02_N, CRATENUM1);
    m_pIOREGISTER = new CCaenIO(BASEVMEIO, CRATENUM1);
    m_pVMEQDC12 = new CAENcard(VMEQDC12_N, CRATENUM1, false, VMEQDC12); //CRS
   

  /*read Tcl variables with ADC thresholds */
  /* Check DAQ initialization file */
  if (Param_readFile("nerodaqini.tcl") != 0) {
    fprintf(stdout, "Error while reading DAQ initilization file\n");
  }

  /* INITIALIZE GENERAL-PURPOSE MODULES */
  Readout_NERO = int(Param_getVal("Readout","NERO"));
  fprintf(stdout, "NERO Readout Status: %d\n", Readout_NERO);   
					  
   
 
    ///* Initialize Branch and CAMAC Crates */
    branchinit(2);
    crateinit(3,3); 
    

    /* Initialize PicoSystems (aka Wash. U.) shaper/CFD's */
    //cout << "Setting gains and thresholds FOR PicoSytem MODULES " << endl;
    initwushapers_nero();
    initwucfds_nero();
    
    /* Initialize CAEN V262 I/O Register */
    m_pIOREGISTER -> ClearAll();
    
    /* Initialize CAEN V785 ADC8 */
          ADC09_thresh = int(Param_getVal("ADC09", "thresh"));
      fprintf(stdout, "ADC09 threshold: %d\n", ADC09_thresh);
    
        m_pVMEADC09->clearData();
        m_pVMEADC09->resetEventCounter();
        m_pVMEADC09->discardUnderThresholdData();
        m_pVMEADC09->keepOverflowData();//I'M KEEPING NOW THE OVERFLOW BUT CHECK LATER
        m_pVMEADC09->setThreshold(-1, ADC09_thresh);// Threshold into all channels 
    
    /* Initialize CAEN V785 ADC9 */
        ADC10_thresh = int(Param_getVal("ADC10", "thresh"));
        fprintf(stdout, "ADC10 threshold: %d\n", ADC10_thresh);
    
       m_pVMEADC10->clearData();
        m_pVMEADC10->resetEventCounter();
        m_pVMEADC10->discardUnderThresholdData();
        m_pVMEADC10->keepOverflowData(); //I'M KEEPING NOW THE OVERFLOW BUT CHECK LATER
    //    m_pVMEADC10->setThreshold(-1, ADC10_thresh);// Threshold into all channels 

    /* Initialize CAEN V792 QDC12 CRS*/
	m_pVMEQDC12->clearData();
	m_pVMEQDC12->reset();

    

  /* Initialize NERO modules */
  if(Readout_NERO) {  
    cout << "Initialize NERO Modules " << endl;


    /*Initialize CAEN V767A TDC */
    sleep(2);
    m_pVMETDC02->clearData();
    sleep(3);
    m_pVMETDC02->tempSetup();

  }
}



void NEROSegment::Clear()
{ 
  if (Readout_NERO) {
        m_pVMEADC09->clearData(); /* Clear CAEN V785 ADC1 */
        m_pVMEADC10->clearData(); /* Clear CAEN V785 ADC2 */
    m_pVMETDC02->clearData(); /* Clear CAEN V767 TDC */
    m_pIOREGISTER->ClearAll(); /* Clear CAEN V262 I/O*/
    m_pVMEQDC12->clearData(); /* Clear CAEN V792 QDC for CRS */
  }
}



unsigned int NEROSegment::MaxSize()
{
 /* Define the size, in words, of the largest possible physics event */
  return 1000;
  }    							      


DAQWordBufferPtr& NEROSegment::Read(DAQWordBufferPtr& rBuf)
{

  int i,j; // Counter index 
  int nodata = 0;
  long betabit; // Beta-decay bit register 
  bool datapresent = false; // "Data present" flag on ADC and TDC readout 
  int NeroTimeout=0;
  int Nerodata=0;
  int ADCdata=0;
  int QDCdata=0;
     

  /* Defining the Event-structure **********************************/
  /* 
     Number of words              --> 16 bits (1word)
     Equipment ID (0x5100)        --> 16 bits (1 word )
     --------------------------------------------------------- READOUT OF NERO
     ADC for QUADA+QUADB          --> 32 bits (2 words) HEADER
                                  --> 32 bits (2 words) x hit channels
				  --> 32 bits (2 words) EOB
     .......................OR .. --> 16 bits (1 word ) no-data word
     ---------------------------------------------------------
     ADC for QUADC+QUADD          --> 32 bits (2 words) HEADER
                                  --> 32 bits (2 words) x hit channels
				  --> 32 bits (2 words) EOB
     .......................OR .. --> 16 bits (1 word ) no-data word
     ---------------------------------------------------------
     TDC multihit                 --> 32 bits (2 words) HEADER
                                  --> 32 bits (2 words) Start signal
                                  --> 32 bits (2 words) x stop signals channels
				  --> 32 bits (2 words) EOB

     .......................OR .. --> 16 bits (1 word ) no-data word
     --------------------------------------------------------- 
     QDC for CRS                  --> 32 bits (2 words) HEADER
                                  --> 32 bits (2 words) x hit channels
				  --> 32 bits (2 words) EOB end of block
     .......................OR .. --> 16 bits (1 word ) no-data word

  */ 
 /******************************************************************/



  /* Begin Packet */
  rBuf = m_NEROPacket.Begin(rBuf);

  /* Documented packet ID is included by default 0x7100 */
  if(Readout_NERO) {
    
    for (i=0; i<CAENTIMEOUT; i++) {
      Nerodata = m_pIOREGISTER -> ReadInput(1);
      if ( Nerodata != 0 ) { // Check that data is available 
	break;
      }
    }

    /*channel 1 shows if NERO data is present */
    if (Nerodata != 0) {
           
     //ADC09
            datapresent = false;
      for (i=0; i<CAENTIMEOUT; i++)
	{
	  if (m_pVMEADC09->dataPresent() != 0) // Check that data is available 
	    {
	      datapresent = true; // Set "data present" flag 
	      break;
	    }
	}
      if (datapresent) // Valid data present 
	{
	  m_pVMEADC09->readEvent(rBuf); // Read data to data stream 
	  ADCdata=1;
	}
      else
	{
	  *rBuf = nodata; ++rBuf; 
	}
         
      //ADC10
      
      datapresent = false; // Reset "data present" flag   
      for (i=0; i<CAENTIMEOUT; i++)
	{
	  if (m_pVMEADC10->dataPresent() != 0) // Check that data is available 
	    {
	      datapresent = true; // Set "data present" flag 
	      break;
	    }
	}
      if (datapresent) // Valid data present 
	{
	  m_pVMEADC10-> readEvent(rBuf); // Read data to data stream 
	  ADCdata=1;
	}
      else
	{
	  *rBuf = nodata; ++rBuf;
	}
      
      
      // ---------------------------------------------------------------------------------------
         
      // Why do you only check the Nero timeout condition for the TDC and not for the ADC's 
	// as well? (Jorge Pereira 10/31/2005) 
      NeroTimeout = m_pIOREGISTER -> ReadInput(2); //channel 2 shows time out has occured 
      for (i=1; i<=500; i++) {
	if (NeroTimeout == 0) {
	  NeroTimeout = m_pIOREGISTER -> ReadInput(2);
	}
	else {
	  break;
	}
      }
      
      if (NeroTimeout != 0) {
	
	// TDC 
	for (i=0; i<CAENTIMEOUT; i++)
	  {
	    int flag;
	    flag = m_pVMETDC02->dataPresent();
	    
	    if (m_pVMETDC02->dataPresent() != 0) //Check that data is available 
	      {
		datapresent = true; // Set "data present" flag 
		break;
	      }
	  }
	
	if (datapresent) { // Valid data present
	  m_pVMETDC02->readEvent(rBuf); // Read data to data stream 
	} else {
	  *rBuf = nodata; ++rBuf;
	  // In the event that there's no TDC data, we put a null word
	  // in the data stream in place of the TDC data.  In the event
	  // unpacker, we check bit nine of this word; if data has been
	  // written, this will be set to one (bit 25 of the 32-bit header
	  // word; see CAEN V775 TDC manual, page 36), and if it hasn't,
	  // it will be zero. 
	}
      } else { 
	cout << "Timeout condition not valid" << endl;
      }
      
  /* ------------------------START - buffer input for CRS--------------------*/
      
         

      datapresent = false; // Reset "data present" flag   
      for (i=0; i<CAENTIMEOUT; i++)
	{
	  if (m_pVMEQDC12->dataPresent() != 0) // Check that data is available 
	    {
	      datapresent = true; // Set "data present" flag 
	      break;
	    }
	}
      if (datapresent) // Valid data present 
	{
	  m_pVMEQDC12-> readEvent(rBuf); // Read data to data stream 
	  QDCdata=1;
	}
      else
	{
	  *rBuf = nodata; ++rBuf;
	}
    

  /* -------------------------END -- buffer input for CRS--------------------*/



    }

    *rBuf = nodata;++rBuf;

  }

  else{

    *rBuf = nodata;++rBuf;  






  }
  /* End Packet */
  rBuf = m_NEROPacket.End(rBuf);
  return rBuf;
}
  

