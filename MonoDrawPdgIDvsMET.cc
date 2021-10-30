////////////////////////////////////
////
////
////      File name: MonoDrawPIDvsMET.cc
////      author: Shih Lin
////      Date: 2021.8.13
////
/////////////////////////////////////////////////////


#include "iostream"
#include "TAttMarker.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TTree.h"
#include "TH1F.h"
#include "math.h"
#include <algorithm>
using namespace std;
void MonoDrawPdgIDvsMET(){

	TFile *fin1 = new TFile("Monopole_PFMET_PF_1000.root");
	TDirectory *dir1 = (TDirectory*)fin1->Get("NOTRG");
	dir1->cd();

        TCanvas *canvas = new TCanvas("canvas","",800,600);
        gStyle->SetOptStat(0);

	TProfile *PFMETvsTwoPID, *PFMETvsOneCandOnePID, *PFMETvsOnlyOnePID;
	PFMETvsTwoPID = (TProfile*)dir1->Get("PFMETvsTwoPID");
	PFMETvsOneCandOnePID = (TProfile*)dir1->Get("PFMETvsOneCandOnePID");
	PFMETvsOnlyOnePID = (TProfile*)dir1->Get("PFMETvsOnlyOnePID");

        PFMETvsTwoPID->SetXTitle("pdg ID");
        PFMETvsTwoPID->SetYTitle("MET(GeV)");
        PFMETvsTwoPID->SetTitle("");
        PFMETvsTwoPID->Draw();
        mgr::SetSinglePad(canvas);
        mgr::SetAxis(PFMETvsTwoPID);
        mgr::DrawCMSLabelOuter(SIMULATION);
        mgr::DrawEntryRight("2018 13TeV 15000 Events MC sample");
        canvas->SaveAs("./Plots/PFMETvsTwoPID.pdf");

        PFMETvsOneCandOnePID->SetXTitle("pdg ID");
        PFMETvsOneCandOnePID->SetYTitle("MET(GeV)");
        PFMETvsOneCandOnePID->SetTitle("");
        PFMETvsOneCandOnePID->Draw();
        mgr::SetSinglePad(canvas);
        mgr::SetAxis(PFMETvsOneCandOnePID);
        mgr::DrawCMSLabelOuter(SIMULATION);
        mgr::DrawEntryRight("2018 13TeV 15000 Events MC sample");
        canvas->SaveAs("./Plots/PFMETvsOneCandOnePID.pdf");


        PFMETvsOnlyOnePID->SetXTitle("pdg ID");
        PFMETvsOnlyOnePID->SetYTitle("MET(GeV)");
        PFMETvsOnlyOnePID->SetTitle("");
        PFMETvsOnlyOnePID->Draw();
        mgr::SetSinglePad(canvas);
        mgr::SetAxis(PFMETvsOnlyOnePID);
        mgr::DrawCMSLabelOuter(SIMULATION);
        mgr::DrawEntryRight("2018 13TeV 15000 Events MC sample");
        canvas->SaveAs("./Plots/PFMETvsOnlyOnePID.pdf");

}
