#include "MyAnalysis/NewObjectDef.h"

NewObjectDef::NewObjectDef(asg::SgTEvent* event, asg::AnaToolHandle<ST::SUSYObjDef_xAOD>& SUSYTool, xAOD::TStore* store, double mcChannel, double EventNumber, double mcWgt, double m_lumiScaled, std::string syst) {

  objTool = SUSYTool;
  eventStore = store;
  systematic = syst;
  mcID = mcChannel;
  eventNumber = EventNumber;
  mcEventWeight = mcWgt;
  lumiScaled = m_lumiScaled;
  currentEvent = event;

  baselineElectrons = new xAOD::ElectronContainer(SG::VIEW_ELEMENTS);
  baselineMuons = new xAOD::MuonContainer(SG::VIEW_ELEMENTS);
  baselineTaus = new xAOD::TauJetContainer(SG::VIEW_ELEMENTS);
  baselinePhotons = new xAOD::PhotonContainer(SG::VIEW_ELEMENTS);

  cosmicMuons = new xAOD::MuonContainer(SG::VIEW_ELEMENTS);
  badJets = new xAOD::JetContainer(SG::VIEW_ELEMENTS);
  badMuons = new xAOD::MuonContainer(SG::VIEW_ELEMENTS);

  goodElectrons = new xAOD::ElectronContainer(SG::VIEW_ELEMENTS);
  goodMuons = new xAOD::MuonContainer(SG::VIEW_ELEMENTS);
  goodTaus = new xAOD::TauJetContainer(SG::VIEW_ELEMENTS);
  goodPhotons = new xAOD::PhotonContainer(SG::VIEW_ELEMENTS);
  goodJets = new xAOD::JetContainer(SG::VIEW_ELEMENTS);
  goodJetsBeforeOR = new xAOD::JetContainer(SG::VIEW_ELEMENTS);
  BJets = new xAOD::JetContainer(SG::VIEW_ELEMENTS);
  nonBJets = new xAOD::JetContainer(SG::VIEW_ELEMENTS);

  store->record(baselineElectrons,"baselineElectrons_"+systematic);
  store->record(baselineMuons,"baselineMuons_"+systematic);
  store->record(baselineTaus,"baselineTaus_"+systematic);
  store->record(baselinePhotons,"baselinePhotons_"+systematic);
  event->record(goodElectrons,"goodElectrons"+systematic);
  event->record(goodTaus,"goodTaus"+systematic);
  event->record(goodMuons,"goodMuons"+systematic);
  event->record(goodPhotons,"goodPhotons"+systematic);
  event->record(BJets,"BJets"+systematic);
  event->record(nonBJets,"nonBJets"+systematic);

  GetObjects();

}

void NewObjectDef::GetObjects() {

  // Setup object containers
  xAOD::MuonContainer* muons_nominal = nullptr;
  xAOD::ShallowAuxContainer* muons_nominal_aux = nullptr;
  xAOD::ElectronContainer* electrons_nominal = nullptr;
  xAOD::ShallowAuxContainer* electrons_nominal_aux = nullptr;
  xAOD::TauJetContainer* taus_nominal = nullptr;
  xAOD::ShallowAuxContainer* taus_nominal_aux = nullptr;
  xAOD::JetContainer* jets_nominal = nullptr;
  xAOD::ShallowAuxContainer* jets_nominal_aux = nullptr;
  xAOD::PhotonContainer* photons_nominal = nullptr;
  xAOD::ShallowAuxContainer* photons_nominal_aux = nullptr;
  // Setup MET containers
  xAOD::MissingETContainer* met_nominal = new xAOD::MissingETContainer;
	xAOD::MissingETAuxContainer* met_nominal_aux = new xAOD::MissingETAuxContainer;
  met_nominal->setStore(met_nominal_aux);
  // Retrieve objects with SUSYTools
  objTool->GetMuons(muons_nominal, muons_nominal_aux);
  eventStore->record(muons_nominal, "muons_"+systematic);
  eventStore->record(muons_nominal_aux, "muons_aux_");
  objTool->GetElectrons(electrons_nominal, electrons_nominal_aux);
  eventStore->record(electrons_nominal, "electrons_"+systematic);
  eventStore->record(electrons_nominal_aux, "electrons_aux_");
  objTool->GetTaus(taus_nominal, taus_nominal_aux);
  objTool->GetJets(jets_nominal, jets_nominal_aux);
  objTool->GetPhotons(photons_nominal, photons_nominal_aux);
  objTool->OverlapRemoval(electrons_nominal, muons_nominal, jets_nominal, photons_nominal, taus_nominal);
  // Get pointers to filled containers
  xAOD::ElectronContainer* electrons(electrons_nominal);
  xAOD::PhotonContainer* photons(photons_nominal);
  xAOD::MuonContainer* muons(muons_nominal);
  xAOD::JetContainer* jets(jets_nominal);
  xAOD::TauJetContainer* taus(taus_nominal);
  // Get MET
  objTool->GetMET(*met_nominal, jets_nominal, electrons_nominal, muons_nominal, NULL, taus_nominal, true);
  xAOD::MissingETContainer::const_iterator met_it = met_nominal->find("Final");
  if (met_it == met_nominal->end())
  {
    std::cout << "No RefFinal inside MET container" << std::endl;
  }
  METvector = new TVector2 ((*met_it)->mpy(),(*met_it)->mpy());
  MET = (*met_it)->met();
  METphi = (*met_it)->phi();
  objTool->GetMETSig(*met_nominal, METsig, false, false);

  // Fill electrons
  for (auto el_itr: *electrons) {
    if (el_itr->auxdata<char>("passOR")) {
      if (el_itr->auxdata<char>("baseline")) baselineElectrons->push_back(el_itr);
      if (el_itr->auxdata<char>("signal")) goodElectrons->push_back(el_itr);
    }
  }

  electronSF = 1;
  electronTriggerSF = 1;
  if (objTool->isData() == 0 && goodElectrons->size() == 1) {
    electronSF = objTool->GetTotalElectronSF(*electrons,true,true,false,true,"", false);
    electronTriggerSF = objTool->GetTotalElectronSF(*electrons,false,false,true,false,"singleLepton", false);
  }

  // Fill muons
  for (const auto& mu_itr: *muons) {
    if (mu_itr->auxdata<char>("passOR")) {
      if (mu_itr->auxdata<char>("baseline") && !(mu_itr)->auxdata<char>("cosmic")) baselineMuons->push_back(mu_itr);
      if (mu_itr->auxdata<char>("baseline") && mu_itr->auxdata<char>("cosmic")) cosmicMuons->push_back(mu_itr);
      if (mu_itr->auxdata<char>("signal")) goodMuons->push_back(mu_itr);
    }
    else {
      if (mu_itr->auxdata<char>("baseline") && mu_itr->auxdata<char>("bad")) badMuons->push_back(mu_itr);
    }
  }

  muonSF = 1;
  muonTriggerSF = 1;
  if (objTool->isData() == 0 && goodMuons->size() == 1) {
    int year = objTool->treatAsYear();
    if (year == 2015) {
      muonTriggerSF = objTool->GetTotalMuonSF(*muons,false, false, "HLT_mu20_iloose_L1MU15_OR_HLT_mu50");
    }
    else {
      muonTriggerSF = objTool->GetTotalMuonSF(*muons,false,false, "HLT_mu26_ivarmedium_OR_HLT_mu50");
    }
    muonSF = objTool->GetTotalMuonSF(*muons,true,true,"");
  }

  // Fill taus
  for (const auto& tau_itr: *taus) {
    if (tau_itr->auxdata<char>("passOR")) {
      if (tau_itr->auxdata<char>("baseline")) baselineTaus->push_back(tau_itr);
      if (tau_itr->auxdata<char>("signal")) goodTaus->push_back(tau_itr);
    }
  }
  // Fill photons
  for (const auto& ph_itr: *photons) {
    if (ph_itr->auxdata<char>("passOR")) {
      if (ph_itr->auxdata<char>("baseline")) baselinePhotons->push_back(ph_itr);
      if (ph_itr->auxdata<char>("signal")) goodPhotons->push_back(ph_itr);
    }
  }
  //Fill jets
  bJetSF = 1;
  JVTSF = 1;
  for (const auto& jet_itr: *jets) {
    if (jet_itr->auxdata<char>("baseline")) goodJetsBeforeOR->push_back(jet_itr);
    if (jet_itr->auxdata<char>("passOR")) {
      if (jet_itr->auxdata<char>("bad")) badJets->push_back(jet_itr);
      if (jet_itr->auxdata<char>("signal") && jet_itr->auxdata<char>("baseline")) {
        goodJets->push_back(jet_itr);
        if (jet_itr->auxdata<char>("bjet")) BJets->push_back(jet_itr);
        if (!(jet_itr)->auxdata<char>("bjet")) nonBJets->push_back(jet_itr);
        if (!objTool->isData()) bJetSF = objTool->BtagSF(goodJets);
        if (!objTool->isData()) JVTSF = objTool->JVT_SF(goodJets);
      }
    }
  }
  //Get nVertex
  const xAOD::VertexContainer* primVertex = 0;
  currentEvent->retrieve( primVertex, "PrimaryVertices" );
  nVertex = 0;

  for ( const auto& vx : *primVertex) {
    if (vx->vertexType() == xAOD::VxType::PriVtx) {
      nVertex++ ;
    }
  }

}
