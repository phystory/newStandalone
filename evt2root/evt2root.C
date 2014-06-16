/*************************************************************************************************\
ROOT script: evt2root.C

Description: Takes .evt files from a list and converts them to ROOT format. There is only one
             output file named "output.root".  The list of evt files is "data_files.list" and its
             first line is the directory where all the data files are located.  This script also
             needs a library where the detectors classes are defined.

DSG = Comment from Daniel Santiago-Gonzalez

DSG: This script is a modified version of the "Read_NSCLDAQ_Online.cpp" code found in sand@anasen
     in the directory "/home/sand/daq/Online".

\*************************************************************************************************/


//C and C++ libraries
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

//ROOT libraries
#include <TFile.h>
#include <TTree.h>
#include <TROOT.h>
#include <TNtuple.h>
#include <TH1I.h>
#include <TGraph.h>
#include <TH2I.h>
#include <TH2F.h>
#include <TCanvas.h>
#include <TRint.h>
#include <TObjArray.h>


using namespace std;

//Detectors' libraries
#include "2011_detclass.h"


//DSG: I found more conveninet to separete all that is related to reading the physics
//     buffer in the function below.
void ReadPhysicsBuffer(int ItemSize);


// Global parameters
const int BufferWords = 13328;
const string files_list = "data_files.list";


// Global variables
TFile* fileR;
TTree* DataTree;
TObjArray* RootObjects;

float CalParamF[128][3];
float CalParamB[128][3];

TH1I* hE1[9][32];
TH1I* hT1[9][32];
TH1I* hE2[9][32];
TH1I* hT2[9][32];
TH1I* hCaenADC[5][32];
TH1I* hCaenADC_IC;
TH1I* hCaenTDC[5][32];
TH1I* HitPattern_MB1;
TH1I* HitPattern_MB2;

TH2I* ChanEn_MB1;
TH2I* ChanEn_MB2;
TH2I* ChanT_MB1;
TH2I* ChanT_MB2;

TH1I* CMonTot;
TH1I* CMonLive;
TGraph* EventRate;

int unsigned Nevents;
int unsigned TotEvents=0;
int unsigned words;  
unsigned short *point,*epoint, *cpoint;
int unsigned type,ZeroCheck,timeStamp,timeOffset;
string TitleStr;
char Run_Title[300];

Int_t EventCounter = 0;
int unsigned EOB_NEvents=0;
int unsigned MESY_EOB_NEvents=0;
int unsigned CAENCounter=0;
int unsigned MESYCounter=0;


//- Detectors' classes --------------------------------------------------------  

   ASICHit Si;
   CAENHit ADC;
   CAENHit TDC;
 
//- Main function -------------------------------------------------------------  
int evt2root(){

  gROOT->Reset();

  cout << "==============================================================================" <<endl;
  cout << "evt2root: Takes .evt files from a list and converts the data into ROOT format." <<endl;
  cout << "------------------------------------------------------------------------------" <<endl;



  unsigned short buffer[BufferWords];
  int unsigned type;
  int unsigned NItems = 0;
  int PhysicsItem = 0;
  int ScalerItem = 0;
  int runNum;

  string target;
  
  	  Int_t Start_time,End_time,Master_total,Master_live;
	  Int_t Master_Old,MasterLive_Old,minute_count;
	  Int_t MB1_TriggerB,MB1_TriggerC,MB2_TriggerB,MB2_TriggerC;
          Int_t Schannel[32];

          Master_Old=0;
          MasterLive_Old=0;
	  Master_total=0;
	  Master_live=0;
	  MB1_TriggerB=0;
	  MB1_TriggerC=0;
	  MB2_TriggerB=0;
	  MB2_TriggerC=0;
	  minute_count=0;
	  for (Int_t i=0; i<32; i++) {
		Schannel[i] = 0;
          }  

/*  
  int argc;
  char** argv;
 
  TRint intobj("intobj", &argc, argv);

  TDirectory* Hits = gDirectory->mkdir("Hits");
  TDirectory* MB1 = gDirectory->mkdir("MB1");
  TDirectory* MB2 = gDirectory->mkdir("MB2");
  TDirectory* CAEN = gDirectory->mkdir("CAEN");

*/

  ifstream ListEVT;
  
  string OutputROOTFile;
  string aux;
  char *ROOTFile; 

  ListEVT.open(files_list.c_str());
  if (!ListEVT.is_open()) {
    cout << "*** Error: could not open " << files_list << endl;
    return 0;
  }
  else{
    cout << "File " << files_list << " opened." <<endl;
    ListEVT >> aux >> aux >> aux >> OutputROOTFile;
  }

  //- ROOT objects' definitions -------------------------------------------------  

  // ROOT output file


  ROOTFile = new char [OutputROOTFile.size()+1];
  strcpy (ROOTFile, OutputROOTFile.c_str());

  fileR = new TFile(ROOTFile,"RECREATE");  
  fileR->SetTitle("Test");

  // Data Tree
  DataTree = new TTree("DataTree","DataTree");

  DataTree->Branch("Run_Title",Run_Title,"Run_Title/C");
  DataTree->Branch("Si.Nhits",&Si.Nhits,"SiNhits/I");

DataTree->Branch("Si.MBID",Si.MBID,"MBID[SiNhits]/I");
  DataTree->Branch("Si.CBID",Si.CBID,"CBID[SiNhits]/I");
  DataTree->Branch("Si.ChNum",Si.ChNum,"ChNum[SiNhits]/I");
  DataTree->Branch("Si.Energy",Si.Energy,"Energy[SiNhits]/I");
  DataTree->Branch("Si.Time",Si.Time,"Time[SiNhits]/I");

//We use this:
  DataTree->Branch("ADC.Nhits",&ADC.Nhits,"ADCNhits/I");
  DataTree->Branch("ADC.ID",ADC.ID,"ID[ADCNhits]/I");
  DataTree->Branch("ADC.ChNum",ADC.ChNum,"ChNum[ADCNhits]/I");
  DataTree->Branch("ADC.Data",ADC.Data,"Data[ADCNhits]/I");

  DataTree->Branch("TDC.Nhits",&TDC.Nhits,"TDCNhits/I");
  DataTree->Branch("TDC.ID",TDC.ID,"ID[TDCNhits]/I");
  DataTree->Branch("TDC.ChNum",TDC.ChNum,"ChNum[TDCNhits]/I");
  DataTree->Branch("TDC.Data",TDC.Data,"Data[TDCNhits]/I");
//we use above this
  
  // Histograms
  hCaenADC_IC = new TH1I("hCaenADC_IC","",4096,0,4096);
  HitPattern_MB1 = new TH1I("HitPattern_MB1","",288,0,288);
  HitPattern_MB2 = new TH1I("HitPattern_MB2","",288,0,288);
  ChanEn_MB1 = new TH2I("EnVsCh_MB1","",288,0,288,4096,0,16384);
  ChanEn_MB2 = new TH2I("EnVsCh_MB2","",288,0,288,4096,0,16384);
  ChanT_MB1 = new TH2I("TiVsCh_MB1","",288,0,288,4096,0,16384);
  ChanT_MB2 = new TH2I("TiVsCh_MB2","",288,0,288,4096,0,16384);
  
  CMonTot   = new TH1I("MonTot","",300,0,300);
  CMonLive  = new TH1I("MonLive","",300,0,300);

  const Int_t n = 86400;
  Int_t TOffset[n];
  Int_t EvtRate[n];


  //List of root objects.
  RootObjects = new TObjArray();
  RootObjects->Add(DataTree);
  RootObjects->Add(hCaenADC_IC);


  //Open file with list of evt files to sort.

  string data_dir = "";

  //Check if this file exists.
  if (!ListEVT.is_open()) {
    cout << "*** Error: could not open " << files_list << endl;
    return 0;
  }
  else{
   // cout << "File " << files_list << " opened." <<endl;
    ListEVT >> aux >> aux >> data_dir;
  }

  ifstream evtfile;
  bool fileProblem = 0;
  bool endOfRun = 0;
  cout << "Loop over evt files " <<endl; //debug

  int run_number;    
  int nChannels;
  int long PECounter;
  int oldOffset;
  int long oldPECounter;
  //char Run_Title[60];
  char *pTitle;
  Int_t PECItems = 0;
  Int_t MinTime=0;

  ListEVT >> run_number;


  //Loop over files in the data file list.
  while(!ListEVT.eof()){

    if (evtfile.is_open()) cout << "  * Problem previous file not closed!" << endl;

    endOfRun=0;
    fileProblem = 0;
    
    //string name = data_dir + "run" + run_number.str() + "-" + buffer_size.str() + ".evt";
    string name = data_dir + Form("run%d/run-%04d-00.evt",run_number,run_number);
    cout << "  Data file: " << name << endl;

    //open evt file
    evtfile.clear();
    evtfile.open(name.c_str(),ios::binary);      

    if (evtfile.bad()) cout << "  ** Bad evt file." << endl;
    if (evtfile.fail()) cout << "  ** Fail evt file" << endl;
    
    if (!evtfile) {
      cout << "  Could not open evt file" << endl;
      //return 1;
    }
    else {
      cout << "  Converting data ..." << endl;
    }
    


    // loop over buffers
     


    for (;;) {
      //DSG 2011-12-12: I don't get why here char* is used if buffer is of type short.
      evtfile.read((char*)buffer,8);
      if (!evtfile) {
	//this could be a bad file or the file
	// is subdivided into parts
	//fileProblem = 1;
	//cout << "  ** Warning: evt file problem" << endl;
	break;
      }
				
      cpoint = buffer;
      unsigned int ItemSize = *cpoint++;
      ItemSize += (*cpoint++)<<=16;
      type = *cpoint++;
      unsigned short ZeroCheck = *cpoint++;

      // cout << "buffer = " << buffer << endl; //debug

      //This is how many elements in the buffer (words) are useful (including this one).
//      int nWords = buffer[0];
      
      //From buffer[nWords-1] to buffer[4095] is junk data. From buffer[0-15] is the
      //header of the buffer. 

      if (ZeroCheck==0 && evtfile.read((char*)buffer,ItemSize-8)){	
      point = buffer;
      NItems++;
      if (NItems%30000 == 0) cout << "  Items read " << NItems << endl;
      epoint = point;
//      if (epoint<point+nWords) words = *epoint++;
      //cout<<"Words "<<words<<endl;
//      if (epoint<point+nWords) type = *epoint++;
      //cout<<"Type "<<type<<endl;


//      Nevents = *(point+6);
     // TotEvents += Nevents;
      
      
      switch(type){
      case 1: 
	// begin run buffer
        cout << "Begin run Item" << endl;
	runNum = *epoint++;
        runNum += (*epoint++)<<=16;
//	cout << "run number="<< runNum << endl;
        timeOffset = *epoint++;
        timeOffset += (*epoint++)<<=16;
        cout << "Time Offset: " << timeOffset << endl;
        timeStamp = *epoint++;
        timeStamp += (*epoint++)<<=16;
        cout << "Time Stamp: " << timeStamp << endl;

	
        for (Int_t i=0;i<60;i++) {
	     Run_Title[i] = ' ';
	}


        char *pTitle;
        pTitle = (char*)epoint;
        for (Int_t i=0;i<60;i++) {
	     Run_Title[i] = *(pTitle++);
             if (Run_Title[i]=='\0') break;
	}
	TitleStr.assign(Run_Title,Run_Title+60);
	cout << "Run number: " << runNum << endl;
	cout << "Run title: " << TitleStr << endl;
//        cout << "Start: "<< *(point+58)<<"/"<<*(point+59)<<"/"<<*(point+60)
//	     <<" at "<<*(point+61)<<":"<<*(point+62)<<":"<<*(point+63)<<endl;     
	break;

      case 2:
	cout << " End run Item" << endl;
	runNum = *epoint++;
        runNum += (*epoint++)<<=16;
//	cout << "run number="<< runNum << endl;
        timeOffset = *epoint++;
        timeOffset += (*epoint++)<<=16;
        cout << "Time Offset: " << timeOffset << endl;
        timeStamp = *epoint++;
        timeStamp += (*epoint++)<<=16;
        cout << "Time Stamp: " << timeStamp << endl;

        for (Int_t i=0;i<60;i++) {
	     Run_Title[i] = ' ';
	}


        pTitle = (char*)epoint;
        for (Int_t i=0;i<60;i++) {
	    Run_Title[i] = *(pTitle++);
            if (Run_Title[i]=='\0') break;
	}
	TitleStr.assign(Run_Title,Run_Title+60);
	cout << "Run number: " << runNum << endl;
	cout << "Run title: " << TitleStr << endl;

	//end run buffer
	//cout << "end of run buffer"<< endl;
//	cout << "Stop: "<< *(point+58)<<"/"<<*(point+59)<<"/"<<*(point+60)
//	     <<" at "<<*(point+61)<<":"<<*(point+62)<<":"<<*(point+63)<<endl;
	endOfRun = 1;

        EventRate = new TGraph(PECItems,TOffset,EvtRate);

        RootObjects->Add(EventRate);

	break;
      case 3: 
	// begin run buffer
	cout << "   "  << endl;
        cout << "Pause run Item" << endl;
	runNum = *epoint++;
        runNum += (*epoint++)<<=16;
//	cout << "run number="<< runNum << endl;
        timeOffset = *epoint++;
        timeOffset += (*epoint++)<<=16;
        cout << "Time Offset: " << timeOffset << endl;
        timeStamp = *epoint++;
        timeStamp += (*epoint++)<<=16;
        cout << "Time Stamp: " << timeStamp << endl;


        for (Int_t i=0;i<60;i++) {
	     Run_Title[i] = ' ';
	}

        pTitle = (char*)epoint;
        for (Int_t i=0;i<60;i++) {
	     Run_Title[i] = *(pTitle++);
             if (Run_Title[i]=='\0') break;
	}
	TitleStr.assign(Run_Title,Run_Title+60);
	cout << "Run number: " << runNum << endl;
	cout << "Run title: " << TitleStr << endl;
//        cout << "Start: "<< *(point+58)<<"/"<<*(point+59)<<"/"<<*(point+60)
//	     <<" at "<<*(point+61)<<":"<<*(point+62)<<":"<<*(point+63)<<endl;     
	break;
      case 4: 
	// begin run buffer
	cout << "   "  << endl;
        cout << "Resume run Item" << endl;
	runNum = *epoint++;
        runNum += (*epoint++)<<=16;
//	cout << "run number="<< runNum << endl;
        timeOffset = *epoint++;
        timeOffset += (*epoint++)<<=16;
        cout << "Time Offset: " << timeOffset << endl;
        timeStamp = *epoint++;
        timeStamp += (*epoint++)<<=16;
        cout << "Time Stamp: " << timeStamp << endl;

        for (Int_t i=0;i<60;i++) {
	     Run_Title[i] = ' ';
	}

        pTitle = (char*)epoint;
        for (Int_t i=0;i<60;i++) {
	     Run_Title[i] = *(pTitle++);
             if (Run_Title[i]=='\0') break;
	}
	TitleStr.assign(Run_Title,Run_Title+60);
	cout << "Run number: " << runNum << endl;
	cout << "Run title: " << TitleStr << endl;
//        cout << "Start: "<< *(point+58)<<"/"<<*(point+59)<<"/"<<*(point+60)
//	     <<" at "<<*(point+61)<<":"<<*(point+62)<<":"<<*(point+63)<<endl;     
	break;	
      case 20:
	// scaler buffer
	ScalerItem++;

//	  cout << "Buffer number" << *(point+4) + *(point+5)*65536 <<endl;
//	  cout << "Run number" << *(point+3) <<endl;
//	  cout << "Number of scalers read out:" << *(point+6)<<endl;
          Start_time = *epoint++; 
          Start_time += (*epoint++)<<=16; 
	  End_time   = *epoint++;
          End_time   += (*epoint++)<<=16;
          epoint++;
          epoint++;
//          cout << "Scaler item" << endl;
//	  cout << "Start time: "  << Start_time <<endl;
//	  cout << "End time: "  << End_time <<endl;
//	  cout << "Channel 0:" << *(point+26) <<endl;
          
          nChannels = *epoint++;
          nChannels += (*epoint++)<<=16;
//          cout << "nChannels: " << nChannels << endl;
          
          for (Int_t i=0; i<nChannels ; i++) {
		Schannel[i] = *epoint++;
		Schannel[i] += (*epoint++)<<=16;
//                cout << "Channel " << i << " value " << Schannel[i] << endl;
          }	

	  Master_total  += Schannel[0];
	  Master_live   += Schannel[1];
	  MB1_TriggerB  += Schannel[2];
	  MB1_TriggerC  += Schannel[3];
	  MB2_TriggerB  += Schannel[4];
	  MB2_TriggerC  += Schannel[5];

	  MinTime += (End_time-Start_time);	 
 
	  if (MinTime >= 60) {
		CMonTot->Fill(minute_count,Master_total-Master_Old);
		CMonLive->Fill(minute_count++,Master_live-MasterLive_Old);
		Master_Old = Master_total;
		MasterLive_Old = Master_live;
                MinTime = 0;
	  }
  	break;
      case 30:
	//cout << " physics buffer" << endl;
	PhysicsItem++;
	ReadPhysicsBuffer(ItemSize);	
	break; //end of physics buffer
      case 31:
	timeOffset = *epoint++;
        timeOffset += (*epoint++)<<=16;
 //      cout << "Time Offset: " << timeOffset << endl;

	int DeltaTime = timeOffset - oldOffset;
  //     cout << "Time from the last PEC Item: " << DeltaTime << endl;

        timeStamp = *epoint++;
        timeStamp += (*epoint++)<<=16;
//       cout << "Time Stamp: " << timeStamp << endl;

        PECounter  = (*epoint++); 
        PECounter += (*epoint++)<<=16;
        PECounter += (*epoint++)<<=32; 
        PECounter += (*epoint++)<<=48;

//		  cout << "PEC="<<PECounter<<", oldPEC="<<oldPECounter<<", DeltaTime="<<DeltaTime<<endl;
        int PERate = 0;
        if(DeltaTime != 0) PERate = (PECounter - oldPECounter)/DeltaTime;
        TOffset[PECItems] = timeOffset;
        EvtRate[PECItems++] = PERate;
    
        if (PECItems > 86400) cout << "WARNING! PECItems is >86400. Going out of bounds for the TOffset and EvetRate arrays!!" << endl;
       
//       cout << "PERate: " << PERate << endl; 
//       cout << "PECounter: " << PECounter << endl; 
	oldOffset = timeOffset;
        oldPECounter = PECounter;

      }//end switch(type)
     } //end for Item 
    } //end for over evtfile
    
    
    evtfile.close();
    evtfile.clear(); // clear event status in case we had a bad file
    //if (endOfRun) break;
      
    //} //end loop over file subsections

    ListEVT >> run_number;
      
  }

  cout << setprecision(3);
  cout << " Total number of Items = " << NItems << endl;
  cout << " Physics Items = " << PhysicsItem  << " (" <<100.0*PhysicsItem/NItems<< "\% of total)"<< endl;
  cout << " Physics Counter Items = " << PECItems  << " (" <<100.0*PECItems/NItems<< "\% of total)"<< endl;
  cout << " Scaler Items = " << ScalerItem << " (" <<100.0*ScalerItem/NItems<< "\% of total)" << endl;
   
  
  cout << "Number of events based on buffer headers: " << TotEvents << endl;
  cout << "Last physics counter item event number = " << PECounter << " !!This has to be less than the total!!" << endl;
  cout << "Number of events based on CAEN EOB: " << EOB_NEvents << endl;
  cout << "Number of triggers based on MESYTEC EOB: " << MESY_EOB_NEvents << endl; 
  cout << "Number of events based on CAEN buffers counter: " << CAENCounter << endl;
  cout << "Number of events based on MESYTEC buffers counter: " << MESYCounter << endl;
  cout << "Number of events based on event counter: " <<  EventCounter << endl;
  
  cout << " Triggers total = " << Master_total << endl;
  cout << " Triggers live = " << Master_live << endl;
  cout << " MB1 Trigger B = " << MB1_TriggerB << endl;
  cout << " MB1 Trigger C = " << MB1_TriggerC << endl;
  cout << " MB2 Trigger B = " << MB2_TriggerB << endl;
  cout << " MB2 Trigger C = " << MB2_TriggerC << endl;
  
  
//  DataTree->Write();
  RootObjects->Write();
//  fileR->Write();
  fileR->Close();
	
  gApplication->Terminate();
  //return 1;
}

////////////////////////////////////////////////////////////////////////////
// Function where the root objects are filled.
////////////////////////////////////////////////////////////////////////////

void ReadPhysicsBuffer(int ItemSize){

//  Nevents = *(epoint+4);
//  TotEvents += Nevents;
//  epoint = epoint + 14;
  //cout << "Nevents = "<<Nevents<<endl;
//  for (unsigned int ievent=0;ievent<Nevents;ievent++) {

    Si.zeroASICHit();
    ADC.zeroCAENHit();
    TDC.zeroCAENHit();

    //create pointer inside of each  event
    unsigned short * fpoint = epoint;
		    
    words = *fpoint++;


    //--- CAEN readout section -------------------------------------------
//    cout << "CAEN" << endl;

    int CAEN = *fpoint++;
    int counter;
	
    counter = 0;
   
    while (CAEN != 0xff01) {
      CAEN = *fpoint++;
      counter++;
      if (counter>10) break;
    }
    
    // CAEN TDC / ADC readout
    
//    cout << " CAEN " << hex << CAEN << endl;	
    if (CAEN==0xff01) {
    	CAENCounter++;
    	    
    while (fpoint < epoint + words){

      if(*fpoint == 0xdddd) break;
      
     if(*fpoint == 0xffff ){
     	fpoint++;
	continue;
     }
		  
      unsigned short *gpoint = fpoint;
      unsigned short GEOaddress = (*(gpoint++) & 0xf800)>>11;
      unsigned short chanCount = (*(gpoint++) & 0xff00)>>8;
      
      int i;
//      cout << "chanCount = " << chanCount << endl;
//      cout << "GEOaddress = " << GEOaddress << endl;
		      
      for (i=0;i<chanCount;i++){
	if(i>31) continue;
	unsigned short geo = (*gpoint&0xf800)>>11;
	unsigned short chn = (*(gpoint++)&0x1f);
	unsigned short ov  = (*gpoint&0x1000)>>12;
	unsigned short un  = (*gpoint&0x2000)>>13;
	unsigned short dat = (*(gpoint++)&0xfff);
	
   cout << "GEO="<<GEOaddress<<", geo="<<geo<<", chn="<<chn<<", dat="<<dat<<endl;
	if (geo == GEOaddress) {
        //if (GEOaddress==9 && chn==5) { hCaenADC_IC->Fill(dat); }
        if (GEOaddress==9) { hCaenADC_IC->Fill(dat); }
        if (GEOaddress==9 && chn<32) {
            ADC.ID[ADC.Nhits] = GEOaddress;
            ADC.ChNum[ADC.Nhits] = chn;
            if (ov) {
              ADC.Data[ADC.Nhits++] = 5000;
            } else if (un) {
              ADC.Data[ADC.Nhits++] = -1000;
            } else {
              ADC.Data[ADC.Nhits++] = dat;
            }
        }

	}

      }
   

     unsigned short EOB_l = *(gpoint++);
     unsigned short EOB_h = *(gpoint++);
     unsigned short EOB_bit;
      
      unsigned short geo = (EOB_h&0xf800)>>11;
      EOB_bit = (EOB_h&0x0400)>>10;
      
      if (geo == GEOaddress && EOB_bit) {
      	      EOB_NEvents = EOB_l+(EOB_h&0x00ff)*65536;
      } 
      
      while ((gpoint < epoint + words )&&(*gpoint==0xffff)){
	gpoint++;
      }
      // go to next CAEN data
      fpoint = gpoint;
		      
      }
     }
     	    
    epoint += words+1; // This skips the rest of the event
		    
    //  eventNo++;
    EventCounter++;

    DataTree->Fill();
 
//  }//end for over events


}
