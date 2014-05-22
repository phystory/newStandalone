  int maxbin=-1;
  Double_t tempbin=0;
  Double_t all_n=0;
  int i=0;




int fit249() {

  readsource("run249/TDC/quadA_2.dat",55367);

  maxbin=hsource->GetMaximumBin();

  gPad->SetLogy(0); 
  gPad->Modified();  

  TString formula1="[0]+[1]*exp(x/[2])";

  TF1* f1 = new TF1("f1",formula1);
  f1->SetParameter(0,05);
  f1->SetParameter(1,05);
  f1->SetParameter(2,maxbin/2);
  f1->SetLineColor(2);

  hsource->Fit("f1","","",0,maxbin);
  f1->GetParameter(0);


  TString formula2="[0]+[1]*x";

  TF1* f2 = new TF1("f2",formula2);
  f2->SetParameter(0,05);
  f2->SetParameter(1,05);
  f2->SetLineColor(2);

  hsource->Fit("f2","","",1980,2007);


  //  TF1* f3 = new TF1("f3","5.35268e-03",0,3000);
  //  f3->SetLineColor(3);
  //  f3->Draw("same");


  tempbin= (f1->GetParameter(0) - f2->GetParameter(0)) /  f2->GetParameter(1);


  cout << "bin number of edge (by lin fit) = " << tempbin << endl;


  all_n = f1->Integral(0,int(tempbin+0.5)) - f1->GetParameter(0)*int(tempbin+0.5);

  cout << "number of all det. neutrons = " << all_n << endl;


  



  TPaveText *pt = new TPaveText(0.55,0.75,0.85,0.85, "NDC");
  pt->AddText("run249 - source on top of NERO.");
  pt->AddText("bottom paddle above source");
  pt->AddText("using only one paddle (bottom)");

  pt->Draw();

  int startbin=2000;

  cout << "background corrected integral from " << startbin << " to end-edge " << int(tempbin+0.5) << "= " << modIntegrate_corr(startbin,int(tempbin+0.5))  <<endl;

}




double modIntegrate_corr(int x1, int x2) {

  Double_t n=0;
  //  cout << "start" << endl;
  n=f1->Integral(x1,x2) - f1->GetParameter(0)*(x2-x1);

  if (n<0) n=0;

  return n;

}


double percent_mod(int t) {

  return modIntegrate_corr(int(tempbin+0.5)-t,int(tempbin+0.5))/modIntegrate_corr(0,int(tempbin+0.5));

}


int show_histo_mod249() {


  fit249();

  TH1F *hmod1;  
  hmod1 = new TH1F("hmod1","hmod1",int(tempbin+10.5),0,int(tempbin+10.5)-1);

  //  cout << percent_mod(1800)  << endl;

  for(i=0;i<int(tempbin+0.5);i=i+1) {

    // cout << "bin= " << i << "  Percent= " << percent_mod(i)<< endl;

    hmod1->Fill(i, percent_mod(i));
  }


  TF1* f4 = new TF1("f4","-251183.3333*exp(0.00012*x)",0,3000);
  f4->SetLineColor(3);
  //  f4->Draw("same");


  hmod1->SetTitle("run249 - Percent of all det. neutrons vs. moderation time");
  hmod1->SetXTitle("moderation time in TDC bins (binwidth=0.2microsec)");
  hmod1->SetYTitle("Percent of neutrons");
  hmod1->SetAxisRange(0,int(tempbin+0.5)+25);
  hmod1->Draw();
  f4->Draw("same");

}


int Output249(){

  TCanvas* c1 = new TCanvas("c1","c1",800,600);
  c1->Divide(1,2);
  c1->cd(1);
  hsource->Draw();
  f1->Draw("same");

  c1->cd(2);
  hmod1->Draw();


}
