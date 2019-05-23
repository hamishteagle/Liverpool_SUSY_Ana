file(REMOVE_RECURSE
  "../x86_64-slc6-gcc62-opt/include/MyAnalysis"
  "../x86_64-slc6-gcc62-opt/include/SUSYTools"
  "../x86_64-slc6-gcc62-opt/include/NewMT2"
  "../x86_64-slc6-gcc62-opt/include/METUtilities"
  "../x86_64-slc6-gcc62-opt/include/RestFrames"
  "../x86_64-slc6-gcc62-opt/data/MyAnalysis/.DS_Store"
  "../x86_64-slc6-gcc62-opt/data/MyAnalysis/._.DS_Store"
  "../x86_64-slc6-gcc62-opt/data/MyAnalysis/MyAnalysis"
  "../x86_64-slc6-gcc62-opt/include/MyAnalysis"
  "../x86_64-slc6-gcc62-opt/include/SUSYTools"
  "../x86_64-slc6-gcc62-opt/include/NewMT2"
  "../x86_64-slc6-gcc62-opt/include/METUtilities"
  "../x86_64-slc6-gcc62-opt/include/RestFrames"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/MyAnalysisHeaderInstall.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
