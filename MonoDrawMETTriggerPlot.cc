#include <string>
using namespace std;
void MonoDrawMETTriggerPlot()
{
	//create a canvas
        string Mass[4] = { "1TeV","2TeV","3TeV","4TeV"};
	string GeV[4] = {"1000","2000","3000","4000"};
        string Year[2] = { "2017","2018"};

	TCanvas *canvas = new TCanvas("canvas","",800,600);

		//open file and directory
		TFile *fin1 = new TFile ("Monopole_PFMETTrigger_2018_1000_.root");
		TFile *fin2 = new TFile ("Monopole_PFMETTrigger_2018_2000_.root");
		TFile *fin3 = new TFile ("Monopole_PFMETTrigger_2018_3000_.root");
		TFile *fin4 = new TFile ("Monopole_PFMETTrigger_2018_4000_.root");
//		TDirectory *dir1 = (TDirectory*)fin1->Get("NOTRG");
//		TDirectory *dir2 = (TDirectory*)fin2->Get("NOTRG");
//		TDirectory *dir3 = (TDirectory*)fin3->Get("NOTRG");
//		TDirectory *dir4 = (TDirectory*)fin4->Get("NOTRG");

		TDirectory *dir1 = (TDirectory*)fin1->Get("HLT_PFMET200_HBHE_BeamHaloCleaned");
		TDirectory *dir2 = (TDirectory*)fin2->Get("HLT_PFMET200_HBHE_BeamHaloCleaned");
		TDirectory *dir3 = (TDirectory*)fin3->Get("HLT_PFMET200_HBHE_BeamHaloCleaned");
		TDirectory *dir4 = (TDirectory*)fin4->Get("HLT_PFMET200_HBHE_BeamHaloCleaned");

//		TDirectory *dir1 = (TDirectory*)fin1->Get("HLT_PFMETTypeOne200_HBHE_BeamHaloCleaned");
//		TDirectory *dir2 = (TDirectory*)fin2->Get("HLT_PFMETTypeOne200_HBHE_BeamHaloCleaned");
//		TDirectory *dir3 = (TDirectory*)fin3->Get("HLT_PFMETTypeOne200_HBHE_BeamHaloCleaned");
//		TDirectory *dir4 = (TDirectory*)fin4->Get("HLT_PFMETTypeOne200_HBHE_BeamHaloCleaned");
	 
		dir1->cd();
		dir2->cd();
		dir3->cd();
		dir4->cd();
		
                gStyle->SetOptStat(0);
                const int plotNum = 5;
                string plotName[plotNum] = { "NoCut_","Flow_Quality_","Flow_MET_","Flow_F51_","Flow_dEdxSig_"};

		string histogram[plotNum] = { "","Flow_HLT_Quality_","Flow_HLT_MET_","Flow_HLT_F51_","Flow_HLT_dEdxSig_"};
		
		vector<TH2*> FracSatVNstrips1;
		vector<TH2*> FracSatVNstrips2;
		vector<TH2*> FracSatVNstrips3;
		vector<TH2*> FracSatVNstrips4;

		vector<TH1*> DedXSig1;
		vector<TH1*> DedXSig2;
		vector<TH1*> DedXSig3;
		vector<TH1*> DedXSig4;
                vector<TH1*> Energy1;
                vector<TH1*> Energy2;
                vector<TH1*> Energy3;
                vector<TH1*> Energy4;
                vector<TH1*> RZcurv1;
                vector<TH1*> RZcurv2;
                vector<TH1*> RZcurv3;
                vector<TH1*> RZcurv4;
                vector<TH1*> F511;
                vector<TH1*> F512;
                vector<TH1*> F513;
                vector<TH1*> F514;
                vector<TH1*> HcalIso1;
                vector<TH1*> HcalIso2;
                vector<TH1*> HcalIso3;
                vector<TH1*> HcalIso4;
                vector<TH1*> MET1;
                vector<TH1*> MET2;
                vector<TH1*> MET3;
                vector<TH1*> MET4;

	for(int i =0 ; i<plotNum ; i++){


	FracSatVNstrips1.push_back((TH2D*)dir1->Get((histogram[i]+"FracSatVNstrips").c_str()));
	FracSatVNstrips2.push_back((TH2D*)dir2->Get((histogram[i]+"FracSatVNstrips").c_str()));
	FracSatVNstrips3.push_back((TH2D*)dir3->Get((histogram[i]+"FracSatVNstrips").c_str()));
	FracSatVNstrips4.push_back((TH2D*)dir4->Get((histogram[i]+"FracSatVNstrips").c_str()));
        FracSatVNstrips1[i]->SetXTitle("Total No. of Strips");
        FracSatVNstrips1[i]->SetYTitle("fraction of saturated strips");
        FracSatVNstrips1[i]->SetTitle("");
        FracSatVNstrips2[i]->SetXTitle("Total No. of Strips");
        FracSatVNstrips2[i]->SetYTitle("fraction of saturated strips");
        FracSatVNstrips2[i]->SetTitle("");
        FracSatVNstrips3[i]->SetXTitle("Total No. of Strips");
        FracSatVNstrips3[i]->SetYTitle("fraction of saturated strips");
        FracSatVNstrips3[i]->SetTitle("");
        FracSatVNstrips4[i]->SetXTitle("Total No. of Strips");
        FracSatVNstrips4[i]->SetYTitle("fraction of saturated strips");
        FracSatVNstrips4[i]->SetTitle("");
        mgr::SetSinglePad(canvas);
        mgr::SetAxis(FracSatVNstrips1[i]);
        mgr::SetAxis(FracSatVNstrips2[i]);
        mgr::SetAxis(FracSatVNstrips3[i]);
        mgr::SetAxis(FracSatVNstrips4[i]);
        mgr::DrawCMSLabelOuter(SIMULATION);
        mgr::DrawEntryRight("2018 13TeV 15000 Entries");
        FracSatVNstrips1[i]->Draw();
	canvas->SaveAs(("./Plots/2018/"+plotName[i]+"FracSatVNstrips1.pdf").c_str());
        FracSatVNstrips2[i]->Draw();
	canvas->SaveAs(("./Plots/2018/"+plotName[i]+"FracSatVNstrips2.pdf").c_str());
        FracSatVNstrips3[i]->Draw();
	canvas->SaveAs(("./Plots/2018/"+plotName[i]+"FracSatVNstrips3.pdf").c_str());
        FracSatVNstrips4[i]->Draw();
	canvas->SaveAs(("./Plots/2018/"+plotName[i]+"FracSatVNstrips4.pdf").c_str());


	//create dedx
	DedXSig1.push_back((TH1D*)dir1->Get((histogram[i]+"DedXSig").c_str()));
	DedXSig2.push_back((TH1D*)dir2->Get((histogram[i]+"DedXSig").c_str()));
	DedXSig3.push_back((TH1D*)dir3->Get((histogram[i]+"DedXSig").c_str()));
	DedXSig4.push_back((TH1D*)dir4->Get((histogram[i]+"DedXSig").c_str()));
        DedXSig3[i]->SetXTitle("dE/dX Significance");
        DedXSig3[i]->SetYTitle("Entries");
        DedXSig3[i]->SetTitle("");
        DedXSig1[i]->SetLineColorAlpha(41,1);
        DedXSig2[i]->SetLineColorAlpha(30,1);
        DedXSig3[i]->SetLineColorAlpha(38,1);
        DedXSig4[i]->SetLineColorAlpha(46,1);
        DedXSig1[i]->SetFillColorAlpha(41,0.45);
        DedXSig2[i]->SetFillColorAlpha(30,0.45);
        DedXSig3[i]->SetFillColorAlpha(38,0.45);
        DedXSig4[i]->SetFillColorAlpha(46,0.45);
        DedXSig3[i]->Draw();
        DedXSig2[i]->Draw("same");
        DedXSig4[i]->Draw("same");
        DedXSig1[i]->Draw("same");
        mgr::SetSinglePad(canvas);
        mgr::SetAxis(DedXSig3[i]);
        mgr::DrawCMSLabelOuter(SIMULATION);
        mgr::DrawEntryRight("2018 13TeV 15000 Entries");
        TLegend *leg = new TLegend(0.7,0.85,1.00,0.70); 
        leg->SetBorderSize( 0 );
        leg->SetFillColorAlpha( 0, 0 );
        leg->AddEntry(DedXSig1[i],"1 TeV","f");
        leg->AddEntry(DedXSig2[i],"2 TeV","f");
        leg->AddEntry(DedXSig3[i],"3 TeV","f");
        leg->AddEntry(DedXSig4[i],"4 TeV","f");
        leg->Draw();
	canvas->SaveAs(("./Plots/2018/"+plotName[i]+"DedXSig.pdf").c_str());
	
	RZcurv1.push_back((TH1D*)dir1->Get((histogram[i]+"RZcurv").c_str()));
	RZcurv2.push_back((TH1D*)dir2->Get((histogram[i]+"RZcurv").c_str()));
	RZcurv3.push_back((TH1D*)dir3->Get((histogram[i]+"RZcurv").c_str()));
	RZcurv4.push_back((TH1D*)dir4->Get((histogram[i]+"RZcurv").c_str()));
        RZcurv3[i]->SetXTitle("RZ curvature");
        RZcurv3[i]->SetYTitle("Entries");
        RZcurv3[i]->SetTitle("");
        RZcurv1[i]->SetLineColorAlpha(41,1);
        RZcurv2[i]->SetLineColorAlpha(30,1);
        RZcurv3[i]->SetLineColorAlpha(38,1);
        RZcurv4[i]->SetLineColorAlpha(46,1);
        RZcurv1[i]->SetFillColorAlpha(41,0.45);
        RZcurv2[i]->SetFillColorAlpha(30,0.45);
        RZcurv3[i]->SetFillColorAlpha(38,0.45);
        RZcurv4[i]->SetFillColorAlpha(46,0.45);
        RZcurv3[i]->Draw();
        RZcurv2[i]->Draw("same");
        RZcurv4[i]->Draw("same");
        RZcurv1[i]->Draw("same");
        mgr::SetSinglePad(canvas);
        mgr::SetAxis(RZcurv3[i]);
        mgr::DrawCMSLabelOuter(SIMULATION);
        mgr::DrawEntryRight("2018 13TeV 15000 Entries");
        TLegend *leg2 = new TLegend(0.7,0.85,1.00,0.70); 
        leg2->SetBorderSize( 0 );
        leg2->SetFillColorAlpha( 0, 0 );
        leg2->AddEntry(RZcurv1[i],"1 TeV","f");
        leg2->AddEntry(RZcurv2[i],"2 TeV","f");
        leg2->AddEntry(RZcurv3[i],"3 TeV","f");
        leg2->AddEntry(RZcurv4[i],"4 TeV","f");
        leg2->Draw();
	canvas->SaveAs(("./Plots/2018/"+plotName[i]+"RZcurv.pdf").c_str());
	
	F511.push_back((TH1D*)dir1->Get((histogram[i]+"F51").c_str()));
	F512.push_back((TH1D*)dir2->Get((histogram[i]+"F51").c_str()));
	F513.push_back((TH1D*)dir3->Get((histogram[i]+"F51").c_str()));
	F514.push_back((TH1D*)dir4->Get((histogram[i]+"F51").c_str()));
        F514[i]->SetXTitle("f51 = e51/e55");
        F514[i]->SetYTitle("Entries");
        F514[i]->SetTitle("");
        F514[i]->Draw();
        F512[i]->Draw("same");
        F513[i]->Draw("same");
        F511[i]->Draw("same");
        F511[i]->SetLineColorAlpha(41,1);
        F512[i]->SetLineColorAlpha(30,1);
        F513[i]->SetLineColorAlpha(38,1);
        F514[i]->SetLineColorAlpha(46,1);
        F511[i]->SetFillColorAlpha(41,0.45);
        F512[i]->SetFillColorAlpha(30,0.45);
        F513[i]->SetFillColorAlpha(38,0.45);
        F514[i]->SetFillColorAlpha(46,0.45);
        mgr::SetSinglePad(canvas);
        mgr::SetAxis(F514[i]);
        mgr::DrawCMSLabelOuter(SIMULATION);
        mgr::DrawEntryRight("2018 13TeV 15000 Entries");
        TLegend *leg4 = new TLegend(0.7,0.85,1.00,0.70); 
        leg4->SetBorderSize( 0 );
        leg4->SetFillColorAlpha( 0, 0 );
        leg4->AddEntry(F511[i],"1 TeV","f");
        leg4->AddEntry(F512[i],"2 TeV","f");
        leg4->AddEntry(F513[i],"3 TeV","f");
        leg4->AddEntry(F514[i],"4 TeV","f");
        leg4->Draw();
	canvas->SaveAs(("./Plots/2018/"+plotName[i]+"F51.pdf").c_str());

	HcalIso1.push_back((TH1D*)dir1->Get((histogram[i]+"HcalIso").c_str()));
	HcalIso2.push_back((TH1D*)dir2->Get((histogram[i]+"HcalIso").c_str()));
	HcalIso3.push_back((TH1D*)dir3->Get((histogram[i]+"HcalIso").c_str()));
	HcalIso4.push_back((TH1D*)dir4->Get((histogram[i]+"HcalIso").c_str()));
        HcalIso1[i]->SetXTitle("Energy(GeV)");
        HcalIso1[i]->SetYTitle("Entries");
        HcalIso1[i]->SetTitle("");
        HcalIso1[i]->Draw();
        HcalIso2[i]->Draw("same");
        HcalIso3[i]->Draw("same");
        HcalIso4[i]->Draw("same");
        HcalIso1[i]->SetLineColorAlpha(41,1);
        HcalIso2[i]->SetLineColorAlpha(30,1);
        HcalIso3[i]->SetLineColorAlpha(38,1);
        HcalIso4[i]->SetLineColorAlpha(46,1);
        HcalIso1[i]->SetFillColorAlpha(41,0.45);
        HcalIso2[i]->SetFillColorAlpha(30,0.45);
        HcalIso3[i]->SetFillColorAlpha(38,0.45);
        HcalIso4[i]->SetFillColorAlpha(46,0.45);
        mgr::SetSinglePad(canvas);
        mgr::SetAxis(HcalIso1[i]);
        mgr::DrawCMSLabelOuter(SIMULATION);
        mgr::DrawEntryRight("2018 13TeV 15000 Entries");
        TLegend *leg5 = new TLegend(0.7,0.85,1.00,0.70); 
        leg5->SetBorderSize( 0 );
        leg5->SetFillColorAlpha( 0, 0 );
        leg5->AddEntry(HcalIso1[i],"1 TeV","f");
        leg5->AddEntry(HcalIso2[i],"2 TeV","f");
        leg5->AddEntry(HcalIso3[i],"3 TeV","f");
        leg5->AddEntry(HcalIso4[i],"4 TeV","f");
        leg5->Draw();
	canvas->SaveAs(("./Plots/2018/"+plotName[i]+"HcalIso.pdf").c_str());
	

	MET1.push_back((TH1D*)dir1->Get((histogram[i]+"MET").c_str()));
	MET2.push_back((TH1D*)dir2->Get((histogram[i]+"MET").c_str()));
	MET3.push_back((TH1D*)dir3->Get((histogram[i]+"MET").c_str()));
	MET4.push_back((TH1D*)dir4->Get((histogram[i]+"MET").c_str()));
        MET3[i]->SetXTitle("E^{miss}_{T} (GeV)");
        MET3[i]->SetYTitle("Entries");
        MET3[i]->SetTitle("");
        MET3[i]->Draw();
        MET1[i]->Draw("same");
        MET2[i]->Draw("same");
        MET4[i]->Draw("same");
        MET1[i]->SetLineColorAlpha(41,1);
        MET2[i]->SetLineColorAlpha(30,1);
        MET3[i]->SetLineColorAlpha(38,1);
        MET4[i]->SetLineColorAlpha(46,1);
        MET1[i]->SetFillColorAlpha(41,0.45);
        MET2[i]->SetFillColorAlpha(30,0.45);
        MET3[i]->SetFillColorAlpha(38,0.45);
        MET4[i]->SetFillColorAlpha(46,0.45);
        mgr::SetSinglePad(canvas);
        mgr::SetAxis(MET3[i]);
        mgr::DrawCMSLabelOuter(SIMULATION);
        mgr::DrawEntryRight("2018 13TeV 15000 Entries");
        TLegend *leg7 = new TLegend(0.7,0.85,1.00,0.70); 
        leg7->SetBorderSize( 0 );
        leg7->SetFillColorAlpha( 0, 0 );
        leg7->AddEntry(MET1[i],"1 TeV","f");
        leg7->AddEntry(MET2[i],"2 TeV","f");
        leg7->AddEntry(MET3[i],"3 TeV","f");
        leg7->AddEntry(MET4[i],"4 TeV","f");
        leg7->Draw();
	canvas->SaveAs(("./Plots/2018/"+plotName[i]+"MET.pdf").c_str());


	}

	for(int i=0;i<plotNum;i++){

	gPad->SetLogy();
	Energy1.push_back((TH1D*)dir1->Get((histogram[i]+"E55").c_str()));
	Energy2.push_back((TH1D*)dir2->Get((histogram[i]+"E55").c_str()));
	Energy3.push_back((TH1D*)dir3->Get((histogram[i]+"E55").c_str()));
	Energy4.push_back((TH1D*)dir4->Get((histogram[i]+"E55").c_str()));
        Energy1[i]->SetXTitle("e55(GeV)");
        Energy1[i]->SetYTitle("Entries");
        Energy1[i]->SetTitle("");
        Energy1[i]->Draw();
        Energy2[i]->Draw("same");
        Energy3[i]->Draw("same");
        Energy4[i]->Draw("same");
        Energy1[i]->SetLineColorAlpha(41,1);
        Energy2[i]->SetLineColorAlpha(30,1);
        Energy3[i]->SetLineColorAlpha(38,1);
        Energy4[i]->SetLineColorAlpha(46,1);
        Energy1[i]->SetFillColorAlpha(41,0.45);
        Energy2[i]->SetFillColorAlpha(30,0.45);
        Energy3[i]->SetFillColorAlpha(38,0.45);
        Energy4[i]->SetFillColorAlpha(46,0.45);
        mgr::SetSinglePad(canvas);
        mgr::SetAxis(Energy1[i]);
        mgr::DrawCMSLabelOuter(SIMULATION);
        mgr::DrawEntryRight("2018 13TeV 15000 Entries");
        TLegend *leg3 = new TLegend(0.7,0.85,1.00,0.70); 
        leg3->SetBorderSize( 0 );
        leg3->SetFillColorAlpha( 0, 0 );
        leg3->AddEntry(Energy1[i],"1 TeV","f");
        leg3->AddEntry(Energy2[i],"2 TeV","f");
        leg3->AddEntry(Energy3[i],"3 TeV","f");
        leg3->AddEntry(Energy4[i],"4 TeV","f");
        leg3->Draw();
	canvas->SaveAs(("./Plots/2018/"+plotName[i]+"E55.pdf").c_str());

	}	
}
