// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIuserdIhteagledIAnalysisDirectorydIBase_2_4_34dIRootCoreBindIobjdIx86_64mIslc6mIgcc49mIoptdITriggerMatchingTooldIobjdITriggerMatchingTool_Reflex

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
#include "/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/TriggerMatchingTool/TriggerMatchingTool/TriggerMatchingToolDict.h"

// Header files passed via #pragma extra_include

namespace Trig {
   namespace ROOT {
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance();
      static TClass *Trig_Dictionary();

      // Function generating the singleton type initializer
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance()
      {
         static ::ROOT::TGenericClassInfo 
            instance("Trig", 0 /*version*/, "TriggerMatchingTool/IMatchingTool.h", 15,
                     ::ROOT::DefineBehavior((void*)0,(void*)0),
                     &Trig_Dictionary, 0);
         return &instance;
      }
      // Insure that the inline function is _not_ optimized away by the compiler
      ::ROOT::TGenericClassInfo *(*_R__UNIQUE_(InitFunctionKeeper))() = &GenerateInitInstance;  
      // Static variable to force the class initialization
      static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstance(); R__UseDummy(_R__UNIQUE_(Init));

      // Dictionary for non-ClassDef classes
      static TClass *Trig_Dictionary() {
         return GenerateInitInstance()->GetClass();
      }

   }
}

namespace ROOT {
   static TClass *TrigcLcLMatchingTool_Dictionary();
   static void TrigcLcLMatchingTool_TClassManip(TClass*);
   static void delete_TrigcLcLMatchingTool(void *p);
   static void deleteArray_TrigcLcLMatchingTool(void *p);
   static void destruct_TrigcLcLMatchingTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Trig::MatchingTool*)
   {
      ::Trig::MatchingTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Trig::MatchingTool));
      static ::ROOT::TGenericClassInfo 
         instance("Trig::MatchingTool", "TriggerMatchingTool/MatchingTool.h", 17,
                  typeid(::Trig::MatchingTool), DefineBehavior(ptr, ptr),
                  &TrigcLcLMatchingTool_Dictionary, isa_proxy, 0,
                  sizeof(::Trig::MatchingTool) );
      instance.SetDelete(&delete_TrigcLcLMatchingTool);
      instance.SetDeleteArray(&deleteArray_TrigcLcLMatchingTool);
      instance.SetDestructor(&destruct_TrigcLcLMatchingTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Trig::MatchingTool*)
   {
      return GenerateInitInstanceLocal((::Trig::MatchingTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::Trig::MatchingTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TrigcLcLMatchingTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Trig::MatchingTool*)0x0)->GetClass();
      TrigcLcLMatchingTool_TClassManip(theClass);
   return theClass;
   }

   static void TrigcLcLMatchingTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TrigcLcLIMatchingTool_Dictionary();
   static void TrigcLcLIMatchingTool_TClassManip(TClass*);
   static void delete_TrigcLcLIMatchingTool(void *p);
   static void deleteArray_TrigcLcLIMatchingTool(void *p);
   static void destruct_TrigcLcLIMatchingTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Trig::IMatchingTool*)
   {
      ::Trig::IMatchingTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Trig::IMatchingTool));
      static ::ROOT::TGenericClassInfo 
         instance("Trig::IMatchingTool", "TriggerMatchingTool/IMatchingTool.h", 19,
                  typeid(::Trig::IMatchingTool), DefineBehavior(ptr, ptr),
                  &TrigcLcLIMatchingTool_Dictionary, isa_proxy, 0,
                  sizeof(::Trig::IMatchingTool) );
      instance.SetDelete(&delete_TrigcLcLIMatchingTool);
      instance.SetDeleteArray(&deleteArray_TrigcLcLIMatchingTool);
      instance.SetDestructor(&destruct_TrigcLcLIMatchingTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Trig::IMatchingTool*)
   {
      return GenerateInitInstanceLocal((::Trig::IMatchingTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::Trig::IMatchingTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TrigcLcLIMatchingTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Trig::IMatchingTool*)0x0)->GetClass();
      TrigcLcLIMatchingTool_TClassManip(theClass);
   return theClass;
   }

   static void TrigcLcLIMatchingTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrapper around operator delete
   static void delete_TrigcLcLMatchingTool(void *p) {
      delete ((::Trig::MatchingTool*)p);
   }
   static void deleteArray_TrigcLcLMatchingTool(void *p) {
      delete [] ((::Trig::MatchingTool*)p);
   }
   static void destruct_TrigcLcLMatchingTool(void *p) {
      typedef ::Trig::MatchingTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Trig::MatchingTool

namespace ROOT {
   // Wrapper around operator delete
   static void delete_TrigcLcLIMatchingTool(void *p) {
      delete ((::Trig::IMatchingTool*)p);
   }
   static void deleteArray_TrigcLcLIMatchingTool(void *p) {
      delete [] ((::Trig::IMatchingTool*)p);
   }
   static void destruct_TrigcLcLIMatchingTool(void *p) {
      typedef ::Trig::IMatchingTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Trig::IMatchingTool

namespace {
  void TriggerDictionaryInitialization_TriggerMatchingTool_Reflex_Impl() {
    static const char* headers[] = {
0    };
    static const char* includePaths[] = {
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/TriggerMatchingTool/Root",
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/TriggerMatchingTool",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/TriggerMatchingTool/cmt/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace Trig{class __attribute__((annotate("$clingAutoload$TriggerMatchingTool/MatchingTool.h")))  MatchingTool;}
namespace Trig{class __attribute__((annotate("$clingAutoload$TriggerMatchingTool/MatchingTool.h")))  IMatchingTool;}
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
#ifndef XAOD_STANDALONE
  #define XAOD_STANDALONE 1
#endif
#ifndef XAOD_ANALYSIS
  #define XAOD_ANALYSIS 1
#endif
#ifndef ASGTOOL_STANDALONE
  #define ASGTOOL_STANDALONE 1
#endif
#ifndef ROOTCORE_PACKAGE
  #define ROOTCORE_PACKAGE "TriggerMatchingTool"
#endif

#define _BACKWARD_BACKWARD_WARNING_H

#ifndef TRIGGERMATCHINGTOOL_TRIGGERMATCHINGTOOLDICT_H
#define TRIGGERMATCHINGTOOL_TRIGGERMATCHINGTOOLDICT_H

#include "TriggerMatchingTool/MatchingTool.h"

#endif

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"Trig::IMatchingTool", payloadCode, "@",
"Trig::MatchingTool", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TriggerMatchingTool_Reflex",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TriggerMatchingTool_Reflex_Impl, {{"namespace DataVector_detail { template <typename B1, typename B2, typename B3> class VirtBases; }", 1},{"template <typename T> class DataVectorBase;", 1},{"template <typename T, typename BASE> class DataVector;", 1}}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TriggerMatchingTool_Reflex_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TriggerMatchingTool_Reflex() {
  TriggerDictionaryInitialization_TriggerMatchingTool_Reflex_Impl();
}
