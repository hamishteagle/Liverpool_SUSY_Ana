void mDifference(){
#include "TFile.h"
#include "TTree.h"

  using namespace std;


  TFile *f1 = TFile::Open("/scratch/hteagle/recoSamples/ttbar_HT.root");
  //  TFile *f2 = TFile::Open("/scratch/hteagle/recoSamples/signal/user.janders.27Oct_SUSY7v1.390218.MGPy8EG_A14N23LO_BB_onestepN2hN1_700_695_60_outputntuple.root");
  //  TFile *f2 = TFile::Open("/scratch/hteagle/recoSamples/newVariables/signal/user.janders.27Oct_SUSY7v1.390283.MGPy8EG_A14N23LO_BB_onestepN2hN1_700_480_350_outputntuple.root");
  //TFile *f2 = TFile::Open("/scratch/hteagle/recoSamples/signal/user.janders.27Oct_SUSY7v1.390151.MGPy8EG_A14N23LO_BB_onestepN2hN1_700_250_60_outputntuple.root");
  //TFile *f2 = TFile::Open("/scratch/hteagle/recoSamples/signal/user.janders.27Oct_SUSY7v1.390271.MGPy8EG_A14N23LO_BB_onestepN2hN1_600_530_400_outputntuple.root");
  //TFile *f2 = TFile::Open("/scratch/hteagle/recoSamples/signal/user.janders.27Oct_SUSY7v1.390263.MGPy8EG_A14N23LO_BB_onestepN2hN1_600_131_1_outputntuple.root");
  //TFile *f2 = TFile::Open("/scratch/hteagle/recoSamples/newVariables/signal/user.janders.27Oct_SUSY7v1.390299.MGPy8EG_A14N23LO_BB_onestepN2hN1_800_680_550_outputntuple.root");
  //TFile *f2 = TFile::Open("/scratch/hteagle/recoSamples/newVariables/signal/user.janders.27Oct_SUSY7v1.390297.MGPy8EG_A14N23LO_BB_onestepN2hN1_800_480_350_outputntuple.root");
  TFile *f2 = TFile::Open("/scratch/hteagle/recoSamples/newVariables/signal/user.janders.27Oct_SUSY7v1.390293.MGPy8EG_A14N23LO_BB_onestepN2hN1_800_131_1_outputntuple.root");

  
  if(f1==0)
    {cout<<"Couldn't find input file"<<endl;
      gApplication->Terminate();
    }
  gStyle->SetOptStat(0);  
  
  

  TTree *ttbarTree =(TTree*)f1->Get("CollectionTree_");
  TTree *CollectionTree = (TTree*)f2->Get("CollectionTree_");



  std::string preselection = /**(ETMiss>250 &&*/ "*(nBJets>=4 && nBaselineLeptons==0 && pTb1>80 && (dPhij1MET>0.4 && dPhij2MET>0.4 && dPhij3MET>0.4 && dPhij4MET>0.4) && (( mcID == 410013 && truthFilterMET < 200) || (mcID == 410014 && truthFilterMET < 200) || (mcID == 410000 && truthFilterHT < 600) || (mcID == 407009 && truthFilterHT > 600 && truthFilterHT < 1000) || (truthFilterHT > 1000 && truthFilterHT < 1500 && mcID == 407010) || (mcID == 407011 && truthFilterHT > 1500) || (mcID != 410013 && mcID != 410014 && mcID != 410000 && mcID != 407009 && mcID != 407010 && mcID != 407011)))";  
  
  std::string luminosity = "36.1*JVTSF*electronTriggerSF*muonSF*electronSF*puWgt*finalXSectScale*mcEventWeight*bJetSF";
  
  //  std::string cuts = "*(((minDR_b1<2 && minDR_b2<2) && (mbb1_2_avg<145 && mbb1_2_avg>95))||((minDR_b2>2 || minDR_b2>2)  && mbb1<145 && mbb1>95))";
  std::string cuts = "*(((minDR_b1<2 && minDR_b2<2) && (mbb1_2_avg<145 && mbb1_2_avg>95)))";
  std::string cuts_DR_2 = "*(minDR_b1<2 && minDR_b2<2)";
  std::string cuts_mDiff_0_7 = "*((mDiff_minDR_pairs<0.7) && (mbb1_2_avg<145 && mbb1_2_avg>95)";
  std::string cuts_Mon_alg = "*(((minDR_b1<2 && minDR_b2<2)&& (mbb1_2_avg<145 && mbb1_2_avg>95))||(minDR_b2>2 && mbb1<145 && mbb1>95))";
  std::string cuts_Mon_alg2= "*(((minDR_b1<2 && minDR_b2<2)&& (mbb1_2_avg<145 && mbb1_2_avg>95))||(minDR_b1<2 && minDR_b2>2 && mbb1<145 && mbb1>95))";
  std::string cuts_Mon_alg3="*(((minDR_b1<2 && minDR_b2<2)&& (mbb1_2_avg<145 && mbb1_2_avg>95))||(minDR_b1<2 && minDR_b2>2 && mbb1<145 && mbb1>95)||(minDR_b2>2 && mbb1<145 && mbb1>95))";
  std::string cuts_MaxMin = "*(minDR<2 && InvMass_Bij_minR>95 && InvMass_Bij_minR<145)";

  std::string cutsToUse = luminosity+preselection+cuts;//+cuts_MaxMin;
  std::string cutsToUse_MaxMin = luminosity+preselection+cuts_MaxMin;
  std::string cutsToUse_Mon_alg = luminosity+preselection+cuts_Mon_alg;
  std::string cutsToUse_Mon_alg2 = luminosity+preselection+cuts_Mon_alg2;
  std::string cutsToUse_Mon_alg3 = luminosity+preselection+cuts_Mon_alg3;
  const char *cutstouse = cutsToUse.c_str();
  const char *cutstouse_MaxMin=cutsToUse_MaxMin.c_str();
  const char *cutstouse_Mon_alg=cutsToUse_Mon_alg.c_str();
  const char *cutstouse_Mon_alg2=cutsToUse_Mon_alg2.c_str();
  const char *cutstouse_Mon_alg3=cutsToUse_Mon_alg3.c_str();
  
  TH1F *mDiff_f1_noCuts= new TH1F("mDiff_f1_count","mDiff_f1_count",10,0,1);
  CollectionTree->Draw("1 >> mDiff_f1_count","","goff");
  cout<<"Number of (raw mc) events for signal (No selections) = "<<mDiff_f1_noCuts->GetEntries()<<endl;

  TH1F *mDiff_f2_noCuts= new TH1F("mDiff_f2_count","mDiff_f2_count",10,0,1);
  ttbarTree->Draw("1 >> mDiff_f2_count","","goff");
  cout<<"Number of (raw mc) events for bkg (No selecitons)= "<<mDiff_f2_noCuts->GetEntries()<<endl;

  TH1F *mDiff_f1_count= new TH1F("mDiff_f1_count","mDiff_f1_count",10,0,1);
  CollectionTree->Draw("1 >> mDiff_f1_count",cutstouse,"goff");
  cout<<"Number of (raw mc) events for signal DR<2 alg= "<<mDiff_f1_count->GetEntries()<<endl;
  TH1F *mDiff_f2_count= new TH1F("mDiff_f2_count","mDiff_f2_count",10,0,1);
  ttbarTree->Draw("1 >> mDiff_f2_count",cutstouse,"goff");
  cout<<"Number of (raw mc) events for bkg DR<2 alg = "<<mDiff_f2_count->GetEntries()<<endl;

  TH1F *mDiff_f1_count_MaxMin= new TH1F("mDiff_f1_count_MaxMin","mDiff_f1_count_MaxMin",10,0,1);
  CollectionTree->Draw("1 >> mDiff_f1_count_MaxMin",cutstouse_MaxMin,"goff");
  cout<<"Number of (raw mc) events for signal (MaxMin)= "<<mDiff_f1_count_MaxMin->GetEntries()<<endl;
  TH1F *mDiff_f2_count_MaxMin= new TH1F("mDiff_f2_count_MaxMin","mDiff_f2_count_MaxMin",10,0,1);
  ttbarTree->Draw("1 >> mDiff_f2_count_MaxMin",cutstouse_MaxMin,"goff");
  cout<<"Number of (raw mc) events for bkg (MaxMin)= "<<mDiff_f2_count_MaxMin->GetEntries()<<endl;

  TH1F *mDiff_f1_count_Mon_alg= new TH1F("mDiff_f1_count_Mon_alg","mDiff_f1_count_Mon_alg",10,0,1);
  CollectionTree->Draw("1 >> mDiff_f1_count_Mon_alg",cutstouse_Mon_alg,"goff");
  cout<<"Number of (raw mc) events for signal (Mon alg)= "<<mDiff_f1_count_Mon_alg->GetEntries()<<endl;
  TH1F *mDiff_f2_count_Mon_alg= new TH1F("mDiff_f2_count_Mon_alg","mDiff_f2_count_Mon_alg",10,0,1);
  ttbarTree->Draw("1 >> mDiff_f2_count_Mon_alg",cutstouse_Mon_alg,"goff");
  cout<<"Number of (raw mc) events for bkg (Mon alg)= "<<mDiff_f2_count_Mon_alg->GetEntries()<<endl;

  TH1F *mDiff_f1_count_Mon_alg2= new TH1F("mDiff_f1_count_Mon_alg2","mDiff_f1_count_Mon_alg2",10,0,1);
  CollectionTree->Draw("1 >> mDiff_f1_count_Mon_alg2",cutstouse_Mon_alg2,"goff");
  cout<<"Number of (raw mc) events for signal (Mon alg2)= "<<mDiff_f1_count_Mon_alg2->GetEntries()<<endl;
  TH1F *mDiff_f2_count_Mon_alg2= new TH1F("mDiff_f2_count_Mon_alg2","mDiff_f2_count_Mon_alg2",10,0,1);
  ttbarTree->Draw("1 >> mDiff_f2_count_Mon_alg2",cutstouse_Mon_alg2,"goff");
  cout<<"Number of (raw mc) events for bkg (Mon alg2)= "<<mDiff_f2_count_Mon_alg2->GetEntries()<<endl;

  TH1F *mDiff_f1_count_Mon_alg3= new TH1F("mDiff_f1_count_Mon_alg3","mDiff_f1_count_Mon_alg3",10,0,1);
  CollectionTree->Draw("1 >> mDiff_f1_count_Mon_alg3",cutstouse_Mon_alg3,"goff");
  cout<<"Number of (raw mc) events for signal (Mon alg3)= "<<mDiff_f1_count_Mon_alg3->GetEntries()<<endl;
  TH1F *mDiff_f2_count_Mon_alg3= new TH1F("mDiff_f2_count_Mon_alg3","mDiff_f2_count_Mon_alg3",10,0,1);
  ttbarTree->Draw("1 >> mDiff_f2_count_Mon_alg3",cutstouse_Mon_alg3,"goff");
  cout<<"Number of (raw mc) events for bkg (Mon alg3)= "<<mDiff_f2_count_Mon_alg3->GetEntries()<<endl;
  

  double Significance=(mDiff_f1_count->GetEntries())/sqrt(mDiff_f2_count->GetEntries() + (0.2*mDiff_f2_count->GetEntries())*(0.2*mDiff_f2_count->GetEntries())+1);	 
  double Significance_MaxMin=(mDiff_f1_count_MaxMin->GetEntries())/sqrt(mDiff_f2_count_MaxMin->GetEntries() + (0.2*mDiff_f2_count_MaxMin->GetEntries())*(0.2*mDiff_f2_count_MaxMin->GetEntries())+1);	 
  double Significance_Mon_alg=(mDiff_f1_count_Mon_alg->GetEntries())/sqrt(mDiff_f2_count_Mon_alg->GetEntries() + (0.2*mDiff_f2_count_Mon_alg->GetEntries())*(0.2*mDiff_f2_count_Mon_alg->GetEntries())+1);	 
  double Significance_Mon_alg2=(mDiff_f1_count_Mon_alg2->GetEntries())/sqrt(mDiff_f2_count_Mon_alg2->GetEntries() + (0.2*mDiff_f2_count_Mon_alg2->GetEntries())*(0.2*mDiff_f2_count_Mon_alg2->GetEntries())+1);	 
  double Significance_Mon_alg3=(mDiff_f1_count_Mon_alg3->GetEntries())/sqrt(mDiff_f2_count_Mon_alg3->GetEntries() + (0.2*mDiff_f2_count_Mon_alg3->GetEntries())*(0.2*mDiff_f2_count_Mon_alg3->GetEntries())+1);	 
  
  cout<<"The significance is for (1) = "<<Significance<<endl;
  cout<<"The significance is for (2) = "<<Significance_Mon_alg<<endl;
  cout<<"The significance is for (3) = "<<Significance_MaxMin<<endl;  
  cout<<"The significance is for (4) = "<<Significance_Mon_alg2<<endl;
  cout<<"The significance is for (5) = "<<Significance_Mon_alg3<<endl;


  TCanvas *c1 = new TCanvas("c1","c1",900,900);
  c1->cd();
  TH1F *mDiff_f1= new TH1F("mDiff_f1","mDiff_f1",10,0,1);
  CollectionTree->Draw("mDiff_minDR_pairs >> mDiff_f1",cutstouse,"goff");
  TH1F *mDiff_f2= new TH1F("mDiff_f2","mDiff_f2",10,0,1);
  ttbarTree->Draw("mDiff_minDR_pairs >> mDiff_f2",cutstouse,"goff");
  
  mDiff_f1->SetTitle("Normalised invariant mass difference between minimal DR pairs;Normalised mass difference;");
  mDiff_f1->GetXaxis()->SetRangeUser(0,1);
  mDiff_f1->SetLineWidth(3);
  mDiff_f2->SetLineColor(kBlack);
  //  mDiff_f1->Scale(1/mDiff_f1->Integral());
  mDiff_f2->SetLineWidth(3);
  mDiff_f1->SetLineColor(kBlue);
  //  mDiff_f2->Scale(1/mDiff_f2->Integral());
 
  double maxval=0;
  if(mDiff_f1->GetEntries()>mDiff_f2->GetEntries())
    {
      maxval=(mDiff_f1->GetMaximum()+(mDiff_f1->GetMaximum()/10));
    }
  else {maxval=(mDiff_f2->GetMaximum()+(mDiff_f2->GetMaximum()/10));}
  mDiff_f1->SetMaximum(maxval);
  mDiff_f1->Draw("HIST");  
  mDiff_f2->Draw("HIST;same");

  TLegend *leg2 = new TLegend(0.73,0.75,0.9,0.9);
  leg2->SetFillStyle(0);
  leg2->SetLineWidth(0);
  leg2->AddEntry(mDiff_f1,"Signal","L");
  leg2->AddEntry(mDiff_f2,"ttbar","L");
  leg2->Draw("same");


  //  c1->SaveAs("SummerAnalysis/Summer_Student_Analysis/histograms/mDiffAlg/600_530/mDiff_DR_2_mDiff07.pdf");
  

  TCanvas *c2 = new TCanvas("c2","c2",900,900);
  c2->cd();
  TH1F *mbb1_f1 =  new TH1F("mbb1_f1","mbb1_f1", 15, 0, 500);
  CollectionTree->Draw("mbb1>>mbb1_f1",cutstouse,"goff");
  TH1F *mbb2_f1 =  new TH1F("mbb2_f1","mbb2_f1", 15, 0, 500);
  CollectionTree->Draw("mbb2>>mbb2_f1",cutstouse,"goff");
  TH1F *mbb1_ttbar = new TH1F("mbb1_ttbar","mbb1_ttbar",15,0, 500);
  ttbarTree->Draw("mbb1>>mbb1_ttbar",cutstouse,"goff");
  TH1F *mbb2_ttbar = new TH1F("mbb2_ttbar","mbb2_ttbar",15,0, 500);
  ttbarTree->Draw("mbb2>>mbb2_ttbar",cutstouse,"goff");
  

  mbb1_f1->SetTitle("Invariant mass of the two minDR pairs;mbb;");
  mbb1_f1->SetLineColor(kRed);
  mbb2_f1->SetLineColor(kBlue);
  mbb1_ttbar->SetLineColor(kBlack);
  mbb2_ttbar->SetLineColor(kBlack);
  mbb2_ttbar->SetLineStyle(2);
  mbb1_f1->SetLineWidth(2);
  mbb2_f1->SetLineWidth(2);
  mbb1_ttbar->SetLineWidth(2);
  mbb2_ttbar->SetLineWidth(2);


  //  mbb1_f1->Scale(1/mbb1_f1->Integral());
  //  mbb2_f1->Scale(1/mbb2_f1->Integral());
  //  mbb1_ttbar->Scale(1/mbb1_ttbar->Integral());
  //  mbb2_ttbar->Scale(1/mbb2_ttbar->Integral());
  
  
  std::vector<double> maxVect1 = {mbb1_f1->GetMaximum(),mbb2_f1->GetMaximum(),mbb1_ttbar->GetMaximum(),mbb2_ttbar->GetMaximum()};
  sort(maxVect1.rbegin(),maxVect1.rend());

  mbb1_f1->SetMaximum(maxVect1[0]+maxVect1[0]/10);
  mbb1_f1->Draw("HIST");
  mbb2_f1->Draw("HIST;same");
  mbb1_ttbar->Draw("HIST;same");
  mbb2_ttbar->Draw("HIST;same");

  TLegend *leg1 = new TLegend(0.73,0.75,0.9,0.9);
  leg1->SetFillStyle(0);
  leg1->SetLineWidth(0);
  leg1->AddEntry(mbb1_f1,"Minimum DR pair","L");
  leg1->AddEntry(mbb2_f1,"2nd lowest DR pair","L");
  leg1->AddEntry(mbb1_ttbar,"Minimum DR pair, ttbar","L");
  leg1->AddEntry(mbb2_ttbar,"2nd lowest  DR pair, ttbar","L");
  leg1->Draw("same");
  //  c2->SaveAs("SummerAnalysis/Summer_Student_Analysis/histograms/mDiffAlg/600_530/mbb_DR_2_mDiff07.pdf");



  TCanvas *c3 = new TCanvas("c3","c3",900,900);
  c3->cd();
  TH1F *DR1_f1 =  new TH1F("DR1_f1","DR1_f1", 15, 0, 6);
  CollectionTree->Draw("minDR_b1>>DR1_f1",cutstouse,"goff");
  TH1F *DR2_f1 =  new TH1F("DR2_f1","DR2_f1", 15, 0, 6);
  CollectionTree->Draw("minDR_b2>>DR2_f1",cutstouse,"goff");
  TH1F *DR1_ttbar =  new TH1F("DR1_ttbar","DR1_ttbar", 15, 0, 6);
  ttbarTree->Draw("minDR_b1>>DR1_ttbar",cutstouse,"goff");
  TH1F *DR2_ttbar =  new TH1F("DR2_ttbar","DR2_ttbar", 15, 0, 6);
  ttbarTree->Draw("minDR_b2>>DR2_ttbar",cutstouse,"goff");
  


  DR1_f1->SetTitle("DR of the two minDR pairs;DR;");
  DR1_f1->SetLineColor(kRed);
  DR2_f1->SetLineColor(kBlue);
  DR1_f1->SetLineWidth(2);
  DR2_f1->SetLineWidth(2);
  DR1_ttbar->SetLineColor(kBlack);
  DR2_ttbar->SetLineColor(kBlack);
  DR1_ttbar->SetLineWidth(2);
  DR2_ttbar->SetLineWidth(2);
  DR2_ttbar->SetLineStyle(2);
  //  DR1_f1->Scale(1/DR1_f1->Integral());
  //  DR2_f1->Scale(1/DR2_f1->Integral());
  //DR1_ttbar->Scale(1/DR1_ttbar->Integral());
  //DR2_ttbar->Scale(1/DR2_ttbar->Integral());
		   

  std::vector<double> maxVect = {DR1_f1->GetMaximum(),DR2_f1->GetMaximum(),DR2_ttbar->GetMaximum(),DR1_ttbar->GetMaximum()};
  sort(maxVect.rbegin(),maxVect.rend());

  DR1_f1->SetMaximum(maxVect[0]+maxVect[0]/10);
  DR1_f1->Draw("HIST");
  DR2_f1->Draw("HIST;same");
  DR1_ttbar->Draw("HIST;same");
  DR2_ttbar->Draw("HIST;same");
 
  TLegend *leg = new TLegend(0.73,0.75,0.9,0.9);
  leg->SetFillStyle(0);
  leg->SetLineWidth(0);
  leg->AddEntry(DR1_f1,"Minimum DR pair","L");
  leg->AddEntry(DR2_f1,"2nd lowest DR pair","L");
  leg->AddEntry(DR1_ttbar,"Mimimum DR pair, ttbar","L");
  leg->AddEntry(DR2_ttbar,"2nd lowest  DR pair, ttbar","L");
  leg->Draw("same");
  //  c3->SaveAs("SummerAnalysis/Summer_Student_Analysis/histograms/mDiffAlg/600_530/DRs_DR_2_mDiff07.pdf");


  TCanvas *c4 = new TCanvas("c4","c4",900,900);
  c4->cd();
  
  TH2F *mbb_b1_b2_signal = new TH2F("mbb_b1_b2_signal","mbb_b1_b2_signal",10,0,500,10,0,500);
  CollectionTree->Draw("mbb1:mbb2>>mbb_b1_b2_signal",cutstouse,"goff");
  mbb_b1_b2_signal->SetTitle("Correlation between mbb1 and mbb2;mbb2;mbb1");
  mbb_b1_b2_signal->SetMarkerColor(kGray+1);
  mbb_b1_b2_signal->SetMarkerSize(0.85);
  mbb_b1_b2_signal->Draw("colz");
  
  //  c4->SaveAs("SummerAnalysis/Summer_Student_Analysis/histograms/mDiffAlg/600_530/mbb1_2_correlation_DR_2_mDiff07.pdf");

  TCanvas *c5 = new TCanvas("c5","c5",900,900);
  c5->cd();
  TH1F *mbb1_2_avg_f1 =  new TH1F("mbb1_2_avg_f1","mbb1_2_avg_f1", 10, 0, 500);
  CollectionTree->Draw("mbb1_2_avg>>mbb1_2_avg_f1",cutstouse,"goff");
  TH1F *mbb1_2_avg_ttbar =  new TH1F("mbb1_2_avg_ttbar","mbb1_2_avg_ttbar", 10, 0, 500);
  ttbarTree->Draw("mbb1_2_avg>>mbb1_2_avg_ttbar",cutstouse,"goff");

  mbb1_2_avg_f1->SetTitle("Avg invariant mass of the two bb pairs;mbb;");
  mbb1_2_avg_f1->SetLineColor(kRed);
  mbb1_2_avg_f1->SetLineWidth(2);

  mbb1_2_avg_ttbar->SetLineColor(kBlack);
  mbb1_2_avg_ttbar->SetLineWidth(2);
  //  mbb1_2_avg_f1->Scale(1/mbb1_2_avg_f1->Integral());
  //  mbb1_2_avg_ttbar->Scale(1/mbb1_2_avg_ttbar->Integral());
		   

  std::vector<double> maxVect3 = {mbb1_2_avg_f1->GetMaximum(),mbb1_2_avg_ttbar->GetMaximum()};
  sort(maxVect3.rbegin(),maxVect3.rend());

  mbb1_2_avg_f1->SetMaximum(maxVect3[0]+maxVect3[0]/10);
  mbb1_2_avg_f1->Draw("HIST");
  mbb1_2_avg_ttbar->Draw("HIST;same");
 
  TLegend *leg3 = new TLegend(0.73,0.75,0.9,0.9);
  leg3->SetFillStyle(0);
  leg3->SetLineWidth(0);
  leg3->AddEntry(mbb1_2_avg_f1,"Signal","L");
  leg3->AddEntry(mbb1_2_avg_ttbar,"ttbar","L");
  leg3->Draw("same");


  TLatex *latex = new TLatex();
  latex->DrawLatex(0.16,200,"Avg=#dfrac{m_{bb}^1+m_{bb}^2}{2}");
  //  c5->SaveAs("SummerAnalysis/Summer_Student_Analysis/histograms/mDiffAlg/600_530/mbb_avg_DR_2_mDiff07.pdf");


  TCanvas *c6 = new TCanvas("c6","c6",900,900);
  c6->cd();

  TH2F *mbb_b1_b2_ttbar = new TH2F("mbb_b1_b2_ttbar","mbb_b1_b2_ttbar",10,0,500,10,0,500);
  ttbarTree->Draw("mbb1:mbb2>>mbb_b1_b2_ttbar",cutstouse,"goff");
  mbb_b1_b2_ttbar->SetTitle("Correlation between mbb1 and mbb2 t#bar{t} ;mbb2;mbb1");
  mbb_b1_b2_ttbar->SetMarkerColor(kGray+1);
  mbb_b1_b2_ttbar->SetMarkerSize(0.85);
  mbb_b1_b2_ttbar->Draw("colz");

  //  c6->SaveAs("SummerAnalysis/Summer_Student_Analysis/histograms/mDiffAlg/600_530/mbb1_2_ttbarcorr_DR_2_mDiff07.pdf");

  TCanvas *c7 = new TCanvas("c7","c7",900,900);
  c7->cd();

  TH2F *avg_normM_corr = new TH2F("avg_normM_corr","avg_normM_corr",10,0,1,20,0,500);
  CollectionTree->Draw("mbb1_2_avg:mDiff_minDR_pairs>>avg_normM_corr",cutstouse,"goff");
  avg_normM_corr->SetTitle("Correlation between mbb1 and mbb2 t#bar{t} ;Normalised inv mass difference;Average invariant mass (GeV)");
  avg_normM_corr->GetYaxis()->SetTitleOffset(1.5);
  avg_normM_corr->SetMarkerColor(kGray+1);
  avg_normM_corr->SetMarkerSize(0.85);
  avg_normM_corr->Draw("colz");

  //  c7->SaveAs("SummerAnalysis/Summer_Student_Analysis/histograms/mDiffAlg/600_530/avg_normM_corr_DR_2_mDiff07.pdf");









  gApplication->Terminate();
}








