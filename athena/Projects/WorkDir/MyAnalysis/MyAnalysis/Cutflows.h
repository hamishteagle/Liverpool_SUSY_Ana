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
	   std::vector<TH1F*> &HSRA,std::vector<TH1F*> &HSRB, std::vector<TH1F*> &HCRZ, std::vector<TH1F*> &HCRTemu, std::vector<TH1F*> &HCRT1L, std::vector<TH1F*> &HCRW, std::vector<TH1F*> &HCRsT, std::vector<TH1F*> &HCRgamma , double bWeight, double leptWeight, double trigWeight, double puWeight, double mcWgt, double evtNo, bool METTrig, bool LepTrig, bool GamTrig, double TruthMET);
  
  
  void SRACutflows( CalculateVariables variables, PreliminarySel region, std::vector<TH1F*> HSRA, double btagWeight, double lepWeight, double triggerWeight, double pileUpWeight, double mcWeight, double evtNo, bool TrigPass, double JVTWgt);
  void SRBCutflows( CalculateVariables variables, PreliminarySel region, std::vector<TH1F*> HSRB, double btagWeight, double lepWeight, double triggerWeight, double pileUpWeight, double mcWeight, double evtNo, bool TrigPass, double JVTWgt);
  void CRZCutflows( CalculateVariables variables, PreliminarySel region, std::vector<TH1F*> HCRZ, double btagWeight, double lepWeight, double triggerWeight, double pileUpWeight, double mcWeight, double evtNo , bool TrigPass, double JVTWgt);
  void CRTemuCutflows( CalculateVariables variables, PreliminarySel region, std::vector<TH1F*> HCRTemu, double btagWeight, double lepWeight, double triggerWeight, double pileUpWeight, double mcWeight, double evtNo, bool TrigPass, double JVTWgt);
  void CRT1LCutflows( CalculateVariables variables, PreliminarySel region, std::vector<TH1F*> HCRT1L, double btagWeight, double lepWeight, double triggerWeight, double pileUpWeight, double mcWeight, double evtNo, bool TrigPass, double METFilt, double JVTWgt);
  void CRWCutflows( CalculateVariables variables, PreliminarySel region, std::vector<TH1F*> HCRW, double btagWeight, double lepWeight, double triggerWeight, double pileUpWeight, double mcWeight, double evtNo, bool TrigPass, double JVTWgt);
  void CRsTCutflows( CalculateVariables variables, PreliminarySel region, std::vector<TH1F*> HCRsT, double btagWeight, double lepWeight, double triggerWeight, double pileUpWeight, double mcWeight, double evtNo, bool TrigPass, double JVTWgt);
  void CRgammaCutflows( CalculateVariables variables, PreliminarySel region, std::vector<TH1F*> HCRgamma, double btagWeight, double lepWeight, double triggerWeight, double pileUpWeight, double mcWeight, double evtNo, bool TrigPass, double JVTWgt);
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


};

#endif
