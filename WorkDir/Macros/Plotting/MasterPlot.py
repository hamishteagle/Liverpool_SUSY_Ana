#!/usr/bin/env python

import os,sys,subprocess,datetime,copy,math,array,shutil,ROOT,string, CorrelationPlot, time, ShapePlot, RatioPlot, Cutflow, Significance, ShapeFit
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
    parser.add_option("-f", "--shapeFit", action="store_true", dest="doShapeFit", help="Run the shapeFt plotting script", default=False)

    parser.add_option("-p", "--shape", action="store_true", dest="doShape", help="do Shape plots?", default=False)
    parser.add_option("-a", "--correlation", action="store_true", dest="doCorr", help="do Correlation plots?", default=False)
    parser.add_option("-d", "--date", action="store", type="string", dest="date", help="date for directory structure", default=date)
    (options, args) = parser.parse_args()

    print ("Arguments " , str(sys.argv))


    if not (options.doCorr or options.doRatio or options.doShape or options.doCutflow or options.doSignif or options.doShapeFit):
        print ("Ran without any options. Produced nothing. Good work")
        return 0


    #Sheff ntuples_21_2_31
    # DiJetFile = "/scratch/hteagle/multiB/nTuple_21_2_31/mc16a/diJet.root"
    # ttVFile = "/scratch/hteagle/multiB/nTuple_21_2_31/mc16a/ttV.root"
    # wJetFile = "/scratch/hteagle/multiB/nTuple_21_2_31/mc16a/wJets.root"
    # zJetFile = "/scratch/hteagle/multiB/nTuple_21_2_31/mc16a/zJets.root"
    # ttbarFile = "/scratch/hteagle/multiB/nTuple_21_2_31/mc16a/ttbar.root"
    # singleTopFile = "/scratch/hteagle/multiB/nTuple_21_2_31/mc16a/singleTop.root"
    # DiBosonFile = "/scratch/hteagle/multiB/nTuple_21_2_31/mc16a/diBoson.root"
    # HiggsFile = "/scratch/hteagle/multiB/nTuple_21_2_31/mc16a/VhTh.root"
    # dataFile = "/scratch/hteagle/multiB/nTuple_21_2_31/data.root"

    #Liv ntuples_wh_21_2_31
    DiJetFile = "/hepstore/hteagle/Wh/ntuples_21.2.31/mc16a/skimmed_newLumi/diJet.root"
    ttVFile = "/hepstore/hteagle/Wh/ntuples_21.2.31/mc16a/skimmed_newLumi/ttV.root"
    wJetFile = "/hepstore/hteagle/Wh/ntuples_21.2.31/mc16a/skimmed_newLumi/wJets.root"
    zJetFile = "/hepstore/hteagle/Wh/ntuples_21.2.31/mc16a/skimmed_newLumi/zJets.root"
    ttbarFile = "/hepstore/hteagle/Wh/ntuples_21.2.31/mc16a/skimmed_newLumi/ttbar.root"
    singleTopFile = "/hepstore/hteagle/Wh/ntuples_21.2.31/mc16a/skimmed_newLumi/singleTop.root"
    DiBosonFile = "/hepstore/hteagle/Wh/ntuples_21.2.31/mc16a/skimmed_newLumi/diBoson.root"
    HiggsFile = "/hepstore/hteagle/Wh/ntuples_21.2.31/mc16a/skimmed_newLumi/VH.root"
    #dataFile = "/hepstore/hteagle/Wh/ntuples_21.2.31/skimmed/data.root"
    dataFile = "/hepstore/hteagle/Wh/ntuples_21.2.31/skimmed/data_151617_2.root"

    signalFiles = []
    signalFiles.append("/hepstore/hteagle/Wh/ntuples_21.2.31/mc16a/skimmed_newLumi/wJets.root")
    #signalFiles.append("/hepstore/hteagle/Wh/ntuples_21.2.31/mc16a/skimmed_newLumi/zJets.root")


    #signalFile = "/hepstore/hteagle/SubmissionOutputs/Wh/recoSamples/mc16_13TeV.410470.PhPy8EG_A14_ttbar_hdamp258p75_nonallhad.deriv.DAOD_SUSY5.e6337_e5984_s3126_r9364_r9315_p3563/data-output/DAOD_SUSY5.root"
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



    #Sheff luminosity and weights
    luminosity_sheff = "79800*jvtweight*AnalysisWeight*pileupweight*LumiWeight*btagweight*MuonWeight*ElecWeight*isttbarMET400_OK*isttbarMET200_OK*isttbarMET300_OK*"
    #Liv luminosity and -weights
    luminosity_liv ="1*70*JVTSF*puWgt*bJetSF*muonSF*electronSF*mcEventWeight*lumiWgtRecalc*YearWeight*" #DON'T FORGET to setAlias!!!
    cutstouse = ""
    #Liv Cleaning cuts
    cleaningCuts = "(coreFlag && sctFlag && LArTileFlag && passedPrimVertex && passedJetClean && passedCosmicMu && passedMuonClean)*"
    #Triggers
    #triggerCuts = "(HLT_e26_lhtight_nod0_ivarloose || HLT_e60_lhmedium_nod0 || HLT_e140_lhloose_nod0 || HLT_mu26_ivarmedium || HLT_mu50) || (HLT_xe90_mht_L1XE50 || HLT_xe100_mht_L1XE50 || HLT_xe110_mht_L1XE50)*"
    triggerCuts = "((triggerDecisions[11] || triggerDecisions[13] || triggerDecisions[15] || triggerDecisions[20] || triggerDecisions[21]) || (triggerDecisions[25] || triggerDecisions[26] || triggerDecisions[27]))*"
    METtriggerCuts = "((year==2015 && triggerDecisions[23])||((year ==2016||year==2017) && (triggerDecisions[25] || triggerDecisions[26] || triggerDecisions[27])))*"
    ymax = 800000
    doLog = False


    # Change this to put the output directory somewhere else
    directory = options.date+"_SbottomMultib_Preliminary/"+foundSignalInput
    print ("Output Directory is: ", directory)
    #############################
    label = "SR_SRB"
    #############################
    EventCounter = True



    preSelection_Wh_Liv = "(nBaselineLeptons==1 && pTl1>27 && nLeptons==1 && nBJets==2 && nJets<4 && ETMiss>200 && m_T>40 && m_bb>50)*"
    # Preliminary Sbottom Multi B regions here:
    # Change the "cutstouse" variable to produce different distributions for a given selection. If plotting a SR distribution,
    # make sure that SR is contained in the label variable, which will blind the distribution
    if label == "noSelection_Liv":
        cutstouse = cleaningCuts+triggerCuts+"(ETMiss>250 && nBJets>=2 && nLeptons>0)"
    elif label == "preSelection_Wh_Liv":
        cutstouse = METtriggerCuts+preSelection_Wh_Liv+"1"
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
    #SRA Regions
    elif label == "SR_SRA":
        cutstouse="(passMETtriggers)*(eT_miss_orig>250)*(nj_good>=6)*(num_bjets>=4)*(nbaselineLep==0)*(dphimin4_orig>0.4)*(maxDRbb>2.5)*(maxminDRbb<2.5)*(maxminDRmbb>80)*(pT_1bjet>200)*(passtauveto==1)*(meff>1000)*(meff<1200)"

    elif label == "CRA":
        cutstouse = cutstouse+"(eT_miss_orig>250 && num_bjets>=4 && nj_good>=6 && pT_1bjet >100 && (nEl==1||nMu==1)&&  pT_1lep>27 && meff>1000 && dphimin4_orig > 0.4)"

    elif label == "VRA":
        cutstouse = "(passMETtriggers &&  eT_miss_orig>250 && num_bjets==3 && nj_good>=6 &&  nbaselineLep==0 && pT_1bjet >200 && (dphimin4_orig>0.4) &&  passtauveto && meff>1000)"


    #SRB Regions
    elif label == "SR_SRB":
        cutstouse = "(passMETtriggers)*(nj_good>=4)*(num_bjets>=4)*(nbaselineLep==0)*(dphimin4_orig>0.4)*(SRB2_Mh<140 && SRB2_Mh>50)*(pT_1jet>300)*(meff>1000)*(passtauveto==1)*(!leadb1)*(fabs(dPhi_1jet)>2.8)*(eT_miss>300)"

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
        print ("Error Wrong label try again. ")
        return 1

    gROOT.LoadMacro("/user/hteagle/AnalysisDirectory/Rel21/Base.21.2.31/run/Macros/Plotting/AtlasStyle/AtlasStyle.cxx")
    ROOT.SetAtlasStyle()

    plottinglist = []

    if options.doRatio:

        # This uses the ratio plotting class, to produce a ratio plot of whatever variable you give as the first argument. The second argument is the latex which will be drawn on the x-axis. 3rd is the xlow, 4th is xhigh and 5th is the rebinning value. The rest you shouldn't need to change and instead should just copy from an existing usage of the function
        #RatioPlot.RatioPlot("1", "cuts", 0.5, 1.5, 1, ymax, cutstouse, directory, label, True, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, True, False, luminosity_liv)
        #RatioPlot.RatioPlot("eT_miss_orig", "eT_miss_orig", 0., 1000, 1, ymax, cutstouse, directory, label, True, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, DiJetFile, ttbarFile, dataFile, signalFiles, False, False, luminosity_liv)

        RatioPlot.RatioPlot("m_bb", "m_{bb}", 30, 630, 30, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv)
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


    if options.doShapeFit:

        #signal = "/user/hteagle/liverpool-ml/TMVATuples/test/non_param/user.msulliva.05Jul2018.392590.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_150p0_0p0__output.root"
        signal_list = []
        # signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/non_param/user.msulliva.05Jul2018.392634.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_0p0__output.root")
        # signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/non_param/user.msulliva.05Jul2018.392635.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_25p0__output.root")
        # signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/non_param/user.msulliva.05Jul2018.392636.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_50p0__output.root")
        # signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/non_param/user.msulliva.05Jul2018.392638.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_75p0__output.root")
        # signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/non_param/user.msulliva.05Jul2018.392637.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_100p0__output.root")



        # signal_list.append("/user/hteagle/liverpool-ml/TMVATuples/test/non_param/user.msulliva.05Jul2018.392618.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_250p0_0p0__output.root")
        # signal_list.append("/user/hteagle/liverpool-ml/TMVATuples/test/non_param/user.msulliva.05Jul2018.392620.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_250p0_50p0__output.root")
        # signal_list.append("/user/hteagle/liverpool-ml/TMVATuples/test/non_param/user.msulliva.05Jul2018.392621.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_250p0_75p0__output.root")
        # signal_list.append("/user/hteagle/liverpool-ml/TMVATuples/test/non_param/user.msulliva.05Jul2018.392622.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_250p0_100p0__output.root")


        ##Low Level
        # signal_list.append("/user/hteagle/liverpool-ml/TMVATuples/test/LowLev/user.msulliva.05Jul2018.392617.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_240p0_110p0__output.root")
        # signal_list.append("/user/hteagle/liverpool-ml/TMVATuples/test/LowLev/user.msulliva.05Jul2018.392618.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_250p0_0p0__output.root")
        # signal_list.append("/user/hteagle/liverpool-ml/TMVATuples/test/LowLev/user.msulliva.05Jul2018.392620.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_250p0_50p0__output.root")
        # signal_list.append("/user/hteagle/liverpool-ml/TMVATuples/test/LowLev/user.msulliva.05Jul2018.392621.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_250p0_75p0__output.root")
        # signal_list.append("/user/hteagle/liverpool-ml/TMVATuples/test/LowLev/user.msulliva.05Jul2018.392622.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_250p0_100p0__output.root")

        # signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/LowLev/user.msulliva.05Jul2018.392634.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_0p0__output.root")
        # signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/LowLev/user.msulliva.05Jul2018.392635.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_25p0__output.root")
        # signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/LowLev/user.msulliva.05Jul2018.392636.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_50p0__output.root")
        # signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/LowLev/user.msulliva.05Jul2018.392638.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_75p0__output.root")
        # signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/LowLev/user.msulliva.05Jul2018.392637.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_100p0__output.root")

        ##parameterised
        # signal_list.append("/user/hteagle/liverpool-ml/TMVATuples/test/param_175_60/user.msulliva.05Jul2018.392618.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_250p0_0p0__output.root")
        # signal_list.append("/user/hteagle/liverpool-ml/TMVATuples/test/param_175_60/user.msulliva.05Jul2018.392620.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_250p0_50p0__output.root")
        # signal_list.append("/user/hteagle/liverpool-ml/TMVATuples/test/param_175_60/user.msulliva.05Jul2018.392621.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_250p0_75p0__output.root")
        # signal_list.append("/user/hteagle/liverpool-ml/TMVATuples/test/param_175_60/user.msulliva.05Jul2018.392622.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_250p0_100p0__output.root")

        # signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/param_175_60/user.msulliva.05Jul2018.392634.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_0p0__output.root")
        # signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/param_175_60/user.msulliva.05Jul2018.392635.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_25p0__output.root")
        # signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/param_175_60/user.msulliva.05Jul2018.392636.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_50p0__output.root")
        # signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/param_175_60/user.msulliva.05Jul2018.392638.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_75p0__output.root")
        # signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/param_175_60/user.msulliva.05Jul2018.392637.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_100p0__output.root")

        ##Compressed
        # signal_list.append("/user/hteagle/liverpool-ml/TMVATuples/test/Compressed/user.msulliva.05Jul2018.392618.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_250p0_0p0__output.root")
        # signal_list.append("/user/hteagle/liverpool-ml/TMVATuples/test/Compressed/user.msulliva.05Jul2018.392620.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_250p0_50p0__output.root")
        # signal_list.append("/user/hteagle/liverpool-ml/TMVATuples/test/Compressed/user.msulliva.05Jul2018.392621.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_250p0_75p0__output.root")
        # signal_list.append("/user/hteagle/liverpool-ml/TMVATuples/test/Compressed/user.msulliva.05Jul2018.392622.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_250p0_100p0__output.root")

        #signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/Compressed/user.msulliva.05Jul2018.392634.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_0p0__output.root")
        #signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/Compressed/user.msulliva.05Jul2018.392635.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_25p0__output.root")
        #signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/Compressed/user.msulliva.05Jul2018.392636.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_50p0__output.root")
        #signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/Compressed/user.msulliva.05Jul2018.392638.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_75p0__output.root")
        #signal_list.append("/user/hteagle//liverpool-ml/TMVATuples/test/Compressed/user.msulliva.05Jul2018.392637.DAOD_TRUTH3.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hall_300p0_100p0__output.root")

        background = "/user/hteagle/liverpool-ml/TMVATuples/test/non_param/ttbar.root"

        variable = "BDT_7N_2L_test"
        direct = "/user/hteagle/liverpool-ml/Significances/Shape/DNN_non_param/"
        ensure_dir(direct)
        #Do it
        #for signal in signal_list:
            #print (signal)
            #ShapeFit.ShapeFit(signal, background, variable, 0.3, direct)
        ShapeFit.multiFit(signal_list,background,variable,0.3,direct)

if __name__ == '__main__':
    main()
