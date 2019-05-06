// header file for tree service


#ifndef TreeService_h
#define TreeService_h


#include "NewObjectDef.h"
#include "PreliminarySel.h"
#include "CalculateVariables.h"
#include "MapVariables.h"
#include "MCChecks.h"
#include "TTree.h"
#include "TFile.h"
#include <string>
#include <EventLoopAlgs/NTupleSvc.h>
#include <vector>

class TreeService

{

 public:
  TreeService(TTree *outputTree, TDirectory *OutDir);

  void fillTree(NewObjectDef *objects, PreliminarySel &region, CalculateVariables &variables, MCChecks MCTruthInfo , double mFinalWeight, double mInitialWeight, double puWeight, double SFmCTbbll, bool TrigMET, bool TrigMu, bool TrigEl, bool TrigDilep, bool TrigGamma, bool Trig6j, std::vector<std::string> muon_triggers, std::vector<int> muon_decisions, std::vector<std::string> electron_triggers, std::vector<int> electron_decisions,std::vector<std::string> dilepton_triggers, std::vector<int> dilepton_decisions, double LeptonTriggerSF, double puSumWeights, double TRUTHMET, double TRUTHHT ,bool CoreFlags, bool SCTFlag, bool LArTileFlag, bool passGRL, bool passedPrimVertex, bool passedJetClean, bool passedCosmicMu, bool passedMuonClean, double RNo, double RenormedMCWgt, int LumiYear, double m_averageIntPerCrossing, double m_actualIntPerCrossing, double m_xsec, double m_filteff, double m_kfactor);

  void writeTree();


 public:

  // Store our Trees. Need to set up the structure in the initialise

  TTree *tree;


  // General Variables

  double mcID;
  double RunNumber;
  unsigned long long eventNumber;
  double mcEventWeight;
  double RenormedMcEventWeight;
  int year;
  double m_averageIntPerX;
  double m_actualIntPerX;
  std::vector<float> weightsVector;

  double xsec;
  double filteff;
  double kfactor;

  double lumiScaled;
  double sampleSFmCTbbll;
  double puWgt;
  bool leadingbs;
  bool primaryb;
  bool secondaryb;

  //Initial event cleaning
  bool coreFlag;
  bool sctFlag;
  bool LArTileFlag;
  bool passedPrimVertex;
  bool passedGRL;

  //Object cleaning cuts
  bool passedJetClean;
  bool passedCosmicMu;
  bool passedMuonClean;

  //Triggers

  //std::vector<int> triggerDecisions;
  bool passedMETTrigger;
  bool passedMuTrigger;
  bool passedElTrigger;
  bool passedGammaTrigger;
  bool passedDileptonTrigger;

  bool elTriggerMatch;
  bool phTriggerMatch;
  bool muTriggerMatch;

  std::vector<std::string> mu_triggers;
  std::vector<std::string> el_triggers;
  std::vector<std::string> dilep_triggers;
  std::vector<int> dilep_decisions;
  std::vector<int> mu_decisions;
  std::vector<int> el_decisions;

  double pileUpSumOfWeights;
  double truthFilterMET;
  double truthFilterHT;
  int jetFilterno;
  int jetFilterno_prompt;

  double pTZBoson;
  double etaZBoson;
  double pTZBoson_Sherpa;
  double etaZBoson_Sherpa;
  bool Zqq;
  bool Zll;
  double duplicateVar;
  std::string CutsRegion;
  double m_bb;
  double m_tautau;
  double m_CT;
  double m_CTcorr;
  double m_ll;
  double h_T;
  double m_T;
  double mbLmin;

  int njet20;
  int njet25;
  int njet30;
  int njet35;
  int njet50;

  double Asymmetry;

  double m_Tjmin;
  double m_Tj1;
  double m_Tj2;
  double m_Tj3;
  double m_Tj4;

  double m_Ttj1;
  double m_Ttj2;
  double m_Ttj1tj2;
  double minm_Ttj;
  double maxm_Ttj;

  double m_Tbmin;
  double m_Tb1;
  double m_Tb2;
  double dPhib1_MET;
  double dPhib2_MET;
  double mindPhib_MET;



  double Reco_pTZ; //
  double Reco_etaZ; //
  double Reco_phiZ; //
  double DR_Zb1;
  double DR_Zb2;
  double minDR_Zb;
  double DPhi_Zb1;
  double DPhi_Zb2;
  double DEta_Zb1;
  double DEta_Zb2;


  double dPhij1MET;
  double dPhij2MET;
  double dPhij3MET;
  double dPhij4MET;
  double dPhiL1MET;
  double dPhiL2MET;

  double dPhib1b2;
  double dPhiL1L2;

  double dPhiL1b1;
  double dPhiL1b2;
  double dPhiL2b1;
  double dPhiL2b2;

  double minDPhijMET;
  double minDPhijMET_4;
  double adjDPhij1MET;
  double minAdjDPhijMET;
  double minDPhiLb;

  double dEtab1b2;
  double dEtaL1L2;

  double dEtaL1bSystem;
  double dEtaL1b1;
  double dEtaL1b2;

  double dEtaL2bSystem;
  double dEtaL2b1;
  double dEtaL2b2;
  double minDEtaLb;


  double dRtj1tj2;

  double dRb1b2;
  double dRL1b1;
  double dRL1b2;
  double dRL2b1;
  double dRL2b2;
  double minDRLb;


  double DRj1j2;
  double DRj1j3;
  double DRj1j4;
  double DRj2j3;
  double DRj2j4;
  double DRj3j4;

  double pTj1;
  double pTj2;
  double pTj3;
  double pTj4;
  double pTj5;
  double pTj6;
  double pTj7;
  double pTj8;

  int j1_bQuantile;
  int j2_bQuantile;
  int j3_bQuantile;
  int j4_bQuantile;

  //ISR variables
  double delPhi1;
  double delPhi2;
  double delPhi3;

  double etaj1;
  double etaj2;
  double etaj3;
  double etaj4;
  double phij1;
  double phij2;
  double phij3;
  double phij4;

  double pTl1;
  double pTl2;
  double etal1;
  double etal2;
  double phil1;
  double phil2;
  double m_taulep;
  double lep1flavour;
  double lep2flavour;

  double pTgamma;
  double etagamma;
  double phigamma;
  double nPhoton;

  double pTb1;
  double pTb2;
  double pTb3;
  double pTb4;
  double etab1;
  double etab2;
  double etab3;
  double etab4;
  double phib1;
  double phib2;
  double phib3;
  double phib4;

  double delPhi_tj1MET;
  double delPhi_tj2MET;
  double delPhi_tj1tj2;
  double mindelPhi_tjMET;
  double maxdelPhi_tjMET;

  double dRtj1b1;
  double dRtj1b2;
  double dRtj1b3;
  double dRtj1b4;

  double dRtj2b1;
  double dRtj2b2;
  double dRtj2b3;
  double dRtj2b4;

  double mindRtj1b;
  double mindRtj2b;
  int nb1;
  int nb2;

  double pTmu1;
  double pTmu2;
  double pTel1;
  double pTel2;
  double pTtj1;
  double pTtj2;

  double etatj1;
  double etatj2;
  double phitj1;
  double phitj2;

  int nJets;
  int nJets_beforeOR;
  int nBJets;
  int nLeptons;
  int nBaselineLeptons;
  int nMuons;
  int nBadMuons;

  int nBaselineElectrons;
  int nBaselineTaus;
  int nBaselineMuons;


  int nElectrons;
  int nTaus;

  double ETMiss;
  double ETMissPhi;
  double mEff2j;
  double ratioMETmEff2j;
  double mEff3j;
  double ratioMETmEff3j;

  double adjustedETMiss;
  double adjustedETMissPhi;
  double adjustedmEff2j;
  double adjustedRatio2j;
  double adjustedmEff3j;
  double adjustedRatio3j;

  double truthBosonPt;
  double m_finalWeightSum;
  double m_intialWeightSum;


  double m_jj;
  double m_jjb1;
  double m_jjb2;
  double maxm_jjb;
  double minm_jjb;
  double dRjjb1;
  double dRjjb2;
  double minDRjjb;
  double maxDRjjb;
  double m_b1l;
  double m_b2l;
  double m_lbb;
  double minm_bl;
  double maxm_bl;

  double RatioDRbbHt;

  // Razor Variable Crap

  double QCDDelta;
  double invGammaRp1;
  double sHatR;
  double MDelR;
  double wrongMDelR;

  double Aplanarity;
  double TransformedAplanarity;
  double Sphericity;

  // Scale Factors

  double muonSF;
  double oldMuonSF;
  double electronSF;
  double electronTriggerSF;
  //  double muonRecoSF;
  double muonTriggerSF;
  double dilepTriggerSF;
  double tauSF;
  double tauTriggerSF;
  double bJetSF;
  double JVTSF;
  double photonSF;
  double leptonTriggerSF;



  double b1m;
  double b2m;
  double b1MV2wgt;
  double b2MV2wgt;
  double minbMV2weight;

  double b1_ntrk;
  double b2_ntrk;

  // DM Specific

  double jet_imbalance; //
  double minDRjj;
  double dEtajj_max;

  // tbMET Specific

  double delPhiMinb;
  double all_HT;
  double all_METSig;
  double all_Meff;
  double nextrajets50;
  double amT2;


  double Weight;
  double MEWeight;
  double WeightNormalisation;
  double NTrials;
  double MUR0p5_MUF0p5_PDF261000;
  double MUR0p5_MUF1_PDF261000;
  double MUR1_MUF0p5_PDF261000;
  double MUR1_MUF1_PDF261000;
  double MUR1_MUF2_PDF261000;
  double MUR2_MUF1_PDF261000;
  double MUR2_MUF2_PDF261000;
  double MUR1_MUF1_PDF261001;
  double MUR1_MUF1_PDF261002;



  double maxDR;
  double InvMass_Bij_maxDR;
  double Imbalance_maxDR;
  double JetAsymm_maxDR;
  double minDR;
  double minDR1;
  double JetAsymmR_min;
  double InvMass_Bij_minR;
  double JetAsymmR_min1;
  double InvMass_Bij_minR1;

  double SRB_minDR;
  double SRB_minDR2;
  double SRB_Hmbb;

  double SRB_Higgsino_minDR;
  double SRB_Higgsino_maxDR;
  double SRB_Higgsino_Hmbb;

  int ttbar_W1_decay;
  int ttbar_tau1_decay;

  int ttbar_W2_decay;
  int ttbar_tau2_decay;

  double tau_1_prongs;
  double tau_2_prongs;

  std::vector<double> jet_pT;
  std::vector<double> jet_eta;
  std::vector<double> jet_phi;
  std::vector<double> jet_E;
  std::vector<double> jet_M;
  std::vector<double> jet_flav;
  std::vector<double> jet_bWgt;
  std::vector<double> jet_truflav;
  std::vector<double> jet_ntrks;
  bool Stop0L_tauVeto;

  std::vector<double> el_pT;
  std::vector<double> el_eta;
  std::vector<double> el_phi;
  std::vector<double> el_E;
  std::vector<double> el_Q;

  std::vector<double> mu_pT;
  std::vector<double> mu_eta;
  std::vector<double> mu_phi;
  std::vector<double> mu_E;
  std::vector<double> mu_Q;

  std::vector<double> tau_pT;
  std::vector<double> tau_eta;
  std::vector<double> tau_phi;
  std::vector<double> tau_E;
  std::vector<double> tau_Q;
  std::vector<double> tau_SmallestDR;
  std::vector<int> tau_associatedTrue;


  std::vector<double> fatJet8_pT;
  std::vector<double> fatJet8_eta;
  std::vector<double> fatJet8_phi;
  std::vector<double> fatJet8_E;
  std::vector<double> fatJet8_M;

  std::vector<double> fatJet12_pT;
  std::vector<double> fatJet12_eta;
  std::vector<double> fatJet12_phi;
  std::vector<double> fatJet12_E;
  std::vector<double> fatJet12_M;

  double metsig_New;

  int multiJetTriggerPlateau;
  bool multiJetTriggerPassed;


};
#endif
