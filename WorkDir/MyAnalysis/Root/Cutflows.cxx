// source code for cutflows. Use threading for concurent processing of regions.

#include "MyAnalysis/Cutflows.h"
#include <math.h>
#include <iostream>
#include <TVector2.h>
#include <TLorentzVector.h>
#include <string>
#include <thread>


Cutflows::Cutflows(){
  // empty constructor

}

Cutflows::Cutflows( CalculateVariables &variables, PreliminarySel &region, std::vector<TH1F*> &HSRA,std::vector<TH1F*> &HSRB, std::vector<TH1F*> &HSRC, double bWeight, double leptWeight, double trigWeight, double puWeight, double mcWgt, double evtNo, bool METTrig, bool LepTrig, bool GamTrig, double TruthMET){

  btagWeight = bWeight;
  lepWeight = leptWeight;
  //triggerWeight = variables.electronTrigSF;
  triggerWeight = 1;
  pileUpWeight = puWeight;
  mcWeight = mcWgt;
  JVTWgt = variables.JVTSF;
  electronWgt = variables.electronSF;
  muonWgt = variables.muonSF;
  electronTrigWgt = variables.electronTrigSF;
  


  EventNumber = evtNo;
  METTriggerPassed = METTrig;
  LepTriggerPassed = LepTrig;
  gammaTriggerPassed = LepTrig;
  METFilt = TruthMET;

  // empty constructor to use the cutflow functions and stuff

  Cutflows C;

  std::thread SRA(&Cutflows::SRACutflows, &C , variables, region, HSRA, btagWeight, lepWeight, triggerWeight, pileUpWeight, mcWeight, EventNumber, METTriggerPassed, JVTWgt);
  std::thread SRB(&Cutflows::SRBCutflows, &C , variables, region, HSRB, btagWeight, lepWeight, triggerWeight, pileUpWeight, mcWeight, EventNumber, METTriggerPassed, JVTWgt);
  std::thread SRC(&Cutflows::SRCCutflows, &C, variables, region, HSRC, btagWeight, lepWeight, triggerWeight, pileUpWeight, mcWeight, EventNumber, METTriggerPassed, JVTWgt);


  SRA.join();
  SRB.join();
  SRC.join();

}


void Cutflows::SRACutflows( CalculateVariables variables, PreliminarySel region,std::vector<TH1F*> HSRA, double btagWeight, double lepWeight, double triggerWeight, double pileUpWeight, double mcWeight, double evtNo , bool TrigPass, double JVTWgt){

  // will have already filled the first 7 bins of every histogram by the point we're here anyway
  // so fill from number 5
  // the [0] element is raw number, the [1] is with mcWgt, the [2] is with btag trigger et al.

  // SRA Variable class will only be filled after:
  // ( (nJets == 2 && region.pTj1 > 50 && region.pTj2 > 50 && region.delPhi1 > 0.4 && region.delPhi2 > 0.4) || (nJets == 3 && region.pTj1 > 50 && region.pTj2 > 50 && region.delPhi1 > 0.4 && region.delPhi2 > 0.4 && region.delPhi3 > 0.4)) && (nLepton == 0) && (eTMiss > 150) && (ratioMetmEff > 0.25) && (nbJets ==2) && (leadingBs)
  
  if (TrigPass == false){
    return;
  }

  int internalCut = 9;

  if (variables.eTMiss > 250 ){
    (HSRA)[0]->Fill(internalCut, 1);
    (HSRA)[1]->Fill(internalCut, mcWeight);
    (HSRA)[2]->Fill(internalCut, mcWeight*btagWeight*lepWeight*triggerWeight*pileUpWeight*JVTWgt);
    internalCut++;
  }
  else {
    return;
  }

   if (variables.nBaselineLepton==0){
    (HSRA)[0]->Fill(internalCut, 1);
    (HSRA)[1]->Fill(internalCut, mcWeight);
    (HSRA)[2]->Fill(internalCut, mcWeight*btagWeight*lepWeight*triggerWeight*pileUpWeight*JVTWgt);
    internalCut++;    
    
  }
  else {
    return;
  }

  if (variables.nJets>=6){
    lepWeight = variables.leptonSF;
    (HSRA)[0]->Fill(internalCut, 1);
    (HSRA)[1]->Fill(internalCut, mcWeight);
    (HSRA)[2]->Fill(internalCut,mcWeight*btagWeight*lepWeight*triggerWeight*pileUpWeight*JVTWgt);
    internalCut++;
  }
  else {
    return;
  }

  if (variables.nbJets>=4){

    (HSRA)[0]->Fill(internalCut, 1);
    (HSRA)[1]->Fill(internalCut, mcWeight);
    (HSRA)[2]->Fill(internalCut, mcWeight*btagWeight*lepWeight*triggerWeight*pileUpWeight*JVTWgt);
    internalCut++;

  }
  else {
    return;
  }

  if (variables.minDelPhi_4 > 0.4){

    btagWeight = variables.bJetSF;

    (HSRA)[0]->Fill(internalCut, 1);
    (HSRA)[1]->Fill(internalCut, mcWeight);
    (HSRA)[2]->Fill(internalCut, mcWeight*btagWeight*lepWeight*triggerWeight*pileUpWeight*JVTWgt);
    internalCut++;
  }
  else {
    return;
  }

  if (variables.Stop0L_tauVeto==true){
    (HSRA)[0]->Fill(internalCut, 1);
    (HSRA)[1]->Fill(internalCut, mcWeight);
    (HSRA)[2]->Fill(internalCut, mcWeight*btagWeight*lepWeight*triggerWeight*pileUpWeight*JVTWgt);
    internalCut++;
  }
  else {
    return;
  }

  if (variables.maxDR>2.5){
    (HSRA)[0]->Fill(internalCut, 1);
    (HSRA)[1]->Fill(internalCut, mcWeight);
    (HSRA)[2]->Fill(internalCut, mcWeight*btagWeight*(variables.electronSF)*(variables.electronTrigSF));//*pileUpWeight*triggerWeight*
    internalCut++;
  }
  else {
    return;
  }

  if (variables.minDR<2.5){
    (HSRA)[0]->Fill(internalCut, 1);
    (HSRA)[1]->Fill(internalCut, mcWeight);
    (HSRA)[2]->Fill(internalCut, mcWeight*btagWeight*(variables.electronSF)*(variables.electronTrigSF)*(variables.muonSF));//*pileUpWeight*triggerWeight*
    internalCut++;
  }
  else {
    return;
  }
  
  if (variables.InvMass_Bij_minR>80){
    (HSRA)[0]->Fill(internalCut, 1);
    (HSRA)[1]->Fill(internalCut, mcWeight);
    (HSRA)[2]->Fill(internalCut, mcWeight*btagWeight*triggerWeight*(variables.electronSF)*(variables.electronTrigSF)*(variables.muonSF)*JVTWgt);
    internalCut++;
  }
  else {
    return;
  }

  if (variables.pTb1>200){
    (HSRA)[0]->Fill(internalCut, 1);
    (HSRA)[1]->Fill(internalCut, mcWeight);
    (HSRA)[2]->Fill(internalCut, mcWeight*btagWeight*triggerWeight*(variables.electronSF)*(variables.electronTrigSF)*(variables.muonSF)*pileUpWeight*JVTWgt);
    internalCut++;
  }
  else {
    return;
  }

  if (variables.all_Meff > 1000){
    (HSRA)[0]->Fill(internalCut, 1);
    (HSRA)[1]->Fill(internalCut, mcWeight);
    (HSRA)[2]->Fill(internalCut, mcWeight*btagWeight*lepWeight*triggerWeight*pileUpWeight*JVTWgt);
    internalCut++;
  }
  else {
    return;
  }
  
  if ((variables.all_Meff>1000) && (1200>=variables.all_Meff)){
    (HSRA)[0]->Fill(internalCut,1);
    (HSRA)[1]->Fill(internalCut, mcWeight);
    (HSRA)[2]->Fill(internalCut, mcWeight*btagWeight*lepWeight*triggerWeight*pileUpWeight*JVTWgt);
    internalCut++;
  }
  else {
    return;
  }

  if ((variables.all_Meff>1200) &&(1500>=variables.all_Meff)){
    (HSRA)[0]->Fill(internalCut, 1);
    (HSRA)[1]->Fill(internalCut, mcWeight);
    (HSRA)[2]->Fill(internalCut, mcWeight*btagWeight*lepWeight*triggerWeight*pileUpWeight*JVTWgt);

    internalCut++;
  }
  else {
    return;
  }

  if (variables.all_Meff>1500){
    (HSRA)[0]->Fill(internalCut, 1);
    (HSRA)[1]->Fill(internalCut, mcWeight);
    (HSRA)[2]->Fill(internalCut, mcWeight*btagWeight*lepWeight*triggerWeight*pileUpWeight*JVTWgt);
    internalCut++;
  }
  else {
    return;
  }

}

void Cutflows::SRBCutflows( CalculateVariables variables, PreliminarySel region,std::vector<TH1F*> HSRB, double btagWeight, double lepWeight, double triggerWeight, double pileUpWeight, double mcWeight, double evtNo , bool TrigPass, double JVTWgt){

  // will have already filled the first 7 bins of every histogram by the point we're here anyway
  // so fill from number 5
  // the [0] element is raw number, the [1] is with mcWgt, the [2] is with btag trigger et al.

  // SRB Variable class will only be filled after:
  // ( (nJets == 2 && region.pTj1 > 50 && region.pTj2 > 50 && region.delPhi1 > 0.4 && region.delPhi2 > 0.4) || (nJets == 3 && region.pTj1 > 50 && region.pTj2 > 50 && region.delPhi1 > 0.4 && region.delPhi2 > 0.4 && region.delPhi3 > 0.4)) && (nLepton == 0) && (eTMiss > 150) && (ratioMetmEff > 0.25) && (nbJets ==2) && (leadingBs)
  
  if (TrigPass == false){
    return;
  }

  int internalCut = 9;

  //DebugMode("SRinA",variables ,region, evtNo);

  if (variables.eTMiss>300){
    
    lepWeight = variables.leptonSF;
    
    (HSRB)[0]->Fill(internalCut, 0.46754945);//Change back to 1 
    (HSRB)[1]->Fill(internalCut, mcWeight);
    (HSRB)[2]->Fill(internalCut, 78.9*mcWeight*btagWeight*lepWeight*triggerWeight*pileUpWeight*JVTWgt);
    internalCut++;
  }
  else {
    return;
  }

  if (variables.nBaselineLepton == 0){

    (HSRB)[0]->Fill(internalCut, 0.46754945);//Change back to 1 
    (HSRB)[1]->Fill(internalCut, mcWeight);
    (HSRB)[2]->Fill(internalCut, 78.9*mcWeight*btagWeight*lepWeight*triggerWeight*pileUpWeight*JVTWgt);
    internalCut++;
  }
  else {
    return;
  }
  
  
  if (variables.nJets>=4){
    (HSRB)[0]->Fill(internalCut, 0.46754945);//Change back to 1 
    (HSRB)[1]->Fill(internalCut, mcWeight);
    (HSRB)[2]->Fill(internalCut, 78.9*mcWeight*btagWeight*lepWeight*triggerWeight*pileUpWeight*JVTWgt);
    internalCut++;
  }
  else {
    return;
  }

  if (variables.nbJets >=4){
    (HSRB)[0]->Fill(internalCut, 0.46754945);//Change back to 1 
    (HSRB)[1]->Fill(internalCut, mcWeight);
    (HSRB)[2]->Fill(internalCut, 78.9*mcWeight*btagWeight*lepWeight*triggerWeight*pileUpWeight*JVTWgt);
    internalCut++;    
    
  }
  else {
    return;
  }
  if (variables.SRB_Hmbb>50 && variables.SRB_Hmbb<140){
    (HSRB)[0]->Fill(internalCut, 0.46754945);//Change back to 1 
    (HSRB)[1]->Fill(internalCut, mcWeight);
    (HSRB)[2]->Fill(internalCut, 78.9*mcWeight*btagWeight*lepWeight*triggerWeight*pileUpWeight*JVTWgt);
    internalCut++;
  }
  else {
    return;
  }
  
  
  if (variables.pTj1 != variables.pTb1){
    (HSRB)[0]->Fill(internalCut, 0.46754945);//Change back to 1 
    (HSRB)[1]->Fill(internalCut, mcWeight);
    (HSRB)[2]->Fill(internalCut, 78.9*mcWeight*btagWeight*lepWeight*triggerWeight*pileUpWeight*JVTWgt);
    internalCut++;
  }
  else {
    return;
  }


  if (variables.pTj1 > 300){
    (HSRB)[0]->Fill(internalCut, 0.46754945);//Change back to 1 
    (HSRB)[1]->Fill(internalCut, mcWeight);
    (HSRB)[2]->Fill(internalCut, 78.9*mcWeight*btagWeight*lepWeight*triggerWeight*pileUpWeight*JVTWgt);
    internalCut++;
  }
  else {
    return;
  }

  if (variables.all_Meff>=1000){
    (HSRB)[0]->Fill(internalCut, 0.46754945);//Change back to 1 
    (HSRB)[1]->Fill(internalCut, mcWeight);
    (HSRB)[2]->Fill(internalCut, 78.9*mcWeight*btagWeight*lepWeight*triggerWeight*pileUpWeight*JVTWgt);
    internalCut++;
  }
  else {
    return;
  }

  
  if (variables.Stop0L_tauVeto==true){

    (HSRB)[0]->Fill(internalCut, 0.46754945);//Change back to 1 
    (HSRB)[1]->Fill(internalCut, mcWeight);
    (HSRB)[2]->Fill(internalCut, 78.9*mcWeight*btagWeight*lepWeight*triggerWeight*pileUpWeight*JVTWgt);
    internalCut++;
  }
  else {
    return;
  }
  if (variables.minDelPhi_4>0.4){
    (HSRB)[0]->Fill(internalCut, 0.46754945);//Change back to 1 
    (HSRB)[1]->Fill(internalCut, mcWeight);
    (HSRB)[2]->Fill(internalCut, 78.9*mcWeight*btagWeight*lepWeight*triggerWeight*pileUpWeight*JVTWgt);
    internalCut++;
  }
  else {
    return;
  }



  if (variables.delPhi1>2.8){
    (HSRB)[0]->Fill(internalCut, 0.46754945);//Change back to 1 
    (HSRB)[1]->Fill(internalCut, mcWeight);
    (HSRB)[2]->Fill(internalCut, 78.9*mcWeight*btagWeight*lepWeight*triggerWeight*pileUpWeight*JVTWgt);
    internalCut++;
  }
  else {
    return;
  }




}
void Cutflows::SRCCutflows( CalculateVariables variables, PreliminarySel region, std::vector<TH1F*> HSRC, double btagWeight, double lepWeight, double triggerWeight, double pileUpWeight, double mcWeight, double evtNo, bool TrigPass, double JVTWgt){


  if (TrigPass == false){
    return;
  }

  //pileUpWeight = 1;
  int internalCut = 9;

  if (variables.eTMiss > 250){
    (HSRC)[0]->Fill(internalCut, 1);
    (HSRC)[1]->Fill(internalCut, mcWeight);
    (HSRC)[2]->Fill(internalCut, mcWeight*btagWeight*lepWeight*triggerWeight*JVTWgt*pileUpWeight);
    internalCut++;
  }
  else {
    return;
  }

  if (variables.nbJets >= 2){
    (HSRC)[0]->Fill(internalCut, 1);
    (HSRC)[1]->Fill(internalCut, mcWeight);
    (HSRC)[2]->Fill(internalCut, 79.8*mcWeight*btagWeight*lepWeight*triggerWeight*pileUpWeight*JVTWgt);
    internalCut++;
  }
  else {
    return;
  }


  if (variables.nJets >= 4){
    (HSRC)[0]->Fill(internalCut, 1);
    (HSRC)[1]->Fill(internalCut, mcWeight);
    (HSRC)[2]->Fill(internalCut, mcWeight*btagWeight*lepWeight*triggerWeight*pileUpWeight*JVTWgt);
    internalCut++;
  }
  else {
    return;
  }

  if (variables.nBaselineLepton==0 ){
    (HSRC)[0]->Fill(internalCut, 1);
    (HSRC)[1]->Fill(internalCut, mcWeight);
    (HSRC)[2]->Fill(internalCut, mcWeight*btagWeight*lepWeight*triggerWeight*pileUpWeight*JVTWgt);
    internalCut++;
  }
  else {
    return;
  }

  if (variables.minDelPhi_4 > 0.4){
    (HSRC)[0]->Fill(internalCut, 1);
    (HSRC)[1]->Fill(internalCut, mcWeight);
    (HSRC)[2]->Fill(internalCut, 79.8*mcWeight*btagWeight*lepWeight*triggerWeight*pileUpWeight*JVTWgt);
    internalCut++;
  }
  else {
    return;
  }

  if (variables.all_METSig > 25){
    (HSRC)[0]->Fill(internalCut, 1);
    (HSRC)[1]->Fill(internalCut, mcWeight);
    (HSRC)[2]->Fill(internalCut, 79.8*mcWeight*btagWeight*lepWeight*triggerWeight*pileUpWeight*JVTWgt);
    internalCut++;
  }
  else {
    return;
  }

  if (variables.all_METSig > 27){
    (HSRC)[0]->Fill(internalCut, 1);
    (HSRC)[1]->Fill(internalCut, mcWeight);
    (HSRC)[2]->Fill(internalCut, 79.8*mcWeight*btagWeight*lepWeight*triggerWeight*pileUpWeight*JVTWgt);
    internalCut++;
  }
  else {
    return;
  }

  if (variables.all_METSig > 30){
    (HSRC)[0]->Fill(internalCut, 1);
    (HSRC)[1]->Fill(internalCut, mcWeight);
    (HSRC)[2]->Fill(internalCut, 79.8*mcWeight*btagWeight*lepWeight*triggerWeight*pileUpWeight*JVTWgt);
    internalCut++;
  }
  else {
    return;
  }

  // if (variables.adjMinDelPhi>0.4){
  //   (HSRC)[0]->Fill(internalCut, 1);
  //   (HSRC)[1]->Fill(internalCut, mcWeight);
  //   (HSRC)[2]->Fill(internalCut, 79.8*mcWeight*btagWeight*lepWeight*triggerWeight*pileUpWeight*JVTWgt);
  //   internalCut++;
  // }
  // else {
  //   return;
  // }

  if (variables.all_METSig > 32){
    (HSRC)[0]->Fill(internalCut, 1);
    (HSRC)[1]->Fill(internalCut, mcWeight);
    (HSRC)[2]->Fill(internalCut, 79.8*mcWeight*btagWeight*lepWeight*triggerWeight*pileUpWeight*JVTWgt);
    internalCut++;
  }
  else {
    return;
  }



  if (variables.eTMiss>0){
    
    btagWeight = variables.bJetSF;

    (HSRC)[0]->Fill(internalCut, 1);
    (HSRC)[1]->Fill(internalCut, mcWeight);
    (HSRC)[2]->Fill(internalCut, 79.8*mcWeight*btagWeight*lepWeight*triggerWeight*pileUpWeight*JVTWgt);
    internalCut++;
  }
  else {
    return;
  }

  if (variables.eTMiss>0){
    (HSRC)[0]->Fill(internalCut, 1);
    (HSRC)[1]->Fill(internalCut, mcWeight);
    (HSRC)[2]->Fill(internalCut, 79.8*mcWeight*btagWeight*lepWeight*triggerWeight*pileUpWeight*JVTWgt);
    internalCut++;
  }
  else {
    return;
  }


  if (variables.eTMiss>0){
    (HSRC)[0]->Fill(internalCut, 1);
    (HSRC)[1]->Fill(internalCut, mcWeight);
    (HSRC)[2]->Fill(internalCut, 79.8*mcWeight*btagWeight*lepWeight*triggerWeight*pileUpWeight*JVTWgt);
    internalCut++;
  }
  else {
    return;
  }


  if (variables.eTMiss >0){
    (HSRC)[0]->Fill(internalCut, 1);
    (HSRC)[1]->Fill(internalCut, mcWeight);
    (HSRC)[2]->Fill(internalCut, 79.8*mcWeight*btagWeight*lepWeight*triggerWeight*pileUpWeight*JVTWgt);
    internalCut++;
  }
  else {
    return;
  }


  if (variables.eTMiss>0){
    (HSRC)[0]->Fill(internalCut, 1);
    (HSRC)[1]->Fill(internalCut, mcWeight);
    (HSRC)[2]->Fill(internalCut, 79.8*mcWeight*btagWeight*lepWeight*triggerWeight*pileUpWeight*JVTWgt);
    internalCut++;
  }
  else {
    return;
  }
  return;
}



void Cutflows::DebugMode(std::string whichThread,  CalculateVariables variables, PreliminarySel region, double evtNo){
  // kind of depends what you want to print out here so change it to whatever
  std::cout.precision(10);
  std::cout << evtNo << " " << variables.nJets << " " << variables.nPhoton << " " << variables.nElectron << " " << variables.nMuon << " " << variables.eTMiss << " " << variables.pTj1 << " " << variables.pTl1 <<std::endl;
 
  // usage:
  // DebugMode("Which Active Thread?", objects, variables, region, evtNo);
  // before the return statement when you fail a cut/depending on what you're wanting to do with it
    
  

}
