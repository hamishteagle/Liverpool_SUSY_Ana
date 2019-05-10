#!/usr/bin/env python

import os,sys,subprocess,datetime,copy,math,array,shutil,ROOT,string
from ROOT import gROOT, TColor, TLatex, gStyle, TLegend, gPad, TAttText

__author__ = "Hamish Teagle"
__doc__    = """Module to do a cutflow from MasterPlot.py
"""

# Make sure that Path exists for output files
def ensure_dir(d):
    if not os.path.isdir(d):
        os.makedirs(d)

def Cutflow(label, cutstouse, signalFile,luminosity):
    
    print (str(cutstouse))

    for i in range(2):
        scaling="1*"
        if i ==1:
            scaling=luminosity
        cuts=[]
        cutsinit=cutstouse.split("*")
        for section in cutsinit:
            section=section.strip()#removig white space from either end
            section=section.strip('()')#removing parenthesis from each end
            #cutsinit2=section.split("&&")
            #for section2 in cutsinit2:
            cuts.append(section)
        
        print( "File; "+str(signalFile))
        print( "cuts recovered=", cuts)
    
    
        signal=ROOT.TFile(signalFile)
        #signalTree=signal.Get("CollectionTree_")
        try:
            signalTree=signal.Get("CollectionTree_")
            signalTree.SetAlias("YearWeight","year==2018 ? 58.5/139 :(year==2017 ? 43.3/139 : 36.2/139)")
        except:
            signalTree=signal.Get("ntuple")
            print ("Setting aliases")
            signalTree.SetAlias("YearWeight","eventWeight>-100")
            signalTree.SetAlias("pileupweight","eventWeight>-100")
            signalTree.SetAlias("jvtweight","eventWeight>-100")
            signalTree.SetAlias("btagweight","eventWeight>-100")
            signalTree.SetAlias("AnalysisWeight","eventWeight")
            signalTree.SetAlias("LumiWeight","(HFScale/1000)")
            
            signalTree.SetAlias("passMETtriggers","eventWeight>-100")
            signalTree.SetAlias("nbaselineLep","nBaselineLeptons")
            signalTree.SetAlias("dphimin4_orig","minDPhiJMET_4")
            signalTree.SetAlias("nj_good","nJets")
            signalTree.SetAlias("num_bjets","nBJets")
            signalTree.SetAlias("eT_miss","ETMiss")                        
            signalTree.SetAlias("metsigHT","metsig_HT")
            signalTree.SetAlias("maxDRbb","maxDR")
            signalTree.SetAlias("maxminDRbb","maxminDR")
            signalTree.SetAlias("leadb1","(pTb1==pTj1)")
            signalTree.SetAlias("SRB3_mbb_avg","max_avg_M")
            signalTree.SetAlias("dPhi_1jet","DPhiJMET_1")
            signalTree.SetAlias("maxminDRmbb","maxmin_M")
            signalTree.SetAlias("pT_1jet","pTj1")

        #signalTree.SetAlias("YearWeight","year==2018 ? 59.9/139 :(year==2017 ? 43.3/139 : 36.2/139)")

        signalHist=ROOT.TH1D("SignalHist","SignalHist",1,0.5,1.5)

        
        cutsUsedInit="1"
        cutsUsedScaledInit=scaling+cutsUsedInit
        signalTree.Draw("1>>SignalHist",cutsUsedScaledInit)
        e=ROOT.Double()
        n=signalHist.IntegralAndError(0, 10000000000, e)
        
        print( "No Cuts", n, e)
        cutsUsed="(1)"
        cutsUsedScaled="1*"
        for cut in cuts:
            cutsUsed=cutsUsed+"*("+cut+")"
            #print( "cutsUsed=", cutsUsed)
            cutsUsedScaled=scaling+"("+cutsUsed+")"
            #print ("Scaled cutstouse: "+str(cutsUsedScaled))
            signalTree.Draw("1>>SignalHist",cutsUsedScaled)
        
            e1=ROOT.Double()
            n1=signalHist.IntegralAndError(0, 10000000000, e1)
            print( ('{0:50}-> {1:>10} p\m {2:>10.2f}'.format(cut, n1, e1)) )
        signalHist.Delete




    return
