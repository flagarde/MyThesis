{

  TFile *_file0 = TFile::Open("chamber_imon_vmon_save.root");
  gStyle->SetTitleSize(0.05,"XY");
  gStyle->SetTitleOffset(0.55,"Y");
 // TDatime da(2016,8,01,00,00,00);
  //double s=1470009600;
 // gStyle->SetTimeOffset(da.Convert());
 //gStyle->SetTimeOffset(da.Convert());
  vector<string> chambers;
  chambers.push_back("DIF16_LR");
  chambers.push_back("DIF32_HR"); 
  chambers.push_back("DIF216_LR"); 
  chambers.push_back("DIF28_LR"); 
  chambers.push_back("DIF6_LR");


  TCanvas* cnv = new TCanvas("cnv", "",1500,400);



    for (int i = 0; i < 5; i++){
    std::map<double,int>value;
    value.clear();
    cnv->Clear();    
      TGraph* vmon1 = (TGraph*) _file0->Get(Form("Vmon_chamber_%d_%s_att1;1", i+1, chambers[i].c_str()));
      TGraph* imon1 = (TGraph*) _file0->Get(Form("Imon_chamber_%d_%s_att1;1", i+1, chambers[i].c_str()));
      TGraph* vmongt1 = (TGraph*) _file0->Get(Form("Vmon_chamber_%d_%s_attgt1;1", i+1, chambers[i].c_str()));
      TGraph* imongt1 = (TGraph*) _file0->Get(Form("Imon_chamber_%d_%s_attgt1;1", i+1, chambers[i].c_str()));
      TGraph* vmonnoinfo = (TGraph*) _file0->Get(Form("Vmon_chamber_%d_%s_attnoinfo;1", i+1, chambers[i].c_str()));
      TGraph* imonnoinfo = (TGraph*) _file0->Get(Form("Imon_chamber_%d_%s_attnoinfo;1", i+1, chambers[i].c_str()));

      TGraph* att1 = (TGraph*) _file0->Get(Form("Att_chamber_%d_%s_att1;1", i+1, chambers[i].c_str()));
      TGraph* attgt1 = (TGraph*) _file0->Get(Form("Att_chamber_%d_%s_attgt1;1", i+1, chambers[i].c_str()));
      TGraph* attnoinfo = (TGraph*) _file0->Get(Form("Att_chamber_%d_%s_attnoinfo;1", i+1, chambers[i].c_str()));
      TGraph* imon_charge1 = (TGraph*) _file0->Get(Form("Imon_vs_Charge_chamber_%d_%s_att1;1", i+1, chambers[i].c_str()));
      TGraph* imon_chargegt1 = (TGraph*) _file0->Get(Form("Imon_vs_Charge_chamber_%d_%s_attgt1;1", i+1, chambers[i].c_str()));
      TGraph* imon_chargenoinfo = (TGraph*) _file0->Get(Form("Imon_vs_Charge_chamber_%d_%s_attnoinfo;1", i+1, chambers[i].c_str()));

      Double_t imax1 = TMath::MinElement(imon1->GetN(),imon1->GetX());
      Double_t imaxgt1 = TMath::MinElement(imongt1->GetN(),imongt1->GetX());
      Double_t imaxnoinfo = TMath::MinElement(imonnoinfo->GetN(),imonnoinfo->GetX());
      Double_t daymax=140;
      
      Double_t cmax = 0;
      
      TGraph* charge1=new TGraph(imon1->GetN());
      TGraph* chargegt1=new TGraph(imongt1->GetN());
      TGraph* chargenoinfo=new TGraph(imonnoinfo->GetN());
      TGraph* charges1=new TGraph();
      TGraph* chargesgt1=new TGraph();
      TGraph* chargesnoinfo=new TGraph();
      
      
      std::vector<TGraph*>dd={vmon1,imon1,vmongt1,imongt1,vmonnoinfo,imonnoinfo,att1,attgt1,attnoinfo,charge1,chargegt1,chargenoinfo};
      
      
      
      Double_t step=6.10352e-05;
      Double_t stepm=4.57764e-05;
      int yy=1;
      for(Int_t i=1;i!=attnoinfo->GetN();++i)
      {
        Double_t x1;
        Double_t x2;
        attnoinfo->GetPoint(i,x1,x2);
        if(x2==-1)attnoinfo->SetPoint(i,x1,0.5);
      }
      
      for(Int_t i=1;i!=imon1->GetN();++i)
      {
        Double_t x1;
        Double_t x2;
        Double_t y1;
        Double_t y2;
        imon1->GetPoint(i,x1,y1);
        imon_charge1->GetPoint(i,x2,y2);
        if(x2>cmax) cmax=x2;
        charge1->SetPoint(i,x1,x2);
        value[x2]=0;
      }
      
      for(Int_t i=1;i!=imongt1->GetN();++i)
      {
        Double_t x1;
        Double_t x2;
        Double_t y1;
        Double_t y2;
        imongt1->GetPoint(i,x1,y1);
        imon_chargegt1->GetPoint(i,x2,y2);
        if(x2>cmax) cmax=x2;
        chargegt1->SetPoint(i,x1,x2);
        value[x2]=1;
      }
      
      for(Int_t i=1;i!=imonnoinfo->GetN();++i)
      {
        Double_t x1;
        Double_t x2;
        Double_t y1;
        Double_t y2;
        imonnoinfo->GetPoint(i,x1,y1);
        imon_chargenoinfo->GetPoint(i,x2,y2);
        if(x2>cmax) cmax=x2;
        chargenoinfo->SetPoint(i,x1,x2);
        value[x2]=2;
      }
              double one=0;
      double two=0;
        double three=0;
        double totale=0;
        double maxx=0;
      for(std::map<double,int>::iterator it=value.begin();it!=value.end();++it)
      {
        if(it->first>maxx)maxx=it->first;
        if(it->second==0) 
        {
          charges1->SetPoint(one,totale*step,it->first);
          one++;
        }
        else if(it->second==1) 
        {
          chargesgt1->SetPoint(two,totale*step,it->first);
          two++;
        }
        else if(it->second==2) 
        {
          chargesnoinfo->SetPoint(three,totale*step,it->first);
          three++;
        }
        totale++;
        //std::cout<<one<<" "<<two<<" "<<three<<" "<<totale<<std::endl;
      }

     /* for(unsigned int i=0;i!=dd.size();++i)
      {
        //TDatime thedate;
        for(Int_t j=1;j!=dd[i]->GetN();++j)
        {
          Double_t x1;
          Double_t x2;
          dd[i]->GetPoint(j,x1,x2);
          //thedate.Set(s+x1);
          dd[i]->SetPoint(j,da.Convert()+x1,x2);  
          dd[i]->GetPoint(j,x1,x2);
          std::cout<<x1<<std::endl;
        }
      }*/
     /* std::cout<<imon1->GetN()<<"  "<<imongt1->GetN()<<"  "<<imonnoinfo->GetN()<<"  "<<imon_charge1->GetN()<<"  "<<imon_chargegt1->GetN()<<"  "<<imon_chargenoinfo->GetN()<<"  "<<std::endl;*/
           TH1D* iPLOTTER = new TH1D("iPLOTTER", Form(";Days from 1st August. 2016;Current #muA"), 1, 0, daymax);
      iPLOTTER->SetStats(0);
      iPLOTTER->SetMinimum(0.0);
      iPLOTTER->SetMaximum(100.0);
     // iPLOTTER->GetXaxis()->SetTimeDisplay(1);
     // iPLOTTER->GetXaxis()->SetTimeFormat("%d-%m-%y");
      iPLOTTER->GetXaxis()->SetLabelSize(0.05);
      iPLOTTER->GetYaxis()->SetLabelSize(0.05);
      if ( i == 1)iPLOTTER->SetMaximum(20.0);
      iPLOTTER->Draw();
      imon1->SetTitle(Form(";Days from 1st August. 2016;#muA"));
      imon1->SetMarkerStyle(20);
      imon1->SetMarkerSize(0.5); 
      imon1->Draw("P");
      imongt1->SetMarkerStyle(20);
      imongt1->SetMarkerSize(0.5);
      imongt1->SetMarkerColor(kRed);
      imongt1->Draw("P");
      imonnoinfo->SetMarkerStyle(20);
      imonnoinfo->SetMarkerSize(0.5);
      imonnoinfo->SetMarkerColor(kBlue);
      imonnoinfo->Draw("P");
      gPad->Update();
      cnv->SaveAs(Form("./current/%s_1.eps", chambers[i].c_str()));
      cnv->SaveAs(Form("./current/%s_1.png", chambers[i].c_str()));
      iPLOTTER = new TH1D("iPLOTTER", Form(";Days from 1st August. 2016;Current #muA"), 1, 0, daymax);
      iPLOTTER->SetStats(0);
      iPLOTTER->SetMinimum(0.0);
      iPLOTTER->SetMaximum(100.0);
     // iPLOTTER->GetXaxis()->SetTimeDisplay(1);
     // iPLOTTER->GetXaxis()->SetTimeFormat("%d-%m-%y");
      iPLOTTER->GetXaxis()->SetLabelSize(0.05);
      iPLOTTER->GetYaxis()->SetLabelSize(0.05);
      if ( i == 1)iPLOTTER->SetMaximum(20.0);
      iPLOTTER->Draw();
      imon1->SetTitle(Form(";Days from 1st August. 2016;#muA"));
      imon1->SetMarkerStyle(20);
      imon1->SetMarkerSize(0.5); 
      imon1->Draw("P");
      imongt1->SetMarkerStyle(20);
      imongt1->SetMarkerSize(0.5);
      imongt1->SetMarkerColor(kRed);
      imongt1->Draw("P");
      imonnoinfo->SetMarkerStyle(20);
      imonnoinfo->SetMarkerSize(0.5);
      imonnoinfo->SetMarkerColor(kBlue);
      imonnoinfo->Draw("P");
      gPad->Update();
      
            cnv->SaveAs(Form("./current/%s_1.eps", chambers[i].c_str()));
      cnv->SaveAs(Form("./current/%s_1.png", chambers[i].c_str()));
      TH1D* icPLOTTER_CURRENT = new TH1D("icPLOTTER",";Days from 1st August. 2016;Integrated charge (C)", 1, 0, daymax);
      icPLOTTER_CURRENT->SetStats(0);
      icPLOTTER_CURRENT->SetMinimum(0.0);
      icPLOTTER_CURRENT->SetMaximum(maxx+1);
    //  icPLOTTER_CURRENT->GetXaxis()->SetTimeDisplay(1);
    //  icPLOTTER_CURRENT->GetXaxis()->SetTimeFormat("%d-%m-%y");
      icPLOTTER_CURRENT->GetXaxis()->SetLabelSize(0.05);
      icPLOTTER_CURRENT->GetYaxis()->SetLabelSize(0.05);
      if ( i == 1)icPLOTTER->SetMaximum(20.0);
      charge1->SetTitle(";Days from 1st Oct. 2016;Integrated charge (C)");
      icPLOTTER_CURRENT->Draw();
      charge1->SetTitle(" ");
      charge1->SetMarkerStyle(20);
      charge1->SetMarkerSize(0.5); 
      charge1->Draw("P");
      chargegt1->SetMarkerStyle(20);
      chargegt1->SetMarkerSize(0.5);
      chargegt1->SetMarkerColor(kRed);
      chargegt1->Draw("P");
      chargenoinfo->SetMarkerStyle(20);
      chargenoinfo->SetMarkerSize(0.5);
      chargenoinfo->SetMarkerColor(kBlue);
      chargenoinfo->Draw("P");
      gPad->Update();
      
            cnv->SaveAs(Form("./current/%s_2.eps", chambers[i].c_str()));
      cnv->SaveAs(Form("./current/%s_2.png", chambers[i].c_str()));
      TH1D* vPLOTTER = new TH1D("vPLOTTER", Form(";Days from 1st August. 2016;HV (V)"), 1, 0, daymax);
      vmon1->SetTitle(Form(";Days from 1st Oct. 2016;HV (V)"));  
      vPLOTTER->SetStats(0);
      vPLOTTER->SetMinimum(5000.0);
      vPLOTTER->SetMaximum(7500.0);
    //  vPLOTTER->GetXaxis()->SetTimeDisplay(1);
    //  vPLOTTER->GetXaxis()->SetTimeFormat("%d-%m-%y");
      vPLOTTER->GetXaxis()->SetLabelSize(0.05);
      vPLOTTER->GetYaxis()->SetLabelSize(0.05);
      vPLOTTER->Draw();
      vmon1->SetMarkerStyle(20);
      vmon1->SetMarkerSize(0.5);
      vmon1->Draw("P");
      vmongt1->SetMarkerStyle(20);
      vmongt1->SetMarkerSize(0.5);
      vmongt1->SetMarkerColor(kRed);
      vmongt1->Draw("P");
      vmonnoinfo->SetMarkerStyle(20);
      vmonnoinfo->SetMarkerSize(0.5);
      vmonnoinfo->SetMarkerColor(kBlue);
      vmonnoinfo->Draw("P");
      gPad->Update();
      cnv->SaveAs(Form("./current/%s_3.eps", chambers[i].c_str()));
      cnv->SaveAs(Form("./current/%s_3.png", chambers[i].c_str()));
      cnv->SetLogy(1);
      TH1D* aPLOTTER = new TH1D("aPLOTTER", Form(";Days from 1st August. 2016;Attenuator Value"), 1, 0, daymax);
      att1->SetTitle(Form(";Days from 1st Oct. 2016;Attenuator Value"));  
     // aPLOTTER->GetXaxis()->SetTimeDisplay(1);
    //  aPLOTTER->GetXaxis()->SetTimeFormat("%d-%m-%y");
      aPLOTTER->SetStats(0);
      aPLOTTER->SetMinimum(0.5);
      aPLOTTER->SetMaximum(47800);
      aPLOTTER->GetXaxis()->SetLabelSize(0.05);
      aPLOTTER->GetYaxis()->SetLabelSize(0.05);
      aPLOTTER->Draw();
      att1->SetMarkerStyle(20);
      att1->SetMarkerSize(0.5);
      //gPad->SetLogy();
      att1->Draw("P");
      attgt1->SetMarkerStyle(20);
      attgt1->SetMarkerSize(0.5);
      attgt1->SetMarkerColor(kRed);
      attgt1->Draw("P");
      attnoinfo->SetMarkerStyle(20);
      attnoinfo->SetMarkerSize(0.5);
      attnoinfo->SetMarkerColor(kBlue);
      attnoinfo->Draw("P");
gPad->Update();
    
      cnv->SaveAs(Form("./current/%s_4.eps", chambers[i].c_str()));
      cnv->SaveAs(Form("./current/%s_4.png", chambers[i].c_str()));
      cnv->SetLogy(0);
      TH1D* aPLOTTER2 = new TH1D("aPLOTTER2", Form(";Days;Integrated charge (C)"), 1, 0,60);
      att1->SetTitle(Form(";Days;Integrated charge (C)"));  
      aPLOTTER2->SetStats(0);
      aPLOTTER2->SetMinimum(0);
      aPLOTTER2->SetMaximum(maxx+1);
      aPLOTTER2->Draw();
      aPLOTTER2->GetXaxis()->SetLabelSize(0.05);
      aPLOTTER2->GetYaxis()->SetLabelSize(0.05);
      charges1->SetMarkerStyle(20);
      charges1->SetMarkerSize(0.5);
      charges1->Draw("P");
      chargesgt1->SetMarkerStyle(20);
      chargesgt1->SetMarkerSize(0.5);
      chargesgt1->SetMarkerColor(kRed);
      chargesgt1->Draw("P");
      chargesnoinfo->SetMarkerStyle(20);
      chargesnoinfo->SetMarkerSize(0.5);
      chargesnoinfo->SetMarkerColor(kBlue);
      chargesnoinfo->Draw("P");
      gPad->Update();
      cnv->SaveAs(Form("./current/%s_5.eps", chambers[i].c_str()));
      cnv->SaveAs(Form("./current/%s_5.png", chambers[i].c_str()));
      
      delete vmon1;
      delete imon1;
      delete vmongt1;
      delete imongt1;
      delete vmonnoinfo ;
      delete imonnoinfo;

      delete att1;
      delete attgt1 ;
      delete attnoinfo;
      delete imon_charge1 ;
      delete imon_chargegt1 ;
      delete imon_chargenoinfo;

      delete charge1;
      delete chargegt1;
      delete chargenoinfo;
      delete charges1;
      delete chargesgt1;
      delete chargesnoinfo;
      
      
      
    }
}
