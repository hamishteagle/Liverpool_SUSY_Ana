"""
 **********************************************************************************
 * Project: HistFitter - A ROOT-based package for statistical data analysis       *
 * Package: HistFitter                                                            *
 *                                                                                *
 * Description:                                                                   *
 *      Simple example configuration with input trees                             *
 *                                                                                *
 * Authors:                                                                       *
 *      HistFitter group, CERN, Geneva                                            *
 *                                                                                *
 * Redistribution and use in source and binary forms, with or without             *
 * modification, are permitted according to the terms listed in the file          *
 * LICENSE.                                                                       *
 **********************************************************************************
"""

################################################################
## In principle all you have to setup is defined in this file ##
################################################################

## This configuration performs a simplified version of the "soft lepton" fits documented in ATLAS-CONF-2012-041.
## Only two systematics are considered:
##   -JES (Tree-based) conservatively treated like an MC stat error
##   -Alpgen Kt scale (weight-based)
##
## For the real complete implementation, see: HistFitterUser/MET_jets_leptons/python/MyOneLeptonKtScaleFit_mergerSoftLep.py

from configManager import configMgr
from ROOT import kBlack,kWhite,kGray,kRed,kPink,kMagenta,kViolet,kBlue,kAzure,kCyan,kTeal,kGreen,kSpring,kYellow,kOrange,kDashed,kSolid,kDotted
from configWriter import fitConfig,Measurement,Channel,Sample
from systematic import Systematic
from math import sqrt

from ROOT import gROOT, TLegend, TLegendEntry, TCanvas
#gROOT.LoadMacro("./macros/AtlasStyle.C")
import ROOT
#ROOT.SetAtlasStyle()

#---------------------------------------------------------------------------------------------
# Some flags for overridding normal execution and telling ROOT to shut up... use with caution!
#---------------------------------------------------------------------------------------------
#gROOT.ProcessLine("gErrorIgnoreLevel=10001;")
#configMgr.plotHistos = True

#---------------------------------------
# Flags to control which fit is executed
#---------------------------------------
useStat=True
doValidation=False #use or use not validation regions to check exptrapolation to signal regions

#-------------------------------
# Parameters for hypothesis test
#-------------------------------
#configMgr.doHypoTest=True
#configMgr.doExclusion=True
#configMgr.nTOYs=1000
configMgr.calculatorType=2
configMgr.testStatType=3
configMgr.nPoints=1
configMgr.readFromTree=True
#configMgr.scanRange = (0., 2.)

#--------------------------------
# Now we start to build the model
#--------------------------------

# First define HistFactory attributes
configMgr.analysisName = "OneLbb_MVA"

# Scaling calculated by outputLumi / inputLumi
configMgr.inputLumi = 1. # Luminosity of input TTree after weighting
configMgr.outputLumi = 139,0 # Luminosity required for output histograms
configMgr.setLumiUnits("fb-1")

configMgr.histCacheFile = "data/"+configMgr.analysisName+".root"

configMgr.outputFileName = "results/"+configMgr.analysisName+"_Output.root"

# Set the files to read from
bgdFiles = []
dataFiles = []
testFiles = []
newSigFiles = []

if configMgr.readFromTree:

    bgdFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/ttbar.root")
    bgdFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/singletop.root")

    dataFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/topMC.root")

    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392590.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392591.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392592.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392593.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392594.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392595.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392596.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392597.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392598.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392599.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392600.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392601.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392602.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392603.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392604.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392605.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392606.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392607.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392608.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392609.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392610.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392611.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392612.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392613.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392614.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392615.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392616.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392617.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392618.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392619.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392620.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392621.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392622.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392623.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392624.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392625.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392626.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392627.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392628.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392629.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392630.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392631.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392632.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392633.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392634.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392635.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392636.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392637.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392638.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392639.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392640.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392641.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392642.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392643.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392644.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392645.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392646.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392647.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392648.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392649.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392650.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392651.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392652.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392653.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392654.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392655.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392656.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392657.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392658.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392659.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392660.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392661.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392662.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392663.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392664.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392665.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392666.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392667.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392668.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_392669.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394055.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394056.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394057.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394058.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394059.root")
    #newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394060.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394061.root")
    #newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394062.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394063.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394064.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394065.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394066.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394067.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394068.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394069.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394070.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394071.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394072.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394073.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394074.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394075.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394076.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394378.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394379.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394380.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394381.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394382.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394383.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394384.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394385.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394386.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394387.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394388.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394389.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394390.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394391.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394392.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394393.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394394.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394395.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394396.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394397.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394398.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394399.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394400.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394401.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394402.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394403.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394404.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394405.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394406.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394701.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394702.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394703.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394704.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394705.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394706.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394707.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394708.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394709.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394710.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394711.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394712.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394713.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394714.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394715.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394716.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394717.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394718.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394719.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394720.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394721.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394722.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394723.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394724.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394725.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394726.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394727.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394728.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394729.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394730.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394731.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394732.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394733.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394734.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394735.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394736.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394737.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394738.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394739.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394740.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394741.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394742.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394743.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394744.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394745.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394784.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394785.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394786.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394787.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394788.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394789.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394790.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394791.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394792.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394793.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394794.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394795.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394796.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394797.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394798.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394799.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394800.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394801.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394802.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394803.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394804.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394805.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394806.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394807.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394808.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394809.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394810.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394811.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394812.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394813.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394814.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394815.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394816.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394817.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394818.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394819.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394820.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394821.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394822.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394823.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394824.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394825.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394826.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394827.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394828.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394829.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394830.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394831.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394832.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394833.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394834.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394835.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394836.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394837.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394838.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394839.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394840.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394841.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394842.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394843.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394844.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394845.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394846.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394847.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394848.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394849.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394850.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394851.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394852.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394853.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394854.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394855.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394856.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_394857.root")  
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406240.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406241.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406242.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406243.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406244.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406245.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406246.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406247.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406248.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406249.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406250.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406251.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406252.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406253.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406254.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406255.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406256.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406257.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406258.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406259.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406260.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406261.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406262.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406263.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406264.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406265.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406266.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406267.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406268.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406269.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406270.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406271.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406272.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406273.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406274.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406275.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406276.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406277.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406278.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406279.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406280.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406281.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406282.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406283.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406284.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406285.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406286.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406287.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406288.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406289.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406290.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406291.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406292.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406293.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406294.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406295.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406296.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406297.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406298.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406299.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406300.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406301.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406302.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406303.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406304.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406305.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406306.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406307.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406308.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406309.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406310.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406311.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406312.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406313.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406314.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406315.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406316.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406317.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406318.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406319.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406320.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406321.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406322.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406323.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406324.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406325.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406326.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406327.root")
    newSigFiles.append("/user/msullivan/Wh_Upgrade_Studies/ML/TMVATuples/signal_406328.root")

else:
    bgdFiles = ["data/"+configMgr.analysisName+".root"]

# Dictionary of cuts for Tree->hist

configMgr.cutsDict["SR1"] = "400_250_Nominal_nominal > 0.99 && nJets25==2 && metsig_New >8 "


# Tuples of nominal weights without and with b-jet selection
configMgr.weights = ("eventWeight","HFScale") 

#--------------------
# List of systematics
#--------------------

# name of nominal histogram for systematics
configMgr.nomName = ""

# List of samples and their plotting colours
#
topSample = Sample("Top",kGreen-9)
topSample.setStatConfig(False)
#
singleTopSample = Sample("SingleTop", kOrange - 9)
singleTopSample.setStatConfig(False)
#
wJetsSample = Sample("wJets", kBlue)
wJetsSample.setStatConfig(False)
#
dataSample = Sample("Data",kBlack)
dataSample.setData()

## set the file from which the samples should be taken
index = 0
for entry in [topSample,singleTopSample,wJetsSample]:#,wjetsSample,dibosonSample,ttVSample]:
    temp = []
    fileName = ""
    fileName = str(bgdFiles[index])    
    temp.append(fileName)
    entry.addInputs(temp, "CollectionTree_")
    index=index+1

dataSample.addInputs(dataFiles, "ntuple")

#************
#Systematics
#************

exp_syst = Systematic("exp",configMgr.weights,1+0.0646,1-0.0646,"user","userHistoSys")
bkgtheory_syst = Systematic("bkgtheory",configMgr.weights,1+0.07,1-0.07,"user","userOverallSys")

#************
#Bkg-only fit
#************



#-----------------------------
# Exclusion fits 
#-----------------------------

if myFitType==FitType.Exclusion:

    #Setup fit config
    ex = configMgr.addFitConfig("Exclusion")
    configMgr.blindSR = True
    configMgr.useSignalInBlindedData=True
    meas=ex.addMeasurement(name="NormalMeasurement",lumi=1.0,lumiErr=0.01)
    meas.addPOI("mu_SIG")

    #Samples
    ex.addSamples([topSample,singleTopSample,wJetsSample,dataSample])

    #Systematics
    ex.getSample("Top").addSystematic(bkgtheory_syst)
    ex.getSample("Top").addSystematic(exp_syst)
    ex.getSample("SingleTop").addSystematic(bkgtheory_syst)
    ex.getSample("SingleTop").addSystematic(exp_syst)

    #Channels
    sr1 = ex.addChannel("cuts",["SR1"],1,0.5,1.5)


    #Channels
    ex.addSignalChannels([sr1, sr2, sr3])

    #newSigSamples = ["m150.0_0.0", "m152p5_22p5", "m162p5_12p5", "m165.0_35.0", "m175.0_0.0", "m175.0_25.0", "m177p5_47p5", "m187p5_12p5", "m187p5_37p5", "m190.0_60.0", "m200.0_0.0", "m200.0_25.0", "m200.0_50.0", "m202p5_72p5", "m212p5_12p5", "m212p5_37p5", "m212p5_62p5", "m215.0_85.0", "m225.0_0.0", "m225.0_25.0", "m225.0_50.0", "m225.0_75.0", "m237p5_12p5", "m227p5_97p5", "m237p5_37p5", "m237p5_62p5", "m237p5_87p5", "m240.0_110.0", "m250.0_0.0", "m250.0_25.0", "m250.0_50.0", "m250.0_75.0", "m250.0_100.0", "m262p5_12p5", "m262p5_37p5", "m262p5_62p5", "m262p5_87p5", "m275.0_0.0", "m275.0_25.0", "m275.0_50.0", "m275.0_75.0", "m287p5_12p5", "m287p5_37p5", "m287p5_62p5", "m300.0_0.0", "m300.0_25.0", "m300.0_50.0", "m300.0_100.0", "m300.0_75.0", "m312p5_12p5", "m312p5_37p5", "m325.0_0.0", "m325.0_25.0", "m325.0_50.0", "m325.0_75.0", "m325.0_100.0", "m337p5_12p5", "m350.0_0.0", "m350.0_25.0", "m350.0_50.0", "m350.0_75.0", "m350.0_100.0", "m375.0_0.0", "m375.0_25.0", "m375.0_50.0", "m375.0_75.0", "m400.0_0.0", "m400.0_25.0", "m400.0_50.0", "m425.0_0.0", "m425.0_25.0", "m450.0_0.0", "m400.0_75.0", "m425.0_50.0", "m425.0_75.0", "m450.0_25.0", "m450.0_50.0", "m475.0_0.0", "m475.0_25.0", "m500.0_0.0", "m275.0_100.0", "m375.0_100.0", "m400.0_100.0", "m425.0_100.0", "m450.0_100.0", "m475.0_100.0", "m450.0_75.0", "m475.0_75.0", "m500.0_75.0", "m475.0_50.0", "m500.0_50.0", "m525.0_50.0", "m500.0_25.0", "m525.0_25.0", "m550.0_25.0", "m575.0_25.0", "m525.0_0.0", "m550.0_0.0", "m575.0_0.0", "m600.0_0.0", "m275.0_145.0", "m275.0_125.0", "m300.0_125.0", "m325.0_125.0", "m350.0_125.0", "m375.0_125.0", "m400.0_125.0", "m425.0_125.0", "m450.0_125.0", "m300.0_170.0", "m300.0_150.0", "m325.0_150.0", "m350.0_150.0", "m375.0_150.0", "m400.0_150.0", "m425.0_150.0", "m450.0_150.0", "m325.0_190.0", "m325.0_175.0", "m350.0_175.0", "m375.0_175.0", "m400.0_175.0", "m425.0_175.0", "m450.0_175.0", "m350.0_200.0", "m375.0_200.0", "m400.0_200.0", "m425.0_200.0", "m450.0_200.0", "m500.0_100.0", "m500.0_125.0", "m500.0_150.0", "m475.0_150.0", "m475.0_125.0", "m525.0_75.0", "m525.0_100.0", "m525.0_125.0", "m550.0_50.0", "m550.0_75.0", "m550.0_100.0", "m550.0_125.0", "m575.0_50.0", "m575.0_75.0", "m575.0_100.0", "m575.0_125.0", "m600.0_15.0", "m600.0_50.0", "m600.0_75.0", "m600.0_100.0", "m600.0_125.0", "m625.0_0.0", "m625.0_25.0", "m625.0_50.0", "m625.0_75.0", "m625.0_100.0", "m650.0_0.0", "m650.0_25.0", "m650.0_50.0", "m650.0_75.0", "m650.0_100.0", "m675.0_0.0", "m675.0_25.0", "m675.0_50.0", "m675.0_75.0", "m675.0_100.0", "m700.0_0.0", "m700.0_25.0", "m700.0_50.0", "m750.0_0.0", "m750.0_25.0", "m750.0_50.0", "m800.0_0.0", "m800.0_25.0", "m800.0_50.0", "m375.0_225.0", "m400.0_225.0", "m400.0_250.0", "m425.0_225.0", "m425.0_250.0", "m450.0_225.0", "m450.0_250.0", "m475.0_175.0", "m475.0_200.0", "m475.0_225.0", "m475.0_250.0", "m500.0_175.0", "m500.0_200.0", "m500.0_225.0", "m500.0_250.0", "m525.0_150.0", "m525.0_175.0", "m525.0_200.0", "m525.0_225.0", "m525.0_250.0", "m550.0_150.0", "m550.0_175.0", "m550.0_200.0", "m550.0_225.0", "m550.0_250.0", "m575.0_150.0", "m575.0_175.0", "m575.0_200.0", "m575.0_225.0", "m575.0_250.0", "m600.0_150.0", "m600.0_175.0", "m600.0_200.0", "m600.0_225.0", "m600.0_250.0", "m625.0_125.0", "m625.0_150.0", "m625.0_175.0", "m625.0_200.0", "m625.0_225.0", "m625.0_250.0", "m650.0_125.0", "m650.0_150.0", "m650.0_175.0", "m650.0_200.0", "m650.0_225.0", "m650.0_250.0", "m675.0_125.0", "m675.0_150.0", "m675.0_175.0", "m675.0_200.0", "m675.0_225.0", "m675.0_250.0", "m700.0_100.0", "m700.0_125.0", "m700.0_150.0", "m700.0_175.0", "m700.0_200.0", "m700.0_225.0", "m700.0_250.0", "m750.0_100.0", "m750.0_125.0", "m750.0_150.0", "m750.0_175.0", "m750.0_200.0", "m750.0_225.0", "m750.0_250.0", "m800.0_100.0", "m800.0_125.0", "m800.0_150.0", "m800.0_175.0", "m800.0_200.0", "m800.0_225.0", "m800.0_250.0", "m500.0_1.0", "m500.0_105.0", "m500.0_210.0", "m500.0_310.0", "m600.0_1.0", "m600.0_105.0", "m600.0_210.0", "m600.0_315.0", "m600.0_415.0", "m700.0_1.0", "m700.0_105.0", "m700.0_210.0", "m700.0_315.0", "m700.0_420.0", "m700.0_520.0", "m800.0_1.0", "m800.0_105.0", "m800.0_210.0", "m800.0_315.0", "m800.0_420.0", "m800.0_525.0", "m800.0_625.0", "m900.0_1.0", "m900.0_100.0", "m900.0_200.0", "m900.0_300.0", "m900.0_400.0", "m900.0_500.0", "m900.0_600.0", "m900.0_700.0", "m1000.0_1.0", "m1000.0_100.0", "m1000.0_200.0", "m1000.0_300.0", "m1000.0_400.0", "m1000.0_500.0", "m1000.0_600.0", "m1000.0_700.0", "m1000.0_800.0", "m1100.0_1.0", "m1100.0_100.0", "m1100.0_200.0", "m1100.0_300.0", "m1100.0_400.0", "m1100.0_500.0", "m1100.0_600.0", "m1100.0_700.0", "m1100.0_800.0", "m1100.0_900.0", "m1200.0_1.0", "m1200.0_100.0", "m1200.0_200.0", "m1200.0_300.0", "m1200.0_400.0", "m1200.0_500.0", "m1200.0_600.0", "m1200.0_700.0", "m1200.0_800.0", "m1200.0_900.0", "m1300.0_1.0", "m1300.0_100.0", "m1300.0_200.0", "m1300.0_300.0", "m1300.0_400.0", "m1300.0_500.0", "m1300.0_600.0", "m1300.0_700.0", "m1300.0_800.0", "m1300.0_900.0", "m1400.0_1.0", "m1400.0_100.0", "m1400.0_200.0", "m1400.0_300.0", "m1400.0_400.0", "m1400.0_500.0", "m1400.0_600.0", "m1400.0_700.0", "m1400.0_800.0", "m1400.0_900.0", "m1500.0_1.0", "m1500.0_100.0", "m1500.0_200.0", "m1500.0_300.0", "m1500.0_400.0", "m1500.0_500.0", "m1500.0_600.0", "m1500.0_700.0", "m1500.0_800.0", "m1500.0_900.0"]    


    sigDir = "/hepstore/hteagle/Wh/ntuple_21.2.60/Signal/"


    index = 0
    for sig in testSamples:

        myTopLvl = configMgr.addFitConfigClone(ex,"Sig_%s"%sig)

        sigSample = Sample(sig,kPink)
        temp = []
        temp.append(testFiles[index])
        sigSample.addInputs(temp, "ntuple")
        sigSample.setNormByTheory()
        sigSample.setNormFactor("mu_SIG",1.,0.,5.)   
        sigSample.addSystematic(exp_syst)                
        myTopLvl.addSamples(sigSample)
        myTopLvl.setSignalSample(sigSample)
        index = index+1

