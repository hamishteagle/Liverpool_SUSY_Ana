#ifndef MyAnalysis_MyxAODAnalysis_H
#define MyAnalysis_MyxAODAnalysis_H

#include <EventLoop/Algorithm.h>
#include "xAODRootAccess/Init.h"
#include "xAODRootAccess/TEvent.h"
//#include "PATInterfaces/SystematicRegistry.h"
#include "MyAnalysis/TreeService.h"
#include <TH1.h>
#include <TTree.h>
#include <map>
#include <utility>
#include <time.h>       /* time */

#include <EventLoopAlgs/NTupleSvc.h>
#include <EventLoopAlgs/AlgSelect.h>

#include "SUSYTools/SUSYObjDef_xAOD.h"
#include "SUSYTools/SUSYCrossSection.h"

#include "PileupReweighting/PileupReweightingTool.h"
#include "AsgTools/ToolHandle.h"

// Added for new METSig
#include "METUtilities/METSignificance.h" 

// GRL inclusion
class GoodRunsListSelectionTool; 
//class JetCleaningTool;
//class JERTool;



namespace CP{
//  class MuonCalibrationAndSmearingTool; // MuonSmearing
class PileupReweightingTool;
}

namespace ST{
  class SUSYObjDef_xAOD; // SUSYToolsObjectDefinition forward declaration
  //class CrossSectionDB; // SUSYToolsCrossSectionDataBase forward declaration
}

namespace SUSY{
  class CrossSectionDB; // Forward Declaration of Cross Section Database
}


//class ObjectDef;
//class TreeService;


class MyxAODAnalysis : public EL::Algorithm
{
#ifndef __CINT__
  ST::SUSYObjDef_xAOD *objTool; //! 
#endif // not __CINT__
  
#ifndef __CINT__
  SUSY::CrossSectionDB *xSectDataBase; //!
#endif // not __CINT__



  //
  //#ifndef __CINT__
  //CP::MuonCalibrationAndSmearingTool *m_muonCalibrationAndSmearingTool; //!
  //#endif // not__CINT__

#ifndef __CINT__
  GoodRunsListSelectionTool *m_grl; //!
  CP::PileupReweightingTool *pu_tool; //!
  JetToolRunner* m_jetRecTool_kt12; //!
  JetToolRunner* m_jetRecTool_kt8; //!

#endif // not__CINT__

  //#ifndef __CINT__
  //JERTool *m_JERTool; //!
  //#endif // not__CINT__

  //#ifndef __CINT__
  //JetCleaningTool *m_jetCleaning; //!
  //#endif // not__CINT__

  // put your configuration variables here as public variables.
  // that way they can be set directly from CINT and python.
public:
  // float cutValue;

  xAOD::TEvent *m_event; //!


  TTree *MetaData; //!
  bool m_isDerivation; //!
  

  int m_eventCounter; //!
  int m_numCleanEvents; //!
  int m_numElectronEvents; //!
  int m_numMuonEvents; //!

  double PUSumOfWeights; //!
  
  int m_runNumber; //!
  int m_lumiBlockNumber; //!

  std::string m_fileType;
  std::string m_fileName;
  double m_fileLumi;
  bool isData;//!
  bool isAtlfast;//!
  bool is25ns; //!
  bool isSignal; //!

  int isyst; //!
  int m_totalEvents; //!

  double m_lumiScaled; //!

  std::unordered_map<int, double> *eventNumberMap; //!

  std::vector<ST::SystInfo> systInfoList; //!

  
  std::vector<CP::SystematicSet> m_sysList; //!
  //TH1 *h_jetPt; //!
  TH1 *h_cuts; //!
  std::vector <std::string> cutList; //!
  std::vector <std::string> runningOverSysts; //!
  asg::AnaToolHandle<IMETSignificance> m_metSignif; //!

  //  EL::OutputStream out



  // Put our new containers here
  // variables that don't get filled at submission time should be
  // protected from being send from the submission node to the worker
  // node (done by the //!)
 public:
  // Tree *myTree; //!

  TH1 *noWeightHist; //!
  TH1 *sherpaWeightHist; //!
  TH1 *h_SumOfWeights; //!
  TH1 *h_SumOfWeightsSquared; //!

  TH1 *renormedSherpaWeightHist; //!

  // Make the Histos for the full cutflows here then:
  
  TH1F *HSRA_noWgt; //!
  TH1F *HSRA_mcWgt; //!
  TH1F *HSRA_allWgt; //!

  TH1F *HSRB_noWgt; //!
  TH1F *HSRB_mcWgt; //!
  TH1F *HSRB_allWgt; //!

  TH1F *HCRgamma_noWgt; //!
  TH1F *HCRgamma_mcWgt; //!
  TH1F *HCRgamma_allWgt; //!

  TH1F *HCRZ_noWgt; //!
  TH1F *HCRZ_mcWgt; //!
  TH1F *HCRZ_allWgt; //!
  
  TH1F *HCRTemu_noWgt; //!
  TH1F *HCRTemu_mcWgt; //!
  TH1F *HCRTemu_allWgt; //!
 
  TH1F *HCRT1L_noWgt; //!
  TH1F *HCRT1L_mcWgt; //!
  TH1F *HCRT1L_allWgt; //!
  
  TH1F *HCRW_noWgt; //!
  TH1F *HCRW_mcWgt; //!
  TH1F *HCRW_allWgt; //!
  
  TH1F *HCRsT_noWgt; //!
  TH1F *HCRsT_mcWgt; //!
  TH1F *HCRsT_allWgt; //!
  
  TH1F *HTruthMETFilt; //!
  TH1F *HTruthHTFilt; //!
  TH1F *HSumOfPileUp; //!



  bool doSyst;
  bool doPhotons;
  bool RunningLocally;


  std::string outputName;
  std::string inputFile;
  
  //TTree *tree; //!
  unsigned long long EventNumber; //!

  int mcChannel; //!

  std::vector<TreeService*> m_treeServiceVector; //!

  double m_PUSumOfWeights; //!
  double m_finalSumOfWeights; //!
  double m_initialSumOfWeights; //!
  double truth_pT_W; //!

  //  OutputStream *out; //!

  // this is a standard constructor
  MyxAODAnalysis ();

  // these are the functions inherited from Algorithm
  virtual EL::StatusCode setupJob (EL::Job& job);
  virtual EL::StatusCode fileExecute ();
  virtual EL::StatusCode histInitialize ();
  virtual EL::StatusCode changeInput (bool firstFile);
  virtual EL::StatusCode initialize ();
  virtual EL::StatusCode execute ();
  virtual EL::StatusCode postExecute ();
  virtual EL::StatusCode finalize ();
  virtual EL::StatusCode histFinalize ();


  // put functions here?
 public:

  // this is needed to distribute the algorithm to the workers
  ClassDef(MyxAODAnalysis, 1);//Commented out for compilation
};
#endif
