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
#include <SampleHandler/MetaFields.h>

#include <iostream>

#include "MyAnalysis/MyxAODAnalysis.h"

std::string get_sample_name(const std::string& s);
std::string get_file_type(const std::string& s);
std::string get_derivation_type(const std::string& s);
bool is_multiple_submission(const std::string& s);
void info_message(const std::string& s);

int main( int argc, char* argv[]) {

    std::string sample_path = "";
    std::string sample_name = "";
    std::string submit_dir = "";
    std::string fileType = "";
    std::string derivationType ="";
    std::string username = "";
    std::string release = "";
    std::string physicsName = "";

    bool RunningWithSyst = false;
    bool RunningWithPhotons = false;
    bool RunningLocally = true;
    int NoEvents = -1;
    std::string nFilesPerJob ="5";
    bool RunningWithTruthJets = false;


    if (argv[1] != "") sample_path = argv[1];
    sample_name = get_sample_name(sample_path);
    if (argv[2] != "") submit_dir  = argv[2];
    if (argv[3] != ""){
      RunningWithSyst = (bool) atoi(argv[3]);
      std::cout<<"RunningWithSyst = "<<RunningWithSyst<<std::endl;
    }
    if (argv[4] != ""){
      RunningWithPhotons = (bool) atoi(argv[4]);
      std::cout<<"RunningWithPhotons = "<<RunningWithPhotons<<std::endl;
    }
    if (argv[5] != ""){
      RunningLocally = (bool) atoi(argv[5]);
      std::cout<<"RunningLocally = "<<RunningLocally<<std::endl;
    }
    if (argv[6] != "") NoEvents = atoi(argv[6]);
    if (argv[7] != "") username = argv[7];
    if (argv[8] != "") release = argv[8];
    if (argv[9] != "") physicsName = argv[9];
    if (argv[10] != ""){
      RunningWithTruthJets = (bool) atoi(argv[10]);
      std::cout<<"RunningWithTruthJets = "<<RunningWithTruthJets<<std::endl;
    }
    if (argc>11 && argv[11] != "") nFilesPerJob=argv[11];
    fileType = get_file_type(sample_name);
    info_message("Input path: " + sample_path);
    info_message("Sample name: " + sample_name);
    info_message("Sample type: " + fileType);
    info_message("Submission directory: " + submit_dir);
    if (RunningWithSyst) info_message("Systematics: True" );
    if (RunningWithPhotons) info_message("Photons: True" );
    if (!RunningLocally) info_message("--- Going to submit to grid ---" );
    if (NoEvents != -1) info_message("Events: " + std::to_string(NoEvents));
    info_message("nFilesPerJob: "+nFilesPerJob);

    // Set up the job for xAOD access:
    xAOD::Init().ignore();
    // Construct the samples to run on:
    SH::SampleHandler sh;
    //job.options()->setString(EL::Job::optXaodAccessMode,EL::Job::optXaodAccessMode_branch);
    if(RunningLocally){

        SH::DiskListLocal list (sample_path);
        SH::scanFiles(sh, list); // specifying one
        sh.setMetaString ("nc_tree", "CollectionTree");
        sh.print();
        // Create an EventLoop job:
        EL::Job job;
        job.sampleHandler( sh );

        job.options()->setString(EL::Job::optXaodAccessMode,EL::Job::optXaodAccessMode_class);
        if (NoEvents != -1) job.options()->setDouble(EL::Job::optMaxEvents, NoEvents);
        // Add our analysis to the job:
        MyxAODAnalysis* alg = new MyxAODAnalysis();
        EL::OutputStream output  ("output");
        job.outputAdd (output);
        job.algsAdd( alg );
        //alg->setProperty("SampleName",inputFile);
        alg->outputName = "outputLabel"; // give the name of the output to our algorithm
        alg->inputFile = sample_name;
        alg->doSyst = RunningWithSyst;
        alg->doPhotons = RunningWithPhotons;
	      alg->doTruthJets = RunningWithTruthJets;
        // If you want to check that the filtering is working correctly, then set this to false
        alg->RunningLocally = true;
        //alg->RunningLocally = false;
        alg->setMsgLevel(MSG::VERBOSE);

        EL::DirectDriver driver;
        job.options()->setDouble (EL::Job::optRemoveSubmitDir, 1);
        job.options()->setDouble (EL::Job::optXAODPerfStats, 1);
        driver.submit( job, submit_dir );
    }
    else if (!RunningLocally){

        std::string output_name = "";

        std::vector<std::string> Months = {"Jan","Feb","Mar","Apr","May","June","July","Aug","Sept","Oct","Nov","Dec"};
        std::time_t t = time(0);
        struct tm * now = localtime( & t );

        int Month = now->tm_mon;
        std::string CurrentDate = std::to_string(now->tm_mday)+Months[Month];

        std::string CreateDir = "/scratch/hteagle/GridSubmissions/"+CurrentDate+fileType;
        std::string Command = "[ ! -d "+CreateDir+" ] && mkdir "+CreateDir+" || echo \"Directory Exists\"";
        std::system(Command.c_str());


        // Create an EventLoop job:
        EL::Job job;
        EL::PrunDriver driver;

        //job.options()->setString(EL::Job::optXaodAccessMode,EL::Job::optXaodAccessMode_branch);
        job.options()->setString(EL::Job::optXaodAccessMode,EL::Job::optXaodAccessMode_class);
        if (is_multiple_submission(sample_name)) {
	  std::cout<<"Doing multiple Submission"<<std::endl;
	  output_name = CurrentDate + "." + "Combined." + fileType;
	  std::unique_ptr<SH::SampleGrid> sample(new SH::SampleGrid("AllMyData"));
	  sh.setMetaString ("nc_tree", "CollectionTree");
	  sample->meta()->setString(SH::MetaFields::gridName, sample_name);
	  sample->meta()->setString(SH::MetaFields::gridFilter, SH::MetaFields::gridFilter_default);
	  sh.add(sample.release());
	  sh.setMetaString ("nc_tree", "CollectionTree");
	  job.options()->setString( EL::Job::optSubmitFlags, "--addNthFieldOfInDSToLFN=2,3 --useContElementBoundary" );
	  driver.options()->setString("nc_outputSampleName", "user." + username + "." + CurrentDate + "." + physicsName +  ".Combined." + fileType+ "." +release);
        } else {
	  SH::scanRucio (sh, sample_name);
	  sh.setMetaString ("nc_tree", "CollectionTree");
	  sh.print();
	  output_name = sample_name;
	  driver.options()->setString("nc_outputSampleName", "user." + username + "." + CurrentDate+"." + physicsName+"_"+fileType+"."+release+".v1."+"%in:name[2]%.%in:name[3]%");
        }
        // Add our analysis to the job:
        MyxAODAnalysis* alg = new MyxAODAnalysis();

        EL::OutputStream output  ("output");

        job.outputAdd (output);

        job.algsAdd( alg );
        alg->outputName = "outputLabel"; // give the name of the output to our algorithm
        alg->inputFile = sample_name;
        alg->doSyst = RunningWithSyst;
        alg->doPhotons = RunningWithPhotons;
        alg->RunningLocally = false;
        alg->doTruthJets = RunningWithTruthJets;
        alg->setMsgLevel(MSG::DEBUG);

        //job.options()->setDouble (EL::Job::optRemoveSubmitDir, 1);
        job.sampleHandler( sh );
        driver.options()->setString(EL::Job::optGridNFilesPerJob, nFilesPerJob);
        // Use submit if you want to see all of the info about the submitted jobs. Use submitOnly if you want to send the jobs then Monitor online with panda
        std::string out_dir = CreateDir + "/" + output_name;
	      //std::cout<<"Would submit grid job with this output_name: "<<output_name<<std::endl;
	      std::cout<<"Going to submit now"<<std::endl;
        driver.submitOnly( job, out_dir );
    }
  return 0;

}

std::string get_sample_name(const std::string& s)
{
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, '/'))
   {
      tokens.push_back(token);
   }
   if (tokens.size() > 0) return tokens[tokens.size() - 1];
   else return (s);
}

std::string get_file_type(const std::string& s)
{

    std::string fileType = "UNKNOWN";

    size_t found_TRUTH1 = s.find("TRUTH1");
    if (found_TRUTH1 != std::string::npos){
      fileType = "TRUTH1";
    }
    size_t found_TRUTH3 = s.find("TRUTH3");
    if (found_TRUTH3 != std::string::npos){
      fileType = "TRUTH3";
    }
    size_t found_data15 = s.find("data15");
    if (found_data15 != std::string::npos){
      fileType = "DATA15";
        size_t found_SUSY5 = s.find("SUSY5");
        if (found_SUSY5 != std::string::npos){
        fileType += ".SUSY5";
        }
        size_t found_SUSY7 = s.find("SUSY7");
        if (found_SUSY7 != std::string::npos){
        fileType += ".SUSY7";
        }
    }

    size_t found_data16 = s.find("data16");
    if (found_data16 != std::string::npos){
      fileType = "DATA16";
        size_t found_SUSY5 = s.find("SUSY5");
        if (found_SUSY5 != std::string::npos){
        fileType += ".SUSY5";
        }
        size_t found_SUSY7 = s.find("SUSY7");
        if (found_SUSY7 != std::string::npos){
        fileType += ".SUSY7";
        }
    }

    size_t found_data17 = s.find("data17");
    if (found_data17 != std::string::npos){
      fileType = "DATA17";
        size_t found_SUSY5 = s.find("SUSY5");
        if (found_SUSY5 != std::string::npos){
        fileType += ".SUSY5";
        }
        size_t found_SUSY7 = s.find("SUSY7");
        if (found_SUSY7 != std::string::npos){
        fileType += ".SUSY7";
        }
    }

    size_t found_data18 = s.find("data18");
    if (found_data18 != std::string::npos){
      fileType = "DATA18";
        size_t found_SUSY5 = s.find("SUSY5");
        if (found_SUSY5 != std::string::npos){
        fileType += ".SUSY5";
        }
        size_t found_SUSY7 = s.find("SUSY7");
        if (found_SUSY7 != std::string::npos){
        fileType += ".SUSY7";
        }
    }

    size_t found_mc16a = s.find("r9364");
    if(found_mc16a != std::string::npos){
      fileType = "MC16a";
    }
    size_t found_mc16d = s.find("r10201");
    if(found_mc16d != std::string::npos){
      fileType = "MC16d";
    }
    size_t found_mc16e = s.find("r10724");
    if(found_mc16e != std::string::npos){
      fileType = "MC16e";
    }

    return fileType;
}

bool is_multiple_submission(const std::string& s)
{

    size_t multi_sub = s.find(",");
    if (multi_sub != std::string::npos){
        return true;
    }
    else {
        return false;
    }
}

void info_message(const std::string& s)
{
    std::cout << "\033[0;32m" << s << "\033[0;0m" << std::endl;
}
