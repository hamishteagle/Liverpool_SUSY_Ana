#include <vector>
#include "TLatex.h"
void TruthbJetpT(){
  

  TFile *f1 = TFile::Open("/hepstore/hteagle/ExclusionInvestigation/mc15_13TeV.390234.MGPy8EG_A14N23LO_BB_onestepN2hN1_400_230_100_MET100.merge.DAOD_TRUTH1.e5671_p2913/hist-DAOD_TRUTH1.root");
  TFile *f2 = TFile::Open("/hepstore/hteagle/ExclusionInvestigation/mc15_13TeV.390134.MGPy8EG_A14N23LO_BB_onestepN2hN1_400_300_60_MET100.merge.DAOD_TRUTH1.e5671_p2913/hist-DAOD_TRUTH1.root");
gStyle->SetOptStat(0);
 
  if(f1==0||f2==0)
    {
      cout<<"Couldn't open input file"<<endl;
      gApplication->Terminate();
    }
  
  vector <double> Maxima;


  double filterEff_400 =0.367283;
  double xSection_400 =1.83;
  TH1F *mcWgt_400= (TH1F*)f1->Get("h_mcWgt");
  double nMacro_400 = mcWgt_400->GetEntries();
  double lEff_400 = nMacro_400/(xSection_400*1000*filterEff_400);
  double SF_400 = 120/(lEff_400);

  double filterEff_400_MN1= 0.710976;
  double xSection_400_MN1= 1.83;
  TH1F *mcWgt_400_MN1= (TH1F*)f2->Get("h_mcWgt");
  double nMacro_400_MN1=mcWgt_400_MN1->GetEntries(); 
  double lEff_400_MN1 = nMacro_400_MN1/(xSection_400_MN1*1000*filterEff_400_MN1);
  double SF_400_MN1 = 120/(lEff_400_MN1);
  

  cout<<"Scaling Factor= "<<SF_400<<endl;  
  cout<<"Scaling Factor_MN1 = "<<SF_400_MN1<<endl;


  
  
  TH1F *pTb1 = (TH1F*)f2->Get("pT_b1");
  TH1F *pTb2 = (TH1F*)f2->Get("pT_b2");
  TH1F *pTb3 = (TH1F*)f2->Get("pT_b3");
  TH1F *pTb4 = (TH1F*)f2->Get("pT_b4");
  

  TCanvas *c1 = new TCanvas("c1","c1",900,900);
  c1->cd();
  c1->SetLogy();
  pTb1->SetLineColor(kRed);
  pTb1->SetLineWidth(3);
  pTb1->Scale(SF_400_MN1);
  //  pTb1->Rebin(4);
  pTb2->SetLineColor(kBlue);
  pTb2->SetLineWidth(3);
  pTb2->Scale(SF_400_MN1);
  // pTb2->Rebin(4);
  pTb3->SetLineColor(kRed);
  pTb3->SetLineWidth(3);
  pTb3->Rebin(4);
  pTb4->SetLineColor(kGreen);
  pTb4->SetLineWidth(3);
  pTb4->Rebin(4);
  
  Maxima ={pTb1->GetMaximum(),pTb2->GetMaximum(),pTb3->GetMaximum(),pTb4->GetMaximum()};
  sort(Maxima.rbegin(),Maxima.rend());
  pTb1->SetMaximum(Maxima[0]+(Maxima[0]));


  pTb1->SetTitle("Transverse momentum of the four leading b-jets (Truth level);p_{T}/GeV;Events scaled to 120 fb^{-1}");
  pTb1->GetXaxis()->SetRangeUser(0,100);
  pTb1->GetYaxis()->SetTitleOffset(1.3);
  pTb1->SetMinimum(1);



  pTb1->Draw("HIST");
  pTb2->Draw("HIST;same");
  //  pTb3->Draw("HIST;same");
  //  pTb4->Draw("HIST;same");


  TLegend *leg = new TLegend(0.73,0.15,0.9,0.3);
  leg->SetFillStyle(0);
  leg->SetLineWidth(0);
  leg->AddEntry(pTb1,"pTb1","L");
  leg->AddEntry(pTb2,"pTb2","L");
  //leg->AddEntry(pTb3,"Third","L");
  //leg->AddEntry(pTb4,"Fourth","L");
  leg->Draw("same");

  TLatex *latex = new TLatex();
  latex->DrawLatex(5,Maxima[0],"#scale[0.8]{ATLAS Internal} #scale[0.5]{#font[42]{M(#tilde{b})=400, M(#tilde{#Chi_{2}^{0}})=300, M(#tilde{#Chi_{1}^{0}})=60}}");


  c1->SaveAs("SummerAnalysis/Summer_Student_Analysis/histograms/Sbottomg3_29_11/400_300_60(100GeV).pdf");







  gApplication->Terminate();
}
