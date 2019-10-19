#
# Environment configuration file setting up the installed GitLabCITests project.
#

# Set up the base environment using the base image's setup script:
source ~/analysis_release_setup.sh

# Set up the GitLabCITests installation:
#source /home/atlas/LivAnalysis/build/*-opt/setup.sh
source /Liverpool_SbottomAnalysis_Rel21/build/*-opt/setup.sh
echo "Configured LivAnalysis from: /Liverpool_SbottomAnalysis_Rel21/build/*-opt/setup.sh it worked"

# Set up the prompt:
export PS1='\[\033[01;35m\][bash]\[\033[01;31m\][\u LivAnalysis-LivAnalysis]\[\033[01;34m\]:\W >\[\033[00m\] ';
