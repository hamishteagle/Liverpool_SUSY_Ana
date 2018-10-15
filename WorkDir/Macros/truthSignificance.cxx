#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "TH1F.h"
#include "TLatex.h"
#include "TFile.h"
#include "macroFunctions/fileReader.cxx"
#include "macroFunctions/split.cxx"
#include <stdlib.h>//atof
void truthSignificance(){
  
  using namespace std;
  vector<string> lines =  fileReader("Macros/inputTexts/truthfiles_DM.txt");
  vector<string> filterEff_s = fileReader("Macros/inputTexts/filterEff_DM.txt");
  vector<double> filterEff;
  vector<string> xsections_s = fileReader("Macros/inputTexts/xSections_DM.txt");
  vector<double> xsections;
  vector<double> Sbottom;
  vector<double> N2;
  vector<double> N1;
  vector<double>Vect;
  unsigned int  fill_it=0;
  gStyle->SetOptStat(0);

  cout<<"File line size= "<<lines.size()<<endl;
  cout<<"FilterEff line size= "<<filterEff_s.size()<<endl;
  cout<<"Cross Sections size= "<<xsections_s.size()<<endl;
  //Calculating the Background events and scaling to 36.5fb^-1
  TFile * f2= TFile::Open("/hepstore/hteagle/ExclusionInvestigation/mc15_13TeV.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.merge.DAOD_TRUTH1.e3698_p2666/hist-DAOD_TRUTH1.root");
  TH1F *hCounter_Cut1d_f2=(TH1F*)f2->Get("h_Counter_CUTd1_2");
  //  TH1F *hCounter_CUT1d_f2_2=(TH1F*)f2->Get("h_pTDiff_Pair");  
  double BkgSurvivors=hCounter_Cut1d_f2->GetEntries();//+hCounter_CUT1d_f2_2->GetEntries();
  TH1F *hCounter_rawevents_f2=(TH1F*)f2->Get("h_mcWgt");
  double RawEvents=hCounter_rawevents_f2->GetEntries();
  double Lumi = RawEvents/(831.7*1000*0.54);//Bkg filterEff=0.54, Bkg CrossSection = 831.7
  double sfbkg = 36.5/Lumi;
  double Real_Background_Survivors= BkgSurvivors*sfbkg;
  cout<<"Number of real background survivors ="<<Real_Background_Survivors<<endl;
  //Calculating the Background events and scaling to 36.5fb^-1 end

  TH2F *h2_Signif1 = new TH2F("Significance 1","Basic significance calculation",16,300,1100,18,100,1000);
  for (unsigned int i=0; i<lines.size();i++)
    {
      if (lines.size()==filterEff_s.size() && lines.size()==xsections_s.size())
	{
	  cout<<"File line = "<<lines[i]<<endl;
	  filterEff.push_back(atof(filterEff_s[i].c_str()));
	  xsections.push_back(atof(xsections_s[i].c_str()));
	  cout<<"FilterEfficiency= "<<filterEff[i]<<", CrossSections= "<<xsections[i]<<endl;
	  vector<string> masses= split(lines[i].c_str(),"_");
	  cout<<"components= "<<masses[0]<<","<<masses[1]<<","<<masses[2]<<endl;
	  Sbottom.push_back(atof(masses[0].c_str()));
	  N2.push_back(atof(masses[1].c_str()));
	  N1.push_back(atof(masses[2].c_str()));
	  
	  string str1 ="/hepstore/hteagle/ExclusionInvestigation/"+lines[i]+"/hist-DAOD_TRUTH1.root";//Directory 
	  const char *charA = str1.c_str();
	  TFile *f1 =TFile::Open(charA);
	  TH1F *hCounter_Cut1d_f1=(TH1F*)f1->Get("h_Counter_CUTd1_2");
	  //	  TH1F *hCounter_CUT1d_f1_2=(TH1F*)f1->Get("h_pTDiff_Pair");
	  double survivors= hCounter_Cut1d_f1->GetEntries();//+hCounter_CUT1d_f1_2->GetEntries();
	  TH1F *hCounter_rawevents=(TH1F*)f1->Get("h_mcWgt");
	  double Events= hCounter_rawevents->GetEntries();
	  double Lumi1=Events/(xsections[i]*1000*filterEff[i]);
	  double sf = 36.5/Lumi1;
	  cout<<"Events = "<<Events<<", Scaling factor= "<<sf<<" Surviving events = "<<survivors*sf<<endl;
	  
	  double Significance1=(survivors*sf)/sqrt(Real_Background_Survivors + (0.2*Real_Background_Survivors)*(0.2*Real_Background_Survivors)+1);
	  double significance1 = std::round(Significance1 * 100) / 100;//rounding to 2 dp   
	  Vect.push_back(significance1);
	  cout<<"SIGNIFICANCE= "<<Vect[i]<<endl;
	
	  int binx = h2_Signif1->GetXaxis()->FindBin(Sbottom[i]); 
	  int biny = h2_Signif1->GetYaxis()->FindBin(N2[i]);
       
	  if (h2_Signif1->GetBinContent(binx,biny)==0)
	    {
	      h2_Signif1->SetBinContent(binx,biny,((h2_Signif1->GetBinContent(binx,biny))+Vect[i]));
	    }
	  fill_it++;
      	}
      else cout<<"Something wrong with the input files."<<endl;
    }
  
  TCanvas* c1 = new TCanvas("c1","c1",900,900);
  c1->cd();
  //    h2_Signif1->SetTitle("Significance  with constant M(#tilde{N}_{2}^{0}-#tilde{N}_{1}^{0}) - MaxMinimum exclusion analysis;Sbottom mass (GeV);Neutralino 2 Mass (GeV)");
  h2_Signif1->SetTitle("Significance with MaxMin algorithm-Truth Level");
    
  h2_Signif1->GetYaxis()->SetTitleOffset(1.4);
  h2_Signif1->Draw("text;colz");
  
    
    TLatex *Tl= new TLatex();
    Tl->SetTextSize(0.025);
    //    Tl->SetTextAlign(13);
    //    Tl->SetNDC(True);
    Tl->DrawLatex(350, 900,"#int Ldt = 36.1 fb^{-1} #sqrt{s} = 13 TeV");
    Tl->DrawLatex(350, 850,"#it{#bf{ATLAS} Internal}");
    Tl->DrawLatex(350, 800,"#Delta m(#tilde{#chi}_{2}^{0}, #tilde{#chi}_{1}^{0}) = 130 GeV");
    Tl->DrawLatex(350,740,"s=#frac{N_{signal}}{#sqrt{N_{bkg}+0.2N_{bkg}^{2}+1}}");
    
    c1->SaveAs("SummerAnalysis/Summer_Student_Analysis/histograms/Significance_MaxMin.pdf");

  gApplication->Terminate(); 
}
  
