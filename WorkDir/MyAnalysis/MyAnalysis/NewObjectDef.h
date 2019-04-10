#ifndef NewObjectDef_h
#define NewObjectDef_h

#include "AsgTools/SgTEvent.h"
#include <AsgTools/AnaToolHandle.h>
#include "SUSYTools/SUSYObjDef_xAOD.h"
#include "xAODEgamma/ElectronContainer.h"
#include "xAODMuon/MuonContainer.h"
#include "xAODTau/TauJetContainer.h"
#include "xAODJet/JetContainer.h"
#include "xAODJet/JetAuxContainer.h"
#include "xAODMissingET/MissingETContainer.h"
#include "xAODMissingET/MissingETAuxContainer.h"
#include <PATInterfaces/CorrectionCode.h>
#include <xAODCore/ShallowAuxContainer.h>
#include <xAODCore/ShallowCopy.h>
#include <AsgTools/StatusCode.h>


class NewObjectDef
{

  public:

    /*asg::AnaToolHandle<ST::SUSYObjDef_xAOD> objTool;*/
    ST::SUSYObjDef_xAOD* objTool;

    NewObjectDef(asg::SgTEvent* event, ST::SUSYObjDef_xAOD* SUSYTool, xAOD::TStore* store, double mcChannel, double EventNumber, double mcWgt, double m_lumiScaled, std::string systematic);

    ~NewObjectDef(){};

    void GetObjects();

    double getMET(){return MET;};
    double getMETPhi(){return METphi;};
    double getMETsig(){return METsig;};

    double getMuonSF(){return muonSF;};
    double getMuonTriggerSF(){return muonTriggerSF;};
    double getElectronSF(){return electronSF;};
    double getElectronTriggerSF(){return electronTriggerSF;};
    double getDilepTriggerSF(){return dilepTriggerSF;};
    double getTauSF(){return 1;};
    double getTauTriggerSF(){return 1;};
    double getPhotonSF(){return 1;};
    double getBJetSF(){return bJetSF;};
    double getJVTSF(){return JVTSF;};
    double getLeptonSF(){return 1;};
    int getPrimVertex(){return nVertex;};
    bool elTriggerMatch(){return passElectronTriggerMatch;};
    bool muTriggerMatch(){return passMuonTriggerMatch;};
    bool taTriggerMatch(){return passTauTriggerMatch;};
    bool phTriggerMatch(){return passPhotonTriggerMatch;};


    TVector2* getMETvector(){return METvector;};
    xAOD::JetContainer* getBadJets(){return badJets;};
    xAOD::JetContainer* getGoodJets(){return goodJets;};
    xAOD::JetContainer* getGoodJets_beforeOR(){return goodJetsBeforeOR;};
    xAOD::JetContainer* getNonBJets(){return nonBJets;};
    xAOD::JetContainer* getBJets(){return BJets;};
    xAOD::ElectronContainer* getBaselineElectrons(){return baselineElectrons;};
    xAOD::ElectronContainer* getGoodElectrons(){return goodElectrons;};
    xAOD::MuonContainer* getBaselineMuons(){return baselineMuons;};
    xAOD::MuonContainer* getGoodMuons(){return goodMuons;};
    xAOD::MuonContainer* getBadMuons(){return badMuons;};
    xAOD::MuonContainer* getCosmicMuons(){return cosmicMuons;};
    xAOD::TauJetContainer* getBaselineTaus(){return baselineTaus;};
    xAOD::TauJetContainer* getGoodTaus(){return goodTaus;};
    xAOD::PhotonContainer* getBaselinePhotons(){return baselinePhotons;};
    xAOD::PhotonContainer* getGoodPhotons(){return goodPhotons;};

    asg::SgTEvent* currentEvent;
    xAOD::TStore* eventStore;
    std::string systematic;
    double mcID;
    double eventNumber;
    double mcEventWeight;
    double lumiScaled;

  private:

    xAOD::JetContainer* badJets;
    xAOD::MuonContainer* cosmicMuons;
    xAOD::MuonContainer* badMuons;
    xAOD::ElectronContainer* baselineElectrons;
    xAOD::TauJetContainer* baselineTaus;
    xAOD::MuonContainer* baselineMuons;
    xAOD::PhotonContainer* baselinePhotons;
    xAOD::JetContainer* goodJets;
    xAOD::JetContainer* goodJetsBeforeOR;
    xAOD::ElectronContainer* goodElectrons;
    xAOD::TauJetContainer* goodTaus;
    xAOD::MuonContainer* goodMuons;
    xAOD::PhotonContainer* goodPhotons;
    xAOD::JetContainer* BJets;
    xAOD::JetContainer* nonBJets;

    double MET;
    double METphi;
    double METsig;

    TVector2* METvector;
    double muonSF;
    double electronSF;
    double electronTriggerSF;
    double tauSF;
    double tauTriggerSF;
    double photonSF;
    double bJetSF;
    double JVTSF;
    double muonTriggerSF;
    double dilepTriggerSF;
    
    
    int nVertex = 0;
    bool passElectronTriggerMatch = false;
    bool passMuonTriggerMatch = false;
    bool passTauTriggerMatch = false;
    bool passPhotonTriggerMatch = false;



  private:

};
#endif
