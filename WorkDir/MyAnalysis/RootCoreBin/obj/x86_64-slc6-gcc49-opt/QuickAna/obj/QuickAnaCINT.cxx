#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#ifdef __llvm__
#pragma GCC diagnostic ignored "-Wunused-private-field"
#endif
// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIuserdIhteagledIAnalysisDirectorydIBase_2_4_34dIRootCoreBindIobjdIx86_64mIslc6mIgcc49mIoptdIQuickAnadIobjdIQuickAnaCINT

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
#include "QuickAna/Global.h"
#include "QuickAna/Configuration.h"
#include "QuickAna/ELExample.h"
#include "QuickAna/QuickAna.h"
#include "QuickAna/ValidationEL.h"
#include "QuickAna/xAODTruth.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *anacLcLConfiguration_Dictionary();
   static void anacLcLConfiguration_TClassManip(TClass*);
   static void *new_anacLcLConfiguration(void *p = 0);
   static void *newArray_anacLcLConfiguration(Long_t size, void *p);
   static void delete_anacLcLConfiguration(void *p);
   static void deleteArray_anacLcLConfiguration(void *p);
   static void destruct_anacLcLConfiguration(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ana::Configuration*)
   {
      ::ana::Configuration *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ana::Configuration));
      static ::ROOT::TGenericClassInfo 
         instance("ana::Configuration", "QuickAna/Configuration.h", 25,
                  typeid(::ana::Configuration), DefineBehavior(ptr, ptr),
                  &anacLcLConfiguration_Dictionary, isa_proxy, 4,
                  sizeof(::ana::Configuration) );
      instance.SetNew(&new_anacLcLConfiguration);
      instance.SetNewArray(&newArray_anacLcLConfiguration);
      instance.SetDelete(&delete_anacLcLConfiguration);
      instance.SetDeleteArray(&deleteArray_anacLcLConfiguration);
      instance.SetDestructor(&destruct_anacLcLConfiguration);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ana::Configuration*)
   {
      return GenerateInitInstanceLocal((::ana::Configuration*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::ana::Configuration*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *anacLcLConfiguration_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ana::Configuration*)0x0)->GetClass();
      anacLcLConfiguration_TClassManip(theClass);
   return theClass;
   }

   static void anacLcLConfiguration_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static void *new_anacLcLELExample(void *p = 0);
   static void *newArray_anacLcLELExample(Long_t size, void *p);
   static void delete_anacLcLELExample(void *p);
   static void deleteArray_anacLcLELExample(void *p);
   static void destruct_anacLcLELExample(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ana::ELExample*)
   {
      ::ana::ELExample *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::ana::ELExample >(0);
      static ::ROOT::TGenericClassInfo 
         instance("ana::ELExample", ::ana::ELExample::Class_Version(), "QuickAna/ELExample.h", 25,
                  typeid(::ana::ELExample), DefineBehavior(ptr, ptr),
                  &::ana::ELExample::Dictionary, isa_proxy, 4,
                  sizeof(::ana::ELExample) );
      instance.SetNew(&new_anacLcLELExample);
      instance.SetNewArray(&newArray_anacLcLELExample);
      instance.SetDelete(&delete_anacLcLELExample);
      instance.SetDeleteArray(&deleteArray_anacLcLELExample);
      instance.SetDestructor(&destruct_anacLcLELExample);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ana::ELExample*)
   {
      return GenerateInitInstanceLocal((::ana::ELExample*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::ana::ELExample*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static TClass *anacLcLQuickAna_Dictionary();
   static void anacLcLQuickAna_TClassManip(TClass*);
   static void delete_anacLcLQuickAna(void *p);
   static void deleteArray_anacLcLQuickAna(void *p);
   static void destruct_anacLcLQuickAna(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ana::QuickAna*)
   {
      ::ana::QuickAna *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ana::QuickAna));
      static ::ROOT::TGenericClassInfo 
         instance("ana::QuickAna", "QuickAna/QuickAna.h", 29,
                  typeid(::ana::QuickAna), DefineBehavior(ptr, ptr),
                  &anacLcLQuickAna_Dictionary, isa_proxy, 4,
                  sizeof(::ana::QuickAna) );
      instance.SetDelete(&delete_anacLcLQuickAna);
      instance.SetDeleteArray(&deleteArray_anacLcLQuickAna);
      instance.SetDestructor(&destruct_anacLcLQuickAna);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ana::QuickAna*)
   {
      return GenerateInitInstanceLocal((::ana::QuickAna*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::ana::QuickAna*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *anacLcLQuickAna_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ana::QuickAna*)0x0)->GetClass();
      anacLcLQuickAna_TClassManip(theClass);
   return theClass;
   }

   static void anacLcLQuickAna_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static void *new_anacLcLValidationEL(void *p = 0);
   static void *newArray_anacLcLValidationEL(Long_t size, void *p);
   static void delete_anacLcLValidationEL(void *p);
   static void deleteArray_anacLcLValidationEL(void *p);
   static void destruct_anacLcLValidationEL(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ana::ValidationEL*)
   {
      ::ana::ValidationEL *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::ana::ValidationEL >(0);
      static ::ROOT::TGenericClassInfo 
         instance("ana::ValidationEL", ::ana::ValidationEL::Class_Version(), "QuickAna/ValidationEL.h", 27,
                  typeid(::ana::ValidationEL), DefineBehavior(ptr, ptr),
                  &::ana::ValidationEL::Dictionary, isa_proxy, 4,
                  sizeof(::ana::ValidationEL) );
      instance.SetNew(&new_anacLcLValidationEL);
      instance.SetNewArray(&newArray_anacLcLValidationEL);
      instance.SetDelete(&delete_anacLcLValidationEL);
      instance.SetDeleteArray(&deleteArray_anacLcLValidationEL);
      instance.SetDestructor(&destruct_anacLcLValidationEL);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ana::ValidationEL*)
   {
      return GenerateInitInstanceLocal((::ana::ValidationEL*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::ana::ValidationEL*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ana {
//______________________________________________________________________________
atomic_TClass_ptr ELExample::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *ELExample::Class_Name()
{
   return "ana::ELExample";
}

//______________________________________________________________________________
const char *ELExample::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::ana::ELExample*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int ELExample::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::ana::ELExample*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ELExample::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::ana::ELExample*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ELExample::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::ana::ELExample*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace ana
namespace ana {
//______________________________________________________________________________
atomic_TClass_ptr ValidationEL::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *ValidationEL::Class_Name()
{
   return "ana::ValidationEL";
}

//______________________________________________________________________________
const char *ValidationEL::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::ana::ValidationEL*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int ValidationEL::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::ana::ValidationEL*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ValidationEL::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::ana::ValidationEL*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ValidationEL::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::ana::ValidationEL*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace ana
namespace ROOT {
   // Wrappers around operator new
   static void *new_anacLcLConfiguration(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::ana::Configuration : new ::ana::Configuration;
   }
   static void *newArray_anacLcLConfiguration(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::ana::Configuration[nElements] : new ::ana::Configuration[nElements];
   }
   // Wrapper around operator delete
   static void delete_anacLcLConfiguration(void *p) {
      delete ((::ana::Configuration*)p);
   }
   static void deleteArray_anacLcLConfiguration(void *p) {
      delete [] ((::ana::Configuration*)p);
   }
   static void destruct_anacLcLConfiguration(void *p) {
      typedef ::ana::Configuration current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ana::Configuration

namespace ana {
//______________________________________________________________________________
void ELExample::Streamer(TBuffer &R__b)
{
   // Stream an object of class ana::ELExample.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(ana::ELExample::Class(),this);
   } else {
      R__b.WriteClassBuffer(ana::ELExample::Class(),this);
   }
}

} // namespace ana
namespace ROOT {
   // Wrappers around operator new
   static void *new_anacLcLELExample(void *p) {
      return  p ? new(p) ::ana::ELExample : new ::ana::ELExample;
   }
   static void *newArray_anacLcLELExample(Long_t nElements, void *p) {
      return p ? new(p) ::ana::ELExample[nElements] : new ::ana::ELExample[nElements];
   }
   // Wrapper around operator delete
   static void delete_anacLcLELExample(void *p) {
      delete ((::ana::ELExample*)p);
   }
   static void deleteArray_anacLcLELExample(void *p) {
      delete [] ((::ana::ELExample*)p);
   }
   static void destruct_anacLcLELExample(void *p) {
      typedef ::ana::ELExample current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ana::ELExample

namespace ROOT {
   // Wrapper around operator delete
   static void delete_anacLcLQuickAna(void *p) {
      delete ((::ana::QuickAna*)p);
   }
   static void deleteArray_anacLcLQuickAna(void *p) {
      delete [] ((::ana::QuickAna*)p);
   }
   static void destruct_anacLcLQuickAna(void *p) {
      typedef ::ana::QuickAna current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ana::QuickAna

namespace ana {
//______________________________________________________________________________
void ValidationEL::Streamer(TBuffer &R__b)
{
   // Stream an object of class ana::ValidationEL.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(ana::ValidationEL::Class(),this);
   } else {
      R__b.WriteClassBuffer(ana::ValidationEL::Class(),this);
   }
}

} // namespace ana
namespace ROOT {
   // Wrappers around operator new
   static void *new_anacLcLValidationEL(void *p) {
      return  p ? new(p) ::ana::ValidationEL : new ::ana::ValidationEL;
   }
   static void *newArray_anacLcLValidationEL(Long_t nElements, void *p) {
      return p ? new(p) ::ana::ValidationEL[nElements] : new ::ana::ValidationEL[nElements];
   }
   // Wrapper around operator delete
   static void delete_anacLcLValidationEL(void *p) {
      delete ((::ana::ValidationEL*)p);
   }
   static void deleteArray_anacLcLValidationEL(void *p) {
      delete [] ((::ana::ValidationEL*)p);
   }
   static void destruct_anacLcLValidationEL(void *p) {
      typedef ::ana::ValidationEL current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ana::ValidationEL

namespace ROOT {
   static TClass *vectorlEstringgR_Dictionary();
   static void vectorlEstringgR_TClassManip(TClass*);
   static void *new_vectorlEstringgR(void *p = 0);
   static void *newArray_vectorlEstringgR(Long_t size, void *p);
   static void delete_vectorlEstringgR(void *p);
   static void deleteArray_vectorlEstringgR(void *p);
   static void destruct_vectorlEstringgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<string>*)
   {
      vector<string> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<string>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<string>", -2, "vector", 214,
                  typeid(vector<string>), DefineBehavior(ptr, ptr),
                  &vectorlEstringgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<string>) );
      instance.SetNew(&new_vectorlEstringgR);
      instance.SetNewArray(&newArray_vectorlEstringgR);
      instance.SetDelete(&delete_vectorlEstringgR);
      instance.SetDeleteArray(&deleteArray_vectorlEstringgR);
      instance.SetDestructor(&destruct_vectorlEstringgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<string> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<string>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEstringgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<string>*)0x0)->GetClass();
      vectorlEstringgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEstringgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEstringgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<string> : new vector<string>;
   }
   static void *newArray_vectorlEstringgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<string>[nElements] : new vector<string>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEstringgR(void *p) {
      delete ((vector<string>*)p);
   }
   static void deleteArray_vectorlEstringgR(void *p) {
      delete [] ((vector<string>*)p);
   }
   static void destruct_vectorlEstringgR(void *p) {
      typedef vector<string> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<string>

namespace {
  void TriggerDictionaryInitialization_QuickAnaCINT_Impl() {
    static const char* headers[] = {
"QuickAna/Global.h",
"QuickAna/Configuration.h",
"QuickAna/ELExample.h",
"QuickAna/QuickAna.h",
"QuickAna/ValidationEL.h",
"QuickAna/xAODTruth.h",
0
    };
    static const char* includePaths[] = {
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/QuickAna/Root",
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/QuickAna",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/QuickAna/cmt/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace ana{struct __attribute__((annotate("$clingAutoload$/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/QuickAna/Root/LinkDef.h")))  Configuration;}
namespace ana{class __attribute__((annotate("$clingAutoload$/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/QuickAna/Root/LinkDef.h")))  ELExample;}
namespace ana{class __attribute__((annotate("$clingAutoload$/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/QuickAna/Root/LinkDef.h")))  QuickAna;}
namespace ana{class __attribute__((annotate("$clingAutoload$/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/QuickAna/Root/LinkDef.h")))  ValidationEL;}
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
  #define ROOTCORE_PACKAGE "QuickAna"
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "QuickAna/Global.h"
#include "QuickAna/Configuration.h"
#include "QuickAna/ELExample.h"
#include "QuickAna/QuickAna.h"
#include "QuickAna/ValidationEL.h"
#include "QuickAna/xAODTruth.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"ana::Configuration", payloadCode, "@",
"ana::ELExample", payloadCode, "@",
"ana::QuickAna", payloadCode, "@",
"ana::ValidationEL", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("QuickAnaCINT",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_QuickAnaCINT_Impl, {{"namespace DataVector_detail { template <typename B1, typename B2, typename B3> class VirtBases; }", 1},{"template <typename T> class DataVectorBase;", 1},{"template <typename T, typename BASE> class DataVector;", 1},{"namespace DataVector_detail { template <typename T> class DVLEltBaseInit; }", 1}}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_QuickAnaCINT_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_QuickAnaCINT() {
  TriggerDictionaryInitialization_QuickAnaCINT_Impl();
}
