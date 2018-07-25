#include "xAODRootAccess/Init.h"
#include "SampleHandler/SampleHandler.h"
#include "SampleHandler/fetch.h"
#include "SampleHandler/ToolsDiscovery.h"
#include "EventLoop/Job.h"
#include <EventLoopGrid/PrunDriver.h>
#include "EventLoop/DirectDriver.h"
#include "SampleHandler/DiskListLocal.h"
#include <TSystem.h>
#include <EventLoopAlgs/NTupleSvc.h> 
#include <EventLoop/OutputStream.h>
#include "testRun.h"

#include <SampleHandler/MetaObject.h>
#include <SampleHandler/Sample.h>
#include <SampleHandler/SampleGrid.h>
#include <SampleHandler/SampleHandler.h>


#include "MyAnalysis/MyxAODAnalysis.h"

int main( int argc, char* argv[]) {

  // Take the submit directory from the input if provided:
  std::string submitDir = "submitDir2";
  std::string inputDir;
  std::string inputFile = "replaceMeSomewhere";
  
  bool RunningWithSyst;
  bool RunningWithPhotons;
  
  std::string gridoption = "n";//Option for running on the grid
  

    if (gridoption == "y")
      {
	std::cout<<"Running on the grid (y)"<<std::endl;
	gridmain(argc, argv);
	return 0;
      }


  submitDir = "/hepstore/hteagle/SubmissionOutputs/";  
  inputDir = "/hepstore/hteagle/Sbot_multiB/recoSamples/";

  if( argc > 1 ) 
      {
	//submitDir = argv[ 1 ];
	inputFile = argv[ 1 ];
	if (argc > 2){
	  std::cout << "Passes argc > 2, with: " << argv[2]  << std::endl;
	  if ( (std::string(argv[2]) == "1") || (std::string(argv[2]) == "true") || (std::string(argv[2]) == "True")  ) {
	    RunningWithSyst = true;
	  }
	  else{
	    RunningWithSyst = false;
	  }
	  
	}
	else{
	  RunningWithSyst = false;
	}
	
	if (argc > 3){
	  
	  std::cout << "Passes argc > 3, with: " << argv[3] <<std::endl;
	  if ( (std::string(argv[3]) == "1") || (std::string(argv[3]) == "true") || (std::string(argv[3]) == "True")  ) {
	    RunningWithPhotons = true;
	  }
	  else{
	    RunningWithPhotons = false;
	  }
	  
	}
	else{
	  RunningWithPhotons = false;
	}
	
	std::cout << "Running with Syst = " << RunningWithSyst << std::endl;
	std::cout << "Running with Photons = " << RunningWithPhotons << std::endl;
	submitDir=submitDir+"NoSyst/";
	std::cout << "The Submission Directory: " << submitDir << std::endl;
      }
  else submitDir=submitDir+"Syst/";
    // Set up the job for xAOD access:
    xAOD::Init().ignore();
    // Construct the samples to run on:
    SH::SampleHandler sh;
    
    
    
    // this is the cutflow file, please do not delete
    //inputFile = "/hepstore/janders/mc15_13TeV.390146.MGPy8EG_A14N23LO_BB_onestepN2hN1_600_400_60.merge.DAOD_SUSY7.e5671_a766_a821_r7676_p2879";
    //inputFile = "/scratch/hteagle/ttbar/mc16_13TeV.410501.PowhegPythia8EvtGen_A14_ttbar_hdamp258p75_nonallhad.deriv.DAOD_SUSY1.e5458_s3126_r9781_r9778_p3401";
    // inputFile=  /hepstore/hteagle/recoSamples/ttbar/mc16_13TeV.410471.PhPy8EG_A14_ttbar_hdamp258p75_allhad.e6337_e5984_s3126_r9364_r9315_p3401
    //inputFile = "/scratch/hteagle/data16/data16_13TeV.00310969.physics_Main.deriv.DAOD_SUSY1.r9264_p3083_p3372";
    //inputFile = "/hepstore/hteagle/recoSamples/ttbar/mc16_13TeV.410470.PhPy8EG_A14_ttbar_hdamp258p75_nonallhad.deriv.DAOD_SUSY1.e6337_e5984_s3126_r10201_r10210_p3401";
    // Change me here
    //inputFile = "signal/mc16_13TeV.390285.MGPy8EG_A14N23LO_BB_onestepN2hN1_700_680_550.deriv.DAOD_SUSY1.e5671_e5984_a875_r9364_r9315_p3404";
    //inputFile = "data15_13TeV.periodD.physics_Main.PhysCont.DAOD_SUSY1.grp15_v01_p3372";
    inputFile = "temp/mc16_13TeV.363355.Sherpa_221_NNPDF30NNLO_ZqqZvv.deriv.DAOD_SUSY1.e5525_s3126_r9364_r9315_p3401/";
    submitDir = submitDir+inputFile;
    
    inputFile = inputDir+inputFile;

    SH::DiskListLocal list (inputFile);
    SH::scanFiles(sh, list); // specifying one 

    sh.setMetaString ("nc_tree", "CollectionTree");

    sh.print();


    // Create an EventLoop job:
    EL::Job job;
    job.sampleHandler( sh );
    //job.options()->setString(EL::Job::optXaodAccessMode,EL::Job::optXaodAccessMode_branch);
    job.options()->setString(EL::Job::optXaodAccessMode,EL::Job::optXaodAccessMode_class);
    
    // Add our analysis to the job:

    MyxAODAnalysis* alg = new MyxAODAnalysis();
 
  
    EL::OutputStream output  ("output");

    job.outputAdd (output);
    job.algsAdd( alg );

    alg->outputName = "outputLabel"; // give the name of the output to our algorithm
    alg->inputFile = inputFile;
    alg->doSyst = RunningWithSyst;
    alg->doPhotons = RunningWithPhotons;
    // If you want to check that the filtering is working correctly, then set this to false
    alg->RunningLocally = true;
  
  
    // Run the job using the local/direct driver:
    EL::DirectDriver driver;
    
    job.options()->setDouble (EL::Job::optRemoveSubmitDir, 1);

    driver.submit( job, submitDir );
    return 0;
}
