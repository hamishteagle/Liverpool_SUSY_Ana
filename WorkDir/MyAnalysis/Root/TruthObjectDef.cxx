#include "MyAnalysis/TruthObjectDef.h"
#include "MyAnalysis/IObjectDef.h"
#include <iterator> 
#include <stdio.h>     
#include <stdlib.h>    
#include <random>
#include "MCTruthClassifier/MCTruthClassifier.h"

//#include "MissingETEvent/MissingET.h"

static SG::AuxElement::Decorator<char> dec_baseline("baseline");
static SG::AuxElement::Decorator<char> dec_signal("signal");
static SG::AuxElement::Decorator<char> dec_passOR("passOR");
static SG::AuxElement::Decorator<char> dec_badjet("bad");
static SG::AuxElement::Decorator<char> dec_bjet("bjet");
static SG::AuxElement::Decorator<char> dec_cosmic("cosmic");


bool ptTruthSorter( const xAOD::IParticle* j1, const xAOD::IParticle* j2 ) {
  return ( j1->pt() > j2->pt() );
}

//TruthObject Def with FatJets fails on PseudoJetGetter
TruthObjectDef::TruthObjectDef(xAOD::TEvent* event, ST::SUSYObjDef_xAOD* SUSYTool, xAOD::TStore* store, double mcChannelNumber, double eventN, double mcEventWgt, double crossSect, std::string systName, bool doPhotons, asg::AnaToolHandle<IMETSignificance> Tool_METSig, double  m_averageIntPerX):IObjectDef(event, SUSYTool, store, mcChannelNumber, eventN, mcEventWgt, crossSect, systName, doPhotons, m_averageIntPerX) //, JetToolRunner* Tool_FatJets_kt12, JetToolRunner* Tool_FatJets_kt8

{

  //fatjet_kt12_tool = Tool_FatJets_kt12;
  //fatjet_kt8_tool = Tool_FatJets_kt8;


  baselineElectronsBeforeOR = new xAOD::TruthParticleContainer(SG::VIEW_ELEMENTS);
  signalElectronsBeforeOR = new xAOD::TruthParticleContainer(SG::VIEW_ELEMENTS);
  baselineTausBeforeOR = new xAOD::TruthParticleContainer(SG::VIEW_ELEMENTS);
  signalTausBeforeOR = new xAOD::TruthParticleContainer(SG::VIEW_ELEMENTS);
  goodJetsBeforeOR = new xAOD::JetContainer(SG::VIEW_ELEMENTS);
  baselineMuonsBeforeOR = new xAOD::TruthParticleContainer(SG::VIEW_ELEMENTS);
  signalMuonsBeforeOR = new xAOD::TruthParticleContainer(SG::VIEW_ELEMENTS);
  baselinePhotonsBeforeOR = new xAOD::TruthParticleContainer(SG::VIEW_ELEMENTS);
  signalPhotonsBeforeOR = new xAOD::TruthParticleContainer(SG::VIEW_ELEMENTS);
  badJets = new xAOD::JetContainer(SG::VIEW_ELEMENTS);
  cosmicMuons = new xAOD::TruthParticleContainer(SG::VIEW_ELEMENTS);
  badMuons = new xAOD::TruthParticleContainer(SG::VIEW_ELEMENTS);
  baselineElectrons = new xAOD::TruthParticleContainer(SG::VIEW_ELEMENTS);
  baselineTaus = new xAOD::TruthParticleContainer(SG::VIEW_ELEMENTS);
  baselineMuons = new xAOD::TruthParticleContainer(SG::VIEW_ELEMENTS);
  baselinePhotons = new xAOD::TruthParticleContainer(SG::VIEW_ELEMENTS);
  goodJets = new xAOD::JetContainer(SG::VIEW_ELEMENTS);
  FatJets_kt8 = new xAOD::JetContainer(SG::VIEW_ELEMENTS);
  FatJets_kt12 = new xAOD::JetContainer(SG::VIEW_ELEMENTS);
  goodAntiKt4TruthJets = new xAOD::JetContainer(SG::VIEW_ELEMENTS);
  goodAntiKt3TruthJets = new xAOD::JetContainer(SG::VIEW_ELEMENTS);
  goodElectrons = new xAOD::TruthParticleContainer(SG::VIEW_ELEMENTS);
  goodTaus = new xAOD::TruthParticleContainer(SG::VIEW_ELEMENTS);
  goodMuons = new xAOD::TruthParticleContainer(SG::VIEW_ELEMENTS);
  goodPhotons = new xAOD::TruthParticleContainer(SG::VIEW_ELEMENTS);
  BJets = new xAOD::JetContainer(SG::VIEW_ELEMENTS);
  nonBJets = new xAOD::JetContainer(SG::VIEW_ELEMENTS);
  METmuons  = new xAOD::TruthParticleContainer(SG::VIEW_ELEMENTS);
  

 

  eventStore->record(baselineElectronsBeforeOR,"baselineElectronsBeforeOR");
  eventStore->record(signalElectronsBeforeOR,"signalElectronsBeforeOR");
  eventStore->record(baselineTausBeforeOR,"baselineTausBeforeOR");
  eventStore->record(signalTausBeforeOR,"signalTausBeforeOR");
  eventStore->record(goodJetsBeforeOR,"goodJetsBeforeOR");
  eventStore->record(baselineMuonsBeforeOR,"baselineMuonsBeforeOR");
  eventStore->record(signalMuonsBeforeOR,"signalMuonsBeforeOR");
  eventStore->record(badJets,"badJets");
  eventStore->record(cosmicMuons,"cosmicMuons");
  eventStore->record(badMuons,"badMuons");
  eventStore->record(baselineElectrons,"baselineElectrons");
  eventStore->record(baselineTaus,"baselineTaus");
  eventStore->record(baselineMuons,"baselineMuons");
  eventStore->record(goodJets,"goodJets");
  eventStore->record(FatJets_kt8,"fatJets_kt8");
  eventStore->record(FatJets_kt12,"fatJets_kt12");
  eventStore->record(goodAntiKt4TruthJets,"goodAntiKt4TruthJets");
  eventStore->record(goodAntiKt3TruthJets,"goodAntiKt3TruthJets");
  eventStore->record(goodElectrons,"goodElectrons");
  eventStore->record(goodTaus,"goodTaus");
  eventStore->record(goodMuons,"goodMuons"); 
  eventStore->record(BJets,"BJets");
  eventStore->record(nonBJets,"nonBJets");
  eventStore->record(METmuons,"METmuons");  

  fatjet_kt12_tool = new JetToolRunner("m_jetRecTool_kt12_");
  fatjet_kt8_tool = new JetToolRunner("m_jetRecTool_kt8_");
 
  this->SetUpFatJetTools(fatjet_kt12_tool, 1.2, "goodJets", "MyFatJetsKt12");
  this->SetUpFatJetTools(fatjet_kt8_tool, 0.8, "goodJets", "MyFatJetsKt8");

  this->FillPreORMuons();
  this->FillPreORElectrons();
  this->FillPreORTaus();
  
  //this->FillPreORPhotons();
  
  this->FillPreORJets();
  this->FillMET();
  
  this->OldOverlapRemoval();
  //this->OverlapRemoval();
  
  this->FillBaselineElectrons();
  this->FillBaselineTaus();
  this->FillBaselineMuons();
  
  //this->FillBaselinePhotons();
  
  this->FillGoodJets();
  this->SetPrimVertex();

  this->FillFatJets_kt8();
  this->FillFatJets_kt12();

  

}

void TruthObjectDef::FillPreORMuons(){


  const xAOD::TruthParticleContainer* muons = 0;
  currentEvent->retrieve( muons, "TruthMuons" );

  std::pair< xAOD::TruthParticleContainer*, xAOD::ShallowAuxContainer* > muons_shallowCopy = xAOD::shallowCopyContainer( *muons );

  eventStore->record(muons_shallowCopy.first, "CalibratedMuons");
  eventStore->record(muons_shallowCopy.second, "CalibratedMuons_Aux");


  xAOD::TruthParticleContainer::iterator mu_itr = (muons_shallowCopy.first)->begin();
  xAOD::TruthParticleContainer::iterator mu_end  = (muons_shallowCopy.first)->end();
  
  for( ; mu_itr != mu_end; ++mu_itr ) {
    
    
    if ((**mu_itr).pt() > 10000 && fabs((**mu_itr).eta())<2.4){

      if (6==(**mu_itr).auxdata<unsigned int>("classifierParticleType")){
	//if ((**mu_itr).status() == 2){
	  dec_baseline(**mu_itr) = true;
	  dec_signal(**mu_itr) = true; 
	  //(No iso for truth particles so makes no sense)
	  baselineMuonsBeforeOR->push_back (*mu_itr);
	  signalMuonsBeforeOR->push_back (*mu_itr);
	  //}
	}
    }
    //    else{
    //  badMuons->push_back(*mu_itr);
    //}
    
  }
  
  baselineMuonsBeforeOR->sort(ptTruthSorter);
  signalMuonsBeforeOR->sort(ptTruthSorter);
  

  return;

}



void TruthObjectDef::FillPreORElectrons(){


  const xAOD::TruthParticleContainer* electrons = 0;
  currentEvent->retrieve( electrons, "TruthElectrons" );

  std::pair< xAOD::TruthParticleContainer*, xAOD::ShallowAuxContainer* > electrons_shallowCopy = xAOD::shallowCopyContainer( *electrons );
  eventStore->record(electrons_shallowCopy.first, "CalibratedElectronCollection");
  eventStore->record(electrons_shallowCopy.second, "CalibratedElectronCollection_Aux");
  
  xAOD::TruthParticleContainer::iterator el_itr = (electrons_shallowCopy.first)->begin();
  xAOD::TruthParticleContainer::iterator el_end = (electrons_shallowCopy.first)->end();


  for( ; el_itr != el_end; ++el_itr ) {

    if ((**el_itr).pt() > 10000 && fabs((**el_itr).eta())<2.4){
      
      if (2==(**el_itr).auxdata<unsigned int>("classifierParticleType")){
      //if ((**el_itr).status() == 1){
	  
	  dec_baseline(**el_itr) = true;
	  dec_signal(**el_itr) = true; 
	  //(No iso for truth particles so makes no sense)
	  baselineElectronsBeforeOR->push_back (*el_itr);
	  signalElectronsBeforeOR->push_back (*el_itr);
      }
	  //}
    }
  }
  
  baselineElectronsBeforeOR->sort(ptTruthSorter);
  signalElectronsBeforeOR->sort(ptTruthSorter);
 
}



void TruthObjectDef::FillPreORTaus(){


  const xAOD::TruthParticleContainer* taus = 0;
  currentEvent->retrieve( taus, "TruthTaus" );

  std::pair< xAOD::TruthParticleContainer*, xAOD::ShallowAuxContainer* > taus_shallowCopy = xAOD::shallowCopyContainer( *taus );
  eventStore->record(taus_shallowCopy.first, "CalibratedTauCollection");
  eventStore->record(taus_shallowCopy.second, "CalibratedTauCollection_Aux");
  
  xAOD::TruthParticleContainer::iterator ta_itr = (taus_shallowCopy.first)->begin();
  xAOD::TruthParticleContainer::iterator ta_end = (taus_shallowCopy.first)->end();


  for( ; ta_itr != ta_end; ++ta_itr ) {

    if ((**ta_itr).pt() > 10000 && fabs((**ta_itr).eta())<2.4){
      
      if (10==(**ta_itr).auxdata<unsigned int>("classifierParticleType")){
      //if ((**ta_itr).status() == 1){
	  
	  dec_baseline(**ta_itr) = true;
	  dec_signal(**ta_itr) = true; 
	  //(No iso for truth particles so makes no sense)
	  baselineTausBeforeOR->push_back (*ta_itr);
	  signalTausBeforeOR->push_back (*ta_itr);
      }
	  //}
    }
  }
  
  baselineTausBeforeOR->sort(ptTruthSorter);
  signalTausBeforeOR->sort(ptTruthSorter);
 
}


void TruthObjectDef::FillPreORPhotons(){


  const xAOD::TruthParticleContainer* photons = 0;
  currentEvent->retrieve( photons, "TruthPhotons" );

  std::pair< xAOD::TruthParticleContainer*, xAOD::ShallowAuxContainer* > photons_shallowCopy = xAOD::shallowCopyContainer( *photons );
  eventStore->record(photons_shallowCopy.first, "CalibratedPhotonCollection");
  eventStore->record(photons_shallowCopy.second, "CalibratedPhotonCollection_Aux");
  
  xAOD::TruthParticleContainer::iterator ph_itr = (photons_shallowCopy.first)->begin();
  xAOD::TruthParticleContainer::iterator ph_end = (photons_shallowCopy.first)->end();


  for( ; ph_itr != ph_end; ++ph_itr ) {

    //if ((**ph_itr).pt() > 25000 && fabs((**ph_itr).eta())<2.37){

      

      if (14==(**ph_itr).auxdata<unsigned int>("classifierParticleType")){
	dec_baseline(**ph_itr) = true;
	  baselinePhotonsBeforeOR->push_back (*ph_itr);
	  
	  //if ((**ph_itr).pt() > 130000){
	    
	    dec_signal(**ph_itr) = true; 
	    signalPhotonsBeforeOR->push_back (*ph_itr);
	    //}
      //}
    }
  }
  
  baselinePhotonsBeforeOR->sort(ptTruthSorter);
  signalPhotonsBeforeOR->sort(ptTruthSorter);
  
}




void TruthObjectDef::FillPreORJets(){


  const xAOD::JetContainer* jets = 0;
  currentEvent->retrieve( jets, "AntiKt4TruthJets" );

  std::pair< xAOD::JetContainer*, xAOD::ShallowAuxContainer* > jets_shallowCopy = xAOD::shallowCopyContainer( *jets );
  eventStore->record(jets_shallowCopy.first, "CalibratedAntiKt4LCTopoJets");
  eventStore->record(jets_shallowCopy.second, "CalibratedAntiKt4LCTopoJets_Aux");

  xAOD::JetContainer::iterator jet_itr = (jets_shallowCopy.first)->begin();
  xAOD::JetContainer::iterator jet_end = (jets_shallowCopy.first)->end();

  for( ; jet_itr != jet_end; ++jet_itr ) {

    if ((**jet_itr).pt() > 0 && fabs((**jet_itr).eta())<2.8){

      dec_baseline(**jet_itr) = true;
      goodJetsBeforeOR->push_back (*jet_itr);
    }
    
    //else{
      //dec_badjet(**jet_itr) = true;
      //badJets->push_back (*jet_itr);
    //}


  }  
  goodJetsBeforeOR->sort(ptTruthSorter);
    
}
  

void TruthObjectDef::FillMET(){


  const xAOD::MissingETContainer* met_Truth = 0;
  currentEvent->retrieve(met_Truth,"MET_Truth");

  if (!met_Truth){
    std::cout << "Could not find MET_Truth container in xAOD" << std::endl;
  }
 
  MET = (*met_Truth)["NonInt"]->met();
  //METphi = (*met_Truth)["NonInt"]->met(); 
  double mpx = (*met_Truth)["NonInt"]->mpx();
  double mpy = (*met_Truth)["NonInt"]->mpy();
  
  METvector = new TVector2 (mpx,mpy);
  METphi = METvector->Phi();

  double m_metsigET = 0; 
  double m_metsigHT = 0;
  double m_metsig = 0; 

  
  metSignificances.push_back(m_metsigET);
  metSignificances.push_back(m_metsigHT);
  metSignificances.push_back(m_metsig);

    
  return;

}

void TruthObjectDef::OldOverlapRemoval(){

  double dRejet = 0.2;
  double dRjete = 0.4;
  double dRjetmu = 0.4;
  bool doHarmonization = false;
 
  xAOD::JetContainer::const_iterator jet_itr = goodJetsBeforeOR->begin();
  xAOD::JetContainer::const_iterator jet_end = goodJetsBeforeOR->end();
  for( ; jet_itr != jet_end; ++jet_itr ) {
    bool jet_sel = dec_baseline(**jet_itr);
    if(jet_sel)
      dec_passOR( **jet_itr ) = 1;
    else
      dec_passOR( **jet_itr ) = 0;
  }

  xAOD::TruthParticleContainer::const_iterator mu_itr = baselineMuonsBeforeOR->begin();
  xAOD::TruthParticleContainer::const_iterator mu_end = baselineMuonsBeforeOR->end();
  for( ; mu_itr != mu_end; ++mu_itr ) {
    bool mu_sel;
    if(doHarmonization) mu_sel = dec_signal(**mu_itr);
    else mu_sel = dec_baseline(**mu_itr);
    if(mu_sel)
      dec_passOR( **mu_itr ) = 1;
    else
      dec_passOR( **mu_itr ) = 0;
  }
  
  // remove jets overlapping with (baseline/signal) electrons
  xAOD::TruthParticleContainer::const_iterator el_itr = baselineElectronsBeforeOR->begin();
  xAOD::TruthParticleContainer::const_iterator el_end = baselineElectronsBeforeOR->end();
  for( ; el_itr != el_end; ++el_itr ) {
    bool el_sel;
    if(doHarmonization) el_sel = dec_signal(**el_itr);
    else el_sel = dec_baseline(**el_itr);
    if( !el_sel ){
      dec_passOR( **el_itr ) = 0;
      continue;
    }else{
      dec_passOR( **el_itr ) = 1;
    }
    

    //xAOD::JetContainer::const_iterator jet_itr = jets->begin();
    //xAOD::JetContainer::const_iterator jet_end = jets->end();
    
    // Reset Jet Iterator
    jet_itr = goodJetsBeforeOR->begin();

    
    for( ; jet_itr != jet_end; ++jet_itr ) {
      if( !dec_passOR(**jet_itr) ) continue;
      
      TLorentzVector el4vec = (*el_itr)->p4();
      TLorentzVector jet4vec = (*jet_itr)->p4();
      
      if (el4vec.DeltaR(jet4vec)<dRejet) {
	dec_passOR( **jet_itr ) = 0;
      }
    }
  } // END loop over electrons
  
  // Remove electrons and muons overlapping with jets
  // Reset El Iterator
  el_itr = baselineElectronsBeforeOR->begin();
  //el_end = electrons->end();
  for( ; el_itr != el_end; ++el_itr ) {
    
    if( !dec_passOR(**el_itr) ) continue;
    
    for( ; jet_itr != jet_end; ++jet_itr ) {
      
      if ( !dec_passOR( **jet_itr ) ) continue;
      
      TLorentzVector el4vec = (*el_itr)->p4();
      TLorentzVector jet4vec = (*jet_itr)->p4();
      
      if (el4vec.DeltaR(jet4vec)<dRjete) {
       	dec_passOR( **el_itr ) = 0;
      }
    }
  }

  // Reset Jets & Muon iterator
  jet_itr = goodJetsBeforeOR->begin();
  mu_itr = baselineMuonsBeforeOR->begin();
  
  for( ; mu_itr != mu_end; ++mu_itr ) {
    
    if( !dec_passOR(**mu_itr) ) continue;
    
    for( ; jet_itr != jet_end; ++jet_itr ) {
      
      if ( !dec_passOR( **jet_itr ) ) continue;
      
      TLorentzVector mu4vec = (*mu_itr)->p4();
      TLorentzVector jet4vec = (*jet_itr)->p4();
      
      std::vector<int> nTrkVec;
      //(*jet_itr)->getAttribute(xAOD::JetAttribute::NumTrkPt500, nTrkVec);
      //int jet_nTrk = nTrkVec[0];
      int jet_nTrk = 0;
      if (mu4vec.DeltaR(jet4vec)<dRjetmu) {
	if(doHarmonization && jet_nTrk<3){
	  dec_passOR( **jet_itr ) = 0;
	}else{
	  dec_passOR( **mu_itr ) = 0;
	}
      }
    }
  }
  
}




void TruthObjectDef::OverlapRemoval(){

  double dRejet = 0.2;
  double dRjete = 0.4;
  double dRjetmu = 0.4;
  bool doHarmonization = false;
 
  double dRphjet = 0.4; 
  double dReph = 0.4;
  double dRmuph = 0.4;
  
  xAOD::JetContainer::const_iterator jet_itr = goodJetsBeforeOR->begin();
  xAOD::JetContainer::const_iterator jet_end = goodJetsBeforeOR->end();
  for( ; jet_itr != jet_end; ++jet_itr ) {
    bool jet_sel = dec_baseline(**jet_itr);
    if(jet_sel)
      dec_passOR( **jet_itr ) = 1;
    else
      dec_passOR( **jet_itr ) = 0;
  }

  
  xAOD::TruthParticleContainer::const_iterator ph_itr = baselinePhotonsBeforeOR->begin();
  xAOD::TruthParticleContainer::const_iterator ph_end = baselinePhotonsBeforeOR->end();
  for( ; ph_itr != ph_end; ++ph_itr ) {
    bool ph_sel;
    if(doHarmonization) ph_sel = dec_signal(**ph_itr);
    else ph_sel = dec_baseline(**ph_itr);
    if(ph_sel)
      dec_passOR( **ph_itr ) = 1;
    else
      dec_passOR( **ph_itr ) = 0;
  }
  
  xAOD::TruthParticleContainer::const_iterator mu_itr = baselineMuonsBeforeOR->begin();
  xAOD::TruthParticleContainer::const_iterator mu_end = baselineMuonsBeforeOR->end();
  for( ; mu_itr != mu_end; ++mu_itr ) {
    bool mu_sel;
    if(doHarmonization) mu_sel = dec_signal(**mu_itr);
    else mu_sel = dec_baseline(**mu_itr);
    if(mu_sel)
      dec_passOR( **mu_itr ) = 1;
    else
      dec_passOR( **mu_itr ) = 0;
  }
  
  // remove jets overlapping with (baseline/signal) electrons
  xAOD::TruthParticleContainer::const_iterator el_itr = baselineElectronsBeforeOR->begin();
  xAOD::TruthParticleContainer::const_iterator el_end = baselineElectronsBeforeOR->end();
  for( ; el_itr != el_end; ++el_itr ) {
    bool el_sel;
    if(doHarmonization) el_sel = dec_signal(**el_itr);
    else el_sel = dec_baseline(**el_itr);
    if( !el_sel ){
      dec_passOR( **el_itr ) = 0;
      continue;
    }else{
      dec_passOR( **el_itr ) = 1;
    }
    

    //xAOD::JetContainer::const_iterator jet_itr = jets->begin();
    //xAOD::JetContainer::const_iterator jet_end = jets->end();
    
    // Reset Jet Iterator
    jet_itr = goodJetsBeforeOR->begin();

    
    for( ; jet_itr != jet_end; ++jet_itr ) {
      if( !dec_passOR(**jet_itr) ) continue;
      
      TLorentzVector el4vec = (*el_itr)->p4();
      TLorentzVector jet4vec = (*jet_itr)->p4();
      
      if (el4vec.DeltaR(jet4vec)<dRejet) {
	dec_passOR( **jet_itr ) = 0;
      }
    }
  } // END loop over electrons
  
  
  // Remove electrons and muons overlapping with jets
  // Reset El Iterator
  el_itr = baselineElectronsBeforeOR->begin();
  jet_itr = goodJetsBeforeOR->begin();
  //el_end = electrons->end();
  
  for( ; el_itr != el_end; ++el_itr ) {
    
    if( !dec_passOR(**el_itr) ) continue;
    
    for( ; jet_itr != jet_end; ++jet_itr ) {
      
      if ( !dec_passOR( **jet_itr ) ) continue;
      
      TLorentzVector el4vec = (*el_itr)->p4();
      TLorentzVector jet4vec = (*jet_itr)->p4();
      
      if (el4vec.DeltaR(jet4vec)<dRjete) {
       	dec_passOR( **el_itr ) = 0;
      }
    }
  }

  // Reset Jets & Muon iterator
  jet_itr = goodJetsBeforeOR->begin();
  mu_itr = baselineMuonsBeforeOR->begin();
  
  for( ; mu_itr != mu_end; ++mu_itr ) {
    
    if( !dec_passOR(**mu_itr) ) continue;
    
    for( ; jet_itr != jet_end; ++jet_itr ) {
      
      if ( !dec_passOR( **jet_itr ) ) continue;
      
      TLorentzVector mu4vec = (*mu_itr)->p4();
      TLorentzVector jet4vec = (*jet_itr)->p4();
      
      std::vector<int> nTrkVec;
      //(*jet_itr)->getAttribute(xAOD::JetAttribute::NumTrkPt500, nTrkVec);
      //int jet_nTrk = nTrkVec[0];
      int jet_nTrk = 0;
      if (mu4vec.DeltaR(jet4vec)<dRjetmu) {
	if(doHarmonization && jet_nTrk<3){
	  dec_passOR( **jet_itr ) = 0;
	}else{
	  dec_passOR( **mu_itr ) = 0;
	}
      }
    }
  }

  // loop over photons and jets

  jet_itr = goodJetsBeforeOR->begin();
  ph_itr = baselinePhotonsBeforeOR->begin();

  for( ; ph_itr != ph_end; ++ph_itr ) {
    
    if( !dec_passOR(**ph_itr) ) continue;
    
    for( ; jet_itr != jet_end; ++jet_itr ) {
      
      if ( !dec_passOR( **jet_itr ) ) continue;
      
      TLorentzVector ph4vec = (*ph_itr)->p4();
      TLorentzVector jet4vec = (*jet_itr)->p4();
      
      if (ph4vec.DeltaR(jet4vec)<dRphjet) {
	  dec_passOR( **jet_itr ) = 0;
      }
    }
  }


  // loop over photons and Muons

  mu_itr = baselineMuonsBeforeOR->begin();
  ph_itr = baselinePhotonsBeforeOR->begin();

  for( ; ph_itr != ph_end; ++ph_itr ) {
    
    if( !dec_passOR(**ph_itr) ) continue;
    
    for( ; mu_itr != mu_end; ++mu_itr ) {
      
      if ( !dec_passOR( **mu_itr ) ) continue;
      
      TLorentzVector ph4vec = (*ph_itr)->p4();
      TLorentzVector mu4vec = (*mu_itr)->p4();
      
      if (ph4vec.DeltaR(mu4vec)<dRmuph) {
	  dec_passOR( **mu_itr ) = 0;
      }
    }
  }

  // loop over photons and electrons

  el_itr = baselineElectronsBeforeOR->begin();
  ph_itr = baselinePhotonsBeforeOR->begin();

  for( ; ph_itr != ph_end; ++ph_itr ) {
    
    if( !dec_passOR(**ph_itr) ) continue;
    
    for( ; el_itr != el_end; ++el_itr ) {
      
      if ( !dec_passOR( **el_itr ) ) continue;
      
      TLorentzVector ph4vec = (*ph_itr)->p4();
      TLorentzVector mu4vec = (*el_itr)->p4();
      
      if (ph4vec.DeltaR(mu4vec)<dReph) {
	  dec_passOR( **el_itr ) = 0;
      }
    }
  }

  
}


void TruthObjectDef::FillBaselineElectrons(){

  xAOD::TruthParticleContainer::iterator el_itr = baselineElectronsBeforeOR->begin();
  xAOD::TruthParticleContainer::iterator el_end = baselineElectronsBeforeOR->end();
  
  electronSF = 1;
  electronTriggerSF = 1;

  for( ; el_itr != el_end; ++el_itr ) {
    //if  (fabs((*el_itr)->eta()) < 2.47){
    
    if  ( (*el_itr)->auxdata< char >("passOR") && ( (*el_itr)->auxdata< char >("baseline") ) )
      baselineElectrons->push_back( *el_itr);
    
    if ( ( (*el_itr)->auxdata< char >("passOR") ) && ( (*el_itr)->auxdata< char >("signal") ) ) {
      goodElectrons->push_back( *el_itr);
      //electronSF = electronSF*objTool->GetSignalElecSF(**el_itr);
      
    }
    
  }
  baselineElectrons->sort(ptTruthSorter);
  goodElectrons->sort(ptTruthSorter);
}


void TruthObjectDef::FillBaselineTaus(){

  xAOD::TruthParticleContainer::iterator ta_itr = baselineTausBeforeOR->begin();
  xAOD::TruthParticleContainer::iterator ta_end = baselineTausBeforeOR->end();
  
  tauSF = 1;
  tauTriggerSF = 1;

  for( ; ta_itr != ta_end; ++ta_itr ) {
    //if  (fabs((*el_itr)->eta()) < 2.47){
    
    if  ( (*ta_itr)->auxdata< char >("passOR") && ( (*ta_itr)->auxdata< char >("baseline") ) )
      baselineTaus->push_back( *ta_itr);
    
    if ( ( (*ta_itr)->auxdata< char >("passOR") ) && ( (*ta_itr)->auxdata< char >("signal") ) ) {
      goodTaus->push_back( *ta_itr);
      //tauSF = tauSF*objTool->GetSignalElecSF(**el_itr);
      
    }
    
  }
  baselineTaus->sort(ptTruthSorter);
  goodTaus->sort(ptTruthSorter);
}



void TruthObjectDef::FillBaselinePhotons(){

  xAOD::TruthParticleContainer::iterator ph_itr = baselinePhotonsBeforeOR->begin();
  xAOD::TruthParticleContainer::iterator ph_end = baselinePhotonsBeforeOR->end();
  photonSF = 1;

  for( ; ph_itr != ph_end; ++ph_itr ) {
    if  ( (*ph_itr)->auxdata< char >("passOR") && ( (*ph_itr)->auxdata< char >("baseline") ) )
      baselinePhotons->push_back( *ph_itr);
    
    if ( ( (*ph_itr)->auxdata< char >("passOR") ) && ( (*ph_itr)->auxdata< char >("signal") ) ) {
      goodPhotons->push_back( *ph_itr);
      
    }
    
  }
  baselinePhotons->sort(ptTruthSorter);
  goodPhotons->sort(ptTruthSorter);
}




void TruthObjectDef::FillBaselineMuons(){
   
  xAOD::TruthParticleContainer::iterator mu_itr = baselineMuonsBeforeOR->begin();
  xAOD::TruthParticleContainer::iterator mu_end = baselineMuonsBeforeOR->end();
  
  muonSF = 1;
  oldMuonSF = 1;
  for( ; mu_itr != mu_end; ++mu_itr ) {
    if  ( ( (*mu_itr)->auxdata< char >("passOR") ) && !(*mu_itr)->auxdata< char >("cosmic") && ( (*mu_itr)->auxdata< char >("baseline") )  )
      baselineMuons->push_back( *mu_itr);
    if  ( ( (*mu_itr)->auxdata< char >("passOR") ) && (*mu_itr)->auxdata< char >("cosmic") && ( (*mu_itr)->auxdata< char >("baseline") )  )
      cosmicMuons->push_back( *mu_itr);
    if ( ( (*mu_itr)->auxdata< char >("passOR") ) && ( (*mu_itr)->auxdata< char >("signal") ==1 ) && (*mu_itr)->auxdata< char >("cosmic") ==0 ) {
      goodMuons->push_back( *mu_itr);
      //muonSF = muonSF*objTool->GetSignalMuonSF(**mu_itr);
    }
    
  }
  baselineMuons->sort(ptTruthSorter);
  cosmicMuons->sort(ptTruthSorter);
  goodMuons->sort(ptTruthSorter);
}


void TruthObjectDef::FillGoodJets(){

  //    xAOD::TruthParticleContainer::iterator jet_itr = goodJetsBeforeOR->begin();
  //   xAOD::TruthParticleContainer::iterator jet_end = goodJetsBeforeOR->end();
    
  xAOD::JetContainer::iterator jet_itr = goodJetsBeforeOR->begin();
  xAOD::JetContainer::iterator jet_end = goodJetsBeforeOR->end();



  int jet = 0;

  bJetSF = 1;

      
  
  for( ; jet_itr != jet_end; ++jet_itr ) {
    
    int flavour = -1;

    //    int brokenFlavour = -1;

    //    (*jet_itr)->getAttribute("ConeTruthLabelID",flavour);

    bool foundHadCone = false;
    if (!(*jet_itr)->getAttribute("HadronConeExclTruthLabelID",flavour)){
      //std::cout << "Failed to get HadronConeExclTruthLabelID Truth Label ID" << std::endl;
      foundHadCone = false;
    }
    
    if (   (*jet_itr)->pt() > 20000. && (*jet_itr)->auxdata< char >("bad") && (*jet_itr)->auxdata< char >("baseline")  )
      {
	badJets->push_back( *jet_itr);
      }
    
    else if( (*jet_itr)->auxdata< char >("baseline")==1  &&
	     (*jet_itr)->auxdata< char >("passOR")==1  &&
	     (*jet_itr)->pt() > 0.  && ( fabs( (*jet_itr)->eta()) < 2.8) )
      {
	goodJets->push_back( *jet_itr);
	
	
	flavour = -1;
	if (foundHadCone == false){
	(*jet_itr)->getAttribute("ConeTruthLabelID",flavour);
	}
	else {
	  (*jet_itr)->getAttribute("HadronConeExclTruthLabelID",flavour);
	}//std::cout << "jet flavour " << flavour << std::endl;
	
	int nTrk = -1;
	(*jet_itr)->getAttribute("NumTrkPt1000",nTrk);
	
	// "Mock" b-tagging:
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distribution(1,10001);
	double randomNumber = distribution(gen);
	double random = randomNumber/10001;

	//random = 0.6;
	// changed from 0.70, 0.20, 0.007

	if ( (fabs( (*jet_itr)->eta()) < 2.5)){
	  if (fabs(flavour) == 5){
	    if (random < 0.7725){
	      dec_bjet(**jet_itr) = true;
	    }
	  }
	  else if (fabs(flavour) == 4){
	    if (random < 0.221){
	      dec_bjet(**jet_itr) = true;
	    }
	  }
	  else if (fabs(flavour) == 0){
	    if (random < 0.00794){
	      dec_bjet(**jet_itr) = true;
	    }
	  }
	  
	}
	
	if ((*jet_itr)->auxdata< char >("bjet")){
	  BJets->push_back(*jet_itr);
	}
	else
	  nonBJets->push_back(*jet_itr);
	
      }
  }
    
  goodJets->sort(ptTruthSorter);
  BJets->sort(ptTruthSorter);
  nonBJets->sort(ptTruthSorter);
  
  //  bJetSF = objTool->BtagSF(BJets);
  bJetSF = 1;
  JVTSF = 1;
  
}


void TruthObjectDef::SetPrimVertex(){

  const xAOD::TruthVertexContainer* primVertex = 0;
  currentEvent->retrieve( primVertex, "TruthVertices" );
  //nVertex = primVertex->size();   
  nVertex = 1;
}


void TruthObjectDef::FillFatJets_kt8(){


  fatjet_kt8_tool->execute();
  currentEvent->retrieve( FatJets_kt8,"MyFatJetsKt8");


}


void TruthObjectDef::FillFatJets_kt12(){

  fatjet_kt12_tool->execute();
  currentEvent->retrieve( FatJets_kt12,"MyFatJetsKt12");


}

bool TruthObjectDef::SetUpFatJetTools(JetToolRunner *& tool, double jetradius, std::string inputcontainer, std::string outputcontainer){

  
  //double jetradius = 0.8; 
  xAOD::IParticleContainer* m_goodJets_recl; //!  
  //std::string inputcontainer = "GoodJets_recl";
  //std::string outputcontainer = "fatJets_kt8"+systName;
  tool = 0;
  //JetFatJet_Kt8_ToolRunner* m_jetRecTool_kt8; //!

  ToolHandleArray<IPseudoJetGetter> hgets;
  ToolHandleArray<IJetExecuteTool> hrecs;

  PseudoJetGetter* plcget = new PseudoJetGetter(("mylcget"+outputcontainer).c_str());
  plcget->setProperty("InputContainer", inputcontainer);
  plcget->setProperty("OutputContainer", "Reclustered"+outputcontainer);
  plcget->setProperty("Label", "Tower");
  plcget->setProperty("SkipNegativeEnergy", true);
  plcget->setProperty("GhostScale", 0.0);

  ToolHandle<IPseudoJetGetter> hlcget(plcget);
  hgets.push_back(hlcget);


  JetFromPseudojet* pbuild = new JetFromPseudojet(("myjetbuild"+outputcontainer).c_str());
  ToolHandle<IJetFromPseudojet> hbuild(pbuild);
  
  pbuild->initialize();
  
  JetFinder* pfind = new JetFinder(("myjetfind"+outputcontainer).c_str());
  pfind->setProperty("JetAlgorithm", "AntiKt");
  pfind->setProperty("JetRadius", jetradius);
  pfind->setProperty("PtMin", 15000.0);
  pfind->setProperty("GhostArea", 0.00);
  pfind->setProperty("RandomOption", 1);
  pfind->setProperty("JetBuilder", hbuild);
  ToolHandle<IJetFinder> hfind(pfind);
  //asg::ToolStore::put(pfind);
  pfind->initialize();
  


  JetRecTool* pjrf = new JetRecTool(("myjrfind"+outputcontainer).c_str());
  pjrf->setProperty("OutputContainer", outputcontainer);
  pjrf->setProperty("PseudoJetGetters", hgets);
  pjrf->setProperty("JetFinder", hfind);
  pjrf->initialize();
  ToolHandle<IJetExecuteTool> hjrf(pjrf);
  hrecs.push_back(pjrf);

 
  tool = new JetToolRunner(("jetrunner"+outputcontainer).c_str());
  tool->setProperty("Tools", hrecs);
  //  Info("Initialising JetReclusteringTool(s)");
  tool->initialize();
  tool->print();


  return true;
}

bool TruthObjectDef::removeFatJetTools(std::string systName){

    //Removing the FatJetTool that we have initialised for this event (to avoid replication)

    std::string FatJets8ToolName = "MyFatJetsKt8"+systName;
    std::cout<<"FatJets8ToolName = "<<FatJets8ToolName<<std::endl;
    std::string FatJets12ToolName = "MyFatJetsKt12"+systName;
    std::cout<<"FatJets12ToolName = "<<FatJets12ToolName<<std::endl;
    std::string FatJetsTool8 ="m_jetRecTool_kt8_"+systName; 
    std::cout<<"FatJetsTool8 = "<<FatJetsTool8<<std::endl;
    std::string FatJetsTool12 ="m_jetRecTool_kt12_"+systName; 
    std::cout<<"FatJetsTool12 = "<<FatJetsTool12<<std::endl;
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
    std::cout<<"Removed the tool plcget "<<std::endl;
    asg::ToolStore::remove(pbuild8);
    asg::ToolStore::remove(pbuild12);
    std::cout<<"Removed the tool pbuild "<<std::endl;
    asg::ToolStore::remove(pfind8);
    asg::ToolStore::remove(pfind12);
    std::cout<<"Removed the tool pfind "<<std::endl;
    asg::ToolStore::remove(pjrfind8);
    asg::ToolStore::remove(pjrfind12);
    std::cout<<"Removed the tool pjrfind "<<std::endl;
    asg::ToolStore::remove(pjrfind_retriever8);
    asg::ToolStore::remove(pjrfind_retriever12);
    std::cout<<"Removed the tool pjrfind "<<std::endl;
    asg::ToolStore::remove(prunner8);
    asg::ToolStore::remove(prunner12);
    std::cout<<"Removed the tool prunner "<<std::endl;
    asg::ToolStore::remove(FatJetsTool8);
    asg::ToolStore::remove(FatJetsTool12);
    std::cout<<"Removed the fatJets tools "<<std::endl;
    return true;
}
//Memory usage checking 
void TruthObjectDef::process_mem_usage(double& vm_usage, double& resident_set)
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

int TruthObjectDef::CheckMem()
{
  using std::cout;
  using std::endl;

  double vm, rss;
  process_mem_usage(vm, rss);
  cout << "VM: " << vm << "; RSS: " << rss << endl;
  return 1;
}
