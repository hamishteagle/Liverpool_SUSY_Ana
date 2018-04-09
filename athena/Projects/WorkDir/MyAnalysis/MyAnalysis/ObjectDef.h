#ifndef ObjectDef_h
#define ObjectDef_h

#include "IObjectDef.h"

// objects go here

class ObjectDef: public virtual IObjectDef

{

 public:
  ObjectDef(xAOD::TEvent* event, ST::SUSYObjDef_xAOD* SUSYTool, xAOD::TStore* store, double mcChannelNumber, double eventN, double mcEventWgt, double crosssect, std::string systName, bool doPhotons, JetToolRunner* Tool_FatJets_kt12, JetToolRunner* Tool_FatJets_kt8, asg::AnaToolHandle<IMETSignificance> Tool_METSig);

  ~ObjectDef(){};

  // Function to set all of the objects using SUSYTools
  void FillPreORMuons();
  void FillPreORElectrons();
  void FillPreORTaus();
  void FillPreORJets();
  void FillPreORPhotons();
  void FillMET();
  void FillOldMET();

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


  
  // Getters
  xAOD::JetContainer* getBadJets(){return badJets;};
  xAOD::JetContainer* getGoodJets(){return goodJets;};
  xAOD::JetContainer* getFatJets_kt8(){return FatJets_kt8;};
  xAOD::JetContainer* getFatJets_kt12(){return FatJets_kt12;};
  xAOD::JetContainer* getBJets(){return BJets;};
  xAOD::JetContainer* getNonBJets(){return nonBJets;};
  xAOD::ElectronContainer* getBaselineElectrons(){return baselineElectrons;};
  xAOD::ElectronContainer* getGoodElectrons(){return goodElectrons;};
  xAOD::MuonContainer* getBaselineMuons(){return baselineMuons;};
  xAOD::MuonContainer* getGoodMuons(){return goodMuons;};
  xAOD::MuonContainer* getBadMuons(){return badMuons;};
  xAOD::TauJetContainer* getBaselineTaus(){return baselineTaus;};
  xAOD::TauJetContainer* getGoodTaus(){return goodTaus;};
  xAOD::PhotonContainer* getBaselinePhotons(){return baselinePhotons;};
  xAOD::PhotonContainer* getGoodPhotons(){return goodPhotons;};
  std::vector<double> getMETSignificance(){return metSignificances;}; 
  

  TVector2* getMETvector(){return METvector;};
  double getMET(){return MET;};
  double getMETPhi(){return METphi;};
  double getMuonSF(){return muonSF;};
  double getOldMuonSF(){return oldMuonSF;};
  double getElectronSF(){return electronSF;};
  double getElectronTriggerSF(){return electronTriggerSF;};
  double getTauSF(){return tauSF;};
  double getTauTriggerSF(){return tauTriggerSF;};
  double getPhotonSF(){return photonSF;};
  double getBJetSF(){return bJetSF;};
  double getJVTSF(){return JVTSF;};
  double getLeptonSF(){return electronSF*muonSF*electronTriggerSF;};

  int getPrimVertex(){return nVertex;};

  bool elTriggerMatch(){return passElectronTriggerMatch;};
  bool muTriggerMatch(){return passMuonTriggerMatch;};
  bool taTriggerMatch(){return passTauTriggerMatch;};
  bool phTriggerMatch(){return passPhotonTriggerMatch;};


 private:
  xAOD::ElectronContainer*  baselineElectronsBeforeOR;
  xAOD::ElectronContainer* signalElectronsBeforeOR;
  xAOD::TauJetContainer*  baselineTausBeforeOR;
  xAOD::TauJetContainer* signalTausBeforeOR;
  xAOD::JetContainer* goodJetsBeforeOR;
  xAOD::MuonContainer* baselineMuonsBeforeOR;
  xAOD::MuonContainer* signalMuonsBeforeOR;
  xAOD::PhotonContainer* baselinePhotonsBeforeOR;
  xAOD::PhotonContainer* signalPhotonsBeforeOR;
  xAOD::JetContainer* badJets;
  xAOD::MuonContainer* cosmicMuons;
  xAOD::MuonContainer* badMuons;
  xAOD::ElectronContainer* baselineElectrons;
  xAOD::TauJetContainer* baselineTaus;
  xAOD::MuonContainer* baselineMuons;  
  xAOD::PhotonContainer* baselinePhotons;  
  xAOD::JetContainer* goodJets;
  xAOD::JetContainer* FatJets_kt8;
  xAOD::JetContainer* FatJets_kt12;
  xAOD::JetContainer* goodAntiKt4TruthJets;
  xAOD::JetContainer* goodAntiKt3TruthJets;
  xAOD::ElectronContainer* goodElectrons;
  xAOD::TauJetContainer* goodTaus;
  xAOD::MuonContainer* goodMuons;
  xAOD::PhotonContainer* goodPhotons;
  xAOD::JetContainer* BJets;
  xAOD::JetContainer* nonBJets;
  xAOD::MuonContainer* METmuons;  
  

  double MET;
  double METphi;
  int DSID;

  TVector2* METvector;
  double muonSF;
  double oldMuonSF;
  double electronSF;
  double electronTriggerSF;
  double tauSF;
  double tauTriggerSF;
  double photonSF;
  double bJetSF;
  double JVTSF;
  int nVertex;

  JetToolRunner* fatjet_kt12_tool;
  JetToolRunner* fatjet_kt8_tool;

  asg::AnaToolHandle<IMETSignificance> METSig_tool; 

  std::vector<double> metSignificances;

  bool passElectronTriggerMatch;
  bool passMuonTriggerMatch;
  bool passTauTriggerMatch;
  bool passPhotonTriggerMatch;




};
#endif
