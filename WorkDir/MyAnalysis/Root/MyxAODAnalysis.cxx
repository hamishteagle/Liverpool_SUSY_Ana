#include <EventLoop/Job.h>
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

MyxAODAnalysis :: MyxAODAnalysis (const std::string& name,
                            ISvcLocator *pSvcLocator)
  : EL::AnaAlgorithm (name, pSvcLocator)
{
  // Here you put any code for the base initialization of variables,
  // e.g. initialize all pointers to 0.  Note that you should only put
  // the most basic initialization here, since this method will be
  // called on both the submission and the worker node.  Most of your
  // initialization code will go into histInitialize() and
  // initialize().

  declareProperty( "doSyst", doSyst = 1, "Do systematics?");
  declareProperty( "doPhotons", doPhotons = 1, "Do photons?");
  declareProperty( "RunningLocally", RunningLocally = 1, "Running locally?");
  declareProperty( "inputFile", inputFile = "", "Input file name?");

}

StatusCode MyxAODAnalysis :: fileExecute ()
{
  // Here you do everything that needs to be done exactly once for every
  // single file, e.g. collect a list of all lumi-blocks processed

  const char* APP_NAME = "MyxAODAnalysis";

  m_event = wk()->xaodEvent();
  double nEventsProcessed  = 0;
  double sumOfWeights        = 0;
  double sumOfWeightsSquared = 0;
  if(m_isDerivation && (m_fileType != "DAOD_TRUTH1" || m_fileType != "DAOD_TRUTH3") && isData == false){

    // check for corruption
    const xAOD::CutBookkeeperContainer* incompleteCBC;
    if(!m_event->retrieveMetaInput(incompleteCBC, "IncompleteCutBookkeepers").isSuccess()){
      Error("initializeEvent()","Failed to retrieve IncompleteCutBookkeepers from MetaData! Exiting.");
      return StatusCode::FAILURE;
    }

    // Now, let's find the actual information
    const xAOD::CutBookkeeperContainer* completeCBC = 0;
    if(!m_event->retrieveMetaInput(completeCBC, "CutBookkeepers").isSuccess()){
      Error("initializeEvent()","Failed to retrieve CutBookkeepers from MetaData! Exiting.");
      return StatusCode::FAILURE;
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
    std::string derivationName = "DAOD_SUSY5"; //need to replace by appropriate name
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




    nEventsProcessed  = cbknEventsProcessed;
    sumOfWeights        = cbksumOfWeights;
    sumOfWeightsSquared = cbksumOfWeightsSquared;
  }

  m_finalSumOfWeights += sumOfWeights;
  m_initialSumOfWeights += sumOfWeightsSquared;
  h_SumOfWeights->Fill(1,sumOfWeights);
  h_SumOfWeightsSquared->Fill(1,sumOfWeightsSquared);

  std::cout << "Total Sum of Weights: " << m_finalSumOfWeights << std::endl;
  std::cout << "Total Sum of Weights Squared: " << m_initialSumOfWeights << std::endl;

  return StatusCode::SUCCESS;
}

StatusCode MyxAODAnalysis :: beginInputFile (bool firstFile)
{
  // Here you do everything you need to do when we change input files,
  // e.g. resetting branch addresses on trees.  If you are using
  // D3PDReader or a similar service this method is not needed.
  // get the MetaData tree once a new file is opened, with

  MetaData = dynamic_cast<TTree*> (wk()->inputFile()->Get("MetaData"));
  if (MetaData) {

    MetaData->LoadTree(0);

    m_isDerivation = !MetaData->GetBranch("StreamAOD");

  }

return StatusCode::SUCCESS;
}

StatusCode MyxAODAnalysis :: initialize ()
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

  Asgmdtool = new asg::AsgMetadataTool("Asgmdtool");

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


  noWeightHist = new TH1F("h_noWeights","h_noWeightHist",1 , 0.5, 1.5);
  sherpaWeightHist = new TH1F("h_sherpaWeights","h_sherpaWeightHist",1 , 0.5, 1.5);
  renormedSherpaWeightHist = new TH1F("h_RenormedSherpaWeights","h_RenormedSherpaWeightHist",1 , 0.5, 1.5);
  h_SumOfWeights = new TH1D("h_SumOfWeights","h_SumOfWeights",1 , 0.5, 1.5);
  h_SumOfWeightsSquared = new TH1D("h_SumOfWeightsSquared","h_SumOfWeightsSquared",1 , 0.5, 1.5);

  //Checking the data with lumicalc
  h_eventsPerRun = new TH1F("h_eventsPerRun","h_eventsPerRun",10000,0,10000);

  HSRA_noWgt = new TH1F("HSRA_noWgt","HSRA_noWgt", 50, 0.5, 50.5);
  HSRA_mcWgt = new TH1F("HSRA_mcWgt","HSRA_mcWgt", 50, 0.5, 50.5);
  HSRA_allWgt = new TH1F("HSRA_allWgt","HSRA_allWgt", 50, 0.5, 50.5);

  HSRB_noWgt = new TH1F("HSRB_noWgt","HSRB_noWgt", 50, 0.5, 50.5);
  HSRB_mcWgt = new TH1F("HSRB_mcWgt","HSRB_mcWgt", 50, 0.5, 50.5);
  HSRB_allWgt = new TH1F("HSRB_allWgt","HSRB_allWgt", 50, 0.5, 50.5);

  HSRC_noWgt = new TH1F("HSRC_noWgt","HSRC_noWgt", 50, 0.5, 50.5);
  HSRC_mcWgt = new TH1F("HSRC_mcWgt","HSRC_mcWgt", 50, 0.5, 50.5);
  HSRC_allWgt = new TH1F("HSRC_allWgt","HSRC_allWgt", 50, 0.5, 50.5);


  HTruthMETFilt = new TH1F("HTruthMETFilt","HTruthMETFilt", 50, 0,1000);
  HTruthHTFilt = new TH1F("HTruthHTFilt","HTruthHTFilt", 50, 0,1000);
  HSumOfPileUp = new TH1F("HSumOfPileUp","HSumOfPileUp", 1, 0.5,1.5);



  noWeightHist->SetDirectory (wk()->getOutputFile("output"));
  sherpaWeightHist->SetDirectory (wk()->getOutputFile("output"));
  h_SumOfWeights->SetDirectory (wk()->getOutputFile("output"));
  h_SumOfWeightsSquared->SetDirectory (wk()->getOutputFile("output"));
  renormedSherpaWeightHist->SetDirectory (wk()->getOutputFile("output"));

  h_eventsPerRun->SetDirectory(wk()->getOutputFile("output"));
  // Make the Histos for the full cutflows here then:

  HSRA_noWgt->SetDirectory (wk()->getOutputFile("output"));
  HSRA_mcWgt->SetDirectory (wk()->getOutputFile("output"));
  HSRA_allWgt->SetDirectory (wk()->getOutputFile("output"));

  HSRB_noWgt->SetDirectory (wk()->getOutputFile("output"));
  HSRB_mcWgt->SetDirectory (wk()->getOutputFile("output"));
  HSRB_allWgt->SetDirectory (wk()->getOutputFile("output"));

  HSRC_noWgt->SetDirectory (wk()->getOutputFile("output"));
  HSRC_mcWgt->SetDirectory (wk()->getOutputFile("output"));
  HSRC_allWgt->SetDirectory (wk()->getOutputFile("output"));

  HTruthMETFilt->SetDirectory (wk()->getOutputFile("output"));
  HTruthHTFilt->SetDirectory (wk()->getOutputFile("output"));
  HSumOfPileUp->SetDirectory (wk()->getOutputFile("output"));

  std::cout << "initialize" << std::endl;

  m_eventCounter = 0;
  m_numCleanEvents = 0;
  m_numElectronEvents = 0;
  m_numMuonEvents = 0;

  // GRL
  m_grl = new GoodRunsListSelectionTool("GoodRunsListSelectionTool");

  //PathResolverDirect
    std::string fullGRLFilePath15 = PathResolverFindCalibFile("MyAnalysis/MyAnalysis/GRL/data15_13TeV.periodAllYear_DetStatus-v89-pro21-02_Unknown_PHYS_StandardGRL_All_Good_25ns.xml");
  std::string fullGRLFilePath16 = PathResolverFindCalibFile("MyAnalysis/MyAnalysis/GRL/data16_13TeV.periodAllYear_DetStatus-v89-pro21-01_DQDefects-00-02-04_PHYS_StandardGRL_All_Good_25ns.xml");
  std::string fullGRLFilePath17 = PathResolverFindCalibFile("MyAnalysis/MyAnalysis/GRL/data17_13TeV_44.3_AllYear_20180619_physics_25ns_Triggerno17e33prim.xml");
  std::string fullGRLFilePath18 = PathResolverFindCalibFile("MyAnalysis/MyAnalysis/GRL/data18_13TeV_47.8_AllYear_20180924_physics_25ns_Triggerno17e33prim.xml");

  //std::string fullGRLFilePath2 = PathResolverFindCalibFile("MyAnalysis/MyAnalysis/GRL/LastGRL.xml");
  std::vector<std::string> vecStringGRL;

  vecStringGRL.push_back(fullGRLFilePath15);
  vecStringGRL.push_back(fullGRLFilePath16);
  vecStringGRL.push_back(fullGRLFilePath17);
  vecStringGRL.push_back(fullGRLFilePath18);
  //vecStringGRL.push_back(fullGRLFilePath2);

  CHECK(m_grl->setProperty( "GoodRunsListVec", vecStringGRL));
  CHECK(m_grl->setProperty("PassThrough", false));

  if (!m_grl->initialize().isSuccess()){
    Error("initialize()", "Failed to properly initialise the GRL. Exiting.");
    return StatusCode::FAILURE;
  }
  std::cout << "Passed GRL init" << std::endl;


  //Assigning the lumicalc files
  std::vector<std::string> lumicalcFiles;

  //Getting the run number of the file to determine MC16a vs MC16c
  const xAOD::EventInfo* eventInfo_init =0;
  if (! evtStore()->retrieve(eventInfo_init, "EventInfo").isSuccess() ){
    Error("execute()","Failed to retrieve event info collection, exiting!!");
  }

  int periodNumber = eventInfo_init->runNumber();
  std::cout<<"MC production period  Number; "<<periodNumber<<std::endl;
  bool isMC16a = (periodNumber == 284500);
  bool isMC16d = (periodNumber == 300000);
  bool isMC16e = (periodNumber == 310000);

  bool isMC15a = false;
  bool isMC15b = false;
  bool isMC15c = false;

  std::cout << "which MC is this: A, B, C, 16a, 16d, 16e" << isMC15a << isMC15b << isMC15c << isMC16a <<isMC16d<<isMC16e<<std::endl;
  if(isMC16a)
    {
      lumicalcFiles.push_back(PathResolverFindCalibFile("MyAnalysis/MyAnalysis/PileUp/PHYS_StandardGRL_All_Good_25ns_276262-284484_OflLumi-13TeV-008.root"));
      lumicalcFiles.push_back(PathResolverFindCalibFile("MyAnalysis/MyAnalysis/PileUp/PHYS_StandardGRL_All_Good_25ns_297730-311481_OflLumi-13TeV-009.root"));
    }
  if(isMC16d){lumicalcFiles.push_back(PathResolverFindCalibFile("MyAnalysis/MyAnalysis/PileUp/physics_25ns_Triggerno17e33prim.lumicalc.OflLumi-13TeV-010.root"));}
  if(isMC16e){lumicalcFiles.push_back(PathResolverFindCalibFile("MyAnalysis/MyAnalysis/PileUp/physics_25ns_Triggerno17e33prim.lumicalc.OflLumi-13TeV-001.root"));}
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
  //ANA_CHECK( objTool->setProperty("ConfigFile", PathResolverFindCalibFile("MyAnalysis/MyAnalysis/EWK_SUSYSkim1L.conf")));
  ANA_CHECK( objTool->setProperty("ConfigFile", PathResolverFindCalibFile("MyAnalysis/MyAnalysis/EWK_consistent_21.2.51.conf")));
  ANA_CHECK(objTool->setBoolProperty("UseBtagging", true));

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

  //Initialise output trees using TreeService for each systematic (nominal if not running)
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

  /*  if(datasource==ST::ISUSYObjDef_xAODTool::Data){
      m_metSignif.setProperty("IsData",true);
    } */
  if (isAtlfast==1){
      ANA_CHECK(m_metSignif.setProperty("IsAFII",true));
  } else {
      ANA_CHECK(m_metSignif.setProperty("IsAFII",  false));
  }

  ANA_CHECK(m_metSignif.retrieve());
  m_metSignif->initialize();

  //Write all of the trees
  for (int m = 0; m < (m_treeServiceVector.size()); m++){
    m_treeServiceVector[m]->writeTree();
  }

  // PMG xsec tools

  //Instantiation (if not using some ToolHandle )
  std::cout<<"Initializing Cross Section Tool"<<std::endl;
  ASG_SET_ANA_TOOL_TYPE( m_PMGCrossSectionTool, PMGTools::PMGCrossSectionTool);
  m_PMGCrossSectionTool.setName("myCrossSectionTool");
  m_PMGCrossSectionTool.retrieve();
  m_PMGCrossSectionTool->readInfosFromDir("/cvmfs/atlas.cern.ch/repo/sw/database/GroupData/dev/PMGTools/");


  std::cout << "Finished initialisation" << std::endl;


  return StatusCode::SUCCESS;
}

StatusCode MyxAODAnalysis :: execute ()
{
  // Here you do everything that needs to be done on every single
  // event, e.g. read input variables, apply cuts, and fill
  // histograms and trees.  This is where most of your actual analysis
  // code will go.

  const char* APP_NAME = "MyxAODAnalysis";
  //std::cout << "In analysis execute" << std::endl;

  //if (m_eventCounter >= 10){return StatusCode::SUCCESS;}
  if ( (m_eventCounter % 1000) == 0 ) Info("execute()","Event Number = %i", m_eventCounter);
  //if ( (m_eventCounter % 100) == 0 ) Info("execute()","Event Number = %i", m_eventCounter);
  m_eventCounter++;


  bool isNominal = true;

  isyst = 0;

  m_event = wk()->xaodEvent();
  int m_entries = m_event->getEntries();

  if (counter == 0) {
    std::cout << "First event" << std::endl;
    beginInputFile(false);
    fileExecute();
  }

  counter++;

  if (counter == m_entries - 1) {
    std::cout << "Last event" << std::endl;
    counter = 0;
  }

  for (const auto& sysInfo : systInfoList){
    const CP::SystematicSet& syst = sysInfo.systset;

    int year = 0;
    int runNumber = 0;
    if (m_fileType != "DAOD_TRUTH1" && m_fileType != "DAOD_TRUTH3"){
      objTool->ApplyPRWTool();
      year = objTool->treatAsYear();
    }

    if (m_fileType != "DAOD_TRUTH1" && m_fileType != "DAOD_TRUTH3"){

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
    if (! evtStore()->retrieve(eventInfo, "EventInfo").isSuccess() ){
      Error("execute()","Failed to retrieve event info collection, exiting!!");
      isyst++;
      continue;
    }

    //File types (MC/truth)
    bool isTruthFile = false;
    if (m_fileType == "DAOD_TRUTH1" || m_fileType == "DAOD_TRUTH3"){
      isTruthFile = true;
    }
    bool isMC = false;
    if(eventInfo->eventType( xAOD::EventInfo::IS_SIMULATION) ){
      isMC = true; // lets us do things correctly later
    }


    if(!isTruthFile){
    m_averageIntPerX=eventInfo->averageInteractionsPerCrossing();
    m_actualIntPerX=eventInfo->actualInteractionsPerCrossing();
    }
    else {
      m_averageIntPerX=1;
      m_actualIntPerX=1;
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



    double weight = 1;

    double truth_pTW = 0;




    mcChannel = 0;

    double mcWgt = 1;
    double truthfilt_MET = 0;
    double truthfilt_HT = 0;
    double renormedMcWgt = 1;
    double xsec = -1;
    double filteff = -1;
    double kfactor = -1;
    // Will fix this when the PMGTools cross section stuff is available


    if (isMC){
      mcChannel = eventInfo->mcChannelNumber();
      puWgt = objTool->GetPileupWeight();
    //}
      //std::cout << "Looking for xsec for " << mcChannel << std::endl;
    //getting metdata from the Map (MapVariables.cxx) using the text file in format as MGPy8EG_A14N23LO_BB_onestepN2hN1.txt
      //std::shared_ptr<MapVariables> m_mappedVars( new MapVariables ("MyAnalysis/data/MyAnalysis/MGPy8EG_A14N23LO_BB_onestepN2hN1.txt"));
      //std::shared_ptr<MapVariables> m_mappedBkgVars( new MapVariables ("MyAnalysis/data/MyAnalysis/susy_crossSections_13TeV.txt"));
    //does this mcID exist in signal map?
      //bool checkMap = m_mappedVars->find(mcChannel);
      //if (checkMap)
      //{
      //  xsec = m_mappedVars->getCrossSection(mcChannel);
      //  filteff= m_mappedVars->getFilterEff(mcChannel);
      //  kfactor= m_mappedVars->getKFactor(mcChannel);
      //}
      //else {//does mcID exist in Bkg map?
     	//  checkMap = m_mappedBkgVars->find(mcChannel);
    	//  if (checkMap)
     	//  {
    //      xsec = m_mappedBkgVars->getCrossSection(mcChannel);
    // 	    filteff= m_mappedBkgVars->getFilterEff(mcChannel);
    // 	    kfactor= m_mappedBkgVars->getKFactor(mcChannel);
    // 	  }
  //    }

      try {
        xsec = m_PMGCrossSectionTool->getAMIXsection(mcChannel);
        filteff = m_PMGCrossSectionTool->getFilterEff(mcChannel);
        kfactor = m_PMGCrossSectionTool->getKfactor(mcChannel);
      } catch (...) {
        if (counter == 1) std::cout << "PMGCrossSectionTool exception caught" << std::endl;
      }

      mcWgt = eventInfo->mcEventWeight();
      renormedMcWgt = mcWgt;
      if (std::abs(renormedMcWgt) >= 100){
     	  renormedMcWgt = 1;
      }
    }

    //lumiScaled gives scaling to 1ifb

    m_lumiScaled = 1;//This needs to be changed
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
      m_objs  = new TruthObjectDef (evtStore(), objTool, store, mcChannel, EventNumber, mcWgt, m_lumiScaled, syst.name(), doPhotons,  m_metSignif, m_averageIntPerX);
    }
    else{
      m_objs  = new ObjectDef (evtStore(), objTool, store, mcChannel, EventNumber, mcWgt, m_lumiScaled, syst.name(), doPhotons, m_metSignif, m_averageIntPerX);
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

      HSRC_noWgt->Fill(1,1);
      HSRC_mcWgt->Fill(1,mcWgt);
      HSRC_allWgt->Fill(1,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);



    }

    // Initialise the class which sorts out the MC checks (if required)
    std::unique_ptr<MCChecks> checkMC (new MCChecks ());
    bool passGRL = false;
    if (!isMC){

      if(!(m_grl->passRunLB(*eventInfo))){
	continue;
      }
      else if (m_grl->passRunLB(*eventInfo)) {
       passGRL = true;
      }
    }

    if (isMC) passGRL = true;

    // get the truth MET info for OR removals between ttbar/single top samples
    if (mcChannel == 410470 || (mcChannel >= 407342 && mcChannel <= 407347) || mcChannel == 410646 || mcChannel == 410647){
    truthfilt_MET = 0.001*eventInfo->auxdata< float >("GenFiltMET");
    truthfilt_HT = 0.001*eventInfo->auxdata< float>("GenFiltHT");
    HTruthMETFilt->Fill(truthfilt_MET);
    HTruthHTFilt->Fill(truthfilt_HT);
    checkMC->ttbar_decay(evtStore());
    }




    if (isMC){
      int foundSherpa = m_fileName.find("Sherpa");

      checkMC->HeavyFlavourFilter_countJets(evtStore(), true);
      checkMC->TruthTaus(evtStore());

      if (isTruthFile && foundSherpa != std::string::npos){
	checkMC->ZpT(evtStore());
	checkMC->SherpaZpT(evtStore());
      }

      int foundSherpa221 = m_fileName.find("Sherpa_221");
      if (foundSherpa221 != std::string::npos){
	checkMC->SherpaUncertaintyWeights(evtStore());
      }
      else {
       checkMC->RetrieveWeights(evtStore());
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

      HSRC_noWgt->Fill(2,1);
      HSRC_mcWgt->Fill(2,mcWgt);
      HSRC_allWgt->Fill(2,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);

    }


    bool coreFlag = true;
    bool sctFlag = true;
    bool LArTileFlag=true;
    if (!isMC){
      if ((eventInfo->errorState(xAOD::EventInfo::SCT) == xAOD::EventInfo::Error )){
	sctFlag = false;
	//isyst++;
	//continue;
      }
      if (eventInfo->isEventFlagBitSet(xAOD::EventInfo::Core,18)){
	coreFlag = false;
	//isyst++;
	//continue;
      }
      if ((eventInfo->errorState(xAOD::EventInfo::LAr)==xAOD::EventInfo::Error) || (eventInfo->errorState(xAOD::EventInfo::Tile) == xAOD::EventInfo::Error)){
	LArTileFlag=false;
	//isyst++;
	//continue;
      }
    }

    // Event Passes LAr, TileError and CoreFlags.
    if (isyst == 0){

      HSRA_noWgt->Fill(3,1);
      HSRA_mcWgt->Fill(3,mcWgt);
      HSRA_allWgt->Fill(3,mcWgt);//*btagWgt*lepWgt*trigWgt*puWgt);

      HSRB_noWgt->Fill(3,1);
      HSRB_mcWgt->Fill(3,mcWgt);
      HSRB_allWgt->Fill(3,1);

      HSRC_noWgt->Fill(3,1);
      HSRC_mcWgt->Fill(3,mcWgt);
      HSRC_allWgt->Fill(3,mcWgt*btagWgt*lepWgt*trigWgt*puWgt);

    }

    double nBadJet = m_objs->getBadJets()->size();
    //Not doing cosmic muons for now
    double nCosmicMu = m_objs->getCosmicMuons()->size();
    //double nCosmicMu = 0;
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

    //NEW TRIGGER IMPLEMENTATION
    std::vector<std::string> triggers = {"2e12_lhloose_L12EM10VH","HLT_2e15_lhvloose_nod0_L12EM13VH","HLT_2e17_lhvloose_nod0","HLT_e17_lhloose_mu14","HLT_e17_lhloose_nod0_mu14","HLT_mu22_mu8noL1","HLT_mu20_mu8noL1","HLT_mu18_mu8noL1","HLT_e24_lhmedium_L1EM20VH","HLT_e24_lhmedium_nod0_L1EM20VH","HLT_e24_lhtight_nod0_ivarloose","HLT_e26_lhtight_nod0_ivarloose","HLT_e60_lhmedium","HLT_e60_lhmedium_nod0","HLT_e120_lhloose","HLT_e140_lhloose_nod0","HLT_mu20_iloose_L1MU15","HLT_mu24_ivarloose","HLT_mu24_ivarloose_L1MU15","HLT_mu24_ivarmedium","HLT_mu26_ivarmedium","HLT_mu50","HLT_xe70_mht","HLT_xe70_tc_lcw","HLT_xe80_tc_lcw_L1XE50","HLT_xe90_mht_L1XE50","HLT_xe100_mht_L1XE50","HLT_xe110_mht_L1XE50"};
    //2016_D4 trigger
    triggers.push_back("HLT_xe110_L1XE50");
    //2017 triggers
    triggers.push_back("HLT_xe110_pufit_L1XE50");
    //2018 triggers
    triggers.push_back("HLT_2e17_lhvloose_nod0_L12EM15VHI");
    triggers.push_back("HLT_2e24_lhvloose_nod0");
    triggers.push_back("HLT_e24_lhvloose_nod0_2e12_lhvloose_nod0_L1EM20VH_3EM10VH");
    triggers.push_back("HLT_e26_lhmedium_nod0_mu8noL1");
    triggers.push_back("HLT_e7_lhmedium_nod0_mu24");
    triggers.push_back("HLT_mu20_2mu4noL1");
    triggers.push_back("HLT_e24_lhmedium_iloose_L1EM18VH");//Needed for data period C3-C4
    triggers.push_back("HLT_xe110_pufit_xe70_L1XE50");
    triggers.push_back("HLT_xe120_pufit_L1XE50");
    triggers.push_back("HLT_xe110_pufit_xe65_L1XE50");

    //std::vector< std::pair<std::string, int> > passedTriggers;
    std::vector<int> passedTriggers;
    for (auto x: triggers) {
     int trigDecision = objTool->IsTrigPassed(x);
     passedTriggers.push_back(trigDecision);
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

    }
    bool passedPrimVertex=true;
    if (m_objs->getPrimVertex() < 1){
      passedPrimVertex=false;
      //isyst++;
      //continue;
      //return StatusCode::SUCCESS;
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
    }

    bool passedJetClean=true;
    if (nBadJet > 0){
      passedJetClean=false;
      //isyst++;
      //continue;
      //return StatusCode::SUCCESS;
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
    }


    bool passedCosmicMu=true;
    if (nCosmicMu > 0){
      passedCosmicMu=false;
      //isyst++;
      //continue;
      //return StatusCode::SUCCESS;
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
    }

    bool passedMuonClean=true;
    if (nBadMu > 0){
      passedMuonClean=false;
      //isyst++;
      //continue;
      //return StatusCode::SUCCESS;
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
    }

    //All cleaning cuts before trigger
    bool passedCleaningCuts=false;
    if(coreFlag && sctFlag && LArTileFlag && passedPrimVertex && passedJetClean && passedCosmicMu && passedMuonClean){
      passedCleaningCuts=true;
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


    std::vector<TH1F*> SRCHists;
    SRCHists.push_back(HSRC_noWgt);
    SRCHists.push_back(HSRC_mcWgt);
    SRCHists.push_back(HSRC_allWgt);


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

  //Checking the number of events against the lumi
  if (isData){
    if((*m_varCalc).eTMiss>250){
      if(isyst==0) std::cout<<"LumiBlockNumber; "<<m_lumiBlockNumber<<std::endl;
      h_eventsPerRun->Fill(runNumber,1);
    }
  }
  ////Continue trimming
  //Doesn't pass the cleaning cuts
  if (! passedCleaningCuts) continue;
  int passOneTrigger=0;
  //Doesn't pass any of the triggers
  for (unsigned int i=0; i<passedTriggers.size();i++){
    //std::cout<<"Trigger ;"<<i<<" bool;"<<passedTriggers[i]<<std::endl;
    if (passedTriggers[i]>0){

      passOneTrigger++;
    }
  }
  if (passOneTrigger==0){
    //std::cout<<"Didn't pass any triggers"<<std::endl;
    continue;
  }
  //std::cout<<"Passed at least one trigger"<<std::endl;

    if (isyst == 0){
      std::unique_ptr<Cutflows> m_cutflows (new Cutflows (*m_varCalc, *m_regions, SRAHists, SRBHists, SRCHists, btagWgt, lepWgt, trigWgt, puWgt, mcWgt, EventNumber, passedMETTrigger, passedLepTrigger, passedGammaTrigger, truthfilt_MET));
    }

    if ( m_fileType != "DAOD_TRUTH1"){
      if (m_regions->interestingRegion || RunningLocally){
	(m_treeServiceVector[isyst])->fillTree(m_objs, *m_regions, *m_varCalc, *checkMC,m_finalSumOfWeights, m_initialSumOfWeights, puWgt, SFmctbbll, passedMETTrigger, passedMuTrigger, passedElTrigger, passedGammaTrigger, passedMultiJetTrigger, passedTriggers, PUSumOfWeights, truthfilt_MET, truthfilt_HT, coreFlag, sctFlag, LArTileFlag, passGRL, passedPrimVertex, passedJetClean, passedCosmicMu, passedMuonClean, m_runNumber, renormedMcWgt, year, m_averageIntPerX, m_actualIntPerX, xsec, filteff, kfactor);
       }
    }

    // not running on reco. fill everything for TRUTH
    else{
      (m_treeServiceVector[isyst])->fillTree(m_objs, *m_regions, *m_varCalc, *checkMC,m_finalSumOfWeights, m_initialSumOfWeights, puWgt, SFmctbbll, passedMETTrigger, passedMuTrigger, passedElTrigger, passedGammaTrigger, passedMultiJetTrigger, passedTriggers, PUSumOfWeights, truthfilt_MET, truthfilt_HT , coreFlag, sctFlag, LArTileFlag, passGRL, passedPrimVertex, passedJetClean, passedCosmicMu, passedMuonClean, m_runNumber, renormedMcWgt, year, m_averageIntPerX, m_actualIntPerX, xsec, filteff, kfactor);
   }

    delete m_objs;
    isyst++;

  }




  //std::cout << "Tree service vector size:" << m_treeServiceVector.size() << std::endl;

  //  std::cout<<"Finished Event loop succesfully"<<std::endl;

  return StatusCode::SUCCESS;
}

StatusCode MyxAODAnalysis :: postExecute ()
{
  // Here you do everything that needs to be done after the main event
  // processing.  This is typically very rare, particularly in user
  // code.  It is mainly used in implementing the NTuplSevc.

  std::cout << "postExecute" << std::endl;

  return StatusCode::SUCCESS;
}

StatusCode MyxAODAnalysis :: finalize ()
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

  std::cout << "finalize" << std::endl;



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


  return StatusCode::SUCCESS;
 }
