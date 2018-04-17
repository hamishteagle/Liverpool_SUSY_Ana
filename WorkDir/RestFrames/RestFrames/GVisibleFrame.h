#ifndef GVisibleFrame_HH
#define GVisibleFrame_HH
#include <iostream>
#include <string>
#include <vector>
#include <TLorentzVector.h>
#include <TVector3.h>
#include "RestFrames/VisibleFrame.h"
#include "RestFrames/GFrame.h"

using namespace std;

namespace RestFrames {

  class RestFrame;
  class GFrame;
  class VisibleFrame;

  ///////////////////////////////////////////////
  // GVisibleFrame class
  ///////////////////////////////////////////////
  class GVisibleFrame : public VisibleFrame, public GFrame{
  public:
    GVisibleFrame(const string& sname, const string& stitle, int key);
    GVisibleFrame(const string& sname, const string& stitle);
    virtual ~GVisibleFrame();

    virtual void SetMass(double val);

  protected:
    double m_Mass;

    virtual void ResetFrame();
    virtual bool GenerateFrame();

  private:
    void Init();

  };

}

#endif
