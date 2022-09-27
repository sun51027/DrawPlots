//
//	ABCD plots for MC
//
#include <string>
using namespace std;
void Draw_MC_ABCD()
{

  TCanvas *canvas = new TCanvas("canvas", "", 800, 600);
  gStyle->SetOptStat(0);

  string mass[10];
  mass[1] = "1000";
  mass[2] = "1500";
  mass[3] = "2000";
  mass[4] = "2500";
  mass[5] = "3000";
  mass[6] = "3500";
  mass[7] = "4000";
  mass[8] = "4500";

  string year[10];
  year[1] = "2018";
  year[2] = "2017";
  year[3] = "2016";
  year[4] = "2016APV";

  TDirectory *dir[50];
  TFile      *fin[50];
  // 17, 18:
  // 1~8, 11~18
  for (int i = 1; i <= 8; i++) {
 //   fin[i] = new TFile(("RootFile/MonoPhotonAnalysis_" + year[1] + "_" + mass[i] + "_0.root").c_str());
    fin[i] = new TFile(("RootFile/MonoPhotonAnalysis_" + year[1] + "_" + mass[i] + "_DeltaRayOff_0.root").c_str());
    dir[i] = (TDirectory *)fin[i]->Get("HLT_Photon200");
    dir[i]->cd();

    //fin[i + 10] = new TFile(("RootFile/MonoPhotonAnalysis_" + year[2] + "_" + mass[i] + "_0.root").c_str());
    fin[i + 10] = new TFile(("RootFile/MonoPhotonAnalysis_" + year[2] + "_" + mass[i] + "_DeltaRayOff_0.root").c_str());
    dir[i + 10] = (TDirectory *)fin[i + 10]->Get("HLT_Photon200");
    dir[i + 10]->cd();

    //fin[i + 20] = new TFile(("RootFile/MonoPhotonAnalysis_" + year[3] + "_" + mass[i] + "_0.root").c_str());
    fin[i + 20] = new TFile(("RootFile/MonoPhotonAnalysis_" + year[3] + "_" + mass[i] + "_DeltaRayOff_0.root").c_str());
    dir[i + 20] = (TDirectory *)fin[i + 20]->Get("HLT_Photon200");
    dir[i + 20]->cd();

    //fin[i + 30] = new TFile(("RootFile/MonoPhotonAnalysis_" + year[4] + "_" + mass[i] + "_0.root").c_str());
    fin[i + 30] = new TFile(("RootFile/MonoPhotonAnalysis_" + year[4] + "_" + mass[i] + "_DeltaRayOff_0.root").c_str());
    dir[i + 30] = (TDirectory *)fin[i + 30]->Get("HLT_Photon200");
    dir[i + 30]->cd();
  }
  // -----------------------------------------------------------------

  TH1D *ABCD_plot[10];
  for (int i = 1; i < 9; i++) {
    ABCD_plot[i] = (TH1D *)dir[i]->Get("Flow_dEdxSig_ABCD");
    ABCD_plot[i]->Add((TH1D *)dir[10 + i]->Get("Flow_dEdxSig_ABCD"));
  }
  double dEdXSigCut_ = 9;
  double f51Cut_     = 0.85;
  for (int i = 1; i < 9; i++) {

    ABCD_plot[i]->SetXTitle("f51");
    ABCD_plot[i]->SetYTitle("dE/dX significance");
    ABCD_plot[i]->SetTitle("");
    ABCD_plot[i]->SetMarkerStyle(7);
    ABCD_plot[i]->Draw("COLZ");
    mgr::SetAxis(ABCD_plot[i]);
    mgr::DrawCMSLabelOuter(SIMULATION);
    mgr::DrawEntryRight(("2017 2018 13TeV Mass "+mass[i]+" GeV").c_str());
    TLine *TightY = new TLine(0, dEdXSigCut_, 1.1, dEdXSigCut_);
    TightY->SetLineColor(4);
    TightY->SetLineStyle(7);
    TightY->SetLineWidth(3);
    TightY->Draw("same");
    TLine *TightX = new TLine(f51Cut_, 0, f51Cut_, 30);
    TightX->SetLineColor(4);
    TightX->SetLineStyle(7);
    TightX->SetLineWidth(3);
    TightX->Draw("same");
    //canvas->SaveAs(("./Plots/MC_ABCD_plot1718_dedxsigCut_" + mass[i] + "_0.pdf").c_str());
    canvas->SaveAs(("./Plots/MC_ABCD_plot1718_dedxsigCut_" + mass[i] + "_deltaRayOff.pdf").c_str());
//    canvas->SaveAs(("/Users/zero/Atom/NTU-Thesis-LaTeX-Template/figures/MC_ABCD_plot1718_EnergyCut_"+mass[i]+".pdf").c_str());
  }

	// 2016---------------------------------------------------
	//
  TH1D *ABCD_plot16[10];
  for (int i = 1; i < 9; i++) {
    ABCD_plot16[i] = (TH1D *)dir[20+i]->Get("Flow_dEdxSig_ABCD");
    ABCD_plot16[i]->Add((TH1D *)dir[30 + i]->Get("Flow_dEdxSig_ABCD"));
  }

  for (int i = 1; i < 9; i++) {

    ABCD_plot16[i]->SetXTitle("f51");
    ABCD_plot16[i]->SetYTitle("dE/dX significance");
    ABCD_plot16[i]->SetTitle("");
    ABCD_plot16[i]->SetMarkerStyle(7);
    ABCD_plot16[i]->Draw("COLZ");
    mgr::SetAxis(ABCD_plot16[i]);
    mgr::DrawCMSLabelOuter(SIMULATION);
    mgr::DrawEntryRight(("2016 13TeV Mass "+mass[i]+" GeV").c_str());
    TLine *TightY = new TLine(0, dEdXSigCut_, 1.1, dEdXSigCut_);
    TightY->SetLineColor(4);
    TightY->SetLineStyle(7);
    TightY->SetLineWidth(3);
    TightY->Draw("same");
    TLine *TightX = new TLine(f51Cut_, 0, f51Cut_, 30);
    TightX->SetLineColor(4);
    TightX->SetLineStyle(7);
    TightX->SetLineWidth(3);
    TightX->Draw("same");
    //canvas->SaveAs(("./Plots/MC_ABCD_plot16_dedxsigCut_" + mass[i] + "_0.pdf").c_str());
    canvas->SaveAs(("./Plots/MC_ABCD_plot16_dedxsigCut_" + mass[i] + "_deltaRayOff.pdf").c_str());
  //  canvas->SaveAs(("/Users/zero/Atom/NTU-Thesis-LaTeX-Template/figures/MC_ABCD_plot16_EnergyCut_"+mass[i]+".pdf").c_str());
  }
}
