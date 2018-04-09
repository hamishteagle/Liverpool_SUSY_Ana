#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#ifdef __llvm__
#pragma GCC diagnostic ignored "-Wunused-private-field"
#endif
// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIuserdIhteagledIAnalysisDirectorydIBase_2_4_34dIRootCoreBindIobjdIx86_64mIslc6mIgcc49mIoptdIMultiDrawdIobjdIMultiDrawCINT

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
#include "MultiDraw/AlgCFlow.h"
#include "MultiDraw/AlgHist.h"
#include "MultiDraw/Formula.h"
#include "MultiDraw/FormulaSvc.h"

// Header files passed via #pragma extra_include

namespace MD {
   namespace ROOT {
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance();
      static TClass *MD_Dictionary();

      // Function generating the singleton type initializer
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance()
      {
         static ::ROOT::TGenericClassInfo 
            instance("MD", 0 /*version*/, "MultiDraw/Global.h", 18,
                     ::ROOT::DefineBehavior((void*)0,(void*)0),
                     &MD_Dictionary, 0);
         return &instance;
      }
      // Insure that the inline function is _not_ optimized away by the compiler
      ::ROOT::TGenericClassInfo *(*_R__UNIQUE_(InitFunctionKeeper))() = &GenerateInitInstance;  
      // Static variable to force the class initialization
      static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstance(); R__UseDummy(_R__UNIQUE_(Init));

      // Dictionary for non-ClassDef classes
      static TClass *MD_Dictionary() {
         return GenerateInitInstance()->GetClass();
      }

   }
}

namespace ROOT {
   static void *new_MDcLcLAlgCFlow(void *p = 0);
   static void *newArray_MDcLcLAlgCFlow(Long_t size, void *p);
   static void delete_MDcLcLAlgCFlow(void *p);
   static void deleteArray_MDcLcLAlgCFlow(void *p);
   static void destruct_MDcLcLAlgCFlow(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MD::AlgCFlow*)
   {
      ::MD::AlgCFlow *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MD::AlgCFlow >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MD::AlgCFlow", ::MD::AlgCFlow::Class_Version(), "MultiDraw/AlgCFlow.h", 28,
                  typeid(::MD::AlgCFlow), DefineBehavior(ptr, ptr),
                  &::MD::AlgCFlow::Dictionary, isa_proxy, 4,
                  sizeof(::MD::AlgCFlow) );
      instance.SetNew(&new_MDcLcLAlgCFlow);
      instance.SetNewArray(&newArray_MDcLcLAlgCFlow);
      instance.SetDelete(&delete_MDcLcLAlgCFlow);
      instance.SetDeleteArray(&deleteArray_MDcLcLAlgCFlow);
      instance.SetDestructor(&destruct_MDcLcLAlgCFlow);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MD::AlgCFlow*)
   {
      return GenerateInitInstanceLocal((::MD::AlgCFlow*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MD::AlgCFlow*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MDcLcLAlgHist(void *p = 0);
   static void *newArray_MDcLcLAlgHist(Long_t size, void *p);
   static void delete_MDcLcLAlgHist(void *p);
   static void deleteArray_MDcLcLAlgHist(void *p);
   static void destruct_MDcLcLAlgHist(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MD::AlgHist*)
   {
      ::MD::AlgHist *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MD::AlgHist >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MD::AlgHist", ::MD::AlgHist::Class_Version(), "MultiDraw/AlgHist.h", 28,
                  typeid(::MD::AlgHist), DefineBehavior(ptr, ptr),
                  &::MD::AlgHist::Dictionary, isa_proxy, 4,
                  sizeof(::MD::AlgHist) );
      instance.SetNew(&new_MDcLcLAlgHist);
      instance.SetNewArray(&newArray_MDcLcLAlgHist);
      instance.SetDelete(&delete_MDcLcLAlgHist);
      instance.SetDeleteArray(&deleteArray_MDcLcLAlgHist);
      instance.SetDestructor(&destruct_MDcLcLAlgHist);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MD::AlgHist*)
   {
      return GenerateInitInstanceLocal((::MD::AlgHist*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MD::AlgHist*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static TClass *MDcLcLFormula_Dictionary();
   static void MDcLcLFormula_TClassManip(TClass*);
   static void *new_MDcLcLFormula(void *p = 0);
   static void *newArray_MDcLcLFormula(Long_t size, void *p);
   static void delete_MDcLcLFormula(void *p);
   static void deleteArray_MDcLcLFormula(void *p);
   static void destruct_MDcLcLFormula(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MD::Formula*)
   {
      ::MD::Formula *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::MD::Formula));
      static ::ROOT::TGenericClassInfo 
         instance("MD::Formula", "MultiDraw/Formula.h", 31,
                  typeid(::MD::Formula), DefineBehavior(ptr, ptr),
                  &MDcLcLFormula_Dictionary, isa_proxy, 4,
                  sizeof(::MD::Formula) );
      instance.SetNew(&new_MDcLcLFormula);
      instance.SetNewArray(&newArray_MDcLcLFormula);
      instance.SetDelete(&delete_MDcLcLFormula);
      instance.SetDeleteArray(&deleteArray_MDcLcLFormula);
      instance.SetDestructor(&destruct_MDcLcLFormula);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MD::Formula*)
   {
      return GenerateInitInstanceLocal((::MD::Formula*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MD::Formula*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *MDcLcLFormula_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::MD::Formula*)0x0)->GetClass();
      MDcLcLFormula_TClassManip(theClass);
   return theClass;
   }

   static void MDcLcLFormula_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static void *new_MDcLcLFormulaSvc(void *p = 0);
   static void *newArray_MDcLcLFormulaSvc(Long_t size, void *p);
   static void delete_MDcLcLFormulaSvc(void *p);
   static void deleteArray_MDcLcLFormulaSvc(void *p);
   static void destruct_MDcLcLFormulaSvc(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MD::FormulaSvc*)
   {
      ::MD::FormulaSvc *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MD::FormulaSvc >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MD::FormulaSvc", ::MD::FormulaSvc::Class_Version(), "MultiDraw/FormulaSvc.h", 49,
                  typeid(::MD::FormulaSvc), DefineBehavior(ptr, ptr),
                  &::MD::FormulaSvc::Dictionary, isa_proxy, 4,
                  sizeof(::MD::FormulaSvc) );
      instance.SetNew(&new_MDcLcLFormulaSvc);
      instance.SetNewArray(&newArray_MDcLcLFormulaSvc);
      instance.SetDelete(&delete_MDcLcLFormulaSvc);
      instance.SetDeleteArray(&deleteArray_MDcLcLFormulaSvc);
      instance.SetDestructor(&destruct_MDcLcLFormulaSvc);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MD::FormulaSvc*)
   {
      return GenerateInitInstanceLocal((::MD::FormulaSvc*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MD::FormulaSvc*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace MD {
//______________________________________________________________________________
atomic_TClass_ptr AlgCFlow::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *AlgCFlow::Class_Name()
{
   return "MD::AlgCFlow";
}

//______________________________________________________________________________
const char *AlgCFlow::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MD::AlgCFlow*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int AlgCFlow::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MD::AlgCFlow*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *AlgCFlow::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MD::AlgCFlow*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *AlgCFlow::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MD::AlgCFlow*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace MD
namespace MD {
//______________________________________________________________________________
atomic_TClass_ptr AlgHist::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *AlgHist::Class_Name()
{
   return "MD::AlgHist";
}

//______________________________________________________________________________
const char *AlgHist::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MD::AlgHist*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int AlgHist::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MD::AlgHist*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *AlgHist::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MD::AlgHist*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *AlgHist::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MD::AlgHist*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace MD
namespace MD {
//______________________________________________________________________________
atomic_TClass_ptr FormulaSvc::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *FormulaSvc::Class_Name()
{
   return "MD::FormulaSvc";
}

//______________________________________________________________________________
const char *FormulaSvc::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MD::FormulaSvc*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int FormulaSvc::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MD::FormulaSvc*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *FormulaSvc::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MD::FormulaSvc*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *FormulaSvc::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MD::FormulaSvc*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace MD
namespace MD {
//______________________________________________________________________________
void AlgCFlow::Streamer(TBuffer &R__b)
{
   // Stream an object of class MD::AlgCFlow.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MD::AlgCFlow::Class(),this);
   } else {
      R__b.WriteClassBuffer(MD::AlgCFlow::Class(),this);
   }
}

} // namespace MD
namespace ROOT {
   // Wrappers around operator new
   static void *new_MDcLcLAlgCFlow(void *p) {
      return  p ? new(p) ::MD::AlgCFlow : new ::MD::AlgCFlow;
   }
   static void *newArray_MDcLcLAlgCFlow(Long_t nElements, void *p) {
      return p ? new(p) ::MD::AlgCFlow[nElements] : new ::MD::AlgCFlow[nElements];
   }
   // Wrapper around operator delete
   static void delete_MDcLcLAlgCFlow(void *p) {
      delete ((::MD::AlgCFlow*)p);
   }
   static void deleteArray_MDcLcLAlgCFlow(void *p) {
      delete [] ((::MD::AlgCFlow*)p);
   }
   static void destruct_MDcLcLAlgCFlow(void *p) {
      typedef ::MD::AlgCFlow current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MD::AlgCFlow

namespace MD {
//______________________________________________________________________________
void AlgHist::Streamer(TBuffer &R__b)
{
   // Stream an object of class MD::AlgHist.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MD::AlgHist::Class(),this);
   } else {
      R__b.WriteClassBuffer(MD::AlgHist::Class(),this);
   }
}

} // namespace MD
namespace ROOT {
   // Wrappers around operator new
   static void *new_MDcLcLAlgHist(void *p) {
      return  p ? new(p) ::MD::AlgHist : new ::MD::AlgHist;
   }
   static void *newArray_MDcLcLAlgHist(Long_t nElements, void *p) {
      return p ? new(p) ::MD::AlgHist[nElements] : new ::MD::AlgHist[nElements];
   }
   // Wrapper around operator delete
   static void delete_MDcLcLAlgHist(void *p) {
      delete ((::MD::AlgHist*)p);
   }
   static void deleteArray_MDcLcLAlgHist(void *p) {
      delete [] ((::MD::AlgHist*)p);
   }
   static void destruct_MDcLcLAlgHist(void *p) {
      typedef ::MD::AlgHist current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MD::AlgHist

namespace ROOT {
   // Wrappers around operator new
   static void *new_MDcLcLFormula(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::MD::Formula : new ::MD::Formula;
   }
   static void *newArray_MDcLcLFormula(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::MD::Formula[nElements] : new ::MD::Formula[nElements];
   }
   // Wrapper around operator delete
   static void delete_MDcLcLFormula(void *p) {
      delete ((::MD::Formula*)p);
   }
   static void deleteArray_MDcLcLFormula(void *p) {
      delete [] ((::MD::Formula*)p);
   }
   static void destruct_MDcLcLFormula(void *p) {
      typedef ::MD::Formula current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MD::Formula

namespace MD {
//______________________________________________________________________________
void FormulaSvc::Streamer(TBuffer &R__b)
{
   // Stream an object of class MD::FormulaSvc.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MD::FormulaSvc::Class(),this);
   } else {
      R__b.WriteClassBuffer(MD::FormulaSvc::Class(),this);
   }
}

} // namespace MD
namespace ROOT {
   // Wrappers around operator new
   static void *new_MDcLcLFormulaSvc(void *p) {
      return  p ? new(p) ::MD::FormulaSvc : new ::MD::FormulaSvc;
   }
   static void *newArray_MDcLcLFormulaSvc(Long_t nElements, void *p) {
      return p ? new(p) ::MD::FormulaSvc[nElements] : new ::MD::FormulaSvc[nElements];
   }
   // Wrapper around operator delete
   static void delete_MDcLcLFormulaSvc(void *p) {
      delete ((::MD::FormulaSvc*)p);
   }
   static void deleteArray_MDcLcLFormulaSvc(void *p) {
      delete [] ((::MD::FormulaSvc*)p);
   }
   static void destruct_MDcLcLFormulaSvc(void *p) {
      typedef ::MD::FormulaSvc current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MD::FormulaSvc

namespace ROOT {
   static TClass *vectorlEunsignedsPlonggR_Dictionary();
   static void vectorlEunsignedsPlonggR_TClassManip(TClass*);
   static void *new_vectorlEunsignedsPlonggR(void *p = 0);
   static void *newArray_vectorlEunsignedsPlonggR(Long_t size, void *p);
   static void delete_vectorlEunsignedsPlonggR(void *p);
   static void deleteArray_vectorlEunsignedsPlonggR(void *p);
   static void destruct_vectorlEunsignedsPlonggR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<unsigned long>*)
   {
      vector<unsigned long> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<unsigned long>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<unsigned long>", -2, "vector", 214,
                  typeid(vector<unsigned long>), DefineBehavior(ptr, ptr),
                  &vectorlEunsignedsPlonggR_Dictionary, isa_proxy, 0,
                  sizeof(vector<unsigned long>) );
      instance.SetNew(&new_vectorlEunsignedsPlonggR);
      instance.SetNewArray(&newArray_vectorlEunsignedsPlonggR);
      instance.SetDelete(&delete_vectorlEunsignedsPlonggR);
      instance.SetDeleteArray(&deleteArray_vectorlEunsignedsPlonggR);
      instance.SetDestructor(&destruct_vectorlEunsignedsPlonggR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<unsigned long> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<unsigned long>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEunsignedsPlonggR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<unsigned long>*)0x0)->GetClass();
      vectorlEunsignedsPlonggR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEunsignedsPlonggR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEunsignedsPlonggR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<unsigned long> : new vector<unsigned long>;
   }
   static void *newArray_vectorlEunsignedsPlonggR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<unsigned long>[nElements] : new vector<unsigned long>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEunsignedsPlonggR(void *p) {
      delete ((vector<unsigned long>*)p);
   }
   static void deleteArray_vectorlEunsignedsPlonggR(void *p) {
      delete [] ((vector<unsigned long>*)p);
   }
   static void destruct_vectorlEunsignedsPlonggR(void *p) {
      typedef vector<unsigned long> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<unsigned long>

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
   static TClass *vectorlEdoublegR_Dictionary();
   static void vectorlEdoublegR_TClassManip(TClass*);
   static void *new_vectorlEdoublegR(void *p = 0);
   static void *newArray_vectorlEdoublegR(Long_t size, void *p);
   static void delete_vectorlEdoublegR(void *p);
   static void deleteArray_vectorlEdoublegR(void *p);
   static void destruct_vectorlEdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<double>*)
   {
      vector<double> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<double>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<double>", -2, "vector", 214,
                  typeid(vector<double>), DefineBehavior(ptr, ptr),
                  &vectorlEdoublegR_Dictionary, isa_proxy, 0,
                  sizeof(vector<double>) );
      instance.SetNew(&new_vectorlEdoublegR);
      instance.SetNewArray(&newArray_vectorlEdoublegR);
      instance.SetDelete(&delete_vectorlEdoublegR);
      instance.SetDeleteArray(&deleteArray_vectorlEdoublegR);
      instance.SetDestructor(&destruct_vectorlEdoublegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<double> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<double>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEdoublegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<double>*)0x0)->GetClass();
      vectorlEdoublegR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEdoublegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEdoublegR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<double> : new vector<double>;
   }
   static void *newArray_vectorlEdoublegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<double>[nElements] : new vector<double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEdoublegR(void *p) {
      delete ((vector<double>*)p);
   }
   static void deleteArray_vectorlEdoublegR(void *p) {
      delete [] ((vector<double>*)p);
   }
   static void destruct_vectorlEdoublegR(void *p) {
      typedef vector<double> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<double>

namespace ROOT {
   static TClass *vectorlEconstsPMDcLcLFormulamUgR_Dictionary();
   static void vectorlEconstsPMDcLcLFormulamUgR_TClassManip(TClass*);
   static void *new_vectorlEconstsPMDcLcLFormulamUgR(void *p = 0);
   static void *newArray_vectorlEconstsPMDcLcLFormulamUgR(Long_t size, void *p);
   static void delete_vectorlEconstsPMDcLcLFormulamUgR(void *p);
   static void deleteArray_vectorlEconstsPMDcLcLFormulamUgR(void *p);
   static void destruct_vectorlEconstsPMDcLcLFormulamUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<const MD::Formula*>*)
   {
      vector<const MD::Formula*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<const MD::Formula*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<const MD::Formula*>", -2, "vector", 214,
                  typeid(vector<const MD::Formula*>), DefineBehavior(ptr, ptr),
                  &vectorlEconstsPMDcLcLFormulamUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<const MD::Formula*>) );
      instance.SetNew(&new_vectorlEconstsPMDcLcLFormulamUgR);
      instance.SetNewArray(&newArray_vectorlEconstsPMDcLcLFormulamUgR);
      instance.SetDelete(&delete_vectorlEconstsPMDcLcLFormulamUgR);
      instance.SetDeleteArray(&deleteArray_vectorlEconstsPMDcLcLFormulamUgR);
      instance.SetDestructor(&destruct_vectorlEconstsPMDcLcLFormulamUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<const MD::Formula*> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<const MD::Formula*>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEconstsPMDcLcLFormulamUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<const MD::Formula*>*)0x0)->GetClass();
      vectorlEconstsPMDcLcLFormulamUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEconstsPMDcLcLFormulamUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEconstsPMDcLcLFormulamUgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<const MD::Formula*> : new vector<const MD::Formula*>;
   }
   static void *newArray_vectorlEconstsPMDcLcLFormulamUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<const MD::Formula*>[nElements] : new vector<const MD::Formula*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEconstsPMDcLcLFormulamUgR(void *p) {
      delete ((vector<const MD::Formula*>*)p);
   }
   static void deleteArray_vectorlEconstsPMDcLcLFormulamUgR(void *p) {
      delete [] ((vector<const MD::Formula*>*)p);
   }
   static void destruct_vectorlEconstsPMDcLcLFormulamUgR(void *p) {
      typedef vector<const MD::Formula*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<const MD::Formula*>

namespace ROOT {
   static TClass *vectorlEboolgR_Dictionary();
   static void vectorlEboolgR_TClassManip(TClass*);
   static void *new_vectorlEboolgR(void *p = 0);
   static void *newArray_vectorlEboolgR(Long_t size, void *p);
   static void delete_vectorlEboolgR(void *p);
   static void deleteArray_vectorlEboolgR(void *p);
   static void destruct_vectorlEboolgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<bool>*)
   {
      vector<bool> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<bool>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<bool>", -2, "vector", 526,
                  typeid(vector<bool>), DefineBehavior(ptr, ptr),
                  &vectorlEboolgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<bool>) );
      instance.SetNew(&new_vectorlEboolgR);
      instance.SetNewArray(&newArray_vectorlEboolgR);
      instance.SetDelete(&delete_vectorlEboolgR);
      instance.SetDeleteArray(&deleteArray_vectorlEboolgR);
      instance.SetDestructor(&destruct_vectorlEboolgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<bool> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<bool>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEboolgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<bool>*)0x0)->GetClass();
      vectorlEboolgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEboolgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEboolgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<bool> : new vector<bool>;
   }
   static void *newArray_vectorlEboolgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<bool>[nElements] : new vector<bool>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEboolgR(void *p) {
      delete ((vector<bool>*)p);
   }
   static void deleteArray_vectorlEboolgR(void *p) {
      delete [] ((vector<bool>*)p);
   }
   static void destruct_vectorlEboolgR(void *p) {
      typedef vector<bool> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<bool>

namespace {
  void TriggerDictionaryInitialization_MultiDrawCINT_Impl() {
    static const char* headers[] = {
"MultiDraw/AlgCFlow.h",
"MultiDraw/AlgHist.h",
"MultiDraw/Formula.h",
"MultiDraw/FormulaSvc.h",
0
    };
    static const char* includePaths[] = {
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/MultiDraw/Root",
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/MultiDraw",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/MultiDraw/cmt/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace MD{class __attribute__((annotate("$clingAutoload$/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/MultiDraw/Root/LinkDef.h")))  AlgCFlow;}
namespace MD{class __attribute__((annotate("$clingAutoload$/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/MultiDraw/Root/LinkDef.h")))  AlgHist;}
namespace MD{class __attribute__((annotate("$clingAutoload$/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/MultiDraw/Root/LinkDef.h")))  Formula;}
namespace MD{class __attribute__((annotate("$clingAutoload$/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/MultiDraw/Root/LinkDef.h")))  FormulaSvc;}
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
  #define ROOTCORE_PACKAGE "MultiDraw"
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "MultiDraw/AlgCFlow.h"
#include "MultiDraw/AlgHist.h"
#include "MultiDraw/Formula.h"
#include "MultiDraw/FormulaSvc.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"MD::AlgCFlow", payloadCode, "@",
"MD::AlgHist", payloadCode, "@",
"MD::Formula", payloadCode, "@",
"MD::FormulaSvc", payloadCode, "@",
"MD::formulas", payloadCode, "@",
"MD::useFormulas", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("MultiDrawCINT",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_MultiDrawCINT_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_MultiDrawCINT_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_MultiDrawCINT() {
  TriggerDictionaryInitialization_MultiDrawCINT_Impl();
}
