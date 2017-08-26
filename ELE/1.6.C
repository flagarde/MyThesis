#include "TH1.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TFrame.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TROOT.h"
#include "TGraphErrors.h"
#include <map>
#include <utility>



class DrawSomething
{
  int W,H;
  int H_ref;
  int W_ref;
  float T,B,L,R;

 
  int iPeriod,iPos;

  TString canvName;
  TCanvas *canv;
  TLegend *leg;
  float leg_xmin,leg_xmax,leg_ymin,leg_ymax;
  void setCanvName(const char *text);
  void makeCanva();
  void makeLegend(const char *header);
  void setGraphAxis(TGraph* gr);

public:
  DrawSomething();
  std::map<int,double>Value;
std::map<int,double>Errors;
  void setLegendCoord(float xmin,float ymin, float xmax, float ymax) {leg_xmin=xmin; leg_ymin=ymin; leg_xmax=xmax; leg_ymax=ymax;}
  void beginCanva(const char* text, const char* legendHeader, int Width=800, int Height=600);
  void drawFake(float xmax, float ymax);
  void addGraph(TGraph* gre,const char *legEntry,double HVstart,double HVend,Int_t color,bool drawAxes=false); //works also for TGraphError
  void finalizeCanva();
  
};


DrawSomething::DrawSomething()
{
  H_ref = 600; 
  W_ref = 800; 
  // references for T, B, L, R
  T = 0.08*H_ref;
  B = 0.12*H_ref; 
  L = 0.12*W_ref;
  R = 0.04*W_ref;


  canv=NULL;  
  leg=NULL;

  //leg = new TLegend(
  leg_xmin=0.15;
  leg_ymin=0.65;
  leg_xmax=0.45;
  leg_ymax=0.90;
  
}


void DrawSomething::beginCanva(const char* text, const char* legendHeader, int Width, int Height)
{
  W=Width;
  H=Height;
  setCanvName(text);
  makeCanva();
  makeLegend(legendHeader);
}

void DrawSomething::setCanvName(const char *text)
{
  canvName = text;
  canvName += "-";
  canvName += W;
  canvName += "-";
  canvName += H;
  canvName += "_";  
}

void DrawSomething::makeCanva()
{
  canv = new TCanvas(canvName,canvName,50,50,W,H);
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
}

void DrawSomething::setGraphAxis(TGraph* gr)
{
   gr->GetXaxis()->SetTitle("High Voltage (V)");
   gr->GetXaxis()->CenterTitle(true);
   gr->GetXaxis()->SetLabelFont(42);
   gr->GetXaxis()->SetLabelSize(0.05);
   gr->GetXaxis()->SetTitleSize(0.05);
   gr->GetXaxis()->SetTitleFont(42);
   gr->GetXaxis()->SetTitleOffset(1.0);
   gr->GetYaxis()->SetTitle("Current (#muA)");
   gr->GetYaxis()->SetTitleOffset(1.0);
   gr->GetYaxis()->CenterTitle(true);
   gr->GetYaxis()->SetLabelFont(42);
   gr->GetYaxis()->SetLabelSize(0.05);
   gr->GetYaxis()->SetTitleSize(0.05);
   gr->GetYaxis()->SetTitleFont(42);
}


void DrawSomething::drawFake(float xmax, float ymax)
{
  TGraph*  gr_fake=new TGraph(2);
  gr_fake->SetMarkerStyle(1);
  gr_fake->SetLineColor(0);
  gr_fake->SetMarkerColor(0);
  gr_fake->SetPoint(0,0,0);
  gr_fake->SetPoint(1,xmax,ymax);
  setGraphAxis(gr_fake);
  gr_fake->Draw("ap");
}

void DrawSomething::makeLegend(const char *header)
{
  leg = new TLegend(leg_xmin,leg_ymin,leg_xmax,leg_ymax);
  leg->SetTextSize(0.035);
  leg->SetLineColor(1);
  leg->SetLineStyle(1);
  leg->SetLineWidth(1);
  leg->SetFillColor(0);
  leg->SetBorderSize(0);
  leg->SetHeader(header);
}


void DrawSomething::addGraph(TGraph* gre,const char *legEntry,double HVstart,double HVend,Int_t color, bool drawAxes)
{
  static int toto=0;
  if(HVend!=0&&HVstart!=0)
  {
  TF1 *f1 = new TF1("f1","[0]*x+[1]",HVstart,HVend);
  f1->SetParameter(0,11.5);
  f1->SetParName(0,"1/R");
  f1->SetParameter(1,100);
  f1->SetParName(1,"cst");
  f1->SetLineColor(color);
  gre->Fit("f1","REWWM");
  Value.insert(std::pair<int,double>(toto,double(f1->GetParameter(0))));
  Errors.insert(std::pair<int,double>(toto,double(f1->GetParError(0))));
  std::cout<<"**************"<<toto<<"  "<<f1->GetParameter(0)<<"    "<<Value[toto]<<"   "<<f1->GetParError(0)<<"  "<<double(f1->GetParError(0))<<endl;
  toto++;
  }
  gre->SetFillColor(1);
  if (drawAxes) gre->Draw("ap"); 
  else gre->Draw("p"); 
  if (NULL != legEntry) leg->AddEntry(gre, legEntry, "p");
}

void DrawSomething::finalizeCanva()
{
  leg->Draw();
  
  canv->Update();
  canv->RedrawAxis();
  canv->GetFrame()->Draw();
  gPad->Print(canvName+".tex");
}



//The various data
float HVTOP[30]={100,1000,1500,2000,2500,3000,3500,4000,4500,5000,5500,6000,6500,
7000,7500,7600,7700,7800,7900,8000,8100,8200,8300,8400,8500,8600,8700,8800,8900,9000};

float TOP[30]={ 0,0,0,0,0,0,0,0,0,0,0,0,0
, 0.031400966183574575
, 0.07971014492753614
, 0.08937198067632846
, 0.10869565217391308
, 0.13768115942028958
, 0.1280193236714977
, 0.19565217391304346
, 0.26328502415458876
, 0.3405797101449277
, 0.4565217391304346
, 0.5821256038647338
, 0.6787439613526569
, 0.8816425120772946
, 1.28743961352657
, 1.6739130434782608
, 2.0990338164251208
, 3.1811594202898554
};

float HVBOTTOM[30]={100,1000,1500,2000,2500,3000,3500,4000,4500,5000,5500,6000,6500,
7000,7500,7600,7700,7800,7900,8000,8100,8200,8300,8400,8500,8600,8700,8800,8900,9000};

float BOTTOM[30]=
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0.04106280193236689,
0.07971014492753614,
0.10869565217391308,
0.1473429951690819,
0.20
, 0.26328502415458876
, 0.2922705314009657
, 0.35990338164251234
, 0.4178743961352658
, 0.5724637681159415
, 0.669082125603865
, 0.833333333333333
, 1.123188405797101
, 1.4420289855072461
, 1.9927536231884058
, 2.8429951690821254       // 22
  };





struct measurements
{
  int june15_markerStyle;
  int june15max_markerStyle;
  int june16ggup_markerStyle;
  int june16ggdown_markerStyle;
  Int_t chamber1_ColorIndex;
  Int_t chamber2_ColorIndex;
  Int_t chamber4_ColorIndex;
  Int_t chamber5_ColorIndex;


  TGraph* gr_TOP;
  TGraph* gr_BOTTOM;
  measurements(); 
};

measurements::measurements()
{
  june15_markerStyle=25; // open square
  june15max_markerStyle=24; // open circle
  june16ggup_markerStyle=26; // open triangle up
  june16ggdown_markerStyle=28; // open cross
  chamber1_ColorIndex=TColor::GetColor("#0000ff");
  chamber2_ColorIndex=TColor::GetColor("#00ff00");
  chamber4_ColorIndex=TColor::GetColor("#ff0000");
  chamber5_ColorIndex=TColor::GetColor("#00ffff");



  gr_TOP=new TGraph(30);
  gr_TOP->SetName("Graph1ggJune15");
  gr_TOP->SetTitle("");
  gr_TOP->SetLineColor(1);
  gr_TOP->SetMarkerColor(1);
  gr_TOP->SetMarkerStyle(21);
  for (int i=0; i<30; ++i) gr_TOP->SetPoint(i,HVTOP[i],TOP[i]);
  
  gr_BOTTOM=new TGraph(30);
  gr_BOTTOM->SetName("Graph1ggJune15");
  gr_BOTTOM->SetTitle("");
  gr_BOTTOM->SetLineColor(2);
  gr_BOTTOM->SetMarkerColor(2);
  gr_BOTTOM->SetMarkerStyle(22);
  for (int i=0; i<30; ++i) gr_BOTTOM->SetPoint(i,HVBOTTOM[i],BOTTOM[i]);
 }


 
void myMacro()
{
 gStyle->SetPaperSize(10.,10.);
//gStyle->SetOptFit(1);
  measurements A;
  
  DrawSomething D;
  D.beginCanva("","");
  D.drawFake(10000,3.5);
  TString a;
  //a.Form("chamber 1, June 15 11 pm; 1/R=%f +-%f",0.0200333,0.000611052); 
  D.addGraph(A.gr_TOP,"Bakelite 1.6/1.6 TOP",0,0,1);
  //D.addGraph(A.gr_TOP,a.Data(),8500,9200,1);
  //a.Form("chamber 2, June 15 11 pm; 1/R=%f +-%f",0.00208525,1.57698e-05); 
  D.addGraph(A.gr_BOTTOM,"Bakelite 1.6/1.6 BOTTOM",0,0,2);
  //D.addGraph(A.gr_BOTTOM,a.Data(),8500,9200,2);
  //for(std::map<int,double>::iterator it=D.Value.begin();it!=D.Value.end();++it) std::cout<<"rrrrrr"<<it->first<<"  "<<it->second<<std::endl;
  D.finalizeCanva();
gPad->Print("Current3.tex");
gPad->Print("Current3.pdf");


}

