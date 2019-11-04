// put the full variable calculations here

#include <math.h>
#include <iostream>
#include <TVector2.h>
#include <TLorentzVector.h>
#include <string>
#include "NewMT2/MT2.h"
#include <fstream>
#include <unistd.h>
#include <AsgTools/MessageCheck.h>

// restframes crap
#include "RestFrames/RestFrame.h"
#include "RestFrames/RFrame.h"
#include "RestFrames/RLabFrame.h"
#include "RestFrames/RDecayFrame.h"
#include "RestFrames/RVisibleFrame.h"
#include "RestFrames/RInvisibleFrame.h"
#include "RestFrames/RSelfAssemblingFrame.h"
#include "RestFrames/InvisibleMassJigsaw.h"
#include "RestFrames/InvisibleRapidityJigsaw.h"
#include "RestFrames/ContraBoostInvariantJigsaw.h"
#include "RestFrames/MinimizeMassesCombinatoricJigsaw.h"
#include "RestFrames/InvisibleGroup.h"
#include "RestFrames/CombinatoricGroup.h"
#include "RestFrames/FramePlot.h"


// Transformed aplanarity stuff
#include <TMatrixD.h>
#include <TMatrixDEigen.h>


#include "MyAnalysis/CalculateVariables.h"

using namespace std;
using namespace RestFrames;

bool btag_wgt_Sorter( const xAOD::Jet* j1, const xAOD::Jet* j2 ) {
  double b1 = 0;
  double b2 = 0;
  j1->btagging()->MVx_discriminant("MV2c10", b1);
  j2->btagging()->MVx_discriminant("MV2c10", b2);
  return ( b1 > b2 );
}



CalculateVariables::CalculateVariables(NewObjectDef *objects,xAOD::TStore* evtStore, bool isTruth, bool doPhotons, bool isData, std::string systematic){

  // Initialise the variables to sensible numbers

  TruthFile = isTruth;
  calculatePhotons = doPhotons;

  //Retrieve objects from the eventStore
  evtStore->retrieve(goodMuon_cont, "goodMuons"+systematic);
  evtStore->retrieve(badMuon_cont, "badMuons"+systematic);
  evtStore->retrieve(baselineMuon_cont, "baselineMuons"+systematic);
  evtStore->retrieve(goodElectron_cont, "goodElectrons"+systematic);
  evtStore->retrieve(baselineElectron_cont, "baselineElectrons"+systematic);
  evtStore->retrieve(goodTau_cont, "goodTaus"+systematic);
  evtStore->retrieve(baselineTau_cont, "baselineTaus"+systematic);
  evtStore->retrieve(goodPhoton_cont, "goodPhotons"+systematic);
  evtStore->retrieve(goodJet_cont, "goodJets"+systematic);
  evtStore->retrieve(goodJet_beforeOR_cont, "goodJets_beforeOR"+systematic);
  evtStore->retrieve(bJet_cont, "BJets"+systematic);
  evtStore->retrieve(nonBJet_cont, "nonBJets"+systematic);
  evtStore->retrieve(METvector_cont, "METvector"+systematic);

  nMuon = goodMuon_cont->size();
  nBadMuon = badMuon_cont->size();
  nElectron = goodElectron_cont->size();
  nTau = goodTau_cont->size();
  nBaselineMuon = baselineMuon_cont->size();
  nBaselineElectron = baselineElectron_cont->size();
  nBaselineTau = baselineTau_cont->size();
  nLepton = nMuon+nElectron;
  nBaselineLepton = nBaselineMuon + nBaselineElectron;
  nPhoton = goodPhoton_cont->size();
  eTMiss = objects->getMET()*0.001;
  eTMissPhi = objects->getMETPhi();
  // This is the ETMiss in the regions with the electron added to the MET
  adjustedETMiss = eTMiss;
  adjustedETMissPhi = eTMissPhi;
  PhotonETMiss = eTMiss;
  PhotonETMissPhi = eTMissPhi;

  nJets = goodJet_cont->size();
  nJets_beforeOR = goodJet_beforeOR_cont->size();
  nbJets = bJet_cont->size();
  nNonBJets = nonBJet_cont->size();
  njet20 = 0;
  njet25 = 0;
  njet30 = 0;
  njet35 = 0;
  njet50 = 0;

  njet20 = goodJet_cont->size();

  for (int iJet = 0; iJet < nJets; iJet++){
    TLorentzVector tempJet = (*goodJet_cont)[iJet]->p4()*0.001;
    if (tempJet.Pt() > 25){
      njet25++;
    }
    if (tempJet.Pt() > 30){
      njet30++;
    }
    if (tempJet.Pt() > 35){
      njet35++;
    }
    if (tempJet.Pt() > 50){
      njet50++;
    }
  }

  // tbMET Analysis variables
  delPhiMinb = 99;
  all_HT = -99;
  all_METSig = -99;
  all_Meff = -99;
  amT2 = -99;
  minDelPhi = 99;
  minDelPhi_4 = 99;
  inMultiJetTriggerPlateau = false;
  int multiJetTriggerCounter = 0;

  if (nJets>0) all_HT=0;//start this at zero properly if we are going to calculate it.
  for (int iJet = 0; iJet < nJets; iJet++){
    auto tempJet = (*goodJet_cont)[iJet];

    all_HT += tempJet->pt()*0.001;
    delPhi1 = fabs(TVector2::Phi_mpi_pi((*(goodJet_cont))[iJet]->phi()  - eTMissPhi));

    if (delPhi1 < minDelPhi){
      if (iJet<4)
	{minDelPhi_4=delPhi1;}
      minDelPhi = delPhi1;
    }

    if (tempJet->auxdata< char >("bjet")==0){
      if (tempJet->pt()*0.001 > 50){
	nextrajets50++;
      }
    }
    if (tempJet->auxdata< char >("bjet")==1){
      double tempMETb = fabs(TVector2::Phi_mpi_pi( tempJet->phi()  - eTMissPhi));
      //std::cout << "mindelphib " << tempMETb << std::endl;
      if (tempMETb < delPhiMinb){
	delPhiMinb = tempMETb;
      }
    }
  }


  all_METSig = eTMiss/std::sqrt(all_HT);
  all_Meff = all_HT + eTMiss;





  // Scale Factors
  muonSF = objects->getMuonSF();
  electronTrigSF = objects->getElectronTriggerSF();
  leptonSF = objects->getLeptonSF();
  bJetSF = objects->getBJetSF();
  JVTSF = objects->getJVTSF();
  electronSF = objects->getElectronSF();
  metsig_New = objects->getMETsig();

  // trigger matching
  elTriggerMatch = objects->elTriggerMatch();
  muTriggerMatch = objects->muTriggerMatch();
  phTriggerMatch = objects->phTriggerMatch();


  // Mass related variables

  m_bb = -99;
  m_tautau = -99;
  m_CT = -99;
  m_CT_corr = -99;
  m_ll = -99;
  h_T = -99;
  m_T = -99;
  m_jj = -99;
  m_jjb1 = -99;
  m_jjb2 = -99;
  maxm_jjb = -99;
  minm_jjb = -99;
  m_b1l = -99;
  m_b2l = -99;
  m_lbb = -99;
  minm_bl = -99;
  maxm_bl = -99;
  mbLmin = -99;
  mEff2j = 0;
  mEff3j = 0;
  adjustedmEff2j = 0;
  adjustedmEff3j = 0;
  // Jet and Lepton properties:

  pTj1 = -99;
  pTj2 = -99;
  pTj3 = -99;
  pTj4 = -99;
  pTj5 = -99;
  pTj6 = -99;
  pTj7 = -99;
  pTj8 = -99;
  etaj1 = -99;
  etaj2 = -99;
  etaj3 = -99;
  etaj4 = -99;
  phij1 = -99;
  phij2 = -99;
  phij3 = -99;
  phij4 = -99;

  pTb1 = -99;
  pTb2 = -99;
  etab1 = -99;
  etab2 = -99;
  phib1 = -99;
  phib2 = -99;


  pTZ = -99; //
  etaZ = -99; //
  phiZ = -99; //
  DR_Zb1 = -99;
  DR_Zb2 = -99;
  minDR_Zb = -99;
  DPhi_Zb1 = -99;
  DPhi_Zb2 = -99;
  DEta_Zb1 = -99;
  DEta_Zb2 = -99;


  pTmu1 = -99;
  pTmu2 = -99;
  pTel1 = -99;
  pTel2 = -99;
  pTtj1 = -99;
  pTtj2 = -99;
  pTtj1tj2 = -99;

  etatj1 = -99;
  etatj2 = -99;
  etatj1tj2 = -99;
  phitj1 = -99;
  phitj2 = -99;
  phitj1tj2 = -99;

  pTl1 = -99;
  pTl2 = -99;
  etal1 = -99;
  etal2 = -99;
  phil1 = -99;
  phil2 = -99;
  m_taulep = -99;

  pTgamma = -99;
  etagamma = -99;
  phigamma = -99;

  if (calculatePhotons && nPhoton >= 1){
    this->CalculatePhotonMET(objects);
  }


  // Mass related variables:

  m_ll = -99;
  m_bb = -99;
  m_T = -99;

  leadingBs = false;
  primaryB = false;
  secondB = false;

  ratioMETmEff2j = -99;
  ratioMETmEff3j = -99;
  adjustedRatio2j = -99;
  adjustedRatio3j = -99;

  // Azimuthal Angle Variables


  delPhi1 = -99;
  delPhi2 = -99;
  delPhi3 = -99;
  delPhi4 = -99;
  //minDelPhi = -99;

  dPhiL1MET = 2*M_PI;
  dPhiL2MET = 2*M_PI;

  dPhib1b2 = 2*M_PI;
  dPhi_bMET = 2*M_PI;
  dPhiL1L2 = 2*M_PI;

  dPhiL1MET = 2*M_PI;
  dPhiL2MET = 2*M_PI;

  dPhiL1b1 = 2*M_PI;
  dPhiL1b2 = 2*M_PI;
  dPhiL2b1 = 2*M_PI;
  dPhiL2b2 = 2*M_PI;

  minDPhiLb = 2*M_PI;

  // delta eta variables should be initialised to something sensible too, 99 seems reasonable
  dEtab1b2 = -99;
  dEtaL1L2 = -99;

  dEtaL1bSystem = -99;
  dEtaL1b1 = -99;
  dEtaL1b2 = -99;

  dEtaL2bSystem = -99;
  dEtaL2b1 = -99;
  dEtaL2b2 = -99;

  minDEtaLb = -99;

  // delta R variables should also be sensible, again go with 99

  dRtj1tj2 = -99;

  dRb1b2 = -99;
  dRL1b1 = -99;
  dRL1b2 = -99;
  dRL2b1 = -99;
  dRL2b2 = -99;
  dRL1L2 = -99;
  minDRLb = -99;

  DRj1j2 = -99;
  DRj1j3 = -99;
  DRj1j4 = -99;
  DRj2j3 = -99;
  DRj2j4 = -99;
  DRj3j4 = -99;


  dRjjb1 = -99;
  dRjjb2 = -99;
  minDRjjb = -99;
  maxDRjjb = -99;

  ratioDRbbHt = -99;

  // Razor Variable Crap

  RJVars_QCD_Delta = -99;
  RJVarsSS_invGamma = -99;
  RJVarsSS_s_hat = -99;
  RJVarsSS_MDelR = -99;
  RJVarsSS_wrongMDelR = -99;

  // Aplanarity stuff

  Aplanarity = -99;
  transformedAplan = -99;
  Sphericity = -99;




  // Now require at least two jets in the event, one b-tagged, or else there's no point in calculating anything

  //  if (nbJets == 0 || nbJets > 2 || nLepton > 2 || nJets < 2){
  //  return;
  // }


  // do initial jet things here:

  mctTool = std::make_unique<TMctLib>();

  if (nJets > 0 &&  nbJets >= 1 && (  ((*(goodJet_cont))[0]->auxdata< char >("bjet")) )) {
  //if ( nbJets >= 1 &&  {
    primaryB = true;
  }


  if(nJets > 1 && nbJets >= 2 &&  ((*(goodJet_cont))[1]->auxdata< char >("bjet")) ){
    secondB = true;
  }

  if (primaryB && secondB){
    leadingBs = true;
  }


  TLorentzVector jet1v(0,0,0,0);
  TLorentzVector jet2v(0,0,0,0);
  TLorentzVector jet3v(0,0,0,0);
  TLorentzVector jet4v(0,0,0,0);

  auto jetVector = std::make_unique<xAOD::JetContainer>(SG::VIEW_ELEMENTS);
  if (nJets >= 1){
    pTj1 = (*(goodJet_cont))[0]->pt()*0.001;
    etaj1 = (*(goodJet_cont))[0]->eta();
    phij1 = (*(goodJet_cont))[0]->phi();
    delPhi1 = fabs(TVector2::Phi_mpi_pi( (*(goodJet_cont))[0]->phi()  - eTMissPhi));
    if (TruthFile == 0){
      jetVector->push_back((*goodJet_cont)[0]);
    }
    mEff2j= mEff2j + pTj1;
    h_T = pTj1;
    //minDelPhi = delPhi1;
    jet1v = (*goodJet_cont)[0]->p4()*0.001;
    if (nJets >= 2){
      pTj2 = (*(goodJet_cont))[1]->pt()*0.001;
      etaj2 = (*(goodJet_cont))[1]->eta();
      phij2 = (*(goodJet_cont))[1]->phi();
      delPhi2 = fabs(TVector2::Phi_mpi_pi( (*(goodJet_cont))[1]->phi()  - eTMissPhi));
      if (TruthFile == 0){
	jetVector->push_back((*goodJet_cont)[1]);
      }
      mEff2j = mEff2j + pTj2;
      h_T = h_T + pTj2;
      jet2v = (*goodJet_cont)[1]->p4()*0.001;
      DRj1j2 = jet1v.DeltaR(jet2v);


      if (nJets >= 3){
	pTj3 = (*(goodJet_cont))[2]->pt()*0.001;
	etaj3 = (*(goodJet_cont))[2]->eta();
	phij3 = (*(goodJet_cont))[2]->phi();
	delPhi3 = fabs(TVector2::Phi_mpi_pi( (*(goodJet_cont))[2]->phi()  - eTMissPhi));
	jet3v = (*goodJet_cont)[2]->p4()*0.001;
	if (TruthFile == 0){
	  jetVector->push_back((*goodJet_cont)[2]);
	}
	DRj1j3 = jet1v.DeltaR(jet3v);
	DRj2j3 = jet2v.DeltaR(jet3v);
	mEff3j = mEff2j + pTj3;
	h_T = h_T + pTj3;


	if (nJets >= 4){
	  pTj4 = (*(goodJet_cont))[3]->pt()*0.001;
	  etaj4 = (*(goodJet_cont))[3]->eta();
	  phij4 = (*(goodJet_cont))[3]->phi();
	  delPhi4 = fabs(TVector2::Phi_mpi_pi( (*(goodJet_cont))[3]->phi()  - eTMissPhi));
	  jet4v = (*goodJet_cont)[3]->p4()*0.001;
	  DRj1j4 = jet1v.DeltaR(jet4v);
	  DRj2j4 = jet2v.DeltaR(jet4v);
	  DRj3j4 = jet3v.DeltaR(jet4v);

	  h_T = h_T + pTj4;

	}
	if(nJets>=5) pTj5 =(*(goodJet_cont))[4]->pt()*0.001;
	if(nJets>=6) pTj6 =(*(goodJet_cont))[5]->pt()*0.001;
	if(nJets>=7) pTj7 =(*(goodJet_cont))[6]->pt()*0.001;
	if(nJets>=8) pTj8 =(*(goodJet_cont))[7]->pt()*0.001;
      }
    }
  }



  if (TruthFile == 0){
    jetVector->sort(btag_wgt_Sorter);
  }



  TLorentzVector jet_wgt1(0,0,0,0);
  TLorentzVector jet_wgt2(0,0,0,0);

  jet_imbalance = 0;

  if (jetVector->size() >= 2){
    jet_wgt1 = (*jetVector)[0]->p4()*0.001;
    jet_wgt2 = (*jetVector)[1]->p4()*0.001;
  }
  jet_imbalance = (jet_wgt1.Pt()-jet_wgt2.Pt())/(jet_wgt1.Pt()+jet_wgt2.Pt());
  minDRjj = std::min(fabs(DRj1j2), std::min(fabs(DRj1j3), fabs(DRj2j3)));;
  dEtajj_max = std::max(fabs(etaj1 - etaj2), std::max(fabs(etaj1 - etaj3), fabs(etaj2 - etaj3)));

  double DM_Temp_dPhib1b2 =  fabs(jet_wgt1.DeltaPhi(jet_wgt2));
  double DM_Temp_dPhiJMET = minDelPhi;
  double DM_Temp_dPhib1MET = fabs(TVector2::Phi_mpi_pi( jet_wgt1.Phi()  - eTMissPhi) );
  double DM_Temp_dPhib2MET = fabs(TVector2::Phi_mpi_pi( jet_wgt2.Phi()  - eTMissPhi) );
  double DM_Temp_dPhibMET = std::min(DM_Temp_dPhib1MET, DM_Temp_dPhib2MET);
  double DM_dEtab1b2 = (jet_wgt1.Eta() - jet_wgt2.Eta());

  x1 = std::min(DM_Temp_dPhib1b2, DM_Temp_dPhiJMET);
  x1b = M_PI - std::min(DM_Temp_dPhib1b2, DM_Temp_dPhibMET);
  y1 = fabs(M_PI - std::min(DM_Temp_dPhib1b2, DM_Temp_dPhiJMET));
  ctanh_bb = tanh((DM_dEtab1b2)/2 );


  // calculate all of the jet properties now:

  // set up the vectors here

  //  if (nbJets == 0 || nbJets > 2 || nLepton > 2 || nJets < 2){
  //  return;
  //}

  TLorentzVector b1v(0,0,0,0);
  TLorentzVector b2v(0,0,0,0);
  TLorentzVector b3v(0,0,0,0);
  TLorentzVector b4v(0,0,0,0);
  TLorentzVector lj1v(0,0,0,0);
  TLorentzVector lj2v(0,0,0,0);
  TLorentzVector tj1v(0,0,0,0);
  TLorentzVector tj2v(0,0,0,0);
  TLorentzVector tj1tj2v(0,0,0,0);

  b1m = 0;
  b2m = 0;

  b1MV2wgt = 0;
  b2MV2wgt = 0;
  minbMV2weight = 0;

  b1_ntrk = 0;
  b2_ntrk = 0;

  if (nbJets>=1){
    b1v = (*bJet_cont)[0]->p4()*0.001;
    pTb1 = b1v.Pt();
    etab1 = b1v.Eta();
    phib1 = b1v.Phi();
    //truthFlavour
    int flavour =-1;
    if(!isData){(*(bJet_cont))[0]->getAttribute("ConeTruthLabelID",flavour);}
    truthFlavb1 = flavour;
    //
  }
  if (nbJets >= 2){
    b2v = (*bJet_cont)[1]->p4()*0.001;
    pTb2 = b2v.Pt();
    etab2 = b2v.Eta();
    phib2 = b2v.Phi();
    //truthFlavour
    int flavour =-1;
    if(!isData){(*(bJet_cont))[1]->getAttribute("ConeTruthLabelID",flavour);}
    truthFlavb2 = flavour;
    //
  }
  if (nbJets >= 3){
    b3v = (*bJet_cont)[2]->p4()*0.001;
    pTb3 = b3v.Pt();
    etab3 = b3v.Eta();
    phib3 = b3v.Phi();
  }

  if(nbJets>=4){
    b4v = (*bJet_cont)[3]->p4()*0.001;
    pTb4 = b4v.Pt();
    etab4 = b4v.Eta();
    phib4 = b4v.Phi();
    }


  if (nbJets == 0 && nJets >= 2){

    if (!TruthFile){
      (*nonBJet_cont)[0]->btagging()->MVx_discriminant("MV2c10", b1MV2wgt);
      (*nonBJet_cont)[1]->btagging()->MVx_discriminant("MV2c10", b2MV2wgt);

      b1_ntrk = (*nonBJet_cont)[0]->btagging()->nSV0_TrackParticles();
      b2_ntrk = (*nonBJet_cont)[1]->btagging()->nSV0_TrackParticles();
    }

  }

  else if (nbJets != 0 && nJets >= 2){
    if (nbJets >= 2){
      b2v = (*bJet_cont)[1]->p4()*0.001;

      if (!TruthFile){

	(*bJet_cont)[0]->btagging()->MVx_discriminant("MV2c10", b1MV2wgt);
	(*bJet_cont)[1]->btagging()->MVx_discriminant("MV2c10", b2MV2wgt);

	b1_ntrk = (*bJet_cont)[0]->btagging()->nSV0_TrackParticles();
	b2_ntrk = (*bJet_cont)[1]->btagging()->nSV0_TrackParticles();
      }

      if (nNonBJets > 1){
	lj1v = (*nonBJet_cont)[0]->p4()*0.001;
	lj2v = (*nonBJet_cont)[1]->p4()*0.001;
	TLorentzVector ljv = lj1v+lj2v;
	m_jj = ljv.M();
	m_jjb1 = (b1v+ljv).M();
	m_jjb2 = (b2v+ljv).M();
	maxm_jjb = std::max(m_jjb1, m_jjb2);
	minm_jjb = std::min(m_jjb1, m_jjb2);
	dRjjb1 = b1v.DeltaR(ljv);
	dRjjb2 = b2v.DeltaR(ljv);
	minDRjjb = std::min(dRjjb1,dRjjb2);
	maxDRjjb = std::max(dRjjb1,dRjjb2);
      }
      else if (nNonBJets == 1){
	lj1v = (*nonBJet_cont)[0]->p4()*0.001;
	m_jjb1 = (b1v+lj1v).M();
	m_jjb2 = (b2v+lj1v).M();
	maxm_jjb = std::max(m_jjb1, m_jjb2);
	minm_jjb = std::min(m_jjb1, m_jjb2) ;
	dRjjb1 = b1v.DeltaR(lj1v);
	dRjjb2 = b2v.DeltaR(lj1v);
	minDRjjb = std::min(dRjjb1,dRjjb2);
	maxDRjjb = std::max(dRjjb1,dRjjb2);
      }
    }

    if (nbJets == 1){
      if (!TruthFile){

	(*bJet_cont)[0]->btagging()->MVx_discriminant("MV2c10", b1MV2wgt);
	(*nonBJet_cont)[0]->btagging()->MVx_discriminant("MV2c10", b2MV2wgt);
	b1_ntrk = (*bJet_cont)[0]->btagging()->nSV0_TrackParticles();
	b2_ntrk = (*nonBJet_cont)[0]->btagging()->nSV0_TrackParticles();
      }


      if (nNonBJets > 2){
	lj1v = (*nonBJet_cont)[1]->p4()*0.001;
	lj2v = (*nonBJet_cont)[2]->p4()*0.001;
	TLorentzVector ljv = lj1v+lj2v;
	m_jj = ljv.M();
	m_jjb1 = (b1v+ljv).M();
	m_jjb2 = (b2v+ljv).M();
	maxm_jjb = std::max(m_jjb1, m_jjb2);
	minm_jjb = std::min(m_jjb1, m_jjb2);
	dRjjb1 = b1v.DeltaR(ljv);
	dRjjb2 = b2v.DeltaR(ljv);
	minDRjjb = std::min(dRjjb1,dRjjb2);
	maxDRjjb = std::max(dRjjb1,dRjjb2);
      }
      else if (nNonBJets == 2){
	lj1v = (*nonBJet_cont)[1]->p4()*0.001;
	m_jjb1 = (b1v+lj1v).M();
	m_jjb2 = (b2v+lj1v).M();
	maxm_jjb = std::max(m_jjb1, m_jjb2);
	minm_jjb = std::min(m_jjb1, m_jjb2) ;
	dRjjb1 = b1v.DeltaR(lj1v);
	dRjjb2 = b2v.DeltaR(lj1v);
	minDRjjb = std::min(dRjjb1,dRjjb2);
	maxDRjjb = std::max(dRjjb1,dRjjb2);
      }
    }
  }


  if (nTau == 1){
    tj1v = (*goodTau_cont)[0]->p4()*0.001;

  }
  if (nTau >= 2){
    tj1v = (*goodTau_cont)[0]->p4()*0.001;
    tj2v = (*goodTau_cont)[1]->p4()*0.001;

  }


  // Calculate Tau related stuff here
  // count the taus to check the multi jet trigger plateau requirements
  for (int iTau = 0; iTau < nTau; iTau++){
    auto tempTau = (*goodTau_cont)[iTau];
    if (tempTau->pt()*0.001 > 55 && std::fabs(tempTau->eta()) < 2.4){
      multiJetTriggerCounter = multiJetTriggerCounter+1;
    }
  }

  if (multiJetTriggerCounter >= 6){
    inMultiJetTriggerPlateau = true;
  }







  delPhi_tj1MET = -99;
  delPhi_tj2MET = -99;
  delPhi_tj1tj2 = -99;
  mindelPhi_tjMET = -99;
  maxdelPhi_tjMET = -99;
  dRtj1b1 = -99;
  dRtj1b2 = -99;
  dRtj1b3 = -99;
  dRtj1b4 = -99;
  dRtj2b1 = -99;
  dRtj2b2 = -99;
  dRtj2b3 = -99;
  dRtj2b4 = -99;

  m_Ttj1 = -99;
  m_Ttj2 = -99;
  m_Ttj1tj2 = -99;
  minm_Ttj = -99;
  maxm_Ttj = -99;


  Stop0L_tauVeto = true;
  int maxJet = goodJet_cont->size();
  for (int iJet = 0; iJet < maxJet; iJet++)
    {
      if( ((*(goodJet_cont))[iJet]->auxdata< char >("bjet") != true ) && fabs((*(goodJet_cont))[iJet]->eta())<2.5 )
    	{
	  std::vector<int> ntrk;
	  (*(goodJet_cont))[iJet]->getAttribute(xAOD::JetAttribute::NumTrkPt500,ntrk);
	  if(ntrk.size()>0)
	    {
	      if (ntrk[0]<=4)
		{
		  double dphi = TVector2::Phi_mpi_pi(eTMissPhi - (*(goodJet_cont))[iJet]->phi());
		  if (fabs(dphi)<(TMath::Pi()/5.0)){Stop0L_tauVeto = false;}
		}
	    }
	}
    }






  if (nTau >= 1){
    pTtj1 = tj1v.Pt();
    etatj1 = tj1v.Eta();
    phitj1 = tj1v.Phi();
    m_Ttj1 = sqrt(2*(pTtj1*eTMiss*(1 - cos(fabs(TVector2::Phi_mpi_pi( (phitj1  - eTMissPhi)))))));
    delPhi_tj1MET = fabs(TVector2::Phi_mpi_pi(phitj1  - eTMissPhi));

    dRtj1b1 = tj1v.DeltaR(b1v);
    dRtj1b2 = tj1v.DeltaR(b2v);
    dRtj1b3 = tj1v.DeltaR(b3v);
    dRtj1b4 = tj1v.DeltaR(b4v);

    dRtj1v.push_back(dRtj1b1);
    dRtj1v.push_back(dRtj1b2);
    dRtj1v.push_back(dRtj1b3);
    dRtj1v.push_back(dRtj1b4);

  }

  if (nTau >= 2){
    tj1tj2v = tj1v + tj2v;
    pTtj1tj2 = tj1tj2v.Pt();
    etatj1tj2 = tj1tj2v.Eta();
    phitj1tj2 = tj1tj2v.Phi();
    dRtj1tj2 = tj1v.DeltaR(tj2v);

    pTtj2 = tj2v.Pt();
    etatj2 = tj2v.Eta();
    phitj2 = tj2v.Phi();
    delPhi_tj2MET = fabs(TVector2::Phi_mpi_pi(phitj2  - eTMissPhi));
    delPhi_tj1tj2 = fabs(TVector2::Phi_mpi_pi(phitj1tj2 - eTMissPhi));
    mindelPhi_tjMET = std::min(delPhi_tj1MET,delPhi_tj2MET);
    maxdelPhi_tjMET = std::max(delPhi_tj1MET,delPhi_tj2MET);
    m_Ttj2 = sqrt(2*(pTtj2*eTMiss*(1 - cos(fabs(TVector2::Phi_mpi_pi( (phitj2  - eTMissPhi)))))));
    minm_Ttj = std::min(m_Ttj1, m_Ttj2);
    maxm_Ttj = std::max(m_Ttj1, m_Ttj2);
    m_Ttj1tj2 = sqrt(2*(pTtj1tj2*eTMiss*(1 - cos(fabs(TVector2::Phi_mpi_pi( (phitj1tj2  - eTMissPhi)))))));
    m_tautau = (tj1v+tj2v).M();

    dRtj2b1 = tj2v.DeltaR(b1v);
    dRtj2b2 = tj2v.DeltaR(b2v);
    dRtj2b3 = tj2v.DeltaR(b3v);
    dRtj2b4 = tj2v.DeltaR(b4v);

    dRtj2v.push_back(dRtj2b1);
    dRtj2v.push_back(dRtj2b2);
    dRtj2v.push_back(dRtj2b3);
    dRtj2v.push_back(dRtj2b4);


  }

    // Calculate mindR for tau 1 and 2 here

  mindRtj1b = 101;
  mindRtj2b = 101;
  nb1 = -99;
  nb2 = -99;

  for(int i = 0; i < 4; i++){

    if(nTau >= 1 && dRtj1v[i] < mindRtj1b){
      mindRtj1b = dRtj1v[i];
      nb1 = i;
    }

    if(nTau >= 2 && dRtj2v[i] < mindRtj2b){
      mindRtj2b = dRtj2v[i];
      nb2 = i;
    }
  }

  // selecting the second mininum to not match with first b-jet

  if(nTau >= 2){
    if (nb1 == nb2){

      if(dRtj1v[nb1] < dRtj2v[nb2]){

	mindRtj2b = 101;

	for(int j = 0; j < 4; j++){
	  if (j == nb2) continue;

	  if(dRtj2v[j] < mindRtj2b){
	    mindRtj2b = dRtj2v[j];
	    nb2 = j;
	  }
	}
      }

      if(dRtj2v[nb2] < dRtj1v[nb1]){

	mindRtj1b = 101;

	for(int k = 0; k < 4; k++){
	  if (k == nb1) continue;

	  if(dRtj1v[k] < mindRtj1b){
	    mindRtj1b = dRtj1v[k];
	    nb1 = k;
	  }
	}
      }

    }
  }

  dRtj1v.clear();
  dRtj2v.clear();

  m_bb = (b1v+b2v).M();
  m_CT = mctTool->mct(b1v, b2v);


  dPhib1b2 =  fabs(b1v.DeltaPhi(b2v));
  dEtab1b2 = fabs(b1v.Eta() - b2v.Eta());
  dRb1b2 = b1v.DeltaR(b2v);

  ratioDRbbHt = dRb1b2/h_T;


  Asymmetry = 0;

  m_Tjmin = 0;
  m_Tj1 = 0;
  m_Tj2 = 0;
  m_Tj3 = 0;
  m_Tj4 = 0;
  if(nJets>=2)
    {
      m_Tj1 = sqrt(2*(pTj1*eTMiss*(1 - cos(fabs(TVector2::Phi_mpi_pi( (phij1  - eTMissPhi)))))));
      m_Tj2 = sqrt(2*(pTj2*eTMiss*(1 - cos(fabs(TVector2::Phi_mpi_pi( (phij2  - eTMissPhi)))))));
      m_Tjmin = std::min(m_Tj1,m_Tj2);
      Asymmetry = (pTj1 - pTj2)/(pTj1 + pTj2);

    }
  if(nJets>=3)
    {
      m_Tj3 = sqrt(2*(pTj3*eTMiss*(1 - cos(fabs(TVector2::Phi_mpi_pi( (phij3  - eTMissPhi)))))));
      m_Tjmin=min(m_Tj3, std::min(m_Tj1,m_Tj2));
    }
  if(nJets>=4)
    {
      m_Tj4 = sqrt(2*(pTj4*eTMiss*(1 - cos(fabs(TVector2::Phi_mpi_pi( (phij4  - eTMissPhi)))))));
      m_Tjmin=std::min(std::min(m_Tj1,m_Tj2),std::min(m_Tj3,m_Tj4));

    }




  m_Tbmin = 0;
  m_Tb1 = 0;
  m_Tb2 = 0;
  dPhib1_MET = 0;
  dPhib2_MET = 0;
  mindPhib_MET = 0;

  if(nbJets>=2)
    {
      m_Tb1 = sqrt(2*(pTb1*eTMiss*(1 - cos(fabs(TVector2::Phi_mpi_pi( (phib1  - eTMissPhi)))))));
      m_Tb2 = sqrt(2*(pTb2*eTMiss*(1 - cos(fabs(TVector2::Phi_mpi_pi( (phib2  - eTMissPhi)))))));
      m_Tbmin = std::min(m_Tb1,m_Tb2);
      dPhib1_MET = fabs(TVector2::Phi_mpi_pi( (phib1  - eTMissPhi)));
      dPhib2_MET = fabs(TVector2::Phi_mpi_pi( (phib2  - eTMissPhi)));
      mindPhib_MET = std::min(dPhib1_MET, dPhib2_MET);
    }


  // put all extra b-variables here

  b1m = b1v.M();
  b2m = b2v.M();

  minbMV2weight = std::min(b1MV2wgt, b2MV2wgt);


  if (nLepton == 1){
    this->CalculateOneLepVariables(objects, b1v, b2v, tj1v);

    //    if(nTau == 1 && nElectron == 1){
    // m_taulep = (tj1v+l1v).M();
    //}

    //else if(nTau == 1 && nMuon == 1){
    // m_taulep = (tj1v+l1v).M();
    //}
  }

  if (nLepton >= 2){
    this->CalculateTwoLepVariables(objects, b1v, b2v);
  }

  // Selecting lepton and tau to calculate invariant mass for higgs reconstruction (hadronic tau + leptonic tau)





  // sort out the adjusted ratio with the electrons as MET

  adjustedmEff2j = mEff2j + adjustedETMiss;
  adjustedmEff3j = mEff3j + adjustedETMiss;

  mEff2j = mEff2j + eTMiss;
  mEff3j = mEff3j + eTMiss;



  ratioMETmEff2j = eTMiss/mEff2j;
  ratioMETmEff3j = eTMiss/mEff3j;
  adjustedRatio2j = adjustedETMiss/adjustedmEff2j;
  adjustedRatio3j = adjustedETMiss/adjustedmEff3j;

  double adjDelPhi1 = 99;
  double adjDelPhi2 = 99;
  double adjDelPhi3 = 99;
  double adjDelPhi4 = 99;

  adjMinDelPhi = -99;

  if (nJets >= 1){
    adjDelPhi1 = fabs(TVector2::Phi_mpi_pi( (*(goodJet_cont))[0]->phi()  - adjustedETMissPhi));
    adjMinDelPhi = adjDelPhi1;
    if (nJets >= 2){
      adjDelPhi2 = fabs(TVector2::Phi_mpi_pi( (*(goodJet_cont))[1]->phi()  - adjustedETMissPhi));
      if (adjDelPhi2 < adjMinDelPhi)
	adjMinDelPhi = adjDelPhi2;

      if (nJets >= 3){
	adjDelPhi3 = fabs(TVector2::Phi_mpi_pi( (*(goodJet_cont))[2]->phi()  - adjustedETMissPhi));
	if (adjDelPhi3 < adjMinDelPhi){
	  adjMinDelPhi = adjDelPhi3;
	}

	if (nJets >= 4){
	  adjDelPhi4 = fabs(TVector2::Phi_mpi_pi( (*(goodJet_cont))[3]->phi()  - adjustedETMissPhi));

	  if (adjDelPhi4 < adjMinDelPhi)
	    adjMinDelPhi = adjDelPhi4;
	}
      }
    }
  }



  // can now calculate them mctCorr because we'll have the stuff for it
  TLorentzVector m_CT_vds(0,0,0,0);
  m_CT_corr = mctTool->mctcorr(b1v, b2v, m_CT_vds, 0.001*(*(METvector_cont)));



  //do aplanarity/extra calculations here



  //
  // Maximum DR exclusion
  double inumR=-1;
  double jnumR=-1;
  maxDR=-99;
  if (nbJets >=4 ){//---Changes 1 24/2
    for (int i = 0; i < (bJet_cont)->size() ; i++)
      {
        for (int j = 0; j < (bJet_cont)->size() ; j++)
          {
            double trialDEta= fabs((*(bJet_cont))[i]->eta()  - (*(bJet_cont))[j]->eta());
            double trialDPhi=fabs(TVector2::Phi_mpi_pi( (*(bJet_cont))[i]->phi()  - (*(bJet_cont))[j]->phi()));

	    double trialDR= std::sqrt((trialDEta*trialDEta)+(trialDPhi*trialDPhi));
            if (trialDR>maxDR && (i != j))
              {
                inumR=i;
                jnumR=j;
                maxDR=trialDR;
              }
          }
      }
  }

  double MaxDRBjetpT1 = -99;
  double MaxDRBjetpT2 = -99;
  InvMass_Bij_maxDR = -99;
  // To me these two are the same calculation with a different name
  Imbalance_maxDR = -99;
  JetAsymm_maxDR = -99;
  if (inumR> -1 && jnumR> -1)
    {
      JetAsymm_maxDR = ((*(bJet_cont))[inumR]->pt()-(*(bJet_cont))[jnumR]->pt()) / ((*(bJet_cont))[inumR]->pt()+(*(bJet_cont))[jnumR]->pt());

      if((*(bJet_cont))[inumR]->pt() < (*(bJet_cont))[jnumR]->pt())
        {
          double x=inumR;
          inumR=jnumR;
          jnumR=x;
        }
      MaxDRBjetpT1=(*(bJet_cont))[inumR]->pt()*0.001;
      MaxDRBjetpT2=(*(bJet_cont))[jnumR]->pt()*0.001;
      Imbalance_maxDR=((*(bJet_cont))[inumR]->pt()-(*(bJet_cont))[jnumR]->pt())/((*(bJet_cont))[inumR]->pt()+(*(bJet_cont))[jnumR]->pt());

      TLorentzVector bMaxRi = (*(bJet_cont))[inumR]->p4()*0.001;
      TLorentzVector bMaxRj = (*(bJet_cont))[jnumR]->p4()*0.001;
      InvMass_Bij_maxDR= (bMaxRi+bMaxRj).M();
    }


  //Min DR algorithm
  double inummR=-1;
  double jnummR=-1;
  double inummR1=-1;
  double jnummR1=-1;

  //
  minDR=99;
  minDR1=99;
  //

  for (int i=0;i<(bJet_cont->size());++i)
    {for (int j=0;j<bJet_cont->size();++j)
        {
          double trialDEta=fabs( (*(bJet_cont))[i]->eta()  - (*(bJet_cont))[j]->eta());
          double trialDPhi=fabs(TVector2::Phi_mpi_pi( (*(bJet_cont))[i]->phi()  - (*(bJet_cont))[j]->phi()));
          double trialDR= std::sqrt((trialDEta*trialDEta)+(trialDPhi*trialDPhi));
          if (trialDR<minDR && i != j && i!=inumR && i!=jnumR && j!=inumR && j!=jnumR && inumR!=-1 && jnumR!=-1)
	    //minimisation with exclusion
            { inummR=i;
              jnummR= j;
              minDR=trialDR;
              if(nbJets==3){std::cout<<"something weird here"<<std::endl;}
            }
          if (trialDR<minDR1 && i != j )//minimisation without exclusion
            { inummR1=i;
              jnummR1=j;
              minDR1=trialDR;
            }
        }
    }

  JetAsymmR_min = -99;
  InvMass_Bij_minR = -99;//maxminmbb
  JetAsymmR_min1 = -99;
  InvMass_Bij_minR1 = -99; //minmbb

  //With exclusion
  if (inummR>-1 && jnummR> -1){
    TLorentzVector bivR = (*(bJet_cont))[inummR]->p4()*0.001;
    TLorentzVector bjvR = (*(bJet_cont))[jnummR]->p4()*0.001;
    InvMass_Bij_minR= (bivR+bjvR).M();
    JetAsymmR_min=((*(bJet_cont))[inummR]->pt()-(*(bJet_cont))[jnummR]->pt())/((*(bJet_cont))[inummR]->pt()+(*(bJet_cont))[jnummR]->pt());
  }

  //Without exclusion
  if (inummR1>-1 && jnummR1> -1){
    TLorentzVector bivR1 = (*(bJet_cont))[inummR1]->p4()*0.001;
    TLorentzVector bjvR1 = (*(bJet_cont))[jnummR1]->p4()*0.001;
    InvMass_Bij_minR1= (bivR1+bjvR1).M();
    JetAsymmR_min1=((*(bJet_cont))[inummR1]->pt()-(*(bJet_cont))[jnummR1]->pt())/((*(bJet_cont))[inummR1]->pt()+(*(bJet_cont))[jnummR1]->pt());
  }

 //Min DR algorithm end
  //

  //SRB algorithms

  //SRB Algorithm Start
      int SRB_id1=-99;
      int SRB_id2=-99;
      int SRB_id3=-99;
      int SRB_id4=-99;
      SRB_minDR=99;
      SRB_minDR2=99;
      SRB_Hmbb=-1;

  if(nbJets>=4)
    {
      //std::cout<<"SRB original alg start"<<std::endl;
      for (int i=0; i<4; ++i)//Change to i<4 for 4 strongest b-jets
	{
	  for(int j=0; j<4; ++j)//Change to i<4 for 4 strongest b-jets
	    {
	      if(i!=j)
		{
		  double trialDEta=fabs( (*(bJet_cont))[i]->eta()  - (*(bJet_cont))[j]->eta());
		  double trialDPhi=fabs(TVector2::Phi_mpi_pi( (*(bJet_cont))[i]->phi()  - (*(bJet_cont))[j]->phi()));
		  double trialDR= std::sqrt((trialDEta*trialDEta)+(trialDPhi*trialDPhi));
		  //std::cout<<"trialDR "<<trialDR<<std::endl;
		  if (trialDR<SRB_minDR)
		    {
		      SRB_minDR=trialDR;
		      SRB_id1=i;
		      SRB_id2=j;
		    }
		  //std::cout<<"SRB_minDR= "<<SRB_minDR<<std::endl;
		}//i!=j
	    }//Loop over b-jets
	}//Loop over b-jets
      //std::cout<<"id1="<<SRB_id1<<",id2= "<<SRB_id2<<std::endl;

      for (int i=0; i<4; ++i)//Change to i<4 for 4 strongest b-jets
	{
	  for(int j=0; j<4; ++j)//Change to i<4 for 4 strongest b-jets
	    {
	      if(i!=j && i!=SRB_id1 && j!=SRB_id1 && i!=SRB_id2 && j!=SRB_id2 )
		{
		  double trialDEta=fabs( (*(bJet_cont))[i]->eta()  - (*(bJet_cont))[j]->eta());
		  double trialDPhi=fabs(TVector2::Phi_mpi_pi( (*(bJet_cont))[i]->phi()  - (*(bJet_cont))[j]->phi()));
		  double trialDR= std::sqrt((trialDEta*trialDEta)+(trialDPhi*trialDPhi));
		  //std::cout<<"trialDR2= "<<trialDR<<std::endl;
		  if (trialDR<SRB_minDR2)
		    {
		      SRB_minDR2=trialDR;
		      SRB_id3=i;
		      SRB_id4=j;
		    }

		  //std::cout<<"SRB_minDR2= "<<SRB_minDR2<<std::endl;
		}//i!=j
	    }//Loop over b-jets
	}//Loop over b-jets
      //std::cout<<"id3="<<SRB_id3<<", id4= "<<SRB_id4<<std::endl;
      //std::cout<<"Out of SRB algorithm"<<std::endl;
    }//nbJets>=4

  if (SRB_id1>-1 && SRB_id2>-1 && SRB_id3>-1 && SRB_id4>-1)
    {
      TLorentzVector b1m = (*(bJet_cont))[SRB_id1]->p4()*0.001;
      TLorentzVector b2m = (*(bJet_cont))[SRB_id2]->p4()*0.001;
      double SRB_mbb1= (b2m+b1m).M();
      TLorentzVector b3m = (*(bJet_cont))[SRB_id3]->p4()*0.001;
      TLorentzVector b4m = (*(bJet_cont))[SRB_id4]->p4()*0.001;
      double SRB_mbb2= (b3m+b4m).M();
      SRB_Hmbb= (SRB_mbb1+SRB_mbb2)/2;
      //std::cout<<"SRB alg 1 Hmbb = "<<SRB_Hmbb<<std::endl;
    }

  //SRB Algorithm End

  //SRB Algorithm with Higgsino minimisation start
      int SRB_Higgsino_id1=-99;
      int SRB_Higgsino_id2=-99;
      int SRB_Higgsino_id3=-99;
      int SRB_Higgsino_id4=-99;
      SRB_Higgsino_maxDR=99;
      SRB_Higgsino_minDR=99;
      SRB_Higgsino_Hmbb=-1;
  if(nbJets>=4)
    {
      //std::cout<<"Begin SRB Higgsino alg"<<std::endl;
      for (int i=0; i<nbJets; ++i)//Change to i<4 for 4 strongest b-jets
	{
	  for(int j=0; j<nbJets; ++j)//Change to i<4 for 4 strongest b-jets
	    {
	      if(i!=j)
		{
		  double trialDEta1=fabs( (*(bJet_cont))[i]->eta()  - (*(bJet_cont))[j]->eta());
		  double trialDPhi1=fabs(TVector2::Phi_mpi_pi( (*(bJet_cont))[i]->phi()  - (*(bJet_cont))[j]->phi()));
		  double trialDR1= std::sqrt((trialDEta1*trialDEta1)+(trialDPhi1*trialDPhi1));
		  for (int i2=0; i2<nbJets; ++i2)//Change to i<4 for 4 strongest b-jets
		    {
		      for(int j2=0; j2<nbJets; ++j2)//Change to i<4 for 4 strongest b-jets
			{
			  if(i2!=j2 && i2!=i && j2!=j && i2!=j && j2!=i )
			    {
			      double trialDEta=fabs( (*(bJet_cont))[i2]->eta()  - (*(bJet_cont))[j2]->eta());
			      double trialDPhi=fabs(TVector2::Phi_mpi_pi( (*(bJet_cont))[i2]->phi()  - (*(bJet_cont))[j2]->phi()));
			      double trialDR2= std::sqrt((trialDEta*trialDEta)+(trialDPhi*trialDPhi));
			      if (std::max(trialDR1,trialDR2)<SRB_Higgsino_maxDR)
				{
				  SRB_Higgsino_maxDR=std::max(trialDR1,trialDR2);
				  //std::cout<<"SRB_Higgino_maxDR= "<<SRB_Higgsino_maxDR<<std::endl;
				  SRB_Higgsino_minDR=std::min(trialDR1,trialDR2);
				  //std::cout<<"SRB_Higgino_minDR= "<<SRB_Higgsino_minDR<<std::endl;
				  SRB_Higgsino_id1=i;
				  SRB_Higgsino_id2=j;
				  SRB_Higgsino_id3=i2;
				  SRB_Higgsino_id4=j2;
				  //std::cout<<" Higgsino b-jet id's = "<<SRB_Higgsino_id1<<", "<<SRB_Higgsino_id2<<", "<<SRB_Higgsino_id3<<", "<<SRB_Higgsino_id4<<std::endl;
				}
			    }//i!=j
			}//Loop over b-jets
		    }//Loop over b-jets
		}//i!=j
	    }//Loop over b-jets
	}//Loop over b-jets
    }//Nbjets>=4
  //SRB Algorithm with Higgsino minimisation start
  if (SRB_Higgsino_id1>-1 && SRB_Higgsino_id2>-1 && SRB_Higgsino_id3>-1 && SRB_Higgsino_id4>-1)
    {
      TLorentzVector b1m = (*(bJet_cont))[SRB_Higgsino_id1]->p4()*0.001;
      TLorentzVector b2m = (*(bJet_cont))[SRB_Higgsino_id2]->p4()*0.001;
      double SRB_Higgsino_mbb1= (b2m+b1m).M();

      TLorentzVector b3m = (*(bJet_cont))[SRB_Higgsino_id3]->p4()*0.001;
      TLorentzVector b4m = (*(bJet_cont))[SRB_Higgsino_id4]->p4()*0.001;
      double SRB_Higgsino_mbb2= (b3m+b4m).M();

      SRB_Higgsino_Hmbb= (SRB_Higgsino_mbb1+SRB_Higgsino_mbb2)/2;
    }

  //SRB algorithms end


}


void CalculateVariables::CalculatePhotonMET(NewObjectDef *objects){

  TVector2 tempMET = *(METvector_cont);
  //std::cout << "Temp MET(px,py): (" << tempMET.Px() << " ," << tempMET.Py() << ")" << std::endl;

  TVector2 tempgamma((*(goodPhoton_cont))[0]->p4().Px(), (*(goodPhoton_cont))[0]->p4().Py());

  //std::cout << "Temp photon(px,py): (" << tempgamma.Px() << " ," << tempgamma.Py() << ")" << std::endl;


  TVector2 moreTemp = tempMET+tempgamma;

  //std::cout << "Combined PhotonMET (px,py): (" << moreTemp.Px() << " ," << moreTemp.Py() << ")" << std::endl;

  PhotonETMiss = moreTemp.Mod()*0.001;
  PhotonETMissPhi = TVector2::Phi_0_2pi(moreTemp.Phi());

  TLorentzVector g1v = (*goodPhoton_cont)[0]->p4()*0.001;
  pTgamma = g1v.Pt();
  phigamma = g1v.Phi();
  etagamma = g1v.Eta();


}


void CalculateVariables::CalculateOneLepVariables(NewObjectDef *objects, TLorentzVector b1v, TLorentzVector b2v, TLorentzVector tj1v){

  TLorentzVector l1v(0,0,0,0);

  if (nLepton == 1 && goodElectron_cont->size() == 1){
    l1v = (*goodElectron_cont)[0]->p4()*0.001;
    pTel1 = l1v.Pt();

    pTl1 = l1v.Pt();
    etal1 = l1v.Eta();
    phil1 = l1v.Phi();

    m_T = sqrt(2*(pTl1*eTMiss*(1 - cos(fabs(TVector2::Phi_mpi_pi( (phil1  - eTMissPhi)))))));
    TVector2 tempMET = *(METvector_cont);
    TVector2 tempEl ((*(goodElectron_cont))[0]->p4().Px(), (*(goodElectron_cont))[0]->p4().Py());
    TVector2 moreTemp = tempMET+tempEl;
    m_taulep = (tj1v+l1v).M();

    adjustedETMiss = moreTemp.Mod()*0.001;
    adjustedETMissPhi = moreTemp.Phi();

  }
  else if (nLepton == 1 && goodMuon_cont->size() == 1){
    l1v = (*goodMuon_cont)[0]->p4()*0.001;
    pTmu1 = l1v.Pt();

    pTl1 = l1v.Pt();
    etal1 = l1v.Eta();
    phil1 = l1v.Phi();

    m_T = sqrt(2*(pTl1*eTMiss*(1 - cos(fabs(TVector2::Phi_mpi_pi( (phil1  - eTMissPhi)))))));
    m_taulep = (tj1v+l1v).M();

  }


  double mbl11 = (l1v+b1v).M();
  m_b1l = mbl11;
  double mbl12 = (l1v+b2v).M();
  m_b2l = mbl12;
  if (bJet_cont->size()>=2) m_lbb = (l1v+b1v+b2v).M();



  TLorentzVector METVector(METvector_cont->X()/1000., METvector_cont->Y()/1000., 0 , 0);
  mbLmin = std::min(mbl11, mbl12);

  // Do the amT2 with b-jets ordered by btag weight
  auto jetVector_tagOrder = std::make_unique<xAOD::JetContainer>(SG::VIEW_ELEMENTS);
  if (nJets>=2){
    //order these jets by b-tag weight
    for(unsigned int i=0;i< nJets; i++){
      jetVector_tagOrder->push_back((*(goodJet_cont))[i]);
      double b_wgt;
      (*(goodJet_cont))[i]->btagging()->MVx_discriminant("MV2c10", b_wgt);
    }
    //Arrange these by b-tag order
    TLorentzVector j1v(0,0,0,0);
    TLorentzVector j2v(0,0,0,0);
    jetVector_tagOrder->sort(btag_wgt_Sorter);
    j1v = (*jetVector_tagOrder)[0]->p4()*0.001;
    j2v = (*jetVector_tagOrder)[1]->p4()*0.001;

    double amT2_1 = -99;
    double amT2_2 = -99;
    auto mT2Tool_1 = std::make_unique<ComputeMT2>(j1v, j2v+l1v, METVector, 80, 0);
    amT2_1 = mT2Tool_1->Compute();
    auto mT2Tool_2 = std::make_unique<ComputeMT2>(j1v+l1v, j2v, METVector, 0, 80);
    amT2_2 = mT2Tool_2->Compute();
    amT2=std::min(amT2_1,amT2_2);

  }
  minm_bl = std::min(mbl11, mbl12);
  maxm_bl = std::max(mbl11, mbl12);


  // dPhi variables
  dPhiL1MET = fabs(TVector2::Phi_mpi_pi( l1v.Phi() - eTMissPhi));
  dPhiL1b1 = fabs(l1v.DeltaPhi(b1v));
  dPhiL1b2 = fabs(l1v.DeltaPhi(b2v));
  minDPhiLb = std::min({dPhiL1b1,dPhiL1b2});

  // dEta variables

  dEtaL1bSystem = fabs(l1v.Eta() - ((b1v+b2v).Eta()));
  dEtaL1b1 = fabs(l1v.Eta() - b1v.Eta());
  dEtaL1b2 = fabs(l1v.Eta() - b2v.Eta());
  minDEtaLb = std::min({dEtaL1b1, dEtaL1b2});


  // dR variables
  dRL1b1 = l1v.DeltaR(b1v);
  dRL1b2 = l1v.DeltaR(b2v);
  minDRLb = std::min(dRL1b1, dRL1b2);




}


void CalculateVariables::CalculateTwoLepVariables(NewObjectDef *objects, TLorentzVector b1v, TLorentzVector b2v){

  TLorentzVector l1v(0,0,0,0);
  TLorentzVector l2v(0,0,0,0);
  auto leptVects = std::make_unique<std::vector<TLorentzVector>>();
  int muonIterator=0;
  int electronIterator=0;
  int stopper=0;

  //lepton pTs
  if (nElectron>0) pTel1 = (*goodElectron_cont)[0]->pt()*0.001;
  if (nElectron>1) pTel2 = (*goodElectron_cont)[1]->pt()*0.001;
  if (nMuon>0) pTmu1 = (*goodMuon_cont)[0]->pt()*0.001;
  if (nMuon>1) pTmu2 = (*goodMuon_cont)[1]->pt()*0.001;


  //Sort the electrons and muons by pT
  if (nLepton>=2){
    double muonpT=0;
    double electronpT=0;
    while(stopper==0){
      //Check the iterator is available
      if (muonIterator<nMuon){
	muonpT=(*goodMuon_cont)[muonIterator]->pt();
      }
      else muonpT=0.0;

      if (electronIterator<nElectron){
	electronpT=(*goodElectron_cont)[electronIterator]->pt();
      }
      else electronpT=0.0;
      //exit if there are none left
      if (muonpT ==0 && electronpT==0){
	stopper+=1;
	continue;
      }
      if (electronpT>muonpT){
	(*leptVects).push_back((*goodElectron_cont)[electronIterator]->p4()*0.001);
	electronIterator+=1;
      }
      else{
	(*leptVects).push_back((*goodMuon_cont)[muonIterator]->p4()*0.001);
	muonIterator+=1;
      }
    }
    l1v=(*leptVects)[0];
    l2v=(*leptVects)[1];
  }



  pTl1 = l1v.Pt();
  etal1 = l1v.Eta();
  phil1 = l1v.Phi();

  pTl2 = l2v.Pt();
  etal2 = l2v.Eta();
  phil2 = l2v.Phi();

  if (pTl1<pTl2){std::cout<<"The lepton pT stuff is screwed"<<std::endl;}




  m_T = sqrt(2*(pTl1*eTMiss*(1 - cos(fabs(TVector2::Phi_mpi_pi( (phil1  - eTMissPhi)))))));
  TVector2 tempMET = *(METvector_cont);
  TVector2 tempEl (l1v.Px(), l2v.Py());
  TVector2 moreTemp = tempMET+tempEl;

  adjustedETMiss = moreTemp.Mod()*0.001;
  adjustedETMissPhi = moreTemp.Phi();


  // Make Z Boson here

  TLorentzVector ZBoson = l1v+l2v;

  pTZ = ZBoson.Pt(); //
  etaZ = ZBoson.Eta(); //
  phiZ = ZBoson.Phi(); //

  DR_Zb1 = ZBoson.DeltaR(b1v);
  DR_Zb2 = ZBoson.DeltaR(b2v);
  minDR_Zb = std::min(DR_Zb1, DR_Zb2);
  DPhi_Zb1 = fabs(TVector2::Phi_mpi_pi( ZBoson.Phi() - b1v.Phi()));
  DPhi_Zb2 = fabs(TVector2::Phi_mpi_pi( ZBoson.Phi() - b2v.Phi()));
  DEta_Zb1 = fabs(ZBoson.Eta() - b1v.Eta());
  DEta_Zb2 = fabs(ZBoson.Eta() - b2v.Eta());




  m_ll = (l1v+l2v).M();

  double mbl11 = (l1v+b1v).M();
  double mbl12 = (l1v+b2v).M();
  m_b1l = std::min(mbl11,mbl12);

  double mbl21 = (l2v+b1v).M();
  double mbl22 = (l2v+b2v).M();
  m_b2l = std::min(mbl21,mbl22);

  mbLmin = std::min(mbl11, std::min(mbl12, std::min(mbl21, mbl22)));
  minm_bl = std::min(mbl11, std::min(mbl12, std::min(mbl21, mbl22)));
  maxm_bl = std::max(mbl11, std::max(mbl12, std::max(mbl21, mbl22)));

  // dPhi variables
  dPhiL1MET = fabs(TVector2::Phi_mpi_pi( l1v.Phi() - eTMissPhi));
  dPhiL2MET = fabs(TVector2::Phi_mpi_pi( l2v.Phi() - eTMissPhi));
  dPhiL1L2 = fabs(l1v.DeltaPhi(l2v));

  dPhiL1b1 = fabs(l1v.DeltaPhi(b1v));
  dPhiL1b2 = fabs(l1v.DeltaPhi(b2v));
  dPhiL2b1 = fabs(l2v.DeltaPhi(b1v));
  dPhiL2b2 = fabs(l2v.DeltaPhi(b2v));;

  minDPhiLb = std::min({dPhiL1b1,dPhiL1b2,dPhiL2b1,dPhiL2b2});

  // dEta variables
  dEtaL1L2 = fabs(l1v.Eta() - l2v.Eta());

  dEtaL1bSystem = fabs(l1v.Eta() - ((b1v+b2v).Eta()));
  dEtaL1b1 = fabs(l1v.Eta() - b1v.Eta());
  dEtaL1b2 = fabs(l1v.Eta() - b2v.Eta());

  dEtaL2bSystem = fabs(l2v.Eta() - ((b1v+b2v).Eta()));
  dEtaL2b1 = fabs(l2v.Eta() - b1v.Eta());
  dEtaL2b2 = fabs(l2v.Eta() - b2v.Eta());

  minDEtaLb = std::min({dEtaL1b1, dEtaL1b2, dEtaL2b1, dEtaL2b2});


  // dR variables
  dRL1b1 = l1v.DeltaR(b1v);
  dRL1b2 = l1v.DeltaR(b2v);
  dRL2b1 = l2v.DeltaR(b1v);
  dRL2b2 = l2v.DeltaR(b2v);
  dRL1L2 = l1v.DeltaR(l2v);

  minDRLb = std::min({dRL1b1, dRL1b2, dRL2b1, dRL2b2});
}

void CalculateVariables::CalculateShapeVariables(NewObjectDef *objects)
{
  // calculate transverse aplanarity and that

    TMatrixD a (3,3);

    for (int i = 0; i < 3; i++){
      for (int j = 0; j < 3; j++){
	a[i][j] = 0;
      }
    }


    // Loop over the Jets and add to the matrix

    for (int iJet = 0; iJet < nJets; iJet++){
      TLorentzVector tempJet = (*goodJet_cont)[iJet]->p4()*0.001;

      double px = tempJet.Px();
      double py = tempJet.Py();
      double pz = tempJet.Pz();
      double modp = ((px*px) + (py*py) + (pz*pz));


      a[0][0] = a[0][0]+((px*px)/modp);
      a[0][1] = a[0][1]+((px*py)/modp);
      a[0][2] = a[0][1]+((px*pz)/modp);

      a[1][0] = a[1][0]+((py*px)/modp);
      a[1][1] = a[1][1]+((py*py)/modp);
      a[1][2] = a[1][2]+((py*pz)/modp);

      a[2][0] = a[2][0]+((pz*px)/modp);
      a[2][1] = a[2][1]+((pz*py)/modp);
      a[2][2] = a[2][2]+((pz*pz)/modp);
    }

    // loop over the muons and add to the matrix

    for (int iMu = 0; iMu < nMuon ; iMu++){
      TLorentzVector tempMu = (*goodMuon_cont)[iMu]->p4()*0.001;

      double px = tempMu.Px();
      double py = tempMu.Py();
      double pz = tempMu.Pz();
      double modp = ((px*px) + (py*py) + (pz*pz));


      a[0][0] = a[0][0]+((px*px)/modp);
      a[0][1] = a[0][1]+((px*py)/modp);
      a[0][2] = a[0][1]+((px*pz)/modp);

      a[1][0] = a[1][0]+((py*px)/modp);
      a[1][1] = a[1][1]+((py*py)/modp);
      a[1][2] = a[1][2]+((py*pz)/modp);

      a[2][0] = a[2][0]+((pz*px)/modp);
      a[2][1] = a[2][1]+((pz*py)/modp);
      a[2][2] = a[2][2]+((pz*pz)/modp);
    }


    // loop over the electrons and add to the matrix

    for (int iEl = 0; iEl < nElectron ; iEl++){
      TLorentzVector tempEl = (*goodElectron_cont)[iEl]->p4()*0.001;

      double px = tempEl.Px();
      double py = tempEl.Py();
      double pz = tempEl.Pz();
      double modp = ((px*px) + (py*py) + (pz*pz));


      a[0][0] = a[0][0]+((px*px)/modp);
      a[0][1] = a[0][1]+((px*py)/modp);
      a[0][2] = a[0][1]+((px*pz)/modp);

      a[1][0] = a[1][0]+((py*px)/modp);
      a[1][1] = a[1][1]+((py*py)/modp);
      a[1][2] = a[1][2]+((py*pz)/modp);

      a[2][0] = a[2][0]+((pz*px)/modp);
      a[2][1] = a[2][1]+((pz*py)/modp);
      a[2][2] = a[2][2]+((pz*pz)/modp);
    }


    // Calculate the eigenvalues of this matrix

    TMatrixDEigen eM (a);

    TMatrixD M = eM.GetEigenValues();



    double eigen_a = M[0][0];
    double eigen_b = M[1][1];
    double eigen_c = M[2][2];

    // Calculate the sum of the eigen values to normalise them to 1
    double eigen_sum = eigen_a + eigen_b + eigen_c;

    // Normalise and calculate abs
    eigen_a = abs(eigen_a/eigen_sum);
    eigen_b = abs(eigen_b/eigen_sum);
    eigen_c = abs(eigen_c/eigen_sum);


    double smallest = std::min({eigen_a,eigen_b,eigen_c});

    Aplanarity = (3/2)*smallest;

    transformedAplan = exp(-8*Aplanarity);

    if ( (eigen_a > eigen_b) && (eigen_a > eigen_c) ){
      Sphericity = (3/2)*(eigen_b + eigen_c);
    }

    if ( (eigen_b > eigen_a) && (eigen_b > eigen_c) ){
      Sphericity = (3/2)*(eigen_a + eigen_c);
    }

    if ( (eigen_c > eigen_a) && (eigen_c > eigen_b) ){
      Sphericity = (3/2)*(eigen_a + eigen_b);
    }


}


void CalculateVariables::CalculateRazorVariables(NewObjectDef *objects)
{

  //////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////
  // Set up RestFrames code
  //////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////

  //////////////////////////////////////////////////////////////
  // different 'Frames' of interest
  //////////////////////////////////////////////////////////////
  //std::cout << " Initialize lists of visible, invisible particles and intermediate states " << endl;
  RLabFrame LAB("LAB","lab");
  RDecayFrame SS("SS","SS");
  RSelfAssemblingFrame S1("S1","#tilde{S}_{a}");
  RSelfAssemblingFrame S2("S2","#tilde{S}_{b}");
  RVisibleFrame V1("V1","V_{a}");
  RVisibleFrame V2("V2","V_{b}");
  RInvisibleFrame I1("I1","I_{a}");
  RInvisibleFrame I2("I2","I_{b}");

  //////////////////////////////////////////////////////////////
  // different 'groups' of particles
  //////////////////////////////////////////////////////////////
  //std::cout << " Define invisible and combinatoric groups " << endl;

  // The invisible group is all of the weakly interacting particles
  InvisibleGroup INV("INV","Invisible State Jigsaws");
  INV.AddFrame(I1);
  INV.AddFrame(I2);

  // the combinatoric group is the list of visible objects
  // that go into our hemispheres
  CombinatoricGroup VIS("VIS","Visible Object Jigsaws");
  VIS.AddFrame(V1);
  VIS.SetNElementsForFrame(V1,1,false);
  VIS.AddFrame(V2);
  VIS.SetNElementsForFrame(V2,1,false);

  //////////////////////////////////////////////////////////////
  // define how all the frames connect in the decay tree
  //////////////////////////////////////////////////////////////
  //std::cout << " Build decay tree " << endl;
  LAB.SetChildFrame(SS);

  SS.AddChildFrame(S1);
  SS.AddChildFrame(S2);

  S1.AddChildFrame(V1);
  S1.AddChildFrame(I1);
  S2.AddChildFrame(V2);
  S2.AddChildFrame(I2);

  //////////////////////////////////////////////////////////////
  // check to make sure the tree is acceptably connected
  //////////////////////////////////////////////////////////////
  //std::cout << "Is consistent tree topology? " << LAB.InitializeTree() << endl;
  LAB.InitializeTree();
  //////////////////////////////////////////////////////////////
  // now we define 'jigsaw rules' that tell the tree
  // how to define the objects in our groups
  //////////////////////////////////////////////////////////////
  InvisibleMassJigsaw MinMassJigsaw("MINMASS_JIGSAW", "Invisible system mass Jigsaw");
  INV.AddJigsaw(MinMassJigsaw);

  InvisibleRapidityJigsaw RapidityJigsaw("RAPIDITY_JIGSAW", "Invisible system rapidity Jigsaw");
  INV.AddJigsaw(RapidityJigsaw);
  RapidityJigsaw.AddVisibleFrame((LAB.GetListVisibleFrames()));

  ContraBoostInvariantJigsaw ContraBoostJigsaw("CB_JIGSAW","Contraboost invariant Jigsaw");
  INV.AddJigsaw(ContraBoostJigsaw);
  ContraBoostJigsaw.AddVisibleFrame((S1.GetListVisibleFrames()), 0);
  ContraBoostJigsaw.AddVisibleFrame((S2.GetListVisibleFrames()), 1);
  ContraBoostJigsaw.AddInvisibleFrame((S1.GetListInvisibleFrames()), 0);
  ContraBoostJigsaw.AddInvisibleFrame((S2.GetListInvisibleFrames()), 1);

  MinimizeMassesCombinatoricJigsaw HemiJigsaw("HEM_JIGSAW","Minimize m _{V_{a,b}} Jigsaw");
  VIS.AddJigsaw(HemiJigsaw);
  HemiJigsaw.AddFrame(V1,0);
  HemiJigsaw.AddFrame(V2,1);

  //////////////////////////////////////////////////////////////
  // check to make sure that all the jigsaws etc. are correctly connected
  //////////////////////////////////////////////////////////////
  //std::cout << "Is consistent analysis tree? : " << LAB.InitializeAnalysis() << endl;
  LAB.InitializeAnalysis();
  //////////////////////////////////////////////////////////////
  // draw some pictures of our tree
  //////////////////////////////////////////////////////////////
  /*FramePlot* TreePlot = new FramePlot("tree","Decay Tree");
  TreePlot->AddFrameTree(LAB);
  TreePlot->AddJigsaw(ContraBoostJigsaw);
  TreePlot->AddJigsaw(HemiJigsaw);
  TreePlot->DrawFramePlot();

  FramePlot* INVPlot = new FramePlot("inv","Invisible Objects Jigsaws");
  INVPlot->AddGroupTree(INV);
  INVPlot->DrawFramePlot();

  FramePlot* VISPlot = new FramePlot("vis","Visible Objects Jigsaws");
  VISPlot->AddGroupTree(VIS);
  VISPlot->DrawFramePlot();
  */
  //////////////////////////////////////////////////////////////
  // Now, we make a 'background'-like, transverse momentum only, tree
  //////////////////////////////////////////////////////////////
  RLabFrame LAB_alt("LAB","lab");
  RSelfAssemblingFrame S_alt("CM","CM");
  RVisibleFrame V_alt("V_alt","Vis");
  RInvisibleFrame I_alt("I_alt","Iinv");

  InvisibleGroup INV_alt("INV_alt","Invisible State Jigsaws");
  INV_alt.AddFrame(I_alt);

  CombinatoricGroup VIS_alt("VIS_alt","Visible Object Jigsaws");
  VIS_alt.AddFrame(V_alt);
  VIS_alt.SetNElementsForFrame(V_alt,1,false);

  LAB_alt.SetChildFrame(S_alt);
  S_alt.AddChildFrame(V_alt);
  S_alt.AddChildFrame(I_alt);

  LAB_alt.InitializeTree();

  // Will just set invisible mass to zero
  InvisibleMassJigsaw MinMass_alt("MINMASS_JIGSAW_ALT", "Invisible system mass Jigsaw");
  INV_alt.AddJigsaw(MinMass_alt);

  // will set rapidity to zero
  InvisibleRapidityJigsaw Rapidity_alt("RAPIDITY_JIGSAW_ALT", "Invisible system rapidity Jigsaw");
  INV_alt.AddJigsaw(Rapidity_alt);
  Rapidity_alt.AddVisibleFrame((LAB_alt.GetListVisibleFrames()));

  LAB_alt.InitializeAnalysis();


  //
  // TEST EVENT Reconcstruction
  //
  int TotalJets = goodJet_cont->size();;
  vector<TLorentzVector> JETS;
  for(int ijet = 0; ijet < TotalJets; ijet++){
    TLorentzVector currentJet = (0.001*(*goodJet_cont)[ijet]->p4());
    JETS.push_back(currentJet);
    //std::cout << "Jet Energy = " << currentJet.E() << std::endl;
  }
    TVector2 tempMET = *(METvector_cont);
    TVector3 MET(tempMET.Px()*0.001,tempMET.Py()*0.001,0.);
    //std::cout << MET.Px() << "MET pX" << std::endl;


    LAB.ClearEvent();
    // can use this to see where
    // each jet ended up in the tree
    vector<GroupElementID> jetID;

    // // add the jets to the 'VIS' group
    for(int i = 0; i < int(JETS.size()); i++)
      jetID.push_back(VIS.AddLabFrameFourVector(JETS[i]));
    // Set the 'INV' group momentum in
    // the lab frame (the MET)
    INV.SetLabFrameThreeVector(MET);
    LAB.AnalyzeEvent();

    // Do the same for 'background' tree - set
    // jets' z-momenta to zero before loading into tree
    LAB_alt.ClearEvent();
    for(int i = 0; i < int(JETS.size()); i++){
      TLorentzVector jet = JETS[i];
      jet.SetPtEtaPhiM(jet.Pt(), 0., jet.Phi(), jet.M());
      VIS_alt.AddLabFrameFourVector(jet);
    }
    INV_alt.SetLabFrameThreeVector(MET);
    LAB_alt.AnalyzeEvent();

    //////////////////////////////////////
    // Calculation of ZeroLepton variables
    /////////////////////////////////////

    // primary observables
    double shatR = SS.GetMass();
    //std::cout << "shatR =  " << shatR << std::endl;

    double gaminvRp1 = SS.GetVisibleShape();
    //std::cout << "1/(gamma_{R+1}) =  " << gaminvRp1 << std::endl;

    double MdeltaR = ((sqrt(shatR))*gaminvRp1)/2;
    //std::cout << "M_{Delta}^{R} = " << MdeltaR << std::endl;

    double testMdeltaR = (shatR*gaminvRp1)/2;
    //std::cout << "test M_{Delta}^{R} = " << testMdeltaR << std::endl;
    RJVarsSS_wrongMDelR = testMdeltaR;

    // some other 'angle'-like things from the CM frame
    double costhetaSS = SS.GetCosDecayAngle();
    double gaminvRp1_T = SS.GetTransverseVisibleShape();
    double dphi12 = SS.GetDeltaPhiVisible();
    double scalarMomTransverseRatio = SS.GetTransverseScalarVisibleMomentum()/SS.GetScalarVisibleMomentum();

    // dphiR and Rptshat (formerly cosPT)
    // for QCD rejection
    double dphiR = SS.GetDeltaPhiBoostVisible();
    //std::cout << "dphiR = " << dphiR << std::endl;

    double PTCM = SS.GetFourVector(LAB).Pt();
    //std::cout << "PTCM = " << PTCM << std::endl;

    double Rptshat = PTCM / (PTCM + shatR/4.);
    //std::cout << "Rptshat = " << Rptshat << std::endl;


    // QCD rejection using the 'background tree'
    // MET 'sibling' in background tree auxillary calculations
    TLorentzVector Psib = I_alt.GetSiblingFrame()->GetFourVector(LAB_alt);
    TLorentzVector Pmet = I_alt.GetFourVector(LAB_alt);
    double Psib_dot_METhat = max(0., Psib.Vect().Dot(MET.Unit()));
    double Mpar2 = Psib.E()*Psib.E()-Psib.Vect().Dot(MET.Unit())*Psib.Vect().Dot(MET.Unit());
    double Msib2 = Psib.M2();
    double MB2 = 2.*(Pmet.E()*Psib.E()-MET.Dot(Psib.Vect()));
    TVector3 boostPsibM = (Pmet+Psib).BoostVector();

    // QCD rejection variables from 'background tree'
    double DepthBKG = S_alt.GetFrameDepth(I_alt);
    int Nsib = I_alt.GetSiblingFrame()->GetNDescendants();
    double cosBKG = I_alt.GetParentFrame()->GetCosDecayAngle();
    double dphiMsib = fabs(MET.DeltaPhi(Psib.Vect()));
    double RpsibM = Psib_dot_METhat / (Psib_dot_METhat + MET.Mag());
    double RmsibM = 1. / ( MB2/(Mpar2-Msib2) + 1.);
    Psib.Boost(-boostPsibM);
    double cosPsibM = -1.*Psib.Vect().Unit().Dot(boostPsibM.Unit());
    cosPsibM = (1.-cosPsibM)/2.;
    double DeltaQCD1 = (cosPsibM-RpsibM)/(cosPsibM+RpsibM);
    //std::cout << "DeltaQCD1 = " << DeltaQCD1 << std::endl;
    double DeltaQCD2 = (cosPsibM-RmsibM)/(cosPsibM+RmsibM);

    RJVars_QCD_Delta = DeltaQCD1;
    RJVarsSS_invGamma = gaminvRp1;
    RJVarsSS_s_hat = shatR;
    RJVarsSS_MDelR = MdeltaR;

    // Hemisphere variables - still studying to improve this part
    int NJ[2];
    double ND[2];
    double cosD[2][3];  // cos-decay angle at some depth
    double RATIO[2][3]; // momentum-ratio between depths
    RestFrame *V[2],*I[2],*S[2];
    V[0] = &V1;
    V[1] = &V2;
    I[0] = &I1;
    I[1] = &I2;
    S[0] = &S1;
    S[1] = &S2;

    for(int h = 0; h < 2; h++){
      NJ[h] = VIS.GetNElementsInFrame(V[h]);
      ND[h] = S[h]->GetFrameDepth(I[h]);
      for(int d = 0; d < 3; d++){
	if(d >= ND[h]){
	  cosD[h][d] = -2.;
	  RATIO[h][d] = -2.;
	  continue;
	}
        const RestFrame* frame = S[h]->GetFrameAtDepth(d+1, I[h]);
	const RestFrame* prod_frame = frame->GetProductionFrame();
	const RestFrame* prod_prod_frame = prod_frame->GetProductionFrame();

	RATIO[h][d] = 2./sqrt(3.)*frame->GetMomentum(prod_frame)/prod_frame->GetMomentum(prod_prod_frame);
	cosD[h][d] = prod_frame->GetCosDecayAngle(frame);
      }
    }
}
