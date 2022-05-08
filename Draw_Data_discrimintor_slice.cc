
#include <string>
using namespace std;
using namespace mgr;
void Draw_Data_discrimintor_slice()
{

  TCanvas *canvas = new TCanvas("canvas", "", 800, 600);
  gStyle->SetOptStat(0);

  // data
  TFile      *fin_data = new TFile("RootFile/UnBlindAnalysis.root");
  TDirectory *data     = (TDirectory *)fin_data->Get("HLT_Photon");
  data->cd();
  canvas->SetLogy();

  TH2 *ABCD;
  ABCD = (TH2 *)data->Get("Blinded_ABCD");
  cout << "Covarianve between f51 & dEdx " << ABCD->GetCovariance(1, 2) << endl;
  cout << "Correlation between f51 & dEdx " << ABCD->GetCorrelationFactor(1, 2) << endl;

  //---f51---\\

  TH1 *f51_all;
  f51_all = (TH1 *)data->Get("Blinded_DedXSig");
  f51_all->Scale(1. / f51_all->Integral());
  vector<TH1 *> f51_slice;
  f51_slice.push_back((TH1 *)data->Get("Blinded_F51_slice1"));
  f51_slice.push_back((TH1 *)data->Get("Blinded_F51_slice2"));
  f51_slice.push_back((TH1 *)data->Get("Blinded_F51_slice3"));
  f51_slice.push_back((TH1 *)data->Get("Blinded_F51_slice4"));
  f51_slice.push_back((TH1 *)data->Get("Blinded_F51_slice5"));
  f51_slice.push_back((TH1 *)data->Get("Blinded_F51_slice6"));
  for (int i = 0; i < f51_slice.size(); i++) {
    f51_slice[i]->Scale(1. / f51_slice[i]->Integral());
    f51_slice[i]->SetXTitle("dEdxSig");
    f51_slice[i]->SetYTitle("Entries");
    f51_slice[i]->SetTitle("");
    f51_slice[0]->SetLineColor(40);
    f51_slice[1]->SetLineColor(30);
    f51_slice[2]->SetLineColor(38);
    f51_slice[3]->SetLineColor(46);
    f51_slice[4]->SetLineColor(20);
    f51_slice[5]->SetLineColor(13);

    mgr::SetSinglePad(canvas);
    mgr::SetAxis(f51_slice[i]);
    mgr::SetAxis(f51_all);
    mgr::DrawEntryRight("2018 13TeV 32.93/fb");
    mgr::DrawCMSLabelOuter(PRELIMINARY);
    //	  f51_slice[i]->Draw("same");
    if (i == 3)
      f51_slice[i]->Draw("E");
    else
      f51_slice[i]->Draw("same E");
  }
  f51_all->Draw("hist same");
  TLegend *leg = new TLegend(0.7, 0.85, 1.00, 0.70);
  leg->SetBorderSize(0);
  leg->SetFillColorAlpha(0, 0);
  leg->AddEntry(f51_slice[0], "0 < f51 < 0.17", "f");
  leg->AddEntry(f51_slice[1], "0.17 < f51 < 0.34", "f");
  leg->AddEntry(f51_slice[2], "0.34 < f51 < 0.51", "f");
  leg->AddEntry(f51_slice[3], "0.51 < f51 < 0.68", "f");
  leg->AddEntry(f51_slice[4], "0.68 < f51 < 0.85", "f");
  leg->AddEntry(f51_slice[5], "0.85 < f51 < 1.02", "f");
  leg->Draw();
  canvas->SaveAs("Data_f51_slice.pdf");

  //----dEdxSig----\\

  TH1 *dEdxSig_all;
  dEdxSig_all = (TH1 *)data->Get("Blinded_F51");
  dEdxSig_all->Scale(1. / dEdxSig_all->Integral());
  // slice
  vector<TH1 *> dEdxSig_slice;
  dEdxSig_slice.push_back((TH1 *)data->Get("Blinded_DedXSig_slice1"));
  dEdxSig_slice.push_back((TH1 *)data->Get("Blinded_DedXSig_slice2"));
  dEdxSig_slice.push_back((TH1 *)data->Get("Blinded_DedXSig_slice3"));
  dEdxSig_slice.push_back((TH1 *)data->Get("Blinded_DedXSig_slice4"));
  dEdxSig_slice.push_back((TH1 *)data->Get("Blinded_DedXSig_slice5"));
  dEdxSig_slice.push_back((TH1 *)data->Get("Blinded_DedXSig_slice6"));
  dEdxSig_slice.push_back((TH1 *)data->Get("Blinded_DedXSig_slice7"));
  for (int i = 0; i < dEdxSig_slice.size(); i++) {
    dEdxSig_slice[i]->Scale(1. / dEdxSig_slice[i]->Integral());
    dEdxSig_slice[i]->SetXTitle("f51");
    dEdxSig_slice[i]->SetYTitle("Entries");
    dEdxSig_slice[i]->SetTitle("");
    dEdxSig_slice[0]->SetLineColor(40);
    dEdxSig_slice[1]->SetLineColor(30);
    dEdxSig_slice[2]->SetLineColor(38);
    dEdxSig_slice[3]->SetLineColor(46);
    dEdxSig_slice[4]->SetLineColor(20);
    dEdxSig_slice[5]->SetLineColor(13);
    dEdxSig_slice[6]->SetLineColor(4);
    mgr::SetSinglePad(canvas);
    mgr::SetAxis(dEdxSig_slice[i]);
    mgr::SetAxis(dEdxSig_all);
    mgr::DrawEntryRight("2018 13TeV 32.93/fb");
    mgr::DrawCMSLabelOuter(PRELIMINARY);
    //	  dEdxSig_slice[i]->Draw("same");
    if (i == 0)
      dEdxSig_slice[i]->Draw("E");
    else
      dEdxSig_slice[i]->Draw("same E");
  }
  dEdxSig_all->Draw("hist same");
  TLegend *leg2 = new TLegend(0.7, 0.85, 1.00, 0.70);
  leg2->SetBorderSize(0);
  leg2->SetFillColorAlpha(0, 0);
  leg2->AddEntry(dEdxSig_slice[0], "0 < dEdxSig < 1.5", "f");
  leg2->AddEntry(dEdxSig_slice[1], "1.5 < dEdxSig < 3.0", "f");
  leg2->AddEntry(dEdxSig_slice[2], "3.0 < dEdxSig < 4.5", "f");
  leg2->AddEntry(dEdxSig_slice[3], "4.5 < dEdxSig < 6.0", "f");
  leg2->AddEntry(dEdxSig_slice[4], "6.0 < dEdxSig < 7.5", "f");
  leg2->AddEntry(dEdxSig_slice[5], "7.5 < dEdxSig < 9", "f");
  leg2->AddEntry(dEdxSig_slice[6], "9 < dEdxSig < 10.5", "f");
  leg2->Draw();
  canvas->SaveAs("Data_dEdxSig_slice.pdf");
}
