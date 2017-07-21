void plot()
{
//=========Macro generated from canvas: FigExample_800-600_2-prelim-left/FigExample_800-600_2-prelim-left
//=========  (Thu Feb 11 12:02:16 2016) by ROOT version5.34/32
gStyle->SetPaperSize(10.,10.);
   TCanvas *FigExample = new TCanvas("FigExample", "FigExample",51,73,800,600);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   FigExample->Range(3.690612,-0.1612671,3.895239,1.182625);
   FigExample->SetFillColor(0);
   FigExample->SetBorderMode(0);
   FigExample->SetBorderSize(2);
   FigExample->SetLeftMargin(0.12);
   FigExample->SetRightMargin(0.04);
   FigExample->SetTopMargin(0.08);
   FigExample->SetBottomMargin(0.12);
   FigExample->SetFrameFillStyle(0);
   FigExample->SetFrameBorderMode(0);
   FigExample->SetFrameFillStyle(0);
   FigExample->SetFrameBorderMode(0);
   
   TGraphErrors *gre = new TGraphErrors(8);
   gre->SetName("Graph0");
   gre->SetTitle("");
   gre->SetFillColor(1);
   gre->SetLineColor(4);
   gre->SetMarkerColor(4);
   gre->SetMarkerStyle(21);
   gre->SetPoint(0,85,0.9575);
   gre->SetPointError(0,0,0.004729);
   
   gre->SetPoint(1,150,0.9599);
   gre->SetPointError(1,0,0.006052);
   
   gre->SetPoint(2,266,0.9377);
   gre->SetPointError(2,0,0.005664);
   
   gre->SetPoint(3,600,0.9211);
   gre->SetPointError(3,0,0.0107);
   
   gre->SetPoint(4,2000,0.8803);
   gre->SetPointError(4,0,0.01313);
   
   gre->SetPoint(5,3100,0.8716);
   gre->SetPointError(5,0,0.008784);
   
   gre->SetPoint(6,5700,0.7931);
   gre->SetPointError(6,0,0.01167);
   
   gre->SetPoint(7,9661,0.7646);
   gre->SetPointError(7,0,0.01241);
   
   TH1F *Graph_Graph_Graph11 = new TH1F("Graph_Graph_Graph11","",1000,100,10000);
   Graph_Graph_Graph11->SetMinimum(0);
   Graph_Graph_Graph11->SetMaximum(1.075114);
   Graph_Graph_Graph11->SetDirectory(0);
   Graph_Graph_Graph11->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph_Graph11->SetLineColor(ci);
   Graph_Graph_Graph11->SetLineStyle(0);
   Graph_Graph_Graph11->SetMarkerStyle(20);
   Graph_Graph_Graph11->GetXaxis()->SetTitle("Rate(Part.s^{-1}.cm^{-2})");
   Graph_Graph_Graph11->GetXaxis()->CenterTitle(true);
   Graph_Graph_Graph11->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph11->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph11->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph11->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph11->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph11->GetYaxis()->SetTitle("Efficiency");
   Graph_Graph_Graph11->GetYaxis()->CenterTitle(true);
   Graph_Graph_Graph11->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph11->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph11->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph_Graph11->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph11->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph11->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph11->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph11->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_Graph11->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_Graph11->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph_Graph11);
   
   gre->Draw("ap");
   
   TLegend *leg = new TLegend(0.5125313,0.1393728,0.6629073,0.2891986,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(62);
   leg->SetTextSize(0.035);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("NULL","PS test beams 08.2014","h");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph0","Low Resistive Glass RPC (~10^{10}#Omega.cm)","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(4);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   leg->Draw();
   TLatex *   tex = new TLatex(0.94,0.88,"Gas mixture : 93% TFE, 5%CO_{2}, 2%SF_{6}");
tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetTextFont(42);
   tex->SetTextSize(0.048);
   tex->SetLineWidth(2);
   tex->Draw();
   tex = new TLatex(0.94,0.82,"Threshold : 0.13pC");
   tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetTextFont(42);
   tex->SetTextSize(0.044);
   tex->SetLineWidth(2);
   tex->Draw();
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","",1000,100,10000);
   Graph_Graph1->SetMinimum(0);
   Graph_Graph1->SetMaximum(1.075114);
   Graph_Graph1->SetDirectory(0);
   Graph_Graph1->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1->SetLineColor(ci);
   Graph_Graph1->SetLineStyle(0);
   Graph_Graph1->SetMarkerStyle(20);
   Graph_Graph1->GetXaxis()->SetTitle("Rate(Part.s^{-1}.cm^{-2})");
   Graph_Graph1->GetXaxis()->CenterTitle(true);
   Graph_Graph1->GetXaxis()->SetLabelFont(42);
   Graph_Graph1->GetXaxis()->SetLabelOffset(0.007);
   Graph_Graph1->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph1->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph1->GetXaxis()->SetTitleFont(42);
   Graph_Graph1->GetYaxis()->SetTitle("Efficiency");
   Graph_Graph1->GetYaxis()->CenterTitle(true);
   Graph_Graph1->GetYaxis()->SetLabelFont(42);
   Graph_Graph1->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph1->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph1->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph1->GetYaxis()->SetTitleFont(42);
   Graph_Graph1->GetZaxis()->SetLabelFont(42);
   Graph_Graph1->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph1->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleFont(42);
   Graph_Graph1->Draw("sameaxis");
   FigExample->Modified();
   FigExample->cd();
   FigExample->SetSelected(FigExample);
   gPad->Print("hpx.tex");
}
