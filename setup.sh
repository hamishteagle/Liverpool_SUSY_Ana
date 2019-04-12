#!/bin/bash

setupATLAS
mkdir build
cd build
asetup 21.2.67,AnalysisBase
cmake ../WorkDir/
source x86_64-*/setup.sh
make
