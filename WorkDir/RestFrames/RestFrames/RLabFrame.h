#ifndef RLabFrame_HH
#define RLabFrame_HH
#include <iostream>
#include <string>
#include <vector>
#include <TLorentzVector.h>
#include <TVector3.h>
#include "VisibleFrame.h"
#include "InvisibleFrame.h"
#include "RestFrames/LabFrame.h"
#include "RestFrames/DecayFrame.h"
#include "RFrame.h"
#include "RestFrames/RestFrameList.h"
#include "RestFrames/Jigsaw.h"
#include "RestFrames/JigsawList.h"
#include "RestFrames/FrameLink.h"
#include "RestFrames/State.h"
#include "RestFrames/StateList.h"

using namespace std;

namespace RestFrames {

  class FrameLink;
  class Jigsaw;
  class JigsawList;
  class RestFrame;
  class RFrame;
  class DecayFrame;
  class LabFrame;
  class RestFrameList;
  class State;
  class StateList;

  ///////////////////////////////////////////////
  // RLabFrame class
  ///////////////////////////////////////////////
  class RLabFrame : public LabFrame, public RFrame {
  public:
    RLabFrame(const string& sname, const string& stitle, int key);
    RLabFrame(const string& sname, const string& stitle);
    virtual ~RLabFrame();
  
    virtual bool InitializeAnalysis();
    virtual void ClearEvent();
    virtual bool AnalyzeEvent();

  protected:
    GroupList  m_LabGroups;
    StateList  m_LabStates;
    JigsawList m_LabJigsaws;
  
    bool InitializeLabStates();
    bool InitializeLabGroups();
    bool InitializeLabJigsaws();

    
    bool ExecuteJigsaws();

  private:
    void Init();
    void ClearStates();
  };

}

#endif
