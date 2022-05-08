//
//	Draw tracking parameters
//	Data vs MC
//
#include <string>
using namespace std;
void Draw_MCvsData_TrackParameter2018()
{

  TCanvas    *canvas = new TCanvas("canvas", "", 800, 600);
  TFile      *fin0   = new TFile("RootFile/MonoData2018_Plot.root");
  fin0->cd();
  gStyle->SetOptStat(0);

  TDirectory *dir[10];

  TFile *fin1 = new TFile("RootFile/MonoPhotonAnalysis_2018_1000_0.root");
  dir[1]      = (TDirectory*)fin1->Get("HLT_Photon200");
  dir[1]->cd();

  TFile *fin2 = new TFile("RootFile/MonoPhotonAnalysis_2018_1500_0.root");
  dir[2]      = (TDirectory*)fin2->Get("HLT_Photon200");
  dir[2]->cd();

  TFile *fin3 = new TFile("RootFile/MonoPhotonAnalysis_2018_2000_0.root");
  dir[3]      = (TDirectory *)fin3->Get("HLT_Photon200");
  dir[3]->cd();

  TFile *fin4 = new TFile("RootFile/MonoPhotonAnalysis_2018_2500_0.root");
  dir[4]      = (TDirectory *)fin4->Get("HLT_Photon200");
  dir[4]->cd();

  TFile *fin5 = new TFile("RootFile/MonoPhotonAnalysis_2018_3000_0.root");
  dir[5]      = (TDirectory *)fin5->Get("HLT_Photon200");
  dir[5]->cd();

  TFile *fin6 = new TFile("RootFile/MonoPhotonAnalysis_2018_3500_0.root");
  dir[6]      = (TDirectory *)fin6->Get("HLT_Photon200");
  dir[6]->cd();

  TFile *fin7 = new TFile("RootFile/MonoPhotonAnalysis_2018_4000_0.root");
  dir[7]      = (TDirectory *)fin7->Get("HLT_Photon200");
  dir[7]->cd();

  TFile *fin8 = new TFile("RootFile/MonoPhotonAnalysis_2018_4500_0.root");
  dir[8]      = (TDirectory *)fin8->Get("HLT_Photon200");
  dir[8]->cd();

  TH1D *RZPar0_MC[10];
  TH1D *RZPar1_MC[10];
  TH1D *RZPar2_MC[10];
  TH1D *XYPar0_MC[10];
  TH1D *XYPar1_MC[10];
  TH1D *XYPar2_MC[10];
  for (int i = 1; i < 9; i++) {
    RZPar0_MC[i] = (TH1D *)dir[i]->Get("RZPar0");
    RZPar1_MC[i] = (TH1D *)dir[i]->Get("RZPar1");
    RZPar2_MC[i] = (TH1D *)dir[i]->Get("RZcurv");
    XYPar0_MC[i] = (TH1D *)dir[i]->Get("XYPar0");
    XYPar1_MC[i] = (TH1D *)dir[i]->Get("XYPar1");
    XYPar2_MC[i] = (TH1D *)dir[i]->Get("XYPar2");
  }

  TH1D *Data_RZPar0;
  Data_RZPar0 = (TH1D *)fin0->Get("Plot_RZPar0");
  Data_RZPar0->SetXTitle("cm ( z direction)");
  Data_RZPar0->Scale(1 / Data_RZPar0->Integral());
	for(int i=1;i<9;i++){
					RZPar0_MC[i]->Scale(1/RZPar0_MC[i]->Integral());
	}
  Data_RZPar0->SetYTitle("Entries");
  Data_RZPar0->SetTitle("");
  Data_RZPar0->Draw("E");
	for(int i=1;i<9;i++){
					RZPar0_MC[i]->Draw("same hist");
	}
	RZPar0_MC[1]->SetLineColor(2);
	RZPar0_MC[2]->SetLineColor(30);
	RZPar0_MC[3]->SetLineColor(4);
	RZPar0_MC[4]->SetLineColor(6);
	RZPar0_MC[5]->SetLineColor(38);
	RZPar0_MC[6]->SetLineColor(8);
	RZPar0_MC[7]->SetLineColor(9);
	RZPar0_MC[8]->SetLineColor(44);
  mgr::SetSinglePad(canvas);
  mgr::SetAxis(Data_RZPar0);
  mgr::DrawEntryRight("2018 13TeV");
  canvas->SaveAs("./Plots/Data2018RZPar0.pdf");
/*
  TH1D *Data_RZPar1;
  Data_RZPar1 = (TH1D *)fin0->Get("RZPar1");
  Data_RZPar1->Scale(RZPar1_MC->Integral() / Data_RZPar1->Integral());
  Data_RZPar1->SetXTitle("gradient in RZ plane");
  Data_RZPar1->SetYTitle("Entries");
  Data_RZPar1->SetTitle("");
  Data_RZPar1->Draw("HIST");
  mgr::SetSinglePad(canvas);
  mgr::SetAxis(Data_RZPar1);
  mgr::DrawEntryRight("2018 13TeV");
  canvas->SaveAs("./Plots/Data2018RZPar1.pdf");

  TH1D *Data_RZPar2;
  Data_RZPar2 = (TH1D *)fin0->Get("RZcurv");
  Data_RZPar2->Scale(RZPar2_MC->Integral() / Data_RZPar2->Integral());
  Data_RZPar2->SetXTitle("RZ curvature");
  Data_RZPar2->SetYTitle("Entries");
  Data_RZPar2->SetTitle("");
  Data_RZPar2->Draw("HIST");
  mgr::SetSinglePad(canvas);
  mgr::SetAxis(Data_RZPar2);
  mgr::DrawEntryRight("2018 13TeV");
  canvas->SaveAs("./Plots/Data2018RZPar2.pdf");

  TH1D *Data_XYPar0;
  Data_XYPar0 = (TH1D *)fin0->Get("XYPar0");
  Data_XYPar0->Scale(XYPar0_MC->Integral() / Data_XYPar0->Integral());
  Data_XYPar0->SetXTitle("d_{0} impact parameter");
  Data_XYPar0->SetYTitle("Entries");
  Data_XYPar0->SetTitle("");
  Data_XYPar0->Draw("HIST");
  mgr::SetSinglePad(canvas);
  mgr::SetAxis(Data_XYPar0);
  mgr::DrawEntryRight("2018 13TeV");
  canvas->SaveAs("./Plots/Data2018XYPar0.pdf");

  TH1D *Data_XYPar1;
  Data_XYPar1 = (TH1D *)fin0->Get("XYPar1");
  Data_XYPar1->Scale(XYPar1_MC->Integral() / Data_XYPar1->Integral());
  Data_XYPar1->SetXTitle("#phi_{0}");
  Data_XYPar1->SetYTitle("Entries");
  Data_XYPar1->SetTitle("");
  Data_XYPar1->Draw("HIST");
  mgr::SetSinglePad(canvas);
  mgr::SetAxis(Data_XYPar1);
  mgr::DrawEntryRight("2018 13TeV");
  canvas->SaveAs("./Plots/Data2018XYPar1.pdf");

  TH1D *Data_XYPar2;
  Data_XYPar2 = (TH1D *)fin0->Get("XYPar2");
  Data_XYPar2->Scale(XYPar2_MC->Integral() / Data_XYPar2->Integral());
  Data_XYPar2->SetXTitle("cm (radius)");
  Data_XYPar2->SetYTitle("Entries");
  Data_XYPar2->SetTitle("");
  Data_XYPar2->Draw("HIST");
  mgr::SetSinglePad(canvas);
  mgr::SetAxis(Data_XYPar2);
  mgr::DrawEntryRight("2018 13TeV");
  canvas->SaveAs("./Plots/Data2018XYPar2.pdf");
*/
  //        double dEdXSigCut_ = 9;
  //        double f51Cut_ = 0.85;
  //	TH2D* ABCD;
  //	ABCD = (TH2D*)fin0->Get("Flow_HLT_Energy_ABCD");
  //        ABCD->SetXTitle("f51");
  //        ABCD->SetYTitle("dE/dX significance");
  //        ABCD->SetTitle("");
  //        ABCD->SetMarkerStyle(7);
  //        ABCD->Draw("COLZ");
  //        mgr::SetSinglePad(canvas);
  //        mgr::SetAxis(ABCD);
  //        mgr::DrawCMSLabelOuter(SIMULATION);
  //        mgr::DrawEntryRight("2018 13TeV Mass 1000GeV 16389 Entries");
  //        TLine *TightY = new TLine(0,dEdXSigCut_,1.1,dEdXSigCut_);
  //        TightY->SetLineColor(4);
  //        TightY->SetLineStyle(7);
  //        TightY->SetLineWidth(3);
  //        TightY->Draw("same");
  //        TLine *TightX = new TLine(f51Cut_,0,f51Cut_,30);
  //        TightX->SetLineColor(4);
  //        TightX->SetLineStyle(7);
  //        TightX->SetLineWidth(3);
  //        TightX->Draw("same");
  //        TLine *LooseY = new TLine(0,7,1.1,7);
  //        LooseY->SetLineColor(38);
  //        LooseY->SetLineStyle(7);
  //        LooseY->Draw("same");
  //        TLine *LooseX = new TLine(0.6,0,0.6,30);
  //        LooseX->SetLineColor(38);
  //        LooseX->SetLineStyle(7);
  //        LooseX->Draw("same");
  //	canvas->SaveAs("ABCD(Ecut+HLT_Photon200).pdf");
  //
}
