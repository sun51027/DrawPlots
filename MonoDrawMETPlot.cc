////////////////////////////////////////
//
//
//      File name: MonoDrawMETPlot.cc
//      author: Shih Lin
//      Content: stack PFMET vs monopole plots
//               Without HLT
//	Date: 2021.5.25
//	      2021.7.9 update(Egamma PFMET)
//
///////////////////////////////////////////////////

#include <string>
#define MASS 4
using namespace std;
void MonoDrawMETPlot()
{
	string GeV[MASS] = {"1000","2000","3000","4000"};
	string Entry[MASS] = {"13510","17500","18000","18000"};
	TCanvas *canvas = new TCanvas("canvas","",800,600);
//	canvas->SetLogy();
//	for(int m=0; m<MASS;m++){
		//open file and directory
		TFile *fin1 = new TFile ("Monopole_PFMET_1000.root");
		TDirectory *NOTRG1 = (TDirectory*)fin1->Get("NOTRG");
		NOTRG1->cd();
	
		TFile *fin2 = new TFile ("Monopole_PFMET_2000.root");
		TDirectory *NOTRG2 = (TDirectory*)fin2->Get("NOTRG");
		NOTRG2->cd();
		
		TFile *fin3 = new TFile ("Monopole_PFMET_3000.root");
		TDirectory *NOTRG3 = (TDirectory*)fin3->Get("NOTRG");
		NOTRG3->cd();
		
		TFile *fin4 = new TFile ("Monopole_PFMET_4000.root");
		TDirectory *NOTRG4 = (TDirectory*)fin4->Get("NOTRG");
		NOTRG4->cd();
	vector<TH1*> METvsMonopole1;	
	vector<TH1*> METvsMonopole2;	
	vector<TH1*> METvsMonopole3;	
	vector<TH1*> METvsMonopole4;	

	vector<TH1*> EtaPt1;
	vector<TH1*> EtaPt2;
	vector<TH1*> EtaPt3;
	vector<TH1*> EtaPt4;
	
	gStyle->SetOptStat(0);
	string EtaPt[4] = {"PhotonlikePt","ElectronlikePt","PhotonlikeEta","ElectronlikeEta"};
	string PlotName[10] = {"PFMETvsTwoPhotonLike","PFMETvsTwoElectronLike","PFMETvsOnePhotonLike","PFMETvsOneElectronLike",
			       "PFMETvsOnePhotonOneElectronlike","PFMETvsOnePhotonOneCand","PFMETvsOneElectronOneCand",
			       "PFMETvsTwoCand","PFMETvsOneCand","PFMETvsZeroMonopole"};
	
	METvsMonopole1.push_back((TH1D*)NOTRG1->Get("PFMETvsTwoPhotonLike"));
	METvsMonopole1.push_back((TH1D*)NOTRG1->Get("PFMETvsTwoElectronLike"));
	METvsMonopole1.push_back((TH1D*)NOTRG1->Get("PFMETvsOnePhotonLike"));
	METvsMonopole1.push_back((TH1D*)NOTRG1->Get("PFMETvsOneElectronLike"));
	METvsMonopole1.push_back((TH1D*)NOTRG1->Get("PFMETvsOnePhotonOneElectronlike"));
	METvsMonopole1.push_back((TH1D*)NOTRG1->Get("PFMETvsOnePhotonOneCand"));
	METvsMonopole1.push_back((TH1D*)NOTRG1->Get("PFMETvsOneElectronOneCand"));
	METvsMonopole1.push_back((TH1D*)NOTRG1->Get("PFMETvsTwoCand"));
	METvsMonopole1.push_back((TH1D*)NOTRG1->Get("PFMETvsOneCand"));
	METvsMonopole1.push_back((TH1D*)NOTRG1->Get("PFMETvsZeroMonopole"));
	EtaPt1.push_back((TH1D*)NOTRG1->Get("PhotonlikePt"));
	EtaPt1.push_back((TH1D*)NOTRG1->Get("ElectronlikePt"));
	EtaPt1.push_back((TH1D*)NOTRG1->Get("PhotonlikeEta"));
	EtaPt1.push_back((TH1D*)NOTRG1->Get("ElectronlikeEta"));
	
	METvsMonopole2.push_back((TH1D*)NOTRG2->Get("PFMETvsTwoPhotonLike"));
	METvsMonopole2.push_back((TH1D*)NOTRG2->Get("PFMETvsTwoElectronLike"));
	METvsMonopole2.push_back((TH1D*)NOTRG2->Get("PFMETvsOnePhotonLike"));
	METvsMonopole2.push_back((TH1D*)NOTRG2->Get("PFMETvsOneElectronLike"));
	METvsMonopole2.push_back((TH1D*)NOTRG2->Get("PFMETvsOnePhotonOneElectronlike"));
	METvsMonopole2.push_back((TH1D*)NOTRG2->Get("PFMETvsOnePhotonOneCand"));
	METvsMonopole2.push_back((TH1D*)NOTRG2->Get("PFMETvsOneElectronOneCand"));
	METvsMonopole2.push_back((TH1D*)NOTRG2->Get("PFMETvsTwoCand"));
	METvsMonopole2.push_back((TH1D*)NOTRG2->Get("PFMETvsOneCand"));
	METvsMonopole2.push_back((TH1D*)NOTRG2->Get("PFMETvsZeroMonopole"));
	EtaPt2.push_back((TH1D*)NOTRG2->Get("PhotonlikePt"));
	EtaPt2.push_back((TH1D*)NOTRG2->Get("ElectronlikePt"));
	EtaPt2.push_back((TH1D*)NOTRG2->Get("PhotonlikeEta"));
	EtaPt2.push_back((TH1D*)NOTRG2->Get("ElectronlikeEta"));

	
	METvsMonopole3.push_back((TH1D*)NOTRG3->Get("PFMETvsTwoPhotonLike"));
	METvsMonopole3.push_back((TH1D*)NOTRG3->Get("PFMETvsTwoElectronLike"));
	METvsMonopole3.push_back((TH1D*)NOTRG3->Get("PFMETvsOnePhotonLike"));
	METvsMonopole3.push_back((TH1D*)NOTRG3->Get("PFMETvsOneElectronLike"));
	METvsMonopole3.push_back((TH1D*)NOTRG3->Get("PFMETvsOnePhotonOneElectronlike"));
	METvsMonopole3.push_back((TH1D*)NOTRG3->Get("PFMETvsOnePhotonOneCand"));
	METvsMonopole3.push_back((TH1D*)NOTRG3->Get("PFMETvsOneElectronOneCand"));
	METvsMonopole3.push_back((TH1D*)NOTRG3->Get("PFMETvsTwoCand"));
	METvsMonopole3.push_back((TH1D*)NOTRG3->Get("PFMETvsOneCand"));
	METvsMonopole3.push_back((TH1D*)NOTRG3->Get("PFMETvsZeroMonopole"));
	EtaPt3.push_back((TH1D*)NOTRG3->Get("PhotonlikePt"));
	EtaPt3.push_back((TH1D*)NOTRG3->Get("ElectronlikePt"));
	EtaPt3.push_back((TH1D*)NOTRG3->Get("PhotonlikeEta"));
	EtaPt3.push_back((TH1D*)NOTRG3->Get("ElectronlikeEta"));
	
	METvsMonopole4.push_back((TH1D*)NOTRG4->Get("PFMETvsTwoPhotonLike"));
	METvsMonopole4.push_back((TH1D*)NOTRG4->Get("PFMETvsTwoElectronLike"));
	METvsMonopole4.push_back((TH1D*)NOTRG4->Get("PFMETvsOnePhotonLike"));
	METvsMonopole4.push_back((TH1D*)NOTRG4->Get("PFMETvsOneElectronLike"));
	METvsMonopole4.push_back((TH1D*)NOTRG4->Get("PFMETvsOnePhotonOneElectronlike"));
	METvsMonopole4.push_back((TH1D*)NOTRG4->Get("PFMETvsOnePhotonOneCand"));
	METvsMonopole4.push_back((TH1D*)NOTRG4->Get("PFMETvsOneElectronOneCand"));
	METvsMonopole4.push_back((TH1D*)NOTRG4->Get("PFMETvsTwoCand"));
	METvsMonopole4.push_back((TH1D*)NOTRG4->Get("PFMETvsOneCand"));
	METvsMonopole4.push_back((TH1D*)NOTRG4->Get("PFMETvsZeroMonopole"));
	EtaPt4.push_back((TH1D*)NOTRG4->Get("PhotonlikePt"));
	EtaPt4.push_back((TH1D*)NOTRG4->Get("ElectronlikePt"));
	EtaPt4.push_back((TH1D*)NOTRG4->Get("PhotonlikeEta"));
	EtaPt4.push_back((TH1D*)NOTRG4->Get("ElectronlikeEta"));


	cout<<"size "<<METvsMonopole1.size()<<endl;
	for(int i=0;i<METvsMonopole1.size();i++){
		cout<<"1000GeV"<<endl;
		cout<<"Mean        "<<METvsMonopole1[i]->GetMean()<<endl;
		cout<<"Entries     "<<METvsMonopole1[i]->GetEntries()<<endl;
		cout<<"Efficiency  "<<METvsMonopole1[i]->GetEntries()/13510<<endl;
		cout<<endl<<"2000GeV"<<endl;
		cout<<"Mean        "<<METvsMonopole2[i]->GetMean()<<endl;
		cout<<"Entries     "<<METvsMonopole2[i]->GetEntries()<<endl;
		cout<<"Efficiency  "<<METvsMonopole2[i]->GetEntries()/17500<<endl;
		cout<<endl<<"3000GeV"<<endl;
		cout<<"Mean        "<<METvsMonopole3[i]->GetMean()<<endl;
		cout<<"Entries     "<<METvsMonopole3[i]->GetEntries()<<endl;
		cout<<"Efficiency  "<<METvsMonopole3[i]->GetEntries()/18000<<endl;
		cout<<endl<<"4000GeV"<<endl;
		cout<<"Mean        "<<METvsMonopole4[i]->GetMean()<<endl;
		cout<<"Entries     "<<METvsMonopole4[i]->GetEntries()<<endl;
		cout<<"Efficiency  "<<METvsMonopole4[i]->GetEntries()/14500<<endl;
		
		METvsMonopole1[i]->SetXTitle("Missing transverse momentum(GeV)");
        	METvsMonopole1[i]->SetYTitle("Entries");
        	METvsMonopole1[i]->SetTitle("");
        	METvsMonopole1[i]->Draw();
        	METvsMonopole2[i]->Draw("same");
        	METvsMonopole3[i]->Draw("same");
        	METvsMonopole4[i]->Draw("same");
		METvsMonopole1[i]->SetLineColorAlpha(41,1);
		METvsMonopole2[i]->SetLineColorAlpha(30,1);
		METvsMonopole3[i]->SetLineColorAlpha(38,1);
		METvsMonopole4[i]->SetLineColorAlpha(46,1);
		METvsMonopole1[i]->SetFillColorAlpha(41,0.45);
		METvsMonopole2[i]->SetFillColorAlpha(30,0.45);
		METvsMonopole3[i]->SetFillColorAlpha(38,0.45);
		METvsMonopole4[i]->SetFillColorAlpha(46,0.45);
        	mgr::SetSinglePad(canvas);
        	mgr::SetAxis(METvsMonopole1[i]);
        	mgr::DrawCMSLabelOuter(SIMULATION);
       // 	mgr::DrawEntryRight(("2018 "+GeV[m]+"GeV "+Entry[m]+" Events").c_str());
        //	canvas->SaveAs(("./Plots/2018/"+GeV[m]+"/"+PlotName[i]+"_NotLog.pdf").c_str());
        	mgr::DrawEntryRight("2018 13TeV");
	        TLegend *leg = new TLegend(0.7,0.85,1.00,0.70);
	        leg->SetBorderSize( 0 );
	        leg->SetFillColorAlpha( 0, 0 );
	        leg->AddEntry(METvsMonopole1[i],"1TeV 13510 Entries","f");
	        leg->AddEntry(METvsMonopole2[i],"2TeV 17500 Entries","f");
	        leg->AddEntry(METvsMonopole3[i],"3TeV 18000 Entries","f");
	        leg->AddEntry(METvsMonopole4[i],"4TeV 14500 Entries","f");
		leg->Draw();
        	canvas->SaveAs(("./Plots/2018/"+PlotName[i]+"_NotLog.pdf").c_str());
	}
	

	for(int i=0;i<EtaPt1.size()-1;i++){
			
		cout<<"1000GeV"<<endl;
		cout<<"Mean        "<<EtaPt1[i]->GetMean()<<endl;
		cout<<"Entries     "<<EtaPt1[i]->GetEntries()<<endl;
		cout<<"Efficiency  "<<EtaPt1[i]->GetEntries()/13510<<endl;
		cout<<endl<<"2000GeV"<<endl;
		cout<<"Mean        "<<EtaPt2[i]->GetMean()<<endl;
		cout<<"Entries     "<<EtaPt2[i]->GetEntries()<<endl;
		cout<<"Efficiency  "<<EtaPt2[i]->GetEntries()/17500<<endl;
		cout<<endl<<"3000GeV"<<endl;
		cout<<"Mean        "<<EtaPt3[i]->GetMean()<<endl;
		cout<<"Entries     "<<EtaPt3[i]->GetEntries()<<endl;
		cout<<"Efficiency  "<<EtaPt3[i]->GetEntries()/18000<<endl;
		cout<<endl<<"4000GeV"<<endl;
		cout<<"Mean        "<<EtaPt4[i]->GetMean()<<endl;
		cout<<"Entries     "<<EtaPt4[i]->GetEntries()<<endl;
		cout<<"Efficiency  "<<EtaPt4[i]->GetEntries()/14500<<endl;
			
		if( i == 0 || i == 1 )	EtaPt2[i]->SetXTitle("pT(GeV)");
		if( i == 2 || i == 3 )	EtaPt2[i]->SetXTitle("#eta");
        	EtaPt2[i]->SetYTitle("Entries");
        	EtaPt2[i]->SetTitle("");
        	EtaPt2[i]->Draw();
        	EtaPt1[i]->Draw("same");
        	EtaPt3[i]->Draw("same");
        	EtaPt4[i]->Draw("same");
		EtaPt1[i]->SetLineColorAlpha(41,1);
		EtaPt2[i]->SetLineColorAlpha(30,1);
		EtaPt3[i]->SetLineColorAlpha(38,1);
		EtaPt4[i]->SetLineColorAlpha(46,1);
		EtaPt1[i]->SetFillColorAlpha(41,0.45);
		EtaPt2[i]->SetFillColorAlpha(30,0.45);
		EtaPt3[i]->SetFillColorAlpha(38,0.45);
		EtaPt4[i]->SetFillColorAlpha(46,0.45);
        	mgr::SetSinglePad(canvas);
        	mgr::SetAxis(EtaPt1[i]);
        	mgr::DrawCMSLabelOuter(SIMULATION);
       // 	mgr::DrawEntryRight(("2018 "+GeV[m]+"GeV "+Entry[m]+" Events").c_str());
        //	canvas->SaveAs(("./Plots/2018/"+GeV[m]+"/"+PlotName[i]+"_NotLog.pdf").c_str());
        	mgr::DrawEntryRight("2018 13TeV");
	        TLegend *leg2 = new TLegend(0.7,0.85,1.00,0.70);
	        leg2->SetBorderSize( 0 );
	        leg2->SetFillColorAlpha( 0, 0 );
	        leg2->AddEntry(EtaPt1[i],"1TeV 13510 Entries","f");
	        leg2->AddEntry(EtaPt2[i],"2TeV 17500 Entries","f");
	        leg2->AddEntry(EtaPt3[i],"3TeV 18000 Entries","f");
	        leg2->AddEntry(EtaPt4[i],"4TeV 14500 Entries","f");
		leg2->Draw();
        	canvas->SaveAs(("./Plots/2018/"+EtaPt[i]+"_NotLog.pdf").c_str());
	}
//	}

			
		EtaPt1[3]->SetXTitle("#eta");
        	EtaPt1[3]->SetYTitle("Entries");
        	EtaPt1[3]->SetTitle("");
        	EtaPt1[3]->Draw();
        	EtaPt2[3]->Draw("same");
        	EtaPt3[3]->Draw("same");
        	EtaPt4[3]->Draw("same");
		EtaPt1[3]->SetLineColorAlpha(41,1);
		EtaPt2[3]->SetLineColorAlpha(30,1);
		EtaPt3[3]->SetLineColorAlpha(38,1);
		EtaPt4[3]->SetLineColorAlpha(46,1);
		EtaPt1[3]->SetFillColorAlpha(41,0.45);
		EtaPt2[3]->SetFillColorAlpha(30,0.45);
		EtaPt3[3]->SetFillColorAlpha(38,0.45);
		EtaPt4[3]->SetFillColorAlpha(46,0.45);
        	mgr::SetSinglePad(canvas);
        	mgr::SetAxis(EtaPt1[3]);
        	mgr::DrawCMSLabelOuter(SIMULATION);
       // 	mgr::DrawEntryRight(("2018 "+GeV[m]+"GeV "+Entry[m]+" Events").c_str());
        //	canvas->SaveAs(("./Plots/2018/"+GeV[m]+"/"+PlotName[i]+"_NotLog.pdf").c_str());
        	mgr::DrawEntryRight("2018 13TeV");
	        TLegend *leg2 = new TLegend(0.7,0.85,1.00,0.70);
	        leg2->SetBorderSize( 0 );
	        leg2->SetFillColorAlpha( 0, 0 );
	        leg2->AddEntry(EtaPt1[3],"1TeV 13510 Entries","f");
	        leg2->AddEntry(EtaPt2[3],"2TeV 17500 Entries","f");
	        leg2->AddEntry(EtaPt3[3],"3TeV 18000 Entries","f");
	        leg2->AddEntry(EtaPt4[3],"4TeV 14500 Entries","f");
		leg2->Draw();
        	canvas->SaveAs(("./Plots/2018/"+EtaPt[3]+"_NotLog.pdf").c_str());
}
