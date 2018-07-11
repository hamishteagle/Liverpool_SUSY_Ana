#include <EventLoop/Job.h>
#include <EventLoop/StatusCode.h>
#include <EventLoop/Worker.h>
#include <MyAnalysis/MyxAODAnalysis.h>
#include "CPAnalysisExamples/errorcheck.h"
#include "xAODEventInfo/EventInfo.h"
#include "GoodRunsLists/GoodRunsListSelectionTool.h"
#include "xAODCutFlow/CutBookkeeper.h"
#include "xAODCutFlow/CutBookkeeperContainer.h"

#include "JetSelectorTools/JetCleaningTool.h"
#include "JetResolution/JERTool.h"
#include <TSystem.h>
#include "MuonMomentumCorrections/MuonCalibrationAndSmearingTool.h"
#include "PATInterfaces/CorrectionCode.h" 
#include <TFile.h>
#include <exception>

#include <string.h>
#include <fstream>
#include <TTreeFormula.h>
#include "xAODEventInfo/EventInfo.h"
#include "MyAnalysis/TruthObjectDef.h"
#include "MyAnalysis/ObjectDef.h"
#include "MyAnalysis/AddPileUp.h"
#include "MyAnalysis/PreliminarySel.h"
#include "MyAnalysis/CalculateVariables.h"
#include "MyAnalysis/TreeService.h"
#include "MyAnalysis/MCChecks.h"
#include "MyAnalysis/Cutflows.h"

#include <EventLoop/OutputStream.h>
#include <time.h>       /* time */

#include "SUSYTools/SUSYObjDef_xAOD.h"
#include "SUSYTools/SUSYCrossSection.h"


// Added for new METSig
#include "METUtilities/METSignificance.h" 

//Replacing ROOTCOREBIN
#include "PathResolver/PathResolver.h"


// this is needed to distribute the algorithm to the workers
ClassImp(MyxAODAnalysis)

MyxAODAnalysis :: MyxAODAnalysis ()
{
  // Here you put any code for the base initialization of variables,
  // e.g. initialize all pointers to 0.  Note that you should only put
  // the most basic initialization here, since this method will be
  // called on both the submission and the worker node.  Most of your
  // initialization code will go into histInitialize() and
  // initialize().

  
  //return EL::StatusCode::SUCCESS;

}



EL::StatusCode MyxAODAnalysis :: setupJob (EL::Job& job)
{
  // Here you put code that sets up the job on the submission object
  // so that it is ready to work with your algorithm, e.g. you can
  // request the D3PDReader service or add output files.  Any code you
  // put here could instead also go into the submission script.  The
  // sole advantage of putting it here is that it gets automatically
  // activated/deactivated when you add/remove the algorithm from your
  // job, which may or may not be of value to you.


  
  job.useXAOD();

  // 10MB is cached
  job.options()->setDouble(EL::Job::optCacheSize, 10*1024*1024);

  // 50 entries are used for the Cache
  job.options()->setDouble (EL::Job::optCacheLearnEntries, 50);

  xAOD::Init("MyxAODAnalysis").ignore(); //call before opening first file
  
  return EL::StatusCode::SUCCESS;
}



EL::StatusCode MyxAODAnalysis :: histInitialize ()
{
  // Here you do everything that needs to be done at the very
  // beginning on each worker node, e.g. create histograms and output
  // trees.  This method gets called before any input files are
  // connected.

  m_finalSumOfWeights = 0;
  m_initialSumOfWeights = 0;

  m_fileType = wk()->metaData()->getString("sample_name");
  std::cout<<"The fileType is: "<<m_fileType<<std::endl;
  m_fileName = inputFile;

  isData = 0;
  isAtlfast = 0;
  isSignal = 0;
  is25ns = true; 
  std::cout << "The File Name is: " << m_fileName << std::endl;
  

  gErrorIgnoreLevel = kFatal;  
  

  std::cout << "Checking Sample type" << std::endl;
  int foundData = m_fileName.find("data");
  int foundAtlfast = m_fileName.find("_a");
    
  // This will find generic SUSY signals
  int foundSignal = m_fileName.find("MGPy8EG_A14N");
  int foundttNNSignal = m_fileName.find("TT_directTT");

  if (foundData != std::string::npos){
    isData = 1;
    std::cout << "Running on a data sample" << std::endl;
  }
  else if (foundAtlfast != std::string::npos){
    isAtlfast= 1;
    std::cout << "Running on an ATLAS Fast Sim sample" << std::endl;
  }
  else {
    std::cout << "Running on ATLAS Full Sim" << std::endl;
  }
  if ((foundSignal != std::string::npos) || (foundttNNSignal != std::string::npos) ){
    isSignal = true;
    std::cout << "Running on a signal Sample" << std::endl;
  }
 
  if (isData){
    doSyst = false;
  }


  int found = m_fileName.find("TRUTH");
  int found_evnt = m_fileName.find("evnt"); // This will run on a private truth derivation 
  if (found != std::string::npos || found_evnt != std::string::npos){
    std::cout << "Running on truth derivation" << std::endl;
    m_fileType = "DAOD_TRUTH1";
    doSyst = false; // Never run Systematics on a Truth Sample
  }
  else{
    m_fileType = "DAOD_SUSY1";    
  }


  noWeightHist = new TH1F("h_noWeights","h_noWeightHist",1 , 0.5, 1.5);
  sherpaWeightHist = new TH1F("h_sherpaWeights","h_sherpaWeightHist",1 , 0.5, 1.5);
  renormedSherpaWeightHist = new TH1F("h_RenormedSherpaWeights","h_RenormedSherpaWeightHist",1 , 0.5, 1.5);
  h_SumOfWeights = new TH1D("h_SumOfWeights","h_SumOfWeights",1 , 0.5, 1.5);
  h_SumOfWeightsSquared = new TH1D("h_SumOfWeightsSquared","h_SumOfWeightsSquared",1 , 0.5, 1.5);


  HSRA_noWgt = new TH1F("HSRA_noWgt","HSRA_noWgt", 50, 0.5, 50.5);
  HSRA_mcWgt = new TH1F("HSRA_mcWgt","HSRA_mcWgt", 50, 0.5, 50.5);
  HSRA_allWgt = new TH1F("HSRA_allWgt","HSRA_allWgt", 50, 0.5, 50.5);


  HSRB_noWgt = new TH1F("HSRB_noWgt","HSRB_noWgt", 50, 0.5, 50.5);
  HSRB_mcWgt = new TH1F("HSRB_mcWgt","HSRB_mcWgt", 50, 0.5, 50.5);
  HSRB_allWgt = new TH1F("HSRB_allWgt","HSRB_allWgt", 50, 0.5, 50.5);

  HCRgamma_noWgt = new TH1F("HCRgamma_noWgt","HCRgamma_noWgt", 50, 0.5, 50.5);
  HCRgamma_mcWgt = new TH1F("HCRgamma_mcWgt","HCRgamma_mcWgt", 50, 0.5, 50.5);
  HCRgamma_allWgt = new TH1F("HCRgamma_allWgt","HCRgamma_allWgt", 50, 0.5, 50.5);

  HSRC_noWgt = new TH1F("HSRC_noWgt","HSRC_noWgt", 50, 0.5, 50.5);
  HSRC_mcWgt = new TH1F("HSRC_mcWgt","HSRC_mcWgt", 50, 0.5, 50.5);
  HSRC_allWgt = new TH1F("HSRC_allWgt","HSRC_allWgt", 50, 0.5, 50.5);
  
  HCRTemu_noWgt = new TH1F("HCRTemu_noWgt","HCRTemu_noWgt", 50, 0.5, 50.5);
  HCRTemu_mcWgt = new TH1F("HCRTemu_mcWgt","HCRTemu_mcWgt", 50, 0.5, 50.5);
  HCRTemu_allWgt = new TH1F("HCRTemu_allWgt","HCRTemu_allWgt", 50, 0.5, 50.5);
 
  HCRT1L_noWgt = new TH1F("HCRT1L_noWgt","HCRT1L_noWgt", 50, 0.5, 50.5);
  HCRT1L_mcWgt = new TH1F("HCRT1L_mcWgt","HCRT1L_mcWgt", 50, 0.5, 50.5);
  HCRT1L_allWgt = new TH1F("HCRT1L_allWgt","HCRT1L_allWgt", 50, 0.5, 50.5);
  
  HCRW_noWgt = new TH1F("HCRW_noWgt","HCRW_noWgt", 50, 0.5, 50.5);
  HCRW_mcWgt = new TH1F("HCRW_mcWgt","HCRW_mcWgt", 50, 0.5, 50.5);
  HCRW_allWgt = new TH1F("HCRW_allWgt","HCRW_allWgt", 50, 0.5, 50.5);
  
  HCRsT_noWgt = new TH1F("HCRsT_noWgt","HCRsT_noWgt", 50, 0.5, 50.5);
  HCRsT_mcWgt = new TH1F("HCRsT_mcWgt","HCRsT_mcWgt", 50, 0.5, 50.5);
  HCRsT_allWgt = new TH1F("HCRsT_allWgt","HCRsT_allWgt", 50, 0.5, 50.5);


  HTruthMETFilt = new TH1F("HTruthMETFilt","HTruthMETFilt", 50, 0,1000);
  HTruthHTFilt = new TH1F("HTruthHTFilt","HTruthHTFilt", 50, 0,1000);

  HSumOfPileUp = new TH1F("HSumOfPileUp","HSumOfPileUp", 1, 0.5,1.5);



  noWeightHist->SetDirectory (wk()->getOutputFile("output"));
  sherpaWeightHist->SetDirectory (wk()->getOutputFile("output"));
  h_SumOfWeights->SetDirectory (wk()->getOutputFile("output"));
  h_SumOfWeightsSquared->SetDirectory (wk()->getOutputFile("output"));
  renormedSherpaWeightHist->SetDirectory (wk()->getOutputFile("output"));

  // Make the Histos for the full cutflows here then:
  
  HSRA_noWgt->SetDirectory (wk()->getOutputFile("output"));
  HSRA_mcWgt->SetDirectory (wk()->getOutputFile("output"));
  HSRA_allWgt->SetDirectory (wk()->getOutputFile("output"));

  HSRB_noWgt->SetDirectory (wk()->getOutputFile("output"));
  HSRB_mcWgt->SetDirectory (wk()->getOutputFile("output"));
  HSRB_allWgt->SetDirectory (wk()->getOutputFile("output"));

  HCRgamma_noWgt->SetDirectory (wk()->getOutputFile("output"));
  HCRgamma_mcWgt->SetDirectory (wk()->getOutputFile("output"));
  HCRgamma_allWgt->SetDirectory (wk()->getOutputFile("output"));

  HSRC_noWgt->SetDirectory (wk()->getOutputFile("output"));
  HSRC_mcWgt->SetDirectory (wk()->getOutputFile("output"));
  HSRC_allWgt->SetDirectory (wk()->getOutputFile("output"));
  
  HCRTemu_noWgt->SetDirectory (wk()->getOutputFile("output"));
  HCRTemu_mcWgt->SetDirectory (wk()->getOutputFile("output"));
  HCRTemu_allWgt->SetDirectory (wk()->getOutputFile("output"));
 
  HCRT1L_noWgt->SetDirectory (wk()->getOutputFile("output"));
  HCRT1L_mcWgt->SetDirectory (wk()->getOutputFile("output"));
  HCRT1L_allWgt->SetDirectory (wk()->getOutputFile("output"));
  
  HCRW_noWgt->SetDirectory (wk()->getOutputFile("output"));
  HCRW_mcWgt->SetDirectory (wk()->getOutputFile("output"));
  HCRW_allWgt->SetDirectory (wk()->getOutputFile("output"));
  
  HCRsT_noWgt->SetDirectory (wk()->getOutputFile("output"));
  HCRsT_mcWgt->SetDirectory (wk()->getOutputFile("output"));
  HCRsT_allWgt->SetDirectory (wk()->getOutputFile("output"));
  
  HTruthMETFilt->SetDirectory (wk()->getOutputFile("output"));
  HTruthHTFilt->SetDirectory (wk()->getOutputFile("output"));
  HSumOfPileUp->SetDirectory (wk()->getOutputFile("output"));




  return EL::StatusCode::SUCCESS;

}



EL::StatusCode MyxAODAnalysis :: fileExecute ()
{
  // Here you do everything that needs to be done exactly once for every
  // single file, e.g. collect a list of all lumi-blocks processed

  const char* APP_NAME = "MyxAODAnalysis";


  std::cout << "We are changing the input file now. Currently in file execute " << std::endl;
  

  m_event = wk()->xaodEvent();
  double nEventsProcessed  = 0;
  double sumOfWeights        = 0;
  double sumOfWeightsSquared = 0;
  if(m_isDerivation && m_fileType != "DAOD_TRUTH1" && isData == false){
    
    std::cout << "This file is a derivation" << std::endl;
    
    // check for corruption
    const xAOD::CutBookkeeperContainer* incompleteCBC;
    if(!m_event->retrieveMetaInput(incompleteCBC, "IncompleteCutBookkeepers").isSuccess()){
      Error("initializeEvent()","Failed to retrieve IncompleteCutBookkeepers from MetaData! Exiting.");
      return EL::StatusCode::FAILURE;
    }

    // Now, let's find the actual information
    const xAOD::CutBookkeeperContainer* completeCBC = 0;
    if(!m_event->retrieveMetaInput(completeCBC, "CutBookkeepers").isSuccess()){
      Error("initializeEvent()","Failed to retrieve CutBookkeepers from MetaData! Exiting.");
      return EL::StatusCode::FAILURE;
    }
    

    // First, let's find the smallest cycle number,
    // i.e., the original first processing step/cycle
    int minCycle = 10000;
    for ( auto cbk : *completeCBC ) {
      if ( ! cbk->name().empty()  && minCycle > cbk->cycle() ){ minCycle = cbk->cycle(); }
    }
    // Now, let's actually find the right one that contains all the needed info...
    const xAOD::CutBookkeeper* allEventsCBK=0;
    const xAOD::CutBookkeeper* DxAODEventsCBK=0;
    std::string derivationName = "DAOD_SUSY1"; //need to replace by appropriate name
    const xAOD::CutBookkeeper* all = 0; int maxCycle=-1; //need to find the max cycle where input stream is StreamAOD and the name is AllExecutedEvents

    for ( auto cbk :  *completeCBC ) {
      if(cbk->inputStream()=="StreamAOD" && cbk->name()=="AllExecutedEvents" && cbk->cycle()>maxCycle) 
	{ 
	  maxCycle=cbk->cycle(); allEventsCBK = cbk; 
	} 
    }
    
    //m_totalEvents += all->sumOfEventWeights(); //also have all->nAcceptedEvents() which is simple event count, and all->sumOfEventWeightsSquared()
    
    uint64_t cbknEventsProcessed  = allEventsCBK->nAcceptedEvents();
    double cbksumOfWeights        = allEventsCBK->sumOfEventWeights();
    double cbksumOfWeightsSquared = allEventsCBK->sumOfEventWeightsSquared();

    

    // Skip this out if we're dealing with a Truth File
    
    nEventsProcessed  = cbknEventsProcessed;
    sumOfWeights        = cbksumOfWeights;
    sumOfWeightsSquared = cbksumOfWeightsSquared;
  }      
  
  std::cout << "Sum of Weights: " << sumOfWeights << std::endl;
  std::cout << "Sum of Weights Squared: " << sumOfWeightsSquared << std::endl;
  m_finalSumOfWeights += sumOfWeights;
  m_initialSumOfWeights += sumOfWeightsSquared;
  h_SumOfWeights->Fill(1,sumOfWeights);
  h_SumOfWeightsSquared->Fill(1,sumOfWeightsSquared);
  

  std::cout << "Total Sum of Weights: " << m_finalSumOfWeights << std::endl;
  std::cout << "Total Sum of Weights Squared: " << m_initialSumOfWeights << std::endl;

  return EL::StatusCode::SUCCESS;
}



EL::StatusCode MyxAODAnalysis :: changeInput (bool firstFile)
{
  // Here you do everything you need to do when we change input files,
  // e.g. resetting branch addresses on trees.  If you are using
  // D3PDReader or a similar service this method is not needed.
  // get the MetaData tree once a new file is opened, with
  
  std::cout << "Changing the input file." << std::endl;
  MetaData = dynamic_cast<TTree*> (wk()->inputFile()->Get("MetaData"));
  if (MetaData) {
    
    MetaData->LoadTree(0);
    
    m_isDerivation = !MetaData->GetBranch("StreamAOD");
    
  }

return EL::StatusCode::SUCCESS;
}



EL::StatusCode MyxAODAnalysis :: initialize ()
{
  // Here you do everything that you need to do after the first input
  // file has been connected and before the first event is processed,
  // e.g. create additional histograms based on which variables are
  // available in the input files.  You can also create all of your
  // histograms and trees in here, but be aware that this method
  // doesn't get called if no events are processed.  So any objects
  // you create here won't be available in the output if you have no
  // input events.

  const char* APP_NAME = "MyxAODAnalysis";

  m_eventCounter = 0;
  m_numCleanEvents = 0;
  m_numElectronEvents = 0;
  m_numMuonEvents = 0;
 
  // GRL
  m_grl = new GoodRunsListSelectionTool("GoodRunsListSelectionTool");
  
  //PathResolverDirect
  std::string fullGRLFilePath = PathResolverFindCalibFile("MyAnalysis/MyAnalysis/data16_13TeV.periodAllYear_DetStatus-v89-pro21-01_DQDefects-00-02-04_PHYS_StandardGRL_All_Good_25ns.xml");
  std::string fullGRLFilePath1 = PathResolverFindCalibFile("MyAnalysis/MyAnalysis/data17_13TeV.periodAllYear_DetStatus-v97-pro21-13_Unknown_PHYS_StandardGRL_All_Good_25ns_Triggerno17e33prim.xml");                                      
  std::string fullGRLFilePath2 = PathResolverFindCalibFile("MyAnalysis/MyAnalysis/LastGRL.xml");
  




  std::vector<std::string> vecStringGRL;
  vecStringGRL.push_back(fullGRLFilePath);
  vecStringGRL.push_back(fullGRLFilePath1);
  vecStringGRL.push_back(fullGRLFilePath2);

  CHECK(m_grl->setProperty( "GoodRunsListVec", vecStringGRL));
  CHECK(m_grl->setProperty("PassThrough", false));
  if (!m_grl->initialize().isSuccess()){
    Error("initialize()", "Failed to properly initialise the GRL. Exiting.");
    return EL::StatusCode::FAILURE;
  }


 
  std::cout << "Passed GRL init" << std::endl;


  std::vector<std::string> lumicalcFiles;
  std::vector<std::string> confFiles;
  
  //Getting the run number of the file to determine MC16a vs MC16c
  const xAOD::EventInfo* eventInfo_init =0;
  if (! m_event->retrieve(eventInfo_init, "EventInfo").isSuccess() ){
    Error("execute()","Failed to retrieve event info collection, exiting!!");
  }
  
  int periodNumber = eventInfo_init->runNumber();
  std::cout<<"Run Number; "<<periodNumber<<std::endl;
  bool isMC16a = (periodNumber == 284500);
  bool isMC16c = (periodNumber == 300000);
  

  bool isMC15a = false;
  bool isMC15b = false;
  bool isMC15c = false;

  if(isMC16a)
    {
      lumicalcFiles.push_back(PathResolverFindCalibFile("MyAnalysis/MyAnalysis/PileUp/PHYS_StandardGRL_All_Good_25ns_276262-284484_OflLumi-13TeV-008.root"));
      lumicalcFiles.push_back(PathResolverFindCalibFile("MyAnalysis/MyAnalysis/PileUp/PHYS_StandardGRL_All_Good_25ns_297730-311481_OflLumi-13TeV-009.root"));
    }
  if(isMC16c){lumicalcFiles.push_back(PathResolverFindCalibFile("MyAnalysis/MyAnalysis/PileUp/physics_25ns_Triggerno17e33prim.lumicalc.OflLumi-13TeV-001.root"));}
  
    
  std::cout << "Passed Lumi Calc Files" << std::endl;  
    
  std::cout << "which MC is this: A, B, C, 16a, 16c" << isMC15a << isMC15b << isMC15c << isMC16a <<isMC16c<<std::endl;
  if (isMC15b){
    confFiles.push_back(PathResolverFindCalibFile("MyAnalysis/MyAnalysis/signals_mc15b_merged.root"));
    confFiles.push_back(PathResolverFindCalibFile("MyAnalysis/MyAnalysis/merged_prw_mc15b.root"));
  }
  else if (isMC15a){
    confFiles.push_back(PathResolverFindCalibFile("MyAnalysis/MyAnalysis/merged_prw.root"));
  }  
  else if (isMC15c){

    if (!isSignal){

      std::cout << "Adding the latest" << std::endl;
      confFiles.push_back(PathResolverFindCalibFile("MyAnalysis/MyAnalysis/mc15c_v2_defaults.NotRecommended.prw.root"));
    }
    else{
      std::cout << "Adding the not recommended" << std::endl;
      confFiles.push_back(PathResolverFindCalibFile("MyAnalysis/MyAnalysis/mc15c_v2_defaults.NotRecommended.prw.root"));
    }
    
  }


  // SUSY Tools initialisation
  
  int m_showerType = 0;
  int foundSherpa =  m_fileName.find("Sherpa");
  if (foundSherpa != std::string::npos){
    m_showerType = 3;
  }
  int foundHerwig =  m_fileName.find("Herwigpp");
  if (foundHerwig != std::string::npos){
    m_showerType = 1;
  }
  int foundPythia8 =  m_fileName.find("Pythia8");
  int foundMGPy8 =  m_fileName.find("MGPy8");
  if ((foundPythia8 != std::string::npos) || (foundMGPy8 != std::string::npos )){
    m_showerType = 2;
  }
  


  objTool = new ST::SUSYObjDef_xAOD("SUSYObjDef_xAOD");
  std::cout << " ABOUT TO INITIALIZE SUSYTOOLS " << std::endl;

  ST::ISUSYObjDef_xAODTool::DataSource datasource = (isData ? ST::ISUSYObjDef_xAODTool::Data : (isAtlfast ? ST::ISUSYObjDef_xAODTool::AtlfastII : ST::ISUSYObjDef_xAODTool::FullSim));  

  ANA_CHECK(objTool->setProperty("DataSource",datasource) ) ;
  ANA_CHECK( objTool->setProperty("ConfigFile", PathResolverFindCalibFile("MyAnalysis/MyAnalysis//sbottom_multib_rel21.conf")));
  ANA_CHECK(objTool->setBoolProperty("UseBtagging", true));
  //CHECK( objTool->setProperty("ShowerType", (int)m_showerType) );

  // skip this if we're not running on a reco file
  if (m_fileType != "DAOD_TRUTH1"){
    std::cout << "Adding Pile up stuff" << std::endl;
    ANA_CHECK(objTool->setProperty("PRWLumiCalcFiles",lumicalcFiles));
    ANA_CHECK(objTool->setBoolProperty("AutoconfigurePRWTool",true));
    //CHECK(objTool->setProperty("PRWConfigFiles", confFiles));//Option for manually setting the config files
  }
  

  //objTool->msg().setLevel(MSG::FATAL);
  //objTool->msg().setLevel(MSG::VERBOSE);
  
  // Actually skip the full initialisation of SUSYTools if we're running on a TRUTH file
  if (m_fileType != "DAOD_TRUTH1"){
    
    if( objTool->initialize() != StatusCode::SUCCESS){
      Error( APP_NAME, "Cannot intialize SUSYObjDef_xAOD..." );
      Error( APP_NAME, "Exiting... " );
      exit(-1);
    }
    else{
      Info( APP_NAME, "SUSYObjDef_xAOD initialized... " );
    }
    std::cout << " INITIALIZED SUSYTOOLS " << std::endl;
  }
  
  
  // Set verbosity if required
  //  objTool->msg().setLevel( MSG::VERBOSE);

  // loop over all systematics if we are running with systematics
  if(!doSyst) {
    ST::SystInfo infodef;
    infodef.affectsKinematics = false;
    infodef.affectsWeights = false;
    infodef.affectsType = ST::Unknown;
    systInfoList.push_back(infodef);

  } 
  else {
    systInfoList = objTool->getSystInfoList();
  }
  
  TTree *Temp;
  
  for(const auto& sysInfo : systInfoList){
    const CP::SystematicSet& sys = sysInfo.systset;
    
    std::cout << "Systematic name: " + sys.name() << std::endl;
    std::cout << "Systematic tree name: " + sys.name() << std::endl;

    std::string treeName = "CollectionTree_"+std::string(sys.name());
    const char * cName = treeName.c_str();
    Temp = new TTree (cName, cName);
    TDirectory *out_TDir = (TDirectory*) wk()->getOutputFile ("output");
    TreeService* Tree_Service = new TreeService(Temp, out_TDir);
    m_treeServiceVector.push_back(Tree_Service);
  
  }	

  
  //Initialise the new METSignificance tool here
  m_metSignif.setTypeAndName("met::METSignificance/metSignif");
  ANA_CHECK(m_metSignif.setProperty("SoftTermParam", 0));
  //  m_metSignif.setProperty("SoftTermReso", 0);
  ANA_CHECK(m_metSignif.setProperty("TreatPUJets",   true));
  ANA_CHECK(m_metSignif.setProperty("IsDataJet",   false));
  ANA_CHECK(m_metSignif.setProperty("IsDataMuon", false));
  ANA_CHECK(m_metSignif.setProperty("IsAFII",  false));

  /*  if(datasource==ST::ISUSYObjDef_xAODTool::Data){
      m_metSignif.setProperty("IsData",true);
      }
      else if (datasource==ST::ISUSYObjDef_xAODTool::AtlfastII){
      m_metSignif.setProperty("IsAFII",true);
      }*/
  
  ANA_CHECK(m_metSignif.retrieve());
  m_metSignif->initialize();


  
  Info("initialize()","number of events = %lli", m_event->getEntries()); 
  


  m_totalEvents = m_event->getEntries();
  
  
  
  for (int m = 0; m < (m_treeServiceVector.size()); m++){
    m_treeServiceVector[m]->writeTree();
  }



  



 
  return EL::StatusCode::SUCCESS;
}


EL::StatusCode MyxAODAnalysis :: execute ()
{
  // Here you do everything that needs to be done on every single
  // events, e.g. read input variables, apply cuts, and fill
  // histograms and trees.  This is where most of your actual analysis
  // code will go.

  const char* APP_NAME = "MyxAODAnalysis";
  //std::cout << "In analysis execute" << std::endl;
  
  //if (m_eventCounter >= 10){return EL::StatusCode::SUCCESS;}
  if ( (m_eventCounter % 10000) == 0 ) Info("execute()","Event Number = %i", m_eventCounter);
  //if ( (m_eventCounter % 100) == 0 ) Info("execute()","Event Number = %i", m_eventCounter);
  m_eventCounter++;

  //std::cout << "Event number: " << m_eventCounter << std::endl;
  
  bool isNominal = true;

  // Event Info
  // ----------
  isyst = 0;



  

  for (const auto& sysInfo : systInfoList){
    const CP::SystematicSet& syst = sysInfo.systset;
    
    int year = 0;    
    if (m_fileType != "DAOD_TRUTH1"){
      objTool->ApplyPRWTool();
      //      std::cout<<"Applied the PRW Tool"<<std::endl;
      year = objTool->treatAsYear(); 
    }

    if (m_fileType != "DAOD_TRUTH1"){
      
      if (objTool->resetSystematics() != CP::SystematicCode::Ok){
	Error(APP_NAME, "Cannot reset SUSYTools systematics" );
	exit(-2);
      }
      
      
      if (objTool->applySystematicVariation(syst) != CP::SystematicCode::Ok){
	std::cout << "Cannot configure SUSYTools for systematic " + syst.name() << std::endl;
      } else {
	//std::cout << "Variation  configured..." + syst.name() << std::endl;
      }
      if(sysInfo.affectsKinematics || sysInfo.affectsWeights) isNominal = false;
    }
    
   // if (doSyst)
     // {
	//int found_MassRes_Top = (std::string(syst.name()).find("MassRes_Top__1up"));
	//if(found_MassRes_Top == std::string::npos) continue;//The FatJetsTools can only be setup for one systematic at a time...Need to sort out this method of looping systematics
     // }
    const xAOD::EventInfo* eventInfo =0;
    if (! m_event->retrieve(eventInfo, "EventInfo").isSuccess() ){
      Error("execute()","Failed to retrieve event info collection, exiting!!");
      isyst++;
      continue;
    }


  
    
  
  
    m_lumiBlockNumber = eventInfo->lumiBlock();
    m_runNumber = eventInfo->runNumber();


    EventNumber = (eventInfo->eventNumber());

    xAOD::TStore* store = wk()->xaodStore();


    double btagWgt = 1;
    double electronWgt = 1;
    double muonWgt = 1;
    double electronTrigWgt;
    double lepWgt = 1;
    double trigWgt = 1;
    double puWgt = 1;
    double JVTWgt = 1;
    
    // Data MC Check
    
    
    bool isMC = false;
    double weight = 1;
    
    double truth_pTW = 0;
    
    
    if(eventInfo->eventType( xAOD::EventInfo::IS_SIMULATION) ){
      isMC = true; // lets us do things correctly later
    }
    
    mcChannel = 0;
    double xsecteff = 1;
    double mcWgt = 1;
    double truthfilt_MET = 0;
    double truthfilt_HT = 0;
    double renormedMcWgt = 1;
    // Will fix this when the PMGTools cross section stuff is available
    m_lumiScaled = 1;
    
    
    if (isMC){
      mcChannel = eventInfo->mcChannelNumber();
    
      mcWgt = eventInfo->mcEventWeight();
      renormedMcWgt = mcWgt;
      if (std::abs(renormedMcWgt) >= 100){
	renormedMcWgt = 1;
      }
      
      if (m_fileType != "DAOD_TRUTH1"){ 
	puWgt = objTool->GetPileupWeight();
      }
    }
    m_lumiScaled = (10*1000*xsecteff)/m_finalSumOfWeights;
    HSumOfPileUp->Fill(1,puWgt);
    
      
    // This can get all of the PDF info etc if it's required at any point
    //const xAOD::TruthEventContainer* truthE = 0;
    //m_event->retrieve(truthE, "TruthEvents" );
      
      // Print their properties, using the tools:
      //for(const auto& evt : *truthE) {
      //	float x1, x2, pdf1, pdf2, scalePDF, Q;
      //int id1, id2;
      //	evt->pdfInfoParameter(id1, xAOD::TruthEvent::PDGID1);
      //evt->pdfInfoParameter(id2, xAOD::TruthEvent::PDGID2);
      //evt->pdfInfoParameter(x1, xAOD::TruthEvent::X1);
      //evt->pdfInfoParameter(x2, xAOD::TruthEvent::X2);
      //evt->pdfInfoParameter(pdf1, xAOD::TruthEvent::PDFID1);
      //evt->pdfInfoParameter(pdf2, xAOD::TruthEvent::PDFID2);
      //evt->pdfInfoParameter(scalePDF, xAOD::TruthEvent::SCALE);
	//evt->pdfInfoParameter(Q, xAOD::TruthEvent::Q);
	//Info( APP_NAME, "PDF INFO: id1/id2: %d/%d x1/x2: %g/%g  pdf1/pdf2: %g/%g  scalePDF: %g",
      //    id1, id2, x1, x2, pdf1, pdf2, scalePDF
      //      );
      //}
   
     
    
  
    
    // initialise the object definitions class
    IObjectDef* m_objs;
    
    //std::cout << "Filled the objects" << std::endl;

    if (m_fileType == "DAOD_TRUTH1"){
      m_objs  = new TruthObjectDef (m_event, objTool, store, mcChannel, EventNumber, mcWgt, xsecteff, syst.name(), doPhotons,  m_metSignif); //, m_jetRecTool_kt12, m_jetRecTool_kt8
    }
    else{
      m_objs  = new ObjectDef (m_event, objTool, store, mcChannel, EventNumber, mcWgt, xsecteff, syst.name(), doPhotons, m_metSignif); //, m_jetRecTool_kt12, m_jetRecTool_kt8
    }
    
    
    if (isyst == 0){
      noWeightHist->Fill(1,1);
      sherpaWeightHist->Fill(1,mcWgt);
      renormedSherpaWeightHist->Fill(1,renormedMcWgt);
      
      HSRA_noWgt->Fill(1,1);
      HSRA_mcWgt->Fill(1,mcWgt); 
      HSRA_allWgt->Fill(1,mcWgt);//*btagWgt*lepWgt*trigWgt*puWgt);
      
      HSRB_noWgt->Fill(1,0.46754945);//Change back to 1
      HSRB_mcWgt->Fill(1,mcWgt); 
      HSRB_allWgt->Fill(1,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
      
      HCRgamma_noWgt->Fill(1,1);
      HCRgamma_mcWgt->Fill(1,mcWgt); 
      HCRgamma_allWgt->Fill(1,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
      
      HSRC_noWgt->Fill(1,1);
      HSRC_mcWgt->Fill(1,mcWgt); 
      HSRC_allWgt->Fill(1,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
      
      HCRTemu_noWgt->Fill(1,1);
      HCRTemu_mcWgt->Fill(1,mcWgt);
      HCRTemu_allWgt->Fill(1,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
      
      HCRT1L_noWgt->Fill(1,1);
      HCRT1L_mcWgt->Fill(1,mcWgt); 
      HCRT1L_allWgt->Fill(1,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
      
      HCRW_noWgt->Fill(1,1);
      HCRW_mcWgt->Fill(1,mcWgt); 
      HCRW_allWgt->Fill(1,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
      
      HCRsT_noWgt->Fill(1,1);
      HCRsT_mcWgt->Fill(1,mcWgt);
      HCRsT_allWgt->Fill(1,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
      
    }
    
    // Initialise the class which sorts out the MC checks (if required)
    std::unique_ptr<MCChecks> checkMC (new MCChecks ());
    
    if (!isMC){
      
      if(!(m_grl->passRunLB(*eventInfo))){
	continue;
      }
    }
    
    // get the truth MET info for OR removals between ttbar/single top samples
    if (mcChannel == 410000 || mcChannel == 410013 || mcChannel == 410014 || mcChannel == 407012 || mcChannel == 407322 || mcChannel == 407009 || mcChannel == 407010 || mcChannel == 407011 || mcChannel == 407018 || mcChannel == 407019 || mcChannel == 407120 || mcChannel == 407021){
    truthfilt_MET = 0.001*eventInfo->auxdata< float >("GenFiltMET");
    truthfilt_HT = 0.001*eventInfo->auxdata< float>("GenFiltHT");
    HTruthMETFilt->Fill(truthfilt_MET);
    HTruthHTFilt->Fill(truthfilt_HT);
    checkMC->ttbar_decay(m_event);
    }
    
      
    bool isTruthFile = false;
    if (m_fileType == "DAOD_TRUTH1"){
      isTruthFile = true;
    
    }

    
    if (isMC){
      int foundSherpa = m_fileName.find("Sherpa");

      checkMC->HeavyFlavourFilter_countJets(m_event, true); 
      checkMC->TruthTaus(m_event); 
     
      if (isTruthFile && foundSherpa != std::string::npos){
	checkMC->ZpT(m_event); 
	checkMC->SherpaZpT(m_event);
      } 
      
      int foundSherpa221 = m_fileName.find("Sherpa_221");
      if (foundSherpa221 != std::string::npos){
	checkMC->SherpaUncertaintyWeights(m_event); 
	//std::cout << "Got Sherpa weights" << std::endl;
	
      } else {
       checkMC->RetrieveWeights(m_event);
      }
    
    }
    
    // Passes Cleaning Selection
  
    if (isyst == 0){
      HSRA_noWgt->Fill(2,1);
      HSRA_mcWgt->Fill(2,mcWgt); 
      HSRA_allWgt->Fill(2,mcWgt);//*btagWgt*lepWgt*trigWgt*puWgt);
      
      HSRB_noWgt->Fill(2,0.46754945);//Change back to 1 
      HSRB_mcWgt->Fill(2,mcWgt); 
      HSRB_allWgt->Fill(2,1);
      
      HCRgamma_noWgt->Fill(2,1);
      HCRgamma_mcWgt->Fill(2,mcWgt); 
      HCRgamma_allWgt->Fill(2,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
      
      HSRC_noWgt->Fill(2,1);
      HSRC_mcWgt->Fill(2,mcWgt); 
      HSRC_allWgt->Fill(2,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
      
      HCRTemu_noWgt->Fill(2,1);
      HCRTemu_mcWgt->Fill(2,mcWgt);
      HCRTemu_allWgt->Fill(2,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
      
      HCRT1L_noWgt->Fill(2,1);
      HCRT1L_mcWgt->Fill(2,mcWgt); 
      HCRT1L_allWgt->Fill(2,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
      
      HCRW_noWgt->Fill(2,1);
      HCRW_mcWgt->Fill(2,mcWgt); 
      HCRW_allWgt->Fill(2,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
      
      HCRsT_noWgt->Fill(2,1);
      HCRsT_mcWgt->Fill(2,mcWgt);
      HCRsT_allWgt->Fill(2,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
      
      
    }


    bool coreFlags = false;
    bool sctFlag = false;

    if (!isMC){
      if ((eventInfo->errorState(xAOD::EventInfo::SCT) == xAOD::EventInfo::Error )){
	sctFlag = true;
      }
      if (eventInfo->isEventFlagBitSet(xAOD::EventInfo::Core,18)){
	coreFlags = true;
      }
      if ( (eventInfo->errorState(xAOD::EventInfo::LAr)==xAOD::EventInfo::Error) || (eventInfo->errorState(xAOD::EventInfo::Tile) == xAOD::EventInfo::Error) || coreFlags || sctFlag){
	isyst++;
	continue;
      }
    }
    // Event Passes LAr, TileError and CoreFlags.     
    if (isyst == 0){
      
      HSRA_noWgt->Fill(3,1);
      HSRA_mcWgt->Fill(3,mcWgt); 
      HSRA_allWgt->Fill(3,mcWgt);//*btagWgt*lepWgt*trigWgt*puWgt);
      
      HSRB_noWgt->Fill(3,0.46754945);//Change back to 1 
      HSRB_mcWgt->Fill(3,mcWgt); 
      HSRB_allWgt->Fill(3,1);
      
      HCRgamma_noWgt->Fill(3,1);
      HCRgamma_mcWgt->Fill(3,mcWgt); 
      HCRgamma_allWgt->Fill(3,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
      
      HSRC_noWgt->Fill(3,1);
      HSRC_mcWgt->Fill(3,mcWgt); 
      HSRC_allWgt->Fill(3,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
      
      HCRTemu_noWgt->Fill(3,1);
      HCRTemu_mcWgt->Fill(3,mcWgt);
      HCRTemu_allWgt->Fill(3,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
      
      HCRT1L_noWgt->Fill(3,1);
      HCRT1L_mcWgt->Fill(3,mcWgt); 
      HCRT1L_allWgt->Fill(3,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
      
      HCRW_noWgt->Fill(3,1);
      HCRW_mcWgt->Fill(3,mcWgt); 
      HCRW_allWgt->Fill(3,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
      
      HCRsT_noWgt->Fill(3,1);
      HCRsT_mcWgt->Fill(3,mcWgt);
      HCRsT_allWgt->Fill(3,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
    }
    
    double nBadJet = m_objs->getBadJets()->size();
    double nCosmicMu = 0;
    double nBadMu = m_objs->getBadMuons()->size();
    
    // Put the trigger here:
    
    bool passedMETTrigger = false;
    bool passedMuTrigger = false;
    bool passedElTrigger = false;
    bool passedGammaTrigger = false;
    bool passedLepTrigger = false;
    bool passedMultiJetTrigger = false;
    bool passedTauTrigger = false;

    //std::cout << "In analysis execute, before the trigger" << std::endl;

    
    if (m_fileType == "DAOD_TRUTH1"){
      passedMETTrigger = true;
      passedMuTrigger = true;
      passedElTrigger = true;
      passedGammaTrigger = true;
      passedMultiJetTrigger = true;
      passedTauTrigger = true;

    }

    else{
      
      if(year==2015){
	if (!isData)
	passedElTrigger=( (objTool->IsTrigPassed("HLT_e24_lhmedium_L1EM20VH || HLT_e60_lhmedium || HLT_e120_lhloose")));
	if(isData)
	  {
	    passedElTrigger=( (objTool->IsTrigPassed("HLT_e24_lhmedium_L1EM20VH || HLT_e60_lhmedium || HLT_e120_lhloose")));
	  }
	passedMuTrigger=( (objTool->IsTrigPassed("HLT_mu20_iloose_L1MU15 || HLT_mu50 ")));
	passedGammaTrigger=(objTool->IsTrigPassed("HLT_g120_loose"));
	passedMETTrigger = objTool->IsMETTrigPassed("HLT_xe70"); // or we use HLT_xe70_mht  or HLT_xe70_tc_lcw 
      }
      else{//These triggers are the same for 2016/17 may change for 2018
	passedElTrigger=  ((objTool->IsTrigPassed("HLT_e26_lhtight_nod0_ivarloose || HLT_e60_lhmedium_nod0 || HLT_e140_lhloose_nod0")));
	passedMuTrigger= ((objTool->IsTrigPassed("HLT_mu26_ivarmedium || HLT_mu50 ")));
	passedGammaTrigger=(objTool->IsTrigPassed("HLT_g140_loose"));
	if(isData){
	  passedMETTrigger = objTool->IsMETTrigPassed("HLT_xe110_mht_L1XE50"); 
	}
	else{
	  passedMETTrigger = objTool->IsMETTrigPassed("HLT_xe100_mht_L1XE50"); 
	}
      }
      passedMETTrigger = objTool->IsMETTrigPassed(); 
      passedMultiJetTrigger = objTool->IsTrigPassed("HLT_6j45_0eta240");
      passedTauTrigger = objTool->IsTrigPassed("tau25_medium1_tracktwo");// this will never pass because it's not in the derivation
    }
    
    if (passedElTrigger == 1 || passedMuTrigger == 1) passedLepTrigger = true;
    
    if (isyst == 0){
      if (passedMETTrigger){
	HSRA_noWgt->Fill(4,1);
	HSRA_mcWgt->Fill(4,mcWgt); 
	HSRA_allWgt->Fill(4,mcWgt);//*btagWgt*lepWgt*trigWgt*puWgt);
	
	HSRB_noWgt->Fill(4,0.46754945);//Change back to 1 
	HSRB_mcWgt->Fill(4,mcWgt); 
	HSRB_allWgt->Fill(4,1);
	
	HSRC_noWgt->Fill(4,1);
 	HSRC_mcWgt->Fill(4,mcWgt); 
	HSRC_allWgt->Fill(4,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
      }

      if (passedLepTrigger){
	HCRgamma_noWgt->Fill(4,1);
	HCRgamma_mcWgt->Fill(4,mcWgt); 
	HCRgamma_allWgt->Fill(4,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);

	
	HCRTemu_noWgt->Fill(4,1);
	HCRTemu_mcWgt->Fill(4,mcWgt);
	HCRTemu_allWgt->Fill(4,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
	
	HCRT1L_noWgt->Fill(4,1);
	HCRT1L_mcWgt->Fill(4,mcWgt); 
	HCRT1L_allWgt->Fill(4,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
	
	HCRW_noWgt->Fill(4,1);
	HCRW_mcWgt->Fill(4,mcWgt); 
	HCRW_allWgt->Fill(4,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
	
	HCRsT_noWgt->Fill(4,1);
	HCRsT_mcWgt->Fill(4,mcWgt);
	HCRsT_allWgt->Fill(4,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
      }
    }

    if (m_objs->getPrimVertex() < 1){
      isyst++;
      continue;
      //return EL::StatusCode::SUCCESS;
    }
    
    if (isyst == 0){
      if (passedMETTrigger){
	HSRA_noWgt->Fill(5,1);
	HSRA_mcWgt->Fill(5,mcWgt); 
	HSRA_allWgt->Fill(5,mcWgt);//*btagWgt*lepWgt*trigWgt*puWgt);

	HSRB_noWgt->Fill(5,0.46754945);//Change back to 1 
	HSRB_mcWgt->Fill(5,mcWgt); 
	HSRB_allWgt->Fill(5,1);

	HSRC_noWgt->Fill(5,1);
	HSRC_mcWgt->Fill(5,mcWgt); 
	HSRC_allWgt->Fill(5,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);

      }
      if (passedMuTrigger || passedElTrigger){
	HCRgamma_noWgt->Fill(5,1);
	HCRgamma_mcWgt->Fill(5,mcWgt); 
	HCRgamma_allWgt->Fill(5,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
      }


      if(passedElTrigger || passedMuTrigger){
	
	HCRTemu_noWgt->Fill(5,1);
	HCRTemu_mcWgt->Fill(5,mcWgt);
	HCRTemu_allWgt->Fill(5,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
	
	HCRT1L_noWgt->Fill(5,1);
	HCRT1L_mcWgt->Fill(5,mcWgt); 
	HCRT1L_allWgt->Fill(5,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
	
	HCRW_noWgt->Fill(5,1);
	HCRW_mcWgt->Fill(5,mcWgt); 
	HCRW_allWgt->Fill(5,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
	
	HCRsT_noWgt->Fill(5,1);
	HCRsT_mcWgt->Fill(5,mcWgt);
	HCRsT_allWgt->Fill(5,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
      }
    }

    
    if (nBadJet > 0){
      isyst++;
      continue;
      //return EL::StatusCode::SUCCESS;
    }
    
    if (isyst == 0){
      
      if (passedMETTrigger){
	HSRA_noWgt->Fill(6, 1);
	HSRA_mcWgt->Fill(6,mcWgt); 
	HSRA_allWgt->Fill(6,mcWgt);//*btagWgt*lepWgt*trigWgt*puWgt);

	HSRB_noWgt->Fill(6,0.46754945);//Change back to 1 
	HSRB_mcWgt->Fill(6,mcWgt); 
	HSRB_allWgt->Fill(6,1);

	HSRC_noWgt->Fill(6,1);
	HSRC_mcWgt->Fill(6,mcWgt); 
	HSRC_allWgt->Fill(6,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);

      }
      if (passedMuTrigger || passedElTrigger){
	HCRgamma_noWgt->Fill(6,1);
	HCRgamma_mcWgt->Fill(6,mcWgt); 
	HCRgamma_allWgt->Fill(6,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
      }


      if(passedElTrigger || passedMuTrigger){
	
	HCRTemu_noWgt->Fill(6,1);
	HCRTemu_mcWgt->Fill(6,mcWgt);
	HCRTemu_allWgt->Fill(6,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
	
	HCRT1L_noWgt->Fill(6,1);
	HCRT1L_mcWgt->Fill(6,mcWgt); 
	HCRT1L_allWgt->Fill(6,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
	
	HCRW_noWgt->Fill(6,1);
	HCRW_mcWgt->Fill(6,mcWgt); 
	HCRW_allWgt->Fill(6,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
	
	HCRsT_noWgt->Fill(6,1);
	HCRsT_mcWgt->Fill(6,mcWgt);
	HCRsT_allWgt->Fill(6,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
      }
    }
    
    
    
    if (nCosmicMu > 0){
      isyst++;
      continue;
      //return EL::StatusCode::SUCCESS;
    }
    
    if (isyst == 0){
      
      if (passedMETTrigger){
	HSRA_noWgt->Fill(7, 1);
	HSRA_mcWgt->Fill(7,mcWgt); 
	HSRA_allWgt->Fill(7,mcWgt);//*btagWgt*lepWgt*trigWgt*puWgt);

	HSRB_noWgt->Fill(7,0.46754945);//Change back to 1 
	HSRB_mcWgt->Fill(7,mcWgt); 
	HSRB_allWgt->Fill(7,1);

	HSRC_noWgt->Fill(7,1);
	HSRC_mcWgt->Fill(7,mcWgt); 
	HSRC_allWgt->Fill(7,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);

      }
      if (passedMuTrigger || passedElTrigger){
	HCRgamma_noWgt->Fill(7,1);
	HCRgamma_mcWgt->Fill(7,mcWgt); 
	HCRgamma_allWgt->Fill(7,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
      }
      

      if(passedElTrigger || passedMuTrigger){
	
	HCRTemu_noWgt->Fill(7,1);
	HCRTemu_mcWgt->Fill(7,mcWgt);
	HCRTemu_allWgt->Fill(7,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
	
	HCRT1L_noWgt->Fill(7,1);
	HCRT1L_mcWgt->Fill(7,mcWgt); 
	HCRT1L_allWgt->Fill(7,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
	
	HCRW_noWgt->Fill(7,1);
	HCRW_mcWgt->Fill(7,mcWgt); 
	HCRW_allWgt->Fill(7,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
	
	HCRsT_noWgt->Fill(7,1);
	HCRsT_mcWgt->Fill(7,mcWgt);
	HCRsT_allWgt->Fill(7,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
      }
    }


    if (nBadMu > 0){
      isyst++;
      continue;
      //return EL::StatusCode::SUCCESS;
    }
    

    if (isyst == 0){
      if (passedMETTrigger){
	HSRA_noWgt->Fill(8, 1);
	HSRA_mcWgt->Fill(8,mcWgt); 
	HSRA_allWgt->Fill(8,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);

	HSRB_noWgt->Fill(8,0.46754945);//Change back to 1 
	HSRB_mcWgt->Fill(8,mcWgt); 
	HSRB_allWgt->Fill(8,1);

	HSRC_noWgt->Fill(8,1);
	HSRC_mcWgt->Fill(8,mcWgt); 
	HSRC_allWgt->Fill(8,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);

      }
      if (passedMuTrigger || passedElTrigger){
	HCRgamma_noWgt->Fill(8,1);
	HCRgamma_mcWgt->Fill(8,mcWgt); 
	HCRgamma_allWgt->Fill(8,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
      }

      if(passedElTrigger || passedMuTrigger){
	
	HCRTemu_noWgt->Fill(8,1);
	HCRTemu_mcWgt->Fill(8,mcWgt);
	HCRTemu_allWgt->Fill(8,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
	
	HCRT1L_noWgt->Fill(8,1);
	HCRT1L_mcWgt->Fill(8,mcWgt); 
	HCRT1L_allWgt->Fill(8,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
	
	HCRW_noWgt->Fill(8,1);
	HCRW_mcWgt->Fill(8,mcWgt); 
	HCRW_allWgt->Fill(8,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
	
	HCRsT_noWgt->Fill(8,1);
	HCRsT_mcWgt->Fill(8,mcWgt);
	HCRsT_allWgt->Fill(8,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);
      }
      
    }
    

  // call the cutflow class now

    std::vector<TH1F*> SRAHists;
    SRAHists.push_back(HSRA_noWgt);
    SRAHists.push_back(HSRA_mcWgt);
    SRAHists.push_back(HSRA_allWgt);


    std::vector<TH1F*> SRBHists;
    SRBHists.push_back(HSRB_noWgt);
    SRBHists.push_back(HSRB_mcWgt);
    SRBHists.push_back(HSRB_allWgt);

    std::vector<TH1F*> CRgammaHists;
    CRgammaHists.push_back(HCRgamma_noWgt);
    CRgammaHists.push_back(HCRgamma_mcWgt);
    CRgammaHists.push_back(HCRgamma_allWgt);
    
    std::vector<TH1F*> SRCHists;
    SRCHists.push_back(HSRC_noWgt);
    SRCHists.push_back(HSRC_mcWgt);
    SRCHists.push_back(HSRC_allWgt);
    
    std::vector<TH1F*> CRTemuHists;
    CRTemuHists.push_back(HCRTemu_noWgt);
    CRTemuHists.push_back(HCRTemu_mcWgt);
    CRTemuHists.push_back(HCRTemu_allWgt);
    
    std::vector<TH1F*> CRT1LHists;
    CRT1LHists.push_back(HCRT1L_noWgt);
    CRT1LHists.push_back(HCRT1L_mcWgt);
    CRT1LHists.push_back(HCRT1L_allWgt);
    
    std::vector<TH1F*> CRWHists;
    CRWHists.push_back(HCRW_noWgt);
    CRWHists.push_back(HCRW_mcWgt);
    CRWHists.push_back(HCRW_allWgt);
    
    std::vector<TH1F*> CRsTHists;
    CRsTHists.push_back(HCRsT_noWgt);
    CRsTHists.push_back(HCRsT_mcWgt);
    CRsTHists.push_back(HCRsT_allWgt);
    

    std::shared_ptr<CalculateVariables> m_varCalc(new CalculateVariables ( m_objs, isTruthFile, doPhotons));
    
    std::unique_ptr<PreliminarySel> m_regions(new PreliminarySel (*m_varCalc));



    double SFmctbbll = 1;
    
    if (!isData && m_fileType != "DAOD_TRUTH1" ) {
      PUSumOfWeights = objTool->GetSumOfWeights(mcChannel); 
      lepWgt = m_varCalc->leptonSF;
      
    }
    else{
      PUSumOfWeights = 0;
      lepWgt = 1;
    }
    
   

    // Temp for debugging
    if (isyst == 0){
      std::unique_ptr<Cutflows> m_cutflows (new Cutflows (*m_varCalc, *m_regions, SRAHists, SRBHists, SRCHists, CRTemuHists, CRT1LHists, CRWHists, CRsTHists, CRgammaHists, btagWgt, lepWgt, trigWgt, puWgt, mcWgt, EventNumber, passedMETTrigger, passedLepTrigger, passedGammaTrigger, truthfilt_MET));
    }
    
    if ( m_fileType != "DAOD_TRUTH1"){
      
      if (m_regions->interestingRegion || RunningLocally){
       //for (int i = 0; i < m_treeServiceVector.size(); ++i) {
	(m_treeServiceVector[isyst])->fillTree(m_objs, *m_regions, *m_varCalc, *checkMC,m_finalSumOfWeights, m_initialSumOfWeights, puWgt, SFmctbbll, passedMETTrigger, passedMuTrigger, passedElTrigger, passedGammaTrigger, passedMultiJetTrigger, PUSumOfWeights, truthfilt_MET, truthfilt_HT, coreFlags, sctFlag, m_runNumber, renormedMcWgt);
       }
      //}
    }
    // not running on reco. fill everything for TRUTH
    else{
      
       //for (int i = 0; i < m_treeServiceVector.size(); ++i) {
      (m_treeServiceVector[isyst])->fillTree(m_objs, *m_regions, *m_varCalc, *checkMC,m_finalSumOfWeights, m_initialSumOfWeights, puWgt, SFmctbbll, passedMETTrigger, passedMuTrigger, passedElTrigger, passedGammaTrigger, passedMultiJetTrigger, PUSumOfWeights, truthfilt_MET, truthfilt_HT , coreFlags, sctFlag, m_runNumber, renormedMcWgt);
    //}
   }
      
    isyst++;
  
  }
  



  std::cout << "Tree service vector size:" << m_treeServiceVector.size() << std::endl;  

  //  std::cout<<"Finished Event loop succesfully"<<std::endl;
  
  return EL::StatusCode::SUCCESS;
}



  EL::StatusCode MyxAODAnalysis :: postExecute ()
{
  // Here you do everything that needs to be done after the main event
  // processing.  This is typically very rare, particularly in user
  // code.  It is mainly used in implementing the NTuplSevc.
  return EL::StatusCode::SUCCESS;
}
 
 

 EL::StatusCode MyxAODAnalysis :: finalize ()
 {
  // This method is the mirror image of initialize(), meaning it gets
  // called after the last event has been processed on the worker node
  // and allows you to finish up any objects you created in
  // initialize() before they are written to disk.  This is actually
  // fairly rare, since this happens separately for each worker node.
  // Most of the time you want to do your post-processing on the
  // submission node after all your histogram outputs have been
  // merged.  This is different from histFinalize() in that it only
  // gets called on worker nodes that processed input events.


  const char* APP_NAME = "MyxAODAnalysis";




  
  // Do SRA Cuts here
  
  std::vector<std::string> SRACutList; 
  SRACutList.push_back("NONE");
  SRACutList.push_back("GRL");
  SRACutList.push_back("LAr & Tile");
  SRACutList.push_back("MET Trigger");
  SRACutList.push_back("Primary Vertex >= 1");
  SRACutList.push_back("Jet/MET");
  SRACutList.push_back("Cosmic Muons");
  SRACutList.push_back("Muon Cleaning");
  SRACutList.push_back("ETMiss > 250");
  SRACutList.push_back("nBaselineLepton ==0");
  SRACutList.push_back("njets >=6");
  SRACutList.push_back("nbjets >= 4");  
  SRACutList.push_back("minDPhi(j4-MET)>0.4"); 
  SRACutList.push_back("tau veto");
  SRACutList.push_back("maxDR>2.5");
  SRACutList.push_back("minDR>2.5");
  SRACutList.push_back("hcand>80");
  SRACutList.push_back("pTb1>200");
  SRACutList.push_back("meff>1000");
  SRACutList.push_back("meff>1000<1200");
  SRACutList.push_back("meff>1200<1500");
  SRACutList.push_back("meff>1500");
  SRACutList.push_back("m_CT > 450");
  

  //m_lumiScaled = 1;

  bool doSRACutflow = true;
  if (doSRACutflow){

  std::cout << "Number of weighted events total:"  << PUSumOfWeights << std::endl;
  
  std::cout << "SRA Selections:" << std::endl;
  std::cout << "Raw Events" << std::endl;
  std::cout << "Sum Of Weights = " << h_SumOfWeights->Integral() << std::endl;
  std::cout << "Cut # " << std::setw(25) << "Cut Name " << std::setw(50) << "Events Passing Selection " << std::setw(25) << " Relative Efficiency" <<std::setw(25) <<" Absolute Efficiency  "  <<std::endl;
  for(size_t icut=0; icut<=SRACutList.size()-1; ++icut)
    {
      if (icut == 0){
	std::cout << std::setw(25) <<std::left << icut+1 << std::setw(25)  << std::left << SRACutList[icut] << std::setw(25) << std::right << HSRA_noWgt->GetBinContent(icut+1) << std::setw(25)<< std::right << std::setprecision(5) << HSRA_noWgt->GetBinContent(icut+1)/HSRA_noWgt->GetBinContent(icut+1) << std::setw(25) <<  std::right << HSRA_noWgt->GetBinContent(icut+1)/HSRA_noWgt->GetBinContent(1)   <<std::endl;
      }
      else{
	std::cout << std::setw(25) <<std::left << icut+1 << std::setw(25)  << std::left << SRACutList[icut] << std::setw(25) << std::right << HSRA_noWgt->GetBinContent(icut+1) << std::setw(25)<< std::right << std::setprecision(5) << HSRA_noWgt->GetBinContent(icut+1)/HSRA_noWgt->GetBinContent(icut) << std::setw(25) <<  std::right << HSRA_noWgt->GetBinContent(icut+1)/HSRA_noWgt->GetBinContent(1)   <<std::endl;
      }
    }  
  
  std::cout << "Scaled Events" << std::endl;
  std::cout << "Cut # " << std::setw(25) << "Cut Name " << std::setw(50) << "Events Passing Selection " << std::setw(25) << " Relative Efficiency" <<std::setw(25) <<" Absolute Efficiency  "  <<std::endl;
  for(size_t icut=0; icut<=SRACutList.size()-1; ++icut)
    {

    if (icut == 0){
      std::cout << std::setw(25) <<std::left << icut+1 << std::setw(25)  << std::left << SRACutList[icut] << std::setw(25) << std::right << HSRA_allWgt->GetBinContent(icut+1) << std::setw(25)<< std::right << std::setprecision(5) << HSRA_allWgt->GetBinContent(icut+1)/(HSRA_allWgt->GetBinContent(icut+1)) << std::setw(25) <<  std::right << HSRA_allWgt->GetBinContent(icut+1)/(HSRA_allWgt->GetBinContent(1))   <<std::endl;
      }
      else{
	std::cout << std::setw(25) <<std::left << icut+1 << std::setw(25)  << std::left << SRACutList[icut] << std::setw(25) << std::right << HSRA_allWgt->GetBinContent(icut+1) << std::setw(25)<< std::right << std::setprecision(5) << HSRA_allWgt->GetBinContent(icut+1)/(HSRA_allWgt->GetBinContent(icut)) << std::setw(25) <<  std::right << HSRA_allWgt->GetBinContent(icut+1)/(HSRA_allWgt->GetBinContent(1))   <<std::endl;
      }
  
    }  

  }
  

  std::vector<std::string> SRBCutList; 
  SRBCutList.push_back("NONE");
  SRBCutList.push_back("GRL");
  SRBCutList.push_back("LAr & Tile");
  SRBCutList.push_back("MET Trigger");
  SRBCutList.push_back("Primary Vertex >= 1");
  SRBCutList.push_back("Jet/MET");
  SRBCutList.push_back("Cosmic Muons");
  SRBCutList.push_back("Muon Cleaning");
  SRBCutList.push_back("ETMiss > 300");
  SRBCutList.push_back("nBaselineLep == 0");
  SRBCutList.push_back("njets >= 4");
  SRBCutList.push_back("nbjets >= 3");
  SRBCutList.push_back(">50<140");
  SRBCutList.push_back("non b-tagged leading jet");
  SRBCutList.push_back("pTj1>300");
  SRBCutList.push_back("meff>1000");
  SRBCutList.push_back("tau veto");
  SRBCutList.push_back("minDelPhi(j1_4-MET) >0.4");
  SRBCutList.push_back("DelPhi(j1-MET)");
  SRBCutList.push_back("NA");
  SRBCutList.push_back("NA");
  SRBCutList.push_back("NA");
  SRBCutList.push_back("NA");

  bool doSRBCutflow = true;
  if (doSRBCutflow){

  std::cout << "Number of weighted events total:"  << PUSumOfWeights << std::endl;
  
  std::cout << "SRB Selections:" << std::endl;
  std::cout << "Raw Events" << std::endl;
  std::cout << "Sum Of Weights = " << h_SumOfWeights->Integral() << std::endl;
  std::cout << "Cut # " << std::setw(25) << "Cut Name " << std::setw(50) << "Events Passing Selection " << std::setw(25) << " Relative Efficiency" <<std::setw(25) <<" Absolute Efficiency  "  <<std::endl;
  for(size_t icut=0; icut<=SRBCutList.size()-1; ++icut)
    {
      if (icut == 0){
	std::cout << std::setw(25) <<std::left << icut+1 << std::setw(25)  << std::left << SRBCutList[icut] << std::setw(25) << std::right << HSRB_noWgt->GetBinContent(icut+1) << std::setw(25)<< std::right << std::setprecision(5) << HSRB_noWgt->GetBinContent(icut+1)/HSRB_noWgt->GetBinContent(icut+1) << std::setw(25) <<  std::right << HSRB_noWgt->GetBinContent(icut+1)/HSRB_noWgt->GetBinContent(1)   <<std::endl;
      }
      else{
	std::cout << std::setw(25) <<std::left << icut+1 << std::setw(25)  << std::left << SRBCutList[icut] << std::setw(25) << std::right << HSRB_noWgt->GetBinContent(icut+1) << std::setw(25)<< std::right << std::setprecision(5) << HSRB_noWgt->GetBinContent(icut+1)/HSRB_noWgt->GetBinContent(icut) << std::setw(25) <<  std::right << HSRB_noWgt->GetBinContent(icut+1)/HSRB_noWgt->GetBinContent(1)   <<std::endl;
      }
    }  
  
  std::cout << "Scaled Events" << std::endl;
  std::cout << "Cut # " << std::setw(25) << "Cut Name " << std::setw(50) << "Events Passing Selection " << std::setw(25) << " Relative Efficiency" <<std::setw(25) <<" Absolute Efficiency  "  <<std::endl;
  for(size_t icut=0; icut<=SRBCutList.size()-1; ++icut)
    {

    if (icut == 0){
      std::cout << std::setw(25) <<std::left << icut+1 << std::setw(25)  << std::left << SRBCutList[icut] << std::setw(25) << std::right << HSRB_allWgt->GetBinContent(icut+1) << std::setw(25)<< std::right << std::setprecision(5) << HSRB_allWgt->GetBinContent(icut+1)/(HSRB_allWgt->GetBinContent(icut+1)) << std::setw(25) <<  std::right << HSRB_allWgt->GetBinContent(icut+1)/(HSRB_allWgt->GetBinContent(1))   <<std::endl;
      }
      else{
	std::cout << std::setw(25) <<std::left << icut+1 << std::setw(25)  << std::left << SRBCutList[icut] << std::setw(25) << std::right << HSRB_allWgt->GetBinContent(icut+1) << std::setw(25)<< std::right << std::setprecision(5) << HSRB_allWgt->GetBinContent(icut+1)/(HSRB_allWgt->GetBinContent(icut)) << std::setw(25) <<  std::right << HSRB_allWgt->GetBinContent(icut+1)/(HSRB_allWgt->GetBinContent(1))   <<std::endl;
      }
  
    }  

  }







  std::vector<std::string> CRT1LCutList; 
  CRT1LCutList.push_back("NONE");
  CRT1LCutList.push_back("GRL");
  CRT1LCutList.push_back("LAr & Tile");
  CRT1LCutList.push_back("1L Trigger");
  CRT1LCutList.push_back("Primary Vertex >= 1");
  CRT1LCutList.push_back("Jet/MET");
  CRT1LCutList.push_back("Cosmic Muons");
  CRT1LCutList.push_back("Muon Cleaning");
  CRT1LCutList.push_back("nBaseline/Signal Lep == 1");
  CRT1LCutList.push_back("pTL > 26");
  CRT1LCutList.push_back("Trigger matched");
  CRT1LCutList.push_back("njets = 2,3,4");
  CRT1LCutList.push_back("pTj1 > 50, pTj2 > 50");
  CRT1LCutList.push_back("pTj4 < 50");
  CRT1LCutList.push_back("nbjets >= 3");
  CRT1LCutList.push_back("leading b");
  CRT1LCutList.push_back("secondary b");
  CRT1LCutList.push_back("JetMET dphi> 0.4");
  CRT1LCutList.push_back("MET/mEff > 0.25");
  CRT1LCutList.push_back("ETMiss > 150");
  CRT1LCutList.push_back("m_bb < 200");
  CRT1LCutList.push_back("m_CT > 150");
  

  std::vector<std::string> CRTemuCutList; 
  CRTemuCutList.push_back("NONE");
  CRTemuCutList.push_back("GRL");
  CRTemuCutList.push_back("LAr & Tile");
  CRTemuCutList.push_back("1L Trigger");
  CRTemuCutList.push_back("Primary Vertex >= 1");
  CRTemuCutList.push_back("Jet/MET");
  CRTemuCutList.push_back("Cosmic Muons");
  CRTemuCutList.push_back("Muon Cleaning");
  CRTemuCutList.push_back("nBaseline/Signal Lep == 1");
  CRTemuCutList.push_back("pTL > 26");
  CRTemuCutList.push_back("Trigger matched");
  CRTemuCutList.push_back("nbjets = 2");
  CRTemuCutList.push_back("100 < ETMiss < 200");
  CRTemuCutList.push_back("mT > 140");
  CRTemuCutList.push_back("mblmin < 170");
  CRTemuCutList.push_back("amT2 > 250");
  CRTemuCutList.push_back("meff > 450");
  CRTemuCutList.push_back("ETmiss significance");
  CRTemuCutList.push_back("DPhiJetMET");

  std::vector<std::string> tbMETSRCutList; 
  tbMETSRCutList.push_back("NONE");
  tbMETSRCutList.push_back("GRL");
  tbMETSRCutList.push_back("LAr & Tile");
  tbMETSRCutList.push_back("1L Trigger");
  tbMETSRCutList.push_back("Primary Vertex >= 1");
  tbMETSRCutList.push_back("Jet/MET");
  tbMETSRCutList.push_back("Cosmic Muons");
  tbMETSRCutList.push_back("Muon Cleaning");
  tbMETSRCutList.push_back("nBaseline/Signal Lep == 1");
  tbMETSRCutList.push_back("pTL > 26");
  tbMETSRCutList.push_back("Trigger matched");
  tbMETSRCutList.push_back("nbjets >= 3");
  tbMETSRCutList.push_back("ETMiss > 200");
  tbMETSRCutList.push_back("mT > 140");
  tbMETSRCutList.push_back("amT2 > 250");
  tbMETSRCutList.push_back("meff > 450");
  tbMETSRCutList.push_back("metSig > 8");
  tbMETSRCutList.push_back("mblmin < 170");
  tbMETSRCutList.push_back("JetMET dphi> 0.4");
  tbMETSRCutList.push_back("m_bb > 200");
  

  bool doCRT1LCutflow = false;
  if (doCRT1LCutflow){

  std::cout << "Number of weighted events total:"  << PUSumOfWeights << std::endl;
  
  std::cout << "CRT1L Selections:" << std::endl;
  std::cout << "Raw Events" << std::endl;
  std::cout << "Sum Of Weights = " << h_SumOfWeights->Integral() << std::endl;
  std::cout << "Cut # " << std::setw(25) << "Cut Name " << std::setw(50) << "Events Passing Selection " << std::setw(25) << " Relative Efficiency" <<std::setw(25) <<" Absolute Efficiency  "  <<std::endl;
  for(size_t icut=0; icut<=CRT1LCutList.size()-1; ++icut)
    {
      if (icut == 0){
	std::cout << std::setw(25) <<std::left << icut+1 << std::setw(25)  << std::left << CRT1LCutList[icut] << std::setw(25) << std::right << HCRT1L_noWgt->GetBinContent(icut+1) << std::setw(25)<< std::right << std::setprecision(5) << HCRT1L_noWgt->GetBinContent(icut+1)/HCRT1L_noWgt->GetBinContent(icut+1) << std::setw(25) <<  std::right << HCRT1L_noWgt->GetBinContent(icut+1)/HCRT1L_noWgt->GetBinContent(1)   <<std::endl;
      }
      else{
	std::cout << std::setw(25) <<std::left << icut+1 << std::setw(25)  << std::left << CRT1LCutList[icut] << std::setw(25) << std::right << HCRT1L_noWgt->GetBinContent(icut+1) << std::setw(25)<< std::right << std::setprecision(5) << HCRT1L_noWgt->GetBinContent(icut+1)/HCRT1L_noWgt->GetBinContent(icut) << std::setw(25) <<  std::right << HCRT1L_noWgt->GetBinContent(icut+1)/HCRT1L_noWgt->GetBinContent(1)   <<std::endl;
      }
    }  
  
  std::cout << "Scaled Events" << std::endl;
  std::cout << "Cut # " << std::setw(25) << "Cut Name " << std::setw(50) << "Events Passing Selection " << std::setw(25) << " Relative Efficiency" <<std::setw(25) <<" Absolute Efficiency  "  <<std::endl;
  for(size_t icut=0; icut<=CRT1LCutList.size()-1; ++icut)
    {

    if (icut == 0){
      std::cout << std::setw(25) <<std::left << icut+1 << std::setw(25)  << std::left << CRT1LCutList[icut] << std::setw(25) << std::right << m_lumiScaled*HCRT1L_allWgt->GetBinContent(icut+1) << std::setw(25)<< std::right << std::setprecision(5) << m_lumiScaled*HCRT1L_allWgt->GetBinContent(icut+1)/(m_lumiScaled*HCRT1L_allWgt->GetBinContent(icut+1)) << std::setw(25) <<  std::right << m_lumiScaled*HCRT1L_allWgt->GetBinContent(icut+1)/(m_lumiScaled*HCRT1L_allWgt->GetBinContent(1))   <<std::endl;
      }
      else{
	std::cout << std::setw(25) <<std::left << icut+1 << std::setw(25)  << std::left << CRT1LCutList[icut] << std::setw(25) << std::right << m_lumiScaled*HCRT1L_allWgt->GetBinContent(icut+1) << std::setw(25)<< std::right << std::setprecision(5) << m_lumiScaled*HCRT1L_allWgt->GetBinContent(icut+1)/(m_lumiScaled*HCRT1L_allWgt->GetBinContent(icut)) << std::setw(25) <<  std::right << m_lumiScaled*HCRT1L_allWgt->GetBinContent(icut+1)/(m_lumiScaled*HCRT1L_allWgt->GetBinContent(1))   <<std::endl;
      }
  
    }  

  }
  
  bool dotbMETSRCutflow = false;
  if (dotbMETSRCutflow){

  std::cout << "Number of weighted events total:"  << PUSumOfWeights << std::endl;
  
  std::cout << "tbMET SRB Selections:" << std::endl;
  std::cout << "Raw Events" << std::endl;
  std::cout << "Sum Of Weights = " << h_SumOfWeights->Integral() << std::endl;
  std::cout << "Cut # " << std::setw(25) << "Cut Name " << std::setw(50) << "Events Passing Selection " << std::setw(25) << " Relative Efficiency" <<std::setw(25) <<" Absolute Efficiency  "  <<std::endl;
  for(size_t icut=0; icut<=tbMETSRCutList.size()-1; ++icut)
    {
      if (icut == 0){
	std::cout << std::setw(25) <<std::left << icut+1 << std::setw(25)  << std::left << tbMETSRCutList[icut] << std::setw(25) << std::right << HCRgamma_noWgt->GetBinContent(icut+1) << std::setw(25)<< std::right << std::setprecision(5) << HCRgamma_noWgt->GetBinContent(icut+1)/HCRgamma_noWgt->GetBinContent(icut+1) << std::setw(25) <<  std::right << HCRgamma_noWgt->GetBinContent(icut+1)/HCRgamma_noWgt->GetBinContent(1)   <<std::endl;
      }
      else{
	std::cout << std::setw(25) <<std::left << icut+1 << std::setw(25)  << std::left << tbMETSRCutList[icut] << std::setw(25) << std::right << HCRgamma_noWgt->GetBinContent(icut+1) << std::setw(25)<< std::right << std::setprecision(5) << HCRgamma_noWgt->GetBinContent(icut+1)/HCRgamma_noWgt->GetBinContent(icut) << std::setw(25) <<  std::right << HCRgamma_noWgt->GetBinContent(icut+1)/HCRgamma_noWgt->GetBinContent(1)   <<std::endl;
      }
    }  
  
  std::cout << "Scaled Events" << std::endl;
  std::cout << "Cut # " << std::setw(25) << "Cut Name " << std::setw(50) << "Events Passing Selection " << std::setw(25) << " Relative Efficiency" <<std::setw(25) <<" Absolute Efficiency  "  <<std::endl;
  for(size_t icut=0; icut<=tbMETSRCutList.size()-1; ++icut)
    {

    if (icut == 0){
      std::cout << std::setw(25) <<std::left << icut+1 << std::setw(25)  << std::left << tbMETSRCutList[icut] << std::setw(25) << std::right << m_lumiScaled*HCRgamma_allWgt->GetBinContent(icut+1) << std::setw(25)<< std::right << std::setprecision(5) << m_lumiScaled*HCRgamma_allWgt->GetBinContent(icut+1)/(m_lumiScaled*HCRgamma_allWgt->GetBinContent(icut+1)) << std::setw(25) <<  std::right << m_lumiScaled*HCRgamma_allWgt->GetBinContent(icut+1)/(m_lumiScaled*HCRgamma_allWgt->GetBinContent(1))   <<std::endl;
      }
      else{
	std::cout << std::setw(25) <<std::left << icut+1 << std::setw(25)  << std::left << tbMETSRCutList[icut] << std::setw(25) << std::right << m_lumiScaled*HCRgamma_allWgt->GetBinContent(icut+1) << std::setw(25)<< std::right << std::setprecision(5) << m_lumiScaled*HCRgamma_allWgt->GetBinContent(icut+1)/(m_lumiScaled*HCRgamma_allWgt->GetBinContent(icut)) << std::setw(25) <<  std::right << m_lumiScaled*HCRgamma_allWgt->GetBinContent(icut+1)/(m_lumiScaled*HCRgamma_allWgt->GetBinContent(1))   <<std::endl;
      }
  
    }  

  }
  


  std::vector<std::string> SRCCutList; 
  SRCCutList.push_back("NONE");
  SRCCutList.push_back("GRL");
  SRCCutList.push_back("LAr & Tile");
  SRCCutList.push_back("MET trigger");
  SRCCutList.push_back("Primary Vertex >= 1");
  SRCCutList.push_back("Jet/MET");
  SRCCutList.push_back("Cosmic Muons");
  SRCCutList.push_back("Muon Cleaning");
  SRCCutList.push_back("MET > 250");
  SRCCutList.push_back("nBJets >= 3");
  SRCCutList.push_back("nJets >= 4");
  SRCCutList.push_back("nBaselineLep == 0");
  SRCCutList.push_back("minDelPhi >0.4");
  SRCCutList.push_back("metsig>25");
  SRCCutList.push_back("metsig>27");
  SRCCutList.push_back("metsig>30");
  SRCCutList.push_back("metsig>32");
  SRCCutList.push_back("NA");
  SRCCutList.push_back("NA");
  SRCCutList.push_back("NA");
  SRCCutList.push_back("NA");
  SRCCutList.push_back("NA");
  SRCCutList.push_back("NA");
  SRCCutList.push_back("NA");


  

  bool doSRCCutflow = true;
  if (doSRCCutflow){

  std::cout << "Number of weighted events total:"  << PUSumOfWeights << std::endl;
  
  std::cout << "SRC Selections:" << std::endl;
  std::cout << "Raw Events" << std::endl;
  std::cout << "Sum Of Weights = " << h_SumOfWeights->Integral() << std::endl;
  std::cout << "Cut # " << std::setw(25) << "Cut Name " << std::setw(50) << "Events Passing Selection " << std::setw(25) << " Relative Efficiency" <<std::setw(25) <<" Absolute Efficiency  "  <<std::endl;
  for(size_t icut=0; icut<=SRCCutList.size()-1; ++icut)
    {
      if (icut == 0){
	std::cout << std::setw(25) <<std::left << icut+1 << std::setw(25)  << std::left << SRCCutList[icut] << std::setw(25) << std::right << HSRC_noWgt->GetBinContent(icut+1) << std::setw(25)<< std::right << std::setprecision(5) << HSRC_noWgt->GetBinContent(icut+1)/HSRC_noWgt->GetBinContent(icut+1) << std::setw(25) <<  std::right << HSRC_noWgt->GetBinContent(icut+1)/HSRC_noWgt->GetBinContent(1)   <<std::endl;
      }
      else{
	std::cout << std::setw(25) <<std::left << icut+1 << std::setw(25)  << std::left << SRCCutList[icut] << std::setw(25) << std::right << HSRC_noWgt->GetBinContent(icut+1) << std::setw(25)<< std::right << std::setprecision(5) << HSRC_noWgt->GetBinContent(icut+1)/HSRC_noWgt->GetBinContent(icut) << std::setw(25) <<  std::right << HSRC_noWgt->GetBinContent(icut+1)/HSRC_noWgt->GetBinContent(1)   <<std::endl;
      }
    }  
  
  std::cout << "Scaled Events" << std::endl;
  std::cout << "Cut # " << std::setw(25) << "Cut Name " << std::setw(50) << "Events Passing Selection " << std::setw(25) << " Relative Efficiency" <<std::setw(25) <<" Absolute Efficiency  "  <<std::endl;
  for(size_t icut=0; icut<=SRCCutList.size()-1; ++icut)
    {

    if (icut == 0){
      std::cout << std::setw(25) <<std::left << icut+1 << std::setw(25)  << std::left << SRCCutList[icut] << std::setw(25) << std::right << HSRC_allWgt->GetBinContent(icut+1) << std::setw(25)<< std::right << std::setprecision(5) << HSRC_allWgt->GetBinContent(icut+1)/(HSRC_allWgt->GetBinContent(icut+1)) << std::setw(25) <<  std::right << HSRC_allWgt->GetBinContent(icut+1)/(HSRC_allWgt->GetBinContent(1))   <<std::endl;
      }
      else{
	std::cout << std::setw(25) <<std::left << icut+1 << std::setw(25)  << std::left << SRCCutList[icut] << std::setw(25) << std::right << HSRC_allWgt->GetBinContent(icut+1) << std::setw(25)<< std::right << std::setprecision(5) << HSRC_allWgt->GetBinContent(icut+1)/(HSRC_allWgt->GetBinContent(icut)) << std::setw(25) <<  std::right << HSRC_allWgt->GetBinContent(icut+1)/(HSRC_allWgt->GetBinContent(1))   <<std::endl;
      }
  
    }  

  }
  



  std::cout << "Sum of Pile up = " << HSumOfPileUp->GetBinContent(1) << std::endl;
  std::cout << "Sum of number of events processed = " << noWeightHist->GetBinContent(1) << std::endl;
  std::cout << "Sum of analysis weights = " << sherpaWeightHist->GetBinContent(1) << std::endl;
  
  
  // GRL
  
  if (m_grl) {
    delete m_grl;
    m_grl = 0;
    
  }
 
  
  return EL::StatusCode::SUCCESS;
 }



EL::StatusCode MyxAODAnalysis :: histFinalize ()
{
  // This method is the mirror image of histInitialize(), meaning it
  // gets called after the last event has been processed on the worker
  // node and allows you to finish up any objects you created in
  // histInitialize() before they are written to disk.  This is
  // actually fairly rare, since this happens separately for each
  // worker node.  Most of the time you want to do your
  // post-processing on the submission node after all your histogram
  // outputs have been merged.  This is different from finalize() in
  // that it gets called on all worker nodes regardless of whether
  // they processed input events.

  return EL::StatusCode::SUCCESS;
}
