{
//=========Macro generated from canvas: cBeamSource/
//=========  (Tue Aug 22 00:45:16 2017) by ROOT version5.34/26
   TCanvas *cBeamSource = new TCanvas("cBeamSource", "");
   gStyle->SetPaperSize(10.,10.);
   gStyle->SetOptStat(10);
   cBeamSource->SetHighLightColor(2);
   cBeamSource->Range(0,0,1,1);
   cBeamSource->SetFillColor(0);
   cBeamSource->SetBorderMode(0);
   cBeamSource->SetBorderSize(2);
   cBeamSource->SetGridx();
   cBeamSource->SetGridy();
   cBeamSource->SetLeftMargin(0.3);
   cBeamSource->SetRightMargin(0.15);
   cBeamSource->SetFrameBorderMode(0);
   
   TH2F *hStatusBeamVsSource = new TH2F("hStatusBeamVsSource","GIF Beam status Vs Source",4,0,4,4,0,4);
   hStatusBeamVsSource->SetBinContent(7,3);
   hStatusBeamVsSource->SetBinContent(8,7);
   hStatusBeamVsSource->SetBinContent(13,23);
   hStatusBeamVsSource->SetBinContent(14,35);
   hStatusBeamVsSource->SetBinContent(19,3);
   hStatusBeamVsSource->SetBinContent(20,3);
   hStatusBeamVsSource->SetBinContent(21,22);
   hStatusBeamVsSource->SetBinContent(28,30);
   hStatusBeamVsSource->SetEntries(126);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hStatusBeamVsSource->SetLineColor(ci);
   hStatusBeamVsSource->GetXaxis()->SetTitle("Source status");
   hStatusBeamVsSource->GetXaxis()->SetBinLabel(1,"OFF");
   hStatusBeamVsSource->GetXaxis()->SetBinLabel(2,"ON");
   hStatusBeamVsSource->GetXaxis()->SetBinLabel(3,"Unknown from GIF elog");
   hStatusBeamVsSource->GetXaxis()->SetBinLabel(4,"Unknown from M3 elog");
   hStatusBeamVsSource->GetXaxis()->SetRange(1,4);
   hStatusBeamVsSource->GetXaxis()->SetLabelFont(42);
   hStatusBeamVsSource->GetXaxis()->SetLabelSize(0.035);
   hStatusBeamVsSource->GetXaxis()->SetTitleSize(0.035);
   hStatusBeamVsSource->GetXaxis()->SetTitleOffset(-0.3);
   hStatusBeamVsSource->GetXaxis()->SetTitleFont(42);
   hStatusBeamVsSource->GetYaxis()->SetTitle("Beam  status");
   hStatusBeamVsSource->GetYaxis()->SetBinLabel(1,"OFF");
   hStatusBeamVsSource->GetYaxis()->SetBinLabel(2,"ON");
   hStatusBeamVsSource->GetYaxis()->SetBinLabel(3,"Unknown from GIF elog");
   hStatusBeamVsSource->GetYaxis()->SetBinLabel(4,"Unknown from M3 elog");
   hStatusBeamVsSource->GetYaxis()->SetRange(1,4);
   hStatusBeamVsSource->GetYaxis()->SetLabelFont(42);
   hStatusBeamVsSource->GetYaxis()->SetLabelSize(0.035);
   hStatusBeamVsSource->GetYaxis()->SetTitleSize(0.035);
   hStatusBeamVsSource->GetYaxis()->SetTitleOffset(-0.3);
   hStatusBeamVsSource->GetYaxis()->SetTitleFont(42);
   hStatusBeamVsSource->GetZaxis()->SetLabelFont(42);
   hStatusBeamVsSource->GetZaxis()->SetLabelSize(0.035);
   hStatusBeamVsSource->GetZaxis()->SetTitleSize(0.035);
   hStatusBeamVsSource->GetZaxis()->SetTitleFont(42);
   hStatusBeamVsSource->Draw("TEXT");
   cBeamSource->Modified();
   cBeamSource->cd();
   cBeamSource->SetSelected(cBeamSource);
   gPad->Print("hStatusBeamVsSource.tex");
}
