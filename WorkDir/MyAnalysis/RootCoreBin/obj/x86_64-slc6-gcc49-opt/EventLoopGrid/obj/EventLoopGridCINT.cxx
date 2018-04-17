#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#ifdef __llvm__
#pragma GCC diagnostic ignored "-Wunused-private-field"
#endif
// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIuserdIhteagledIAnalysisDirectorydIBase_2_4_34dIRootCoreBindIobjdIx86_64mIslc6mIgcc49mIoptdIEventLoopGriddIobjdIEventLoopGridCINT

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
#include "EventLoopGrid/GridWorker.h"
#include "EventLoopGrid/PandaRootTools.h"
#include "EventLoopGrid/GridDriver.h"
#include "EventLoopGrid/PrunDriver.h"
#include "EventLoopGrid/GridJobLoader.h"

// Header files passed via #pragma extra_include

namespace EL {
   namespace ROOT {
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance();
      static TClass *EL_Dictionary();

      // Function generating the singleton type initializer
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance()
      {
         static ::ROOT::TGenericClassInfo 
            instance("EL", 0 /*version*/, "EventLoop/Global.h", 17,
                     ::ROOT::DefineBehavior((void*)0,(void*)0),
                     &EL_Dictionary, 0);
         return &instance;
      }
      // Insure that the inline function is _not_ optimized away by the compiler
      ::ROOT::TGenericClassInfo *(*_R__UNIQUE_(InitFunctionKeeper))() = &GenerateInitInstance;  
      // Static variable to force the class initialization
      static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstance(); R__UseDummy(_R__UNIQUE_(Init));

      // Dictionary for non-ClassDef classes
      static TClass *EL_Dictionary() {
         return GenerateInitInstance()->GetClass();
      }

   }
}

namespace ROOT {
   static void delete_ELcLcLGridWorker(void *p);
   static void deleteArray_ELcLcLGridWorker(void *p);
   static void destruct_ELcLcLGridWorker(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::GridWorker*)
   {
      ::EL::GridWorker *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EL::GridWorker >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EL::GridWorker", ::EL::GridWorker::Class_Version(), "EventLoopGrid/GridWorker.h", 15,
                  typeid(::EL::GridWorker), DefineBehavior(ptr, ptr),
                  &::EL::GridWorker::Dictionary, isa_proxy, 4,
                  sizeof(::EL::GridWorker) );
      instance.SetDelete(&delete_ELcLcLGridWorker);
      instance.SetDeleteArray(&deleteArray_ELcLcLGridWorker);
      instance.SetDestructor(&destruct_ELcLcLGridWorker);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::GridWorker*)
   {
      return GenerateInitInstanceLocal((::EL::GridWorker*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::GridWorker*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_ELcLcLGridDriver(void *p = 0);
   static void *newArray_ELcLcLGridDriver(Long_t size, void *p);
   static void delete_ELcLcLGridDriver(void *p);
   static void deleteArray_ELcLcLGridDriver(void *p);
   static void destruct_ELcLcLGridDriver(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::GridDriver*)
   {
      ::EL::GridDriver *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EL::GridDriver >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EL::GridDriver", ::EL::GridDriver::Class_Version(), "EventLoopGrid/GridDriver.h", 16,
                  typeid(::EL::GridDriver), DefineBehavior(ptr, ptr),
                  &::EL::GridDriver::Dictionary, isa_proxy, 4,
                  sizeof(::EL::GridDriver) );
      instance.SetNew(&new_ELcLcLGridDriver);
      instance.SetNewArray(&newArray_ELcLcLGridDriver);
      instance.SetDelete(&delete_ELcLcLGridDriver);
      instance.SetDeleteArray(&deleteArray_ELcLcLGridDriver);
      instance.SetDestructor(&destruct_ELcLcLGridDriver);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::GridDriver*)
   {
      return GenerateInitInstanceLocal((::EL::GridDriver*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::GridDriver*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_ELcLcLPrunDriver(void *p = 0);
   static void *newArray_ELcLcLPrunDriver(Long_t size, void *p);
   static void delete_ELcLcLPrunDriver(void *p);
   static void deleteArray_ELcLcLPrunDriver(void *p);
   static void destruct_ELcLcLPrunDriver(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::PrunDriver*)
   {
      ::EL::PrunDriver *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EL::PrunDriver >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EL::PrunDriver", ::EL::PrunDriver::Class_Version(), "EventLoopGrid/PrunDriver.h", 13,
                  typeid(::EL::PrunDriver), DefineBehavior(ptr, ptr),
                  &::EL::PrunDriver::Dictionary, isa_proxy, 4,
                  sizeof(::EL::PrunDriver) );
      instance.SetNew(&new_ELcLcLPrunDriver);
      instance.SetNewArray(&newArray_ELcLcLPrunDriver);
      instance.SetDelete(&delete_ELcLcLPrunDriver);
      instance.SetDeleteArray(&deleteArray_ELcLcLPrunDriver);
      instance.SetDestructor(&destruct_ELcLcLPrunDriver);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::PrunDriver*)
   {
      return GenerateInitInstanceLocal((::EL::PrunDriver*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::PrunDriver*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_ELcLcLGridJobLoader(void *p = 0);
   static void *newArray_ELcLcLGridJobLoader(Long_t size, void *p);
   static void delete_ELcLcLGridJobLoader(void *p);
   static void deleteArray_ELcLcLGridJobLoader(void *p);
   static void destruct_ELcLcLGridJobLoader(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::GridJobLoader*)
   {
      ::EL::GridJobLoader *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EL::GridJobLoader >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EL::GridJobLoader", ::EL::GridJobLoader::Class_Version(), "EventLoopGrid/GridJobLoader.h", 8,
                  typeid(::EL::GridJobLoader), DefineBehavior(ptr, ptr),
                  &::EL::GridJobLoader::Dictionary, isa_proxy, 4,
                  sizeof(::EL::GridJobLoader) );
      instance.SetNew(&new_ELcLcLGridJobLoader);
      instance.SetNewArray(&newArray_ELcLcLGridJobLoader);
      instance.SetDelete(&delete_ELcLcLGridJobLoader);
      instance.SetDeleteArray(&deleteArray_ELcLcLGridJobLoader);
      instance.SetDestructor(&destruct_ELcLcLGridJobLoader);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::GridJobLoader*)
   {
      return GenerateInitInstanceLocal((::EL::GridJobLoader*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::GridJobLoader*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_PandaRootTools(void *p = 0);
   static void *newArray_PandaRootTools(Long_t size, void *p);
   static void delete_PandaRootTools(void *p);
   static void deleteArray_PandaRootTools(void *p);
   static void destruct_PandaRootTools(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::PandaRootTools*)
   {
      ::PandaRootTools *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::PandaRootTools >(0);
      static ::ROOT::TGenericClassInfo 
         instance("PandaRootTools", ::PandaRootTools::Class_Version(), "EventLoopGrid/PandaRootTools.h", 15,
                  typeid(::PandaRootTools), DefineBehavior(ptr, ptr),
                  &::PandaRootTools::Dictionary, isa_proxy, 4,
                  sizeof(::PandaRootTools) );
      instance.SetNew(&new_PandaRootTools);
      instance.SetNewArray(&newArray_PandaRootTools);
      instance.SetDelete(&delete_PandaRootTools);
      instance.SetDeleteArray(&deleteArray_PandaRootTools);
      instance.SetDestructor(&destruct_PandaRootTools);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::PandaRootTools*)
   {
      return GenerateInitInstanceLocal((::PandaRootTools*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::PandaRootTools*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace EL {
//______________________________________________________________________________
atomic_TClass_ptr GridWorker::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *GridWorker::Class_Name()
{
   return "EL::GridWorker";
}

//______________________________________________________________________________
const char *GridWorker::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::GridWorker*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int GridWorker::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::GridWorker*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *GridWorker::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::GridWorker*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *GridWorker::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::GridWorker*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace EL
namespace EL {
//______________________________________________________________________________
atomic_TClass_ptr GridDriver::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *GridDriver::Class_Name()
{
   return "EL::GridDriver";
}

//______________________________________________________________________________
const char *GridDriver::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::GridDriver*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int GridDriver::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::GridDriver*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *GridDriver::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::GridDriver*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *GridDriver::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::GridDriver*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace EL
namespace EL {
//______________________________________________________________________________
atomic_TClass_ptr PrunDriver::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *PrunDriver::Class_Name()
{
   return "EL::PrunDriver";
}

//______________________________________________________________________________
const char *PrunDriver::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::PrunDriver*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int PrunDriver::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::PrunDriver*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *PrunDriver::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::PrunDriver*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *PrunDriver::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::PrunDriver*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace EL
namespace EL {
//______________________________________________________________________________
atomic_TClass_ptr GridJobLoader::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *GridJobLoader::Class_Name()
{
   return "EL::GridJobLoader";
}

//______________________________________________________________________________
const char *GridJobLoader::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::GridJobLoader*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int GridJobLoader::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::GridJobLoader*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *GridJobLoader::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::GridJobLoader*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *GridJobLoader::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::GridJobLoader*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace EL
//______________________________________________________________________________
atomic_TClass_ptr PandaRootTools::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *PandaRootTools::Class_Name()
{
   return "PandaRootTools";
}

//______________________________________________________________________________
const char *PandaRootTools::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::PandaRootTools*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int PandaRootTools::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::PandaRootTools*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *PandaRootTools::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::PandaRootTools*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *PandaRootTools::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::PandaRootTools*)0x0)->GetClass(); }
   return fgIsA;
}

namespace EL {
//______________________________________________________________________________
void GridWorker::Streamer(TBuffer &R__b)
{
   // Stream an object of class EL::GridWorker.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EL::GridWorker::Class(),this);
   } else {
      R__b.WriteClassBuffer(EL::GridWorker::Class(),this);
   }
}

} // namespace EL
namespace ROOT {
   // Wrapper around operator delete
   static void delete_ELcLcLGridWorker(void *p) {
      delete ((::EL::GridWorker*)p);
   }
   static void deleteArray_ELcLcLGridWorker(void *p) {
      delete [] ((::EL::GridWorker*)p);
   }
   static void destruct_ELcLcLGridWorker(void *p) {
      typedef ::EL::GridWorker current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::GridWorker

namespace EL {
//______________________________________________________________________________
void GridDriver::Streamer(TBuffer &R__b)
{
   // Stream an object of class EL::GridDriver.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EL::GridDriver::Class(),this);
   } else {
      R__b.WriteClassBuffer(EL::GridDriver::Class(),this);
   }
}

} // namespace EL
namespace ROOT {
   // Wrappers around operator new
   static void *new_ELcLcLGridDriver(void *p) {
      return  p ? new(p) ::EL::GridDriver : new ::EL::GridDriver;
   }
   static void *newArray_ELcLcLGridDriver(Long_t nElements, void *p) {
      return p ? new(p) ::EL::GridDriver[nElements] : new ::EL::GridDriver[nElements];
   }
   // Wrapper around operator delete
   static void delete_ELcLcLGridDriver(void *p) {
      delete ((::EL::GridDriver*)p);
   }
   static void deleteArray_ELcLcLGridDriver(void *p) {
      delete [] ((::EL::GridDriver*)p);
   }
   static void destruct_ELcLcLGridDriver(void *p) {
      typedef ::EL::GridDriver current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::GridDriver

namespace EL {
//______________________________________________________________________________
void PrunDriver::Streamer(TBuffer &R__b)
{
   // Stream an object of class EL::PrunDriver.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EL::PrunDriver::Class(),this);
   } else {
      R__b.WriteClassBuffer(EL::PrunDriver::Class(),this);
   }
}

} // namespace EL
namespace ROOT {
   // Wrappers around operator new
   static void *new_ELcLcLPrunDriver(void *p) {
      return  p ? new(p) ::EL::PrunDriver : new ::EL::PrunDriver;
   }
   static void *newArray_ELcLcLPrunDriver(Long_t nElements, void *p) {
      return p ? new(p) ::EL::PrunDriver[nElements] : new ::EL::PrunDriver[nElements];
   }
   // Wrapper around operator delete
   static void delete_ELcLcLPrunDriver(void *p) {
      delete ((::EL::PrunDriver*)p);
   }
   static void deleteArray_ELcLcLPrunDriver(void *p) {
      delete [] ((::EL::PrunDriver*)p);
   }
   static void destruct_ELcLcLPrunDriver(void *p) {
      typedef ::EL::PrunDriver current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::PrunDriver

namespace EL {
//______________________________________________________________________________
void GridJobLoader::Streamer(TBuffer &R__b)
{
   // Stream an object of class EL::GridJobLoader.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EL::GridJobLoader::Class(),this);
   } else {
      R__b.WriteClassBuffer(EL::GridJobLoader::Class(),this);
   }
}

} // namespace EL
namespace ROOT {
   // Wrappers around operator new
   static void *new_ELcLcLGridJobLoader(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::EL::GridJobLoader : new ::EL::GridJobLoader;
   }
   static void *newArray_ELcLcLGridJobLoader(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::EL::GridJobLoader[nElements] : new ::EL::GridJobLoader[nElements];
   }
   // Wrapper around operator delete
   static void delete_ELcLcLGridJobLoader(void *p) {
      delete ((::EL::GridJobLoader*)p);
   }
   static void deleteArray_ELcLcLGridJobLoader(void *p) {
      delete [] ((::EL::GridJobLoader*)p);
   }
   static void destruct_ELcLcLGridJobLoader(void *p) {
      typedef ::EL::GridJobLoader current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::GridJobLoader

//______________________________________________________________________________
void PandaRootTools::Streamer(TBuffer &R__b)
{
   // Stream an object of class PandaRootTools.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(PandaRootTools::Class(),this);
   } else {
      R__b.WriteClassBuffer(PandaRootTools::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_PandaRootTools(void *p) {
      return  p ? new(p) ::PandaRootTools : new ::PandaRootTools;
   }
   static void *newArray_PandaRootTools(Long_t nElements, void *p) {
      return p ? new(p) ::PandaRootTools[nElements] : new ::PandaRootTools[nElements];
   }
   // Wrapper around operator delete
   static void delete_PandaRootTools(void *p) {
      delete ((::PandaRootTools*)p);
   }
   static void deleteArray_PandaRootTools(void *p) {
      delete [] ((::PandaRootTools*)p);
   }
   static void destruct_PandaRootTools(void *p) {
      typedef ::PandaRootTools current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::PandaRootTools

namespace ROOT {
   static TClass *vectorlETStringgR_Dictionary();
   static void vectorlETStringgR_TClassManip(TClass*);
   static void *new_vectorlETStringgR(void *p = 0);
   static void *newArray_vectorlETStringgR(Long_t size, void *p);
   static void delete_vectorlETStringgR(void *p);
   static void deleteArray_vectorlETStringgR(void *p);
   static void destruct_vectorlETStringgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TString>*)
   {
      vector<TString> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TString>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TString>", -2, "vector", 214,
                  typeid(vector<TString>), DefineBehavior(ptr, ptr),
                  &vectorlETStringgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<TString>) );
      instance.SetNew(&new_vectorlETStringgR);
      instance.SetNewArray(&newArray_vectorlETStringgR);
      instance.SetDelete(&delete_vectorlETStringgR);
      instance.SetDeleteArray(&deleteArray_vectorlETStringgR);
      instance.SetDestructor(&destruct_vectorlETStringgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TString> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<TString>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETStringgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<TString>*)0x0)->GetClass();
      vectorlETStringgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETStringgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETStringgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<TString> : new vector<TString>;
   }
   static void *newArray_vectorlETStringgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<TString>[nElements] : new vector<TString>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETStringgR(void *p) {
      delete ((vector<TString>*)p);
   }
   static void deleteArray_vectorlETStringgR(void *p) {
      delete [] ((vector<TString>*)p);
   }
   static void destruct_vectorlETStringgR(void *p) {
      typedef vector<TString> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<TString>

namespace {
  void TriggerDictionaryInitialization_EventLoopGridCINT_Impl() {
    static const char* headers[] = {
"EventLoopGrid/GridWorker.h",
"EventLoopGrid/PandaRootTools.h",
"EventLoopGrid/GridDriver.h",
"EventLoopGrid/PrunDriver.h",
"EventLoopGrid/GridJobLoader.h",
0
    };
    static const char* includePaths[] = {
"/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoopGrid/Root",
"/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoopGrid",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoopGrid/cmt/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace EL{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoopGrid/Root/LinkDef.h")))  GridWorker;}
namespace EL{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoopGrid/Root/LinkDef.h")))  GridDriver;}
namespace EL{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoopGrid/Root/LinkDef.h")))  PrunDriver;}
namespace EL{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoopGrid/Root/LinkDef.h")))  GridJobLoader;}
class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoopGrid/Root/LinkDef.h")))  PandaRootTools;
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
  #define ROOTCORE_PACKAGE "EventLoopGrid"
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "EventLoopGrid/GridWorker.h"
#include "EventLoopGrid/PandaRootTools.h"
#include "EventLoopGrid/GridDriver.h"
#include "EventLoopGrid/PrunDriver.h"
#include "EventLoopGrid/GridJobLoader.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"EL::GridDriver", payloadCode, "@",
"EL::GridJobLoader", payloadCode, "@",
"EL::GridWorker", payloadCode, "@",
"EL::PrunDriver", payloadCode, "@",
"EL::getRootCoreConfig", payloadCode, "@",
"PandaRootTools", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("EventLoopGridCINT",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_EventLoopGridCINT_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_EventLoopGridCINT_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_EventLoopGridCINT() {
  TriggerDictionaryInitialization_EventLoopGridCINT_Impl();
}
