#include "MyAnalysis/PreliminarySel.h"
#include <math.h>
#include <iostream>
#include <string>




PreliminarySel::PreliminarySel(CalculateVariables &variables, bool &passCleaningCuts){

  interestingRegion = this->whichPreliminaryRegion(variables, passCleaningCuts);

}


bool PreliminarySel::whichPreliminaryRegion(CalculateVariables &variables, bool &passedCleaningCuts){

  bool passesPresel = false;

  if (variables.nJets>=2 && variables.nbJets >=1 && variables.nLepton ==1 && passedCleaningCuts){
    region = "Preselection";
    return true;
  }
  return false;
}
