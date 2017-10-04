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

   TGraphErrors *gre = new TGraphErrors(21);
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
   gre->SetPoint(0,0.1428571,0.873786);
   gre->SetPointError(0,0,0.0247525);
   gre->SetPoint(1,0.2571429,0.857143);
   gre->SetPointError(1,0,0.0381802);
   gre->SetPoint(2,0.3142857,0.856757);
   gre->SetPointError(2,0,0.0113599);
   gre->SetPoint(3,0.3714286,0.875);
   gre->SetPointError(3,0,0.0245145);
   gre->SetPoint(4,0.5428572,0.895161);
   gre->SetPointError(4,0,0.0205606);
   gre->SetPoint(5,0.6,0.835616);
   gre->SetPointError(5,0,0.0474534);
   gre->SetPoint(6,0.6,0.835616);
   gre->SetPointError(6,0,0.0474534);
   gre->SetPoint(7,0.9,0.875752);
   gre->SetPointError(7,0,0.0157796);
   gre->SetPoint(8,1.15,0.891234);
   gre->SetPointError(8,0,0.0132879);
   gre->SetPoint(9,1.4,0.883249);
   gre->SetPointError(9,0,0.0140552);
   gre->SetPoint(10,1.525,0.83878);
   gre->SetPointError(10,0,0.0187414);
   gre->SetPoint(11,1.775,0.857671);
   gre->SetPointError(11,0,0.0162199);
   gre->SetPoint(12,2.025,0.85447);
   gre->SetPointError(12,0,0.0173942);
   gre->SetPoint(13,2.275,0.845763);
   gre->SetPointError(13,0,0.0161685);
   gre->SetPoint(14,2.525,0.8);
   gre->SetPointError(14,0,0.019245);
   gre->SetPoint(15,3.15,0.804286);
   gre->SetPointError(15,0,0.016721);
   gre->SetPoint(16,3.775,0.739206);
   gre->SetPointError(16,0,0.0212232);
   gre->SetPoint(17,4.4,0.647362);
   gre->SetPointError(17,0,0.0213037);
   gre->SetPoint(18,5.025,0.592593);
   gre->SetPointError(18,0,0.0210665);
   gre->SetPoint(19,5.65,0.350529);
   gre->SetPointError(19,0,0.0293102);
   gre->SetPoint(20,6.275,0.0526316);
   gre->SetPointError(20,0,0.0394737);
   
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

  

  TLegend *leg = new TLegend(0.30,0.35,0.70,0.50);
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
  gPad->Print("hpx.tex");
  return canv;
}
