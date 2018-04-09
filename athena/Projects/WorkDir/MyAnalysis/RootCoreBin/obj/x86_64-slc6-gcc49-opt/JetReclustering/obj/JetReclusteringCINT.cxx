#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#ifdef __llvm__
#pragma GCC diagnostic ignored "-Wunused-private-field"
#endif
// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIuserdIhteagledIAnalysisDirectorydIBase_2_4_34dIRootCoreBindIobjdIx86_64mIslc6mIgcc49mIoptdIJetReclusteringdIobjdIJetReclusteringCINT

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
#include "JetReclustering/JetReclusteringAlgo.h"
#include "JetReclustering/JetReclusteringTool.h"
#include "JetReclustering/EffectiveRTool.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_JetReclusteringAlgo(void *p = 0);
   static void *newArray_JetReclusteringAlgo(Long_t size, void *p);
   static void delete_JetReclusteringAlgo(void *p);
   static void deleteArray_JetReclusteringAlgo(void *p);
   static void destruct_JetReclusteringAlgo(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::JetReclusteringAlgo*)
   {
      ::JetReclusteringAlgo *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::JetReclusteringAlgo >(0);
      static ::ROOT::TGenericClassInfo 
         instance("JetReclusteringAlgo", ::JetReclusteringAlgo::Class_Version(), "JetReclustering/JetReclusteringAlgo.h", 15,
                  typeid(::JetReclusteringAlgo), DefineBehavior(ptr, ptr),
                  &::JetReclusteringAlgo::Dictionary, isa_proxy, 4,
                  sizeof(::JetReclusteringAlgo) );
      instance.SetNew(&new_JetReclusteringAlgo);
      instance.SetNewArray(&newArray_JetReclusteringAlgo);
      instance.SetDelete(&delete_JetReclusteringAlgo);
      instance.SetDeleteArray(&deleteArray_JetReclusteringAlgo);
      instance.SetDestructor(&destruct_JetReclusteringAlgo);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::JetReclusteringAlgo*)
   {
      return GenerateInitInstanceLocal((::JetReclusteringAlgo*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::JetReclusteringAlgo*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static TClass *JetReclusteringTool_Dictionary();
   static void JetReclusteringTool_TClassManip(TClass*);
   static void delete_JetReclusteringTool(void *p);
   static void deleteArray_JetReclusteringTool(void *p);
   static void destruct_JetReclusteringTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::JetReclusteringTool*)
   {
      ::JetReclusteringTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::JetReclusteringTool));
      static ::ROOT::TGenericClassInfo 
         instance("JetReclusteringTool", "JetReclustering/JetReclusteringTool.h", 29,
                  typeid(::JetReclusteringTool), DefineBehavior(ptr, ptr),
                  &JetReclusteringTool_Dictionary, isa_proxy, 4,
                  sizeof(::JetReclusteringTool) );
      instance.SetDelete(&delete_JetReclusteringTool);
      instance.SetDeleteArray(&deleteArray_JetReclusteringTool);
      instance.SetDestructor(&destruct_JetReclusteringTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::JetReclusteringTool*)
   {
      return GenerateInitInstanceLocal((::JetReclusteringTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::JetReclusteringTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *JetReclusteringTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::JetReclusteringTool*)0x0)->GetClass();
      JetReclusteringTool_TClassManip(theClass);
   return theClass;
   }

   static void JetReclusteringTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *EffectiveRTool_Dictionary();
   static void EffectiveRTool_TClassManip(TClass*);
   static void delete_EffectiveRTool(void *p);
   static void deleteArray_EffectiveRTool(void *p);
   static void destruct_EffectiveRTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EffectiveRTool*)
   {
      ::EffectiveRTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::EffectiveRTool));
      static ::ROOT::TGenericClassInfo 
         instance("EffectiveRTool", "JetReclustering/EffectiveRTool.h", 13,
                  typeid(::EffectiveRTool), DefineBehavior(ptr, ptr),
                  &EffectiveRTool_Dictionary, isa_proxy, 4,
                  sizeof(::EffectiveRTool) );
      instance.SetDelete(&delete_EffectiveRTool);
      instance.SetDeleteArray(&deleteArray_EffectiveRTool);
      instance.SetDestructor(&destruct_EffectiveRTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EffectiveRTool*)
   {
      return GenerateInitInstanceLocal((::EffectiveRTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EffectiveRTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *EffectiveRTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::EffectiveRTool*)0x0)->GetClass();
      EffectiveRTool_TClassManip(theClass);
   return theClass;
   }

   static void EffectiveRTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr JetReclusteringAlgo::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *JetReclusteringAlgo::Class_Name()
{
   return "JetReclusteringAlgo";
}

//______________________________________________________________________________
const char *JetReclusteringAlgo::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::JetReclusteringAlgo*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int JetReclusteringAlgo::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::JetReclusteringAlgo*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *JetReclusteringAlgo::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::JetReclusteringAlgo*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *JetReclusteringAlgo::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::JetReclusteringAlgo*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void JetReclusteringAlgo::Streamer(TBuffer &R__b)
{
   // Stream an object of class JetReclusteringAlgo.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(JetReclusteringAlgo::Class(),this);
   } else {
      R__b.WriteClassBuffer(JetReclusteringAlgo::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_JetReclusteringAlgo(void *p) {
      return  p ? new(p) ::JetReclusteringAlgo : new ::JetReclusteringAlgo;
   }
   static void *newArray_JetReclusteringAlgo(Long_t nElements, void *p) {
      return p ? new(p) ::JetReclusteringAlgo[nElements] : new ::JetReclusteringAlgo[nElements];
   }
   // Wrapper around operator delete
   static void delete_JetReclusteringAlgo(void *p) {
      delete ((::JetReclusteringAlgo*)p);
   }
   static void deleteArray_JetReclusteringAlgo(void *p) {
      delete [] ((::JetReclusteringAlgo*)p);
   }
   static void destruct_JetReclusteringAlgo(void *p) {
      typedef ::JetReclusteringAlgo current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::JetReclusteringAlgo

namespace ROOT {
   // Wrapper around operator delete
   static void delete_JetReclusteringTool(void *p) {
      delete ((::JetReclusteringTool*)p);
   }
   static void deleteArray_JetReclusteringTool(void *p) {
      delete [] ((::JetReclusteringTool*)p);
   }
   static void destruct_JetReclusteringTool(void *p) {
      typedef ::JetReclusteringTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::JetReclusteringTool

namespace ROOT {
   // Wrapper around operator delete
   static void delete_EffectiveRTool(void *p) {
      delete ((::EffectiveRTool*)p);
   }
   static void deleteArray_EffectiveRTool(void *p) {
      delete [] ((::EffectiveRTool*)p);
   }
   static void destruct_EffectiveRTool(void *p) {
      typedef ::EffectiveRTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EffectiveRTool

namespace {
  void TriggerDictionaryInitialization_JetReclusteringCINT_Impl() {
    static const char* headers[] = {
"JetReclustering/JetReclusteringAlgo.h",
"JetReclustering/JetReclusteringTool.h",
"JetReclustering/EffectiveRTool.h",
0
    };
    static const char* includePaths[] = {
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/JetReclustering/Root",
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/JetReclustering",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/JetReclustering/cmt/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/JetReclustering/Root/LinkDef.h")))  JetReclusteringAlgo;
class __attribute__((annotate("$clingAutoload$/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/JetReclustering/Root/LinkDef.h")))  JetReclusteringTool;
class __attribute__((annotate("$clingAutoload$/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/JetReclustering/Root/LinkDef.h")))  EffectiveRTool;
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
  #define ROOTCORE_PACKAGE "JetReclustering"
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "JetReclustering/JetReclusteringAlgo.h"
#include "JetReclustering/JetReclusteringTool.h"
#include "JetReclustering/EffectiveRTool.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"EffectiveRTool", payloadCode, "@",
"JetReclusteringAlgo", payloadCode, "@",
"JetReclusteringTool", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("JetReclusteringCINT",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_JetReclusteringCINT_Impl, {{"namespace DataVector_detail { template <typename B1, typename B2, typename B3> class VirtBases; }", 1},{"template <typename T> class DataVectorBase;", 1},{"template <typename T, typename BASE> class DataVector;", 1},{"namespace DataVector_detail { template <typename T> class DVLEltBaseInit; }", 1}}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_JetReclusteringCINT_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_JetReclusteringCINT() {
  TriggerDictionaryInitialization_JetReclusteringCINT_Impl();
}
