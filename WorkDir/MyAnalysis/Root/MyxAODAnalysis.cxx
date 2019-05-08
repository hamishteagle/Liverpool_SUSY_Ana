#include <EventLoop/Job.h>
#include <EventLoop/Worker.h>
#include <MyAnalysis/MyxAODAnalysis.h>
#include "CPAnalysisExamples/errorcheck.h"
#include "xAODEventInfo/EventInfo.h"
#include "xAODTruth/TruthEventContainer.h"
#include "GoodRunsLists/GoodRunsListSelectionTool.h"
#include "xAODCutFlow/CutBookkeeper.h"
#include "xAODCutFlow/CutBookkeeperContainer.h"
#include "xAODMetaData/FileMetaData.h"

#include "JetSelectorTools/JetCleaningTool.h"
#include "JetResolution/JERTool.h"
#include <TSystem.h>
#include "MuonMomentumCorrections/MuonCalibrationAndSmearingTool.h"
#include "PATInterfaces/CorrectionCode.h"
#include <TFile.h>
#include <exception>
#include <AsgTools/MessageCheck.h>

#include <string.h>
#include <fstream>
#include <TTreeFormula.h>
#include "xAODEventInfo/EventInfo.h"
#include "MyAnalysis/NewObjectDef.h"
#include "MyAnalysis/AddPileUp.h"
#include "MyAnalysis/PreliminarySel.h"
#include "MyAnalysis/CalculateVariables.h"
#include "MyAnalysis/MapVariables.h"
#include "MyAnalysis/TreeService.h"
#include "MyAnalysis/MCChecks.h"
#include "MyAnalysis/Cutflows.h"

#include "PileupReweighting/TPileupReweighting.h"

#include <EventLoop/OutputStream.h>
#include <time.h>       /* time */

#include "SUSYTools/SUSYObjDef_xAOD.h"
#include "SUSYTools/SUSYCrossSection.h"

//Replacing ROOTCOREBIN
#include "PathResolver/PathResolver.h"


// this is needed to distribute the algorithm to the workers
ClassImp(MyxAODAnalysis)

MyxAODAnalysis :: MyxAODAnalysis (/*const std::string& name,
                            ISvcLocator *pSvcLocator)
  : EL::AnaAlgorithm (name, pSvcLocator*/)
{
  // Here you put any code for the base initialization of variables,
  // e.g. initialize all pointers to 0.  Note that you should only put
  // the most basic initialization here, since this method will be
  // called on both the submission and the worker node.  Most of your
  // initialization code will go into histInitialize() and
  // initialize().

  //declareProperty( "doSyst", doSyst = 1, "Do systematics?");
  //declareProperty( "doPhotons", doPhotons = 1, "Do photons?");
  //declareProperty( "RunningLocally", RunningLocally = 1, "Running locally?");
  //declareProperty( "inputFile", inputFile = "", "Input file name?");

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

EL::StatusCode MyxAODAnalysis :: fileExecute ()
{
  // Here you do everything that needs to be done exactly once for every
  // single file, e.g. collect a list of all lumi-blocks processed

  m_event = wk()->xaodEvent();
  double sumOfWeights        = 0;
  double sumOfWeightsSquared = 0;

  if(m_isDerivation && (!isTruth) && (!isData)){

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
    int maxCycle=-1; //need to find the max cycle where input stream is StreamAOD and the name is AllExecutedEvents

    for ( auto cbk :  *completeCBC ) {
      if(cbk->inputStream()=="StreamAOD" && cbk->name()=="AllExecutedEvents" && cbk->cycle()>maxCycle)
      {
        maxCycle=cbk->cycle(); allEventsCBK = cbk;
      }
    }

    
    double cbksumOfWeights        = allEventsCBK->sumOfEventWeights();
    double cbksumOfWeightsSquared = allEventsCBK->sumOfEventWeightsSquared();




    sumOfWeights        = cbksumOfWeights;
    sumOfWeightsSquared = cbksumOfWeightsSquared;
  }

  m_finalSumOfWeights += sumOfWeights;
  m_initialSumOfWeights += sumOfWeightsSquared;
  h_SumOfWeights->Fill(1,sumOfWeights);
  h_SumOfWeightsSquared->Fill(1,sumOfWeightsSquared);

  return StatusCode::SUCCESS;
}

EL::StatusCode MyxAODAnalysis :: beginInputFile (bool firstFile)
{
  // Here you do everything you need to do when we change input files,
  // e.g. resetting branch addresses on trees.  If you are using
  // D3PDReader or a similar service this method is not needed.
  // get the MetaData tree once a new file is opened, with

  MetaData = dynamic_cast<TTree*> (wk()->inputFile()->Get("MetaData"));
  if (MetaData) {
    MetaData->LoadTree(0);
    m_isDerivation = !MetaData->GetBranch("StreamAOD");
    if (isTruth = MetaData->GetBranch("TruthMetaData")){
      ANA_MSG_INFO ("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
      ANA_MSG_INFO ("This is Truth");
    }
  }

return StatusCode::SUCCESS;
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

  m_eventCounter = 0;
  m_numCleanEvents = 0;
  m_numElectronEvents = 0;
  m_numMuonEvents = 0;

  m_fileType = wk()->metaData()->castString("sample_name");
  m_fileName = inputFile;


  // GRL
  m_grl.setTypeAndName("GoodRunsListSelectionTool/grl");

  //PathResolverDirect
  std::string fullGRLFilePath15 = PathResolverFindCalibFile("GoodRunsLists/data15_13TeV/20170619/physics_25ns_21.0.19.xml");
  std::string fullGRLFilePath16 = PathResolverFindCalibFile("GoodRunsLists/data16_13TeV/20180129/physics_25ns_21.0.19.xml");
  std::string fullGRLFilePath17 = PathResolverFindCalibFile("GoodRunsLists/data17_13TeV/20180619/physics_25ns_Triggerno17e33prim.xml");
  std::string fullGRLFilePath18 = PathResolverFindCalibFile("GoodRunsLists/data18_13TeV/20190219/physics_25ns_Triggerno17e33prim.xml");

  std::vector<std::string> vecStringGRL;

  vecStringGRL.push_back(fullGRLFilePath15);
  vecStringGRL.push_back(fullGRLFilePath16);
  vecStringGRL.push_back(fullGRLFilePath17);
  vecStringGRL.push_back(fullGRLFilePath18);

  ANA_CHECK(m_grl.setProperty( "GoodRunsListVec", vecStringGRL));
  ANA_CHECK(m_grl.setProperty("PassThrough", false));
  ANA_CHECK(m_grl.initialize());

  //Assigning the lumicalc files
  std::vector<std::string> lumicalcFiles;

  //Getting the run number of the file to determine MC16a vs MC16c
  const xAOD::EventInfo* eventInfo_init(nullptr);
  ANA_CHECK(evtStore()->retrieve(eventInfo_init, "EventInfo"));

  int periodNumber = eventInfo_init->runNumber();
  bool isMC16a = (periodNumber == 284500);
  bool isMC16d = (periodNumber == 300000);
  bool isMC16e = (periodNumber == 310000);

  if(isMC16a)
    {
      lumicalcFiles.push_back(PathResolverFindCalibFile("GoodRunsLists/data15_13TeV/20170619/PHYS_StandardGRL_All_Good_25ns_276262-284484_OflLumi-13TeV-008.root"));
      lumicalcFiles.push_back(PathResolverFindCalibFile("GoodRunsLists/data16_13TeV/20180129/PHYS_StandardGRL_All_Good_25ns_297730-311481_OflLumi-13TeV-009.root"));
    }
  if(isMC16d){lumicalcFiles.push_back(PathResolverFindCalibFile("GoodRunsLists/data17_13TeV/20180619/physics_25ns_Triggerno17e33prim.lumicalc.OflLumi-13TeV-010.root"));}
  if(isMC16e){lumicalcFiles.push_back(PathResolverFindCalibFile("GoodRunsLists/data18_13TeV/20190219/ilumicalc_histograms_None_348885-364292_OflLumi-13TeV-010.root"));}


  objTool = new ST::SUSYObjDef_xAOD("SUSYObjDef_xAOD");

  //Get the metadata using SUSYTools
  const xAOD::FileMetaData* fmd = nullptr;
  ANA_CHECK(objTool->inputMetaStore()->retrieve(fmd, "FileMetaData") );
  //Get the simulation flavour
  std::string simFlavour;
  if (!(isData = !fmd->value(xAOD::FileMetaData::simFlavour, simFlavour))){
    isMC = true;
    isAtlfast = (simFlavour == "AtlfastII");
    ANA_MSG_INFO ("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
    ANA_MSG_INFO ("simFlavour = " << simFlavour );
  }  
  else {
    ANA_MSG_INFO ("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
    ANA_MSG_INFO ("This is data");
    isMC= false;
  }
  //Get the Derivation type
  std::string dataType;
  fmd->value(xAOD::FileMetaData::dataType, dataType);
  m_SUSY5= (dataType == "StreamDAOD_SUSY5") ;
  m_SUSY7= (dataType == "StreamDAOD_SUSY7") ;
  



  ST::ISUSYObjDef_xAODTool::DataSource datasource = (isData ? ST::ISUSYObjDef_xAODTool::Data : (isAtlfast ? ST::ISUSYObjDef_xAODTool::AtlfastII : ST::ISUSYObjDef_xAODTool::FullSim));
  
  ANA_CHECK(objTool->setProperty("DataSource",datasource) );
  if (m_SUSY5){
    ANA_CHECK(objTool->setProperty("ConfigFile",PathResolverFindCalibFile("/MyAnalysis/MyAnalysis/configs/1Lbb_default.conf")));
    ANA_MSG_INFO("This is SUSY5");
  }
  ANA_CHECK(objTool->setProperty("UseBtagging", true));
  
  if (!isTruth){
    ANA_CHECK(objTool->setProperty("PRWLumiCalcFiles",lumicalcFiles));
    ANA_CHECK(objTool->setProperty("AutoconfigurePRWTool",true));
    ANA_CHECK(objTool->initialize());
  }

  if(!doSyst) {
    ANA_MSG_INFO("Running without systematics.");
    ST::SystInfo infodef;
    infodef.affectsKinematics = false;
    infodef.affectsWeights = false;
    infodef.affectsType = ST::Unknown;
    systInfoList.push_back(infodef);

  }
  else {
    ANA_MSG_INFO("Running with systematics.");
    systInfoList = objTool->getSystInfoList();
  }

  TTree *Temp;
  for(const auto& sysInfo : systInfoList){

    const CP::SystematicSet& sys = sysInfo.systset;

    std::string temp = "On systematic: " + sys.name();
    ANA_MSG_INFO(temp);

    std::string treeName = "CollectionTree_"+std::string(sys.name());
    const char * cName = treeName.c_str();
    Temp = new TTree (cName, cName);
    TDirectory *out_TDir = (TDirectory*) wk()->getOutputFile ("output");
    TreeService* Tree_Service = new TreeService(Temp, out_TDir);
    m_treeServiceVector.push_back(Tree_Service);

  }

  for (unsigned int m = 0; m < (m_treeServiceVector.size()); m++){
    m_treeServiceVector[m]->writeTree();
  }
  
  //PMGCrossSectionTool setup
  std::cout<<"Before cross-sections tool"<<std::endl;
  ASG_SET_ANA_TOOL_TYPE( m_PMGCrossSectionTool, PMGTools::PMGCrossSectionTool);
  m_PMGCrossSectionTool.setName("myCrossSectionTool");
  ANA_CHECK(m_PMGCrossSectionTool.retrieve());
  m_PMGCrossSectionTool->readInfosFromDir("/cvmfs/atlas.cern.ch/repo/sw/database/GroupData/dev/PMGTools/");
  std::cout<<"After cross-sections tool"<<std::endl;
  //BTaggingSelectionTool setup
  ASG_SET_ANA_TOOL_TYPE( m_BTaggingSelectionTool, BTaggingSelectionTool);
  m_BTaggingSelectionTool.setName("myBTaggingSelectionTool");
  ANA_CHECK( m_BTaggingSelectionTool.setProperty( "FlvTagCutDefinitionsFileName","xAODBTaggingEfficiency/13TeV/2017-21-13TeV-MC16-CDI-2018-02-09_v1.root" ) ); //CDI file might need updating..
  ANA_CHECK( m_BTaggingSelectionTool.setProperty("TaggerName",    "MV2c10"  ) );
  ANA_CHECK( m_BTaggingSelectionTool.setProperty("OperatingPoint", "Continuous") );
  ANA_CHECK( m_BTaggingSelectionTool.setProperty("JetAuthor",      "AntiKt4EMTopoJets" ) );
  ANA_CHECK( m_BTaggingSelectionTool.initialize() );
  std::cout<<"After BTaggingTool tool"<<std::endl;

  return StatusCode::SUCCESS;
}

EL::StatusCode MyxAODAnalysis :: histInitialize ()
{
  // Here you do everything that you need to do after the first input
  // file has been connected and before the first event is processed,
  // e.g. create additional histograms based on which variables are
  // available in the input files.  You can also create all of your
  // histograms and trees in here, but be aware that this method
  // doesn't get called if no events are processed.  So any objects
  // you create here won't be available in the output if you have no
  // input events.

  m_finalSumOfWeights = 0;
  m_initialSumOfWeights = 0;


  isData = 0;
  isAtlfast = 0;
  isTruth = 0;

  gErrorIgnoreLevel = kFatal;


  noWeightHist = new TH1F("h_noWeights","h_noWeightHist",1 , 0.5, 1.5);
  sherpaWeightHist = new TH1F("h_sherpaWeights","h_sherpaWeightHist",1 , 0.5, 1.5);
  renormedSherpaWeightHist = new TH1F("h_RenormedSherpaWeights","h_RenormedSherpaWeightHist",1 , 0.5, 1.5);
  h_SumOfWeights = new TH1D("h_SumOfWeights","h_SumOfWeights",1 , 0.5, 1.5);
  h_SumOfWeightsSquared = new TH1D("h_SumOfWeightsSquared","h_SumOfWeightsSquared",1 , 0.5, 1.5);

  //Checking the data with lumicalc
  h_eventsPerRun = new TH1F("h_eventsPerRun","h_eventsPerRun",10000,0,10000);

  noWeightHist->SetDirectory (wk()->getOutputFile("output"));
  sherpaWeightHist->SetDirectory (wk()->getOutputFile("output"));
  h_SumOfWeights->SetDirectory (wk()->getOutputFile("output"));
  h_SumOfWeightsSquared->SetDirectory (wk()->getOutputFile("output"));
  renormedSherpaWeightHist->SetDirectory (wk()->getOutputFile("output"));

  h_eventsPerRun->SetDirectory(wk()->getOutputFile("output"));

  if (doTruthJets){
    h_dPhi_p30= new TH1F("h_dPhi_p30","h_dPhi_p30",1000, -0.5 , 0.5);
    h_dPhi_p40= new TH1F("h_dPhi_p40","h_dPhi_p40",1000, -0.5 , 0.5);
    h_dPhi_p80= new TH1F("h_dPhi_p80","h_dPhi_p80",1000, -0.5 , 0.5);
    h_dPhi_p200= new TH1F("h_dPhi_p200","h_dPhi_p200",1000, -0.5 , 0.5);
    h_dPhi_H= new TH1F("h_dPhi_H","h_dPhi_H",1000, -0.5 , 0.5);

    h_dEta_p30= new TH1F("h_dEta_p30","h_dEta_p30",1000, -0.5 , 0.5);
    h_dEta_p40= new TH1F("h_dEta_p40","h_dEta_p40",1000, -0.5 , 0.5);
    h_dEta_p80= new TH1F("h_dEta_p80","h_dEta_p80",1000, -0.5 , 0.5);
    h_dEta_p200= new TH1F("h_dEta_p200","h_dEta_p200",1000, -0.5 , 0.5);
    h_dEta_H= new TH1F("h_dEta_H","h_dEta_H",1000, -0.5 , 0.5);
    
    h_dPhi_p30->SetDirectory(wk()->getOutputFile("output"));
    h_dPhi_p40->SetDirectory(wk()->getOutputFile("output"));
    h_dPhi_p80->SetDirectory(wk()->getOutputFile("output"));
    h_dPhi_p200->SetDirectory(wk()->getOutputFile("output"));
    h_dPhi_H->SetDirectory(wk()->getOutputFile("output"));

    h_dEta_p30->SetDirectory(wk()->getOutputFile("output"));
    h_dEta_p40->SetDirectory(wk()->getOutputFile("output"));
    h_dEta_p80->SetDirectory(wk()->getOutputFile("output"));
    h_dEta_p200->SetDirectory(wk()->getOutputFile("output"));
    h_dEta_H->SetDirectory(wk()->getOutputFile("output"));
    
  }


  return StatusCode::SUCCESS;
}

EL::StatusCode MyxAODAnalysis :: execute ()
{
  // Here you do everything that needs to be done on every single
  // event, e.g. read input variables, apply cuts, and fill
  // histograms and trees.  This is where most of your actual analysis
  // code will go.

  const char* APP_NAME = "MyxAODAnalysis";


  isyst = 0;

  for (const auto& sysInfo : systInfoList){

    const CP::SystematicSet& syst = sysInfo.systset;

    int year = 0;

    if (!isTruth){
      objTool->ApplyPRWTool();
      year = objTool->treatAsYear();

      if (objTool->resetSystematics() != CP::SystematicCode::Ok) {
        Error(APP_NAME, "Cannot reset SUSYTools systematics" );
        exit(-2);
      }

      if (objTool->applySystematicVariation(syst) != CP::SystematicCode::Ok) {
        std::string temp = "Cannot configure SUSYTools for systematic: " + syst.name();
        ANA_MSG_INFO(temp);
      }
    }

    const xAOD::EventInfo* eventInfo =0;
    if (! evtStore()->retrieve(eventInfo, "EventInfo").isSuccess() ){
      Error("execute()","Failed to retrieve event info collection, exiting!!");
      isyst++;
      continue;
    }

    if(!isTruth && !isData){
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
    mcChannel = 0;
    double puWgt = 1;
    double mcWgt = 1;
    double truthfilt_MET = 0;
    double truthfilt_HT = 0;
    double renormedMcWgt = 1;
    double xsec = -1;
    double filteff = -1;
    double kfactor = -1;


    if (isMC){
      mcChannel = eventInfo->mcChannelNumber();
      puWgt = objTool->GetPileupWeight();

      try {
        xsec = m_PMGCrossSectionTool->getAMIXsection(mcChannel);
        filteff = m_PMGCrossSectionTool->getFilterEff(mcChannel);
        kfactor = m_PMGCrossSectionTool->getKfactor(mcChannel);
      } catch (...) {
        if (counter == 1) Error("execute()", "PMGCrossSectionTool exception caught");
      }

      mcWgt = eventInfo->mcEventWeight();
      renormedMcWgt = mcWgt;
      if (std::abs(renormedMcWgt) >= 100){
     	  renormedMcWgt = 1;
      }

      // This can get all of the PDF info etc if it's required at any point
      const xAOD::TruthEventContainer* truthE = 0;
      m_event->retrieve(truthE, "TruthEvents" );

      for(const auto& evt : *truthE) {
	//float x1, x2, pdf1, pdf2, scalePDF, Q;
	int id1, id2;
	evt->pdfInfoParameter(id1, xAOD::TruthEvent::PDGID1);
	evt->pdfInfoParameter(id2, xAOD::TruthEvent::PDGID2);
        //evt->pdfInfoParameter(x1, xAOD::TruthEvent::X1);
        //evt->pdfInfoParameter(x2, xAOD::TruthEvent::X2);
        //evt->pdfInfoParameter(pdf1, xAOD::TruthEvent::PDFID1);
        //evt->pdfInfoParameter(pdf2, xAOD::TruthEvent::PDFID2);
        //evt->pdfInfoParameter(scalePDF, xAOD::TruthEvent::SCALE);
        //evt->pdfInfoParameter(Q, xAOD::TruthEvent::Q);
      }
    }

    NewObjectDef* m_objs;
    m_objs = new NewObjectDef(evtStore(), objTool, store, mcChannel, EventNumber, mcWgt, m_lumiScaled, syst.name(), doTruthJets);
    if (firstEvent == true) firstEvent = false;

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

    if (isMC) {

      truthfilt_MET = 0.001*eventInfo->auxdata< float >("GenFiltMET");
      truthfilt_HT = 0.001*eventInfo->auxdata< float>("GenFiltHT");
      checkMC->ttbar_decay(evtStore());
      static const size_t foundSherpa = m_fileName.find("Sherpa");

      //checkMC->HeavyFlavourFilter_countJets(evtStore(), true);
      //checkMC->TruthTaus(evtStore());

      if (isTruth && foundSherpa != std::string::npos){
      	checkMC->ZpT(evtStore());
      	checkMC->SherpaZpT(evtStore());
      }

      static const size_t foundSherpa221 = m_fileName.find("Sherpa_221");
      if (foundSherpa221 != std::string::npos){
  	    checkMC->SherpaUncertaintyWeights(evtStore());
      }
      else {
        checkMC->RetrieveWeights(evtStore());
      }
    }

    bool coreFlag = true;
    bool sctFlag = true;
    bool LArTileFlag=true;

    if (!isMC){
      if ((eventInfo->errorState(xAOD::EventInfo::SCT) == xAOD::EventInfo::Error )){
    	  sctFlag = false;
    	  isyst++;
    	  continue;
      }
      if (eventInfo->isEventFlagBitSet(xAOD::EventInfo::Core,18)){
      	coreFlag = false;
      	isyst++;
      	continue;
      }
      if ((eventInfo->errorState(xAOD::EventInfo::LAr)==xAOD::EventInfo::Error) || (eventInfo->errorState(xAOD::EventInfo::Tile) == xAOD::EventInfo::Error)){
      	LArTileFlag=false;
      	isyst++;
      	continue;
      }
    }

    double nBadJet = m_objs->getBadJets()->size();
    double nCosmicMu = m_objs->getCosmicMuons()->size();
    double nBadMu = m_objs->getBadMuons()->size();

    


    // Put the trigger here:
    bool passedMETTrigger = false;
    bool passedGammaTrigger = false;
    bool passedMultiJetTrigger = false;
    bool passedSingleMuTrigger = false;
    bool passedSingleElTrigger = false;
    bool passedDiLeptonTrigger = false;

    int mu_triggers = 0;
    int el_triggers = 0;
    int dilep_triggers = 0;

    std::vector<std::string> muon_triggers;
    std::vector<std::string> electron_triggers;
    std::vector<std::string>dilepton_triggers;
    std::vector<int> muon_decisions;
    std::vector<int> electron_decisions;
    std::vector<int> dilepton_decisions;

    double leptonTriggerSF =1;
    
    if (isTruth){
      passedMETTrigger = true;
      passedGammaTrigger = true;
      passedMultiJetTrigger = true;
      passedSingleMuTrigger = true;
      passedSingleElTrigger = true;
      passedDiLeptonTrigger = true;
    }

    //NEW TRIGGER IMPLEMENTATION
    //Note:diMuon triggers only require 1 L1 muon.
    else {
      std::vector<std::string> single_el_2015 = {"HLT_e24_lhmedium_L1EM20VH", "HLT_e60_lhmedium", "HLT_e120_lhloose"};
      std::vector<std::string> single_mu_2015 = {"HLT_mu20_iloose_L1MU15", "HLT_mu50"};
      std::vector<std::string> di_lepton_2015 = {"HLT_2e12_lhloose_L12EM10VH", "HLT_mu18_mu8noL1", "HLT_e17_lhloose_mu14"};
      std::vector<std::string> single_el_2016 = {"HLT_e26_lhtight_nod0_ivarloose", "HLT_e60_lhmedium_nod0", "HLT_e140_lhloose_nod0"};
      std::vector<std::string> single_mu_2016 = {"HLT_mu26_ivarmedium","HLT_mu50"};
      std::vector<std::string> di_lepton_2016 = {"HLT_2e17_lhvloose_nod0","HLT_mu22_mu8noL1","HLT_e17_lhloose_nod0_mu14 "};
      std::vector<std::string> single_el_2017 = {"HLT_e26_lhtight_nod0_ivarloose", "HLT_e60_lhmedium_nod0", "HLT_e140_lhloose_nod0"};
      std::vector<std::string> single_mu_2017 = {"HLT_mu26_ivarmedium","HLT_mu50"};
      std::vector<std::string> di_lepton_2017 = {"HLT_2e17_lhvloose_nod0_L12EM15VHI","HLT_mu22_mu8noL1", "HLT_e17_lhloose_nod0_mu14"};
      std::vector<std::string> single_el_2018 = {"HLT_e26_lhtight_nod0_ivarloose","HLT_2e24_lhvloose_nod0", "HLT_e60_lhmedium_nod0", "HLT_e140_lhloose_nod0"};
      std::vector<std::string> single_mu_2018 = {"HLT_mu26_ivarmedium","HLT_mu50"};
      std::vector<std::string> di_lepton_2018 = {"HLT_2e17_lhvloose_nod0_L12EM15VHI","HLT_2e24_lhvloose_nod0","HLT_mu22_mu8noL1","HLT_e17_lhloose_nod0_mu14"};
      //Use IsMETTriggerPassed() function which should check the lowest un-prescaled triggers
      if (year == 2015) {
        for (auto mu_trig: single_mu_2015) {
          int trigDecision = objTool->IsTrigPassed(mu_trig);
          mu_triggers += trigDecision;
          muon_triggers.push_back(mu_trig);
          muon_decisions.push_back(trigDecision);
        }
        for (auto el_trig: single_el_2015) {
          int trigDecision = objTool->IsTrigPassed(el_trig);
          el_triggers += trigDecision;
          electron_triggers.push_back(el_trig);
          electron_decisions.push_back(trigDecision);
        }
        for (auto dilep_trig: di_lepton_2015) {
          int trigDecision = objTool->IsTrigPassed(dilep_trig);
          dilep_triggers += trigDecision;
          dilepton_triggers.push_back(dilep_trig);
          dilepton_decisions.push_back(trigDecision);
        }
      }
      if (year == 2016) {
        for (auto mu_trig: single_mu_2016) {
          int trigDecision = objTool->IsTrigPassed(mu_trig);
          mu_triggers += trigDecision;
          muon_triggers.push_back(mu_trig);
          muon_decisions.push_back(trigDecision);
        }
        for (auto el_trig: single_el_2016) {
          int trigDecision = objTool->IsTrigPassed(el_trig);
          el_triggers += trigDecision;
          electron_triggers.push_back(el_trig);
          electron_decisions.push_back(trigDecision);
        }
        for (auto dilep_trig: di_lepton_2016) {
          int trigDecision = objTool->IsTrigPassed(dilep_trig);
          dilep_triggers += trigDecision;
          dilepton_triggers.push_back(dilep_trig);
          dilepton_decisions.push_back(trigDecision);
        }
      }
      if (year == 2017) {
        for (auto mu_trig: single_mu_2017) {
          int trigDecision = objTool->IsTrigPassed(mu_trig);
          mu_triggers += trigDecision;
          muon_triggers.push_back(mu_trig);
          muon_decisions.push_back(trigDecision);
        }
        for (auto el_trig: single_el_2017) {
          int trigDecision = objTool->IsTrigPassed(el_trig);
          el_triggers += trigDecision;
          electron_triggers.push_back(el_trig);
          electron_decisions.push_back(trigDecision);
        }
        for (auto dilep_trig: di_lepton_2017) {
          int trigDecision = objTool->IsTrigPassed(dilep_trig);
          dilep_triggers += trigDecision;
          dilepton_triggers.push_back(dilep_trig);
          dilepton_decisions.push_back(trigDecision);
        }
      }
      if (year == 2018) {
        for (auto mu_trig: single_mu_2018) {
          int trigDecision = objTool->IsTrigPassed(mu_trig);
          mu_triggers += trigDecision;
          muon_triggers.push_back(mu_trig);
          muon_decisions.push_back(trigDecision);
        }
        for (auto el_trig: single_el_2018) {
          int trigDecision = objTool->IsTrigPassed(el_trig);
          el_triggers += trigDecision;
          electron_triggers.push_back(el_trig);
          electron_decisions.push_back(trigDecision);
        }
        for (auto dilep_trig: di_lepton_2018) {
          int trigDecision = objTool->IsTrigPassed(dilep_trig);
          dilep_triggers += trigDecision;
          dilepton_triggers.push_back(dilep_trig);
          dilepton_decisions.push_back(trigDecision);
        }
      }
      if (mu_triggers > 0) {
        passedSingleMuTrigger = true;
	leptonTriggerSF = m_objs->getMuonTriggerSF();
      }
      if (el_triggers > 0) {
        passedSingleElTrigger = true;
	leptonTriggerSF = m_objs->getElectronTriggerSF();
      }
      if (dilep_triggers >0) {
	passedDiLeptonTrigger = true;
	leptonTriggerSF = m_objs->getDilepTriggerSF();
      }
      if (objTool->IsMETTrigPassed()) {
        passedMETTrigger = true;
      }
    }
    if(passedSingleMuTrigger ==true && passedSingleElTrigger== true){
      if(passedDiLeptonTrigger !=true && passedSingleMuTrigger ==true && passedSingleElTrigger== true){
	std::cout<<"WARNING, both single lep triggers fired but no di-lepton trigger, your SFs are not prepared for this!!"<<std::endl;
      }
    }
    

    bool passedPrimVertex=true;
    if (m_objs->getPrimVertex() < 1){
      passedPrimVertex=false;
      //isyst++;
      continue;
    }

    bool passedJetClean=true;
    if (nBadJet > 0){
      passedJetClean=false;
      //isyst++;
      continue;
    }

    bool passedCosmicMu=true;
    if (nCosmicMu > 0){
      passedCosmicMu=false;
      //isyst++;
      continue;
    }

    bool passedMuonClean=true;
    if (nBadMu > 0){
      passedMuonClean=false;
      //isyst++;
      continue;
    }

    //All cleaning cuts before trigger
    bool passedCleaningCuts=false;
    if(coreFlag && sctFlag && LArTileFlag && passedPrimVertex && passedJetClean && passedCosmicMu && passedMuonClean){
      passedCleaningCuts=true;
    }

    std::unique_ptr<CalculateVariables> m_varCalc(new CalculateVariables ( m_objs, m_BTaggingSelectionTool, isTruth, doPhotons));
    std::unique_ptr<PreliminarySel> m_regions(new PreliminarySel (*m_varCalc, passedCleaningCuts));



    double SFmctbbll = 1;

    if (!isData && !isTruth) {
      PUSumOfWeights = objTool->GetSumOfWeights(mcChannel);
    }
    else{
      PUSumOfWeights = 0;
    }

    //Checking the number of events against the lumi
    if (isData) {
      if(isyst==0) {
        h_eventsPerRun->Fill(m_runNumber,1);
      }
    }

    //Filling truthJet-recoJet information
    double dR_init = 99;
    double dEta_init = -99;
    double dPhi_init = -99;
    double P_init = -99;
    if (doTruthJets){
      int nTruthJets = m_objs->getTruthJets()->size();
      //Compare truth jets and reco jets
      for (auto truth_jet: (*m_objs->getTruthJets())){
	for (auto reco_jet: (*m_objs->getGoodJets())){
	  double dR = truth_jet->p4().DeltaR(reco_jet->p4());
	  double dEta = truth_jet->eta()-reco_jet->eta();
	  double dPhi = truth_jet->phi()-reco_jet->phi();
	  double dP = fabs(truth_jet->e()-reco_jet->e())/(reco_jet->e()+truth_jet->e());
	  double truthP = sqrt((truth_jet->px()*truth_jet->px())+(truth_jet->pz()*truth_jet->py())+(truth_jet->pz()*truth_jet->pz()));
	  if (fabs(dR)<dR_init && dR<0.4 && dP <0.2){
	    dR_init=dR;
	    dEta_init = dEta;
	    P_init = truthP;
	    dPhi_init = dPhi;
	  }
	}
	if (P_init>0){
	  if (truth_jet->e()*0.001<30){	
	    h_dPhi_p30->Fill(dPhi_init);
	    h_dEta_p30->Fill(dEta_init);
	  }
	  if (P_init*0.001<40){	
	    h_dPhi_p40->Fill(dPhi_init);
	    h_dEta_p40->Fill(dEta_init);
	  }
	  if (P_init*0.001<80){	
	    h_dPhi_p80->Fill(dPhi_init);
	    h_dEta_p80->Fill(dEta_init);
	  }
	  if (P_init*0.001<200){	
	    h_dPhi_p200->Fill(dPhi_init);
	    h_dEta_p200->Fill(dEta_init);
	  }
	  if (P_init*0.001>200){	
	    h_dPhi_H->Fill(dPhi_init);
	    h_dEta_H->Fill(dEta_init);
	  }
	}
      }
    }



    if (!isTruth){
      if (m_regions->interestingRegion || RunningLocally){
      	(m_treeServiceVector[isyst])->fillTree(m_objs, *m_regions, *m_varCalc, *checkMC,m_finalSumOfWeights, m_initialSumOfWeights, puWgt, SFmctbbll, passedMETTrigger, passedSingleMuTrigger, passedSingleElTrigger, passedDiLeptonTrigger, passedGammaTrigger, passedMultiJetTrigger, muon_triggers, muon_decisions, electron_triggers, electron_decisions, dilepton_triggers, dilepton_decisions,leptonTriggerSF, PUSumOfWeights, truthfilt_MET, truthfilt_HT, coreFlag, sctFlag, LArTileFlag, passGRL, passedPrimVertex, passedJetClean, passedCosmicMu, passedMuonClean, m_runNumber, renormedMcWgt, year, m_averageIntPerX, m_actualIntPerX, xsec, filteff, kfactor);
      }
    }

    store->clear();

    isyst++;
    if(m_objs){
      delete m_objs;
    }
    electron_triggers.clear();
    electron_decisions.clear();
    muon_triggers.clear();
    muon_decisions.clear();
    dilepton_triggers.clear();
    dilepton_decisions.clear();
  }
  return StatusCode::SUCCESS;
}

EL::StatusCode MyxAODAnalysis :: postExecute ()
{
  // Here you do everything that needs to be done after the main event
  // processing.  This is typically very rare, particularly in user
  // code.  It is mainly used in implementing the NTuplSevc.

  return StatusCode::SUCCESS;
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

  if (objTool) {
    delete objTool;
    objTool = 0;
  }

  delete noWeightHist;
  delete sherpaWeightHist;
  delete renormedSherpaWeightHist;
  delete h_eventsPerRun;


  return StatusCode::SUCCESS;
 }
