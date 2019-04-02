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
  std::string submitDir = "";
  std::string inputDir = "";
  std::string inputFile = "";
  bool RunningWithSyst = false;
  bool RunningWithPhotons = false;
  bool RunningLocally = true;
  int NoEvents = -1;

  if (argc > 3) {
    inputDir = argv[1];
    inputFile = argv[2];
    submitDir = argv[3];
    RunningWithSyst = (bool) atoi(argv[4]);
    RunningWithPhotons = (bool) atoi(argv[5]);
    RunningLocally = (bool) atoi(argv[6]);
    NoEvents = atoi(argv[7]);
    std::cout << "Input dir: " << argv[1] << std::endl;
    std::cout << "Input file: " << argv[2] << std::endl;
    std::cout << "Submission file: " << argv[3] << std::endl;
    std::cout << "RunningWithSyst: " << RunningWithSyst << std::endl;
    std::cout << "RunningWithPhotons: " << RunningWithPhotons << std::endl;
    std::cout << "RunningLocally: " << RunningLocally << std::endl;
    std::cout << "Running on: " << NoEvents << " events" << std::endl;
  }

  // Set up the job for xAOD access:
  xAOD::Init().ignore();
  // Construct the samples to run on:
  SH::SampleHandler sh;

  submitDir = submitDir + inputFile;
  inputFile = inputDir + inputFile;

  SH::DiskListLocal list (inputFile);
  SH::scanFiles(sh, list); // specifying one

  sh.setMetaString ("nc_tree", "CollectionTree");

  sh.print();


  // Create an EventLoop job:
  EL::Job job;
  job.sampleHandler( sh );
  //job.options()->setString(EL::Job::optXaodAccessMode,EL::Job::optXaodAccessMode_branch);
  job.options()->setString(EL::Job::optXaodAccessMode,EL::Job::optXaodAccessMode_class);
  if (NoEvents != -1) job.options()->setDouble(EL::Job::optMaxEvents, NoEvents);

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
  alg->RunningLocally = RunningLocally;
  alg->setMsgLevel(MSG::VERBOSE);

  // Run the job using the local/direct driver:
  EL::DirectDriver driver;
  job.options()->setDouble (EL::Job::optRemoveSubmitDir, 1);

  driver.submit( job, submitDir );
  return 0;

}
