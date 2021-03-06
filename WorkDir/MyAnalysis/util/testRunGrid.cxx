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
#include <SampleHandler/MetaObject.h>
#include <SampleHandler/Sample.h>
#include <SampleHandler/SampleGrid.h>
#include <SampleHandler/SampleHandler.h>
#include "testRun.h"

#include <ctime>
#include "MyAnalysis/MyxAODAnalysis.h"

int main( int argc, char* argv[] ) {

  std::string inputFile = argv[1];
  std::string submitDir = argv[2];
  std::string username = argv[3];
  std::string release = argv[4];
  bool RunningWithSyst = argv[5];
  bool RunningWithPhotons = argv[6];

  std::vector<std::string> Months = {"Jan","Feb","Mar","Apr","May","June","July","Aug","Sept","Oct","Nov","Dec"};
  std::time_t t = time(0);
  struct tm * now = localtime( & t );

  int Month = now->tm_mon;
  std::string CurrentDate = std::to_string(now->tm_mday)+Months[Month];
  std::string fileType = "";

  std::size_t found_TRUTH1 = inputFile.find("TRUTH1");
  if (found_TRUTH1 != std::string::npos){
	   fileType = "TRUTH1";
	   RunningWithSyst = false;
  }
  std::size_t found_TRUTH3 = inputFile.find("TRUTH3");
  if (found_TRUTH3 != std::string::npos){
	   fileType = "TRUTH3";
	   RunningWithSyst = false;
  }
  std::size_t found_SUSY5 = inputFile.find("SUSY5");
  if (found_SUSY5 != std::string::npos){
     fileType = "SUSY5";
  }
  std::size_t found_SUSY7 = inputFile.find("SUSY7");
  if (found_SUSY7 != std::string::npos){
     fileType = "SUSY7";
  }
  std::size_t found_data15 = inputFile.find("data15");
  if (found_data15 != std::string::npos){
	   fileType = "DATA15";
  }

  std::size_t found_data16 = inputFile.find("data16");
  if (found_data16 != std::string::npos){
	   fileType = "DATA16";
  }

  std::size_t found_data17 = inputFile.find("data17");
  if (found_data17 != std::string::npos){
	   fileType = "DATA17";
  }

  std::size_t found_data18 = inputFile.find("data18");
  if (found_data18 != std::string::npos){
	   fileType = "DATA18";
  }

  std::size_t found_mc16a = inputFile.find("r9364");
  if(found_mc16a != std::string::npos){
	   fileType = "MC16a";
  }
  std::size_t found_mc16d = inputFile.find("r10201");
  if(found_mc16d != std::string::npos){
	   fileType = "MC16d";
  }
  std::size_t found_mc16e = inputFile.find("r10724");
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

  // Set up the job for xAOD access:
  xAOD::Init().ignore();
  // Construct the samples to run on:
  SH::SampleHandler sh;

  // Grid Running from a shell script with a given input file
  SH::scanRucio (sh, inputFile);

  // Can run on a specific grid file by setting it here:
  //SH::scanRucio(sh, "mc16_13TeV.410470.PhPy8EG_A14_ttbar_hdamp258p75_nonallhad.deriv.DAOD_SUSY1.e6337_e5984_s3126_r10201_r10210_p3401/");

  sh.print();
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
  alg->RunningLocally = false;
  alg->setMsgLevel(MSG::ERROR);
  // Run the job using the griddriver:
  EL::PrunDriver driver;

  driver.options()->setString("nc_outputSampleName", "user."+username+"."+CurrentDate+"_"+fileType+"%in:name[2]%.%in:name[3]%"+release);
  driver.options()->setString(EL::Job::optGridNFilesPerJob, "5");
  // Use submit if you want to see all of the info about the submitted jobs. Use submitOnly if you want to send the jobs then Monitor online with panda
  driver.submitOnly( job, submitDir );

  return 0;
}
