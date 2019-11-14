#include "MyAnalysis/PreliminarySel.h"
#include <math.h>
#include <iostream>
#include <string>




PreliminarySel::PreliminarySel(NewObjectDef *objects, xAOD::TStore* evtStore, std::string systematic){

  interestingRegion = this->whichPreliminaryRegion(objects, evtStore, systematic);

}


bool PreliminarySel::whichPreliminaryRegion(NewObjectDef *objects, xAOD::TStore* evtStore, std::string systematic){

  evtStore->retrieve(goodMuon_cont, "goodMuons"+systematic);
  evtStore->retrieve(goodElectron_cont, "goodElectrons"+systematic);
  evtStore->retrieve(goodJet_cont, "goodJets"+systematic);
  evtStore->retrieve(bJet_cont, "BJets"+systematic);
  bool passesPresel = false;
  if (bJet_cont->size()==2){
  TLorentzVector b1v = (*bJet_cont)[0]->p4()*0.001;
  TLorentzVector b2v = (*bJet_cont)[1]->p4()*0.001;
  double m_bb = (b1v+b2v).M();

  if (((goodElectron_cont->size())+(goodMuon_cont->size())) ==1 && (objects->getMET()*0.001)>50 && goodJet_cont->size()<4 && objects->getMETsig()>5 && m_bb> 50 && m_bb<200){
    region = "Preselection";
    return true;
  }
}
  return false;
}
