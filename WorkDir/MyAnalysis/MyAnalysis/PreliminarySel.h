// Initial Selections go here

#ifndef PreliminarySel_h
#define PreliminarySel_h


#include "CalculateVariables.h"
#include <iostream>
#include <string>
class PreliminarySel


{


 public:
  PreliminarySel(NewObjectDef *objects, xAOD::TStore* evtStore, std::string systematic);

  bool whichPreliminaryRegion(NewObjectDef *objects, xAOD::TStore* evtStore, std::string systematic);


 public:

  std::string region;
  bool interestingRegion;
  xAOD::MuonContainer *goodMuon_cont = nullptr;
  xAOD::ElectronContainer *goodElectron_cont = nullptr;
  xAOD::JetContainer *goodJet_cont = nullptr;
  xAOD::JetContainer *bJet_cont = nullptr;

};
#endif
