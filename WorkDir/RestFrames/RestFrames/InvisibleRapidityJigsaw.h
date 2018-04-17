#ifndef InvisibleRapidityJigsaw_HH
#define InvisibleRapidityJigsaw_HH
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
  // InvisibleRapidityJigsaw class
  ///////////////////////////////////////////////
  class InvisibleRapidityJigsaw : public NVisibleMInvisibleJigsaw {
  public:
    //constructor and destructor
    InvisibleRapidityJigsaw(const string& sname, const string& stitle);
    InvisibleRapidityJigsaw(const string& sname, const string& stitle, int ikey);
    virtual ~InvisibleRapidityJigsaw();

    virtual bool AnalyzeEvent();

  protected:
    void Init();
  
  };

}

#endif
