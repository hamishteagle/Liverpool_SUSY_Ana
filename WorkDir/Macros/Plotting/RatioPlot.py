#!/usr/bin/env python
 
import os,sys,subprocess,datetime,copy,math,array,shutil,ROOT,string
from ROOT import gROOT, TColor, TLatex, gStyle, TLegend, gPad, TAttText

__author__ = "John Anders"
__doc__    = """Module to do a Ratio plot using the MasterPlot.py script
"""

# Make sure that Path exists for output files
def ensure_dir(d):
    if not os.path.isdir(d):
        os.makedirs(d)

# Will read in the names of all of the Histograms in the file, and convert it to a list of strings
def GetKeyNames(infile):
    return [key.GetName() for key in infile.GetListOfKeys()]

# Will count the number of events in two Histograms for a comparison of raw events and scaled events
def EventCounter(Data,ttbar,DiBoson, Signal,Zjets,Wjets,ttVs,SingleTop, Higgs, SMTot,SRbool):

    
    e1 = ROOT.Double()
    n1 = Data.IntegralAndError(0, 10000000000, e1)

    e2 = ROOT.Double()
    n2 = SMTot.IntegralAndError(0, 10000000000, e2)

    e3 = ROOT.Double()
    n3 = ttbar.IntegralAndError(0, 10000000000, e3)

    e4 = ROOT.Double()
    n4 = DiBoson.IntegralAndError(0, 10000000000, e4)

    e5 = ROOT.Double()
    n5 = Zjets.IntegralAndError(0, 10000000000, e5)

    e6 = ROOT.Double()
    n6 = Wjets.IntegralAndError(0, 10000000000, e6)

    e7 = ROOT.Double()
    n7 = ttVs.IntegralAndError(0, 10000000000, e7)
    
    e8 = ROOT.Double()
    n8 = SingleTop.IntegralAndError(0, 10000000000, e8)
    
    e10 = ROOT.Double()
    n10 = Higgs.IntegralAndError(0, 10000000000, e10)
    
    #e11 = ROOT.Double()
    #n11 = DiJet.IntegralAndError(0,10000000000,e11)

    e9 = ROOT.Double()
    n9 = Signal.IntegralAndError(0, 10000000000, e9)

    print( "~~~~~~~~~ Sample Composition ~~~~~~~~~~")
    if (SRbool):
        print( "SM  ", n2, " p/m", e2)
        print( "ttbar  ", n3, " p/m ", e3)
        print( "DiBoson  ", n4, " p/m ", e4)
        print( "Higgs  ", n10, " p/m ", e10) 
        print( "Z-Jets  ", n5, " p/m ", e5)
        print( "W-Jets ", n6, " p/m ", e6)
        print( "ttV ", n7, " p/m ", e7)
        print( "Single Top  ", n8, " p/m ", e8)
        #print( "DiJet  ", n11, " p/m ", e11)
        print( "Signal  ", n9, " p/m ", e9)

    else:  
        print( "Data  ", n1, " p/m ", e1)
        print( "SM  ", n2, " p/m", e2)
        print( "ttbar  ", n3, " p/m ", e3)
        print( "DiBoson  ", n4, " p/m ", e4 )
        print( "Higgs  ", n10, " p/m ", e10) 
        print( "Z-Jets  ", n5, " p/m ", e5)
        print( "W-Jets ", n6, " p/m ", e6)
        print( "ttV ", n7, " p/m ", e7)
        print( "Single Top  ", n8, " p/m ", e8)
#        print( "DiJet  ", n11, " p/m ", e11)
        print( "Signal  ", n9, " p/m ", e9)
        
        if (n1 > 0 and n2 > 0 and e1 > 0 and e2 > 0):
            print( "mu_factor = ", n1/n2, " p/m ", (n1/n2)*(( (e1/n1)**2 + (e2/n2)**2 )**0.5) )
        else:
            print( "Invalid Mu factor")
    

    print( "~~~~~~~~~ Sample Composition ~~~~~~~~~~")
    if (SRbool):
        print( "\hline")
        print( "SM  &", round(n2,4) , " $\pm$", round(e2,4) , r"\\")
        print( "\hline")
        print( "$t\bar{t}$ &  ", round(n3,4), " $\pm$ ", round(e3,4), r"\\")
        print( "DiBoson &  ", round(n4,4), " $\pm$ ", round(e4,4), r"\\")
        print( "Higgs &  ", round(n10,4), " $\pm$ ", round(e10,4), r"\\")
        #print( "DiJet &  ", round(n11,4), " $\pm$ ", round(e11,4), r"\\")
        print( "Z-Jets & ", round(n5,4), " $\pm$ ", round(e5,4), r"\\")
        print( "W-Jets &", round(n6,4), " $\pm$ ", round(e6,4), r"\\")
        print( "$t\bar{t}V$ &", round(n7,4), " $\pm$ ", round(e7,4), r"\\")
        print( "Single Top & ", round(n8,4), " $\pm$ ", round(e8,4), r"\\")
        print( "\hline")

    else:
       print( "Data & ", round(n1,4) , " $\pm$ ", round(e1,4) , r"\\")
       print( "\hline")
       print( "SM  &", round(n2,4) , " $\pm$", round(e2,4) , r"\\")
       print( "\hline")
       print( r"$t\bar{t}$ &  ", round(n3,4), " $\pm$ ", round(e3,4), r"\\")
       print( "DiBoson &  ", round(n4,4), " $\pm$ ", round(e4,4), r"\\")
       print( "Higgs &  ", round(n10,4), " $\pm$ ", round(e10,4), r"\\")
       #print( "DiJet &  ", round(n11,4), " $\pm$ ", round(e11,4), r"\\")
       print( "Z-Jets & ", round(n5,4), " $\pm$ ", round(e5,4), r"\\")
       print( "W-Jets &", round(n6,4), " $\pm$ ", round(e6,4), r"\\")
       print( r"$t\bar{t}V$ &", round(n7,4), " $\pm$ ", round(e7,4), r"\\")
       print( "Single Top & ", round(n8,4), " $\pm$ ", round(e8,4), r"\\")
       print( "\hline")

    #print( "$\mu$ &", round(n1/n2,4), "& $\pm$ ", round((n1/n2)*(( (e1/n1)**2 + (e2/n2)**2 )**0.5),4), r"\\"
    

    DataEvents = n1
    SMEvents = n2
    ttbarEvents = ttbar.Integral()
    DiBosonEvents = DiBoson.Integral()
    ZjetsEvents = Zjets.Integral()
    WjetsEvents = Wjets.Integral()
    HiggsEvents = Higgs.Integral()    
    #DiJetEvents = DiJet.Integral()
    ttVsEvents = ttVs.Integral()
    SingleTopEvents = SingleTop.Integral()
    SignalEvents = Signal.Integral()
    
    

    print( "~~~~~~~~~ Percentage Composition ~~~~~~~~~~")
    print( "ttbar: \t\t", (ttbarEvents/SMEvents)*100 ,"%")
    print( "DiBoson: \t", (DiBosonEvents/SMEvents)*100 ,"%")
    print( "ZJets: \t\t", (ZjetsEvents/SMEvents)*100 ,"%")
    print( "WJets: \t\t", (WjetsEvents/SMEvents)*100 ,"%")
    print( "Higgs: \t\t", (HiggsEvents/SMEvents)*100 ,"%")
    #print( "Di-Jets: \t", (DiJetEvents/SMEvents)*100 ,"%")
    print( "Single Top: \t", (SingleTopEvents/SMEvents)*100 ,"%")
    
    print( "S/sqrt(B + (0.3B*B +1)): \t", SignalEvents/(math.sqrt(0.3*SMEvents**2+1)))
    
    
# Draws latex on the plots
def latex_draw(label):
    
    Tl = ROOT.TLatex()
    Tl.SetTextSize(0.035)
    Tl.SetTextAlign(13)
    Tl.SetNDC(True)
    Tl.DrawLatex(0.195, 0.87,"#sqrt{s} = 13 TeV, 36.1 fb^{-1}")
    Tl.DrawLatex(0.195, 0.92,"#it{#bf{ATLAS}} Internal")
    Tl.DrawLatex(0.195, 0.82,label)
   
def RatioPlot(variable, xaxislabel, xmin, xmax, rebin, ymax, selection, directory, label, doEctCounter, ttVFile, singleTopFile, DiBosonFile, HiggsFile, WjetsFile, ZjetsFile, ttbarFile, DiJetFile, datafile, inputSignalFiles, phiplot, etaplot, luminosity, sigOnly):

    output_dir = directory+label
    
    if(not sigOnly):
        ttV = ROOT.TFile(ttVFile)
        ttVTree = ttV.Get("CollectionTree_")
        #ttVTree.SetAlias("YearWeight","year==2017 ? 43600/79800 : 36200/79800")
        
        SingleTop = ROOT.TFile(singleTopFile)
        SingleTopTree = SingleTop.Get("CollectionTree_")
        #SingleTopTree.SetAlias("YearWeight","year==2017 ? 43600/79800 : 36200/79800")
        
        DiBoson = ROOT.TFile(DiBosonFile)
        DiBosonTree = DiBoson.Get("CollectionTree_")
        #DiBosonTree.SetAlias("YearWeight","year==2017 ? 43600/79800 : 36200/79800")
        
        Higgs = ROOT.TFile(HiggsFile)
        HiggsTree = Higgs.Get("CollectionTree_")
        #HiggsTree.SetAlias("YearWeight","year==2017 ? 43600/79800 : 36200/79800")
        
        DiJet = ROOT.TFile(DiJetFile)
        DiJetTree = DiJet.Get("CollectionTree_")
        #DiJetTree.SetAlias("YearWeight","year==2017 ? 43600/79800 : 36200/79800")
        
        Wjets = ROOT.TFile(WjetsFile)
        WjetsTree = Wjets.Get("CollectionTree_")
        #WjetsTree.SetAlias("YearWeight","year==2017 ? 43600/79800 : 36200/79800")
        
        Zjets = ROOT.TFile(ZjetsFile)
        ZjetsTree = Zjets.Get("CollectionTree_")
        #ZjetsTree.SetAlias("YearWeight","year==2017 ? 43600/79800 : 36200/79800")
        
        ttbar = ROOT.TFile(ttbarFile)
        ttbarTree = ttbar.Get("CollectionTree_")
        #ttbarTree.SetAlias("YearWeight","year==2017 ? 43600/79800 : 36200/79800")
        
        Data = ROOT.TFile(datafile)
        DataTree = Data.Get("CollectionTree_")
        
        blind = False
        if ("SR" in label):
            blind = True 
            Data = ROOT.TFile(signalFiles[0])
            DataTree = signalFiles[0].Get("CollectionTree_")
        
    crblind =False
    if ("CR" in label or "VR" in label):
        crblind =True


    ##Adaptation for multiple signal files
    signalFiles={}#Dictionary of trees
    i=0
    for signalFile in inputSignalFiles: 
        signalFiles["signalFile_"+str(i)] = ROOT.TFile(signalFile)
        print( "signalFile_"+str(i)+"="+signalFile)
        i=i+1

        
        
        
    print( "input files read in")

    
    # Loads the ATLAS style Macro for plotting
#    gROOT.LoadMacro("../../../../ATLAS_Style/atlasstyle-00-03-05/AtlasStyle.C")
#    ROOT.SetAtlasStyle()


    # Output Directory
    # Change here to change the top level directory 
    #where the histograms go
    output_dir = "/user/hteagle//SummerAnalysis/Summer_Student_Analysis/histograms/RecoPlots/"
   
    change_me = directory+"/"+label+"/"
    output_dir = output_dir + change_me
    print((output_dir))
    ensure_dir(output_dir)
    

    varname = variable
    

    histtoplot = varname+"_"+label


    variabletoplot = variable

    minvalue = float(xmin)
    maxvalue = float(xmax) 
    rebinvalue = rebin
    #luminosity = "79800*jvtweight*AnalysisWeight*pileupweight*LumiWeight*btagweight*MuonWeight*ElecWeight*isttbarMET400_OK*isttbarMET200_OK*isttbarMET300_OK*"
    #luminosity = "1*"

    
    cutstouse = luminosity+selection
    print( ("Scaling = " +str(cutstouse)))
    datacutstouse = selection
    
    if rebinvalue > 1 and not phiplot and not etaplot:
        xaxislabel = xaxislabel+" [GeV]"

    #numberofbins = int(xmax-xmin)
    numberofbins = int(rebinvalue)
    print( "Number of bins: ", numberofbins)
    
    if rebinvalue == 0 and "jet_imbalance" in variabletoplot:
        numberofbins = 20
        

    if rebinvalue == 0 and "MV2" in variabletoplot:
        numberofbins = 50


    # catch the variable to plot here
        
    #TF1 func("mTb1MET","TMath::sqrt(2*(pTb1*ETMiss*(1 - TMath::cos(TMath::fabs(TMath::TVector2::Phi_mpi_pi( (phib1  - ETMissPhi)))))))",xmin,xmax);
    #tree->Draw( "func.(length)" );
        

    if phiplot:
        numberofbins = 15
    elif etaplot:
        numberofbins = 22
        xmax = xmax + 1

    if(not sigOnly):
        SMBkgPlot = ROOT.TH1D("SMBkgPlot","Title",numberofbins,xmin,xmax ) 
        SMBkgPlot.Sumw2()
    
        SingleTopPlot = ROOT.TH1D("SingleTopPlot","Title",numberofbins,xmin,xmax)
        ttVPlot = ROOT.TH1D("ttVPlot","Title",numberofbins,xmin,xmax)
        DiBosonPlot =ROOT.TH1D("DiBosonPlot","Title",numberofbins,xmin,xmax )
        HiggsPlot =ROOT.TH1D("HiggsPlot","Title",numberofbins,xmin,xmax )
        DiJetPlot =ROOT.TH1D("DiJetPlot","Title",numberofbins,xmin,xmax )
        WjetsPlot = ROOT.TH1D("WjetsPlot","Title",numberofbins,xmin,xmax ) 
        ZjetsPlot = ROOT.TH1D("ZjetsPlot","Title",numberofbins,xmin,xmax )
        ttbarPlot = ROOT.TH1D("ttbarPlot","Title",numberofbins,xmin,xmax )

        # Temp plots for correct stats
        SingleTopTempPlot = ROOT.TH1D("SingleTopTempPlot","Title",numberofbins,xmin,xmax)
        ttVTempPlot = ROOT.TH1D("ttVTempPlot","Title",numberofbins,xmin,xmax)
        DiBosonTempPlot =ROOT.TH1D("DiBosonTempPlot","Title",numberofbins,xmin,xmax )
        HiggsTempPlot =ROOT.TH1D("HiggsTempPlot","Title",numberofbins,xmin,xmax )
        DiJetTempPlot =ROOT.TH1D("DiJetTempPlot","Title",numberofbins,xmin,xmax )
        WjetsTempPlot = ROOT.TH1D("WjetsTempPlot","Title",numberofbins,xmin,xmax ) 
        ZjetsTempPlot = ROOT.TH1D("ZjetsTempPlot","Title",numberofbins,xmin,xmax )
        ttbarTempPlot = ROOT.TH1D("ttbarTempPlot","Title",numberofbins,xmin,xmax )
        
        ttbarTempPlot.Sumw2()
        ZjetsTempPlot.Sumw2()
        WjetsTempPlot.Sumw2()
        ttVTempPlot.Sumw2()
        SingleTopTempPlot.Sumw2()
        DiBosonTempPlot.Sumw2()
        HiggsTempPlot.Sumw2()
        DiJetTempPlot.Sumw2()

    signalPlots={}

    print( "length of signalFiles: "+str(len(signalFiles)))
    for i in range (0,len(signalFiles)):
        print("Drawing signalPlot"+str(i))
        signalTree = signalFiles["signalFile_"+str(i)].Get("CollectionTree_")
        signalPlots["signalPlot_"+str(i)] = ROOT.TH1D("signalPlot_"+str(i),"Title",numberofbins,xmin,xmax )
        print( "signalPlot_"+str(i)+"=ROOT.TH1D(signalPlot_"+str(i))
        signalTree.Draw(variabletoplot+">>signalPlot_"+str(i),cutstouse)
        
    if(not sigOnly):
        SingleTopTree.Draw(variabletoplot+">>SingleTopPlot",cutstouse)
        ttVTree.Draw(variabletoplot+">>ttVPlot",cutstouse)
        DiBosonTree.Draw(variabletoplot+">>DiBosonPlot",cutstouse)
        HiggsTree.Draw(variabletoplot+">>HiggsPlot",cutstouse)
        DiJetTree.Draw(variabletoplot+">>DiJetPlot",cutstouse)
        WjetsTree.Draw(variabletoplot+">>WjetsPlot",cutstouse)
        ZjetsTree.Draw(variabletoplot+">>ZjetsPlot",cutstouse)
        ttbarTree.Draw(variabletoplot+">> ttbarPlot",cutstouse)
    
        ttVTree.Draw(variabletoplot+">>ttVTempPlot",cutstouse)
        DiBosonTree.Draw(variabletoplot+">>DiBosonTempPlot",cutstouse)
        HiggsTree.Draw(variabletoplot+">>HiggsTempPlot",cutstouse)
        DiJetTree.Draw(variabletoplot+">>DiJetTempPlot",cutstouse)
        SingleTopTree.Draw(variabletoplot+">>SingleTopTempPlot",cutstouse)
        WjetsTree.Draw(variabletoplot+">>WjetsTempPlot",cutstouse)
        ZjetsTree.Draw(variabletoplot+">>ZjetsTempPlot",cutstouse)
        ttbarTree.Draw(variabletoplot+">> ttbarTempPlot",cutstouse)


    
        SMBkgPlot.Add(ZjetsTempPlot)
        SMBkgPlot.Add(ttbarTempPlot)
        SMBkgPlot.Add(ttVTempPlot)
        SMBkgPlot.Add(SingleTopTempPlot)
        SMBkgPlot.Add(DiBosonTempPlot)
        SMBkgPlot.Add(HiggsTempPlot)
        SMBkgPlot.Add(DiJetTempPlot)
        SMBkgPlot.Add(WjetsTempPlot)


        StackedPlot = ROOT.THStack("hs","")
        
        DataPlot = ROOT.TH1D("DataPlot","Title",numberofbins,xmin,xmax )
        DataPlot.Sumw2()
        DataTree.Draw(variabletoplot+">>DataPlot",datacutstouse)


  
    # Sets up Canvas and Legend
    Canvas = ROOT.TCanvas("Canvas1","Canvas1",0,0,900,900)

    
    
    
    if not sigOnly:
        pad1 = ROOT.TPad("pad1","pad1",0,0.30,1,1)
        pad1.SetBottomMargin(0)
    else:
        pad1 = ROOT.TPad("pad1","pad1",0,0,1,1)
        


    dology = True


    #if not phiplot and not etaplot and rebinvalue!=0:
        # if not sigOnly:
        #     ttbarPlot.Rebin(rebinvalue)
        #     ttVPlot.Rebin(rebinvalue)
        #     SingleTopPlot.Rebin(rebinvalue)
        #     DiBosonPlot.Rebin(rebinvalue)
        #     WjetsPlot.Rebin(rebinvalue)
        #     ZjetsPlot.Rebin(rebinvalue)
        #     SMBkgPlot.Rebin(rebinvalue)
        #     DataPlot.Rebin(rebinvalue)
        #     HiggsPlot.Rebin(rebinvalue)
        #     DiJetPlot.Rebin(rebinvalue)
        # for string,Plot in signalPlots.items():
        #     print( "Plot; type ="+str(type(Plot)))
        #     Plot.Rebin(rebinvalue)



    if not sigOnly:
        nbinsx = SMBkgPlot.GetXaxis().GetNbins()
        nbins_d = DataPlot.GetXaxis().GetNbins()
        maximum = 10000
        maxBin = 0
        # changed here from -1
        for i in range (0, nbinsx):
            #print( "i = ", i
            if (SMBkgPlot.GetBinContent(i) > maxBin):
                maximum = (SMBkgPlot.GetBinContent(i))
                maxBin = SMBkgPlot.GetBinContent(i)
                #print( "SM Maximum = ", maximum
                print( "SM Maxbin = ", maxBin)
        for i in range (0, nbins_d):
            #print( "i = ", i
            if (DataPlot.GetBinContent(i) > maxBin):
                maximum = (DataPlot.GetBinContent(i))
                maxBin = DataPlot.GetBinContent(i)
                #print( "Data Maximum = ", maximum
                #print( "Data Maxbin = ", maxBin

        if maximum < 500:
            #maximum = maximum*(1.3)
            maximum = maximum*1000
            #dology = False
            #print( "Maximum - ", maximum
        else:
            maximum = maximum*1000
            #print( "Maximum - ", maximum

        if "jet_imbalance" in variabletoplot:
            maximum = 10
    if (dology):
        pad1.SetLogy()

    pad1.Draw()
    if not sigOnly:
        pad2 = ROOT.TPad("pad2","pad2",0,0.065,1,0.30)
        pad2.SetTopMargin(0)
        pad2.SetBottomMargin(0.4)
        pad2.Draw()


    pad1.cd()

    Legend = ROOT.TLegend(0.50,0.66,0.70,0.94)
   
    otherColor = ROOT.TColor(3004,168./255, 164./255, 150./255)
    ZColor = ROOT.TColor(3005,253./255, 175./255, 9./255)
    singletopColor = ROOT.TColor(3000,54./255, 121./255,191./255)
    WColor = ROOT.TColor(3002,130./255, 95./255, 135./255)
    ttbarColor = ROOT.TColor(3001,123./255, 178./255, 116./255)
    HiggsColor = ROOT.TColor(6,1./255, 1./255, 255./255)
    DiJetColor = ROOT.TColor(3007,1./255, 1./255, 255./255)

    if not sigOnly:
        ttbarPlot.SetFillColor(870)
        ttVPlot.SetFillColor(418)
        SingleTopPlot.SetFillColor(407)
        DiBosonPlot.SetFillColor(633)
        WjetsPlot.SetFillColor(797)
        ZjetsPlot.SetFillColor(867)
        HiggsPlot.SetFillColor(6)
        DiJetPlot.SetFillColor(3007)
    

        # Sort out the Line Colours
        ttbarPlot.SetLineColor(807)
        ttVPlot.SetLineColor(418)
        SingleTopPlot.SetLineColor(407)
        DiBosonPlot.SetLineColor(633)
        WjetsPlot.SetLineColor(797)
        ZjetsPlot.SetLineColor(867)
        HiggsPlot.SetLineColor(6)
        DiJetPlot.SetLineColor(3007)


    color=0
    for signalPlot in signalPlots:
        signalPlots[signalPlot].SetLineColor(ROOT.kMagenta+color)
        signalPlots[signalPlot].SetLineWidth(3)
        signalPlots[signalPlot].SetLineStyle(2)
        signalPlots[signalPlot].Scale(1/signalPlots[signalPlot].Integral())
        signalPlots[signalPlot].SetMinimum(0.01)
        color+=3
    if not sigOnly:
        #SMBkgPlot.SetLineColor(ROOT.kRed) # Sbottom Style
        SMBkgPlot.SetLineColor(ROOT.kBlack)
        SMBkgPlot.SetMarkerSize(0.000000001)
        SMBkgPlot.SetMarkerColor(ROOT.kRed)
        # Sort out the Line Colours
        ttbarPlot.SetLineWidth(1)
        ttVPlot.SetLineWidth(1)
        SingleTopPlot.SetLineWidth(1)
        DiBosonPlot.SetLineWidth(1)
        WjetsPlot.SetLineWidth(1)
        ZjetsPlot.SetLineWidth(1)
        HiggsPlot.SetLineWidth(1)
        DiJetPlot.SetLineWidth(1)



        # Sort out line width for full SM Background plot
        SMBkgPlot.SetLineWidth(7)

        ttbarPlot.GetXaxis().SetRangeUser(minvalue,maxvalue)
        ttVPlot.GetXaxis().SetRangeUser(minvalue,maxvalue)
        SingleTopPlot.GetXaxis().SetRangeUser(minvalue,maxvalue)
        DiBosonPlot.GetXaxis().SetRangeUser(minvalue,maxvalue)
        HiggsPlot.GetXaxis().SetRangeUser(minvalue,maxvalue)
        DiJetPlot.GetXaxis().SetRangeUser(minvalue,maxvalue)
        WjetsPlot.GetXaxis().SetRangeUser(minvalue,maxvalue)
        ZjetsPlot.GetXaxis().SetRangeUser(minvalue,maxvalue)
        SMBkgPlot.GetXaxis().SetRangeUser(minvalue,maxvalue)
        DataPlot.GetXaxis().SetRangeUser(minvalue,maxvalue)
    for signalPlot in signalPlots:
        signalPlots["signalPlot_0"].GetXaxis().SetRangeUser(minvalue,maxvalue)




    if not sigOnly:
        SMBkgLine = SMBkgPlot.Clone()
        SMCheck = SMBkgPlot.Clone()
        TempDataPlot = SMBkgPlot.Clone()
        TempDataPlot.Divide(SMBkgPlot)
        TempDataPlot.SetLineColor(ROOT.kRed)


    
        HatchedDataPlot = SMBkgPlot.Clone()
        HatchedDataPlot.Sumw2()
        HatchedDataPlot.Divide(SMBkgPlot)
        HatchedDataPlot.SetFillColor(ROOT.kBlack)
        #HatchedDataPlot.SetFillStyle(3004) # sbottom style
        HatchedDataPlot.SetFillStyle(3013)


        DataPlot.Sumw2()
        SMBkgPlot.SetFillColor(ROOT.kBlack)
        SMBkgPlot.SetFillStyle(3002)
        SMBkgPlot.SetMarkerSize(0.001)
    

        TempRatioPlot = DataPlot.Clone()
        TempRatioPlot.Divide(SMCheck)
    
        # Add the Histograms to the Stack Order Matters
    
        StackedPlot.Add(DiJetPlot)
        print( "Added DiJet")
        StackedPlot.Add(HiggsPlot)
        print( "Added Higgs")
        StackedPlot.Add(DiBosonPlot)
        print( "Added DiBoson")
        StackedPlot.Add(ZjetsPlot)
        print( "Added Zjets")
        StackedPlot.Add(ttVPlot)
        print( "Added ttV")
        StackedPlot.Add(WjetsPlot)
        print( "Added Wjets")
        StackedPlot.Add(SingleTopPlot)
        print( "Added SingleTop")
        StackedPlot.Add(ttbarPlot)
        print( "Added ttbar")
    

    
        # Sorts out all of the legend drawing
        Legend.AddEntry(DataPlot,"Data","P")
        Legend.AddEntry(SMBkgPlot,"SM Total","L")
        Legend.AddEntry(ttbarPlot,"t#bar{t}", "F")
        Legend.AddEntry(WjetsPlot,"W + Jets","F")
        Legend.AddEntry(SingleTopPlot,"Single t","F")
        Legend.AddEntry(ZjetsPlot,"Z + Jets", "F")
        Legend.AddEntry(ttVPlot,"t#bar{t}+V","F")
        Legend.AddEntry(DiBosonPlot,"DiBoson", "F")
        Legend.AddEntry(HiggsPlot,"Higgs", "F")
        Legend.AddEntry(DiJetPlot,"DiJet", "F")
    j=0
    for inputSignalFile in inputSignalFiles:
        TruthBool = False
        UnsmearedBool = False
        if (inputSignalFile.find("TRUTH") != -1):
            TruthBool = True
            if (inputSignalFile.find("Unsmeared")!=-1):
                UnsmearedBool = True
        if (inputSignalFile.find("C1N2") != -1):
            print ('inputSignalFile has type:'+str(type(inputSignalFile)))
            print ('inputSignalFile is:'+str(inputSignalFile))
            inputSignalFile=inputSignalFile.split("C1N2_Wh_hbb_")
            signalmass = (inputSignalFile[1].split("_")[0])+","+(inputSignalFile[1].split("_")[1])
            if TruthBool:
                signalmass = signalmass+"TRUTH"
                if UnsmearedBool:
                    signalmass = signalmass+"Unsmeared"
            Legend.AddEntry(signalPlots["signalPlot_"+str(j)],"(m_{#tilde{#chi}_{2}^{0}}/m_{#tilde{#chi}_{1}^{#pm}}, m_{#tilde{#chi}_{1}^{0}}) = ("+signalmass+")GeV", "L")

        else:
            #Legend.AddEntry(signalPlots["signalPlot_"+str(j)],"(m_{#tilde{b}}, m_{#tilde{#chi}}_{1}^{0}) = (800,1)GeV", "L")
            if TruthBool:
                Legend.AddEntry(signalPlots["signalPlot_"+str(j)],"ttbar_Truth", "L")
            else:
                Legend.AddEntry(signalPlots["signalPlot_"+str(j)],"ttbar", "L")
        j+=1
    Legend.SetTextSize(0.02)
    #Legend.SetTextFont(2)
    Legend.SetFillColor(0)
    Legend.SetFillStyle(0)
    Legend.SetBorderSize(0)
  
    if not sigOnly:
        # Sorts out the labels etc of the Histogram to be plotted first
        SMBkgPlot.SetXTitle(xaxislabel)
        SMBkgPlot.SetTitleSize(0.05,"X")
        SMBkgPlot.SetLabelSize(0.05,"X")
    
        if rebinvalue > 1 and not phiplot and not etaplot:
            SMBkgPlot.SetYTitle("Events / "+str(rebinvalue)+" GeV")
        elif phiplot:
            SMBkgPlot.SetYTitle("Events / #frac{#Pi}{10}")
        else:
            SMBkgPlot.SetYTitle("Events")

        SMBkgPlot.SetTitleSize(0.045,"Y")
        SMBkgPlot.SetTitleOffset(1.5,"Y")
        SMBkgPlot.SetLabelSize(0.045,"Y")
        SMBkgPlot.SetMinimum(0.5)
    

        #SMBkgPlot.SetMaximum(SMBkgPlot.Integral()*3)
        SMBkgPlot.SetMaximum(maximum)
    
    if dology:
        print( "set canvas log y")
        Canvas.SetLogy()
    gStyle.SetErrorX(.5);
    gStyle.SetHatchesSpacing(0.2);
        
    if not sigOnly:
        SMBkgPlot.SetFillColor(ROOT.kGray+1)
        SMBkgPlot.SetFillStyle(3004)
        SMBkgPlot.Draw("HIST;E2")
        SMBkgLine.Draw("same;HIST")
        StackedPlot.Draw("same;HIST")
        if not blind:
            DataPlot.Draw("P same E1 X0")
    
    if not crblind:
        i=0
        for signalPlot in signalPlots:
            if sigOnly:
                if i==0 :
                    signalPlots[signalPlot].GetXaxis().SetTitle(xaxislabel)
                    signalPlots[signalPlot].SetLabelSize(0.04,"X")
                    signalPlots[signalPlot].SetMaximum(signalPlots[signalPlot].GetMaximum()*10)
                    signalPlots[signalPlot].Draw("HIST;E")
                    print ("number of events: "+str(signalPlots[signalPlot].GetEntries()))
                else:
                    signalPlots[signalPlot].Draw("SAME;HIST;E")
                    print ("number of events: "+str(signalPlots[signalPlot].GetEntries()))
            else:
                signalPlots[signalPlot].Draw("SAME;HIST;E")
                print ("number of events: "+str(signalPlots[signalPlot].GetEntries()))
            i+=1
    latex_draw(label)
    Legend.Draw()



    

    # Need to set up the data ratio to have the same number of bins and the same range as the plots above

    #Bins = DataPlot.GetNbinsX()
    

    #DataRatio = ROOT.TH1D("DataRatio","DataRatio",Bins, minvalue, maxvalue)
    

    # sum W2 somewhere


    if not sigOnly:
        pad2.cd()
        TempRatioPlot.SetLineWidth(1)
        TempRatioPlot.SetLineColor(ROOT.kBlack)
        HatchedDataPlot.SetXTitle(xaxislabel)
        HatchedDataPlot.SetTitleSize(0.12,"X")
        HatchedDataPlot.SetLabelSize(0.12,"X")
        HatchedDataPlot.SetTitleOffset(1,"X")
        HatchedDataPlot.SetYTitle("Data / SM")
        HatchedDataPlot.SetLineWidth(1)
        HatchedDataPlot.SetTitleSize(0.12,"Y")
        HatchedDataPlot.SetTitleOffset(0.5,"Y")
        HatchedDataPlot.SetLabelSize(0.12,"Y")
        HatchedDataPlot.SetMaximum(3)
        HatchedDataPlot.SetMinimum(0)
        HatchedDataPlot.GetYaxis().SetRangeUser(-0.1,2.2)
        HatchedDataPlot.GetYaxis().SetNdivisions(3,6,0)
        HatchedDataPlot.GetYaxis().CenterTitle()
        HatchedDataPlot.SetMarkerSize(0.00001)
        HatchedDataPlot.SetFillColor(ROOT.kBlack)
        HatchedDataPlot.Draw("E2")
    


    middleLine = ROOT.TLine()
    middleLine.SetLineColor(ROOT.kRed)

    if not sigOnly:
        if not blind:
            TempRatioPlot.Draw("P same E1 X0")
            
            TempRatioPlot.Draw("PE same X0")
            oldSize = TempRatioPlot.GetMarkerSize()
            TempRatioPlot.SetMarkerSize(0)
            TempRatioPlot.DrawCopy("same E0 X0")
            TempRatioPlot.SetMarkerSize(oldSize)
            TempRatioPlot.Draw("PE same X0")

        middleLine.DrawLine(minvalue,1,maxvalue,1)
    
    
    Canvas.SaveAs(output_dir + histtoplot +".png")
    Canvas.SaveAs(output_dir + histtoplot +".eps")
    Canvas.SaveAs(output_dir + histtoplot +".pdf")
    Canvas.SaveAs(output_dir + histtoplot +".C")
    SRbool =False
    if sigOnly:
        doEctCounter = False
    if (doEctCounter):
        if ("SR" in label):
            SRbool=True
        print( "Doing Event counter")
        for signalPlot in signalPlots:
            EventCounter(DataPlot,ttbarTempPlot,DiBosonTempPlot, signalPlots[signalPlot] ,ZjetsTempPlot,WjetsTempPlot,ttVTempPlot,SingleTopTempPlot, HiggsTempPlot, SMBkgPlot, SRbool)


    print( "Canvas saved as " + output_dir+histtoplot + ".pdf")

    return
