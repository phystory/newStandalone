#include <fstream>
#include <iostream>

using namespace std;

  // declaring global variables

  char temp[900];
  TString valuestring;
  float valuefloat;
  TString runtitlebackgr;
  TString runtitlesource;
  TString runnumberbackgr;
  TString runnumbersource;
  TString starttimebackgr;
  TString starttimesource;
  TString endtimebackgr;
  TString endtimesource;
  TString runtimebackgr;
  TString runtimesource;

  float IntegrateAll=-1;

  

  //define histograms to be filled for global use

  TH1F *backgrQuadA = new TH1F("backgrQuadA","background rate in counts/sec", 16, 1, 17);
  TH1F *backgrQuadB = new TH1F("backgrQuadB","background rate in counts/sec", 16, 1, 17);
  TH1F *backgrQuadC = new TH1F("backgrQuadC","background rate in counts/sec", 16, 1, 17);
  TH1F *backgrQuadD = new TH1F("backgrQuadD","background rate in counts/sec", 16, 1, 17);

  TH1F *sourceQuadA = new TH1F("sourceQuadA","Source rate in counts/sec", 16, 1, 17);
  TH1F *sourceQuadB = new TH1F("sourceQuadB","Source rate in counts/sec", 16, 1, 17);
  TH1F *sourceQuadC = new TH1F("sourceQuadC","Source rate in counts/sec", 16, 1, 17);
  TH1F *sourceQuadD = new TH1F("sourceQuadD","Source rate in counts/sec", 16, 1, 17);

  TH1F *sourceCorrQuadA = new TH1F("sourceCorrQuadA","Corrected source rate in counts/sec", 16, 1, 17);
  TH1F *sourceCorrQuadB = new TH1F("sourceCorrQuadB","Corrected source rate in counts/sec", 16, 1, 17);
  TH1F *sourceCorrQuadC = new TH1F("sourceCorrQuadC","Corrected source rate in counts/sec", 16, 1, 17);
  TH1F *sourceCorrQuadD = new TH1F("sourceCorrQuadD","Corrected source rate in counts/sec", 16, 1, 17);



int readbackgr(char* pFilename) {

  //reset all histos and variables

  backgrQuadA->Reset();
  backgrQuadB->Reset();
  backgrQuadC->Reset();
  backgrQuadD->Reset();

  valuestring = "";
  valuefloat=0;
  runtitlebackgr = "";
  runnumberbackgr = "";
  starttimebackgr = "";
  endtimebackgr = "";
  runtimebackgr = "";
  IntegrateAll=-1;

  //open file and read header

  ifstream file(pFilename, ios::in);


    cout << endl ;

    file.getline(temp, 900);
    for(Int_t i=21;i<41;i++){
      runtitlebackgr +=temp[i];
    }
    cout << "runtitlebackgr :  " << runtitlebackgr << endl ;

 
    file.getline(temp, 900);
    for(Int_t i=26;i<29;i++){
      runnumberbackgr +=temp[i];
    }
    cout << "runnumberbackgr:  " << runnumberbackgr << endl ;

    file.getline(temp, 900);
    for(Int_t i=30;i<61;i++){
      starttimebackgr +=temp[i];
    }
    cout << "starttimebackgr:  " << starttimebackgr << endl ;   

    file.getline(temp, 900);
    for(Int_t i=29;i<60;i++){
      endtimebackgr +=temp[i];
    }
    cout << "endtimebackgr  :  " << endtimebackgr << endl ; 

    file.getline(temp, 900);
    for(Int_t i=31;i<41;i++){
      runtimebackgr +=temp[i];
    }
    cout << "runtimebackgr  :  " << runtimebackgr << endl << endl ; 

    
    file.getline(temp, 900);
    //    cout << temp << endl ; 
    file.getline(temp, 900);
    //    cout << temp << endl ; 

    //end of header



    //read line by line and extract the count rate from this line.
    //then put number into correct histo (quadA-D). Count rate readout is limited <100 counts/sec.
    //quadA

    for(Int_t i=1;i<17;i++){
      valuestring = "";
      file.getline(temp, 900);
      for(Int_t ch=32;ch<38;ch++){                //if trouble because of rates>100 1/sec change 32 to lower number 31 (rates up to 1000) or 30 (rates up to 10000)
        valuestring +=temp[ch];
      }
      valuefloat = atof(valuestring);             //convert string to float
      //      cout << valuestring << " ---- " << valuefloat << endl ; 
      backgrQuadA->Fill(i,valuefloat);
    }


    //quadB

    for(Int_t i=1;i<17;i++){
      valuestring = "";
      file.getline(temp, 900);
      for(Int_t ch=32;ch<38;ch++){
        valuestring +=temp[ch];
      }
      valuefloat = atof(valuestring);
      //      cout << valuestring << " ---- " << valuefloat << endl ; 
      backgrQuadB->Fill(i,valuefloat);
    }


    //quadC
      
    for(Int_t i=1;i<17;i++){
      valuestring = "";
      file.getline(temp, 900);
      for(Int_t ch=32;ch<38;ch++){
        valuestring +=temp[ch];
      }
      valuefloat = atof(valuestring);
      //      cout << valuestring << " ---- " << valuefloat << endl ; 
      backgrQuadC->Fill(i,valuefloat);
    }


    //quadD

    for(Int_t i=1;i<17;i++){
      valuestring = "";
      file.getline(temp, 900);
      for(Int_t ch=32;ch<38;ch++){
        valuestring +=temp[ch];
      }
      valuefloat = atof(valuestring);
      //      cout << valuestring << " ---- " << valuefloat << endl ; 
      backgrQuadD->Fill(i,valuefloat);
    }


    cout << pFilename <<" loaded to background histogram backgrQuadA, backgrQuadB, backgrQuadC, backgrQuadD " << endl << endl ; 

    file.close();

}




int readsource(char* pFilename) {

  //reset all histos and variables

  sourceQuadA->Reset();
  sourceQuadB->Reset();
  sourceQuadC->Reset();
  sourceQuadD->Reset();

  valuestring = "";
  valuefloat=0;
  runtitlesource = "";
  runnumbersource = "";
  starttimesource = "";
  endtimesource = "";
  runtimesource = "";
  IntegrateAll=-1;

  //open file and read header

  ifstream file(pFilename, ios::in);


    cout << endl ;

    file.getline(temp, 900);
    for(Int_t i=21;i<41;i++){
      runtitlesource +=temp[i];
    }
    cout << "runtitlesource :  " << runtitlesource << endl ;

 
    file.getline(temp, 900);
    for(Int_t i=26;i<29;i++){
      runnumbersource +=temp[i];
    }
    cout << "runnumbersource:  " << runnumbersource << endl ;

    file.getline(temp, 900);
    for(Int_t i=30;i<61;i++){
      starttimesource +=temp[i];
    }
    cout << "starttimesource:  " << starttimesource << endl ;   

    file.getline(temp, 900);
    for(Int_t i=29;i<60;i++){
      endtimesource +=temp[i];
    }
    cout << "endtimesource  :  " << endtimesource << endl ; 

    file.getline(temp, 900);
    for(Int_t i=31;i<41;i++){
      runtimesource +=temp[i];
    }
    cout << "runtimesource  :  " << runtimesource << endl << endl ; 

    
    file.getline(temp, 900);
    //    cout << temp << endl ; 
    file.getline(temp, 900);
    //    cout << temp << endl ; 

    //end of header



    //read line by line and extract the count rate from this line.
    //then put number into correct histo (quadA-D)
    //quadA

    for(Int_t i=1;i<17;i++){
      valuestring = "";
      file.getline(temp, 900);
      for(Int_t ch=32;ch<38;ch++){
        valuestring +=temp[ch];
      }
      valuefloat = atof(valuestring);
      //      cout << valuestring << " ---- " << valuefloat << endl ; 
      sourceQuadA->Fill(i,valuefloat);
    }


    //quadB

    for(Int_t i=1;i<17;i++){
      valuestring = "";
      file.getline(temp, 900);
      for(Int_t ch=32;ch<38;ch++){
        valuestring +=temp[ch];
      }
      valuefloat = atof(valuestring);
      //      cout << valuestring << " ---- " << valuefloat << endl ; 
      sourceQuadB->Fill(i,valuefloat);
    }


    //quadC
      
    for(Int_t i=1;i<17;i++){
      valuestring = "";
      file.getline(temp, 900);
      for(Int_t ch=32;ch<38;ch++){
        valuestring +=temp[ch];
      }
      valuefloat = atof(valuestring);
      //      cout << valuestring << " ---- " << valuefloat << endl ; 
      sourceQuadC->Fill(i,valuefloat);
    }


    //quadD

    for(Int_t i=1;i<17;i++){
      valuestring = "";
      file.getline(temp, 900);
      for(Int_t ch=32;ch<38;ch++){
        valuestring +=temp[ch];
      }
      valuefloat = atof(valuestring);
      //      cout << valuestring << " ---- " << valuefloat << endl ; 
      sourceQuadD->Fill(i,valuefloat);
    }


    cout << pFilename <<" loaded to source histogram sourceQuadA, sourceQuadB, sourceQuadC, sourceQuadD " << endl << endl ; 

    file.close();

}





int corr_source() {

  IntegrateAll=-1;

  sourceCorrQuadA->Reset();
  sourceCorrQuadB->Reset();
  sourceCorrQuadC->Reset();
  sourceCorrQuadD->Reset();

  //subtraction of the two histograms. (*histo) is used, because I work with pointer. without pointer, just histo=histo1+histo2

  (*sourceCorrQuadA) = (*sourceQuadA) - (*backgrQuadA);
  (*sourceCorrQuadB) = (*sourceQuadB) - (*backgrQuadB);
  (*sourceCorrQuadC) = (*sourceQuadC) - (*backgrQuadC);
  (*sourceCorrQuadD) = (*sourceQuadD) - (*backgrQuadD);

  cout << "corrected rates saved to histogram sourceCorrQuadA, sourceCorrQuadB, sourceCorrQuadC, sourceCorrQuadD " << endl << endl ; 
  IntegrateAll = sourceCorrQuadA->Integral()+sourceCorrQuadB->Integral()+sourceCorrQuadC->Integral()+sourceCorrQuadD->Integral();

  cout << "corrected rate = " << IntegrateAll << " (includes all Tubes)" << endl << endl;
}


int Output(char* pFilename) {

  sourceCorrQuadA->SetTitle("Corrected source rate in counts/sec");
  sourceCorrQuadB->SetTitle("Corrected source rate in counts/sec");
  sourceCorrQuadC->SetTitle("Corrected source rate in counts/sec");
  sourceCorrQuadD->SetTitle("Corrected source rate in counts/sec");



  sourceCorrQuadA->Draw();    //just to start the canvas window. don't know how to do that better
  

  c1->Clear();      //clear everything in the new window
  c1->Divide(2,2);  //divide it in four subwindows for four histograms


  gStyle->SetOptStat(1000011);
  //gStyle->SetOptStat(11111111);

  c1->cd(1);
  sourceCorrQuadA->Draw();
  gPad->SetGridx(1);
  gPad->Modified();
  TString text;
  text = "Data = run"+runnumbersource+" - run"+runnumberbackgr;
  pt = new TPaveText(0.15,0.2,0.45,0.25, "NDC");  
  pt->AddText(text);
  pt->Draw();


  c1->cd(2);
  sourceCorrQuadB->Draw();
  gPad->SetGridx(1);
  gPad->Modified();
  TString text;
  text = "Data = run"+runnumbersource+" - run"+runnumberbackgr;
  pt = new TPaveText(0.15,0.2,0.45,0.25, "NDC");  
  pt->AddText(text);
  pt->Draw();

  c1->cd(3);
  sourceCorrQuadC->Draw();
  gPad->SetGridx(1);
  gPad->Modified();
  TString text;
  text = "Data = run"+runnumbersource+" - run"+runnumberbackgr;
  pt = new TPaveText(0.15,0.2,0.45,0.25, "NDC");  
  pt->AddText(text);
  pt->Draw();

  c1->cd(4);
  sourceCorrQuadD->Draw();
  gPad->SetGridx(1);
  gPad->Modified();
  TString text;
  text = "Data = run"+runnumbersource+" - run"+runnumberbackgr;
  pt = new TPaveText(0.15,0.2,0.45,0.25, "NDC");  
  pt->AddText(text);
  pt->Draw();

  c1->SaveAs(pFilename);                      //save output. (C,jpg,gif,pdf,...)



}


int go(){

  readsource("run137.scalers");
  readbackgr("run136.scalers");
  corr_source();
}


float efficiency(float nactivity){

  if(IntegrateAll!=-1){

    float tempeff;


    tempeff=sourceCorrQuadA->Integral()/nactivity*100;
    cout << "Efficiency quadA: " << tempeff<< endl;

    tempeff=sourceCorrQuadB->Integral()/nactivity*100;
    cout << "Efficiency quadB: " << tempeff<< endl;

    tempeff=sourceCorrQuadC->Integral()/nactivity*100;
    cout << "Efficiency quadC: " << tempeff<< endl;

    tempeff=sourceCorrQuadD->Integral()/nactivity*100;
    cout << "Efficiency quadD: " << tempeff<< endl;

    tempeff=IntegrateAll/nactivity*100;
    cout << "Efficiency   all: " << tempeff<< endl;


    return tempeff;

  }

}
