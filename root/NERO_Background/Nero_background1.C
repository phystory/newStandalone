#include <fstream>
#include <iostream>

using namespace std;

  // declaring global variables

  char temp[900];
  TString valuestring;
  float valuefloat;
  TString runtitle;
  TString runnumber;
  TString starttime;
  TString endtime;
  TString runtime;
  float runtimesec=0;

  float IntegrateAll=-1;  


  //define histograms to be filled for global use

  TH1F *quadA = new TH1F("quadA","background rate in counts/sec", 16, 1, 17);
  TH1F *quadB = new TH1F("quadB","background rate in counts/sec", 16, 1, 17);
  TH1F *quadC = new TH1F("quadC","background rate in counts/sec", 16, 1, 17);
  TH1F *quadD = new TH1F("quadD","background rate in counts/sec", 16, 1, 17);



int readfile(char* pFilename) {

  //reset all histos and variables

  quadA->Reset();
  quadB->Reset();
  quadC->Reset();
  quadD->Reset();

  valuestring = "";
  valuefloat=0;
  runtitle = "";
  runnumber = "";
  starttime = "";
  endtime = "";
  runtime = "";
  IntegrateAll=-1;


  //open file and read header

  ifstream file(pFilename, ios::in);


    cout << endl ;

    file.getline(temp, 900);
    for(Int_t i=21;i<41;i++){
      runtitle +=temp[i];
    }
    cout << "runtitle :  " << runtitle << endl ;

 
    file.getline(temp, 900);
    for(Int_t i=26;i<29;i++){
      runnumber +=temp[i];
    }
    cout << "runnumber:  " << runnumber << endl ;

    file.getline(temp, 900);
    for(Int_t i=30;i<61;i++){
      starttime +=temp[i];
    }
    cout << "starttime:  " << starttime << endl ;   

    file.getline(temp, 900);
    for(Int_t i=29;i<60;i++){
      endtime +=temp[i];
    }
    cout << "endtime  :  " << endtime << endl ; 

    file.getline(temp, 900);
    for(Int_t i=31;i<41;i++){
      runtime +=temp[i];
    }
    cout << "runtime  :  " << runtime << endl << endl ; 

    
    file.getline(temp, 900);
    //    cout << temp << endl ; 
    file.getline(temp, 900);
    //    cout << temp << endl ; 

    //end of header


    //convert runtime into seconds
    runtimesec=getseconds();
    


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
      quadA->Fill(i,valuefloat);
      quadA->SetBinError(i,sqrt(valuefloat)/sqrt(runtimesec));
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
      if (i!=16){
      quadB->Fill(i,valuefloat);
      quadB->SetBinError(i,sqrt(valuefloat)/sqrt(runtimesec));
      }
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
      if (i!=16){
      quadC->Fill(i,valuefloat);
      quadC->SetBinError(i,sqrt(valuefloat)/sqrt(runtimesec));
      }
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
      if (i!=16){      
      quadD->Fill(i,valuefloat);
      quadD->SetBinError(i,sqrt(valuefloat)/sqrt(runtimesec));
      }
    }

  file.close();

  cout << "Scaler data loaded to histogram quadA, quadB, quadC, quadD " << endl << endl ; 

}



float getseconds(){
  
  valuestring="";
  float runtimetemp=0;
  //  cout << runtime << endl;

    valuestring="";
    valuestring +=runtime[0];
    //  cout << valuestring << endl;
    runtimetemp = atof(valuestring)*24*60*60;
    //    cout << runtimetemp <<endl;

    valuestring = "";
    valuestring +=runtime[2];
    valuestring +=runtime[3];
    //  cout << valuestring << endl;
    runtimetemp = runtimetemp + atof(valuestring)*60*60;

    valuestring = "";
    valuestring +=runtime[5];
    valuestring +=runtime[6];
    //  cout << valuestring << endl;
    runtimetemp = runtimetemp + atof(valuestring)*60;

    valuestring = "";
    valuestring +=runtime[8];
    valuestring +=runtime[9];
    //  cout << valuestring << endl;
    runtimetemp = runtimetemp + atof(valuestring);


    cout << "runtime = " << runtime << " = " << runtimetemp << "s" << endl;

  return runtimetemp;
}





int Output(char* pFilename) {

  IntegrateAll=-1;

/*  quadA->Draw();    //just to start the canvas window. don't know how to do that better
  
  c1->Clear();      //clear everything in the new window
  c1->Divide(2,2);  //divide it in four subwindows for four histograms

  gStyle->SetOptStat(1000011);   //only title and entries should be shown in stat box (upper right)

  c1->cd(1);                //change to subwindow1
  quadA->Draw();            //draw quadA histo to subwindow 1  (options: "c","e","p","l","h")
  gPad->SetGridx(1);        //sets the x-grid in a histogram
  gPad->Modified();         //to display modification, you need this command

  pt = new TPaveText(0.15,0.2,0.45,0.35, "NDC");   //produce a text box with corners (x1,y1,x2,y2, "NDC")
  pt->AddText(runtitle);                           //add text

  TString text;
  text = "run:     "+runnumber;
  pt->AddText(text);

  text = "runtime: "+runtime;
  pt->AddText(text);

  pt->AddText(starttime);

  pt->Draw();                                      //draw textbox to current subwindow


  c1->cd(2);
  quadB->Draw();
  gPad->SetGridx(1); 
  gPad->Modified();

  c1->cd(3);
  quadC->Draw();
  gPad->SetGridx(1); 
  gPad->Modified();

  c1->cd(4);
  quadD->Draw();
  gPad->SetGridx(1); 
  gPad->Modified();


  c1->SaveAs(pFilename);                      //save output. (C,jpg,gif,pdf,...)
*/
  IntegrateAll = quadA->Integral()+quadB->Integral()+quadC->Integral()+quadD->Integral();

  float IntegralAError=0;
  for(Int_t i=1;i<17;i++){
    IntegralAError=IntegralAError+(quadA->GetBinError(i))**2;
  }
  IntegralAError=sqrt(IntegralAError);
  cout << "sum of quadA = " << quadA->Integral() << " +/- " << IntegralAError << endl;

  float IntegralBError=0;
  for(Int_t i=1;i<17;i++){
    IntegralBError=IntegralBError+(quadB->GetBinError(i))**2;
  }
  IntegralBError=sqrt(IntegralBError);
  cout << "sum of quadB = " << quadB->Integral() << " +/- " << IntegralBError << endl;

  float IntegralCError=0;
  for(Int_t i=1;i<17;i++){
    IntegralCError=IntegralCError+(quadC->GetBinError(i))**2;
  }
  IntegralCError=sqrt(IntegralCError);
  cout << "sum of quadC = " << quadC->Integral() << " +/- " << IntegralCError << endl;

  float IntegralDError=0;
  for(Int_t i=1;i<17;i++){
    IntegralDError=IntegralDError+(quadD->GetBinError(i))**2;
  }
  IntegralDError=sqrt(IntegralDError);
  cout << "sum of quadD = " << quadD->Integral() << " +/- " << IntegralDError << endl;


  float IntegralAllError=sqrt(IntegralAError**2+IntegralBError**2+IntegralCError**2+IntegralDError**2);
  

  cout << endl << "background rate = " << IntegrateAll << " +/- " << IntegralAllError << " (includes all Tubes)" << endl << endl;


}


int Nero_go(char* pFilename) {

  readfile(pFilename);

  TString text;
  text = "run"+runnumber+" - background.pdf";
  Output(text);

}
