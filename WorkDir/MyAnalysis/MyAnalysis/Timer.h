#ifndef MyAnalysis_Timer_H
#define MyAnalysis_Timer_H
/*

  Static singleton class to log the performance of the framework
  Intended usage is simple

  Written by: Matthew Gignac (UBC)

*/

// ROOT
#include "TStopwatch.h"
#include "TH1F.h"
#include "TString.h"

// C++
#include <stdarg.h>
#include <map>

class Timer
{

 public:
   static Timer* Instance();

   ///
   /// Start a Timer. If it doesn't exist, create it.
   /// If it exists and is running still, stop it.
   ///
   void Start(const char *va_fmt, ...);

   ///
   /// Stop a Timer.
   ///
   void End(const char *va_fmt, ...);

   ///
   /// Write each timer histogram
   /// TODO: Format this better, where to write? What if 200 events haven't been looped over?
   ///
   void write();

   ///
   /// Printer average +/- RMS of the time
   ///
   void printPerformance();

   // Only accessor to the log,
   // Calculates averages and fill histograms
   // if the class has not already been toggled to do so
   std::map<TString,TH1F*> getTimeLog();

 private:
   Timer();
   ~Timer(){};

   // Data structure to hold
   // individual entries and fills the
   // hist when entires size exceeds 200
   // Used to determine the bounds of the histogram
   struct TimeLog
   {
     std::vector<float> entries;
     bool convertToHist;
     TH1F* hist;
   };

   void log(TString uniqueID,float run_time);

   void ConvertToHist(TString uniqueID,TimeLog*& timeLog);

   // Global timers, started the first time Start is called
   // and is used to log the various calls to this class
   std::map<TString,TStopwatch*> m_timers;

   //
   // Everytime a time is taken, store in these histograms
   std::map<TString,TimeLog*> m_timeLog;

   // Instance of this class
   static Timer* m_pInstance;

   //Converting args to proper format
   TString format(const char* va_fmt, va_list args);

};


#endif
