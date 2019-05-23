void AnalyseTree ()
{  
#include "TFile.h"
#include "TTree.h"
#include "TLatex.h"  
  TFile *f1 = TFile::Open("/hepstore/hteagle/GridSubmissions/OutputTruthOutput/data-output/DAOD_TRUTH1.root");
  TFile *f1reco = TFile::Open("/hepstore/hteagle/GridSubmissions/OutputRecoOutput/data-output/DAOD_SUSY7.root");
  TFile *f2 =TFile::Open("/hepstore/hteagle/SubmissionOutputs/mc15_13TeV.390225.MGPy8EG_A14N23LO_BB_onestepN2hN1_300_295_165_MET100.merge.DAOD_TRUTH1.e5671_p2913/hist-DAOD_TRUTH1.root");
  
  //  f1->ls();
   f1reco->ls();

  if (f1==0 || f2==0 || f1reco==0)
    {cout<<"Unable to open file"<<endl;
       gApplication->Terminate();
    }

  // CollectionTree->Draw("var","cuts")
  // CollectionTree->Draw("var","(mcEventWeight*)")
  // find the cross section * filter efficiency * kfactor 
  // divide by #events = 740671.4
  // lumiScaling = (crosssection*kfact*efficiency)/(N_rawEvents)*(luminosityCollected)
  // ShapeScale = (1/Integral)
  gStyle->SetOptStat(0);
  gStyle->SetTitleH(0.045);



  TTree *CollectionTree = (TTree*)f1->Get("NominalFixed");
  TTree *RecoTree=(TTree*)f1reco->Get("NominalFixed");
  
  TH1F *Scaling =(TH1F*)f1->Get("h_sherpaWeights");
  int rawEvents = Scaling->Integral();

  cout<<"rawEvents= "<<rawEvents<<endl;
  double xSect = 8.5*1000;//in femtobarns
  double FilterEff = 0.204675;
  double EffectiveLumi = rawEvents/(xSect*FilterEff);
  double ScalingFactor = 36.5/EffectiveLumi;//Scaled to 36.5 fb^-1
  cout<<"xsection= "<<xSect<<endl;
  cout<<"FilterEff= "<<FilterEff<<endl;
  cout<<"ScalingFactor= "<<ScalingFactor<<endl;  

  TH1F *ScalingReco = (TH1F*)f1reco->Get("h_sherpaWeights");
  int rawEventsReco = ScalingReco->Integral();
  double EffectiveLumiReco = rawEventsReco/(xSect*FilterEff);
  double ScalingFactorReco = 36.5/EffectiveLumiReco;
  cout<<"ScalingFactorReco= "<<ScalingFactorReco<<endl;


  TH1F *Scale =(TH1F*)f2->Get("h_Counter_MET100");
  double rawEvents2 = Scale->GetEntries();
  cout<<"rawEvents2= "<<rawEvents2<<endl;
  double EffectiveLumi2 = rawEvents2/(xSect*FilterEff);
  double ScalingFactor2 =36.5/EffectiveLumi2; 
  cout<<"ScalingFactor2= "<<ScalingFactor2<<endl;



  TCanvas* c2 = new TCanvas("c2","c2",900,900);
  c2->cd();
  TH1F *h2 = new TH1F("h2","h2",20,0,4);
  CollectionTree->Draw("minDPhijMET>> h2","","goff" );
  h2->Scale(ScalingFactor);
  h2->SetTitle("min#Delta#phi (Jet-MET) considering all jets");
  h2->GetXaxis()->SetTitle("min#Delta#phi");

  TH1F *h2reco = new TH1F("h2reco","h2reco",20,0,4);
  RecoTree->Draw("minDPhijMET >> h2reco","", "goff");
  h2reco->SetLineColor(kRed);
  h2reco->Scale(ScalingFactorReco);

  if(h2->GetMaximum()<h2reco->GetMaximum())
    {h2->SetMaximum(h2reco->GetMaximum());}
  
  h2->Draw("HIST;same");
  h2reco->Draw("HIST;same");
  myLegend1 = new TLegend(0.7,0.8,0.8,0.89);
  myLegend1 -> SetFillColor(0);
  myLegend1 -> SetBorderSize(0);
  myLegend1 -> SetTextSize(0.04);
  myLegend1 -> AddEntry(h2,"TruthLevel","l");
  myLegend1 -> AddEntry(h2reco,"RecoLevel","l");
  myLegend1->Draw("same");
  c2->SaveAs("SummerAnalysis/Summer_Student_Analysis/histograms/TreeTrials/600_400/MaxMin/NoCuts/minDPhijMET");

    TCanvas* c3 = new TCanvas("c3","c3",900,900);
  c3->cd();
  TH1F *h3 = new TH1F("h3","h3",50,0,1000);
  CollectionTree->Draw("ETMiss>> h3","","goff");
  h3->Scale(ScalingFactor);
  h3->SetTitle("Missing Transverse energy");
  h3->GetXaxis()->SetTitle("Missing Transverse energy (GeV)");
  h3->Draw("HIST;same");
  TH1F *h3reco = new TH1F("h3reco","h3reco",50,0,1000);
  RecoTree->Draw("ETMiss>>h3reco","","goff");
  h3reco->SetLineColor(kRed);
  h3reco->Scale(ScalingFactorReco);
  h3reco->Draw("HIST;same");
  gPad->SetLogy();

  myLegend2 = new TLegend(0.7,0.8,0.8,0.89);
  myLegend2 -> SetFillColor(0);
  myLegend2 -> SetBorderSize(0);
  myLegend2 -> SetTextSize(0.04);
  myLegend2 -> AddEntry(h3,"TruthLevel","l");
  myLegend2 -> AddEntry(h3reco,"RecoLevel","l");
  myLegend2->Draw("same");
  c3->SaveAs("SummerAnalysis/Summer_Student_Analysis/histograms/TreeTrials/600_400/MaxMin/NoCuts/ETMiss.eps");
    
  TCanvas* c4 = new TCanvas("c4","c4",900,900);
  c4->cd();
  TH1F *h4 = new TH1F("h4","h4",8,0,8);
  CollectionTree->Draw("nBJets>> h4","", "goff");
  h4->Scale(ScalingFactor);
  h4->SetTitle("Number of b-jets ");
  h4->GetXaxis()->SetTitle("Number of b-jets");
  h4->SetMaximum(10000);
  h4->Draw("HIST:same");
  TH1F *h4reco = new TH1F("h4reco","h4reco",8,0,8);
  RecoTree->Draw("nBJets>> h4reco","","goff");
  h4reco->SetLineColor(kRed);
  h4reco->Scale(ScalingFactorReco);
  if(h4->GetMaximum()<h4reco->GetMaximum())
    {h4->SetMaximum(h4reco->GetMaximum()+h4reco->GetMaximum()/10);}
  h4reco->Draw("HIST;same");

  myLegend3 = new TLegend(0.7,0.8,0.8,0.89);
  myLegend3 -> SetFillColor(0);
  myLegend3 -> SetBorderSize(0);
  myLegend3 -> SetTextSize(0.04);
  myLegend3 -> AddEntry(h4,"TruthLevel","l");
  myLegend3 -> AddEntry(h4reco,"RecoLevel","l");
  myLegend3->Draw("same");
  c4->SaveAs("SummerAnalysis/Summer_Student_Analysis/histograms/TreeTrials/600_400/MaxMin/NoCuts/nBJets");

  TCanvas* c5 = new TCanvas("c5","c5",900,900);
  c5->cd();
  TH1F *h5 = new TH1F("h5","h5",12,0,4);
  CollectionTree->Draw("minDR>> h5","","goff");
  h5->Scale(ScalingFactor);
  h5->SetTitle("#DeltaRmin between b-jets after Max exclusion");
  h5->GetXaxis()->SetTitle("Min#DeltaR");
  h5->Draw("HIST;same");
  TH1F *h5reco = new TH1F("h5reco","h5reco",12,0,4);
  RecoTree->Draw("minDR>> h5reco","","goff");
  h5reco->Scale(ScalingFactorReco);
  h5reco->SetLineColor(kRed);
  h5reco->Draw("HIST;same");

  myLegend4 = new TLegend(0.7,0.8,0.8,0.89);
  myLegend4 -> SetFillColor(0);
  myLegend4 -> SetBorderSize(0);
  myLegend4 -> SetTextSize(0.04);
  myLegend4 -> AddEntry(h5,"TruthLevel","l");
  myLegend4 -> AddEntry(h5reco,"RecoLevel","l");
  myLegend4->Draw("same");
  c5->SaveAs("SummerAnalysis/Summer_Student_Analysis/histograms/TreeTrials/600_400/MaxMin/NoCuts/minDR");

  TCanvas* c6 = new TCanvas("c6","c6",900,900);
  c6->cd();
  TH1F *h6 = new TH1F("h6","h6",100,0,1000);
  CollectionTree->Draw("pTj1 >> h6","","goff");
  h6->Scale(ScalingFactor);
  h6->SetTitle("pT of leading jet");
  h6->GetXaxis()->SetTitle("pT (Gev)");
  h6->Draw("HIST;same");
  TH1F *h6reco = new TH1F("h6reco","h6reco",100,0,1000);
  RecoTree->Draw("pTj1 >> h6reco","","goff");
  h6reco->Scale(ScalingFactorReco);
  h6reco->SetLineColor(kRed);
  h6reco->Draw("HIST;same");
  if(h6->GetMaximum()<h6reco->GetMaximum())
    {h6->SetMaximum(h6reco->GetMaximum()+h6reco->GetMaximum()/10);}
  myLegend5 = new TLegend(0.7,0.8,0.8,0.89);
  myLegend5 -> SetFillColor(0);
  myLegend5 -> SetBorderSize(0);
  myLegend5 -> SetTextSize(0.04);
  myLegend5 -> AddEntry(h6,"TruthLevel","l");
  myLegend5 -> AddEntry(h6reco,"RecoLevel","l");
  myLegend5->Draw("same");
  c6->SaveAs("SummerAnalysis/Summer_Student_Analysis/histograms/TreeTrials/600_400/MaxMin/NoCuts/pTj1.eps");

  TCanvas* c1 = new TCanvas("c1","c1",900,900);     
  c1->cd();
  TH1F *h1 = new TH1F("h1","h1",20,0,200);
  CollectionTree->Draw("InvMass_Bij_minR>> h1","(ETMiss>200) && (pTj1>80) && (minDPhi>0.4) && (nBJets>=4) && (minDR<2.5)","goff");  
  h1->Scale(ScalingFactor);
  h1->SetTitle("#splitline{Invariant Mass of b-jet pairs after MaxMin procedure }{Zero leptons, ETMiss>200, pTj1>80, nBJets>=4, minDR<2.5}");
  h1->GetXaxis()->SetTitle("Invariant Mass of b-jet pairs (GeV) ");
  h1->Draw("HIST;same");
  TH1F *h1reco = new TH1F("h1reco","h1reco",20,0,200);
  RecoTree->Draw("InvMass_Bij_minR>> h1reco","(ETMiss>200) && (pTj1>80) && (minDPhi>0.4) && (nBJets>=4) && (minDR<2.5)","goff");
  h1reco->SetLineColor(kRed);
  h1reco->Scale(ScalingFactorReco);
  h1reco->Draw("Hist;same");
  if(h1->GetMaximum()<h1reco->GetMaximum())
    {h1->SetMaximum(h1reco->GetMaximum()+h1reco->GetMaximum()/10);}

  myLegend6 = new TLegend(0.7,0.8,0.8,0.89);
  myLegend6 -> SetFillColor(0);
  myLegend6 -> SetBorderSize(0);
  myLegend6 -> SetTextSize(0.04);
  myLegend6 -> AddEntry(h2,"TruthLevel","l");
  myLegend6 -> AddEntry(h2reco,"RecoLevel","l");
  myLegend6->Draw("same");

  c1->SaveAs("SummerAnalysis/Summer_Student_Analysis/histograms/TreeTrials/600_400/MaxMin/NoCuts/InvMass_AFTMaxMin");
 

  TCanvas* c7 = new TCanvas("c7","c7",900,800);     
  c7->cd();
  TH1F *h7 = new TH1F("h7","h7",20,0,200);
  CollectionTree->Draw("InvMass_Bij_minR>> h7","","goff");  
  h7->Scale(ScalingFactor);
  h7->SetTitle("#splitline{Invariant Mass of b-jet pairs with Minimum #DeltaR }{ after maximal #DeltaR b-jet exclusion}");
  h7->GetXaxis()->SetTitle("Invariant Mass of b-jet pairs (GeV) ");
  h7->Draw("HIST;same");
  TH1F *h7reco = new TH1F("h7reco","h7reco",20,0,200);
  RecoTree->Draw("InvMass_Bij_minR>> h7reco","","goff");
  h7reco->SetLineColor(kRed);
  h7reco->Scale(ScalingFactorReco);
  h7reco->Draw("Hist;same");
  if(h7->GetMaximum()<h7reco->GetMaximum())
    {h7->SetMaximum(h7reco->GetMaximum()+h7reco->GetMaximum()/10);}

  myLegend6 = new TLegend(0.7,0.8,0.8,0.89);
  myLegend6 -> SetFillColor(0);
  myLegend6 -> SetBorderSize(0);
  myLegend6 -> SetTextSize(0.04);
  myLegend6 -> AddEntry(h2,"TruthLevel","l");
  myLegend6 -> AddEntry(h2reco,"RecoLevel","l");
  myLegend6->Draw("same");

  c7->SaveAs("SummerAnalysis/Summer_Student_Analysis/histograms/TreeTrials/600_400/MaxMin/NoCuts/InvMass_Raw");




  TCanvas* c8= new TCanvas("c8","c8",900,900);     
  c8->cd();
  TH1F *h8 = new TH1F("h8","h8",20,0,200);
  CollectionTree->Draw("InvMass_Bij_minR>> h8","minDPhi>0.4","goff");  
  h8->Scale(ScalingFactor);
  h8->SetTitle("Invariant Mass of b-jet pairs with Minimum #DeltaR after maximal #DelatR b-jet  exclusion, min#Delta#phi>0.4");
  h8->GetXaxis()->SetTitle("Invariant Mass of b-jet pairs (GeV) ");
  h8->Draw("HIST;same");
  TH1F *h8reco = new TH1F("h8reco","h8reco",20,0,200);
  RecoTree->Draw("InvMass_Bij_minR>> h8reco","minDPhi>0.4","goff");
  h8reco->SetLineColor(kRed);
  h8reco->Scale(ScalingFactorReco);
  h8reco->Draw("Hist;same");
  if(h8->GetMaximum()<h8reco->GetMaximum())
    {h8->SetMaximum(h8reco->GetMaximum()+h8reco->GetMaximum()/10);}

  myLegend6 = new TLegend(0.7,0.8,0.8,0.89);
  myLegend6 -> SetFillColor(0);
  myLegend6 -> SetBorderSize(0);
  myLegend6 -> SetTextSize(0.04);
  myLegend6 -> AddEntry(h2,"TruthLevel","l");
  myLegend6 -> AddEntry(h2reco,"RecoLevel","l");
  myLegend6->Draw("same");

  c8->SaveAs("SummerAnalysis/Summer_Student_Analysis/histograms/TreeTrials/600_400/MaxMin/NoCuts/InvMass_minDPhi");

  TCanvas* c9= new TCanvas("c9","c9",900,900);
  c9->cd();
  TH1F *h9 = new TH1F("h9","h9",16,0,16);
  CollectionTree->Draw("nJets>> h9","","goff");
  h9->Scale(ScalingFactor);
  h9->SetTitle("Number of jets");
  h9->GetXaxis()->SetTitle("Number of Jets");
  h9->Draw("HIST;same");
  TH1F *h9reco = new TH1F("h9reco","h9reco",16,0,16);
  RecoTree->Draw("nJets>> h9reco","","goff");
  h9reco->SetLineColor(kRed);
  h9reco->Scale(ScalingFactorReco);
  h9reco->Draw("Hist;same");
  if(h9->GetMaximum()<h9reco->GetMaximum())
    {h9->SetMaximum(h9reco->GetMaximum()+(h9reco->GetMaximum()/10));}

  myLegend7 = new TLegend(0.7,0.8,0.8,0.89);
  myLegend7 -> SetFillColor(0);
  myLegend7 -> SetBorderSize(0);
  myLegend7 -> SetTextSize(0.04);
  myLegend7 -> AddEntry(h2,"TruthLevel","l");
  myLegend7 -> AddEntry(h2reco,"RecoLevel","l");
  myLegend7->Draw("same");

  c9->SaveAs("SummerAnalysis/Summer_Student_Analysis/histograms/TreeTrials/600_400/MaxMin/NoCuts/NJets");


  TCanvas* c10= new TCanvas("c10","c10",900,900);
  c10->cd();
  TH1F *h10 = new TH1F("h10","h10",20,0,4);
  CollectionTree->Draw("minDPhi>> h10","","goff");
  h10->Scale(ScalingFactor);
  h10->SetTitle("min#Delta#phi with 4 strongest jets");
  h10->GetXaxis()->SetTitle("min#Delta#phi");
  h10->Draw("HIST;same");
  TH1F *h10reco = new TH1F("h10reco","h10reco",20,0,4);
  RecoTree->Draw("minDPhi>> h10reco","","goff");
  h10reco->SetLineColor(kRed);
  h10reco->Scale(ScalingFactorReco);
  h10reco->Draw("Hist;same");
  if(h10->GetMaximum()<h10reco->GetMaximum())
    {h10->SetMaximum(h10reco->GetMaximum()+h10reco->GetMaximum()/10);}

  myLegend8 = new TLegend(0.7,0.8,0.8,0.89);
  myLegend8 -> SetFillColor(0);
  myLegend8 -> SetBorderSize(0);
  myLegend8 -> SetTextSize(0.04);
  myLegend8 -> AddEntry(h2,"TruthLevel","l");
  myLegend8 -> AddEntry(h2reco,"RecoLevel","l");
  myLegend8->Draw("same");

  c10->SaveAs("SummerAnalysis/Summer_Student_Analysis/histograms/TreeTrials/600_400/MaxMin/NoCuts/minDphi_4strong");


  TCanvas* c11= new TCanvas("c11","c11",900,900);
  c11->cd();
  TH1F *h11 = new TH1F("h11","h11",50,0,200);
  CollectionTree->Draw("InvMass_Bij_minR1>> h11","ETMiss>250","goff");
  h11->Scale(ScalingFactor);
  h11->SetTitle("#splitline{Invariant mass of min#DeltaR b-jet pairs, no max #DeltaR exclusion}{ETmiss>250, nBJets>=4, min#Delta#Phi>0.4, pTj1>80, min#DeltaR<2.5}");
  h11->GetXaxis()->SetTitle("Invariant Mass (GeV)");
  h11->Draw("HIST;same");
  TH1F *h11reco = new TH1F("h11reco","h11reco",50,0,200);
  RecoTree->Draw("InvMass_Bij_minR1>> h11reco","ETMiss>250","goff");
  h11reco->SetLineColor(kRed);
  h11reco->Scale(ScalingFactorReco);
  h11reco->Draw("Hist;same");
  if(h11->GetMaximum()<h11reco->GetMaximum())
    {h11->SetMaximum(h11reco->GetMaximum()+h11reco->GetMaximum()/10);}

  myLegend9 = new TLegend(0.7,0.8,0.8,0.89);
  myLegend9 -> SetFillColor(0);
  myLegend9 -> SetBorderSize(0);
  myLegend9 -> SetTextSize(0.04);
  myLegend9 -> AddEntry(h2,"TruthLevel","l");
  myLegend9 -> AddEntry(h2reco,"RecoLevel","l");
  myLegend9->Draw("same");

  c11->SaveAs("SummerAnalysis/Summer_Student_Analysis/histograms/TreeTrials/600_400/Min/NoCuts/InvMass_AFT");


  TCanvas* c12= new TCanvas("c12","c12",900,900);
  c12->cd();
  TH1F *h12 = new TH1F("h12","h12",50,0,200);
  CollectionTree->Draw("InvMass_Bij_minR1>> h12","nBaselineLeptons==0 && ETMiss>200","goff");
  h12->Scale(ScalingFactor);
  h12->SetTitle("#splitline{Invariant mass of minimal #DeltaR jets, no max #DeltaR exclusion}{zero leptons, ETMiss>200}; InvMass(GeV)");
  //  h12->GetXaxis()->SetTitle("Number of Jets");
  h12->Draw("HIST;same");
  TH1F *h12reco = new TH1F("h12reco","h12reco",50,0,200);
  RecoTree->Draw("InvMass_Bij_minR1>> h12reco","nBaselineLeptons==0 && ETMiss>200","goff");
  h12reco->SetLineColor(kRed);
  h12reco->Scale(ScalingFactorReco);
  h12reco->Draw("Hist;same");
  if(h12->GetMaximum()<h12reco->GetMaximum())
    {h12->SetMaximum(h12reco->GetMaximum()+h12reco->GetMaximum()/10);}

  myLegend10 = new TLegend(0.7,0.8,0.8,0.89);
  myLegend10 -> SetFillColor(0);
  myLegend10 -> SetBorderSize(0);
  myLegend10 -> SetTextSize(0.04);
  myLegend10 -> AddEntry(h12,"TruthLevel","l");
  myLegend10 -> AddEntry(h12reco,"RecoLevel","l");
  myLegend10->Draw("same");

  c12->SaveAs("SummerAnalysis/Summer_Student_Analysis/histograms/TreeTrials/600_400/Min/NlepAndMET/InvMass_Raw");


  TCanvas* c17= new TCanvas("c17","c17",900,900);
  c17->cd();
  TH1F *h17 = new TH1F("h17","h17",12,0,4);
  CollectionTree->Draw("minDR1>> h17","nBaselineLeptons==0 && ETMiss>200","goff");
  h17->Scale(ScalingFactor);
  h17->SetTitle("#splitline{min#DeltaR between b-jets, no max #DeltaR exclusion,}{ No leptons, ETMiss>200}; min#DeltaR");
  //  h17->GetXaxis()->SetTitle("Number of Jets");
  h17->Draw("HIST;same");
  TH1F *h17reco = new TH1F("h17reco","h17reco",12,0,4);
  RecoTree->Draw("minDR1>> h17reco","nBaselineLeptons==0 && ETMiss>200","goff");
  h17reco->SetLineColor(kRed);
  h17reco->Scale(ScalingFactorReco);
  h17reco->Draw("Hist;same");
  if(h17->GetMaximum()<h17reco->GetMaximum())
    {h17->SetMaximum(h17reco->GetMaximum()+h17reco->GetMaximum()/10);}

  myLegend11 = new TLegend(0.7,0.8,0.8,0.89);
  myLegend11 -> SetFillColor(0);
  myLegend11 -> SetBorderSize(0);
  myLegend11 -> SetTextSize(0.04);
  myLegend11 -> AddEntry(h17,"TruthLevel","l");
  myLegend11 -> AddEntry(h17reco,"RecoLevel","l");
  myLegend11->Draw("same");

  c17->SaveAs("SummerAnalysis/Summer_Student_Analysis/histograms/TreeTrials/600_400/Min/NlepAndMET/minDR1");

  TCanvas* c18= new TCanvas("c18","c18",900,900);
  c18->cd();
  TH1F *h18 = new TH1F("h18","h18",15,0,5);
  CollectionTree->Draw("maxDR>> h18","","goff");
  h18->Scale(ScalingFactor);
  h18->SetTitle("max#DeltaR between b-jets; max#DeltaR");
  h18->Draw("HIST;same");
  TH1F *h18reco = new TH1F("h18reco","h18reco",15,0,5);
  RecoTree->Draw("maxDR>> h18reco","","goff");
  h18reco->SetLineColor(kRed);
  h18reco->Scale(ScalingFactorReco);
  h18reco->Draw("Hist;same");
  if(h18->GetMaximum()<h18reco->GetMaximum())
    {h18->SetMaximum(h18reco->GetMaximum()+h18reco->GetMaximum()/10);}

  myLegend12 = new TLegend(0.7,0.8,0.8,0.89);
  myLegend12 -> SetFillColor(0);
  myLegend12 -> SetBorderSize(0);
  myLegend12 -> SetTextSize(0.04);
  myLegend12 -> AddEntry(h18,"TruthLevel","l");
  myLegend12 -> AddEntry(h18reco,"RecoLevel","l");
  myLegend12->Draw("same");

  c18->SaveAs("SummerAnalysis/Summer_Student_Analysis/histograms/TreeTrials/600_400/MaxMin/NoCuts/maxDR");


  TCanvas* c19= new TCanvas("c19","c19",900,900);
  c19->cd();
  TH1F *h19 = new TH1F("h19","h19",5,0,5);
  CollectionTree->Draw("nBaselineLeptons>> h19","","goff");
  h19->Scale(ScalingFactor);
  h19->SetTitle("Number of Baseline Leptons; nBaselineLeptons");
  h19->Draw("HIST;same");
  TH1F *h19reco = new TH1F("h19reco","h19reco",5,0,5);
  RecoTree->Draw("nBaselineLeptons>> h19reco","","goff");
  h19reco->SetLineColor(kRed);
  h19reco->Scale(ScalingFactorReco);
  h19reco->Draw("Hist;same");
  if(h19->GetMaximum()<h19reco->GetMaximum())
    {h19->SetMaximum(h19reco->GetMaximum()+h19reco->GetMaximum()/10);}
  myLegend13 = new TLegend(0.7,0.8,0.8,0.89);
  myLegend13 -> SetFillColor(0);
  myLegend13 -> SetBorderSize(0);
  myLegend13 -> SetTextSize(0.04);
  myLegend13 -> AddEntry(h19,"TruthLevel","l");
  myLegend13 -> AddEntry(h19reco,"RecoLevel","l");
  myLegend13->Draw("same");
  c19->SaveAs("SummerAnalysis/Summer_Student_Analysis/histograms/TreeTrials/600_400/MaxMin/NoCuts/nBaselineLeptons");

  TCanvas* c20= new TCanvas("c20","c20",900,900);
  c20->cd();
  TH1F *h20 = new TH1F("h20","h20",100,0,1000);
  CollectionTree->Draw("m_CT>> h20","","goff");
  h20->Scale(ScalingFactor);
  h20->SetTitle("mCT; mCT");
  h20->Draw("HIST;same");
  TH1F *h20reco = new TH1F("h20reco","h20reco",100,0,1000);
  RecoTree->Draw("m_CT>> h20reco","","goff");
  h20reco->SetLineColor(kRed);
  h20reco->Scale(ScalingFactorReco);
  h20reco->Draw("Hist;same");
  if(h20->GetMaximum()<h20reco->GetMaximum())
    {h20->SetMaximum(h20reco->GetMaximum()+h20reco->GetMaximum()/10);}
  myLegend14 = new TLegend(0.7,0.8,0.8,0.89);
  myLegend14 -> SetFillColor(0);
  myLegend14 -> SetBorderSize(0);
  myLegend14 -> SetTextSize(0.04);
  myLegend14 -> AddEntry(h20,"TruthLevel","l");
  myLegend14 -> AddEntry(h20reco,"RecoLevel","l");
  myLegend14->Draw("same");
  c20->SaveAs("SummerAnalysis/Summer_Student_Analysis/histograms/TreeTrials/600_400/MaxMin/NoCuts/m_CT");


  TCanvas* c21= new TCanvas("c21","c21",900,900);
  c21->cd();
  TH1F *h21 = new TH1F("h21","h21",100,0,1000);
  CollectionTree->Draw("m_bb>> h21","","goff");
  h21->Scale(ScalingFactor);
  h21->SetTitle("Invariant mass of the two stongest jets; m_bb");
  h21->Draw("HIST;same");
  TH1F *h21reco = new TH1F("h21reco","h21reco",100,0,1000);
  RecoTree->Draw("m_bb>> h21reco","","goff");
  h21reco->SetLineColor(kRed);
  h21reco->Scale(ScalingFactorReco);
  h21reco->Draw("Hist;same");
  if(h21->GetMaximum()<h21reco->GetMaximum())
    {h21->SetMaximum(h21reco->GetMaximum()+h21reco->GetMaximum()/10);}
  myLegend14 = new TLegend(0.7,0.8,0.8,0.89);
  myLegend14 -> SetFillColor(0);
  myLegend14 -> SetBorderSize(0);
  myLegend14 -> SetTextSize(0.04);
  myLegend14 -> AddEntry(h21,"TruthLevel","l");
  myLegend14 -> AddEntry(h21reco,"RecoLevel","l");
  myLegend14->Draw("same");
  c21->SaveAs("SummerAnalysis/Summer_Student_Analysis/histograms/TreeTrials/600_400/MaxMin/NoCuts/m_bb");







  //---------------------------2D plots no selecitons-----------------------------------

  TCanvas* c13 = new TCanvas("c13","c13",1000,900);
  c13->cd();
  TH2F *h13reco = new TH2F("h13reco","h13reco",20,0,200,20,0,400);  
  h13reco->SetTitle("ETMiss vs Invariant mass of min#DeltaR b-jet pairs-no max exclusion (zero leptons); InvMass; ETMiss");
  RecoTree->Draw("ETMiss:InvMass_Bij_minR1 >> h13reco","nBaselineLeptons==0","goff");
  h13reco->GetYaxis()->SetTitleOffset(1.3);
  h13reco->Draw("colz");
  //  if(h13->GetMaximum()<h13reco->GetMaximum())
  // {h13->SetMaximum(h13reco->GetMaximum()+h13reco->GetMaximum()/10);}

  c13->SaveAs("SummerAnalysis/Summer_Student_Analysis/histograms/TreeTrials/600_400/Min/NoCuts/ETMiss_InvMass_MINraw_noLeptons");


  TCanvas* c14 = new TCanvas("c14","c14",1000,900);
  c14->cd();
  TH2F *h14reco = new TH2F("h14reco","h14reco",20,0,200,20,0,400);
  h14reco->SetTitle("ETMiss vs Invariant mass of min#DeltaR b-jet pairs-with max exclusion (zero leptons); InvMass; ETMiss");
  RecoTree->Draw("ETMiss:InvMass_Bij_minR >> h14reco","nBaselineLeptons==0","goff");
  h14reco->GetYaxis()->SetTitleOffset(1.3);
  h14reco->Draw("colz");
  //  if(h14->GetMaximum()<h14reco->GetMaximum())                                                                                                                                                                  
  // {h14->SetMaximum(h14reco->GetMaximum()+h14reco->GetMaximum()/10);}                                                                                                                                           
  c14->SaveAs("SummerAnalysis/Summer_Student_Analysis/histograms/TreeTrials/600_400/Min/NoCuts/ETMiss_InvMass_MAXMINraw_noLeptons");

  TCanvas* c15 = new TCanvas("c15","c15",1000,900);
  c15->cd();
  TH2F *h15reco = new TH2F("h15reco","h15reco",20,0,400,20,0,400);  
  h15reco->SetTitle("ETMiss vs leading jet pT; Leading jet pT (zero leptons); ETMiss");
  RecoTree->Draw("ETMiss:pTj1 >> h15reco","nBaselineLeptons==0","goff");
  h15reco->GetYaxis()->SetTitleOffset(1.2);
  h15reco->Draw("colz");
  //  if(h15->GetMaximum()<h15reco->GetMaximum())
  // {h15->SetMaximum(h15reco->GetMaximum()+h15reco->GetMaximum()/10);}


  c15->SaveAs("SummerAnalysis/Summer_Student_Analysis/histograms/TreeTrials/600_400/Min/NoCuts/ETMiss_pTj1_noVeto_noLeptons");



  TCanvas* c16 = new TCanvas("c16","c16",1000,900);
  c16->cd();
  TH2F *h16reco = new TH2F("h16reco","h16reco",20,0,4,20,0,400);  
  h16reco->SetTitle("ETMiss vs minDPhi; MinDPhi; ETMiss");
  RecoTree->Draw("ETMiss:minDPhi >> h16reco","","goff");
  h16reco->GetYaxis()->SetTitleOffset(1.2);
  h16reco->Draw("colz");
  //  if(h16->GetMaximum()<h16reco->GetMaximum())
  // {h16->SetMaximum(h16reco->GetMaximum()+h16reco->GetMaximum()/10);}


  c16->SaveAs("SummerAnalysis/Summer_Student_Analysis/histograms/TreeTrials/600_400/Min/NoCuts/ETMiss_MinDPhi");


  cout<<"MaxMin Analysis method cutflow"<<endl;
  int NoCuts = CollectionTree->Draw("1","","goff");
  cout<<"Number of entries (no cuts)= "<<NoCuts*ScalingFactor<<endl;

  int Cut1 = CollectionTree->Draw("1","ETMiss>200","goff");
  cout<<"Number of entries; MET>200= "<<Cut1*ScalingFactor<<endl;
    
  int Cut2 = CollectionTree->Draw("1","ETMiss>200 && pTj1>80","goff");
  cout<<"Number of entries; MET>200, pTj1>80= "<<Cut2*ScalingFactor<<endl;

  int Cut3 = CollectionTree->Draw("1","ETMiss>200 && pTj1>80 && minDPhijMET>0.4","goff");
  cout<<"Number of entries; MET>200, pTj1>80, minDPhijMET>0.4= "<<Cut3*ScalingFactor<<endl;

  int Cut4 = CollectionTree->Draw("1","ETMiss>200 && pTj1>80 && minDPhijMET>0.4 && nBJets>=4","goff");
  cout<<"Number of entries; MET>200, pTj1>80, minDPhijMET>0.4, nBJets>=4= "<<Cut4*ScalingFactor<<endl;

  int Cut5 = CollectionTree->Draw("1","ETMiss>200 && pTj1>80 && minDPhijMET>0.4 && nBJets>=4 && minDR<2.5","goff");
  cout<<"Number of entries; MET>200, pTj1>80, minDPhijMET>0.4, nBJets>=4, minDR<2.5= "<<Cut5*ScalingFactor<<endl;

  int Cut6 = CollectionTree->Draw("1","ETMiss>200 && pTj1>80 && minDPhijMET>0.4 && nBJets>=4 && minDR<2.5 && InvMass_Bij_minR<145 && InvMass_Bij_minR>95 ","goff");
  cout<<"Number of entries; MET>200, pTj1>80, minDPhijMET>0.4, nBJets>=4, minDR<2.5, 95<InvMass<145= "<<Cut6*ScalingFactor<<endl;


  cout<<"Min Analysis method cutflow"<<endl;
  int MinNoCuts = CollectionTree->Draw("1","","goff");
  cout<<"Number of entries (no cuts)= "<<NoCuts*ScalingFactor<<endl;

  int MinCut1 = CollectionTree->Draw("1","ETMiss>200","goff");
  cout<<"Number of entries; MET>200= "<<MinCut1*ScalingFactor<<endl;
    
  int MinCut2 = CollectionTree->Draw("1","ETMiss>200 && pTj1>80","goff");
  cout<<"Number of entries; MET>200, pTj1>80= "<<MinCut2*ScalingFactor<<endl;

  int MinCut3 = CollectionTree->Draw("1","ETMiss>200 && pTj1>80 && minDPhijMET>0.4","goff");
  cout<<"Number of entries; MET>200, pTj1>80, minDPhijMET>0.4= "<<MinCut3*ScalingFactor<<endl;

  int MinCut4 = CollectionTree->Draw("1","ETMiss>200 && pTj1>80 && minDPhijMET>0.4 && nBJets>=3","goff");
  cout<<"Number of entries; MET>200, pTj1>80, minDPhijMET>0.4, nBJets>=3= "<<MinCut4*ScalingFactor<<endl;

  int MinCut5 = CollectionTree->Draw("1","ETMiss>200 && pTj1>80 && minDPhijMET>0.4 && nBJets>=4 && minDR1<2.5","goff");
  cout<<"Number of entries; MET>200, pTj1>80, minDPhijMET>0.4, nBJets>=3, minDR1<2.5= "<<MinCut5*ScalingFactor<<endl;

  int MinCut6 = CollectionTree->Draw("1","ETMiss>200 && pTj1>80 && minDPhijMET>0.4 && nBJets>=3 && minDR1<2.5 && InvMass_Bij_minR1<145 && InvMass_Bij_minR1>95 ","goff");
  cout<<"Number of entries; MET>200, pTj1>80, minDPhijMET>0.4, nBJets>=3, minDR1<2.5, 95<InvMass1<145= "<<MinCut6*ScalingFactor<<endl;

  gApplication->Terminate();
    
}


