int fit() {
  
  cout << "start of fit procedure" << endl;

  //  readsource("run374/CRS/CRS_QDC_01!qdc01.dat",64343);
  readbackgr("run377/CRS/CRS_QDC_01!qdc01.dat",251);
  readsource("run377/CRS/CRS_QDC_00!qdc00.dat",251);
  corr();

  TPaveText *pt = new TPaveText(0.65,0.7,0.85,0.85, "NDC");
  pt->AddText("run374-run371");
  pt->AddText("Co60");
  pt->AddText("ch01 - box II");

  /*
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
  f1->SetParameter(2,500);

  f1->SetLineColor(2);

  hcorr->SetMinimum(0);
  hcorr->SetMaximum(1.2*maxvalue);

  hcorr->Fit("f1","","",900,4095);
  //  hcorr->Fit("f1","","",maxbin-maxbin/6,4095);

  pt->Draw();


  tempbin=sqrt(-log(maxvalue*2/3/(f1->GetParameter(0)))*(f1->GetParameter(2)))+f1->GetParameter(1);

  c1->SaveAs("PDF/energycal/run374-Co60-boxII.pdf");


  tempbinerror=sqrt( (1/(2*sqrt(-log(maxvalue*2/3/(f1->GetParameter(0)))*(f1->GetParameter(2)))+f1->GetParameter(1)) * f1->GetParError(0)/f1->GetParameter(0))**2 +

   ( 1/(2*sqrt(-log(maxvalue*2/3/(f1->GetParameter(0)))*(f1->GetParameter(2)))+f1->GetParameter(1)) *(-log(maxvalue*2/3/(f1->GetParameter(2))))*f1->GetParError(2))**2   +  

   ( 1/(2*sqrt(-log(maxvalue*2/3/(f1->GetParameter(0)))*(f1->GetParameter(2)))+f1->GetParameter(1))*f1->GetParError(1))**2              );







  cout << "2/3 of maximum height is in      tempbin = " << tempbin << "->" <<int(tempbin+0.5) << endl;
  cout << "                            tempbinerror = " << tempbinerror << endl;

  
  cout << endl << "max bin = " << maxbin << " with content = " << maxvalue << endl;

  */

}
