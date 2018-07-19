#ifndef TruthObjectDef_h
#define TruthObjectDef_h


#include "IObjectDef.h"
#include <time.h>       /* time */
#include <random>

// objects go here
class TruthObjectDef: public virtual IObjectDef

{

 public:
  //TruthObjectDef with fat jets fails on PsuedoJetGetter
  TruthObjectDef(xAOD::TEvent* event, ST::SUSYObjDef_xAOD* SUSYTool, xAOD::TStore* store, double mcChannelNumber, double eventN, double mcEventWgt, double crosssect, std::string systName, bool doPhotons, asg::AnaToolHandle<IMETSignificance> Tool_METSig); //, JetToolRunner* Tool_FatJets_kt12, JetToolRunner* Tool_FatJets_kt8

  ~TruthObjectDef(){};

  JetToolRunner* fatjet_kt12_tool;
  JetToolRunner* fatjet_kt8_tool;

  // Function to set all of the objects using SUSYTools
  void FillPreORMuons();
  void FillPreORElectrons();
  void FillPreORTaus();
  void FillPreORPhotons();
  void FillPreORJets();
  void FillMET();
  void FillOldMET(){std::cout << "This isn't used" << std::endl;};

  void OverlapRemoval();
  void OldOverlapRemoval();

  void FillBaselineElectrons();
  void FillBaselineMuons();
  void FillBaselineTaus();
  void FillBaselinePhotons();
  void FillGoodJets();
  void FillFatJets_kt8();
  void FillFatJets_kt12();
  void SetPrimVertex();

  bool SetUpFatJetTools(JetToolRunner *& tool, double jetradius, std::string inputcontainer, std::string outputcontainer);
  
  
  // Getters
  xAOD::JetContainer* getBadJets(){return badJets;};
  xAOD::JetContainer* getGoodJets(){return goodJets;};
  xAOD::JetContainer* getGoodJets_beforeOR(){return goodJets;};
  xAOD::JetContainer* getFatJets_kt8(){return FatJets_kt12;};
  xAOD::JetContainer* getFatJets_kt12(){return FatJets_kt12;};
  xAOD::JetContainer* getBJets(){return BJets;};
  xAOD::JetContainer* getNonBJets(){return nonBJets;};
  xAOD::TruthParticleContainer* getBaselineMuons(){return baselineMuons;};
  xAOD::TruthParticleContainer* getBaselineElectrons(){return baselineElectrons;};
  xAOD::TruthParticleContainer* getBaselineTaus(){return baselineTaus;};
  xAOD::TruthParticleContainer* getBaselinePhotons(){return baselinePhotons;};
  xAOD::TruthParticleContainer* getGoodMuons(){return goodMuons;};
  xAOD::TruthParticleContainer* getBadMuons(){return badMuons;};
  xAOD::TruthParticleContainer* getCosmicMuons(){return cosmicMuons;};
  xAOD::TruthParticleContainer* getGoodPhotons(){return goodPhotons;};
  xAOD::TruthParticleContainer* getGoodElectrons(){return goodElectrons;};
  xAOD::TruthParticleContainer* getGoodTaus(){return goodTaus;};
  std::vector<double> getMETSignificance(){return metSignificances;}; 
  TVector2* getMETvector(){return METvector;};
  double getMET(){return MET;};
  double getMETPhi(){return METphi;};
  double getMuonSF(){return muonSF;};
  double getOldMuonSF(){return oldMuonSF;};
  double getPhotonSF(){return photonSF;};
  double getElectronSF(){return electronSF;};
  double getTauSF(){return tauSF;};
  double getElectronTriggerSF(){return electronTriggerSF;};
  double getTauTriggerSF(){return tauTriggerSF;};
  double getBJetSF(){return bJetSF;};
  double getJVTSF(){return JVTSF;};
  double getLeptonSF(){return electronSF*muonSF*tauSF;};
  int getPrimVertex(){return nVertex;};

 private:
  xAOD::TruthParticleContainer* baselineElectronsBeforeOR;
  xAOD::TruthParticleContainer* signalElectronsBeforeOR;
  xAOD::TruthParticleContainer* baselineTausBeforeOR;
  xAOD::TruthParticleContainer* signalTausBeforeOR;
  xAOD::JetContainer* goodJetsBeforeOR;
  xAOD::TruthParticleContainer* baselineMuonsBeforeOR;
  xAOD::TruthParticleContainer* signalMuonsBeforeOR;
  xAOD::TruthParticleContainer* baselinePhotonsBeforeOR;
  xAOD::TruthParticleContainer* signalPhotonsBeforeOR;
  xAOD::JetContainer* badJets;
  xAOD::TruthParticleContainer* cosmicMuons;
  xAOD::TruthParticleContainer* badMuons;
  xAOD::TruthParticleContainer* baselineElectrons;
  xAOD::TruthParticleContainer* baselineTaus;
  xAOD::TruthParticleContainer* baselineMuons;  
  xAOD::TruthParticleContainer* baselinePhotons;  
  xAOD::JetContainer* goodJets;
  xAOD::JetContainer* FatJets_kt8;
  xAOD::JetContainer* FatJets_kt12;
  xAOD::JetContainer* goodAntiKt4TruthJets;
  xAOD::JetContainer* goodAntiKt3TruthJets;
  xAOD::TruthParticleContainer* goodElectrons;
  xAOD::TruthParticleContainer* goodMuons;
  xAOD::TruthParticleContainer* goodTaus;
  xAOD::TruthParticleContainer* goodPhotons;
  xAOD::JetContainer* BJets;
  xAOD::JetContainer* nonBJets;
  xAOD::TruthParticleContainer* METmuons;  

  double MET;
  double METphi;
  TVector2* METvector;
  double muonSF;
  double oldMuonSF;
  double photonSF;
  double electronSF;
  double tauSF;
  double electronTriggerSF;
  double tauTriggerSF;
  double bJetSF;
  double JVTSF;
  int nVertex;

  bool doPhotonOR;

  asg::AnaToolHandle<IMETSignificance> METSig_tool; 

  //JetToolRunner* fatjet_kt12_tool;
  //JetToolRunner* fatjet_kt8_tool;

  std::vector<double> metSignificances;


  bool elTriggerMatch(){return 1;};
  bool muTriggerMatch(){return 1;};
  bool taTriggerMatch(){return 1;};
  bool phTriggerMatch(){return 1;};



  //  double eventNumber



};
#endif
