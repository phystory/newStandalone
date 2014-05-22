int gorun371(){

  showbackgr_ch0();
  showbackgr_ch1();
  showbackgr_ch0_0();
  showbackgr_ch1_1();
  showbackgr_ch0_1();
  showbackgr_ch1_0();

}




int showbackgr_ch0(){

  TCanvas* c1=new TCanvas("c1","c1",800,800);
  readbackgr("run371/CRS/CRS_QDC_00.dat",56948);
  hbackgr->SetAxisRange(0.0001,150,"Y");
  hbackgr->SetTitle("background");
  hbackgr->GetXaxis()->SetTitle("QDC bin");
  hbackgr->SetYTitle("counts/sec");
  gPad->SetLogy(1);

  TPaveText *pt = new TPaveText(0.65,0.7,0.85,0.85, "NDC");
  pt->AddText("run371");
  pt->AddText("raw data");
  pt->AddText("ch00 - box I");
  pt->Draw();

  gStyle->SetOptStat(1000001);
  gPad->Modified();

  c1->SaveAs("CRS_backgr_run371/qdc00.eps");

}



int showbackgr_ch1(){

  TCanvas* c1=new TCanvas("c1","c1",800,800);
  readbackgr("run371/CRS/CRS_QDC_01.dat",56948);
  hbackgr->SetAxisRange(0.0001,150,"Y");
  hbackgr->SetTitle("background");
  hbackgr->GetXaxis()->SetTitle("QDC bin");
  hbackgr->SetYTitle("counts/sec");
  gPad->SetLogy(1);

  TPaveText *pt = new TPaveText(0.65,0.7,0.85,0.85, "NDC");
  pt->AddText("run371");
  pt->AddText("raw data");
  pt->AddText("ch01 - box II");
  pt->Draw();

  gStyle->SetOptStat(1000001);
  gPad->Modified();

  c1->SaveAs("CRS_backgr_run371/qdc01.eps");

}


int showbackgr_ch0_0(){

  TCanvas* c1=new TCanvas("c1","c1",800,800);
  readbackgr("run371/CRS/CRS_QDC_00!qdc00.dat",56948);
// fit();
  hbackgr->SetAxisRange(0,0.27,"Y");

  hbackgr->SetTitle("background");
  hbackgr->GetXaxis()->SetTitle("QDC bin");
  hbackgr->SetYTitle("counts/sec");
//  gPad->SetLogy(1);

  TPaveText *pt = new TPaveText(0.65,0.7,0.85,0.85, "NDC");
  pt->AddText("run371");
  pt->AddText("software threshold");
  pt->AddText("ch00 - box I");
  pt->Draw();

  gStyle->SetOptStat(1000001);
  gPad->Modified();

  c1->SaveAs("CRS_backgr_run371/qdc00!qdc00.eps");

}


int showbackgr_ch1_1(){

  TCanvas* c1=new TCanvas("c1","c1",800,800);
  readbackgr("run371/CRS/CRS_QDC_01!qdc01.dat",56948);
//  fit();
  hbackgr->SetAxisRange(0,0.27,"Y");
  hbackgr->SetTitle("background");
  hbackgr->GetXaxis()->SetTitle("QDC bin");
  hbackgr->SetYTitle("counts/sec");
//  gPad->SetLogy(1);

  TPaveText *pt = new TPaveText(0.65,0.7,0.85,0.85, "NDC");
  pt->AddText("run371");
  pt->AddText("software threshold");
  pt->AddText("ch01 - box II");
  pt->Draw();

  gStyle->SetOptStat(1000001);
  gPad->Modified();

  c1->SaveAs("CRS_backgr_run371/qdc01!qdc01.eps");

}


int showbackgr_ch0_1(){

  TCanvas* c1=new TCanvas("c1","c1",800,800);
  readbackgr("run371/CRS/CRS_QDC_00!qdc01.dat",56948);
//  fit();
  hbackgr->SetAxisRange(0,0.01,"Y");

  hbackgr->SetTitle("background");
  hbackgr->GetXaxis()->SetTitle("QDC bin");
  hbackgr->SetYTitle("counts/sec");
//  gPad->SetLogy(1);

  TPaveText *pt = new TPaveText(0.65,0.7,0.85,0.85, "NDC");
  pt->AddText("run371");
  pt->AddText("coincidence with ch01_thresh.");
  pt->AddText("ch00 - box I");
  pt->Draw();

  gStyle->SetOptStat(1000001);
  gPad->Modified();

  c1->SaveAs("CRS_backgr_run371/qdc00!qdc01.eps");

}


int showbackgr_ch1_0(){

  TCanvas* c1=new TCanvas("c1","c1",800,800);


  readbackgr("run371/CRS/CRS_QDC_01!qdc00.dat",56948);
//  fit();
  hbackgr->SetAxisRange(0,0.01,"Y");
  hbackgr->SetTitle("background");
  hbackgr->GetXaxis()->SetTitle("QDC bin");
  hbackgr->SetYTitle("counts/sec");
//  gPad->SetLogy(1);

  TPaveText *pt = new TPaveText(0.65,0.7,0.85,0.85, "NDC");
  pt->AddText("run371");
  pt->AddText("coincidence with ch01_thresh.");
  pt->AddText("ch01 - box II");
  pt->Draw();

  gStyle->SetOptStat(1000001);
  gPad->Modified();

  c1->SaveAs("CRS_backgr_run371/qdc01!qdc00.eps");

}



int fit(){

  int maxbin=hbackgr->GetMaximumBin();
  Double_t maxvalue = hbackgr->GetBinContent(maxbin);

  TF1* f1 = new TF1("f1","[0]*exp(-((x-[1])^2)/[2])");
  f1->SetLineColor(2);
//  f1->SetParameter(0,maxvalue);
//  f1->SetParameter(1,maxbin);

  f1->SetParameter(0,0.0075);
  f1->SetParameter(1,2100);

  f1->SetParameter(2,1);
//  hbackgr->Fit("f1","","",maxbin-250,maxbin+200);
  hbackgr->Fit("f1","","",1750,2400);
}

int integral_all(){

  double integ=0;
  double integError=0;

  for(Int_t i=1;i<4096;i++){
     integ = integ + hbackgr->GetBinContent(i);
     integError=integError+hbackgr->GetBinError(i)**2;
  }

  integError=sqrt(integError);

  cout << integ << " +- " << integError << endl; 

}
