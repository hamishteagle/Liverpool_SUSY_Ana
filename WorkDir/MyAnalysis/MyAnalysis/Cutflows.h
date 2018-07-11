// header file for cutflows


#ifndef Cutflows_h
#define Cutflows_h



#include <iostream>
#include "PreliminarySel.h"
#include "CalculateVariables.h"
#include <string>
#include <TH1.h>
#include <vector>
#include <functional>

class Cutflows
{
 public:
  
  Cutflows();


  Cutflows(CalculateVariables &variables, PreliminarySel &region,
	   std::vector<TH1F*> &HSRA,std::vector<TH1F*> &HSRB, std::vector<TH1F*> &HSRC , double bWeight, double leptWeight, double trigWeight, double puWeight, double mcWgt, double evtNo, bool METTrig, bool LepTrig, bool GamTrig, double TruthMET);
  
  
  void SRACutflows( CalculateVariables variables, PreliminarySel region, std::vector<TH1F*> HSRA, double btagWeight, double lepWeight, double triggerWeight, double pileUpWeight, double mcWeight, double evtNo, bool TrigPass, double JVTWgt);
  void SRBCutflows( CalculateVariables variables, PreliminarySel region, std::vector<TH1F*> HSRB, double btagWeight, double lepWeight, double triggerWeight, double pileUpWeight, double mcWeight, double evtNo, bool TrigPass, double JVTWgt);
  void SRCCutflows( CalculateVariables variables, PreliminarySel region, std::vector<TH1F*> HSRC, double btagWeight, double lepWeight, double triggerWeight, double pileUpWeight, double mcWeight, double evtNo , bool TrigPass, double JVTWgt);
 void DebugMode(std::string whichThread,  CalculateVariables variables, PreliminarySel region, double evtNo);

  int EventNumber;
  double btagWeight;
  double lepWeight;
  double triggerWeight;
  double pileUpWeight;
  double mcWeight;
  bool METTriggerPassed;
  bool LepTriggerPassed;
  bool gammaTriggerPassed;
  double METFilt;
  double JVTWgt;
  double electronWgt;
  double muonWgt;
  double electronTrigWgt;

};

#endif
