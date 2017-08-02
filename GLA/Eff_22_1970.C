#include "TH1.h"
#include "TH1F.h"
 
TCanvas* example_plot( )
{ 
  gStyle->SetPaperSize(10.,10.);
  //  if( iPos==0 ) relPosX = 0.12;

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
 // if( writeExtraText ) canvName += "-prelim";

  TCanvas* canv = new TCanvas();
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

  {

   TGraphErrors *gre = new TGraphErrors(9);
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
   gre->SetPoint(0,0.1428571,0.646341);
   gre->SetPointError(0,0,0.0656727);
   gre->SetPoint(1,0.62857,0.418182);
   gre->SetPointError(1,0,0.102852);
   gre->SetPoint(2,1.4,0.44843);
   gre->SetPointError(2,0,0.0497333);
   
   gre->SetPoint(3,1.775,0.307339);
   gre->SetPointError(3,0,0.0563679);
   gre->SetPoint(4,2.275,0.409396);
   gre->SetPointError(4,0,0.0629586);
   gre->SetPoint(5,3.15,0.248731);
   gre->SetPointError(5,0,0.0617539);
   gre->SetPoint(6,4.4,0.265);
   gre->SetPointError(6,0,0.0606218);
   gre->SetPoint(7,5.65,0.0761421);
   gre->SetPointError(7,0,0.0684809);
   gre->SetPoint(8,6.275,0.0318471);
   gre->SetPointError(8,0,0.0785276);
   
   TH1F *Graph_Graph3 = new TH1F("Graph_Graph3","",100,0,6.888214);
   Graph_Graph3->SetMinimum(0);
   Graph_Graph3->SetMaximum(1);
   Graph_Graph3->SetDirectory(0);
   Graph_Graph3->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph3->SetLineColor(ci);
   Graph_Graph3->GetXaxis()->SetTitle("Threshold (pC)");
   Graph_Graph3->GetXaxis()->CenterTitle(true);
   Graph_Graph3->GetXaxis()->SetLabelFont(42);
   Graph_Graph3->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph3->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph3->GetXaxis()->SetTitleFont(42);
   Graph_Graph3->GetYaxis()->SetTitle("Efficiency");
   Graph_Graph3->GetYaxis()->CenterTitle(true);
   Graph_Graph3->GetYaxis()->SetLabelFont(42);
   Graph_Graph3->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph3->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph3->GetYaxis()->SetTitleFont(42);
   Graph_Graph3->GetZaxis()->SetLabelFont(42);
   Graph_Graph3->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph3->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph3->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph3);
   
   gre->Draw("ap");

  

  TLegend *leg = new TLegend(0.30,0.65,0.70,0.90);
  leg->SetTextSize(0.035);
  leg->SetLineColor(1);
  leg->SetLineStyle(1);
  leg->SetLineWidth(1);
  leg->SetFillColor(0);
  leg->SetBorderSize(0);
  leg->SetHeader("GIF++ test beams 08.2015");
  leg->AddEntry(gre, "Low Resistivity Glass RPC", "p");
  leg->Draw();
}
  canv->Update();
  canv->RedrawAxis();
  canv->GetFrame()->Draw();
  gPad->Print("Eff_22_1970.tex");
  return canv;
}
