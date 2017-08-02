#include "TH1.h"
#include "TH1F.h"
 

TCanvas* example_plot( )
{ 
  //  if( iPos==0 ) relPosX = 0.12;
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



   TGraphErrors* gre = new TGraphErrors(20);
   gre->SetName("Graph0");
   gre->SetTitle("");
   gre->SetFillColor(1);
   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000ff");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#0000ff");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#0000ff");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(21);
   gre->SetPoint(0,0.1428571,1.98333);
   gre->SetPointError(0,0,0);
   gre->SetPoint(1,0.2571429,1.70238);
   gre->SetPointError(1,0,0);
   gre->SetPoint(2,0.3142857,1.74238);
   gre->SetPointError(2,0,0);
   gre->SetPoint(3,0.3714286,1.8022);
   gre->SetPointError(3,0,0);
   gre->SetPoint(4,0.5428572,1.54955);
   gre->SetPointError(4,0,0);
   gre->SetPoint(5,0.6,1.78689);
   gre->SetPointError(5,0,0);
   gre->SetPoint(6,0.6,1.78689);
   gre->SetPointError(6,0,0);
   gre->SetPoint(7,0.9,1.56522);
   gre->SetPointError(7,0,0);
   gre->SetPoint(8,1.15,1.55738);
   gre->SetPointError(8,0,0);
   gre->SetPoint(9,1.4,1.53257);
   gre->SetPointError(9,0,0);
   gre->SetPoint(10,1.525,1.42338);
   gre->SetPointError(10,0,0);
   gre->SetPoint(11,1.775,1.42026);
   gre->SetPointError(11,0,0);
   gre->SetPoint(12,2.025,1.37956);
   gre->SetPointError(12,0,0);
   gre->SetPoint(13,2.275,1.41483);
   gre->SetPointError(13,0,0);
   gre->SetPoint(14,2.525,1.3588);
   gre->SetPointError(14,0,0);
   gre->SetPoint(15,3.15,1.33037);
   gre->SetPointError(15,0,0);
   gre->SetPoint(16,3.775,1.26402);
   gre->SetPointError(16,0,0);
   gre->SetPoint(17,4.4,1.18091);
   gre->SetPointError(17,0,0);
   gre->SetPoint(18,5.025,1.22794);
   gre->SetPointError(18,0,0);
   gre->SetPoint(19,5.65,1.1434);
   gre->SetPointError(19,0,0);
   gre->SetPoint(20,6.275,1.28125);
   gre->SetPointError(20,0,0);
   
   TH1F *Graph_Graph4 = new TH1F("Graph_Graph4","",100,0,6.888214);
   Graph_Graph4->SetMinimum(1);
   Graph_Graph4->SetMaximum(2.5);
   Graph_Graph4->SetDirectory(0);
   Graph_Graph4->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph4->SetLineColor(ci);
   Graph_Graph4->GetXaxis()->SetTitle("Threshold (pC)");
   Graph_Graph4->GetXaxis()->CenterTitle(true);
   Graph_Graph4->GetXaxis()->SetLabelFont(42);
   Graph_Graph4->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph4->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph4->GetXaxis()->SetTitleFont(42);
   Graph_Graph4->GetYaxis()->SetTitle("Multiplicity");
   Graph_Graph4->GetYaxis()->CenterTitle(true);
   Graph_Graph4->GetYaxis()->SetLabelFont(42);
   Graph_Graph4->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph4->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph4->GetYaxis()->SetTitleFont(42);
   Graph_Graph4->GetZaxis()->SetLabelFont(42);
   Graph_Graph4->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph4->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph4->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph4);
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

 gPad->Print("hpx.tex");
  return canv;
}
