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
#include "MyAnalysis/MapVariables.h"
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
  std::string period= "period";
  int foundDataPeriod =m_fileName.find(period);

  if (foundData != std::string::npos){
    isData = 1;
    std::cout << "Running on a data sample" << std::endl;
    if(foundDataPeriod != std::string::npos){
      std::cout<<"Data period =="<<m_fileName.at(foundDataPeriod+period.length())<<std::endl;
    }
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
    m_fileType = "DAOD_SUSY7";    
  }

  HSumOfPileUp = new TH1F("HSumOfPileUp","HSumOfPileUp",1, 0.5, 1.5);
  noWeightHist = new TH1F("h_noWeights","h_noWeightHist",1 , 0.5, 1.5);
  sherpaWeightHist = new TH1F("h_sherpaWeights","h_sherpaWeightHist",1 , 0.5, 1.5);
  renormedSherpaWeightHist = new TH1F("h_RenormedSherpaWeights","h_RenormedSherpaWeightHist",1 , 0.5, 1.5);
  h_SumOfWeights = new TH1D("h_SumOfWeights","h_SumOfWeights",1 , 0.5, 1.5);
  h_SumOfWeightsSquared = new TH1D("h_SumOfWeightsSquared","h_SumOfWeightsSquared",1 , 0.5, 1.5);


  noWeightHist->SetDirectory (wk()->getOutputFile("output"));
  sherpaWeightHist->SetDirectory (wk()->getOutputFile("output"));
  h_SumOfWeights->SetDirectory (wk()->getOutputFile("output"));
  h_SumOfWeightsSquared->SetDirectory (wk()->getOutputFile("output"));
  renormedSherpaWeightHist->SetDirectory (wk()->getOutputFile("output"));





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
    std::string derivationName = "DAOD_SUSY7"; //need to replace by appropriate name
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
  std::cout<<"Got the MetaData"<<std::endl;
  if (MetaData) {
    std::cout<<"In metadata"<<std::endl;
    MetaData->LoadTree(0);
    std::cout<<"Loaded the tree"<<std::endl;
    m_isDerivation = !MetaData->GetBranch("StreamAOD");
    std::cout<<"Get Branch StreamAOD passed"<<std::endl;
  }

return EL::StatusCode::SUCCESS;
}



EL::StatusCode MyxAODAnalysis :: initialize ()
{
  std::cout<<"In initialise"<<std::endl;
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
  //Assigning the lumicalc files
  std::vector<std::string> lumicalcFiles;


  const xAOD::EventInfo* eventInfo_init =0;
  if (! m_event->retrieve(eventInfo_init, "EventInfo").isSuccess() ){
    Error("execute()","Failed to retrieve event info collection, exiting!!");
  }

    bool isMC = false;	
  if(eventInfo_init->eventType( xAOD::EventInfo::IS_SIMULATION) ){
    isMC = true; 
  }

  double xsecteff = -1;    
  double filtereff = -1;
  if(isMC){
    mcChannel = eventInfo_init->mcChannelNumber();
    //std::cout << "Looking for xsec for " << mcChannel << std::endl;
    //getting metdata from the Map (MapVariables.cxx) using the text file in format as MGPy8EG_A14N23LO_BB_onestepN2hN1.txt
    std::unique_ptr<MapVariables> m_mappedVars (new MapVariables (PathResolverFindCalibFile("MyAnalysis/MyAnalysis/MGPy8EG_A14N23LO_BB_onestepN2hN1.txt")));
    std::unique_ptr<MapVariables> m_mappedBkgVars (new MapVariables (PathResolverFindCalibFile("MyAnalysis/MyAnalysis/susy_crossSections_13TeV.txt")));
    bool checkxSecMap = m_mappedVars->finder(mcChannel,m_mappedVars->xSecMap);
    bool checkfilterMap = m_mappedVars->finder(mcChannel,m_mappedVars->filterEffMap);
    if (checkxSecMap && checkfilterMap){ //does this mcID exist in signal map? 
      xsecteff = m_mappedVars->xSecMap[mcChannel];
      filtereff= m_mappedVars->filterEffMap[mcChannel];
    }
    else {
      checkxSecMap = m_mappedBkgVars->finder(mcChannel, m_mappedBkgVars->xSecMap);
      checkfilterMap = m_mappedBkgVars->finder(mcChannel, m_mappedBkgVars->filterEffMap);
      if (checkxSecMap && checkfilterMap){//does mcID exist in Bkg map?
	xsecteff = m_mappedBkgVars->xSecMap[mcChannel];
	filtereff= m_mappedBkgVars->filterEffMap[mcChannel];
      }
      else {
	std::cout<<"ERROR: mcID does not exist in Map"<<std::endl;
	xsecteff = 1.;
	filtereff = 1.;
	return EL::StatusCode::FAILURE;
      }
    }
  }
  else {//Not MC
    xsecteff=1;
    filtereff=1;
    }
  //lumiScaled gives scaling to 1ifb
  std::cout<<"Got a cross section of; "<<xsecteff<<std::endl;
  m_lumiScaled = (1000*xsecteff*filtereff)/m_finalSumOfWeights;

  //Getting the run number of the file to determine MC16a vs MC16c
  int periodNumber = eventInfo_init->runNumber();
  std::cout<<"MC production period  Number; "<<periodNumber<<std::endl;
  bool isMC16a = (periodNumber == 284500);
  bool isMC16c = (periodNumber == 300000);
  

  bool isMC15a = false;
  bool isMC15b = false;
  bool isMC15c = false;

  std::cout << "which MC is this: A, B, C, 16a, 16c" << isMC15a << isMC15b << isMC15c << isMC16a <<isMC16c<<std::endl;
  if(isMC16a)
    {
      lumicalcFiles.push_back(PathResolverFindCalibFile("MyAnalysis/MyAnalysis/PileUp/PHYS_StandardGRL_All_Good_25ns_276262-284484_OflLumi-13TeV-008.root"));
      lumicalcFiles.push_back(PathResolverFindCalibFile("MyAnalysis/MyAnalysis/PileUp/PHYS_StandardGRL_All_Good_25ns_297730-311481_OflLumi-13TeV-009.root"));
    }
  if(isMC16c){lumicalcFiles.push_back(PathResolverFindCalibFile("MyAnalysis/MyAnalysis/PileUp/physics_25ns_Triggerno17e33prim.lumicalc.OflLumi-13TeV-001.root"));}
  std::cout << "Passed Lumi Calc Files" << std::endl;  

    
  //Assigining the config files for MC15
  std::vector<std::string> confFiles;
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
  ANA_CHECK( objTool->setProperty("ConfigFile", PathResolverFindCalibFile("MyAnalysis/MyAnalysis//Sbottom_multiB_21.2.31.conf")));
  ANA_CHECK(objTool->setBoolProperty("UseBtagging", true));
  //CHECK( objTool->setProperty("ShowerType", (int)m_showerType) );

  // skip this if we're not running on a reco file
  if (m_fileType != "DAOD_TRUTH1"){
    std::cout << "Adding Pile up stuff" << std::endl;
    ANA_CHECK(objTool->setProperty("PRWLumiCalcFiles",lumicalcFiles));
    ANA_CHECK(objTool->setBoolProperty("AutoconfigurePRWTool",true));
    //CHECK(objTool->setProperty("PRWConfigFiles", confFiles));//Option for manually setting the config files
  }
  
  
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
   objTool->msg().setLevel( MSG::ERROR);

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
  
  //Initialise output trees using TreeService for each systematic (nominal if not running)
  TTree *Temp;
  for(const auto& sysInfo : systInfoList){
    const CP::SystematicSet& sys = sysInfo.systset;
    
    //std::cout << "Systematic name: " + sys.name() << std::endl;
    //std::cout << "Systematic tree name: " + sys.name() << std::endl;

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
  
  //Write all of the trees
  for (int m = 0; m < (m_treeServiceVector.size()); m++){
    m_treeServiceVector[m]->writeTree();
    //std::cout<<"Wrote tree; "<<m_treeServiceVector[m]<<std::endl;	
  }

  

  
 
  return EL::StatusCode::SUCCESS;
}


EL::StatusCode MyxAODAnalysis :: execute ()
{
  
  // Here you do everything that needs to be done on every single
  // event, e.g. read input variables, apply cuts, and fill
  // histograms and trees.  This is where most of your actual analysis
  // code will go.

  const char* APP_NAME = "MyxAODAnalysis";

  
  //if (m_eventCounter >= 10){return EL::StatusCode::SUCCESS;}
  if ( (m_eventCounter % 1000) == 0 ) Info("execute()","Event Number = %i", m_eventCounter);
  //if ( (m_eventCounter % 100) == 0 ) Info("execute()","Event Number = %i", m_eventCounter);
  m_eventCounter++;

  
  bool isNominal = true;

  isyst = 0;
  

  for (const auto& sysInfo : systInfoList){
    const CP::SystematicSet& syst = sysInfo.systset;

    int year = 0;    
    int runNumber = 0;
    if (m_fileType != "DAOD_TRUTH1"){
      objTool->ApplyPRWTool();
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
    double electronTrigWgt = 1;
    double lepWgt = 1;
    double trigWgt = 1;
    double puWgt = 1;
    double JVTWgt = 1;
    double weight = 1;
    double truth_pTW = 0;
    
    bool isMC = false;	
    if(eventInfo->eventType( xAOD::EventInfo::IS_SIMULATION) ){
      isMC = true; // lets us do things correctly later
    }
    
    mcChannel = 0;
    
    double mcWgt = 1;
    double truthfilt_MET = 0;
    double truthfilt_HT = 0;
    double renormedMcWgt = 1;
	// Will fix this when the PMGTools cross section stuff is available
    
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
	
	if (m_fileType == "DAOD_TRUTH1"){
	  m_objs = new TruthObjectDef (m_event, objTool, store, mcChannel, EventNumber, mcWgt, m_lumiScaled, syst.name(), doPhotons,  m_metSignif);
	}
	else{
	  m_objs = new ObjectDef (m_event, objTool, store, mcChannel, EventNumber, mcWgt, m_lumiScaled, syst.name(), doPhotons, m_metSignif); 
	}

	// Initialise the class which sorts out the MC checks (if required)
	std::unique_ptr<MCChecks> checkMC (new MCChecks ());

	if (!isMC){
	  if(!(m_grl->passRunLB(*eventInfo))){
	    std::cout<<"Failed on good run lists"<<std::endl;
	    //if(!m_objs->removeFatJetTools(syst.name()))std::cout<<"Failed to remove FatJet tools"<<std::endl;
	    delete m_objs;
	    std::cout<<"In reset checkMC"<<std::endl;
	    checkMC.reset();
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
	  }
	  else {
	    checkMC->RetrieveWeights(m_event);
	  }
	}
	

	
	bool coreFlag = true;
	bool sctFlag = true;
	bool LArTileFlag=true;
	if (!isMC){
	  if ((eventInfo->errorState(xAOD::EventInfo::SCT) == xAOD::EventInfo::Error )){
	    sctFlag = false;
	    isyst++;
	    std::cout<<"Failed on SCT"<<std::endl;
	    //if(!m_objs->removeFatJetTools(syst.name()))std::cout<<"Failed to remove FatJet tools"<<std::endl;
	    delete m_objs;
	    checkMC.reset();
	    continue;
	  }
	  if (eventInfo->isEventFlagBitSet(xAOD::EventInfo::Core,18)){
	    coreFlag = false;
	    isyst++;
	    std::cout<<"Failed on core"<<std::endl;
	    //if(!m_objs->removeFatJetTools(syst.name()))std::cout<<"Failed to remove FatJet tools"<<std::endl;
	    delete m_objs;
	    checkMC.reset();
	    continue;
	  }
	  if ((eventInfo->errorState(xAOD::EventInfo::LAr)==xAOD::EventInfo::Error) || (eventInfo->errorState(xAOD::EventInfo::Tile) == xAOD::EventInfo::Error)){
	    LArTileFlag=false;
	    isyst++;
	    std::cout<<"Failed on LAR tiles"<<std::endl;
	    //if(!m_objs->removeFatJetTools(syst.name()))std::cout<<"Failed to remove FatJet tools"<<std::endl;
	    delete m_objs;
	    checkMC.reset();
	    continue;
	  }
	}

	double nBadJet = m_objs->getBadJets()->size();

	//Not doing cosmic muons for now
	//double nCosmicMu = m_objs->getCosmicMuons()->size();
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
	
		

	if (m_fileType == "DAOD_TRUTH1"){
	  passedMETTrigger = true;
	  passedMuTrigger = true;
	  passedElTrigger = true;
	  passedGammaTrigger = true;
	  passedMultiJetTrigger = true;
	  passedTauTrigger = true;
	  
	}

	//Trigger menus by year
	else{
	  if(year==2015){
	    if (!isData)
	      passedElTrigger=( (objTool->IsTrigPassed("HLT_e24_lhmedium_L1EM20VH || HLT_e60_lhmedium || HLT_e120_lhloose")));
	    if(isData)
	      {
		passedElTrigger=( (objTool->IsTrigPassed("HLT_e24_lhmedium_L1EM20VH || HLT_e60_lhmedium || HLT_e120_lhloose")));
	      }
	    passedMuTrigger=( (objTool->IsTrigPassed("HLT_mu26_iloose_L1MU15 || HLT_mu50 ")));
	    passedGammaTrigger=(objTool->IsTrigPassed("HLT_g120_loose"));
	    passedMETTrigger = objTool->IsMETTrigPassed("HLT_xe70_mht"); // or we use HLT_xe70  or HLT_xe70_tc_lcw 
	  }
	  else if (year==2016){
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
	}
	//	std::cout<<"MemCheck 4;"<<std::endl;      
	//	m_objs->CheckMem();
	//NEW TRIGGER IMPLEMENTATION
	std::vector<std::string> triggers = {"2e12_lhloose_L12EM10VH","HLT_2e15_lhvloose_nod0_L12EM13VH","HLT_2e17_lhvloose_nod0","HLT_e17_lhloose_mu14","HLT_e17_lhloose_nod0_mu14","HLT_mu22_mu8noL1","HLT_mu20_mu8noL1","HLT_mu18_mu8noL1","HLT_e24_lhmedium_L1EM20VH","HLT_e24_lhmedium_nod0_L1EM20VH","HLT_e24_lhtight_nod0_ivarloose","HLT_e26_lhtight_nod0_ivarloose","HLT_e60_lhmedium","HLT_e60_lhmedium_nod0","HLT_e120_lhloose","HLT_e140_lhloose_nod0","HLT_mu20_iloose_L1MU15","HLT_mu24_ivarloose","HLT_mu24_ivarloose_L1MU15","HLT_mu24_ivarmedium","HLT_mu26_ivarmedium","HLT_mu50","HLT_xe70_mht","HLT_xe70_tc_lcw","HLT_xe80_tc_lcw_L1XE50","HLT_xe90_mht_L1XE50","HLT_xe100_mht_L1XE50","HLT_xe110_mht_L1XE50"}; 
	std::vector<int> passedTriggers;
	for (auto x: triggers) {
	  int trigDecision = objTool->IsTrigPassed(x);
	  passedTriggers.push_back(trigDecision);
  	}
	

	if (passedElTrigger == 1 || passedMuTrigger == 1) passedLepTrigger = true;
	
	bool passedPrimVertex=true;
	if (m_objs->getPrimVertex() < 1){
	  passedPrimVertex=false;
	  isyst++;
	  std::cout<<"Failed on single primary vertex"<<std::endl;
	  //if(!m_objs->removeFatJetTools(syst.name()))std::cout<<"Failed to remove FatJet tools"<<std::endl;
	  delete m_objs;
	  checkMC.reset();
	  continue;
	  //return EL::StatusCode::SUCCESS;
	}
  
	bool passedJetClean=true;
	if (nBadJet > 0){
	  passedJetClean=false;
	  isyst++;
	  std::cout<<"Failed on Jet cleaning"<<std::endl;
	  //if(!m_objs->removeFatJetTools(syst.name()))std::cout<<"Failed to remove FatJet tools"<<std::endl;
	  delete m_objs;
	  continue;
	}
	
	bool passedCosmicMu=true;
	if (nCosmicMu > 0){
	  passedCosmicMu=false;
	  isyst++;
	  std::cout<<"Failed on cosmic muons"<<std::endl;
	  //if(!m_objs->removeFatJetTools(syst.name()))std::cout<<"Failed to remove FatJet tools"<<std::endl;
	  delete m_objs;
	  checkMC.reset();
	  continue;
	}
  
  	bool passedMuonClean=true;
	if (nBadMu > 0){
	  passedMuonClean=false;
	  isyst++;
	  std::cout<<"Failed on bad muons"<<std::endl;
	  //if(!m_objs->removeFatJetTools(syst.name()))std::cout<<"Failed to remove FatJet tools"<<std::endl;
	  delete m_objs;
	  checkMC.reset();
	  continue;
	}
	
	
	//All cleaning cuts before trigger
	bool passedCleaningCuts=false; 
	if(coreFlag && sctFlag && LArTileFlag && passedPrimVertex && passedJetClean && passedCosmicMu && passedMuonClean){
	  passedCleaningCuts=true; 
	}
	
	std::unique_ptr<CalculateVariables> m_varCalc(new CalculateVariables ( m_objs, isTruthFile, doPhotons));
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

	//trimming for >1 lepton && >2 jets && cleaning cuts
	if((m_objs->getGoodJets()->size()<2 || (m_objs->getGoodElectrons()->size()<1 && m_objs->getGoodMuons()->size()<1))){
	  isyst++;
	  //std::cout<<"Failed at trimming"<<std::endl;
	  //if(!m_objs->removeFatJetTools(syst.name()))std::cout<<"Failed to remove FatJet tools"<<std::endl;
	  delete m_objs;
	  checkMC.reset();
	  m_varCalc.reset();
	  m_regions.reset();
	  continue;
	}
	
	
	if ( m_fileType != "DAOD_TRUTH1"){
	  if (m_regions->interestingRegion || RunningLocally){
	    (m_treeServiceVector[isyst])->fillTree(m_objs, *m_regions, *m_varCalc, *checkMC,m_finalSumOfWeights, m_initialSumOfWeights, puWgt, SFmctbbll, passedMETTrigger, passedMuTrigger, passedElTrigger, passedGammaTrigger, passedMultiJetTrigger, passedTriggers, PUSumOfWeights, truthfilt_MET, truthfilt_HT, coreFlag, sctFlag, LArTileFlag, passedPrimVertex, passedJetClean, passedCosmicMu, passedMuonClean, m_runNumber, renormedMcWgt);
	  }
	}
	// not running on reco. fill everything for TRUTH
	else{
	  (m_treeServiceVector[isyst])->fillTree(m_objs, *m_regions, *m_varCalc, *checkMC,m_finalSumOfWeights, m_initialSumOfWeights, puWgt, SFmctbbll, passedMETTrigger, passedMuTrigger, passedElTrigger, passedGammaTrigger, passedMultiJetTrigger, passedTriggers, PUSumOfWeights, truthfilt_MET, truthfilt_HT , coreFlag, sctFlag, LArTileFlag, passedPrimVertex, passedJetClean, passedCosmicMu, passedMuonClean, m_runNumber, renormedMcWgt);
	}
	
	isyst++;
	

	//if (!m_objs->removeFatJetTools(syst.name())){std::cout<<"Failed to remove FatJet tools"<<std::endl;}
	delete m_objs;
	checkMC.reset();
	m_varCalc.reset();
	m_regions.reset();
  }



  //std::cout << "Tree service vector size:" << m_treeServiceVector.size() << std::endl;  

  //std::cout<<"Finished Event loop succesfully"<<std::endl;
  
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


  //std::cout << "Sum of Pile up = " << HSumOfPileUp->GetBinContent(1) << std::endl;
  //std::cout << "Sum of number of events processed = " << noWeightHist->GetBinContent(1) << std::endl;
  //std::cout << "Sum of analysis weights = " << sherpaWeightHist->GetBinContent(1) << std::endl;
  std::cout<<"Finished the run sucessfully"<<std::endl;
  
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
