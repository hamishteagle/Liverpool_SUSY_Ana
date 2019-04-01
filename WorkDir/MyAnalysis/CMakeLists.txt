#The name of the package:
atlas_subdir (MyAnalysis)

#Add the subdirectories ??
atlas_depends_on_subdirs(
PUBLIC
SUSYTools
)


atlas_add_root_dictionary(MyAnalysisLib MyAnalysisLibCintDict
			ROOT_HEADERS MyAnalysis/MyxAODAnalysis.h Root/LinkDef.h
			EXTERNAL_PACKAGES ROOT
)



# Add the shared library:
atlas_add_library (MyAnalysisLib MyAnalysis/*.h Root/*.cxx ${MyAnalysisLibCintDict}
  PUBLIC_HEADERS MyAnalysis BoostedJetTaggers SUSYTools NewMT2 METUtilities RestFrames

  LINK_LIBRARIES AnaAlgorithmLib AsgAnalysisInterfaces         GoodRunsListsLib            TruthUtils            xAODMetaData
AsgExampleToolsLib                    NewMT2Lib		          METInterface                RootCoreUtils                   ZMassConstraintLib   xAODMetaDataCnv
AsgTools                              HFORToolsLib                METUtilitiesLib  	      SUSYToolsLib            xAODMissingET
AssociationUtilsLib                   IRegionSelector             MVAUtils                    SampleHandler                   egammaLayerRecalibTool  xAODMuon
AthContainers                         InDetTrackSelectionToolLib     MultiDraw                egammaMVACalibLib          xAODPFlow
AthContainersInterfaces               InDetTrackSystematicsToolsLib  MuonEfficiencyCorrectionsLib   TauAnalysisToolsLib                egammaRecEvent          xAODParticleEvent
AthLinks                              IsolationCorrectionsLib        MuonIdHelpersLib               TestTools                                  xAODPrimitives
BoostedJetTaggersLib                  IsolationSelectionLib      MuonMomentumCorrectionsLib     TrackVertexAssociationToolLib                         xAODRootAccess
CPAnalysisExamplesLib                 JetAnalysisInterfacesLib MuonSelectorToolsLib           TrigAnalysisInterfaces                             xAODRootAccessInterfaces
CalibrationDataInterfaceLib           JetCPInterfaces          TrigAnalysisTestLib            tauRecToolsLib                  xAODBTaggingEfficiencyLib     xAODTau
CaloGeoHelpers                        JetCalibToolsLib            TrigBunchCrossingTool       xAODAssociations                xAODTracking
CxxUtils                              JetEDM                      PATCoreLib                     TrigConfBase                 xAODBPhysLib               xAODTrigBphys
DiTauMassToolsLib                        JetInterface                PATInterfaces               TrigConfHLTData                 xAODBTagging            xAODTrigCalo
JetJvtEfficiencyLib                   PFlowUtilsLib                  TrigConfInterfaces       xAODTrigEgamma
ElectronEfficiencyCorrectionLib       JetMomentToolsLib        PMGToolsLib                    TrigConfL1Data                  xAODBase                xAODTrigL1Calo
ElectronPhotonFourMomentumCorrectionLib  JetRecLib                ParticleJetToolsLib         TrigConfxAODLib                    xAODCaloEvent           xAODTrigMinBias
ElectronPhotonSelectorToolsLib        JetReclusteringLib          PathResolver                TrigDecisionInterface           xAODCore                xAODTrigMissingET
ElectronPhotonShowerShapeFudgeToolLib    JetResolutionLib         PhotonEfficiencyCorrectionLib  TrigDecisionToolLib                xAODCutFlow             xAODTrigMuon
EventLoop                             JetSelectorToolsLib         PhotonVertexSelectionLib         xAODEgamma              xAODTrigRinger
EventLoopAlgs                         JetSubStructureMomentToolsLib  PileupReweightingLib     xAODEventFormat         xAODTrigger
EventLoopGrid                         JetSubStructureUtils        QuickAnaLib                    TrigNavStructure                xAODEventInfo           xAODTriggerCnvLib
EventPrimitives                       JetTileCorrectionLib           RestFramesLib               TrigRoiConversionLib               xAODEventShape          xAODTruth
EventShapeInterface                   JetUncertaintiesLib            ReweightUtilsLib               TrigSteeringEvent               xAODForward
FourMomUtils                          JetUtils                    RoiDescriptor               TrigTauMatchingLib                 xAODHIEvent
FsrUtilsLib                                  xAODJet
GeoPrimitives                         MCTruthClassifierLib            TriggerMatchingToolLib             xAODLuminosity)

#Removed from Link_Libraries;
#MCUtils
#RootCoreTest
#HEPUtils
#boost
#SemileptonicCorr
#fastjet
#gmock
#gtest
#Eigen
#TrigGlobalEfficiencyCorrection
#TrigMuonEfficiency
#LHAPDFLib
#RooUnfoldLib
#RootCoreLib
#TriggerAnalysisInterfacesLib

# Add the dictionary:
atlas_add_dictionary (MyAnalysisDict
  MyAnalysis/MyAnalysisDict.h
  MyAnalysis/selection.xml
  LINK_LIBRARIES MyAnalysisLib)


atlas_install_data( data/* )


atlas_add_executable( testRun util/testRunHamish.cxx util/testRunGrid.cxx ${testRun.h}
		      LINK_LIBRARIES MyAnalysisLib ${Boost_LIBRARIES}
)



# Install files from the package:
atlas_install_joboptions( share/*.py )

Include(CTest)
add_test(TestMyAnalysis testRun)
