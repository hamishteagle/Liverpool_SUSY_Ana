#ifndef MinimizeMassesCombinatoricJigsaw_HH
#define MinimizeMassesCombinatoricJigsaw_HH
#include <iostream>
#include <string>
#include <vector>
#include <TLorentzVector.h>
#include <TVector3.h>
#include "RestFrames/RestFrame.h"
#include "RestFrames/RestFrameList.h"
#include "RestFrames/Jigsaw.h"
#include "RestFrames/JigsawList.h"
#include "RestFrames/CombinatoricJigsaw.h"
#include "RestFrames/State.h"
#include "RestFrames/StateList.h"

using namespace std;

namespace RestFrames {

  class RestFrame;
  class RestFrameList;
  class Jigsaw;
  class JigsawList;
  class CombinatoricJigsaw;
  class State;
  class StateList;

  ///////////////////////////////////////////////
  // MinimizeMassesCombinatoricJigsaw class
  ///////////////////////////////////////////////
  class MinimizeMassesCombinatoricJigsaw : public CombinatoricJigsaw{
  public:
    MinimizeMassesCombinatoricJigsaw(const string& sname, const string& stitle);
    MinimizeMassesCombinatoricJigsaw(const string& sname, const string& stitle, int ikey);
    virtual ~MinimizeMassesCombinatoricJigsaw();

    virtual bool AnalyzeEvent();

  private:
    void Init();

  };

}

#endif
