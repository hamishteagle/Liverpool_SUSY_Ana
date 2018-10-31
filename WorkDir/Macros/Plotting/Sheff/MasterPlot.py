#!/usr/bin/env python

import os,sys,subprocess,datetime,copy,math,array,shutil,ROOT,string, CorrelationPlot, time, ShapePlot, RatioPlot, Cutflow
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
    print "Current date " + date   

    parser = OptionParser()
    parser.add_option("-f","--cutflow", action="store_true", dest="doCutflow", help="do cutflow?", default=False)
    parser.add_option("-r", "--ratio", action="store_true", dest="doRatio", help="do Ratio plots?", default=False)
    parser.add_option("-c", "--correlation", action="store_true", dest="doCorr", help="do Correlation plots?", default=False)
    parser.add_option("-s", "--shape", action="store_true", dest="doShape", help="do Shape plots?", default=False)
    parser.add_option("-d", "--date", action="store", type="string", dest="date", help="date for directory structure", default=date)
    (options, args) = parser.parse_args()    
    print "Arguments " , str(sys.argv)    
    

    if not (options.doCorr or options.doRatio or options.doShape or options.doCutflow):
        print "Ran without any options. Produced nothing. Good work"
        return 0


    #Sheff ntuples_21_2_31
    DiJetFile = "/hepstore/hteagle/Sbot_multiB/Sheff_ntuples_21_2_42/diJet.root"
    ttVFile = "/hepstore/hteagle/Sbot_multiB/Sheff_ntuples_21_2_42/ttV.root"
    wJetFile = "/hepstore/hteagle/Sbot_multiB/Sheff_ntuples_21_2_42/wJets.root"
    zJetFile = "/hepstore/hteagle/Sbot_multiB/Sheff_ntuples_21_2_42/zJets.root"
    ttbarFile = "/hepstore/hteagle/Sbot_multiB/Sheff_ntuples_21_2_42/ttbar.root"
    singleTopFile = "/hepstore/hteagle/Sbot_multiB/Sheff_ntuples_21_2_42/singleTop.root"
    DiBosonFile = "/hepstore/hteagle/Sbot_multiB/Sheff_ntuples_21_2_42/diBoson.root"
    HiggsFile = "/hepstore/hteagle/Sbot_multiB/Sheff_ntuples_21_2_42/Higgs.root" 
    dataFile = "/hepstore/hteagle/Sbot_multiB/Sheff_ntuples_21_2_42/data.root"

    #Liv ntuples_wh_21_2_31
    # DiJetFile = "/hepstore/hteagle/Wh/ntuples_21.2.31/mc16a/skimmed_newLumi/diJet.root"
    # ttVFile = "/hepstore/hteagle/Wh/ntuples_21.2.31/mc16a/skimmed_newLumi/ttV.root"
    # wJetFile = "/hepstore/hteagle/Wh/ntuples_21.2.31/mc16a/skimmed_newLumi/wJets.root"
    # zJetFile = "/hepstore/hteagle/Wh/ntuples_21.2.31/mc16a/skimmed_newLumi/zJets.root"
    # ttbarFile = "/hepstore/hteagle/Wh/ntuples_21.2.31/mc16a/skimmed_newLumi/ttbar.root"
    # singleTopFile = "/hepstore/hteagle/Wh/ntuples_21.2.31/mc16a/skimmed_newLumi/singleTop.root"
    # DiBosonFile = "/hepstore/hteagle/Wh/ntuples_21.2.31/mc16a/skimmed_newLumi/diBoson.root"
    # HiggsFile = "/hepstore/hteagle/Wh/ntuples_21.2.31/mc16a/skimmed_newLumi/VH.root" 
    # #dataFile = "/hepstore/hteagle/Wh/ntuples_21.2.31/skimmed/data_full_skim.root"
    # dataFile = "/hepstore/hteagle/Wh/ntuples_21.2.31/skimmed/data_1516.root"
    


    ### Edit the file below to use a different signal file
    #signalFile = "/hepstore/hteagle/nTuples_21_2_31/mc16_13TeV.390285.MGPy8EG_A14N23LO_BB_onestepN2hN1_700_680_550.e5671_e5984_a875_r9364_r9315_p3404_sbottom_multib_fixed.root"


    ###Liverpool ntuples (may be old ):start
    ###Liverpool ntuples (may be old ):end 

   ###These ntuples have the sheff trimming :( eT_miss_orig>250 && nj_good>=4&&  num_bjets>=2 && num_bjets>=6 && (nbaselineLep==0 || (nEl+nMu==1) || (nEl+nMu==2)) )
    #signalFile = "/hepstore/hteagle/nTuples_21_2_31/mc16_13TeV.390305.MGPy8EG_A14N23LO_BB_onestepN2hN1_900_530_400.e5671_e5984_a875_r9364_r9315_p3404_sbottom_multib_fixed.root"#21.2.31
    #signalFile = "/scratch/hteagle/multiB/nTuple_21_2_31/mc16a/signal/mc16_13TeV.390219.MGPy8EG_A14N23LO_BB_onestepN2hN1_800_795_60.e5671_e5984_a875_r9364_r9315_p3404_sbottom_multib_fixed.root"
    #signalFile = "/scratch/hteagle/multiB/nTuple_21_2_31/mc16a/signal/mc16_13TeV.390251.MGPy8EG_A14N23LO_BB_onestepN2hN1_500_380_250.e5671_e5984_a875_r9364_r9315_p3404_sbottom_multib_fixed.root"
    #signalFile = "/scratch/hteagle/multiB/nTuple_21_2_31/mc16a/mc16_13TeV.390285.MGPy8EG_A14N23LO_BB_onestepN2hN1_700_680_550.e5671_e5984_a875_r9364_r9315_p3404_sbottom_multib_fixed.root" 
    
   ###These are the ntuples which have only have cleaning cuts applied:
    #signalFile = "/hepstore/hteagle/Sbot_multiB/nTuples_21_2_31_clean/mc16_13TeV.390219.MGPy8EG_A14N23LO_BB_onestepN2hN1_800_795_60.e5671_e5984_a875_r9364_r9315_p3404_sbottom_multib_fixed.root"
    #signalFile = "/hepstore/hteagle/Sbot_multiB/nTuple_21_2_31_noFilter/mc16_13TeV.390285.MGPy8EG_A14N23LO_BB_onestepN2hN1_700_680_550.e5671_e5984_a875_r9364_r9315_p3404_sbottom_multib_fixed.root"
    
   ###These are for cutflow checks on Wh 1lbb
    #signalFile = "/scratch/hteagle/multiB/nTuple_21_2_31/mc16a/signal/mc16_13TeV.390285.MGPy8EG_A14N23LO_BB_onestepN2hN1_700_680_550.e5671_e5984_a875_r9364_r9315_p3404_sbottom_multib_fixed.root"
    #    signalFile = "/hepstore/hteagle/Sbot_multiB/Sheff_ntuples_21_2_42/mc16_13TeV.390285.MGPy8EG_A14N23LO_BB_onestepN2hN1_700_680_550.sbottom_multib_fixed.root"
    #signalFile = "/hepstore/hteagle/Sbot_multiB/Sheff_ntuples_21_2_42/mc16_13TeV.390300.MGPy8EG_A14N23LO_BB_onestepN2hN1_800_780_650.sbottom_multib_fixed.root"
    #signalFile = "/hepstore/hteagle/Sbot_multiB/Sheff_ntuples_21_2_42/mc16_13TeV.390285.MGPy8EG_A14N23LO_BB_onestepN2hN1_700_680_550.sbottom_multib_fixed.root"
    #signalFile = "/hepstore/hteagle/Sbot_multiB/Sheff_ntuples_21_2_42/mc16_13TeV.390308.MGPy8EG_A14N23LO_BB_onestepN2hN1_900_830_700.sbottom_multib_fixed.root"
    signalFile = "/hepstore/hteagle/Sbot_multiB/Sheff_ntuples_21_2_42/mc16_13TeV.390314.MGPy8EG_A14N23LO_BB_onestepN2hN1_1000_930_800.root"
    foundSignalInput = ""



    for i in sys.argv:
        print i
        if (str(i)).find(".root") > -1:
            print "Found a signal file"
            signalFile = str(i)
            print "Signal file is", signalFile
            if (signalFile.find("BB_direct") != -1):
                print "Found BB_direct"
                foundSignalInput = (signalFile.split("/")[6]).split(".")[4]
            elif (signalFile.find("Combined") != -1):
                print "Found combined"
                foundSignalInput = (signalFile.split("/")[6]).split(".")[0]
            elif (signalFile.find("onestepN2hN1") != -1):
                print "Found MultiB signal"
                foundSignalInput = ((signalFile.split("/")[6]).split(".")[4]).split("_")[4]+"_"+((signalFile.split("/")[6]).split(".")[4]).split("_")[5]+"_"+((signalFile.split("/")[6]).split(".")[4]).split("_")[6]
    


    #Sheff luminosity and weights
    luminosity_sheff = "47800*jvtweight*AnalysisWeight*pileupweight*LumiWeight*btagweight*MuonWeight*ElecWeight*isttbarMET400_OK*isttbarMET200_OK*isttbarMET300_OK*"#(YearWeight)*"

 #Liv luminosity and -weights
    luminosity_liv ="1*36.1*JVTSF*puWgt*bJetSF*muonSF*electronSF*mcEventWeight*lumiWgtRecalc*"#YearWeight*" DON'T FORGET to setAlias!!!
    cutstouse = ""
    #Liv Cleaning cuts
    cleaningCuts = "(coreFlag && sctFlag && LArTileFlag && passedPrimVertex && passedJetClean && passedCosmicMu && passedMuonClean)*"
    #Triggers 
    #triggerCuts = "(HLT_e26_lhtight_nod0_ivarloose || HLT_e60_lhmedium_nod0 || HLT_e140_lhloose_nod0 || HLT_mu26_ivarmedium || HLT_mu50) || (HLT_xe90_mht_L1XE50 || HLT_xe100_mht_L1XE50 || HLT_xe110_mht_L1XE50)*"
    triggerCuts = "((triggerDecisions[11] || triggerDecisions[13] || triggerDecisions[15] || triggerDecisions[20] || triggerDecisions[21]) || (triggerDecisions[25] || triggerDecisions[26] || triggerDecisions[27]))*"
    METtriggerCuts = "((year==2015 && triggerDecisions[23])||(year ==2016 && (triggerDecisions[25] || triggerDecisions[26] || triggerDecisions[27])))*"
    ymax = 800000
    doLog = False


    # Change this to put the output directory somewhere else
    directory = options.date+"_SbottomMultib_Preliminary/"+foundSignalInput
    print "Output Directory is: ", directory
    label = "pre-2b-4j-0L"
    EventCounter = True



    preSelection_Wh_Liv = "(LArTileFlag && coreFlag && sctFlag && passedPrimVertex && passedJetClean &&  passedMuonClean && nBaselineLeptons==1 && nLeptons==1 && nBJets==2 && nJets<4 && ETMiss>100 && m_T>40 && m_bb>50)*"
    # Preliminary Sbottom Multi B regions here:
    # Change the "cutstouse" variable to produce different distributions for a given selection. If plotting a SR distribution, 
    # make sure that SR is contained in the label variable, which will blind the distribution
    if label == "noSelection_Liv":
        cutstouse = cleaningCuts+triggerCuts+"(ETMiss>250 && nBJets>=2 && nLeptons>0)"
    elif label == "preSelection_Wh_Liv":
        cutstouse = preSelection_Wh_Liv+METtriggerCuts+"1"
    #Run1 Wh 1lbb (from int note)
    elif label =="cleaningCuts_Liv":
        cutstouse = "(LArTileFlag && coreFlag && sctFlag && passedPrimVertex && passedJetClean &&  passedMuonClean)"
    elif label =="preSelection_Liv":
        cutstouse = "(LArTileFlag && coreFlag && sctFlag && passedPrimVertex && passedJetClean &&  passedMuonClean && nBaselineLeptons==1 && nLeptons==1 && nBJets==2 && nJets<4 && ETMiss>100 && m_T>40 && m_bb>50)"
    elif label =="SRLM_Liv":
        cutstouse = "("+preSelection_Wh_Liv+triggerCuts+"(m_bb>105 && m_bb<135)*(m_CTcorr>160)*(ETMiss>200)*(m_T>100 && m_T<140))"
    elif label =="SRMM_Liv":
        cutstouse = "("+preSelection_Wh_Liv+triggerCuts+"(m_bb>105 && m_bb<135)*(m_CTcorr>160)*(ETMiss>200)*(m_T>140 && m_T<200))"
    elif label =="SRHM_Liv":
        cutstouse = "("+preSelection_Wh_Liv+triggerCuts+"(m_bb>105 && m_bb<135)*(m_CTcorr>160)*(ETMiss>200)*(m_T>200))"
    elif label =="TRHM_Liv":
        cutstouse = "("+preSelection_Wh_Liv+triggerCuts+" (m_bb<105 || m_bb>135)*(m_CTcorr<160)*(ETMiss>200)*(m_T>200))"
        

    #Fixed Sheffield Sbottom_MB regions
    elif label == "preSelection_SBMB":
        cutstouse="(passMETtriggers)*(eT_miss_orig>250)*(num_bjets>=4)"
    #SRA Regions
    elif label == "SR_SRA":
        cutstouse="(passMETtriggers)*(eT_miss_orig>250)*(nj_good>=6)*(num_bjets>=4)*(nbaselineLep==0)*(dphimin4_orig>0.4)*(maxDRbb>2.5)*(maxminDRbb<2.5)*(maxminDRmbb>80)*(pT_1bjet>200)*(passtauveto==1)*(meff>1000)*(meff<1200)"

    elif label == "CRA":
        cutstouse = cutstouse+"(eT_miss_orig>250 && num_bjets>=4 && nj_good>=6 && pT_1bjet >100 && (nEl==1||nMu==1)&&  pT_1lep>27 && meff>1000 && dphimin4_orig > 0.4)"

    elif label == "VRA":
        cutstouse = "(passMETtriggers &&  eT_miss_orig>250 && num_bjets==3 && nj_good>=6 &&  nbaselineLep==0 && pT_1bjet >200 && (dphimin4_orig>0.4) &&  passtauveto && meff>1000)"
    elif label == "pre-2b-4j-0L":
        cutstouse = "(eT_miss_orig>250 && num_bjets>=2 && nj_good>=4 &&  nbaselineLep==0 && (dphimin4_orig>0.4))"
    elif label == "pre-2b-4j-1L":
        cutstouse = "((eT_miss_orig>250)*(nj_good>=4)*(num_bjets>=2)*(nEl+nMu==1)*(pT_1lep>20)*(nbaselineLep==1)*(MT>20))"
    elif label == "pre-2b-4j-2LOS":
        cutstouse = "(eT_miss_orig>250)*(nj_good>=4)*(num_bjets>=2)*(nbaselineLep==2)*( (nEl==2)*(nMu==0)||(nEl==0)*(nMu==2))*(pT_1lep>27)*(pT_2lep>20)"

    #SRB Regions
    elif label == "SR_SRB":
        cutstouse = "(passMETtriggers)*(nj_good>=4)*(num_bjets>=4)*(nbaselineLep==0)*(dphimin4_orig>0.4)*(SRB2_Mh<140 && SRB2_Mh>50)*(pT_1jet>300)*(meff>1000)*(passtauveto==1)*(!leadb1)*(fabs(dPhi_1jet)>2.8)*(eT_miss>300)"

    elif label == "SR_SRB_new_N-1":
        cutstouse = "(passMETtriggers)*(nj_good>=4)*(num_bjets>=4)*(nbaselineLep==0)*(dphimin4_orig>0.4)*(pT_1jet>350)*(meff>1400)*(passtauveto==1)*(!leadb1)*(fabs(dPhi_1jet)>2.8)*(eT_miss>350)"

    elif label == "VRB":
        cutstouse = "(passMETtriggers)*(eT_miss_orig>250)*(nj_good>=4)*(nbaselineLep==0)*(dphimin4_orig>0.4)*(num_bjets==3)*(pT_1jet>300)*(meff>1000)*(passtauveto==1)*(!leadb1)*(fabs(dPhi_1jet)>2.8)*(metsig<25)"

    elif label == "CR_CRB":
        cutstouse ="(passMETtriggers)*(eT_miss_orig>250)*(nj_good>=4)*(num_bjets>=4)*(nEl+nMu==1)*(pT_1lep>20)*(nbaselineLep==1)*(MT>20)*(pT_1jet>300)*(meff>1000)*(passtauveto==1)*(!leadb1)*(fabs(dPhi_1jet)>2.2)"

    #SRC Regions
    elif label == "SR_SRC":
        cutstouse = "(passMETtriggers)*(eT_miss_orig>250)*(nj_good>=4)*(num_bjets>=3)*(nbaselineLep==0)*(dphimin4_orig>0.4)*(metsig>25)*(metsig>27)*(metsig>30)*(metsig>32)"

    elif label == "VRC_0lTop":
        cutstouse = "(passMETtriggers)*(eT_miss_orig>250)*(nj_good>=4)*(nbaselineLep==0)*((dphimin4_orig>0.2) && (dphimin4_orig<0.4))*(num_bjets>=3)*(metsig>19)*(metsig<22)"

    elif label == "VRC_1lZ":
        cutstouse = "(passMETtriggers)*(eT_miss_orig>250)*(nj_good>=4)*(num_bjets>=2)*(nbaselineLep==0)*(dphimin4_orig>0.4)*(metsig>23)*(metsig<24)*(num_bjets==2)*(mct2b>200)*(dphimin4>0.8)"

    elif label == "CR_CRC1l":
        cutstouse = "(passMETtriggers)*(eT_miss_orig>250)*(nj_good>=4)*(num_bjets>=3)*(nEl+nMu==1)*(pT_1lep>20)*(nbaselineLep==1)*(MT>20)*(metsig>20)"

    elif label == "CR_CRC2l":
        cutstouse = "(nj_good>=4)*(num_bjets>=3)*(nbaselineLep==2)*( ((nEl==2)*(nMu==0)||(nEl==0)*(nMu==2))   )*(pT_1lep>27)*(pT_2lep>20)*(charge_1l+charge_2l==0)*(mll>86)*(mll<106)*(eT_miss>250)"


    else:
        print "Error Wrong label try again. "
        return 1

    gROOT.LoadMacro("/user/hteagle/AnalysisDirectory/Rel21/Base.21.2.31/run/Macros/Plotting/AtlasStyle/AtlasStyle.cxx")                                                                                                                                                                                                
    ROOT.SetAtlasStyle()       

    plottinglist = []

    if options.doRatio:

        # This uses the ratio plotting class, to produce a ratio plot of whatever variable you give as the first argument. The second argument is the latex which will be drawn on the x-axis. 3rd is the xlow, 4th is xhigh and 5th is the rebinning value. The rest you shouldn't need to change and instead should just copy from an existing usage of the function
        #RatioPlot.RatioPlot("1", "cuts", 0.5, 1.5, 1, ymax, cutstouse, directory, label, True, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, True, False, luminosity_sheff)
        #RatioPlot.RatioPlot("eT_miss_orig", "eT_miss_orig", 250, 500, 25, ymax, cutstouse, directory, label, True, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile,DiJetFile, dataFile, signalFile, False, False, luminosity_sheff)

        #RatioPlot.RatioPlot("m_bb", "m_{bb}", 30, 630, 30, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, False, False, luminosity_sheff)
        #RatioPlot.RatioPlot("fatJet8_M[0]", "m_{leading 0.8Jet}", 0, 200, 10, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, False, False, luminosity_sheff)
        RatioPlot.RatioPlot("eT_miss", "E_{T}^{miss}", 250, 1000, 50, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile,HiggsFile, wJetFile, zJetFile, ttbarFile, dataFile, signalFile, False, False, luminosity_sheff)
        RatioPlot.RatioPlot("metsig", "Oject-based METsig", 0, 45, 2, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile,HiggsFile, wJetFile, zJetFile, ttbarFile, dataFile, signalFile, False, False, luminosity_sheff)
        RatioPlot.RatioPlot("nj_good", "n_{jets}", 0, 15, 1, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, dataFile, signalFile, False,False, luminosity_sheff)
        RatioPlot.RatioPlot("num_bjets", "n_{b-jets}", -0.5, 9.5, 1, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, dataFile, signalFile, False, False, luminosity_sheff)
        #RatioPlot.RatioPlot("maxminDRmbb1", "min #Delta R(m_{bb})", 50, 250, 20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, False, False, luminosity_sheff)
        # #RatioPlot.RatioPlot("maxminDRmbb", "maxMin #Delta R(m_{bb})", 60, 160, 10, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, False, False, luminosity_sheff)
        # #RatioPlot.RatioPlot("minDR", "min #Delta R(b,b)", 0, 4, 1, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, False, False, luminosity_sheff)
        RatioPlot.RatioPlot("meff", "m_{eff}", 500, 2500, 80, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, dataFile, signalFile, True, False, luminosity_sheff)
        RatioPlot.RatioPlot("pT_1lep", "p_{T}(leading lep)", 30, 300, 25, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, dataFile, signalFile, False, False, luminosity_sheff)
        # #RatioPlot.RatioPlot("pTel1", "p_{T}(e)", 0, 800, 40, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, False, False, luminosity_sheff)
        #RatioPlot.RatioPlot("dphimin4_orig", "min #Delta#phi(j,E_{T}^{miss})", 0, math.pi,20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, True, False, luminosity_sheff)
        #RatioPlot.RatioPlot("dPhi_1jet", "min #Delta#phi(j1,E_{T}^{miss})", -3.5, 3.5,20, ymax, cutstouse, directory, label, True, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, True, False, luminosity_sheff)
        #RatioPlot.RatioPlot("pT_1bjet", "p_{T}^{b1}", 0, 800, 40, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile,dataFile, signalFile, False, False, luminosity_sheff)
        RatioPlot.RatioPlot("pT_1jet", "p_{T}^{j1} ", 200, 800, 50, ymax, cutstouse, directory, label, True, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, dataFile, signalFile, False, False, luminosity_sheff)
        #RatioPlot.RatioPlot("MT", "m_T", 0, 200, 10, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, False, False, luminosity_sheff)
        #RatioPlot.RatioPlot("m_CT", "m_{CT}", 0, 700, 80, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, dataFile, signalFile, False, False, -luminosity_sheff)
        RatioPlot.RatioPlot("HT", "H_{T}", 0, 2000, 150, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, dataFile, signalFile, False, False, luminosity_sheff)
        # #RatioPlot.RatioPlot("dPhib1b2", "#Delta#phi(b_{1},b_{2})", 0, math.pi,20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, True, False, luminosity_sheff)
        # #RatioPlot.RatioPlot("HiggsMassCandidate_4Hb", "Higgs Candidate mass", 0, math.pi,20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, True, False, luminosity_sheff)
        #RatioPlot.RatioPlot("SRB1_Mh", "Average Mass of the 2 b-jet pairs (SRB1)", 0, 300,20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, False, False, luminosity_sheff)
        #RatioPlot.RatioPlot("SRB2_Mh", "Average Mass of the 2 b-jet pairs (SRB2)", 0, 300,20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, False, False, luminosity_sheff)
        #RatioPlot.RatioPlot("SRB3_mbb_avg", "Average Mass of the 2 b-jet pairs (SRB3)", 0, 300,20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, wJetFile, zJetFile, ttbarFile, dataFile, signalFile, False, False, luminosity_sheff)
       # RatioPlot.RatioPlot("SRB4_mbb_avg", "Average Mass of the 2 b-jet pairs (SRB4)", 0, 300,20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, wJetFile, zJetFile, ttbarFile, dataFile, signalFile, False, False, luminosity_sheff)
        #RatioPlot.RatioPlot("SRB1_DRmin", "SRB1_DRmin", 0.0001, 6.0001,1, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, True, False,luminosity_sheff)
        #RatioPlot.RatioPlot("SRB2_minDR", "SRB2_minDR", 0.0001, 6.0001,1, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, True, False, luminosity_sheff)
        #RatioPlot.RatioPlot("SRB1_DRmin2", "SRB1_DRmin2", 0.0001, 6.0001,1, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, True, False, luminosity_sheff)
        #RatioPlot.RatioPlot("SRB2_maxDR", "SRB2_maxDR", 0.0001, 6.0001,1, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, True, False, luminosity_sheff)
        # #RatioPlot.RatioPlot("nbaselineLep","#leptons",-0.5,9.5,1,ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, True, False, luminosity_sheff)
        #RatioPlot.RatioPlot("leadb1","ISRlead (0), b-jet lead (1)",-0.5,1.5,1,ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, False, False, luminosity_sheff)
        #RatioPlot.RatioPlot("SRB2_Mh1 ","Higgs candidate mass-DRmin",0,500,50,ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, False, False, luminosity_sheff)
        #RatioPlot.RatioPlot("SRB2_Mh2 ","Higgs candidate mass-DRmax",0,300,25,ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, False, False, luminosity_sheff)


    if options.doCorr:
        CorrelationPlot.CorrelationPlot("amT2", "min( (sqrt(2*(pT_1bjet *eT_miss_orig*(1 - cos(fabs(TVector2::Phi_mpi_pi( (phib1  - eT_miss_origPhi))))))) ), (sqrt(2*(pTb2*eT_miss_orig*(1 - cos(fabs(TVector2::Phi_mpi_pi( (phib2  - eT_miss_origPhi)))))))))","am_{T2}", "min-m_{T}(b,E_{T}^{miss})", 0, 400, 20, 0, 400, 20, cutstouse, directory, label, dataFile, zJetFile)

    if options.doShape:
        ShapePlot.ShapePlot2("m_CT", "m_{CT}", 0, 1000, 50, 100000, cutstouse, directory, label, inputstringShape1,inputstringShape2, False, False, False)
        ShapePlot.ShapePlot2("m_T", "m_{T}", 0, 1000, 50, 100000, cutstouse, directory, label, inputstringShape1,inputstringShape2, False, False, False)

    if options.doCutflow:
        print "Going to do cutflow"
        Cutflow.Cutflow(label, cutstouse, signalFile, luminosity_sheff)

if __name__ == '__main__':
    main()
