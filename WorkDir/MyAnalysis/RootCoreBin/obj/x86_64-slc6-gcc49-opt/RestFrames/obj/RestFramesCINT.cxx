#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#ifdef __llvm__
#pragma GCC diagnostic ignored "-Wunused-private-field"
#endif
// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIuserdIhteagledIAnalysisDirectorydIBase_2_4_34dIRootCoreBindIobjdIx86_64mIslc6mIgcc49mIoptdIRestFramesdIobjdIRestFramesCINT

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "RestFrames/CombinatoricGroup.h"
#include "RestFrames/Group.h"
#include "RestFrames/Jigsaw.h"
#include "RestFrames/RestFrame.h"
#include "RestFrames/RestFrameList.h"
#include "RestFrames/GroupList.h"
#include "RestFrames/State.h"
#include "RestFrames/JigsawList.h"
#include "RestFrames/StateList.h"
#include "RestFrames/RFrame.h"
#include "RestFrames/FrameLink.h"
#include "RestFrames/CombinatoricState.h"
#include "RestFrames/CombinatoricJigsaw.h"
#include "RestFrames/ContraBoostInvariantJigsaw.h"
#include "RestFrames/NVisibleMInvisibleJigsaw.h"
#include "RestFrames/InvisibleJigsaw.h"
#include "RestFrames/InvisibleState.h"
#include "RestFrames/RInvisibleFrame.h"
#include "RestFrames/InvisibleFrame.h"
#include "RestFrames/DecayFrame.h"
#include "RestFrames/FramePlot.h"
#include "RestFrames/RVisibleFrame.h"
#include "RestFrames/VisibleFrame.h"
#include "RestFrames/RDecayFrame.h"
#include "RestFrames/GDecayFrame.h"
#include "RestFrames/GFrame.h"
#include "RestFrames/GInvisibleFrame.h"
#include "RestFrames/GLabFrame.h"
#include "RestFrames/LabFrame.h"
#include "RestFrames/GVisibleFrame.h"
#include "RestFrames/InvisibleGroup.h"
#include "RestFrames/InvisibleMassJigsaw.h"
#include "RestFrames/InvisibleRapidityJigsaw.h"
#include "RestFrames/MinimizeMassesCombinatoricJigsaw.h"
#include "RestFrames/RestFrames_config.h"
#include "RestFrames/RLabFrame.h"
#include "RestFrames/VisibleFrame.h"
#include "RestFrames/InvisibleFrame.h"
#include "RestFrames/RFrame.h"
#include "RestFrames/RSelfAssemblingFrame.h"

// Header files passed via #pragma extra_include

namespace RestFrames {
   namespace ROOT {
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance();
      static TClass *RestFrames_Dictionary();

      // Function generating the singleton type initializer
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance()
      {
         static ::ROOT::TGenericClassInfo 
            instance("RestFrames", 0 /*version*/, "RestFrames/RestFrame.h", 39,
                     ::ROOT::DefineBehavior((void*)0,(void*)0),
                     &RestFrames_Dictionary, 0);
         return &instance;
      }
      // Insure that the inline function is _not_ optimized away by the compiler
      ::ROOT::TGenericClassInfo *(*_R__UNIQUE_(InitFunctionKeeper))() = &GenerateInitInstance;  
      // Static variable to force the class initialization
      static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstance(); R__UseDummy(_R__UNIQUE_(Init));

      // Dictionary for non-ClassDef classes
      static TClass *RestFrames_Dictionary() {
         return GenerateInitInstance()->GetClass();
      }

   }
}

namespace {
  void TriggerDictionaryInitialization_RestFramesCINT_Impl() {
    static const char* headers[] = {
"RestFrames/CombinatoricGroup.h",
"RestFrames/Group.h",
"RestFrames/Jigsaw.h",
"RestFrames/RestFrame.h",
"RestFrames/RestFrameList.h",
"RestFrames/GroupList.h",
"RestFrames/State.h",
"RestFrames/JigsawList.h",
"RestFrames/StateList.h",
"RestFrames/RFrame.h",
"RestFrames/FrameLink.h",
"RestFrames/CombinatoricState.h",
"RestFrames/CombinatoricJigsaw.h",
"RestFrames/ContraBoostInvariantJigsaw.h",
"RestFrames/NVisibleMInvisibleJigsaw.h",
"RestFrames/InvisibleJigsaw.h",
"RestFrames/InvisibleState.h",
"RestFrames/RInvisibleFrame.h",
"RestFrames/InvisibleFrame.h",
"RestFrames/DecayFrame.h",
"RestFrames/FramePlot.h",
"RestFrames/RVisibleFrame.h",
"RestFrames/VisibleFrame.h",
"RestFrames/RDecayFrame.h",
"RestFrames/GDecayFrame.h",
"RestFrames/GFrame.h",
"RestFrames/GInvisibleFrame.h",
"RestFrames/GLabFrame.h",
"RestFrames/LabFrame.h",
"RestFrames/GVisibleFrame.h",
"RestFrames/InvisibleGroup.h",
"RestFrames/InvisibleMassJigsaw.h",
"RestFrames/InvisibleRapidityJigsaw.h",
"RestFrames/MinimizeMassesCombinatoricJigsaw.h",
"RestFrames/RestFrames_config.h",
"RestFrames/RLabFrame.h",
"RestFrames/VisibleFrame.h",
"RestFrames/InvisibleFrame.h",
"RestFrames/RFrame.h",
"RestFrames/RSelfAssemblingFrame.h",
0
    };
    static const char* includePaths[] = {
"/user/hteagle/AnalysisDirectory/Base_2_4_34/RestFrames/Root",
"/user/hteagle/AnalysisDirectory/Base_2_4_34/RestFrames",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/user/hteagle/AnalysisDirectory/Base_2_4_34/RestFrames/cmt/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif
#ifndef ROOTCORE
  #define ROOTCORE 1
#endif
#ifndef ROOTCORE_RELEASE_SERIES
  #define ROOTCORE_RELEASE_SERIES 24
#endif
#ifndef ROOTCORE_TEST_FILE
  #define ROOTCORE_TEST_FILE "/afs/cern.ch/user/a/asgbase/patspace/xAODs/r7725/mc15_13TeV.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.merge.AOD.e3698_s2608_s2183_r7725_r7676/AOD.07915862._000100.pool.root.1"
#endif
#ifndef ROOTCORE_TEST_DATA
  #define ROOTCORE_TEST_DATA "/afs/cern.ch/user/a/asgbase/patspace/xAODs/r7725"
#endif
#ifndef ASG_TEST_FILE_DATA
  #define ASG_TEST_FILE_DATA "/afs/cern.ch/user/a/asgbase/patspace/xAODs/r7562/data15_13TeV.00284154.physics_Main.merge.AOD.r7562_p2521/AOD.07687819._000382.pool.root.1"
#endif
#ifndef ASG_TEST_FILE_MC
  #define ASG_TEST_FILE_MC "/afs/cern.ch/user/a/asgbase/patspace/xAODs/r7725/mc15_13TeV.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.merge.AOD.e3698_s2608_s2183_r7725_r7676/AOD.07915862._000100.pool.root.1"
#endif
#ifndef ASG_TEST_FILE_MCAFII
  #define ASG_TEST_FILE_MCAFII ""
#endif
#ifndef ROOTCORE_PACKAGE
  #define ROOTCORE_PACKAGE "RestFrames"
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "RestFrames/CombinatoricGroup.h"
#include "RestFrames/Group.h"
#include "RestFrames/Jigsaw.h"
#include "RestFrames/RestFrame.h"
#include "RestFrames/RestFrameList.h"
#include "RestFrames/GroupList.h"
#include "RestFrames/State.h"
#include "RestFrames/JigsawList.h"
#include "RestFrames/StateList.h"
#include "RestFrames/RFrame.h"
#include "RestFrames/FrameLink.h"
#include "RestFrames/CombinatoricState.h"
#include "RestFrames/CombinatoricJigsaw.h"
#include "RestFrames/ContraBoostInvariantJigsaw.h"
#include "RestFrames/NVisibleMInvisibleJigsaw.h"
#include "RestFrames/InvisibleJigsaw.h"
#include "RestFrames/InvisibleState.h"
#include "RestFrames/RInvisibleFrame.h"
#include "RestFrames/InvisibleFrame.h"
#include "RestFrames/DecayFrame.h"
#include "RestFrames/FramePlot.h"
#include "RestFrames/RVisibleFrame.h"
#include "RestFrames/VisibleFrame.h"
#include "RestFrames/RDecayFrame.h"
#include "RestFrames/GDecayFrame.h"
#include "RestFrames/GFrame.h"
#include "RestFrames/GInvisibleFrame.h"
#include "RestFrames/GLabFrame.h"
#include "RestFrames/LabFrame.h"
#include "RestFrames/GVisibleFrame.h"
#include "RestFrames/InvisibleGroup.h"
#include "RestFrames/InvisibleMassJigsaw.h"
#include "RestFrames/InvisibleRapidityJigsaw.h"
#include "RestFrames/MinimizeMassesCombinatoricJigsaw.h"
#include "RestFrames/RestFrames_config.h"
#include "RestFrames/RLabFrame.h"
#include "RestFrames/VisibleFrame.h"
#include "RestFrames/InvisibleFrame.h"
#include "RestFrames/RFrame.h"
#include "RestFrames/RSelfAssemblingFrame.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("RestFramesCINT",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_RestFramesCINT_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_RestFramesCINT_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_RestFramesCINT() {
  TriggerDictionaryInitialization_RestFramesCINT_Impl();
}
