// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIuserdIhteagledIAnalysisDirectorydIBase_2_4_34dIRootCoreBindIobjdIx86_64mIslc6mIgcc49mIoptdIegammaMVACalibdIobjdIegammaMVACalib_Reflex

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
#include "/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/egammaMVACalib/egammaMVACalib/egammaMVACalibDict.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *egammaMVACalib_Dictionary();
   static void egammaMVACalib_TClassManip(TClass*);
   static void delete_egammaMVACalib(void *p);
   static void deleteArray_egammaMVACalib(void *p);
   static void destruct_egammaMVACalib(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::egammaMVACalib*)
   {
      ::egammaMVACalib *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::egammaMVACalib));
      static ::ROOT::TGenericClassInfo 
         instance("egammaMVACalib", "egammaMVACalib/egammaMVACalib.h", 52,
                  typeid(::egammaMVACalib), DefineBehavior(ptr, ptr),
                  &egammaMVACalib_Dictionary, isa_proxy, 0,
                  sizeof(::egammaMVACalib) );
      instance.SetDelete(&delete_egammaMVACalib);
      instance.SetDeleteArray(&deleteArray_egammaMVACalib);
      instance.SetDestructor(&destruct_egammaMVACalib);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::egammaMVACalib*)
   {
      return GenerateInitInstanceLocal((::egammaMVACalib*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::egammaMVACalib*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *egammaMVACalib_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::egammaMVACalib*)0x0)->GetClass();
      egammaMVACalib_TClassManip(theClass);
   return theClass;
   }

   static void egammaMVACalib_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *IegammaMVATool_Dictionary();
   static void IegammaMVATool_TClassManip(TClass*);
   static void delete_IegammaMVATool(void *p);
   static void deleteArray_IegammaMVATool(void *p);
   static void destruct_IegammaMVATool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::IegammaMVATool*)
   {
      ::IegammaMVATool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::IegammaMVATool));
      static ::ROOT::TGenericClassInfo 
         instance("IegammaMVATool", "egammaMVACalib/IegammaMVATool.h", 18,
                  typeid(::IegammaMVATool), DefineBehavior(ptr, ptr),
                  &IegammaMVATool_Dictionary, isa_proxy, 0,
                  sizeof(::IegammaMVATool) );
      instance.SetDelete(&delete_IegammaMVATool);
      instance.SetDeleteArray(&deleteArray_IegammaMVATool);
      instance.SetDestructor(&destruct_IegammaMVATool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::IegammaMVATool*)
   {
      return GenerateInitInstanceLocal((::IegammaMVATool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::IegammaMVATool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *IegammaMVATool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::IegammaMVATool*)0x0)->GetClass();
      IegammaMVATool_TClassManip(theClass);
   return theClass;
   }

   static void IegammaMVATool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *egammaMVATool_Dictionary();
   static void egammaMVATool_TClassManip(TClass*);
   static void delete_egammaMVATool(void *p);
   static void deleteArray_egammaMVATool(void *p);
   static void destruct_egammaMVATool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::egammaMVATool*)
   {
      ::egammaMVATool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::egammaMVATool));
      static ::ROOT::TGenericClassInfo 
         instance("egammaMVATool", "egammaMVACalib/egammaMVATool.h", 17,
                  typeid(::egammaMVATool), DefineBehavior(ptr, ptr),
                  &egammaMVATool_Dictionary, isa_proxy, 0,
                  sizeof(::egammaMVATool) );
      instance.SetDelete(&delete_egammaMVATool);
      instance.SetDeleteArray(&deleteArray_egammaMVATool);
      instance.SetDestructor(&destruct_egammaMVATool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::egammaMVATool*)
   {
      return GenerateInitInstanceLocal((::egammaMVATool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::egammaMVATool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *egammaMVATool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::egammaMVATool*)0x0)->GetClass();
      egammaMVATool_TClassManip(theClass);
   return theClass;
   }

   static void egammaMVATool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrapper around operator delete
   static void delete_egammaMVACalib(void *p) {
      delete ((::egammaMVACalib*)p);
   }
   static void deleteArray_egammaMVACalib(void *p) {
      delete [] ((::egammaMVACalib*)p);
   }
   static void destruct_egammaMVACalib(void *p) {
      typedef ::egammaMVACalib current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::egammaMVACalib

namespace ROOT {
   // Wrapper around operator delete
   static void delete_IegammaMVATool(void *p) {
      delete ((::IegammaMVATool*)p);
   }
   static void deleteArray_IegammaMVATool(void *p) {
      delete [] ((::IegammaMVATool*)p);
   }
   static void destruct_IegammaMVATool(void *p) {
      typedef ::IegammaMVATool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::IegammaMVATool

namespace ROOT {
   // Wrapper around operator delete
   static void delete_egammaMVATool(void *p) {
      delete ((::egammaMVATool*)p);
   }
   static void deleteArray_egammaMVATool(void *p) {
      delete [] ((::egammaMVATool*)p);
   }
   static void destruct_egammaMVATool(void *p) {
      typedef ::egammaMVATool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::egammaMVATool

namespace {
  void TriggerDictionaryInitialization_egammaMVACalib_Reflex_Impl() {
    static const char* headers[] = {
0    };
    static const char* includePaths[] = {
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/egammaMVACalib/Root",
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/egammaMVACalib",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/egammaMVACalib/cmt/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$egammaMVACalib/egammaMVACalib.h")))  egammaMVACalib;
class __attribute__((annotate("$clingAutoload$egammaMVACalib/IegammaMVATool.h")))  IegammaMVATool;
class __attribute__((annotate("$clingAutoload$egammaMVACalib/egammaMVATool.h")))  egammaMVATool;
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
  #define ROOTCORE_PACKAGE "egammaMVACalib"
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#ifndef EGAMMAMVACALIB_EGAMMAMVACALIBDICT_H

#include "egammaMVACalib/egammaMVACalib.h"
#include "egammaMVACalib/IegammaMVATool.h"
#include "egammaMVACalib/egammaMVATool.h"
//#include "egammaMVACalib/egammaMVATree.h"
#include <vector>

/*
namespace egammaMVACalibDict
{
  struct tmp
  {
    std::vector<egammaMVACalibNmsp::Node*> tmp1;
  };

} // namespace egammaMVACalibDict
*/

#endif // EGAMMAMVACALIB_EGAMMAMVACALIBDICT_H

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"IegammaMVATool", payloadCode, "@",
"egammaMVACalib", payloadCode, "@",
"egammaMVACalib::CalibrationType", payloadCode, "@",
"egammaMVACalib::ParticleType", payloadCode, "@",
"egammaMVACalib::ShiftType", payloadCode, "@",
"egammaMVACalib::egammaType", payloadCode, "@",
"egammaMVATool", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("egammaMVACalib_Reflex",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_egammaMVACalib_Reflex_Impl, {{"namespace DataVector_detail { template <typename B1, typename B2, typename B3> class VirtBases; }", 1},{"template <typename T, typename BASE> class DataVector;", 1}}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_egammaMVACalib_Reflex_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_egammaMVACalib_Reflex() {
  TriggerDictionaryInitialization_egammaMVACalib_Reflex_Impl();
}
