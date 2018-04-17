#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#ifdef __llvm__
#pragma GCC diagnostic ignored "-Wunused-private-field"
#endif
// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIuserdIhteagledIAnalysisDirectorydIBase_2_4_34dIRootCoreBindIobjdIx86_64mIslc6mIgcc49mIoptdIEventLoopAlgsdIobjdIEventLoopAlgsCINT

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
#include "EventLoopAlgs/AlgSelect.h"
#include "EventLoopAlgs/DuplicateChecker.h"
#include "EventLoopAlgs/NTupleSvc.h"
#include "EventLoopAlgs/UnitTestSkim.h"
#include "EventLoopAlgs/WhiteBoardSvc.h"
#include "SampleHandler/MetaData.h"
#include "SampleHandler/MetaVector.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *SHcLcLMetaDatalEfloatgR_Dictionary();
   static void SHcLcLMetaDatalEfloatgR_TClassManip(TClass*);
   static void *new_SHcLcLMetaDatalEfloatgR(void *p = 0);
   static void *newArray_SHcLcLMetaDatalEfloatgR(Long_t size, void *p);
   static void delete_SHcLcLMetaDatalEfloatgR(void *p);
   static void deleteArray_SHcLcLMetaDatalEfloatgR(void *p);
   static void destruct_SHcLcLMetaDatalEfloatgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SH::MetaData<float>*)
   {
      ::SH::MetaData<float> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::SH::MetaData<float> >(0);
      static ::ROOT::TGenericClassInfo 
         instance("SH::MetaData<float>", ::SH::MetaData<float>::Class_Version(), "SampleHandler/MetaData.h", 22,
                  typeid(::SH::MetaData<float>), DefineBehavior(ptr, ptr),
                  &SHcLcLMetaDatalEfloatgR_Dictionary, isa_proxy, 4,
                  sizeof(::SH::MetaData<float>) );
      instance.SetNew(&new_SHcLcLMetaDatalEfloatgR);
      instance.SetNewArray(&newArray_SHcLcLMetaDatalEfloatgR);
      instance.SetDelete(&delete_SHcLcLMetaDatalEfloatgR);
      instance.SetDeleteArray(&deleteArray_SHcLcLMetaDatalEfloatgR);
      instance.SetDestructor(&destruct_SHcLcLMetaDatalEfloatgR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SH::MetaData<float>*)
   {
      return GenerateInitInstanceLocal((::SH::MetaData<float>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SH::MetaData<float>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SHcLcLMetaDatalEfloatgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SH::MetaData<float>*)0x0)->GetClass();
      SHcLcLMetaDatalEfloatgR_TClassManip(theClass);
   return theClass;
   }

   static void SHcLcLMetaDatalEfloatgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SHcLcLMetaVectorlEfloatgR_Dictionary();
   static void SHcLcLMetaVectorlEfloatgR_TClassManip(TClass*);
   static void *new_SHcLcLMetaVectorlEfloatgR(void *p = 0);
   static void *newArray_SHcLcLMetaVectorlEfloatgR(Long_t size, void *p);
   static void delete_SHcLcLMetaVectorlEfloatgR(void *p);
   static void deleteArray_SHcLcLMetaVectorlEfloatgR(void *p);
   static void destruct_SHcLcLMetaVectorlEfloatgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SH::MetaVector<float>*)
   {
      ::SH::MetaVector<float> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::SH::MetaVector<float> >(0);
      static ::ROOT::TGenericClassInfo 
         instance("SH::MetaVector<float>", ::SH::MetaVector<float>::Class_Version(), "SampleHandler/MetaVector.h", 23,
                  typeid(::SH::MetaVector<float>), DefineBehavior(ptr, ptr),
                  &SHcLcLMetaVectorlEfloatgR_Dictionary, isa_proxy, 4,
                  sizeof(::SH::MetaVector<float>) );
      instance.SetNew(&new_SHcLcLMetaVectorlEfloatgR);
      instance.SetNewArray(&newArray_SHcLcLMetaVectorlEfloatgR);
      instance.SetDelete(&delete_SHcLcLMetaVectorlEfloatgR);
      instance.SetDeleteArray(&deleteArray_SHcLcLMetaVectorlEfloatgR);
      instance.SetDestructor(&destruct_SHcLcLMetaVectorlEfloatgR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SH::MetaVector<float>*)
   {
      return GenerateInitInstanceLocal((::SH::MetaVector<float>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SH::MetaVector<float>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SHcLcLMetaVectorlEfloatgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SH::MetaVector<float>*)0x0)->GetClass();
      SHcLcLMetaVectorlEfloatgR_TClassManip(theClass);
   return theClass;
   }

   static void SHcLcLMetaVectorlEfloatgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static void *new_ELcLcLAlgSelect(void *p = 0);
   static void *newArray_ELcLcLAlgSelect(Long_t size, void *p);
   static void delete_ELcLcLAlgSelect(void *p);
   static void deleteArray_ELcLcLAlgSelect(void *p);
   static void destruct_ELcLcLAlgSelect(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::AlgSelect*)
   {
      ::EL::AlgSelect *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EL::AlgSelect >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EL::AlgSelect", ::EL::AlgSelect::Class_Version(), "EventLoopAlgs/AlgSelect.h", 29,
                  typeid(::EL::AlgSelect), DefineBehavior(ptr, ptr),
                  &::EL::AlgSelect::Dictionary, isa_proxy, 4,
                  sizeof(::EL::AlgSelect) );
      instance.SetNew(&new_ELcLcLAlgSelect);
      instance.SetNewArray(&newArray_ELcLcLAlgSelect);
      instance.SetDelete(&delete_ELcLcLAlgSelect);
      instance.SetDeleteArray(&deleteArray_ELcLcLAlgSelect);
      instance.SetDestructor(&destruct_ELcLcLAlgSelect);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::AlgSelect*)
   {
      return GenerateInitInstanceLocal((::EL::AlgSelect*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::AlgSelect*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_ELcLcLDuplicateChecker(void *p = 0);
   static void *newArray_ELcLcLDuplicateChecker(Long_t size, void *p);
   static void delete_ELcLcLDuplicateChecker(void *p);
   static void deleteArray_ELcLcLDuplicateChecker(void *p);
   static void destruct_ELcLcLDuplicateChecker(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::DuplicateChecker*)
   {
      ::EL::DuplicateChecker *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EL::DuplicateChecker >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EL::DuplicateChecker", ::EL::DuplicateChecker::Class_Version(), "EventLoopAlgs/DuplicateChecker.h", 33,
                  typeid(::EL::DuplicateChecker), DefineBehavior(ptr, ptr),
                  &::EL::DuplicateChecker::Dictionary, isa_proxy, 4,
                  sizeof(::EL::DuplicateChecker) );
      instance.SetNew(&new_ELcLcLDuplicateChecker);
      instance.SetNewArray(&newArray_ELcLcLDuplicateChecker);
      instance.SetDelete(&delete_ELcLcLDuplicateChecker);
      instance.SetDeleteArray(&deleteArray_ELcLcLDuplicateChecker);
      instance.SetDestructor(&destruct_ELcLcLDuplicateChecker);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::DuplicateChecker*)
   {
      return GenerateInitInstanceLocal((::EL::DuplicateChecker*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::DuplicateChecker*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_ELcLcLNTupleSvc(void *p = 0);
   static void *newArray_ELcLcLNTupleSvc(Long_t size, void *p);
   static void delete_ELcLcLNTupleSvc(void *p);
   static void deleteArray_ELcLcLNTupleSvc(void *p);
   static void destruct_ELcLcLNTupleSvc(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::NTupleSvc*)
   {
      ::EL::NTupleSvc *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EL::NTupleSvc >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EL::NTupleSvc", ::EL::NTupleSvc::Class_Version(), "EventLoopAlgs/NTupleSvc.h", 49,
                  typeid(::EL::NTupleSvc), DefineBehavior(ptr, ptr),
                  &::EL::NTupleSvc::Dictionary, isa_proxy, 4,
                  sizeof(::EL::NTupleSvc) );
      instance.SetNew(&new_ELcLcLNTupleSvc);
      instance.SetNewArray(&newArray_ELcLcLNTupleSvc);
      instance.SetDelete(&delete_ELcLcLNTupleSvc);
      instance.SetDeleteArray(&deleteArray_ELcLcLNTupleSvc);
      instance.SetDestructor(&destruct_ELcLcLNTupleSvc);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::NTupleSvc*)
   {
      return GenerateInitInstanceLocal((::EL::NTupleSvc*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::NTupleSvc*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_ELcLcLUnitTestSkim(void *p = 0);
   static void *newArray_ELcLcLUnitTestSkim(Long_t size, void *p);
   static void delete_ELcLcLUnitTestSkim(void *p);
   static void deleteArray_ELcLcLUnitTestSkim(void *p);
   static void destruct_ELcLcLUnitTestSkim(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::UnitTestSkim*)
   {
      ::EL::UnitTestSkim *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EL::UnitTestSkim >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EL::UnitTestSkim", ::EL::UnitTestSkim::Class_Version(), "EventLoopAlgs/UnitTestSkim.h", 26,
                  typeid(::EL::UnitTestSkim), DefineBehavior(ptr, ptr),
                  &::EL::UnitTestSkim::Dictionary, isa_proxy, 4,
                  sizeof(::EL::UnitTestSkim) );
      instance.SetNew(&new_ELcLcLUnitTestSkim);
      instance.SetNewArray(&newArray_ELcLcLUnitTestSkim);
      instance.SetDelete(&delete_ELcLcLUnitTestSkim);
      instance.SetDeleteArray(&deleteArray_ELcLcLUnitTestSkim);
      instance.SetDestructor(&destruct_ELcLcLUnitTestSkim);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::UnitTestSkim*)
   {
      return GenerateInitInstanceLocal((::EL::UnitTestSkim*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::UnitTestSkim*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_ELcLcLWhiteBoardSvc(void *p = 0);
   static void *newArray_ELcLcLWhiteBoardSvc(Long_t size, void *p);
   static void delete_ELcLcLWhiteBoardSvc(void *p);
   static void deleteArray_ELcLcLWhiteBoardSvc(void *p);
   static void destruct_ELcLcLWhiteBoardSvc(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::WhiteBoardSvc*)
   {
      ::EL::WhiteBoardSvc *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EL::WhiteBoardSvc >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EL::WhiteBoardSvc", ::EL::WhiteBoardSvc::Class_Version(), "EventLoopAlgs/WhiteBoardSvc.h", 36,
                  typeid(::EL::WhiteBoardSvc), DefineBehavior(ptr, ptr),
                  &::EL::WhiteBoardSvc::Dictionary, isa_proxy, 4,
                  sizeof(::EL::WhiteBoardSvc) );
      instance.SetNew(&new_ELcLcLWhiteBoardSvc);
      instance.SetNewArray(&newArray_ELcLcLWhiteBoardSvc);
      instance.SetDelete(&delete_ELcLcLWhiteBoardSvc);
      instance.SetDeleteArray(&deleteArray_ELcLcLWhiteBoardSvc);
      instance.SetDestructor(&destruct_ELcLcLWhiteBoardSvc);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::WhiteBoardSvc*)
   {
      return GenerateInitInstanceLocal((::EL::WhiteBoardSvc*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::WhiteBoardSvc*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace SH {
//______________________________________________________________________________
template <> atomic_TClass_ptr MetaData<float>::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
template <> const char *MetaData<float>::Class_Name()
{
   return "SH::MetaData<float>";
}

//______________________________________________________________________________
template <> const char *MetaData<float>::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::SH::MetaData<float>*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
template <> int MetaData<float>::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::SH::MetaData<float>*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
template <> TClass *MetaData<float>::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::SH::MetaData<float>*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
template <> TClass *MetaData<float>::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::SH::MetaData<float>*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace SH
namespace SH {
//______________________________________________________________________________
template <> atomic_TClass_ptr MetaVector<float>::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
template <> const char *MetaVector<float>::Class_Name()
{
   return "SH::MetaVector<float>";
}

//______________________________________________________________________________
template <> const char *MetaVector<float>::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::SH::MetaVector<float>*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
template <> int MetaVector<float>::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::SH::MetaVector<float>*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
template <> TClass *MetaVector<float>::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::SH::MetaVector<float>*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
template <> TClass *MetaVector<float>::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::SH::MetaVector<float>*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace SH
namespace EL {
//______________________________________________________________________________
atomic_TClass_ptr AlgSelect::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *AlgSelect::Class_Name()
{
   return "EL::AlgSelect";
}

//______________________________________________________________________________
const char *AlgSelect::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::AlgSelect*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int AlgSelect::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::AlgSelect*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *AlgSelect::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::AlgSelect*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *AlgSelect::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::AlgSelect*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace EL
namespace EL {
//______________________________________________________________________________
atomic_TClass_ptr DuplicateChecker::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *DuplicateChecker::Class_Name()
{
   return "EL::DuplicateChecker";
}

//______________________________________________________________________________
const char *DuplicateChecker::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::DuplicateChecker*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int DuplicateChecker::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::DuplicateChecker*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *DuplicateChecker::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::DuplicateChecker*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *DuplicateChecker::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::DuplicateChecker*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace EL
namespace EL {
//______________________________________________________________________________
atomic_TClass_ptr NTupleSvc::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *NTupleSvc::Class_Name()
{
   return "EL::NTupleSvc";
}

//______________________________________________________________________________
const char *NTupleSvc::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::NTupleSvc*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int NTupleSvc::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::NTupleSvc*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *NTupleSvc::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::NTupleSvc*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *NTupleSvc::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::NTupleSvc*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace EL
namespace EL {
//______________________________________________________________________________
atomic_TClass_ptr UnitTestSkim::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *UnitTestSkim::Class_Name()
{
   return "EL::UnitTestSkim";
}

//______________________________________________________________________________
const char *UnitTestSkim::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::UnitTestSkim*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int UnitTestSkim::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::UnitTestSkim*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *UnitTestSkim::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::UnitTestSkim*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *UnitTestSkim::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::UnitTestSkim*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace EL
namespace EL {
//______________________________________________________________________________
atomic_TClass_ptr WhiteBoardSvc::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *WhiteBoardSvc::Class_Name()
{
   return "EL::WhiteBoardSvc";
}

//______________________________________________________________________________
const char *WhiteBoardSvc::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::WhiteBoardSvc*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int WhiteBoardSvc::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::WhiteBoardSvc*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *WhiteBoardSvc::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::WhiteBoardSvc*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *WhiteBoardSvc::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::WhiteBoardSvc*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace EL
namespace SH {
//______________________________________________________________________________
template <> void MetaData<float>::Streamer(TBuffer &R__b)
{
   // Stream an object of class SH::MetaData<float>.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(SH::MetaData<float>::Class(),this);
   } else {
      R__b.WriteClassBuffer(SH::MetaData<float>::Class(),this);
   }
}

} // namespace SH
namespace ROOT {
   // Wrappers around operator new
   static void *new_SHcLcLMetaDatalEfloatgR(void *p) {
      return  p ? new(p) ::SH::MetaData<float> : new ::SH::MetaData<float>;
   }
   static void *newArray_SHcLcLMetaDatalEfloatgR(Long_t nElements, void *p) {
      return p ? new(p) ::SH::MetaData<float>[nElements] : new ::SH::MetaData<float>[nElements];
   }
   // Wrapper around operator delete
   static void delete_SHcLcLMetaDatalEfloatgR(void *p) {
      delete ((::SH::MetaData<float>*)p);
   }
   static void deleteArray_SHcLcLMetaDatalEfloatgR(void *p) {
      delete [] ((::SH::MetaData<float>*)p);
   }
   static void destruct_SHcLcLMetaDatalEfloatgR(void *p) {
      typedef ::SH::MetaData<float> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SH::MetaData<float>

namespace SH {
//______________________________________________________________________________
template <> void MetaVector<float>::Streamer(TBuffer &R__b)
{
   // Stream an object of class SH::MetaVector<float>.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(SH::MetaVector<float>::Class(),this);
   } else {
      R__b.WriteClassBuffer(SH::MetaVector<float>::Class(),this);
   }
}

} // namespace SH
namespace ROOT {
   // Wrappers around operator new
   static void *new_SHcLcLMetaVectorlEfloatgR(void *p) {
      return  p ? new(p) ::SH::MetaVector<float> : new ::SH::MetaVector<float>;
   }
   static void *newArray_SHcLcLMetaVectorlEfloatgR(Long_t nElements, void *p) {
      return p ? new(p) ::SH::MetaVector<float>[nElements] : new ::SH::MetaVector<float>[nElements];
   }
   // Wrapper around operator delete
   static void delete_SHcLcLMetaVectorlEfloatgR(void *p) {
      delete ((::SH::MetaVector<float>*)p);
   }
   static void deleteArray_SHcLcLMetaVectorlEfloatgR(void *p) {
      delete [] ((::SH::MetaVector<float>*)p);
   }
   static void destruct_SHcLcLMetaVectorlEfloatgR(void *p) {
      typedef ::SH::MetaVector<float> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SH::MetaVector<float>

namespace EL {
//______________________________________________________________________________
void AlgSelect::Streamer(TBuffer &R__b)
{
   // Stream an object of class EL::AlgSelect.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EL::AlgSelect::Class(),this);
   } else {
      R__b.WriteClassBuffer(EL::AlgSelect::Class(),this);
   }
}

} // namespace EL
namespace ROOT {
   // Wrappers around operator new
   static void *new_ELcLcLAlgSelect(void *p) {
      return  p ? new(p) ::EL::AlgSelect : new ::EL::AlgSelect;
   }
   static void *newArray_ELcLcLAlgSelect(Long_t nElements, void *p) {
      return p ? new(p) ::EL::AlgSelect[nElements] : new ::EL::AlgSelect[nElements];
   }
   // Wrapper around operator delete
   static void delete_ELcLcLAlgSelect(void *p) {
      delete ((::EL::AlgSelect*)p);
   }
   static void deleteArray_ELcLcLAlgSelect(void *p) {
      delete [] ((::EL::AlgSelect*)p);
   }
   static void destruct_ELcLcLAlgSelect(void *p) {
      typedef ::EL::AlgSelect current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::AlgSelect

namespace EL {
//______________________________________________________________________________
void DuplicateChecker::Streamer(TBuffer &R__b)
{
   // Stream an object of class EL::DuplicateChecker.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EL::DuplicateChecker::Class(),this);
   } else {
      R__b.WriteClassBuffer(EL::DuplicateChecker::Class(),this);
   }
}

} // namespace EL
namespace ROOT {
   // Wrappers around operator new
   static void *new_ELcLcLDuplicateChecker(void *p) {
      return  p ? new(p) ::EL::DuplicateChecker : new ::EL::DuplicateChecker;
   }
   static void *newArray_ELcLcLDuplicateChecker(Long_t nElements, void *p) {
      return p ? new(p) ::EL::DuplicateChecker[nElements] : new ::EL::DuplicateChecker[nElements];
   }
   // Wrapper around operator delete
   static void delete_ELcLcLDuplicateChecker(void *p) {
      delete ((::EL::DuplicateChecker*)p);
   }
   static void deleteArray_ELcLcLDuplicateChecker(void *p) {
      delete [] ((::EL::DuplicateChecker*)p);
   }
   static void destruct_ELcLcLDuplicateChecker(void *p) {
      typedef ::EL::DuplicateChecker current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::DuplicateChecker

namespace EL {
//______________________________________________________________________________
void NTupleSvc::Streamer(TBuffer &R__b)
{
   // Stream an object of class EL::NTupleSvc.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EL::NTupleSvc::Class(),this);
   } else {
      R__b.WriteClassBuffer(EL::NTupleSvc::Class(),this);
   }
}

} // namespace EL
namespace ROOT {
   // Wrappers around operator new
   static void *new_ELcLcLNTupleSvc(void *p) {
      return  p ? new(p) ::EL::NTupleSvc : new ::EL::NTupleSvc;
   }
   static void *newArray_ELcLcLNTupleSvc(Long_t nElements, void *p) {
      return p ? new(p) ::EL::NTupleSvc[nElements] : new ::EL::NTupleSvc[nElements];
   }
   // Wrapper around operator delete
   static void delete_ELcLcLNTupleSvc(void *p) {
      delete ((::EL::NTupleSvc*)p);
   }
   static void deleteArray_ELcLcLNTupleSvc(void *p) {
      delete [] ((::EL::NTupleSvc*)p);
   }
   static void destruct_ELcLcLNTupleSvc(void *p) {
      typedef ::EL::NTupleSvc current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::NTupleSvc

namespace EL {
//______________________________________________________________________________
void UnitTestSkim::Streamer(TBuffer &R__b)
{
   // Stream an object of class EL::UnitTestSkim.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EL::UnitTestSkim::Class(),this);
   } else {
      R__b.WriteClassBuffer(EL::UnitTestSkim::Class(),this);
   }
}

} // namespace EL
namespace ROOT {
   // Wrappers around operator new
   static void *new_ELcLcLUnitTestSkim(void *p) {
      return  p ? new(p) ::EL::UnitTestSkim : new ::EL::UnitTestSkim;
   }
   static void *newArray_ELcLcLUnitTestSkim(Long_t nElements, void *p) {
      return p ? new(p) ::EL::UnitTestSkim[nElements] : new ::EL::UnitTestSkim[nElements];
   }
   // Wrapper around operator delete
   static void delete_ELcLcLUnitTestSkim(void *p) {
      delete ((::EL::UnitTestSkim*)p);
   }
   static void deleteArray_ELcLcLUnitTestSkim(void *p) {
      delete [] ((::EL::UnitTestSkim*)p);
   }
   static void destruct_ELcLcLUnitTestSkim(void *p) {
      typedef ::EL::UnitTestSkim current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::UnitTestSkim

namespace EL {
//______________________________________________________________________________
void WhiteBoardSvc::Streamer(TBuffer &R__b)
{
   // Stream an object of class EL::WhiteBoardSvc.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EL::WhiteBoardSvc::Class(),this);
   } else {
      R__b.WriteClassBuffer(EL::WhiteBoardSvc::Class(),this);
   }
}

} // namespace EL
namespace ROOT {
   // Wrappers around operator new
   static void *new_ELcLcLWhiteBoardSvc(void *p) {
      return  p ? new(p) ::EL::WhiteBoardSvc : new ::EL::WhiteBoardSvc;
   }
   static void *newArray_ELcLcLWhiteBoardSvc(Long_t nElements, void *p) {
      return p ? new(p) ::EL::WhiteBoardSvc[nElements] : new ::EL::WhiteBoardSvc[nElements];
   }
   // Wrapper around operator delete
   static void delete_ELcLcLWhiteBoardSvc(void *p) {
      delete ((::EL::WhiteBoardSvc*)p);
   }
   static void deleteArray_ELcLcLWhiteBoardSvc(void *p) {
      delete [] ((::EL::WhiteBoardSvc*)p);
   }
   static void destruct_ELcLcLWhiteBoardSvc(void *p) {
      typedef ::EL::WhiteBoardSvc current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::WhiteBoardSvc

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

namespace ROOT {
   static TClass *vectorlEfloatgR_Dictionary();
   static void vectorlEfloatgR_TClassManip(TClass*);
   static void *new_vectorlEfloatgR(void *p = 0);
   static void *newArray_vectorlEfloatgR(Long_t size, void *p);
   static void delete_vectorlEfloatgR(void *p);
   static void deleteArray_vectorlEfloatgR(void *p);
   static void destruct_vectorlEfloatgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<float>*)
   {
      vector<float> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<float>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<float>", -2, "vector", 214,
                  typeid(vector<float>), DefineBehavior(ptr, ptr),
                  &vectorlEfloatgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<float>) );
      instance.SetNew(&new_vectorlEfloatgR);
      instance.SetNewArray(&newArray_vectorlEfloatgR);
      instance.SetDelete(&delete_vectorlEfloatgR);
      instance.SetDeleteArray(&deleteArray_vectorlEfloatgR);
      instance.SetDestructor(&destruct_vectorlEfloatgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<float> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<float>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEfloatgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<float>*)0x0)->GetClass();
      vectorlEfloatgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEfloatgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEfloatgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<float> : new vector<float>;
   }
   static void *newArray_vectorlEfloatgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<float>[nElements] : new vector<float>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEfloatgR(void *p) {
      delete ((vector<float>*)p);
   }
   static void deleteArray_vectorlEfloatgR(void *p) {
      delete [] ((vector<float>*)p);
   }
   static void destruct_vectorlEfloatgR(void *p) {
      typedef vector<float> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<float>

namespace ROOT {
   static TClass *setlEstringgR_Dictionary();
   static void setlEstringgR_TClassManip(TClass*);
   static void *new_setlEstringgR(void *p = 0);
   static void *newArray_setlEstringgR(Long_t size, void *p);
   static void delete_setlEstringgR(void *p);
   static void deleteArray_setlEstringgR(void *p);
   static void destruct_setlEstringgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const set<string>*)
   {
      set<string> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(set<string>));
      static ::ROOT::TGenericClassInfo 
         instance("set<string>", -2, "set", 90,
                  typeid(set<string>), DefineBehavior(ptr, ptr),
                  &setlEstringgR_Dictionary, isa_proxy, 0,
                  sizeof(set<string>) );
      instance.SetNew(&new_setlEstringgR);
      instance.SetNewArray(&newArray_setlEstringgR);
      instance.SetDelete(&delete_setlEstringgR);
      instance.SetDeleteArray(&deleteArray_setlEstringgR);
      instance.SetDestructor(&destruct_setlEstringgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Insert< set<string> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const set<string>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *setlEstringgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const set<string>*)0x0)->GetClass();
      setlEstringgR_TClassManip(theClass);
   return theClass;
   }

   static void setlEstringgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_setlEstringgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) set<string> : new set<string>;
   }
   static void *newArray_setlEstringgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) set<string>[nElements] : new set<string>[nElements];
   }
   // Wrapper around operator delete
   static void delete_setlEstringgR(void *p) {
      delete ((set<string>*)p);
   }
   static void deleteArray_setlEstringgR(void *p) {
      delete [] ((set<string>*)p);
   }
   static void destruct_setlEstringgR(void *p) {
      typedef set<string> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class set<string>

namespace ROOT {
   static TClass *maplEpairlEstringcOstringgRcOmaplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgRsPgR_Dictionary();
   static void maplEpairlEstringcOstringgRcOmaplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgRsPgR_TClassManip(TClass*);
   static void *new_maplEpairlEstringcOstringgRcOmaplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgRsPgR(void *p = 0);
   static void *newArray_maplEpairlEstringcOstringgRcOmaplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgRsPgR(Long_t size, void *p);
   static void delete_maplEpairlEstringcOstringgRcOmaplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgRsPgR(void *p);
   static void deleteArray_maplEpairlEstringcOstringgRcOmaplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgRsPgR(void *p);
   static void destruct_maplEpairlEstringcOstringgRcOmaplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<pair<string,string>,map<Long64_t,pair<unsigned int,unsigned int> > >*)
   {
      map<pair<string,string>,map<Long64_t,pair<unsigned int,unsigned int> > > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<pair<string,string>,map<Long64_t,pair<unsigned int,unsigned int> > >));
      static ::ROOT::TGenericClassInfo 
         instance("map<pair<string,string>,map<Long64_t,pair<unsigned int,unsigned int> > >", -2, "map", 96,
                  typeid(map<pair<string,string>,map<Long64_t,pair<unsigned int,unsigned int> > >), DefineBehavior(ptr, ptr),
                  &maplEpairlEstringcOstringgRcOmaplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(map<pair<string,string>,map<Long64_t,pair<unsigned int,unsigned int> > >) );
      instance.SetNew(&new_maplEpairlEstringcOstringgRcOmaplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgRsPgR);
      instance.SetNewArray(&newArray_maplEpairlEstringcOstringgRcOmaplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgRsPgR);
      instance.SetDelete(&delete_maplEpairlEstringcOstringgRcOmaplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgRsPgR);
      instance.SetDeleteArray(&deleteArray_maplEpairlEstringcOstringgRcOmaplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgRsPgR);
      instance.SetDestructor(&destruct_maplEpairlEstringcOstringgRcOmaplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<pair<string,string>,map<Long64_t,pair<unsigned int,unsigned int> > > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<pair<string,string>,map<Long64_t,pair<unsigned int,unsigned int> > >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEpairlEstringcOstringgRcOmaplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<pair<string,string>,map<Long64_t,pair<unsigned int,unsigned int> > >*)0x0)->GetClass();
      maplEpairlEstringcOstringgRcOmaplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEpairlEstringcOstringgRcOmaplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEpairlEstringcOstringgRcOmaplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) map<pair<string,string>,map<Long64_t,pair<unsigned int,unsigned int> > > : new map<pair<string,string>,map<Long64_t,pair<unsigned int,unsigned int> > >;
   }
   static void *newArray_maplEpairlEstringcOstringgRcOmaplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) map<pair<string,string>,map<Long64_t,pair<unsigned int,unsigned int> > >[nElements] : new map<pair<string,string>,map<Long64_t,pair<unsigned int,unsigned int> > >[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEpairlEstringcOstringgRcOmaplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgRsPgR(void *p) {
      delete ((map<pair<string,string>,map<Long64_t,pair<unsigned int,unsigned int> > >*)p);
   }
   static void deleteArray_maplEpairlEstringcOstringgRcOmaplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgRsPgR(void *p) {
      delete [] ((map<pair<string,string>,map<Long64_t,pair<unsigned int,unsigned int> > >*)p);
   }
   static void destruct_maplEpairlEstringcOstringgRcOmaplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgRsPgR(void *p) {
      typedef map<pair<string,string>,map<Long64_t,pair<unsigned int,unsigned int> > > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<pair<string,string>,map<Long64_t,pair<unsigned int,unsigned int> > >

namespace ROOT {
   static TClass *maplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgR_Dictionary();
   static void maplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgR_TClassManip(TClass*);
   static void *new_maplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgR(void *p = 0);
   static void *newArray_maplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgR(Long_t size, void *p);
   static void delete_maplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgR(void *p);
   static void deleteArray_maplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgR(void *p);
   static void destruct_maplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<Long64_t,pair<unsigned int,unsigned int> >*)
   {
      map<Long64_t,pair<unsigned int,unsigned int> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<Long64_t,pair<unsigned int,unsigned int> >));
      static ::ROOT::TGenericClassInfo 
         instance("map<Long64_t,pair<unsigned int,unsigned int> >", -2, "map", 96,
                  typeid(map<Long64_t,pair<unsigned int,unsigned int> >), DefineBehavior(ptr, ptr),
                  &maplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(map<Long64_t,pair<unsigned int,unsigned int> >) );
      instance.SetNew(&new_maplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgR);
      instance.SetNewArray(&newArray_maplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgR);
      instance.SetDelete(&delete_maplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgR);
      instance.SetDeleteArray(&deleteArray_maplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgR);
      instance.SetDestructor(&destruct_maplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<Long64_t,pair<unsigned int,unsigned int> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<Long64_t,pair<unsigned int,unsigned int> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<Long64_t,pair<unsigned int,unsigned int> >*)0x0)->GetClass();
      maplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void maplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) map<Long64_t,pair<unsigned int,unsigned int> > : new map<Long64_t,pair<unsigned int,unsigned int> >;
   }
   static void *newArray_maplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) map<Long64_t,pair<unsigned int,unsigned int> >[nElements] : new map<Long64_t,pair<unsigned int,unsigned int> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgR(void *p) {
      delete ((map<Long64_t,pair<unsigned int,unsigned int> >*)p);
   }
   static void deleteArray_maplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgR(void *p) {
      delete [] ((map<Long64_t,pair<unsigned int,unsigned int> >*)p);
   }
   static void destruct_maplELong64_tcOpairlEunsignedsPintcOunsignedsPintgRsPgR(void *p) {
      typedef map<Long64_t,pair<unsigned int,unsigned int> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<Long64_t,pair<unsigned int,unsigned int> >

namespace {
  void TriggerDictionaryInitialization_EventLoopAlgsCINT_Impl() {
    static const char* headers[] = {
"EventLoopAlgs/AlgSelect.h",
"EventLoopAlgs/DuplicateChecker.h",
"EventLoopAlgs/NTupleSvc.h",
"EventLoopAlgs/UnitTestSkim.h",
"EventLoopAlgs/WhiteBoardSvc.h",
"SampleHandler/MetaData.h",
"SampleHandler/MetaVector.h",
0
    };
    static const char* includePaths[] = {
"/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoopAlgs/Root",
"/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoopAlgs",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoopAlgs/cmt/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace SH{template <class T> class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoopAlgs/Root/LinkDef.h")))  MetaData;
}
namespace SH{template <class T> class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoopAlgs/Root/LinkDef.h")))  MetaVector;
}
namespace EL{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoopAlgs/Root/LinkDef.h")))  AlgSelect;}
namespace EL{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoopAlgs/Root/LinkDef.h")))  DuplicateChecker;}
namespace EL{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoopAlgs/Root/LinkDef.h")))  NTupleSvc;}
namespace EL{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoopAlgs/Root/LinkDef.h")))  UnitTestSkim;}
namespace EL{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoopAlgs/Root/LinkDef.h")))  WhiteBoardSvc;}
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
  #define ROOTCORE_PACKAGE "EventLoopAlgs"
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "EventLoopAlgs/AlgSelect.h"
#include "EventLoopAlgs/DuplicateChecker.h"
#include "EventLoopAlgs/NTupleSvc.h"
#include "EventLoopAlgs/UnitTestSkim.h"
#include "EventLoopAlgs/WhiteBoardSvc.h"
#include "SampleHandler/MetaData.h"
#include "SampleHandler/MetaVector.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"EL::AlgSelect", payloadCode, "@",
"EL::DuplicateChecker", payloadCode, "@",
"EL::NTupleSvc", payloadCode, "@",
"EL::UnitTestSkim", payloadCode, "@",
"EL::WhiteBoardSvc", payloadCode, "@",
"SH::MetaData<float>", payloadCode, "@",
"SH::MetaVector<float>", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("EventLoopAlgsCINT",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_EventLoopAlgsCINT_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_EventLoopAlgsCINT_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_EventLoopAlgsCINT() {
  TriggerDictionaryInitialization_EventLoopAlgsCINT_Impl();
}
