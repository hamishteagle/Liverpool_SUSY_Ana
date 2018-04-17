#ifndef NVisibleMInvisibleJigsaw_HH
#define NVisibleMInvisibleJigsaw_HH
#include <iostream>
#include <string>
#include <vector>
#include "RestFrames/RestFrame.h"
#include "RestFrames/RestFrameList.h"
#include "RestFrames/InvisibleJigsaw.h"
#include "RestFrames/JigsawList.h"
#include "RestFrames/State.h"
#include "RestFrames/StateList.h"

using namespace std;

namespace RestFrames {

  class RestFrame;
  class RestFrameList;
  class Jigsaw;
  class JigsawList;
  class InvisibleJigsaw;
  class State;
  class StateList;

  ///////////////////////////////////////////////
  // NVisibleMInvisibleJigsaw class
  ///////////////////////////////////////////////
  class NVisibleMInvisibleJigsaw : public InvisibleJigsaw{
  public:
    NVisibleMInvisibleJigsaw(const string& sname, const string& stitle, int N, int M);
    NVisibleMInvisibleJigsaw(const string& sname, const string& stitle, int ikey, int N, int M);
    virtual ~NVisibleMInvisibleJigsaw();

    virtual bool IsSoundBody() const ;
    virtual void SetGroup(Group* groupPtr);

  private:
    int m_Nvis;
    int m_Minv;  
    void Init(int N, int M);

  };

}

#endif
