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
#include "AsgTools/AsgMetadataTool.h"

//#include <AnaAlgorithm/AnaAlgorithm.h>

// Added for new METSig
#include "METUtilities/METSignificance.h"

//PMG xsec tool
#include "AsgTools/AnaToolHandle.h"
#include "PMGAnalysisInterfaces/IPMGCrossSectionTool.h"
#include "PMGTools/PMGCrossSectionTool.h"

//BTaggingSelectionTool
#include "FTagAnalysisInterfaces/IBTaggingSelectionTool.h"//Interface
#include "xAODBTaggingEfficiency/BTaggingSelectionTool.h"//tool header for type definition

// GRL inclusion
class GoodRunsListSelectionTool;
//class JetCleaningTool;
//class JERTool;



namespace CP{
//  class MuonCalibrationAndSmearingTool; // MuonSmearing
class PileupReweightingTool;
}

namespace ST{
  class SUSYObjDef_xAOD; //! // SUSYToolsObjectDefinition forward declaration
  //class CrossSectionDB; // SUSYToolsCrossSectionDataBase forward declaration
}

namespace SUSY{
  class CrossSectionDB; //! // Forward Declaration of Cross Section Database
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
  //CP::MuonCalibrationAndSmearingTool *m_muonCalibrationAndSmearingTool;
  //#endif // not__CINT__

#ifndef __CINT__
  //GoodRunsListSelectionTool *m_grl;
  CP::PileupReweightingTool *pu_tool; //!
  //JetToolRunner* m_jetRecTool_kt12; //!
  //JetToolRunner* m_jetRecTool_kt8; //!

#endif // not__CINT__

  //#ifndef __CINT__
  //JERTool *m_JERTool;
  //#endif // not__CINT__

  //#ifndef __CINT__
  //JetCleaningTool *m_jetCleaning;
  //#endif // not__CINT__

  // put your configuration variables here as public variables.
  // that way they can be set directly from CINT and python.
public:
  // float cutValue;

  xAOD::TEvent *m_event; //!

  TTree *MetaData; //!
  bool m_isDerivation; //!
  bool m_SUSY5= false; //!
  bool m_SUSY7= false; //!

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
  

  int isyst; //!
  int m_totalEvents; //!

  double m_lumiScaled; //!

  std::vector<ST::SystInfo> systInfoList; //!


  std::vector<CP::SystematicSet> m_sysList; //!
  //TH1 *h_jetPt;
  TH1 *h_cuts; //!
  std::vector <std::string> cutList; //!
  std::vector <std::string> runningOverSysts; //!
  asg::AnaToolHandle<IMETSignificance> m_metSignif; //!
  asg::AnaToolHandle<IBTaggingSelectionTool> m_BTaggingSelectionTool;//!
  //  EL::OutputStream out



  // Put our new containers here
  // variables that don't get filled at submission time should be
  // protected from being send from the submission node to the worker
  // node (done by the )
 public:
  // Tree *myTree;

  TH1 *noWeightHist; //!
  TH1 *sherpaWeightHist; //!
  TH1 *h_SumOfWeights; //!
  TH1 *h_SumOfWeightsSquared; //!
  TH1 *h_eventsPerRun; //!
  TH1 *renormedSherpaWeightHist; //!

  TH1F *HTruthMETFilt; //!
  TH1F *HTruthHTFilt; //!
  TH1F *HSumOfPileUp; //!

  TH1F *h_dPhi_p30; //!
  TH1F *h_dPhi_p40; //!
  TH1F *h_dPhi_p80; //!
  TH1F *h_dPhi_p200; //!
  TH1F *h_dPhi_H; //!

  TH1F *h_dEta_p30; //!
  TH1F *h_dEta_p40; //!
  TH1F *h_dEta_p80; //!
  TH1F *h_dEta_p200; //!
  TH1F *h_dEta_H; //!

  std::string outputName;

  //TTree *tree;
  unsigned long long EventNumber; //!

  int mcChannel; //!

  std::vector<TreeService*> m_treeServiceVector; //!
  double m_PUSumOfWeights; //!
  double m_finalSumOfWeights; //!
  double m_initialSumOfWeights; //!
  double m_averageIntPerX; //!
  double m_actualIntPerX; //!
  double truth_pT_W; //!

  std::string inputFile;//!
  int counter = 0;
  bool RunningLocally=true;
  bool RunningWithSyst = false;
  bool RunningWithPhotons = false;
  bool RunningWithTruthJets = false;
  int NoEvents = -1;
  bool firstFile = true;
  bool firstEvent = true;
  int doSyst;
  int doPhotons;
  int doTruthJets;

  //  OutputStream *out;

  // this is a standard constructor
  MyxAODAnalysis (/*const std::string& name, ISvcLocator* pSvcLocator*/);

  // these are the functions inherited from Algorithm
  virtual EL::StatusCode setupJob (EL::Job& job);
  virtual EL::StatusCode fileExecute ();
  virtual EL::StatusCode beginInputFile (bool firstFile);
  virtual EL::StatusCode histInitialize ();
  virtual EL::StatusCode initialize ();
  virtual EL::StatusCode execute ();
  virtual EL::StatusCode postExecute ();
  virtual EL::StatusCode finalize ();

 private:

  bool isData; //!
  bool isMC; //!
  bool isAtlfast; //!
  bool isTruth; //!
  
  asg::AnaToolHandle<PMGTools::IPMGCrossSectionTool> m_PMGCrossSectionTool; //!
  asg::AnaToolHandle<CP::IPileupReweightingTool> m_prw_tool; //!
  asg::AnaToolHandle<CP::IMuonCalibrationAndSmearingTool> m_muonCalibrationAndSmearingTool; //!
  /*asg::AnaToolHandle<ST::SUSYObjDef_xAOD> objTool; //!*/
  asg::AnaToolHandle<IGoodRunsListSelectionTool> m_grl; //!

  // put functions here?
 public:

  // this is needed to distribute the algorithm to the workers
  ClassDef(MyxAODAnalysis, 1);//Commented out for compilation
};
#endif
