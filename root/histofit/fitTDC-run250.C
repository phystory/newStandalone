  int maxbin=-1;
  Double_t tempbin=0;
  Double_t all_n=0;
  int i=0; 

  TH1F *htemp;  
  TH1F *hbackground;  


int fit250() {

  readsource("run250/TDC/quadA_2.dat",255128);

  maxbin=hsource->GetMaximumBin();

  gPad->SetLogy(0); 
  gPad->Modified();  

  TString formula1="[0]+[1]*exp(x/[2])";

  TF1* f1 = new TF1("f1",formula1);
  f1->SetParameter(0,05);
  f1->SetParameter(1,05);
  f1->SetParameter(2,maxbin/2);
  f1->SetLineColor(2);

  hsource->Fit("f1","","",1500,maxbin);
  f1->GetParameter(0);


  TString formula2="[0]+[1]*x";

  TF1* f2 = new TF1("f2",formula2);
  f2->SetParameter(0,05);
  f2->SetParameter(1,05);
  f2->SetLineColor(2);

  hsource->Fit("f2","","",1988,2015);


  TF1* f3 = new TF1("f3","3.24591185512053924e-03",0,3000);
  f3->SetLineColor(3);
  f3->Draw("same");

  double linearbackgr = f1->GetParameter(0);

  tempbin= (f1->GetParameter(0) - f2->GetParameter(0)) /  f2->GetParameter(1);


  cout << "bin number of edge (by lin fit) = " << tempbin << endl;

 
  all_n = f1->Integral(0,int(tempbin+0.5)) - f1->GetParameter(0)*int(tempbin);

  cout << "number of all det. neutrons = " << all_n << endl;


  



  TPaveText *pt = new TPaveText(0.55,0.75,0.85,0.85, "NDC");
  pt->AddText("run250 - source in NERO (holder).");
  pt->AddText("bottom paddle at end of NERO, closing the beamline");
  pt->AddText("using only one paddle (bottom)");

  pt->Draw();

  int startbin=2000;

  cout << "background corrected integral from " << startbin << " to end-edge " << int(tempbin+0.5) << "= " << modIntegrate_corr(startbin,int(tempbin+0.5))  <<endl;

}




double modIntegrate_corr(int x1, int x2) {


  Double_t n=0;

  //  cout << "start" << endl;
  //  n=f1->Integral(x1,x2) - f1->GetParameter(0)*(x2-x1); // function uses exponential offset for background subtract

  n=f1->Integral(x1,x2) - hsource->Integral(0,1000)/1000*(x2-x1);  

  //function uses average of first 1000 bins for background subtract

  if (n<0) n=0;

  return n;

}


double percent_mod(int t) {

  return modIntegrate_corr(int(tempbin+0.5)-t,int(tempbin+0.5))/modIntegrate_corr(0,int(tempbin+0.5));

}


int show_histo_mod250() {



  fit250();

  // TH1F *hmod2;  
  hmod2 = new TH1F("hmod2","hmod2",int(tempbin+10.5),0,int(tempbin+10.5)-1);

  // TH1F *hbackground;  
  hbackground = new TH1F("hbackground","hbackground",4096,0,4096);
 
  //  TH1F *htemp;  
  htemp = new TH1F("htemp","htemp",4096,0,4096);

    for(i=0;i<int(tempbin+0.5);i=i+1) {
      hbackground->Fill(i,0.2);
    }

    (*htemp) = (*hbackground);
 
   for(i=0;i<int(tempbin+0.5);i=i+1) {
     if (htemp->GetBinContent(i)<0) htemp->SetBinContent(0);
    }


  //  cout << percent_mod(1800)  << endl;

  for(i=0;i<int(tempbin+0.5);i=i+1) {

    // cout << "bin= " << i << "  Percent= " << percent_mod(i)<< endl;

    hmod2->Fill(i, percent_mod(i));
  }


  hmod2->SetTitle("run250 - Percent of all det. neutrons vs. moderation time");
  hmod2->SetXTitle("moderation time in TDC bins (binwidth=0.2microsec)");
  hmod2->SetYTitle("Percent of neutrons");
  hmod2->SetAxisRange(0,int(tempbin+10.5));
  hmod2->Draw();

  htemp->Draw();

}


int Output250(){

  TCanvas* c1 = new TCanvas("c1","c1",800,600);
  c1->Divide(1,2);
  c1->cd(1);
  hsource->Draw();
  f1->Draw("same");
  f3->Draw("same");

  c1->cd(2);
  hmod2->Draw();


}
