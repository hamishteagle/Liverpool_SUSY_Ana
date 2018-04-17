################################################################################
# Package: NewMT2
################################################################################
	
	 
# Declare the package name:
atlas_subdir( NewMT2 )

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
find_package( ROOT COMPONENTS Core Tree MathCore Hist RIO REQUIRED )
find_package( GTest )

#atlas_add_root_dictionary( NewMT2Lib NewMT2CintDict
#  ROOT_HEADERS NewMT2/*.h Root/LinkDef.h
#  EXTERNAL_PACKAGES ROOT )
  
# Libraries in the package:
atlas_add_library( NewMT2Lib
  NewMT2/*.h Root/*.cxx #${NewMT2CintDict}
  PUBLIC_HEADERS NewMT2
  PRIVATE_INCLUDE_DIRS ${ROOT_INCLUDE_DIRS} ${BOOST_INCLUDE_DIRS}
  LINK_LIBRARIES xAODRootAccess AsgTools PATInterfaces xAODEventFormat xAODEventInfo xAODTruth ${extra_libs} ${ROOT_LIBRARIES} )
