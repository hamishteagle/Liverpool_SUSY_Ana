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

#include <ctime>
#include "MyAnalysis/MyxAODAnalysis.h"

int main( int argc, char* argv[]) {

  // Take the submit directory from the input if provided:
  std::string submitDir = "";
  std::string inputFile = "";
  std::vector<std::string> Months = {"Jan","Feb","Mar","Apr","May","June","July","Aug","Sept","Oct","Nov","Dec"};
  std::time_t t = time(0);   // get time now                                                                                                                                                                     

  bool RunningWithSyst;
  bool RunningWithPhotons;
     
  struct tm * now = localtime( & t );

  int Month = now->tm_mon;
  std::string CurrentDate = std::to_string(now->tm_mday)+Months[Month];
  std::string fileType = "SUSY7";
  
  std::string appPhotons = "_MultiB_";
  
    
  if( argc > 1 ) 
    {
      //submitDir = argv[ 1 ];
      inputFile = argv[ 1 ];

      if (argc > 2){
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

      if (RunningWithPhotons){
	appPhotons = "_Photons_";
      }
      
      int found = inputFile.find("TRUTH1");
      if (found != std::string::npos){
	fileType = "TRUTH1";
	RunningWithSyst = false;
      }
      
      int found_data15 = inputFile.find("data15");
      if (found_data15 != std::string::npos){
	fileType = "DATA15";
      }

      int found_data16 = inputFile.find("data16");
      if (found_data16 != std::string::npos){
	fileType = "DATA16";
      }
      
      
      submitDir = CurrentDate+"_v1_"+fileType+appPhotons+"/";
      
      // creates a directory in scratch for the job
      std::string CreateDir = "/scratch/hteagle/mulitB/GridSubmissions/"+submitDir;
      std::cout << "output Directory is: " << CreateDir << std::endl;

      if (submitDir == "true"){
	std::cout << "do not add the true thing to the submit dir" << std::endl;
        return 0;
      }
      
      std::string Command = "[ ! -d "+CreateDir+" ] && mkdir "+CreateDir+" || echo \"Directory Exists\"";
      std::system(Command.c_str());
      
      
      // put everything in scratch
      submitDir = CreateDir+'/'+inputFile;
      std::cout << "The Submission Directory: " << submitDir << std::endl;
    }
  
  // Set up the job for xAOD access:
  xAOD::Init().ignore();
  // Construct the samples to run on:
  SH::SampleHandler sh;
  
  // Grid Running from a shell script with a given input file
  SH::scanDQ2 (sh, inputFile);
  
  // Can run on a specific grid file by setting it here:
  //SH::scanDQ2(sh, "mc14_13TeV.110401.PowhegPythia_P2012_ttbar_nonallhad.merge.AOD.e2931_s1982_s2008_r5787_r5853/");
  
  
  sh.print();
  
  sh.setMetaString ("nc_tree", "CollectionTree");
  
  
  double nEventsTotal = 0;
  
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
  // Run the job using the griddriver:
  EL::PrunDriver driver;
  
  driver.options()->setString("nc_outputSampleName", "user.janders."+CurrentDate+"_"+fileType+"v1.%in:name[2]%.%in:name[3]%");
  driver.options()->setString(EL::Job::optGridNFilesPerJob, "1");
  // Use submit if you want to see all of the info about the submitted jobs. Use submitOnly if you want to send the jobs then Monitor online with panda
  //driver.submit( job, submitDir );
  driver.submitOnly( job, submitDir );
  
  return 0;
}
