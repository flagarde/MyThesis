{
   double ymin=0;
   double ymax=1.0;
   double ymin2=0;
   double ymax2=100;
//=========Macro generated from canvas: HP/HP
//=========  (Tue Feb 16 16:52:51 2016) by ROOT version5.34/30
   gStyle->SetPaperSize(10.,10.);
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
   //pad1->SetLogy();
   pad1->Range(0,0,1,1);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetFrameBorderMode(0);

   double HV1[8]={5800,6000,6200,6400,6500,6600,6800,7000};
   double Noise1[8]={0.9914984415450944,1.4284139776185372,2.388943677985073,2.9926261335465547,3.608758088837009,5.00478015427864,14.919262564934622,52.110150269917284};
   double HV2[6]={6000,6200,6500,6600,6800,7000};
   double Noise2[6]={2.016743656132317,3.501089180086602,3.051201520762579,3.3208933164972403,4.566537697699327,6.640550531551298};
   TGraphErrors *gre0 = new TGraphErrors(8,HV1,Noise1);
   gre0->SetName("Graph0");
   gre0->SetTitle("Graph0");
   gre0->SetFillColor(1);
   gre0->SetLineColor(1);
   gre0->SetMarkerColor(1);
   gre0->SetMarkerStyle(21);
   TGraphErrors *gre1 = new TGraphErrors(6,HV2,Noise2);
   gre1->SetName("Graph1");
   gre1->SetTitle("Graph0");
   gre1->SetFillColor(2);
   gre1->SetLineColor(2);
   gre1->SetMarkerColor(2);
   gre1->SetMarkerStyle(22);
   double HV3[5]={6200,6400,6500,6600,6800};
   double Effi1[5]={40.559006211180126,70.93167701863354,81.92546583850931,88.07453416149068,98.13664596273292};
   TGraphErrors *gre2 = new TGraphErrors(5,HV3,Effi1);
   gre2->SetName("Graph2");
   gre2->SetTitle("Graph0");
   gre2->SetFillColor(3);
   gre2->SetLineColor(3);
   gre2->SetMarkerColor(3);
   gre2->SetMarkerStyle(23);

   
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","",100,5700,7000);
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
   Graph_Graph1->GetXaxis()->SetTitle("HV (V)");
   Graph_Graph1->GetXaxis()->CenterTitle(true);
   Graph_Graph1->GetXaxis()->SetLabelFont(42);
   Graph_Graph1->GetXaxis()->SetLabelOffset(0.003);
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
   gre2->SetHistogram(Graph_Graph1);

   
   
   TH1F *Graph_Graph2 = new TH1F("Graph_Graph2","",100,5700,7000);
   Graph_Graph2->SetMinimum(ymin2);
   Graph_Graph2->SetMaximum(ymax2);
   Graph_Graph2->SetDirectory(0);
   Graph_Graph2->SetStats(0);
 
   ci = TColor::GetColor("#000099");
   
   Graph_Graph2->SetLineColor(ci);
   Graph_Graph2->SetLineStyle(0);
   Graph_Graph2->SetMarkerStyle(20);
   Graph_Graph2->GetXaxis()->SetTitle("HV (V)");
   Graph_Graph2->GetXaxis()->CenterTitle(true);
   Graph_Graph2->GetXaxis()->SetLabelFont(42);
   Graph_Graph2->GetXaxis()->SetLabelOffset(0.003);
   Graph_Graph2->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph2->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph2->GetXaxis()->SetTitleFont(42);
   Graph_Graph2->GetYaxis()->SetTitle("Efficiency");
   Graph_Graph2->GetYaxis()->CenterTitle(true);
   Graph_Graph2->GetYaxis()->SetLabelFont(42);
   Graph_Graph2->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph2->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph2->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph2->GetYaxis()->SetTitleFont(42);
   Graph_Graph2->GetZaxis()->SetLabelFont(42);
   Graph_Graph2->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph2->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph2->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph2->GetZaxis()->SetTitleFont(42);
   gre0->SetHistogram(Graph_Graph2);
   gre1->SetHistogram(Graph_Graph2);
   gre0->Draw("ap");
   gre1->Draw("samep");
   gre2->Draw("samep");
   pad1->Modified();
   HP->cd();
  
// ------------>Primitives in pad: pad2
   TPad* pad2 = new TPad("pad2", "",0,0,1,1);
   //pad2->SetLogy();
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
   gaxis->SetTitle("Noise");
   gaxis->SetLabelFont(22);
   gaxis->Draw();
   pad2->Modified();
   pad1->Modified();
   TLegend *leg = new TLegend(0.20,0.6393728,0.50,0.80,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(62);
   leg->SetTextSize(0.035);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Graph0","Noise 5%","p");
   entry=leg->AddEntry("Graph1","Noise 0.3%","p");
   entry=leg->AddEntry("Graph2","Efficicency","p");
   leg->Draw();
   TLatex * tex = new TLatex(0.50,0.82,"Threshold : 0.13pC");
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
  
   gPad->Print("EffiNoiseChi.tex");
   
}
