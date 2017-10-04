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

   TGraphErrors* gre = new TGraphErrors(11);
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
   gre->SetPoint(0,0.1428571,2.81437);
   gre->SetPointError(0,0,0);
   gre->SetPoint(1,0.1714286,2.7645);
   gre->SetPointError(1,0,0);
   gre->SetPoint(2,0.2,2.63193);
   gre->SetPointError(2,0,0);
   gre->SetPoint(3,0.2285714,2.41855);
   gre->SetPointError(3,0,0);
   gre->SetPoint(4,0.2571429,2.53649);
   gre->SetPointError(4,0,0);
   gre->SetPoint(5,0.3142857,2.38226);
   gre->SetPointError(5,0,0);
   gre->SetPoint(6,0.3714286,2.35844);
   gre->SetPointError(6,0,0);
   gre->SetPoint(7,0.4571429,2.23768);
   gre->SetPointError(7,0,0);
   gre->SetPoint(8,0.5142857,2.13821);
   gre->SetPointError(8,0,0);
   gre->SetPoint(9,0.5714286,2.09173);
   gre->SetPointError(9,0,0);
   gre->SetPoint(10,0.6285715,3.56213);
   gre->SetPointError(10,0,0);
   
   TH1F *Graph_Graph6 = new TH1F("Graph_Graph6","",100,0.09428572,0.6771429);
   Graph_Graph6->SetMinimum(1);
   Graph_Graph6->SetMaximum(3);
   Graph_Graph6->SetDirectory(0);
   Graph_Graph6->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph6->SetLineColor(ci);
   Graph_Graph6->GetXaxis()->SetTitle("Threshold (pC)");
   Graph_Graph6->GetXaxis()->CenterTitle(true);
   Graph_Graph6->GetXaxis()->SetLabelFont(42);
   Graph_Graph6->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph6->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph6->GetXaxis()->SetTitleFont(42);
   Graph_Graph6->GetYaxis()->SetTitle("Multiplicity");
   Graph_Graph6->GetYaxis()->CenterTitle(true);
   Graph_Graph6->GetYaxis()->SetLabelFont(42);
   Graph_Graph6->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph6->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph6->GetYaxis()->SetTitleFont(42);
   Graph_Graph6->GetZaxis()->SetLabelFont(42);
   Graph_Graph6->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph6->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph6->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph6);
   
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
gPad->Print("Mul_46_5500.tex");
  return canv;
}
