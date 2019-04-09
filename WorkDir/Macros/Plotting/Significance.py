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
def Significance(cutstouse,luminosity, signalFiles, bkgFile, outputdir, label):
    
    ensure_dir(outputdir)
    cutstouse = luminosity+cutstouse
    ## Set Styles
    gROOT.LoadMacro("/user/hteagle/AnalysisDirectory/Rel21/Base.21.2.31/run/Macros/Plotting/AtlasStyle/AtlasStyle.cxx")              
    ROOT.SetAtlasStyle()
    gStyle.SetPalette(1);
    gStyle.SetOptTitle(0);
    gStyle.SetOptStat(0);

    
    ##Open all background files individually (helps with compositions)
    bkg = ROOT.TFile.Open(bkgFile)
    bkgTree = bkg.Get("CollectionTree_")
    bkgPlot = ROOT.TH1F("bkgPlot","Title",1,0.5,1.5) 
    bkgPlot.Sumw2()

    bkgTree.Draw("1>>bkgPlot",cutstouse)

    # singleTop = TFile.Open(singleTopFile)
    # singleTopTree = singleTop.Get("ntuple")    
    # singleTopPlot = ROOT.TH1F("SingleTopPlot","Title",1,0.5,1.5) 
    # singleTopPlot.Sumw2()
    # singleTopTree.Draw(variabletoplot+">>SingleTopPlot",cutstouse)

    # wJet = TFile.Open(wJetFile)
    # wJetTree = wJet.Get("ntuple")    
    # wJetPlot = ROOT.TH1F("SingleTopPlot","Title",1,0.5,1.5) 
    # wJetPlot.Sumw2()
    # wJetTree.Draw(variabletoplot+">>SingleTopPlot",cutstouse)

    # ttV = TFile.Open(ttVFile)
    # ttVTree = ttV.Get("ntuple")    
    # ttVPlot = ROOT.TH1F("SingleTopPlot","Title",1,0.5,1.5) 
    # ttVPlot.Sumw2()
    # ttVTree.Draw(variabletoplot+">>SingleTopPlot",cutstouse)

    # DiBoson = TFile.Open(DiBosonFile)
    # DiBosonTree = DiBoson.Get("ntuple")    
    # DiBosonPlot = ROOT.TH1F("SingleTopPlot","Title",1,0.5,1.5) 
    # DiBosonPlot.Sumw2()
    # DiBosonTree.Draw(variabletoplot+">>SingleTopPlot",cutstouse)

    # Higgs = TFile.Open(HiggsFile)
    # HiggsTree = Higgs.Get("ntuple")    
    # HiggsPlot = ROOT.TH1F("SingleTopPlot","Title",1,0.5,1.5) 
    # HiggsPlot.Sumw2()
    # HiggsTree.Draw(variabletoplot+">>SingleTopPlot",cutstouse)
    
    # zJet = TFile.Open(zJetFile)
    # zJetTree = zJet.Get("ntuple")    
    # zJetPlot = ROOT.TH1F("SingleTopPlot","Title",1,0.5,1.5) 
    # zJetPlot.Sumw2()
    # zJetTree.Draw(variabletoplot+">>SingleTopPlot",cutstouse)

    # DiJet = TFile.Open(DiJetFile)
    # DiJetTree = DiJet.Get("ntuple")    
    # DiJetPlot = ROOT.TH1F("SingleTopPlot","Title",1,0.5,1.5) 
    # DiJetPlot.Sumw2()
    # DiJetTree.Draw(variabletoplot+">>SingleTopPlot",cutstouse)
    

    ##Add all backgrounds to SMBkgPlot
    SMBkgPlot = ROOT.TH1F("SMBkgPlot","Title",1,0.5,1.5 ) 
    SMBkgPlot.Sumw2()
    SMBkgPlot.Add(bkgPlot)
    # SMBKgPlot.Add(singleTopPlot)
    # SMBKgPlot.Add(wJetPlot)
    # SMBKgPlot.Add(ttVPlot)
    # SMBKgPlot.Add(DiBosonPlot)
    # SMBKgPlot.Add(HiggsPlot)    
    # SMBKgPlot.Add(zJetPlot)
    # SMBKgPlot.Add(DiJetPlot)
    
    SMBkgNumber = SMBkgPlot.Integral()


    #Calculate the significance with signal files
    Significance = ROOT.TH2F("Siginificance","Put varaiable (cuts) title here",400,125,525,200,0,200)

    for signal in signalFiles:
        sigtree = signal.Get("CollectionTree_")
        sigPlot = ROOT.TH1F("sigPlot","Title",1,0.5,1.5) 
        sigPlot.Sumw2()
        sigtree.SetAlias("YearWeight","year==2018 ? 59900/140000 :(year==2017 ? 44300/14000 : 36200/14000)")
        sigtree.Draw("1>>sigPlot",cutstouse)
        nSignal = sigPlot.Integral()

        ###############
        #significance = nSignal/math.sqrt(SMBkgNumber + (((0.3 * SMBkgNumber + 1))**2))
        significance = RooStats.NumberCountingUtils.BinomialExpZ(nSignal, SMBkgNumber, 0.3)
        ###############
        if significance > 9.99:
            significance=9.99
        if significance <=0 :
            significance = 0.0001

        sigtree.GetEntry(0)
        try:
            print ("C1N2: "+str(sigtree.C1N2_mass_real)+" N1:"+str(sigtree.N1_mass_real)+" Significance: "+str(significance)+", NSig; "+str(nSignal)+", Nbkg; "+str(SMBkgNumber))
            Significance.Fill(sigtree.C1N2_mass_real, sigtree.N1_mass_real, significance)
        except:
            print ("C1N2: "+str(sigtree.C1N2_mass)+" N1:"+str(sigtree.N1_mass)+" Significance: "+str(significance)+", NSig; "+str(nSignal)+", Nbkg; "+str(SMBkgNumber))
            Significance.Fill(sigtree.C1N2_mass, sigtree.N1_mass, significance)
            
        
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
    Significance.SetZTitle("Zn")
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
    
    Significance.Draw("COLZ")
    Significance.Draw("text same")

    latex_draw(label)
    Canvas.SaveAs(outputdir + "sig_" + label + ".png")







if __name__ == '__main__':
    main()

#  LocalWords:  SMBkgNumber
