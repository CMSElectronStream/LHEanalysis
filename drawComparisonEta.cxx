{
 TTree* tree_8 = (TTree*) _file0-> Get("tree");
 TH1F* h_8 = new TH1F ("h_8","",30,0,5);
 tree_8->Draw("abs(eta1) >> h_8","","goff");

 TTree* tree_13 = (TTree*) _file1-> Get("tree");
 TH1F* h_13 = new TH1F ("h_13","",30,0,5);
 tree_13->Draw("abs(eta1) >> h_13","","goff");

 double integral_scale = h_13->Integral();
 std::cout << " integral_scale = " << integral_scale << std::endl;
 h_13->Scale (1. / integral_scale);
 h_13->GetXaxis()->SetTitle ("electron |#eta|");
 h_13->SetLineWidth(2);
 h_13->SetLineColor(kRed);

 integral_scale = h_8->Integral();
 std::cout << " integral_scale = " << integral_scale << std::endl;
 h_8->Scale (1. / integral_scale);
 h_8->GetXaxis()->SetTitle ("electron |#eta|");
 h_8->SetLineWidth(2);
 h_8->SetLineColor(kBlue);

 TCanvas* c1 = new TCanvas ("c1","c1");
 h_8->Draw();
 h_13->Draw("same");
 c1->SetGrid();
 c1->SaveAs("eta_comparison.png");

 Double_t *integral = h_13->GetIntegral();
 TH1* h_13_int = (TH1*) h_13->Clone();
 h_13_int->SetContent(integral);
 h_13_int->Scale (1);

 Double_t *integral_8 = h_8->GetIntegral();
 TH1* h_8_int = (TH1*) h_8->Clone();
 h_8_int->SetContent(integral_8);
 h_8_int->Scale (1);

 TCanvas* c2 = new TCanvas ("c2","c2");
 h_8_int->Draw();
 h_13_int->Draw("same");


 TH1* h_13_int = (TH1*) h_13->Clone();
 h_13_int->SetContent(integral);
 h_13_int->Scale (1);

 TH1* h_8_int = (TH1*) h_8->Clone();
 h_8_int->SetContent(integral);
 h_8_int->Scale (1);

 TCanvas* c3 = new TCanvas ("c3","c3");
 h_13_int->GetYaxis()->SetTitle ("Efficiency (|#eta| < threshold)");
 h_13_int->GetXaxis()->SetTitle ("electron |#eta|");
 h_13_int->SetLineWidth(2);
 h_13_int->SetLineColor(kRed);
 h_8_int->GetYaxis()->SetTitle ("Efficiency (|#eta| < threshold)");
 h_8_int->GetXaxis()->SetTitle ("electron |#eta|");
 h_8_int->SetLineWidth(2);
 h_8_int->SetLineColor(kBlue);

 h_13_int->Draw();
 h_8_int->Draw("same");
 c3->SetGrid();
 c3->SaveAs("etaInt_comparison.png");

}