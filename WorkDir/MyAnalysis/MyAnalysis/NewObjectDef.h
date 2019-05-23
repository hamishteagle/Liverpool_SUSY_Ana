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

    NewObjectDef(asg::SgTEvent* event, ST::SUSYObjDef_xAOD* SUSYTool, xAOD::TStore* store, double mcChannel, double EventNumber, double mcWgt, double m_lumiScaled, std::string systematic, bool doTruthJets, bool m_SUSY5, bool m_SUSY7);

    ~NewObjectDef(){
    };

    void GetObjects();
    void GetBaselineObjects(bool m_SUSY5, bool m_SUSY7);
    void GetTruthJets();

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
    int getNBadMuons(){return nBadMuons;};
    int getNCosmicMuons(){return nCosmicMuons;};
    int getNBadJets(){return nBadJets;};
    bool elTriggerMatch(){return passElectronTriggerMatch;};
    bool muTriggerMatch(){return passMuonTriggerMatch;};
    bool taTriggerMatch(){return passTauTriggerMatch;};
    bool phTriggerMatch(){return passPhotonTriggerMatch;};

    //Things not in the event store
    TVector2* getMETvector(){return METvector.get();};
    xAOD::JetContainer* getBadJets(){return badJets.get();};
    xAOD::JetContainer* getGoodJets_beforeOR(){return goodJetsBeforeOR.get();};
    xAOD::MuonContainer* getCosmicMuons(){return cosmicMuons.get();};
    xAOD::MuonContainer* getBadMuons(){return badMuons.get();};

    xAOD::JetContainer* getGoodJets(){return goodJets.get();};
    xAOD::JetContainer* getNonBJets(){return nonBJets.get();};
    xAOD::JetContainer* getBJets(){return BJets.get();};
    xAOD::ElectronContainer* getBaselineElectrons(){return baselineElectrons.get();};
    xAOD::ElectronContainer* getGoodElectrons(){return goodElectrons.get();};
    xAOD::MuonContainer* getBaselineMuons(){return baselineMuons.get();};
    xAOD::MuonContainer* getGoodMuons(){return goodMuons.get();};
    xAOD::TauJetContainer* getBaselineTaus(){return baselineTaus.get();};
    xAOD::TauJetContainer* getGoodTaus(){return goodTaus.get();};
    xAOD::PhotonContainer* getBaselinePhotons(){return baselinePhotons.get();};
    xAOD::PhotonContainer* getGoodPhotons(){return goodPhotons.get();};

    xAOD::JetContainer* getTruthJets(){return goodTruthJets;};
    
    
    asg::SgTEvent* currentEvent;
    xAOD::TStore* eventStore;
    std::string systematic;
    double mcID;
    double eventNumber;
    double mcEventWeight;
    double lumiScaled;



    std::unique_ptr<xAOD::JetContainer>      preOR_baselineJets      = nullptr;
    std::unique_ptr<xAOD::ElectronContainer> preOR_baselineElectrons = nullptr;
    std::unique_ptr<xAOD::MuonContainer>     preOR_baselineMuons     = nullptr;
    std::unique_ptr<xAOD::TauJetContainer>   preOR_baselineTaus      = nullptr;
    std::unique_ptr<xAOD::PhotonContainer>   preOR_baselinePhotons   = nullptr;

    std::unique_ptr<xAOD::JetContainer>  badJets           = nullptr;
    std::unique_ptr<xAOD::MuonContainer> cosmicMuons       = nullptr;
    std::unique_ptr<xAOD::MuonContainer> badMuons          = nullptr;
    std::unique_ptr<xAOD::JetContainer>  goodJetsBeforeOR  = nullptr;
    std::unique_ptr<TVector2>            METvector         = nullptr;

    std::unique_ptr<xAOD::ElectronContainer> baselineElectrons = nullptr;
    std::unique_ptr<xAOD::TauJetContainer> baselineTaus = nullptr;
    std::unique_ptr<xAOD::MuonContainer> baselineMuons = nullptr;
    std::unique_ptr<xAOD::PhotonContainer> baselinePhotons = nullptr;
    
    std::unique_ptr<xAOD::JetContainer> goodJets = nullptr;
    std::unique_ptr<xAOD::ElectronContainer> goodElectrons = nullptr;
    std::unique_ptr<xAOD::TauJetContainer> goodTaus = nullptr;
    std::unique_ptr<xAOD::MuonContainer> goodMuons = nullptr;
    std::unique_ptr<xAOD::PhotonContainer> goodPhotons = nullptr;
    std::unique_ptr<xAOD::JetContainer> BJets = nullptr;
    std::unique_ptr<xAOD::JetContainer> nonBJets = nullptr;

    
    xAOD::JetContainer* goodTruthJets = nullptr;
    
  private:
    double MET;
    double METphi;
    double METsig;


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
    int nBadMuons = 0;
    int nCosmicMuons = 0;
    int nBadJets = 0;
    bool passElectronTriggerMatch = false;
    bool passMuonTriggerMatch = false;
    bool passTauTriggerMatch = false;
    bool passPhotonTriggerMatch = false;


};
#endif
