// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIuserdIhteagledIAnalysisDirectorydIBase_2_4_34dIRootCoreBindIobjdIx86_64mIslc6mIgcc49mIoptdIHFORToolsdIobjdIHFORTools_Reflex

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
#include "/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/HFORTools/HFORTools/HFORToolsDict.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *HFORSelectionTool_Dictionary();
   static void HFORSelectionTool_TClassManip(TClass*);
   static void delete_HFORSelectionTool(void *p);
   static void deleteArray_HFORSelectionTool(void *p);
   static void destruct_HFORSelectionTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::HFORSelectionTool*)
   {
      ::HFORSelectionTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::HFORSelectionTool));
      static ::ROOT::TGenericClassInfo 
         instance("HFORSelectionTool", "HFORTools/HFORSelectionTool.h", 38,
                  typeid(::HFORSelectionTool), DefineBehavior(ptr, ptr),
                  &HFORSelectionTool_Dictionary, isa_proxy, 0,
                  sizeof(::HFORSelectionTool) );
      instance.SetDelete(&delete_HFORSelectionTool);
      instance.SetDeleteArray(&deleteArray_HFORSelectionTool);
      instance.SetDestructor(&destruct_HFORSelectionTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::HFORSelectionTool*)
   {
      return GenerateInitInstanceLocal((::HFORSelectionTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::HFORSelectionTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *HFORSelectionTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::HFORSelectionTool*)0x0)->GetClass();
      HFORSelectionTool_TClassManip(theClass);
   return theClass;
   }

   static void HFORSelectionTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *IHFORSelectionTool_Dictionary();
   static void IHFORSelectionTool_TClassManip(TClass*);
   static void delete_IHFORSelectionTool(void *p);
   static void deleteArray_IHFORSelectionTool(void *p);
   static void destruct_IHFORSelectionTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::IHFORSelectionTool*)
   {
      ::IHFORSelectionTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::IHFORSelectionTool));
      static ::ROOT::TGenericClassInfo 
         instance("IHFORSelectionTool", "HFORTools/IHFORSelectionTool.h", 8,
                  typeid(::IHFORSelectionTool), DefineBehavior(ptr, ptr),
                  &IHFORSelectionTool_Dictionary, isa_proxy, 0,
                  sizeof(::IHFORSelectionTool) );
      instance.SetDelete(&delete_IHFORSelectionTool);
      instance.SetDeleteArray(&deleteArray_IHFORSelectionTool);
      instance.SetDestructor(&destruct_IHFORSelectionTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::IHFORSelectionTool*)
   {
      return GenerateInitInstanceLocal((::IHFORSelectionTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::IHFORSelectionTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *IHFORSelectionTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::IHFORSelectionTool*)0x0)->GetClass();
      IHFORSelectionTool_TClassManip(theClass);
   return theClass;
   }

   static void IHFORSelectionTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrapper around operator delete
   static void delete_HFORSelectionTool(void *p) {
      delete ((::HFORSelectionTool*)p);
   }
   static void deleteArray_HFORSelectionTool(void *p) {
      delete [] ((::HFORSelectionTool*)p);
   }
   static void destruct_HFORSelectionTool(void *p) {
      typedef ::HFORSelectionTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::HFORSelectionTool

namespace ROOT {
   // Wrapper around operator delete
   static void delete_IHFORSelectionTool(void *p) {
      delete ((::IHFORSelectionTool*)p);
   }
   static void deleteArray_IHFORSelectionTool(void *p) {
      delete [] ((::IHFORSelectionTool*)p);
   }
   static void destruct_IHFORSelectionTool(void *p) {
      typedef ::IHFORSelectionTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::IHFORSelectionTool

namespace {
  void TriggerDictionaryInitialization_HFORTools_Reflex_Impl() {
    static const char* headers[] = {
0    };
    static const char* includePaths[] = {
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/HFORTools/Root",
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/HFORTools",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/HFORTools/cmt/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$HFORTools/HFORSelectionTool.h")))  HFORSelectionTool;
class __attribute__((annotate("$clingAutoload$HFORTools/HFORSelectionTool.h")))  IHFORSelectionTool;
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
  #define ROOTCORE_PACKAGE "HFORTools"
#endif

#define _BACKWARD_BACKWARD_WARNING_H

#ifndef HFORTOOLS_HFORTOOLSDICT_H
#define HFORTOOLS_HFORTOOLSDICT_H

#include "HFORTools/HFORSelectionTool.h"

#endif

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"HFORSelectionTool", payloadCode, "@",
"IHFORSelectionTool", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("HFORTools_Reflex",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_HFORTools_Reflex_Impl, {{"namespace DataVector_detail { template <typename B1, typename B2, typename B3> class VirtBases; }", 1},{"template <typename T> class DataVectorBase;", 1},{"template <typename T, typename BASE> class DataVector;", 1},{"namespace DataVector_detail { template <typename T> class DVLEltBaseInit; }", 1}}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_HFORTools_Reflex_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_HFORTools_Reflex() {
  TriggerDictionaryInitialization_HFORTools_Reflex_Impl();
}
