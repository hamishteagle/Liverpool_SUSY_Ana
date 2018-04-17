// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIuserdIhteagledIAnalysisDirectorydIBase_2_4_34dIRootCoreBindIobjdIx86_64mIslc6mIgcc49mIoptdIElectronPhotonFourMomentumCorrectiondIobjdIElectronPhotonFourMomentumCorrection_Reflex

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
#include "/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/ElectronPhotonFourMomentumCorrection/ElectronPhotonFourMomentumCorrection/ElectronPhotonFourMomentumCorrectionDict.h"

// Header files passed via #pragma extra_include

namespace egEnergyCorr {
   namespace ROOT {
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance();
      static TClass *egEnergyCorr_Dictionary();

      // Function generating the singleton type initializer
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance()
      {
         static ::ROOT::TGenericClassInfo 
            instance("egEnergyCorr", 0 /*version*/, "ElectronPhotonFourMomentumCorrection/egammaEnergyCorrectionTool.h", 46,
                     ::ROOT::DefineBehavior((void*)0,(void*)0),
                     &egEnergyCorr_Dictionary, 0);
         return &instance;
      }
      // Insure that the inline function is _not_ optimized away by the compiler
      ::ROOT::TGenericClassInfo *(*_R__UNIQUE_(InitFunctionKeeper))() = &GenerateInitInstance;  
      // Static variable to force the class initialization
      static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstance(); R__UseDummy(_R__UNIQUE_(Init));

      // Dictionary for non-ClassDef classes
      static TClass *egEnergyCorr_Dictionary() {
         return GenerateInitInstance()->GetClass();
      }

   }
}

namespace egEnergyCorr {
   namespace Resolution {
   namespace ROOT {
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance();
      static TClass *egEnergyCorrcLcLResolution_Dictionary();

      // Function generating the singleton type initializer
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance()
      {
         static ::ROOT::TGenericClassInfo 
            instance("egEnergyCorr::Resolution", 0 /*version*/, "ElectronPhotonFourMomentumCorrection/egammaEnergyCorrectionTool.h", 50,
                     ::ROOT::DefineBehavior((void*)0,(void*)0),
                     &egEnergyCorrcLcLResolution_Dictionary, 0);
         return &instance;
      }
      // Insure that the inline function is _not_ optimized away by the compiler
      ::ROOT::TGenericClassInfo *(*_R__UNIQUE_(InitFunctionKeeper))() = &GenerateInitInstance;  
      // Static variable to force the class initialization
      static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstance(); R__UseDummy(_R__UNIQUE_(Init));

      // Dictionary for non-ClassDef classes
      static TClass *egEnergyCorrcLcLResolution_Dictionary() {
         return GenerateInitInstance()->GetClass();
      }

   }
}
}

namespace egEnergyCorr {
   namespace Scale {
   namespace ROOT {
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance();
      static TClass *egEnergyCorrcLcLScale_Dictionary();

      // Function generating the singleton type initializer
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance()
      {
         static ::ROOT::TGenericClassInfo 
            instance("egEnergyCorr::Scale", 0 /*version*/, "ElectronPhotonFourMomentumCorrection/egammaEnergyCorrectionTool.h", 101,
                     ::ROOT::DefineBehavior((void*)0,(void*)0),
                     &egEnergyCorrcLcLScale_Dictionary, 0);
         return &instance;
      }
      // Insure that the inline function is _not_ optimized away by the compiler
      ::ROOT::TGenericClassInfo *(*_R__UNIQUE_(InitFunctionKeeper))() = &GenerateInitInstance;  
      // Static variable to force the class initialization
      static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstance(); R__UseDummy(_R__UNIQUE_(Init));

      // Dictionary for non-ClassDef classes
      static TClass *egEnergyCorrcLcLScale_Dictionary() {
         return GenerateInitInstance()->GetClass();
      }

   }
}
}

namespace ROOT {
   static TClass *CPcLcLIEgammaCalibrationAndSmearingTool_Dictionary();
   static void CPcLcLIEgammaCalibrationAndSmearingTool_TClassManip(TClass*);
   static void delete_CPcLcLIEgammaCalibrationAndSmearingTool(void *p);
   static void deleteArray_CPcLcLIEgammaCalibrationAndSmearingTool(void *p);
   static void destruct_CPcLcLIEgammaCalibrationAndSmearingTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CP::IEgammaCalibrationAndSmearingTool*)
   {
      ::CP::IEgammaCalibrationAndSmearingTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::CP::IEgammaCalibrationAndSmearingTool));
      static ::ROOT::TGenericClassInfo 
         instance("CP::IEgammaCalibrationAndSmearingTool", "ElectronPhotonFourMomentumCorrection/IEgammaCalibrationAndSmearingTool.h", 26,
                  typeid(::CP::IEgammaCalibrationAndSmearingTool), DefineBehavior(ptr, ptr),
                  &CPcLcLIEgammaCalibrationAndSmearingTool_Dictionary, isa_proxy, 0,
                  sizeof(::CP::IEgammaCalibrationAndSmearingTool) );
      instance.SetDelete(&delete_CPcLcLIEgammaCalibrationAndSmearingTool);
      instance.SetDeleteArray(&deleteArray_CPcLcLIEgammaCalibrationAndSmearingTool);
      instance.SetDestructor(&destruct_CPcLcLIEgammaCalibrationAndSmearingTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CP::IEgammaCalibrationAndSmearingTool*)
   {
      return GenerateInitInstanceLocal((::CP::IEgammaCalibrationAndSmearingTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::CP::IEgammaCalibrationAndSmearingTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CPcLcLIEgammaCalibrationAndSmearingTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::CP::IEgammaCalibrationAndSmearingTool*)0x0)->GetClass();
      CPcLcLIEgammaCalibrationAndSmearingTool_TClassManip(theClass);
   return theClass;
   }

   static void CPcLcLIEgammaCalibrationAndSmearingTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CPcLcLEgammaCalibrationAndSmearingTool_Dictionary();
   static void CPcLcLEgammaCalibrationAndSmearingTool_TClassManip(TClass*);
   static void delete_CPcLcLEgammaCalibrationAndSmearingTool(void *p);
   static void deleteArray_CPcLcLEgammaCalibrationAndSmearingTool(void *p);
   static void destruct_CPcLcLEgammaCalibrationAndSmearingTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CP::EgammaCalibrationAndSmearingTool*)
   {
      ::CP::EgammaCalibrationAndSmearingTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::CP::EgammaCalibrationAndSmearingTool));
      static ::ROOT::TGenericClassInfo 
         instance("CP::EgammaCalibrationAndSmearingTool", "ElectronPhotonFourMomentumCorrection/EgammaCalibrationAndSmearingTool.h", 69,
                  typeid(::CP::EgammaCalibrationAndSmearingTool), DefineBehavior(ptr, ptr),
                  &CPcLcLEgammaCalibrationAndSmearingTool_Dictionary, isa_proxy, 0,
                  sizeof(::CP::EgammaCalibrationAndSmearingTool) );
      instance.SetDelete(&delete_CPcLcLEgammaCalibrationAndSmearingTool);
      instance.SetDeleteArray(&deleteArray_CPcLcLEgammaCalibrationAndSmearingTool);
      instance.SetDestructor(&destruct_CPcLcLEgammaCalibrationAndSmearingTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CP::EgammaCalibrationAndSmearingTool*)
   {
      return GenerateInitInstanceLocal((::CP::EgammaCalibrationAndSmearingTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::CP::EgammaCalibrationAndSmearingTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CPcLcLEgammaCalibrationAndSmearingTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::CP::EgammaCalibrationAndSmearingTool*)0x0)->GetClass();
      CPcLcLEgammaCalibrationAndSmearingTool_TClassManip(theClass);
   return theClass;
   }

   static void CPcLcLEgammaCalibrationAndSmearingTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *AtlasRootcLcLegammaEnergyCorrectionTool_Dictionary();
   static void AtlasRootcLcLegammaEnergyCorrectionTool_TClassManip(TClass*);
   static void *new_AtlasRootcLcLegammaEnergyCorrectionTool(void *p = 0);
   static void *newArray_AtlasRootcLcLegammaEnergyCorrectionTool(Long_t size, void *p);
   static void delete_AtlasRootcLcLegammaEnergyCorrectionTool(void *p);
   static void deleteArray_AtlasRootcLcLegammaEnergyCorrectionTool(void *p);
   static void destruct_AtlasRootcLcLegammaEnergyCorrectionTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::AtlasRoot::egammaEnergyCorrectionTool*)
   {
      ::AtlasRoot::egammaEnergyCorrectionTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::AtlasRoot::egammaEnergyCorrectionTool));
      static ::ROOT::TGenericClassInfo 
         instance("AtlasRoot::egammaEnergyCorrectionTool", "ElectronPhotonFourMomentumCorrection/egammaEnergyCorrectionTool.h", 240,
                  typeid(::AtlasRoot::egammaEnergyCorrectionTool), DefineBehavior(ptr, ptr),
                  &AtlasRootcLcLegammaEnergyCorrectionTool_Dictionary, isa_proxy, 0,
                  sizeof(::AtlasRoot::egammaEnergyCorrectionTool) );
      instance.SetNew(&new_AtlasRootcLcLegammaEnergyCorrectionTool);
      instance.SetNewArray(&newArray_AtlasRootcLcLegammaEnergyCorrectionTool);
      instance.SetDelete(&delete_AtlasRootcLcLegammaEnergyCorrectionTool);
      instance.SetDeleteArray(&deleteArray_AtlasRootcLcLegammaEnergyCorrectionTool);
      instance.SetDestructor(&destruct_AtlasRootcLcLegammaEnergyCorrectionTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::AtlasRoot::egammaEnergyCorrectionTool*)
   {
      return GenerateInitInstanceLocal((::AtlasRoot::egammaEnergyCorrectionTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::AtlasRoot::egammaEnergyCorrectionTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *AtlasRootcLcLegammaEnergyCorrectionTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::AtlasRoot::egammaEnergyCorrectionTool*)0x0)->GetClass();
      AtlasRootcLcLegammaEnergyCorrectionTool_TClassManip(theClass);
   return theClass;
   }

   static void AtlasRootcLcLegammaEnergyCorrectionTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *EgammaCalibPeriodRunNumbersExamplecLcLROOT6_NamespaceAutoloadHook_Dictionary();
   static void EgammaCalibPeriodRunNumbersExamplecLcLROOT6_NamespaceAutoloadHook_TClassManip(TClass*);
   static void *new_EgammaCalibPeriodRunNumbersExamplecLcLROOT6_NamespaceAutoloadHook(void *p = 0);
   static void *newArray_EgammaCalibPeriodRunNumbersExamplecLcLROOT6_NamespaceAutoloadHook(Long_t size, void *p);
   static void delete_EgammaCalibPeriodRunNumbersExamplecLcLROOT6_NamespaceAutoloadHook(void *p);
   static void deleteArray_EgammaCalibPeriodRunNumbersExamplecLcLROOT6_NamespaceAutoloadHook(void *p);
   static void destruct_EgammaCalibPeriodRunNumbersExamplecLcLROOT6_NamespaceAutoloadHook(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EgammaCalibPeriodRunNumbersExample::ROOT6_NamespaceAutoloadHook*)
   {
      ::EgammaCalibPeriodRunNumbersExample::ROOT6_NamespaceAutoloadHook *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::EgammaCalibPeriodRunNumbersExample::ROOT6_NamespaceAutoloadHook));
      static ::ROOT::TGenericClassInfo 
         instance("EgammaCalibPeriodRunNumbersExample::ROOT6_NamespaceAutoloadHook", "ElectronPhotonFourMomentumCorrection/IEgammaCalibrationAndSmearingTool.h", 20,
                  typeid(::EgammaCalibPeriodRunNumbersExample::ROOT6_NamespaceAutoloadHook), DefineBehavior(ptr, ptr),
                  &EgammaCalibPeriodRunNumbersExamplecLcLROOT6_NamespaceAutoloadHook_Dictionary, isa_proxy, 0,
                  sizeof(::EgammaCalibPeriodRunNumbersExample::ROOT6_NamespaceAutoloadHook) );
      instance.SetNew(&new_EgammaCalibPeriodRunNumbersExamplecLcLROOT6_NamespaceAutoloadHook);
      instance.SetNewArray(&newArray_EgammaCalibPeriodRunNumbersExamplecLcLROOT6_NamespaceAutoloadHook);
      instance.SetDelete(&delete_EgammaCalibPeriodRunNumbersExamplecLcLROOT6_NamespaceAutoloadHook);
      instance.SetDeleteArray(&deleteArray_EgammaCalibPeriodRunNumbersExamplecLcLROOT6_NamespaceAutoloadHook);
      instance.SetDestructor(&destruct_EgammaCalibPeriodRunNumbersExamplecLcLROOT6_NamespaceAutoloadHook);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EgammaCalibPeriodRunNumbersExample::ROOT6_NamespaceAutoloadHook*)
   {
      return GenerateInitInstanceLocal((::EgammaCalibPeriodRunNumbersExample::ROOT6_NamespaceAutoloadHook*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EgammaCalibPeriodRunNumbersExample::ROOT6_NamespaceAutoloadHook*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *EgammaCalibPeriodRunNumbersExamplecLcLROOT6_NamespaceAutoloadHook_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::EgammaCalibPeriodRunNumbersExample::ROOT6_NamespaceAutoloadHook*)0x0)->GetClass();
      EgammaCalibPeriodRunNumbersExamplecLcLROOT6_NamespaceAutoloadHook_TClassManip(theClass);
   return theClass;
   }

   static void EgammaCalibPeriodRunNumbersExamplecLcLROOT6_NamespaceAutoloadHook_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *egEnergyCorrcLcLROOT6_OpenNamespaceWorkaround_Dictionary();
   static void egEnergyCorrcLcLROOT6_OpenNamespaceWorkaround_TClassManip(TClass*);
   static void *new_egEnergyCorrcLcLROOT6_OpenNamespaceWorkaround(void *p = 0);
   static void *newArray_egEnergyCorrcLcLROOT6_OpenNamespaceWorkaround(Long_t size, void *p);
   static void delete_egEnergyCorrcLcLROOT6_OpenNamespaceWorkaround(void *p);
   static void deleteArray_egEnergyCorrcLcLROOT6_OpenNamespaceWorkaround(void *p);
   static void destruct_egEnergyCorrcLcLROOT6_OpenNamespaceWorkaround(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::egEnergyCorr::ROOT6_OpenNamespaceWorkaround*)
   {
      ::egEnergyCorr::ROOT6_OpenNamespaceWorkaround *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::egEnergyCorr::ROOT6_OpenNamespaceWorkaround));
      static ::ROOT::TGenericClassInfo 
         instance("egEnergyCorr::ROOT6_OpenNamespaceWorkaround", "ElectronPhotonFourMomentumCorrection/egammaEnergyCorrectionTool.h", 47,
                  typeid(::egEnergyCorr::ROOT6_OpenNamespaceWorkaround), DefineBehavior(ptr, ptr),
                  &egEnergyCorrcLcLROOT6_OpenNamespaceWorkaround_Dictionary, isa_proxy, 0,
                  sizeof(::egEnergyCorr::ROOT6_OpenNamespaceWorkaround) );
      instance.SetNew(&new_egEnergyCorrcLcLROOT6_OpenNamespaceWorkaround);
      instance.SetNewArray(&newArray_egEnergyCorrcLcLROOT6_OpenNamespaceWorkaround);
      instance.SetDelete(&delete_egEnergyCorrcLcLROOT6_OpenNamespaceWorkaround);
      instance.SetDeleteArray(&deleteArray_egEnergyCorrcLcLROOT6_OpenNamespaceWorkaround);
      instance.SetDestructor(&destruct_egEnergyCorrcLcLROOT6_OpenNamespaceWorkaround);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::egEnergyCorr::ROOT6_OpenNamespaceWorkaround*)
   {
      return GenerateInitInstanceLocal((::egEnergyCorr::ROOT6_OpenNamespaceWorkaround*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::egEnergyCorr::ROOT6_OpenNamespaceWorkaround*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *egEnergyCorrcLcLROOT6_OpenNamespaceWorkaround_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::egEnergyCorr::ROOT6_OpenNamespaceWorkaround*)0x0)->GetClass();
      egEnergyCorrcLcLROOT6_OpenNamespaceWorkaround_TClassManip(theClass);
   return theClass;
   }

   static void egEnergyCorrcLcLROOT6_OpenNamespaceWorkaround_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *egEnergyCorrcLcLResolutioncLcLROOT6_OpenNamespaceWorkaround_Dictionary();
   static void egEnergyCorrcLcLResolutioncLcLROOT6_OpenNamespaceWorkaround_TClassManip(TClass*);
   static void *new_egEnergyCorrcLcLResolutioncLcLROOT6_OpenNamespaceWorkaround(void *p = 0);
   static void *newArray_egEnergyCorrcLcLResolutioncLcLROOT6_OpenNamespaceWorkaround(Long_t size, void *p);
   static void delete_egEnergyCorrcLcLResolutioncLcLROOT6_OpenNamespaceWorkaround(void *p);
   static void deleteArray_egEnergyCorrcLcLResolutioncLcLROOT6_OpenNamespaceWorkaround(void *p);
   static void destruct_egEnergyCorrcLcLResolutioncLcLROOT6_OpenNamespaceWorkaround(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::egEnergyCorr::Resolution::ROOT6_OpenNamespaceWorkaround*)
   {
      ::egEnergyCorr::Resolution::ROOT6_OpenNamespaceWorkaround *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::egEnergyCorr::Resolution::ROOT6_OpenNamespaceWorkaround));
      static ::ROOT::TGenericClassInfo 
         instance("egEnergyCorr::Resolution::ROOT6_OpenNamespaceWorkaround", "ElectronPhotonFourMomentumCorrection/egammaEnergyCorrectionTool.h", 51,
                  typeid(::egEnergyCorr::Resolution::ROOT6_OpenNamespaceWorkaround), DefineBehavior(ptr, ptr),
                  &egEnergyCorrcLcLResolutioncLcLROOT6_OpenNamespaceWorkaround_Dictionary, isa_proxy, 0,
                  sizeof(::egEnergyCorr::Resolution::ROOT6_OpenNamespaceWorkaround) );
      instance.SetNew(&new_egEnergyCorrcLcLResolutioncLcLROOT6_OpenNamespaceWorkaround);
      instance.SetNewArray(&newArray_egEnergyCorrcLcLResolutioncLcLROOT6_OpenNamespaceWorkaround);
      instance.SetDelete(&delete_egEnergyCorrcLcLResolutioncLcLROOT6_OpenNamespaceWorkaround);
      instance.SetDeleteArray(&deleteArray_egEnergyCorrcLcLResolutioncLcLROOT6_OpenNamespaceWorkaround);
      instance.SetDestructor(&destruct_egEnergyCorrcLcLResolutioncLcLROOT6_OpenNamespaceWorkaround);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::egEnergyCorr::Resolution::ROOT6_OpenNamespaceWorkaround*)
   {
      return GenerateInitInstanceLocal((::egEnergyCorr::Resolution::ROOT6_OpenNamespaceWorkaround*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::egEnergyCorr::Resolution::ROOT6_OpenNamespaceWorkaround*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *egEnergyCorrcLcLResolutioncLcLROOT6_OpenNamespaceWorkaround_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::egEnergyCorr::Resolution::ROOT6_OpenNamespaceWorkaround*)0x0)->GetClass();
      egEnergyCorrcLcLResolutioncLcLROOT6_OpenNamespaceWorkaround_TClassManip(theClass);
   return theClass;
   }

   static void egEnergyCorrcLcLResolutioncLcLROOT6_OpenNamespaceWorkaround_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *egEnergyCorrcLcLScalecLcLROOT6_OpenNamespaceWorkaround_Dictionary();
   static void egEnergyCorrcLcLScalecLcLROOT6_OpenNamespaceWorkaround_TClassManip(TClass*);
   static void *new_egEnergyCorrcLcLScalecLcLROOT6_OpenNamespaceWorkaround(void *p = 0);
   static void *newArray_egEnergyCorrcLcLScalecLcLROOT6_OpenNamespaceWorkaround(Long_t size, void *p);
   static void delete_egEnergyCorrcLcLScalecLcLROOT6_OpenNamespaceWorkaround(void *p);
   static void deleteArray_egEnergyCorrcLcLScalecLcLROOT6_OpenNamespaceWorkaround(void *p);
   static void destruct_egEnergyCorrcLcLScalecLcLROOT6_OpenNamespaceWorkaround(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::egEnergyCorr::Scale::ROOT6_OpenNamespaceWorkaround*)
   {
      ::egEnergyCorr::Scale::ROOT6_OpenNamespaceWorkaround *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::egEnergyCorr::Scale::ROOT6_OpenNamespaceWorkaround));
      static ::ROOT::TGenericClassInfo 
         instance("egEnergyCorr::Scale::ROOT6_OpenNamespaceWorkaround", "ElectronPhotonFourMomentumCorrection/egammaEnergyCorrectionTool.h", 102,
                  typeid(::egEnergyCorr::Scale::ROOT6_OpenNamespaceWorkaround), DefineBehavior(ptr, ptr),
                  &egEnergyCorrcLcLScalecLcLROOT6_OpenNamespaceWorkaround_Dictionary, isa_proxy, 0,
                  sizeof(::egEnergyCorr::Scale::ROOT6_OpenNamespaceWorkaround) );
      instance.SetNew(&new_egEnergyCorrcLcLScalecLcLROOT6_OpenNamespaceWorkaround);
      instance.SetNewArray(&newArray_egEnergyCorrcLcLScalecLcLROOT6_OpenNamespaceWorkaround);
      instance.SetDelete(&delete_egEnergyCorrcLcLScalecLcLROOT6_OpenNamespaceWorkaround);
      instance.SetDeleteArray(&deleteArray_egEnergyCorrcLcLScalecLcLROOT6_OpenNamespaceWorkaround);
      instance.SetDestructor(&destruct_egEnergyCorrcLcLScalecLcLROOT6_OpenNamespaceWorkaround);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::egEnergyCorr::Scale::ROOT6_OpenNamespaceWorkaround*)
   {
      return GenerateInitInstanceLocal((::egEnergyCorr::Scale::ROOT6_OpenNamespaceWorkaround*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::egEnergyCorr::Scale::ROOT6_OpenNamespaceWorkaround*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *egEnergyCorrcLcLScalecLcLROOT6_OpenNamespaceWorkaround_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::egEnergyCorr::Scale::ROOT6_OpenNamespaceWorkaround*)0x0)->GetClass();
      egEnergyCorrcLcLScalecLcLROOT6_OpenNamespaceWorkaround_TClassManip(theClass);
   return theClass;
   }

   static void egEnergyCorrcLcLScalecLcLROOT6_OpenNamespaceWorkaround_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *eg_resolution_Dictionary();
   static void eg_resolution_TClassManip(TClass*);
   static void delete_eg_resolution(void *p);
   static void deleteArray_eg_resolution(void *p);
   static void destruct_eg_resolution(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::eg_resolution*)
   {
      ::eg_resolution *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::eg_resolution));
      static ::ROOT::TGenericClassInfo 
         instance("eg_resolution", "ElectronPhotonFourMomentumCorrection/eg_resolution.h", 28,
                  typeid(::eg_resolution), DefineBehavior(ptr, ptr),
                  &eg_resolution_Dictionary, isa_proxy, 0,
                  sizeof(::eg_resolution) );
      instance.SetDelete(&delete_eg_resolution);
      instance.SetDeleteArray(&deleteArray_eg_resolution);
      instance.SetDestructor(&destruct_eg_resolution);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::eg_resolution*)
   {
      return GenerateInitInstanceLocal((::eg_resolution*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::eg_resolution*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *eg_resolution_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::eg_resolution*)0x0)->GetClass();
      eg_resolution_TClassManip(theClass);
   return theClass;
   }

   static void eg_resolution_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *EgammaFactory_Dictionary();
   static void EgammaFactory_TClassManip(TClass*);
   static void *new_EgammaFactory(void *p = 0);
   static void *newArray_EgammaFactory(Long_t size, void *p);
   static void delete_EgammaFactory(void *p);
   static void deleteArray_EgammaFactory(void *p);
   static void destruct_EgammaFactory(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EgammaFactory*)
   {
      ::EgammaFactory *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::EgammaFactory));
      static ::ROOT::TGenericClassInfo 
         instance("EgammaFactory", "ElectronPhotonFourMomentumCorrection/EgammaFactory.h", 35,
                  typeid(::EgammaFactory), DefineBehavior(ptr, ptr),
                  &EgammaFactory_Dictionary, isa_proxy, 0,
                  sizeof(::EgammaFactory) );
      instance.SetNew(&new_EgammaFactory);
      instance.SetNewArray(&newArray_EgammaFactory);
      instance.SetDelete(&delete_EgammaFactory);
      instance.SetDeleteArray(&deleteArray_EgammaFactory);
      instance.SetDestructor(&destruct_EgammaFactory);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EgammaFactory*)
   {
      return GenerateInitInstanceLocal((::EgammaFactory*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EgammaFactory*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *EgammaFactory_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::EgammaFactory*)0x0)->GetClass();
      EgammaFactory_TClassManip(theClass);
   return theClass;
   }

   static void EgammaFactory_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *LArTemperatureCorrectionTool_Dictionary();
   static void LArTemperatureCorrectionTool_TClassManip(TClass*);
   static void delete_LArTemperatureCorrectionTool(void *p);
   static void deleteArray_LArTemperatureCorrectionTool(void *p);
   static void destruct_LArTemperatureCorrectionTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::LArTemperatureCorrectionTool*)
   {
      ::LArTemperatureCorrectionTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::LArTemperatureCorrectionTool));
      static ::ROOT::TGenericClassInfo 
         instance("LArTemperatureCorrectionTool", "ElectronPhotonFourMomentumCorrection/LArTemperatureCorrectionTool.h", 30,
                  typeid(::LArTemperatureCorrectionTool), DefineBehavior(ptr, ptr),
                  &LArTemperatureCorrectionTool_Dictionary, isa_proxy, 0,
                  sizeof(::LArTemperatureCorrectionTool) );
      instance.SetDelete(&delete_LArTemperatureCorrectionTool);
      instance.SetDeleteArray(&deleteArray_LArTemperatureCorrectionTool);
      instance.SetDestructor(&destruct_LArTemperatureCorrectionTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::LArTemperatureCorrectionTool*)
   {
      return GenerateInitInstanceLocal((::LArTemperatureCorrectionTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::LArTemperatureCorrectionTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *LArTemperatureCorrectionTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::LArTemperatureCorrectionTool*)0x0)->GetClass();
      LArTemperatureCorrectionTool_TClassManip(theClass);
   return theClass;
   }

   static void LArTemperatureCorrectionTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrapper around operator delete
   static void delete_CPcLcLIEgammaCalibrationAndSmearingTool(void *p) {
      delete ((::CP::IEgammaCalibrationAndSmearingTool*)p);
   }
   static void deleteArray_CPcLcLIEgammaCalibrationAndSmearingTool(void *p) {
      delete [] ((::CP::IEgammaCalibrationAndSmearingTool*)p);
   }
   static void destruct_CPcLcLIEgammaCalibrationAndSmearingTool(void *p) {
      typedef ::CP::IEgammaCalibrationAndSmearingTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::CP::IEgammaCalibrationAndSmearingTool

namespace ROOT {
   // Wrapper around operator delete
   static void delete_CPcLcLEgammaCalibrationAndSmearingTool(void *p) {
      delete ((::CP::EgammaCalibrationAndSmearingTool*)p);
   }
   static void deleteArray_CPcLcLEgammaCalibrationAndSmearingTool(void *p) {
      delete [] ((::CP::EgammaCalibrationAndSmearingTool*)p);
   }
   static void destruct_CPcLcLEgammaCalibrationAndSmearingTool(void *p) {
      typedef ::CP::EgammaCalibrationAndSmearingTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::CP::EgammaCalibrationAndSmearingTool

namespace ROOT {
   // Wrappers around operator new
   static void *new_AtlasRootcLcLegammaEnergyCorrectionTool(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::AtlasRoot::egammaEnergyCorrectionTool : new ::AtlasRoot::egammaEnergyCorrectionTool;
   }
   static void *newArray_AtlasRootcLcLegammaEnergyCorrectionTool(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::AtlasRoot::egammaEnergyCorrectionTool[nElements] : new ::AtlasRoot::egammaEnergyCorrectionTool[nElements];
   }
   // Wrapper around operator delete
   static void delete_AtlasRootcLcLegammaEnergyCorrectionTool(void *p) {
      delete ((::AtlasRoot::egammaEnergyCorrectionTool*)p);
   }
   static void deleteArray_AtlasRootcLcLegammaEnergyCorrectionTool(void *p) {
      delete [] ((::AtlasRoot::egammaEnergyCorrectionTool*)p);
   }
   static void destruct_AtlasRootcLcLegammaEnergyCorrectionTool(void *p) {
      typedef ::AtlasRoot::egammaEnergyCorrectionTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::AtlasRoot::egammaEnergyCorrectionTool

namespace ROOT {
   // Wrappers around operator new
   static void *new_EgammaCalibPeriodRunNumbersExamplecLcLROOT6_NamespaceAutoloadHook(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::EgammaCalibPeriodRunNumbersExample::ROOT6_NamespaceAutoloadHook : new ::EgammaCalibPeriodRunNumbersExample::ROOT6_NamespaceAutoloadHook;
   }
   static void *newArray_EgammaCalibPeriodRunNumbersExamplecLcLROOT6_NamespaceAutoloadHook(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::EgammaCalibPeriodRunNumbersExample::ROOT6_NamespaceAutoloadHook[nElements] : new ::EgammaCalibPeriodRunNumbersExample::ROOT6_NamespaceAutoloadHook[nElements];
   }
   // Wrapper around operator delete
   static void delete_EgammaCalibPeriodRunNumbersExamplecLcLROOT6_NamespaceAutoloadHook(void *p) {
      delete ((::EgammaCalibPeriodRunNumbersExample::ROOT6_NamespaceAutoloadHook*)p);
   }
   static void deleteArray_EgammaCalibPeriodRunNumbersExamplecLcLROOT6_NamespaceAutoloadHook(void *p) {
      delete [] ((::EgammaCalibPeriodRunNumbersExample::ROOT6_NamespaceAutoloadHook*)p);
   }
   static void destruct_EgammaCalibPeriodRunNumbersExamplecLcLROOT6_NamespaceAutoloadHook(void *p) {
      typedef ::EgammaCalibPeriodRunNumbersExample::ROOT6_NamespaceAutoloadHook current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EgammaCalibPeriodRunNumbersExample::ROOT6_NamespaceAutoloadHook

namespace ROOT {
   // Wrappers around operator new
   static void *new_egEnergyCorrcLcLROOT6_OpenNamespaceWorkaround(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::egEnergyCorr::ROOT6_OpenNamespaceWorkaround : new ::egEnergyCorr::ROOT6_OpenNamespaceWorkaround;
   }
   static void *newArray_egEnergyCorrcLcLROOT6_OpenNamespaceWorkaround(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::egEnergyCorr::ROOT6_OpenNamespaceWorkaround[nElements] : new ::egEnergyCorr::ROOT6_OpenNamespaceWorkaround[nElements];
   }
   // Wrapper around operator delete
   static void delete_egEnergyCorrcLcLROOT6_OpenNamespaceWorkaround(void *p) {
      delete ((::egEnergyCorr::ROOT6_OpenNamespaceWorkaround*)p);
   }
   static void deleteArray_egEnergyCorrcLcLROOT6_OpenNamespaceWorkaround(void *p) {
      delete [] ((::egEnergyCorr::ROOT6_OpenNamespaceWorkaround*)p);
   }
   static void destruct_egEnergyCorrcLcLROOT6_OpenNamespaceWorkaround(void *p) {
      typedef ::egEnergyCorr::ROOT6_OpenNamespaceWorkaround current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::egEnergyCorr::ROOT6_OpenNamespaceWorkaround

namespace ROOT {
   // Wrappers around operator new
   static void *new_egEnergyCorrcLcLResolutioncLcLROOT6_OpenNamespaceWorkaround(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::egEnergyCorr::Resolution::ROOT6_OpenNamespaceWorkaround : new ::egEnergyCorr::Resolution::ROOT6_OpenNamespaceWorkaround;
   }
   static void *newArray_egEnergyCorrcLcLResolutioncLcLROOT6_OpenNamespaceWorkaround(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::egEnergyCorr::Resolution::ROOT6_OpenNamespaceWorkaround[nElements] : new ::egEnergyCorr::Resolution::ROOT6_OpenNamespaceWorkaround[nElements];
   }
   // Wrapper around operator delete
   static void delete_egEnergyCorrcLcLResolutioncLcLROOT6_OpenNamespaceWorkaround(void *p) {
      delete ((::egEnergyCorr::Resolution::ROOT6_OpenNamespaceWorkaround*)p);
   }
   static void deleteArray_egEnergyCorrcLcLResolutioncLcLROOT6_OpenNamespaceWorkaround(void *p) {
      delete [] ((::egEnergyCorr::Resolution::ROOT6_OpenNamespaceWorkaround*)p);
   }
   static void destruct_egEnergyCorrcLcLResolutioncLcLROOT6_OpenNamespaceWorkaround(void *p) {
      typedef ::egEnergyCorr::Resolution::ROOT6_OpenNamespaceWorkaround current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::egEnergyCorr::Resolution::ROOT6_OpenNamespaceWorkaround

namespace ROOT {
   // Wrappers around operator new
   static void *new_egEnergyCorrcLcLScalecLcLROOT6_OpenNamespaceWorkaround(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::egEnergyCorr::Scale::ROOT6_OpenNamespaceWorkaround : new ::egEnergyCorr::Scale::ROOT6_OpenNamespaceWorkaround;
   }
   static void *newArray_egEnergyCorrcLcLScalecLcLROOT6_OpenNamespaceWorkaround(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::egEnergyCorr::Scale::ROOT6_OpenNamespaceWorkaround[nElements] : new ::egEnergyCorr::Scale::ROOT6_OpenNamespaceWorkaround[nElements];
   }
   // Wrapper around operator delete
   static void delete_egEnergyCorrcLcLScalecLcLROOT6_OpenNamespaceWorkaround(void *p) {
      delete ((::egEnergyCorr::Scale::ROOT6_OpenNamespaceWorkaround*)p);
   }
   static void deleteArray_egEnergyCorrcLcLScalecLcLROOT6_OpenNamespaceWorkaround(void *p) {
      delete [] ((::egEnergyCorr::Scale::ROOT6_OpenNamespaceWorkaround*)p);
   }
   static void destruct_egEnergyCorrcLcLScalecLcLROOT6_OpenNamespaceWorkaround(void *p) {
      typedef ::egEnergyCorr::Scale::ROOT6_OpenNamespaceWorkaround current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::egEnergyCorr::Scale::ROOT6_OpenNamespaceWorkaround

namespace ROOT {
   // Wrapper around operator delete
   static void delete_eg_resolution(void *p) {
      delete ((::eg_resolution*)p);
   }
   static void deleteArray_eg_resolution(void *p) {
      delete [] ((::eg_resolution*)p);
   }
   static void destruct_eg_resolution(void *p) {
      typedef ::eg_resolution current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::eg_resolution

namespace ROOT {
   // Wrappers around operator new
   static void *new_EgammaFactory(void *p) {
      return  p ? new(p) ::EgammaFactory : new ::EgammaFactory;
   }
   static void *newArray_EgammaFactory(Long_t nElements, void *p) {
      return p ? new(p) ::EgammaFactory[nElements] : new ::EgammaFactory[nElements];
   }
   // Wrapper around operator delete
   static void delete_EgammaFactory(void *p) {
      delete ((::EgammaFactory*)p);
   }
   static void deleteArray_EgammaFactory(void *p) {
      delete [] ((::EgammaFactory*)p);
   }
   static void destruct_EgammaFactory(void *p) {
      typedef ::EgammaFactory current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EgammaFactory

namespace ROOT {
   // Wrapper around operator delete
   static void delete_LArTemperatureCorrectionTool(void *p) {
      delete ((::LArTemperatureCorrectionTool*)p);
   }
   static void deleteArray_LArTemperatureCorrectionTool(void *p) {
      delete [] ((::LArTemperatureCorrectionTool*)p);
   }
   static void destruct_LArTemperatureCorrectionTool(void *p) {
      typedef ::LArTemperatureCorrectionTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::LArTemperatureCorrectionTool

namespace {
  void TriggerDictionaryInitialization_ElectronPhotonFourMomentumCorrection_Reflex_Impl() {
    static const char* headers[] = {
0    };
    static const char* includePaths[] = {
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/ElectronPhotonFourMomentumCorrection/Root",
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/ElectronPhotonFourMomentumCorrection",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include",
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/ElectronPhotonFourMomentumCorrection/cmt/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace CP{class __attribute__((annotate("$clingAutoload$ElectronPhotonFourMomentumCorrection/IEgammaCalibrationAndSmearingTool.h")))  IEgammaCalibrationAndSmearingTool;}
namespace CP{class __attribute__((annotate("$clingAutoload$ElectronPhotonFourMomentumCorrection/EgammaCalibrationAndSmearingTool.h")))  EgammaCalibrationAndSmearingTool;}
namespace AtlasRoot{class __attribute__((annotate("$clingAutoload$ElectronPhotonFourMomentumCorrection/egammaEnergyCorrectionTool.h")))  egammaEnergyCorrectionTool;}
namespace EgammaCalibPeriodRunNumbersExample{struct __attribute__((annotate("$clingAutoload$ElectronPhotonFourMomentumCorrection/IEgammaCalibrationAndSmearingTool.h")))  ROOT6_NamespaceAutoloadHook;}
namespace egEnergyCorr{struct __attribute__((annotate("$clingAutoload$ElectronPhotonFourMomentumCorrection/egammaEnergyCorrectionTool.h")))  ROOT6_OpenNamespaceWorkaround;}
namespace egEnergyCorr{namespace Resolution{struct __attribute__((annotate("$clingAutoload$ElectronPhotonFourMomentumCorrection/egammaEnergyCorrectionTool.h")))  ROOT6_OpenNamespaceWorkaround;}}
namespace egEnergyCorr{namespace Scale{struct __attribute__((annotate("$clingAutoload$ElectronPhotonFourMomentumCorrection/egammaEnergyCorrectionTool.h")))  ROOT6_OpenNamespaceWorkaround;}}
class __attribute__((annotate("$clingAutoload$ElectronPhotonFourMomentumCorrection/eg_resolution.h")))  eg_resolution;
class __attribute__((annotate("$clingAutoload$ElectronPhotonFourMomentumCorrection/EgammaFactory.h")))  EgammaFactory;
class __attribute__((annotate("$clingAutoload$ElectronPhotonFourMomentumCorrection/LArTemperatureCorrectionTool.h")))  LArTemperatureCorrectionTool;
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
  #define ROOTCORE_PACKAGE "ElectronPhotonFourMomentumCorrection"
#endif

#define _BACKWARD_BACKWARD_WARNING_H
// Dear emacs, this is -*-c++-*-
//
// Dictionary generation for this package
//
// - March 2013 : first release
//
#ifndef ELECTRONPHOTONFOURMOMENTUMCORRECTION_ELECTRONPHOTONFOURMOMENTUMCORRECTIONDICT_H
#define ELECTRONPHOTONFOURMOMENTUMCORRECTION_ELECTRONPHOTONFOURMOMENTUMCORRECTIONDICT_H

#include "ElectronPhotonFourMomentumCorrection/egammaEnergyCorrectionTool.h"
#include "ElectronPhotonFourMomentumCorrection/IEgammaCalibrationAndSmearingTool.h"
#include "ElectronPhotonFourMomentumCorrection/EgammaCalibrationAndSmearingTool.h"
#include "ElectronPhotonFourMomentumCorrection/eg_resolution.h"
#include "ElectronPhotonFourMomentumCorrection/EgammaFactory.h"
#include "ElectronPhotonFourMomentumCorrection/LArTemperatureCorrectionTool.h"
#endif

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"AtlasRoot::egammaEnergyCorrectionTool", payloadCode, "@",
"CP::EgammaCalibrationAndSmearingTool", payloadCode, "@",
"CP::IEgammaCalibrationAndSmearingTool", payloadCode, "@",
"EgammaCalibPeriodRunNumbersExample::ROOT6_NamespaceAutoloadHook", payloadCode, "@",
"EgammaCalibPeriodRunNumbersExample::run_2015", payloadCode, "@",
"EgammaCalibPeriodRunNumbersExample::run_2016", payloadCode, "@",
"EgammaFactory", payloadCode, "@",
"LArTemperatureCorrectionTool", payloadCode, "@",
"egEnergyCorr::ESModel", payloadCode, "@",
"egEnergyCorr::Geometry", payloadCode, "@",
"egEnergyCorr::MaterialCategory", payloadCode, "@",
"egEnergyCorr::ROOT6_OpenNamespaceWorkaround", payloadCode, "@",
"egEnergyCorr::Resolution::ROOT6_OpenNamespaceWorkaround", payloadCode, "@",
"egEnergyCorr::Resolution::Variation", payloadCode, "@",
"egEnergyCorr::Resolution::resolutionType", payloadCode, "@",
"egEnergyCorr::Scale::ROOT6_OpenNamespaceWorkaround", payloadCode, "@",
"egEnergyCorr::Scale::Variation", payloadCode, "@",
"eg_resolution", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("ElectronPhotonFourMomentumCorrection_Reflex",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_ElectronPhotonFourMomentumCorrection_Reflex_Impl, {{"namespace DataVector_detail { template <typename B1, typename B2, typename B3> class VirtBases; }", 1},{"template <typename T> class DataVectorBase;", 1},{"template <typename T, typename BASE> class DataVector;", 1},{"namespace DataVector_detail { template <typename T> class DVLEltBaseInit; }", 1}}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_ElectronPhotonFourMomentumCorrection_Reflex_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_ElectronPhotonFourMomentumCorrection_Reflex() {
  TriggerDictionaryInitialization_ElectronPhotonFourMomentumCorrection_Reflex_Impl();
}
