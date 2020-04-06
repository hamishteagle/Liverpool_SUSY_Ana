#include "MyAnalysis/Timer.h"
#include <map>
#include <algorithm>
#include "TCanvas.h"
#include <AsgTools/MessageCheck.h>
Timer* Timer::m_pInstance = NULL;

using namespace asg::msgUserCode;
//
Timer::Timer()
{

}
// --------------------------------------------------- //
Timer* Timer::Instance()
{

  if( !m_pInstance ){
    m_pInstance = new Timer();
  }

  return m_pInstance;

}
// --------------------------------------------------- //
void Timer::Start(const char *va_fmt, ...)
{

  // Format string
  va_list args;
  va_start (args, va_fmt);
  TString uniqueID = format(va_fmt,args);
  va_end (args);

  // Look up
  auto timer = m_timers.find(uniqueID);

  if( timer == m_timers.end() ){

    ANA_MSG_INFO("Timer::Start Created TStopwatch for "<<uniqueID.Data() );
    //
    TStopwatch* TSW = new TStopwatch();
    TSW->Reset();
    TSW->Start();
    //
    m_timers.insert( std::pair<TString,TStopwatch*>(uniqueID,TSW) );

  }
  else{
    // Restart
    timer->second->Stop();
    timer->second->Reset();
    timer->second->Start();
  }

}
// --------------------------------------------------- //
void Timer::End(const char *va_fmt, ...)
{

  // Format
  va_list args;
  va_start (args, va_fmt);
  TString uniqueID = format(va_fmt,args);
  va_end (args);

  // Loop up
  auto timer = m_timers.find(uniqueID);

  if( timer == m_timers.end() ){
    ANA_MSG_WARNING("Timer::End No timer found for "<<uniqueID.Data() );
    return;
  }

  //
  double RealTime = 1000.0 * timer->second->RealTime();

  // Log
  log(uniqueID,RealTime);

  // Reset
  timer->second->Reset();

}
// --------------------------------------------------- //
void Timer::log(TString uniqueID,float run_time)
{

  auto it = m_timeLog.find(uniqueID);

  if( it==m_timeLog.end() ){

    // Simply save the number
    // Not logging the first entry,
    // since usually this is skewed since
    // many methods have some type of setup?
    TimeLog* timeLog = new TimeLog();
    timeLog->convertToHist = false;
    timeLog->hist = 0;
    timeLog->entries.push_back(run_time);

    //
    m_timeLog.insert( std::pair<TString,TimeLog*>(uniqueID,timeLog) );

  }
  else{

    if( !it->second->hist ){

      // Save time log
      it->second->entries.push_back(run_time);

      // Compute average and dump contents of entries
      // when we have 200 entires
      if( it->second->entries.size()>=200 ){
        ConvertToHist(uniqueID,it->second);
      }
    }
    else{
      it->second->hist->Fill(run_time,1.0);
    }
  }

}

// --------------------------------------------------- //
void Timer::ConvertToHist(TString uniqueID,TimeLog*& timeLog)
{

  // Some checks
  if( !timeLog ){
    ANA_MSG_WARNING("Timer::ConvertToHist TimeLog does not exist!");
  }

  float max = 1.0;
  float min = 0.0;

  // max_element/min_element crash for lists
  // with only 1 element. So determine ourselves
  if( timeLog->entries.size()==1 ){
    max = timeLog->entries[0] + timeLog->entries[0]/2.0;
    min = timeLog->entries[0] - timeLog->entries[0]/2.0;
  }
  else{
    max = *std::max_element(std::begin(timeLog->entries), std::end(timeLog->entries));
    min = *std::min_element(std::begin(timeLog->entries), std::end(timeLog->entries));
  }

  timeLog->hist = new TH1F(uniqueID.Data(),"",100,min,max*1.1);
  timeLog->hist->GetYaxis()->SetTitle("Number of calls");
  timeLog->hist->GetXaxis()->SetTitle("Run time (ms)");
  timeLog->hist->SetDirectory(0);

  for( const auto& time : timeLog->entries ){
    timeLog->hist->Fill(time,1.0);
  }

  timeLog->entries.clear();
  timeLog->convertToHist = true;

}
// --------------------------------------------------- //
std::map<TString,TH1F*> Timer::getTimeLog()
{

  std::map<TString,TH1F*> timeLog;

  // Reduce to just map with histograms
  for( auto& it : m_timeLog ){

    // Low statistics probabaly, but need a histogram
    if( !it.second->convertToHist ){
      ConvertToHist(it.first,it.second);
    }

    timeLog.insert( std::pair<TString,TH1F*>(it.first,it.second->hist) );

  }

  // Return
  return timeLog;

}
// --------------------------------------------------- //
void Timer::printPerformance()
{

  for( auto& it : m_timeLog ){

    // Low statistics probabaly, but need a histogram
    if( !it.second->convertToHist ){
      ConvertToHist(it.first,it.second);
    }

    ANA_MSG_INFO(it.first<<" Average time per event :"<<it.first.Data()<<" ms/event "<<it.second->hist->GetMean() );

  }

}
// --------------------------------------------------- //
void Timer::write()
{

  for( auto& it : m_timeLog ){
    if( !it.second->hist ) continue;
    TCanvas* c = new TCanvas();
    c->SetLogy();
    it.second->hist->Draw();
    c->SaveAs( TString::Format("Timer_%s.pdf",it.first.Data()) );
    delete c;
  }

}
// --------------------------------------------------- //
TString Timer::format(const char* va_fmt, va_list args)
{

  char buffer[512];
  vsnprintf (buffer,512,va_fmt,args);

  TString formatted_string = TString(buffer);
  return formatted_string;

}
