#ifndef ContraBoostInvariantJigsaw_HH
#define ContraBoostInvariantJigsaw_HH
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <TLorentzVector.h>
#include <TVector3.h>
#include "RestFrames/RestFrame.h"
#include "RestFrames/RestFrameList.h"
#include "RestFrames/NVisibleMInvisibleJigsaw.h"
#include "RestFrames/JigsawList.h"
#include "RestFrames/InvisibleState.h"
#include "RestFrames/StateList.h"

using namespace std;

namespace RestFrames {

  class RestFrame;
  class RestFrameList;
  class Jigsaw;
  class NVisibleMInvisibleJigsaw;
  class State;
  class InvisibleState;
  class StateList;

  ///////////////////////////////////////////////
  // ContraBoostInvariantJigsaw class
  ///////////////////////////////////////////////
  class ContraBoostInvariantJigsaw : public NVisibleMInvisibleJigsaw {
  public:
    //constructor and destructor
    ContraBoostInvariantJigsaw(const string& sname, const string& stitle);
    ContraBoostInvariantJigsaw(const string& sname, const string& stitle, int ikey);
    ~ContraBoostInvariantJigsaw();

    virtual double GetMinimumMass();
    virtual bool AnalyzeEvent();

    virtual void FillInvisibleMassJigsawDependancies(JigsawList* jigsaws);

  protected:
    void CalcCoef();
    double GetC1(){ return m_C1; }
    double GetC2(){ return m_C2; }

  private:
    double m_C1;
    double m_C2;
    void Init();
  
  };

}

#endif
