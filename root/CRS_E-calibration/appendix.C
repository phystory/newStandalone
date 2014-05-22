int appendix_backgr_boxI(){


  readbackgr("run371/CRS/CRS_QDC_00!qdc00.dat",56948);

  TPaveText *pt = new TPaveText(0.65,0.7,0.85,0.85, "NDC");
  pt->AddText("run371");
  pt->AddText("background");
  pt->AddText("box I (QDC ch00)");

  hbackgr->GetXaxis()->SetTitle("QDC energy [bin]");
  hbackgr->SetTitle("Background - box I");
  hbackgr->SetYTitle("counts/sec");

  TCanvas* c1=new TCanvas("c1","c1",800,270);
  hbackgr->Draw();
  pt->Draw("same");
  c1->SaveAs("appendix/boxI-backgr.eps");

}

int appendix_backgr_boxII(){

  readbackgr("run371/CRS/CRS_QDC_01!qdc01.dat",56948);

  TPaveText *pt = new TPaveText(0.65,0.7,0.85,0.85, "NDC");
  pt->AddText("run371");
  pt->AddText("background");
  pt->AddText("box II (QDC ch01)");

  hbackgr->GetXaxis()->SetTitle("QDC energy [bin]");
  hbackgr->SetTitle("Background - box II");
  hbackgr->SetYTitle("counts/sec");

  TCanvas* c1=new TCanvas("c1","c1",800,270);
  hbackgr->Draw();
  pt->Draw("same");
  c1->SaveAs("appendix/boxII-backgr.eps");

}


int appendix_ba133_boxI(){

  readsource("run373/CRS/CRS_QDC_00!qdc00.dat",7224);
  readbackgr("run371/CRS/CRS_QDC_00!qdc00.dat",56948);
  corr();

  TPaveText *pt = new TPaveText(0.65,0.65,0.85,0.85, "NDC");
  pt->AddText("run373");
  pt->AddText("Ba-133 corrected");
  pt->AddText("box I (QDC ch00)");
  pt->AddText("compton edge at 610+-30");

  hcorr->GetXaxis()->SetTitle("QDC energy [bin]");
  hcorr->SetTitle("Ba-133 - box I");
  hcorr->SetYTitle("counts/sec");

  TCanvas* c1=new TCanvas("c1","c1",800,270);
  hcorr->Draw();
  pt->Draw("same");
  c1->SaveAs("appendix/boxI-Ba-133.eps");

}

int appendix_ba133_boxII(){

  readsource("run372/CRS/CRS_QDC_01!qdc01.dat",7214);
  readbackgr("run371/CRS/CRS_QDC_01!qdc01.dat",56948);
  corr();

  TPaveText *pt = new TPaveText(0.65,0.65,0.85,0.85, "NDC");
  pt->AddText("run372");
  pt->AddText("Ba-133 corrected");
  pt->AddText("box II (QDC ch01)");
  pt->AddText("compton edge at 496+-20");

  hcorr->GetXaxis()->SetTitle("QDC energy [bin]");
  hcorr->SetTitle("Ba-133 - box II");
  hcorr->SetYTitle("counts/sec");

  TCanvas* c1=new TCanvas("c1","c1",800,270);
  hcorr->Draw();
  pt->Draw("same");
  c1->SaveAs("appendix/boxII-Ba-133.eps");

}

int appendix_cs137_boxI(){

  readsource("run370/CRS/CRS_QDC_00!qdc00.dat",7215);
  readbackgr("run371/CRS/CRS_QDC_00!qdc00.dat",56948);
  corr();

  TPaveText *pt = new TPaveText(0.65,0.65,0.85,0.85, "NDC");
  pt->AddText("run370");
  pt->AddText("Cs-137 corrected");
  pt->AddText("box I (QDC ch00)");
  pt->AddText("compton edge at 860+-8");

  hcorr->GetXaxis()->SetTitle("QDC energy [bin]");
  hcorr->SetTitle("Cs-137 - box I");
  hcorr->SetYTitle("counts/sec");

  TCanvas* c1=new TCanvas("c1","c1",800,270);
  hcorr->Draw();
  pt->Draw("same");
  c1->SaveAs("appendix/boxI-Cs-137.eps");

}

int appendix_cs137_boxII(){

  readsource("run369/CRS/CRS_QDC_01!qdc01.dat",7202);
  readbackgr("run371/CRS/CRS_QDC_01!qdc01.dat",56948);
  corr();

  TPaveText *pt = new TPaveText(0.65,0.65,0.85,0.85, "NDC");
  pt->AddText("run369");
  pt->AddText("Cs-137 corrected");
  pt->AddText("box II (QDC ch01)");
  pt->AddText("compton edge at 809+-20");

  hcorr->GetXaxis()->SetTitle("QDC energy [bin]");
  hcorr->SetTitle("Cs-137 - box II");
  hcorr->SetYTitle("counts/sec");

  TCanvas* c1=new TCanvas("c1","c1",800,270);
  hcorr->Draw();
  pt->Draw("same");
  c1->SaveAs("appendix/boxII-Cs-137.eps");

}

int appendix_mn54_boxI(){

  readsource("run386/CRS/CRS_QDC_00!qdc00.dat",14013);
  readbackgr("run371/CRS/CRS_QDC_00!qdc00.dat",56948);
  corr();

  TPaveText *pt = new TPaveText(0.65,0.65,0.85,0.85, "NDC");
  pt->AddText("run386");
  pt->AddText("Mn-54 corrected");
  pt->AddText("box I (QDC ch00)");
  pt->AddText("compton edge at 913+-13");

  hcorr->GetXaxis()->SetTitle("QDC energy [bin]");
  hcorr->SetTitle("Mn-54 - box I");
  hcorr->SetYTitle("counts/sec");

  TCanvas* c1=new TCanvas("c1","c1",800,270);
  hcorr->Draw();
  pt->Draw("same");
  c1->SaveAs("appendix/boxI-Mn-54.eps");

}

int appendix_mn54_boxII(){

  readsource("run385/CRS/CRS_QDC_01!qdc01.dat",15041);
  readbackgr("run371/CRS/CRS_QDC_01!qdc01.dat",56948);
  corr();

  TPaveText *pt = new TPaveText(0.65,0.65,0.85,0.85, "NDC");
  pt->AddText("run385");
  pt->AddText("Mn-54 corrected");
  pt->AddText("box II (QDC ch01)");
  pt->AddText("compton edge at 980+-13");

  hcorr->GetXaxis()->SetTitle("QDC energy [bin]");
  hcorr->SetTitle("Mn-54 - box II");
  hcorr->SetYTitle("counts/sec");

  TCanvas* c1=new TCanvas("c1","c1",800,270);
  hcorr->Draw();
  pt->Draw("same");
  c1->SaveAs("appendix/boxII-Mn-54.eps");

}

int appendix_co60_boxI(){

  readsource("run375/CRS/CRS_QDC_00!qdc00.dat",69024);
  readbackgr("run371/CRS/CRS_QDC_00!qdc00.dat",56948);
  corr();

  TPaveText *pt = new TPaveText(0.65,0.65,0.85,0.85, "NDC");
  pt->AddText("run375");
  pt->AddText("Co-60 corrected");
  pt->AddText("box I (QDC ch00)");
  pt->AddText("compton edge at 1221+-8");

  hcorr->GetXaxis()->SetTitle("QDC energy [bin]");
  hcorr->SetTitle("Co-60 - box I");
  hcorr->SetYTitle("counts/sec");

  TCanvas* c1=new TCanvas("c1","c1",800,270);
  hcorr->Draw();
  pt->Draw("same");
  c1->SaveAs("appendix/boxI-Co-60.eps");

}

int appendix_co60_boxII(){

  readsource("run374/CRS/CRS_QDC_01!qdc01.dat",64343);
  readbackgr("run371/CRS/CRS_QDC_01!qdc01.dat",56948);
  corr();

  TPaveText *pt = new TPaveText(0.65,0.65,0.85,0.85, "NDC");
  pt->AddText("run374");
  pt->AddText("Co-60 corrected");
  pt->AddText("box II (QDC ch01)");
  pt->AddText("compton edge at 1054+-8");

  hcorr->GetXaxis()->SetTitle("QDC energy [bin]");
  hcorr->SetTitle("Co-60 - box II");
  hcorr->SetYTitle("counts/sec");

  TCanvas* c1=new TCanvas("c1","c1",800,270);
  hcorr->Draw();
  pt->Draw("same");
  c1->SaveAs("appendix/boxII-Co-60.eps");

}




int go(){

  appendix_backgr_boxI();
  appendix_backgr_boxII();
  appendix_ba133_boxI();
  appendix_ba133_boxII();
  appendix_cs137_boxI();
  appendix_cs137_boxII();
  appendix_mn54_boxI();
  appendix_mn54_boxII();
  appendix_co60_boxI();
  appendix_co60_boxII();

}
