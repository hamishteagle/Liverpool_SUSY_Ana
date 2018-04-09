#ifndef InvisibleJigsaw_HH
#define InvisibleJigsaw_HH
#include <iostream>
#include <string>
#include <vector>
#include <TLorentzVector.h>
#include <TVector3.h>
#include "RestFrames/RestFrame.h"
#include "RestFrames/RestFrameList.h"
#include "RestFrames/RFrame.h"
#include "RestFrames/Jigsaw.h"
#include "RestFrames/JigsawList.h"
#include "RestFrames/InvisibleState.h"
#include "RestFrames/StateList.h"

using namespace std;

namespace RestFrames {

  class RestFrame;
  class RestFrameList;
  class RFrame;
  class Jigsaw;
  class JigsawList;
  class State;
  class StateList;
  class InvisibleState;
  class Jigsaw;

  ///////////////////////////////////////////////
  // InvisibleJigsaw class
  ///////////////////////////////////////////////

  class InvisibleJigsaw : public Jigsaw {
  public:
    InvisibleJigsaw(const string& sname, const string& stitle);
    InvisibleJigsaw(const string& sname, const string& stitle, int ikey);
    virtual ~InvisibleJigsaw();

    void AddVisibleFrame(RestFrame& framePtr, int i = 0);
    void AddVisibleFrame(RestFrame* framePtr, int i = 0);
    void AddVisibleFrame(RestFrameList* framesPtr, int i = 0);
    void AddInvisibleFrame(RestFrame& framePtr, int i = 0);
    void AddInvisibleFrame(RestFrame* framePtr, int i = 0);
    void AddInvisibleFrame(RestFrameList* framesPtr, int i = 0);

    virtual double GetMinimumMass();
    virtual bool InitializeDependancyJigsaws();
    virtual void FillInvisibleMassJigsawDependancies(JigsawList* jigsaws);

    virtual bool InitializeJigsawExecutionList(JigsawList* chain_jigsawPtr);

  protected:
    virtual State* NewOutputState();

  private:
    void Init();
  
  };

}

#endif
