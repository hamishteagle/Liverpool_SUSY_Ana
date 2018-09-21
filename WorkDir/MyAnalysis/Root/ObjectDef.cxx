#include "MyAnalysis/ObjectDef.h"
#include "MyAnalysis/IObjectDef.h"
#include <iterator> 

bool ptSorter( const xAOD::IParticle* j1, const xAOD::IParticle* j2 ) {
  return ( j1->pt() > j2->pt() );
}

//ObjectDef with FatJets (Crashes on PseudoJetGetter when running on systematics)
ObjectDef::ObjectDef(xAOD::TEvent* event, ST::SUSYObjDef_xAOD* SUSYTool, xAOD::TStore* store, double mcChannelNumber, double eventN, double mcEventWgt, double m_lumiScaled, std::string systName, bool doPhotons, asg::AnaToolHandle<IMETSignificance> Tool_METSig):IObjectDef(event, SUSYTool, store, mcChannelNumber, eventN, mcEventWgt, m_lumiScaled, systName, doPhotons) //JetToolRunner* Tool_FatJets_kt12, JetToolRunner* Tool_FatJets_kt8, 
{
  
  METSig_tool = Tool_METSig; 
  
  baselineElectronsBeforeOR = new xAOD::ElectronContainer(SG::VIEW_ELEMENTS);
  signalElectronsBeforeOR = new xAOD::ElectronContainer(SG::VIEW_ELEMENTS);
  baselineTausBeforeOR = new xAOD::TauJetContainer(SG::VIEW_ELEMENTS);
  signalTausBeforeOR = new xAOD::TauJetContainer(SG::VIEW_ELEMENTS);
  goodJetsBeforeOR = new xAOD::JetContainer(SG::VIEW_ELEMENTS);
  baselineMuonsBeforeOR = new xAOD::MuonContainer(SG::VIEW_ELEMENTS);
  signalMuonsBeforeOR = new xAOD::MuonContainer(SG::VIEW_ELEMENTS);
  baselinePhotonsBeforeOR = new xAOD::PhotonContainer(SG::VIEW_ELEMENTS);
  signalPhotonsBeforeOR = new xAOD::PhotonContainer(SG::VIEW_ELEMENTS);
  badJets = new xAOD::JetContainer(SG::VIEW_ELEMENTS);
  cosmicMuons = new xAOD::MuonContainer(SG::VIEW_ELEMENTS);
  badMuons = new xAOD::MuonContainer(SG::VIEW_ELEMENTS);
  baselineElectrons = new xAOD::ElectronContainer(SG::VIEW_ELEMENTS);
  baselineTaus = new xAOD::TauJetContainer(SG::VIEW_ELEMENTS);
  baselineMuons = new xAOD::MuonContainer(SG::VIEW_ELEMENTS);
  baselinePhotons = new xAOD::PhotonContainer(SG::VIEW_ELEMENTS);
  goodJets = new xAOD::JetContainer(SG::VIEW_ELEMENTS);
  FatJets_kt8 = new xAOD::JetContainer(SG::VIEW_ELEMENTS);
  FatJets_kt12 = new xAOD::JetContainer(SG::VIEW_ELEMENTS);
  goodAntiKt4TruthJets = new xAOD::JetContainer(SG::VIEW_ELEMENTS);
  goodAntiKt3TruthJets = new xAOD::JetContainer(SG::VIEW_ELEMENTS);
  goodElectrons = new xAOD::ElectronContainer(SG::VIEW_ELEMENTS);
  goodTaus = new xAOD::TauJetContainer(SG::VIEW_ELEMENTS);
  goodMuons = new xAOD::MuonContainer(SG::VIEW_ELEMENTS);
  goodPhotons = new xAOD::PhotonContainer(SG::VIEW_ELEMENTS);
  BJets = new xAOD::JetContainer(SG::VIEW_ELEMENTS);
  nonBJets = new xAOD::JetContainer(SG::VIEW_ELEMENTS);
  METmuons  = new xAOD::MuonContainer(SG::VIEW_ELEMENTS);
  
  eventStore->record(baselineElectronsBeforeOR,"baselineElectronsBeforeOR"+systematic);
  eventStore->record(signalElectronsBeforeOR,"signalElectronsBeforeOR"+systematic);
  eventStore->record(baselineTausBeforeOR,"baselineTausBeforeOR"+systematic);
  eventStore->record(signalTausBeforeOR,"signalTausBeforeOR"+systematic);
  eventStore->record(baselinePhotonsBeforeOR,"baselinePhotonsBeforeOR"+systematic);
  eventStore->record(signalPhotonsBeforeOR,"signalPhotonsBeforeOR"+systematic);
  eventStore->record(goodJetsBeforeOR,"goodJetsBeforeOR"+systematic);
  eventStore->record(baselineMuonsBeforeOR,"baselineMuonsBeforeOR"+systematic);
  eventStore->record(signalMuonsBeforeOR,"signalMuonsBeforeOR"+systematic);
  eventStore->record(badJets,"badJets"+systematic);
  eventStore->record(cosmicMuons,"cosmicMuons"+systematic);
  eventStore->record(badMuons,"badMuons"+systematic);
  eventStore->record(baselineElectrons,"baselineElectrons"+systematic);
  eventStore->record(baselineTaus,"baselineTaus"+systematic);
  eventStore->record(baselineMuons,"baselineMuons"+systematic);
  eventStore->record(baselinePhotons,"baselinePhotons"+systematic);
  eventStore->record(goodJets,"goodJets"+systematic);
  eventStore->record(FatJets_kt8,"fatJets_kt8"+systematic);
  eventStore->record(FatJets_kt12,"fatJets_kt12"+systematic);
  eventStore->record(goodAntiKt4TruthJets,"goodAntiKt4TruthJets"+systematic);
  eventStore->record(goodAntiKt3TruthJets,"goodAntiKt3TruthJets"+systematic);
  eventStore->record(goodElectrons,"goodElectrons"+systematic);
  eventStore->record(goodTaus,"goodTaus"+systematic);
  eventStore->record(goodMuons,"goodMuons"+systematic); 
  eventStore->record(goodPhotons,"goodPhotons"+systematic); 
  eventStore->record(BJets,"BJets"+systematic);
  eventStore->record(nonBJets,"nonBJets"+systematic);
  eventStore->record(METmuons,"Something"+systematic);  

  DSID = mcChannelNumber;

  //  fatjet_kt12_tool = new JetToolRunner("m_jetRecTool_kt12_"+systematic);
  //fatjet_kt8_tool = new JetToolRunner("m_jetRecTool_kt8_"+systematic);

  //  this->SetUpFatJetTools(fatjet_kt12_tool, 1.2, "goodJets"+systematic, "MyFatJetsKt12"+systematic);
  //  this->SetUpFatJetTools(fatjet_kt8_tool, 0.8, "goodJets"+systematic, "MyFatJetsKt8"+systematic);


  this->SetPrimVertex();
  this->FillPreORMuons();
  this->FillPreORElectrons();
  this->FillPreORTaus();
  this->FillPreORJets();
  this->FillPreORPhotons();
  
  //this->FillOldMET(); This was the MET calculation without adding the photon to it
  //this->OldOverlapRemoval(); //This was the OR calculation without adding photons
  this->OverlapRemoval(); //This now includes photons and taus
  
  this->FillMET();
    
  this->FillBaselineElectrons();
  this->FillBaselineTaus();
  this->FillBaselineMuons();
  this->FillGoodJets();
  //this->FillFatJets_kt8();
  //this->FillFatJets_kt12();
  //this->FillBaselinePhotons();
    
}


void ObjectDef::FillPreORMuons(){


  xAOD::MuonContainer* muons_nominal(0);
  xAOD::ShallowAuxContainer* muons_nominal_aux(0);
  
  objTool->GetMuons(muons_nominal, muons_nominal_aux);
  
  eventStore->record(muons_nominal, "CalibratedMuons"+systematic);
  eventStore->record(muons_nominal_aux, "CalibratedMuons_Aux"+systematic);
  

  xAOD::MuonContainer::iterator mu_itr = (muons_nominal)->begin();
  xAOD::MuonContainer::iterator mu_end  = (muons_nominal)->end();
  
  for( ; mu_itr != mu_end; ++mu_itr ) {
    if ((**mu_itr).muonType()==(**mu_itr).Combined || (**mu_itr).muonType()==(**mu_itr).MuonStandAlone )
      METmuons->push_back(*mu_itr);
    
    
    if ( (*mu_itr)->auxdata< char >("baseline") && !(*mu_itr)->auxdata< char >("bad") ){
      baselineMuonsBeforeOR->push_back (*mu_itr);
      
      if ( (*mu_itr)->auxdata< char >("signal") )
	signalMuonsBeforeOR->push_back (*mu_itr);
    }

    if (  (*mu_itr)->auxdata< char >("baseline") && ( (*mu_itr)->auxdata< char >("bad"))) 
      badMuons->push_back( *mu_itr);
    
  }

  baselineMuonsBeforeOR->sort(ptSorter);
  signalMuonsBeforeOR->sort(ptSorter);
  badMuons->sort(ptSorter);

  return;

}



void ObjectDef::FillPreORElectrons(){

  //std::cout << "In Pre Ele" << std::endl;


  xAOD::ElectronContainer* electrons_nominal(0);
  xAOD::ShallowAuxContainer* electrons_nominal_aux(0);
  
  objTool->GetElectrons(electrons_nominal, electrons_nominal_aux);

  eventStore->record(electrons_nominal, "CalibratedElectronCollection"+systematic);
  eventStore->record(electrons_nominal_aux, "CalibratedElectronCollection_Aux"+systematic);

  
  xAOD::ElectronContainer::iterator el_itr = (electrons_nominal)->begin();
  xAOD::ElectronContainer::iterator el_end = (electrons_nominal)->end();

  for( ; el_itr != el_end; ++el_itr ) {

    xAOD::Electron el = **el_itr;
    
    
    if ( (*el_itr)->auxdata< char >("baseline")){
      baselineElectronsBeforeOR->push_back (*el_itr);
      
      if (  (*el_itr)->auxdata< char >("signal") )
	signalElectronsBeforeOR->push_back (*el_itr);
    }
  }
  
  baselineElectronsBeforeOR->sort(ptSorter);
  signalElectronsBeforeOR->sort(ptSorter);
  
 
}


void ObjectDef::FillPreORTaus(){

  //std::cout << "In Pre Tau" << std::endl;


  xAOD::TauJetContainer* taus_nominal(0);
  xAOD::ShallowAuxContainer* taus_nominal_aux(0);
  
  objTool->GetTaus(taus_nominal, taus_nominal_aux);

  eventStore->record(taus_nominal, "CalibratedTauCollection"+systematic);
  eventStore->record(taus_nominal_aux, "CalibratedTauCollection_Aux"+systematic);

  
  xAOD::TauJetContainer::iterator ta_itr = (taus_nominal)->begin();
  xAOD::TauJetContainer::iterator ta_end = (taus_nominal)->end();


  for( ; ta_itr != ta_end; ++ta_itr ) {

    xAOD::TauJet ta = **ta_itr;
    
    
    if ( (*ta_itr)->auxdata< char >("baseline")){
      baselineTausBeforeOR->push_back (*ta_itr);
      
      if (  (*ta_itr)->auxdata< char >("signal") )
	signalTausBeforeOR->push_back (*ta_itr);
    }

  }
  
  baselineTausBeforeOR->sort(ptSorter);
  signalTausBeforeOR->sort(ptSorter);
    
}



void ObjectDef::FillPreORPhotons(){

  //std::cout << "In Pre Photons" << std::endl;


  xAOD::PhotonContainer* photons_nominal(0);
  xAOD::ShallowAuxContainer* photons_nominal_aux(0);
  
  objTool->GetPhotons(photons_nominal, photons_nominal_aux);

  eventStore->record(photons_nominal, "CalibratedPhotonCollection"+systematic);
  eventStore->record(photons_nominal_aux, "CalibratedPhotonCollection_Aux"+systematic);


  
  xAOD::PhotonContainer::iterator ph_itr = (photons_nominal)->begin();
  xAOD::PhotonContainer::iterator ph_end = (photons_nominal)->end();
  
  for( ; ph_itr != ph_end; ++ph_itr ) {

    xAOD::Photon ph = **ph_itr;
    
    
    if ( (*ph_itr)->auxdata< char >("baseline")){
      baselinePhotonsBeforeOR->push_back (*ph_itr);
      
      if (  (*ph_itr)->auxdata< char >("signal") )
	signalPhotonsBeforeOR->push_back (*ph_itr);
    }
  }
  
  baselinePhotonsBeforeOR->sort(ptSorter);
  signalPhotonsBeforeOR->sort(ptSorter);

  
}


void ObjectDef::FillPreORJets(){

  //std::cout << "In Pre-Jets" << std::endl;

  xAOD::JetContainer* jets_nominal(0);
  xAOD::ShallowAuxContainer* jets_nominal_aux(0);

  objTool->GetJets(jets_nominal,jets_nominal_aux);

  eventStore->record(jets_nominal, "CalibratedAntiKt4EMTopoJets"+systematic);
  eventStore->record(jets_nominal_aux, "CalibratedAntiKt4EMTopoJets_Aux"+systematic);





  xAOD::JetContainer::iterator jet_itr = (jets_nominal)->begin();
  xAOD::JetContainer::iterator jet_end = (jets_nominal)->end();
  for( ; jet_itr != jet_end; ++jet_itr ) {
    
    typedef ElementLink< xAOD::IParticleContainer > Link_t;
    static const char* linkName = "originalObjectLink";
    const xAOD::IParticleContainer* cont =
      dynamic_cast< const xAOD::IParticleContainer* >( (*jet_itr)->container() );
    if( ! cont ) {
      std::cout << 
	"Input object not part of a container, 'originalObjectLink' ElementLink not established" << std::endl;
    }
    else{
      const Link_t link( *jets_nominal, (*jet_itr)->index() );
      Link_t& auxLink = (*jet_itr)->auxdata< Link_t >( linkName );
      auxLink = link;
      auxLink.toPersistent();
    }
      
    if ( (*jet_itr)->auxdata< char >("baseline") ){
      
      goodJetsBeforeOR->push_back(*jet_itr);
    }
    
  }
  goodJetsBeforeOR->sort(ptSorter);
  
}


void ObjectDef::FillOldMET(){


  xAOD::MissingETContainer met;
  xAOD::MissingETAuxContainer metAux;
  
  met.setStore(&metAux);

  

  xAOD::MissingETContainer::const_iterator met_it = met.find("Final");

  const xAOD::JetContainer* jets = 0;
  currentEvent->retrieve( jets, "AntiKt4EMTopoJets");

  xAOD::JetContainer* METjets = 0;
  
  eventStore->retrieve( METjets, "CalibratedAntiKt4EMTopoJets"+systematic );
  
  const xAOD::MuonContainer* muons = 0;
  currentEvent->retrieve( muons, "Muons");

  xAOD::MuonContainer* METmuonsAll = 0;
  eventStore->retrieve( METmuonsAll, "CalibratedMuons"+systematic );
  
  const xAOD::ElectronContainer* electrons = 0;
  currentEvent->retrieve( electrons, "Electrons");

  xAOD::ElectronContainer* METelectrons = 0;
  eventStore->retrieve( METelectrons, "CalibratedElectronCollection"+systematic );


 
  xAOD::setOriginalObjectLink(*jets,*METjets);
  xAOD::setOriginalObjectLink(*muons,*METmuonsAll);
  xAOD::setOriginalObjectLink(*electrons,*METelectrons);
  
  objTool->GetMET(met, METjets, METelectrons,METmuonsAll,NULL,NULL,true);
  
  met_it = met.find("Final");

  if (met_it == met.end())
    {
      std::cout << "No RefFinal inside MET container" << std::endl;
    }
  


  double mpx = (*met_it)->mpx();
  double mpy = (*met_it)->mpy();

  METvector = new TVector2 (mpx,mpy);
 
  MET = (*met_it)->met();
  METphi = (*met_it)->phi();


  
 
  return;

}

void ObjectDef::FillMET(){

  //std::cout << "In MET" << std::endl;


  xAOD::MissingETContainer met;
  xAOD::MissingETAuxContainer metAux;
  
  met.setStore(&metAux);


  xAOD::MissingETContainer::const_iterator met_it = met.find("Final");
 
 const xAOD::JetContainer* jets = 0;
 currentEvent->retrieve( jets, "AntiKt4EMTopoJets");

 xAOD::JetContainer* METjets = 0;
 
 eventStore->retrieve( METjets, "CalibratedAntiKt4EMTopoJets"+systematic );
 
 const xAOD::MuonContainer* muons = 0;
 currentEvent->retrieve( muons, "Muons");

 xAOD::MuonContainer* METmuonsAll = 0;
 eventStore->retrieve( METmuonsAll, "CalibratedMuons"+systematic );
 
const xAOD::ElectronContainer* electrons = 0;
 currentEvent->retrieve( electrons, "Electrons");

 xAOD::ElectronContainer* METelectrons = 0;
 eventStore->retrieve( METelectrons, "CalibratedElectronCollection"+systematic );

 const xAOD::PhotonContainer* photons = 0;
 currentEvent->retrieve( photons, "Photons");

  xAOD::PhotonContainer* METphotons = 0;
  eventStore->retrieve( METphotons, "CalibratedPhotonCollection"+systematic );

  
  xAOD::setOriginalObjectLink(*jets,*METjets);
  xAOD::setOriginalObjectLink(*muons,*METmuonsAll);
  xAOD::setOriginalObjectLink(*electrons,*METelectrons);
  xAOD::setOriginalObjectLink(*photons,*METphotons);


  
  objTool->GetMET(met, METjets, METelectrons,METmuonsAll, METphotons,NULL,true);
  
  met_it = met.find("Final");
  
  
  
  if (met_it == met.end())
    {
      std::cout << "No RefFinal inside MET container" << std::endl;
    }
  
  //std::cout <<  " MET_Final: " << (*(met.find("Final")))->met() << " MET_Ele: " << (*(met.find("RefEle")))->met() << " MET_Jet: " <<(*(met.find("RefJet")))->met() << " MET_Photon: " <<(*(met.find("RefGamma")))->met() << " MET_Muons: " <<(*(met.find("Muons")))->met() << std::endl;
  
  double mpx = (*met_it)->mpx();
  double mpy = (*met_it)->mpy();

  METvector = new TVector2 (mpx,mpy);
 
  MET = (*met_it)->met();
  METphi = (*met_it)->phi();

  METSig_tool->varianceMET(&met, "RefJet", "PVSoftTrk","Final");
  double m_metsigET = METSig_tool->GetMETOverSqrtSumET();
  double m_metsigHT = METSig_tool->GetMETOverSqrtHT();
  double m_metsig = METSig_tool->GetSignificance();
  
  metSignificances.push_back(m_metsigET);
  metSignificances.push_back(m_metsigHT);
  metSignificances.push_back(m_metsig);
  
  return;

}

void ObjectDef::OldOverlapRemoval(){

  objTool->OverlapRemoval(baselineElectronsBeforeOR, baselineMuonsBeforeOR, goodJetsBeforeOR, NULL); //baselineTausBeforeOR

}

void ObjectDef::OverlapRemoval(){

  objTool->OverlapRemoval(baselineElectronsBeforeOR, baselineMuonsBeforeOR, goodJetsBeforeOR, baselinePhotonsBeforeOR, baselineTausBeforeOR);

}



void ObjectDef::FillBaselineElectrons(){

  xAOD::ElectronContainer::iterator el_itr = baselineElectronsBeforeOR->begin();
  xAOD::ElectronContainer::iterator el_end = baselineElectronsBeforeOR->end();
  
  electronSF = 1;

  for( ; el_itr != el_end; ++el_itr ) {
    
    if  ( (*el_itr)->auxdata< char >("passOR") && ( (*el_itr)->auxdata< char >("baseline") ) )
      baselineElectrons->push_back( *el_itr);
    
    if ( ( (*el_itr)->auxdata< char >("passOR") ) && ( (*el_itr)->auxdata< char >("signal") ) && ( (*el_itr)->auxdata< char >("baseline") ) ) {
      goodElectrons->push_back( *el_itr);
    }
    
  }

  xAOD::ElectronContainer* TriggerPassElectrons  = new xAOD::ElectronContainer(SG::VIEW_ELEMENTS);
  eventStore->record(TriggerPassElectrons,"TriggerPassElectrons"+systematic);

  xAOD::ElectronContainer* NontriggerpassElectrons  = new xAOD::ElectronContainer(SG::VIEW_ELEMENTS);
  eventStore->record(NontriggerpassElectrons,"NontriggerpassElectrons"+systematic);


  baselineElectrons->sort(ptSorter);
  goodElectrons->sort(ptSorter);

  // loop over for Trig matched here
  int year = objTool->treatAsYear();
  
  electronSF = 1;
  electronTriggerSF = 1;
  el_itr = goodElectrons->begin();
  el_end = goodElectrons->end();
  passElectronTriggerMatch = false;

  bool leadingLepton = true;
  for (; el_itr != el_end; ++el_itr) {
    if (leadingLepton){
      if (!objTool->isData())
	{
	  electronSF = objTool->GetTotalElectronSF(*goodElectrons,true,true,false,true,"");
	  electronTriggerSF = objTool->GetTotalElectronSF(*goodElectrons,false,false,true,false,"singleLepton");
	}
    }
    
    bool thisElectronPass = false;


      if (objTool->treatAsYear() == 2015){
	if (objTool->isData()){
	  
	  if ( (((objTool->IsTrigMatched( *el_itr, "HLT_e24_lhmedium_L1EM20VH") && (*el_itr)->pt() > 27000 )) || ((objTool->IsTrigMatched( *el_itr, "HLT_e60_lhmedium") && (*el_itr)->pt() > 62000 )) || ((objTool->IsTrigMatched( *el_itr, "HLT_e120_lhloose") && (*el_itr)->pt() > 122000 ))))
	    {
	      //electronTriggerSF = objTool->GetSignalElecSF(**el_itr, false, false, true, "Eff_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_Tight_Gradient");
	      passElectronTriggerMatch = true;
	      thisElectronPass = true;
	      TriggerPassElectrons->push_back(*el_itr);

	    }
	  else
	    {
	      NontriggerpassElectrons->push_back(*el_itr);
	      //electronTriggerSF = objTool->GetTotalElectronSF(*NontriggerpassElectrons, true, true, false, true);
	      //electronSF = electronSF*electronTriggerSF;
	    }
	}
	else{
	  if ( ( ( (objTool->IsTrigMatched( *el_itr, "HLT_e24_lhmedium_L1EM20VH") && (*el_itr)->pt() > 27000 ) ) || ((objTool->IsTrigMatched( *el_itr, "HLT_e60_lhmedium") && (*el_itr)->pt() > 62000 )) || ((objTool->IsTrigMatched( *el_itr, "HLT_e120_lhloose") && (*el_itr)->pt() > 122000 ))) ) 
	    {
	      TriggerPassElectrons->push_back(*el_itr);
	      //electronSF = objTool->GetTotalElectronSF(*TriggerPassElectrons, true, true, true, true);
	      passElectronTriggerMatch = true;
	    }
	  else{
	    NontriggerpassElectrons->push_back(*el_itr);
	    //electronTriggerSF = objTool->GetTotalElectronSF(*NontriggerpassElectrons, true, true, false, true);
	  }
	}
      }
      
      else if (objTool->treatAsYear() == 2016){
 	if (  ( (objTool->IsTrigMatched( *el_itr, "HLT_e26_lhtight_nod0_ivarloose") && (*el_itr)->pt() > 27000  )  ||  (objTool->IsTrigMatched( *el_itr, "HLT_e60_lhmedium_nod0") && (*el_itr)->pt() > 62000  )  || (objTool->IsTrigMatched( *el_itr, "HLT_e140_lhloose_nod0") && (*el_itr)->pt() > 142000 ) ) )
	 {
	   //electronTriggerSF = objTool->GetSignalElecSF(**el_itr, false, false, true, "Eff_SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0_Tight_Gradient");
	    TriggerPassElectrons->push_back(*el_itr);
	    
	    passElectronTriggerMatch = true;
	    thisElectronPass = true;
	    
	  }
	else
	  {
	    NontriggerpassElectrons->push_back(*el_itr);
	    //electronTriggerSF = objTool->GetTotalElectronSF(*NontriggerpassElectrons, true, true, false, true);
	  }
	
      }


      if (passElectronTriggerMatch) break;
      leadingLepton = false;
  }
  //electronTriggerSF = objTool->GetTotalElectronSF(*TriggerPassElectrons,false,false,true,false, "singleLepton");      
  //electronSF = electronSF*electronTriggerSF;
  
  
}



void ObjectDef::FillBaselineTaus(){

  xAOD::TauJetContainer::iterator ta_itr = baselineTausBeforeOR->begin();
  xAOD::TauJetContainer::iterator ta_end = baselineTausBeforeOR->end();
  
  tauSF = 1;
  
  for( ; ta_itr != ta_end; ++ta_itr ) {
    
    if  ( (*ta_itr)->auxdata< char >("passOR") && ( (*ta_itr)->auxdata< char >("baseline") ) ){
      baselineTaus->push_back( *ta_itr);
    
    }
    
    if ( ( (*ta_itr)->auxdata< char >("passOR") ) && ( (*ta_itr)->auxdata< char >("signal") ) && ( (*ta_itr)->auxdata< char >("baseline") ) ) {
      goodTaus->push_back( *ta_itr);

    }
    
  }

  xAOD::TauJetContainer* TriggerPassTaus  = new xAOD::TauJetContainer(SG::VIEW_ELEMENTS);
  eventStore->record(TriggerPassTaus,"TriggerPassTaus"+systematic);

  xAOD::TauJetContainer* NontriggerpassTaus  = new xAOD::TauJetContainer(SG::VIEW_ELEMENTS);
  eventStore->record(NontriggerpassTaus,"NontriggerpassTaus"+systematic);


  baselineTaus->sort(ptSorter);
  goodTaus->sort(ptSorter);

  // loop over for Trig matched here
  int year = objTool->treatAsYear();
  
  tauSF = 1;
  tauTriggerSF = 1;
  ta_itr = goodTaus->begin();
  ta_end = goodTaus->end();
  passTauTriggerMatch = false;

  bool leadingLepton = true;
  for (; ta_itr != ta_end; ++ta_itr) {
    // I don't think trigger matching/etc is used here. 
    if (leadingLepton){
    // the below will return just the ID SF
    tauSF = objTool->GetTotalTauSF(*goodTaus,true,false);
    // This trigger SF is only returning the trigger SF
    tauTriggerSF = objTool->GetTotalTauSF(*goodTaus,false,true,"tau25_medium1_tracktwo");
    
    }

    leadingLepton = false;
  }
  //tauTriggerSF = objTool->GetTotalTauSF(*TriggerPassTaus,false,false,true,false, "singleLepton");      
  //tauSF = tauSF*tauTriggerSF;
  
  
}



void ObjectDef::FillBaselinePhotons(){

  xAOD::PhotonContainer::iterator ph_itr = baselinePhotonsBeforeOR->begin();
  xAOD::PhotonContainer::iterator ph_end = baselinePhotonsBeforeOR->end();
  
  photonSF = 1;

  for( ; ph_itr != ph_end; ++ph_itr ) {
    if  ( (*ph_itr)->auxdata< char >("passOR") && ( (*ph_itr)->auxdata< char >("baseline") ) )
      baselinePhotons->push_back( *ph_itr);
    
    if ( ( (*ph_itr)->auxdata< char >("passOR") ) && ( (*ph_itr)->auxdata< char >("signal") ) ) {
      goodPhotons->push_back( *ph_itr);
     
    }
    
  }
  baselinePhotons->sort(ptSorter);
  goodPhotons->sort(ptSorter);

  
  ph_itr = goodPhotons->begin();
  ph_end = goodPhotons->end();
  
  passPhotonTriggerMatch = false;
  for (; ph_itr != ph_end; ++ph_itr) {
    
    if (objTool->IsTrigMatched( *ph_itr, "HLT_g120_loose") && (*ph_itr)->pt() > 130000)
      {
	passPhotonTriggerMatch = true;
	
	if ( this->DSID <= 0){
	  photonSF = 1;
	}
	
	else{
	  photonSF = objTool->GetTotalPhotonSF( *goodPhotons, true,true);
	}
	return;
      }
  }
}

void ObjectDef::FillBaselineMuons(){
  
  xAOD::MuonContainer::iterator mu_itr = baselineMuonsBeforeOR->begin();
  xAOD::MuonContainer::iterator mu_end = baselineMuonsBeforeOR->end();
  
  double MuonTriggerSF = 1;
  double MuonRecoSF = 1;
  muonSF = 1;
  oldMuonSF = 1;
  
  for( ; mu_itr != mu_end; ++mu_itr ) {
    if  ( ( (*mu_itr)->auxdata< char >("passOR") ) && !(*mu_itr)->auxdata< char >("cosmic") && ( (*mu_itr)->auxdata< char >("baseline") )  )
      baselineMuons->push_back( *mu_itr);
    if  ( ( (*mu_itr)->auxdata< char >("passOR") ) && (*mu_itr)->auxdata< char >("cosmic") && ( (*mu_itr)->auxdata< char >("baseline") )  )
      cosmicMuons->push_back( *mu_itr);
    if ( ( (*mu_itr)->auxdata< char >("passOR") ) && ( (*mu_itr)->auxdata< char >("signal") ==1 ) && (*mu_itr)->auxdata< char >("cosmic") ==0 ) {
      goodMuons->push_back( *mu_itr);
    }
    
  }

  baselineMuons->sort(ptSorter);
  cosmicMuons->sort(ptSorter);
  goodMuons->sort(ptSorter);

  xAOD::MuonContainer* TriggerPassMuons  = new xAOD::MuonContainer(SG::VIEW_ELEMENTS);
  eventStore->record(TriggerPassMuons,"TriggerPassMuons"+systematic);

  xAOD::MuonContainer* NontriggerpassMuons  = new xAOD::MuonContainer(SG::VIEW_ELEMENTS);
  eventStore->record(NontriggerpassMuons,"NontriggerpassMuons"+systematic);


  mu_itr = goodMuons->begin();
  mu_end = goodMuons->end();
  passMuonTriggerMatch = false;
  bool FirstRun = true;


  for (; mu_itr != mu_end; ++mu_itr) {
  bool thisMuonPass = false;


  if (FirstRun)
    {
      if ( objTool->treatAsYear() == 2015){
	MuonTriggerSF = objTool->GetTotalMuonSF(*goodMuons,false,false,"HLT_mu20_iloose_L1MU15_OR_HLT_mu50");
      }      
      else {//These triggers are the same for 2016/17 may change for 2018
	MuonTriggerSF = objTool->GetTotalMuonSF(*goodMuons,false,false,"HLT_mu26_ivarmedium_OR_HLT_mu50");
      }
      FirstRun = false;
      MuonRecoSF = objTool->GetTotalMuonSF(*goodMuons,true,true,"");
    }

    if ( objTool->treatAsYear() == 2015){
      
      if ( ((objTool->IsTrigMatched( *mu_itr, "HLT_mu20_iloose_L1MU15") && (*mu_itr)->pt() > 27) || (objTool->IsTrigMatched( *mu_itr, "HLT_mu50") && (*mu_itr)->pt() > 27))  && !passMuonTriggerMatch && !thisMuonPass)
	{
	  TriggerPassMuons->push_back(*mu_itr);
	  passMuonTriggerMatch = true;
	  thisMuonPass = true;
	}
    }
    
    else if ( objTool->treatAsYear() == 2016){
    
      if ( ((objTool->IsTrigMatched( *mu_itr, "HLT_mu50") && (*mu_itr)->pt() > 27) || (objTool->IsTrigMatched( *mu_itr, "HLT_mu26_ivarmedium") && (*mu_itr)->pt() > 27))  && !passMuonTriggerMatch && !thisMuonPass){
	TriggerPassMuons->push_back(*mu_itr);
	
	passMuonTriggerMatch = true;
	thisMuonPass = true;
      }
    }

    if (!thisMuonPass)
      {
	NontriggerpassMuons->push_back(*mu_itr);
	//muonSF *= objTool->GetTotalMuonSF(*NontriggerpassMuons, true, true, "");
      }
  }
  //muonSF = objTool->GetTotalMuonSF(*TriggerPassMuons, false, false, "HLT_mu26_ivarmedium_OR_HLT_mu50");
  //muonSF *= objTool->GetTotalMuonSF(*NontriggerpassMuons, true, true, "");
  
  muonSF = MuonTriggerSF*MuonRecoSF;

    
}
  



void ObjectDef::FillGoodJets(){

  xAOD::JetContainer::iterator jet_itr = goodJetsBeforeOR->begin();
  xAOD::JetContainer::iterator jet_end = goodJetsBeforeOR->end();
  int jet = 0;

  bJetSF = 1;
  
  for( ; jet_itr != jet_end; ++jet_itr ) {
    
    int flavour = -1;

    (*jet_itr)->getAttribute("TruthLabelID",flavour);
    
    if ( (*jet_itr)->auxdata< char >("passOR")==1 &&  (*jet_itr)->auxdata< char >("bad")==1 )
      {
	badJets->push_back( *jet_itr);
      }
    
    else if( (*jet_itr)->auxdata< char >("baseline")==1  && (*jet_itr)->auxdata< char >("signal")==1 && (*jet_itr)->auxdata< char >("passOR")==1) 
           
      {
	
	goodJets->push_back(*jet_itr);
	
	
	flavour = -1;
	(*jet_itr)->getAttribute("TruthLabelID",flavour);
	if ( (*jet_itr)->auxdata< char >("bjet")==1 && (fabs((*jet_itr)->eta() < 2.5)))
	  {
	    BJets->push_back( *jet_itr);
	  }
	else{
	  nonBJets->push_back(*jet_itr);
	}
      }
  }
  
  goodJets->sort(ptSorter);
  BJets->sort(ptSorter);
  nonBJets->sort(ptSorter);

  if ( this->DSID <= 0){
    bJetSF = 1;
  }
  else{
    bJetSF = objTool->BtagSF(goodJets);
  }
  
  if ( this->DSID <= 0){
    JVTSF = 1;
  }
  else{
    JVTSF = objTool->JVT_SF(goodJets);
  }
  
}

void ObjectDef::SetPrimVertex(){

  const xAOD::VertexContainer* primVertex = 0;
  currentEvent->retrieve( primVertex, "PrimaryVertices" );
  nVertex = 0;
  
  for ( const auto& vx : *primVertex) {
      if (vx->vertexType() == xAOD::VxType::PriVtx) {
        nVertex++ ;
      }
   }
  
}

void ObjectDef::FillFatJets_kt8(){
  fatjet_kt8_tool->msg().setLevel( MSG::ERROR);
  fatjet_kt8_tool->execute();
  currentEvent->retrieve( FatJets_kt8,"MyFatJetsKt8"+systematic );
  //if (!currentEvent->retrieve( FatJets_kt8,"MyFatJetsKt8"+systematic ).isSuccess()) std::cout << "Something went wrong here" << std::endl;
  //if (currentEvent->retrieve( FatJets_kt8,"MyFatJetsKt8"+systematic ).isSuccess()) std::cout << "FatJets container retrieved" << std::endl;
  
  
}


void ObjectDef::FillFatJets_kt12(){
  fatjet_kt12_tool->msg().setLevel( MSG::ERROR);
  fatjet_kt12_tool->execute();
  currentEvent->retrieve( FatJets_kt12,"MyFatJetsKt12"+systematic );
  //if (!currentEvent->retrieve( FatJets_kt12,"MyFatJetsKt12"+systematic ).isSuccess()) std::cout << "Something went wrong here" << std::endl;
  //if (currentEvent->retrieve( FatJets_kt12,"MyFatJetsKt12"+systematic ).isSuccess()) << "FatJets container retrieved" << std::endl;

}

bool ObjectDef::SetUpFatJetTools(JetToolRunner *&tool, double jetradius, std::string inputcontainer, std::string outputcontainer){

  
  //double jetradius = 0.8; 
  xAOD::IParticleContainer* m_goodJets_recl; //!  
  //std::string inputcontainer = "GoodJets_recl";
  //std::string outputcontainer = "fatJets_kt8"+systName;
  tool = 0;
  //JetFatJet_Kt8_ToolRunner* m_jetRecTool_kt8; //!

  ToolHandleArray<IPseudoJetGetter> hgets;
  ToolHandleArray<IJetExecuteTool> hrecs;

  PseudoJetGetter * plcget = new PseudoJetGetter(("mylcget"+outputcontainer).c_str());
  plcget->msg().setLevel( MSG::ERROR);
  plcget->setProperty("InputContainer", inputcontainer);
  plcget->setProperty("OutputContainer", "Reclustered"+outputcontainer);
  plcget->setProperty("Label", "Tower");
  plcget->setProperty("SkipNegativeEnergy", true);
  plcget->setProperty("GhostScale", 0.0);

  ToolHandle<IPseudoJetGetter> hlcget(plcget);
  hgets.push_back(hlcget);


  JetFromPseudojet * pbuild = new JetFromPseudojet(("myjetbuild"+outputcontainer).c_str());
  ToolHandle<IJetFromPseudojet> hbuild(pbuild);
  pbuild->msg().setLevel( MSG::ERROR);
  pbuild->initialize();
  
  JetFinder * pfind = new JetFinder(("myjetfind"+outputcontainer).c_str());
  pfind->msg().setLevel( MSG::ERROR);
  pfind->setProperty("JetAlgorithm", "AntiKt");
  pfind->setProperty("JetRadius", jetradius);
  pfind->setProperty("PtMin", 15000.0);
  pfind->setProperty("GhostArea", 0.00);
  pfind->setProperty("RandomOption", 1);
  pfind->setProperty("JetBuilder", hbuild);

  ToolHandle<IJetFinder> hfind(pfind);
  pfind->initialize();
  


  JetRecTool * pjrf = new JetRecTool(("myjrfind"+outputcontainer).c_str());
  pjrf->msg().setLevel( MSG::ERROR);
  pjrf->setProperty("OutputContainer", outputcontainer);
  pjrf->setProperty("PseudoJetGetters", hgets);
  pjrf->setProperty("JetFinder", hfind);
  pjrf->initialize();
  ToolHandle<IJetExecuteTool> hjrf(pjrf);
  hrecs.push_back(pjrf);

 
  tool = new JetToolRunner(("jetrunner"+outputcontainer).c_str());
  tool->msg().setLevel( MSG::ERROR);
  tool->setProperty("Tools", hrecs);
  //  Info("Initialising JetReclusteringTool(s)");
  tool->initialize();
  //tool->print();
  
  delete plcget;//Need to delete all of the below tools in some way to avoid a memory leal 
  delete pbuild;
  delete pfind;
  delete pjrf;
  return true;
}

bool ObjectDef::removeFatJetTools(std::string systName){

    //Removing the FatJetTool that we have initialised for this event (to avoid replication)

    std::string FatJets8ToolName = "MyFatJetsKt8"+systName;
    std::string FatJets12ToolName = "MyFatJetsKt12"+systName;
    std::string FatJetsTool8 ="m_jetRecTool_kt8_"+systName; 
    std::string FatJetsTool12 ="m_jetRecTool_kt12_"+systName; 
    std::string plcGet8 = "mylcget"+FatJets8ToolName;
    std::string plcGet12 = "mylcget"+FatJets12ToolName;
    std::string pbuild8 = "myjetbuild"+FatJets8ToolName;
    std::string pbuild12 = "myjetbuild"+FatJets12ToolName;
    std::string pfind8 = "myjetfind"+FatJets8ToolName;
    std::string pfind12 = "myjetfind"+FatJets12ToolName;
    std::string pjrfind8 = "myjrfind"+FatJets8ToolName;
    std::string pjrfind12 = "myjrfind"+FatJets12ToolName;
    std::string prunner8 = "jetrunner"+FatJets8ToolName;
    std::string prunner12 = "jetrunner"+FatJets12ToolName;
    std::string pjrfind_retriever8 = pjrfind8+"_retriever";
    std::string pjrfind_retriever12 = pjrfind12+"_retriever";
    
    asg::ToolStore::remove(plcGet8);
    
    asg::ToolStore::remove(plcGet12);
    //std::cout<<"Removed the tool in a continue loop  plcget "<<std::endl;
    asg::ToolStore::remove(pbuild8);
    asg::ToolStore::remove(pbuild12);
    //std::cout<<"Removed the tool in a continue loop  pbuild "<<std::endl;
    asg::ToolStore::remove(pfind8);
    asg::ToolStore::remove(pfind12);
    //std::cout<<"Removed the tool in a continue loop  pfind "<<std::endl;
    asg::ToolStore::remove(pjrfind8);
    asg::ToolStore::remove(pjrfind12);
    //std::cout<<"Removed the tool in a continue loop  pjrfind "<<std::endl;
    asg::ToolStore::remove(pjrfind_retriever8);
    asg::ToolStore::remove(pjrfind_retriever12);
    //std::cout<<"Removed the tool in a continue loop  pjrfind "<<std::endl;
    asg::ToolStore::remove(prunner8);
    asg::ToolStore::remove(prunner12);
    //std::cout<<"Removed the tool in a continue loop  prunner "<<std::endl;
    asg::ToolStore::remove(FatJetsTool8);
    asg::ToolStore::remove(FatJetsTool12);
    //std::cout<<"Removed the fatJets tools "<<std::endl;
    
    delete fatjet_kt12_tool;
    delete fatjet_kt8_tool;
    return true;
}
//Memory usage checking 
void ObjectDef::process_mem_usage(double& vm_usage, double& resident_set)
{
  vm_usage     = 0.0;
  resident_set = 0.0;

  // the two fields we want
  unsigned long vsize;
  long rss;
  {
    std::string ignore;
    std::ifstream ifs("/proc/self/stat", std::ios_base::in);
    ifs >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore
	>> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore
	>> ignore >> ignore >> vsize >> rss;
  }

  long page_size_kb = sysconf(_SC_PAGE_SIZE) / 1024; // in case x86-64 is configured to use 2MB pages
  vm_usage = vsize / 1024.0;
  resident_set = rss * page_size_kb;
}

int ObjectDef::CheckMem()
{
  using std::cout;
  using std::endl;

  double vm, rss;
  process_mem_usage(vm, rss);
  cout << "VM: " << vm << "; RSS: " << rss << endl;
  return 1;
}
