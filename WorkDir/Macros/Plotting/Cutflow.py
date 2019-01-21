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
    
    for i in range(2):
        scaling="1*"
        if i ==1:
            scaling=luminosity
        cuts=[]
        cutsinit=cutstouse.split("*")
        for section in cutsinit:
            section=section.strip()#removig white space from either end
            section=section.strip('()')#removing parenthesis from each end
            cutsinit2=section.split("&&")
            for section2 in cutsinit2:
                cuts.append(section2)
        
        print( "File; "+str(signalFile))
        print( "cuts recovered=", cuts)
    
    
        signal=ROOT.TFile(signalFile)
        Livbool=label.find("_Liv")
        
        if Livbool>0:
            print( "This is a liverpool selection")
            signalTree=signal.Get("CollectionTree_")
        elif Livbool==-1:
            signalTree=signal.Get("NominalFixed")
            
        signalHist=ROOT.TH1D("SignalHist","SignalHist",1,0.5,1.5)

        
        cutsUsedInit="1"
        cutsUsedScaledInit=scaling+cutsUsedInit
        signalTree.Draw("1>>SignalHist",cutsUsedScaledInit)
        e=ROOT.Double()
        n=signalHist.IntegralAndError(0, 10000000000, e)
        
        print( "No Cuts", n, e)
        cutsUsed="1"
        cutsUsedScaled="1"
        for cut in cuts:
            cutsUsed=cutsUsed+" && "+cut
            cutsUsedScaled=scaling+"("+cutsUsed+")"
            #print( "cutsUsedScaled=", cutsUsedScaled)
            signalTree.Draw("1>>SignalHist",cutsUsedScaled)
        
            e1=ROOT.Double()
            n1=signalHist.IntegralAndError(0, 10000000000, e1)
            print( ('{0:50}-> {1:>10} p\m {2:>10.2f}'.format(cut, n1, e1)) )
        signalHist.Delete




    return
