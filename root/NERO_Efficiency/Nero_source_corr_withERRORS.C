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
  double A_n_today=-1;
  double delta_A_n_today=-1;
  

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

  TH1F *effQuadA = new TH1F("effQuadA","Efficiency in %", 16, 1, 17);
  TH1F *effQuadB = new TH1F("effQuadB","Efficiency in %", 16, 1, 17);
  TH1F *effQuadC = new TH1F("effQuadC","Efficiency in %", 16, 1, 17);
  TH1F *effQuadD = new TH1F("effQuadD","Efficiency in %", 16, 1, 17);

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
  float runtimesec=0;

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

    runtimesec=getseconds(runtimebackgr);

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
      backgrQuadA->SetBinError(i,sqrt(valuefloat)/sqrt(runtimesec));
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
      backgrQuadB->Fill(i,valuefloat);
      backgrQuadB->SetBinError(i,sqrt(valuefloat)/sqrt(runtimesec));
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
      backgrQuadC->Fill(i,valuefloat);
      backgrQuadC->SetBinError(i,sqrt(valuefloat)/sqrt(runtimesec));
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
       	backgrQuadD->Fill(i,valuefloat);
       	backgrQuadD->SetBinError(i,sqrt(valuefloat)/sqrt(runtimesec));
      }
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
  float runtimesec=0;

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

    runtimesec=getseconds(runtimesource);

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
      sourceQuadA->SetBinError(i,sqrt(valuefloat)/sqrt(runtimesec));
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
      sourceQuadB->Fill(i,valuefloat);
      sourceQuadB->SetBinError(i,sqrt(valuefloat)/sqrt(runtimesec));
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
      sourceQuadC->Fill(i,valuefloat);
      sourceQuadC->SetBinError(i,sqrt(valuefloat)/sqrt(runtimesec));
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
      sourceQuadD->Fill(i,valuefloat);
      sourceQuadD->SetBinError(i,sqrt(valuefloat)/sqrt(runtimesec));
      }
    }


    cout << pFilename <<" loaded to source histogram sourceQuadA, sourceQuadB, sourceQuadC, sourceQuadD " << endl << endl ; 

    file.close();

}





int corr_source() {

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
}


int efficiency(int days) {

  getactivity(days);
  double activity = A_n_today;
  double delta_activity = delta_A_n_today;

    for(Int_t i=1;i<17;i++){	//Quad A
      if (i!=9){
      effQuadA->Fill(i,sourceCorrQuadA->GetBinContent(i)/activity);
      effQuadA->SetBinError(i,sqrt( ( sourceCorrQuadA->GetBinError(i)/activity )**2 + ( sourceCorrQuadA->GetBinContent(i) * delta_activity / (activity**2) )**2 ));
      }
    }


    for(Int_t i=1;i<17;i++){	//Quad B
      if (i!=16){
      effQuadB->Fill(i,sourceCorrQuadB->GetBinContent(i)/activity);
      effQuadB->SetBinError(i,sqrt( ( sourceCorrQuadB->GetBinError(i)/activity )**2 + ( sourceCorrQuadB->GetBinContent(i) * delta_activity / (activity**2) )**2 ));
      }
    }


    for(Int_t i=1;i<17;i++){	//Quad C
      if (i!=16){
      effQuadC->Fill(i,sourceCorrQuadC->GetBinContent(i)/activity);
      effQuadC->SetBinError(i,sqrt( ( sourceCorrQuadC->GetBinError(i)/activity )**2 + ( sourceCorrQuadC->GetBinContent(i) * delta_activity / (activity**2) )**2 ));
      }
    }


    for(Int_t i=1;i<17;i++){	//Quad D
      if (i!=16){
      effQuadD->Fill(i,sourceCorrQuadD->GetBinContent(i)/activity);
      effQuadD->SetBinError(i,sqrt( ( sourceCorrQuadD->GetBinError(i)/activity )**2 + ( sourceCorrQuadD->GetBinContent(i) * delta_activity / (activity**2) )**2 ));
      }
    }

 // get efficiency by ring1 (He3)

  double IntegralRing1=0;
  double delta_IntegralRing1=0;

  for(Int_t i=1;i<5;i++){
    IntegralRing1=IntegralRing1 + effQuadA->GetBinContent(i);
    delta_IntegralRing1=delta_IntegralRing1+(effQuadA->GetBinError(i))**2;
    IntegralRing1=IntegralRing1 + effQuadB->GetBinContent(i);
    delta_IntegralRing1=delta_IntegralRing1+(effQuadB->GetBinError(i))**2;
    IntegralRing1=IntegralRing1 + effQuadC->GetBinContent(i);
    delta_IntegralRing1=delta_IntegralRing1+(effQuadC->GetBinError(i))**2;
    IntegralRing1=IntegralRing1 + effQuadD->GetBinContent(i);
    delta_IntegralRing1=delta_IntegralRing1+(effQuadD->GetBinError(i))**2;
  }
  delta_IntegralRing1=sqrt(delta_IntegralRing1);
  cout << "Efficiency of ring1 (He3) = " << IntegralRing1*100 << " +/- " << delta_IntegralRing1*100 << " %" << endl;


 // get efficiency by ring2 (BF3)
  double IntegralRing2=0;
  double delta_IntegralRing2=0;

  for(Int_t i=5;i<10;i++){
    if (i!=9){
      IntegralRing2=IntegralRing2 + effQuadA->GetBinContent(i);
      delta_IntegralRing2=delta_IntegralRing2+(effQuadA->GetBinError(i))**2;
    }
    IntegralRing2=IntegralRing2 + effQuadB->GetBinContent(i);
    delta_IntegralRing2=delta_IntegralRing2+(effQuadB->GetBinError(i))**2;
    IntegralRing2=IntegralRing2 + effQuadC->GetBinContent(i);
    delta_IntegralRing2=delta_IntegralRing2+(effQuadC->GetBinError(i))**2;
    IntegralRing2=IntegralRing2 + effQuadD->GetBinContent(i);
    delta_IntegralRing2=delta_IntegralRing2+(effQuadD->GetBinError(i))**2;
  }

    IntegralRing2=IntegralRing2 + effQuadA->GetBinContent(16);
    delta_IntegralRing2=delta_IntegralRing2+(effQuadA->GetBinError(16))**2;

  delta_IntegralRing2=sqrt(delta_IntegralRing2);
  cout << "Efficiency of ring2 (BF3) = " << IntegralRing2*100 << " +/- " << delta_IntegralRing2*100 << " %" << endl;

 // get efficiency by ring3 (BF3)

  double IntegralRing3=0;
  double delta_IntegralRing3=0;

  for(Int_t i=10;i<16;i++){
    IntegralRing3=IntegralRing3 + effQuadA->GetBinContent(i);
    delta_IntegralRing3=delta_IntegralRing3+(effQuadA->GetBinError(i))**2;
    IntegralRing3=IntegralRing3 + effQuadB->GetBinContent(i);
    delta_IntegralRing3=delta_IntegralRing3+(effQuadB->GetBinError(i))**2;
    IntegralRing3=IntegralRing3 + effQuadC->GetBinContent(i);
    delta_IntegralRing3=delta_IntegralRing3+(effQuadC->GetBinError(i))**2;
    IntegralRing3=IntegralRing3 + effQuadD->GetBinContent(i);
    delta_IntegralRing3=delta_IntegralRing3+(effQuadD->GetBinError(i))**2;
  }
  delta_IntegralRing3=sqrt(delta_IntegralRing3);
  cout << "Efficiency of ring3 (BF3) = " << IntegralRing3*100 << " +/- " << delta_IntegralRing3*100 << " %" << endl;


 // get efficiency by quadA

  double IntegralQuadA=0;
  double delta_IntegralQuadA=0;

  for(Int_t i=1;i<17;i++){
    if (i!=9){
      IntegralQuadA=IntegralQuadA + effQuadA->GetBinContent(i);
      delta_IntegralQuadA=delta_IntegralQuadA+(effQuadA->GetBinError(i))**2;
    }
  }
  delta_IntegralQuadA=sqrt(delta_IntegralQuadA);
  cout << "Efficiency of QuadA       = " << IntegralQuadA*100 << " +/- " << delta_IntegralQuadA*100 << " %" << endl;

 // get efficiency by quadB

  double IntegralQuadB=0;
  double delta_IntegralQuadB=0;

  for(Int_t i=1;i<17;i++){
    if (i!=16){
      IntegralQuadB=IntegralQuadB + effQuadB->GetBinContent(i);
      delta_IntegralQuadB=delta_IntegralQuadB+(effQuadB->GetBinError(i))**2;
    }
  }
  delta_IntegralQuadB=sqrt(delta_IntegralQuadB);
  cout << "Efficiency of QuadB       = " << IntegralQuadB*100 << " +/- " << delta_IntegralQuadB*100 << " %" << endl;

 // get efficiency by quadC

  double IntegralQuadC=0;
  double delta_IntegralQuadC=0;

  for(Int_t i=1;i<17;i++){
    if (i!=16){
      IntegralQuadC=IntegralQuadC + effQuadC->GetBinContent(i);
      delta_IntegralQuadC=delta_IntegralQuadC+(effQuadC->GetBinError(i))**2;
    }
  }
  delta_IntegralQuadC=sqrt(delta_IntegralQuadC);
  cout << "Efficiency of QuadC       = " << IntegralQuadC*100 << " +/- " << delta_IntegralQuadC*100 << " %" << endl;

 // get efficiency by quadD

  double IntegralQuadD=0;
  double delta_IntegralQuadD=0;

  for(Int_t i=1;i<17;i++){
    if (i!=16){
      IntegralQuadD=IntegralQuadD + effQuadD->GetBinContent(i);
      delta_IntegralQuadD=delta_IntegralQuadD+(effQuadD->GetBinError(i))**2;
    }
  }
  delta_IntegralQuadD=sqrt(delta_IntegralQuadD);
  cout << "Efficiency of QuadD       = " << IntegralQuadD*100 << " +/- " << delta_IntegralQuadD*100 << " %" << endl;

 // get efficiency by all

  double IntegralAll=0;
  double delta_IntegralAll=0;


      IntegralAll=IntegralQuadA + IntegralQuadB + IntegralQuadC + IntegralQuadD;
      delta_IntegralAll=delta_IntegralQuadA**2 + delta_IntegralQuadB**2 + delta_IntegralQuadC**2 + delta_IntegralQuadD**2;

  delta_IntegralAll=sqrt(delta_IntegralAll);
  cout << "Efficiency of NERO        = " << IntegralAll*100 << " +/- " << delta_IntegralAll*100 << " %" << endl;




}




float getseconds(TString runtimestring){
  
  valuestring="";
  float runtimetemp=0;
  //  cout << runtimestring << endl;

    valuestring="";
    valuestring +=runtimestring[0];
    //  cout << valuestring << endl;
    runtimetemp = atof(valuestring)*24*60*60;
    //    cout << runtimetemp <<endl;

    valuestring = "";
    valuestring +=runtimestring[2];
    valuestring +=runtimestring[3];
    //  cout << valuestring << endl;
    runtimetemp = runtimetemp + atof(valuestring)*60*60;

    valuestring = "";
    valuestring +=runtimestring[5];
    valuestring +=runtimestring[6];
    //  cout << valuestring << endl;
    runtimetemp = runtimetemp + atof(valuestring)*60;

    valuestring = "";
    valuestring +=runtimestring[8];
    valuestring +=runtimestring[9];
    //  cout << valuestring << endl;
    runtimetemp = runtimetemp + atof(valuestring);


    cout << "runtime = " << runtimestring << " = " << runtimetemp << "s" << endl;

  return runtimetemp;
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


double getactivity(int days){

  A_n_today = -1;
  delta_A_n_today = -1;

  double A_0 = 50e-6 *3.7e10;	//in 1/s   ->	50µCi * 3.7*10¹° 1/(s*Ci)
  double delta_A_0 = 0.05*A_0;

  double fiss_branch = 0.03092;
  double delta_fiss_branch = 0.00005;		// estimated after comparing values in literatur

  double n_per_fiss = 3.7676;
  double delta_n_per_fission = 0.0047;

  double t_half = 83247170.72;			// in s
  double delta_t_half = 31556.93;		// in s  -  last digit of 2.638a

  double ln2 = 0.693147181;

  double time = days*86400;			// in s
  double delta_time = 86400;

  double lambda = ln2/t_half;
  double delta_lambda = ln2/(t_half**2)*delta_t_half;

  A_n_today = A_0* n_per_fiss * fiss_branch * exp(  -lambda*time  );

  delta_A_n_today = sqrt( (A_n_today/A_0*delta_A_0)**2 + (A_n_today/n_per_fiss*delta_n_per_fission)**2 + (A_n_today/fiss_branch*delta_fiss_branch)**2 + (A_n_today*time*delta_lambda)**2 + (A_n_today*lambda*delta_time)**2);


  cout << "n-activity(today) = " << A_n_today << " +- " << delta_A_n_today << endl << endl;


  return A_n_today;

}


int go(TString source, TString backgr, int days){
  readsource(source);                     
  readbackgr(backgr);
  corr_source();

  cout << "source: " << source << endl;
  cout << "backgr: " << backgr << endl;

  efficiency(days);

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
