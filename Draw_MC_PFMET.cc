
  using namespace mgr;
void Draw_MC_PFMET(){
  TFile *fin = new TFile("RootFile/MonoPFMETAnlysis_2018_1000.root");
  TDirectory *dir = (TDirectory*)fin->Get("NOTRG");
  dir->cd();
  TH1D *h_OnlyOnePF = (TH1D*)dir->Get("PFMETvsOnlyOnePF");
  TH1D *h_OneCandOnePF = (TH1D*)dir->Get("PFMETvsOneCandOnePF");
  TH1D *h_TwoPF = (TH1D*)dir->Get("PFMETvsTwoPF");

  gStyle->SetOptStat(0);
  TCanvas *c = new TCanvas("c","",800,600);
  h_OnlyOnePF->Draw();
  h_OnlyOnePF->GetXaxis()->SetTitle("MET (GeV)");
  h_OnlyOnePF->GetYaxis()->SetTitle("Entries");
  mgr::DrawCMSLabelOuter(SIMULATION);
  mgr::SetAxis(h_OnlyOnePF);
  mgr::SetSinglePad(c);
  mgr::DrawEntryRight(("2018 Mass 1000 GeV #sqrt{s} = 13 TeV"));
  c->SaveAs("h_OnlyOnePF.pdf");
  cout<<"mean MET "<<h_OnlyOnePF->GetMean()<<endl;


  h_OneCandOnePF->Draw();
  h_OneCandOnePF->Draw();
  h_OneCandOnePF->GetXaxis()->SetTitle("MET (GeV)");
  h_OneCandOnePF->GetYaxis()->SetTitle("Entries");
  mgr::DrawCMSLabelOuter(SIMULATION);
  mgr::SetAxis(h_OneCandOnePF);
  mgr::SetSinglePad(c);
  mgr::DrawEntryRight(("2018 Mass 1000 GeV #sqrt{s} = 13 TeV"));
  c->SaveAs("h_OneCandOnePF.pdf");
  cout<<"mean MET "<<h_OneCandOnePF->GetMean()<<endl;

  h_TwoPF->Draw();
  h_TwoPF->Draw();
  h_TwoPF->GetXaxis()->SetTitle("MET (GeV)");
  h_TwoPF->GetYaxis()->SetTitle("Entries");
  mgr::DrawCMSLabelOuter(SIMULATION);
  mgr::SetAxis(h_TwoPF);
  mgr::SetSinglePad(c);
  mgr::DrawEntryRight(("2018 Mass 1000 GeV #sqrt{s} = 13 TeV"));
  c->SaveAs("h_TwoPF.pdf");
  cout<<"mean MET "<<h_TwoPF->GetMean()<<endl;
}
