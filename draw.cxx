{
 TH1F* h = new TH1F ("h","",120,0,60);
 tree->Draw("pt1 >> h","","goff");

 double integral_scale = h->Integral();
 std::cout << " integral_scale = " << integral_scale << std::endl;
 h->Scale (1. / integral_scale);
 h->GetXaxis()->SetTitle ("electron pT [GeV]");
 h->SetLineWidth(2);
 h->SetLineColor(kRed);

 TCanvas* c1 = new TCanvas ("c1","c1");
 h->Draw();
 c1->SetGrid();

 Double_t *integral = h->GetIntegral();
 TH1* h_int = (TH1*) h->Clone();
 h_int->SetContent(integral);
 h_int->Scale (1);

 TCanvas* c2 = new TCanvas ("c2","c2");
 h_int->Draw();


 TH1* h_int = (TH1*) h->Clone();
 h_int->SetContent(integral);
 h_int->Scale (1);

 TCanvas* c3 = new TCanvas ("c3","c3");
 TH1* h_int_left = (TH1*) h_int->Clone();
 for (int i=0; i<h_int->GetNbinsX(); i++) {
  h_int_left->SetBinContent (i+1, 1. - h_int->GetBinContent (i+1));
 }
 h_int_left->GetYaxis()->SetTitle ("Efficiency (pT > threshold)");
 h_int_left->GetXaxis()->SetTitle ("electron pT [GeV]");
 h_int_left->SetLineWidth(2);
 h_int_left->SetLineColor(kBlue);
 h_int_left->Draw();
 c3->SetGrid();

}