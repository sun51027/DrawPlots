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
void NPVvsF51_noCut(TDirectory *DC_MC1, TDirectory *DC_MC2, TDirectory *DC_MC3, TDirectory *DC_MC4)
{

  TCanvas  *canvas = new TCanvas("canvas", "", 800, 600);
  TProfile *MC1_Flow_dEdxSig_PileUp_f51, *MC2_Flow_dEdxSig_PileUp_f51, *MC3_Flow_dEdxSig_PileUp_f51,
    *MC4_Flow_dEdxSig_PileUp_f51;
  MC1_Flow_dEdxSig_PileUp_f51 = (TProfile *)DC_MC1->Get("PileUp_f51");
  MC2_Flow_dEdxSig_PileUp_f51 = (TProfile *)DC_MC2->Get("PileUp_f51");
  MC3_Flow_dEdxSig_PileUp_f51 = (TProfile *)DC_MC3->Get("PileUp_f51");
  MC4_Flow_dEdxSig_PileUp_f51 = (TProfile *)DC_MC4->Get("PileUp_f51");

  MC1_Flow_dEdxSig_PileUp_f51->SetXTitle("No. of pile-up vertex");
  MC1_Flow_dEdxSig_PileUp_f51->SetYTitle("f51");
  MC1_Flow_dEdxSig_PileUp_f51->SetTitle("");
  MC1_Flow_dEdxSig_PileUp_f51->SetAxisRange(0.2, 1.2, "y");
  MC1_Flow_dEdxSig_PileUp_f51->Draw("E");
  MC2_Flow_dEdxSig_PileUp_f51->Draw("same E");
  MC3_Flow_dEdxSig_PileUp_f51->Draw("same E");
  MC4_Flow_dEdxSig_PileUp_f51->Draw("same E");
  MC1_Flow_dEdxSig_PileUp_f51->SetMarkerColor(30);
  MC1_Flow_dEdxSig_PileUp_f51->SetLineColor(30);
  MC2_Flow_dEdxSig_PileUp_f51->SetMarkerColor(38);
  MC2_Flow_dEdxSig_PileUp_f51->SetLineColor(38);
  MC3_Flow_dEdxSig_PileUp_f51->SetMarkerColor(46);
  MC3_Flow_dEdxSig_PileUp_f51->SetLineColor(46);
  MC4_Flow_dEdxSig_PileUp_f51->SetMarkerColor(20);
  MC4_Flow_dEdxSig_PileUp_f51->SetLineColor(20);
  MC1_Flow_dEdxSig_PileUp_f51->SetMarkerStyle(20);
  MC2_Flow_dEdxSig_PileUp_f51->SetMarkerStyle(21);
  MC3_Flow_dEdxSig_PileUp_f51->SetMarkerStyle(22);
  MC4_Flow_dEdxSig_PileUp_f51->SetMarkerStyle(23);
  mgr::SetSinglePad(canvas);
  mgr::SetAxis(MC1_Flow_dEdxSig_PileUp_f51);
  mgr::DrawEntryRight("2018 MC 16889 Entries");
  mgr::DrawCMSLabelOuter(PRELIMINARY);
  TLegend *leg = new TLegend(0.25, 0.20, 0.55, 0.40);
  leg->SetBorderSize(0);
  leg->SetFillColorAlpha(0, 0);
  leg->SetTextSize(0.04);
  leg->AddEntry(MC1_Flow_dEdxSig_PileUp_f51, "1TeV", "p");
  leg->AddEntry(MC2_Flow_dEdxSig_PileUp_f51, "2TeV", "p");
  leg->AddEntry(MC3_Flow_dEdxSig_PileUp_f51, "3TeV", "p");
  leg->AddEntry(MC4_Flow_dEdxSig_PileUp_f51, "4TeV", "p");
  leg->AddEntry((TObject *)0, "Without any selection", "");
  //	leg->AddEntry((TObject*)0, "1.479 < |#eta| < 3.0 (EcalEndCap) ", "");
  //	leg->AddEntry((TObject*)0, "|#eta| < 3.0 (Whole Ecal) ", "");
  leg->Draw();
  canvas->SaveAs("NPV-f51_noCut.pdf");
  canvas->SaveAs("~/Atom/NTU-Thesis-LaTeX-Template/figures/NPV-f51_noCut.pdf");
//  canvas->SaveAs("NPV-f51_noCut.png");
}
void NPVvsDedxSig_noCut(TDirectory *DC_MC1, TDirectory *DC_MC2, TDirectory *DC_MC3, TDirectory *DC_MC4)
{

  TCanvas  *canvas = new TCanvas("canvas", "", 800, 600);
  TProfile *MC1_Flow_dEdxSig_PileUp_DedXSig, *MC2_Flow_dEdxSig_PileUp_DedXSig, *MC3_Flow_dEdxSig_PileUp_DedXSig,
    *MC4_Flow_dEdxSig_PileUp_DedXSig;
  MC1_Flow_dEdxSig_PileUp_DedXSig = (TProfile *)DC_MC1->Get("PileUp_DedXSig");
  MC2_Flow_dEdxSig_PileUp_DedXSig = (TProfile *)DC_MC2->Get("PileUp_DedXSig");
  MC3_Flow_dEdxSig_PileUp_DedXSig = (TProfile *)DC_MC3->Get("PileUp_DedXSig");
  MC4_Flow_dEdxSig_PileUp_DedXSig = (TProfile *)DC_MC4->Get("PileUp_DedXSig");

  MC1_Flow_dEdxSig_PileUp_DedXSig->SetXTitle("No. of pile-up vertex");
  MC1_Flow_dEdxSig_PileUp_DedXSig->SetYTitle("dE/dx Significance");
  MC1_Flow_dEdxSig_PileUp_DedXSig->SetTitle("");
  MC1_Flow_dEdxSig_PileUp_DedXSig->SetAxisRange(-2, 30, "y");
  MC1_Flow_dEdxSig_PileUp_DedXSig->Draw("E");
  MC2_Flow_dEdxSig_PileUp_DedXSig->Draw("same E");
  MC3_Flow_dEdxSig_PileUp_DedXSig->Draw("same E");
  MC4_Flow_dEdxSig_PileUp_DedXSig->Draw("same E");
  MC1_Flow_dEdxSig_PileUp_DedXSig->SetMarkerColor(30);
  MC1_Flow_dEdxSig_PileUp_DedXSig->SetLineColor(30);
  MC2_Flow_dEdxSig_PileUp_DedXSig->SetMarkerColor(38);
  MC2_Flow_dEdxSig_PileUp_DedXSig->SetLineColor(38);
  MC3_Flow_dEdxSig_PileUp_DedXSig->SetMarkerColor(46);
  MC3_Flow_dEdxSig_PileUp_DedXSig->SetLineColor(46);
  MC4_Flow_dEdxSig_PileUp_DedXSig->SetMarkerColor(20);
  MC4_Flow_dEdxSig_PileUp_DedXSig->SetLineColor(20);
  MC1_Flow_dEdxSig_PileUp_DedXSig->SetMarkerStyle(20);
  MC2_Flow_dEdxSig_PileUp_DedXSig->SetMarkerStyle(21);
  MC3_Flow_dEdxSig_PileUp_DedXSig->SetMarkerStyle(22);
  MC4_Flow_dEdxSig_PileUp_DedXSig->SetMarkerStyle(23);
  mgr::SetSinglePad(canvas);
  mgr::SetAxis(MC1_Flow_dEdxSig_PileUp_DedXSig);
  mgr::DrawEntryRight("2018 MC 16889 Entries");
  mgr::DrawCMSLabelOuter(PRELIMINARY);
  TLegend *leg = new TLegend(0.25, 0.20, 0.55, 0.40);
  leg->SetBorderSize(0);
  leg->SetFillColorAlpha(0, 0);
  leg->SetTextSize(0.04);
  leg->AddEntry(MC1_Flow_dEdxSig_PileUp_DedXSig, "1TeV", "p");
  leg->AddEntry(MC2_Flow_dEdxSig_PileUp_DedXSig, "2TeV", "p");
  leg->AddEntry(MC3_Flow_dEdxSig_PileUp_DedXSig, "3TeV", "p");
  leg->AddEntry(MC4_Flow_dEdxSig_PileUp_DedXSig, "4TeV", "p");
  leg->AddEntry((TObject *)0, "Without any selection", "");
  //  leg->AddEntry((TObject *)0, "", "");
  //	leg->AddEntry((TObject*)0, "1.479 < |#eta| < 3.0 (EcalEndCap) ", "");
  //	leg->AddEntry((TObject*)0, "|#eta| < 3.0 (Whole Ecal) ", "");
  leg->Draw();
  canvas->SaveAs("NPV-dEdxSig_noCut.pdf");
  canvas->SaveAs("~/Atom/NTU-Thesis-LaTeX-Template/figures/NPV-dEdxSig_noCut.pdf");
}
/*-----------------HLT--------------------*/
void NPVvsF51(TDirectory *DC_MC1, TDirectory *DC_MC2, TDirectory *DC_MC3, TDirectory *DC_MC4)
{

  TCanvas  *canvas = new TCanvas("canvas", "", 800, 600);
  TProfile *MC1_Flow_dEdxSig_PileUp_f51, *MC2_Flow_dEdxSig_PileUp_f51, *MC3_Flow_dEdxSig_PileUp_f51,
    *MC4_Flow_dEdxSig_PileUp_f51;
  MC1_Flow_dEdxSig_PileUp_f51 = (TProfile *)DC_MC1->Get("Flow_dEdxSig_PileUp_f51");
  MC2_Flow_dEdxSig_PileUp_f51 = (TProfile *)DC_MC2->Get("Flow_dEdxSig_PileUp_f51");
  MC3_Flow_dEdxSig_PileUp_f51 = (TProfile *)DC_MC3->Get("Flow_dEdxSig_PileUp_f51");
  MC4_Flow_dEdxSig_PileUp_f51 = (TProfile *)DC_MC4->Get("Flow_dEdxSig_PileUp_f51");

  MC1_Flow_dEdxSig_PileUp_f51->SetXTitle("No. of pile-up vertex");
  MC1_Flow_dEdxSig_PileUp_f51->SetYTitle("f51");
  MC1_Flow_dEdxSig_PileUp_f51->SetTitle("");
  MC1_Flow_dEdxSig_PileUp_f51->SetAxisRange(0.2, 1.2, "y");
  MC1_Flow_dEdxSig_PileUp_f51->Draw("E");
  MC2_Flow_dEdxSig_PileUp_f51->Draw("same E");
  MC3_Flow_dEdxSig_PileUp_f51->Draw("same E");
  MC4_Flow_dEdxSig_PileUp_f51->Draw("same E");
  MC1_Flow_dEdxSig_PileUp_f51->SetMarkerColor(30);
  MC1_Flow_dEdxSig_PileUp_f51->SetLineColor(30);
  MC2_Flow_dEdxSig_PileUp_f51->SetMarkerColor(38);
  MC2_Flow_dEdxSig_PileUp_f51->SetLineColor(38);
  MC3_Flow_dEdxSig_PileUp_f51->SetMarkerColor(46);
  MC3_Flow_dEdxSig_PileUp_f51->SetLineColor(46);
  MC4_Flow_dEdxSig_PileUp_f51->SetMarkerColor(20);
  MC4_Flow_dEdxSig_PileUp_f51->SetLineColor(20);
  MC1_Flow_dEdxSig_PileUp_f51->SetMarkerStyle(20);
  MC2_Flow_dEdxSig_PileUp_f51->SetMarkerStyle(21);
  MC3_Flow_dEdxSig_PileUp_f51->SetMarkerStyle(22);
  MC4_Flow_dEdxSig_PileUp_f51->SetMarkerStyle(23);
  mgr::SetSinglePad(canvas);
  mgr::SetAxis(MC1_Flow_dEdxSig_PileUp_f51);
  mgr::DrawEntryRight("2018 MC 16889 Entries");
  mgr::DrawCMSLabelOuter(PRELIMINARY);
  TLegend *leg = new TLegend(0.25, 0.20, 0.55, 0.40);
  leg->SetBorderSize(0);
  leg->SetFillColorAlpha(0, 0);
  leg->SetTextSize(0.04);
  leg->AddEntry(MC1_Flow_dEdxSig_PileUp_f51, "1TeV", "p");
  leg->AddEntry(MC2_Flow_dEdxSig_PileUp_f51, "2TeV", "p");
  leg->AddEntry(MC3_Flow_dEdxSig_PileUp_f51, "3TeV", "p");
  leg->AddEntry(MC4_Flow_dEdxSig_PileUp_f51, "4TeV", "p");
  leg->AddEntry((TObject *)0, "Pass all selection", "");
  //	leg->AddEntry((TObject*)0, "1.479 < |#eta| < 3.0 (EcalEndCap) ", "");
  //	leg->AddEntry((TObject*)0, "|#eta| < 3.0 (Whole Ecal) ", "");
  leg->Draw();
  canvas->SaveAs("NPV-f51.pdf");
  canvas->SaveAs("~/Atom/NTU-Thesis-LaTeX-Template/figures/NPV-f51.pdf");
}
void NPVvsDedxSig(TDirectory *DC_MC1, TDirectory *DC_MC2, TDirectory *DC_MC3, TDirectory *DC_MC4)
{

  TCanvas  *canvas = new TCanvas("canvas", "", 800, 600);
  TProfile *MC1_Flow_dEdxSig_PileUp_DedXSig, *MC2_Flow_dEdxSig_PileUp_DedXSig, *MC3_Flow_dEdxSig_PileUp_DedXSig,
    *MC4_Flow_dEdxSig_PileUp_DedXSig;
  MC1_Flow_dEdxSig_PileUp_DedXSig = (TProfile *)DC_MC1->Get("Flow_dEdxSig_PileUp_DedXSig");
  MC2_Flow_dEdxSig_PileUp_DedXSig = (TProfile *)DC_MC2->Get("Flow_dEdxSig_PileUp_DedXSig");
  MC3_Flow_dEdxSig_PileUp_DedXSig = (TProfile *)DC_MC3->Get("Flow_dEdxSig_PileUp_DedXSig");
  MC4_Flow_dEdxSig_PileUp_DedXSig = (TProfile *)DC_MC4->Get("Flow_dEdxSig_PileUp_DedXSig");

  MC1_Flow_dEdxSig_PileUp_DedXSig->SetXTitle("No. of pile-up vertex");
  MC1_Flow_dEdxSig_PileUp_DedXSig->SetYTitle("dE/dx Significance");
  MC1_Flow_dEdxSig_PileUp_DedXSig->SetTitle("");
  MC1_Flow_dEdxSig_PileUp_DedXSig->SetAxisRange(-2, 30, "y");
  MC1_Flow_dEdxSig_PileUp_DedXSig->Draw("E");
  MC2_Flow_dEdxSig_PileUp_DedXSig->Draw("same E");
  MC3_Flow_dEdxSig_PileUp_DedXSig->Draw("same E");
  MC4_Flow_dEdxSig_PileUp_DedXSig->Draw("same E");
  MC1_Flow_dEdxSig_PileUp_DedXSig->SetMarkerColor(30);
  MC1_Flow_dEdxSig_PileUp_DedXSig->SetLineColor(30);
  MC2_Flow_dEdxSig_PileUp_DedXSig->SetMarkerColor(38);
  MC2_Flow_dEdxSig_PileUp_DedXSig->SetLineColor(38);
  MC3_Flow_dEdxSig_PileUp_DedXSig->SetMarkerColor(46);
  MC3_Flow_dEdxSig_PileUp_DedXSig->SetLineColor(46);
  MC4_Flow_dEdxSig_PileUp_DedXSig->SetMarkerColor(20);
  MC4_Flow_dEdxSig_PileUp_DedXSig->SetLineColor(20);
  MC1_Flow_dEdxSig_PileUp_DedXSig->SetMarkerStyle(20);
  MC2_Flow_dEdxSig_PileUp_DedXSig->SetMarkerStyle(21);
  MC3_Flow_dEdxSig_PileUp_DedXSig->SetMarkerStyle(22);
  MC4_Flow_dEdxSig_PileUp_DedXSig->SetMarkerStyle(23);
  mgr::SetSinglePad(canvas);
  mgr::SetAxis(MC1_Flow_dEdxSig_PileUp_DedXSig);
  mgr::DrawEntryRight("2018 MC 16889 Entries");
  mgr::DrawCMSLabelOuter(PRELIMINARY);
  TLegend *leg = new TLegend(0.25, 0.20, 0.55, 0.40);
  leg->SetBorderSize(0);
  leg->SetFillColorAlpha(0, 0);
  leg->SetTextSize(0.04);
  leg->AddEntry(MC1_Flow_dEdxSig_PileUp_DedXSig, "1TeV", "p");
  leg->AddEntry(MC2_Flow_dEdxSig_PileUp_DedXSig, "2TeV", "p");
  leg->AddEntry(MC3_Flow_dEdxSig_PileUp_DedXSig, "3TeV", "p");
  leg->AddEntry(MC4_Flow_dEdxSig_PileUp_DedXSig, "4TeV", "p");
  leg->AddEntry((TObject *)0, "Pass all selection", "");
  //  leg->AddEntry((TObject *)0, "", "");
  //	leg->AddEntry((TObject*)0, "1.479 < |#eta| < 3.0 (EcalEndCap) ", "");
  //	leg->AddEntry((TObject*)0, "|#eta| < 3.0 (Whole Ecal) ", "");
  leg->Draw();
  canvas->SaveAs("NPV-dEdxSig.pdf");
  canvas->SaveAs("~/Atom/NTU-Thesis-LaTeX-Template/figures/NPV-dEdxSig.pdf");
}
void Draw_MC_PileUp()
{

  gStyle->SetOptStat(0);

  // MC 1TeV
  TFile      *fin1   = new TFile("RootFile/MonoPhotonAnalysis_2018_1000_0.root");
  TDirectory *DC_MC1 = (TDirectory *)fin1->Get("HLT_Photon200");
  DC_MC1->cd();
  TDirectory *DC_MC1_nocut = (TDirectory *)fin1->Get("NOTRG");
  DC_MC1_nocut->cd();
  // M 2TeV
  TFile      *fin2   = new TFile("RootFile/MonoPhotonAnalysis_2018_2000_0.root");
  TDirectory *DC_MC2 = (TDirectory *)fin2->Get("HLT_Photon200");
  DC_MC2->cd();
  TDirectory *DC_MC2_nocut = (TDirectory *)fin2->Get("NOTRG");
  DC_MC2_nocut->cd();
	// M 3TeV
  TFile      *fin3   = new TFile("RootFile/MonoPhotonAnalysis_2018_3000_0.root");
  TDirectory *DC_MC3 = (TDirectory *)fin3->Get("HLT_Photon200");
  DC_MC3->cd();
  TDirectory *DC_MC3_nocut = (TDirectory *)fin3->Get("NOTRG");
  DC_MC3_nocut->cd();
  // 4TeV
  TFile      *fin4   = new TFile("RootFile/MonoPhotonAnalysis_2018_4000_0.root");
  TDirectory *DC_MC4 = (TDirectory *)fin4->Get("HLT_Photon200");
  DC_MC4->cd();
  TDirectory *DC_MC4_nocut = (TDirectory *)fin4->Get("NOTRG");
  DC_MC4_nocut->cd();

  NPVvsDedxSig(DC_MC1, DC_MC2, DC_MC3, DC_MC4);
  NPVvsF51(DC_MC1, DC_MC2, DC_MC3, DC_MC4);
  NPVvsDedxSig_noCut(DC_MC1_nocut, DC_MC2_nocut, DC_MC3_nocut, DC_MC4_nocut);
  NPVvsF51_noCut(DC_MC1_nocut, DC_MC2_nocut, DC_MC3_nocut, DC_MC4_nocut);
}

