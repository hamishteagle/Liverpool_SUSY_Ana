################################################################################
# Package: RestFrames
################################################################################
	
	 
# Declare the package name:
atlas_subdir( RestFrames )

# Extra dependencies based on the build environment:
set( extra_deps )
set( extra_libs )
     
# Declare the package's dependencies:
atlas_depends_on_subdirs(
  PUBLIC
    Control/xAODRootAccess 
    Control/AthToolSupport/AsgTools 
    PhysicsAnalysis/AnalysisCommon/PATInterfaces 
    Event/xAOD/xAODBase
    Event/xAOD/xAODTruth
  ${extra_deps} )
  
# External dependencies:
find_package( Boost )
find_package( ROOT COMPONENTS Core Tree MathCore Hist RIO REQUIRED Graf Gpad)
find_package( GTest )

#atlas_add_root_dictionary( RestFramesLib RestFramesCintDict
#  ROOT_HEADERS RestFrames/*.h Root/LinkDef.h
#  EXTERNAL_PACKAGES ROOT )
  
# Libraries in the package:
atlas_add_library( RestFramesLib
  RestFrames/*.h Root/*.cxx #${RestFramesCintDict}
  PUBLIC_HEADERS RestFrames
  PRIVATE_INCLUDE_DIRS ${ROOT_INCLUDE_DIRS} ${BOOST_INCLUDE_DIRS}
  LINK_LIBRARIES xAODRootAccess AsgTools PATInterfaces xAODEventFormat xAODEventInfo xAODTruth ${extra_libs} ${ROOT_LIBRARIES} )
