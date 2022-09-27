using namespace mgr;
void Draw_MC_Cross(){

  TFile *fin = new TFile("RootFile/MonoPhotonAnalysis_2018_1000__1.root");
  TDirectory *dir = (TDirectory*)fin->Get("NOTRG");
  TDirectory *dir2 = (TDirectory*)fin->Get("HLT_Photon200");
  dir->cd();
  dir2->cd();
  TH1D *cross  = (TH1D*)dir->Get("Spike");
  TH1D *cross_cut  = (TH1D*)dir2->Get("Flow_dEdxSig_Spike");

  TCanvas *c = new TCanvas ("c","",800,600);
  cross->Draw();
  cross_cut->Draw("hist same");
  c->SetLogy();

}

