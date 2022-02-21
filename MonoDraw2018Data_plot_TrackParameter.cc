////////////////////////////////////////
//
//
///////////////////////////////////////////////////

#include <string>
using namespace std;
void MonoDraw2018Data_plot_TrackParameter()
{

        TCanvas *canvas = new TCanvas("canvas","",800,600);
	gStyle->SetOptStat(0);

	//data
        TFile *file_data = new TFile ("RootFile/MonoData2018_Plot.root");
//        TDirectory *DC_data = (TDirectory*)fin_data->Get("HLT_Photon");
//        DC_data->cd();	
	//MC 1TeV
        TFile *fin1 = new TFile ("RootFile/MonoPhotonAnalysis_2018_1000_1.root");
        TDirectory *DC_MC1 = (TDirectory*)fin1->Get("HLT_Photon200");
        DC_MC1->cd();
	//M 2TeV
        TFile *fin2 = new TFile ("RootFile/MonoPhotonAnalysis_2018_2000_1.root");
        TDirectory *DC_MC2 = (TDirectory*)fin2->Get("HLT_Photon200");
        DC_MC2->cd();	
	//3TeV
        TFile *fin3 = new TFile ("RootFile/MonoPhotonAnalysis_2018_3000_1.root");
        TDirectory *DC_MC3 = (TDirectory*)fin3->Get("HLT_Photon200");
        DC_MC3->cd();	
	//4TeV
        TFile *fin4 = new TFile ("RootFile/MonoPhotonAnalysis_2018_4000_1.root");
        TDirectory *DC_MC4 = (TDirectory*)fin4->Get("HLT_Photon200");
        DC_MC4->cd();	

        TH1D *MC1_RZPar0, *MC2_RZPar0, *MC3_RZPar0, *MC4_RZPar0;
        TH1D *MC1_RZPar1, *MC2_RZPar1, *MC3_RZPar1, *MC4_RZPar1;
        TH1D *MC1_RZPar2, *MC2_RZPar2, *MC3_RZPar2, *MC4_RZPar2;
        TH1D *MC1_XYPar0, *MC2_XYPar0, *MC3_XYPar0, *MC4_XYPar0;
        TH1D *MC1_XYPar1, *MC2_XYPar1, *MC3_XYPar1, *MC4_XYPar1;
        TH1D *MC1_XYPar2, *MC2_XYPar2, *MC3_XYPar2, *MC4_XYPar2;

	MC1_RZPar0 = (TH1D*)DC_MC1->Get("RZPar0");	 
	MC1_RZPar1 = (TH1D*)DC_MC1->Get("RZPar1");	 
	MC1_RZPar2 = (TH1D*)DC_MC1->Get("RZcurv");	 
	MC1_XYPar0 = (TH1D*)DC_MC1->Get("XYPar0");	 
	MC1_XYPar1 = (TH1D*)DC_MC1->Get("XYPar1");	 
	MC1_XYPar2 = (TH1D*)DC_MC1->Get("XYPar2");	 

	MC2_RZPar0 = (TH1D*)DC_MC2->Get("RZPar0");	 
	MC2_RZPar1 = (TH1D*)DC_MC2->Get("RZPar1");	 
	MC2_RZPar2 = (TH1D*)DC_MC2->Get("RZcurv");	 
	MC2_XYPar0 = (TH1D*)DC_MC2->Get("XYPar0");	 
	MC2_XYPar1 = (TH1D*)DC_MC2->Get("XYPar1");	 
	MC2_XYPar2 = (TH1D*)DC_MC2->Get("XYPar2");	

	MC3_RZPar0 = (TH1D*)DC_MC3->Get("RZPar0");	 
	MC3_RZPar1 = (TH1D*)DC_MC3->Get("RZPar1");	 
	MC3_RZPar2 = (TH1D*)DC_MC3->Get("RZcurv");	 
	MC3_XYPar0 = (TH1D*)DC_MC3->Get("XYPar0");	 
	MC3_XYPar1 = (TH1D*)DC_MC3->Get("XYPar1");	 
	MC3_XYPar2 = (TH1D*)DC_MC3->Get("XYPar2");	 

	MC4_RZPar0 = (TH1D*)DC_MC4->Get("RZPar0");	 
	MC4_RZPar1 = (TH1D*)DC_MC4->Get("RZPar1");	 
	MC4_RZPar2 = (TH1D*)DC_MC4->Get("RZcurv");	 
	MC4_XYPar0 = (TH1D*)DC_MC4->Get("XYPar0");	 
	MC4_XYPar1 = (TH1D*)DC_MC4->Get("XYPar1");	 
	MC4_XYPar2 = (TH1D*)DC_MC4->Get("XYPar2");	 
 
        TH1D *Data_RZPar0;
	Data_RZPar0 = (TH1D*)file_data->Get("Plot_RZPar0");	 
	Data_RZPar0->Scale(1./Data_RZPar0->Integral());
	MC1_RZPar0->Scale(1./MC1_RZPar0->Integral());
	MC2_RZPar0->Scale(1./MC2_RZPar0->Integral());
	MC3_RZPar0->Scale(1./MC3_RZPar0->Integral());
	MC4_RZPar0->Scale(1./MC4_RZPar0->Integral());
        Data_RZPar0->SetXTitle("cm ( z direction)");
        Data_RZPar0->SetYTitle("Entries");
        Data_RZPar0->SetTitle("");
        Data_RZPar0->Draw("HIST same");
        MC1_RZPar0->Draw("HIST SAME");
        MC2_RZPar0->Draw("HIST SAME");
        MC3_RZPar0->Draw("HIST SAME");
        MC4_RZPar0->Draw("HIST SAME");
	MC1_RZPar0->SetLineColorAlpha(30,1);
	MC2_RZPar0->SetLineColorAlpha(38,1);
	MC3_RZPar0->SetLineColorAlpha(46,1);
	MC4_RZPar0->SetLineColorAlpha(20,1);
        mgr::SetSinglePad(canvas);
        mgr::SetAxis(Data_RZPar0);
        mgr::DrawEntryRight("2018 13TeV");
//        TLegend *leg = new TLegend(0.25,0.25,0.55,0.55);
//        leg->SetBorderSize( 0 );
//	leg->SetTextSize(0.05);
//        leg->SetFillColorAlpha( 0, 0 );
//        leg->AddEntry(MC1_RZPar0,"1TeV","L");
//        leg->AddEntry(MC2_RZPar0,"2TeV","L");
//        leg->AddEntry(MC3_RZPar0,"3TeV","L");
//        leg->AddEntry(MC4_RZPar0,"4TeV","L");
//        leg->Draw();
//        canvas->SaveAs("./Thesis/DatavsMC_2018RZPar0.pdf");

/*        TH1D *Data_RZPar1; 
        Data_RZPar1=(TH1D*)file_data->Get("Plot_RZPar1");	 
	Data_RZPar1->Scale(1./Data_RZPar1->Integral());
	MC1_RZPar1->Scale(1./MC1_RZPar1->Integral());
	MC2_RZPar1->Scale(1./MC2_RZPar1->Integral());
	MC3_RZPar1->Scale(1./MC3_RZPar1->Integral());
	MC4_RZPar1->Scale(1./MC4_RZPar1->Integral());
        Data_RZPar1->SetXTitle("gradient in RZ plane");
        Data_RZPar1->SetYTitle("Entries");
        Data_RZPar1->SetTitle("");
        Data_RZPar1->Draw("HIST");
        MC1_RZPar1->Draw("SAME HIST");
        MC2_RZPar1->Draw("SAME HIST");
        MC3_RZPar1->Draw("SAME HIST");
        MC4_RZPar1->Draw("SAME HIST");
        mgr::SetSinglePad(canvas);
        mgr::SetAxis(Data_RZPar1);
        mgr::DrawEntryRight("2018 13TeV");
        canvas->SaveAs("./Thesis/DatavsMC_2018RZPar1.pdf");

        TH1D *Data_RZPar2; 
        Data_RZPar2=(TH1D*)file_data->Get("Plot_RZPar2");	 
	Data_RZPar2->Scale(1./Data_RZPar2->Integral());
	MC1_RZPar2->Scale(1./MC1_RZPar2->Integral());
	MC2_RZPar2->Scale(1./MC2_RZPar2->Integral());
	MC3_RZPar2->Scale(1./MC3_RZPar2->Integral());
	MC4_RZPar2->Scale(1./MC4_RZPar2->Integral());
        Data_RZPar2->SetXTitle("RZ curvature");
        Data_RZPar2->SetYTitle("Entries");
        Data_RZPar2->SetTitle("");
        Data_RZPar2->Draw("HIST");
        MC1_RZPar2->Draw("SAME HIST");
        MC2_RZPar2->Draw("SAME HIST");
        MC3_RZPar2->Draw("SAME HIST");
        MC4_RZPar2->Draw("SAME HIST");
        mgr::SetSinglePad(canvas);
        mgr::SetAxis(Data_RZPar2);
        mgr::DrawEntryRight("2018 13TeV");
        canvas->SaveAs("./Thesis/DatavsMC_2018RZPar2.pdf");


        TH1D *Data_XYPar0; 
        Data_XYPar0=(TH1D*)file_data->Get("Plot_XYPar0");	 
	Data_XYPar0->Scale(1./Data_XYPar0->Integral());
	MC1_XYPar0->Scale(1./MC1_XYPar0->Integral());
	MC2_XYPar0->Scale(1./MC2_XYPar0->Integral());
	MC3_XYPar0->Scale(1./MC3_XYPar0->Integral());
	MC4_XYPar0->Scale(1./MC4_XYPar0->Integral());
        Data_XYPar0->SetXTitle("d_{0} impact parameter");
        Data_XYPar0->SetYTitle("Entries");
        Data_XYPar0->SetTitle("");
        Data_XYPar0->Draw("HIST");
        MC1_XYPar0->Draw("SAME HIST");
        MC2_XYPar0->Draw("SAME HIST");
        MC3_XYPar0->Draw("SAME HIST");
        MC4_XYPar0->Draw("SAME HIST");
        mgr::SetSinglePad(canvas);
        mgr::SetAxis(Data_XYPar0);
        mgr::DrawEntryRight("2018 13TeV");
        canvas->SaveAs("./Thesis/DatavsMC_2018XYPar0.pdf");


        TH1D *Data_XYPar1; 
        Data_XYPar1=(TH1D*)file_data->Get("Plot_XYPar1");	 
	Data_XYPar1->Scale(1./Data_XYPar1->Integral());
	MC1_XYPar1->Scale(1./MC1_XYPar1->Integral());
	MC2_XYPar1->Scale(1./MC2_XYPar1->Integral());
	MC3_XYPar1->Scale(1./MC3_XYPar1->Integral());
	MC4_XYPar1->Scale(1./MC4_XYPar1->Integral());
        Data_XYPar1->SetXTitle("#phi_{0}");
        Data_XYPar1->SetYTitle("Entries");
        Data_XYPar1->SetTitle("");
        Data_XYPar1->Draw("HIST");
        MC1_XYPar1->Draw("SAME HIST");
        MC2_XYPar1->Draw("SAME HIST");
        MC3_XYPar1->Draw("SAME HIST");
        MC4_XYPar1->Draw("SAME HIST");
        mgr::SetSinglePad(canvas);
        mgr::SetAxis(Data_XYPar1);
        mgr::DrawEntryRight("2018 13TeV");
        canvas->SaveAs("./Thesis/DatavsMC_2018XYPar1.pdf");

        TH1D *Data_XYPar2; 
        Data_XYPar2=(TH1D*)file_data->Get("Plot_XYPar2");	 
	Data_XYPar2->Scale(1./Data_XYPar2->Integral());
	MC1_XYPar2->Scale(1./MC1_XYPar2->Integral());
	MC2_XYPar2->Scale(1./MC2_XYPar2->Integral());
	MC3_XYPar2->Scale(1./MC3_XYPar2->Integral());
	MC4_XYPar2->Scale(1./MC4_XYPar2->Integral());
        Data_XYPar2->SetXTitle("cm (radius)");
        Data_XYPar2->SetYTitle("Entries");
        Data_XYPar2->SetTitle("");
        Data_XYPar2->Draw("HIST");
        MC1_XYPar2->Draw("SAME HIST");
        MC2_XYPar2->Draw("SAME HIST");
        MC3_XYPar2->Draw("SAME HIST");
        MC4_XYPar2->Draw("SAME HIST");
        mgr::SetSinglePad(canvas);
        mgr::SetAxis(Data_XYPar2);
        mgr::DrawEntryRight("2018 13TeV");
        canvas->SaveAs("./Thesis/DatavsMC_2018XYPar2.pdf");
*/
//        double dEdXSigCut_ = 9;
//        double f51Cut_ = 0.85;
//	TH2D* ABCD;
//	ABCD = (TH2D*)DC_data->Get("Flow_HLT_Energy_ABCD");
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
