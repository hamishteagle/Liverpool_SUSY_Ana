#ifndef InvisibleMassJigsaw_HH
#define InvisibleMassJigsaw_HH
#include <iostream>
#include <TLorentzVector.h>
#include <TVector3.h>
#include "RestFrames/RestFrame.h"
#include "RestFrames/RestFrameList.h"
#include "RestFrames/NVisibleMInvisibleJigsaw.h"
#include "RestFrames/JigsawList.h"
#include "RestFrames/State.h"
#include "RestFrames/StateList.h"

using namespace std;

namespace RestFrames {

  class RestFrame;
  class RestFrameList;
  class Jigsaw;
  class NVisibleMInvisibleJigsaw;
  class State;
  class StateList;

  ///////////////////////////////////////////////
  // InvisibleMassJigsaw class
  ///////////////////////////////////////////////
  class InvisibleMassJigsaw : public NVisibleMInvisibleJigsaw {
  public:
    InvisibleMassJigsaw(const string& sname, const string& stitle);
    InvisibleMassJigsaw(const string& sname, const string& stitle, int ikey);
    virtual ~InvisibleMassJigsaw();

    virtual bool AnalyzeEvent();
    
  protected:
    void Init();
  
  };

}

#endif
