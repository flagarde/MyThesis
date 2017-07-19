{
   double pas=2.5;//mmm
   double ymin=1;
   double ymax=2.1;
   double ymin2=pas*ymin/sqrt(12);
   double ymax2=pas*ymax/sqrt(12);
//=========Macro generated from canvas: HP/HP
//=========  (Tue Feb 16 16:52:51 2016) by ROOT version5.34/30
   TCanvas *HP = new TCanvas("HP", "HP",9,31,600,600);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   HP->Range(0,0,1,1);
   HP->SetGrid();
   HP->SetFillColor(0);
   HP->SetBorderMode(0);
   HP->SetBorderSize(2);
   HP->SetLeftMargin(0.12);
   HP->SetRightMargin(0.04);
   HP->SetTopMargin(0.08);
   HP->SetBottomMargin(0.12);
   HP->SetFrameFillStyle(0);
   HP->SetFrameBorderMode(0);
   HP->SetFrameFillStyle(0);
   HP->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: pad1
   TPad *pad1 = new TPad("pad1", "",0,0,1,1);
   pad1->Draw();
   pad1->cd();
   pad1->Range(0,0,1,1);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetFrameBorderMode(0);
   
   TGraphErrors *gre = new TGraphErrors(8);
   gre->SetName("Graph0");
   gre->SetTitle("");
   gre->SetFillColor(1);
   gre->SetLineColor(4);
   gre->SetMarkerColor(4);
   gre->SetMarkerStyle(21);
   gre->SetPoint(0,85,1.924);
   gre->SetPointError(0,0,0.0448);
   gre->SetPoint(1,150,1.96);
   gre->SetPointError(1,0,0.0428);
   gre->SetPoint(2,266,1.946);
   gre->SetPointError(2,0,0.0263);
   gre->SetPoint(3,600,1.933);
   gre->SetPointError(3,0,0.0419);
   gre->SetPoint(4,2000,1.854);
   gre->SetPointError(4,0,0.0249);
   gre->SetPoint(5,3100,1.75);
   gre->SetPointError(5,0,0.0163);
   gre->SetPoint(6,5700,1.66);
   gre->SetPointError(6,0,0.0383);
   gre->SetPoint(7,9661,1.574);
   gre->SetPointError(7,0,0.0537);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","",100,0,10618.6);
   Graph_Graph1->SetMinimum(ymin);
   Graph_Graph1->SetMaximum(ymax);
   Graph_Graph1->SetDirectory(0);
   Graph_Graph1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   
   Graph_Graph1->SetLineColor(ci);
   Graph_Graph1->SetLineStyle(0);
   Graph_Graph1->SetMarkerStyle(20);
   Graph_Graph1->GetXaxis()->SetTitle("Rate(Part.s^{-1}.cm^{-2})");
   Graph_Graph1->GetXaxis()->CenterTitle(true);
   Graph_Graph1->GetXaxis()->SetLabelFont(42);
   Graph_Graph1->GetXaxis()->SetLabelOffset(0.003);
   Graph_Graph1->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph1->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph1->GetXaxis()->SetTitleFont(42);
   Graph_Graph1->GetYaxis()->SetTitle("Multiplicity");
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
   gre->SetHistogram(Graph_Graph1);
   gre->Draw("ape");
   pad1->Modified();
   HP->cd();
  
// ------------>Primitives in pad: pad2
   pad2 = new TPad("pad2", "",0,0,1,1);
   pad2->Draw();
   pad2->cd();
   pad2->Range(0,0,1,1);
   //pad2->Range(-1250,-0.3608439,11250,3.247595);
   pad2->SetFillColor(0);
   pad2->SetFillStyle(4000);
   pad2->SetBorderMode(0);
   pad2->SetBorderSize(2);
   pad2->SetFrameBorderMode(0);
   TGaxis *gaxis = new TGaxis(1-0.10,0+0.10,1-0.10,1-0.10,ymin2,ymax2,10+100*5+10000*5,"+L");
   gaxis->SetLabelOffset(0.005);
   gaxis->SetLabelSize(0.05);
   gaxis->SetTickSize(0.03);
   gaxis->SetGridLength(0);
   gaxis->SetTitleOffset(1);
   gaxis->SetTitleSize(0.05);
   gaxis->SetTitleColor(1);
   gaxis->SetTitleFont(22);
   gaxis->SetTitle("Spatial Resolution (mm)");
   gaxis->SetLabelFont(22);
   gaxis->Draw();
   pad2->Modified();
   pad1->Modified();
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
   
   HP->cd();
   HP->Modified();
   HP->cd();
   HP->SetSelected(HP);
   
}
