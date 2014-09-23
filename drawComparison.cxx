{
 TTree* tree_8 = (TTree*) _file0-> Get("tree");
 TH1F* h_8 = new TH1F ("h_8","",120,0,60);
 tree_8->Draw("pt1 >> h_8","","goff");

 TTree* tree_13 = (TTree*) _file1-> Get("tree");
 TH1F* h_13 = new TH1F ("h_13","",120,0,60);
 tree_13->Draw("pt1 >> h_13","","goff");

 double integral_scale = h_13->Integral();
 std::cout << " integral_scale = " << integral_scale << std::endl;
 h_13->Scale (1. / integral_scale);
 h_13->GetXaxis()->SetTitle ("electron pT [GeV]");
 h_13->SetLineWidth(2);
 h_13->SetLineColor(kRed);

 integral_scale = h_8->Integral();
 std::cout << " integral_scale = " << integral_scale << std::endl;
 h_8->Scale (1. / integral_scale);
 h_8->GetXaxis()->SetTitle ("electron pT [GeV]");
 h_8->SetLineWidth(2);
 h_8->SetLineColor(kBlue);

 TCanvas* c1 = new TCanvas ("c1","c1");
 h_13->Draw();
 h_8->Draw("same");
 c1->SetGrid();
 c1->SaveAs("pt_comparison.png");

 Double_t *integral = h_13->GetIntegral();
 TH1* h_13_int = (TH1*) h_13->Clone();
 h_13_int->SetContent(integral);
 h_13_int->Scale (1);

 Double_t *integral_8 = h_8->GetIntegral();
 TH1* h_8_int = (TH1*) h_8->Clone();
 h_8_int->SetContent(integral_8);
 h_8_int->Scale (1);

 TCanvas* c2 = new TCanvas ("c2","c2");
 h_13_int->Draw();
 h_8_int->Draw("same");


 TH1* h_13_int = (TH1*) h_13->Clone();
 h_13_int->SetContent(integral);
 h_13_int->Scale (1);

 TH1* h_8_int = (TH1*) h_8->Clone();
 h_8_int->SetContent(integral);
 h_8_int->Scale (1);

 TCanvas* c3 = new TCanvas ("c3","c3");
 TH1* h_13_int_left = (TH1*) h_13_int->Clone();
 for (int i=0; i<h_13_int->GetNbinsX(); i++) {
  h_13_int_left->SetBinContent (i+1, 1. - h_13_int->GetBinContent (i+1));
 }
 h_13_int_left->GetYaxis()->SetTitle ("Efficiency (pT > threshold)");
 h_13_int_left->GetXaxis()->SetTitle ("electron pT [GeV]");
 h_13_int_left->SetLineWidth(2);
 h_13_int_left->SetLineColor(kRed);
 TH1* h_8_int_left = (TH1*) h_8_int->Clone();
 for (int i=0; i<h_8_int->GetNbinsX(); i++) {
  h_8_int_left->SetBinContent (i+1, 1. - h_8_int->GetBinContent (i+1));
 }
 h_8_int_left->GetYaxis()->SetTitle ("Efficiency (pT > threshold)");
 h_8_int_left->GetXaxis()->SetTitle ("electron pT [GeV]");
 h_8_int_left->SetLineWidth(2);
 h_8_int_left->SetLineColor(kBlue);

 h_13_int_left->Draw();
 h_8_int_left->Draw("same");
 c3->SetGrid();
 c3->SaveAs("ptInt_comparison.png");

}