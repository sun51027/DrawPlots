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
	TDirectory *dir0	= (TDirectory*)fin0->Get("HLT_Photon");
  dir0->cd();
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

	//------------------------------------------------
	//Draw RZPar0

  TH1D *Data_RZPar0;
  Data_RZPar0 = (TH1D *)dir0->Get("RZPar0");
  Data_RZPar0->SetXTitle("cm (shift in z-direction)");
  Data_RZPar0->SetYTitle("Entries");
  Data_RZPar0->SetTitle("");
  Data_RZPar0->SetMarkerStyle(20);
  Data_RZPar0->Scale(1 / Data_RZPar0->Integral());
	for(int i=1;i<9;i++){
					RZPar0_MC[i]->Scale(1/RZPar0_MC[i]->Integral());
	}
  Data_RZPar0->Draw("E same");
	for(int i=1;i<9;i++){
					RZPar0_MC[i]->Draw("same hist");
	}
	Data_RZPar0->SetMaximum(0.07);
	RZPar0_MC[1]->SetLineColor(2);
	RZPar0_MC[2]->SetLineColor(30);
	RZPar0_MC[3]->SetLineColor(4);
	RZPar0_MC[4]->SetLineColor(12);
	RZPar0_MC[5]->SetLineColor(38);
	RZPar0_MC[6]->SetLineColor(8);
	RZPar0_MC[7]->SetLineColor(9);
	RZPar0_MC[8]->SetLineColor(44);
  mgr::SetSinglePad(canvas);
  mgr::SetAxis(Data_RZPar0);
  mgr::DrawEntryRight("2018 13TeV");
  mgr::DrawCMSLabelOuter(SIMULATION);
  TLegend *leg = new TLegend(0.20, 0.40, 0.50, 0.70);
  leg->SetBorderSize(0);
  leg->SetFillColorAlpha(0, 0);
  leg->SetTextSize(0.03);
  leg->AddEntry(RZPar0_MC[1], "1000 GeV", "l");
  leg->AddEntry(RZPar0_MC[2], "1500 GeV", "l");
  leg->AddEntry(RZPar0_MC[3], "2000 GeV", "l");
  leg->AddEntry(RZPar0_MC[4], "2500 GeV", "l");
  leg->AddEntry(RZPar0_MC[5], "3000 GeV", "l");
  leg->AddEntry(RZPar0_MC[6], "3500 GeV", "l");
  leg->AddEntry(RZPar0_MC[7], "4000 GeV", "l");
  leg->AddEntry(RZPar0_MC[8], "4500 GeV", "l");
  leg->AddEntry(Data_RZPar0, "data", "p");
	leg->Draw();
  canvas->SaveAs("./Plots/Data2018RZPar0.pdf");
	//------------------------------------------------
	//Draw RZPar1
  TH1D *Data_RZPar1;
  Data_RZPar1 = (TH1D *)dir0->Get("RZPar1");
  Data_RZPar1->SetXTitle("gradient in RZ plane");
  Data_RZPar1->SetYTitle("Entries");
  Data_RZPar1->SetTitle("");
  Data_RZPar1->SetMarkerStyle(20);
  Data_RZPar1->Scale(1 / Data_RZPar1->Integral());
	for(int i=1;i<9;i++){
					RZPar1_MC[i]->Scale(1/RZPar1_MC[i]->Integral());
	}
  Data_RZPar1->Draw("E");
	for(int i=1;i<9;i++){
					RZPar1_MC[i]->Draw("same hist");
	}
	Data_RZPar1->SetMaximum(0.1);
	RZPar1_MC[1]->SetLineColor(2);
	RZPar1_MC[2]->SetLineColor(30);
	RZPar1_MC[3]->SetLineColor(4);
	RZPar1_MC[4]->SetLineColor(12);
	RZPar1_MC[5]->SetLineColor(38);
	RZPar1_MC[6]->SetLineColor(8);
	RZPar1_MC[7]->SetLineColor(9);
	RZPar1_MC[8]->SetLineColor(44);
  mgr::SetSinglePad(canvas);
  mgr::SetAxis(Data_RZPar1);
  mgr::DrawEntryRight("2018 13TeV");
  mgr::DrawCMSLabelOuter(SIMULATION);
  TLegend *leg2 = new TLegend(0.20, 0.40, 0.50, 0.70);
  leg2->SetBorderSize(0);
  leg2->SetFillColorAlpha(0, 0);
  leg2->SetTextSize(0.03);
  leg2->AddEntry(RZPar1_MC[1], "1000 GeV", "l");
  leg2->AddEntry(RZPar1_MC[2], "1500 GeV", "l");
  leg2->AddEntry(RZPar1_MC[3], "2000 GeV", "l");
  leg2->AddEntry(RZPar1_MC[4], "2500 GeV", "l");
  leg2->AddEntry(RZPar1_MC[5], "3000 GeV", "l");
  leg2->AddEntry(RZPar1_MC[6], "3500 GeV", "l");
  leg2->AddEntry(RZPar1_MC[7], "4000 GeV", "l");
  leg2->AddEntry(RZPar1_MC[8], "4500 GeV", "l");
  leg2->AddEntry(Data_RZPar1, "data", "p");
	leg2->Draw();
  canvas->SaveAs("./Plots/Data2018RZPar1.pdf");
	//------------------------------------------------
	//Draw RZPar2
  TH1D *Data_RZPar2;
  Data_RZPar2 = (TH1D *)dir0->Get("RZcurv");
  Data_RZPar2->SetXTitle("RZ curvature");
  Data_RZPar2->SetYTitle("Entries");
  Data_RZPar2->SetTitle("");
  Data_RZPar2->SetMarkerStyle(20);
  Data_RZPar2->Scale(1 / Data_RZPar2->Integral());
	for(int i=1;i<9;i++){
					RZPar2_MC[i]->Scale(1/RZPar2_MC[i]->Integral());
	}
  Data_RZPar2->Draw("E");
	for(int i=1;i<9;i++){
					RZPar2_MC[i]->Draw("same hist");
	}
	RZPar2_MC[1]->SetLineColor(2);
	RZPar2_MC[2]->SetLineColor(30);
	RZPar2_MC[3]->SetLineColor(4);
	RZPar2_MC[4]->SetLineColor(12);
	RZPar2_MC[5]->SetLineColor(38);
	RZPar2_MC[6]->SetLineColor(8);
	RZPar2_MC[7]->SetLineColor(9);
	RZPar2_MC[8]->SetLineColor(44);
  mgr::SetSinglePad(canvas);
  mgr::SetAxis(Data_RZPar2);
  mgr::DrawEntryRight("2018 13TeV");
  mgr::DrawCMSLabelOuter(SIMULATION);
  TLegend *leg3 = new TLegend(0.20, 0.40, 0.50, 0.70);
  leg3->SetBorderSize(0);
  leg3->SetFillColorAlpha(0, 0);
  leg3->SetTextSize(0.03);
  leg3->AddEntry(RZPar2_MC[1], "1000 GeV", "l");
  leg3->AddEntry(RZPar2_MC[2], "1500 GeV", "l");
  leg3->AddEntry(RZPar2_MC[3], "2000 GeV", "l");
  leg3->AddEntry(RZPar2_MC[4], "2500 GeV", "l");
  leg3->AddEntry(RZPar2_MC[5], "3000 GeV", "l");
  leg3->AddEntry(RZPar2_MC[6], "3500 GeV", "l");
  leg3->AddEntry(RZPar2_MC[7], "4000 GeV", "l");
  leg3->AddEntry(RZPar2_MC[8], "4500 GeV", "l");
  leg3->AddEntry(Data_RZPar2, "data", "p");
	leg3->Draw();
  canvas->SaveAs("./Plots/Data2018RZPar2.pdf");

	//------------------------------------------------
	//Draw XYPar0
  TH1D *Data_XYPar0;
  Data_XYPar0 = (TH1D *)dir0->Get("XYPar0");
  Data_XYPar0->SetXTitle("d_{0} impact parameter (cm)");
  Data_XYPar0->SetYTitle("Entries");
  Data_XYPar0->SetTitle("");
  Data_XYPar0->SetMarkerStyle(20);
  Data_XYPar0->Scale(1 / Data_XYPar0->Integral());
	for(int i=1;i<9;i++){
					XYPar0_MC[i]->Scale(1/XYPar0_MC[i]->Integral());
	}
	Data_XYPar0->SetMaximum(0.13);
  Data_XYPar0->Draw("E");
	for(int i=1;i<9;i++){
					XYPar0_MC[i]->Draw("same hist");
	}
	XYPar0_MC[1]->SetLineColor(2);
	XYPar0_MC[2]->SetLineColor(30);
	XYPar0_MC[3]->SetLineColor(4);
	XYPar0_MC[4]->SetLineColor(12);
	XYPar0_MC[5]->SetLineColor(38);
	XYPar0_MC[6]->SetLineColor(8);
	XYPar0_MC[7]->SetLineColor(9);
	XYPar0_MC[8]->SetLineColor(44);
  mgr::SetSinglePad(canvas);
  mgr::SetAxis(Data_XYPar0);
  mgr::DrawEntryRight("2018 13TeV");
  mgr::DrawCMSLabelOuter(SIMULATION);
  TLegend *leg4 = new TLegend(0.20, 0.40, 0.50, 0.70);
  leg4->SetBorderSize(0);
  leg4->SetFillColorAlpha(0, 0);
  leg4->SetTextSize(0.03);
  leg4->AddEntry(XYPar0_MC[1], "1000 GeV", "l");
  leg4->AddEntry(XYPar0_MC[2], "1500 GeV", "l");
  leg4->AddEntry(XYPar0_MC[3], "2000 GeV", "l");
  leg4->AddEntry(XYPar0_MC[4], "2500 GeV", "l");
  leg4->AddEntry(XYPar0_MC[5], "3000 GeV", "l");
  leg4->AddEntry(XYPar0_MC[6], "3500 GeV", "l");
  leg4->AddEntry(XYPar0_MC[7], "4000 GeV", "l");
  leg4->AddEntry(XYPar0_MC[8], "4500 GeV", "l");
  leg4->AddEntry(Data_XYPar0, "data", "p");
	leg4->Draw();
  canvas->SaveAs("./Plots/Data2018XYPar0.pdf");
	//------------------------------------------------
	//Draw XYPar1
  TH1D *Data_XYPar1;
  Data_XYPar1 = (TH1D *)dir0->Get("XYPar1");
  Data_XYPar1->SetXTitle("#phi_{0}");
  Data_XYPar1->SetYTitle("Entries");
  Data_XYPar1->SetTitle("");
  Data_XYPar1->SetMarkerStyle(20);
  Data_XYPar1->Scale(1 / Data_XYPar1->Integral());
	for(int i=1;i<9;i++){
					XYPar1_MC[i]->Scale(1/XYPar1_MC[i]->Integral());
	}
  Data_XYPar1->Draw("E");
	for(int i=1;i<9;i++){
					XYPar1_MC[i]->Draw("same hist");
	}
	XYPar1_MC[1]->SetLineColor(2);
	XYPar1_MC[2]->SetLineColor(30);
	XYPar1_MC[3]->SetLineColor(4);
	XYPar1_MC[4]->SetLineColor(12);
	XYPar1_MC[5]->SetLineColor(38);
	XYPar1_MC[6]->SetLineColor(8);
	XYPar1_MC[7]->SetLineColor(9);
	XYPar1_MC[8]->SetLineColor(44);
  mgr::SetSinglePad(canvas);
  mgr::SetAxis(Data_XYPar1);
  mgr::DrawEntryRight("2018 13TeV");
  mgr::DrawCMSLabelOuter(SIMULATION);
  TLegend *leg5 = new TLegend(0.20, 0.40, 0.50, 0.70);
  leg5->SetBorderSize(0);
  leg5->SetFillColorAlpha(0, 0);
  leg5->SetTextSize(0.03);
  leg5->AddEntry(XYPar1_MC[1], "1000 GeV", "l");
  leg5->AddEntry(XYPar1_MC[2], "1500 GeV", "l");
  leg5->AddEntry(XYPar1_MC[3], "2000 GeV", "l");
  leg5->AddEntry(XYPar1_MC[4], "2500 GeV", "l");
  leg5->AddEntry(XYPar1_MC[5], "3000 GeV", "l");
  leg5->AddEntry(XYPar1_MC[6], "3500 GeV", "l");
  leg5->AddEntry(XYPar1_MC[7], "4000 GeV", "l");
  leg5->AddEntry(XYPar1_MC[8], "4500 GeV", "l");
  leg5->AddEntry(Data_XYPar1, "data", "p");
	leg5->Draw();
  canvas->SaveAs("./Plots/Data2018XYPar1.pdf");

	//------------------------------------------------
	//Draw XYPar2
	canvas->SetLogy();
  TH1D *Data_XYPar2;
  Data_XYPar2 = (TH1D *)dir0->Get("XYPar2");
  Data_XYPar2->SetXTitle("radius (m)");
  Data_XYPar2->SetYTitle("Entries");
  Data_XYPar2->SetTitle("");
  Data_XYPar2->SetMarkerStyle(20);
  Data_XYPar2->Scale(1 / Data_XYPar2->Integral());
	for(int i=1;i<9;i++){
					XYPar2_MC[i]->Scale(1/XYPar2_MC[i]->Integral());
	}
	Data_XYPar2->SetMaximum(1);
  Data_XYPar2->Draw("E");
	for(int i=1;i<9;i++){
					XYPar2_MC[i]->Draw("same hist");
	}
	XYPar2_MC[1]->SetLineColor(2);
	XYPar2_MC[2]->SetLineColor(30);
	XYPar2_MC[3]->SetLineColor(4);
	XYPar2_MC[4]->SetLineColor(12);
	XYPar2_MC[5]->SetLineColor(38);
	XYPar2_MC[6]->SetLineColor(8);
	XYPar2_MC[7]->SetLineColor(9);
	XYPar2_MC[8]->SetLineColor(44);
  mgr::SetSinglePad(canvas);
  mgr::SetAxis(Data_XYPar2);
  mgr::DrawEntryRight("2018 13TeV");
  mgr::DrawCMSLabelOuter(SIMULATION);
  TLegend *leg6 = new TLegend(0.20, 0.40, 0.50, 0.70);
  leg6->SetBorderSize(0);
  leg6->SetFillColorAlpha(0, 0);
  leg6->SetTextSize(0.03);
  leg6->AddEntry(XYPar2_MC[1], "1000 GeV", "l");
  leg6->AddEntry(XYPar2_MC[2], "1500 GeV", "l");
  leg6->AddEntry(XYPar2_MC[3], "2000 GeV", "l");
  leg6->AddEntry(XYPar2_MC[4], "2500 GeV", "l");
  leg6->AddEntry(XYPar2_MC[5], "3000 GeV", "l");
  leg6->AddEntry(XYPar2_MC[6], "3500 GeV", "l");
  leg6->AddEntry(XYPar2_MC[7], "4000 GeV", "l");
  leg6->AddEntry(XYPar2_MC[8], "4500 GeV", "l");
  leg6->AddEntry(Data_XYPar2, "data", "p");
	leg6->Draw();
  canvas->SaveAs("./Plots/Data2018XYPar2.pdf");
}
