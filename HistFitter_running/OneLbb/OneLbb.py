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
#configMgr.doHypoTest=False
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
configMgr.analysisName = "OneLbb"

# Scaling calculated by outputLumi / inputLumi
configMgr.inputLumi = 1. # Luminosity of input TTree after weighting
configMgr.outputLumi = 36.1 # Luminosity required for output histograms
configMgr.setLumiUnits("fb-1")

configMgr.histCacheFile = "data/"+configMgr.analysisName+".root"

configMgr.outputFileName = "results/"+configMgr.analysisName+"_Output.root"

# Set the files to read from
bgdFiles = []
dataFiles = []
sigFiles = []
if configMgr.readFromTree:
    bgdFiles.append("/hepstore/msullivan/Wh_tuples/ttbar/hadd/ttbar.root")
    bgdFiles.append("/hepstore/msullivan/Wh_tuples/ttbar/hadd/ttbar.root")
    bgdFiles.append("/hepstore/msullivan/Wh_tuples/ttbar/hadd/ttbar.root")
    bgdFiles.append("/hepstore/msullivan/Wh_tuples/singletop/hadd/singletop.root")
    bgdFiles.append("/hepstore/msullivan/Wh_tuples/wjets/hadd/wjets.root")
    bgdFiles.append("/hepstore/msullivan/Wh_tuples/zjets/hadd/zjets.root")
    bgdFiles.append("/hepstore/msullivan/Wh_tuples/ttV/hadd/ttV.root")
    bgdFiles.append("/hepstore/msullivan/Wh_tuples/ttH/hadd/ttH.root")
    bgdFiles.append("/hepstore/msullivan/Wh_tuples/VH/hadd/VH.root")
    bgdFiles.append("/hepstore/msullivan/Wh_tuples/diboson/hadd/diboson.root")
    bgdFiles.append("/hepstore/msullivan/Wh_tuples/triboson/hadd/triboson.root")
    dataFiles.append("/hepstore/msullivan/Data_new/merge/Data_new.root")
    if myFitType==FitType.Exclusion:
        # 1-step simplified model
        sigFiles.append("/hepstore/msullivan/OutputDir_392669/data-output/DAOD_SUSY5.root")
else:
    bgdFiles = ["data/"+configMgr.analysisName+".root"]

# Dictionnary of cuts for Tree->hist
leptonSelection = "nBaselineLeptons == 1 && nLeptons == 1 && pTl1 > 25 && "
jetSelection = "nBJets == 2 && pTb1 > 25 && pTb2 > 25 && pTj1 > 25 && pTj2 > 25 && (pTj3 > 25 || pTj3 == -99) && pTj4 < 25 && "
sampleOR = "(mcID != 410000 && mcID != 410013 && mcID != 410014 || truthFilterMET < 200) && (mcID != 410013 && mcID != 410014 || truthFilterHT < 500) && "
commonSelection = leptonSelection + jetSelection + sampleOR + " m_bb > 50 && m_T > 40 && ETMiss > 200 && passedMETTrigger "
VROFFSelection = leptonSelection + jetSelection + sampleOR + " m_bb > 50 && m_T > 40 && ETMiss > 180 && passedMETTrigger "
#SR
configMgr.cutsDict["SR1"] = commonSelection + " m_CTcorr > 160 && (m_bb > 105 && m_bb < 135) && (m_T > 140 && m_T < 200) "
configMgr.cutsDict["SR2"] = commonSelection + " m_CTcorr > 160 && (m_bb > 105 && m_bb < 135) && (m_T > 140 && m_T < 200) "
configMgr.cutsDict["SR3"] = commonSelection + " m_CTcorr > 160 && (m_bb > 105 && m_bb < 135) && m_T > 200 "
#CRttbar
configMgr.cutsDict["CRTT1"] = commonSelection + " m_CTcorr < 160 && (m_bb < 105 || m_bb > 135) && (m_T > 100 && m_T < 140) "
configMgr.cutsDict["CRTT2"] = commonSelection + " m_CTcorr < 160 && (m_bb < 105 || m_bb > 135) && (m_T > 140 && m_T < 200) "
configMgr.cutsDict["CRTT3"] = commonSelection + " m_CTcorr < 160 && (m_bb < 105 || m_bb > 135) && m_T > 200 "
#CRST
configMgr.cutsDict["CRST"] = commonSelection + " m_CTcorr > 160 && m_bb > 195 && m_T > 100 "
#CRST (split)
configMgr.cutsDict["CRST1"] = commonSelection + " m_CTcorr > 160 && m_bb > 195 && (m_T > 100 && m_T < 140) "
configMgr.cutsDict["CRST2"] = commonSelection + " m_CTcorr > 160 && m_bb > 195 && (m_T > 100 && m_T < 140) "
configMgr.cutsDict["CRST3"] = commonSelection + " m_CTcorr > 160 && m_bb > 195 && m_T > 200 "
#CRW
configMgr.cutsDict["CRW"] = commonSelection + " m_CTcorr > 160 && m_bb < 80 && m_T < 100 "
#VR-ON
configMgr.cutsDict["VR1ON"] = commonSelection + " m_CTcorr < 160 && (m_bb > 105 && m_bb < 135) && (m_T > 100 && m_T < 140) "
configMgr.cutsDict["VR2ON"] = commonSelection + " m_CTcorr < 160 && (m_bb > 105 && m_bb < 135) && (m_T > 140 && m_T < 200) "
configMgr.cutsDict["VR3ON"] = commonSelection + " m_CTcorr < 160 && (m_bb > 105 && m_bb < 135) && m_T > 200 "
#VR-OFF
configMgr.cutsDict["VR1OFF"] = VROFFSelection + " m_CTcorr > 160 && ((m_bb > 50 && m_bb < 95) || (m_bb > 145 && m_bb < 195)) && (m_T > 100 && m_T < 140) "
configMgr.cutsDict["VR2OFF"] = VROFFSelection + " m_CTcorr > 160 && ((m_bb > 50 && m_bb < 95) || (m_bb > 145 && m_bb < 195)) && (m_T > 140 && m_T < 200) "
configMgr.cutsDict["VR3OFF"] = VROFFSelection + " m_CTcorr > 160 && ((m_bb > 50 && m_bb < 95) || (m_bb > 145 && m_bb < 195)) && m_T > 200 "

# Tuples of nominal weights without and with b-jet selection
configMgr.weights = ("mcEventWeight","fixedFinalXSectScale","bJetSF","puWgt")

#--------------------
# List of systematics
#--------------------

# KtScale uncertainty as histoSys - two-sided, no additional normalization
#topKtScale = Systematic("KtScaleTop",configMgr.weights,ktScaleTopHighWeights,ktScaleTopLowWeights,"weight","histoSys")
#wzKtScale = Systematic("KtScaleWZ",configMgr.weights,ktScaleWHighWeights,ktScaleWLowWeights,"weight","histoSys")
#topKtScale = Systematic("KtScaleTop",configMgr.weights,ktScaleTopHighWeights,ktScaleTopLowWeights,"weight","overallNormHistoSys")
#wzKtScale = Systematic("KtScaleWZ",configMgr.weights,ktScaleWHighWeights,ktScaleWLowWeights,"weight","overallNormHistoSys")


# JES uncertainty as shapeSys - one systematic per region (combine WR and TR), merge samples
#jes = Systematic("JES","_NoSys","_JESup","_JESdown","tree","histoSys")
#jes = Systematic("JES","_NoSys","_JESup","_JESdown","tree","overallNormHistoSys")

#statWRwz  = Systematic("SLWR_wz", "_NoSys","","","tree","shapeStat")
#statWRtop = Systematic("SLWR_top","_NoSys","","","tree","shapeStat")

# name of nominal histogram for systematics
configMgr.nomName = ""

# List of samples and their plotting colours
#
topSample1 = Sample("Top_bin1",kGreen-9)
topSample1.setNormFactor("mu_Top1",1.,0.,5.)
#topSample1.setNormRegions([("CRTT1","cuts"),("CRTT2","cuts"),("CRTT3","cuts"),("CRST","cuts"),("CRW","cuts")])
topSample1.setStatConfig(useStat)
topSample1.addSampleSpecificWeight("(m_T>100. && m_T<140.)")
#
topSample2 = Sample("Top_bin2",kGreen-9)
topSample2.setNormFactor("mu_Top2",1.,0.,5.)
#topSample2.setNormRegions([("CRTT1","cuts"),("CRTT2","cuts"),("CRTT3","cuts"),("CRST","cuts"),("CRW","cuts")])
topSample2.setStatConfig(useStat)
topSample2.addSampleSpecificWeight("(m_T>140. && m_T<200.)")
#
topSample3 = Sample("Top_bin3",kGreen-9)
topSample3.setNormFactor("mu_Top3",1.,0.,5.)
#topSample3.setNormRegions([("CRTT1","cuts"),("CRTT2","cuts"),("CRTT3","cuts"),("CRST","cuts"),("CRW","cuts")])
topSample3.setStatConfig(useStat)
topSample3.addSampleSpecificWeight("(m_T > 200.)")
#
singletopSample = Sample("SingleTop", kOrange - 9)
singletopSample.setNormFactor("mu_ST",1.,0.,5.)
#singletopSample.setNormRegions([("CRTT1","cuts"),("CRTT2","cuts"),("CRTT3","cuts"),("CRST","cuts"),("CRW","cuts")])
singletopSample.setStatConfig(useStat)
#
wjetsSample = Sample("Wjets", kBlue - 9)
wjetsSample.setNormFactor("mu_Wjets",1.,0.,5.)
#wjetsSample.setNormRegions([("CRTT1","cuts"),("CRTT2","cuts"),("CRTT3","cuts"),("CRST","cuts"),("CRW","cuts")])
wjetsSample.setStatConfig(useStat)
#
zjetsSample = Sample("zjets", kRed - 9)
zjetsSample.setStatConfig(useStat)
#
ttVSample = Sample("ttV", kRed - 8)
ttVSample.setStatConfig(useStat)
#
ttHSample = Sample("ttH", kRed - 7)
ttHSample.setStatConfig(useStat)
#
VHSample = Sample("VH", kBlue - 6)
VHSample.setStatConfig(useStat)
#
DibosonSample = Sample("diboson", kBlue - 5)
DibosonSample.setStatConfig(useStat)
#
TribosonSample = Sample("triboson", kBlue - 4)
TribosonSample.setStatConfig(useStat)
#
dataSample = Sample("Data",kBlack)
dataSample.setData()
## set the file from which the samples should be taken
index = 0
for entry in [topSample1,topSample2,topSample3,singletopSample,wjetsSample,zjetsSample,ttVSample,ttHSample,VHSample,DibosonSample,TribosonSample]:
    temp = []    
    fileName = str(bgdFiles[index])
    temp.append(fileName)
    entry.addInputs(temp, "CollectionTree_")
    index=index+1

dataSample.addInputs(dataFiles, "CollectionTree_")

#Binnings
#nJetBinLowHard = 3
#nJetBinLowSoft = 2
#nJetBinHighTR = 10
#nJetBinHighWR = 10


#nBJetBinLow = 0
#nBJetBinHigh = 4
#
#meffNBins = 6
#meffBinLow = 400.
#meffBinHigh = 1600.
#
#meffNBinsSR4 = 4
#meffBinLowSR4 = 800.
#meffBinHighSR4 = 1600.
#
#lepPtNBins = 6
#lepPtLow = 20.
#lepPtHigh = 600.
#
#srNBins = 1
#srBinLow = 0.5
#srBinHigh = 1.5
#
#************
#Bkg only fit
#************

bkt = configMgr.addFitConfig("BkgOnly")
if useStat:
    bkt.statErrThreshold=0.05 
else:
    bkt.statErrThreshold=None
bkt.addSamples([topSample1,topSample2,topSample3,singletopSample,wjetsSample,zjetsSample,ttVSample,ttHSample,VHSample,DibosonSample,TribosonSample,dataSample])
tmp = bkt.addChannel("cuts",["CRTT1"], 1, 0.5, 1.5)
bkt.addBkgConstrainChannels(tmp)
tmp = bkt.addChannel("cuts",["CRTT2"], 1, 0.5, 1.5)
bkt.addBkgConstrainChannels(tmp)
tmp = bkt.addChannel("cuts",["CRTT3"], 1, 0.5, 1.5)
bkt.addBkgConstrainChannels(tmp)
tmp = bkt.addChannel("cuts",["CRST"], 1, 0.5, 1.5)
bkt.addBkgConstrainChannels(tmp)
tmp = bkt.addChannel("cuts",["CRW"], 1, 0.5, 1.5)
bkt.addBkgConstrainChannels(tmp)
#***********
#Test stuff
#***********
#bkt.addChannel("cuts",["SR3"],1,0.5,1.5)

# Systematics to be applied globally within this topLevel
#bkt.getSample("Top").addSystematic(topKtScale)
#bkt.getSample("WZ").addSystematic(wzKtScale)

meas=bkt.addMeasurement(name="NormalMeasurement",lumi=1.0,lumiErr=0.039)
meas.addPOI("mu_SIG")
meas.addParamSetting("mu_BG",True,1)
meas.addParamSetting("Lumi",True,1)

#-------------------------------------------------
# Constraining regions - statistically independent
#-------------------------------------------------

# WR using nJet
#nJetWS = bkt.addChannel("nJet",["SLWR"],nJetBinHighWR-nJetBinLowSoft,nJetBinLowSoft,nJetBinHighWR)
#nJetWS.hasB = True
#nJetWS.hasBQCD = False
#nJetWS.useOverflowBin = False
#nJetWS.addSystematic(jes)

# TR using nJet
#nJetTS = bkt.addChannel("nJet",["SLTR"],nJetBinHighTR-nJetBinLowSoft,nJetBinLowSoft,nJetBinHighTR)
#nJetTS.hasB = True
#nJetTS.hasBQCD = True
#nJetTS.useOverflowBin = False    
#nJetTS.addSystematic(jes)

#bkt.addBkgConstrainChannels([nJetWS,nJetTS])

### alternative: statistical error for each sample
#nJetWS.getSample("Top").addSystematic(statWRtop)
#nJetWS.getSample("WZ").addSystematic(statWRwz)

###################
#                                               #
#    Example new cosmetics     #
#                                               #
###################

# Set global plotting colors/styles
bkt.dataColor = dataSample.color
bkt.totalPdfColor = kBlue
bkt.errorFillColor = kBlue-5
bkt.errorFillStyle = 3004
bkt.errorLineStyle = kDashed
bkt.errorLineColor = kBlue-5

# Set Channel titleX, titleY, minY, maxY, logY
#nJetWS.minY = 0.5
#nJetWS.maxY = 5000
#nJetWS.titleX = "n jets"
#nJetWS.titleY = "Entries"
#nJetWS.logY = True
#nJetWS.ATLASLabelX = 0.25
#nJetWS.ATLASLabelY = 0.85
#nJetWS.ATLASLabelText = "Work in progress"


#--------------------------------------------------------------
# Validation regions - not necessarily statistically independent
#--------------------------------------------------------------

if doValidation:
    # s1l2jT
    #srs1l2jTChannel = bkt.addChannel("cuts",["SR1sl2j"],srNBins,srBinLow,srBinHigh)
    #srs1l2jTChannel.addSystematic(jes)

    # additional VRs if using soft lep CRs
    #nJetSLVR2 = bkt.addChannel("nJet",["SLVR2"],nJetBinHighTR-nJetBinLowSoft,nJetBinLowSoft,nJetBinHighTR)
    #nJetSLVR2.addSystematic(jes)
    
    #signal region treated as validation region for this case
    #mm2J = bkt.addChannel("met/meff2Jet",["SS"],6,0.1,0.7)
    #mm2J.useOverflowBin=True
    #mm2J.addSystematic(jes)
    #mm2J.remapSystChanName = 'metmeff2Jet_SSloose'

    #signal region treated as validation region for this case
    #mm2Jl = bkt.addChannel("met/meff2Jet",["SSloose"],6,0.1,0.7)
    #mm2Jl.useOverflowBin=True
    #mm2Jl.addSystematic(jes)

    #    bkt.addValidationChannels([nJetSLVR2,metSLVR2,meffSLVR2,nBJetSLVR2,metmeffSLVR2,mm2J,srs1l2jTChannel])
    #bkt.addValidationChannels([nJetSLVR2,srs1l2jTChannel,mm2J,mm2Jl])
     
    #dataSample.buildHisto([0.,1.,6.,16.,3.,0.],"SS","metmeff2Jet",0.1,0.1)
    #dataSample.buildHisto([25.],"SR1sl2j","cuts",0.5)
    #dataSample.buildHisto([1.,6.,24.,37.,7.,0.],"SSloose","metmeff2Jet",0.1,0.1)   
    #dataSample.buildHisto([403.,202.,93.,39.,11.,10.,4.,1.],"SLVR2","nJet",2)
    print("Do validation")
# Create TLegend (AK: TCanvas is needed for that, but it gets deleted afterwards)
c = TCanvas()
compFillStyle = 1001 # see ROOT for Fill styles
leg = TLegend(0.6,0.475,0.9,0.925,"")
leg.SetFillStyle(0)
leg.SetFillColor(0)
leg.SetBorderSize(0)
#
entry = TLegendEntry()
entry = leg.AddEntry("","Data 2015+2016 (#sqrt{s}=13 TeV)","p") 
entry.SetMarkerColor(bkt.dataColor)
entry.SetMarkerStyle(20)
#
entry = leg.AddEntry("","Total pdf","lf") 
entry.SetLineColor(bkt.totalPdfColor)
entry.SetLineWidth(2)
entry.SetFillColor(bkt.errorFillColor)
entry.SetFillStyle(bkt.errorFillStyle)
#
entry = leg.AddEntry("","t#bar{t}","lf") 
entry.SetLineColor(topSample1.color)
entry.SetFillColor(topSample1.color)
entry.SetFillStyle(compFillStyle)
#
entry = leg.AddEntry("","Single top","lf") 
entry.SetLineColor(singletopSample.color)
entry.SetFillColor(singletopSample.color)
entry.SetFillStyle(compFillStyle)
#
entry = leg.AddEntry("","W+jets","lf") 
entry.SetLineColor(wjetsSample.color)
entry.SetFillColor(wjetsSample.color)
entry.SetFillStyle(compFillStyle)
#
entry = leg.AddEntry("","Z+jets","lf") 
entry.SetLineColor(zjetsSample.color)
entry.SetFillColor(zjetsSample.color)
entry.SetFillStyle(compFillStyle)
#
entry = leg.AddEntry("","ttV","lf") 
entry.SetLineColor(ttVSample.color)
entry.SetFillColor(ttVSample.color)
entry.SetFillStyle(compFillStyle)
#
entry = leg.AddEntry("","ttH","lf") 
entry.SetLineColor(ttHSample.color)
entry.SetFillColor(ttHSample.color)
entry.SetFillStyle(compFillStyle)
#
entry = leg.AddEntry("","VH","lf") 
entry.SetLineColor(VHSample.color)
entry.SetFillColor(VHSample.color)
entry.SetFillStyle(compFillStyle)
#
entry = leg.AddEntry("","Diboson","lf") 
entry.SetLineColor(DibosonSample.color)
entry.SetFillColor(DibosonSample.color)
entry.SetFillStyle(compFillStyle)
#
entry = leg.AddEntry("","Triboson","lf") 
entry.SetLineColor(TribosonSample.color)
entry.SetFillColor(TribosonSample.color)
entry.SetFillStyle(compFillStyle)
#
if myFitType==FitType.Exclusion:
    entry = leg.AddEntry("","signal","lf") 
    entry.SetLineColor(kPink)
    entry.SetFillColor(kPink)
    entry.SetFillStyle(compFillStyle)


# Set legend for fitConfig
bkt.tLegend = leg
if myFitType==FitType.Exclusion:
    myTopLvl.tLegend = leg
c.Close()
