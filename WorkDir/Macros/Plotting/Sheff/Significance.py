#!/usr/bin/env python 
import os, sys, math, ROOT, time
from ROOT import gROOT, TColor, TLatex, gStyle, TLegend, gPad, TAttText, RooStats


__author__ = "Hamish Teagle"
__doc__    = """Integrated Significance plotting and calculations"""


## Make sure that Path exists for output files
def ensure_dir(d):
    if not os.path.isdir(d):
        os.makedirs(d)

def latex_draw(label):
    
    Tl = ROOT.TLatex()
    Tl.SetTextSize(0.025)
    Tl.SetTextAlign(13)
    Tl.SetNDC(True)
    Tl.DrawLatex(0.26, 0.90,"#int Ldt = 150 fb^{-1} #sqrt{s} = 13 TeV")
    Tl.DrawLatex(0.1, 0.90,"#it{#bf{ATLAS} Internal}")
    Tl.DrawLatex(0.1, 0.85,"Region: #bf{"+label+"}")
    Tl.DrawLatex(0.25, 0.75,"")


##Pass the signal and backgrounds as strings 
def Significance(cutstouse,luminosity ,signalFiles, ttVFile, singleTopFile, DiBosonFile,HiggsFile, wJetFile, zJetFile, ttbarFile, outputdir, label):
    
    ensure_dir(outputdir)
    cutstouse = luminosity+cutstouse
    ## Set Styles
    gROOT.LoadMacro("/user/hteagle/AnalysisDirectory/Rel21/Base.21.2.31/run/Macros/Plotting/AtlasStyle/AtlasStyle.cxx")              
    ROOT.SetAtlasStyle()
    gStyle.SetPalette(1);
    gStyle.SetOptTitle(0);
    gStyle.SetOptStat(0);

    
    ##Open all background files individually (helps with compositions)
    ttV = ROOT.TFile.Open(ttVFile)
    ttVTree = ttV.Get("NominalFixed")    
    ttVPlot = ROOT.TH1F("SingleTopPlot","Title",1,0.5,1.5) 
    ttVPlot.Sumw2()
    ttVTree.SetAlias("YearWeight","treatAsYear==2017 ? 43600/48500 : 36200/48500")
    ttVTree.Draw("1>>SingleTopPlot",cutstouse)
    
    singleTop = ROOT.TFile.Open(singleTopFile)
    singleTopTree = singleTop.Get("NominalFixed")    
    singleTopPlot = ROOT.TH1F("SingleTopPlot","Title",1,0.5,1.5) 
    singleTopPlot.Sumw2()
    singleTopTree.SetAlias("YearWeight","treatAsYear==2017 ? 43600/48500 : 36200/48500")
    singleTopTree.Draw("1>>SingleTopPlot",cutstouse)
    
    DiBoson = ROOT.TFile.Open(DiBosonFile)
    DiBosonTree = DiBoson.Get("NominalFixed")    
    DiBosonPlot = ROOT.TH1F("SingleTopPlot","Title",1,0.5,1.5) 
    DiBosonPlot.Sumw2()
    DiBosonTree.SetAlias("YearWeight","treatAsYear==2017 ? 43600/48500 : 36200/48500")
    DiBosonTree.Draw("1>>SingleTopPlot",cutstouse)
    
    Higgs = ROOT.TFile.Open(HiggsFile)
    HiggsTree = Higgs.Get("NominalFixed")    
    HiggsPlot = ROOT.TH1F("SingleTopPlot","Title",1,0.5,1.5) 
    HiggsPlot.Sumw2()
    HiggsTree.SetAlias("YearWeight","treatAsYear==2017 ? 43600/48500 : 36200/48500")
    HiggsTree.Draw("1>>SingleTopPlot",cutstouse)

    wJet = ROOT.TFile.Open(wJetFile)
    wJetTree = wJet.Get("NominalFixed")    
    wJetPlot = ROOT.TH1F("SingleTopPlot","Title",1,0.5,1.5) 
    wJetPlot.Sumw2()
    wJetTree.SetAlias("YearWeight","treatAsYear==2017 ? 43600/48500 : 36200/48500")
    wJetTree.Draw("1>>SingleTopPlot",cutstouse)

    zJet = ROOT.TFile.Open(zJetFile)
    zJetTree = zJet.Get("NominalFixed")    
    zJetPlot = ROOT.TH1F("SingleTopPlot","Title",1,0.5,1.5) 
    zJetPlot.Sumw2()
    zJetTree.SetAlias("YearWeight","treatAsYear==2017 ? 43600/48500 : 36200/48500")
    zJetTree.Draw("1>>SingleTopPlot",cutstouse)

    ttbar = ROOT.TFile.Open(ttbarFile)
    ttbarTree = ttbar.Get("NominalFixed")
    ttbarPlot = ROOT.TH1F("ttbarPlot","Title",1,0.5,1.5) 
    ttbarPlot.Sumw2()
    ttbarTree.SetAlias("YearWeight","treatAsYear==2017 ? 43600/48500 : 36200/48500")
    ttbarTree.Draw("1>>ttbarPlot",cutstouse)



    ##Add all backgrounds to SMBkgPlot
    SMBkgPlot = ROOT.TH1F("SMBkgPlot","Title",1,0.5,1.5 ) 
    SMBkgPlot.Sumw2()
    SMBkgPlot.Add(ttVPlot)
    SMBkgPlot.Add(singleTopPlot)
    SMBkgPlot.Add(DiBosonPlot)
    SMBkgPlot.Add(HiggsPlot)    
    SMBkgPlot.Add(wJetPlot)    
    SMBkgPlot.Add(zJetPlot)    
    SMBkgPlot.Add(ttbarPlot)    
    SMBkgNumber = SMBkgPlot.Integral()


    #Calculate the significance with signal files
    Significance = ROOT.TH2F("Siginificance","Put varaiable (cuts) title here",400,125,525,200,0,200)

    for signal in signalFiles:
        sigtree = signal.Get("NominalFixed")
        sigPlot = ROOT.TH1F("sigPlot","Title",1,0.5,1.5) 
        sigPlot.Sumw2()
        sigtree.SetAlias("YearWeight","treatAsYear==2017 ? 43600/48500 : 36200/48500")
        sigtree.Draw("1>>sigPlot",cutstouse)
        nSignal = sigPlot.Integral()

        ###############
        #significance = nSignal/math.sqrt(SMBkgNumber + (((0.3 * SMBkgNumber + 1))**2))
        significance = RooStats.NumberCountingUtils.BinomialExpZ(nSignal, SMBkgNumber, 0.3)
        ###############
        sigtree.GetEntry(0)
        print (str(signal)+" Significance = "+str(significance)+", NSig = "+str(nSignal)+", NBkg = "+str(SMBkgNumber))
        if significance > 9.99:
            significance=9.99
        if significance <=0 :
            significance = 0.0001
    #Significance.Fill(sigtree.C1N2_mass_real, sigtree.N1_mass_real, significance)
            
        
    Significance.SetXTitle("m( #tilde{#chi}_{2}^{0} /#tilde{#chi}_{1}^{#pm}  ) [GeV]")
    Significance.RebinX(25)
    Significance.RebinY(10)
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
    Significance.SetContour(1000)
    #gStyle.SetPalette(1)
    gStyle.SetPaintTextFormat("1.2f")
    Significance.GetZaxis().SetRangeUser(0,5)
    
    print ("Cuts used: "+str(cutstouse))

    Canvas = ROOT.TCanvas("Canvas1","Canvas1",0,0,900,900)
    Canvas.SetRightMargin(0.15)
    Canvas.SetLeftMargin(0.1)
    Canvas.SetBottomMargin(0.1)
    
    # Significance.Draw("COLZ")
    # Significance.Draw("text same")

    # latex_draw(label)
    # Canvas.SaveAs(outputdir + "sig_" + label + ".png")







if __name__ == '__main__':
    main()

#  LocalWords:  SMBkgNumber
