void CutflowMacro(){
#include "TFile.h"
  
  TFile *f1 = TFile::Open("/hepstore/hteagle/ExclusionInvestigation/mc15_13TeV.390146.MGPy8EG_A14N23LO_BB_onestepN2hN1_600_400_60.merge.DAOD_TRUTH1.e5671_p2913/hist-DAOD_TRUTH1.root");
  

  if(f1==0)
    {cout<<"Couldn't find input file"<<endl;
      gApplication->Terminate();
    }
  TH1F *Wgt = (TH1F*)f1->Get("h_mcWgt");
  

  TH1F *MET = (TH1F*)f1->Get("h_Counter_CUT1a");
  cout<<"MET>250 cut = "<<MET->GetEntries()/(Wgt->GetEntries())<<endl;
  TH1F *Leading =(TH1F*)f1->Get("h_Counter_CUT1b");
  cout<<"Leading jet pT>80 = "<<Leading->GetEntries()/(Wgt->GetEntries())<<endl;
  TH1F *MinDPhi = (TH1F*)f1->Get("h_Counter_CUT1c");
  cout<<"minDPhi>0.4 = "<<MinDPhi->GetEntries()/(Wgt->GetEntries())<<endl;
  TH1F *NB4 = (TH1F*)f1->Get("h_Counter_CUTd1");
  cout<<"NbJets>=4 = "<<NB4->GetEntries()/(Wgt->GetEntries())<<endl;
 
  TH1F *minDR1 = (TH1F*)f1->Get("h_Counter_newCUTd3");
  cout<<"minDR1<2.5 = "<<minDR1->GetEntries()/(Wgt->GetEntries())<<endl;
  TH1F *Inv1 = (TH1F*)f1->Get("h_Counter_newCUTd3_1");
  cout<<"Invariant mass1 = "<<Inv1->GetEntries()/(Wgt->GetEntries())<<endl;
  
  TH1F *minDR = (TH1F*)f1->Get("h_Counter_CUTd1_1");
  cout<<"minDR<2.5 = "<<minDR->GetEntries()/(Wgt->GetEntries())<<endl;
  TH1F *Inv = (TH1F*)f1->Get("h_Counter_CUTd1_2");
  cout<<"Invariant mass = "<<Inv->GetEntries()/(Wgt->GetEntries())<<endl;












  gApplication->Terminate();
}
