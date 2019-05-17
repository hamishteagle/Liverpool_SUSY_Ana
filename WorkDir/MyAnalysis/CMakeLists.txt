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
  PUBLIC_HEADERS MyAnalysis SUSYTools NewMT2 METUtilities RestFrames

  LINK_LIBRARIES  AsgAnalysisInterfaces         GoodRunsListsLib            TruthUtils            xAODMetaData
AsgExampleToolsLib                    NewMT2Lib		          METInterface                RootCoreUtils  
AsgTools                              METUtilitiesLib  	      SUSYToolsLib            xAODMissingET
IRegionSelector                      SampleHandler    xAODMuon
TauAnalysisToolsLib                egammaRecEvent                  
xAODRootAccess
CPAnalysisExamplesLib       JetCPInterfaces          TrigAnalysisTestLib            tauRecToolsLib                  xAODBTaggingEfficiencyLib     xAODTau
CxxUtils                              JetEDM                      PATCoreLib                     TrigConfBase                 xAODBPhysLib         
JetInterface                PATInterfaces               xAODBTagging            xAODTrigEgamma
JetMomentToolsLib        PMGToolsLib           xAODBase              
JetRecLib                ParticleJetToolsLib         TrigConfxAODLib
JetReclusteringLib          PathResolver                TrigDecisionInterface           xAODCore                xAODTrigMissingET
TrigDecisionToolLib                xAODCutFlow             xAODTrigMuon
EventLoop                             JetSelectorToolsLib          xAODEgamma      
EventLoopAlgs                         JetSubStructureMomentToolsLib  PileupReweightingLib         xAODTrigger
EventLoopGrid                         JetSubStructureUtils                     TrigNavStructure                xAODEventInfo  
EventPrimitives                       RestFramesLib                  xAODTruth
EventShapeInterface                   JetUncertaintiesLib            ReweightUtilsLib               TrigSteeringEvent    
FourMomUtils                          JetUtils                 
FsrUtilsLib             xAODJet   MCTruthClassifierLib            TriggerMatchingToolLib             xAODLuminosity     FTagAnalysisInterfacesLib)


# Add the dictionary:
atlas_add_dictionary (MyAnalysisDict
  MyAnalysis/MyAnalysisDict.h
  MyAnalysis/selection.xml
  LINK_LIBRARIES MyAnalysisLib)


atlas_install_data( data/* )


atlas_add_executable( testRun util/testRunTest.cxx LINK_LIBRARIES MyAnalysisLib ${Boost_LIBRARIES} )
atlas_add_executable( testRunGrid util/testRunGrid.cxx LINK_LIBRARIES MyAnalysisLib ${Boost_LIBRARIES} )

# Install files from the package:
atlas_install_joboptions( share/*.py )

Include(CTest)
add_test(TestMyAnalysis testRun /hepstore/hteagle/Wh/recoSamples/ttbar_checkfile/mc16_13TeV/ /user/hteagle/AnalysisDirectory/Rel21/Base.21.2.72/run/submitdir_ttbarCheck 0 0 1 -1 hteagle 21.2.70  TYPE 0)
find_program( MEMORYCHECK_COMMAND valgrind )
set( MEMORYCHECK_COMMAND_OPTIONS "--trace-children=yes --leak-check=full" )
set( MEMORYCHECK_SUPPRESSIONS_FILE "${PROJECT_SOURCE_DIR}/valgrind_suppress.txt" )
