
void fit_test()
{
   TCanvas *c1 = new TCanvas("","");
	 std::vector<double>x={25.5,21.5,17.5,13.5,9.5,5.5};
	 std::vector<double>y={3.94,4.28,4.67,5.26,5.65,6.05};
	 c1->cd();
   TGraph* gr = new TGraph(x.size(),&x[0],&y[0]);
   //Change title and axis
	 gr->SetTitle("Along-strip position measurement with iRPC chamber;Average hit position: Distance from the FEB (cm);<#DeltaT> (ns)");
   //Plot
	 gr->Draw();
   //Linear regression fit
	 gr->Fit("pol1","+");
	 TF1 *func=gr->GetFunction("pol1");
	 Double_t p0=func->GetParameter(0);
	 Double_t p1=func->GetParameter(1);
	 Double_t e1=func->GetParError(1);
	 gr->SetLineColorAlpha(0, 0.35);
	 //Change width of plotted line
	 gr->SetLineWidth(2);
	 //Change style of plotted line
	 gr->SetLineStyle(1);
	 //Change color of plotted points
	 gr->SetMarkerColorAlpha(kBlue, 0.35);
	 //Change shape of plotted points
	 gr->SetMarkerStyle(kFullSquare);
	 //Change size of plotted points
	 gr->SetMarkerSize(1);
	 //Fit parameters settings
	 //Show Fit parameters
	 gStyle->SetOptFit(0111);
	 auto stats1 = (TPaveStats*)gr->GetListOfFunctions()->FindObject("stats");
	 //Change color of fit parameters
	 //stats1->SetTextColor(kRed);
	 stats1->SetLineColor(0);
	 //Change width of plotted line
	 gr->SetLineWidth(2);
	 //Change style of plotted line
	 gr->SetLineStyle(1);
	 //Lines' positions of parameters' box in image (corners)
	 stats1->SetX1NDC(0.55); stats1->SetX2NDC(0.85);
	 stats1->SetY1NDC(0.70); stats1->SetY2NDC(0.80);
	 //Fit Line settings
	 func->SetLineColor(kRed);
	 func->SetLineWidth(2);
	 func->SetLineStyle(1);
	 //func->SetLineLimits(5.5,25.5);
	 // CMS flag
	 TLatex text1; 
	 text1.SetTextFont(42); 
	 text1.SetNDC(); 
	 text1.DrawLatex(c1->GetLeftMargin()+ 0.02, 1-c1->GetTopMargin()- 0.06,"#bf{CMS},#scale[0.75]{ #it{Work in progress}}");
	 c1->Draw();
	 c1->SaveAs("toto.tex");
   return c1;
} 
