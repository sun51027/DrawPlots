//
//	Draw all plots from Analyzer.root!!
//	（沒必要話全部ㄅ ）
//
//
#include <string>
using namespace std;
void Draw_MC_allPlots()
{
  // create a canvas
  string Mass[3] = {"1TeV", "2TeV", "3TeV", "4TeV"};
  string GeV[3]  = {"1000", "2000", "3000", "4000"};
  string Year[2] = {"2017", "2018"};

  TCanvas *canvas = new TCanvas("canvas", "", 800, 600);

  for (int y = 1; y < 2; y++) {
    for (int m = 0; m < 3; m++) {
      // open file and directory
      TFile      *fin = new TFile(("Monopole_Analyzer_" + Year[y] + "_" + GeV[m] + ".root").c_str());
      TDirectory *dir = (TDirectory *)fin->Get("NOTRG");

      dir->cd();

      gStyle->SetOptStat(0);
      const int     plotNum       = 10;
      string        plotName[10]  = {"NoCut_", "N1_Quality_",   "N1_Energy_",   "N1_F51_",   "N1_dEdxSig_",
                             "N1_",    "Flow_Quality_", "Flow_Energy_", "Flow_F51_", "Flow_dEdxSig_"};
      string        histogram[10] = {"",     "N_1_Quality_",  "N_1_Energy_",  "N_1_F51_",  "N_1_dEdxSig_",
                              "N_1_", "Flow_Quality_", "Flow_Energy_", "Flow_F51_", "Flow_dEdxSig_"};
      string        plotCut[6]    = {"FracSatVNstrips", "DedXSig", "RZcurv", "F51", "HcalIso", "ABCD"};
      vector<TH1 *> FracSatVNstrips;
      vector<TH1 *> DedXSig;
      vector<TH1 *> RZcurv;
      vector<TH1 *> F51;
      vector<TH1 *> HcalIso;
      vector<TH1 *> Energy;
      vector<TH1 *> ABCD;
      for (int i = 0; i < plotNum; i++) {

        // create FracSatVNstrips
        FracSatVNstrips.push_back((TH2D *)dir->Get((histogram[i] + "FracSatVNstrips").c_str()));
        FracSatVNstrips[i]->SetXTitle("Total No. of Strips");
        FracSatVNstrips[i]->SetYTitle("fraction of saturated strips");
        FracSatVNstrips[i]->SetTitle("");
        FracSatVNstrips[i]->Draw();
        mgr::SetSinglePad(canvas);
        mgr::SetAxis(FracSatVNstrips[i]);
        mgr::DrawCMSLabelOuter(SIMULATION);
        mgr::DrawEntryRight((Year[y] + " Mass " + Mass[m]).c_str());
        canvas->SaveAs(
          ("./Plots/" + Year[y] + " MC 15k " + Mass[m] + "/NoTRG/" + plotName[i] + "FracSatVNstrips.pdf").c_str());

        // create dedx
        DedXSig.push_back((TH1D *)dir->Get((histogram[i] + "DedXSig").c_str()));
        DedXSig[i]->SetXTitle("dE/dX Significance");
        DedXSig[i]->SetYTitle("Entries");
        DedXSig[i]->SetTitle("");
        DedXSig[i]->SetLineColorAlpha(28, 0.5);
        DedXSig[i]->SetFillColor(42);
        DedXSig[i]->Draw();
        mgr::SetSinglePad(canvas);
        mgr::SetAxis(DedXSig[i]);
        mgr::DrawCMSLabelOuter(SIMULATION);
        mgr::DrawEntryRight((Year[y] + " Mass " + Mass[m] + " 15000 Entries").c_str());
        TLegend *leg = new TLegend(0.18, 0.77, 0.43, 0.82);
        leg->SetBorderSize(0);
        leg->SetFillColorAlpha(0, 0);
        leg->AddEntry(DedXSig[i], Mass[m].c_str(), "f");
        leg->Draw();
        canvas->SaveAs(("./Plots/" + Year[y] + " MC 15k " + Mass[m] + "/NoTRG/" + plotName[i] + "DedXSig.pdf").c_str());

        // create f51
        F51.push_back((TH1D *)dir->Get((histogram[i] + "F51").c_str()));
        F51[i]->SetXTitle("F51(E5x1/E5x5)");
        F51[i]->SetYTitle("Entries");
        F51[i]->SetLineColorAlpha(28, 0.5);
        F51[i]->SetFillColor(42);
        F51[i]->SetTitle("");
        F51[i]->Draw();
        mgr::SetSinglePad(canvas);
        mgr::SetAxis(F51[i]);
        mgr::DrawCMSLabelOuter(SIMULATION);
        mgr::DrawEntryRight((Year[y] + " Mass " + Mass[m] + " 15000 Entries").c_str());
        TLegend *leg2 = new TLegend(0.18, 0.77, 0.43, 0.82);
        leg2->SetBorderSize(0);
        leg2->SetFillColorAlpha(0, 0);
        leg2->AddEntry(F51[i], Mass[m].c_str(), "f");
        leg2->Draw();
        canvas->SaveAs(("./Plots/" + Year[y] + " MC 15k " + Mass[m] + "/NoTRG/" + plotName[i] + "F51.pdf").c_str());

        string test = Year[y] + " Mass " + Mass[m] + " 15000 Entries";
        // create hiso
        HcalIso.push_back((TH1D *)dir->Get((histogram[i] + "HcalIso").c_str()));
        HcalIso[i]->SetXTitle("Energy(GeV)");
        HcalIso[i]->SetYTitle("Entries");
        HcalIso[i]->SetLineColorAlpha(28, 0.5);
        HcalIso[i]->SetFillColor(42);
        HcalIso[i]->SetTitle("");
        HcalIso[i]->Draw();
        mgr::SetSinglePad(canvas);
        mgr::SetAxis(HcalIso[i]);
        mgr::DrawCMSLabelOuter(SIMULATION);
        mgr::DrawEntryRight((Year[y] + " Mass " + Mass[m] + " 15000 Entries").c_str());
        TLegend *leg3 = new TLegend(0.7, 0.77, 0.95, 0.82);
        leg3->SetBorderSize(0);
        leg3->SetFillColorAlpha(0, 0);
        leg3->AddEntry(HcalIso[i], Mass[m].c_str(), "f");
        leg3->Draw();
        canvas->SaveAs(("./Plots/" + Year[y] + " MC 15k " + Mass[m] + "/NoTRG/" + plotName[i] + "HcalIso.pdf").c_str());

        // Energy(e55)
        Energy.push_back((TH1D *)dir->Get((histogram[i] + "E55").c_str()));
        Energy[i]->SetXTitle("Energy(GeV)");
        Energy[i]->SetYTitle("Entries");
        Energy[i]->SetLineColorAlpha(28, 0.5);
        Energy[i]->SetFillColor(42);
        Energy[i]->SetTitle("");
        Energy[i]->Draw();
        mgr::SetSinglePad(canvas);
        mgr::SetAxis(Energy[i]);
        mgr::DrawCMSLabelOuter(SIMULATION);
        mgr::DrawEntryRight((Year[y] + " Mass " + Mass[m] + " 15000 Entries").c_str());
        TLegend *leg4 = new TLegend(0.7, 0.77, 0.95, 0.82);
        leg4->SetBorderSize(0);
        leg4->SetFillColorAlpha(0, 0);
        leg4->AddEntry(Energy[i], Mass[m].c_str(), "f");
        leg4->Draw();
        canvas->SaveAs(
          ("./Plots/" + Year[y] + " MC 15k " + Mass[m] + "/NoTRG/" + plotName[i] + "Energy(e55).pdf").c_str());

        // Rz curv
        RZcurv.push_back((TH1D *)dir->Get((histogram[i] + "RZcurv").c_str()));
        RZcurv[i]->SetXTitle("R-Z curvature");
        RZcurv[i]->SetYTitle("Entries");
        RZcurv[i]->SetLineColorAlpha(28, 0.5);
        RZcurv[i]->SetFillColor(42);
        RZcurv[i]->SetTitle("");
        RZcurv[i]->Draw();
        mgr::SetSinglePad(canvas);
        mgr::SetAxis(RZcurv[i]);
        mgr::DrawCMSLabelOuter(SIMULATION);
        mgr::DrawEntryRight((Year[y] + " Mass " + Mass[m] + " 15000 Entries").c_str());
        TLegend *leg5 = new TLegend(0.7, 0.77, 0.95, 0.82);
        leg5->SetBorderSize(0);
        leg5->SetFillColorAlpha(0, 0);
        leg5->AddEntry(RZcurv[i], Mass[m].c_str(), "f");
        leg5->Draw();
        canvas->SaveAs(("./Plots/" + Year[y] + " MC 15k " + Mass[m] + "/NoTRG/" + plotName[i] + "RZcurv.pdf").c_str());

        double dEdXSigCut_ = 9;
        double f51Cut_     = 0.85;
        ABCD.push_back((TH2D *)dir->Get((histogram[i] + "ABCD").c_str()));
        ABCD[i]->SetXTitle("f51");
        ABCD[i]->SetYTitle("dE/dX significance");
        ABCD[i]->SetTitle("");
        ABCD[i]->SetMarkerStyle(7);
        ABCD[i]->Draw();
        mgr::SetSinglePad(canvas);
        mgr::SetAxis(ABCD[i]);
        mgr::DrawCMSLabelOuter(SIMULATION);
        mgr::DrawEntryRight((Year[y] + " Mass " + Mass[m] + " 15000 Entries").c_str());
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
        TLine *LooseY = new TLine(0, 7, 1.1, 7);
        LooseY->SetLineColor(38);
        LooseY->SetLineStyle(7);
        LooseY->Draw("same");
        TLine *LooseX = new TLine(0.6, 0, 0.6, 30);
        LooseX->SetLineColor(38);
        LooseX->SetLineStyle(7);
        LooseX->Draw("same");
        canvas->SaveAs(("./Plots/" + Year[y] + " MC 15k " + Mass[m] + "/NoTRG/" + plotName[i] + "ABCD.pdf").c_str());
      }
    } // mass
  }   // year
}
