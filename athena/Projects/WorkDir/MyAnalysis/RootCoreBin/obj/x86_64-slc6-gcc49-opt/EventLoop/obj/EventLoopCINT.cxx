#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#ifdef __llvm__
#pragma GCC diagnostic ignored "-Wunused-private-field"
#endif
// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIuserdIhteagledIAnalysisDirectorydIBase_2_4_34dIRootCoreBindIobjdIx86_64mIslc6mIgcc49mIoptdIEventLoopdIobjdIEventLoopCINT

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
#include "EventLoop/Algorithm.h"
#include "EventLoop/StatusCode.h"
#include "EventLoop/BackgroundDriver.h"
#include "EventLoop/BackgroundJob.h"
#include "EventLoop/BackgroundTSelector.h"
#include "EventLoop/BackgroundWorker.h"
#include "EventLoop/Worker.h"
#include "EventLoop/BatchDriver.h"
#include "EventLoop/BatchJob.h"
#include "EventLoop/Job.h"
#include "EventLoop/BatchSegment.h"
#include "EventLoop/BatchSample.h"
#include "EventLoop/BatchWorker.h"
#include "EventLoop/CondorDriver.h"
#include "EventLoop/DirectDriver.h"
#include "EventLoop/D3PDReaderSvc.h"
#include "EventLoop/GEDriver.h"
#include "EventLoop/LLDriver.h"
#include "EventLoop/LSFDriver.h"
#include "EventLoop/LocalDriver.h"
#include "EventLoop/OutputStream.h"
#include "EventLoop/MetricsSvc.h"
#include "EventLoop/ProofArgs.h"
#include "EventLoop/ProofDriver.h"
#include "EventLoop/ProofTSelector.h"
#include "EventLoop/SoGEDriver.h"
#include "EventLoop/SlurmDriver.h"
#include "EventLoop/TEventSvc.h"
#include "EventLoop/TorqueDriver.h"
#include "EventLoop/UnitTestAlg.h"
#include "EventLoop/UnitTestAlg1.h"
#include "EventLoop/VomsProxySvc.h"
#include "EventLoop/ProofWorker.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_ELcLcLAlgorithm(void *p = 0);
   static void *newArray_ELcLcLAlgorithm(Long_t size, void *p);
   static void delete_ELcLcLAlgorithm(void *p);
   static void deleteArray_ELcLcLAlgorithm(void *p);
   static void destruct_ELcLcLAlgorithm(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::Algorithm*)
   {
      ::EL::Algorithm *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EL::Algorithm >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EL::Algorithm", ::EL::Algorithm::Class_Version(), "EventLoop/Algorithm.h", 30,
                  typeid(::EL::Algorithm), DefineBehavior(ptr, ptr),
                  &::EL::Algorithm::Dictionary, isa_proxy, 4,
                  sizeof(::EL::Algorithm) );
      instance.SetNew(&new_ELcLcLAlgorithm);
      instance.SetNewArray(&newArray_ELcLcLAlgorithm);
      instance.SetDelete(&delete_ELcLcLAlgorithm);
      instance.SetDeleteArray(&deleteArray_ELcLcLAlgorithm);
      instance.SetDestructor(&destruct_ELcLcLAlgorithm);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::Algorithm*)
   {
      return GenerateInitInstanceLocal((::EL::Algorithm*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::Algorithm*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_ELcLcLBackgroundDriver(void *p = 0);
   static void *newArray_ELcLcLBackgroundDriver(Long_t size, void *p);
   static void delete_ELcLcLBackgroundDriver(void *p);
   static void deleteArray_ELcLcLBackgroundDriver(void *p);
   static void destruct_ELcLcLBackgroundDriver(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::BackgroundDriver*)
   {
      ::EL::BackgroundDriver *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EL::BackgroundDriver >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EL::BackgroundDriver", ::EL::BackgroundDriver::Class_Version(), "EventLoop/BackgroundDriver.h", 26,
                  typeid(::EL::BackgroundDriver), DefineBehavior(ptr, ptr),
                  &::EL::BackgroundDriver::Dictionary, isa_proxy, 4,
                  sizeof(::EL::BackgroundDriver) );
      instance.SetNew(&new_ELcLcLBackgroundDriver);
      instance.SetNewArray(&newArray_ELcLcLBackgroundDriver);
      instance.SetDelete(&delete_ELcLcLBackgroundDriver);
      instance.SetDeleteArray(&deleteArray_ELcLcLBackgroundDriver);
      instance.SetDestructor(&destruct_ELcLcLBackgroundDriver);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::BackgroundDriver*)
   {
      return GenerateInitInstanceLocal((::EL::BackgroundDriver*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::BackgroundDriver*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_ELcLcLBackgroundJob(void *p = 0);
   static void *newArray_ELcLcLBackgroundJob(Long_t size, void *p);
   static void delete_ELcLcLBackgroundJob(void *p);
   static void deleteArray_ELcLcLBackgroundJob(void *p);
   static void destruct_ELcLcLBackgroundJob(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::BackgroundJob*)
   {
      ::EL::BackgroundJob *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EL::BackgroundJob >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EL::BackgroundJob", ::EL::BackgroundJob::Class_Version(), "EventLoop/BackgroundJob.h", 38,
                  typeid(::EL::BackgroundJob), DefineBehavior(ptr, ptr),
                  &::EL::BackgroundJob::Dictionary, isa_proxy, 4,
                  sizeof(::EL::BackgroundJob) );
      instance.SetNew(&new_ELcLcLBackgroundJob);
      instance.SetNewArray(&newArray_ELcLcLBackgroundJob);
      instance.SetDelete(&delete_ELcLcLBackgroundJob);
      instance.SetDeleteArray(&deleteArray_ELcLcLBackgroundJob);
      instance.SetDestructor(&destruct_ELcLcLBackgroundJob);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::BackgroundJob*)
   {
      return GenerateInitInstanceLocal((::EL::BackgroundJob*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::BackgroundJob*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_ELcLcLBackgroundTSelector(void *p = 0);
   static void *newArray_ELcLcLBackgroundTSelector(Long_t size, void *p);
   static void delete_ELcLcLBackgroundTSelector(void *p);
   static void deleteArray_ELcLcLBackgroundTSelector(void *p);
   static void destruct_ELcLcLBackgroundTSelector(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::BackgroundTSelector*)
   {
      ::EL::BackgroundTSelector *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EL::BackgroundTSelector >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EL::BackgroundTSelector", ::EL::BackgroundTSelector::Class_Version(), "EventLoop/BackgroundTSelector.h", 28,
                  typeid(::EL::BackgroundTSelector), DefineBehavior(ptr, ptr),
                  &::EL::BackgroundTSelector::Dictionary, isa_proxy, 4,
                  sizeof(::EL::BackgroundTSelector) );
      instance.SetNew(&new_ELcLcLBackgroundTSelector);
      instance.SetNewArray(&newArray_ELcLcLBackgroundTSelector);
      instance.SetDelete(&delete_ELcLcLBackgroundTSelector);
      instance.SetDeleteArray(&deleteArray_ELcLcLBackgroundTSelector);
      instance.SetDestructor(&destruct_ELcLcLBackgroundTSelector);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::BackgroundTSelector*)
   {
      return GenerateInitInstanceLocal((::EL::BackgroundTSelector*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::BackgroundTSelector*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static TClass *ELcLcLBackgroundWorker_Dictionary();
   static void ELcLcLBackgroundWorker_TClassManip(TClass*);
   static void delete_ELcLcLBackgroundWorker(void *p);
   static void deleteArray_ELcLcLBackgroundWorker(void *p);
   static void destruct_ELcLcLBackgroundWorker(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::BackgroundWorker*)
   {
      ::EL::BackgroundWorker *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::EL::BackgroundWorker));
      static ::ROOT::TGenericClassInfo 
         instance("EL::BackgroundWorker", "EventLoop/BackgroundWorker.h", 23,
                  typeid(::EL::BackgroundWorker), DefineBehavior(ptr, ptr),
                  &ELcLcLBackgroundWorker_Dictionary, isa_proxy, 4,
                  sizeof(::EL::BackgroundWorker) );
      instance.SetDelete(&delete_ELcLcLBackgroundWorker);
      instance.SetDeleteArray(&deleteArray_ELcLcLBackgroundWorker);
      instance.SetDestructor(&destruct_ELcLcLBackgroundWorker);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::BackgroundWorker*)
   {
      return GenerateInitInstanceLocal((::EL::BackgroundWorker*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::BackgroundWorker*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ELcLcLBackgroundWorker_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::EL::BackgroundWorker*)0x0)->GetClass();
      ELcLcLBackgroundWorker_TClassManip(theClass);
   return theClass;
   }

   static void ELcLcLBackgroundWorker_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static void delete_ELcLcLBatchDriver(void *p);
   static void deleteArray_ELcLcLBatchDriver(void *p);
   static void destruct_ELcLcLBatchDriver(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::BatchDriver*)
   {
      ::EL::BatchDriver *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EL::BatchDriver >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EL::BatchDriver", ::EL::BatchDriver::Class_Version(), "EventLoop/BatchDriver.h", 27,
                  typeid(::EL::BatchDriver), DefineBehavior(ptr, ptr),
                  &::EL::BatchDriver::Dictionary, isa_proxy, 4,
                  sizeof(::EL::BatchDriver) );
      instance.SetDelete(&delete_ELcLcLBatchDriver);
      instance.SetDeleteArray(&deleteArray_ELcLcLBatchDriver);
      instance.SetDestructor(&destruct_ELcLcLBatchDriver);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::BatchDriver*)
   {
      return GenerateInitInstanceLocal((::EL::BatchDriver*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::BatchDriver*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_ELcLcLBatchJob(void *p = 0);
   static void *newArray_ELcLcLBatchJob(Long_t size, void *p);
   static void delete_ELcLcLBatchJob(void *p);
   static void deleteArray_ELcLcLBatchJob(void *p);
   static void destruct_ELcLcLBatchJob(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::BatchJob*)
   {
      ::EL::BatchJob *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EL::BatchJob >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EL::BatchJob", ::EL::BatchJob::Class_Version(), "EventLoop/BatchJob.h", 31,
                  typeid(::EL::BatchJob), DefineBehavior(ptr, ptr),
                  &::EL::BatchJob::Dictionary, isa_proxy, 4,
                  sizeof(::EL::BatchJob) );
      instance.SetNew(&new_ELcLcLBatchJob);
      instance.SetNewArray(&newArray_ELcLcLBatchJob);
      instance.SetDelete(&delete_ELcLcLBatchJob);
      instance.SetDeleteArray(&deleteArray_ELcLcLBatchJob);
      instance.SetDestructor(&destruct_ELcLcLBatchJob);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::BatchJob*)
   {
      return GenerateInitInstanceLocal((::EL::BatchJob*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::BatchJob*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_ELcLcLBatchSample(void *p = 0);
   static void *newArray_ELcLcLBatchSample(Long_t size, void *p);
   static void delete_ELcLcLBatchSample(void *p);
   static void deleteArray_ELcLcLBatchSample(void *p);
   static void destruct_ELcLcLBatchSample(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::BatchSample*)
   {
      ::EL::BatchSample *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EL::BatchSample >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EL::BatchSample", ::EL::BatchSample::Class_Version(), "EventLoop/BatchSample.h", 27,
                  typeid(::EL::BatchSample), DefineBehavior(ptr, ptr),
                  &::EL::BatchSample::Dictionary, isa_proxy, 4,
                  sizeof(::EL::BatchSample) );
      instance.SetNew(&new_ELcLcLBatchSample);
      instance.SetNewArray(&newArray_ELcLcLBatchSample);
      instance.SetDelete(&delete_ELcLcLBatchSample);
      instance.SetDeleteArray(&deleteArray_ELcLcLBatchSample);
      instance.SetDestructor(&destruct_ELcLcLBatchSample);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::BatchSample*)
   {
      return GenerateInitInstanceLocal((::EL::BatchSample*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::BatchSample*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_ELcLcLBatchSegment(void *p = 0);
   static void *newArray_ELcLcLBatchSegment(Long_t size, void *p);
   static void delete_ELcLcLBatchSegment(void *p);
   static void deleteArray_ELcLcLBatchSegment(void *p);
   static void destruct_ELcLcLBatchSegment(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::BatchSegment*)
   {
      ::EL::BatchSegment *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EL::BatchSegment >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EL::BatchSegment", ::EL::BatchSegment::Class_Version(), "EventLoop/BatchSegment.h", 26,
                  typeid(::EL::BatchSegment), DefineBehavior(ptr, ptr),
                  &::EL::BatchSegment::Dictionary, isa_proxy, 4,
                  sizeof(::EL::BatchSegment) );
      instance.SetNew(&new_ELcLcLBatchSegment);
      instance.SetNewArray(&newArray_ELcLcLBatchSegment);
      instance.SetDelete(&delete_ELcLcLBatchSegment);
      instance.SetDeleteArray(&deleteArray_ELcLcLBatchSegment);
      instance.SetDestructor(&destruct_ELcLcLBatchSegment);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::BatchSegment*)
   {
      return GenerateInitInstanceLocal((::EL::BatchSegment*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::BatchSegment*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static TClass *ELcLcLBatchWorker_Dictionary();
   static void ELcLcLBatchWorker_TClassManip(TClass*);
   static void delete_ELcLcLBatchWorker(void *p);
   static void deleteArray_ELcLcLBatchWorker(void *p);
   static void destruct_ELcLcLBatchWorker(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::BatchWorker*)
   {
      ::EL::BatchWorker *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::EL::BatchWorker));
      static ::ROOT::TGenericClassInfo 
         instance("EL::BatchWorker", "EventLoop/BatchWorker.h", 27,
                  typeid(::EL::BatchWorker), DefineBehavior(ptr, ptr),
                  &ELcLcLBatchWorker_Dictionary, isa_proxy, 4,
                  sizeof(::EL::BatchWorker) );
      instance.SetDelete(&delete_ELcLcLBatchWorker);
      instance.SetDeleteArray(&deleteArray_ELcLcLBatchWorker);
      instance.SetDestructor(&destruct_ELcLcLBatchWorker);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::BatchWorker*)
   {
      return GenerateInitInstanceLocal((::EL::BatchWorker*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::BatchWorker*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ELcLcLBatchWorker_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::EL::BatchWorker*)0x0)->GetClass();
      ELcLcLBatchWorker_TClassManip(theClass);
   return theClass;
   }

   static void ELcLcLBatchWorker_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static void *new_ELcLcLCondorDriver(void *p = 0);
   static void *newArray_ELcLcLCondorDriver(Long_t size, void *p);
   static void delete_ELcLcLCondorDriver(void *p);
   static void deleteArray_ELcLcLCondorDriver(void *p);
   static void destruct_ELcLcLCondorDriver(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::CondorDriver*)
   {
      ::EL::CondorDriver *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EL::CondorDriver >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EL::CondorDriver", ::EL::CondorDriver::Class_Version(), "EventLoop/CondorDriver.h", 27,
                  typeid(::EL::CondorDriver), DefineBehavior(ptr, ptr),
                  &::EL::CondorDriver::Dictionary, isa_proxy, 4,
                  sizeof(::EL::CondorDriver) );
      instance.SetNew(&new_ELcLcLCondorDriver);
      instance.SetNewArray(&newArray_ELcLcLCondorDriver);
      instance.SetDelete(&delete_ELcLcLCondorDriver);
      instance.SetDeleteArray(&deleteArray_ELcLcLCondorDriver);
      instance.SetDestructor(&destruct_ELcLcLCondorDriver);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::CondorDriver*)
   {
      return GenerateInitInstanceLocal((::EL::CondorDriver*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::CondorDriver*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_ELcLcLDirectDriver(void *p = 0);
   static void *newArray_ELcLcLDirectDriver(Long_t size, void *p);
   static void delete_ELcLcLDirectDriver(void *p);
   static void deleteArray_ELcLcLDirectDriver(void *p);
   static void destruct_ELcLcLDirectDriver(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::DirectDriver*)
   {
      ::EL::DirectDriver *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EL::DirectDriver >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EL::DirectDriver", ::EL::DirectDriver::Class_Version(), "EventLoop/DirectDriver.h", 25,
                  typeid(::EL::DirectDriver), DefineBehavior(ptr, ptr),
                  &::EL::DirectDriver::Dictionary, isa_proxy, 4,
                  sizeof(::EL::DirectDriver) );
      instance.SetNew(&new_ELcLcLDirectDriver);
      instance.SetNewArray(&newArray_ELcLcLDirectDriver);
      instance.SetDelete(&delete_ELcLcLDirectDriver);
      instance.SetDeleteArray(&deleteArray_ELcLcLDirectDriver);
      instance.SetDestructor(&destruct_ELcLcLDirectDriver);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::DirectDriver*)
   {
      return GenerateInitInstanceLocal((::EL::DirectDriver*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::DirectDriver*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_ELcLcLDriver(void *p = 0);
   static void *newArray_ELcLcLDriver(Long_t size, void *p);
   static void delete_ELcLcLDriver(void *p);
   static void deleteArray_ELcLcLDriver(void *p);
   static void destruct_ELcLcLDriver(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::Driver*)
   {
      ::EL::Driver *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EL::Driver >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EL::Driver", ::EL::Driver::Class_Version(), "EventLoop/Driver.h", 28,
                  typeid(::EL::Driver), DefineBehavior(ptr, ptr),
                  &::EL::Driver::Dictionary, isa_proxy, 4,
                  sizeof(::EL::Driver) );
      instance.SetNew(&new_ELcLcLDriver);
      instance.SetNewArray(&newArray_ELcLcLDriver);
      instance.SetDelete(&delete_ELcLcLDriver);
      instance.SetDeleteArray(&deleteArray_ELcLcLDriver);
      instance.SetDestructor(&destruct_ELcLcLDriver);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::Driver*)
   {
      return GenerateInitInstanceLocal((::EL::Driver*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::Driver*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static TClass *ELcLcLJob_Dictionary();
   static void ELcLcLJob_TClassManip(TClass*);
   static void *new_ELcLcLJob(void *p = 0);
   static void *newArray_ELcLcLJob(Long_t size, void *p);
   static void delete_ELcLcLJob(void *p);
   static void deleteArray_ELcLcLJob(void *p);
   static void destruct_ELcLcLJob(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::Job*)
   {
      ::EL::Job *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::EL::Job));
      static ::ROOT::TGenericClassInfo 
         instance("EL::Job", "EventLoop/Job.h", 33,
                  typeid(::EL::Job), DefineBehavior(ptr, ptr),
                  &ELcLcLJob_Dictionary, isa_proxy, 4,
                  sizeof(::EL::Job) );
      instance.SetNew(&new_ELcLcLJob);
      instance.SetNewArray(&newArray_ELcLcLJob);
      instance.SetDelete(&delete_ELcLcLJob);
      instance.SetDeleteArray(&deleteArray_ELcLcLJob);
      instance.SetDestructor(&destruct_ELcLcLJob);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::Job*)
   {
      return GenerateInitInstanceLocal((::EL::Job*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::Job*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ELcLcLJob_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::EL::Job*)0x0)->GetClass();
      ELcLcLJob_TClassManip(theClass);
   return theClass;
   }

   static void ELcLcLJob_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static void *new_ELcLcLGEDriver(void *p = 0);
   static void *newArray_ELcLcLGEDriver(Long_t size, void *p);
   static void delete_ELcLcLGEDriver(void *p);
   static void deleteArray_ELcLcLGEDriver(void *p);
   static void destruct_ELcLcLGEDriver(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::GEDriver*)
   {
      ::EL::GEDriver *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EL::GEDriver >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EL::GEDriver", ::EL::GEDriver::Class_Version(), "EventLoop/GEDriver.h", 27,
                  typeid(::EL::GEDriver), DefineBehavior(ptr, ptr),
                  &::EL::GEDriver::Dictionary, isa_proxy, 4,
                  sizeof(::EL::GEDriver) );
      instance.SetNew(&new_ELcLcLGEDriver);
      instance.SetNewArray(&newArray_ELcLcLGEDriver);
      instance.SetDelete(&delete_ELcLcLGEDriver);
      instance.SetDeleteArray(&deleteArray_ELcLcLGEDriver);
      instance.SetDestructor(&destruct_ELcLcLGEDriver);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::GEDriver*)
   {
      return GenerateInitInstanceLocal((::EL::GEDriver*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::GEDriver*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_ELcLcLLSFDriver(void *p = 0);
   static void *newArray_ELcLcLLSFDriver(Long_t size, void *p);
   static void delete_ELcLcLLSFDriver(void *p);
   static void deleteArray_ELcLcLLSFDriver(void *p);
   static void destruct_ELcLcLLSFDriver(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::LSFDriver*)
   {
      ::EL::LSFDriver *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EL::LSFDriver >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EL::LSFDriver", ::EL::LSFDriver::Class_Version(), "EventLoop/LSFDriver.h", 27,
                  typeid(::EL::LSFDriver), DefineBehavior(ptr, ptr),
                  &::EL::LSFDriver::Dictionary, isa_proxy, 4,
                  sizeof(::EL::LSFDriver) );
      instance.SetNew(&new_ELcLcLLSFDriver);
      instance.SetNewArray(&newArray_ELcLcLLSFDriver);
      instance.SetDelete(&delete_ELcLcLLSFDriver);
      instance.SetDeleteArray(&deleteArray_ELcLcLLSFDriver);
      instance.SetDestructor(&destruct_ELcLcLLSFDriver);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::LSFDriver*)
   {
      return GenerateInitInstanceLocal((::EL::LSFDriver*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::LSFDriver*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_ELcLcLLLDriver(void *p = 0);
   static void *newArray_ELcLcLLLDriver(Long_t size, void *p);
   static void delete_ELcLcLLLDriver(void *p);
   static void deleteArray_ELcLcLLLDriver(void *p);
   static void destruct_ELcLcLLLDriver(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::LLDriver*)
   {
      ::EL::LLDriver *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EL::LLDriver >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EL::LLDriver", ::EL::LLDriver::Class_Version(), "EventLoop/LLDriver.h", 27,
                  typeid(::EL::LLDriver), DefineBehavior(ptr, ptr),
                  &::EL::LLDriver::Dictionary, isa_proxy, 4,
                  sizeof(::EL::LLDriver) );
      instance.SetNew(&new_ELcLcLLLDriver);
      instance.SetNewArray(&newArray_ELcLcLLLDriver);
      instance.SetDelete(&delete_ELcLcLLLDriver);
      instance.SetDeleteArray(&deleteArray_ELcLcLLLDriver);
      instance.SetDestructor(&destruct_ELcLcLLLDriver);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::LLDriver*)
   {
      return GenerateInitInstanceLocal((::EL::LLDriver*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::LLDriver*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_ELcLcLLocalDriver(void *p = 0);
   static void *newArray_ELcLcLLocalDriver(Long_t size, void *p);
   static void delete_ELcLcLLocalDriver(void *p);
   static void deleteArray_ELcLcLLocalDriver(void *p);
   static void destruct_ELcLcLLocalDriver(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::LocalDriver*)
   {
      ::EL::LocalDriver *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EL::LocalDriver >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EL::LocalDriver", ::EL::LocalDriver::Class_Version(), "EventLoop/LocalDriver.h", 27,
                  typeid(::EL::LocalDriver), DefineBehavior(ptr, ptr),
                  &::EL::LocalDriver::Dictionary, isa_proxy, 4,
                  sizeof(::EL::LocalDriver) );
      instance.SetNew(&new_ELcLcLLocalDriver);
      instance.SetNewArray(&newArray_ELcLcLLocalDriver);
      instance.SetDelete(&delete_ELcLcLLocalDriver);
      instance.SetDeleteArray(&deleteArray_ELcLcLLocalDriver);
      instance.SetDestructor(&destruct_ELcLcLLocalDriver);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::LocalDriver*)
   {
      return GenerateInitInstanceLocal((::EL::LocalDriver*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::LocalDriver*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_ELcLcLOutputStream(void *p = 0);
   static void *newArray_ELcLcLOutputStream(Long_t size, void *p);
   static void delete_ELcLcLOutputStream(void *p);
   static void deleteArray_ELcLcLOutputStream(void *p);
   static void destruct_ELcLcLOutputStream(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::OutputStream*)
   {
      ::EL::OutputStream *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EL::OutputStream >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EL::OutputStream", ::EL::OutputStream::Class_Version(), "EventLoop/OutputStream.h", 29,
                  typeid(::EL::OutputStream), DefineBehavior(ptr, ptr),
                  &::EL::OutputStream::Dictionary, isa_proxy, 4,
                  sizeof(::EL::OutputStream) );
      instance.SetNew(&new_ELcLcLOutputStream);
      instance.SetNewArray(&newArray_ELcLcLOutputStream);
      instance.SetDelete(&delete_ELcLcLOutputStream);
      instance.SetDeleteArray(&deleteArray_ELcLcLOutputStream);
      instance.SetDestructor(&destruct_ELcLcLOutputStream);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::OutputStream*)
   {
      return GenerateInitInstanceLocal((::EL::OutputStream*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::OutputStream*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_ELcLcLMetricsSvc(void *p = 0);
   static void *newArray_ELcLcLMetricsSvc(Long_t size, void *p);
   static void delete_ELcLcLMetricsSvc(void *p);
   static void deleteArray_ELcLcLMetricsSvc(void *p);
   static void destruct_ELcLcLMetricsSvc(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::MetricsSvc*)
   {
      ::EL::MetricsSvc *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EL::MetricsSvc >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EL::MetricsSvc", ::EL::MetricsSvc::Class_Version(), "EventLoop/MetricsSvc.h", 14,
                  typeid(::EL::MetricsSvc), DefineBehavior(ptr, ptr),
                  &::EL::MetricsSvc::Dictionary, isa_proxy, 4,
                  sizeof(::EL::MetricsSvc) );
      instance.SetNew(&new_ELcLcLMetricsSvc);
      instance.SetNewArray(&newArray_ELcLcLMetricsSvc);
      instance.SetDelete(&delete_ELcLcLMetricsSvc);
      instance.SetDeleteArray(&deleteArray_ELcLcLMetricsSvc);
      instance.SetDestructor(&destruct_ELcLcLMetricsSvc);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::MetricsSvc*)
   {
      return GenerateInitInstanceLocal((::EL::MetricsSvc*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::MetricsSvc*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_ELcLcLProofArgs(void *p = 0);
   static void *newArray_ELcLcLProofArgs(Long_t size, void *p);
   static void delete_ELcLcLProofArgs(void *p);
   static void deleteArray_ELcLcLProofArgs(void *p);
   static void destruct_ELcLcLProofArgs(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::ProofArgs*)
   {
      ::EL::ProofArgs *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EL::ProofArgs >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EL::ProofArgs", ::EL::ProofArgs::Class_Version(), "EventLoop/ProofArgs.h", 28,
                  typeid(::EL::ProofArgs), DefineBehavior(ptr, ptr),
                  &::EL::ProofArgs::Dictionary, isa_proxy, 4,
                  sizeof(::EL::ProofArgs) );
      instance.SetNew(&new_ELcLcLProofArgs);
      instance.SetNewArray(&newArray_ELcLcLProofArgs);
      instance.SetDelete(&delete_ELcLcLProofArgs);
      instance.SetDeleteArray(&deleteArray_ELcLcLProofArgs);
      instance.SetDestructor(&destruct_ELcLcLProofArgs);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::ProofArgs*)
   {
      return GenerateInitInstanceLocal((::EL::ProofArgs*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::ProofArgs*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_ELcLcLProofDriver(void *p = 0);
   static void *newArray_ELcLcLProofDriver(Long_t size, void *p);
   static void delete_ELcLcLProofDriver(void *p);
   static void deleteArray_ELcLcLProofDriver(void *p);
   static void destruct_ELcLcLProofDriver(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::ProofDriver*)
   {
      ::EL::ProofDriver *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EL::ProofDriver >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EL::ProofDriver", ::EL::ProofDriver::Class_Version(), "EventLoop/ProofDriver.h", 25,
                  typeid(::EL::ProofDriver), DefineBehavior(ptr, ptr),
                  &::EL::ProofDriver::Dictionary, isa_proxy, 4,
                  sizeof(::EL::ProofDriver) );
      instance.SetNew(&new_ELcLcLProofDriver);
      instance.SetNewArray(&newArray_ELcLcLProofDriver);
      instance.SetDelete(&delete_ELcLcLProofDriver);
      instance.SetDeleteArray(&deleteArray_ELcLcLProofDriver);
      instance.SetDestructor(&destruct_ELcLcLProofDriver);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::ProofDriver*)
   {
      return GenerateInitInstanceLocal((::EL::ProofDriver*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::ProofDriver*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_ELcLcLProofTSelector(void *p = 0);
   static void *newArray_ELcLcLProofTSelector(Long_t size, void *p);
   static void delete_ELcLcLProofTSelector(void *p);
   static void deleteArray_ELcLcLProofTSelector(void *p);
   static void destruct_ELcLcLProofTSelector(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::ProofTSelector*)
   {
      ::EL::ProofTSelector *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EL::ProofTSelector >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EL::ProofTSelector", ::EL::ProofTSelector::Class_Version(), "EventLoop/ProofTSelector.h", 28,
                  typeid(::EL::ProofTSelector), DefineBehavior(ptr, ptr),
                  &::EL::ProofTSelector::Dictionary, isa_proxy, 4,
                  sizeof(::EL::ProofTSelector) );
      instance.SetNew(&new_ELcLcLProofTSelector);
      instance.SetNewArray(&newArray_ELcLcLProofTSelector);
      instance.SetDelete(&delete_ELcLcLProofTSelector);
      instance.SetDeleteArray(&deleteArray_ELcLcLProofTSelector);
      instance.SetDestructor(&destruct_ELcLcLProofTSelector);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::ProofTSelector*)
   {
      return GenerateInitInstanceLocal((::EL::ProofTSelector*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::ProofTSelector*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static TClass *ELcLcLProofWorker_Dictionary();
   static void ELcLcLProofWorker_TClassManip(TClass*);
   static void delete_ELcLcLProofWorker(void *p);
   static void deleteArray_ELcLcLProofWorker(void *p);
   static void destruct_ELcLcLProofWorker(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::ProofWorker*)
   {
      ::EL::ProofWorker *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::EL::ProofWorker));
      static ::ROOT::TGenericClassInfo 
         instance("EL::ProofWorker", "EventLoop/ProofWorker.h", 27,
                  typeid(::EL::ProofWorker), DefineBehavior(ptr, ptr),
                  &ELcLcLProofWorker_Dictionary, isa_proxy, 4,
                  sizeof(::EL::ProofWorker) );
      instance.SetDelete(&delete_ELcLcLProofWorker);
      instance.SetDeleteArray(&deleteArray_ELcLcLProofWorker);
      instance.SetDestructor(&destruct_ELcLcLProofWorker);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::ProofWorker*)
   {
      return GenerateInitInstanceLocal((::EL::ProofWorker*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::ProofWorker*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ELcLcLProofWorker_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::EL::ProofWorker*)0x0)->GetClass();
      ELcLcLProofWorker_TClassManip(theClass);
   return theClass;
   }

   static void ELcLcLProofWorker_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static void *new_ELcLcLSlurmDriver(void *p = 0);
   static void *newArray_ELcLcLSlurmDriver(Long_t size, void *p);
   static void delete_ELcLcLSlurmDriver(void *p);
   static void deleteArray_ELcLcLSlurmDriver(void *p);
   static void destruct_ELcLcLSlurmDriver(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::SlurmDriver*)
   {
      ::EL::SlurmDriver *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EL::SlurmDriver >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EL::SlurmDriver", ::EL::SlurmDriver::Class_Version(), "EventLoop/SlurmDriver.h", 29,
                  typeid(::EL::SlurmDriver), DefineBehavior(ptr, ptr),
                  &::EL::SlurmDriver::Dictionary, isa_proxy, 4,
                  sizeof(::EL::SlurmDriver) );
      instance.SetNew(&new_ELcLcLSlurmDriver);
      instance.SetNewArray(&newArray_ELcLcLSlurmDriver);
      instance.SetDelete(&delete_ELcLcLSlurmDriver);
      instance.SetDeleteArray(&deleteArray_ELcLcLSlurmDriver);
      instance.SetDestructor(&destruct_ELcLcLSlurmDriver);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::SlurmDriver*)
   {
      return GenerateInitInstanceLocal((::EL::SlurmDriver*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::SlurmDriver*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_ELcLcLSoGEDriver(void *p = 0);
   static void *newArray_ELcLcLSoGEDriver(Long_t size, void *p);
   static void delete_ELcLcLSoGEDriver(void *p);
   static void deleteArray_ELcLcLSoGEDriver(void *p);
   static void destruct_ELcLcLSoGEDriver(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::SoGEDriver*)
   {
      ::EL::SoGEDriver *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EL::SoGEDriver >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EL::SoGEDriver", ::EL::SoGEDriver::Class_Version(), "EventLoop/SoGEDriver.h", 27,
                  typeid(::EL::SoGEDriver), DefineBehavior(ptr, ptr),
                  &::EL::SoGEDriver::Dictionary, isa_proxy, 4,
                  sizeof(::EL::SoGEDriver) );
      instance.SetNew(&new_ELcLcLSoGEDriver);
      instance.SetNewArray(&newArray_ELcLcLSoGEDriver);
      instance.SetDelete(&delete_ELcLcLSoGEDriver);
      instance.SetDeleteArray(&deleteArray_ELcLcLSoGEDriver);
      instance.SetDestructor(&destruct_ELcLcLSoGEDriver);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::SoGEDriver*)
   {
      return GenerateInitInstanceLocal((::EL::SoGEDriver*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::SoGEDriver*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static TClass *ELcLcLStatusCode_Dictionary();
   static void ELcLcLStatusCode_TClassManip(TClass*);
   static void *new_ELcLcLStatusCode(void *p = 0);
   static void *newArray_ELcLcLStatusCode(Long_t size, void *p);
   static void delete_ELcLcLStatusCode(void *p);
   static void deleteArray_ELcLcLStatusCode(void *p);
   static void destruct_ELcLcLStatusCode(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::StatusCode*)
   {
      ::EL::StatusCode *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::EL::StatusCode));
      static ::ROOT::TGenericClassInfo 
         instance("EL::StatusCode", "EventLoop/StatusCode.h", 24,
                  typeid(::EL::StatusCode), DefineBehavior(ptr, ptr),
                  &ELcLcLStatusCode_Dictionary, isa_proxy, 4,
                  sizeof(::EL::StatusCode) );
      instance.SetNew(&new_ELcLcLStatusCode);
      instance.SetNewArray(&newArray_ELcLcLStatusCode);
      instance.SetDelete(&delete_ELcLcLStatusCode);
      instance.SetDeleteArray(&deleteArray_ELcLcLStatusCode);
      instance.SetDestructor(&destruct_ELcLcLStatusCode);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::StatusCode*)
   {
      return GenerateInitInstanceLocal((::EL::StatusCode*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::StatusCode*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ELcLcLStatusCode_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::EL::StatusCode*)0x0)->GetClass();
      ELcLcLStatusCode_TClassManip(theClass);
   return theClass;
   }

   static void ELcLcLStatusCode_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static void *new_ELcLcLTorqueDriver(void *p = 0);
   static void *newArray_ELcLcLTorqueDriver(Long_t size, void *p);
   static void delete_ELcLcLTorqueDriver(void *p);
   static void deleteArray_ELcLcLTorqueDriver(void *p);
   static void destruct_ELcLcLTorqueDriver(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::TorqueDriver*)
   {
      ::EL::TorqueDriver *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EL::TorqueDriver >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EL::TorqueDriver", ::EL::TorqueDriver::Class_Version(), "EventLoop/TorqueDriver.h", 27,
                  typeid(::EL::TorqueDriver), DefineBehavior(ptr, ptr),
                  &::EL::TorqueDriver::Dictionary, isa_proxy, 4,
                  sizeof(::EL::TorqueDriver) );
      instance.SetNew(&new_ELcLcLTorqueDriver);
      instance.SetNewArray(&newArray_ELcLcLTorqueDriver);
      instance.SetDelete(&delete_ELcLcLTorqueDriver);
      instance.SetDeleteArray(&deleteArray_ELcLcLTorqueDriver);
      instance.SetDestructor(&destruct_ELcLcLTorqueDriver);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::TorqueDriver*)
   {
      return GenerateInitInstanceLocal((::EL::TorqueDriver*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::TorqueDriver*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_ELcLcLUnitTestAlg(void *p = 0);
   static void *newArray_ELcLcLUnitTestAlg(Long_t size, void *p);
   static void delete_ELcLcLUnitTestAlg(void *p);
   static void deleteArray_ELcLcLUnitTestAlg(void *p);
   static void destruct_ELcLcLUnitTestAlg(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::UnitTestAlg*)
   {
      ::EL::UnitTestAlg *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EL::UnitTestAlg >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EL::UnitTestAlg", ::EL::UnitTestAlg::Class_Version(), "EventLoop/UnitTestAlg.h", 35,
                  typeid(::EL::UnitTestAlg), DefineBehavior(ptr, ptr),
                  &::EL::UnitTestAlg::Dictionary, isa_proxy, 4,
                  sizeof(::EL::UnitTestAlg) );
      instance.SetNew(&new_ELcLcLUnitTestAlg);
      instance.SetNewArray(&newArray_ELcLcLUnitTestAlg);
      instance.SetDelete(&delete_ELcLcLUnitTestAlg);
      instance.SetDeleteArray(&deleteArray_ELcLcLUnitTestAlg);
      instance.SetDestructor(&destruct_ELcLcLUnitTestAlg);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::UnitTestAlg*)
   {
      return GenerateInitInstanceLocal((::EL::UnitTestAlg*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::UnitTestAlg*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_ELcLcLUnitTestAlg1(void *p = 0);
   static void *newArray_ELcLcLUnitTestAlg1(Long_t size, void *p);
   static void delete_ELcLcLUnitTestAlg1(void *p);
   static void deleteArray_ELcLcLUnitTestAlg1(void *p);
   static void destruct_ELcLcLUnitTestAlg1(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::UnitTestAlg1*)
   {
      ::EL::UnitTestAlg1 *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EL::UnitTestAlg1 >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EL::UnitTestAlg1", ::EL::UnitTestAlg1::Class_Version(), "EventLoop/UnitTestAlg1.h", 35,
                  typeid(::EL::UnitTestAlg1), DefineBehavior(ptr, ptr),
                  &::EL::UnitTestAlg1::Dictionary, isa_proxy, 4,
                  sizeof(::EL::UnitTestAlg1) );
      instance.SetNew(&new_ELcLcLUnitTestAlg1);
      instance.SetNewArray(&newArray_ELcLcLUnitTestAlg1);
      instance.SetDelete(&delete_ELcLcLUnitTestAlg1);
      instance.SetDeleteArray(&deleteArray_ELcLcLUnitTestAlg1);
      instance.SetDestructor(&destruct_ELcLcLUnitTestAlg1);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::UnitTestAlg1*)
   {
      return GenerateInitInstanceLocal((::EL::UnitTestAlg1*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::UnitTestAlg1*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_ELcLcLVomsProxySvc(void *p = 0);
   static void *newArray_ELcLcLVomsProxySvc(Long_t size, void *p);
   static void delete_ELcLcLVomsProxySvc(void *p);
   static void deleteArray_ELcLcLVomsProxySvc(void *p);
   static void destruct_ELcLcLVomsProxySvc(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::VomsProxySvc*)
   {
      ::EL::VomsProxySvc *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EL::VomsProxySvc >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EL::VomsProxySvc", ::EL::VomsProxySvc::Class_Version(), "EventLoop/VomsProxySvc.h", 19,
                  typeid(::EL::VomsProxySvc), DefineBehavior(ptr, ptr),
                  &::EL::VomsProxySvc::Dictionary, isa_proxy, 4,
                  sizeof(::EL::VomsProxySvc) );
      instance.SetNew(&new_ELcLcLVomsProxySvc);
      instance.SetNewArray(&newArray_ELcLcLVomsProxySvc);
      instance.SetDelete(&delete_ELcLcLVomsProxySvc);
      instance.SetDeleteArray(&deleteArray_ELcLcLVomsProxySvc);
      instance.SetDestructor(&destruct_ELcLcLVomsProxySvc);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::VomsProxySvc*)
   {
      return GenerateInitInstanceLocal((::EL::VomsProxySvc*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::VomsProxySvc*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static TClass *ELcLcLWorker_Dictionary();
   static void ELcLcLWorker_TClassManip(TClass*);
   static void delete_ELcLcLWorker(void *p);
   static void deleteArray_ELcLcLWorker(void *p);
   static void destruct_ELcLcLWorker(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::Worker*)
   {
      ::EL::Worker *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::EL::Worker));
      static ::ROOT::TGenericClassInfo 
         instance("EL::Worker", "EventLoop/Worker.h", 49,
                  typeid(::EL::Worker), DefineBehavior(ptr, ptr),
                  &ELcLcLWorker_Dictionary, isa_proxy, 4,
                  sizeof(::EL::Worker) );
      instance.SetDelete(&delete_ELcLcLWorker);
      instance.SetDeleteArray(&deleteArray_ELcLcLWorker);
      instance.SetDestructor(&destruct_ELcLcLWorker);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::Worker*)
   {
      return GenerateInitInstanceLocal((::EL::Worker*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::Worker*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ELcLcLWorker_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::EL::Worker*)0x0)->GetClass();
      ELcLcLWorker_TClassManip(theClass);
   return theClass;
   }

   static void ELcLcLWorker_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *pairlELong64_tcOLong64_tgR_Dictionary();
   static void pairlELong64_tcOLong64_tgR_TClassManip(TClass*);
   static void *new_pairlELong64_tcOLong64_tgR(void *p = 0);
   static void *newArray_pairlELong64_tcOLong64_tgR(Long_t size, void *p);
   static void delete_pairlELong64_tcOLong64_tgR(void *p);
   static void deleteArray_pairlELong64_tcOLong64_tgR(void *p);
   static void destruct_pairlELong64_tcOLong64_tgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const pair<Long64_t,Long64_t>*)
   {
      pair<Long64_t,Long64_t> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(pair<Long64_t,Long64_t>));
      static ::ROOT::TGenericClassInfo 
         instance("pair<Long64_t,Long64_t>", "string", 96,
                  typeid(pair<Long64_t,Long64_t>), DefineBehavior(ptr, ptr),
                  &pairlELong64_tcOLong64_tgR_Dictionary, isa_proxy, 4,
                  sizeof(pair<Long64_t,Long64_t>) );
      instance.SetNew(&new_pairlELong64_tcOLong64_tgR);
      instance.SetNewArray(&newArray_pairlELong64_tcOLong64_tgR);
      instance.SetDelete(&delete_pairlELong64_tcOLong64_tgR);
      instance.SetDeleteArray(&deleteArray_pairlELong64_tcOLong64_tgR);
      instance.SetDestructor(&destruct_pairlELong64_tcOLong64_tgR);
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const pair<Long64_t,Long64_t>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *pairlELong64_tcOLong64_tgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const pair<Long64_t,Long64_t>*)0x0)->GetClass();
      pairlELong64_tcOLong64_tgR_TClassManip(theClass);
   return theClass;
   }

   static void pairlELong64_tcOLong64_tgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static void *new_ELcLcLTEventSvc(void *p = 0);
   static void *newArray_ELcLcLTEventSvc(Long_t size, void *p);
   static void delete_ELcLcLTEventSvc(void *p);
   static void deleteArray_ELcLcLTEventSvc(void *p);
   static void destruct_ELcLcLTEventSvc(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EL::TEventSvc*)
   {
      ::EL::TEventSvc *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EL::TEventSvc >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EL::TEventSvc", ::EL::TEventSvc::Class_Version(), "EventLoop/TEventSvc.h", 35,
                  typeid(::EL::TEventSvc), DefineBehavior(ptr, ptr),
                  &::EL::TEventSvc::Dictionary, isa_proxy, 4,
                  sizeof(::EL::TEventSvc) );
      instance.SetNew(&new_ELcLcLTEventSvc);
      instance.SetNewArray(&newArray_ELcLcLTEventSvc);
      instance.SetDelete(&delete_ELcLcLTEventSvc);
      instance.SetDeleteArray(&deleteArray_ELcLcLTEventSvc);
      instance.SetDestructor(&destruct_ELcLcLTEventSvc);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EL::TEventSvc*)
   {
      return GenerateInitInstanceLocal((::EL::TEventSvc*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EL::TEventSvc*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace EL {
//______________________________________________________________________________
atomic_TClass_ptr Algorithm::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *Algorithm::Class_Name()
{
   return "EL::Algorithm";
}

//______________________________________________________________________________
const char *Algorithm::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::Algorithm*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int Algorithm::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::Algorithm*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Algorithm::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::Algorithm*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Algorithm::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::Algorithm*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace EL
namespace EL {
//______________________________________________________________________________
atomic_TClass_ptr BackgroundDriver::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *BackgroundDriver::Class_Name()
{
   return "EL::BackgroundDriver";
}

//______________________________________________________________________________
const char *BackgroundDriver::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::BackgroundDriver*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int BackgroundDriver::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::BackgroundDriver*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *BackgroundDriver::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::BackgroundDriver*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *BackgroundDriver::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::BackgroundDriver*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace EL
namespace EL {
//______________________________________________________________________________
atomic_TClass_ptr BackgroundJob::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *BackgroundJob::Class_Name()
{
   return "EL::BackgroundJob";
}

//______________________________________________________________________________
const char *BackgroundJob::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::BackgroundJob*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int BackgroundJob::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::BackgroundJob*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *BackgroundJob::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::BackgroundJob*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *BackgroundJob::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::BackgroundJob*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace EL
namespace EL {
//______________________________________________________________________________
atomic_TClass_ptr BackgroundTSelector::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *BackgroundTSelector::Class_Name()
{
   return "EL::BackgroundTSelector";
}

//______________________________________________________________________________
const char *BackgroundTSelector::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::BackgroundTSelector*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int BackgroundTSelector::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::BackgroundTSelector*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *BackgroundTSelector::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::BackgroundTSelector*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *BackgroundTSelector::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::BackgroundTSelector*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace EL
namespace EL {
//______________________________________________________________________________
atomic_TClass_ptr BatchDriver::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *BatchDriver::Class_Name()
{
   return "EL::BatchDriver";
}

//______________________________________________________________________________
const char *BatchDriver::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::BatchDriver*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int BatchDriver::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::BatchDriver*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *BatchDriver::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::BatchDriver*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *BatchDriver::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::BatchDriver*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace EL
namespace EL {
//______________________________________________________________________________
atomic_TClass_ptr BatchJob::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *BatchJob::Class_Name()
{
   return "EL::BatchJob";
}

//______________________________________________________________________________
const char *BatchJob::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::BatchJob*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int BatchJob::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::BatchJob*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *BatchJob::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::BatchJob*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *BatchJob::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::BatchJob*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace EL
namespace EL {
//______________________________________________________________________________
atomic_TClass_ptr BatchSample::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *BatchSample::Class_Name()
{
   return "EL::BatchSample";
}

//______________________________________________________________________________
const char *BatchSample::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::BatchSample*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int BatchSample::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::BatchSample*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *BatchSample::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::BatchSample*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *BatchSample::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::BatchSample*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace EL
namespace EL {
//______________________________________________________________________________
atomic_TClass_ptr BatchSegment::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *BatchSegment::Class_Name()
{
   return "EL::BatchSegment";
}

//______________________________________________________________________________
const char *BatchSegment::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::BatchSegment*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int BatchSegment::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::BatchSegment*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *BatchSegment::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::BatchSegment*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *BatchSegment::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::BatchSegment*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace EL
namespace EL {
//______________________________________________________________________________
atomic_TClass_ptr CondorDriver::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *CondorDriver::Class_Name()
{
   return "EL::CondorDriver";
}

//______________________________________________________________________________
const char *CondorDriver::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::CondorDriver*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int CondorDriver::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::CondorDriver*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *CondorDriver::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::CondorDriver*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *CondorDriver::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::CondorDriver*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace EL
namespace EL {
//______________________________________________________________________________
atomic_TClass_ptr DirectDriver::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *DirectDriver::Class_Name()
{
   return "EL::DirectDriver";
}

//______________________________________________________________________________
const char *DirectDriver::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::DirectDriver*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int DirectDriver::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::DirectDriver*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *DirectDriver::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::DirectDriver*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *DirectDriver::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::DirectDriver*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace EL
namespace EL {
//______________________________________________________________________________
atomic_TClass_ptr Driver::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *Driver::Class_Name()
{
   return "EL::Driver";
}

//______________________________________________________________________________
const char *Driver::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::Driver*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int Driver::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::Driver*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Driver::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::Driver*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Driver::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::Driver*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace EL
namespace EL {
//______________________________________________________________________________
atomic_TClass_ptr GEDriver::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *GEDriver::Class_Name()
{
   return "EL::GEDriver";
}

//______________________________________________________________________________
const char *GEDriver::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::GEDriver*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int GEDriver::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::GEDriver*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *GEDriver::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::GEDriver*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *GEDriver::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::GEDriver*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace EL
namespace EL {
//______________________________________________________________________________
atomic_TClass_ptr LSFDriver::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *LSFDriver::Class_Name()
{
   return "EL::LSFDriver";
}

//______________________________________________________________________________
const char *LSFDriver::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::LSFDriver*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int LSFDriver::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::LSFDriver*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *LSFDriver::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::LSFDriver*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *LSFDriver::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::LSFDriver*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace EL
namespace EL {
//______________________________________________________________________________
atomic_TClass_ptr LLDriver::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *LLDriver::Class_Name()
{
   return "EL::LLDriver";
}

//______________________________________________________________________________
const char *LLDriver::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::LLDriver*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int LLDriver::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::LLDriver*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *LLDriver::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::LLDriver*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *LLDriver::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::LLDriver*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace EL
namespace EL {
//______________________________________________________________________________
atomic_TClass_ptr LocalDriver::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *LocalDriver::Class_Name()
{
   return "EL::LocalDriver";
}

//______________________________________________________________________________
const char *LocalDriver::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::LocalDriver*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int LocalDriver::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::LocalDriver*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *LocalDriver::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::LocalDriver*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *LocalDriver::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::LocalDriver*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace EL
namespace EL {
//______________________________________________________________________________
atomic_TClass_ptr OutputStream::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *OutputStream::Class_Name()
{
   return "EL::OutputStream";
}

//______________________________________________________________________________
const char *OutputStream::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::OutputStream*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int OutputStream::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::OutputStream*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *OutputStream::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::OutputStream*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *OutputStream::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::OutputStream*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace EL
namespace EL {
//______________________________________________________________________________
atomic_TClass_ptr MetricsSvc::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MetricsSvc::Class_Name()
{
   return "EL::MetricsSvc";
}

//______________________________________________________________________________
const char *MetricsSvc::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::MetricsSvc*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MetricsSvc::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::MetricsSvc*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MetricsSvc::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::MetricsSvc*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MetricsSvc::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::MetricsSvc*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace EL
namespace EL {
//______________________________________________________________________________
atomic_TClass_ptr ProofArgs::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *ProofArgs::Class_Name()
{
   return "EL::ProofArgs";
}

//______________________________________________________________________________
const char *ProofArgs::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::ProofArgs*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int ProofArgs::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::ProofArgs*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ProofArgs::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::ProofArgs*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ProofArgs::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::ProofArgs*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace EL
namespace EL {
//______________________________________________________________________________
atomic_TClass_ptr ProofDriver::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *ProofDriver::Class_Name()
{
   return "EL::ProofDriver";
}

//______________________________________________________________________________
const char *ProofDriver::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::ProofDriver*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int ProofDriver::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::ProofDriver*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ProofDriver::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::ProofDriver*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ProofDriver::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::ProofDriver*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace EL
namespace EL {
//______________________________________________________________________________
atomic_TClass_ptr ProofTSelector::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *ProofTSelector::Class_Name()
{
   return "EL::ProofTSelector";
}

//______________________________________________________________________________
const char *ProofTSelector::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::ProofTSelector*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int ProofTSelector::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::ProofTSelector*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ProofTSelector::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::ProofTSelector*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ProofTSelector::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::ProofTSelector*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace EL
namespace EL {
//______________________________________________________________________________
atomic_TClass_ptr SlurmDriver::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *SlurmDriver::Class_Name()
{
   return "EL::SlurmDriver";
}

//______________________________________________________________________________
const char *SlurmDriver::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::SlurmDriver*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int SlurmDriver::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::SlurmDriver*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *SlurmDriver::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::SlurmDriver*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *SlurmDriver::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::SlurmDriver*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace EL
namespace EL {
//______________________________________________________________________________
atomic_TClass_ptr SoGEDriver::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *SoGEDriver::Class_Name()
{
   return "EL::SoGEDriver";
}

//______________________________________________________________________________
const char *SoGEDriver::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::SoGEDriver*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int SoGEDriver::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::SoGEDriver*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *SoGEDriver::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::SoGEDriver*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *SoGEDriver::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::SoGEDriver*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace EL
namespace EL {
//______________________________________________________________________________
atomic_TClass_ptr TorqueDriver::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TorqueDriver::Class_Name()
{
   return "EL::TorqueDriver";
}

//______________________________________________________________________________
const char *TorqueDriver::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::TorqueDriver*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TorqueDriver::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::TorqueDriver*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TorqueDriver::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::TorqueDriver*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TorqueDriver::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::TorqueDriver*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace EL
namespace EL {
//______________________________________________________________________________
atomic_TClass_ptr UnitTestAlg::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *UnitTestAlg::Class_Name()
{
   return "EL::UnitTestAlg";
}

//______________________________________________________________________________
const char *UnitTestAlg::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::UnitTestAlg*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int UnitTestAlg::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::UnitTestAlg*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *UnitTestAlg::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::UnitTestAlg*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *UnitTestAlg::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::UnitTestAlg*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace EL
namespace EL {
//______________________________________________________________________________
atomic_TClass_ptr UnitTestAlg1::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *UnitTestAlg1::Class_Name()
{
   return "EL::UnitTestAlg1";
}

//______________________________________________________________________________
const char *UnitTestAlg1::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::UnitTestAlg1*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int UnitTestAlg1::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::UnitTestAlg1*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *UnitTestAlg1::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::UnitTestAlg1*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *UnitTestAlg1::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::UnitTestAlg1*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace EL
namespace EL {
//______________________________________________________________________________
atomic_TClass_ptr VomsProxySvc::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *VomsProxySvc::Class_Name()
{
   return "EL::VomsProxySvc";
}

//______________________________________________________________________________
const char *VomsProxySvc::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::VomsProxySvc*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int VomsProxySvc::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::VomsProxySvc*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *VomsProxySvc::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::VomsProxySvc*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *VomsProxySvc::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::VomsProxySvc*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace EL
namespace EL {
//______________________________________________________________________________
atomic_TClass_ptr TEventSvc::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TEventSvc::Class_Name()
{
   return "EL::TEventSvc";
}

//______________________________________________________________________________
const char *TEventSvc::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::TEventSvc*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TEventSvc::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EL::TEventSvc*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TEventSvc::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::TEventSvc*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TEventSvc::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EL::TEventSvc*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace EL
namespace EL {
//______________________________________________________________________________
void Algorithm::Streamer(TBuffer &R__b)
{
   // Stream an object of class EL::Algorithm.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EL::Algorithm::Class(),this);
   } else {
      R__b.WriteClassBuffer(EL::Algorithm::Class(),this);
   }
}

} // namespace EL
namespace ROOT {
   // Wrappers around operator new
   static void *new_ELcLcLAlgorithm(void *p) {
      return  p ? new(p) ::EL::Algorithm : new ::EL::Algorithm;
   }
   static void *newArray_ELcLcLAlgorithm(Long_t nElements, void *p) {
      return p ? new(p) ::EL::Algorithm[nElements] : new ::EL::Algorithm[nElements];
   }
   // Wrapper around operator delete
   static void delete_ELcLcLAlgorithm(void *p) {
      delete ((::EL::Algorithm*)p);
   }
   static void deleteArray_ELcLcLAlgorithm(void *p) {
      delete [] ((::EL::Algorithm*)p);
   }
   static void destruct_ELcLcLAlgorithm(void *p) {
      typedef ::EL::Algorithm current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::Algorithm

namespace EL {
//______________________________________________________________________________
void BackgroundDriver::Streamer(TBuffer &R__b)
{
   // Stream an object of class EL::BackgroundDriver.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EL::BackgroundDriver::Class(),this);
   } else {
      R__b.WriteClassBuffer(EL::BackgroundDriver::Class(),this);
   }
}

} // namespace EL
namespace ROOT {
   // Wrappers around operator new
   static void *new_ELcLcLBackgroundDriver(void *p) {
      return  p ? new(p) ::EL::BackgroundDriver : new ::EL::BackgroundDriver;
   }
   static void *newArray_ELcLcLBackgroundDriver(Long_t nElements, void *p) {
      return p ? new(p) ::EL::BackgroundDriver[nElements] : new ::EL::BackgroundDriver[nElements];
   }
   // Wrapper around operator delete
   static void delete_ELcLcLBackgroundDriver(void *p) {
      delete ((::EL::BackgroundDriver*)p);
   }
   static void deleteArray_ELcLcLBackgroundDriver(void *p) {
      delete [] ((::EL::BackgroundDriver*)p);
   }
   static void destruct_ELcLcLBackgroundDriver(void *p) {
      typedef ::EL::BackgroundDriver current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::BackgroundDriver

namespace EL {
//______________________________________________________________________________
void BackgroundJob::Streamer(TBuffer &R__b)
{
   // Stream an object of class EL::BackgroundJob.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EL::BackgroundJob::Class(),this);
   } else {
      R__b.WriteClassBuffer(EL::BackgroundJob::Class(),this);
   }
}

} // namespace EL
namespace ROOT {
   // Wrappers around operator new
   static void *new_ELcLcLBackgroundJob(void *p) {
      return  p ? new(p) ::EL::BackgroundJob : new ::EL::BackgroundJob;
   }
   static void *newArray_ELcLcLBackgroundJob(Long_t nElements, void *p) {
      return p ? new(p) ::EL::BackgroundJob[nElements] : new ::EL::BackgroundJob[nElements];
   }
   // Wrapper around operator delete
   static void delete_ELcLcLBackgroundJob(void *p) {
      delete ((::EL::BackgroundJob*)p);
   }
   static void deleteArray_ELcLcLBackgroundJob(void *p) {
      delete [] ((::EL::BackgroundJob*)p);
   }
   static void destruct_ELcLcLBackgroundJob(void *p) {
      typedef ::EL::BackgroundJob current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::BackgroundJob

namespace EL {
//______________________________________________________________________________
void BackgroundTSelector::Streamer(TBuffer &R__b)
{
   // Stream an object of class EL::BackgroundTSelector.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EL::BackgroundTSelector::Class(),this);
   } else {
      R__b.WriteClassBuffer(EL::BackgroundTSelector::Class(),this);
   }
}

} // namespace EL
namespace ROOT {
   // Wrappers around operator new
   static void *new_ELcLcLBackgroundTSelector(void *p) {
      return  p ? new(p) ::EL::BackgroundTSelector : new ::EL::BackgroundTSelector;
   }
   static void *newArray_ELcLcLBackgroundTSelector(Long_t nElements, void *p) {
      return p ? new(p) ::EL::BackgroundTSelector[nElements] : new ::EL::BackgroundTSelector[nElements];
   }
   // Wrapper around operator delete
   static void delete_ELcLcLBackgroundTSelector(void *p) {
      delete ((::EL::BackgroundTSelector*)p);
   }
   static void deleteArray_ELcLcLBackgroundTSelector(void *p) {
      delete [] ((::EL::BackgroundTSelector*)p);
   }
   static void destruct_ELcLcLBackgroundTSelector(void *p) {
      typedef ::EL::BackgroundTSelector current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::BackgroundTSelector

namespace ROOT {
   // Wrapper around operator delete
   static void delete_ELcLcLBackgroundWorker(void *p) {
      delete ((::EL::BackgroundWorker*)p);
   }
   static void deleteArray_ELcLcLBackgroundWorker(void *p) {
      delete [] ((::EL::BackgroundWorker*)p);
   }
   static void destruct_ELcLcLBackgroundWorker(void *p) {
      typedef ::EL::BackgroundWorker current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::BackgroundWorker

namespace EL {
//______________________________________________________________________________
void BatchDriver::Streamer(TBuffer &R__b)
{
   // Stream an object of class EL::BatchDriver.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EL::BatchDriver::Class(),this);
   } else {
      R__b.WriteClassBuffer(EL::BatchDriver::Class(),this);
   }
}

} // namespace EL
namespace ROOT {
   // Wrapper around operator delete
   static void delete_ELcLcLBatchDriver(void *p) {
      delete ((::EL::BatchDriver*)p);
   }
   static void deleteArray_ELcLcLBatchDriver(void *p) {
      delete [] ((::EL::BatchDriver*)p);
   }
   static void destruct_ELcLcLBatchDriver(void *p) {
      typedef ::EL::BatchDriver current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::BatchDriver

namespace EL {
//______________________________________________________________________________
void BatchJob::Streamer(TBuffer &R__b)
{
   // Stream an object of class EL::BatchJob.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EL::BatchJob::Class(),this);
   } else {
      R__b.WriteClassBuffer(EL::BatchJob::Class(),this);
   }
}

} // namespace EL
namespace ROOT {
   // Wrappers around operator new
   static void *new_ELcLcLBatchJob(void *p) {
      return  p ? new(p) ::EL::BatchJob : new ::EL::BatchJob;
   }
   static void *newArray_ELcLcLBatchJob(Long_t nElements, void *p) {
      return p ? new(p) ::EL::BatchJob[nElements] : new ::EL::BatchJob[nElements];
   }
   // Wrapper around operator delete
   static void delete_ELcLcLBatchJob(void *p) {
      delete ((::EL::BatchJob*)p);
   }
   static void deleteArray_ELcLcLBatchJob(void *p) {
      delete [] ((::EL::BatchJob*)p);
   }
   static void destruct_ELcLcLBatchJob(void *p) {
      typedef ::EL::BatchJob current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::BatchJob

namespace EL {
//______________________________________________________________________________
void BatchSample::Streamer(TBuffer &R__b)
{
   // Stream an object of class EL::BatchSample.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EL::BatchSample::Class(),this);
   } else {
      R__b.WriteClassBuffer(EL::BatchSample::Class(),this);
   }
}

} // namespace EL
namespace ROOT {
   // Wrappers around operator new
   static void *new_ELcLcLBatchSample(void *p) {
      return  p ? new(p) ::EL::BatchSample : new ::EL::BatchSample;
   }
   static void *newArray_ELcLcLBatchSample(Long_t nElements, void *p) {
      return p ? new(p) ::EL::BatchSample[nElements] : new ::EL::BatchSample[nElements];
   }
   // Wrapper around operator delete
   static void delete_ELcLcLBatchSample(void *p) {
      delete ((::EL::BatchSample*)p);
   }
   static void deleteArray_ELcLcLBatchSample(void *p) {
      delete [] ((::EL::BatchSample*)p);
   }
   static void destruct_ELcLcLBatchSample(void *p) {
      typedef ::EL::BatchSample current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::BatchSample

namespace EL {
//______________________________________________________________________________
void BatchSegment::Streamer(TBuffer &R__b)
{
   // Stream an object of class EL::BatchSegment.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EL::BatchSegment::Class(),this);
   } else {
      R__b.WriteClassBuffer(EL::BatchSegment::Class(),this);
   }
}

} // namespace EL
namespace ROOT {
   // Wrappers around operator new
   static void *new_ELcLcLBatchSegment(void *p) {
      return  p ? new(p) ::EL::BatchSegment : new ::EL::BatchSegment;
   }
   static void *newArray_ELcLcLBatchSegment(Long_t nElements, void *p) {
      return p ? new(p) ::EL::BatchSegment[nElements] : new ::EL::BatchSegment[nElements];
   }
   // Wrapper around operator delete
   static void delete_ELcLcLBatchSegment(void *p) {
      delete ((::EL::BatchSegment*)p);
   }
   static void deleteArray_ELcLcLBatchSegment(void *p) {
      delete [] ((::EL::BatchSegment*)p);
   }
   static void destruct_ELcLcLBatchSegment(void *p) {
      typedef ::EL::BatchSegment current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::BatchSegment

namespace ROOT {
   // Wrapper around operator delete
   static void delete_ELcLcLBatchWorker(void *p) {
      delete ((::EL::BatchWorker*)p);
   }
   static void deleteArray_ELcLcLBatchWorker(void *p) {
      delete [] ((::EL::BatchWorker*)p);
   }
   static void destruct_ELcLcLBatchWorker(void *p) {
      typedef ::EL::BatchWorker current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::BatchWorker

namespace EL {
//______________________________________________________________________________
void CondorDriver::Streamer(TBuffer &R__b)
{
   // Stream an object of class EL::CondorDriver.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EL::CondorDriver::Class(),this);
   } else {
      R__b.WriteClassBuffer(EL::CondorDriver::Class(),this);
   }
}

} // namespace EL
namespace ROOT {
   // Wrappers around operator new
   static void *new_ELcLcLCondorDriver(void *p) {
      return  p ? new(p) ::EL::CondorDriver : new ::EL::CondorDriver;
   }
   static void *newArray_ELcLcLCondorDriver(Long_t nElements, void *p) {
      return p ? new(p) ::EL::CondorDriver[nElements] : new ::EL::CondorDriver[nElements];
   }
   // Wrapper around operator delete
   static void delete_ELcLcLCondorDriver(void *p) {
      delete ((::EL::CondorDriver*)p);
   }
   static void deleteArray_ELcLcLCondorDriver(void *p) {
      delete [] ((::EL::CondorDriver*)p);
   }
   static void destruct_ELcLcLCondorDriver(void *p) {
      typedef ::EL::CondorDriver current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::CondorDriver

namespace EL {
//______________________________________________________________________________
void DirectDriver::Streamer(TBuffer &R__b)
{
   // Stream an object of class EL::DirectDriver.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EL::DirectDriver::Class(),this);
   } else {
      R__b.WriteClassBuffer(EL::DirectDriver::Class(),this);
   }
}

} // namespace EL
namespace ROOT {
   // Wrappers around operator new
   static void *new_ELcLcLDirectDriver(void *p) {
      return  p ? new(p) ::EL::DirectDriver : new ::EL::DirectDriver;
   }
   static void *newArray_ELcLcLDirectDriver(Long_t nElements, void *p) {
      return p ? new(p) ::EL::DirectDriver[nElements] : new ::EL::DirectDriver[nElements];
   }
   // Wrapper around operator delete
   static void delete_ELcLcLDirectDriver(void *p) {
      delete ((::EL::DirectDriver*)p);
   }
   static void deleteArray_ELcLcLDirectDriver(void *p) {
      delete [] ((::EL::DirectDriver*)p);
   }
   static void destruct_ELcLcLDirectDriver(void *p) {
      typedef ::EL::DirectDriver current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::DirectDriver

namespace EL {
//______________________________________________________________________________
void Driver::Streamer(TBuffer &R__b)
{
   // Stream an object of class EL::Driver.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EL::Driver::Class(),this);
   } else {
      R__b.WriteClassBuffer(EL::Driver::Class(),this);
   }
}

} // namespace EL
namespace ROOT {
   // Wrappers around operator new
   static void *new_ELcLcLDriver(void *p) {
      return  p ? new(p) ::EL::Driver : new ::EL::Driver;
   }
   static void *newArray_ELcLcLDriver(Long_t nElements, void *p) {
      return p ? new(p) ::EL::Driver[nElements] : new ::EL::Driver[nElements];
   }
   // Wrapper around operator delete
   static void delete_ELcLcLDriver(void *p) {
      delete ((::EL::Driver*)p);
   }
   static void deleteArray_ELcLcLDriver(void *p) {
      delete [] ((::EL::Driver*)p);
   }
   static void destruct_ELcLcLDriver(void *p) {
      typedef ::EL::Driver current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::Driver

namespace ROOT {
   // Wrappers around operator new
   static void *new_ELcLcLJob(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::EL::Job : new ::EL::Job;
   }
   static void *newArray_ELcLcLJob(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::EL::Job[nElements] : new ::EL::Job[nElements];
   }
   // Wrapper around operator delete
   static void delete_ELcLcLJob(void *p) {
      delete ((::EL::Job*)p);
   }
   static void deleteArray_ELcLcLJob(void *p) {
      delete [] ((::EL::Job*)p);
   }
   static void destruct_ELcLcLJob(void *p) {
      typedef ::EL::Job current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::Job

namespace EL {
//______________________________________________________________________________
void GEDriver::Streamer(TBuffer &R__b)
{
   // Stream an object of class EL::GEDriver.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EL::GEDriver::Class(),this);
   } else {
      R__b.WriteClassBuffer(EL::GEDriver::Class(),this);
   }
}

} // namespace EL
namespace ROOT {
   // Wrappers around operator new
   static void *new_ELcLcLGEDriver(void *p) {
      return  p ? new(p) ::EL::GEDriver : new ::EL::GEDriver;
   }
   static void *newArray_ELcLcLGEDriver(Long_t nElements, void *p) {
      return p ? new(p) ::EL::GEDriver[nElements] : new ::EL::GEDriver[nElements];
   }
   // Wrapper around operator delete
   static void delete_ELcLcLGEDriver(void *p) {
      delete ((::EL::GEDriver*)p);
   }
   static void deleteArray_ELcLcLGEDriver(void *p) {
      delete [] ((::EL::GEDriver*)p);
   }
   static void destruct_ELcLcLGEDriver(void *p) {
      typedef ::EL::GEDriver current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::GEDriver

namespace EL {
//______________________________________________________________________________
void LSFDriver::Streamer(TBuffer &R__b)
{
   // Stream an object of class EL::LSFDriver.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EL::LSFDriver::Class(),this);
   } else {
      R__b.WriteClassBuffer(EL::LSFDriver::Class(),this);
   }
}

} // namespace EL
namespace ROOT {
   // Wrappers around operator new
   static void *new_ELcLcLLSFDriver(void *p) {
      return  p ? new(p) ::EL::LSFDriver : new ::EL::LSFDriver;
   }
   static void *newArray_ELcLcLLSFDriver(Long_t nElements, void *p) {
      return p ? new(p) ::EL::LSFDriver[nElements] : new ::EL::LSFDriver[nElements];
   }
   // Wrapper around operator delete
   static void delete_ELcLcLLSFDriver(void *p) {
      delete ((::EL::LSFDriver*)p);
   }
   static void deleteArray_ELcLcLLSFDriver(void *p) {
      delete [] ((::EL::LSFDriver*)p);
   }
   static void destruct_ELcLcLLSFDriver(void *p) {
      typedef ::EL::LSFDriver current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::LSFDriver

namespace EL {
//______________________________________________________________________________
void LLDriver::Streamer(TBuffer &R__b)
{
   // Stream an object of class EL::LLDriver.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EL::LLDriver::Class(),this);
   } else {
      R__b.WriteClassBuffer(EL::LLDriver::Class(),this);
   }
}

} // namespace EL
namespace ROOT {
   // Wrappers around operator new
   static void *new_ELcLcLLLDriver(void *p) {
      return  p ? new(p) ::EL::LLDriver : new ::EL::LLDriver;
   }
   static void *newArray_ELcLcLLLDriver(Long_t nElements, void *p) {
      return p ? new(p) ::EL::LLDriver[nElements] : new ::EL::LLDriver[nElements];
   }
   // Wrapper around operator delete
   static void delete_ELcLcLLLDriver(void *p) {
      delete ((::EL::LLDriver*)p);
   }
   static void deleteArray_ELcLcLLLDriver(void *p) {
      delete [] ((::EL::LLDriver*)p);
   }
   static void destruct_ELcLcLLLDriver(void *p) {
      typedef ::EL::LLDriver current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::LLDriver

namespace EL {
//______________________________________________________________________________
void LocalDriver::Streamer(TBuffer &R__b)
{
   // Stream an object of class EL::LocalDriver.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EL::LocalDriver::Class(),this);
   } else {
      R__b.WriteClassBuffer(EL::LocalDriver::Class(),this);
   }
}

} // namespace EL
namespace ROOT {
   // Wrappers around operator new
   static void *new_ELcLcLLocalDriver(void *p) {
      return  p ? new(p) ::EL::LocalDriver : new ::EL::LocalDriver;
   }
   static void *newArray_ELcLcLLocalDriver(Long_t nElements, void *p) {
      return p ? new(p) ::EL::LocalDriver[nElements] : new ::EL::LocalDriver[nElements];
   }
   // Wrapper around operator delete
   static void delete_ELcLcLLocalDriver(void *p) {
      delete ((::EL::LocalDriver*)p);
   }
   static void deleteArray_ELcLcLLocalDriver(void *p) {
      delete [] ((::EL::LocalDriver*)p);
   }
   static void destruct_ELcLcLLocalDriver(void *p) {
      typedef ::EL::LocalDriver current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::LocalDriver

namespace EL {
//______________________________________________________________________________
void OutputStream::Streamer(TBuffer &R__b)
{
   // Stream an object of class EL::OutputStream.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EL::OutputStream::Class(),this);
   } else {
      R__b.WriteClassBuffer(EL::OutputStream::Class(),this);
   }
}

} // namespace EL
namespace ROOT {
   // Wrappers around operator new
   static void *new_ELcLcLOutputStream(void *p) {
      return  p ? new(p) ::EL::OutputStream : new ::EL::OutputStream;
   }
   static void *newArray_ELcLcLOutputStream(Long_t nElements, void *p) {
      return p ? new(p) ::EL::OutputStream[nElements] : new ::EL::OutputStream[nElements];
   }
   // Wrapper around operator delete
   static void delete_ELcLcLOutputStream(void *p) {
      delete ((::EL::OutputStream*)p);
   }
   static void deleteArray_ELcLcLOutputStream(void *p) {
      delete [] ((::EL::OutputStream*)p);
   }
   static void destruct_ELcLcLOutputStream(void *p) {
      typedef ::EL::OutputStream current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::OutputStream

namespace EL {
//______________________________________________________________________________
void MetricsSvc::Streamer(TBuffer &R__b)
{
   // Stream an object of class EL::MetricsSvc.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EL::MetricsSvc::Class(),this);
   } else {
      R__b.WriteClassBuffer(EL::MetricsSvc::Class(),this);
   }
}

} // namespace EL
namespace ROOT {
   // Wrappers around operator new
   static void *new_ELcLcLMetricsSvc(void *p) {
      return  p ? new(p) ::EL::MetricsSvc : new ::EL::MetricsSvc;
   }
   static void *newArray_ELcLcLMetricsSvc(Long_t nElements, void *p) {
      return p ? new(p) ::EL::MetricsSvc[nElements] : new ::EL::MetricsSvc[nElements];
   }
   // Wrapper around operator delete
   static void delete_ELcLcLMetricsSvc(void *p) {
      delete ((::EL::MetricsSvc*)p);
   }
   static void deleteArray_ELcLcLMetricsSvc(void *p) {
      delete [] ((::EL::MetricsSvc*)p);
   }
   static void destruct_ELcLcLMetricsSvc(void *p) {
      typedef ::EL::MetricsSvc current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::MetricsSvc

namespace EL {
//______________________________________________________________________________
void ProofArgs::Streamer(TBuffer &R__b)
{
   // Stream an object of class EL::ProofArgs.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EL::ProofArgs::Class(),this);
   } else {
      R__b.WriteClassBuffer(EL::ProofArgs::Class(),this);
   }
}

} // namespace EL
namespace ROOT {
   // Wrappers around operator new
   static void *new_ELcLcLProofArgs(void *p) {
      return  p ? new(p) ::EL::ProofArgs : new ::EL::ProofArgs;
   }
   static void *newArray_ELcLcLProofArgs(Long_t nElements, void *p) {
      return p ? new(p) ::EL::ProofArgs[nElements] : new ::EL::ProofArgs[nElements];
   }
   // Wrapper around operator delete
   static void delete_ELcLcLProofArgs(void *p) {
      delete ((::EL::ProofArgs*)p);
   }
   static void deleteArray_ELcLcLProofArgs(void *p) {
      delete [] ((::EL::ProofArgs*)p);
   }
   static void destruct_ELcLcLProofArgs(void *p) {
      typedef ::EL::ProofArgs current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::ProofArgs

namespace EL {
//______________________________________________________________________________
void ProofDriver::Streamer(TBuffer &R__b)
{
   // Stream an object of class EL::ProofDriver.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EL::ProofDriver::Class(),this);
   } else {
      R__b.WriteClassBuffer(EL::ProofDriver::Class(),this);
   }
}

} // namespace EL
namespace ROOT {
   // Wrappers around operator new
   static void *new_ELcLcLProofDriver(void *p) {
      return  p ? new(p) ::EL::ProofDriver : new ::EL::ProofDriver;
   }
   static void *newArray_ELcLcLProofDriver(Long_t nElements, void *p) {
      return p ? new(p) ::EL::ProofDriver[nElements] : new ::EL::ProofDriver[nElements];
   }
   // Wrapper around operator delete
   static void delete_ELcLcLProofDriver(void *p) {
      delete ((::EL::ProofDriver*)p);
   }
   static void deleteArray_ELcLcLProofDriver(void *p) {
      delete [] ((::EL::ProofDriver*)p);
   }
   static void destruct_ELcLcLProofDriver(void *p) {
      typedef ::EL::ProofDriver current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::ProofDriver

namespace EL {
//______________________________________________________________________________
void ProofTSelector::Streamer(TBuffer &R__b)
{
   // Stream an object of class EL::ProofTSelector.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EL::ProofTSelector::Class(),this);
   } else {
      R__b.WriteClassBuffer(EL::ProofTSelector::Class(),this);
   }
}

} // namespace EL
namespace ROOT {
   // Wrappers around operator new
   static void *new_ELcLcLProofTSelector(void *p) {
      return  p ? new(p) ::EL::ProofTSelector : new ::EL::ProofTSelector;
   }
   static void *newArray_ELcLcLProofTSelector(Long_t nElements, void *p) {
      return p ? new(p) ::EL::ProofTSelector[nElements] : new ::EL::ProofTSelector[nElements];
   }
   // Wrapper around operator delete
   static void delete_ELcLcLProofTSelector(void *p) {
      delete ((::EL::ProofTSelector*)p);
   }
   static void deleteArray_ELcLcLProofTSelector(void *p) {
      delete [] ((::EL::ProofTSelector*)p);
   }
   static void destruct_ELcLcLProofTSelector(void *p) {
      typedef ::EL::ProofTSelector current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::ProofTSelector

namespace ROOT {
   // Wrapper around operator delete
   static void delete_ELcLcLProofWorker(void *p) {
      delete ((::EL::ProofWorker*)p);
   }
   static void deleteArray_ELcLcLProofWorker(void *p) {
      delete [] ((::EL::ProofWorker*)p);
   }
   static void destruct_ELcLcLProofWorker(void *p) {
      typedef ::EL::ProofWorker current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::ProofWorker

namespace EL {
//______________________________________________________________________________
void SlurmDriver::Streamer(TBuffer &R__b)
{
   // Stream an object of class EL::SlurmDriver.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EL::SlurmDriver::Class(),this);
   } else {
      R__b.WriteClassBuffer(EL::SlurmDriver::Class(),this);
   }
}

} // namespace EL
namespace ROOT {
   // Wrappers around operator new
   static void *new_ELcLcLSlurmDriver(void *p) {
      return  p ? new(p) ::EL::SlurmDriver : new ::EL::SlurmDriver;
   }
   static void *newArray_ELcLcLSlurmDriver(Long_t nElements, void *p) {
      return p ? new(p) ::EL::SlurmDriver[nElements] : new ::EL::SlurmDriver[nElements];
   }
   // Wrapper around operator delete
   static void delete_ELcLcLSlurmDriver(void *p) {
      delete ((::EL::SlurmDriver*)p);
   }
   static void deleteArray_ELcLcLSlurmDriver(void *p) {
      delete [] ((::EL::SlurmDriver*)p);
   }
   static void destruct_ELcLcLSlurmDriver(void *p) {
      typedef ::EL::SlurmDriver current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::SlurmDriver

namespace EL {
//______________________________________________________________________________
void SoGEDriver::Streamer(TBuffer &R__b)
{
   // Stream an object of class EL::SoGEDriver.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EL::SoGEDriver::Class(),this);
   } else {
      R__b.WriteClassBuffer(EL::SoGEDriver::Class(),this);
   }
}

} // namespace EL
namespace ROOT {
   // Wrappers around operator new
   static void *new_ELcLcLSoGEDriver(void *p) {
      return  p ? new(p) ::EL::SoGEDriver : new ::EL::SoGEDriver;
   }
   static void *newArray_ELcLcLSoGEDriver(Long_t nElements, void *p) {
      return p ? new(p) ::EL::SoGEDriver[nElements] : new ::EL::SoGEDriver[nElements];
   }
   // Wrapper around operator delete
   static void delete_ELcLcLSoGEDriver(void *p) {
      delete ((::EL::SoGEDriver*)p);
   }
   static void deleteArray_ELcLcLSoGEDriver(void *p) {
      delete [] ((::EL::SoGEDriver*)p);
   }
   static void destruct_ELcLcLSoGEDriver(void *p) {
      typedef ::EL::SoGEDriver current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::SoGEDriver

namespace ROOT {
   // Wrappers around operator new
   static void *new_ELcLcLStatusCode(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::EL::StatusCode : new ::EL::StatusCode;
   }
   static void *newArray_ELcLcLStatusCode(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::EL::StatusCode[nElements] : new ::EL::StatusCode[nElements];
   }
   // Wrapper around operator delete
   static void delete_ELcLcLStatusCode(void *p) {
      delete ((::EL::StatusCode*)p);
   }
   static void deleteArray_ELcLcLStatusCode(void *p) {
      delete [] ((::EL::StatusCode*)p);
   }
   static void destruct_ELcLcLStatusCode(void *p) {
      typedef ::EL::StatusCode current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::StatusCode

namespace EL {
//______________________________________________________________________________
void TorqueDriver::Streamer(TBuffer &R__b)
{
   // Stream an object of class EL::TorqueDriver.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EL::TorqueDriver::Class(),this);
   } else {
      R__b.WriteClassBuffer(EL::TorqueDriver::Class(),this);
   }
}

} // namespace EL
namespace ROOT {
   // Wrappers around operator new
   static void *new_ELcLcLTorqueDriver(void *p) {
      return  p ? new(p) ::EL::TorqueDriver : new ::EL::TorqueDriver;
   }
   static void *newArray_ELcLcLTorqueDriver(Long_t nElements, void *p) {
      return p ? new(p) ::EL::TorqueDriver[nElements] : new ::EL::TorqueDriver[nElements];
   }
   // Wrapper around operator delete
   static void delete_ELcLcLTorqueDriver(void *p) {
      delete ((::EL::TorqueDriver*)p);
   }
   static void deleteArray_ELcLcLTorqueDriver(void *p) {
      delete [] ((::EL::TorqueDriver*)p);
   }
   static void destruct_ELcLcLTorqueDriver(void *p) {
      typedef ::EL::TorqueDriver current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::TorqueDriver

namespace EL {
//______________________________________________________________________________
void UnitTestAlg::Streamer(TBuffer &R__b)
{
   // Stream an object of class EL::UnitTestAlg.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EL::UnitTestAlg::Class(),this);
   } else {
      R__b.WriteClassBuffer(EL::UnitTestAlg::Class(),this);
   }
}

} // namespace EL
namespace ROOT {
   // Wrappers around operator new
   static void *new_ELcLcLUnitTestAlg(void *p) {
      return  p ? new(p) ::EL::UnitTestAlg : new ::EL::UnitTestAlg;
   }
   static void *newArray_ELcLcLUnitTestAlg(Long_t nElements, void *p) {
      return p ? new(p) ::EL::UnitTestAlg[nElements] : new ::EL::UnitTestAlg[nElements];
   }
   // Wrapper around operator delete
   static void delete_ELcLcLUnitTestAlg(void *p) {
      delete ((::EL::UnitTestAlg*)p);
   }
   static void deleteArray_ELcLcLUnitTestAlg(void *p) {
      delete [] ((::EL::UnitTestAlg*)p);
   }
   static void destruct_ELcLcLUnitTestAlg(void *p) {
      typedef ::EL::UnitTestAlg current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::UnitTestAlg

namespace EL {
//______________________________________________________________________________
void UnitTestAlg1::Streamer(TBuffer &R__b)
{
   // Stream an object of class EL::UnitTestAlg1.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EL::UnitTestAlg1::Class(),this);
   } else {
      R__b.WriteClassBuffer(EL::UnitTestAlg1::Class(),this);
   }
}

} // namespace EL
namespace ROOT {
   // Wrappers around operator new
   static void *new_ELcLcLUnitTestAlg1(void *p) {
      return  p ? new(p) ::EL::UnitTestAlg1 : new ::EL::UnitTestAlg1;
   }
   static void *newArray_ELcLcLUnitTestAlg1(Long_t nElements, void *p) {
      return p ? new(p) ::EL::UnitTestAlg1[nElements] : new ::EL::UnitTestAlg1[nElements];
   }
   // Wrapper around operator delete
   static void delete_ELcLcLUnitTestAlg1(void *p) {
      delete ((::EL::UnitTestAlg1*)p);
   }
   static void deleteArray_ELcLcLUnitTestAlg1(void *p) {
      delete [] ((::EL::UnitTestAlg1*)p);
   }
   static void destruct_ELcLcLUnitTestAlg1(void *p) {
      typedef ::EL::UnitTestAlg1 current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::UnitTestAlg1

namespace EL {
//______________________________________________________________________________
void VomsProxySvc::Streamer(TBuffer &R__b)
{
   // Stream an object of class EL::VomsProxySvc.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EL::VomsProxySvc::Class(),this);
   } else {
      R__b.WriteClassBuffer(EL::VomsProxySvc::Class(),this);
   }
}

} // namespace EL
namespace ROOT {
   // Wrappers around operator new
   static void *new_ELcLcLVomsProxySvc(void *p) {
      return  p ? new(p) ::EL::VomsProxySvc : new ::EL::VomsProxySvc;
   }
   static void *newArray_ELcLcLVomsProxySvc(Long_t nElements, void *p) {
      return p ? new(p) ::EL::VomsProxySvc[nElements] : new ::EL::VomsProxySvc[nElements];
   }
   // Wrapper around operator delete
   static void delete_ELcLcLVomsProxySvc(void *p) {
      delete ((::EL::VomsProxySvc*)p);
   }
   static void deleteArray_ELcLcLVomsProxySvc(void *p) {
      delete [] ((::EL::VomsProxySvc*)p);
   }
   static void destruct_ELcLcLVomsProxySvc(void *p) {
      typedef ::EL::VomsProxySvc current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::VomsProxySvc

namespace ROOT {
   // Wrapper around operator delete
   static void delete_ELcLcLWorker(void *p) {
      delete ((::EL::Worker*)p);
   }
   static void deleteArray_ELcLcLWorker(void *p) {
      delete [] ((::EL::Worker*)p);
   }
   static void destruct_ELcLcLWorker(void *p) {
      typedef ::EL::Worker current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::Worker

namespace ROOT {
   // Wrappers around operator new
   static void *new_pairlELong64_tcOLong64_tgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) pair<Long64_t,Long64_t> : new pair<Long64_t,Long64_t>;
   }
   static void *newArray_pairlELong64_tcOLong64_tgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) pair<Long64_t,Long64_t>[nElements] : new pair<Long64_t,Long64_t>[nElements];
   }
   // Wrapper around operator delete
   static void delete_pairlELong64_tcOLong64_tgR(void *p) {
      delete ((pair<Long64_t,Long64_t>*)p);
   }
   static void deleteArray_pairlELong64_tcOLong64_tgR(void *p) {
      delete [] ((pair<Long64_t,Long64_t>*)p);
   }
   static void destruct_pairlELong64_tcOLong64_tgR(void *p) {
      typedef pair<Long64_t,Long64_t> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class pair<Long64_t,Long64_t>

namespace EL {
//______________________________________________________________________________
void TEventSvc::Streamer(TBuffer &R__b)
{
   // Stream an object of class EL::TEventSvc.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EL::TEventSvc::Class(),this);
   } else {
      R__b.WriteClassBuffer(EL::TEventSvc::Class(),this);
   }
}

} // namespace EL
namespace ROOT {
   // Wrappers around operator new
   static void *new_ELcLcLTEventSvc(void *p) {
      return  p ? new(p) ::EL::TEventSvc : new ::EL::TEventSvc;
   }
   static void *newArray_ELcLcLTEventSvc(Long_t nElements, void *p) {
      return p ? new(p) ::EL::TEventSvc[nElements] : new ::EL::TEventSvc[nElements];
   }
   // Wrapper around operator delete
   static void delete_ELcLcLTEventSvc(void *p) {
      delete ((::EL::TEventSvc*)p);
   }
   static void deleteArray_ELcLcLTEventSvc(void *p) {
      delete [] ((::EL::TEventSvc*)p);
   }
   static void destruct_ELcLcLTEventSvc(void *p) {
      typedef ::EL::TEventSvc current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EL::TEventSvc

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
                  &vectorlEunsignedsPintgR_Dictionary, isa_proxy, 0,
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
   static TClass *vectorlEpairlELong64_tcOLong64_tgRsPgR_Dictionary();
   static void vectorlEpairlELong64_tcOLong64_tgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEpairlELong64_tcOLong64_tgRsPgR(void *p = 0);
   static void *newArray_vectorlEpairlELong64_tcOLong64_tgRsPgR(Long_t size, void *p);
   static void delete_vectorlEpairlELong64_tcOLong64_tgRsPgR(void *p);
   static void deleteArray_vectorlEpairlELong64_tcOLong64_tgRsPgR(void *p);
   static void destruct_vectorlEpairlELong64_tcOLong64_tgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<pair<Long64_t,Long64_t> >*)
   {
      vector<pair<Long64_t,Long64_t> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<pair<Long64_t,Long64_t> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<pair<Long64_t,Long64_t> >", -2, "vector", 214,
                  typeid(vector<pair<Long64_t,Long64_t> >), DefineBehavior(ptr, ptr),
                  &vectorlEpairlELong64_tcOLong64_tgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<pair<Long64_t,Long64_t> >) );
      instance.SetNew(&new_vectorlEpairlELong64_tcOLong64_tgRsPgR);
      instance.SetNewArray(&newArray_vectorlEpairlELong64_tcOLong64_tgRsPgR);
      instance.SetDelete(&delete_vectorlEpairlELong64_tcOLong64_tgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEpairlELong64_tcOLong64_tgRsPgR);
      instance.SetDestructor(&destruct_vectorlEpairlELong64_tcOLong64_tgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<pair<Long64_t,Long64_t> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<pair<Long64_t,Long64_t> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEpairlELong64_tcOLong64_tgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<pair<Long64_t,Long64_t> >*)0x0)->GetClass();
      vectorlEpairlELong64_tcOLong64_tgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEpairlELong64_tcOLong64_tgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEpairlELong64_tcOLong64_tgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<pair<Long64_t,Long64_t> > : new vector<pair<Long64_t,Long64_t> >;
   }
   static void *newArray_vectorlEpairlELong64_tcOLong64_tgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<pair<Long64_t,Long64_t> >[nElements] : new vector<pair<Long64_t,Long64_t> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEpairlELong64_tcOLong64_tgRsPgR(void *p) {
      delete ((vector<pair<Long64_t,Long64_t> >*)p);
   }
   static void deleteArray_vectorlEpairlELong64_tcOLong64_tgRsPgR(void *p) {
      delete [] ((vector<pair<Long64_t,Long64_t> >*)p);
   }
   static void destruct_vectorlEpairlELong64_tcOLong64_tgRsPgR(void *p) {
      typedef vector<pair<Long64_t,Long64_t> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<pair<Long64_t,Long64_t> >

namespace ROOT {
   static TClass *vectorlEELcLcLOutputStreamgR_Dictionary();
   static void vectorlEELcLcLOutputStreamgR_TClassManip(TClass*);
   static void *new_vectorlEELcLcLOutputStreamgR(void *p = 0);
   static void *newArray_vectorlEELcLcLOutputStreamgR(Long_t size, void *p);
   static void delete_vectorlEELcLcLOutputStreamgR(void *p);
   static void deleteArray_vectorlEELcLcLOutputStreamgR(void *p);
   static void destruct_vectorlEELcLcLOutputStreamgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<EL::OutputStream>*)
   {
      vector<EL::OutputStream> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<EL::OutputStream>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<EL::OutputStream>", -2, "vector", 214,
                  typeid(vector<EL::OutputStream>), DefineBehavior(ptr, ptr),
                  &vectorlEELcLcLOutputStreamgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<EL::OutputStream>) );
      instance.SetNew(&new_vectorlEELcLcLOutputStreamgR);
      instance.SetNewArray(&newArray_vectorlEELcLcLOutputStreamgR);
      instance.SetDelete(&delete_vectorlEELcLcLOutputStreamgR);
      instance.SetDeleteArray(&deleteArray_vectorlEELcLcLOutputStreamgR);
      instance.SetDestructor(&destruct_vectorlEELcLcLOutputStreamgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<EL::OutputStream> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<EL::OutputStream>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEELcLcLOutputStreamgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<EL::OutputStream>*)0x0)->GetClass();
      vectorlEELcLcLOutputStreamgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEELcLcLOutputStreamgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEELcLcLOutputStreamgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<EL::OutputStream> : new vector<EL::OutputStream>;
   }
   static void *newArray_vectorlEELcLcLOutputStreamgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<EL::OutputStream>[nElements] : new vector<EL::OutputStream>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEELcLcLOutputStreamgR(void *p) {
      delete ((vector<EL::OutputStream>*)p);
   }
   static void deleteArray_vectorlEELcLcLOutputStreamgR(void *p) {
      delete [] ((vector<EL::OutputStream>*)p);
   }
   static void destruct_vectorlEELcLcLOutputStreamgR(void *p) {
      typedef vector<EL::OutputStream> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<EL::OutputStream>

namespace ROOT {
   static TClass *vectorlEELcLcLBatchSegmentgR_Dictionary();
   static void vectorlEELcLcLBatchSegmentgR_TClassManip(TClass*);
   static void *new_vectorlEELcLcLBatchSegmentgR(void *p = 0);
   static void *newArray_vectorlEELcLcLBatchSegmentgR(Long_t size, void *p);
   static void delete_vectorlEELcLcLBatchSegmentgR(void *p);
   static void deleteArray_vectorlEELcLcLBatchSegmentgR(void *p);
   static void destruct_vectorlEELcLcLBatchSegmentgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<EL::BatchSegment>*)
   {
      vector<EL::BatchSegment> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<EL::BatchSegment>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<EL::BatchSegment>", -2, "vector", 214,
                  typeid(vector<EL::BatchSegment>), DefineBehavior(ptr, ptr),
                  &vectorlEELcLcLBatchSegmentgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<EL::BatchSegment>) );
      instance.SetNew(&new_vectorlEELcLcLBatchSegmentgR);
      instance.SetNewArray(&newArray_vectorlEELcLcLBatchSegmentgR);
      instance.SetDelete(&delete_vectorlEELcLcLBatchSegmentgR);
      instance.SetDeleteArray(&deleteArray_vectorlEELcLcLBatchSegmentgR);
      instance.SetDestructor(&destruct_vectorlEELcLcLBatchSegmentgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<EL::BatchSegment> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<EL::BatchSegment>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEELcLcLBatchSegmentgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<EL::BatchSegment>*)0x0)->GetClass();
      vectorlEELcLcLBatchSegmentgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEELcLcLBatchSegmentgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEELcLcLBatchSegmentgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<EL::BatchSegment> : new vector<EL::BatchSegment>;
   }
   static void *newArray_vectorlEELcLcLBatchSegmentgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<EL::BatchSegment>[nElements] : new vector<EL::BatchSegment>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEELcLcLBatchSegmentgR(void *p) {
      delete ((vector<EL::BatchSegment>*)p);
   }
   static void deleteArray_vectorlEELcLcLBatchSegmentgR(void *p) {
      delete [] ((vector<EL::BatchSegment>*)p);
   }
   static void destruct_vectorlEELcLcLBatchSegmentgR(void *p) {
      typedef vector<EL::BatchSegment> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<EL::BatchSegment>

namespace ROOT {
   static TClass *vectorlEELcLcLBatchSamplegR_Dictionary();
   static void vectorlEELcLcLBatchSamplegR_TClassManip(TClass*);
   static void *new_vectorlEELcLcLBatchSamplegR(void *p = 0);
   static void *newArray_vectorlEELcLcLBatchSamplegR(Long_t size, void *p);
   static void delete_vectorlEELcLcLBatchSamplegR(void *p);
   static void deleteArray_vectorlEELcLcLBatchSamplegR(void *p);
   static void destruct_vectorlEELcLcLBatchSamplegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<EL::BatchSample>*)
   {
      vector<EL::BatchSample> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<EL::BatchSample>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<EL::BatchSample>", -2, "vector", 214,
                  typeid(vector<EL::BatchSample>), DefineBehavior(ptr, ptr),
                  &vectorlEELcLcLBatchSamplegR_Dictionary, isa_proxy, 0,
                  sizeof(vector<EL::BatchSample>) );
      instance.SetNew(&new_vectorlEELcLcLBatchSamplegR);
      instance.SetNewArray(&newArray_vectorlEELcLcLBatchSamplegR);
      instance.SetDelete(&delete_vectorlEELcLcLBatchSamplegR);
      instance.SetDeleteArray(&deleteArray_vectorlEELcLcLBatchSamplegR);
      instance.SetDestructor(&destruct_vectorlEELcLcLBatchSamplegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<EL::BatchSample> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<EL::BatchSample>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEELcLcLBatchSamplegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<EL::BatchSample>*)0x0)->GetClass();
      vectorlEELcLcLBatchSamplegR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEELcLcLBatchSamplegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEELcLcLBatchSamplegR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<EL::BatchSample> : new vector<EL::BatchSample>;
   }
   static void *newArray_vectorlEELcLcLBatchSamplegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<EL::BatchSample>[nElements] : new vector<EL::BatchSample>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEELcLcLBatchSamplegR(void *p) {
      delete ((vector<EL::BatchSample>*)p);
   }
   static void deleteArray_vectorlEELcLcLBatchSamplegR(void *p) {
      delete [] ((vector<EL::BatchSample>*)p);
   }
   static void destruct_vectorlEELcLcLBatchSamplegR(void *p) {
      typedef vector<EL::BatchSample> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<EL::BatchSample>

namespace ROOT {
   static TClass *vectorlEELcLcLAlgorithmmUgR_Dictionary();
   static void vectorlEELcLcLAlgorithmmUgR_TClassManip(TClass*);
   static void *new_vectorlEELcLcLAlgorithmmUgR(void *p = 0);
   static void *newArray_vectorlEELcLcLAlgorithmmUgR(Long_t size, void *p);
   static void delete_vectorlEELcLcLAlgorithmmUgR(void *p);
   static void deleteArray_vectorlEELcLcLAlgorithmmUgR(void *p);
   static void destruct_vectorlEELcLcLAlgorithmmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<EL::Algorithm*>*)
   {
      vector<EL::Algorithm*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<EL::Algorithm*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<EL::Algorithm*>", -2, "vector", 214,
                  typeid(vector<EL::Algorithm*>), DefineBehavior(ptr, ptr),
                  &vectorlEELcLcLAlgorithmmUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<EL::Algorithm*>) );
      instance.SetNew(&new_vectorlEELcLcLAlgorithmmUgR);
      instance.SetNewArray(&newArray_vectorlEELcLcLAlgorithmmUgR);
      instance.SetDelete(&delete_vectorlEELcLcLAlgorithmmUgR);
      instance.SetDeleteArray(&deleteArray_vectorlEELcLcLAlgorithmmUgR);
      instance.SetDestructor(&destruct_vectorlEELcLcLAlgorithmmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<EL::Algorithm*> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<EL::Algorithm*>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEELcLcLAlgorithmmUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<EL::Algorithm*>*)0x0)->GetClass();
      vectorlEELcLcLAlgorithmmUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEELcLcLAlgorithmmUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEELcLcLAlgorithmmUgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<EL::Algorithm*> : new vector<EL::Algorithm*>;
   }
   static void *newArray_vectorlEELcLcLAlgorithmmUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<EL::Algorithm*>[nElements] : new vector<EL::Algorithm*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEELcLcLAlgorithmmUgR(void *p) {
      delete ((vector<EL::Algorithm*>*)p);
   }
   static void deleteArray_vectorlEELcLcLAlgorithmmUgR(void *p) {
      delete [] ((vector<EL::Algorithm*>*)p);
   }
   static void destruct_vectorlEELcLcLAlgorithmmUgR(void *p) {
      typedef vector<EL::Algorithm*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<EL::Algorithm*>

namespace ROOT {
   static TClass *maplEstringcOTH1mUgR_Dictionary();
   static void maplEstringcOTH1mUgR_TClassManip(TClass*);
   static void *new_maplEstringcOTH1mUgR(void *p = 0);
   static void *newArray_maplEstringcOTH1mUgR(Long_t size, void *p);
   static void delete_maplEstringcOTH1mUgR(void *p);
   static void deleteArray_maplEstringcOTH1mUgR(void *p);
   static void destruct_maplEstringcOTH1mUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<string,TH1*>*)
   {
      map<string,TH1*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<string,TH1*>));
      static ::ROOT::TGenericClassInfo 
         instance("map<string,TH1*>", -2, "map", 96,
                  typeid(map<string,TH1*>), DefineBehavior(ptr, ptr),
                  &maplEstringcOTH1mUgR_Dictionary, isa_proxy, 0,
                  sizeof(map<string,TH1*>) );
      instance.SetNew(&new_maplEstringcOTH1mUgR);
      instance.SetNewArray(&newArray_maplEstringcOTH1mUgR);
      instance.SetDelete(&delete_maplEstringcOTH1mUgR);
      instance.SetDeleteArray(&deleteArray_maplEstringcOTH1mUgR);
      instance.SetDestructor(&destruct_maplEstringcOTH1mUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<string,TH1*> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<string,TH1*>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEstringcOTH1mUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<string,TH1*>*)0x0)->GetClass();
      maplEstringcOTH1mUgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEstringcOTH1mUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEstringcOTH1mUgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) map<string,TH1*> : new map<string,TH1*>;
   }
   static void *newArray_maplEstringcOTH1mUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) map<string,TH1*>[nElements] : new map<string,TH1*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEstringcOTH1mUgR(void *p) {
      delete ((map<string,TH1*>*)p);
   }
   static void deleteArray_maplEstringcOTH1mUgR(void *p) {
      delete [] ((map<string,TH1*>*)p);
   }
   static void destruct_maplEstringcOTH1mUgR(void *p) {
      typedef map<string,TH1*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<string,TH1*>

namespace ROOT {
   static TClass *maplEstringcOSHcLcLDiskWritermUgR_Dictionary();
   static void maplEstringcOSHcLcLDiskWritermUgR_TClassManip(TClass*);
   static void *new_maplEstringcOSHcLcLDiskWritermUgR(void *p = 0);
   static void *newArray_maplEstringcOSHcLcLDiskWritermUgR(Long_t size, void *p);
   static void delete_maplEstringcOSHcLcLDiskWritermUgR(void *p);
   static void deleteArray_maplEstringcOSHcLcLDiskWritermUgR(void *p);
   static void destruct_maplEstringcOSHcLcLDiskWritermUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<string,SH::DiskWriter*>*)
   {
      map<string,SH::DiskWriter*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<string,SH::DiskWriter*>));
      static ::ROOT::TGenericClassInfo 
         instance("map<string,SH::DiskWriter*>", -2, "map", 96,
                  typeid(map<string,SH::DiskWriter*>), DefineBehavior(ptr, ptr),
                  &maplEstringcOSHcLcLDiskWritermUgR_Dictionary, isa_proxy, 0,
                  sizeof(map<string,SH::DiskWriter*>) );
      instance.SetNew(&new_maplEstringcOSHcLcLDiskWritermUgR);
      instance.SetNewArray(&newArray_maplEstringcOSHcLcLDiskWritermUgR);
      instance.SetDelete(&delete_maplEstringcOSHcLcLDiskWritermUgR);
      instance.SetDeleteArray(&deleteArray_maplEstringcOSHcLcLDiskWritermUgR);
      instance.SetDestructor(&destruct_maplEstringcOSHcLcLDiskWritermUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<string,SH::DiskWriter*> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<string,SH::DiskWriter*>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEstringcOSHcLcLDiskWritermUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<string,SH::DiskWriter*>*)0x0)->GetClass();
      maplEstringcOSHcLcLDiskWritermUgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEstringcOSHcLcLDiskWritermUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEstringcOSHcLcLDiskWritermUgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) map<string,SH::DiskWriter*> : new map<string,SH::DiskWriter*>;
   }
   static void *newArray_maplEstringcOSHcLcLDiskWritermUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) map<string,SH::DiskWriter*>[nElements] : new map<string,SH::DiskWriter*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEstringcOSHcLcLDiskWritermUgR(void *p) {
      delete ((map<string,SH::DiskWriter*>*)p);
   }
   static void deleteArray_maplEstringcOSHcLcLDiskWritermUgR(void *p) {
      delete [] ((map<string,SH::DiskWriter*>*)p);
   }
   static void destruct_maplEstringcOSHcLcLDiskWritermUgR(void *p) {
      typedef map<string,SH::DiskWriter*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<string,SH::DiskWriter*>

namespace {
  void TriggerDictionaryInitialization_EventLoopCINT_Impl() {
    static const char* headers[] = {
"EventLoop/Algorithm.h",
"EventLoop/StatusCode.h",
"EventLoop/BackgroundDriver.h",
"EventLoop/BackgroundJob.h",
"EventLoop/BackgroundTSelector.h",
"EventLoop/BackgroundWorker.h",
"EventLoop/Worker.h",
"EventLoop/BatchDriver.h",
"EventLoop/BatchJob.h",
"EventLoop/Job.h",
"EventLoop/BatchSegment.h",
"EventLoop/BatchSample.h",
"EventLoop/BatchWorker.h",
"EventLoop/CondorDriver.h",
"EventLoop/DirectDriver.h",
"EventLoop/D3PDReaderSvc.h",
"EventLoop/GEDriver.h",
"EventLoop/LLDriver.h",
"EventLoop/LSFDriver.h",
"EventLoop/LocalDriver.h",
"EventLoop/OutputStream.h",
"EventLoop/MetricsSvc.h",
"EventLoop/ProofArgs.h",
"EventLoop/ProofDriver.h",
"EventLoop/ProofTSelector.h",
"EventLoop/SoGEDriver.h",
"EventLoop/SlurmDriver.h",
"EventLoop/TEventSvc.h",
"EventLoop/TorqueDriver.h",
"EventLoop/UnitTestAlg.h",
"EventLoop/UnitTestAlg1.h",
"EventLoop/VomsProxySvc.h",
"EventLoop/ProofWorker.h",
0
    };
    static const char* includePaths[] = {
"/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoop/Root",
"/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoop",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoop/cmt/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace EL{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoop/Root/LinkDef.h")))  Algorithm;}
namespace EL{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoop/Root/LinkDef.h")))  BackgroundDriver;}
namespace EL{struct __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoop/Root/LinkDef.h")))  BackgroundJob;}
namespace EL{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoop/Root/LinkDef.h")))  BackgroundTSelector;}
namespace EL{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoop/Root/LinkDef.h")))  BackgroundWorker;}
namespace EL{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoop/Root/LinkDef.h")))  BatchDriver;}
namespace EL{struct __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoop/Root/LinkDef.h")))  BatchJob;}
namespace EL{struct __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoop/Root/LinkDef.h")))  BatchSample;}
namespace EL{struct __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoop/Root/LinkDef.h")))  BatchSegment;}
namespace EL{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoop/Root/LinkDef.h")))  BatchWorker;}
namespace EL{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoop/Root/LinkDef.h")))  CondorDriver;}
namespace EL{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoop/Root/LinkDef.h")))  DirectDriver;}
namespace EL{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoop/Root/LinkDef.h")))  Driver;}
namespace EL{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoop/Root/LinkDef.h")))  Job;}
namespace EL{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoop/Root/LinkDef.h")))  GEDriver;}
namespace EL{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoop/Root/LinkDef.h")))  LSFDriver;}
namespace EL{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoop/Root/LinkDef.h")))  LLDriver;}
namespace EL{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoop/Root/LinkDef.h")))  LocalDriver;}
namespace EL{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoop/Root/LinkDef.h")))  OutputStream;}
namespace EL{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoop/Root/LinkDef.h")))  MetricsSvc;}
namespace EL{struct __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoop/Root/LinkDef.h")))  ProofArgs;}
namespace EL{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoop/Root/LinkDef.h")))  ProofDriver;}
namespace EL{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoop/Root/LinkDef.h")))  ProofTSelector;}
namespace EL{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoop/Root/LinkDef.h")))  ProofWorker;}
namespace EL{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoop/Root/LinkDef.h")))  SlurmDriver;}
namespace EL{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoop/Root/LinkDef.h")))  SoGEDriver;}
namespace EL{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoop/Root/LinkDef.h")))  StatusCode;}
namespace EL{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoop/Root/LinkDef.h")))  TorqueDriver;}
namespace EL{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoop/Root/LinkDef.h")))  UnitTestAlg;}
namespace EL{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoop/Root/LinkDef.h")))  UnitTestAlg1;}
namespace EL{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoop/Root/LinkDef.h")))  VomsProxySvc;}
namespace EL{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoop/Root/LinkDef.h")))  Worker;}
namespace std{template <class _T1, class _T2> struct __attribute__((annotate("$clingAutoload$string")))  pair;
}
namespace std{template <typename _Tp> class __attribute__((annotate("$clingAutoload$string")))  allocator;
}
namespace EL{class __attribute__((annotate("$clingAutoload$/user/hteagle/AnalysisDirectory/Base_2_4_34/EventLoop/Root/LinkDef.h")))  TEventSvc;}
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
  #define ROOTCORE_PACKAGE "EventLoop"
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "EventLoop/Algorithm.h"
#include "EventLoop/StatusCode.h"
#include "EventLoop/BackgroundDriver.h"
#include "EventLoop/BackgroundJob.h"
#include "EventLoop/BackgroundTSelector.h"
#include "EventLoop/BackgroundWorker.h"
#include "EventLoop/Worker.h"
#include "EventLoop/BatchDriver.h"
#include "EventLoop/BatchJob.h"
#include "EventLoop/Job.h"
#include "EventLoop/BatchSegment.h"
#include "EventLoop/BatchSample.h"
#include "EventLoop/BatchWorker.h"
#include "EventLoop/CondorDriver.h"
#include "EventLoop/DirectDriver.h"
#include "EventLoop/D3PDReaderSvc.h"
#include "EventLoop/GEDriver.h"
#include "EventLoop/LLDriver.h"
#include "EventLoop/LSFDriver.h"
#include "EventLoop/LocalDriver.h"
#include "EventLoop/OutputStream.h"
#include "EventLoop/MetricsSvc.h"
#include "EventLoop/ProofArgs.h"
#include "EventLoop/ProofDriver.h"
#include "EventLoop/ProofTSelector.h"
#include "EventLoop/SoGEDriver.h"
#include "EventLoop/SlurmDriver.h"
#include "EventLoop/TEventSvc.h"
#include "EventLoop/TorqueDriver.h"
#include "EventLoop/UnitTestAlg.h"
#include "EventLoop/UnitTestAlg1.h"
#include "EventLoop/VomsProxySvc.h"
#include "EventLoop/ProofWorker.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"EL::Algorithm", payloadCode, "@",
"EL::BackgroundDriver", payloadCode, "@",
"EL::BackgroundJob", payloadCode, "@",
"EL::BackgroundTSelector", payloadCode, "@",
"EL::BackgroundWorker", payloadCode, "@",
"EL::BatchDriver", payloadCode, "@",
"EL::BatchJob", payloadCode, "@",
"EL::BatchSample", payloadCode, "@",
"EL::BatchSegment", payloadCode, "@",
"EL::BatchWorker", payloadCode, "@",
"EL::CondorDriver", payloadCode, "@",
"EL::DirectDriver", payloadCode, "@",
"EL::Driver", payloadCode, "@",
"EL::GEDriver", payloadCode, "@",
"EL::Job", payloadCode, "@",
"EL::LLDriver", payloadCode, "@",
"EL::LSFDriver", payloadCode, "@",
"EL::LocalDriver", payloadCode, "@",
"EL::MetricsSvc", payloadCode, "@",
"EL::OutputStream", payloadCode, "@",
"EL::ProofArgs", payloadCode, "@",
"EL::ProofDriver", payloadCode, "@",
"EL::ProofTSelector", payloadCode, "@",
"EL::ProofWorker", payloadCode, "@",
"EL::SlurmDriver", payloadCode, "@",
"EL::SoGEDriver", payloadCode, "@",
"EL::StatusCode", payloadCode, "@",
"EL::TEventSvc", payloadCode, "@",
"EL::TorqueDriver", payloadCode, "@",
"EL::UnitTestAlg", payloadCode, "@",
"EL::UnitTestAlg1", payloadCode, "@",
"EL::VomsProxySvc", payloadCode, "@",
"EL::Worker", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("EventLoopCINT",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_EventLoopCINT_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_EventLoopCINT_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_EventLoopCINT() {
  TriggerDictionaryInitialization_EventLoopCINT_Impl();
}
