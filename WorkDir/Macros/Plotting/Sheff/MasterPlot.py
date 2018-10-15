#!/usr/bin/env python

import os,sys,subprocess,datetime,copy,math,array,shutil,ROOT,string, CorrelationPlot, time, ShapePlot, RatioPlot
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
    parser.add_option("-r", "--ratio", action="store_true", dest="doRatio", help="do Ratio plots?", default=False)
    parser.add_option("-c", "--correlation", action="store_true", dest="doCorr", help="do Correlation plots?", default=False)
    parser.add_option("-s", "--shape", action="store_true", dest="doShape", help="do Shape plots?", default=False)
    parser.add_option("-d", "--date", action="store", type="string", dest="date", help="date for directory structure", default=date)
    (options, args) = parser.parse_args()    
    print "Arguments " , str(sys.argv)    
    

    if not (options.doCorr or options.doRatio or options.doShape):
        print "Ran without any options. Produced nothing. Good work"
        return 0

    DiJetFile = "/hepstore/hteagle/Ntuples_12_06/DiJet.root"
    ttVFile = "/hepstore/hteagle/Ntuples_12_06/ttV.root"
    wJetFile = "/hepstore/hteagle/Ntuples_12_06/WJets.root"
    zJetFile = "/hepstore/hteagle/Ntuples_12_06/ZJets.root"
    ttbarFile = "/hepstore/hteagle/Ntuples_12_06/ttbar.root"
    singleTopFile = "/hepstore/hteagle/Ntuples_12_06/singleTop.root"
    DiBosonFile = "/hepstore/hteagle/Ntuples_12_06/DiBoson.root"
    HiggsFile = "/hepstore/hteagle/Ntuples_12_06/Higgs.root" 
    
    #Add new data file when finished
    #dataFile = "/scratch/janders/tempSbottom/MultiB_13Oct/Data.root"
    dataFile = "/hepstore/hteagle/Ntuples_12_06/Data.root"
    # Edit the file below to use a different signal file
    #signalFile = "/hepstore/hteagle/Ntuples_12_06/MonteCarlo/mc16_13TeV.390284.MGPy8EG_A14N23LO_BB_onestepN2hN1_700_580_450.e5671_e5984_a875_r9364_r9315_p3404_sbottom_multib_fixed.root"
    #signalFile = "/hepstore/hteagle/Ntuples_12_06/MonteCarlo/mc16_13TeV.390303.MGPy8EG_A14N23LO_BB_onestepN2hN1_900_330_200.e5671_e5984_a875_r9364_r9315_p3404_sbottom_multib_fixed.root"
    #signalFile = "/hepstore/hteagle/Ntuples_12_06/MonteCarlo/mc16_13TeV.390285.MGPy8EG_A14N23LO_BB_onestepN2hN1_700_680_550.e5671_e5984_a875_r9364_r9315_p3404_sbottom_multib_fixed.root "
    signalFile = "/hepstore/hteagle/Ntuples_12_06/MonteCarlo/mc16_13TeV.390219.MGPy8EG_A14N23LO_BB_onestepN2hN1_800_795_60.e5671_e5984_a875_r9364_r9315_p3404_sbottom_multib_fixed.root"
    #signalFile = "/hepstore/hteagle/Ntuples_12_06/MonteCarlo/mc16_13TeV.390251.MGPy8EG_A14N23LO_BB_onestepN2hN1_500_380_250.e5671_e5984_a875_r9364_r9315_p3404_sbottom_multib_fixed.root"
    
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
    
    # these can be ignored
    inputstringShape1 = "/scratch/janders/tempSbottom/Sbottom2017Final/ttbar.root"
    inputstringShape2  = "/scratch/janders/tempSbottom/Sbottom2017Final/Sherpa_ttbar.root"


#     pass0LSelection = 1
#     pass1LSelection = 0


    cutstouse = ""
    ZeroLPreselection = "(eT_miss_orig>250 && num_bjets>=2 && nj_good>=4 &&  nbaselineLep==0 && pT_1bjet >100 && (dphimin4_orig>0.4) && passMETtriggers)"
    OneLPreselection = "(eT_miss_orig>250 && num_bjets>=3 && nj_good>=4 && pT_1bjet >100 && (nEl==1||nMu==1)&&  pT_1lep>20 && passMETtriggers)*"
    OneLSRBPreselection = "(eT_miss_orig>250 && num_bjets>=3 && nj_good>=4 && (nEl==1||nMu==1)&&  pT_1lep>20 && passMETtriggers)*"
    preselection = "(nbaselineLep == 0 && nj_good >= 4 && pT_1bjet > 100 && num_bjets >= 3 && eT_miss_orig > 250 && dphimin4_orig > 0.4 && passMETtriggers) *"
    preselection_4b = "(nbaselineLep == 0 && nj_good >= 4 && pT_1bjet > 100 && num_bjets >= 4 && eT_miss_orig > 250 && dphimin4_orig > 0.4 && passMETtriggers)*"


    ymax = 800000
    doLog = False


    # Change this to put the output directory somewhere else
    directory = options.date+"_SbottomMultib_Preliminary/"+foundSignalInput
    print "Output Directory is: ", directory
    label = "noSelection"
    #label = "Diagonal_Test"
    EventCounter = True

    # Preliminary Sbottom Multi B regions here:
    # Change the "cutstouse" variable to produce different distributions for a given selection. If plotting a SR distribution, 
    # make sure that SR is contained in the label variable, which will blind the distribution
    if label == "preselection":
        cutstouse =preselection+"1"

    elif label =="noSelection":
        cutstouse = "1" 
    
    elif label == "ZeroLPreselection":
        cutstouse = ZeroLPreselection

    elif label == "OneLPreselection":
        cutstouse = OneLPreselection

    elif label == "VRA":
        cutstouse = "(eT_miss_orig>250 && num_bjets==3 && nj_good>=6 &&  nbaselineLep==0 && pT_1bjet >200 && (dphimin4_orig>0.4) && passMETtriggers && passtauveto && meff>1000)"

    elif label == "CRA":
        cutstouse = cutstouse+"(eT_miss_orig>250 && num_bjets>=4 && nj_good>=6 && pT_1bjet >100 && (nEl==1||nMu==1)&&  pT_1lep>27 && meff>1000 && dphimin4_orig > 0.4)"

    elif label == "CRB_N-1_leadb":
        cutstouse = OneLSRBPreselection+ "(nj_good>=5 && num_bjets>=4 && meff>1000 && leadb1==1 && (pT_1bjet==pT_1jet) && pT_1jet>300 && passtauveto )"

    elif label == "CRB_N-1_nonleadb_20_N-1":
        cutstouse = OneLSRBPreselection+"( num_bjets>=4 &&  nj_good>=4 && meff>1000 && leadb1==0 && pT_1jet>300 && passtauveto )"

    elif label == "CRB_N-1_nonleadb_20":
        cutstouse = OneLSRBPreselection+"( num_bjets>=4 &&  nj_good>=4 && meff>1000 && leadb1==0 && pT_1jet>200 && fabs(dPhi_1jet)>2.8 && passtauveto)"

    elif label == "bbN2_Preselection":
        cutstouse = cutstouse+"(nbaselineLep == 0 && nj_good >= 4 && pT_1jet > 50 && pTj2 > 50 && num_bjets >= 3 && eT_miss_orig > 250 && dphimin4_orig > 0.4 && (isttbarMET400_OK || truthFilterMET < 400 ))"
    
    elif label == "SR_SRA_DM":
        cutstouse = preselection+"((eT_miss_orig > 250.) && (nbaselineLep==0) && (pT_1bjet>200.) && (nj_good>=6) && (num_bjets>3) && maxminDRbb<2.5 && maxDRbb>2.5 && maxminDRmbb>80 && (meff > 900.) && passtauveto==1)"

    elif label == "VR_SA":
        cutstouse = preselection+"((eT_miss_orig > 250) && (nbaselineLep==0) && (pT_1bjet>200) && (nj_good>=6) && (num_bjets==3) && (meff > 900.) && passtauveto==1)"
        
    elif label == "SR_SRB_original":
        cutstouse = preselection+"(num_bjets>=4 && (SRB1_Mh<150 && SRB1_Mh>100)&& pT_1jet>350 && meff>1000 && passtauveto==1)"

    elif label == "SR_SRB_original_N-1":
        cutstouse = preselection+"(num_bjets>=4 && meff>1000 && passtauveto==1 )"

    elif label == "SR_SRB_original_1step":
        cutstouse = preselection+"(num_bjets>=4 && (SRB1_DRmin<2 && SRB1_DRmin2<3.5) && (SRB1_Mh<150 && SRB1_Mh>100) && pT_1jet>350 && meff>1000 )"

    elif label == "SR_SRB_Higgsino_1step":
        cutstouse = preselection+"(num_bjets>=4 && (SRB2_minDR<2 && SRB2_maxDR<3) && (SRB2_Mh<140 && SRB2_Mh>90) && pT_1jet>300 && meff>1000)"

    elif label == "SR_SRB":
        cutstouse = "(passMETtriggers)*(nj_good>=4)*(num_bjets>=4)*(nbaselineLep==0)*(dphimin4_orig>0.4)*(SRB2_Mh<140 && SRB2_Mh>50)*(pT_1jet>300)*(meff>1000)*(passtauveto==1)*(!leadb1)*(fabs(dPhi_1jet)>2.8)*(eT_miss>300)"

    elif label == "SR_SRB_N-1":
        cutstouse = "(passMETtriggers)*(nj_good>=4)*(num_bjets>=4)*(nbaselineLep==0)*(dphimin4_orig>0.4)*(pT_1jet>300)*(meff>1000)*(passtauveto==1)*(!leadb1)*(fabs(dPhi_1jet)>2.8)*(eT_miss>300)"
        
    elif label == "SR_SRB_N-1_mh12Diff":
        cutstouse = "(passMETtriggers)*(nj_good>=4)*(num_bjets>=4)*(nbaselineLep==0)*(SRB2_Mh<140 && SRB2_Mh>50)*(pT_1jet>300)*(meff>1000)*(passtauveto==1)*(!leadb1)*(fabs(dPhi_1jet)>2.8)*(eT_miss>300)"

    elif label == "CR_CRB":
        cutstouse ="(passMETtriggers)*(eT_miss_orig>250)*(nj_good>=4)*(num_bjets>=4)*(nEl+nMu==1)*(pT_1lep>20)*(nbaselineLep==1)*(MT>20)*(pT_1jet>300)*(meff>1000)*(passtauveto==1)*(!leadb1)*(fabs(dPhi_1jet)>2.2)"

    elif label == "CR_CRB_N-1":
        cutstouse ="(passMETtriggers)*(eT_miss_orig>250)*(nj_good>=4)*(num_bjets>=4)*(nEl+nMu==1)*(pT_1lep>20)*(nbaselineLep==1)*(MT>20)*(pT_1jet>300)*(meff>1000)*(passtauveto==1)*(!leadb1)*(fabs(dPhi_1jet)>2.2)"

    elif label == "SRB_CR_Orignal":
        cutstouse= luminosity+preselection+"*(((SRB1_minDR<2 && SRB1_maxDR<2) && (SRB1_Mh<145 && SRB1_Mh>95)))"
        
    elif label == "SR_SRC":
        cutstouse = "(passMETtriggers)*(eT_miss_orig>250)*(nj_good>=4)*(num_bjets>=3)*(nbaselineLep==0)*(dphimin4_orig>0.4)"#*(metsig>25)"

    elif label == "CR_CRC1l":
        cutstouse = "(passMETtriggers)*(eT_miss_orig>250)*(nj_good>=4)*(num_bjets>=3)*(nEl+nMu==1)*(pT_1lep>20)*(nbaselineLep==1)*(MT>20)*(metsig>20)"

    elif label == "CR_CRC2l":
        cutstouse = "(nj_good>=4)*(num_bjets>=3)*(nbaselineLep==2)*( ((nEl==2)*(nMu==0)||(nEl==0)*(nMu==2))   )*(pT_1lep>27)*(pT_2lep>20)*(charge_1l+charge_2l==0)*(mll>86)*(mll<106)*(eT_miss>250)"

    elif label == "Diagonal_Test":
        cutstouse = "( (nj_good>=4) && (num_bjets>=3) && (eT_miss_orig > 250) && (nbaselineLep==0)  && (dphimin4_orig>0.4) && ( (mcID == 410013 && truthFilterMET < 200) || (mcID == 410014 && truthFilterMET < 200) || (mcID == 410000 && truthFilterHT < 600) || (mcID == 407009 && truthFilterHT > 600 && truthFilterHT < 1000) || (truthFilterHT > 1000 && truthFilterHT < 1500 && mcID == 407010) || (mcID == 407011 && truthFilterHT > 1500) || (mcID != 410013 && mcID != 410014 && mcID != 410000 && mcID != 407009 && mcID != 407010 && mcID != 407011) ) )"


    else:
        print "Error Wrong label try again. "
        return 1

    gROOT.LoadMacro("/user/hteagle/Macros/Plotting/AtlasStyle/AtlasStyle.cxx")                                                                                                                                                                                                
    ROOT.SetAtlasStyle()       

    plottinglist = []

    if options.doRatio:

        # This uses the ratio plotting class, to produce a ratio plot of whatever variable you give as the first argument. The second argument is the latex which will be drawn on the x-axis. 3rd is the xlow, 4th is xhigh and 5th is the rebinning value. The rest you shouldn't need to change and instead should just copy from an existing usage of the function
        RatioPlot.RatioPlot("1", "cuts", 0.5, 1.5, 1, ymax, cutstouse, directory, label, True, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, dataFile, signalFile, True, False)
        #RatioPlot.RatioPlot("m_bb", "m_{bb}", 0, 1000, 120, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, False, False)
        #RatioPlot.RatioPlot("fatJet8_M[0]", "m_{leading 0.8Jet}", 0, 200, 10, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, False, False)
        #RatioPlot.RatioPlot("eT_miss_orig", "E_{T}^{miss}", 0, 1000, 50, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, False, False)
        #RatioPlot.RatioPlot("nj_good", "n_{jets}", 0, 15, 1, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, False,- False)
        #RatioPlot.RatioPlot("num_bjets", "n_{b-jets}", -0.5, 9.5, 1, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, False, False)
        #RatioPlot.RatioPlot("maxminDRmbb1", "min #Delta R(m_{bb})", 50, 250, 20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, False, False)
        # #RatioPlot.RatioPlot("maxminDRmbb", "maxMin #Delta R(m_{bb})", 60, 160, 10, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, False, False)
        # #RatioPlot.RatioPlot("minDR", "min #Delta R(b,b)", 0, 4, 1, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, False, False)
        #RatioPlot.RatioPlot("meff", "m_{eff}", 0, 3000, 160, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, True, False)
        #RatioPlot.RatioPlot("pT_1lep", "p_{T}(leading lep)", 0, 300, 25, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, False, False)
        # #RatioPlot.RatioPlot("pTel1", "p_{T}(e)", 0, 800, 40, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, False, False)
        #RatioPlot.RatioPlot("dphimin4_orig", "min #Delta#phi(j,E_{T}^{miss})", 0, math.pi,20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, True, False)
        #RatioPlot.RatioPlot("dPhi_1jet", "min #Delta#phi(j1,E_{T}^{miss})", -3.5, 3.5,20, ymax, cutstouse, directory, label, True, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, True, False)
       # RatioPlot.RatioPlot("pT_1bjet", "p_{T}^{b1}", 0, 800, 40, ymax, cutstouse, directory, label, True, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, False, False)
        #RatioPlot.RatioPlot("pT_1jet", "p_{T}^{j1} (non b)", 0, 1000, 50, ymax, cutstouse, directory, label, True, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, False, -False)
        #RatioPlot.RatioPlot("MT", "m_T", 0, 200, 10, ymax, cutstouse, directory, label, True, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, False, False)
        #RatioPlot.RatioPlot("m_CT", "m_{CT}", 0, 700, 80, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, False, False)
        #RatioPlot.RatioPlot("HT", "H_{T}", 0, 2000, 150, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, False, False)
        # #RatioPlot.RatioPlot("dPhib1b2", "#Delta#phi(b_{1},b_{2})", 0, math.pi,20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, True, False)
        # #RatioPlot.RatioPlot("HiggsMassCandidate_4Hb", "Higgs Candidate mass", 0, math.pi,20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, True, False)
        #RatioPlot.RatioPlot("SRB1_Mh", "Average Mass of the 2 b-jet pairs (SRB1)", 0, 300,20, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, False, False)
        #RatioPlot.RatioPlot("SRB2_Mh", "Average Mass of the 2 b-jet pairs (SRB2)", 0, 300,20, ymax, cutstouse, directory, label, True, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, False, False)
        #RatioPlot.RatioPlot("SRB1_DRmin", "SRB1_DRmin", 0.0001, 6.0001,1, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, True, -False)
        #RatioPlot.RatioPlot("SRB2_minDR", "SRB2_minDR", 0.0001, 6.0001,1, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, True, False)
        #RatioPlot.RatioPlot("SRB1_DRmin2", "SRB1_DRmin2", 0.0001, 6.0001,1, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, True, False)
        #RatioPlot.RatioPlot("SRB2_maxDR", "SRB2_maxDR", 0.0001, 6.0001,1, ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, True, False)
        # #RatioPlot.RatioPlot("nbaselineLep","#leptons",-0.5,9.5,1,ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, True, False)
        #RatioPlot.RatioPlot("leadb1","ISRlead (0), b-jet lead (1)",-0.5,1.5,1,ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, False, False)
        #RatioPlot.RatioPlot("SRB2_Mh1 ","Higgs candidate mass-DRmin",0,500,50,ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, False, False)
        # RatioPlot.RatioPlot("SRB2_Mh2 ","Higgs candidate mass-DRmax",0,500,50,ymax, cutstouse, directory, label, False, ttVFile, singleTopFile, DiBosonFile, HiggsFile, wJetFile, zJetFile, ttbarFile, DiJetFile, dataFile, signalFile, False, False)


    if options.doCorr:
        CorrelationPlot.CorrelationPlot("amT2", "min( (sqrt(2*(pT_1bjet *eT_miss_orig*(1 - cos(fabs(TVector2::Phi_mpi_pi( (phib1  - eT_miss_origPhi))))))) ), (sqrt(2*(pTb2*eT_miss_orig*(1 - cos(fabs(TVector2::Phi_mpi_pi( (phib2  - eT_miss_origPhi)))))))))","am_{T2}", "min-m_{T}(b,E_{T}^{miss})", 0, 400, 20, 0, 400, 20, cutstouse, directory, label, dataFile, zJetFile)

    if options.doShape:
        ShapePlot.ShapePlot2("m_CT", "m_{CT}", 0, 1000, 50, 100000, cutstouse, directory, label, inputstringShape1,inputstringShape2, False, False, False)
        ShapePlot.ShapePlot2("m_T", "m_{T}", 0, 1000, 50, 100000, cutstouse, directory, label, inputstringShape1,inputstringShape2, False, False, False)


if __name__ == '__main__':
    main()
