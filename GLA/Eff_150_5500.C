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


   TGraphErrors *gre = new TGraphErrors(12);
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
   gre->SetPoint(0,0.1428571,0.943962);
   gre->SetPointError(0,0,0.00470259);
   gre->SetPoint(1,0.1714286,0.940484);
   gre->SetPointError(1,0,0.00447348);
   gre->SetPoint(2,0.2,0.935519);
   gre->SetPointError(2,0,0.00484668);
   gre->SetPoint(3,0.2285714,0.928495);
   gre->SetPointError(3,0,0.00504356);
   gre->SetPoint(4,0.2571429,0.931586);
   gre->SetPointError(4,0,0.00551296);
   gre->SetPoint(5,0.2857143,0.924183);
   gre->SetPointError(5,0,0.00521949);
   gre->SetPoint(6,0.3142857,0.925186);
   gre->SetPointError(6,0,0.00541335);
   gre->SetPoint(7,0.3428572,0.918469);
   gre->SetPointError(7,0,0.00520881);
   gre->SetPoint(8,0.3714286,0.926619);
   gre->SetPointError(8,0,0.00524148);
   gre->SetPoint(9,0.4,0.931496);
   gre->SetPointError(9,0,0.00526956);
   gre->SetPoint(10,0.4285714,0.932581);
   gre->SetPointError(10,0,0.00466349);
   gre->SetPoint(11,0.4571429,0.924199);
   gre->SetPointError(11,0,0.00348535);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","",100,0.1114286,0.4885714);
   Graph_Graph1->SetMinimum(0);
   Graph_Graph1->SetMaximum(1);
   Graph_Graph1->SetDirectory(0);
   Graph_Graph1->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1->SetLineColor(ci);
   Graph_Graph1->GetXaxis()->SetTitle("Threshold (pC)");
   Graph_Graph1->GetXaxis()->CenterTitle(true);
   Graph_Graph1->GetXaxis()->SetLabelFont(42);
   Graph_Graph1->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph1->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph1->GetXaxis()->SetTitleFont(42);
   Graph_Graph1->GetYaxis()->SetTitle("Efficiency");
   Graph_Graph1->GetYaxis()->SetRange(0,1);
   Graph_Graph1->GetYaxis()->CenterTitle(true);
   Graph_Graph1->GetYaxis()->SetLabelFont(42);
   Graph_Graph1->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph1->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph1->GetYaxis()->SetTitleFont(42);
   Graph_Graph1->GetZaxis()->SetLabelFont(42);
   Graph_Graph1->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1);
   
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
gPad->Print("Eff_150_5500.tex");
  return canv;
}
