
using namespace std;
void Draw_MC_f51_uncertainty(string mass = "1000")
{

  TCanvas    *canvas = new TCanvas("canvas", "", 800, 600);
  TFile      *fin1   = new TFile(("./RootFile/MonoPhotonAnalysis_2018_" + mass + "_1.root").c_str());
  TDirectory *NOTRG1 = (TDirectory *)fin1->Get("HLT_Photon200");
  NOTRG1->cd();
  TFile      *fin2   = new TFile(("./RootFile/MonoPhotonAnalysis_2018_"+mass+"_DeltaRayOff_1.root").c_str());
  TDirectory *NOTRG2 = (TDirectory *)fin2->Get("HLT_Photon200");
  NOTRG2->cd();
//  TFile      *fin3   = new TFile(("./RootFile/EcalUncertainty_Analysis_2018_" + mass + ".root").c_str());
//  TDirectory *NOTRG3 = (TDirectory *)fin3->Get("HLT_Photon200");
//  NOTRG3->cd();
  gStyle->SetOptStat(0);

  double dEdXSigCut_ = 9;
  double f51Cut_     = 0.85;

//  TH2D *ABCD[3];
//  TH2D *ABCD_deltaRayOff;
//  TH2D *ABCD_spikeOff;
//  ABCD[0] = (TH2D *)NOTRG1->Get("ABCD");
//  ABCD[1] = (TH2D *)NOTRG2->Get("ABCD"); // deltaRay off
//  ABCD[2] = (TH2D *)NOTRG3->Get("ABCD"); // spike off

  /*	for(int i=0; i<3 ;i++){
              ABCD[i]->SetXTitle("f51");
              ABCD[i]->SetYTitle("dE/dX significance");
              ABCD[i]->SetTitle("");
              ABCD[i]->SetMarkerStyle(7);
              ABCD[i]->Draw("COLZ");
  //            mgr::SetSinglePad(canvas);
              mgr::SetAxis(ABCD[i]);
              mgr::DrawCMSLabelOuter(SIMULATION);
        if(i==0)      mgr::DrawEntryRight(("2018 13TeV Mass "+mass+"GeV 16389 Entries").c_str());
        else if(i==1)      mgr::DrawEntryRight(("2018 13TeV Mass "+mass+"GeV 14500 Entries").c_str());
        else if(i==2)      mgr::DrawEntryRight(("2018 13TeV Mass "+mass+"GeV 16889 Entries").c_str());
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
        if(i==0)	canvas->SaveAs("./Plots/ABCD_default.pdf");
        else if(i==1)	canvas->SaveAs("./Plots/ABCD_deltaRayOff.pdf");
        else if(i==2)	canvas->SaveAs("./Plots/ABCD_spikeOff.pdf");
    }
  */
  canvas->SetLogy();
  TH1D *f51;
  TH1D *f51_deltaRayOff;
//  TH1D *f51_spikeOff;
//  f51             = (TH1D *)NOTRG1->Get("F51");
//  f51_deltaRayOff = (TH1D *)NOTRG2->Get("F51");
  f51             = (TH1D *)NOTRG1->Get("Flow_F51_F51");
  f51_deltaRayOff = (TH1D *)NOTRG2->Get("Flow_F51_F51");
//  f51_spikeOff    = (TH1D *)NOTRG3->Get("Flow_dEdxSig_F51");
  f51->Scale(1 / f51->Integral());
  f51_deltaRayOff->Scale(1 / f51_deltaRayOff->Integral());
//  f51_spikeOff->Scale(1 / f51_spikeOff->Integral());
  f51_deltaRayOff->SetXTitle("f_{51}");
  f51_deltaRayOff->SetYTitle("Entries");
  f51_deltaRayOff->SetTitle("");
  f51->SetLineColor(46);
  f51_deltaRayOff->SetLineColor(38);
//  f51_spikeOff->SetLineColor(8);
  f51->SetLineWidth(3);
  f51_deltaRayOff->SetLineWidth(3);
//  f51_spikeOff->SetLineWidth(3);
  f51_deltaRayOff->Draw("hist"); // note: deltaRay make f51 smaller!
//  f51_deltaRayOff->SetAxisRange(0.8, 1.05, "x");
  f51->Draw("hist same");
//  f51_spikeOff->Draw("same hist");
  mgr::SetSinglePad(canvas);
  mgr::SetAxis(f51);
  mgr::DrawCMSLabelOuter(SIMULATION);
  mgr::DrawEntryRight(("2018 Mass " + mass + " GeV").c_str());
  TLegend *leg4 = new TLegend(0.3, 0.85, 0.55, 0.60);
  leg4->SetBorderSize(0);
  leg4->SetFillColorAlpha(0, 0);
  leg4->AddEntry(f51, "Default", "l");
  leg4->AddEntry(f51_deltaRayOff, "Delta-ray Off", "l");
//  leg4->AddEntry(f51_spikeOff, "Spike algorithm Off", "l");
  leg4->Draw();
  canvas->SaveAs(("Plots/f51_ShowerShape_Matched_cutall" + mass + ".pdf").c_str());

  ofstream fout("f51_uncert" + mass + ".csv");

  fout << "2018 " + mass + ",f51 deltaRay Off,f51 spike Off,f51 default" << endl;
//  fout << "Mean (from f51 distribution)," << f51_deltaRayOff->GetMean() << "," << f51_spikeOff->GetMean() << ","
//       << f51->GetMean() << endl;
  fout << "Mean (from f51 distribution)," << f51_deltaRayOff->GetMean() << ","
       << f51->GetMean() << endl;
//  fout << "Uncertainty," << (f51_deltaRayOff->GetMean() - f51->GetMean()) / f51->GetMean() << ","
//       << (f51_spikeOff->GetMean() - f51->GetMean()) / f51->GetMean() << endl;
  fout << "Uncertainty," << (f51_deltaRayOff->GetMean() - f51->GetMean()) / f51->GetMean() <<endl;

  cout << "f51 default " << f51->GetMean() << endl;
  cout << "f51 deltaRay Off " << f51_deltaRayOff->GetMean() << endl;
//  cout << "f51 spike Off " << f51_spikeOff->GetMean() << endl;
}
