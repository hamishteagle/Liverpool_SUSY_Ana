// put the header for the full variable calculations here
#ifndef CalculateVariables_h
#define CalculateVariables_h

#include "NewObjectDef.h"

#include "TMctLib.h"
class CalculateVariables

{
 public:
 CalculateVariables(NewObjectDef *objects, xAOD::TStore* evtStore, bool isTruth, bool doPhotons, bool isData, std::string systematic);
  void CalculateOneLepVariables(NewObjectDef *objects, TLorentzVector b1v, TLorentzVector b2v, TLorentzVector tj1v);
  void CalculateTwoLepVariables(NewObjectDef *objects, TLorentzVector b1v, TLorentzVector b2v);
  void CalculatePhotonMET(NewObjectDef *objects);
  void CalculateShapeVariables(NewObjectDef *objects);
  void CalculateRazorVariables(NewObjectDef *objects);


 public:

  //Object containers
  xAOD::MuonContainer *goodMuon_cont = nullptr;
  xAOD::MuonContainer *badMuon_cont = nullptr;
  xAOD::MuonContainer *baselineMuon_cont = nullptr;
  xAOD::ElectronContainer *goodElectron_cont = nullptr;
  xAOD::ElectronContainer *baselineElectron_cont = nullptr;
  xAOD::TauJetContainer *goodTau_cont = nullptr;
  xAOD::TauJetContainer *baselineTau_cont = nullptr;
  xAOD::PhotonContainer *goodPhoton_cont = nullptr;
  xAOD::JetContainer *goodJet_cont = nullptr;
  xAOD::JetContainer *goodJet_beforeOR_cont = nullptr;
  xAOD::JetContainer *baselineJet_cont = nullptr;
  xAOD::JetContainer *bJet_cont = nullptr;
  xAOD::JetContainer *nonBJet_cont = nullptr;
  TVector2 *METvector_cont = nullptr;


  int nMuon; //
  int nBadMuon; //
  int nElectron; //
  int nTau; //
  int nLepton; //
  int nPhoton;
  double eTMiss; //
  double eTMissPhi; //
  int nBaselineMuon; //
  int nBaselineElectron; //
  int nBaselineTau; //
  int nBaselineLepton; //
  bool Stop0L_tauVeto; //

  // scale factors
  double electronTrigSF;
  double leptonSF;
  double bJetSF;
  double JVTSF;
  double electronSF;
  double muonSF;
  //  double muonRecoSF;
  double muonTrigSF;
  // adjusted ETMiss is for the regions with electrons to add to the MET


  double adjustedETMiss; //
  double adjustedETMissPhi; //
  double PhotonETMiss; //
  double PhotonETMissPhi; //
  int nJets; //
  int nJets_beforeOR; //
  int nbJets; //
  int nNonBJets; //


  int njet20;
  int njet25;
  int njet30;
  int njet35;
  int njet50;





  bool primaryB; //
  bool secondB; //
  bool leadingBs; //

  // Mass related variables

  double m_bb; //
  double m_tautau; //
  double m_taulep;
  double m_CT; //
  double m_CT_corr; //
  double m_ll;
  double h_T; //
  double m_T;

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

  double delPhi_tj1MET;
  double delPhi_tj2MET;
  double delPhi_tj1tj2;
  double mindelPhi_tjMET;
  double maxdelPhi_tjMET;

  double dRtj1b1;
  double dRtj1b2;
  double dRtj1b3;
  double dRtj1b4;

  std::vector<double> dRtj1v;
  std::vector<double> dRtj2v;


  double dRtj2b1;
  double dRtj2b2;
  double dRtj2b3;
  double dRtj2b4;

  double mindRtj1b;
  double mindRtj2b;
  int nb1;
  int nb2;


  double m_Tbmin;
  double m_Tb1;
  double m_Tb2;
  double dPhib1_MET;
  double dPhib2_MET;
  double mindPhib_MET;



  double m_jj; //
  double m_jjb1; //
  double m_jjb2; //
  double maxm_jjb; //
  double minm_jjb; //
  double m_b1l;
  double m_b2l;
  double m_lbb;
  double minm_bl;
  double maxm_bl;
  double mbLmin;
  double mEff2j; //
  double mEff3j; //
  double adjustedmEff2j;
  double adjustedmEff3j;

  double ratioMETmEff2j;
  double ratioMETmEff3j;
  double adjustedRatio2j;
  double adjustedRatio3j;


  // Jet and Lepton properties:

  double pTj1; //
  double pTj2; //
  double pTj3; //
  double pTj4; //
  double pTj5; //
  double pTj6; //
  double pTj7; //
  double pTj8; //
  double etaj1; //
  double etaj2; //
  double etaj3; //
  double etaj4; //
  double phij1; //
  double phij2; //
  double phij3; //
  double phij4; //

  double pTZ; //
  double etaZ; //
  double phiZ; //
  double DR_Zb1;
  double DR_Zb2;
  double minDR_Zb;
  double DPhi_Zb1;
  double DPhi_Zb2;
  double DEta_Zb1;
  double DEta_Zb2;

  double DRj1j2;
  double DRj1j3;
  double DRj1j4;
  double DRj2j3;
  double DRj2j4;
  double DRj3j4;

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
  int b1_quantile;
  int b2_quantile;
  int b3_quantile;
  int b4_quantile;
  int truthFlavb1;
  int truthFlavb2;


  double pTmu1;
  double pTmu2;
  double pTel1;
  double pTel2;
  double pTtj1;
  double pTtj2;
  double pTtj1tj2;

  double pTl1;
  double pTl2;
  double etal1;
  double etal2;
  double phil1;
  double phil2;
  double etatj1;
  double etatj2;
  double etatj1tj2;
  double phitj1;
  double phitj2;
  double phitj1tj2;
  double lep1flavour;
  double lep2flavour;

 public:
  double pTgamma;
  double etagamma;
  double phigamma;



  // Azimuthal Angle Variables


  double delPhi1; //
  double delPhi2; //
  double delPhi3; //
  double delPhi4; //
  double minDelPhi; //
  double minDelPhi_4; //
  double adjMinDelPhi; //
  double adjDelPhi1;
  double dPhib1b2;

  double dPhiL1L2;

  double dPhiL1MET;
  double dPhiL2MET;

  double dPhiL1b1;
  double dPhiL1b2;
  double dPhiL2b1;
  double dPhiL2b2;

  double minDPhiLb;

  // delta eta variables should be initialised to something sensible too, 99 seems reasonable
  double dEtab1b2;
  double dEtaL1L2;

  double dEtaL1bSystem;
  double dEtaL1b1;
  double dEtaL1b2;

  double dEtaL2bSystem;
  double dEtaL2b1;
  double dEtaL2b2;

  double minDEtaLb;

  // delta R variables should also be sensible, again go with 99

  double dRtj1tj2;

  double dRb1b2;
  double dRL1b1;
  double dRL1b2;
  double dRL2b1;
  double dRL2b2;
  double dRL1L2;
  double minDRLb;

  double dRjjb1; //
  double dRjjb2; //
  double minDRjjb; //
  double maxDRjjb; //

  double ratioDRbbHt;


  // Razor Variable Crap

  double RJVars_QCD_Delta; //
  double RJVarsSS_invGamma; //
  double RJVarsSS_s_hat; //
  double RJVarsSS_MDelR; //
  double RJVarsSS_wrongMDelR; //

  // Aplanarity stuff

  double Aplanarity; //
  double transformedAplan; //
  double Sphericity; //

  bool elTriggerMatch;
  bool muTriggerMatch;
  bool phTriggerMatch;


  // b-jet related stuff

  double b1m;
  double b2m;

  double b1MV2wgt;
  double b2MV2wgt;
  double minbMV2weight;

  double b1_ntrk;
  double b2_ntrk;

  bool TruthFile;


  // Tools

  std::unique_ptr<TMctLib> mctTool;


  // DM Specific

  double jet_imbalance; //
  double minDRjj;
  double dEtajj_max;
  double x1;
  double x1b;
  double y1;
  double ctanh_bb;
  double dPhi_bMET;

  // tbMET Specific

  double delPhiMinb;
  double all_HT;
  double all_METSig;
  double all_Meff;
  double nextrajets50;
  double amT2;
  double metsig_New;

  bool calculatePhotons;


  // Multi b specific
  //MaxMin alg
  double maxDR;
  double InvMass_Bij_maxDR;
  double Imbalance_maxDR;
  double JetAsymm_maxDR;

  double minDR;
  double minDR1;

  //SRB algs
  double SRB_minDR;
  double SRB_minDR2;
  double SRB_Hmbb;

  double SRB_Higgsino_minDR;
  double SRB_Higgsino_maxDR;
  double SRB_Higgsino_Hmbb;



  double JetAsymmR_min;
  double InvMass_Bij_minR;
  double JetAsymmR_min1;
  double InvMass_Bij_minR1;


  double tau1_TruthMatched;
  double tau2_TruthMatched;

  bool inMultiJetTriggerPlateau;



};

#endif
