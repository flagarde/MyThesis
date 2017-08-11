void plot()
{
//=========Macro generated from canvas: Canvas_1/Canvas_1
//=========  (Sat Feb 13 12:46:08 2016) by ROOT version5.34/32
gStyle->SetPaperSize(10.,10.);
   TCanvas *Canvas_1 = new TCanvas("Canvas_1", "Canvas_1",0,23,1366,720);
   Canvas_1->Range(5.951162,-0.1596491,7.449937,1.423158);
   Canvas_1->SetFillColor(0);
   Canvas_1->SetBorderMode(0);
   Canvas_1->SetBorderSize(2);
   Canvas_1->SetTopMargin(0.0778098);
   Canvas_1->SetFrameBorderMode(0);
   Canvas_1->SetFrameBorderMode(0);
   
   TGraph *graph = new TGraph(6);
   graph->SetName("Graph0");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   graph->SetMarkerColor(ci);
   graph->SetMarkerStyle(20);
   graph->SetMarkerSize(1.5);
   graph->SetPoint(0,6.2005,0.1505);
   graph->SetPoint(1,6.4005,0.3755);
   graph->SetPoint(2,6.5995,0.8105);
   graph->SetPoint(3,6.7995,0.9005);
   graph->SetPoint(4,6.9995,0.9505);
   graph->SetPoint(5,7.1995,0.9475);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","Graph",100,6.1006,7.2994);
   Graph_Graph1->SetMinimum(0);
   Graph_Graph1->SetMaximum(1.3);
   Graph_Graph1->SetDirectory(0);
   Graph_Graph1->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1->SetLineColor(ci);
   Graph_Graph1->SetMarkerColor(4);
   Graph_Graph1->SetMarkerStyle(21);
   Graph_Graph1->SetMarkerSize(0.4);
   Graph_Graph1->GetXaxis()->SetTitle("Applied HV(kV)");
   Graph_Graph1->GetXaxis()->CenterTitle(true);
   Graph_Graph1->GetXaxis()->SetLabelFont(42);
   Graph_Graph1->GetXaxis()->SetLabelSize(0.05);
   Graph_Graph1->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph1->GetXaxis()->SetTitleFont(42);
   Graph_Graph1->GetYaxis()->SetTitle("#mu detection efficiency");
   Graph_Graph1->GetYaxis()->CenterTitle(true);
   Graph_Graph1->GetYaxis()->SetLabelFont(42);
   Graph_Graph1->GetYaxis()->SetLabelSize(0.05);
   Graph_Graph1->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph1->GetYaxis()->SetTitleFont(42);
   Graph_Graph1->GetZaxis()->SetLabelFont(42);
   Graph_Graph1->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph1);
   
   graph->Draw("ap");
   
   graph = new TGraph(11);
   graph->SetName("Graph1");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetMarkerStyle(21);
   graph->SetMarkerSize(1.5);
   graph->SetPoint(0,6.0995,0.0065);
   graph->SetPoint(1,6.2005,0.0455);
   graph->SetPoint(2,6.2995,0.1875);
   graph->SetPoint(3,6.4005,0.3605);
   graph->SetPoint(4,6.4995,0.5785);
   graph->SetPoint(5,6.5995,0.6625);
   graph->SetPoint(6,6.7005,0.9025);
   graph->SetPoint(7,6.7995,0.9405);
   graph->SetPoint(8,6.9005,0.9505);
   graph->SetPoint(9,6.9995,0.9815);
   graph->SetPoint(10,7.0995,0.9705);
   
   TH1F *Graph_Graph2 = new TH1F("Graph_Graph2","Graph",100,5.9995,7.1995);
   Graph_Graph2->SetMinimum(0);
   Graph_Graph2->SetMaximum(1.079);
   Graph_Graph2->SetDirectory(0);
   Graph_Graph2->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph2->SetLineColor(ci);
   Graph_Graph2->GetXaxis()->SetLabelFont(42);
   Graph_Graph2->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph2->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph2->GetXaxis()->SetTitleFont(42);
   Graph_Graph2->GetYaxis()->SetLabelFont(42);
   Graph_Graph2->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph2->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph2->GetYaxis()->SetTitleFont(42);
   Graph_Graph2->GetZaxis()->SetLabelFont(42);
   Graph_Graph2->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph2->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph2->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph2);
   
   graph->Draw("p");
   
   TPaveText *pt = new TPaveText(0.4489552,0.9303535,0.5510448,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   pt->Draw();
   TLine *line = new TLine(6.1,1,7.3,1);
   line->SetLineStyle(2);
   line->Draw();
   
   TLegend *leg = new TLegend(0.478739,0.1224784,0.7785924,0.2723343,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(62);
   leg->SetTextSize(0.035);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Graph1","CMS Geometry GRPC mechanical fixation","P");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1.5);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph0","CMS Geometry GRPC glued","P");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#ff0000");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1.5);
   entry->SetTextFont(62);
   leg->Draw();
   TLatex *   tex = new TLatex(0.96,0.936," ");
tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetTextFont(42);
   tex->SetTextSize(0.048);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.1722,0.892,"Preliminary");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextFont(52);
   tex->SetTextSize(0.0456);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.1722,0.851872,"Gas mixture : 93% TFE, 5%CO_{2}, 2%SF_{6}");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextFont(52);
   tex->SetTextSize(0.0264);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.1722,0.811744,"Threshold : 0.13pC");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextFont(52);
   tex->SetTextSize(0.0264);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.1722,0.771616,"Cosmic #mu");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextFont(52);
   tex->SetTextSize(0.0264);
   tex->SetLineWidth(2);
   tex->Draw();
   
   pt = new TPaveText(0.05718475,0.795389,0.09457478,0.9005764,"nbNDC");
   pt->SetFillColor(10);
   pt->SetLineColor(10);
   pt->Draw();
   Canvas_1->Modified();
   Canvas_1->cd();
   Canvas_1->SetSelected(Canvas_1);
     gPad->Print("hpx.tex");
}
