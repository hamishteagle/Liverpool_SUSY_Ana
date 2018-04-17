RC_CXX       = g++
RC_LD        = g++
RC_CXXFLAGS  = -I/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/HFORTools/Root -I/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/HFORTools -O2 -Wall -fPIC -pthread -std=c++11 -Wno-deprecated-declarations -m64 -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include -I/user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/include -g -Wno-tautological-undefined-compare -DROOTCORE -pthread -std=c++11 -Wno-deprecated-declarations -m64 -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include -pipe -W -Wall -Wno-deprecated -pedantic -Wwrite-strings -Wpointer-arith -Woverloaded-virtual -Wno-long-long -Wdeprecated-declarations -DROOTCORE_RELEASE_SERIES=24 -DROOTCORE_TEST_FILE=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r7725/mc15_13TeV.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.merge.AOD.e3698_s2608_s2183_r7725_r7676/AOD.07915862._000100.pool.root.1\" -DROOTCORE_TEST_DATA=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r7725\" -DASG_TEST_FILE_DATA=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r7562/data15_13TeV.00284154.physics_Main.merge.AOD.r7562_p2521/AOD.07687819._000382.pool.root.1\" -DASG_TEST_FILE_MC=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r7725/mc15_13TeV.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.merge.AOD.e3698_s2608_s2183_r7725_r7676/AOD.07915862._000100.pool.root.1\" -DASG_TEST_FILE_MCAFII=\"\" -DXAOD_STANDALONE -DXAOD_ANALYSIS -DASGTOOL_STANDALONE -DROOTCORE_PACKAGE=\"HFORTools\" 
RC_DICTFLAGS = -I/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/HFORTools/Root -I/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/HFORTools -O2 -Wall -fPIC -pthread -std=c++11 -Wno-deprecated-declarations -m64 -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include -I/user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/include -g -Wno-tautological-undefined-compare -DROOTCORE -pthread -std=c++11 -Wno-deprecated-declarations -m64 -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include -pipe -W -Wall -Wno-deprecated -pedantic -Wwrite-strings -Wpointer-arith -Woverloaded-virtual -Wno-long-long -Wdeprecated-declarations -DROOTCORE_RELEASE_SERIES=24 -DROOTCORE_TEST_FILE=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r7725/mc15_13TeV.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.merge.AOD.e3698_s2608_s2183_r7725_r7676/AOD.07915862._000100.pool.root.1\" -DROOTCORE_TEST_DATA=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r7725\" -DASG_TEST_FILE_DATA=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r7562/data15_13TeV.00284154.physics_Main.merge.AOD.r7562_p2521/AOD.07687819._000382.pool.root.1\" -DASG_TEST_FILE_MC=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r7725/mc15_13TeV.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.merge.AOD.e3698_s2608_s2183_r7725_r7676/AOD.07915862._000100.pool.root.1\" -DASG_TEST_FILE_MCAFII=\"\" -DXAOD_STANDALONE -DXAOD_ANALYSIS -DASGTOOL_STANDALONE -DROOTCORE_PACKAGE=\"HFORTools\" 
RC_INCFLAGS  = -I/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/HFORTools/Root -I/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/HFORTools -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include -I/user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/include -DROOTCORE -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/include -DROOTCORE_RELEASE_SERIES=24 -DROOTCORE_TEST_FILE=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r7725/mc15_13TeV.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.merge.AOD.e3698_s2608_s2183_r7725_r7676/AOD.07915862._000100.pool.root.1\" -DROOTCORE_TEST_DATA=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r7725\" -DASG_TEST_FILE_DATA=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r7562/data15_13TeV.00284154.physics_Main.merge.AOD.r7562_p2521/AOD.07687819._000382.pool.root.1\" -DASG_TEST_FILE_MC=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r7725/mc15_13TeV.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.merge.AOD.e3698_s2608_s2183_r7725_r7676/AOD.07915862._000100.pool.root.1\" -DASG_TEST_FILE_MCAFII=\"\" -DXAOD_STANDALONE -DXAOD_ANALYSIS -DASGTOOL_STANDALONE -DROOTCORE_PACKAGE=\"HFORTools\"
RC_LIBFLAGS  = -shared -m64 -L/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/lib -lCore -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -pthread -lm -ldl -rdynamic 
RC_DICTLIBFLAGS = -shared -m64 -L/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/lib -lCore -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -pthread -lm -ldl -rdynamic
RC_BINFLAGS  = -L/user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/lib -L/user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/lib/x86_64-slc6-gcc49-opt -lHFORTools -lxAODJet -lGenVector -lxAODPFlow -lGenVector -lxAODCaloEvent -lCaloGeoHelpers -lxAODBTagging -lxAODTracking -lxAODTrigger -lPathResolver -lboost_filesystem -lHist -lPATCore -lxAODTruth -lTruthUtils -lxAODEventInfo -lxAODBase -lPhysics -lEventLoop -lProofPlayer -lProof -lHist -lTree -lSampleHandler -lPyROOT -lProof -lTree -lAsgTools -lxAODRootAccess -lNet -lTree -lxAODEventFormat -lxAODCore -lRIO -lAthContainers -lAthLinks -lCxxUtils -lboost_regex -lboost_system -lxAODRootAccessInterfaces -lAsg_GoogleTest -lRootCoreUtils -lboost_regex -lTree -lHist -m64 -L/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.04.16-x86_64-slc6-gcc49-opt/lib -lCore -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -pthread -lm -ldl -rdynamic


all_HFORTools : dep_HFORTools package_HFORTools

package_HFORTools :  /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/lib/libHFORTools.so /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/lib/libHFORTools_Reflex.so /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/test-bin/ut_HFORTools_test postcompile_HFORTools

/user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/lib/libHFORTools.so :  /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/obj/HFOR_Truth.o /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/obj/HFORSelectionTool.o | /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/lib
	$(SILENT)echo Linking `basename $@`
	$(SILENT)$(RC_LD) /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/obj/HFOR_Truth.o /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/obj/HFORSelectionTool.o $(RC_LIBFLAGS) -L/user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/lib/x86_64-slc6-gcc49-opt -o $@

/user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/obj/%.o : /cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/HFORTools/Root/%.cxx | /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/obj/HFOR_Truth.d
	$(SILENT)echo Compiling `basename $@`
	$(SILENT)rc --internal check_dep_cc HFORTools $@
	$(SILENT)$(RC_CXX) $(RC_CXXFLAGS) $(INCLUDES) -c $< -o $@

/user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/obj/%.d : /cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/HFORTools/Root/%.cxx | /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/obj /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/obj
	$(SILENT)echo Making dependency for `basename $<`
	$(SILENT)rc --internal make_dep $(RC_CXX) $(RC_CXXFLAGS) $(INCLUDES)  -- $@ $< 

/user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/obj : 
	$(SILENT)echo Making directory $@
	$(SILENT)mkdir -p $@

/user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/lib : 
	$(SILENT)echo Making directory $@
	$(SILENT)mkdir -p $@

/user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/lib/libHFORTools_Reflex.so :  /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/lib/libHFORTools.so /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/obj/HFORTools_Reflex.o | /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/lib
	$(SILENT)echo Linking `basename $@`
	$(SILENT)$(RC_LD) -L/user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/lib -lHFORTools /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/obj/HFORTools_Reflex.o $(RC_DICTLIBFLAGS) $(RC_BINFLAGS) -o $@

/user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/obj/HFORTools_Reflex.o : /cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/HFORTools/HFORTools/HFORToolsDict.h /cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/HFORTools/HFORTools/selection.xml | /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/obj/HFORTools_Reflex.d
	$(SILENT)echo Compiling `basename $@`
	$(SILENT)rc --internal check_dep_cc HFORTools $@
	$(SILENT)rc --internal genreflex /cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/HFORTools/HFORTools/HFORToolsDict.h /cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/HFORTools/HFORTools/selection.xml /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/obj/HFORTools_Reflex.cxx /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/lib/libHFORTools_Reflex.rootmap libHFORTools_Reflex.so /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/lib $(RC_INCFLAGS)
	$(SILENT)$(RC_CXX) $(RC_DICTFLAGS) $(INCLUDES) -c /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/obj/HFORTools_Reflex.cxx -o $@

/user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/obj/HFORTools_Reflex.d : /cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/HFORTools/HFORTools/HFORToolsDict.h | /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/obj /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/obj
	$(SILENT)echo Making dependency for `basename $<`
	$(SILENT)rc --internal make_dep $(RC_CXX) $(RC_CXXFLAGS) $(INCLUDES)  -- $@ $< 

/user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/test-bin/% : /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/obj/%.o | /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/lib/libHFORTools.so /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/test-bin
	$(SILENT)echo Linking `basename $@`
	$(SILENT)$(RC_LD) -o $@ $< $(RC_BINFLAGS)

/user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/obj/%.o : /cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/HFORTools/test/%.cxx | /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/obj/ut_HFORTools_test.d
	$(SILENT)echo Compiling `basename $@`
	$(SILENT)rc --internal check_dep_cc HFORTools $@
	$(SILENT)$(RC_CXX) $(RC_CXXFLAGS) $(INCLUDES) -c $< -o $@

/user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/obj/%.d : /cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.4.34/HFORTools/test/%.cxx | /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/obj /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/obj
	$(SILENT)echo Making dependency for `basename $<`
	$(SILENT)rc --internal make_dep $(RC_CXX) $(RC_CXXFLAGS) $(INCLUDES)  -- $@ $< 

/user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/test-bin : 
	$(SILENT)echo Making directory $@
	$(SILENT)mkdir -p $@

postcompile_HFORTools :  /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/lib/libHFORTools.so /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/lib/libHFORTools_Reflex.so /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/test-bin/ut_HFORTools_test
	$(SILENT)rc --internal postcompile_pkg HFORTools


dep_HFORTools : /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/obj/ut_HFORTools_test.d /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/obj/HFORTools_Reflex.d /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/obj/HFOR_Truth.d /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/obj/HFORSelectionTool.d


-include  /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/obj/ut_HFORTools_test.d /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/obj/HFORTools_Reflex.d /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/obj/HFOR_Truth.d /user/hteagle/AnalysisDirectory/Base_2_4_34/RootCoreBin/obj/x86_64-slc6-gcc49-opt/HFORTools/obj/HFORSelectionTool.d
