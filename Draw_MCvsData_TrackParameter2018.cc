//
//	Draw tracking parameters 
//	Data vs MC
//
#include <string>
using namespace std;
void Draw_MCvsData_TrackParameter2018()
{

  TCanvas    *canvas = new TCanvas("canvas", "", 800, 600);
  TFile      *fin0   = new TFile("BlindAnalysis.root");
  TDirectory *NOTRG0 = (TDirectory *)fin1->Get("HLT_Photon");
  NOTRG0->cd();
  gStyle->SetOptStat(0);

  TFile      *fin2   = new TFile("MonoPhotonAnalysis_2018_1000.root");
  TDirectory *NOTRG2 = (TDirectory *)fin2->Get("HLT_Photon200");
  NOTRG2->cd();

  TH1D *MC_RZPar0;
  TH1D *MC_RZPar1;
  TH1D *MC_RZPar2;
  TH1D *MC_XYPar0;
  TH1D *MC_XYPar1;
  TH1D *MC_XYPar2;
  MC_RZPar0 = (TH1D *)NOTRG2->Get("RZPar0");
  MC_RZPar1 = (TH1D *)NOTRG2->Get("RZPar1");
  MC_RZPar2 = (TH1D *)NOTRG2->Get("RZcurv");
  MC_XYPar0 = (TH1D *)NOTRG2->Get("XYPar0");
  MC_XYPar1 = (TH1D *)NOTRG2->Get("XYPar1");
  MC_XYPar2 = (TH1D *)NOTRG2->Get("XYPar2");

  TH1D *Data_RZPar0;
  Data_RZPar0 = (TH1D *)NOTRG1->Get("RZPar0");
  Data_RZPar0->SetXTitle("cm ( z direction)");
  Data_RZPar0->Scale(MC_RZPar0->Integral() / Data_RZPar0->Integral());
  Data_RZPar0->SetYTitle("Entries");
  Data_RZPar0->SetTitle("");
  Data_RZPar0->Draw("HIST");
  mgr::SetSinglePad(canvas);
  mgr::SetAxis(Data_RZPar0);
  mgr::DrawEntryRight("2018 13TeV");
  canvas->SaveAs("./Plots/Data2018RZPar0.pdf");

  TH1D *Data_RZPar1;
  Data_RZPar1 = (TH1D *)NOTRG1->Get("RZPar1");
  Data_RZPar1->Scale(MC_RZPar1->Integral() / Data_RZPar1->Integral());
  Data_RZPar1->SetXTitle("gradient in RZ plane");
  Data_RZPar1->SetYTitle("Entries");
  Data_RZPar1->SetTitle("");
  Data_RZPar1->Draw("HIST");
  mgr::SetSinglePad(canvas);
  mgr::SetAxis(Data_RZPar1);
  mgr::DrawEntryRight("2018 13TeV");
  canvas->SaveAs("./Plots/Data2018RZPar1.pdf");

  TH1D *Data_RZPar2;
  Data_RZPar2 = (TH1D *)NOTRG1->Get("RZcurv");
  Data_RZPar2->Scale(MC_RZPar2->Integral() / Data_RZPar2->Integral());
  Data_RZPar2->SetXTitle("RZ curvature");
  Data_RZPar2->SetYTitle("Entries");
  Data_RZPar2->SetTitle("");
  Data_RZPar2->Draw("HIST");
  mgr::SetSinglePad(canvas);
  mgr::SetAxis(Data_RZPar2);
  mgr::DrawEntryRight("2018 13TeV");
  canvas->SaveAs("./Plots/Data2018RZPar2.pdf");

  TH1D *Data_XYPar0;
  Data_XYPar0 = (TH1D *)NOTRG1->Get("XYPar0");
  Data_XYPar0->Scale(MC_XYPar0->Integral() / Data_XYPar0->Integral());
  Data_XYPar0->SetXTitle("d_{0} impact parameter");
  Data_XYPar0->SetYTitle("Entries");
  Data_XYPar0->SetTitle("");
  Data_XYPar0->Draw("HIST");
  mgr::SetSinglePad(canvas);
  mgr::SetAxis(Data_XYPar0);
  mgr::DrawEntryRight("2018 13TeV");
  canvas->SaveAs("./Plots/Data2018XYPar0.pdf");

  TH1D *Data_XYPar1;
  Data_XYPar1 = (TH1D *)NOTRG1->Get("XYPar1");
  Data_XYPar1->Scale(MC_XYPar1->Integral() / Data_XYPar1->Integral());
  Data_XYPar1->SetXTitle("#phi_{0}");
  Data_XYPar1->SetYTitle("Entries");
  Data_XYPar1->SetTitle("");
  Data_XYPar1->Draw("HIST");
  mgr::SetSinglePad(canvas);
  mgr::SetAxis(Data_XYPar1);
  mgr::DrawEntryRight("2018 13TeV");
  canvas->SaveAs("./Plots/Data2018XYPar1.pdf");

  TH1D *Data_XYPar2;
  Data_XYPar2 = (TH1D *)NOTRG1->Get("XYPar2");
  Data_XYPar2->Scale(MC_XYPar2->Integral() / Data_XYPar2->Integral());
  Data_XYPar2->SetXTitle("cm (radius)");
  Data_XYPar2->SetYTitle("Entries");
  Data_XYPar2->SetTitle("");
  Data_XYPar2->Draw("HIST");
  mgr::SetSinglePad(canvas);
  mgr::SetAxis(Data_XYPar2);
  mgr::DrawEntryRight("2018 13TeV");
  canvas->SaveAs("./Plots/Data2018XYPar2.pdf");

  //        double dEdXSigCut_ = 9;
  //        double f51Cut_ = 0.85;
  //	TH2D* ABCD;
  //	ABCD = (TH2D*)NOTRG1->Get("Flow_HLT_Energy_ABCD");
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
