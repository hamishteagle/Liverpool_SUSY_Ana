# Based on https://gitlab.cern.ch/akraszna/GitLabCITests/blob/158cc55d8f8e1b1204c9e108ee959befb0389663/Dockerfile
# Based on https://gitlab.cern.ch/atlas-phys/exot/hqt/R21_Wt_MET/NtuplerRun2/blob/master/Dockerfile,2019-04-18, Ben Bruers
# 2019-05-19, Hamish Teagle

#
# Image providing the project on top of an AnalysisBase image.
#

# Set up the base image:
FROM atlas/analysisbase:21.2.88

# Copy the project's sources into the image:
# You need to copy this one by one, else unwanted files will be copied, too
COPY WorkDir/CMakeLists.txt Liverpool_SbottomAnalysis_Rel21/source/
COPY WorkDir/Macros Liverpool_SbottomAnalysis_Rel21/source/Macros
COPY WorkDir/NewMT2 Liverpool_SbottomAnalysis_Rel21/source/NewMT2
COPY WorkDir/RestFrames Liverpool_SbottomAnalysis_Rel21/source/RestFrames
COPY WorkDir/MyAnalysis Liverpool_SbottomAnalysis_Rel21/source/MyxAODAnalysis

# and set the permissions from root to atlas
USER root
RUN chown --recursive atlas:atlas Liverpool_SbottomAnalysis_Rel21
USER atlas


# Build the project inside a build/ directory:
# Set up the environment setup script:
RUN mv /home/atlas/release_setup.sh /home/atlas/analysis_release_setup.sh
COPY CI/release_setup.sh /home/atlas/

# Start the image with BASH by default:
CMD /bin/bash
