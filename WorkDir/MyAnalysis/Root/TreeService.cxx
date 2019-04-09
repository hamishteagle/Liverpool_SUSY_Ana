// source file for tree service

#include "MyAnalysis/TreeService.h"
#include "TFile.h"
#include <string>
#include "xAODEgamma/Electron.h"
#include "xAODMuon/Muon.h"

TreeService::TreeService(TTree *outputTree, TDirectory *OutDir){

  tree = outputTree;

  tree->SetDirectory(OutDir);
  tree->SetAutoFlush(500);
  //gDirectory->cd(OutDir.c_str());

  tree->Branch("mcID", &mcID);
  tree->Branch("year", &year);
  tree->Branch("RunNumber", &RunNumber);
  tree->Branch("eventNumber", &eventNumber);
  tree->Branch("mcEventWeight", &mcEventWeight);
  tree->Branch("RenormedMcEventWeight", &RenormedMcEventWeight);
  tree->Branch("weightsVector", &weightsVector);
  tree->Branch("sampleSFmCTbbll",&sampleSFmCTbbll);
  tree->Branch("pileUpSumOfWeights",&pileUpSumOfWeights);
  tree->Branch("m_averageIntPerX",&m_averageIntPerX);
  tree->Branch("m_actualIntPerX",&m_actualIntPerX);


  //Initial event cleaning
  tree->Branch("Region", &CutsRegion);
  tree->Branch("coreFlag", &coreFlag);
  tree->Branch("sctFlag", &sctFlag);
  tree->Branch("LArTileFlag",&LArTileFlag);
  tree->Branch("passedPrimVertex", &passedPrimVertex);
  tree->Branch("passedGRL", &passedGRL);

  //Object cleaning cuts
  tree->Branch("passedJetClean", &passedJetClean);
  tree->Branch("passedCosmicMu", &passedCosmicMu);
  tree->Branch("passedMuonClean", &passedMuonClean);

  // Triggers
  tree->Branch("passedMETTrigger", &passedMETTrigger);
  tree->Branch("passedMuTrigger", &passedMuTrigger);
  tree->Branch("passedElTrigger", &passedElTrigger);
  tree->Branch("passedGammaTrigger", &passedGammaTrigger);

  tree->Branch("muon_triggers",&mu_triggers);
  tree->Branch("muon_decisions", &mu_decisions);
  tree->Branch("electron_triggers",&el_triggers);
  tree->Branch("electron_decisions", &el_decisions);
  tree->Branch("MET_triggers",&MET_triggers);
  tree->Branch("MET_decisions", &MET_decisions);


  //Trigger matching
  tree->Branch("elTriggerMatch", &elTriggerMatch);
  tree->Branch("muTriggerMatch", &muTriggerMatch);
  tree->Branch("phTriggerMatch", &phTriggerMatch);

  tree->Branch("truthFilterMET", &truthFilterMET);
  tree->Branch("truthFilterHT", &truthFilterHT);


  tree->Branch("m_bb", &m_bb);
  tree->Branch("m_CTcorr",&m_CTcorr);
  tree->Branch("m_ll", &m_ll);
  tree->Branch("h_T", &h_T);
  tree->Branch("m_T", &m_T);

  tree->Branch("njet20" ,&njet20);
  tree->Branch("njet25" ,&njet25);
  tree->Branch("njet30", &njet30);
  tree->Branch("njet35", &njet35);
  tree->Branch("njet50", &njet50);

  tree->Branch("pTj1",&pTj1);
  tree->Branch("pTj2",&pTj2);
  tree->Branch("pTj3",&pTj3);
  tree->Branch("pTj4",&pTj4);
  tree->Branch("pTj5",&pTj5);
  tree->Branch("pTj6",&pTj6);
  tree->Branch("pTj7",&pTj7);
  tree->Branch("pTj8",&pTj8);

  tree->Branch("pTl1",&pTl1);
  tree->Branch("pTl2",&pTl2);
  tree->Branch("etal1",&etal1);
  tree->Branch("etal2",&etal2);
  tree->Branch("phil1",&phil1);
  tree->Branch("phil2",&phil2);
  tree->Branch("lep1flavour",&lep1flavour);
  tree->Branch("lep2flavour",&lep2flavour);


  tree->Branch("pTel1",&pTel1);
  tree->Branch("pTel2",&pTel2);
  tree->Branch("pTmu1",&pTmu1);
  tree->Branch("pTmu2",&pTmu2);
  tree->Branch("pTtj1",&pTtj1);
  tree->Branch("pTtj2",&pTtj2);

  tree->Branch("pTb1",&pTb1);
  tree->Branch("pTb2",&pTb2);
  tree->Branch("pTb3",&pTb3);
  tree->Branch("pTb4",&pTb4);
  tree->Branch("etab1",&etab1);
  tree->Branch("etab2",&etab2);
  tree->Branch("etab3",&etab3);
  tree->Branch("etab4",&etab4);
  tree->Branch("phib1",&phib1);
  tree->Branch("phib2",&phib2);
  tree->Branch("phib3",&phib3);
  tree->Branch("phib4",&phib4);

  tree->Branch("nJets",&nJets);
  tree->Branch("nJets_beforeOR",&nJets_beforeOR);
  tree->Branch("nBJets",&nBJets);
  tree->Branch("nLeptons",&nLeptons);
  tree->Branch("nBaselineLeptons",&nBaselineLeptons);
  tree->Branch("nBaselineElectrons",&nBaselineElectrons);
  tree->Branch("nBaselineTaus",&nBaselineTaus);
  tree->Branch("nBaselineMuons",&nBaselineMuons);
  tree->Branch("nMuons",&nMuons);
  tree->Branch("nBadMuons",&nBadMuons);
  tree->Branch("nElectrons",&nElectrons);
  tree->Branch("nTaus",&nTaus);
  tree->Branch("nPhoton",&nPhoton);
  tree->Branch("ETMiss", &ETMiss);
  tree->Branch("ETMissPhi", &ETMissPhi);
  tree->Branch("adjustedETMiss", &adjustedETMiss);
  tree->Branch("adjustedETMissPhi", &adjustedETMissPhi);

  tree->Branch("m_finalWeightSum", &m_finalWeightSum);
  tree->Branch("m_intialWeightSum", &m_intialWeightSum);


  tree->Branch("m_jj", &m_jj);
  tree->Branch("m_jjb1", &m_jjb1);
  tree->Branch("m_jjb2", &m_jjb2);
  tree->Branch("maxm_jjb", &maxm_jjb);
  tree->Branch("minm_jjb", &minm_jjb);
  tree->Branch("dRjjb1", &dRjjb1);
  tree->Branch("dRjjb2", &dRjjb2);
  tree->Branch("minDRjjb", &minDRjjb);
  tree->Branch("maxDRjjb", &maxDRjjb);
  tree->Branch("m_b1l", &m_b1l);
  tree->Branch("m_b2l", &m_b2l);
  tree->Branch("minm_bl", &minm_bl);
  tree->Branch("maxm_bl", &maxm_bl);

  // Scale Factors

  tree->Branch("muonSF", &muonSF);
  tree->Branch("electronSF", &electronSF);
  tree->Branch("electronTriggerSF", &electronTriggerSF);
  tree->Branch("tauSF", &tauSF);
  tree->Branch("tauTriggerSF", &tauTriggerSF);
  tree->Branch("photonSF", &photonSF);
  tree->Branch("bJetSF", &bJetSF);
  tree->Branch("JVTSF", &JVTSF);
  tree->Branch("puWgt", &puWgt);
  //tree->Branch("muonRecoSF", &muonRecoSF);
  tree->Branch("muonTriggerSF", &muonTriggerSF);
  tree->Branch("dilepTriggerSF",&dilepTriggerSF);



  //btagging
  tree->Branch("b1m", &b1m);
  tree->Branch("b2m", &b2m);
  tree->Branch("b1MV2wgt", &b1MV2wgt);
  tree->Branch("b2MV2wgt", &b2MV2wgt);
  tree->Branch("minb1MV2weight", &minbMV2weight);
  tree->Branch("b1_ntrk", &b1_ntrk);
  tree->Branch("b2_ntrk", &b2_ntrk);

  //tree->Write();

  tree->Branch("delPhiMinb",&delPhiMinb);
  tree->Branch("all_HT",&all_HT);
  tree->Branch("all_METSig",&all_METSig);
  tree->Branch("all_Meff",&all_Meff);
  tree->Branch("amT2",&amT2);
  tree->Branch("metsig_New", &metsig_New);

  //Additional variables for WH 1Lbb
  tree->Branch("dRb1b2", &dRb1b2);
  tree->Branch("dRL1b1", &dRL1b1);
  tree->Branch("dRL1b2", &dRL1b2);

  //Xsec info
  tree->Branch("xsec", &xsec);
  tree->Branch("filteff", &filteff);
  tree->Branch("kfactor", &kfactor);


}


void TreeService::fillTree(NewObjectDef *objects ,PreliminarySel &region, CalculateVariables &variables, MCChecks MCTruthInfo, double mFinalWeight, double mInitialWeight, double puWeight, double SFmCTbbll, bool TrigMET, bool TrigMu, bool TrigEl, bool TrigGamma, bool Trig6j, std::vector<std::string> muon_triggers, std::vector<int> muon_decisions, std::vector<std::string> electron_triggers, std::vector<int> electron_decisions, std::vector<std::string> met_triggers, std::vector<int> met_decisions, double puSumWeights, double TRUTHMET, double TRUTHHT, bool CoreFlags, bool SCTFlag,bool LArTileFlags, bool passGRL, bool passedPrimVertexes, bool passedJetCleans, bool passedCosmicMus, bool passedMuonCleans, double RNo,  double RenormedMCWgt, int LumiYear, double m_averageIntPerCrossing, double m_actualIntPerCrossing, double m_xsec, double m_filteff, double m_kfactor){

  CutsRegion = region.region;

  coreFlag = CoreFlags;
  sctFlag = SCTFlag;
  LArTileFlag =LArTileFlags;
  passedPrimVertex=passedPrimVertexes;
  passedJetClean=passedJetCleans;
  passedCosmicMu=passedCosmicMus;
  passedMuonClean=passedMuonCleans;
  //triggerDecisions = triggers;
  passedGRL = passGRL;

  m_finalWeightSum = mFinalWeight;
  m_intialWeightSum = mInitialWeight;

  xsec = m_xsec;
  filteff = m_filteff;
  kfactor = m_kfactor;

  leadingbs = variables.leadingBs;
  primaryb = variables.primaryB;
  secondaryb = variables.secondB;


  mcID = objects->mcID;
  RunNumber = RNo;
  eventNumber = objects->eventNumber;
  mcEventWeight = objects->mcEventWeight;
  RenormedMcEventWeight = RenormedMCWgt;
  year = LumiYear;
  weightsVector = MCTruthInfo.variationweights;

  m_averageIntPerX=m_averageIntPerCrossing;
  m_actualIntPerX=m_actualIntPerCrossing;
  lumiScaled = objects->lumiScaled;
  puWgt = puWeight;
  sampleSFmCTbbll = SFmCTbbll;
  pileUpSumOfWeights = puSumWeights;


  pTZBoson = MCTruthInfo.pTZBoson;
  etaZBoson = std::abs(MCTruthInfo.etaZBoson);
  pTZBoson_Sherpa = MCTruthInfo.pTZBoson_Sherpa;
  etaZBoson_Sherpa = std::abs(MCTruthInfo.etaZBoson_Sherpa);
  duplicateVar = MCTruthInfo.arbitraryDuplicateCheck;
  Zqq = MCTruthInfo.Zqq;
  Zll = MCTruthInfo.Zll;
  truthFilterMET = TRUTHMET;
  truthFilterHT = TRUTHHT;
  jetFilterno = MCTruthInfo.jetFilterno;
  jetFilterno_prompt = MCTruthInfo.jetFilterno_prompt;

  ttbar_W1_decay = MCTruthInfo.ttbar_W1_decay;
  ttbar_W2_decay = MCTruthInfo.ttbar_W2_decay;
  ttbar_tau1_decay = MCTruthInfo.ttbar_tau1_decay;
  ttbar_tau2_decay = MCTruthInfo.ttbar_tau2_decay;
  tau_1_prongs = MCTruthInfo.tau_1_prongs;
  tau_2_prongs = MCTruthInfo.tau_2_prongs;


  Asymmetry = variables.Asymmetry;
  m_Tj1= variables.m_Tj1;
  m_Tj2 =  variables.m_Tj2;
  m_Tj3 =  variables.m_Tj3;
  m_Tj4 =  variables.m_Tj4;

  m_Ttj1 = variables.m_Ttj1;
  m_Ttj2 = variables.m_Ttj2;
  m_Ttj1tj2 = variables.m_Ttj1tj2;
  minm_Ttj = variables.minm_Ttj;
  maxm_Ttj = variables.maxm_Ttj;

  delPhi_tj1MET = variables.delPhi_tj1MET;
  delPhi_tj2MET = variables.delPhi_tj2MET;
  delPhi_tj1tj2 = variables.delPhi_tj1tj2;
  mindelPhi_tjMET = variables.mindelPhi_tjMET;
  maxdelPhi_tjMET = variables.maxdelPhi_tjMET;

  dRtj1b1 = variables.dRtj1b1;
  dRtj1b2 = variables.dRtj1b2;
  dRtj1b3 = variables.dRtj1b3;
  dRtj1b4 = variables.dRtj1b4;

  dRtj2b1 = variables.dRtj2b1;
  dRtj2b2 = variables.dRtj2b2;
  dRtj2b3 = variables.dRtj2b3;
  dRtj2b4 = variables.dRtj2b4;
  mindRtj1b = variables.mindRtj1b;
  mindRtj2b = variables.mindRtj2b;
  nb1 = variables.nb1;
  nb2 = variables.nb2;

  m_Tbmin= variables.m_Tbmin;
  m_Tb1= variables.m_Tb1;
  m_Tb2= variables.m_Tb2;
  dPhib1_MET= variables.dPhib1_MET;
  dPhib2_MET= variables.dPhib2_MET;
  mindPhib_MET= variables.mindPhib_MET;


  Weight = MCTruthInfo.Weight;
  MEWeight = MCTruthInfo.MEWeight;
  WeightNormalisation = MCTruthInfo.WeightNormalisation;
  NTrials = MCTruthInfo.NTrials;
  MUR0p5_MUF0p5_PDF261000 = MCTruthInfo.MUR0p5_MUF0p5_PDF261000;
  MUR0p5_MUF1_PDF261000 = MCTruthInfo.MUR0p5_MUF1_PDF261000;
  MUR1_MUF0p5_PDF261000 = MCTruthInfo.MUR1_MUF0p5_PDF261000;
  MUR1_MUF1_PDF261000 = MCTruthInfo.MUR1_MUF1_PDF261000;
  MUR1_MUF2_PDF261000 = MCTruthInfo.MUR1_MUF2_PDF261000;
  MUR2_MUF1_PDF261000 = MCTruthInfo.MUR2_MUF1_PDF261000;
  MUR2_MUF2_PDF261000 = MCTruthInfo.MUR2_MUF2_PDF261000;
  MUR1_MUF1_PDF261001 = MCTruthInfo.MUR1_MUF1_PDF261001;
  MUR1_MUF1_PDF261002 = MCTruthInfo.MUR1_MUF1_PDF261002;


  pTj1 = variables.pTj1;
  pTj2 = variables.pTj2;
  pTj3 = variables.pTj3;
  pTj4 = variables.pTj4;

  pTj5 = variables.pTj5;
  pTj6 = variables.pTj6;
  pTj7 = variables.pTj7;
  pTj8 = variables.pTj8;


  njet20 = variables.njet20;
  njet25 = variables.njet25;
  njet30 = variables.njet30;
  njet35 = variables.njet35;
  njet50 = variables.njet50;


  Reco_pTZ = variables.pTZ;
  Reco_etaZ = variables.etaZ;
  Reco_phiZ = variables.phiZ;
  DR_Zb1 = variables.DR_Zb1;
  DR_Zb2 = variables.DR_Zb2;
  minDR_Zb = variables.minDR_Zb;
  DPhi_Zb1 = variables.DPhi_Zb1;
  DPhi_Zb2 = variables.DPhi_Zb2;
  DEta_Zb1 = variables.DEta_Zb1;
  DEta_Zb2 = variables.DEta_Zb2;




  DRj1j2 = variables.DRj1j2;
  DRj1j3 = variables.DRj1j3;
  DRj1j4 = variables.DRj1j4;
  DRj2j3 = variables.DRj2j3;
  DRj2j4 = variables.DRj2j4;
  DRj3j4 = variables.DRj3j4;


  etaj1 = variables.etaj1;
  etaj2 = variables.etaj2;
  etaj3 = variables.etaj3;
  etaj4 = variables.etaj4;

  phij1 = variables.phij1;
  phij2 = variables.phij2;
  phij3 = variables.phij3;
  phij4 = variables.phij4;

  pTl1 = variables.pTl1;
  pTl2 = variables.pTl2;
  etal1 = variables.etal1;
  etal2 = variables.etal2;
  phil1 = variables.phil1;
  phil2 = variables.phil2;
  m_taulep = variables.m_taulep;


  pTmu1 = variables.pTmu1;
  pTmu2 = variables.pTmu2;
  pTel1 = variables.pTel1;
  pTel2 = variables.pTel2;
  pTtj1 = variables.pTtj1;
  pTtj2 = variables.pTtj2;
  etatj1 = variables.etatj1;
  etatj2 = variables.etatj2;
  phitj1 = variables.phitj1;
  phitj2 = variables.phitj2;

  lep1flavour = variables.lep1flavour;
  lep2flavour = variables.lep2flavour;

  pTgamma = variables.pTgamma;
  etagamma = variables.etagamma;
  phigamma = variables.phigamma;

  nJets = variables.nJets;
  nJets_beforeOR = variables.nJets_beforeOR;
  nBJets = variables.nbJets;
  nLeptons = variables.nLepton;
  nBaselineLeptons = variables.nBaselineLepton;
  nBaselineElectrons = variables.nBaselineElectron;
  nBaselineTaus = variables.nBaselineTau;
  nBaselineMuons = variables.nBaselineMuon;

  nPhoton = variables.nPhoton;

  nMuons = variables.nMuon;
  nBadMuons = objects->getBadMuons()->size();
  nElectrons = variables.nElectron;
  nTaus = variables.nTau;
  ETMiss = variables.eTMiss;
  adjustedETMiss = variables.adjustedETMiss;
  ETMissPhi = variables.eTMissPhi;
  adjustedETMissPhi = variables.adjustedETMissPhi;

  // fill these from the variables class
  m_bb = variables.m_bb;
  m_tautau = variables.m_tautau;
  m_CT = variables.m_CT;
  m_CTcorr = variables.m_CT_corr;
  m_ll = variables.m_ll;
  h_T = variables.h_T;
  m_T = variables.m_T;
  mbLmin = variables.mbLmin;
  mEff2j = variables.mEff2j;
  adjustedmEff2j = variables.adjustedmEff2j;
  mEff3j = variables.mEff3j;
  adjustedmEff3j = variables.adjustedmEff3j;
  adjustedRatio3j = variables.adjustedRatio3j;
  minAdjDPhijMET = variables.adjMinDelPhi;
  adjDPhij1MET = variables.adjDelPhi1;
  ratioMETmEff2j = variables.ratioMETmEff2j;
  ratioMETmEff3j = variables.ratioMETmEff3j;

  pTb1 = variables.pTb1;
  pTb2 = variables.pTb2;
  pTb3 = variables.pTb3;
  pTb4 = variables.pTb4;
  etab1 = variables.etab1;
  etab2 = variables.etab2;
  etab3 = variables.etab3;
  etab4 = variables.etab4;
  phib1 = variables.phib1;
  phib2 = variables.phib2;
  phib3 = variables.phib3;
  phib4 = variables.phib4;


  dPhij1MET = variables.delPhi1;
  dPhij2MET = variables.delPhi2;
  dPhij3MET = variables.delPhi3;
  dPhij4MET = variables.delPhi4;
  dPhiL1MET = variables.dPhiL1MET;
  dPhiL2MET = variables.dPhiL2MET;

  dPhib1b2 = variables.dPhib1b2;
  dPhiL1L2 = variables.dPhiL1L2;

  dPhiL1b1 = variables.dPhiL1b1;
  dPhiL1b2 = variables.dPhiL1b2;
  dPhiL2b1 = variables.dPhiL2b1;
  dPhiL2b2 = variables.dPhiL2b2;

  minDPhijMET = variables.minDelPhi;
  minDPhijMET_4 = variables.minDelPhi_4;
  minAdjDPhijMET = variables.adjMinDelPhi;
  minDPhiLb = variables.minDPhiLb;

  dEtab1b2 = variables.dEtab1b2;
  dEtaL1L2 = variables.dEtaL1L2;

  dEtaL1bSystem = variables.dEtaL1bSystem;
  dEtaL1b1 = variables.dEtaL1b1;
  dEtaL1b2 = variables.dEtaL1b2;

  dEtaL2bSystem = variables.dEtaL2bSystem;
  dEtaL2b1 = variables.dEtaL2b1;
  dEtaL2b2 = variables.dEtaL2b2;

  minDEtaLb= variables.minDEtaLb;



  dRtj1tj2 = variables.dRtj1tj2;

  dRb1b2 = variables.dRb1b2;
  dRL1b1 = variables.dRL1b1;
  dRL1b2 = variables.dRL1b2;
  dRL2b1 = variables.dRL2b1;
  dRL2b2 = variables.dRL2b2;
  minDRLb = variables.minDRLb;

  RatioDRbbHt = variables.ratioDRbbHt;

  m_jj = variables.m_jj;
  m_jjb1 = variables.m_jjb1;
  m_jjb2 = variables.m_jjb2;
  maxm_jjb = variables.maxm_jjb;
  minm_jjb = variables.minm_jjb;
  dRjjb1 = variables.dRjjb1;
  dRjjb2 = variables.dRjjb2;
  minDRjjb = variables.minDRjjb;
  maxDRjjb = variables.maxDRjjb;
  m_b1l = variables.m_b1l;
  m_b2l = variables.m_b2l;
  minm_bl = variables.minm_bl;
  maxm_bl = variables.maxm_bl;


  QCDDelta = variables.RJVars_QCD_Delta;
  invGammaRp1 = variables.RJVarsSS_invGamma;
  sHatR = variables.RJVarsSS_s_hat;
  MDelR = variables.RJVarsSS_MDelR;
  wrongMDelR = variables.RJVarsSS_wrongMDelR;

  //Vetos for cutflow
  Stop0L_tauVeto = variables.Stop0L_tauVeto;

  Aplanarity = variables.Aplanarity;
  TransformedAplanarity = variables.transformedAplan;
  Sphericity = variables.Sphericity;


  // Scale Factors:

  muonSF = objects->getMuonSF();
  muonTriggerSF = objects->getMuonTriggerSF();
  dilepTriggerSF = objects->getDilepTriggerSF();
  //  muonRecoSF = objects->getMuonRecoSF();
  //  oldMuonSF = objects->getOldMuonSF();
  electronSF = objects->getElectronSF();
  electronTriggerSF = objects->getElectronTriggerSF();
  tauSF = objects->getTauSF();
  tauTriggerSF = objects->getTauTriggerSF();
  photonSF = objects->getPhotonSF();
  bJetSF = objects->getBJetSF();
  JVTSF = objects->getJVTSF();


  passedMETTrigger = TrigMET;
  passedMuTrigger = TrigMu;
  passedElTrigger = TrigEl;
  passedGammaTrigger = TrigGamma;

  elTriggerMatch = objects->elTriggerMatch();
  muTriggerMatch = objects->muTriggerMatch();
  phTriggerMatch = objects->phTriggerMatch();

  mu_triggers = muon_triggers;
  mu_decisions = muon_decisions;
  el_triggers = electron_triggers;
  el_decisions = electron_decisions;
  MET_triggers = met_triggers;
  MET_decisions = met_decisions;

  b1m = variables.b1m;
  b2m = variables.b2m;
  b1MV2wgt = variables.b1MV2wgt;
  b2MV2wgt = variables.b2MV2wgt;
  minbMV2weight = variables.minbMV2weight;

  b1_ntrk = variables.b1_ntrk;
  b2_ntrk = variables.b2_ntrk;


  jet_imbalance = variables.jet_imbalance; //
  minDRjj = variables.minDRjj;
  dEtajj_max = variables.dEtajj_max;

  delPhiMinb = variables.delPhiMinb;
  all_HT = variables.all_HT;
  all_METSig = variables.all_METSig;
  all_Meff = variables.all_Meff;
  nextrajets50 = variables.nextrajets50;
  amT2 = variables.amT2;

  //MaxMin
  maxDR = variables.maxDR;
  InvMass_Bij_maxDR = variables.InvMass_Bij_maxDR;
  Imbalance_maxDR = variables.Imbalance_maxDR;
  JetAsymm_maxDR = variables.JetAsymm_maxDR;
  minDR = variables.minDR;
  minDR1 = variables.minDR1;
  JetAsymmR_min = variables.JetAsymmR_min;
  InvMass_Bij_minR = variables.InvMass_Bij_minR;
  JetAsymmR_min1 = variables.JetAsymmR_min1;
  InvMass_Bij_minR1 = variables.InvMass_Bij_minR1;

  //SRB algs
  SRB_minDR2 = variables.SRB_minDR2;
  SRB_minDR = variables.SRB_minDR;
  SRB_Hmbb = variables.SRB_Hmbb;

  SRB_Higgsino_maxDR = variables.SRB_Higgsino_maxDR;
  SRB_Higgsino_minDR = variables.SRB_Higgsino_minDR;
  SRB_Higgsino_Hmbb = variables.SRB_Higgsino_Hmbb;

  jet_pT.clear();
  jet_eta.clear();
  jet_phi.clear();
  jet_E.clear();
  jet_M.clear();
  jet_flav.clear();
  jet_bWgt.clear();
  jet_truflav.clear();

  el_pT.clear();
  el_eta.clear();
  el_phi.clear();
  el_E.clear();

  mu_pT.clear();
  mu_eta.clear();
  mu_phi.clear();
  mu_E.clear();

  tau_pT.clear();
  tau_eta.clear();
  tau_phi.clear();
  tau_E.clear();
  tau_SmallestDR.clear();
  tau_associatedTrue.clear();



  int maxJet = objects->getGoodJets()->size();
  for (int iJet = 0; iJet < maxJet; iJet++)
    {
      jet_pT.push_back(0.001*(*(objects->getGoodJets()))[iJet]->pt());
      jet_eta.push_back((*(objects->getGoodJets()))[iJet]->eta());
      jet_phi.push_back((*(objects->getGoodJets()))[iJet]->phi());
      jet_E.push_back(0.001*(*(objects->getGoodJets()))[iJet]->e());
      jet_M.push_back(0.001*(*(objects->getGoodJets()))[iJet]->m());
      double flav= ( ((*(objects->getGoodJets()))[iJet]->auxdata< char >("bjet") == true ) && fabs((*(objects->getGoodJets()))[iJet]->eta())<2.5 ) ? 5 : 0;
      jet_flav.push_back(flav);
      if (flav != 5)
	{
	  std::vector<int> ntrk;
	  (*(objects->getGoodJets()))[iJet]->getAttribute(xAOD::JetAttribute::NumTrkPt500,ntrk);
	  if(ntrk.size()>0)
	    {
	      jet_ntrks.push_back(ntrk[0]);
	      if (ntrk[0]<=4)
		{
		  double dphi = TVector2::Phi_mpi_pi(ETMissPhi - (*(objects->getGoodJets()))[iJet]->phi());
		}
	    }
	}
      int flavour = -1;
      // mcid == 0 for Data
      if(mcID > 0){(*(objects->getGoodJets()))[iJet]->getAttribute("ConeTruthLabelID",flavour);}
      jet_truflav.push_back( flavour );
      double MV2c10wgt = -99;
      if(mcID > 0){(*(objects->getGoodJets()))[iJet]->btagging()->MVx_discriminant("MV2c10", MV2c10wgt);}
      jet_bWgt.push_back(MV2c10wgt);
    }



  int maxEl = objects->getGoodElectrons()->size();
  for (int iel = 0; iel < maxEl; iel++){
    el_pT.push_back(0.001*(*(objects->getGoodElectrons()))[iel]->pt());
    el_eta.push_back((*(objects->getGoodElectrons()))[iel]->eta());
    el_phi.push_back((*(objects->getGoodElectrons()))[iel]->phi());
    el_E.push_back(0.001*(*(objects->getGoodElectrons()))[iel]->e());
  }

  int maxMu = objects->getGoodMuons()->size();
  for (int imu = 0; imu < maxMu; imu++){
    mu_pT.push_back(0.001*(*(objects->getGoodMuons()))[imu]->pt());
    mu_eta.push_back((*(objects->getGoodMuons()))[imu]->eta());
    mu_phi.push_back((*(objects->getGoodMuons()))[imu]->phi());
    mu_E.push_back(0.001*(*(objects->getGoodMuons()))[imu]->e());
  }

  int maxTau = objects->getGoodTaus()->size();
  for (int itau = 0; itau < maxTau; itau++){
    tau_pT.push_back(0.001*(*(objects->getGoodTaus()))[itau]->pt());
    tau_eta.push_back((*(objects->getGoodTaus()))[itau]->eta());
    tau_phi.push_back((*(objects->getGoodTaus()))[itau]->phi());
    tau_E.push_back(0.001*(*(objects->getGoodTaus()))[itau]->e());

    // do truth matching here with the first tau. Probably should have a Vector of taus in the truth tau part of MCChecks at some point
    TLorentzVector tau(0,0,0,0);
    tau.SetPtEtaPhiE(0.001*(*(objects->getGoodTaus()))[itau]->pt(),(*(objects->getGoodTaus()))[itau]->eta(),(*(objects->getGoodTaus()))[itau]->phi(),(*(objects->getGoodTaus()))[itau]->e());

    double smallestDR_1 = 99;
    int truthtau_x = 0;
    //for (int iTrueTau = 0; iTrueTau < MCTruthInfo.TruthTau.size(); iTrueTau++ ){
    //  if (tau.DeltaR(MCTruthInfo.TruthTau[iTrueTau]) < smallestDR_1){
    //	smallestDR_1 = tau.DeltaR(MCTruthInfo.TruthTau[iTrueTau]);
    //	truthtau_x = iTrueTau;
    // }
    //}

    for (int iTrueJet = 0; iTrueJet < MCTruthInfo.m_jet_pt.size(); iTrueJet++ ){
      TLorentzVector trueJet(0,0,0,0);
      trueJet.SetPtEtaPhiM(0.001*MCTruthInfo.m_jet_pt[iTrueJet], MCTruthInfo.m_jet_eta[iTrueJet], MCTruthInfo.m_jet_phi[iTrueJet], MCTruthInfo.m_jet_m[iTrueJet]);
      if (tau.DeltaR(trueJet) < smallestDR_1 && std::fabs(MCTruthInfo.m_jet_TruthID[iTrueJet]) == 15){
	smallestDR_1 = tau.DeltaR(trueJet);
	truthtau_x = iTrueJet;
      }
    }


    tau_SmallestDR.push_back(smallestDR_1);
    tau_associatedTrue.push_back(truthtau_x);


  }

  metsig_New = objects->getMETsig();

  multiJetTriggerPlateau = variables.inMultiJetTriggerPlateau;
  multiJetTriggerPassed = Trig6j;

  tree->Fill();


}



void TreeService::writeTree(){

  //  Output.cd() = variables. ;
  tree->Write();

  //std::cout << "Tree name:" + std::string(tree->GetName()) << std::endl;


}
