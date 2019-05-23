#!/bin/bash
export ATLAS_LOCAL_ROOT_BASE=/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase
setupATLAS
lsetup "root 6.06.06-x86_64-slc6-gcc49-opt"
cd ../HistFitter
source setup.sh
cd src/
make
cd ../../HistFitter_running
