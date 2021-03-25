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
#include <time.h> /* time */

#include <EventLoopAlgs/NTupleSvc.h>
#include <EventLoopAlgs/AlgSelect.h>

#include "SUSYTools/SUSYObjDef_xAOD.h"
#include "SUSYTools/SUSYCrossSection.h"

#include "PileupReweighting/PileupReweightingTool.h"
#include "AsgTools/ToolHandle.h"
#include "AsgTools/AsgMetadataTool.h"

// Added for new METSig
#include "METUtilities/METSignificance.h"

//PMG xsec tool
#include "AsgTools/AnaToolHandle.h"
#include "PMGAnalysisInterfaces/IPMGTruthWeightTool.h"
#include "PMGTools/PMGCrossSectionTool.h"

// GRL inclusion
class GoodRunsListSelectionTool;

namespace CP
{
  //  class MuonCalibrationAndSmearingTool; // MuonSmearing
  class PileupReweightingTool;
}

namespace ST
{
  class SUSYObjDef_xAOD; //! // SUSYToolsObjectDefinition forward declaration
}

namespace SUSY
{
  class CrossSectionDB; //! // Forward Declaration of Cross Section Database
}

class MyxAODAnalysis : public EL::Algorithm
{
#ifndef __CINT__
  std::unique_ptr<ST::SUSYObjDef_xAOD> objTool;       //!
  std::unique_ptr<ST::SUSYObjDef_xAOD> objTool_PFlow; //!
#endif                                                // not __CINT__

#ifndef __CINT__
  SUSY::CrossSectionDB *xSectDataBase; //!
#endif                                 // not __CINT__

#ifndef __CINT__
  CP::PileupReweightingTool *pu_tool; //!
#endif                                // not__CINT__

  // put your configuration variables here as public variables.
  // that way they can be set directly from CINT and python.
public:
  // this is needed to distribute the algorithm to the workers
  ClassDef(MyxAODAnalysis, 1); //Commented out for compilation

  MyxAODAnalysis();

  std::string inputFile; //!
  std::string m_fileType;
  std::string m_fileName;
  std::string outputName;

  bool m_isDerivation;  //!
  bool m_SUSY5 = false; //!
  bool m_SUSY7 = false; //!

  int m_eventCounter;      //!
  int m_numCleanEvents;    //!
  int m_numElectronEvents; //!
  int m_numMuonEvents;     //!

  int counter = 0;
  bool RunningLocally = true;
  int NoEvents = -1;
  bool firstFile = true;
  bool firstEvent = true;

  //All the booleans that take their value directly from alg-><> =true/false they get interpreted as ints
  int doSyst;
  int doPhotons;
  int doTruthJets;
  int m_doCombiLeptons;

  // these are the functions inherited from Algorithm
  virtual EL::StatusCode setupJob(EL::Job &job);
  virtual EL::StatusCode fileExecute();
  virtual EL::StatusCode beginInputFile(bool firstFile);
  virtual EL::StatusCode histInitialize();
  virtual EL::StatusCode initialize();
  virtual EL::StatusCode execute();
  virtual EL::StatusCode postExecute();
  virtual EL::StatusCode finalize();

private:
  //MetaData things
  xAOD::TEvent *m_event;          //!
  TTree *MetaData;                //!
  bool isData;                    //!
  bool isMC;                      //!
  bool isAtlfast;                 //!
  bool isTruth;                   //!
  double m_PUSumOfWeights;        //!
  double m_finalSumOfWeights;     //!
  double m_initialSumOfWeights;   //!
  double m_averageIntPerX;        //!
  double m_actualIntPerX;         //!
  double truth_pT_W;              //!
  double m_fileLumi;              //!
  int m_runNumber;                //!
  int m_lumiBlockNumber;          //!
  unsigned long long EventNumber; //!
  int mcChannel;                  //!
  double PUSumOfWeights;          //!
  int isyst;                      //!
  int m_totalEvents;              //!
  double m_lumiScaled;            //!

  //MetaData tools
  asg::AnaToolHandle<PMGTools::IPMGCrossSectionTool> m_PMGCrossSectionTool; //!
  asg::AnaToolHandle<CP::IPileupReweightingTool> m_prw_tool;                //!
  asg::AnaToolHandle<IGoodRunsListSelectionTool> m_grl;                     //!

  //Tree things
  std::vector<TreeService *> m_treeServiceVector; //!

  //Systematics things
  std::vector<ST::SystInfo> systInfoList;         //!
  std::vector<ST::SystInfo> systInfoList_weights; //!

  //Systematics tools
  asg::AnaToolHandle<PMGTools::IPMGTruthWeightTool> m_MGTruthWeightTool; //!

  TH1 *noWeightHist;             //!
  TH1 *sherpaWeightHist;         //!
  TH1 *h_SumOfWeights;           //!
  TH1 *h_SumOfWeightsSquared;    //!
  TH1 *h_eventsPerRun;           //!
  TH1 *renormedSherpaWeightHist; //!

  TH1F *HTruthMETFilt; //!
  TH1F *HTruthHTFilt;  //!
  TH1F *HSumOfPileUp;  //!

  TH1F *h_dPhi_p30;  //!
  TH1F *h_dPhi_p40;  //!
  TH1F *h_dPhi_p80;  //!
  TH1F *h_dPhi_p200; //!
  TH1F *h_dPhi_H;    //!

  TH1F *h_dEta_p30;  //!
  TH1F *h_dEta_p40;  //!
  TH1F *h_dEta_p80;  //!
  TH1F *h_dEta_p200; //!
  TH1F *h_dEta_H;    //!
};
#endif
