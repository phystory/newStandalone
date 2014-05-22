  int maxbin=-1;
  Double_t tempbin=0;
  Double_t all_n=0;
  int i=0; 
Double_t offset=0;

  TH1F *htemp;
  TH1F *htime;
  TH1F *hbackground;  
  TH1F *hmod2;  
  TH1F *htimeInteg;
  TPaveText *pt259 = new TPaveText(0.55,0.25,0.85,0.4, "NDC");


int fit259() {

  readsource("run259/TDC/quadA_2.dat",60627);

  pt259->AddText("run259 - source on top of nero");
  pt259->AddText("source between NERO and top paddle");
  pt259->AddText("using bottom(under NERO) and");
  pt259->AddText("top paddle(on NERO) for start");

  maxbin=hsource->GetMaximumBin();

  gPad->SetLogy(0); 
  gPad->Modified();  

  TString formula1="[0]+[1]*exp(x/[2])";

  TF1* f1 = new TF1("f1",formula1);
  f1->SetParameter(0,003);
  f1->SetParameter(1,05);
  f1->SetParameter(2,-100);
  f1->SetLineColor(2);

  hsource->Fit("f1","","",maxbin,1900);
  //  f1->GetParameter(0);


  // TString formula2="[0]+[1]*x";

  //  TF1* f2 = new TF1("f2",formula2);
  //  f2->SetParameter(0,05);
  //  f2->SetParameter(1,05);
  //  f2->SetLineColor(2);

  //  hsource->Fit("f2","","",1982,2010);

  offset=f1->GetParameter(0);

  TF1* f3 = new TF1("f3","[0]",0,3000);
  f3->SetParameter(0,offset);
  f3->SetLineColor(3);
  f3->Draw("same");


  //  tempbin= (f1->GetParameter(0) - f2->GetParameter(0)) /  f2->GetParameter(1);

  tempbin=maxbin;

  //cout << "bin number of edge (by lin fit) = " << tempbin << endl;



  


  pt259->Draw();


  cout << "end of fit procedure" <<endl;

}




double modIntegrate_corr(int x1, int x2) {


  Double_t n=0;


  n=htemp->Integral(x1,x2);

  //function uses average of first 1000 bins for background subtract


  return n;

}


double percent_mod(int t) {

  return modIntegrate_corr(maxbin,t) / modIntegrate_corr(maxbin,1900);

}


int show_histo_mod259() {



  fit259();

  hmod2 = new TH1F("hmod2","hmod2",int(1900),0,int(1900-1));
  htemp = new TH1F("htemp","htemp",4096,0,4096);
  hbackgr = new TH1F("hbackgr","hbackgr",4096,0,4095);


  f3->SetParameter(0,offset);

  for(i=0;i<int(4095);i=i+1) {
    hbackgr->SetBinContent(i,offset);
  }

  (*htemp) = (*hsource) - (*hbackgr);


  for(i=0;i<int(4095);i=i+1) {
    if (htemp->GetBinContent(i)<0) {
      htemp->SetBinContent(i,0);
    }
    htemp->SetBinError(i,0);
  }

  cout << "fill hmod2..." << endl;
  for(i=maxbin;i<);i=i+1) {

    // cout << "bin= " << i << "  Percent= " << percent_mod(i)<< endl;
    hmod2->Fill(i, percent_mod(i));
  }
  cout << "ended" << endl;

  hmod2->SetTitle("run259 - Percent of all det. neutrons vs. moderation time");
  hmod2->SetXTitle("moderation time in TDC bins (binwidth 0.2 microsec)");
  hmod2->SetYTitle("Percent of neutrons");
  hmod2->SetAxisRange(0,int(tempbin+10.5));
  
  // htemp->Draw();

}



int Compare259(){

  htime = new TH1F("htime","htime",4096,0,4096);
  htime->Reset();
  for (i=maxbin;i<1900;i=i+1){
    
    htime->SetBinContent(i-maxbin,htemp->GetBinContent(i)/htemp->Integral(htemp->GetMaximumBin(),1900));
  }

  //*********************just take maximum bin for start signal**********************//

  TF1* f10 = new TF1("f10","1/[0]*exp(-x/[0])",0,3000);
  
  f10->SetParameter(0,200);
  //  f10->SetParameter(1,200);
  htime->Fit("f10","","",0,1900);
  f10->SetLineColor(2);
  f10->Draw("same");


}


int ShowYield(){


  //experimental histogram -> % moderated vs. time

  htimeInteg = new TH1F("htime","htime",4096,0,4096);
  htimeInteg->GetXaxis()->SetTitle("mod. time in TDC-bins (binwidth=0.2microsec");
  htimeInteg->SetTitle("% of detected neutrons within moderation time");
  
  for (i=0,i<1900;i=i+1) {
    htimeInteg->Fill(i,htime->Integral(0,i));
    //   htimeInteg->SetBinContent(htemp->Integral(i,htime->Integral(0,i)));
  }


  //experiment fit -> % moderated vs. time

  TF1* fexp = new TF1("fexp","1-exp(-x/[0])",0,3000);
  fexp->SetParameter(0,f10->GetParameter(0));
  fexp->SetLineColor(2);


  //simulation fit -> % moderated vs. time

  TF1* fsim = new TF1("fsim","1-exp(-x/559.70068)",0,3000);
  fsim->SetLineColor(3);

  htimeInteg->Draw();
  fexp->Draw("same");
  fsim->Draw("same"); 

}



int go259(){

  show_histo_mod259();
  Compare259();
  ShowYield();  

  pt259->Draw();
}




int Output259(){

  TCanvas* c1 = new TCanvas("c1","c1",800,600);
  c1->Divide(1,2);
  c1->cd(1);
  hsource->Draw();
  f1->Draw("same");
  f3->Draw("same");

  c1->cd(2);
  hmod2->Draw();

}

int Print259(){

  for(i=0;i<2040;i=i+20){
    cout << htimeInteg->GetBinContent(i) << endl;

  }

}
