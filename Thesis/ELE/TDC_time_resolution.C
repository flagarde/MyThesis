#include "TH1.h"
#include "TH1F.h"

void TDC_time_resolution()
{
  gStyle->SetPaperSize(10.,10.);
  //=========Macro generated from canvas: c1/c1
  //=========  (Thu Feb 11 00:14:00 2016) by ROOT version5.34/21
   TCanvas *c1 = new TCanvas("c1", "c1",147,106,700,500);
   gStyle->SetOptStat(0);
   c1->Range(0.475,-128.4938,1.725,1156.444);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *hnew1 = new TH1F("hnew1","",40,0.6,1.6);
   hnew1->SetBinContent(15,1);
   hnew1->SetBinContent(16,46);
   hnew1->SetBinContent(17,107);
   hnew1->SetBinContent(18,643);
   hnew1->SetBinContent(19,979);
   hnew1->SetBinContent(20,534);
   hnew1->SetBinContent(21,378);
   hnew1->SetBinContent(22,80);
   hnew1->SetBinContent(23,22);
   hnew1->SetEntries(2790);
   hnew1->SetStats(0);
   
   TF1 *PrevFitTMP = new TF1("PrevFitTMP","gaus",0.6,1.6);
   PrevFitTMP->SetFillColor(19);
   PrevFitTMP->SetFillStyle(0);
   PrevFitTMP->SetLineColor(2);
   PrevFitTMP->SetLineWidth(3);
   PrevFitTMP->SetChisquare(163.9371);
   PrevFitTMP->SetNDF(6);
   PrevFitTMP->GetXaxis()->SetLabelFont(42);
   PrevFitTMP->GetXaxis()->SetLabelSize(0.035);
   PrevFitTMP->GetXaxis()->SetTitleSize(0.035);
   PrevFitTMP->GetXaxis()->SetTitleFont(42);
   PrevFitTMP->GetYaxis()->SetLabelFont(42);
   PrevFitTMP->GetYaxis()->SetLabelSize(0.035);
   PrevFitTMP->GetYaxis()->SetTitleSize(0.035);
   PrevFitTMP->GetYaxis()->SetTitleFont(42);
   PrevFitTMP->SetParameter(0,851.9755);
   PrevFitTMP->SetParError(0,21.48564);
   PrevFitTMP->SetParLimits(0,0,0);
   PrevFitTMP->SetParameter(1,1.068337);
   PrevFitTMP->SetParError(1,0.0006605504);
   PrevFitTMP->SetParLimits(1,0,0);
   PrevFitTMP->SetParameter(2,0.03074854);
   PrevFitTMP->SetParError(2,0.0004927518);
   PrevFitTMP->SetParLimits(2,0,0.3168529);
   hnew1->GetListOfFunctions()->Add(PrevFitTMP);
   
   TPaveStats *ptstats = new TPaveStats(0.55,0.70,0.85,0.85,"blNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(0);
   ptstats->SetFillColor(10);
   ptstats->SetLineColor(0);
   ptstats->SetLineWidth(0);
   ptstats->SetTextAlign(12);
   TText *text = ptstats->AddText("TDC time resolution: 30.8 #pm 0.5 ps");
   ptstats->SetTextSize(0.035);
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   hnew1->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(hnew1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hnew1->SetLineColor(ci);
   hnew1->GetXaxis()->SetTitle("Time (ns)");
   hnew1->GetYaxis()->SetTitle("N tests");
   hnew1->GetXaxis()->SetLabelFont(42);
   hnew1->GetXaxis()->SetLabelSize(0.035);
   hnew1->GetXaxis()->SetTitleSize(0.05);
   hnew1->GetXaxis()->SetTitleOffset(0.7);
   hnew1->GetXaxis()->SetTitleFont(42);
   hnew1->GetYaxis()->SetLabelFont(42);
   hnew1->GetYaxis()->SetLabelSize(0.035);
   hnew1->GetYaxis()->SetTitleSize(0.05);
   hnew1->GetYaxis()->SetTitleOffset(0.9);
   hnew1->GetYaxis()->SetTitleFont(42);
   hnew1->GetZaxis()->SetLabelFont(42);
   hnew1->GetZaxis()->SetLabelSize(0.035);
   hnew1->GetZaxis()->SetTitleSize(0.035);
   hnew1->GetZaxis()->SetTitleFont(42);
   hnew1->Draw("");

   TPaveText *pt = new TPaveText(0.1,0.91,0.9,0.98,"nbNDC");
   pt->SetBorderSize(0);
   pt->SetFillColor(10);
   text = pt->AddText("");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
   c1->Draw();
   gPad->Print("TDCTimeResolution.tex");
}
