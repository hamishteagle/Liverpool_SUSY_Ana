#!/usr/bin/env python

import os,sys,subprocess,datetime,copy,math,array,shutil,ROOT,string, CorrelationPlot, time, ShapePlot, RatioPlot, Cutflow, Significance, TurnOn#, ShapeFit
from ROOT import gROOT, TColor, TLatex, gStyle, TLegend, gPad, TAttText,TMath, TVector2, RooStats
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
    parser.add_option("-t", "--turnon", action="store_true", dest="doTurnOn", help="do TurnOnCurves?", default =False)
    parser.add_option("-p", "--shape", action="store_true", dest="doShape", help="do Shape plots?", default=False)
    parser.add_option("-a", "--correlation", action="store_true", dest="doCorr", help="do Correlation plots?", default=False)
    parser.add_option("-d", "--date", action="store", type="string", dest="date", help="date for directory structure", default=date)
    #parser.add_option("-f", "--shapeFit", action="store_true", dest="doShapeFit", help="Run the shapeFt plotting script", default=False)
    (options, args) = parser.parse_args()

    print ("Arguments " , str(sys.argv))


    if not (options.doCorr or options.doRatio or options.doShape or options.doCutflow or options.doSignif or options.doTurnOn): #or options.doShapeFit):
        print ("Ran without any options. Produced nothing. Good work")
        return 0


    # #Liv ntuples_wh_21_2_55
    DiJetFile = "/hepstore/hteagle/Wh/ntuples_21.2.60/diJet.root"
    ttVFile = "/hepstore/hteagle/Wh/ntuples_21.2.60/ttV.root"
    wJetFile = "/hepstore/hteagle/Wh/ntuples_21.2.60/wJets.root"
    zJetFile = "/hepstore/hteagle/Wh/ntuples_21.2.60/zJets.root"
    ttbarFile = "/hepstore/hteagle/Wh/ntuples_21.2.60/ttbar.root"
    singleTopFile = "/hepstore/hteagle/Wh/ntuples_21.2.60/singleTop.root"
    DiBosonFile = "/hepstore/hteagle/Wh/ntuples_21.2.60/diBoson.root"
    HiggsFile = "/hepstore/hteagle/Wh/ntuples_21.2.60/higgs.root"
    dataFile = "/hepstore/hteagle/Wh/ntuples_21.2.60/data.root"


    #Liv ntuples_wh_21.2.60_BDT
    # DiJetFile = "/user/hteagle/liverpool-ml/TMVATuples/reco_full/diJet.root"
    # ttVFile = "/user/hteagle/liverpool-ml/TMVATuples/reco_full/ttV.root"
    # wJetFile = "/user/hteagle/liverpool-ml/TMVATuples/reco_full/wJets.root"
    # zJetFile = "/user/hteagle/liverpool-ml/TMVATuples/reco_full/zJets.root"
    # ttbarFile = "/user/hteagle/liverpool-ml/TMVATuples/reco_full/ttbar.root"
    # #ttbarFile = "/user/hteagle/liverpool-ml/TMVATuples/reco_full/ttbar_nominal.root"
    # singleTopFile = "/user/hteagle/liverpool-ml/TMVATuples/reco_full/singleTop.root"
    # DiBosonFile = "/user/hteagle/liverpool-ml/TMVATuples/reco_full/diBoson.root"
    # HiggsFile = "/user/hteagle/liverpool-ml/TMVATuples/reco_full/higgs.root"
    # dataFile = "/user/hteagle/liverpool-ml/TMVATuples/reco_full/data.root"

    signalFiles = []

    ##TruthSmeared-reco comparisons
    # signalFiles.append('/hepstore/hteagle/Wh/ntuples_simpleAnalysis/400_250_TruthSmeared.root')
    # signalFiles.append('/hepstore/hteagle/Wh/ntuples_simpleAnalysis/400_250_TruthSmeared_EtaPhiPsmear.root')
    # signalFiles.append('/hepstore/hteagle/Wh/ntuples_21.2.60/396734.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hbb_400p0_250p0_lep_output.root')
    
    ##Local files
    # signalFiles.append('/user/hteagle/AnalysisDirectory/Rel21/Base.21.2.72/run/submitdir_300_150/data-output/DAOD_SUSY5.root')
    # signalFiles.append('/user/hteagle/AnalysisDirectory/Rel21/Base.21.2.72/run/submitdir_400_250/data-output/DAOD_SUSY5.root')
    # signalFiles.append('/hepstore/hteagle/Wh/ntuples_21.2.67/26Apr.TTBAR_MC16a.21.2.67410470.PhPy8EG_A14_ttbar_hdamp258p75_nonallhad_output.root')
    
    #signalFiles.append('/scratch/hteagle/SbMB/dm130/mc16_13TeV.390285.MGPy8EG_A14N23LO_BB_onestepN2hN1_700_680_550_a_d_e.root')
    #signalFiles.append('/scratch/hteagle/SbMB/dm130/mc16_13TeV.391841.MGPy8EG_A14N23LO_BB_onestepN2hN1_1100_330_200_a_d_e.root')
    #signalFiles.append('/scratch/hteagle/SbMB/m60/mc16_13TeV.391874.MGPy8EG_A14N23LO_BB_onestepN2hN1_1200_1150_60_a_d_e.root')

    #signalFiles.append('/user/hteagle/AnalysisDirectory/Rel21/Base.21.2.72/run/wh_cutflow/data-output/DAOD_SUSY5.root')
    #signalFiles.append('/user/hteagle/AnalysisDirectory/Rel21/Base.21.2.72/run/submitdir_300_150_cutflow/data-output/DAOD_SUSY5.root')

    
    #signalFiles.append("/hepstore/hteagle/Wh/ntuples_21.2.60/ttV.root")
    #signalFiles.append("/hepstore/hteagle/Wh/ntuples_21.2.60/diBoson.root")
    signalFiles.append('/hepstore/hteagle/Wh/ntuples_21.2.60/396716.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hbb_300p0_150p0_lep_output.root')
    signalFiles.append('/hepstore/hteagle/Wh/ntuples_21.2.60/396734.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hbb_400p0_250p0_lep_output.root')
    signalFiles.append('/hepstore/hteagle/Wh/ntuples_21.2.60/396750.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hbb_500p0_350p0_lep_output.root')
    signalFiles.append('/hepstore/hteagle/Wh/ntuples_21.2.60/396767.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hbb_600p0_400p0_lep_output.root')
    
    #signalFiles.append('/user/hteagle/liverpool-ml/TMVATuples/reco_full/400_250_TruthSmeared.root')    
    #signalFiles.append('/user/hteagle/liverpool-ml/TMVATuples/reco_full/400_250_TruthSmeared_EtaPhiPsmear.root')
    # signalFiles.append('/user/hteagle/liverpool-ml/TMVATuples/reco_full/396706.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hbb_250p0_100p0_lep_output.root')
    # signalFiles.append('/user/hteagle/liverpool-ml/TMVATuples/reco_full/396716.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hbb_300p0_150p0_lep_output.root')
    # signalFiles.append('/user/hteagle/liverpool-ml/TMVATuples/reco_full/396734.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hbb_400p0_250p0_lep_output.root')
    # signalFiles.append('/user/hteagle/liverpool-ml/TMVATuples/reco_full/396750.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hbb_500p0_350p0_lep_output.root')


    ##SbottomMB files
    #signalFiles.append('/hepstore/hteagle/SbMB/Sheff_ntuples_21_2_62/mc16_13TeV.391874.MGPy8EG_A14N23LO_BB_onestepN2hN1_1200_1150_60.root')
    
    
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


    #Liv Cleaning cuts
    cleaningCuts = "(coreFlag)*(sctFlag)*(LArTileFlag)*(passedPrimVertex)*(passedJetClean)*(passedMuonClean)*"
    weights = 'mcEventWeight*HFScale*JVTSF*puWgt*bJetSF*muonSF*electronSF*YearWeight*'
    #Liv luminosity and -weights
    luminosity_liv ="139*"+weights
    luminosity_Shef ="139000*LumiWeight*pileupweight*jvtweight*btagweight*AnalysisWeight*YearWeight*"

    luminosity_Truth = "140.5*mcEventWeight*HFScale*"
    cutstouse = ""


    #Triggers
    METtriggerCuts_15 = "(((year==2015 && triggerDecisions[0])||"

    METtriggerCuts_16 = "(year ==2016 && ((RunNumber<=302919 && triggerDecisions[2]) || (RunNumber>302919 && triggerDecisions[1])) )|| "

    METtriggerCuts_17 = "(year==2017 && ((RunNumber <= 328393 && (triggerDecisions[4] || triggerDecisions[5]))||((RunNumber >328393 && RunNumber<=33047) &&(triggerDecisions[6]||triggerDecisions[7]||triggerDecisions[8]))||((RunNumber >33047 && RunNumber<=331975) && (triggerDecisions[7] || triggerDecisions[8]))||(RunNumber>331975 &&triggerDecisions[8])))||"

    METtriggerCuts_18 = "(year == 2018 && ((RunNumber<=349533 && (triggerDecisions[9]||triggerDecisions[11]))||(RunNumber>349533 && RunNumber<= 355273 &&(triggerDecisions[9] || triggerDecisions[10] && triggerDecisions[11]))||(RunNumber > 355273 && (triggerDecisions[9] || triggerDecisions[10]))))))*"
    METtriggerCuts = METtriggerCuts_15+METtriggerCuts_16+METtriggerCuts_17+METtriggerCuts_18 


    OneLtriggerCuts = "((year == 2015 && ((triggerDecisions[9] || triggerDecisions[12] || triggerDecisions[14])||(triggerDecisions[16] || triggerDecisions[21])))||((triggerDecisions[10] ||triggerDecisions[13] || triggerDecisions[15])||(triggerDecisions[20] || triggerDecisions[21])))*"

    isttbarOK = "( (mcID != 410470 || truthFilterMET < 100)&&(mcID != 345935 || (truthFilterMET >= 100 && truthFilterMET < 200))&&(mcID != 407345 || (truthFilterMET >= 200 && truthFilterMET < 300))&&(mcID != 407346 || (truthFilterMET >= 300 && truthFilterMET < 400))&&(mcID != 407347 || truthFilterMET > 400) )*"

    issingleTopOK = "( (year==2018) ||(((mcID != 407019 || truthFilterMET >=200)&&(mcID != 407021 || truthFilterMET >=200))&&((mcID >410647 ||mcID <410644) || truthFilterMET<200)&&(mcID!=410658 || mcID!=410659 || truthFilterMET<200)) )*"

    
    ymax = 800000
    doLog = False


    # Change this to put the output directory somewhere else
    directory = options.date+'/'
    print ("Output Directory is: ", directory)
    #############################
    label = "preSelection_SR_3Jets_ISR100"
    #############################
    EventCounter = True

    preCuts = cleaningCuts+isttbarOK+issingleTopOK

    
    preSelection_Wh_Liv = "(pTl1>27)*(nLeptons==1)*(nBJets==2)*(nJets<4)*(ETMiss>200)*(m_T>100)*(m_bb>50)*"
    # Preliminary Sbottom Multi B regions here:
    # Change the "cutstouse" variable to produce different distributions for a given selection. If plotting a SR distribution,
    # make sure that SR is contained in the label variable, which will blind the distribution
    if label == "noSelection_SR_MET100":
        cutstouse = preCuts
    elif label == "preSelection_SR_3Jets_ISR100":
        cutstouse = preCuts+"(nJets==3)*(ETMiss>100)*(nBJets==2)*(nLeptons==1)*(pTl1>27)*(pTj1>pTb1)*(pTj1>100)"
    elif label ==  "Matts_presel":
        cutstouse = "ETMiss>110 && m_T>110 && nBJets ==2 && nLeptons==1"
        #1L + 2 b-jets + MET > 110 + mT > 110
    elif label == "ISR":
        cutstouse = "(nLeptons==1)*(nBJets==2)*(ETMiss>200)*(nJets==3)"
    elif label == "nonISR":
        cutstouse = preCuts+"(nLeptons==1)*(nBJets==2)*(nJets==3)*(m_bb>100 && m_bb<140)*(m_T>100)*(ETMiss>240)"
        
    elif label == "compressedSR":
        cutstouse = preCuts+"(400_250_Nominal_nominal_class2>0.99)*(400_250_Nominal_nominal_class2<1)*(metsig_New>8)"#*(dRb1b2<2)
    elif label == "compressedFitSR":
        #cutstouse = preCuts+"(400_250_Nominal_nominal_class2>0.99)*(400_250_Nominal_nominal_class2<1)"#*(dRb1b2<2)
        cutstouse = preCuts+"(ETMiss>100)*(nBJets==2)*(nLeptons==1)*(nJets<4)"#*(dRb1b2<2)

    elif label == "CRSpace":
        cutstouse = preCuts+"(400_250_Nominal_nominal_class2>0.5)*(nJet25==2)*(400_250_Nominal_nominal_class2<0.8)*(metsig_New>8)"#*(dRb1b2<2)
    elif label == "VRSpace_SR":
        cutstouse = preCuts+"(400_250_Nominal_nominal_class2>0.8)*(nJet25==2)*(400_250_Nominal_nominal_class2<0.0.97)*(metsig_New>8)"#*(dRb1b2<2)

    elif label == "ttbarCR":
        cutstouse = preCuts+"(400_250_Nominal_nominal_class2>0.6 && 400_250_Nominal_nominal_class2<0.8)*(400_250_Nominal_nominal_class3<0.1)*(nJet25==2)*(metsig_New>8)*(400_250_Nominal_nominal_class0>0.3)*(400_250_Nominal_nominal_class1<0.15)"
    elif label == "singleTopCR":
        cutstouse = preCuts+"(400_250_Nominal_nominal_class2>0.5)*(400_250_Nominal_nominal_class2<0.8)*(400_250_Nominal_nominal_class3<0.1)*(nJet25==2)*(metsig_New>8)*(400_250_Nominal_nominal_class0>0)*(400_250_Nominal_nominal_class1>0.13)*(mt>90)"# 
    elif label == "wJetsCR":
        cutstouse = preCuts+"(400_250_Nominal_nominal_class2>0.5)*(400_250_Nominal_nominal_class2<0.8)*(nJet25==2)*(metsig_New>8)*(400_250_Nominal_nominal_class3>0.12)"# 



    elif label =="SRLM":
        cutstouse = preCuts+"(nLeptons==1)*(nBJets==2)*(m_bb>100 && m_bb<140)*(nJets<4)*(ETMiss>240)*(m_T>100 && m_T<160)*(m_CTcorr>180 && m_CTcorr<230)"
    elif label == "SRCutflow":
        cutstouse = preCuts+"(nBaselineLeptons==1)*(nLeptons==1)*(nJets ==2 || nJets ==3)*(ETMiss>200)*(m_T>50)*(nBJets==2)*(m_bb>50)*(m_bb>100 && m_bb<140)*(m_CTcorr>180)*(ETMiss>240)*(m_T>100)"
        


    elif label == "monotop_preSelection":
        cutstouse = preCuts+"(nLeptons==1)*(nBJets>=1)"
    elif label == "monotop_cutflow":
        #cutstouse = "passedMETTrigger==1"
        cutstouse = "(ETMiss>=100)*(nLeptons==1)*(pTl1>27)*(nJets>=2)*(nBJets>=1)*(pTb1>40)*(pTb2>25)*(pTj1>50)*(pTj2>40)*(minDPhijMET_4>0.4)*(m_T>120)"


    elif label == "SRB":
        cutstouse = "(passMETtriggers)*(nbaselineLep==0)*(nj_good>=4)*(num_bjets>=4)*(eT_miss_orig>350)*(dphimin4_orig>0.4)*(SRB3_mbb_avg>75 && SRB3_mbb_avg<175)*(!leadb1)*(pT_1jet>350)*(fabs(dPhi_1jet)>2.8) *(meff>1000)*(passtauveto==1)"
                    #(passMETtriggers)*(nbaselineLep==0)*(nj_good>=5)*(num_bjets>=4)*(eT_miss>350)*(dphimin4_orig>0.4)*(SRB3_mbb_avg>75 && SRB3_mbb_avg<175)*(!leadb1)*(pT_1jet>350)*(fabs(dPhi_1jet)>2.8)*(meff>1000)*(passtauveto==1)
    elif label == "SRA_incl":
        cutstouse = "(passMETtriggers)*(nbaselineLep==0)*(nj_good>=6)*(num_bjets>=4)*(eT_miss_orig>350)*(dphimin4_orig>0.4)*(pT_1bjet>200)*(maxDRbb>2.5)*(maxminDRbb<2.5)*( maxminDRmbb>80)*(meff>1000)*(passtauveto==1)"
    elif label == "SRA_L":
        cutstouse = "(passMETtriggers)*(nbaselineLep==0)*(nj_good>=6)*(num_bjets>=4)*(eT_miss_orig>350)*(dphimin4_orig>0.4)*( pT_1bjet>200)*(maxDRbb>2.5)*(maxminDRbb<2.5)*( maxminDRmbb>80)*(meff>1000)*(meff<1500)*(passtauveto==1)"
    elif label == "SRA_M":
        cutstouse = "(passMETtriggers)*(nbaselineLep==0)*(nj_good>=6)*(num_bjets>=4)*(eT_miss_orig>350)*(dphimin4_orig>0.4)*( pT_1bjet>200)*(maxDRbb>2.5)*(maxminDRbb<2.5)*( maxminDRmbb>80)*(meff>1500)*(meff<2000)*(passtauveto==1)"
    elif label == "SRA_H":
        cutstouse = "(passMETtriggers)*(nbaselineLep==0)*(nj_good>=6)*(num_bjets>=4)*(eT_miss_orig>350)*(dphimin4_orig>0.4)*( pT_1bjet>200)*(maxDRbb>2.5)*(maxminDRbb<2.5)*( maxminDRmbb>80)*(meff>2000)*(passtauveto==1)"
    elif label == "SRC_incl":
        cutstouse = "((passMETtriggers==1)*(nbaselineLep==0)*(dphimin4_orig>0.4)*(nj_good>=4)*(num_bjets>=3)*(eT_miss_orig>250)*(metsigHT>18.4))"
    elif label == "SRC_22":
        cutstouse = "((passMETtriggers==1)*(nbaselineLep==0)*(dphimin4_orig>0.4)*(nj_good>=4)*(num_bjets>=3)*(eT_miss_orig>250)*(metsigHT>18.4)*(metsigHT<21.0))"
    elif label == "SRC_24":
        cutstouse = "((passMETtriggers==1)*(nbaselineLep==0)*(dphimin4_orig>0.4)*(nj_good>=4)*(num_bjets>=3)*(eT_miss_orig>250)*(metsigHT>21)*(metsigHT<23.55))"
    elif label == "SRC_26":
        cutstouse = "((passMETtriggers==1)*(nbaselineLep==0)*(dphimin4_orig>0.4)*(nj_good>=4)*(num_bjets>=3)*(eT_miss_orig>250)*(metsigHT>23.55)*(metsigHT<26.1))"
    elif label == "SRC_28":
        cutstouse = "((passMETtriggers==1)*(nbaselineLep==0)*(dphimin4_orig>0.4)*(nj_good>=4)*(num_bjets>=3)*(eT_miss_orig>250)*(metsigHT>26.1))"

    
    else:
        print ("Error Wrong label try again. ")
        return 1

    gROOT.SetStyle("ATLAS")
    gROOT.SetBatch()
    plottinglist = []

    if options.doRatio:




        # This uses the ratio plotting class, to produce a ratio plot of whatever variable you give as the first argument. The second argument is the latex which will be drawn on the x-axis. 3rd is the xlow, 4th is xhigh and 5th is the rebinning value. The rest you shouldn't need to change and instead should just copy from an existing usage of the function


        ##Signal Only plots
        #RatioPlot.RatioPlot("m_bb", "m_{bb}", 0, 600, 30, ymax, cutstouse, directory, label, True, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False,False)
        RatioPlot.RatioPlot("ETMiss", "E_{T}^{miss}", 0, 1000, 20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False,False)
        RatioPlot.RatioPlot("pTj1", "p_{T}^{j1}", 0, 600, 20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False,False)
        # #RatioPlot.RatioPlot("amT2", "amT_{2}", 0, 600, 15, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        #RatioPlot.RatioPlot("(pTb1 < pTj1)", "leading jet is non-b", -0.5, 1.5, 2, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        RatioPlot.RatioPlot("dRb1b2", "#DeltaR(b_{1},b_{2})", 0, 4, 20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        RatioPlot.RatioPlot("fabs(TVector2::Phi_mpi_pi(fabs(phib1-phib2)))", "#Delta#Phi(b_{1},b_{2})", 0, 4, 20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        RatioPlot.RatioPlot("fabs(TVector2::Phi_mpi_pi(fabs(phib1-ETMissPhi)))", "#Delta#Phi(b_{1},E_{T}^{Miss})", 0, 4, 20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        RatioPlot.RatioPlot("fabs(TVector2::Phi_mpi_pi(fabs(phib2-ETMissPhi)))", "#Delta#Phi(b_{2},E_{T}^{Miss})", 0, 4, 20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        RatioPlot.RatioPlot("fabs(TVector2::Phi_mpi_pi(fabs(phil1-ETMissPhi)))", "#Delta#Phi(l_{1},E_{T}^{Miss})", 0, 4, 20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        # RatioPlot.RatioPlot("metsig_New", "Obj-based Metsig", 0, 20, 20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False,False)
        RatioPlot.RatioPlot("pTl1", "leading lepton pT", 0, 400, 20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        #RatioPlot.RatioPlot("nJets", "N_{jets}", -0.5, 9.5, 10, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False,False)

        #RatioPlot.RatioPlot("truthFilterMET", "E_{T}^{miss} TruthFilter", 0, 600, 12, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False,False)
        #RatioPlot.RatioPlot("nTruthElectronsBeforeOR", "NElectrons_{truth}", -0.5, 3.5, 4, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False,False)
        #RatioPlot.RatioPlot("nTruthMuonsBeforeOR+nTruthElectronsBeforeOR", "NLep_{truth}", -0.5, 3.5, 4, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False,False)
        #RatioPlot.RatioPlot("nTruthMuonsBeforeOR", "NMuonsd_{truth}", -0.5, 3.5, 4, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False,False)
        #RatioPlot.RatioPlot("nTruthTausBeforeOR", "NTaus_{truth}", -0.5, 3.5, 4, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False,False)
        # RatioPlot.RatioPlot("m_CTcorr", "m_{CT}Corrected", 0, 300, 20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        # RatioPlot.RatioPlot("m_T", "m_{T}", 0, 600, 15, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)

         

        #Proper Ratio plots
        #RatioPlot.RatioPlot("1", "cuts", 0.5, 1.5, 1, ymax, cutstouse, directory, label, True, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, True, False, luminosity_liv, False, False)

        #RatioPlot.RatioPlot("fabs(TVector2::Phi_mpi_pi(fabs(phib1-phib2)))", "#Delta#Phi(b_{1},b_{2})", 0, 4, 20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        # RatioPlot.RatioPlot("1/400_250_Nominal_nominal_class2", "XGB_nominal Signal response", 1, 1.5, 50, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        # RatioPlot.RatioPlot("1/400_250_Nominal_nominal_class1", "XGB_nominal singleTop response", 1, 100, 50, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        # RatioPlot.RatioPlot("1/400_250_Nominal_nominal_class0", "XGB_nominal ttbar response", 1, 100, 50, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        # RatioPlot.RatioPlot("1/400_250_Nominal_nominal_class3", "XGB_nominal wJets response", 1, 100, 50, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)


        #RatioPlot.RatioPlot("400_250_Nominal_nominal_class1", "XGB_nominal singleTop response", 0.0, 1, 50, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        #RatioPlot.RatioPlot("400_250_Nominal_nominal_class0", "XGB_nominal ttbar response", 0.0, 1, 50, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        #RatioPlot.RatioPlot("400_250_Nominal_nominal_class3", "XGB_nominal wJets response", 0.0, 1, 50, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        #RatioPlot.RatioPlot("mbb", "m_{bb}", 80, 160, 16, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        # #RatioPlot.RatioPlot("metsig_SumHT", "E_{T}^{miss}/#sqrt(HT)", 0, 20, 20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        #RatioPlot.RatioPlot("metsig_SumET", "E_{T}^{miss}/#sqrt(E_{T}^{miss})", 0, 20, 20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        # #RatioPlot.RatioPlot("all_metsig", "all_metsig", 0, 20, 20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        # #RatioPlot.RatioPlot("all_Meff", "m_{eff}", 0, 1000, 50, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        #RatioPlot.RatioPlot("met", "E_{T}^{miss}", 100, 800, 20, ymax, cutstouse, directory, label, True, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        # RatioPlot.RatioPlot("truthFilterMET", "E_{T}^{miss} truth filter", 0, 800, 40, ymax, cutstouse, directory, label, True, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        # # # RatioPlot.RatioPlot("all_Meff", "m_{Effective}", 0, 1000, 20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        #RatioPlot.RatioPlot("m_CTcorr", "m_{CT}Corrected", 0, 500, 15, ymax, cutstouse, directory, label, True, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        #RatioPlot.RatioPlot("mt", "m_{T}", 0, 600, 15, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        #RatioPlot.RatioPlot("dRb1b2", "#DeltaR(b_{1},b_{2})", 0, 4, 20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        #RatioPlot.RatioPlot("nJet25", "N_{jets}", -0.5, 9.5, 10, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False,False)

        #RatioPlot.RatioPlot("mlb1", "m_{bl1}", 0, 600, 15, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        #RatioPlot.RatioPlot("mlb2", "m_{bl2}", 0, 600, 15, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        #RatioPlot.RatioPlot("lep1Pt", "p_{T}^{l1}", 0, 400, 20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        #RatioPlot.RatioPlot("bjet1Pt", "p_{T}^{b1}", 0, 600, 30, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        #RatioPlot.RatioPlot("bjet2Pt", "p_{T}^{b2}", 0, 600, 30, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        #RatioPlot.RatioPlot("dRL1b1", "#Delta R(l1b1)", 0, 1000, 50, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        #RatioPlot.RatioPlot("dRL1b2", "#Delta R(l1b2)", 0, 4, 20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        # RatioPlot.RatioPlot("etal1", "#eta_{l1}", -4, 4, 20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        # RatioPlot.RatioPlot("etab1", "#eta_{b1}", -4, 4, 20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        # RatioPlot.RatioPlot("etab2", "#eta_{b2}", -4, 4, 20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        # RatioPlot.RatioPlot("phib2", "#phi_{b2}", -4, 4, 20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        # RatioPlot.RatioPlot("phib1", "#phi_{b1}", -4, 4, 20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        # RatioPlot.RatioPlot("phil1", "#phi_{l1}", -4, 4, 20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)

#ML variable plots
        # RatioPlot.RatioPlot("400_250_Nominal_nominal_class2", "XGB_nominal Signal response", 0.95, 1, 5, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        # #RatioPlot.RatioPlot("nBJet25_MV2c10", "N_{b-jets}", -0.5, 3.5, 4, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, True,True)
        # #RatioPlot.RatioPlot("nLep_signal", "N_{sig leptons}", -0.5, 3.5,4, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, True,True)
        # RatioPlot.RatioPlot("nJet25", "N_{jets}", -0.5, 9.5, 10, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False,False)
        # RatioPlot.RatioPlot("mbb", "m_{bb}", 0, 300, 30, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False,False)
        # RatioPlot.RatioPlot("metsig_New", "Object-based METsig", 0, 22, 11, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)        
        # RatioPlot.RatioPlot("met", "E_{T}^{miss}", 0, 600, 24, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        # RatioPlot.RatioPlot("m_CTcorr", "m_{CT}", 0, 400, 20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, True, True)
        # RatioPlot.RatioPlot("mt", "m_{T}", 0, 600, 15, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, False, False)
        #RatioPlot.RatioPlot("dRb1b2", "#DeltaR(b_{1},b_{2})", 0, 4, 10, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, True,True)
        # RatioPlot.RatioPlot("fabs(TVector2::Phi_mpi_pi(fabs(phib1-phib2)))", "#Delta#Phi(b_{1},b_{2})", 0, 4, 10, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, True,True)
        # RatioPlot.RatioPlot(" mlb1", "m_{bl1}", 0, 600, 15, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, True,True)
        # RatioPlot.RatioPlot(" mlb2", "m_{bl2}", 0, 600, 15, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, True,True)
        # RatioPlot.RatioPlot("lep1Pt", "p_{T}^{l1}", 0, 400, 10, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, True,True)
        #RatioPlot.RatioPlot("bjet1Pt", "p_{T}^{b1}", 0, 400, 20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, True,True)
        #RatioPlot.RatioPlot("bjet2Pt", "p_{T}^{b2}", 0, 400, 20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, True,True)
        #RatioPlot.RatioPlot("dRL1b1", "#Delta R(l1b1)", 0, 1000, 50, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, True,True)
        #RatioPlot.RatioPlot("dRL1b2", "#Delta R(l1b2)", 0, 4, 20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, True,True)
        # RatioPlot.RatioPlot("etaL1", "#eta_{l1}", -4, 4, 40, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, True,True)
        # RatioPlot.RatioPlot("etab1", "#eta_{b1}", -4, 4, 40, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, True,True)
        # RatioPlot.RatioPlot("etab2", "#eta_{b2}", -4, 4, 40, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, True,True)
        # RatioPlot.RatioPlot("phib2", "#phi_{b2}", -4, 4, 10, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, True,True)
        # RatioPlot.RatioPlot("phib1", "#phi_{b1}", -4, 4, 10, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, True,True)
        # RatioPlot.RatioPlot("phiL1", "#phi_{l1}", -4, 4, 10, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFiles, False, False, luminosity_liv, True,True)




##Correlations
        weight="eventWeight*"
        cutstouse=weight+cutstouse
    if options.doCorr:
        
        
        inFile1 = signalFiles[0]#Truth
        inFile2 = signalFiles[1]#TruthSmeared
        inFile3 = signalFiles[2]#TruthSmeared_EtaPhiP
        inFile4 = signalFiles[3]#Reco
        

        #Looking at b-tag weights
        #inFile1 = "/user/hteagle/AnalysisDirectory/Rel21/Base.21.2.31/run/running/ttbar/data-output/mc16_13TeV.396716.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hbb_300p0_150p0_lep.deriv.DAOD_SUSY5.e6972_a875_r9364_p3736.root"
        #inFile2 = "/user/hteagle/AnalysisDirectory/Rel21/Base.21.2.31/run/running/ttbar/data-output/mc16_13TeV.396716.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hbb_300p0_150p0_lep.deriv.DAOD_SUSY5.e6972_a875_r9364_p3736.root"
        #CorrelationPlot.CorrelationPlot("b1MV2wgt","etab1","b1tag score", "#etab1", 0, 1, 20, -4, 4, 20, cutstouse, directory, label, inFile1, inFile2)
        

        #CorrelationPlot.CorrelationPlot("etaL1","phiL1","#etaL1", "#phiL1", -4, 4, 20, -4, 4, 20, cutstouse, directory, label, inFile1, inFile2, inFile3)
        #CorrelationPlot.CorrelationPlot("phib1","phiL1","#phib1", "#phil1", -4, 4, 20, -4, 4, 20, cutstouse, directory, label, inFile1, inFile2, inFile3)
        #CorrelationPlot.CorrelationPlot("phib2","phiL1","#phib2", "#phil1", -4, 4, 20, -4, 4, 20, cutstouse, directory, label, inFile1, inFile2, inFile3)
        #CorrelationPlot.CorrelationPlot("phib1","phib2","#phib1", "#phib2", -4, 4, 20, -4, 4, 20, cutstouse, directory, label, inFile1, inFile2, inFile3)
        #CorrelationPlot.CorrelationPlot("bjet1Pt","mct","pT^{b1}", "m_{CT}", 0, 300, 30, 0, 300, 30, cutstouse, directory, label, inFile1, inFile2, inFile3)
        #CorrelationPlot.CorrelationPlot("bjet2Pt","mct","pT^{b2}", "m_{CT}", 0, 300, 30, 0, 300, 30, cutstouse, directory, label, inFile1, inFile2, inFile3)
        #CorrelationPlot.CorrelationPlot("bjet1Pt","bjet2Pt","pT^{b1}", "pT^{b2}", 0, 300, 30, 0, 300, 30, cutstouse, directory, label, inFile1, inFile2, inFile3)
        #CorrelationPlot.CorrelationPlot("bjet1Pt","lep1Pt","pT^{b1}", "pT^{L1}", 0, 300, 30, 0, 300, 30, cutstouse, directory, label, inFile1, inFile2, inFile3)
        #CorrelationPlot.CorrelationPlot("bjet2Pt","lep1Pt","pT^{b2}", "pT^{L1}", 0, 300, 30, 0, 300, 30, cutstouse, directory, label, inFile1, inFile2, inFile3)
        #CorrelationPlot.CorrelationPlot("mct","dRb1b2","m_{CT}", "#DeltaR_{b1,b2}", 0, 300, 30, 0, 6, 30, cutstouse, directory, label, inFile1, inFile2, inFile3)
        #CorrelationPlot.CorrelationPlot("mct","fabs(TVector2::Phi_mpi_pi(fabs(phib1-phib2)))","m_{CT}", "#Delta#Phi{b1,b2}", 0, 300, 20, 0, 4, 20, cutstouse, directory, label, inFile1, inFile2, inFile3)
        #CorrelationPlot.CorrelationPlot("phib1","phib2","#Phi{b1}", "#Phi{b2}", 0, 300, 20, 0, 4, 20, cutstouse, directory, label, inFile1, inFile2, inFile3)
        #CorrelationPlot.CorrelationPlot("m_CTcorr","fabs(etab1-etab2)","m_{CT}", "#Delta#eta{b1,b2}", 0, 300, 30, 0, 6, 30, cutstouse, directory, label, inFile1, inFile2, inFile3)



##Linear correlation plots
        ## pTs
        #CorrelationPlot.LinCorrelationPlot("bjet1Pt","bjet2Pt","pT^{b1}", "pT^{b2}", 0, 300, 30, 0, 300, 30, cutstouse, directory, label, inFile1, inFile2, inFile3, inFile4)
        #CorrelationPlot.LinCorrelationPlot("bjet1Pt","lep1Pt","pT^{b1}", "pT^{l1}", 0, 300, 30, 0, 300, 20, cutstouse, directory, label, inFile1, inFile2, inFile3, inFile4)
        # CorrelationPlot.LinCorrelationPlot("bjet2Pt","lep1Pt","pT^{b2}", "pT^{l1}", 0, 300, 30, 0, 300, 30, cutstouse, directory, label, inFile1, inFile2, inFile3, inFile4)
        
        ##mCTs
        CorrelationPlot.LinCorrelationPlot("bjet1Pt","m_CTcorr","pT^{b1}", "m_{CT}", 0, 300, 30, 0, 300, 30, cutstouse, directory, label, inFile1, inFile2, inFile3, inFile4)
        #CorrelationPlot.LinCorrelationPlot("bjet2Pt","m_CTcorr","pT^{b2}", "m_{CT}", 0, 300, 30, 0, 300, 30, cutstouse, directory, label, inFile1, inFile2, inFile3, inFile4)
        #CorrelationPlot.LinCorrelationPlot("lep1Pt","m_CTcorr","pT^{l1}", "m_{CT}", 0, 300, 30, 0, 300, 30, cutstouse, directory, label, inFile1, inFile2, inFile3, inFile4)
        #CorrelationPlot.LinCorrelationPlot("dRb1b2","m_CTcorr","#DeltaR_{b1,b2}", "m_{CT}", 0, 4, 30, 0, 300, 30, cutstouse, directory, label, inFile1, inFile2, inFile3, inFile4)
        #CorrelationPlot.LinCorrelationPlot("metphi","m_CTcorr","#Phi_{MET}", "m_{CT}", 0, 300, 30, 0, 300, 30, cutstouse, directory, label, inFile1, inFile2, inFile3, inFile4)
        
        #CorrelationPlot.LinCorrelationPlot("phib1","metphi","#phi^{b1}", "#phi^{MET}", 0, 4, 20, 0, 4, 20, cutstouse, directory, label, inFile1, inFile2, inFile3, inFile4)
        #CorrelationPlot.LinCorrelationPlot("phib2","metphi","#phi^{b2}", "#phi^{MET}", 0, 4, 20, 0, 4, 20, cutstouse, directory, label, inFile1, inFile2, inFile3, inFile4)
        #CorrelationPlot.LinCorrelationPlot("phib1","phib2","#phi^{b1}", "#phi^{b2}", 0, 4, 20, 0, 4, 20, cutstouse, directory, label, inFile1, inFile2, inFile3, inFile4)

        
        # CorrelationPlot.LinCorrelationPlot("bjet1Pt","mt","pT^{b1}", "m_{T}", 0, 300, 30, 0, 300, 30, cutstouse, directory, label, inFile1, inFile2, inFile3, inFile4)
        # CorrelationPlot.LinCorrelationPlot("bjet2Pt","mt","pT^{b2}", "m_{T}", 0, 300, 30, 0, 300, 30, cutstouse, directory, label, inFile1, inFile2, inFile3, inFile4)
        # CorrelationPlot.LinCorrelationPlot("lep1Pt","mt","pT^{l1}", "m_{T}", 0, 300, 30, 0, 300, 30, cutstouse, directory, label, inFile1, inFile2, inFile3, inFile4)

        # CorrelationPlot.LinCorrelationPlot("bjet1Pt","met","pT^{b1}", "E_T^{miss}", 0, 300, 30, 0, 300, 30, cutstouse, directory, label, inFile1, inFile2, inFile3, inFile4)
        # CorrelationPlot.LinCorrelationPlot("bjet2Pt","met","pT^{b2}", "E_T^{miss}", 0, 300, 30, 0, 300, 30, cutstouse, directory, label, inFile1, inFile2, inFile3, inFile4)
        # CorrelationPlot.LinCorrelationPlot("lep1Pt","met","pT^{l1}", "E_T^{miss}", 0, 300, 30, 0, 300, 30, cutstouse, directory, label, inFile1, inFile2, inFile3, inFile4)

        # CorrelationPlot.LinCorrelationPlot("bjet1Pt","mlb1","pT^{b1}", "m(l,b_1)", 0, 300, 30, 0, 300, 30, cutstouse, directory, label, inFile1, inFile2, inFile3, inFile4)
        # CorrelationPlot.LinCorrelationPlot("bjet2Pt","mlb1","pT^{b2}", "m(l,b_1)", 0, 300, 30, 0, 300, 30, cutstouse, directory, label, inFile1, inFile2, inFile3, inFile4)
        # CorrelationPlot.LinCorrelationPlot("lep1Pt","mlb1","pT^{l1}", "m(l,b_1)", 0, 300, 30, 0, 300, 30, cutstouse, directory, label, inFile1, inFile2, inFile3, inFile4)

        # CorrelationPlot.LinCorrelationPlot("bjet1Pt","mlb2","pT^{b1}", "m(l,b_2)", 0, 300, 30, 0, 300, 30, cutstouse, directory, label, inFile1, inFile2, inFile3, inFile4)
        # CorrelationPlot.LinCorrelationPlot("bjet2Pt","mlb2","pT^{b2}", "m(l,b_2)", 0, 300, 30, 0, 300, 30, cutstouse, directory, label, inFile1, inFile2, inFile3, inFile4)
        # CorrelationPlot.LinCorrelationPlot("lep1Pt","mlb2","pT^{l1}", "m(l,b_2)", 0, 300, 30, 0, 300, 30, cutstouse, directory, label, inFile1, inFile2, inFile3, inFile4)

        # CorrelationPlot.LinCorrelationPlot("bjet1Pt","dRb1b2","pT^{b1}", "#DeltaR(b_1,b_2)", 0, 300, 30, 0, 300, 30, cutstouse, directory, label, inFile1, inFile2, inFile3, inFile4)
        # CorrelationPlot.LinCorrelationPlot("bjet2Pt","dRb1b2","pT^{b2}", "#DeltaR(b_1,b_2)", 0, 300, 30, 0, 300, 30, cutstouse, directory, label, inFile1, inFile2, inFile3, inFile4)
        # CorrelationPlot.LinCorrelationPlot("lep1Pt","dRb1b2","pT^{l1}", "#DeltaR(b_1,b_2)", 0, 300, 30, 0, 300, 30, cutstouse, directory, label, inFile1, inFile2, inFile3, inFile4)


#ShapePlots
    if options.doShape:
        ShapePlot.ShapePlot2("m_CT", "m_{CT}", 0, 1000, 50, 100000, cutstouse, directory, label, inputstringShape1,inputstringShape2, False, False, False)
        ShapePlot.ShapePlot2("m_T", "m_{T}", 0, 1000, 50, 100000, cutstouse, directory, label, inputstringShape1,inputstringShape2, False, False, False)



    if options.doCutflow:
        print ("Going to do cutflow")
        ##untrimmed                                                          submitdir_ttbarCheck/data-output/DAOD_SUSY5.root
        #signalFile = '/user/hteagle/AnalysisDirectory/Rel21/Base.21.2.67/run/submitdir_ttbarCheck/data-output/DAOD_SUSY5.root'
        Cutflow.Cutflow(label, cutstouse, signalFile, luminosity_liv)

#TurnOn Curves
    if options.doTurnOn:
        print("Going to do turn on curves")
        turnOnInfiles= []
        # variable = 'pTl1'
        variable = 'ETMiss'
        trigger = 'triggerDecisions[37]'# MET 2018 
        #trigger = '((triggerDecisions[10] ||triggerDecisions[13] || triggerDecisions[15])||(triggerDecisions[20] || triggerDecisions[21]))'#2016/17/18 -1L
        year = '2018'
        turnOnInfiles.append("/user/hteagle/AnalysisDirectory/Rel21/Base.21.2.31/run/running/data18/data-output/data18_13TeV.periodB.physics_Main.PhysCont.DAOD_SUSY18.grp18_v01_p3704.root")
        #turnOnInfiles.append("/user/hteagle/AnalysisDirectory/Rel21/Base.21.2.31/run/running/ttbar/data-output/mc16_13TeV.410470.PhPy8EG_A14_ttbar_hdamp258p75_nonallhad.deriv.DAOD_SUSY1.e6337_s3126_r10724_p3756.root")
        for infile in turnOnInfiles:
            TurnOn.TurnOn(infile, trigger, variable, year, options.date)

#Significances
    if options.doSignif:
        print ("Going to do Significance")

        directory = "/hepstore/hteagle/Wh/ntuples_simpleAnalysis/SbMB/dm130/"
        directory_reco = "/scratch/hteagle/SbMB/dm130/"


        bkgFile = directory+"410470.root"
        signalFiles = []
        reco_signalFiles = []

        for files  in os.listdir(directory):
            if files.find(".root")!=-1:
                signalFiles.append(files)

        for reco_files  in os.listdir(directory_reco):
            if reco_files.find(".root")!=-1:
                reco_signalFiles.append(reco_files)


        Significance.Significance(cutstouse,luminosity_Shef ,signalFiles, reco_signalFiles, bkgFile, label, False, False, True, False, False, directory_reco, directory)


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
