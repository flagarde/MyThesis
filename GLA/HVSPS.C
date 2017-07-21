//example of macro illustrating how to superimpose two histograms
#include "TCanvas.h"
#include "TStyle.h"
#include "TH1.h"
#include "TGaxis.h"

void plot2()
{
   gROOT->Reset();
   gStyle->SetPaperSize(10.,10.);
   TCanvas*c1 = new TCanvas("c1","gerrors2",200,10,700,500);
   TPad *pad = new TPad("pad","",0,0,1,1);
   pad->SetFillColor(0);
   pad->SetGrid();
   pad->Draw();
   pad->cd();
  
      // draw a frame to define the range
   TH1F *hr = c1->DrawFrame(5380,1,7520,4);
   hr->GetYaxis()->SetLabelOffset(99);
   pad->GetFrame()->SetFillColor(0);
   pad->GetFrame()->SetBorderSize(12);
   pad->GetFrame()->Draw("AH");
   
      // create first graph
   TGraphErrors *gr1 = new TGraphErrors(20);
   gr1->GetYaxis()->SetLabelOffset(99);
   gr1->SetName("Graph0");
   gr1->SetTitle("");
   gr1->SetFillColor(1);
   gr1->SetLineColor(4);
   gr1->SetMarkerColor(4);
   gr1->SetMarkerStyle(21);
   gr1->SetPoint(0,5400,1.13313);
   gr1->SetPointError(0,0,0);
   gr1->SetPoint(1,5500,1.09136);
   gr1->SetPointError(1,0,0);
   gr1->SetPoint(2,5600,1.13001);
   gr1->SetPointError(2,0,0);
   gr1->SetPoint(3,5700,1.20645);
   gr1->SetPointError(3,0,0);
   gr1->SetPoint(4,5800,1.28269);
   gr1->SetPointError(4,0,0);
   gr1->SetPoint(5,5900,1.36188);
   gr1->SetPointError(5,0,0);
   gr1->SetPoint(6,6000,1.45264);
   gr1->SetPointError(6,0,0);
   gr1->SetPoint(7,6100,1.54098);
   gr1->SetPointError(7,0,0);
   gr1->SetPoint(8,6200,1.63157);
   gr1->SetPointError(8,0,0);
   gr1->SetPoint(9,6300,1.74623);
   gr1->SetPointError(9,0,0);
   gr1->SetPoint(10,6400,1.84249);
   gr1->SetPointError(10,0,0);
   gr1->SetPoint(11,6500,1.97674);
   gr1->SetPointError(11,0,0);
   gr1->SetPoint(12,6600,2.10343);
   gr1->SetPointError(12,0,0);
   gr1->SetPoint(13,6700,2.26613);
   gr1->SetPointError(13,0,0);
   gr1->SetPoint(14,6800,2.45509);
   gr1->SetPointError(14,0,0);
   gr1->SetPoint(15,7000,2.91188);
   gr1->SetPointError(15,0,0);
   gr1->SetPoint(16,7100,3.10152);
   gr1->SetPointError(16,0,0);
   gr1->SetPoint(17,7300,3.44235);
   gr1->SetPointError(17,0,0);
   gr1->SetPoint(18,7400,3.56932);
   gr1->SetPointError(18,0,0);
   gr1->SetPoint(19,7500,3.66958);
   gr1->SetPointError(19,0,0);
   gr1->SetMarkerColor(kBlue);
   gr1->SetMarkerStyle(21);
   gr1->Draw("P");

      // create second graph
   
   //create a transparent pad drawn on top of the main pad
   c1->cd();
   TPad *overlay = new TPad("overlay","",0,0,1,1);
   overlay->SetFillStyle(000);
   overlay->SetFillColor(0);
   overlay->SetFrameFillStyle(000);
   overlay->Draw();
   overlay->cd();
   TGraphErrors *gre2 = new TGraphErrors(20);
   gre2->SetName("Graph1");
   gre2->SetTitle("");
   gre2->SetFillColor(1);
   gre2->SetLineColor(4);
   gre2->SetMarkerColor(4);
   gre2->SetMarkerStyle(21);
   gre2->SetPoint(0,5400,0.0296809);
   gre2->SetPointError(0,0,0.00536924);
   gre2->SetPoint(1,5500,0.104536);
   gre2->SetPointError(1,0,0.00479461);
   gre2->SetPoint(2,5600,0.214692);
   gre2->SetPointError(2,0,0.00493778);
   gre2->SetPoint(3,5700,0.347853);
   gre2->SetPointError(3,0,0.00441103);
   gre2->SetPoint(4,5800,0.470752);
   gre2->SetPointError(4,0,0.00395922);
   gre2->SetPoint(5,5900,0.579752);
   gre2->SetPointError(5,0,0.00351478);
   gre2->SetPoint(6,6000,0.686489);
   gre2->SetPointError(6,0,0.00304552);
   gre2->SetPoint(7,6100,0.780909);
   gre2->SetPointError(7,0,0.00250754);
   gre2->SetPoint(8,6200,0.85262);
   gre2->SetPointError(8,0,0.00204301);
   gre2->SetPoint(9,6300,0.900056);
   gre2->SetPointError(9,0,0.00171959);
   gre2->SetPoint(10,6400,0.929143);
   gre2->SetPointError(10,0,0.00144666);
   gre2->SetPoint(11,6500,0.94844);
   gre2->SetPointError(11,0,0.0011455);
   gre2->SetPoint(12,6600,0.960287);
   gre2->SetPointError(12,0,0.00108286);
   gre2->SetPoint(13,6700,0.969078);
   gre2->SetPointError(13,0,0.000964429);
   gre2->SetPoint(14,6800,0.973713);
   gre2->SetPointError(14,0,0.000881638);
   gre2->SetPoint(15,7000,0.978582);
   gre2->SetPointError(15,0,0.00100408);
   gre2->SetPoint(16,7100,0.977462);
   gre2->SetPointError(16,0,0.00123136);
   gre2->SetPoint(17,7300,0.976827);
   gre2->SetPointError(17,0,0.00158039);
   gre2->SetPoint(18,7400,0.976739);
   gre2->SetPointError(18,0,0.00159381);
   gre2->SetPoint(19,7500,0.975994);
   gre2->SetPointError(19,0,0.00186321);
   gre2->SetMarkerColor(kRed);
   gre2->SetMarkerStyle(20);
   gre2->SetName("gr2");
   Double_t xmin = pad->GetUxmin();
   Double_t ymin = 0;
   Double_t xmax = pad->GetUxmax();
   Double_t ymax = 1;
   TH1F *hframe = overlay->DrawFrame(xmin,ymin,xmax,ymax);
  hframe->GetYaxis()->SetLabelSize(0);
   hframe->GetXaxis()->SetLabelSize(0);
  // hframe->Draw("A");
      hframe->GetXaxis()->CenterTitle();
   hframe->SetXTitle("Applied HV(V)");
   gre2->Draw("P");
   hframe->GetYaxis()->SetTickLength(0);
   hframe->GetYaxis()->SetLabelOffset(99); 
   gre2->GetYaxis()->SetLabelOffset(99);
   //Draw an axis on the right side
   TGaxis *axis = new TGaxis(xmin,ymin,xmin, ymax,ymin,ymax,510,"-R");
   axis->SetLineColor(kRed);
   axis->SetLabelColor(kRed);
   axis->SetTitleColor(kRed);
   axis->SetTitle("#mu detection efficiency");

   axis->CenterTitle();
   axis->Draw();
    TGaxis *axis2 = new TGaxis(xmax,ymin,xmax, ymax,1,4,510,"+L");
   axis2->SetLineColor(kBlue);
   axis2->SetLabelColor(kBlue);
   axis2->SetTitleColor(kBlue);
   axis2->SetTitle("Cluster size");

   axis2->CenterTitle();
   axis2->Draw();
    TLatex *   tex = new TLatex(0.96,0.936," ");
tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetTextFont(42);
   tex->SetTextSize(0.048);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.12,0.892,"Preliminary");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextFont(52);
   tex->SetTextSize(0.048);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.12,0.851872,"Gas mixture : 93% TFE, 5%CO_{2}, 2%SF_{6}");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextFont(52);
   tex->SetTextSize(0.036);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.12,0.811744,"Threshold : 0.13pC");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextFont(52);
   tex->SetTextSize(0.036);
   tex->SetLineWidth(2);
   tex->Draw();
 
   TLegend *leg = new TLegend(0.55,0.15,0.75,0.25,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg-> SetNColumns(2);
   leg->SetTextSize(0.036);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   leg-> SetNColumns(4);
   TLegendEntry *entry=leg->AddEntry("NULL","SPS test beams 06.2015","h");
   
   entry=leg->AddEntry("Graph0",",","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(4);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph1","Low resistive glass RPC - 10^{10} #Omega.cm","p");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(2);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   c1->SaveAs("hpx.tex");
}




