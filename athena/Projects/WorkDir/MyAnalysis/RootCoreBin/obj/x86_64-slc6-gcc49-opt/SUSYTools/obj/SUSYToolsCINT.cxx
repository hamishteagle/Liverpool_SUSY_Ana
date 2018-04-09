#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#ifdef __llvm__
#pragma GCC diagnostic ignored "-Wunused-private-field"
#endif
// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIuserdIhteagledIAnalysisDirectorydIBase_2_4_34dIRootCoreBindIobjdIx86_64mIslc6mIgcc49mIoptdISUSYToolsdIobjdISUSYToolsCINT

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
#include "SUSYTools/SUSYCrossSection.h"
#include "SUSYTools/SUSYObjDef_xAOD.h"

// Header files passed via #pragma extra_include

namespace SUSY {
   namespace ROOT {
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance();
      static TClass *SUSY_Dictionary();

      // Function generating the singleton type initializer
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance()
      {
         static ::ROOT::TGenericClassInfo 
            instance("SUSY", 0 /*version*/, "SUSYTools/SUSYCrossSection.h", 14,
                     ::ROOT::DefineBehavior((void*)0,(void*)0),
                     &SUSY_Dictionary, 0);
         return &instance;
      }
      // Insure that the inline function is _not_ optimized away by the compiler
      ::ROOT::TGenericClassInfo *(*_R__UNIQUE_(InitFunctionKeeper))() = &GenerateInitInstance;  
      // Static variable to force the class initialization
      static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstance(); R__UseDummy(_R__UNIQUE_(Init));

      // Dictionary for non-ClassDef classes
      static TClass *SUSY_Dictionary() {
         return GenerateInitInstance()->GetClass();
      }

   }
}

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
                  &STcLcLSUSYObjDef_xAOD_Dictionary, isa_proxy, 4,
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
   static TClass *SUSYcLcLCrossSectionDB_Dictionary();
   static void SUSYcLcLCrossSectionDB_TClassManip(TClass*);
   static void *new_SUSYcLcLCrossSectionDB(void *p = 0);
   static void *newArray_SUSYcLcLCrossSectionDB(Long_t size, void *p);
   static void delete_SUSYcLcLCrossSectionDB(void *p);
   static void deleteArray_SUSYcLcLCrossSectionDB(void *p);
   static void destruct_SUSYcLcLCrossSectionDB(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SUSY::CrossSectionDB*)
   {
      ::SUSY::CrossSectionDB *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SUSY::CrossSectionDB));
      static ::ROOT::TGenericClassInfo 
         instance("SUSY::CrossSectionDB", "SUSYTools/SUSYCrossSection.h", 19,
                  typeid(::SUSY::CrossSectionDB), DefineBehavior(ptr, ptr),
                  &SUSYcLcLCrossSectionDB_Dictionary, isa_proxy, 4,
                  sizeof(::SUSY::CrossSectionDB) );
      instance.SetNew(&new_SUSYcLcLCrossSectionDB);
      instance.SetNewArray(&newArray_SUSYcLcLCrossSectionDB);
      instance.SetDelete(&delete_SUSYcLcLCrossSectionDB);
      instance.SetDeleteArray(&deleteArray_SUSYcLcLCrossSectionDB);
      instance.SetDestructor(&destruct_SUSYcLcLCrossSectionDB);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SUSY::CrossSectionDB*)
   {
      return GenerateInitInstanceLocal((::SUSY::CrossSectionDB*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SUSY::CrossSectionDB*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SUSYcLcLCrossSectionDB_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SUSY::CrossSectionDB*)0x0)->GetClass();
      SUSYcLcLCrossSectionDB_TClassManip(theClass);
   return theClass;
   }

   static void SUSYcLcLCrossSectionDB_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SUSYcLcLCrossSectionDBcLcLProcess_Dictionary();
   static void SUSYcLcLCrossSectionDBcLcLProcess_TClassManip(TClass*);
   static void *new_SUSYcLcLCrossSectionDBcLcLProcess(void *p = 0);
   static void *newArray_SUSYcLcLCrossSectionDBcLcLProcess(Long_t size, void *p);
   static void delete_SUSYcLcLCrossSectionDBcLcLProcess(void *p);
   static void deleteArray_SUSYcLcLCrossSectionDBcLcLProcess(void *p);
   static void destruct_SUSYcLcLCrossSectionDBcLcLProcess(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SUSY::CrossSectionDB::Process*)
   {
      ::SUSY::CrossSectionDB::Process *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SUSY::CrossSectionDB::Process));
      static ::ROOT::TGenericClassInfo 
         instance("SUSY::CrossSectionDB::Process", "SUSYTools/SUSYCrossSection.h", 30,
                  typeid(::SUSY::CrossSectionDB::Process), DefineBehavior(ptr, ptr),
                  &SUSYcLcLCrossSectionDBcLcLProcess_Dictionary, isa_proxy, 4,
                  sizeof(::SUSY::CrossSectionDB::Process) );
      instance.SetNew(&new_SUSYcLcLCrossSectionDBcLcLProcess);
      instance.SetNewArray(&newArray_SUSYcLcLCrossSectionDBcLcLProcess);
      instance.SetDelete(&delete_SUSYcLcLCrossSectionDBcLcLProcess);
      instance.SetDeleteArray(&deleteArray_SUSYcLcLCrossSectionDBcLcLProcess);
      instance.SetDestructor(&destruct_SUSYcLcLCrossSectionDBcLcLProcess);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SUSY::CrossSectionDB::Process*)
   {
      return GenerateInitInstanceLocal((::SUSY::CrossSectionDB::Process*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SUSY::CrossSectionDB::Process*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SUSYcLcLCrossSectionDBcLcLProcess_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SUSY::CrossSectionDB::Process*)0x0)->GetClass();
      SUSYcLcLCrossSectionDBcLcLProcess_TClassManip(theClass);
   return theClass;
   }

   static void SUSYcLcLCrossSectionDBcLcLProcess_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *pairlEfloatcOvectorlEfloatgRsPgR_Dictionary();
   static void pairlEfloatcOvectorlEfloatgRsPgR_TClassManip(TClass*);
   static void *new_pairlEfloatcOvectorlEfloatgRsPgR(void *p = 0);
   static void *newArray_pairlEfloatcOvectorlEfloatgRsPgR(Long_t size, void *p);
   static void delete_pairlEfloatcOvectorlEfloatgRsPgR(void *p);
   static void deleteArray_pairlEfloatcOvectorlEfloatgRsPgR(void *p);
   static void destruct_pairlEfloatcOvectorlEfloatgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const pair<float,vector<float> >*)
   {
      pair<float,vector<float> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(pair<float,vector<float> >));
      static ::ROOT::TGenericClassInfo 
         instance("pair<float,vector<float> >", "string", 96,
                  typeid(pair<float,vector<float> >), DefineBehavior(ptr, ptr),
                  &pairlEfloatcOvectorlEfloatgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(pair<float,vector<float> >) );
      instance.SetNew(&new_pairlEfloatcOvectorlEfloatgRsPgR);
      instance.SetNewArray(&newArray_pairlEfloatcOvectorlEfloatgRsPgR);
      instance.SetDelete(&delete_pairlEfloatcOvectorlEfloatgRsPgR);
      instance.SetDeleteArray(&deleteArray_pairlEfloatcOvectorlEfloatgRsPgR);
      instance.SetDestructor(&destruct_pairlEfloatcOvectorlEfloatgRsPgR);
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const pair<float,vector<float> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *pairlEfloatcOvectorlEfloatgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const pair<float,vector<float> >*)0x0)->GetClass();
      pairlEfloatcOvectorlEfloatgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void pairlEfloatcOvectorlEfloatgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *pairlEvectorlEfloatgRcOvectorlEfloatgRsPgR_Dictionary();
   static void pairlEvectorlEfloatgRcOvectorlEfloatgRsPgR_TClassManip(TClass*);
   static void *new_pairlEvectorlEfloatgRcOvectorlEfloatgRsPgR(void *p = 0);
   static void *newArray_pairlEvectorlEfloatgRcOvectorlEfloatgRsPgR(Long_t size, void *p);
   static void delete_pairlEvectorlEfloatgRcOvectorlEfloatgRsPgR(void *p);
   static void deleteArray_pairlEvectorlEfloatgRcOvectorlEfloatgRsPgR(void *p);
   static void destruct_pairlEvectorlEfloatgRcOvectorlEfloatgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const pair<vector<float>,vector<float> >*)
   {
      pair<vector<float>,vector<float> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(pair<vector<float>,vector<float> >));
      static ::ROOT::TGenericClassInfo 
         instance("pair<vector<float>,vector<float> >", "string", 96,
                  typeid(pair<vector<float>,vector<float> >), DefineBehavior(ptr, ptr),
                  &pairlEvectorlEfloatgRcOvectorlEfloatgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(pair<vector<float>,vector<float> >) );
      instance.SetNew(&new_pairlEvectorlEfloatgRcOvectorlEfloatgRsPgR);
      instance.SetNewArray(&newArray_pairlEvectorlEfloatgRcOvectorlEfloatgRsPgR);
      instance.SetDelete(&delete_pairlEvectorlEfloatgRcOvectorlEfloatgRsPgR);
      instance.SetDeleteArray(&deleteArray_pairlEvectorlEfloatgRcOvectorlEfloatgRsPgR);
      instance.SetDestructor(&destruct_pairlEvectorlEfloatgRcOvectorlEfloatgRsPgR);
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const pair<vector<float>,vector<float> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *pairlEvectorlEfloatgRcOvectorlEfloatgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const pair<vector<float>,vector<float> >*)0x0)->GetClass();
      pairlEvectorlEfloatgRcOvectorlEfloatgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void pairlEvectorlEfloatgRcOvectorlEfloatgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *pairlEintcOSUSYcLcLCrossSectionDBcLcLProcessgR_Dictionary();
   static void pairlEintcOSUSYcLcLCrossSectionDBcLcLProcessgR_TClassManip(TClass*);
   static void *new_pairlEintcOSUSYcLcLCrossSectionDBcLcLProcessgR(void *p = 0);
   static void *newArray_pairlEintcOSUSYcLcLCrossSectionDBcLcLProcessgR(Long_t size, void *p);
   static void delete_pairlEintcOSUSYcLcLCrossSectionDBcLcLProcessgR(void *p);
   static void deleteArray_pairlEintcOSUSYcLcLCrossSectionDBcLcLProcessgR(void *p);
   static void destruct_pairlEintcOSUSYcLcLCrossSectionDBcLcLProcessgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const pair<int,SUSY::CrossSectionDB::Process>*)
   {
      pair<int,SUSY::CrossSectionDB::Process> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(pair<int,SUSY::CrossSectionDB::Process>));
      static ::ROOT::TGenericClassInfo 
         instance("pair<int,SUSY::CrossSectionDB::Process>", "string", 96,
                  typeid(pair<int,SUSY::CrossSectionDB::Process>), DefineBehavior(ptr, ptr),
                  &pairlEintcOSUSYcLcLCrossSectionDBcLcLProcessgR_Dictionary, isa_proxy, 4,
                  sizeof(pair<int,SUSY::CrossSectionDB::Process>) );
      instance.SetNew(&new_pairlEintcOSUSYcLcLCrossSectionDBcLcLProcessgR);
      instance.SetNewArray(&newArray_pairlEintcOSUSYcLcLCrossSectionDBcLcLProcessgR);
      instance.SetDelete(&delete_pairlEintcOSUSYcLcLCrossSectionDBcLcLProcessgR);
      instance.SetDeleteArray(&deleteArray_pairlEintcOSUSYcLcLCrossSectionDBcLcLProcessgR);
      instance.SetDestructor(&destruct_pairlEintcOSUSYcLcLCrossSectionDBcLcLProcessgR);
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const pair<int,SUSY::CrossSectionDB::Process>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *pairlEintcOSUSYcLcLCrossSectionDBcLcLProcessgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const pair<int,SUSY::CrossSectionDB::Process>*)0x0)->GetClass();
      pairlEintcOSUSYcLcLCrossSectionDBcLcLProcessgR_TClassManip(theClass);
   return theClass;
   }

   static void pairlEintcOSUSYcLcLCrossSectionDBcLcLProcessgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *_Rb_tree_const_iteratorlEpairlEconstsPSUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgRsPgR_Dictionary();
   static void _Rb_tree_const_iteratorlEpairlEconstsPSUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgRsPgR_TClassManip(TClass*);
   static void *new__Rb_tree_const_iteratorlEpairlEconstsPSUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgRsPgR(void *p = 0);
   static void *newArray__Rb_tree_const_iteratorlEpairlEconstsPSUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgRsPgR(Long_t size, void *p);
   static void delete__Rb_tree_const_iteratorlEpairlEconstsPSUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgRsPgR(void *p);
   static void deleteArray__Rb_tree_const_iteratorlEpairlEconstsPSUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgRsPgR(void *p);
   static void destruct__Rb_tree_const_iteratorlEpairlEconstsPSUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::_Rb_tree_const_iterator<pair<const SUSY::CrossSectionDB::Key,SUSY::CrossSectionDB::Process> >*)
   {
      ::_Rb_tree_const_iterator<pair<const SUSY::CrossSectionDB::Key,SUSY::CrossSectionDB::Process> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::_Rb_tree_const_iterator<pair<const SUSY::CrossSectionDB::Key,SUSY::CrossSectionDB::Process> >));
      static ::ROOT::TGenericClassInfo 
         instance("_Rb_tree_const_iterator<pair<const SUSY::CrossSectionDB::Key,SUSY::CrossSectionDB::Process> >", "map", 242,
                  typeid(::_Rb_tree_const_iterator<pair<const SUSY::CrossSectionDB::Key,SUSY::CrossSectionDB::Process> >), DefineBehavior(ptr, ptr),
                  &_Rb_tree_const_iteratorlEpairlEconstsPSUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgRsPgR_Dictionary, isa_proxy, 1,
                  sizeof(::_Rb_tree_const_iterator<pair<const SUSY::CrossSectionDB::Key,SUSY::CrossSectionDB::Process> >) );
      instance.SetNew(&new__Rb_tree_const_iteratorlEpairlEconstsPSUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgRsPgR);
      instance.SetNewArray(&newArray__Rb_tree_const_iteratorlEpairlEconstsPSUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgRsPgR);
      instance.SetDelete(&delete__Rb_tree_const_iteratorlEpairlEconstsPSUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgRsPgR);
      instance.SetDeleteArray(&deleteArray__Rb_tree_const_iteratorlEpairlEconstsPSUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgRsPgR);
      instance.SetDestructor(&destruct__Rb_tree_const_iteratorlEpairlEconstsPSUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgRsPgR);

      ::ROOT::AddClassAlternate("_Rb_tree_const_iterator<pair<const SUSY::CrossSectionDB::Key,SUSY::CrossSectionDB::Process> >","SUSY::CrossSectionDB::iterator");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::_Rb_tree_const_iterator<pair<const SUSY::CrossSectionDB::Key,SUSY::CrossSectionDB::Process> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *_Rb_tree_const_iteratorlEpairlEconstsPSUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::_Rb_tree_const_iterator<pair<const SUSY::CrossSectionDB::Key,SUSY::CrossSectionDB::Process> >*)0x0)->GetClass();
      _Rb_tree_const_iteratorlEpairlEconstsPSUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void _Rb_tree_const_iteratorlEpairlEconstsPSUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgRsPgR_TClassManip(TClass* ){
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
   // Wrappers around operator new
   static void *new_SUSYcLcLCrossSectionDB(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SUSY::CrossSectionDB : new ::SUSY::CrossSectionDB;
   }
   static void *newArray_SUSYcLcLCrossSectionDB(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SUSY::CrossSectionDB[nElements] : new ::SUSY::CrossSectionDB[nElements];
   }
   // Wrapper around operator delete
   static void delete_SUSYcLcLCrossSectionDB(void *p) {
      delete ((::SUSY::CrossSectionDB*)p);
   }
   static void deleteArray_SUSYcLcLCrossSectionDB(void *p) {
      delete [] ((::SUSY::CrossSectionDB*)p);
   }
   static void destruct_SUSYcLcLCrossSectionDB(void *p) {
      typedef ::SUSY::CrossSectionDB current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SUSY::CrossSectionDB

namespace ROOT {
   // Wrappers around operator new
   static void *new_SUSYcLcLCrossSectionDBcLcLProcess(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SUSY::CrossSectionDB::Process : new ::SUSY::CrossSectionDB::Process;
   }
   static void *newArray_SUSYcLcLCrossSectionDBcLcLProcess(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SUSY::CrossSectionDB::Process[nElements] : new ::SUSY::CrossSectionDB::Process[nElements];
   }
   // Wrapper around operator delete
   static void delete_SUSYcLcLCrossSectionDBcLcLProcess(void *p) {
      delete ((::SUSY::CrossSectionDB::Process*)p);
   }
   static void deleteArray_SUSYcLcLCrossSectionDBcLcLProcess(void *p) {
      delete [] ((::SUSY::CrossSectionDB::Process*)p);
   }
   static void destruct_SUSYcLcLCrossSectionDBcLcLProcess(void *p) {
      typedef ::SUSY::CrossSectionDB::Process current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SUSY::CrossSectionDB::Process

namespace ROOT {
   // Wrappers around operator new
   static void *new_pairlEfloatcOvectorlEfloatgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) pair<float,vector<float> > : new pair<float,vector<float> >;
   }
   static void *newArray_pairlEfloatcOvectorlEfloatgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) pair<float,vector<float> >[nElements] : new pair<float,vector<float> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_pairlEfloatcOvectorlEfloatgRsPgR(void *p) {
      delete ((pair<float,vector<float> >*)p);
   }
   static void deleteArray_pairlEfloatcOvectorlEfloatgRsPgR(void *p) {
      delete [] ((pair<float,vector<float> >*)p);
   }
   static void destruct_pairlEfloatcOvectorlEfloatgRsPgR(void *p) {
      typedef pair<float,vector<float> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class pair<float,vector<float> >

namespace ROOT {
   // Wrappers around operator new
   static void *new_pairlEvectorlEfloatgRcOvectorlEfloatgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) pair<vector<float>,vector<float> > : new pair<vector<float>,vector<float> >;
   }
   static void *newArray_pairlEvectorlEfloatgRcOvectorlEfloatgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) pair<vector<float>,vector<float> >[nElements] : new pair<vector<float>,vector<float> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_pairlEvectorlEfloatgRcOvectorlEfloatgRsPgR(void *p) {
      delete ((pair<vector<float>,vector<float> >*)p);
   }
   static void deleteArray_pairlEvectorlEfloatgRcOvectorlEfloatgRsPgR(void *p) {
      delete [] ((pair<vector<float>,vector<float> >*)p);
   }
   static void destruct_pairlEvectorlEfloatgRcOvectorlEfloatgRsPgR(void *p) {
      typedef pair<vector<float>,vector<float> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class pair<vector<float>,vector<float> >

namespace ROOT {
   // Wrappers around operator new
   static void *new_pairlEintcOSUSYcLcLCrossSectionDBcLcLProcessgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) pair<int,SUSY::CrossSectionDB::Process> : new pair<int,SUSY::CrossSectionDB::Process>;
   }
   static void *newArray_pairlEintcOSUSYcLcLCrossSectionDBcLcLProcessgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) pair<int,SUSY::CrossSectionDB::Process>[nElements] : new pair<int,SUSY::CrossSectionDB::Process>[nElements];
   }
   // Wrapper around operator delete
   static void delete_pairlEintcOSUSYcLcLCrossSectionDBcLcLProcessgR(void *p) {
      delete ((pair<int,SUSY::CrossSectionDB::Process>*)p);
   }
   static void deleteArray_pairlEintcOSUSYcLcLCrossSectionDBcLcLProcessgR(void *p) {
      delete [] ((pair<int,SUSY::CrossSectionDB::Process>*)p);
   }
   static void destruct_pairlEintcOSUSYcLcLCrossSectionDBcLcLProcessgR(void *p) {
      typedef pair<int,SUSY::CrossSectionDB::Process> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class pair<int,SUSY::CrossSectionDB::Process>

namespace ROOT {
   // Wrappers around operator new
   static void *new__Rb_tree_const_iteratorlEpairlEconstsPSUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::_Rb_tree_const_iterator<pair<const SUSY::CrossSectionDB::Key,SUSY::CrossSectionDB::Process> > : new ::_Rb_tree_const_iterator<pair<const SUSY::CrossSectionDB::Key,SUSY::CrossSectionDB::Process> >;
   }
   static void *newArray__Rb_tree_const_iteratorlEpairlEconstsPSUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::_Rb_tree_const_iterator<pair<const SUSY::CrossSectionDB::Key,SUSY::CrossSectionDB::Process> >[nElements] : new ::_Rb_tree_const_iterator<pair<const SUSY::CrossSectionDB::Key,SUSY::CrossSectionDB::Process> >[nElements];
   }
   // Wrapper around operator delete
   static void delete__Rb_tree_const_iteratorlEpairlEconstsPSUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgRsPgR(void *p) {
      delete ((::_Rb_tree_const_iterator<pair<const SUSY::CrossSectionDB::Key,SUSY::CrossSectionDB::Process> >*)p);
   }
   static void deleteArray__Rb_tree_const_iteratorlEpairlEconstsPSUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgRsPgR(void *p) {
      delete [] ((::_Rb_tree_const_iterator<pair<const SUSY::CrossSectionDB::Key,SUSY::CrossSectionDB::Process> >*)p);
   }
   static void destruct__Rb_tree_const_iteratorlEpairlEconstsPSUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgRsPgR(void *p) {
      typedef ::_Rb_tree_const_iterator<pair<const SUSY::CrossSectionDB::Key,SUSY::CrossSectionDB::Process> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::_Rb_tree_const_iterator<pair<const SUSY::CrossSectionDB::Key,SUSY::CrossSectionDB::Process> >

namespace ROOT {
   static TClass *vectorlEvectorlEunsignedsPintgRsPgR_Dictionary();
   static void vectorlEvectorlEunsignedsPintgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlEunsignedsPintgRsPgR(void *p = 0);
   static void *newArray_vectorlEvectorlEunsignedsPintgRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlEunsignedsPintgRsPgR(void *p);
   static void deleteArray_vectorlEvectorlEunsignedsPintgRsPgR(void *p);
   static void destruct_vectorlEvectorlEunsignedsPintgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<unsigned int> >*)
   {
      vector<vector<unsigned int> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<unsigned int> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<unsigned int> >", -2, "vector", 214,
                  typeid(vector<vector<unsigned int> >), DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEunsignedsPintgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<vector<unsigned int> >) );
      instance.SetNew(&new_vectorlEvectorlEunsignedsPintgRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlEunsignedsPintgRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlEunsignedsPintgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlEunsignedsPintgRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlEunsignedsPintgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<unsigned int> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<vector<unsigned int> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlEunsignedsPintgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<vector<unsigned int> >*)0x0)->GetClass();
      vectorlEvectorlEunsignedsPintgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlEunsignedsPintgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlEunsignedsPintgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<vector<unsigned int> > : new vector<vector<unsigned int> >;
   }
   static void *newArray_vectorlEvectorlEunsignedsPintgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<vector<unsigned int> >[nElements] : new vector<vector<unsigned int> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlEunsignedsPintgRsPgR(void *p) {
      delete ((vector<vector<unsigned int> >*)p);
   }
   static void deleteArray_vectorlEvectorlEunsignedsPintgRsPgR(void *p) {
      delete [] ((vector<vector<unsigned int> >*)p);
   }
   static void destruct_vectorlEvectorlEunsignedsPintgRsPgR(void *p) {
      typedef vector<vector<unsigned int> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<vector<unsigned int> >

namespace ROOT {
   static TClass *vectorlEvectorlEintgRsPgR_Dictionary();
   static void vectorlEvectorlEintgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlEintgRsPgR(void *p = 0);
   static void *newArray_vectorlEvectorlEintgRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlEintgRsPgR(void *p);
   static void deleteArray_vectorlEvectorlEintgRsPgR(void *p);
   static void destruct_vectorlEvectorlEintgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<int> >*)
   {
      vector<vector<int> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<int> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<int> >", -2, "vector", 214,
                  typeid(vector<vector<int> >), DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEintgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<vector<int> >) );
      instance.SetNew(&new_vectorlEvectorlEintgRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlEintgRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlEintgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlEintgRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlEintgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<int> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<vector<int> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlEintgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<vector<int> >*)0x0)->GetClass();
      vectorlEvectorlEintgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlEintgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlEintgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<vector<int> > : new vector<vector<int> >;
   }
   static void *newArray_vectorlEvectorlEintgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<vector<int> >[nElements] : new vector<vector<int> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlEintgRsPgR(void *p) {
      delete ((vector<vector<int> >*)p);
   }
   static void deleteArray_vectorlEvectorlEintgRsPgR(void *p) {
      delete [] ((vector<vector<int> >*)p);
   }
   static void destruct_vectorlEvectorlEintgRsPgR(void *p) {
      typedef vector<vector<int> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<vector<int> >

namespace ROOT {
   static TClass *vectorlEvectorlEfloatgRsPgR_Dictionary();
   static void vectorlEvectorlEfloatgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlEfloatgRsPgR(void *p = 0);
   static void *newArray_vectorlEvectorlEfloatgRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlEfloatgRsPgR(void *p);
   static void deleteArray_vectorlEvectorlEfloatgRsPgR(void *p);
   static void destruct_vectorlEvectorlEfloatgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<float> >*)
   {
      vector<vector<float> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<float> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<float> >", -2, "vector", 214,
                  typeid(vector<vector<float> >), DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEfloatgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<vector<float> >) );
      instance.SetNew(&new_vectorlEvectorlEfloatgRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlEfloatgRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlEfloatgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlEfloatgRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlEfloatgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<float> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<vector<float> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlEfloatgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<vector<float> >*)0x0)->GetClass();
      vectorlEvectorlEfloatgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlEfloatgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlEfloatgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<vector<float> > : new vector<vector<float> >;
   }
   static void *newArray_vectorlEvectorlEfloatgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<vector<float> >[nElements] : new vector<vector<float> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlEfloatgRsPgR(void *p) {
      delete ((vector<vector<float> >*)p);
   }
   static void deleteArray_vectorlEvectorlEfloatgRsPgR(void *p) {
      delete [] ((vector<vector<float> >*)p);
   }
   static void destruct_vectorlEvectorlEfloatgRsPgR(void *p) {
      typedef vector<vector<float> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<vector<float> >

namespace ROOT {
   static TClass *vectorlEvectorlEdoublegRsPgR_Dictionary();
   static void vectorlEvectorlEdoublegRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlEdoublegRsPgR(void *p = 0);
   static void *newArray_vectorlEvectorlEdoublegRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlEdoublegRsPgR(void *p);
   static void deleteArray_vectorlEvectorlEdoublegRsPgR(void *p);
   static void destruct_vectorlEvectorlEdoublegRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<double> >*)
   {
      vector<vector<double> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<double> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<double> >", -2, "vector", 214,
                  typeid(vector<vector<double> >), DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEdoublegRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<vector<double> >) );
      instance.SetNew(&new_vectorlEvectorlEdoublegRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlEdoublegRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlEdoublegRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlEdoublegRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlEdoublegRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<double> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<vector<double> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlEdoublegRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<vector<double> >*)0x0)->GetClass();
      vectorlEvectorlEdoublegRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlEdoublegRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlEdoublegRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<vector<double> > : new vector<vector<double> >;
   }
   static void *newArray_vectorlEvectorlEdoublegRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<vector<double> >[nElements] : new vector<vector<double> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlEdoublegRsPgR(void *p) {
      delete ((vector<vector<double> >*)p);
   }
   static void deleteArray_vectorlEvectorlEdoublegRsPgR(void *p) {
      delete [] ((vector<vector<double> >*)p);
   }
   static void destruct_vectorlEvectorlEdoublegRsPgR(void *p) {
      typedef vector<vector<double> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<vector<double> >

namespace ROOT {
   static TClass *vectorlEunsignedsPintgR_Dictionary();
   static void vectorlEunsignedsPintgR_TClassManip(TClass*);
   static void *new_vectorlEunsignedsPintgR(void *p = 0);
   static void *newArray_vectorlEunsignedsPintgR(Long_t size, void *p);
   static void delete_vectorlEunsignedsPintgR(void *p);
   static void deleteArray_vectorlEunsignedsPintgR(void *p);
   static void destruct_vectorlEunsignedsPintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<unsigned int>*)
   {
      vector<unsigned int> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<unsigned int>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<unsigned int>", -2, "vector", 214,
                  typeid(vector<unsigned int>), DefineBehavior(ptr, ptr),
                  &vectorlEunsignedsPintgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<unsigned int>) );
      instance.SetNew(&new_vectorlEunsignedsPintgR);
      instance.SetNewArray(&newArray_vectorlEunsignedsPintgR);
      instance.SetDelete(&delete_vectorlEunsignedsPintgR);
      instance.SetDeleteArray(&deleteArray_vectorlEunsignedsPintgR);
      instance.SetDestructor(&destruct_vectorlEunsignedsPintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<unsigned int> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<unsigned int>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEunsignedsPintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<unsigned int>*)0x0)->GetClass();
      vectorlEunsignedsPintgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEunsignedsPintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEunsignedsPintgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<unsigned int> : new vector<unsigned int>;
   }
   static void *newArray_vectorlEunsignedsPintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<unsigned int>[nElements] : new vector<unsigned int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEunsignedsPintgR(void *p) {
      delete ((vector<unsigned int>*)p);
   }
   static void deleteArray_vectorlEunsignedsPintgR(void *p) {
      delete [] ((vector<unsigned int>*)p);
   }
   static void destruct_vectorlEunsignedsPintgR(void *p) {
      typedef vector<unsigned int> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<unsigned int>

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
   static TClass *vectorlEintgR_Dictionary();
   static void vectorlEintgR_TClassManip(TClass*);
   static void *new_vectorlEintgR(void *p = 0);
   static void *newArray_vectorlEintgR(Long_t size, void *p);
   static void delete_vectorlEintgR(void *p);
   static void deleteArray_vectorlEintgR(void *p);
   static void destruct_vectorlEintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<int>*)
   {
      vector<int> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<int>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<int>", -2, "vector", 214,
                  typeid(vector<int>), DefineBehavior(ptr, ptr),
                  &vectorlEintgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<int>) );
      instance.SetNew(&new_vectorlEintgR);
      instance.SetNewArray(&newArray_vectorlEintgR);
      instance.SetDelete(&delete_vectorlEintgR);
      instance.SetDeleteArray(&deleteArray_vectorlEintgR);
      instance.SetDestructor(&destruct_vectorlEintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<int> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<int>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<int>*)0x0)->GetClass();
      vectorlEintgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEintgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<int> : new vector<int>;
   }
   static void *newArray_vectorlEintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<int>[nElements] : new vector<int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEintgR(void *p) {
      delete ((vector<int>*)p);
   }
   static void deleteArray_vectorlEintgR(void *p) {
      delete [] ((vector<int>*)p);
   }
   static void destruct_vectorlEintgR(void *p) {
      typedef vector<int> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<int>

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
                  &vectorlEfloatgR_Dictionary, isa_proxy, 4,
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
                  &vectorlEdoublegR_Dictionary, isa_proxy, 4,
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
   static TClass *maplEstringcOstringgR_Dictionary();
   static void maplEstringcOstringgR_TClassManip(TClass*);
   static void *new_maplEstringcOstringgR(void *p = 0);
   static void *newArray_maplEstringcOstringgR(Long_t size, void *p);
   static void delete_maplEstringcOstringgR(void *p);
   static void deleteArray_maplEstringcOstringgR(void *p);
   static void destruct_maplEstringcOstringgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<string,string>*)
   {
      map<string,string> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<string,string>));
      static ::ROOT::TGenericClassInfo 
         instance("map<string,string>", -2, "map", 96,
                  typeid(map<string,string>), DefineBehavior(ptr, ptr),
                  &maplEstringcOstringgR_Dictionary, isa_proxy, 0,
                  sizeof(map<string,string>) );
      instance.SetNew(&new_maplEstringcOstringgR);
      instance.SetNewArray(&newArray_maplEstringcOstringgR);
      instance.SetDelete(&delete_maplEstringcOstringgR);
      instance.SetDeleteArray(&deleteArray_maplEstringcOstringgR);
      instance.SetDestructor(&destruct_maplEstringcOstringgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<string,string> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<string,string>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEstringcOstringgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<string,string>*)0x0)->GetClass();
      maplEstringcOstringgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEstringcOstringgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEstringcOstringgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) map<string,string> : new map<string,string>;
   }
   static void *newArray_maplEstringcOstringgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) map<string,string>[nElements] : new map<string,string>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEstringcOstringgR(void *p) {
      delete ((map<string,string>*)p);
   }
   static void deleteArray_maplEstringcOstringgR(void *p) {
      delete [] ((map<string,string>*)p);
   }
   static void destruct_maplEstringcOstringgR(void *p) {
      typedef map<string,string> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<string,string>

namespace ROOT {
   static TClass *maplEstringcOfunctionlEbooloPcPgRsPgR_Dictionary();
   static void maplEstringcOfunctionlEbooloPcPgRsPgR_TClassManip(TClass*);
   static void *new_maplEstringcOfunctionlEbooloPcPgRsPgR(void *p = 0);
   static void *newArray_maplEstringcOfunctionlEbooloPcPgRsPgR(Long_t size, void *p);
   static void delete_maplEstringcOfunctionlEbooloPcPgRsPgR(void *p);
   static void deleteArray_maplEstringcOfunctionlEbooloPcPgRsPgR(void *p);
   static void destruct_maplEstringcOfunctionlEbooloPcPgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<string,function<bool()> >*)
   {
      map<string,function<bool()> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<string,function<bool()> >));
      static ::ROOT::TGenericClassInfo 
         instance("map<string,function<bool()> >", -2, "map", 96,
                  typeid(map<string,function<bool()> >), DefineBehavior(ptr, ptr),
                  &maplEstringcOfunctionlEbooloPcPgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(map<string,function<bool()> >) );
      instance.SetNew(&new_maplEstringcOfunctionlEbooloPcPgRsPgR);
      instance.SetNewArray(&newArray_maplEstringcOfunctionlEbooloPcPgRsPgR);
      instance.SetDelete(&delete_maplEstringcOfunctionlEbooloPcPgRsPgR);
      instance.SetDeleteArray(&deleteArray_maplEstringcOfunctionlEbooloPcPgRsPgR);
      instance.SetDestructor(&destruct_maplEstringcOfunctionlEbooloPcPgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<string,function<bool()> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<string,function<bool()> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEstringcOfunctionlEbooloPcPgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<string,function<bool()> >*)0x0)->GetClass();
      maplEstringcOfunctionlEbooloPcPgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEstringcOfunctionlEbooloPcPgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEstringcOfunctionlEbooloPcPgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) map<string,function<bool()> > : new map<string,function<bool()> >;
   }
   static void *newArray_maplEstringcOfunctionlEbooloPcPgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) map<string,function<bool()> >[nElements] : new map<string,function<bool()> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEstringcOfunctionlEbooloPcPgRsPgR(void *p) {
      delete ((map<string,function<bool()> >*)p);
   }
   static void deleteArray_maplEstringcOfunctionlEbooloPcPgRsPgR(void *p) {
      delete [] ((map<string,function<bool()> >*)p);
   }
   static void destruct_maplEstringcOfunctionlEbooloPcPgRsPgR(void *p) {
      typedef map<string,function<bool()> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<string,function<bool()> >

namespace ROOT {
   static TClass *maplEstringcOboolgR_Dictionary();
   static void maplEstringcOboolgR_TClassManip(TClass*);
   static void *new_maplEstringcOboolgR(void *p = 0);
   static void *newArray_maplEstringcOboolgR(Long_t size, void *p);
   static void delete_maplEstringcOboolgR(void *p);
   static void deleteArray_maplEstringcOboolgR(void *p);
   static void destruct_maplEstringcOboolgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<string,bool>*)
   {
      map<string,bool> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<string,bool>));
      static ::ROOT::TGenericClassInfo 
         instance("map<string,bool>", -2, "map", 96,
                  typeid(map<string,bool>), DefineBehavior(ptr, ptr),
                  &maplEstringcOboolgR_Dictionary, isa_proxy, 0,
                  sizeof(map<string,bool>) );
      instance.SetNew(&new_maplEstringcOboolgR);
      instance.SetNewArray(&newArray_maplEstringcOboolgR);
      instance.SetDelete(&delete_maplEstringcOboolgR);
      instance.SetDeleteArray(&deleteArray_maplEstringcOboolgR);
      instance.SetDestructor(&destruct_maplEstringcOboolgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<string,bool> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<string,bool>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEstringcOboolgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<string,bool>*)0x0)->GetClass();
      maplEstringcOboolgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEstringcOboolgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEstringcOboolgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) map<string,bool> : new map<string,bool>;
   }
   static void *newArray_maplEstringcOboolgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) map<string,bool>[nElements] : new map<string,bool>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEstringcOboolgR(void *p) {
      delete ((map<string,bool>*)p);
   }
   static void deleteArray_maplEstringcOboolgR(void *p) {
      delete [] ((map<string,bool>*)p);
   }
   static void destruct_maplEstringcOboolgR(void *p) {
      typedef map<string,bool> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<string,bool>

namespace ROOT {
   static TClass *maplEintcOSUSYcLcLCrossSectionDBcLcLProcessgR_Dictionary();
   static void maplEintcOSUSYcLcLCrossSectionDBcLcLProcessgR_TClassManip(TClass*);
   static void *new_maplEintcOSUSYcLcLCrossSectionDBcLcLProcessgR(void *p = 0);
   static void *newArray_maplEintcOSUSYcLcLCrossSectionDBcLcLProcessgR(Long_t size, void *p);
   static void delete_maplEintcOSUSYcLcLCrossSectionDBcLcLProcessgR(void *p);
   static void deleteArray_maplEintcOSUSYcLcLCrossSectionDBcLcLProcessgR(void *p);
   static void destruct_maplEintcOSUSYcLcLCrossSectionDBcLcLProcessgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<int,SUSY::CrossSectionDB::Process>*)
   {
      map<int,SUSY::CrossSectionDB::Process> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<int,SUSY::CrossSectionDB::Process>));
      static ::ROOT::TGenericClassInfo 
         instance("map<int,SUSY::CrossSectionDB::Process>", -2, "map", 96,
                  typeid(map<int,SUSY::CrossSectionDB::Process>), DefineBehavior(ptr, ptr),
                  &maplEintcOSUSYcLcLCrossSectionDBcLcLProcessgR_Dictionary, isa_proxy, 4,
                  sizeof(map<int,SUSY::CrossSectionDB::Process>) );
      instance.SetNew(&new_maplEintcOSUSYcLcLCrossSectionDBcLcLProcessgR);
      instance.SetNewArray(&newArray_maplEintcOSUSYcLcLCrossSectionDBcLcLProcessgR);
      instance.SetDelete(&delete_maplEintcOSUSYcLcLCrossSectionDBcLcLProcessgR);
      instance.SetDeleteArray(&deleteArray_maplEintcOSUSYcLcLCrossSectionDBcLcLProcessgR);
      instance.SetDestructor(&destruct_maplEintcOSUSYcLcLCrossSectionDBcLcLProcessgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<int,SUSY::CrossSectionDB::Process> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<int,SUSY::CrossSectionDB::Process>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEintcOSUSYcLcLCrossSectionDBcLcLProcessgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<int,SUSY::CrossSectionDB::Process>*)0x0)->GetClass();
      maplEintcOSUSYcLcLCrossSectionDBcLcLProcessgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEintcOSUSYcLcLCrossSectionDBcLcLProcessgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEintcOSUSYcLcLCrossSectionDBcLcLProcessgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) map<int,SUSY::CrossSectionDB::Process> : new map<int,SUSY::CrossSectionDB::Process>;
   }
   static void *newArray_maplEintcOSUSYcLcLCrossSectionDBcLcLProcessgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) map<int,SUSY::CrossSectionDB::Process>[nElements] : new map<int,SUSY::CrossSectionDB::Process>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEintcOSUSYcLcLCrossSectionDBcLcLProcessgR(void *p) {
      delete ((map<int,SUSY::CrossSectionDB::Process>*)p);
   }
   static void deleteArray_maplEintcOSUSYcLcLCrossSectionDBcLcLProcessgR(void *p) {
      delete [] ((map<int,SUSY::CrossSectionDB::Process>*)p);
   }
   static void destruct_maplEintcOSUSYcLcLCrossSectionDBcLcLProcessgR(void *p) {
      typedef map<int,SUSY::CrossSectionDB::Process> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<int,SUSY::CrossSectionDB::Process>

namespace ROOT {
   static TClass *maplESUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgR_Dictionary();
   static void maplESUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgR_TClassManip(TClass*);
   static void *new_maplESUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgR(void *p = 0);
   static void *newArray_maplESUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgR(Long_t size, void *p);
   static void delete_maplESUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgR(void *p);
   static void deleteArray_maplESUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgR(void *p);
   static void destruct_maplESUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<SUSY::CrossSectionDB::Key,SUSY::CrossSectionDB::Process>*)
   {
      map<SUSY::CrossSectionDB::Key,SUSY::CrossSectionDB::Process> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<SUSY::CrossSectionDB::Key,SUSY::CrossSectionDB::Process>));
      static ::ROOT::TGenericClassInfo 
         instance("map<SUSY::CrossSectionDB::Key,SUSY::CrossSectionDB::Process>", -2, "map", 96,
                  typeid(map<SUSY::CrossSectionDB::Key,SUSY::CrossSectionDB::Process>), DefineBehavior(ptr, ptr),
                  &maplESUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgR_Dictionary, isa_proxy, 0,
                  sizeof(map<SUSY::CrossSectionDB::Key,SUSY::CrossSectionDB::Process>) );
      instance.SetNew(&new_maplESUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgR);
      instance.SetNewArray(&newArray_maplESUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgR);
      instance.SetDelete(&delete_maplESUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgR);
      instance.SetDeleteArray(&deleteArray_maplESUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgR);
      instance.SetDestructor(&destruct_maplESUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<SUSY::CrossSectionDB::Key,SUSY::CrossSectionDB::Process> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<SUSY::CrossSectionDB::Key,SUSY::CrossSectionDB::Process>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplESUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<SUSY::CrossSectionDB::Key,SUSY::CrossSectionDB::Process>*)0x0)->GetClass();
      maplESUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgR_TClassManip(theClass);
   return theClass;
   }

   static void maplESUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplESUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) map<SUSY::CrossSectionDB::Key,SUSY::CrossSectionDB::Process> : new map<SUSY::CrossSectionDB::Key,SUSY::CrossSectionDB::Process>;
   }
   static void *newArray_maplESUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) map<SUSY::CrossSectionDB::Key,SUSY::CrossSectionDB::Process>[nElements] : new map<SUSY::CrossSectionDB::Key,SUSY::CrossSectionDB::Process>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplESUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgR(void *p) {
      delete ((map<SUSY::CrossSectionDB::Key,SUSY::CrossSectionDB::Process>*)p);
   }
   static void deleteArray_maplESUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgR(void *p) {
      delete [] ((map<SUSY::CrossSectionDB::Key,SUSY::CrossSectionDB::Process>*)p);
   }
   static void destruct_maplESUSYcLcLCrossSectionDBcLcLKeycOSUSYcLcLCrossSectionDBcLcLProcessgR(void *p) {
      typedef map<SUSY::CrossSectionDB::Key,SUSY::CrossSectionDB::Process> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<SUSY::CrossSectionDB::Key,SUSY::CrossSectionDB::Process>

namespace {
  void TriggerDictionaryInitialization_SUSYToolsCINT_Impl() {
    static const char* headers[] = {
"SUSYTools/SUSYCrossSection.h",
"SUSYTools/SUSYObjDef_xAOD.h",
0
    };
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
namespace ST{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/SUSYTools/Root/LinkDef.h")))  SUSYObjDef_xAOD;}
namespace SUSY{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/SUSYTools/Root/LinkDef.h")))  CrossSectionDB;}
namespace std{template <typename _Tp> class __attribute__((annotate("$clingAutoload$string")))  allocator;
}
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
#include "SUSYTools/SUSYCrossSection.h"
#include "SUSYTools/SUSYObjDef_xAOD.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"ST::SUSYObjDef_xAOD", payloadCode, "@",
"SUSY::CrossSectionDB", payloadCode, "@",
"SUSY::CrossSectionDB::Process", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("SUSYToolsCINT",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_SUSYToolsCINT_Impl, {{"namespace DataVector_detail { template <typename B1, typename B2, typename B3> class VirtBases; }", 1},{"template <typename T> class DataVectorBase;", 1},{"template <typename T, typename BASE> class DataVector;", 1},{"namespace DataVector_detail { template <typename T> class DVLEltBaseInit; }", 1}}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_SUSYToolsCINT_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_SUSYToolsCINT() {
  TriggerDictionaryInitialization_SUSYToolsCINT_Impl();
}
