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
from optparse import OptionParser

from ROOT import gROOT, TLegend, TLegendEntry, TCanvas
#gROOT.LoadMacro("./macros/AtlasStyle.C")
import ROOT, os, fnmatch
#ROOT.SetAtlasStyle()

myUserArgs= configMgr.userArg.split(' ')
 
myInputParser = OptionParser()

myInputParser.add_option('', '--SR', dest = 'SRnum', default = 'SR1')
myInputParser.add_option('', '--doFit', dest = 'doFit', default = 'True')



(options, args) = myInputParser.parse_args(myUserArgs)
#doFit = options.doFit ##Fix InputParser

doFit = True
doCutAndCount = False
doFitXGB = False
doFitS = False
doFitBoth = True
whichSR = options.SRnum

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
#configMgr.doUL = False

#configMgr.nTOYs=5000
configMgr.calculatorType=2
configMgr.testStatType=3 #2
if doFit:
    configMgr.nPoints = 50
else:
    configMgr.nPoints=20 #50
configMgr.readFromTree=True
#configMgr.scanRange = (0., 10.)

#--------------------------------
# Now we start to build the model
#--------------------------------

# First define HistFactory attributes
if not doFit: 
    configMgr.analysisName = "OneLbb_MVA_OneBin"
elif doFit:
    if doCutAndCount:
        configMgr.analysisName = "OneLbb_MVA_CutAndCount"
    elif doFitS:
        configMgr.analysisName = "OneLbb_MVA_metsig"
    elif doFitBoth:
        configMgr.analysisName = "OneLbb_MVA_Both"
    elif doFitXGB:
        configMgr.analysisName = "OneLbb_MVA_Fit_10bin"

# Scaling calculated by outputLumi / inputLumi
configMgr.inputLumi = 1. # Luminosity of input TTree after weighting
configMgr.outputLumi = 139.0 # Luminosity required for output histograms
configMgr.setLumiUnits("fb-1")

configMgr.histCacheFile = "data/"+configMgr.analysisName+".root"

configMgr.outputFileName = "results/"+configMgr.analysisName+"_Output.root"

# Set the files to read from
bgdFiles = []
dataFiles = []
testFiles = []
newSigFiles = []
testSamples = []
if configMgr.readFromTree:
    directory = "/user/hteagle/liverpool-ml/TMVATuples/21.2.75_tested/"
    #directory = "/hepstore/hteagle/Wh/ntuples_21.2.60/"
    bgdFiles.append(directory+"ttbar.root")
    bgdFiles.append(directory+"singleTop.root")
    bgdFiles.append(directory+"wJets.root")
    bgdFiles.append(directory+"ttV.root")
    bgdFiles.append(directory+"diBoson.root")
    bgdFiles.append(directory+"triBoson.root")
    bgdFiles.append(directory+"higgs.root")   
    #bgdFiles.append(directory+"diJet.root")
    bgdFiles.append(directory+"zJets.root")   
    

    dataFiles.append(directory+"data.root")
    
    listOfFiles = os.listdir(directory)
    #pattern = "*396734*C1*.root"
    pattern = "*C1N2*.root"
    for entry in listOfFiles:
        if fnmatch.fnmatch(entry,pattern):
            print ("signal File: "+str(directory+entry))
            testFiles.append(directory+entry)
            mass_0 = entry.strip("_lep_output_A__D__E_.root")
            mass_1 = 'm'+mass_0.split('hbb_')[1]
            mass=mass_1.replace('p','.')
            print ("has mass: "+str(mass))
            testSamples.append(mass)
else:
    bgdFiles = ["data/"+configMgr.analysisName+".root"]



# Dictionary of cuts for Tree->hist
isttbarOK ="( (mcID != 410470 || truthFilterMET < 200)&&(mcID != 407345 || (truthFilterMET >= 200 && truthFilterMET < 300))&&(mcID != 407346 || (truthFilterMET >= 300 && truthFilterMET < 400))&&(mcID != 407347 || truthFilterMET > 400) )*"

cleaningCuts = "(coreFlag)*(sctFlag)*(LArTileFlag)*(passedPrimVertex)*(passedJetClean)*(passedCosmicMu)*(passedMuonClean)*"
weights = 'eventWeight*HFScale*JVTSF*puWgt*bJetSF*muonSF*electronSF*muonTriggerSF*electronTriggerSF*YearWeight*'
#Set the year weight here
YearWeight = "(year==2018 ? 58.5/139 :(year==2017 ? 44.3/139 : 36.2/139))"

#preCuts = "(passedMuTrigger || passedElTrigger)*"+isttbarOK
preCuts = isttbarOK

##XGB one-bin fit
configMgr.cutsDict["SR1"] = preCuts+"(3Sig_FS_RW_HFscaled_PC_class2>0.996)*(m_CTcorr>100)*(3Sig_FS_RW_HFscaled_PC_class2<1)*(metsig_New>8)"

##XGB output fit regions
#configMgr.cutsDict["SR1_fitXGB"]  = preCuts+"(m_CTcorr>100)*(3Sig_FS_RW_HFscaled_PC_class2>0.99)*(3Sig_FS_RW_HFscaled_PC_class2<1)*(metsig_New>8)"
configMgr.cutsDict["SR1_fitXGB"]  = preCuts+"(m_CTcorr>150)*(3Sig_FS_RW_HFscaled_PC_class2>0.95)*(3Sig_FS_RW_HFscaled_PC_class2<1)*(metsig_New>12)"

## metsig fit regions
configMgr.cutsDict["SR1_fitS"]    = preCuts+"(nJets==2)*(400_250_Nominal_shuffled_relWgt_fix_class2>0.99)*(400_250_Nominal_shuffled_relWgt_fix_class2<1)"

##XGB + mCT fit regions
configMgr.cutsDict["SR0_fitBoth"] = preCuts+"*(3Sig_FS_RW_HFscaled_PC_class2<1)*(3Sig_FS_RW_HFscaled_PC_class2>0.98)*(m_CTcorr>0)*(m_CTcorr<100)"
configMgr.cutsDict["SR1_fitBoth"] = preCuts+"*(3Sig_FS_RW_HFscaled_PC_class2<1)*(3Sig_FS_RW_HFscaled_PC_class2>0.98)*(m_CTcorr>100)*(m_CTcorr<200)"
configMgr.cutsDict["SR2_fitBoth"] = preCuts+"*(3Sig_FS_RW_HFscaled_PC_class2<1)*(3Sig_FS_RW_HFscaled_PC_class2>0.98)*(m_CTcorr>200)*(m_CTcorr<300)"
configMgr.cutsDict["SR3_fitBoth"] = preCuts+"*(3Sig_FS_RW_HFscaled_PC_class2<1)*(3Sig_FS_RW_HFscaled_PC_class2>0.98)*(m_CTcorr>300)"

#Preliminary control regions
configMgr.cutsDict["CRttbar"] = preCuts+"(3Sig_FS_RW_HFscaled_PC_class2>0.6 && 3Sig_FS_RW_HFscaled_PC_class2<0.8)*(400_250_Nominal_class3<0.1)*(nJets==2)*(metsig_New>8)*(400_250_Nominal_class0>0.3)*(400_250_Nominal_class1<0.15)"
configMgr.cutsDict["CRsingleTop"] = preCuts+"(3Sig_FS_RW_HFscaled_PC_class2>0.5)*(3Sig_FS_RW_HFscaled_PC_class2<0.8)*(400_250_Nominal_class3<0.1)*(nJets==2)*(metsig_New>8)*(400_250_Nominal_class0>0)*(400_250_Nominal_class1>0.13)*(m_T>90)" 
configMgr.cutsDict["CRwJets"] = preCuts+"(3Sig_FS_RW_HFscaled_PC_class2>0.5)*(3Sig_FS_RW_HFscaled_PC_class2<0.8)*(nJets==2)*(metsig_New>8)*(400_250_Nominal_class3>0.12)"


#Nominal analysis regions
configMgr.cutsDict["SRLM_1"] = preCuts+"(nLeptons==1)*(nBJets==2)*(m_bb>100 && m_bb<140)*(nJets<4)*(ETMiss>240)*(m_T>100 && m_T<160)*(m_CTcorr>180 && m_CTcorr<230)"
configMgr.cutsDict["SRLM_2"] = preCuts+"(nLeptons==1)*(nBJets==2)*(m_bb>100 && m_bb<140)*(nJets<4)*(ETMiss>240)*(m_T>100 && m_T<160)*(m_CTcorr>230 && m_CTcorr<280)"
configMgr.cutsDict["SRLM_3"] = preCuts+"(nLeptons==1)*(nBJets==2)*(m_bb>100 && m_bb<140)*(nJets<4)*(ETMiss>240)*(m_T>100 && m_T<160)*(m_CTcorr>280)"
configMgr.cutsDict["SRMM_1"] = preCuts+"(nLeptons==1)*(nBJets==2)*(m_bb>100 && m_bb<140)*(nJets<4)*(ETMiss>240)*(m_T>160 && m_T<240)*(m_CTcorr>180 && m_CTcorr<230)"
configMgr.cutsDict["SRMM_2"] = preCuts+"(nLeptons==1)*(nBJets==2)*(m_bb>100 && m_bb<140)*(nJets<4)*(ETMiss>240)*(m_T>160 && m_T<240)*(m_CTcorr>230 && m_CTcorr<280)"
configMgr.cutsDict["SRMM_3"] = preCuts+"(nLeptons==1)*(nBJets==2)*(m_bb>100 && m_bb<140)*(nJets<4)*(ETMiss>240)*(m_T>160 && m_T<240)*(m_CTcorr>280)"
configMgr.cutsDict["SRHM_1"] = preCuts+"(nLeptons==1)*(nBJets==2)*(m_bb>100 && m_bb<140)*(nJets<4)*(ETMiss>240)*(m_T>240)*(mlb1>120)*(m_CTcorr>180 && m_CTcorr<230)"
configMgr.cutsDict["SRHM_2"] = preCuts+"(nLeptons==1)*(nBJets==2)*(m_bb>100 && m_bb<140)*(nJets<4)*(ETMiss>240)*(m_T>240)*(mlb1>120)*(m_CTcorr>230 && m_CTcorr<280)"
configMgr.cutsDict["SRHM_3"] = preCuts+"(nLeptons==1)*(nBJets==2)*(m_bb>100 && m_bb<140)*(nJets<4)*(ETMiss>240)*(m_T>240)*(mlb1>120)*(m_CTcorr>280)"

# Tuples of nominal weights without and with b-jet selection
#configMgr.weights = ("mcEventWeight","HFScale", "JVTSF","bJetSF","muonSF","electronSF","electronTriggerSF","muonTriggerSF",YearWeight) 
configMgr.weights = ("mcEventWeight","HFScale", "JVTSF","bJetSF","muonSF","electronSF",YearWeight) 




#--------------------
# List of systematics
#--------------------
SignalSys         = Systematic("SignalSys"         , "" , 0.95 , 1.05 , "user" , "overallSys")
# name of nominal histogram for systematics
configMgr.nomName = ""

# List of samples and their plotting colours
#
topSample = Sample("Top",kGreen-9)
topSample.setNormByTheory()
topSample.setStatConfig(False)
#
singletopSample = Sample("SingleTop", kOrange - 9)
singletopSample.setNormByTheory()
singletopSample.setStatConfig(False)
#
wjetsSample = Sample("Wjets",kRed-9)
wjetsSample.setNormByTheory()
wjetsSample.setStatConfig(False)
#wjetsSample.addSampleSpecificWeight("2.0 * 1.22")
#
ttVSample = Sample("ttV",kRed-9)
ttVSample.setNormByTheory()
ttVSample.setStatConfig(False)
#
dibosonSample = Sample("Diboson",kRed-9)
dibosonSample.setNormByTheory()
dibosonSample.setStatConfig(False)
#
tribosonSample = Sample("Triboson",kRed-9)
tribosonSample.setNormByTheory()
tribosonSample.setStatConfig(False)
#
higgsSample = Sample("Higgs",kRed-9)
higgsSample.setNormByTheory()
higgsSample.setStatConfig(False)
#
#diJetSample = Sample("Dijet",kRed-9)
#diJetSample.setStatConfig(False)
#
zJetsSample = Sample("Zjets",kRed-9)
zJetsSample.setNormByTheory()
zJetsSample.setStatConfig(False)
#
dataSample = Sample("Data",kBlack)
dataSample.setData()


## set the file from which the samples should be taken
index = 0
for entry in [topSample,singletopSample,wjetsSample,dibosonSample,ttVSample,tribosonSample,higgsSample,zJetsSample]:
    temp = []
    fileName = ""
    fileName = str(bgdFiles[index])    
    temp.append(fileName)
    entry.addInputs(temp, "CollectionTree_")
    print("%%%%%%%%%%%%%%%%%%%% Background input %%%%%%%%%%%%%")
    print (str(temp))
    index=index+1

#dataSample.addInputs(dataFiles, "CollectionTree_")

#************
#Systematics
#************

exp_syst = Systematic("exp",configMgr.weights,1.+0.3,1.-0.3,"user","userOverallSys")
bkgtheory_syst = Systematic("bkgtheory",configMgr.weights,1.,1.,"user","userOverallSys")
bkg_syst = Systematic("bkg_syst",configMgr.weights,1+0.2,1-0.2,"user","overallSys")

#-----------------------------
# Discovery fits 
#-----------------------------

if myFitType==FitType.Discovery:

    channel = "SR1"
   
    index = 0

    #Setup fit config
    disc = configMgr.addFitConfig("DiscOnly")
    configMgr.blindSR = True
    #configMgr.useSignalInBlindedData=True
    meas=disc.addMeasurement(name="NormalMeasurement",lumi=1.0,lumiErr=0.01)
    #meas.addPOI("mu_DISCOVERY_"+channel)
    meas.addPOI("mu_SIG")

    #Samples
    disc.addSamples([topSample,singletopSample,wjetsSample,ttVSample,dibosonSample,dataSample])

    #Systematics
    disc.getSample("Top").addSystematic(bkg_syst)
    disc.getSample("SingleTop").addSystematic(bkg_syst)
    disc.getSample("Wjets").addSystematic(bkg_syst)
    disc.getSample("ttV").addSystematic(bkg_syst)
    disc.getSample("Diboson").addSystematic(bkg_syst)
    disc.getSample("Triboson").addSystematic(bkg_syst)
    disc.getSample("Higgs").addSystematic(bkg_syst)
    disc.getSample("Dijet").addSystematic(bkg_syst)
    disc.getSample("Zjets").addSystematic(bkg_syst)

    #Channels
    sr = disc.addChannel("cuts",[channel],1,0.5,1.5)
    
    #Channels
    disc.addSignalChannels([sr]) 
    
    for sig in testSamples:

        configMgr.analysisName = "Disc_OneLbb_"+sig+"_"+channel
        myTopLvl = configMgr.addFitConfigClone(disc,"Sig_"+sig+"_"+channel)
        sigSample = Sample(sig,kPink)
        temp = []
        temp.append(newSigFiles[index])
        sigSample.addInputs(temp, "CollectionTree_")
        sigSample.setNormByTheory()
        #sigSample.setNormFactor("mu_DISCOVERY_"+channel,1.,0.,5.) 
        sigSample.setNormFactor("mu_SIG",1.,0.,5.)   
        sigSample.setStatConfig(True)
        myTopLvl.addSamples(sigSample)
        myTopLvl.setSignalSample(sigSample)
        index = index+1

#-----------------------------
# Exclusion fits 
#-----------------------------

if myFitType==FitType.Exclusion:
    
    channel = "SR1"
    
    print("%%%%%%%%%%%%%%%%%%%%%%%%% Exlcusion Fit %%%%%%%%%%%%%%%%%%%%")
    #Setup fit config
    ex = configMgr.addFitConfig("Exclusion")
    configMgr.blindSR = True
    configMgr.useSignalInBlindedData=False
    meas=ex.addMeasurement(name="NormalMeasurement",lumi=1.0,lumiErr=0.032)
    meas.addPOI("mu_SIG")
    meas.addParamSetting("Lumi","const",1)

    #Samples
    ex.addSamples([topSample,singletopSample,wjetsSample,ttVSample,dibosonSample,tribosonSample,higgsSample,zJetsSample,dataSample])
    


    #Systematics
    ex.getSample("Top").addSystematic(bkg_syst)
    ex.getSample("SingleTop").addSystematic(bkg_syst)
    ex.getSample("Wjets").addSystematic(bkg_syst)
    ex.getSample("ttV").addSystematic(bkg_syst)
    ex.getSample("Diboson").addSystematic(bkg_syst)
    ex.getSample("Triboson").addSystematic(bkg_syst)
    ex.getSample("Higgs").addSystematic(bkg_syst)
    #ex.getSample("Dijet").addSystematic(bkg_syst)
    ex.getSample("Zjets").addSystematic(bkg_syst)
    
    #Channels
    if doFit: 
        if doFitXGB:
            sr1          = ex.addChannel("3Sig_FS_RW_HFscaled_PC_class2",["SR1_fitXGB"],10,0.9,1.)
            ex.addSignalChannels([sr1])
        elif doFitS:
            sr1          = ex.addChannel("metsig_New",["SR1_fitS"],10,2,22)
            ex.addSignalChannels([sr1])
        elif doFitBoth:
            sr0          = ex.addChannel("3Sig_FS_RW_HFscaled_PC_class2",["SR0_fitBoth"],5,0.98,1.)
            sr1          = ex.addChannel("3Sig_FS_RW_HFscaled_PC_class2",["SR1_fitBoth"],5,0.98,1.)
            sr2          = ex.addChannel("3Sig_FS_RW_HFscaled_PC_class2",["SR2_fitBoth"],5,0.98,1.)
            sr3          = ex.addChannel("3Sig_FS_RW_HFscaled_PC_class2",["SR3_fitBoth"],5,0.98,1.)
            #sr4          = ex.addChannel("3Sig_FS_RW_HFscaled_PC_class2",["SR4_fitBoth"],5,0.95,1.)
            #sr5          = ex.addChannel("3Sig_FS_RW_HFscaled_PC_class2",["SR5_fitBoth"],5,0.95,1.)
            ex.addSignalChannels([sr0])
            ex.addSignalChannels([sr1])
            ex.addSignalChannels([sr2])
            ex.addSignalChannels([sr3])
            #ex.addSignalChannels([sr4])
            #ex.addSignalChannels([sr5])
        elif doCutAndCount:
            srL_1 = ex.addChannel("cuts",["SRLM_1"],1,0.,1.5)
            srL_2 = ex.addChannel("cuts",["SRLM_2"],1,0.,1.5)
            srL_3 = ex.addChannel("cuts",["SRLM_3"],1,0.,1.5)
            srM_1 = ex.addChannel("cuts",["SRMM_1"],1,0.,1.5)
            srM_2 = ex.addChannel("cuts",["SRMM_2"],1,0.,1.5)
            srM_3 = ex.addChannel("cuts",["SRMM_3"],1,0.,1.5)
            srH_1 = ex.addChannel("cuts",["SRHM_1"],1,0.,1.5)
            srH_2 = ex.addChannel("cuts",["SRHM_2"],1,0.,1.5)
            srH_3 = ex.addChannel("cuts",["SRHM_3"],1,0.,1.5)
            ex.addSignalChannels([srL_1])
            ex.addSignalChannels([srL_2])
            ex.addSignalChannels([srL_3])
            ex.addSignalChannels([srM_1])
            ex.addSignalChannels([srM_2])
            ex.addSignalChannels([srM_3])
            ex.addSignalChannels([srH_1])
            ex.addSignalChannels([srH_2])
            ex.addSignalChannels([srH_3])
    else:
        sr1          = ex.addChannel("cuts",["SR1"],1,0.5,1.5)
        ex.addSignalChannels([sr1])



    #crttbar     = ex.addChannel("cuts",["CRttbar"],1,0.5,1.5)
    #crsingleTop = ex.addChannel("cuts",["CRsingleTop"],1,0.5,1.5)
    #crwJets     = ex.addChannel("cuts",["CRwJets"],1,0.5,1.5)

    #Add Channels
    #ex.addBkgConstrainChannels([crttbar,crsingleTop,crwJets])



 
    index = 0

    for sig in testSamples:
        #Assume this is a top-level config which holds general info for common info
        myTopLvl = configMgr.addFitConfigClone(ex,"Sig_%s"%sig)

        sigSample = Sample(sig,kPink)
        temp = []
        temp.append(testFiles[index])
        sigSample.addInputs(temp, "CollectionTree_")
        print("%%%%%%%%%%%%%%%%%% Sig input%%%%%%%%%%%%%%")
        print (str(temp))
        sigSample.setNormByTheory()
        sigSample.setStatConfig(True)
        sigSample.setNormFactor("mu_SIG",1.,0.,100.)   
        #sigSample.addSystematic(exp_syst)                
        #sigSample.buildHisto([10.0],"SR1","cuts",0.5)
        myTopLvl.addSamples(sigSample)
        myTopLvl.setSignalSample(sigSample)
        index = index+1

