////////////////////////////////////////
//
//
//      File name: MonoDrawEGamaalike.cc
//      author: Shih Lin
//      Content: Draw electron/photon like monopole
//
//      Output: /Plots/2016MC1TeV/*.pdf
//      Create Date: 2021.6.4
//
///////////////////////////////////////////////////

#include <string>
using namespace std;
void MonoDrawPhoton()
{

        TCanvas *canvas = new TCanvas("canvas","",800,600);
        TFile *fin1 = new TFile ("MonoPhotonAnalysis_2018_1000_TrackParameter_withoutMatching_XYPar2inverse.root");
        //TFile *fin1 = new TFile ("MonoPhotonAnalysis_2018_1000.root");
        TDirectory *NOTRG1 = (TDirectory*)fin1->Get("HLT_Photon200");
        NOTRG1->cd();
	gStyle->SetOptStat(0);


/*        double dEdXSigCut_ = 9;
        double f51Cut_ = 0.85;
	TH2D* ABCD;
	ABCD = (TH2D*)NOTRG1->Get("Flow_HLT_Energy_ABCD");
        ABCD->SetXTitle("f51");
        ABCD->SetYTitle("dE/dX significance");
        ABCD->SetTitle("");
        ABCD->SetMarkerStyle(7);
        ABCD->Draw("COLZ");
        mgr::SetSinglePad(canvas);
        mgr::SetAxis(ABCD);
        mgr::DrawCMSLabelOuter(SIMULATION);
        mgr::DrawEntryRight("2018 13TeV Mass 1000GeV 16389 Entries");
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
	canvas->SaveAs("ABCD(Ecut+HLT_Photon200).pdf");
*/
        TH1D *RZPar0; 
        RZPar0  = (TH1D*)NOTRG1->Get("RZPar0");	 
        gStyle->SetOptStat(0);
    //    canvas->SetLogy();
        RZPar0->SetXTitle("cm ( z direction)");
        RZPar0->SetYTitle("Entries");
        RZPar0->SetTitle("");
        RZPar0->Draw();
        mgr::SetSinglePad(canvas);
        mgr::SetAxis(RZPar0);
        mgr::DrawCMSLabelOuter(SIMULATION);
        mgr::DrawEntryRight("2018 Mass 1TeV 16389 Events");
/*        TLegend *leg4 = new TLegend(0.7,0.85,1.00,0.70);
        leg4->SetBorderSize( 0 );
        leg4->SetFillColorAlpha( 0, 0 );
        leg4->AddEntry(RZPar0,"1000GeV","f");
        leg4->Draw();*/
        canvas->SaveAs("./Plots/MonopoleRZPar0.pdf");

        TH1D *RZPar1; 
        RZPar1  = (TH1D*)NOTRG1->Get("RZPar1");	 
        gStyle->SetOptStat(0);
   //     canvas->SetLogy();
        RZPar1->SetXTitle("gradient in RZ plane");
        RZPar1->SetYTitle("Entries");
        RZPar1->SetTitle("");
        RZPar1->Draw();
        mgr::SetSinglePad(canvas);
        mgr::SetAxis(RZPar1);
        mgr::DrawCMSLabelOuter(SIMULATION);
        mgr::DrawEntryRight("2018 Mass 1TeV 16389 Events");
/*        TLegend *leg4 = new TLegend(0.7,0.85,1.00,0.70);
        leg4->SetBorderSize( 0 );
        leg4->SetFillColorAlpha( 0, 0 );
        leg4->AddEntry(RZPar1,"1000GeV","f");
        leg4->Draw();*/
        canvas->SaveAs("./Plots/MonopoleRZPar1.pdf");

        TH1D *RZPar2; 
        RZPar2  = (TH1D*)NOTRG1->Get("RZcurv");	 
        gStyle->SetOptStat(0);
  //      canvas->SetLogy();
        RZPar2->SetXTitle("RZ curvature");
        RZPar2->SetYTitle("Entries");
        RZPar2->SetTitle("");
        RZPar2->Draw();
        mgr::SetSinglePad(canvas);
        mgr::SetAxis(RZPar2);
        mgr::DrawCMSLabelOuter(SIMULATION);
        mgr::DrawEntryRight("2018 Mass 1TeV 16389 Events");
/*        TLegend *leg4 = new TLegend(0.7,0.85,1.00,0.70);
        leg4->SetBorderSize( 0 );
        leg4->SetFillColorAlpha( 0, 0 );
        leg4->AddEntry(RZPar2,"1000GeV","f");
        leg4->Draw();*/
        canvas->SaveAs("./Plots/MonopoleRZPar2.pdf");


        TH1D *XYPar0; 
        XYPar0  = (TH1D*)NOTRG1->Get("XYPar0");	 
        gStyle->SetOptStat(0);
 //       canvas->SetLogy();
        XYPar0->SetXTitle("d_{0} impact parameter");
        XYPar0->SetYTitle("Entries");
        XYPar0->SetTitle("");
        XYPar0->Draw();
        mgr::SetSinglePad(canvas);
        mgr::SetAxis(XYPar0);
        mgr::DrawCMSLabelOuter(SIMULATION);
        mgr::DrawEntryRight("2018 Mass 1TeV 16389 Events");
/*        TLegend *leg4 = new TLegend(0.7,0.85,1.00,0.70);
        leg4->SetBorderSize( 0 );
        leg4->SetFillColorAlpha( 0, 0 );
        leg4->AddEntry(XYPar0,"1000GeV","f");
        leg4->Draw();*/
        canvas->SaveAs("./Plots/MonopoleXYPar0.pdf");


        TH1D *XYPar1; 
        XYPar1  = (TH1D*)NOTRG1->Get("XYPar1");	 
        gStyle->SetOptStat(0);
//        canvas->SetLogy();
        XYPar1->SetXTitle("#phi_{0}");
        XYPar1->SetYTitle("Entries");
        XYPar1->SetTitle("");
        XYPar1->Draw();
        mgr::SetSinglePad(canvas);
        mgr::SetAxis(XYPar1);
        mgr::DrawCMSLabelOuter(SIMULATION);
        mgr::DrawEntryRight("2018 Mass 1TeV 16389 Events");
/*        TLegend *leg4 = new TLegend(0.7,0.85,1.00,0.70);
        leg4->SetBorderSize( 0 );
        leg4->SetFillColorAlpha( 0, 0 );
        leg4->AddEntry(XYPar1,"1000GeV","f");
        leg4->Draw();*/
        canvas->SaveAs("./Plots/MonopoleXYPar1.pdf");

        TH1D *XYPar2; 
        XYPar2  = (TH1D*)NOTRG1->Get("XYPar2");	 
        gStyle->SetOptStat(0);
//        canvas->SetLogy();
        XYPar2->SetXTitle("cm (radius)");
        XYPar2->SetYTitle("Entries");
        XYPar2->SetTitle("");
        XYPar2->Draw();
        mgr::SetSinglePad(canvas);
        mgr::SetAxis(XYPar2);
        mgr::DrawCMSLabelOuter(SIMULATION);
        mgr::DrawEntryRight("2018 Mass 1TeV 16389 Events");
/*        TLegend *leg4 = new TLegend(0.7,0.85,1.00,0.70);
        leg4->SetBorderSize( 0 );
        leg4->SetFillColorAlpha( 0, 0 );
        leg4->AddEntry(XYPar2,"1000GeV","f");
        leg4->Draw();*/
        canvas->SaveAs("./Plots/MonopoleXYPar2.pdf");

}


