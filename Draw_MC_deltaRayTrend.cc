{
  ifstream infile;
  infile.open("delta.txt");
  double c1,c2,c3,c4;
  vector<double> Delta_2018;
  vector<double> Delta_2017;
  vector<double> Delta_2016;
  vector<double> Delta_2016APV;
  vector<double> mass;
  if(!infile.is_open())
    cout<<"Fail to open!"<<endl;
  else{
    while(infile>>c1>>c2>>c3>>c4){
      Delta_2018.push_back(c1);
      Delta_2017.push_back(c2);
      Delta_2016.push_back(c3);
      Delta_2016APV.push_back(c4);
    }
  }
  ifstream infile2;
  infile2.open("delta_errobar.txt");
  double c5, c6, c7,c8; 
  vector<double> error_2018;
  vector<double> error_2017;
  vector<double> error_2016;
  vector<double> error_2016APV;
  if(!infile2.is_open())
    cout<<"Fail to open 2!"<<endl;
  else{
    while(infile2>>c5>>c6>>c7>>c8){
      error_2018.push_back(c5);
      error_2017.push_back(c6);
      error_2016.push_back(c7);
      error_2016APV.push_back(c8);
    }
  }
//  TGraph *g_trend1 = new TGraph(Delta_2018.size(),mass.data(),Delta_2018.data());
//  TGraph *g_trend2 = new TGraph(Delta_2017.size(),mass.data(),Delta_2017.data());
//  TGraph *g_trend3 = new TGraph(Delta_2016.size(),mass.data(),Delta_2016.data());
//  TGraph *g_trend4 = new TGraph(Delta_2016APV.size(),mass.data(),Delta_2016APV.data());

// TGraphErrors *g_trend1 = new TGraphErrors();
// TGraphErrors *g_trend2 = new TGraphErrors();
// TGraphErrors *g_trend3 = new TGraphErrors();
// TGraphErrors *g_trend4 = new TGraphErrors();
  for(int i =0;i<Delta_2018.size();i++){

    mass.push_back((double)(i+1)/2*1000+500);
 //   error_2018.push_back(i*0.1);
 //   error_2017.push_back(i*0.1);
 //   error_2016.push_back(i*0.1);
 //   error_2016APV.push_back(i*0.1);
//    g_trend1->SetPoint(i,mass[i],Delta_2018[i]);    
//    g_trend2->SetPoint(i,mass[i],Delta_2017[i]);    
//    g_trend3->SetPoint(i,mass[i],Delta_2016[i]);    
//    g_trend4->SetPoint(i,mass[i],Delta_2016APV[i]);    
//
//    g_trend1->SetPointError(i,mass[i],error_2018[i]);    
//    g_trend2->SetPointError(i,mass[i],error_2017[i]);    
//    g_trend3->SetPointError(i,mass[i],error_2016[i]);    
//    g_trend4->SetPointError(i,mass[i],error_2016APV[i]);    

    cout<<mass[i]<<" "<<Delta_2018[i]<<" "<<Delta_2017[i]
        <<" "<<Delta_2016[i]<<" "<<Delta_2016APV[i]<<endl;
  }

  TGraphErrors *g_trend1 = new TGraphErrors(Delta_2018.size(),mass.data(),Delta_2018.data(),0,error_2018.data());
  TGraphErrors *g_trend2 = new TGraphErrors(Delta_2017.size(),mass.data(),Delta_2017.data(),0,error_2017.data());
  TGraphErrors *g_trend3 = new TGraphErrors(Delta_2016.size(),mass.data(),Delta_2016.data(),0,error_2016.data());
  TGraphErrors *g_trend4 = new TGraphErrors(Delta_2016APV.size(),mass.data(),Delta_2016APV.data(),0,error_2016APV.data());
  TCanvas *c = new TCanvas ("c","",800,600);
  
  g_trend1->SetMarkerColor(41);
  g_trend2->SetMarkerColor(36);
  g_trend3->SetMarkerColor(46);
  g_trend4->SetMarkerColor(30);

  g_trend1->SetLineColor(41);
  g_trend2->SetLineColor(36);
  g_trend3->SetLineColor(46);
  g_trend4->SetLineColor(30);

  g_trend1->SetMarkerStyle(20);
  g_trend2->SetMarkerStyle(20);
  g_trend3->SetMarkerStyle(20);
  g_trend4->SetMarkerStyle(20);

  TMultiGraph *mg = new TMultiGraph();
  mg->Add(g_trend1);
  mg->Add(g_trend2);
  mg->Add(g_trend3);
  mg->Add(g_trend4);
  mg->Draw("ACP");
  mg->GetXaxis()->SetTitle("Mass (GeV)");
  mg->GetYaxis()->SetTitle("uncertainty");
  mg->GetYaxis()->SetTitleOffset(1.2);
  
  TLegend *leg2 = new TLegend(0.15, 0.15, 0.35, 0.35);
  leg2->SetTextSize(0.04);
  leg2->AddEntry(g_trend1, "2018", "pl");
  leg2->AddEntry(g_trend2, "2017", "pl");
  leg2->AddEntry(g_trend3, "2016", "pl");
  leg2->AddEntry(g_trend4, "2016APV", "pl");
  leg2->Draw();
  c->Modified();
  c->SetGrid(1,1);
  c->SaveAs("deltaTrend.pdf");
}
