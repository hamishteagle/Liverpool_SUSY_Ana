#ifndef IObjectDef_h
#define IObjectDef_h


// objects go here

#include <iostream>

#include "xAODRootAccess/TEvent.h"

#include "xAODMuon/MuonContainer.h"
//#include "xAODTau/TauContainer.h"
#include "xAODEgamma/ElectronContainer.h"
#include "xAODTruth/TruthParticleAuxContainer.h"
#include "xAODJet/JetContainer.h"
#include "xAODJet/JetAuxContainer.h"
#include "xAODCaloEvent/CaloCluster.h"
#include "xAODTruth/TruthParticleContainer.h"
#include "xAODTruth/TruthEventContainer.h"
#include "xAODTruth/TruthEvent.h"
#include "xAODCore/ShallowCopy.h"
#include "xAODMissingET/MissingETContainer.h"
#include "xAODMissingET/MissingETAuxContainer.h"
#include "xAODBTaggingEfficiency/BTaggingEfficiencyTool.h"
#include "xAODBase/IParticleHelpers.h"
#include "xAODEgamma/EgammaxAODHelpers.h"
//#include "xAODTau/TauxAODHelpers.h"
#include "xAODMissingET/MissingETComposition.h"

#include "SUSYTools/SUSYObjDef_xAOD.h"

#include "xAODCore/ShallowCopy.h"
#include "xAODTruth/TruthParticleContainer.h"
#include "xAODTruth/TruthEventContainer.h"
#include "xAODTruth/TruthEvent.h"
#include "xAODBase/IParticleHelpers.h"
#include "xAODMuon/Muon.h"
#include "xAODEgamma/EgammaxAODHelpers.h"

#include "AsgTools/SgTEvent.h"
#include "xAODRootAccess/Init.h"
#include "xAODRootAccess/TEvent.h"
#include "xAODRootAccess/TStore.h"
#include "xAODRootAccess/TActiveStore.h"

#include "JetRec/PseudoJetGetter.h"
#include "JetRec/JetFromPseudojet.h"
#include "JetRec/JetFinder.h"
#include "JetRec/JetSplitter.h"
#include "JetRec/JetRecTool.h"
#include "JetRec/JetDumper.h"
#include "JetRec/JetToolRunner.h"

#include "AsgTools/ToolHandle.h"

#include "CPAnalysisExamples/errorcheck.h"

#include "AsgTools/AsgTool.h"       
#include "AsgTools/IAsgTool.h"
#include "AsgTools/AsgMessaging.h"

#include "xAODJet/JetTypes.h"

#include "xAODEgamma/Electron.h"
#include "xAODEgamma/ElectronContainer.h"
#include "xAODMuon/Muon.h"
#include "xAODMuon/MuonContainer.h"
//#include "xAODTau/Tau.h"
//#include "xAODTau/TauContainer.h"
#include "xAODTracking/TrackingPrimitives.h"
#include "xAODJet/Jet.h"
#include "xAODJet/JetContainer.h"
#include "xAODEgamma/Photon.h"
#include "xAODEgamma/PhotonContainer.h"
//#include "xAODTau/TauJet.h"
//#include "xAODTau/TauJetContainer.h"
#include "xAODEventInfo/EventInfo.h"
#include "xAODJet/JetTypes.h"
#include "xAODMissingET/MissingET.h"
#include "xAODMissingET/MissingETContainer.h"
#include "xAODMissingET/MissingETAuxContainer.h"
#include "xAODMissingET/MissingETComposition.h"

#include "JetCalibTools/JetCalibrationTool.h"
#include "MuonMomentumCorrections/MuonCalibrationAndSmearingTool.h"
#include "JetResolution/JERTool.h"
#include "MuonEfficiencyCorrections/MuonEfficiencyScaleFactors.h"
#include "METUtilities/METRebuilder.h"
#include "METUtilities/METSignificance.h"

#include "ElectronEfficiencyCorrection/AsgElectronEfficiencyCorrectionTool.h"

//#include "PATInterfaces/SystematicCode.h"
//#include "PATInterfaces/SystematicSet.h"
//#include "PATInterfaces/SystematicList.h"
//#include "PATInterfaces/SystematicRegistry.h"
//#include "PATInterfaces/SystematicVariation.h"

#include "xAODBTaggingEfficiency/BTaggingEfficiencyTool.h"

#include "TauAnalysisTools/TauSelectionTool.h"

#include "TauAnalysisTools/TauSelectionTool.h"
#include "TauAnalysisTools/TauEfficiencyCorrectionsTool.h"
#include "TauAnalysisTools/TauSmearingTool.h"

#include "JetRec/JetToolRunner.h"

#include "AssociationUtils/OverlapRemovalTool.h"


#include "AsgTools/AsgTool.h"       
#include "AsgTools/IAsgTool.h"
#include "AsgTools/AsgMessaging.h"
#include "xAODBase/IParticle.h"


//#include "JetSimTools/TruthPseudoJetGetter.h"
//#include "JetSimTools/JetTruthParticleSelectorTool.h"
//#include "JetSimTools/IJetTruthParticleSelectorTool.h"

class IObjectDef
{

 public:
  
  IObjectDef(xAOD::TEvent* event, ST::SUSYObjDef_xAOD* SUSYTool, xAOD::TStore* store, double mcChannelNumber, double eventN, double mcEventWgt, double crossSect, std::string systName, bool doPhotons){
    
    
    currentEvent = event;
    objTool = SUSYTool;
    eventStore = store;
    mcID = mcChannelNumber;
    eventNumber = eventN;
    mcEventWeight = mcEventWgt;
    xSect = crossSect;
    systematic = systName;
    doPhotonOR = doPhotons;
  };
  
  virtual ~IObjectDef(){};
  
  virtual void FillPreORMuons() = 0;
  virtual void FillPreORElectrons() = 0;
  virtual void FillPreORTaus() = 0;
  virtual void FillPreORPhotons() = 0;
  virtual void FillPreORJets() = 0;
  virtual void FillMET() = 0;
  virtual void FillOldMET() = 0;
  virtual void OverlapRemoval() = 0;
  virtual void FillBaselineElectrons() = 0;
  virtual void FillBaselineTaus() = 0;
  virtual void FillBaselineMuons() = 0;
  virtual void FillBaselinePhotons() = 0;
  virtual void FillGoodJets() = 0;
  virtual void FillFatJets_kt8() = 0;
  virtual void FillFatJets_kt12() = 0;
  virtual void SetPrimVertex() = 0;

  virtual xAOD::JetContainer* getBadJets() = 0;
  virtual xAOD::JetContainer* getGoodJets() = 0;
  virtual xAOD::JetContainer* getFatJets_kt8() = 0;
  virtual xAOD::JetContainer* getFatJets_kt12() = 0;
  virtual xAOD::JetContainer* getBJets() = 0;
  virtual xAOD::JetContainer* getNonBJets() = 0;
  virtual xAOD::IParticleContainer* getBaselineMuons() = 0;
  virtual xAOD::IParticleContainer* getBaselineElectrons() = 0;
  virtual xAOD::IParticleContainer* getBaselineTaus() = 0;
  virtual xAOD::IParticleContainer* getGoodMuons() = 0;
  virtual xAOD::IParticleContainer* getGoodPhotons() = 0;
  virtual xAOD::IParticleContainer* getBadMuons() = 0;
  virtual xAOD::IParticleContainer* getGoodElectrons() = 0;
  virtual xAOD::IParticleContainer* getGoodTaus() = 0;
  virtual std::vector<double> getMETSignificance() = 0;
  virtual TVector2* getMETvector() = 0;
  virtual double getMET() = 0;
  virtual double getMETPhi() = 0;
  virtual double getMuonSF() = 0;
  virtual double getOldMuonSF() = 0;
  virtual double getPhotonSF() = 0;
  virtual double getElectronSF() = 0;
  virtual double getElectronTriggerSF() = 0;
  virtual double getTauSF() = 0;
  virtual double getTauTriggerSF() = 0;
  virtual double getBJetSF() = 0;
  virtual double getJVTSF() = 0;
  virtual double getLeptonSF() = 0;
  virtual int getPrimVertex() = 0;

  virtual bool elTriggerMatch() = 0;
  virtual bool muTriggerMatch() = 0;
  virtual bool taTriggerMatch() = 0;
  virtual bool phTriggerMatch() = 0;



  
 public:
  xAOD::TEvent* currentEvent;
  ST::SUSYObjDef_xAOD* objTool;  
  xAOD::TStore* eventStore;

  
  // useful variables for debugging purposes
  double mcID;
  double xSect;
  double eventNumber;
  double mcEventWeight;
  bool doPhotonOR;
  std::string systematic;

 
};
#endif
