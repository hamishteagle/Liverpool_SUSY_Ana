#!/usr/bin/env python 
import os, sys, math, ROOT, time
from ROOT import gROOT, TColor, TLatex, gStyle, TLegend, gPad, TAttText


__author__ = "Hamish Teagle"
__doc__    = """Integrated Significance plotting and calculations"""


# Make sure that Path exists for output files
def ensure_dir(d):
    if not os.path.isdir(d):
        os.makedirs(d)

##Pass the signal and backgrounds as strings 
def Significance(cutstouse,luminosity, signalFiles, ttbarFile, singleTopFile):
    
    ## Set Styles
    ROOT.SetAtlasStyle()
    gStyle.SetPalette(1);
    gStyle.SetOptTitle(0);
    gStyle.SetOptStat(0);

    
    ##Open all background files individually (helps with compositions)
    ttbar = TFile.Open(ttbarFile)
    ttbarTree = ttbar.Get("ntuple")
    ttbarPlot = TH1D("ttbarPlot","Title",1,0.5,1.5) 
    ttbarPlot.Sumw2()
    ttbarTree.Draw("1>>ttbarPlot",cutstouse)

    # singleTop = TFile.Open(singleTopFile)
    # singleTopTree = singleTop.Get("ntuple")    
    # singleTopPlot = ROOT.TH1D("SingleTopPlot","Title",1,0.5,1.5) 
    # singleTopPlot.Sumw2()
    # singleTopTree.Draw(variabletoplot+">>SingleTopPlot",cutstouse)
    
    SMBkgPlot = ROOT.TH1D("SMBkgPlot","Title",1,0.5,1.5 ) 
    SMBkgPlot.Sumw2()
    SMBkgPlot.Add(ttbarPlot)
#    SMBKgPlot.Add(singleTopPlot)
    
    SMBkgNumber = SMBkgPlot.Integral()


    #Calculate the significance with signal files
    Significance = ROOT.TH2F("Siginificance","Put varaiable (cuts) title here",725,275,1000,900,-25,875)
    for signal in signalFiles:

        sigFile = TFile.Open(signal)
        sigtree = sigFile.Get("ntuple")
        nSignal = sigFile.GetEntries()#Needs cutstouse!!

        sigtree.GetEntry(0)
        
        significance = nSignal/math.sqrt(SMBkgNumber + (((0.3 * SMBkgNumber + 1))**2))
        print ("C1N2: "+str(sigtree.C1N2_mass)+" N1:"+str(N1_mass)+" Significance: "+str(significance))
        

    Significance.SetXTitle("m( #tilde{b} ) [GeV]")
    Significance.RebinX(50)
    Significance.RebinY(50)
    Significance.SetTitleSize(0.03,"X")
    Significance.SetLabelSize(0.03,"X")
    Significance.SetTitleOffset(1.5,"x")
    Significance.SetYTitle("m( #tilde{#chi}_{1}^{0} ) [GeV]")
    Significance.SetTitleSize(0.03,"Y")
    Significance.SetLabelSize(0.03,"Y")
    Significance.SetTitleOffset(1.5,"y")
    Significance.LabelsDeflate() 
    Significance.SetTitleOffset(1.2,"Z")
    Significance.SetZTitle("S")
    Significance.SetTitleSize(0.03,"Z")
    Significance.SetLabelSize(0.03,"Z")
    gStyle.SetPalette(1)
    gStyle.SetPaintTextFormat("2.2f")
    Significance.GetZaxis().SetRangeUser(1e-10,5)
        









if __name__ == '__main__':
    main()
