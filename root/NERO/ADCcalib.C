
int maxbinA1=-1;
int maxbinA2=-1;
int maxbinA3=-1;
int maxbinA4=-1;
int maxbinA5=-1;
int maxbinA6=-1;
int maxbinA7=-1;
int maxbinA8=-1;
int maxbinA9=-1;
int maxbinA10=-1;
int maxbinA11=-1;
int maxbinA12=-1;
int maxbinA13=-1;
int maxbinA14=-1;
int maxbinA15=-1;
int maxbinA16=-1;

int maxbinB1=-1;
int maxbinB2=-1;
int maxbinB3=-1;
int maxbinB4=-1;
int maxbinB5=-1;
int maxbinB6=-1;
int maxbinB7=-1;
int maxbinB8=-1;
int maxbinB9=-1;
int maxbinB10=-1;
int maxbinB11=-1;
int maxbinB12=-1;
int maxbinB13=-1;
int maxbinB14=-1;
int maxbinB15=-1;
int maxbinB16=-1;

int maxbinC1=-1;
int maxbinC2=-1;
int maxbinC3=-1;
int maxbinC4=-1;
int maxbinC5=-1;
int maxbinC6=-1;
int maxbinC7=-1;
int maxbinC8=-1;
int maxbinC9=-1;
int maxbinC10=-1;
int maxbinC11=-1;
int maxbinC12=-1;
int maxbinC13=-1;
int maxbinC14=-1;
int maxbinC15=-1;
int maxbinC16=-1;

int maxbinD1=-1;
int maxbinD2=-1;
int maxbinD3=-1;
int maxbinD4=-1;
int maxbinD5=-1;
int maxbinD6=-1;
int maxbinD7=-1;
int maxbinD8=-1;
int maxbinD9=-1;
int maxbinD10=-1;
int maxbinD11=-1;
int maxbinD12=-1;
int maxbinD13=-1;
int maxbinD14=-1;
int maxbinD15=-1;
int maxbinD16=-1;

  TH1F *hHe3_0;
  TH1F *hHe3_50;
  TH1F *hBF3_0;
  TH1F *hBF3_50;









int getpeak(char* pFilename) {

  int maxbin=-1;
  float maxvalue=1;

  readsource(pFilename,1);
  hsource->SetAxisRange(0,1500);
  hsource->Draw();
  hsource->SetAxisRange(200,1500);
  maxbin=hsource->GetMaximumBin();
  hsource->SetAxisRange(0,1500);


  /*
  TString formula="[0]*exp(-((x-[1])^2)/[2])";
  TF1* f1 = new TF1("f1",formula);
  f1->SetParameter(0,maxvalue);
  f1->SetParameter(1,maxbin);
  f1->SetParameter(2,1);
  f1->SetLineColor(2);  

  hsource->Fit("f1","","",maxbin,maxbin+maxbin/2);
  */ 

  cout << pFilename << "  maxbin = " << maxbin << endl;

  return maxbin;

}


int getmaxbins(){

  maxbinA1= getpeak("run212/ADC!TDC/quadA_1!TDC.dat");
  maxbinA2= getpeak("run212/ADC!TDC/quadA_2!TDC.dat");
  maxbinA3= getpeak("run212/ADC!TDC/quadA_3!TDC.dat");
  maxbinA4= getpeak("run212/ADC!TDC/quadA_4!TDC.dat");
  maxbinA5= getpeak("run212/ADC!TDC/quadA_5!TDC.dat");
  maxbinA6= getpeak("run212/ADC!TDC/quadA_6!TDC.dat");
  maxbinA7= getpeak("run212/ADC!TDC/quadA_7!TDC.dat");
  maxbinA8= getpeak("run212/ADC!TDC/quadA_8!TDC.dat");
  maxbinA9= getpeak("run212/ADC!TDC/quadA_9!TDC.dat");
  maxbinA10= getpeak("run212/ADC!TDC/quadA_10!TDC.dat");
  maxbinA11= getpeak("run212/ADC!TDC/quadA_11!TDC.dat");
  maxbinA12= getpeak("run212/ADC!TDC/quadA_12!TDC.dat");
  maxbinA13= getpeak("run212/ADC!TDC/quadA_13!TDC.dat");
  maxbinA14= getpeak("run212/ADC!TDC/quadA_14!TDC.dat");
  maxbinA15= getpeak("run212/ADC!TDC/quadA_15!TDC.dat");
  maxbinA16= getpeak("run212/ADC!TDC/quadA_16!TDC.dat");

  maxbinB1= getpeak("run212/ADC!TDC/quadB_1!TDC.dat");
  maxbinB2= getpeak("run212/ADC!TDC/quadB_2!TDC.dat");
  maxbinB3= getpeak("run212/ADC!TDC/quadB_3!TDC.dat");
  maxbinB4= getpeak("run212/ADC!TDC/quadB_4!TDC.dat");
  maxbinB5= getpeak("run212/ADC!TDC/quadB_5!TDC.dat");
  maxbinB6= getpeak("run212/ADC!TDC/quadB_6!TDC.dat");
  maxbinB7= getpeak("run212/ADC!TDC/quadB_7!TDC.dat");
  maxbinB8= getpeak("run212/ADC!TDC/quadB_8!TDC.dat");
  maxbinB9= getpeak("run212/ADC!TDC/quadB_9!TDC.dat");
  maxbinB10= getpeak("run212/ADC!TDC/quadB_10!TDC.dat");
  maxbinB11= getpeak("run212/ADC!TDC/quadB_11!TDC.dat");
  maxbinB12= getpeak("run212/ADC!TDC/quadB_12!TDC.dat");
  maxbinB13= getpeak("run212/ADC!TDC/quadB_13!TDC.dat");
  maxbinB14= getpeak("run212/ADC!TDC/quadB_14!TDC.dat");
  maxbinB15= getpeak("run212/ADC!TDC/quadB_15!TDC.dat");
  maxbinB16= getpeak("run212/ADC!TDC/quadB_16!TDC.dat");


  maxbinC1= getpeak("run212/ADC!TDC/quadC_1!TDC.dat");
  maxbinC2= getpeak("run212/ADC!TDC/quadC_2!TDC.dat");
  maxbinC3= getpeak("run212/ADC!TDC/quadC_3!TDC.dat");
  maxbinC4= getpeak("run212/ADC!TDC/quadC_4!TDC.dat");
  maxbinC5= getpeak("run212/ADC!TDC/quadC_5!TDC.dat");
  maxbinC6= getpeak("run212/ADC!TDC/quadC_6!TDC.dat");
  maxbinC7= getpeak("run212/ADC!TDC/quadC_7!TDC.dat");
  maxbinC8= getpeak("run212/ADC!TDC/quadC_8!TDC.dat");
  maxbinC9= getpeak("run212/ADC!TDC/quadC_9!TDC.dat");
  maxbinC10= getpeak("run212/ADC!TDC/quadC_10!TDC.dat");
  maxbinC11= getpeak("run212/ADC!TDC/quadC_11!TDC.dat");
  maxbinC12= getpeak("run212/ADC!TDC/quadC_12!TDC.dat");
  maxbinC13= getpeak("run212/ADC!TDC/quadC_13!TDC.dat");
  maxbinC14= getpeak("run212/ADC!TDC/quadC_14!TDC.dat");
  maxbinC15= getpeak("run212/ADC!TDC/quadC_15!TDC.dat");
  maxbinC16= getpeak("run212/ADC!TDC/quadC_16!TDC.dat");

  maxbinD1= getpeak("run212/ADC!TDC/quadD_1!TDC.dat");
  maxbinD2= getpeak("run212/ADC!TDC/quadD_2!TDC.dat");
  maxbinD3= getpeak("run212/ADC!TDC/quadD_3!TDC.dat");
  maxbinD4= getpeak("run212/ADC!TDC/quadD_4!TDC.dat");
  maxbinD5= getpeak("run212/ADC!TDC/quadD_5!TDC.dat");
  maxbinD6= getpeak("run212/ADC!TDC/quadD_6!TDC.dat");
  maxbinD7= getpeak("run212/ADC!TDC/quadD_7!TDC.dat");
  maxbinD8= getpeak("run212/ADC!TDC/quadD_8!TDC.dat");
  maxbinD9= getpeak("run212/ADC!TDC/quadD_9!TDC.dat");
  maxbinD10= getpeak("run212/ADC!TDC/quadD_10!TDC.dat");
  maxbinD11= getpeak("run212/ADC!TDC/quadD_11!TDC.dat");
  maxbinD12= getpeak("run212/ADC!TDC/quadD_12!TDC.dat");
  maxbinD13= getpeak("run212/ADC!TDC/quadD_13!TDC.dat");
  maxbinD14= getpeak("run212/ADC!TDC/quadD_14!TDC.dat");
  maxbinD15= getpeak("run212/ADC!TDC/quadD_15!TDC.dat");
  maxbinD16= getpeak("run212/ADC!TDC/quadD_16!TDC.dat");
}


int addADC_He3_0(){



  getmaxbins();

  hHe3_0 = new TH1F("He3 0-50","He3 0-50",4096,0,4095);
  hHe3_0->GetXaxis()->SetTitle("energy in bin");


  readsource("run412/ADC!TDC_0-50/quadA_1!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hHe3_0->AddBinContent(i*1500/maxbinA1, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadA_2!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hHe3_0->AddBinContent(i*1500/maxbinA2, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadA_3!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hHe3_0->AddBinContent(i*1500/maxbinA3, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadA_4!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hHe3_0->AddBinContent(i*1500/maxbinA4, hsource->GetBinContent(i));
  }

  readsource("run412/ADC!TDC_0-50/quadB_1!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hHe3_0->AddBinContent(i*1500/maxbinB1, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadB_2!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hHe3_0->AddBinContent(i*1500/maxbinB2, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadB_3!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hHe3_0->AddBinContent(i*1500/maxbinB3, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadB_4!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hHe3_0->AddBinContent(i*1500/maxbinB4, hsource->GetBinContent(i));
  }

  readsource("run412/ADC!TDC_0-50/quadC_1!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hHe3_0->AddBinContent(i*1500/maxbinC1, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadC_2!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hHe3_0->AddBinContent(i*1500/maxbinC2, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadC_3!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hHe3_0->AddBinContent(i*1500/maxbinC3, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadC_4!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hHe3_0->AddBinContent(i*1500/maxbinC4, hsource->GetBinContent(i));
  }

  readsource("run412/ADC!TDC_0-50/quadD_1!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hHe3_0->AddBinContent(i*1500/maxbinD1, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadD_2!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hHe3_0->AddBinContent(i*1500/maxbinD2, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadD_3!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hHe3_0->AddBinContent(i*1500/maxbinD3, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadD_4!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hHe3_0->AddBinContent(i*1500/maxbinD4, hsource->GetBinContent(i));
  }



  hHe3_0->Draw();

}


int addADC_He3_50(){



  hHe3_50 = new TH1F("He3 50-end","He3 50-end",4096,0,4095);
  hHe3_50->GetXaxis()->SetTitle("energy in bin");


  readsource("run412/ADC!TDC_50-400000/quadA_1!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hHe3_50->AddBinContent(i*1500/maxbinA1, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadA_2!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hHe3_50->AddBinContent(i*1500/maxbinA2, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadA_3!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hHe3_50->AddBinContent(i*1500/maxbinA3, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadA_4!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hHe3_50->AddBinContent(i*1500/maxbinA4, hsource->GetBinContent(i));
  }

  readsource("run412/ADC!TDC_50-400000/quadB_1!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hHe3_50->AddBinContent(i*1500/maxbinB1, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadB_2!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hHe3_50->AddBinContent(i*1500/maxbinB2, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadB_3!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hHe3_50->AddBinContent(i*1500/maxbinB3, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadB_4!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hHe3_50->AddBinContent(i*1500/maxbinB4, hsource->GetBinContent(i));
  }

  readsource("run412/ADC!TDC_50-400000/quadC_1!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hHe3_50->AddBinContent(i*1500/maxbinC1, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadC_2!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hHe3_50->AddBinContent(i*1500/maxbinC2, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadC_3!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hHe3_50->AddBinContent(i*1500/maxbinC3, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadC_4!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hHe3_50->AddBinContent(i*1500/maxbinC4, hsource->GetBinContent(i));
  }

  readsource("run412/ADC!TDC_50-400000/quadD_1!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hHe3_50->AddBinContent(i*1500/maxbinD1, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadD_2!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hHe3_50->AddBinContent(i*1500/maxbinD2, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadD_3!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hHe3_50->AddBinContent(i*1500/maxbinD3, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadD_4!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hHe3_50->AddBinContent(i*1500/maxbinD4, hsource->GetBinContent(i));
  }


  hHe3_50->Draw();

}



int addADC_BF3_0(){


  hBF3_0 = new TH1F("BF3 0-50","BF3 0-50",4096,0,4095);
  hBF3_0->GetXaxis()->SetTitle("energy in bin");



  readsource("run412/ADC!TDC_0-50/quadA_5!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinA5, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadA_6!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinA6, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadA_7!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinA7, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadA_8!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinA8, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadA_9!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinA9, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadA_10!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinA10, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadA_11!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinA11, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadA_12!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinA12, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadA_13!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinA13, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadA_14!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinA14, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadA_15!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinA15, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadA_16!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinA16, hsource->GetBinContent(i));
  }

  readsource("run412/ADC!TDC_0-50/quadB_5!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinB5, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadB_6!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinB6, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadB_7!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinB7, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadB_8!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinB8, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadB_9!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinB9, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadB_10!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinB10, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadB_11!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinB11, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadB_12!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinB12, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadB_13!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinB13, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadB_14!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinB14, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadB_15!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinB15, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadB_16!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinB16, hsource->GetBinContent(i));
  }

  readsource("run412/ADC!TDC_0-50/quadC_5!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinC5, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadC_6!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinC6, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadC_7!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinC7, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadC_8!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinC8, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadC_9!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinC9, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadC_10!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinC10, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadC_11!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinC11, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadC_12!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinC12, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadC_13!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinC13, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadC_14!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinC14, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadC_15!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinC15, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadC_16!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinC16, hsource->GetBinContent(i));
  }


  readsource("run412/ADC!TDC_0-50/quadD_5!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinD5, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadD_6!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinD6, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadD_7!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinD7, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadD_8!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinD8, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadD_9!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinD9, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadD_10!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinD10, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadD_11!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinD11, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadD_12!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinD12, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadD_13!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinD13, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadD_14!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinD14, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadD_15!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinD15, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_0-50/quadD_16!TDC_0-50.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_0->AddBinContent(i*1500/maxbinD16, hsource->GetBinContent(i));
  }


  hBF3_0->Draw();

}


int addADC_BF3_50(){

  hBF3_50 = new TH1F("BF3 50-end","BF3 50-end",4096,0,4095);
  hBF3_50->GetXaxis()->SetTitle("energy in bin");

  readsource("run412/ADC!TDC_50-400000/quadA_5!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinA5, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadA_6!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinA6, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadA_7!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinA7, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadA_8!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinA8, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadA_9!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinA9, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadA_10!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinA10, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadA_11!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinA11, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadA_12!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinA12, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadA_13!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinA13, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadA_14!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinA14, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadA_15!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinA15, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadA_16!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinA16, hsource->GetBinContent(i));
  }


  readsource("run412/ADC!TDC_50-400000/quadB_5!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinB5, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadB_6!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinB6, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadB_7!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinB7, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadB_8!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinB8, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadB_9!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinB9, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadB_10!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinB10, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadB_11!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinB11, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadB_12!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinB12, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadB_13!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinB13, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadB_14!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinB14, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadB_15!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinB15, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadB_16!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinB16, hsource->GetBinContent(i));
  }


  readsource("run412/ADC!TDC_50-400000/quadC_5!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinC5, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadC_6!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinC6, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadC_7!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinC7, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadC_8!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinC8, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadC_9!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinC9, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadC_10!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinC10, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadC_11!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinC11, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadC_12!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinC12, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadC_13!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinC13, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadC_14!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinC14, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadC_15!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinC15, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadC_16!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinC16, hsource->GetBinContent(i));
  }

  readsource("run412/ADC!TDC_50-400000/quadD_5!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinD5, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadD_6!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinD6, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadD_7!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinD7, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadD_8!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinD8, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadD_9!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinD9, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadD_10!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinD10, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadD_11!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinD11, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadD_12!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinD12, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadD_13!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinD13, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadD_14!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinD14, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadD_15!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinD15, hsource->GetBinContent(i));
  }
  readsource("run412/ADC!TDC_50-400000/quadD_16!TDC_50-400000.dat",1);
  for(int i=1;i<4096;i++){
    hBF3_50->AddBinContent(i*1500/maxbinD16, hsource->GetBinContent(i));
  }



  hBF3_50->Draw();

}
