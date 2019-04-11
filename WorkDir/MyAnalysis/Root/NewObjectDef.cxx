#include "MyAnalysis/NewObjectDef.h"

NewObjectDef::NewObjectDef(asg::SgTEvent* event, ST::SUSYObjDef_xAOD* SUSYTool, xAOD::TStore* store, double mcChannel, double EventNumber, double mcWgt, double m_lumiScaled, std::string syst) {

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

  eventStore->record(baselineElectrons,"baselineElectrons_"+systematic);
  eventStore->record(baselineMuons,"baselineMuons_"+systematic);
  eventStore->record(baselineTaus,"baselineTaus_"+systematic);
  eventStore->record(baselinePhotons,"baselinePhotons_"+systematic);
  eventStore->record(goodElectrons,"goodElectrons"+systematic);
  eventStore->record(goodTaus,"goodTaus"+systematic);
  eventStore->record(goodMuons,"goodMuons"+systematic);
  eventStore->record(goodPhotons,"goodPhotons"+systematic);
  eventStore->record(BJets,"BJets"+systematic);
  eventStore->record(nonBJets,"nonBJets"+systematic);

  GetObjects();

}

bool pT_Sorter( const xAOD::Jet* j1, const xAOD::Jet* j2 ) {
  double pT1 = 0;
  double pT2 = 0;
  // need to change this to the new discriminant 
  pT1=j1->pt();
  pT2=j2->pt();
  return ( pT1 > pT2 );
}



void NewObjectDef::GetObjects() {

  // Setup object containers
  xAOD::MuonContainer* muons_nominal(0);
  xAOD::ShallowAuxContainer* muons_nominal_aux(0);
  xAOD::ElectronContainer* electrons_nominal(0);
  xAOD::ShallowAuxContainer* electrons_nominal_aux(0);
  xAOD::TauJetContainer* taus_nominal(0);
  xAOD::ShallowAuxContainer* taus_nominal_aux(0);
  xAOD::JetContainer* jets_nominal(0);
  xAOD::ShallowAuxContainer* jets_nominal_aux(0);
  xAOD::PhotonContainer* photons_nominal(0);
  xAOD::ShallowAuxContainer* photons_nominal_aux(0);
  // Setup MET containers
  xAOD::MissingETContainer* met_nominal = new xAOD::MissingETContainer;
  xAOD::MissingETAuxContainer* met_nominal_aux = new xAOD::MissingETAuxContainer;
  met_nominal->setStore(met_nominal_aux);
  met_nominal->reserve(10);

  // Retrieve objects with SUSYTools
  objTool->GetMuons(muons_nominal, muons_nominal_aux);
  objTool->GetElectrons(electrons_nominal, electrons_nominal_aux);
  objTool->GetJets(jets_nominal, jets_nominal_aux);
  objTool->GetTaus(taus_nominal, taus_nominal_aux);
  objTool->GetPhotons(photons_nominal, photons_nominal_aux);
  objTool->OverlapRemoval(electrons_nominal, muons_nominal, jets_nominal, photons_nominal, taus_nominal);

  eventStore->record(muons_nominal, "muons_"+systematic);
  eventStore->record(muons_nominal_aux, "muons_aux_"+systematic);
  eventStore->record(electrons_nominal, "electrons_"+systematic);
  eventStore->record(electrons_nominal_aux, "electrons_aux_"+systematic);
  eventStore->record(taus_nominal, "taus_"+systematic);
  eventStore->record(taus_nominal_aux, "taus_aux_"+systematic);
  eventStore->record(jets_nominal, "jets_"+systematic);
  eventStore->record(jets_nominal_aux, "jets_aux_"+systematic);
  eventStore->record(photons_nominal, "photons_"+systematic);
  eventStore->record(photons_nominal_aux, "photons_aux_"+systematic);
  // Get pointers to filled containers
  xAOD::ElectronContainer* electrons(electrons_nominal);
  xAOD::PhotonContainer* photons(photons_nominal);
  xAOD::MuonContainer* muons(muons_nominal);
  xAOD::JetContainer* jets(jets_nominal);
  xAOD::TauJetContainer* taus(taus_nominal);
  // Get MET
  //Only jets electrons muons, NoPhotons, NoTaus
  objTool->GetMET(*met_nominal, jets_nominal, electrons_nominal, muons_nominal, NULL, NULL, true);
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
  if (objTool->isData() == 0) {
    electronSF = objTool->GetTotalElectronSF(*electrons,true,true,false,true,"", false);
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
  if (objTool->isData() == 0 ) {
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
    goodJets->sort(pT_Sorter);
    BJets->sort(pT_Sorter);
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

  //Lepton trigger SFs
  //If only one 1-lepton trigger has fired, take this scale factor, if both e and mu fire, then dilep should fire and we take this as the scale factor.
  //cout events to check if the muon trigger and electron trigger fire without the mu_e trigger firing (should never happen)
  electronTriggerSF = 1;
  muonTriggerSF = 1;
  dilepTriggerSF = 1;

  if (objTool->isData() == 0) {
    if (goodElectrons->size() == 1) {
      electronTriggerSF = objTool->GetTotalElectronSF(*electrons,false,false,true,false,"singleLepton", false);
    }
    if (goodMuons->size() == 1) {
      int year = objTool->treatAsYear();
      if (year == 2015) {
        muonTriggerSF = objTool->GetTotalMuonSF(*muons,false, false, "HLT_mu20_iloose_L1MU15_OR_HLT_mu50");
      }
      else {
        muonTriggerSF = objTool->GetTotalMuonSF(*muons,false,false, "HLT_mu26_ivarmedium_OR_HLT_mu50");
      }
    }
    if ((goodElectrons->size() + goodMuons->size()) >= 2) {
      dilepTriggerSF = objTool->GetTriggerGlobalEfficiencySF(*electrons, *muons, "diLepton");
      if (goodElectrons->size() == 1) electronTriggerSF = objTool->GetTotalElectronSF(*electrons,false,false,true,false,"singleLepton", false);
      if (goodMuons->size() == 1) {
        int year = objTool->treatAsYear();
        if (year == 2015) {
          muonTriggerSF = objTool->GetTotalMuonSF(*muons,false, false, "HLT_mu20_iloose_L1MU15_OR_HLT_mu50");
        }
        else {
          muonTriggerSF = objTool->GetTotalMuonSF(*muons,false,false, "HLT_mu26_ivarmedium_OR_HLT_mu50");
        }
      }
    }
  }

  delete met_nominal;
  delete met_nominal_aux;

  return;

}

