int fit() {
  
  cout << "start of fit procedure" << endl;

  //----------------------------------------------------------

  TString background="run242/CRS/CRS_QDC_01.dat";
  TString source="run242/CRS/CRS_QDC_01.dat";


  TString describe="Cs-137 corrected";
  TString save="run242_ch01.jpg";

  readbackgr(background,86407);
  readsource(source,62390);


  //----------------------------------------------------------



  corr();

  TString formula="[0]*exp(-((x-[1])^2)/[2])";


  TCanvas* c1 = new TCanvas("c1","c1",800,600);



  int maxbin=-1;
  Double_t maxvalue=-1;
  Double_t tempbin=0;

  TString text="";

  hcorr->GetXaxis()->SetRange(300,4000);
  maxbin=hcorr->GetMaximumBin();
  maxvalue=hcorr->GetBinContent(maxbin);
  hcorr->GetXaxis()->SetRange(0,4095);

  TF1* f1 = new TF1("f1",formula);
  f1->SetParameter(0,maxvalue);
  f1->SetParameter(1,maxbin);
  f1->SetParameter(2,1);

  f1->SetLineColor(2);

  hcorr->SetMinimum(0);
  hcorr->SetMaximum(1.2*maxvalue);
  gStyle->SetOptFit(0111);
  gStyle->SetOptStat(00000011)

    //hcorr->Fit("f1","","",maxbin-maxbin/6,4095);
  hcorr->Fit("f1","","",maxbin,maxbin+maxbin/2);


  TPaveText *pt = new TPaveText(0.3,0.83,0.5,0.88, "NDC");
  pt->AddText(describe);
  pt->AddText(source);
  pt->Draw();

  TPaveText *pt2 = new TPaveText(0.3,0.78,0.5,0.83, "NDC");
  pt2->AddText(formula);
  pt2->Draw();


  tempbin=sqrt(-log(maxvalue*2/3/(f1->GetParameter(0)))*(f1->GetParameter(2)))+f1->GetParameter(1);

  cout << "2/3 of maximum height is in bin " << tempbin << "->" <<int(tempbin+0.5) << endl;

  cout << endl << "max bin = " << maxbin << " with content = " << maxvalue << endl;

  c1->SaveAs(save);

}
