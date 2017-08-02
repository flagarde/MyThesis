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

   TGraphErrors* gre = new TGraphErrors(12);
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
   gre->SetPoint(0,0.1428571,2.72617);
   gre->SetPointError(0,0,0);
   gre->SetPoint(1,0.1714286,2.66643);
   gre->SetPointError(1,0,0);
   gre->SetPoint(2,0.2,2.50857);
   gre->SetPointError(2,0,0);
   gre->SetPoint(3,0.2285714,2.46858);
   gre->SetPointError(3,0,0);
   gre->SetPoint(4,0.2571429,2.33);
   gre->SetPointError(4,0,0);
   gre->SetPoint(5,0.2857143,2.36703);
   gre->SetPointError(5,0,0);
   gre->SetPoint(6,0.3142857,2.30737);
   gre->SetPointError(6,0,0);
   gre->SetPoint(7,0.3428572,2.25254);
   gre->SetPointError(7,0,0);
   gre->SetPoint(8,0.3714286,2.26182);
   gre->SetPointError(8,0,0);
   gre->SetPoint(9,0.4,2.13185);
   gre->SetPointError(9,0,0);
   gre->SetPoint(10,0.4285714,2.20719);
   gre->SetPointError(10,0,0);
   gre->SetPoint(11,0.4571429,2.10786);
   gre->SetPointError(11,0,0);
   
   TH1F *Graph_Graph2 = new TH1F("Graph_Graph2","",100,0.1114286,0.4885714);
   Graph_Graph2->SetMinimum(1);
   Graph_Graph2->SetMaximum(3);
   Graph_Graph2->SetDirectory(0);
   Graph_Graph2->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph2->SetLineColor(ci);
   Graph_Graph2->GetXaxis()->SetTitle("Threshold (pC)");
   Graph_Graph2->GetXaxis()->CenterTitle(true);
   Graph_Graph2->GetXaxis()->SetLabelFont(42);
   Graph_Graph2->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph2->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph2->GetXaxis()->SetTitleFont(42);
   Graph_Graph2->GetYaxis()->SetTitle("Multiplicity");
   Graph_Graph2->GetYaxis()->CenterTitle(true);
   Graph_Graph2->GetYaxis()->SetLabelFont(42);
   Graph_Graph2->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph2->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph2->GetYaxis()->SetTitleFont(42);
   Graph_Graph2->GetZaxis()->SetLabelFont(42);
   Graph_Graph2->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph2->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph2->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph2);
   
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
  gPad->Print("Mul_150_5500.tex");
  return canv;
}
