{
 TH1F* h = new TH1F ("h","",60,0,2.5);
 tree->Draw("abs(eta1) >> h","","goff");

 double integral_scale = h->Integral();
 std::cout << " integral_scale = " << integral_scale << std::endl;
 h->Scale (1. / integral_scale);
 h->GetXaxis()->SetTitle ("#eta electron");
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

 h_int->GetYaxis()->SetTitle ("Efficiency (#eta < threshold)");
 h_int->GetXaxis()->SetTitle ("#eta electron");
 h_int->SetLineWidth(2);
 h_int->SetLineColor(kBlue);
 h_int->Draw();
 c2->SetGrid();


}