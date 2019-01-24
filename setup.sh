#!/bin/bash

setupATLAS
cd build
asetup 21.2.55,AnalysisBase
cmake ../WorkDir/
source x86_64-*/setup.sh
make
