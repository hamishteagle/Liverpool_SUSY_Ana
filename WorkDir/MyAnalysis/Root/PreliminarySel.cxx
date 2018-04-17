#include "MyAnalysis/PreliminarySel.h"
#include <math.h>
#include <iostream>
#include <string>




PreliminarySel::PreliminarySel(CalculateVariables &variables){

  interestingRegion = this->whichPreliminaryRegion(variables);
 
}


bool PreliminarySel::whichPreliminaryRegion(CalculateVariables &variables){
  
  bool passesPresel = false;


  if (variables.nJets >= 3 && ( (variables.nLepton == 0 && variables.eTMiss > 250) || (variables.nLepton >= 1 && variables.pTl1 > 26) || (variables.nTau >= 1 && variables.inMultiJetTriggerPlateau) || (variables.nTau >= 1 && variables.eTMiss > 250)) && variables.nbJets >= 3 )
    {
      passesPresel = true;
    }


  if (!passesPresel){
    return false;
  }

  if ( variables.nBaselineLepton == 0 && variables.leadingBs == true && variables.pTj1 > 130 && variables.eTMiss > 250 && variables.m_CT > 350 && (variables.nJets == 2 || variables.nJets == 3 || variables.nJets == 4)){
    region = "SRA";
    return true;
  }
  
  region = "Preselection";
  return true;
  
}

