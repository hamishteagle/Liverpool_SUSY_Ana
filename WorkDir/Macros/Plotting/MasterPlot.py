#!/usr/bin/env python

import os,sys,subprocess,datetime,copy,math,array,shutil,ROOT,string, CorrelationPlot, time, ShapePlot, RatioPlot, Cutflow, Significance#, ShapeFit
from ROOT import gROOT, TColor, TLatex, gStyle, TLegend, gPad, TAttText
from optparse import OptionParser

__author__ = "John Anders"
__doc__    = """Interface to all the other Plotting scripts"""

# Make sure that Path exists for output files
def ensure_dir(d):
    if not os.path.isdir(d):
        os.makedirs(d)

def main():
# List of Root Files we want to include
    #List of input files. Probably easier to produce them with a .txt file later
    date = time.strftime("%d")  + "_"  + time.strftime("%B") + "_20" + time.strftime("%y")
    print ("Current date " +str(date))

    parser = OptionParser()
    parser.add_option("-c","--cutflow", action="store_true", dest="doCutflow", help="do cutflow?", default=False)
    parser.add_option("-r", "--ratio", action="store_true", dest="doRatio", help="do Ratio plots?", default=False)
    parser.add_option("-s", "--siginificance", action="store_true", dest="doSignif", help="do Significance plots?", default=False)
    #parser.add_option("-f", "--shapeFit", action="store_true", dest="doShapeFit", help="Run the shapeFt plotting script", default=False)

    parser.add_option("-p", "--shape", action="store_true", dest="doShape", help="do Shape plots?", default=False)
    parser.add_option("-a", "--correlation", action="store_true", dest="doCorr", help="do Correlation plots?", default=False)
    parser.add_option("-d", "--date", action="store", type="string", dest="date", help="date for directory structure", default=date)
    (options, args) = parser.parse_args()

    print ("Arguments " , str(sys.argv))


    if not (options.doCorr or options.doRatio or options.doShape or options.doCutflow or options.doSignif): #or options.doShapeFit):
        print ("Ran without any options. Produced nothing. Good work")
        return 0


    #Liv ntuples_wh_21_2_31
    DiJetFile = "/hepstore/hteagle/Wh/ntuples_21.2.55/diJet.root"
    ttVFile = "/hepstore/hteagle/Wh/ntuples_21.2.55/ttV.root"
    wJetFile = "/hepstore/hteagle/Wh/ntuples_21.2.55/wJets.root"
    zJetFile = "/hepstore/hteagle/Wh/ntuples_21.2.55/zJets.root"
    ttbarFile = "/hepstore/hteagle/Wh/ntuples_21.2.55/ttbar_nominal.root"
    singleTopFile = "/hepstore/hteagle/Wh/ntuples_21.2.55/singleTop_nominal.root"
    DiBosonFile = "/hepstore/hteagle/Wh/ntuples_21.2.55/diBoson.root"
    HiggsFile = "/hepstore/hteagle/Wh/ntuples_21.2.55/higgs.root"
    dataFile = "/hepstore/hteagle/Wh/ntuples_21.2.55/data1516.root"

    signalFiles = []
    #ttbar comparisons
    #signalFiles.append("/user/hteagle/liverpool-ml/TMVATuples/Reco/ttbar_new_TRUTH.root")
    #signalFiles.append("/hepstore/hteagle/Wh/ntuples_21.2.55/mc16a/28Jan_MC16av1.410470.PhPy8EG_A14_ttbar_hdamp258p75_nonallhad_21_2_51_output.root")
    #signalFiles.append("/user/hteagle/liverpool-ml/TMVATuples/Reco/singleTop_TRUTH.root")
    #signalFiles.append("/hepstore/hteagle/Wh/ntuples_21.2.55/mc16a/singleTop_nominal.root")
    #signalFiles.append("/hepstore/hteagle/Wh/ntuples_21.2.55/mc16a/26Jan_MC16av1.396716.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hbb_300p0_150p0_lep_21_2_51_output.root")
    #signalFiles.append("/user/hteagle/liverpool-ml/TMVATuples/Reco/MT50/26Jan_MC16av1.396716.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hbb_300p0_150p0_lep_21_2_51_output.root")
    #signalFiles.append("/user/hteagle/liverpool-ml/TMVATuples/Reco/26Jan_MC16av1.396716.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hbb_300p0_150p0_lep_21_2_51_TRUTH_output.root")
    #signalFiles.append("/hepstore/hteagle/Wh/ntuples_21.2.55/26Jan_MC16av1.396714.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hbb_300p0_75p0_lep_21_2_51_output.root")    
    #signalFiles.append("/hepstore/hteagle/Wh/ntuples_21.2.55/26Jan_MC16av1.396720.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hbb_350p0_25p0_lep_21_2_51_output.root")
    signalFiles.append("/hepstore/hteagle/Wh/ntuples_21.2.55/mc16a/Signal/26Jan_MC16av1.396706.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hbb_250p0_100p0_lep_21_2_51_output.root")
    signalFiles.append("/hepstore/hteagle/Wh/ntuples_21.2.55/mc16a/Signal/26Jan_MC16av1.396716.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hbb_300p0_150p0_lep_21_2_51_output.root")
    signalFiles.append("/hepstore/hteagle/Wh/ntuples_21.2.55/mc16a/Signal/26Jan_MC16av1.396734.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hbb_400p0_250p0_lep_21_2_51_output.root")
    signalFiles.append("/hepstore/hteagle/Wh/ntuples_21.2.55/mc16a/Signal/27Jan_MC16av1.396750.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hbb_500p0_350p0_lep_21_2_51_output.root")


    

    
    foundSignalInput = ""

    signalFile=signalFiles[0]#This is the signal file passed to the cutflow

    for i in sys.argv:
        print (str(i))
        if (str(i)).find(".root") > -1:
            print ("Found a signal file")
            signalFile = str(i)
            print ("Signal file is", str(signalFile))
            if (signalFile.find("BB_direct") != -1):
                print ("Found BB_direct")
                foundSignalInput = (signalFile.split("/")[6]).split(".")[4]
            elif (signalFile.find("Combined") != -1):
                print ("Found combined")
                foundSignalInput = (signalFile.split("/")[6]).split(".")[0]
            elif (signalFile.find("onestepN2hN1") != -1):
                print ("Found MultiB signal")
                foundSignalInput = ((signalFile.split("/")[6]).split(".")[4]).split("_")[4]+"_"+((signalFile.split("/")[6]).split(".")[4]).split("_")[5]+"_"+((signalFile.split("/")[6]).split(".")[4]).split("_")[6]



    #Liv luminosity and -weights
    #luminosity_liv ="1*70*JVTSF*puWgt*bJetSF*muonSF*electronSF*mcEventWeight*lumiWgtRecalc*YearWeight*" #DON'T FORGET to setAlias!!!
    luminosity_liv ="1*36.1*JVTSF*puWgt*bJetSF*muonSF*electronSF*mcEventWeight*HFScale*"
    luminosity_Truth = "1*"
    cutstouse = ""

    #Liv Cleaning cuts
    cleaningCuts = "(coreFlag)*(sctFlag)*(LArTileFlag)*(passedPrimVertex)*(passedJetClean)*(passedCosmicMu)*(passedMuonClean)*"

    #Triggers
    #triggerCuts = "(HLT_e26_lhtight_nod0_ivarloose || HLT_e60_lhmedium_nod0 || HLT_e140_lhloose_nod0 || HLT_mu26_ivarmedium || HLT_mu50) || (HLT_xe90_mht_L1XE50 || HLT_xe100_mht_L1XE50 || HLT_xe110_mht_L1XE50)*"
    triggerCuts = "((triggerDecisions[11] || triggerDecisions[13] || triggerDecisions[15] || triggerDecisions[20] || triggerDecisions[21]) || (triggerDecisions[25] || triggerDecisions[26] || triggerDecisions[27]))*"
    METtriggerCuts = "((year==2015 && triggerDecisions[22])||((year ==2016) && (triggerDecisions[25] || triggerDecisions[27]))||(year==2017 && triggerDecisions[29])||(year==2018 && triggerDecisions[28]))*"
    OneLtriggerCuts = "("
    ##Sort this out for filtered ttbar/singleTop
    ttbar_singleTop_filtered = "(mcID == 410470 && ETMiss<100 && all_HT<600)||(mcID == 345935 && ETMiss>100 && ETMiss<200 && all_HT<600 "
    ymax = 800000
    doLog = False


    # Change this to put the output directory somewhere else
    directory = options.date+"_SbottomMultib_Preliminary/"+foundSignalInput
    print ("Output Directory is: ", directory)
    #############################
    label = "preSelection_ML_MET"
    #############################
    EventCounter = True



    preSelection_Wh_Liv = "(pTl1>27)*(nLeptons==1)*(nBJets==2)*(nJets<4)*(ETMiss>200)*(m_T>100)*(m_bb>50)*"
    # Preliminary Sbottom Multi B regions here:
    # Change the "cutstouse" variable to produce different distributions for a given selection. If plotting a SR distribution,
    # make sure that SR is contained in the label variable, which will blind the distribution
    if label == "noSelection_Liv":
        cutstouse = cleaningCuts+triggerCuts+"(ETMiss>250 && nBJets>=2 && nLeptons>0)"
    elif label == "preSelection_Wh_Liv":
        cutstouse =METtriggerCuts+preSelection_Wh_Liv+"1"
    elif label == "preSelection_Wh_Truth":
        cutstouse = "(ETMiss>200)*(m_T>100)*(m_bb>50 && m_bb<200)"
        

#Run1 Wh 1lbb (from int note)
    elif label =="cleaningCuts_Liv":
        cutstouse = cleaningCuts
    elif label =="preSelection_Liv":
        cutstouse = METtriggerCuts+cleaningCuts+"(nBaselineLeptons==1)*(nLeptons==1)*(nBJets==2)*(nJets<4)*(ETMiss>100)*(m_T>40)*(m_bb>50)"
    elif label =="preSelection_ML_MET":
        cutstouse = cleaningCuts+METtriggerCuts+"(ETMiss>200)*(m_T>50)*(nLeptons==1)*(nBJets==2)*(nJets<4)"
    elif label =="preSelection_ML_1L":
        cutstouse = cleaningCuts+OneLtriggerCuts+"(ETMiss>100)*(m_T>50)*(nLeptons==1)*(nBJets==2)*(nJets<4)*(pT1l>27)"
    elif label =="SRLM_Liv":
        cutstouse = cleaningCuts+METtriggerCuts+preSelection_Wh_Liv+"(m_bb>105 && m_bb<135)*(m_CTcorr>160)*(ETMiss>200)*(m_T>100 && m_T<140)"
    elif label =="SRMM_Liv":
        cutstouse = +cleaningCuts+METtriggerCuts+preSelection_Wh_Liv+"(m_bb>105 && m_bb<135)*(m_CTcorr>160)*(ETMiss>200)*(m_T>140 && m_T<200)"
    elif label =="SRHM_Liv":
        cutstouse = cleaningCuts+METtriggerCuts+preSelection_Wh_Liv+"(m_bb>105 && m_bb<135)*(m_CTcorr>160)*(ETMiss>200)*(m_T>200)"
    elif label =="TRHM_Liv":
        cutstouse = cleaningCuts+METtriggerCuts+preSelection_Wh_Liv+" (m_bb<105 || m_bb>135)*(m_CTcorr<160)*(ETMiss>200)*(m_T>200)"




    else:
        print ("Error Wrong label try again. ")
        return 1

    gROOT.LoadMacro("/user/hteagle/AnalysisDirectory/Rel21/Base.21.2.31/run/Macros/Plotting/AtlasStyle/AtlasStyle.cxx")
    ROOT.SetAtlasStyle()

    plottinglist = []

    if options.doRatio:




        # This uses the ratio plotting class, to produce a ratio plot of whatever variable you give as the first argument. The second argument is the latex which will be drawn on the x-axis. 3rd is the xlow, 4th is xhigh and 5th is the rebinning value. The rest you shouldn't need to change and instead should just copy from an existing usage of the function


        ##Signal Only plots
        #RatioPlot.RatioPlot("m_bb", "m_{bb}", 0, 600, 20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_Truth, True)
        RatioPlot.RatioPlot("ETMiss", "E_{T}^{miss}", 100, 600, 25, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_Truth, True)
        RatioPlot.RatioPlot("m_CTcorr", "m_{CT}", 0, 1000, 50, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_Truth, True)
        # RatioPlot.RatioPlot("m_CTcorr", "m_{CT}", 0, 1000, 50, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_Truth, True)
        # RatioPlot.RatioPlot("m_T", "m_{T}", 0, 1000, 50, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_Truth, True)
        # RatioPlot.RatioPlot("dRb1b2", "#DeltaR(b_{1},b_{2})", 0, 8, 20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_Truth, True)
        # RatioPlot.RatioPlot(" m_b1l", "m_{bl1})", 0, 1000, 50, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_Truth, True)
        # RatioPlot.RatioPlot(" m_b2l", "m_{bl2})", 0, 1000, 50, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_Truth, True)
        # RatioPlot.RatioPlot(" pTl1", "p_{T}^{l1}", 0, 1000, 50, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_Truth, True)
        # RatioPlot.RatioPlot(" pTb2", "p_{T}^{b2}", 0, 1000, 50, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_Truth, True)
        # RatioPlot.RatioPlot(" pTb1", "p_{T}^{b1}", 0, 1000, 50, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_Truth, True)
        # #RatioPlot.RatioPlot("dRL1b1", "#Delta R(l1b1)", 0, 1000, 50, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_Truth, True)
        # #RatioPlot.RatioPlot("dRL1b2", "#Delta R(l1b2)", 0, 4, 20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_Truth, True)
        # RatioPlot.RatioPlot("etal1", "#eta_{l1}", -4, 4, 40, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_Truth, True)
        # RatioPlot.RatioPlot("etab1", "#eta_{b1}", -4, 4, 40, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_Truth, True)
        # RatioPlot.RatioPlot("etab2", "#eta_{b2}", -4, 4, 40, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_Truth, True)
        # RatioPlot.RatioPlot("phib2", "#phi_{b2}", -4, 4, 40, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_Truth, True)
        # RatioPlot.RatioPlot("phib1", "#phi_{b1}", -4, 4, 40, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_Truth, True)
        # RatioPlot.RatioPlot("phil1", "#phi_{l1}", -4, 4, 40, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_Truth, True)
        

        #RatioPlot.RatioPlot("1", "cuts", 0.5, 1.5, 1, ymax, cutstouse, directory, label, True, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, True, False, luminosity_liv)
        #RatioPlot.RatioPlot("eT_miss_orig", "eT_miss_orig", 0., 1000, 1, ymax, cutstouse, directory, label, True, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, DiJetFile, ttbarFile, dataFile, signalFiles, False, False, luminosity_liv)
        #RatioPlot.RatioPlot("m_bb", "m_{bb}", 30, 630, 30, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False)
        #RatioPlot.RatioPlot("fatJet8_M[0]", "m_{leading 0.8Jet}", 0, 200, 10, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv)
        #RatioPlot.RatioPlot("ETMiss", "E_{T}^{miss}", 0, 1000, 50, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv)
        #RatioPlot.RatioPlot("nJets", "n_{jets}", 0, 15, 1, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False,False, luminosity_liv)
        #RatioPlot.RatioPlot("nBJets", "n_{b-jets}", -0.5, 9.5, 1, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile,DiJetFile, dataFile, signalFiles, False, False, luminosity_liv)
        #RatioPlot.RatioPlot("maxminDRmbb1", "min #Delta R(m_{bb})", 50, 250, 20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv)
        # #RatioPlot.RatioPlot("maxminDRmbb", "maxMin #Delta R(m_{bb})", 60, 160, 10, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv)
        # #RatioPlot.RatioPlot("minDR", "min #Delta R(b,b)", 0, 4, 1, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv)
        #RatioPlot.RatioPlot("all_Meff", "m_{eff}", 0, 3000, 160, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, True, False, luminosity_liv)
        #RatioPlot.RatioPlot("metsig", "Object-based METsig", 0, 40, 160, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, True, False, luminosity_liv)
        #RatioPlot.RatioPlot("pTl1", "p_{T}(leading lep)", 0, 300, 25, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv)
        #RatioPlot.RatioPlot("pTel1", "p_{T}(e)", 0, 800, 40, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv)
        #RatioPlot.RatioPlot("dphimin4_orig", "min #Delta#phi(j,E_{T}^{miss})", 0, math.pi,20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, True, False, luminosity_liv)
        #RatioPlot.RatioPlot("dPhi_1jet", "min #Delta#phi(j1,E_{T}^{miss})", -3.5, 3.5,20, ymax, cutstouse, directory, label, True, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, True, False, luminosity_liv)
        #RatioPlot.RatioPlot("pTb1", "p_{T}^{b1}", 0, 800, 40, ymax, cutstouse, directory, label, True, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv)
        #RatioPlot.RatioPlot("pTj1", "p_{T}^{j1}", 0, 1000, 50, ymax, cutstouse, directory, label, True, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, -False, luminosity_liv)
        #RatioPlot.RatioPlot("m_T", "m_T", 0, 300, 20, ymax, cutstouse, directory, label, True, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv)
        #RatioPlot.RatioPlot("m_CTcorr", "m_{CT}", 0, 700, 80, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv)
        #RatioPlot.RatioPlot("h_T", "H_{T}", 0, 2000, 150, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv)
        # #RatioPlot.RatioPlot("dPhib1b2", "#Delta#phi(b_{1},b_{2})", 0, math.pi,20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, True, False, luminosity_liv)
        # #RatioPlot.RatioPlot("HiggsMassCandidate_4Hb", "Higgs Candidate mass", 0, math.pi,20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, True, False, luminosity_liv)
        #RatioPlot.RatioPlot("SRB1_Mh", "Average Mass of the 2 b-jet pairs (SRB1)", 0, 300,20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv)
        #RatioPlot.RatioPlot("SRB2_Mh", "Average Mass of the 2 b-jet pairs (SRB2)", 0, 300,20, ymax, cutstouse, directory, label, True, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv)
        #RatioPlot.RatioPlot("SRB1_DRmin", "SRB1_DRmin", 0.0001, 6.0001,1, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, True, False,luminosity_liv)
        #RatioPlot.RatioPlot("SRB2_minDR", "SRB2_minDR", 0.0001, 6.0001,1, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, True, False, luminosity_liv)
        #RatioPlot.RatioPlot("SRB1_DRmin2", "SRB1_DRmin2", 0.0001, 6.0001,1, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, True, False, luminosity_liv)
        #RatioPlot.RatioPlot("SRB2_maxDR", "SRB2_maxDR", 0.0001, 6.0001,1, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, True, False, luminosity_liv)
        # #RatioPlot.RatioPlot("nbaselineLep","#leptons",-0.5,9.5,1,ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, True, False, luminosity_liv)
        #RatioPlot.RatioPlot("leadb1","ISRlead (0), b-jet lead (1)",-0.5,1.5,1,ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv)
        #RatioPlot.RatioPlot("SRB2_Mh1 ","Higgs candidate mass-DRmin",0,500,50,ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv)
        # RatioPlot.RatioPlot("SRB2_Mh2 ","Higgs candidate mass-DRmax",0,500,50,ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv)


    if options.doCorr:
        CorrelationPlot.CorrelationPlot("amT2", "min( (sqrt(2*(pT_1bjet *eT_miss_orig*(1 - cos(fabs(TVector2::Phi_mpi_pi( (phib1  - eT_miss_origPhi))))))) ), (sqrt(2*(pTb2*eT_miss_orig*(1 - cos(fabs(TVector2::Phi_mpi_pi( (phib2  - eT_miss_origPhi)))))))))","am_{T2}", "min-m_{T}(b,E_{T}^{miss})", 0, 400, 20, 0, 400, 20, cutstouse, directory, label, dataFile, zJetFile)

    if options.doShape:
        ShapePlot.ShapePlot2("m_CT", "m_{CT}", 0, 1000, 50, 100000, cutstouse, directory, label, inputstringShape1,inputstringShape2, False, False, False)
        ShapePlot.ShapePlot2("m_T", "m_{T}", 0, 1000, 50, 100000, cutstouse, directory, label, inputstringShape1,inputstringShape2, False, False, False)



    if options.doCutflow:
        print ("Going to do cutflow")
        Cutflow.Cutflow(label, cutstouse, signalFile, luminosity_liv)



    if options.doSignif:
        print ("Going to do Significance")
        #########
        label = 'SRLM_Liv'
        ########

        preSelection_Wh = "(met>200 && mt>100  && (mcChannel != 410000 && mcChannel!= 410013 && mcChannel!= 410014 || met < 100) )*"

        if label == "preSelection_Wh":
            cutstouse = preSelection_Wh

        ##ML selections
        elif label == 'BDT_0.29':
            cutstouse = "("+preSelection_Wh+"(BDT_param_test>0.29))"
        elif label == 'DNN_0.99':
            cutstouse = "("+preSelection_Wh+"(DNN_test>0.99))"
        elif label == 'BDT_compressed_0.21':
            cutstouse = "("+preSelection_Wh+"(BDT_7N_2L_test>0.21))"
        elif label == 'DNN_compressed_0.995':
            cutstouse = "("+preSelection_Wh+"(DNN_7N_2Ltest>0.995))"
        elif label == 'Param_DNN_0.985':
            cutstouse = "("+preSelection_Wh+"(DNN_param_test>0.985))"
        elif label == 'Param_BDT_0.23':
            cutstouse = "("+preSelection_Wh+"(BDT_param_test>0.23))"
        elif label == 'Param_175_60_DNN_0.991':
            cutstouse = "("+preSelection_Wh+"(DNN_param_test>0.991))"
        elif label == 'Param_175_60_BDT_0.25':
            cutstouse = "("+preSelection_Wh+"(BDT_param_test>0.25))"
        elif label == 'XGB_0.9999':
            cutstouse = "("+preSelection_Wh+"(xgb_test>0.9999))"
        elif label == 'Non_param_DNN_0.995':
            cutstouse = "("+preSelection_Wh+"(DNN_test>0.995))"
        elif label == 'Non_param_BDT_0.28':
            cutstouse = "("+preSelection_Wh+"(BDT_test>0.28))"

        ## Wh Run 1 selections
        elif label == 'SRLM_Liv':
            cutstouse = "("+preSelection_Wh+"(mbb>105 && mbb<135)*(mct>160)*(met>200)*(mt>100 && mt<140))"
        elif label == 'SRMM_Liv':
            cutstouse = "("+preSelection_Wh+"(mbb>105 && mbb<135)*(mct>160)*(met>200)*(mt>140 && mt<200))"
        elif label == 'SRHM_Liv':
            cutstouse = "("+preSelection_Wh+"(mbb>105 && mbb<135)*(mct>160)*(met>200)*(mt>200))"

        luminosity_sim = "150*HFScale*eventWeight*"
        #directory = "/user/hteagle/liverpool-ml/TMVATuples/train/LowLev"
        directory = "/user/hteagle/liverpool-ml/TMVATuples/test/param_/"
        #directory = "/user/hteagle/liverpool-ml/TMVATuples/param_175_60/"
        outputdir = "/user/hteagle/liverpool-ml/Significances/"
        ttbarFile = directory+"ttbar.root"
        signalFiles = []

        for files  in os.listdir(directory):

            if "hall" not in files:
                #if "predictions" in files:
                print (str(files))
                signalFile = ROOT.TFile(directory+files)
                signalFiles.append(signalFile)

        Significance.Significance(cutstouse,luminosity_sim ,signalFiles, ttbarFile, signalFiles, outputdir, label)


# if options.doShapeFit:

#         #signal = "/user/hteagle/liverpool-ml/TMVATuples/test/non_param/user.msulliva.05Jul2018.392590.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_150p0_0p0__output.root"
#         signal_list = []
#         # signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/non_param/user.msulliva.05Jul2018.392634.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_0p0__output.root")
#         # signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/non_param/user.msulliva.05Jul2018.392635.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_25p0__output.root")
#         # signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/non_param/user.msulliva.05Jul2018.392636.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_50p0__output.root")
#         # signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/non_param/user.msulliva.05Jul2018.392638.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_75p0__output.root")
#         # signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/non_param/user.msulliva.05Jul2018.392637.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_100p0__output.root")



#         # signal_list.append("/user/hteagle/liverpool-ml/TMVATuples/test/non_param/user.msulliva.05Jul2018.392618.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_250p0_0p0__output.root")
#         # signal_list.append("/user/hteagle/liverpool-ml/TMVATuples/test/non_param/user.msulliva.05Jul2018.392620.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_250p0_50p0__output.root")
#         # signal_list.append("/user/hteagle/liverpool-ml/TMVATuples/test/non_param/user.msulliva.05Jul2018.392621.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_250p0_75p0__output.root")
#         # signal_list.append("/user/hteagle/liverpool-ml/TMVATuples/test/non_param/user.msulliva.05Jul2018.392622.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_250p0_100p0__output.root")


#         ##Low Level
#         # signal_list.append("/user/hteagle/liverpool-ml/TMVATuples/test/LowLev/user.msulliva.05Jul2018.392617.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_240p0_110p0__output.root")
#         # signal_list.append("/user/hteagle/liverpool-ml/TMVATuples/test/LowLev/user.msulliva.05Jul2018.392618.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_250p0_0p0__output.root")
#         # signal_list.append("/user/hteagle/liverpool-ml/TMVATuples/test/LowLev/user.msulliva.05Jul2018.392620.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_250p0_50p0__output.root")
#         # signal_list.append("/user/hteagle/liverpool-ml/TMVATuples/test/LowLev/user.msulliva.05Jul2018.392621.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_250p0_75p0__output.root")
#         # signal_list.append("/user/hteagle/liverpool-ml/TMVATuples/test/LowLev/user.msulliva.05Jul2018.392622.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_250p0_100p0__output.root")

#         # signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/LowLev/user.msulliva.05Jul2018.392634.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_0p0__output.root")
#         # signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/LowLev/user.msulliva.05Jul2018.392635.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_25p0__output.root")
#         # signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/LowLev/user.msulliva.05Jul2018.392636.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_50p0__output.root")
#         # signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/LowLev/user.msulliva.05Jul2018.392638.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_75p0__output.root")
#         # signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/LowLev/user.msulliva.05Jul2018.392637.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_100p0__output.root")

#         ##parameterised
#         # signal_list.append("/user/hteagle/liverpool-ml/TMVATuples/test/param_175_60/user.msulliva.05Jul2018.392618.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_250p0_0p0__output.root")
#         # signal_list.append("/user/hteagle/liverpool-ml/TMVATuples/test/param_175_60/user.msulliva.05Jul2018.392620.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_250p0_50p0__output.root")
#         # signal_list.append("/user/hteagle/liverpool-ml/TMVATuples/test/param_175_60/user.msulliva.05Jul2018.392621.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_250p0_75p0__output.root")
#         # signal_list.append("/user/hteagle/liverpool-ml/TMVATuples/test/param_175_60/user.msulliva.05Jul2018.392622.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_250p0_100p0__output.root")

#         # signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/param_175_60/user.msulliva.05Jul2018.392634.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_0p0__output.root")
#         # signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/param_175_60/user.msulliva.05Jul2018.392635.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_25p0__output.root")
#         # signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/param_175_60/user.msulliva.05Jul2018.392636.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_50p0__output.root")
#         # signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/param_175_60/user.msulliva.05Jul2018.392638.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_75p0__output.root")
#         # signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/param_175_60/user.msulliva.05Jul2018.392637.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_100p0__output.root")

#         ##Compressed
#         # signal_list.append("/user/hteagle/liverpool-ml/TMVATuples/test/Compressed/user.msulliva.05Jul2018.392618.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_250p0_0p0__output.root")
#         # signal_list.append("/user/hteagle/liverpool-ml/TMVATuples/test/Compressed/user.msulliva.05Jul2018.392620.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_250p0_50p0__output.root")
#         # signal_list.append("/user/hteagle/liverpool-ml/TMVATuples/test/Compressed/user.msulliva.05Jul2018.392621.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_250p0_75p0__output.root")
#         # signal_list.append("/user/hteagle/liverpool-ml/TMVATuples/test/Compressed/user.msulliva.05Jul2018.392622.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_250p0_100p0__output.root")

#         #signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/Compressed/user.msulliva.05Jul2018.392634.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_0p0__output.root")
#         #signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/Compressed/user.msulliva.05Jul2018.392635.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_25p0__output.root")
#         #signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/Compressed/user.msulliva.05Jul2018.392636.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_50p0__output.root")
#         #signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/Compressed/user.msulliva.05Jul2018.392638.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_75p0__output.root")
#         #signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/Compressed/user.msulliva.05Jul2018.392637.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_100p0__output.root")

#         background = "/user/hteagle/liverpool-ml/TMVATuples/test/non_param/ttbar.root"

#         variable = "BDT_7N_2L_test"
#         direct = "/user/hteagle/liverpool-ml/Significances/Shape/DNN_non_param/"
#         ensure_dir(direct)
#         #Do it
#         #for signal in signal_list:
#             #print (signal)
#             #ShapeFit.ShapeFit(signal, background, variable, 0.3, direct)
#         ShapeFit.multiFit(signal_list,background,variable,0.3,direct)

if __name__ == '__main__':
    main()
