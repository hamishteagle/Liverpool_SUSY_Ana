// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIuserdIhteagledIAnalysisDirectorydIBase_2_4_34dIRootCoreBindIobjdIx86_64mIslc6mIgcc49mIoptdITrigDecisionTooldIobjdITrigDecisionTool_Reflex

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
#include "/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/TrigDecisionTool/TrigDecisionTool/TrigDecisionToolDict.h"

// Header files passed via #pragma extra_include

namespace TrigDefs {
   namespace ROOT {
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance();
      static TClass *TrigDefs_Dictionary();

      // Function generating the singleton type initializer
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance()
      {
         static ::ROOT::TGenericClassInfo 
            instance("TrigDefs", 0 /*version*/, "TrigDecisionInterface/Conditions.h", 15,
                     ::ROOT::DefineBehavior((void*)0,(void*)0),
                     &TrigDefs_Dictionary, 0);
         return &instance;
      }
      // Insure that the inline function is _not_ optimized away by the compiler
      ::ROOT::TGenericClassInfo *(*_R__UNIQUE_(InitFunctionKeeper))() = &GenerateInitInstance;  
      // Static variable to force the class initialization
      static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstance(); R__UseDummy(_R__UNIQUE_(Init));

      // Dictionary for non-ClassDef classes
      static TClass *TrigDefs_Dictionary() {
         return GenerateInitInstance()->GetClass();
      }

   }
}

namespace ROOT {
   static TClass *TrigcLcLLogger_Dictionary();
   static void TrigcLcLLogger_TClassManip(TClass*);
   static void *new_TrigcLcLLogger(void *p = 0);
   static void *newArray_TrigcLcLLogger(Long_t size, void *p);
   static void delete_TrigcLcLLogger(void *p);
   static void deleteArray_TrigcLcLLogger(void *p);
   static void destruct_TrigcLcLLogger(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Trig::Logger*)
   {
      ::Trig::Logger *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Trig::Logger));
      static ::ROOT::TGenericClassInfo 
         instance("Trig::Logger", "TrigDecisionTool/Logger.h", 27,
                  typeid(::Trig::Logger), DefineBehavior(ptr, ptr),
                  &TrigcLcLLogger_Dictionary, isa_proxy, 0,
                  sizeof(::Trig::Logger) );
      instance.SetNew(&new_TrigcLcLLogger);
      instance.SetNewArray(&newArray_TrigcLcLLogger);
      instance.SetDelete(&delete_TrigcLcLLogger);
      instance.SetDeleteArray(&deleteArray_TrigcLcLLogger);
      instance.SetDestructor(&destruct_TrigcLcLLogger);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Trig::Logger*)
   {
      return GenerateInitInstanceLocal((::Trig::Logger*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::Trig::Logger*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TrigcLcLLogger_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Trig::Logger*)0x0)->GetClass();
      TrigcLcLLogger_TClassManip(theClass);
   return theClass;
   }

   static void TrigcLcLLogger_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TrigcLcLChainGroup_Dictionary();
   static void TrigcLcLChainGroup_TClassManip(TClass*);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Trig::ChainGroup*)
   {
      ::Trig::ChainGroup *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Trig::ChainGroup));
      static ::ROOT::TGenericClassInfo 
         instance("Trig::ChainGroup", "TrigDecisionTool/ChainGroup.h", 51,
                  typeid(::Trig::ChainGroup), DefineBehavior(ptr, ptr),
                  &TrigcLcLChainGroup_Dictionary, isa_proxy, 0,
                  sizeof(::Trig::ChainGroup) );
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Trig::ChainGroup*)
   {
      return GenerateInitInstanceLocal((::Trig::ChainGroup*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::Trig::ChainGroup*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TrigcLcLChainGroup_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Trig::ChainGroup*)0x0)->GetClass();
      TrigcLcLChainGroup_TClassManip(theClass);
   return theClass;
   }

   static void TrigcLcLChainGroup_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TrigcLcLCacheGlobalMemory_Dictionary();
   static void TrigcLcLCacheGlobalMemory_TClassManip(TClass*);
   static void *new_TrigcLcLCacheGlobalMemory(void *p = 0);
   static void *newArray_TrigcLcLCacheGlobalMemory(Long_t size, void *p);
   static void delete_TrigcLcLCacheGlobalMemory(void *p);
   static void deleteArray_TrigcLcLCacheGlobalMemory(void *p);
   static void destruct_TrigcLcLCacheGlobalMemory(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Trig::CacheGlobalMemory*)
   {
      ::Trig::CacheGlobalMemory *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Trig::CacheGlobalMemory));
      static ::ROOT::TGenericClassInfo 
         instance("Trig::CacheGlobalMemory", "TrigDecisionTool/CacheGlobalMemory.h", 56,
                  typeid(::Trig::CacheGlobalMemory), DefineBehavior(ptr, ptr),
                  &TrigcLcLCacheGlobalMemory_Dictionary, isa_proxy, 0,
                  sizeof(::Trig::CacheGlobalMemory) );
      instance.SetNew(&new_TrigcLcLCacheGlobalMemory);
      instance.SetNewArray(&newArray_TrigcLcLCacheGlobalMemory);
      instance.SetDelete(&delete_TrigcLcLCacheGlobalMemory);
      instance.SetDeleteArray(&deleteArray_TrigcLcLCacheGlobalMemory);
      instance.SetDestructor(&destruct_TrigcLcLCacheGlobalMemory);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Trig::CacheGlobalMemory*)
   {
      return GenerateInitInstanceLocal((::Trig::CacheGlobalMemory*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::Trig::CacheGlobalMemory*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TrigcLcLCacheGlobalMemory_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Trig::CacheGlobalMemory*)0x0)->GetClass();
      TrigcLcLCacheGlobalMemory_TClassManip(theClass);
   return theClass;
   }

   static void TrigcLcLCacheGlobalMemory_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TrigcLcLChainGroupFunctions_Dictionary();
   static void TrigcLcLChainGroupFunctions_TClassManip(TClass*);
   static void delete_TrigcLcLChainGroupFunctions(void *p);
   static void deleteArray_TrigcLcLChainGroupFunctions(void *p);
   static void destruct_TrigcLcLChainGroupFunctions(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Trig::ChainGroupFunctions*)
   {
      ::Trig::ChainGroupFunctions *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Trig::ChainGroupFunctions));
      static ::ROOT::TGenericClassInfo 
         instance("Trig::ChainGroupFunctions", "TrigDecisionTool/ChainGroupFunctions.h", 24,
                  typeid(::Trig::ChainGroupFunctions), DefineBehavior(ptr, ptr),
                  &TrigcLcLChainGroupFunctions_Dictionary, isa_proxy, 0,
                  sizeof(::Trig::ChainGroupFunctions) );
      instance.SetDelete(&delete_TrigcLcLChainGroupFunctions);
      instance.SetDeleteArray(&deleteArray_TrigcLcLChainGroupFunctions);
      instance.SetDestructor(&destruct_TrigcLcLChainGroupFunctions);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Trig::ChainGroupFunctions*)
   {
      return GenerateInitInstanceLocal((::Trig::ChainGroupFunctions*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::Trig::ChainGroupFunctions*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TrigcLcLChainGroupFunctions_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Trig::ChainGroupFunctions*)0x0)->GetClass();
      TrigcLcLChainGroupFunctions_TClassManip(theClass);
   return theClass;
   }

   static void TrigcLcLChainGroupFunctions_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TrigcLcLConfigurationAccess_Dictionary();
   static void TrigcLcLConfigurationAccess_TClassManip(TClass*);
   static void delete_TrigcLcLConfigurationAccess(void *p);
   static void deleteArray_TrigcLcLConfigurationAccess(void *p);
   static void destruct_TrigcLcLConfigurationAccess(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Trig::ConfigurationAccess*)
   {
      ::Trig::ConfigurationAccess *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Trig::ConfigurationAccess));
      static ::ROOT::TGenericClassInfo 
         instance("Trig::ConfigurationAccess", "TrigDecisionTool/ConfigurationAccess.h", 23,
                  typeid(::Trig::ConfigurationAccess), DefineBehavior(ptr, ptr),
                  &TrigcLcLConfigurationAccess_Dictionary, isa_proxy, 0,
                  sizeof(::Trig::ConfigurationAccess) );
      instance.SetDelete(&delete_TrigcLcLConfigurationAccess);
      instance.SetDeleteArray(&deleteArray_TrigcLcLConfigurationAccess);
      instance.SetDestructor(&destruct_TrigcLcLConfigurationAccess);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Trig::ConfigurationAccess*)
   {
      return GenerateInitInstanceLocal((::Trig::ConfigurationAccess*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::Trig::ConfigurationAccess*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TrigcLcLConfigurationAccess_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Trig::ConfigurationAccess*)0x0)->GetClass();
      TrigcLcLConfigurationAccess_TClassManip(theClass);
   return theClass;
   }

   static void TrigcLcLConfigurationAccess_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TrigcLcLExpertMethods_Dictionary();
   static void TrigcLcLExpertMethods_TClassManip(TClass*);
   static void delete_TrigcLcLExpertMethods(void *p);
   static void deleteArray_TrigcLcLExpertMethods(void *p);
   static void destruct_TrigcLcLExpertMethods(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Trig::ExpertMethods*)
   {
      ::Trig::ExpertMethods *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Trig::ExpertMethods));
      static ::ROOT::TGenericClassInfo 
         instance("Trig::ExpertMethods", "TrigDecisionTool/ExpertMethods.h", 46,
                  typeid(::Trig::ExpertMethods), DefineBehavior(ptr, ptr),
                  &TrigcLcLExpertMethods_Dictionary, isa_proxy, 0,
                  sizeof(::Trig::ExpertMethods) );
      instance.SetDelete(&delete_TrigcLcLExpertMethods);
      instance.SetDeleteArray(&deleteArray_TrigcLcLExpertMethods);
      instance.SetDestructor(&destruct_TrigcLcLExpertMethods);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Trig::ExpertMethods*)
   {
      return GenerateInitInstanceLocal((::Trig::ExpertMethods*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::Trig::ExpertMethods*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TrigcLcLExpertMethods_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Trig::ExpertMethods*)0x0)->GetClass();
      TrigcLcLExpertMethods_TClassManip(theClass);
   return theClass;
   }

   static void TrigcLcLExpertMethods_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TrigcLcLTrigDecisionTool_Dictionary();
   static void TrigcLcLTrigDecisionTool_TClassManip(TClass*);
   static void delete_TrigcLcLTrigDecisionTool(void *p);
   static void deleteArray_TrigcLcLTrigDecisionTool(void *p);
   static void destruct_TrigcLcLTrigDecisionTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Trig::TrigDecisionTool*)
   {
      ::Trig::TrigDecisionTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Trig::TrigDecisionTool));
      static ::ROOT::TGenericClassInfo 
         instance("Trig::TrigDecisionTool", "TrigDecisionTool/TrigDecisionTool.h", 48,
                  typeid(::Trig::TrigDecisionTool), DefineBehavior(ptr, ptr),
                  &TrigcLcLTrigDecisionTool_Dictionary, isa_proxy, 0,
                  sizeof(::Trig::TrigDecisionTool) );
      instance.SetDelete(&delete_TrigcLcLTrigDecisionTool);
      instance.SetDeleteArray(&deleteArray_TrigcLcLTrigDecisionTool);
      instance.SetDestructor(&destruct_TrigcLcLTrigDecisionTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Trig::TrigDecisionTool*)
   {
      return GenerateInitInstanceLocal((::Trig::TrigDecisionTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::Trig::TrigDecisionTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TrigcLcLTrigDecisionTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Trig::TrigDecisionTool*)0x0)->GetClass();
      TrigcLcLTrigDecisionTool_TClassManip(theClass);
   return theClass;
   }

   static void TrigcLcLTrigDecisionTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TrigcLcLTrigDecisionToolCore_Dictionary();
   static void TrigcLcLTrigDecisionToolCore_TClassManip(TClass*);
   static void *new_TrigcLcLTrigDecisionToolCore(void *p = 0);
   static void *newArray_TrigcLcLTrigDecisionToolCore(Long_t size, void *p);
   static void delete_TrigcLcLTrigDecisionToolCore(void *p);
   static void deleteArray_TrigcLcLTrigDecisionToolCore(void *p);
   static void destruct_TrigcLcLTrigDecisionToolCore(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Trig::TrigDecisionToolCore*)
   {
      ::Trig::TrigDecisionToolCore *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Trig::TrigDecisionToolCore));
      static ::ROOT::TGenericClassInfo 
         instance("Trig::TrigDecisionToolCore", "TrigDecisionTool/TrigDecisionToolCore.h", 29,
                  typeid(::Trig::TrigDecisionToolCore), DefineBehavior(ptr, ptr),
                  &TrigcLcLTrigDecisionToolCore_Dictionary, isa_proxy, 0,
                  sizeof(::Trig::TrigDecisionToolCore) );
      instance.SetNew(&new_TrigcLcLTrigDecisionToolCore);
      instance.SetNewArray(&newArray_TrigcLcLTrigDecisionToolCore);
      instance.SetDelete(&delete_TrigcLcLTrigDecisionToolCore);
      instance.SetDeleteArray(&deleteArray_TrigcLcLTrigDecisionToolCore);
      instance.SetDestructor(&destruct_TrigcLcLTrigDecisionToolCore);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Trig::TrigDecisionToolCore*)
   {
      return GenerateInitInstanceLocal((::Trig::TrigDecisionToolCore*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::Trig::TrigDecisionToolCore*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TrigcLcLTrigDecisionToolCore_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Trig::TrigDecisionToolCore*)0x0)->GetClass();
      TrigcLcLTrigDecisionToolCore_TClassManip(theClass);
   return theClass;
   }

   static void TrigcLcLTrigDecisionToolCore_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *ToolHandlelETrigcLcLTrigDecisionToolgR_Dictionary();
   static void ToolHandlelETrigcLcLTrigDecisionToolgR_TClassManip(TClass*);
   static void *new_ToolHandlelETrigcLcLTrigDecisionToolgR(void *p = 0);
   static void *newArray_ToolHandlelETrigcLcLTrigDecisionToolgR(Long_t size, void *p);
   static void delete_ToolHandlelETrigcLcLTrigDecisionToolgR(void *p);
   static void deleteArray_ToolHandlelETrigcLcLTrigDecisionToolgR(void *p);
   static void destruct_ToolHandlelETrigcLcLTrigDecisionToolgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ToolHandle<Trig::TrigDecisionTool>*)
   {
      ::ToolHandle<Trig::TrigDecisionTool> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ToolHandle<Trig::TrigDecisionTool>));
      static ::ROOT::TGenericClassInfo 
         instance("ToolHandle<Trig::TrigDecisionTool>", "AsgTools/ToolHandle.h", 77,
                  typeid(::ToolHandle<Trig::TrigDecisionTool>), DefineBehavior(ptr, ptr),
                  &ToolHandlelETrigcLcLTrigDecisionToolgR_Dictionary, isa_proxy, 0,
                  sizeof(::ToolHandle<Trig::TrigDecisionTool>) );
      instance.SetNew(&new_ToolHandlelETrigcLcLTrigDecisionToolgR);
      instance.SetNewArray(&newArray_ToolHandlelETrigcLcLTrigDecisionToolgR);
      instance.SetDelete(&delete_ToolHandlelETrigcLcLTrigDecisionToolgR);
      instance.SetDeleteArray(&deleteArray_ToolHandlelETrigcLcLTrigDecisionToolgR);
      instance.SetDestructor(&destruct_ToolHandlelETrigcLcLTrigDecisionToolgR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ToolHandle<Trig::TrigDecisionTool>*)
   {
      return GenerateInitInstanceLocal((::ToolHandle<Trig::TrigDecisionTool>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::ToolHandle<Trig::TrigDecisionTool>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ToolHandlelETrigcLcLTrigDecisionToolgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ToolHandle<Trig::TrigDecisionTool>*)0x0)->GetClass();
      ToolHandlelETrigcLcLTrigDecisionToolgR_TClassManip(theClass);
   return theClass;
   }

   static void ToolHandlelETrigcLcLTrigDecisionToolgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_TrigcLcLLogger(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::Trig::Logger : new ::Trig::Logger;
   }
   static void *newArray_TrigcLcLLogger(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::Trig::Logger[nElements] : new ::Trig::Logger[nElements];
   }
   // Wrapper around operator delete
   static void delete_TrigcLcLLogger(void *p) {
      delete ((::Trig::Logger*)p);
   }
   static void deleteArray_TrigcLcLLogger(void *p) {
      delete [] ((::Trig::Logger*)p);
   }
   static void destruct_TrigcLcLLogger(void *p) {
      typedef ::Trig::Logger current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Trig::Logger

namespace ROOT {
} // end of namespace ROOT for class ::Trig::ChainGroup

namespace ROOT {
   // Wrappers around operator new
   static void *new_TrigcLcLCacheGlobalMemory(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::Trig::CacheGlobalMemory : new ::Trig::CacheGlobalMemory;
   }
   static void *newArray_TrigcLcLCacheGlobalMemory(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::Trig::CacheGlobalMemory[nElements] : new ::Trig::CacheGlobalMemory[nElements];
   }
   // Wrapper around operator delete
   static void delete_TrigcLcLCacheGlobalMemory(void *p) {
      delete ((::Trig::CacheGlobalMemory*)p);
   }
   static void deleteArray_TrigcLcLCacheGlobalMemory(void *p) {
      delete [] ((::Trig::CacheGlobalMemory*)p);
   }
   static void destruct_TrigcLcLCacheGlobalMemory(void *p) {
      typedef ::Trig::CacheGlobalMemory current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Trig::CacheGlobalMemory

namespace ROOT {
   // Wrapper around operator delete
   static void delete_TrigcLcLChainGroupFunctions(void *p) {
      delete ((::Trig::ChainGroupFunctions*)p);
   }
   static void deleteArray_TrigcLcLChainGroupFunctions(void *p) {
      delete [] ((::Trig::ChainGroupFunctions*)p);
   }
   static void destruct_TrigcLcLChainGroupFunctions(void *p) {
      typedef ::Trig::ChainGroupFunctions current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Trig::ChainGroupFunctions

namespace ROOT {
   // Wrapper around operator delete
   static void delete_TrigcLcLConfigurationAccess(void *p) {
      delete ((::Trig::ConfigurationAccess*)p);
   }
   static void deleteArray_TrigcLcLConfigurationAccess(void *p) {
      delete [] ((::Trig::ConfigurationAccess*)p);
   }
   static void destruct_TrigcLcLConfigurationAccess(void *p) {
      typedef ::Trig::ConfigurationAccess current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Trig::ConfigurationAccess

namespace ROOT {
   // Wrapper around operator delete
   static void delete_TrigcLcLExpertMethods(void *p) {
      delete ((::Trig::ExpertMethods*)p);
   }
   static void deleteArray_TrigcLcLExpertMethods(void *p) {
      delete [] ((::Trig::ExpertMethods*)p);
   }
   static void destruct_TrigcLcLExpertMethods(void *p) {
      typedef ::Trig::ExpertMethods current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Trig::ExpertMethods

namespace ROOT {
   // Wrapper around operator delete
   static void delete_TrigcLcLTrigDecisionTool(void *p) {
      delete ((::Trig::TrigDecisionTool*)p);
   }
   static void deleteArray_TrigcLcLTrigDecisionTool(void *p) {
      delete [] ((::Trig::TrigDecisionTool*)p);
   }
   static void destruct_TrigcLcLTrigDecisionTool(void *p) {
      typedef ::Trig::TrigDecisionTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Trig::TrigDecisionTool

namespace ROOT {
   // Wrappers around operator new
   static void *new_TrigcLcLTrigDecisionToolCore(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::Trig::TrigDecisionToolCore : new ::Trig::TrigDecisionToolCore;
   }
   static void *newArray_TrigcLcLTrigDecisionToolCore(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::Trig::TrigDecisionToolCore[nElements] : new ::Trig::TrigDecisionToolCore[nElements];
   }
   // Wrapper around operator delete
   static void delete_TrigcLcLTrigDecisionToolCore(void *p) {
      delete ((::Trig::TrigDecisionToolCore*)p);
   }
   static void deleteArray_TrigcLcLTrigDecisionToolCore(void *p) {
      delete [] ((::Trig::TrigDecisionToolCore*)p);
   }
   static void destruct_TrigcLcLTrigDecisionToolCore(void *p) {
      typedef ::Trig::TrigDecisionToolCore current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Trig::TrigDecisionToolCore

namespace ROOT {
   // Wrappers around operator new
   static void *new_ToolHandlelETrigcLcLTrigDecisionToolgR(void *p) {
      return  p ? new(p) ::ToolHandle<Trig::TrigDecisionTool> : new ::ToolHandle<Trig::TrigDecisionTool>;
   }
   static void *newArray_ToolHandlelETrigcLcLTrigDecisionToolgR(Long_t nElements, void *p) {
      return p ? new(p) ::ToolHandle<Trig::TrigDecisionTool>[nElements] : new ::ToolHandle<Trig::TrigDecisionTool>[nElements];
   }
   // Wrapper around operator delete
   static void delete_ToolHandlelETrigcLcLTrigDecisionToolgR(void *p) {
      delete ((::ToolHandle<Trig::TrigDecisionTool>*)p);
   }
   static void deleteArray_ToolHandlelETrigcLcLTrigDecisionToolgR(void *p) {
      delete [] ((::ToolHandle<Trig::TrigDecisionTool>*)p);
   }
   static void destruct_ToolHandlelETrigcLcLTrigDecisionToolgR(void *p) {
      typedef ::ToolHandle<Trig::TrigDecisionTool> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ToolHandle<Trig::TrigDecisionTool>

namespace {
  void TriggerDictionaryInitialization_TrigDecisionTool_Reflex_Impl() {
    static const char* headers[] = {
0    };
    static const char* includePaths[] = {
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/TrigDecisionTool/Root",
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/TrigDecisionTool",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/TrigDecisionTool/cmt/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace Trig{class __attribute__((annotate("$clingAutoload$TrigDecisionTool/Logger.h")))  Logger;}
namespace Trig{class __attribute__((annotate("$clingAutoload$TrigDecisionTool/ChainGroup.h")))  ChainGroup;}
namespace Trig{class __attribute__((annotate("$clingAutoload$TrigDecisionTool/ChainGroup.h")))  CacheGlobalMemory;}
namespace Trig{class __attribute__((annotate("$clingAutoload$TrigDecisionTool/ChainGroupFunctions.h")))  ChainGroupFunctions;}
namespace Trig{class __attribute__((annotate("$clingAutoload$TrigDecisionTool/ConfigurationAccess.h")))  ConfigurationAccess;}
namespace Trig{class __attribute__((annotate("$clingAutoload$TrigDecisionTool/ExpertMethods.h")))  ExpertMethods;}
namespace Trig{class __attribute__((annotate("$clingAutoload$TrigDecisionTool/TrigDecisionTool.h")))  TrigDecisionTool;}
namespace Trig{class __attribute__((annotate("$clingAutoload$TrigDecisionTool/TrigDecisionTool.h")))  TrigDecisionToolCore;}
template <class T> class __attribute__((annotate("$clingAutoload$TrigDecisionTool/TrigDecisionTool.h")))  ToolHandle;

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
  #define ROOTCORE_PACKAGE "TrigDecisionTool"
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#ifndef TRIGDECISION_TRIGDECISIONDICT_H
#define TRIGDECISION_TRIGDECISIONDICT_H

#include "TrigDecisionTool/Logger.h"
#include "TrigDecisionTool/ChainGroup.h"
#include "TrigDecisionTool/CacheGlobalMemory.h"
#include "TrigDecisionTool/ChainGroupFunctions.h"
#include "TrigDecisionTool/Combination.h"
#include "TrigDecisionTool/Conditions.h"
#include "TrigDecisionTool/ConfigurationAccess.h"
#include "TrigDecisionTool/DecisionAccess.h"
#include "TrigDecisionTool/ExpertMethods.h"
#include "TrigDecisionTool/Feature.h"
#include "TrigDecisionTool/FeatureContainer.h"
#include "TrigDecisionTool/TrigDecisionTool.h"
#include "TrigDecisionTool/TrigDecisionToolCore.h"
#include "TrigDecisionTool/TDTUtilities.h"


namespace TDTStruct {
   ToolHandle<Trig::TrigDecisionTool> tdt;

}

#endif

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"ToolHandle<Trig::TrigDecisionTool>", payloadCode, "@",
"Trig::CacheGlobalMemory", payloadCode, "@",
"Trig::ChainGroup", payloadCode, "@",
"Trig::ChainGroupFunctions", payloadCode, "@",
"Trig::ConfigurationAccess", payloadCode, "@",
"Trig::ExpertMethods", payloadCode, "@",
"Trig::Logger", payloadCode, "@",
"Trig::TrigDecisionTool", payloadCode, "@",
"Trig::TrigDecisionToolCore", payloadCode, "@",
"TrigDefs::EF_error", payloadCode, "@",
"TrigDefs::EF_passThrough", payloadCode, "@",
"TrigDefs::EF_passedRaw", payloadCode, "@",
"TrigDefs::EF_prescaled", payloadCode, "@",
"TrigDefs::EF_resurrected", payloadCode, "@",
"TrigDefs::Express_passed", payloadCode, "@",
"TrigDefs::L1_isPassedAfterPrescale", payloadCode, "@",
"TrigDefs::L1_isPassedAfterVeto", payloadCode, "@",
"TrigDefs::L1_isPassedBeforePrescale", payloadCode, "@",
"TrigDefs::L2_error", payloadCode, "@",
"TrigDefs::L2_passThrough", payloadCode, "@",
"TrigDefs::L2_passedRaw", payloadCode, "@",
"TrigDefs::L2_prescaled", payloadCode, "@",
"TrigDefs::L2_resurrected", payloadCode, "@",
"TrigDefs::Physics", payloadCode, "@",
"TrigDefs::allowResurrectedDecision", payloadCode, "@",
"TrigDefs::alsoDeactivateTEs", payloadCode, "@",
"TrigDefs::enforceLogicalFlow", payloadCode, "@",
"TrigDefs::eventAccepted", payloadCode, "@",
"TrigDefs::fullChain", payloadCode, "@",
"TrigDefs::ignoreFDR", payloadCode, "@",
"TrigDefs::ignoreIOV", payloadCode, "@",
"TrigDefs::passedThrough", payloadCode, "@",
"TrigDefs::requireDecision", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TrigDecisionTool_Reflex",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TrigDecisionTool_Reflex_Impl, {{"namespace DataVector_detail { template <typename B1, typename B2, typename B3> class VirtBases; }", 1},{"template <typename T> class DataVectorBase;", 1},{"template <typename T, typename BASE> class DataVector;", 1}}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TrigDecisionTool_Reflex_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TrigDecisionTool_Reflex() {
  TriggerDictionaryInitialization_TrigDecisionTool_Reflex_Impl();
}
