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
  std::string PhysicsName = "";
  std::string username = "hteagle";
  std::string release = "";
  std::string gridString = "";
  bool RunningWithSyst = false;
  bool RunningWithPhotons = false;
  int NoEvents = -1;
  bool doTogether = false;
  std::string inputFile;
  int counter = 0;
  bool RunningLocally=true;


  if (argc > 2) {
    inputDir = argv[1];
    inputFile = argv[1];
    std::cout << "InputFile: "<< inputFile << std::endl;
    std::cout << "Input dir: " << inputDir << std::endl;
    PhysicsName = argv[2];
    std::cout << "Input Type: " << PhysicsName << std::endl;
    submitDir = argv[3];
    std::cout << "Submission file: " << submitDir << std::endl;
    RunningWithSyst = (bool) atoi(argv[4]);
    std::cout << "RunningWithSyst: " << RunningWithSyst << std::endl;
    RunningWithPhotons = (bool) atoi(argv[5]);
    std::cout << "RunningWithPhotons: " << RunningWithPhotons << std::endl;
    RunningLocally = (bool) atoi(argv[6]);
    std::cout << "RunningLocally: " << RunningLocally << std::endl;
    NoEvents = atoi(argv[7]);
    std::cout << "Running on: " << NoEvents << " events" << std::endl;
    release = argv[8];
    std::cout << "AnalysisBase release: " << release << std::endl;
    doTogether = (bool)atoi(argv[9]);
    std::cout << "doTogether " << doTogether << std::endl;

  }

  // Set up the job for xAOD access:
  xAOD::Init().ignore();
  // Construct the samples to run on:
  SH::SampleHandler sh;

  SH::DiskListLocal list (inputDir);
  SH::scanFiles(sh, list); // specifying one
  sh.setMetaString ("nc_tree", "CollectionTree");

  sh.print();


  // Create an EventLoop job:
  EL::Job job;
  job.sampleHandler( sh );
  //job.options()->setString(EL::Job::optXaodAccessMode,EL::Job::optXaodAccessMode_branch);
  if(RunningLocally){
    job.options()->setString(EL::Job::optXaodAccessMode,EL::Job::optXaodAccessMode_class);
    if (NoEvents != -1) job.options()->setDouble(EL::Job::optMaxEvents, NoEvents);
    
    // Add our analysis to the job:
    MyxAODAnalysis* alg = new MyxAODAnalysis();
    
    
    EL::OutputStream output  ("output");
    
    job.outputAdd (output);
    job.algsAdd( alg );
    
    //alg->setProperty("SampleName",inputFile);
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
  }
  else if (!RunningLocally){
    std::vector<std::string> Months = {"Jan","Feb","Mar","Apr","May","June","July","Aug","Sept","Oct","Nov","Dec"};
    std::time_t t = time(0);
    struct tm * now = localtime( & t );
    
    int Month = now->tm_mon;
    std::string CurrentDate = std::to_string(now->tm_mday)+Months[Month];
    std::string fileType = "";
    std::string derivationType = "";
    int found_TRUTH1 = inputFile.find("TRUTH1");
    if (found_TRUTH1 != std::string::npos){
      fileType = "TRUTH1";
      RunningWithSyst = false;
    }
    int found_TRUTH3 = inputFile.find("TRUTH3");
    if (found_TRUTH3 != std::string::npos){
      fileType = "TRUTH3";
      RunningWithSyst = false;
    }
    int found_SUSY5 = inputFile.find("SUSY5");
    if (found_SUSY5 != std::string::npos){
      derivationType = "SUSY5";
    }
    int found_SUSY7 = inputFile.find("SUSY7");
    if (found_SUSY7 != std::string::npos){
      derivationType = "SUSY7";
    }
    int found_data15 = inputFile.find("data15");
    if (found_data15 != std::string::npos){
      fileType = "DATA15";
    }
    
    int found_data16 = inputFile.find("data16");
    if (found_data16 != std::string::npos){
      fileType = "DATA16";
    }
    
    int found_data17 = inputFile.find("data17");
    if (found_data17 != std::string::npos){
      fileType = "DATA17";
    }
    
    int found_data18 = inputFile.find("data18");
    if (found_data18 != std::string::npos){
      fileType = "DATA18";
    }
    
    int found_mc16a = inputFile.find("r9364");
    if(found_mc16a != std::string::npos){
      fileType = "MC16a";
    }
    int found_mc16d = inputFile.find("r10201");
    if(found_mc16d != std::string::npos){
      fileType = "MC16d";
    }
    int found_mc16e = inputFile.find("r10724");
    if(found_mc16e != std::string::npos){
      fileType = "MC16e";
    }
    
    submitDir = CurrentDate+fileType;
    
    std::string CreateDir = "/scratch/hteagle/GridSubmissions/"+submitDir;
    std::string Command = "[ ! -d "+CreateDir+" ] && mkdir "+CreateDir+" || echo \"Directory Exists\"";
    std::system(Command.c_str());
    
    
    // put everything in scratch
    submitDir = CreateDir+'/'+inputFile;
    std::cout << "The Submission Directory: " << submitDir << std::endl;
    
    if (!doTogether){
      // Grid Running from a shell script with a given input file
      SH::scanRucio (sh, inputFile);
      sh.setMetaString ("nc_tree", "CollectionTree");    
    }
    // else {
    //   std::unique_ptr<SH::SampleGrid> sample(new SH::SampleGrid("AllMyData"));
    //   sample->meta()->setString(SH::MetaFields::gridName, gridString);
    //   sample->meta()->setString(SH::MetaFields::gridFilter, SH::MetaFields::gridFilter_default);
    //   sh.add(sample.release());
    //   job.options()->setString (EL::Job::optSubmitFlags, "--addNthFieldOfInDSToLFN=1,2,3 --useContElementBoundary");
    // }


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
    alg->RunningLocally = false;
    alg->setMsgLevel(MSG::ERROR);
    // Run the job using the griddriver:
    EL::PrunDriver driver;
    if (!doTogether){
      driver.options()->setString("nc_outputSampleName", "user."+username+"."+CurrentDate+"_"+fileType+"%in:name[2]%.%in:name[3]%"+derivationType+release);
    }
    driver.options()->setString(EL::Job::optGridNFilesPerJob, "5");
    // Use submit if you want to see all of the info about the submitted jobs. Use submitOnly if you want to send the jobs then Monitor online with panda
    driver.submitOnly( job, submitDir );

  }
  return 0;

}
