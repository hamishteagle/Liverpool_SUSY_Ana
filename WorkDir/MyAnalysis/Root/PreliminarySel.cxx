#include "MyAnalysis/PreliminarySel.h"
#include <math.h>
#include <iostream>
#include <string>




PreliminarySel::PreliminarySel(CalculateVariables &variables){

  interestingRegion = this->whichPreliminaryRegion(variables);
 
}


bool PreliminarySel::whichPreliminaryRegion(CalculateVariables &variables){
  
  bool passesPresel = false;

  if (variables.nbJets >=1 && variables.nLepton >0 && variables.eTMiss>100){
    region = "Preselection";
    return true;
  }
  return false;
}
