// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIuserdIhteagledIAnalysisDirectorydIBase_2_4_34dIRootCoreBindIobjdIx86_64mIslc6mIgcc49mIoptdISUSYToolsdIobjdISUSYTools_Reflex

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
#include "/user/hteagle/AnalysisDirectory/Base_2_4_34/SUSYTools/SUSYTools/SUSYToolsDict.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *STcLcLSUSYObjDef_xAOD_Dictionary();
   static void STcLcLSUSYObjDef_xAOD_TClassManip(TClass*);
   static void delete_STcLcLSUSYObjDef_xAOD(void *p);
   static void deleteArray_STcLcLSUSYObjDef_xAOD(void *p);
   static void destruct_STcLcLSUSYObjDef_xAOD(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ST::SUSYObjDef_xAOD*)
   {
      ::ST::SUSYObjDef_xAOD *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ST::SUSYObjDef_xAOD));
      static ::ROOT::TGenericClassInfo 
         instance("ST::SUSYObjDef_xAOD", "SUSYTools/SUSYObjDef_xAOD.h", 108,
                  typeid(::ST::SUSYObjDef_xAOD), DefineBehavior(ptr, ptr),
                  &STcLcLSUSYObjDef_xAOD_Dictionary, isa_proxy, 0,
                  sizeof(::ST::SUSYObjDef_xAOD) );
      instance.SetDelete(&delete_STcLcLSUSYObjDef_xAOD);
      instance.SetDeleteArray(&deleteArray_STcLcLSUSYObjDef_xAOD);
      instance.SetDestructor(&destruct_STcLcLSUSYObjDef_xAOD);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ST::SUSYObjDef_xAOD*)
   {
      return GenerateInitInstanceLocal((::ST::SUSYObjDef_xAOD*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::ST::SUSYObjDef_xAOD*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *STcLcLSUSYObjDef_xAOD_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ST::SUSYObjDef_xAOD*)0x0)->GetClass();
      STcLcLSUSYObjDef_xAOD_TClassManip(theClass);
   return theClass;
   }

   static void STcLcLSUSYObjDef_xAOD_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *STcLcLISUSYObjDef_xAODTool_Dictionary();
   static void STcLcLISUSYObjDef_xAODTool_TClassManip(TClass*);
   static void delete_STcLcLISUSYObjDef_xAODTool(void *p);
   static void deleteArray_STcLcLISUSYObjDef_xAODTool(void *p);
   static void destruct_STcLcLISUSYObjDef_xAODTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ST::ISUSYObjDef_xAODTool*)
   {
      ::ST::ISUSYObjDef_xAODTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ST::ISUSYObjDef_xAODTool));
      static ::ROOT::TGenericClassInfo 
         instance("ST::ISUSYObjDef_xAODTool", "SUSYTools/ISUSYObjDef_xAODTool.h", 143,
                  typeid(::ST::ISUSYObjDef_xAODTool), DefineBehavior(ptr, ptr),
                  &STcLcLISUSYObjDef_xAODTool_Dictionary, isa_proxy, 0,
                  sizeof(::ST::ISUSYObjDef_xAODTool) );
      instance.SetDelete(&delete_STcLcLISUSYObjDef_xAODTool);
      instance.SetDeleteArray(&deleteArray_STcLcLISUSYObjDef_xAODTool);
      instance.SetDestructor(&destruct_STcLcLISUSYObjDef_xAODTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ST::ISUSYObjDef_xAODTool*)
   {
      return GenerateInitInstanceLocal((::ST::ISUSYObjDef_xAODTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::ST::ISUSYObjDef_xAODTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *STcLcLISUSYObjDef_xAODTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ST::ISUSYObjDef_xAODTool*)0x0)->GetClass();
      STcLcLISUSYObjDef_xAODTool_TClassManip(theClass);
   return theClass;
   }

   static void STcLcLISUSYObjDef_xAODTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrapper around operator delete
   static void delete_STcLcLSUSYObjDef_xAOD(void *p) {
      delete ((::ST::SUSYObjDef_xAOD*)p);
   }
   static void deleteArray_STcLcLSUSYObjDef_xAOD(void *p) {
      delete [] ((::ST::SUSYObjDef_xAOD*)p);
   }
   static void destruct_STcLcLSUSYObjDef_xAOD(void *p) {
      typedef ::ST::SUSYObjDef_xAOD current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ST::SUSYObjDef_xAOD

namespace ROOT {
   // Wrapper around operator delete
   static void delete_STcLcLISUSYObjDef_xAODTool(void *p) {
      delete ((::ST::ISUSYObjDef_xAODTool*)p);
   }
   static void deleteArray_STcLcLISUSYObjDef_xAODTool(void *p) {
      delete [] ((::ST::ISUSYObjDef_xAODTool*)p);
   }
   static void destruct_STcLcLISUSYObjDef_xAODTool(void *p) {
      typedef ::ST::ISUSYObjDef_xAODTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ST::ISUSYObjDef_xAODTool

namespace {
  void TriggerDictionaryInitialization_SUSYTools_Reflex_Impl() {
    static const char* headers[] = {
0    };
    static const char* includePaths[] = {
"/user/hteagle/AnalysisDirectory/Base_2_4_34/SUSYTools/Root",
"/user/hteagle/AnalysisDirectory/Base_2_4_34/SUSYTools",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/user/hteagle/AnalysisDirectory/Base_2_4_34/SUSYTools/cmt/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace ST{class __attribute__((annotate("$clingAutoload$SUSYTools/SUSYObjDef_xAOD.h")))  SUSYObjDef_xAOD;}
namespace ST{class __attribute__((annotate("$clingAutoload$SUSYTools/SUSYObjDef_xAOD.h")))  ISUSYObjDef_xAODTool;}
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
  #define ROOTCORE_PACKAGE "SUSYTools"
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#ifndef SUSYTOOLS_SUSYTOOLSDICT_H
#define SUSYTOOLS_SUSYTOOLSDICT_H

#include "SUSYTools/SUSYObjDef_xAOD.h"

#endif // not SUSYTOOLS_SUSYTOOLSDICT_H

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"ST::ISUSYObjDef_xAODTool", payloadCode, "@",
"ST::SUSYObjDef_xAOD", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("SUSYTools_Reflex",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_SUSYTools_Reflex_Impl, {{"namespace DataVector_detail { template <typename B1, typename B2, typename B3> class VirtBases; }", 1},{"template <typename T> class DataVectorBase;", 1},{"template <typename T, typename BASE> class DataVector;", 1},{"namespace DataVector_detail { template <typename T> class DVLEltBaseInit; }", 1}}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_SUSYTools_Reflex_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_SUSYTools_Reflex() {
  TriggerDictionaryInitialization_SUSYTools_Reflex_Impl();
}
