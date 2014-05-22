int fit() {
  
  cout << "start of fit procedure" << endl;

  readsource("run386/CRS/CRS_QDC_00!qdc00.dat",14013);
  readbackgr("run371/CRS/CRS_QDC_00!qdc00.dat",56948);
  corr();

  TPaveText *pt = new TPaveText(0.65,0.7,0.85,0.85, "NDC");
  pt->AddText("run386-run371");
  pt->AddText("Mn54");
  pt->AddText("ch00 - box I");


  int maxbin=-1;
  Double_t maxvalue=-1;
  Double_t tempbin=0;
  Double_t tempbinerror=0;

  TString text="";

  hcorr->GetXaxis()->SetRange(200,4000);
  maxbin=hcorr->GetMaximumBin();
  maxvalue=hcorr->GetBinContent(maxbin);
  hcorr->GetXaxis()->SetRange(0,4095);

  TF1* f1 = new TF1("f1","[0]*exp(-((x-[1])^2)/[2])");
  f1->SetParameter(0,maxvalue);
  f1->SetParameter(1,maxbin);
  f1->SetParameter(2,1);

  f1->SetLineColor(2);

  hcorr->SetMinimum(0);
  hcorr->SetMaximum(1.2*maxvalue);

  hcorr->Fit("f1","","",maxbin-maxbin/6,4095);

  pt->Draw();


  tempbin=sqrt(-log(maxvalue*2/3/(f1->GetParameter(0)))*(f1->GetParameter(2)))+f1->GetParameter(1);

  c1->SaveAs("PDF/energycalib/run386-Mn54-boxI.pdf");


  tempbinerror=sqrt( (1/(2*sqrt(-log(maxvalue*2/3/(f1->GetParameter(0)))*(f1->GetParameter(2)))+f1->GetParameter(1)) * f1->GetParError(0)/f1->GetParameter(0))**2 +

   ( 1/(2*sqrt(-log(maxvalue*2/3/(f1->GetParameter(0)))*(f1->GetParameter(2)))+f1->GetParameter(1)) *(-log(maxvalue*2/3/(f1->GetParameter(2))))*f1->GetParError(2))**2   +  

   ( 1/(2*sqrt(-log(maxvalue*2/3/(f1->GetParameter(0)))*(f1->GetParameter(2)))+f1->GetParameter(1))*f1->GetParError(1))**2              );







  cout << "2/3 of maximum height is in      tempbin = " << tempbin << "->" <<int(tempbin+0.5) << endl;
  cout << "                            tempbinerror = " << tempbinerror << endl;

  
  cout << endl << "max bin = " << maxbin << " with content = " << maxvalue << endl;



}
