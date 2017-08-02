#include "TH1.h"
#include "TH1F.h"

TCanvas* example_plot()
{ 
  gStyle->SetPaperSize(10.,10.);

  int W = 800;
  int H = 600;

  int H_ref = 600; 
  int W_ref = 800; 

  // references for T, B, L, R
  float T = 0.08*H_ref;
  float B = 0.12*H_ref; 
  float L = 0.12*W_ref;
  float R = 0.04*W_ref;

  TString canvName = "FigExample_";
  canvName += W;
  canvName += "-";
  canvName += H;
  canvName += "_";  

  TCanvas* canv = new TCanvas(canvName,canvName,50,50,W,H);
  canv->SetFillColor(0);
  canv->SetBorderMode(0);
  canv->SetFrameFillStyle(0);
  canv->SetFrameBorderMode(0);
  canv->SetLeftMargin( L/W );
  canv->SetRightMargin( R/W );
  canv->SetTopMargin( T/H );
  canv->SetBottomMargin( B/H );
  canv->SetTickx(0);
  canv->SetTicky(0);


  int histLineColor = kOrange+7;
  int histFillColor = kOrange-2;
  float markerSize  = 1.0;

   TGraphErrors *gre = new TGraphErrors(11);
   gre->SetName("Graph0");
   gre->SetTitle("");
   gre->SetFillColor(1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000ff");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#0000ff");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(21);
   gre->SetPoint(0,0.1428571,0.933737);
   gre->SetPointError(0,0,0.00517424);
   gre->SetPoint(1,0.1714286,0.928338);
   gre->SetPointError(1,0,0.00510574);
   gre->SetPoint(2,0.2,0.938204);
   gre->SetPointError(2,0,0.00473951);
   gre->SetPoint(3,0.2285714,0.939315);
   gre->SetPointError(3,0,0.00512881);
   gre->SetPoint(4,0.2571429,0.929515);
   gre->SetPointError(4,0,0.0055723);
   gre->SetPoint(5,0.3142857,0.921661);
   gre->SetPointError(5,0,0.00579099);
   gre->SetPoint(6,0.3714286,0.927908);
   gre->SetPointError(6,0,0.00564668);
   gre->SetPoint(7,0.4571429,0.922973);
   gre->SetPointError(7,0,0.0058904);
   gre->SetPoint(8,0.5142857,0.911906);
   gre->SetPointError(8,0,0.00619829);
   gre->SetPoint(9,0.5714286,0.897292);
   gre->SetPointError(9,0,0.00601055);
   gre->SetPoint(10,0.6285715,0.92751);
   gre->SetPointError(10,0,0.004689);
   
   TH1F *Graph_Graph5 = new TH1F("Graph_Graph5","",100,0.09428572,0.6771429);
   Graph_Graph5->SetMinimum(0);
   Graph_Graph5->SetMaximum(1);
   Graph_Graph5->SetDirectory(0);
   Graph_Graph5->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph5->SetLineColor(ci);
   Graph_Graph5->GetXaxis()->SetTitle("Threshold (pC)");
   Graph_Graph5->GetXaxis()->CenterTitle(true);
   Graph_Graph5->GetXaxis()->SetLabelFont(42);
   Graph_Graph5->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph5->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph5->GetXaxis()->SetTitleFont(42);
   Graph_Graph5->GetYaxis()->SetTitle("Efficiency");
   Graph_Graph5->GetYaxis()->CenterTitle(true);
   Graph_Graph5->GetYaxis()->SetLabelFont(42);
   Graph_Graph5->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph5->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph5->GetYaxis()->SetTitleFont(42);
   Graph_Graph5->GetZaxis()->SetLabelFont(42);
   Graph_Graph5->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph5->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph5->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph5);
   gre->Draw("ap");

  TLegend *leg = new TLegend(0.55,0.35,0.70,0.50);
  leg->SetTextSize(0.035);
  leg->SetLineColor(1);
  leg->SetLineStyle(1);
  leg->SetLineWidth(1);
  leg->SetFillColor(0);
  leg->SetBorderSize(0);
  leg->SetHeader("GIF++ test beams 08.2015");
  leg->AddEntry(gre, "Low Resistivity Glass RPC", "p");
  leg->Draw();

  canv->Update();
  canv->RedrawAxis();
  canv->GetFrame()->Draw();

gPad->Print("Eff_46_5500.tex");
  return canv;
}
