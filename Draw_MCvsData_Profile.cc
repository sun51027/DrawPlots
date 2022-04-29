///////////////////////
//
//	Profile plots:
//	x-axis f51
//	y-axis dEdx
//	See the covariance and correlation between f51 and dEdx
//	option:
//	  EcalBarrel
//	  EcalEndCup
//	  EcalAll
//
///////////////////////
#include <string>
using namespace std;
using namespace mgr;
void Draw_MCvsData_Profile()
{

  TCanvas *canvas = new TCanvas("canvas", "", 600, 600);
  gStyle->SetOptStat(0);

  // data
  TFile      *fin_data = new TFile("RootFile/BlindAnalysis.root");
  TDirectory *DC_data  = (TDirectory *)fin_data->Get("HLT_Photon");
  DC_data->cd();
  // MC 1TeV
  TFile      *fin1   = new TFile("RootFile/MonoPhotonAnalysis_2018_1000.root");
  TDirectory *DC_MC1 = (TDirectory *)fin1->Get("HLT_Photon200");
  DC_MC1->cd();
  // M 2TeV
  TFile      *fin2   = new TFile("RootFile/MonoPhotonAnalysis_2018_2000.root");
  TDirectory *DC_MC2 = (TDirectory *)fin2->Get("HLT_Photon200");
  DC_MC2->cd();
  // 3TeV
  TFile      *fin3   = new TFile("RootFile/MonoPhotonAnalysis_2018_3000.root");
  TDirectory *DC_MC3 = (TDirectory *)fin3->Get("HLT_Photon200");
  DC_MC3->cd();
  // 4TeV
  TFile      *fin4   = new TFile("RootFile/MonoPhotonAnalysis_2018_4000.root");
  TDirectory *DC_MC4 = (TDirectory *)fin4->Get("HLT_Photon200");
  DC_MC4->cd();

  TProfile *Data_EcalBarrel, *MC1_EcalBarrel, *MC2_EcalBarrel, *MC3_EcalBarrel, *MC4_EcalBarrel;
  MC1_EcalBarrel  = (TProfile *)DC_MC1->Get("Flow_dEdxSig_EcalBarrel");
  MC2_EcalBarrel  = (TProfile *)DC_MC2->Get("Flow_dEdxSig_EcalBarrel");
  MC3_EcalBarrel  = (TProfile *)DC_MC3->Get("Flow_dEdxSig_EcalBarrel");
  MC4_EcalBarrel  = (TProfile *)DC_MC4->Get("Flow_dEdxSig_EcalBarrel");
  Data_EcalBarrel = (TProfile *)DC_data->Get("Blinded_EcalBarrel");

  Double_t factor = 1.;

  //	Data_EcalBarrel->Scale(factor/Data_EcalBarrel->Integral());
  //	MC1_EcalBarrel->Scale(factor/MC1_EcalBarrel->Integral());
  //	MC2_EcalBarrel->Scale(factor/MC2_EcalBarrel->Integral());
  //	MC3_EcalBarrel->Scale(factor/MC3_EcalBarrel->Integral());
  //	MC4_EcalBarrel->Scale(factor/MC4_EcalBarrel->Integral());
  MC1_EcalBarrel->SetXTitle("f51");
  MC1_EcalBarrel->SetYTitle("dE/dx Significance");
  MC1_EcalBarrel->SetTitle("");
  MC1_EcalBarrel->SetAxisRange(-2, 30, "y");
  MC1_EcalBarrel->Draw("E");
  MC2_EcalBarrel->Draw("same E");
  MC3_EcalBarrel->Draw("same E");
  MC4_EcalBarrel->Draw("same E");
  Data_EcalBarrel->Draw("same E");
  MC1_EcalBarrel->SetMarkerColor(30);
  MC1_EcalBarrel->SetLineColor(30);
  MC2_EcalBarrel->SetMarkerColor(38);
  MC2_EcalBarrel->SetLineColor(38);
  MC3_EcalBarrel->SetMarkerColor(46);
  MC3_EcalBarrel->SetLineColor(46);
  MC4_EcalBarrel->SetMarkerColor(20);
  MC4_EcalBarrel->SetLineColor(20);
  MC1_EcalBarrel->SetMarkerStyle(22);
  MC2_EcalBarrel->SetMarkerStyle(22);
  MC3_EcalBarrel->SetMarkerStyle(22);
  MC4_EcalBarrel->SetMarkerStyle(22);
  Data_EcalBarrel->SetMarkerStyle(20);
  Data_EcalBarrel->SetMarkerColor(1);
  Data_EcalBarrel->SetLineColor(1);
  mgr::SetSinglePad(canvas);
  mgr::SetAxis(MC1_EcalBarrel);
  mgr::DrawEntryRight("2018 13TeV 32.93/fb");
  mgr::DrawCMSLabelOuter(PRELIMINARY);
  TLegend *leg = new TLegend(0.25, 0.80, 0.55, 0.45);
  leg->SetBorderSize(0);
  leg->SetFillColorAlpha(0, 0);
  leg->SetTextSize(0.03);
  leg->AddEntry(MC1_EcalBarrel, "1TeV", "p");
  leg->AddEntry(MC2_EcalBarrel, "2TeV", "p");
  leg->AddEntry(MC3_EcalBarrel, "3TeV", "p");
  leg->AddEntry(MC4_EcalBarrel, "4TeV", "p");
  leg->AddEntry(Data_EcalBarrel, "Data", "p");
  leg->AddEntry((TObject *)0, "|#eta| < 1.479 (ECal Barrel)", "");
  //	leg->AddEntry((TObject*)0, "1.479 < |#eta| < 3.0 (EcalEndCap) ", "");
  //	leg->AddEntry((TObject*)0, "|#eta| < 3.0 (Whole Ecal) ", "");
  leg->Draw();
  canvas->SaveAs("Profile_f51vsDedxSig_MCvsData_2018_EcalBarrel.pdf");
}
