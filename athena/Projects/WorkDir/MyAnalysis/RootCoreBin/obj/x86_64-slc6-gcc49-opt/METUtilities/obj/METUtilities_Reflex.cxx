// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIuserdIhteagledIAnalysisDirectorydIBase_2_4_34dIRootCoreBindIobjdIx86_64mIslc6mIgcc49mIoptdIMETUtilitiesdIobjdIMETUtilities_Reflex

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
#include "/user/hteagle/AnalysisDirectory/Base_2_4_34/METUtilities/METUtilities/METUtilitiesDict.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *metcLcLMETRebuilder_Dictionary();
   static void metcLcLMETRebuilder_TClassManip(TClass*);
   static void delete_metcLcLMETRebuilder(void *p);
   static void deleteArray_metcLcLMETRebuilder(void *p);
   static void destruct_metcLcLMETRebuilder(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::met::METRebuilder*)
   {
      ::met::METRebuilder *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::met::METRebuilder));
      static ::ROOT::TGenericClassInfo 
         instance("met::METRebuilder", "METUtilities/METRebuilder.h", 34,
                  typeid(::met::METRebuilder), DefineBehavior(ptr, ptr),
                  &metcLcLMETRebuilder_Dictionary, isa_proxy, 0,
                  sizeof(::met::METRebuilder) );
      instance.SetDelete(&delete_metcLcLMETRebuilder);
      instance.SetDeleteArray(&deleteArray_metcLcLMETRebuilder);
      instance.SetDestructor(&destruct_metcLcLMETRebuilder);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::met::METRebuilder*)
   {
      return GenerateInitInstanceLocal((::met::METRebuilder*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::met::METRebuilder*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *metcLcLMETRebuilder_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::met::METRebuilder*)0x0)->GetClass();
      metcLcLMETRebuilder_TClassManip(theClass);
   return theClass;
   }

   static void metcLcLMETRebuilder_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *metcLcLMETMaker_Dictionary();
   static void metcLcLMETMaker_TClassManip(TClass*);
   static void delete_metcLcLMETMaker(void *p);
   static void deleteArray_metcLcLMETMaker(void *p);
   static void destruct_metcLcLMETMaker(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::met::METMaker*)
   {
      ::met::METMaker *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::met::METMaker));
      static ::ROOT::TGenericClassInfo 
         instance("met::METMaker", "METUtilities/METMaker.h", 32,
                  typeid(::met::METMaker), DefineBehavior(ptr, ptr),
                  &metcLcLMETMaker_Dictionary, isa_proxy, 0,
                  sizeof(::met::METMaker) );
      instance.SetDelete(&delete_metcLcLMETMaker);
      instance.SetDeleteArray(&deleteArray_metcLcLMETMaker);
      instance.SetDestructor(&destruct_metcLcLMETMaker);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::met::METMaker*)
   {
      return GenerateInitInstanceLocal((::met::METMaker*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::met::METMaker*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *metcLcLMETMaker_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::met::METMaker*)0x0)->GetClass();
      metcLcLMETMaker_TClassManip(theClass);
   return theClass;
   }

   static void metcLcLMETMaker_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *metcLcLMETSystematicsTool_Dictionary();
   static void metcLcLMETSystematicsTool_TClassManip(TClass*);
   static void delete_metcLcLMETSystematicsTool(void *p);
   static void deleteArray_metcLcLMETSystematicsTool(void *p);
   static void destruct_metcLcLMETSystematicsTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::met::METSystematicsTool*)
   {
      ::met::METSystematicsTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::met::METSystematicsTool));
      static ::ROOT::TGenericClassInfo 
         instance("met::METSystematicsTool", "METUtilities/METSystematicsTool.h", 70,
                  typeid(::met::METSystematicsTool), DefineBehavior(ptr, ptr),
                  &metcLcLMETSystematicsTool_Dictionary, isa_proxy, 0,
                  sizeof(::met::METSystematicsTool) );
      instance.SetDelete(&delete_metcLcLMETSystematicsTool);
      instance.SetDeleteArray(&deleteArray_metcLcLMETSystematicsTool);
      instance.SetDestructor(&destruct_metcLcLMETSystematicsTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::met::METSystematicsTool*)
   {
      return GenerateInitInstanceLocal((::met::METSystematicsTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::met::METSystematicsTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *metcLcLMETSystematicsTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::met::METSystematicsTool*)0x0)->GetClass();
      metcLcLMETSystematicsTool_TClassManip(theClass);
   return theClass;
   }

   static void metcLcLMETSystematicsTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *metcLcLMETSignificance_Dictionary();
   static void metcLcLMETSignificance_TClassManip(TClass*);
   static void delete_metcLcLMETSignificance(void *p);
   static void deleteArray_metcLcLMETSignificance(void *p);
   static void destruct_metcLcLMETSignificance(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::met::METSignificance*)
   {
      ::met::METSignificance *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::met::METSignificance));
      static ::ROOT::TGenericClassInfo 
         instance("met::METSignificance", "METUtilities/METSignificance.h", 41,
                  typeid(::met::METSignificance), DefineBehavior(ptr, ptr),
                  &metcLcLMETSignificance_Dictionary, isa_proxy, 0,
                  sizeof(::met::METSignificance) );
      instance.SetDelete(&delete_metcLcLMETSignificance);
      instance.SetDeleteArray(&deleteArray_metcLcLMETSignificance);
      instance.SetDestructor(&destruct_metcLcLMETSignificance);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::met::METSignificance*)
   {
      return GenerateInitInstanceLocal((::met::METSignificance*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::met::METSignificance*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *metcLcLMETSignificance_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::met::METSignificance*)0x0)->GetClass();
      metcLcLMETSignificance_TClassManip(theClass);
   return theClass;
   }

   static void metcLcLMETSignificance_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrapper around operator delete
   static void delete_metcLcLMETRebuilder(void *p) {
      delete ((::met::METRebuilder*)p);
   }
   static void deleteArray_metcLcLMETRebuilder(void *p) {
      delete [] ((::met::METRebuilder*)p);
   }
   static void destruct_metcLcLMETRebuilder(void *p) {
      typedef ::met::METRebuilder current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::met::METRebuilder

namespace ROOT {
   // Wrapper around operator delete
   static void delete_metcLcLMETMaker(void *p) {
      delete ((::met::METMaker*)p);
   }
   static void deleteArray_metcLcLMETMaker(void *p) {
      delete [] ((::met::METMaker*)p);
   }
   static void destruct_metcLcLMETMaker(void *p) {
      typedef ::met::METMaker current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::met::METMaker

namespace ROOT {
   // Wrapper around operator delete
   static void delete_metcLcLMETSystematicsTool(void *p) {
      delete ((::met::METSystematicsTool*)p);
   }
   static void deleteArray_metcLcLMETSystematicsTool(void *p) {
      delete [] ((::met::METSystematicsTool*)p);
   }
   static void destruct_metcLcLMETSystematicsTool(void *p) {
      typedef ::met::METSystematicsTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::met::METSystematicsTool

namespace ROOT {
   // Wrapper around operator delete
   static void delete_metcLcLMETSignificance(void *p) {
      delete ((::met::METSignificance*)p);
   }
   static void deleteArray_metcLcLMETSignificance(void *p) {
      delete [] ((::met::METSignificance*)p);
   }
   static void destruct_metcLcLMETSignificance(void *p) {
      typedef ::met::METSignificance current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::met::METSignificance

namespace {
  void TriggerDictionaryInitialization_METUtilities_Reflex_Impl() {
    static const char* headers[] = {
0    };
    static const char* includePaths[] = {
"/user/hteagle/AnalysisDirectory/Base_2_4_34/METUtilities/Root",
"/user/hteagle/AnalysisDirectory/Base_2_4_34/METUtilities",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/user/hteagle/AnalysisDirectory/Base_2_4_34/METUtilities/cmt/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace met{class __attribute__((annotate("$clingAutoload$METUtilities/METRebuilder.h")))  METRebuilder;}
namespace met{class __attribute__((annotate("$clingAutoload$METUtilities/METMaker.h")))  METMaker;}
namespace met{class __attribute__((annotate("$clingAutoload$METUtilities/METSystematicsTool.h")))  METSystematicsTool;}
namespace met{class __attribute__((annotate("$clingAutoload$METUtilities/METSignificance.h")))  METSignificance;}
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
  #define ROOTCORE_PACKAGE "METUtilities"
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#ifndef METUTILITIESDICT_H
#define METUTILITIESDICT_H

#if defined(__GCCXML__) and not defined(EIGEN_DONT_VECTORIZE)
#define EIGEN_DONT_VECTORIZE
#endif // __GCCXML__

#include "METUtilities/METRebuilder.h"
#include "METUtilities/METMaker.h"
#include "METUtilities/METSystematicsTool.h"
#include "METUtilities/METSignificance.h"

#endif //METUTILITIESDICT_H

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"met::METMaker", payloadCode, "@",
"met::METRebuilder", payloadCode, "@",
"met::METSignificance", payloadCode, "@",
"met::METSystematicsTool", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("METUtilities_Reflex",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_METUtilities_Reflex_Impl, {{"namespace DataVector_detail { template <typename B1, typename B2, typename B3> class VirtBases; }", 1},{"template <typename T> class DataVectorBase;", 1},{"template <typename T, typename BASE> class DataVector;", 1},{"namespace DataVector_detail { template <typename T> class DVLEltBaseInit; }", 1}}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_METUtilities_Reflex_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_METUtilities_Reflex() {
  TriggerDictionaryInitialization_METUtilities_Reflex_Impl();
}
