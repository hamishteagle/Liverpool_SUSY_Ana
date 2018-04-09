file(REMOVE_RECURSE
  "../x86_64-slc6-gcc62-opt/include/RestFrames"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/Package_RestFrames_tests.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
