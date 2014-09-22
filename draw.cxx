{
 TH1F* h = new TH1F ("h","",100,0,100);
 tree->Draw("pt1 >> h","goff");

 h->Draw();

}