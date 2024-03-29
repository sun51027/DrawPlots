////////////////////////////////////////
//
//	Background shape(Data) vs signal shape(MC)
//	for significant plots
//	dEdxSig, f51, FracSatVNstrips,
//
///////////////////////////////////////////////////

#include <string>
using namespace std;
using namespace mgr;
TH1 *DrawHIso(TDirectory *DC_data, TDirectory *DC_MC1, TDirectory *DC_MC2, TDirectory *DC_MC3, TDirectory *DC_MC4)
{

  // HIso
  TCanvas *canvas = new TCanvas("canvas", "", 800, 600);
  TH1D    *MC1_HIso, *MC2_HIso, *MC3_HIso, *MC4_HIso;
  MC1_HIso = (TH1D *)DC_MC1->Get("HcalIso");
  MC2_HIso = (TH1D *)DC_MC2->Get("HcalIso");
  MC3_HIso = (TH1D *)DC_MC3->Get("HcalIso");
  MC4_HIso = (TH1D *)DC_MC4->Get("HcalIso");

  Double_t factor = 1.;
  //  TH1D *Data_HIso;
  //  Data_HIso = (TH1D *)DC_data->Get("Blinded_HIso");
  //  Data_HIso->Scale(factor / Data_HIso->Integral());
  MC1_HIso->Scale(factor / MC1_HIso->Integral());
  MC2_HIso->Scale(factor / MC2_HIso->Integral());
  MC3_HIso->Scale(factor / MC3_HIso->Integral());
  MC4_HIso->Scale(factor / MC4_HIso->Integral());
  MC1_HIso->SetXTitle("HCAL isolation (GeV)");
  MC1_HIso->SetYTitle("");
  MC1_HIso->SetTitle("");
  MC1_HIso->SetLineWidth(2);
  MC2_HIso->SetLineWidth(2);
  MC3_HIso->SetLineWidth(2);
  MC4_HIso->SetLineWidth(2);
  MC1_HIso->Draw("HIST");
  MC2_HIso->Draw("HIST same");
  MC3_HIso->Draw("HIST same");
  MC4_HIso->Draw("HIST same");
  //  Data_HIso->Draw("same");
  MC1_HIso->SetLineColorAlpha(30, 1);
  MC2_HIso->SetLineColorAlpha(38, 1);
  MC3_HIso->SetLineColorAlpha(46, 1);
  MC4_HIso->SetLineColorAlpha(20, 1);
  //  Data_HIso->SetMarkerStyle(8);
  //  Data_HIso->SetMarkerColor(1);
  //  Data_HIso->SetLineColor(1);
  TLegend *leg2 = new TLegend(0.65, 0.55, 0.85, 0.75);
  leg2->SetBorderSize(0);
  leg2->SetTextSize(0.04);
  leg2->SetFillColorAlpha(0, 0);
  leg2->AddEntry(MC1_HIso, "1TeV", "L");
  leg2->AddEntry(MC2_HIso, "2TeV", "L");
  leg2->AddEntry(MC3_HIso, "3TeV", "L");
  leg2->AddEntry(MC4_HIso, "4TeV", "L");
  //  leg2->AddEntry(Data_HIso, "Data", "p");
  leg2->Draw();
  mgr::SetSinglePad(canvas);
  mgr::SetAxis(MC1_HIso);
  mgr::DrawCMSLabelOuter(PRELIMINARY);
  //  mgr::DrawEntryRight("32.93fb^{-1} (13TeV)");
  mgr::DrawEntryRight("2018 MC 13TeV");
  canvas->SetLogy();
  canvas->SaveAs("Thesis/MC_2018_HIso.pdf");
  canvas->SaveAs("/Users/zero/Atom/NTU-Thesis-LaTeX-Template/figures/MC_2018_HIso.pdf");
  delete canvas;
  return MC1_HIso;
}
TH1 *Drawf51(TDirectory *DC_data, TDirectory *DC_MC1, TDirectory *DC_MC2, TDirectory *DC_MC3, TDirectory *DC_MC4)
{

  // F51
  TCanvas *canvas = new TCanvas("canvas", "", 800, 600);
  TH1D    *MC1_F51, *MC2_F51, *MC3_F51, *MC4_F51;
  MC1_F51 = (TH1D *)DC_MC1->Get("F51");
  MC2_F51 = (TH1D *)DC_MC2->Get("F51");
  MC3_F51 = (TH1D *)DC_MC3->Get("F51");
  MC4_F51 = (TH1D *)DC_MC4->Get("F51");

  Double_t factor = 1.;
  TH1D    *Data_F51;
  Data_F51 = (TH1D *)DC_data->Get("Blinded_F51");
  Data_F51->Scale(factor / Data_F51->Integral());
  MC1_F51->Scale(factor / MC1_F51->Integral());
  MC2_F51->Scale(factor / MC2_F51->Integral());
  MC3_F51->Scale(factor / MC3_F51->Integral());
  MC4_F51->Scale(factor / MC4_F51->Integral());
  MC1_F51->SetXTitle("f_{51}");
  MC1_F51->SetYTitle("");
  MC1_F51->SetTitle("");
  MC1_F51->SetLineWidth(2);
  MC2_F51->SetLineWidth(2);
  MC3_F51->SetLineWidth(2);
  MC4_F51->SetLineWidth(2);
  MC1_F51->Draw("HIST");
  MC2_F51->Draw("HIST same");
  MC3_F51->Draw("HIST same");
  MC4_F51->Draw("HIST same");
  Data_F51->Draw("same");
  MC1_F51->SetLineColorAlpha(30, 1);
  MC2_F51->SetLineColorAlpha(38, 1);
  MC3_F51->SetLineColorAlpha(46, 1);
  MC4_F51->SetLineColorAlpha(20, 1);
  Data_F51->SetMarkerStyle(8);
  Data_F51->SetMarkerColor(1);
  Data_F51->SetLineColor(1);
  TLegend *leg2 = new TLegend(0.55, 0.15, 0.75, 0.45);
  leg2->SetBorderSize(0);
  leg2->SetTextSize(0.04);
  leg2->SetFillColorAlpha(0, 0);
  leg2->AddEntry(MC1_F51, "1TeV", "L");
  leg2->AddEntry(MC2_F51, "2TeV", "L");
  leg2->AddEntry(MC3_F51, "3TeV", "L");
  leg2->AddEntry(MC4_F51, "4TeV", "L");
  leg2->AddEntry(Data_F51, "Data", "p");
  leg2->Draw();
  mgr::SetSinglePad(canvas);
  mgr::SetAxis(MC1_F51);
  mgr::DrawCMSLabelOuter(PRELIMINARY);
  mgr::DrawEntryRight("32.93fb^{-1} (13TeV)");
  //		mgr::DrawEntryRight("2018 MC 13TeV");
  canvas->SaveAs("MCvsData_2018_F51.pdf");
  delete canvas;
  //		canvas->SaveAs("MC2018_F51.pdf");
  return MC1_F51;
}
TH1 *DrawDedXSig(TDirectory *DC_data, TDirectory *DC_MC1, TDirectory *DC_MC2, TDirectory *DC_MC3, TDirectory *DC_MC4,
                 TDirectory *DC_MC5)
{
  TCanvas *canvas = new TCanvas("canvas", "", 800, 600);
  TH1D    *MC1_DedXSig, *MC2_DedXSig, *MC3_DedXSig, *MC4_DedXSig, *MC5_DedXSig;
  MC1_DedXSig = (TH1D *)DC_MC1->Get("DedXSig");
  MC2_DedXSig = (TH1D *)DC_MC2->Get("DedXSig");
  MC3_DedXSig = (TH1D *)DC_MC3->Get("DedXSig");
  MC4_DedXSig = (TH1D *)DC_MC4->Get("DedXSig");
  MC5_DedXSig = (TH1D *)DC_MC5->Get("DedXSig");

  Double_t factor = 1.;
  TH1D    *Data_DedXSig;
  Data_DedXSig = (TH1D *)DC_data->Get("Blinded_DedXSig");
  Data_DedXSig->Scale(factor / Data_DedXSig->Integral());
  MC1_DedXSig->Scale(factor / MC1_DedXSig->Integral());
  MC2_DedXSig->Scale(factor / MC2_DedXSig->Integral());
  MC3_DedXSig->Scale(factor / MC3_DedXSig->Integral());
  MC4_DedXSig->Scale(factor / MC4_DedXSig->Integral());
  MC5_DedXSig->Scale(factor / MC5_DedXSig->Integral());
  MC1_DedXSig->SetXTitle("dE/dx_{Significance}");
  MC1_DedXSig->SetYTitle("");
  MC1_DedXSig->SetTitle("");
  MC1_DedXSig->SetLineWidth(2);
  MC2_DedXSig->SetLineWidth(2);
  MC3_DedXSig->SetLineWidth(2);
  MC4_DedXSig->SetLineWidth(2);
  MC5_DedXSig->SetLineWidth(2);
  MC1_DedXSig->Draw("HIST");
  MC2_DedXSig->Draw("HIST same");
  MC3_DedXSig->Draw("HIST same");
  MC4_DedXSig->Draw("HIST same");
  //  MC5_DedXSig->Draw("HIST same");
//  Data_DedXSig->Draw("same");
  MC1_DedXSig->SetLineColorAlpha(30, 1);
  MC2_DedXSig->SetLineColorAlpha(38, 1);
  MC3_DedXSig->SetLineColorAlpha(46, 1);
  MC4_DedXSig->SetLineColorAlpha(20, 1);
  //	MC5_DedXSig->SetLineColorAlpha(2,1);
  Data_DedXSig->SetMarkerStyle(8);
  Data_DedXSig->SetMarkerColor(1);
  Data_DedXSig->SetLineColor(1);
  mgr::SetSinglePad(canvas);
  mgr::SetAxis(MC1_DedXSig);
  mgr::DrawEntryRight("32.93fb^{-1} (2018 13TeV)");
  //		mgr::DrawEntryRight("2018 MC 13TeV");
  mgr::DrawCMSLabelOuter(PRELIMINARY);
  TLegend *leg = new TLegend(0.25, 0.85, 0.55, 0.60);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.04);
  leg->SetFillColorAlpha(0, 0);
  leg->AddEntry(MC1_DedXSig, "1TeV", "L");
  //		leg->AddEntry(MC5_DedXSig,"1TeV Delta-ray off","L");
  leg->AddEntry(MC2_DedXSig, "2TeV", "L");
  leg->AddEntry(MC3_DedXSig, "3TeV", "L");
  leg->AddEntry(MC4_DedXSig, "4TeV", "L");
//  leg->AddEntry(Data_DedXSig, "Data", "p");
  leg->Draw();
  canvas->SetLogy(1);
  canvas->SaveAs("MCvsData_2018_DedXSig.pdf");

  delete canvas;
  return MC1_DedXSig;
}
TH2 *DrawFracSatVNstrips(TDirectory *DC_data, TDirectory *DC_MC1)
{

  TCanvas *canvas = new TCanvas("canvas", "", 800, 600);
  TH2D    *MC1_FracSatVNstrips;
  MC1_FracSatVNstrips = (TH2D *)DC_MC1->Get("Flow_dEdxSig_FracSatVNstrips");
  TH2D *Data_FracSatVNstrips;
  Data_FracSatVNstrips = (TH2D *)DC_data->Get("FracSatVNstrips");
  //Data_FracSatVNstrips = (TH2D *)DC_data->Get("Blinded_FracSatVNstrips");
  MC1_FracSatVNstrips->SetYTitle("Fraction of saturated strips");
  MC1_FracSatVNstrips->SetXTitle("Total number of strips");
  MC1_FracSatVNstrips->SetTitle("");
  MC1_FracSatVNstrips->Draw("");
  Data_FracSatVNstrips->Draw("same COZ");
  MC1_FracSatVNstrips->SetMarkerColor(kRed);
  Data_FracSatVNstrips->SetMarkerStyle(7);
  MC1_FracSatVNstrips->SetMarkerStyle(7);
  Data_FracSatVNstrips->SetMarkerColor(1);

  TH1D *MC1_DedXSig;
  MC1_DedXSig = (TH1D *)DC_MC1->Get("DedXSig");

  //	for(int i=0;i < MC1_FracSatVNstrips->GetNbinsX();i++){
  //	for(int j=0;j < MC1_FracSatVNstrips->GetNbinsY();j++){

  cout << Data_FracSatVNstrips->GetBinContent(0, 0) << endl;
  //}
  //	}

  TLegend *leg3 = new TLegend(0.55, 0.55, 0.75, 0.35);
  leg3->SetBorderSize(0);
  leg3->SetTextSize(0.05);
  leg3->SetFillColorAlpha(0, 0);
  leg3->AddEntry(MC1_FracSatVNstrips, "Monopole 1TeV", "p");
  leg3->AddEntry(Data_FracSatVNstrips, "Data", "p");
  leg3->Draw();
  mgr::SetSinglePad(canvas);
  mgr::SetAxis(MC1_FracSatVNstrips);
  mgr::DrawCMSLabelOuter(PRELIMINARY);
  mgr::DrawEntryRight("1.8fb^{-1} 13TeV");
   canvas->SaveAs("MCvsData_2018_FracSatVNstrips.pdf");
  //	delete canvas;
  return MC1_FracSatVNstrips;
}
void DrawNPV(TDirectory *DC_data, TDirectory *DC_MC1, TDirectory *DC_MC2, TDirectory *DC_MC3, TDirectory *DC_MC4)
{
  TCanvas  *c1      = new TCanvas("canvas", "", 800, 600);
  TProfile *dEdxNPV = (TProfile *)DC_MC1->Get("PileUp_DedXSig");
  dEdxNPV->SetXTitle("No. of Pile up vertex");
  dEdxNPV->SetYTitle("#LT dE/dx #GT");
  dEdxNPV->SetMarkerStyle(9);
  dEdxNPV->Draw("E1");
  mgr::SetSinglePad(c1);
  mgr::SetAxis(dEdxNPV);
  mgr::DrawCMSLabelOuter(SIMULATION);
  mgr::DrawEntryRight("2018 MC 13TeV");
  c1->SaveAs("./Plots/PileUp_DedXSig.pdf");

  TProfile *f51NPV = (TProfile *)DC_MC1->Get("PileUp_f51");
  f51NPV->SetXTitle("No. of Pile up vertex");
  f51NPV->SetYTitle("#LT f51 #GT");
  f51NPV->SetMarkerStyle(9);
  f51NPV->Draw("E1");
  mgr::SetSinglePad(c1);
  mgr::SetAxis(f51NPV);
  mgr::DrawCMSLabelOuter(SIMULATION);
  mgr::DrawEntryRight("2018 MC 13TeV");
  c1->SaveAs("./Plots/PileUp_f51.pdf");
}
void DrawABCD(TDirectory *DC_data, TDirectory *DC_MC1, TDirectory *DC_MC2, TDirectory *DC_MC3, TDirectory *DC_MC4)
{
  //	TH1D *MC1_ABCD,*MC2_ABCD,*MC3_ABCD,*MC4_ABCD;

  /*        double dEdXSigCut_ = 9;
        double f51Cut_ = 0.85;
        TH2D* ABCD;
        ABCD = (TH2D*)DC_data->Get("Blinded_ABCD");
        ABCD->SetXTitle("f51");
        ABCD->SetYTitle("dE/dX significance");
        ABCD->SetTitle("");
        ABCD->SetMarkerStyle(7);
        ABCD->Draw("COLZ");
        mgr::SetSinglePad(canvas);
        mgr::SetAxis(ABCD);
        mgr::DrawCMSLabelOuter(SIMULATION);
        mgr::DrawEntryRight("2018 13TeV 32.93/fb");
        TLine *TightY = new TLine(0,dEdXSigCut_,1.1,dEdXSigCut_);
        TightY->SetLineColor(4);
        TightY->SetLineStyle(7);
        TightY->SetLineWidth(3);
        TightY->Draw("same");
        TLine *TightX = new TLine(f51Cut_,0,f51Cut_,30);
        TightX->SetLineColor(4);
        TightX->SetLineStyle(7);
        TightX->SetLineWidth(3);
        TightX->Draw("same");
        TLine *LooseY = new TLine(0,7,1.1,7);
        LooseY->SetLineColor(38);
        LooseY->SetLineStyle(7);
        LooseY->Draw("same");
        TLine *LooseX = new TLine(0.6,0,0.6,30);
        LooseX->SetLineColor(38);
        LooseX->SetLineStyle(7);
        LooseX->Draw("same");
        canvas->SaveAs("./Plots/Data_ABCD.pdf");

   */
}
void Draw_MCvsData_SignificantPlots()
{

  TCanvas *canvas = new TCanvas("canvas", "", 800, 600);
  gStyle->SetOptStat(0);

  // data
  TFile      *fin_data = new TFile("RootFile/MonoData2018_Plot.root");
  TDirectory *DC_data  = (TDirectory *)fin_data->Get("HLT_Photon");
  DC_data->cd();
  // MC 1TeV
  TFile      *fin1   = new TFile("RootFile/MonoPhotonAnalysis_2018_1000_0.root");
  TDirectory *DC_MC1 = (TDirectory *)fin1->Get("HLT_Photon200");
  DC_MC1->cd();
  // M 2TeV
  TFile      *fin2   = new TFile("RootFile/MonoPhotonAnalysis_2018_2000_0.root");
  TDirectory *DC_MC2 = (TDirectory *)fin2->Get("HLT_Photon200");
  DC_MC2->cd();
  // 3TeV
  TFile      *fin3   = new TFile("RootFile/MonoPhotonAnalysis_2018_3000_0.root");
  TDirectory *DC_MC3 = (TDirectory *)fin3->Get("HLT_Photon200");
  DC_MC3->cd();
  // 4TeV
  TFile      *fin4   = new TFile("RootFile/MonoPhotonAnalysis_2018_4000_0.root");
  TDirectory *DC_MC4 = (TDirectory *)fin4->Get("HLT_Photon200");
  DC_MC4->cd();
  // delta ray off
  TFile      *fin5   = new TFile("RootFile/DeltaRayOff_Analysis_2018_1000_NoMatched.root");
  TDirectory *DC_MC5 = (TDirectory *)fin5->Get("HLT_Photon200");
  DC_MC5->cd();

    DrawFracSatVNstrips(DC_data, DC_MC1);
  //  DrawDedXSig(DC_data, DC_MC1, DC_MC2, DC_MC3, DC_MC4, DC_MC5);
  
  //  Drawf51(DC_data, DC_MC1, DC_MC2, DC_MC3, DC_MC4);
  // DrawHIso(DC_data, DC_MC1, DC_MC2, DC_MC3, DC_MC4);
//  DrawNPV(DC_data, DC_MC1, DC_MC2, DC_MC3, DC_MC4);
}
