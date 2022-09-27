
#include <string>
using namespace std;
using namespace mgr;
void Draw_MC_generator()
{
  // create a canvas
  string Mass[8] = {"1TeV", "1.5TeV", "2TeV", "2.5TeV", "3TeV", "3.5TeV", "4TeV", "4.5TeV"};
  string GeV[8]  = {"1000", "1500", "2000", "2500", "3000", "3500", "4000", "4500"};
  //  string Mass[4] = {"1TeV","2TeV","3TeV","4TeV"};
  //  string GeV[4]  = {"1000", "2000","3000", "4000"};
  TH1D *h_eta[8];
  TH1D *h_phi[8];
  TH1D *h_pt[8]; 
  TH1D *h_p[8]; 
  TH1D *h_E[8];
  TH2D *h2_beta_gamma[8];
  TCanvas *canvas = new TCanvas("canvas", "", 800, 600);
  int nbin = 100;
  for (int m = 0; m < 8; m++) {
  h_eta[m] = new TH1D("h_eta","",nbin,-7,7);
  h_phi[m]= new TH1D("h_phi","",nbin,-3.5,3.5);
  h_pt[m] = new TH1D("h_pt","",nbin,0,5000);
  h_p[m]= new TH1D("h_p","",nbin,0,5000);
  h2_beta_gamma[m]= new TH2D("h2_beta","",nbin,0.1,1,nbin,1,2);
  }

  for (int m = 0; m < 1; m++) {
    // open file and directory
    TFile *fin  = new TFile(("MonoNtuple2018_MC_" + GeV[m] + ".root").c_str());
    TTree *tree = (TTree *)fin->Get("monopoles");

    double   mono_eta;
    double   mono_phi;
    double   mono_pt;
    double   mono_p;
    double   mono_E;
    double   mono_m;
    double beta=0;
    double gamma=0;

    tree->SetBranchAddress("mono_eta", &mono_eta);
    tree->SetBranchAddress("mono_phi", &mono_phi);
    tree->SetBranchAddress("mono_pt", &mono_pt);
    tree->SetBranchAddress("mono_p", &mono_p);
    tree->SetBranchAddress("mono_E", &mono_E);
    tree->SetBranchAddress("mono_m", &mono_m);


    cout<<"processing "<<GeV[m]<<" GeV ..."<<endl;
    for (unsigned ev = 0; ev < tree->GetEntries(); ev++) {
      if (ev % 1000 == 0) cout << ev << "/" << tree->GetEntries() << endl;
      tree->GetEntry(ev);
      // h_eta[m]->Fill(mono_eta);
      // h_phi[m]->Fill(mono_phi);
      // h_pt[m]->Fill(mono_pt);
      // h_p[m]->Fill(mono_p);
      h2_beta_gamma[m]->Fill(mono_p/mono_E,mono_E/mono_m);
      //cout << "mono_eta " << mono_eta << " mono_phi " << mono_phi << endl;
      
    }
  }
  gStyle->SetOptStat(0);


  // h_eta[6]->Draw("Hist");
  // h_eta[0]->Draw("Hist same");
  // h_eta[1]->Draw("Hist same");
  // h_eta[2]->Draw("Hist same");
  // h_eta[3]->Draw("Hist same");
  // h_eta[4]->Draw("Hist same");
  // h_eta[5]->Draw("Hist same");
  // h_eta[7]->Draw("Hist same");
  // h_eta[6]->SetLineColor(40);
  // h_eta[0]->SetLineColor(46);
  // h_eta[1]->SetLineColor(42);
  // h_eta[2]->SetLineColor(30);
  // h_eta[3]->SetLineColor(38);
  // h_eta[4]->SetLineColor(28);
  // h_eta[5]->SetLineColor(9);
  // h_eta[7]->SetLineColor(8);
  // h_eta[6]->GetXaxis()->SetTitle("#eta");
  // h_eta[6]->GetYaxis()->SetTitle("Entries");
  // mgr::DrawCMSLabelOuter(GEN);
  // mgr::SetSinglePad(canvas);
  // mgr::SetAxis(h_eta[6]);
  // mgr::DrawEntryRight(("2018 13TeV 10000 entires"));
  // TLegend *leg = new TLegend(0.20, 0.20, 0.50, 0.45);
  // leg->SetBorderSize(0);
  // leg->SetFillColorAlpha(0, 0);
  // leg->SetTextSize(0.03);
  // for(int i=0;i<8;i++){
  //   leg->AddEntry(h_eta[i], Mass[i].c_str(), "l");
  // }
  // leg->Draw();
  // canvas->Modified();
  // canvas->SaveAs("Plots/mono_eta.pdf");
  //
  // h_phi[5]->Draw("Hist");
  // h_phi[0]->Draw("Hist same");
  // h_phi[1]->Draw("Hist same");
  // h_phi[2]->Draw("Hist same");
  // h_phi[3]->Draw("Hist same");
  // h_phi[4]->Draw("Hist same");
  // h_phi[6]->Draw("Hist same");
  // h_phi[7]->Draw("Hist same");
  // h_phi[6]->SetLineColor(40);
  // h_phi[0]->SetLineColor(46);
  // h_phi[1]->SetLineColor(42);
  // h_phi[2]->SetLineColor(30);
  // h_phi[3]->SetLineColor(38);
  // h_phi[4]->SetLineColor(28);
  // h_phi[5]->SetLineColor(9);
  // h_phi[7]->SetLineColor(8);
  // h_phi[5]->GetXaxis()->SetTitle("#phi");
  // h_phi[5]->GetYaxis()->SetTitle("Entries");
  // mgr::DrawCMSLabelOuter(GEN);
  // mgr::SetSinglePad(canvas);
  // mgr::SetAxis(h_phi[5]);
  // mgr::DrawEntryRight(("2018 13TeV 10000 entires"));
  // TLegend *leg5= new TLegend(0.20, 0.20, 0.50, 0.45);
  // leg5->SetBorderSize(0);
  // leg5->SetFillColorAlpha(0, 0);
  // leg5->SetTextSize(0.03);
  // for(int i=0;i<8;i++){
  //   leg5->AddEntry(h_phi[i], Mass[i].c_str(), "l");
  // }
  // leg5->Draw();
  // canvas->Modified();
  // canvas->SaveAs("Plots/mono_phi.pdf");
  //
  // h_pt[0]->Draw("Hist");
  // h_pt[1]->Draw("Hist same");
  // h_pt[2]->Draw("Hist same");
  // h_pt[3]->Draw("Hist same");
  // h_pt[4]->Draw("Hist same");
  // h_pt[5]->Draw("Hist same");
  // h_pt[6]->Draw("Hist same");
  // h_pt[7]->Draw("Hist same");
  // h_pt[6]->SetLineColor(40);
  // h_pt[0]->SetLineColor(46);
  // h_pt[1]->SetLineColor(42);
  // h_pt[2]->SetLineColor(30);
  // h_pt[3]->SetLineColor(38);
  // h_pt[4]->SetLineColor(28);
  // h_pt[5]->SetLineColor(9);
  // h_pt[7]->SetLineColor(8);
  // h_pt[0]->GetXaxis()->SetTitle("pT (transverse momentum) [GeV]");
  // h_pt[0]->GetYaxis()->SetTitle("Entries");
  // mgr::DrawCMSLabelOuter(GEN);
  // mgr::SetSinglePad(canvas);
  // mgr::SetAxis(h_pt[0]);
  // mgr::DrawEntryRight(("2018 13TeV 10000 entires"));
  // TLegend *leg2= new TLegend(0.60, 0.50, 0.90, 0.80);
  // leg2->SetBorderSize(0);
  // leg2->SetFillColorAlpha(0, 0);
  // leg2->SetTextSize(0.03);
  // for(int i=0;i<8;i++){
  //   leg2->AddEntry(h_pt[i], Mass[i].c_str(), "l");
  // }
  // leg2->Draw();
  // canvas->Modified();
  // canvas->SaveAs("Plots/mono_pt.pdf");
  //
  // h_p[0]->Draw("Hist");
  // h_p[1]->Draw("Hist same");
  // h_p[2]->Draw("Hist same");
  // h_p[3]->Draw("Hist same");
  // h_p[4]->Draw("Hist same");
  // h_p[5]->Draw("Hist same");
  // h_p[6]->Draw("Hist same");
  // h_p[7]->Draw("Hist same");
  // h_p[6]->SetLineColor(40);
  // h_p[0]->SetLineColor(46);
  // h_p[1]->SetLineColor(42);
  // h_p[2]->SetLineColor(30);
  // h_p[3]->SetLineColor(38);
  // h_p[4]->SetLineColor(28);
  // h_p[5]->SetLineColor(9);
  // h_p[7]->SetLineColor(8);
  // h_p[0]->GetXaxis()->SetTitle("p (total momentum) [GeV]");
  // h_p[0]->GetYaxis()->SetTitle("Entries");
  // mgr::DrawCMSLabelOuter(GEN);
  // mgr::SetSinglePad(canvas);
  // mgr::SetAxis(h_p[0]);
  // mgr::DrawEntryRight(("2018 13TeV 10000 entires"));
  // TLegend *leg3= new TLegend(0.60, 0.50, 0.90, 0.80);
  // leg3->SetBorderSize(0);
  // leg3->SetFillColorAlpha(0, 0);
  // leg3->SetTextSize(0.03);
  // for(int i=0;i<8;i++){
  //   leg3->AddEntry(h_p[i], Mass[i].c_str(), "l");
  // }
  // leg3->Draw();
  // canvas->Modified();
  // canvas->SaveAs("Plots/mono_p.pdf");

  h2_beta_gamma[0]->Draw("CONT4Z");
  h2_beta_gamma[0]->GetXaxis()->SetTitle("#beta=p/E");
  h2_beta_gamma[0]->GetYaxis()->SetTitle("#gamma = E/m");
  mgr::DrawCMSLabelOuter(GEN);
  //mgr::SetSinglePad(canvas);
  mgr::SetAxis(h2_beta_gamma[0]);
  mgr::DrawEntryRight(("2018 13TeV Mass 1000 GeV"));
//  TLegend *leg5= new TLegend(0.60, 0.50, 0.90, 0.80);
//  leg5->SetBorderSize(0);
//  leg5->SetFillColorAlpha(0, 0);
//  leg5->SetTextSize(0.03);
//  leg5->Draw();
  canvas->Modified();
  canvas->SaveAs("Plots/mono_beta_gamma_1000.pdf");

}
