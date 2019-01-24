// Header file for MCChecks Class. MCChecks class checks properties belonging to the MC that we are dealing with. Such as the SherpaWOR pT removal for overlapping samples, and also the cross section from SUSYTools

#ifndef MCChecks_h
#define MCChecks_h


#include "SUSYTools/SUSYObjDef_xAOD.h"
#include "xAODEventInfo/EventInfo.h"
#include "xAODTruth/TruthParticleContainer.h"

#include <iostream>
#include <string>

class MCChecks


{
 public:
  MCChecks();

  bool RetrieveWeights(asg::SgTEvent* event);
  bool SherpaWOR(asg::SgTEvent* event, double ptThreshold);
  bool VariableForDuplicates(asg::SgTEvent* event);
  bool DiBosonOR(asg::SgTEvent* event);
  bool SherpaUncertaintyWeights(asg::SgTEvent* event);
  bool TruthTaus(asg::SgTEvent* event);


  double OverlappingMETSlices(asg::SgTEvent* event);

  bool ZpT(asg::SgTEvent* event);
  bool SherpaZpT(asg::SgTEvent* event);
  bool ttbarpT(asg::SgTEvent* event);
  int HeavyFlavourFilter_countJets(asg::SgTEvent* event, bool doPrompt);

  bool ttbar_decay(asg::SgTEvent* event);


  int jetFilterno_prompt;
  int jetFilterno;
  double pTZBoson;
  double phiZBoson;
  double etaZBoson;
  double pTZBoson_Sherpa;
  double phiZBoson_Sherpa;
  double etaZBoson_Sherpa;
  bool Zqq;
  bool Zll;
  double arbitraryDuplicateCheck;
  double truthFilterMET;

  double pTt1;
  double phit1;
  double etat1;

  double pTt2;
  double phit2;
  double etat2;

  double pTttbar;
  double phittbar;
  double etattbar;

  int ttbar_W1_decay;
  int ttbar_tau1_decay;

  int ttbar_W2_decay;
  int ttbar_tau2_decay;

  double tau_1_prongs;
  double tau_2_prongs;

  TLorentzVector tau_1;
  TLorentzVector tau_2;

  std::vector<TLorentzVector> TruthTau;
  std::vector<float> variationweights;

  double Weight;
  double MEWeight;
  double WeightNormalisation;
  double NTrials;
  double MUR0p5_MUF0p5_PDF261000;
  double MUR0p5_MUF1_PDF261000;
  double MUR1_MUF0p5_PDF261000;
  double MUR1_MUF1_PDF261000;
  double MUR1_MUF2_PDF261000;
  double MUR2_MUF1_PDF261000;
  double MUR2_MUF2_PDF261000;
  double MUR1_MUF1_PDF261001;
  double MUR1_MUF1_PDF261002;

  std::vector<int> m_jet_trueflav; //jet flavor coming from association to hadrons
  std::vector<int> m_jet_count; //number of matched hadrons
  std::vector<int> m_jet_id; // origin of hadron matched to the jet
  std::vector<int> m_jet_TruthID; // different hadCone method for getting jet PT
  std::vector<float> m_jet_pt; //internal use
  std::vector<float> m_jet_eta; //internal use
  std::vector<float> m_jet_phi; //internal use
  std::vector<float> m_jet_m; //internal use
  ///MAPS JUST FOR HF DEDICATED STUDIES///
  std::map<int, int> m_FinalHadrons; //map hadron, origin
  std::map<int, int> m_HadronJets; //map hadron, jet



};
#endif
