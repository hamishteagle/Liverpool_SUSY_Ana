#!/usr/bin/env python

import os,sys,subprocess,datetime,copy,math,array,shutil,ROOT,string
from ROOT import gROOT, TColor, TLatex, gStyle, TLegend, gPad, TAttText

__author__ = "John Anders"
__doc__    = """Module to do a plot using the MasterPlot.py script
"""

# Make sure that Path exists for output files
def ensure_dir(d):
    if not os.path.isdir(d):
        os.makedirs(d)

# Will read in the names of all of the Histograms in the file, and convert it to a list of strings
def GetKeyNames(infile):
    return [key.GetName() for key in infile.GetListOfKeys()]

# Draws latex on the plots
def latex_draw(label):
    
    Tl = ROOT.TLatex()
    Tl.SetTextSize(0.035)
    Tl.SetTextAlign(13)
    Tl.SetNDC(True)
    Tl.DrawLatex(0.2, 0.89,"#sqrt{s} = 13 TeV")
    Tl.DrawLatex(0.2, 0.94,"#it{#bf{ATLAS}} Internal")
    Tl.DrawLatex(0.2, 0.84,label)
   

def CorrelationPlot(variable1, variable2, xaxislabel, yaxislabel, xmin, xmax, xbins, ymin, ymax, ybins,selection, directory, label, inputFile1, inputFile2, inputFile3):

    inFile1 = ROOT.TFile(inputFile1)
    inTree1 = inFile1.Get("CollectionTree_")
    inFile2 = ROOT.TFile(inputFile2)
    inTree2 = inFile2.Get("CollectionTree_")
    inFile3 = ROOT.TFile(inputFile3)
    inTree3 = inFile3.Get("CollectionTree_")


    

    print ("input files read in")



    xvariabletoplot = variable1
    xnbins = xbins
    yvariabletoplot = variable2
    ynbins = ybins
    cutstouse = selection

    gStyle.SetPaintTextFormat("1.0f");

    scatterPlot1 = ROOT.TH2F("scatterPlot1","scatterPlot1" , xnbins, xmin, xmax, ynbins, ymin, ymax)
    scatterPlot2 = ROOT.TH2F("scatterPlot2","scatterPlot2" , xnbins, xmin, xmax, ynbins, ymin, ymax)
    scatterPlot4 = ROOT.TH2F("scatterPlot4","scatterPlot4" , xnbins, xmin, xmax, ynbins, ymin, ymax)

    inTree1.Draw(yvariabletoplot+":"+xvariabletoplot+">>scatterPlot1", cutstouse)
    inTree2.Draw(yvariabletoplot+":"+xvariabletoplot+">>scatterPlot2", cutstouse)
    inTree3.Draw(yvariabletoplot+":"+xvariabletoplot+">>scatterPlot4", cutstouse)


#    gROOT.LoadMacro("../ATLAS_Style/atlasstyle-00-03-05/AtlasStyle.C")
#    ROOT.SetAtlasStyle()
    gStyle.SetPalette(1)
    




    Canvas = ROOT.TCanvas("Canvas1","Canvas1",0,0,900,900)
    
    Canvas.SetRightMargin(0.15)
    #Canvas.SetLogz()

    scatterPlot1.GetXaxis().SetTitle(xaxislabel);
    scatterPlot1.GetZaxis().SetTitle("n_{Events}");
    #scatterPlot1.GetZaxis().SetRangeUser(1,5000);
    scatterPlot1.GetYaxis().SetTitle(yaxislabel)
    scatterPlot1.GetYaxis().SetLabelOffset(0.012)
    scatterPlot1.SetMarkerColor(ROOT.kGray+1)
    scatterPlot1.SetMarkerSize(0.85)

    scatterPlot1.SetTitleSize(0.03,"X")
    scatterPlot1.SetLabelSize(0.03,"X")
    scatterPlot1.SetTitleSize(0.03,"Y")
    scatterPlot1.SetLabelSize(0.03,"Y")
    scatterPlot1.SetTitleSize(0.03,"Z")
    scatterPlot1.SetLabelSize(0.03,"Z")
    

    scatterPlot1.Draw("colz")
    latex_draw("300_150")
    
    Canvas2 = ROOT.TCanvas("Canvas2","Canvas2",0,0,900,900)
    Canvas2.SetRightMargin(0.15)
    
    scatterPlot2.GetXaxis().SetTitle(xaxislabel);
    scatterPlot2.GetYaxis().SetTitle(yaxislabel);
    scatterPlot2.GetYaxis().SetLabelOffset(0.012)
    scatterPlot2.SetMarkerColor(ROOT.kGray+1)
    scatterPlot2.SetMarkerSize(0.85)
    scatterPlot2.SetTitleSize(0.03,"X")
    scatterPlot2.SetLabelSize(0.03,"X")
    scatterPlot2.SetTitleSize(0.03,"Y")
    scatterPlot2.SetLabelSize(0.03,"Y")
    scatterPlot2.SetTitleSize(0.03,"Z")
    scatterPlot2.SetLabelSize(0.03,"Z")


    scatterPlot2.Draw("colz")
    latex_draw("400_150")

    Canvas4 = ROOT.TCanvas("Canvas4","Canvas4",0,0,900,900)
    Canvas4.SetRightMargin(0.15)
    
    scatterPlot4.GetXaxis().SetTitle(xaxislabel);
    scatterPlot4.GetYaxis().SetTitle(yaxislabel);
    scatterPlot4.GetYaxis().SetLabelOffset(0.012)
    scatterPlot4.SetMarkerColor(ROOT.kGray+1)
    scatterPlot4.SetMarkerSize(0.85)
    scatterPlot4.SetTitleSize(0.03,"X")
    scatterPlot4.SetLabelSize(0.03,"X")
    scatterPlot4.SetTitleSize(0.03,"Y")
    scatterPlot4.SetLabelSize(0.03,"Y")
    scatterPlot4.SetTitleSize(0.03,"Z")
    scatterPlot4.SetLabelSize(0.03,"Z")


    scatterPlot4.Draw("colz")
    latex_draw("ttbar")

    #Divide the two to see differences
    scatterPlot3=scatterPlot2.Clone()
    scatterPlot3.Divide(scatterPlot1)

    Canvas3 = ROOT.TCanvas("Canvas3","Canvas3",0,0,900,900)
    Canvas3.SetRightMargin(0.15)
    scatterPlot3.GetXaxis().SetTitle(xaxislabel);
    scatterPlot3.GetYaxis().SetTitle(yaxislabel);
    scatterPlot3.GetYaxis().SetLabelOffset(0.012)
    scatterPlot3.SetMarkerColor(ROOT.kGray+1)
    scatterPlot3.SetMarkerSize(0.85)
    scatterPlot3.SetTitleSize(0.03,"X")
    scatterPlot3.SetLabelSize(0.03,"X")
    scatterPlot3.SetTitleSize(0.03,"Y")
    scatterPlot3.SetLabelSize(0.03,"Y")
    scatterPlot3.SetTitleSize(0.03,"Z")
    scatterPlot3.SetLabelSize(0.03,"Z")

    scatterPlot3.Draw("colz")
    

    






    output_dir = "/user/hteagle//SummerAnalysis/Summer_Student_Analysis/histograms/CorrelationPlots/"
   
    change_me = directory+"/"+label+"/"
    output_dir = output_dir + change_me
    print("Directory is :"+str(output_dir))
    ensure_dir(output_dir)




    Canvas.SaveAs(output_dir+variable1+"_"+variable2+"300_150.pdf")
    Canvas2.SaveAs(output_dir+variable1+"_"+variable2+"400_250.pdf")
    Canvas4.SaveAs(output_dir+variable1+"_"+variable2+"ttbar.pdf")
    Canvas3.SaveAs(output_dir+variable1+"_"+variable2+"ratio.pdf")




    return

def getLinCorrelationPlot(variable1, variable2, xaxislabel, yaxislabel,xbins,xmin,xmax,ybins,ymin,ymax,inTree,xvariabletoplot,yvariabletoplot,cutstouse):

    #Draw the scatter first
    scatterPlot = ROOT.TH2F("scatterPlot","scatterPlot" , xbins, xmin, xmax, ybins, ymin, ymax)
    inTree.Draw(yvariabletoplot+":"+xvariabletoplot+">>scatterPlot", cutstouse)
    print("entries"+str(scatterPlot.GetEntries()))
    try:
         h_linCorr.Reset()
         print("reseting the hist")
    except:
        h_linCorr=ROOT.TH1D("linCorr","Linear Correlation between variables",15,-30,30)
    xmean=scatterPlot.GetMean(1)
    ymean=scatterPlot.GetMean(2)
    xrms=scatterPlot.GetRMS(1)
    yrms=scatterPlot.GetRMS(2)
    for entry in range(inTree.GetEntries()):
        inTree.GetEntry(entry)
        if xvariabletoplot.find("+")!=-1:
            print ("Splitting x varible into:"+str(xvariabletoplot.split("+")[0])+" and "+str(xvariabletoplot.split("+")[1]))
            x1 = inTree.GetLeaf(xvariabletoplot.split("+")[0]).GetValue()
            x1 = inTree.GetLeaf(xvariabletoplot.split("+")[1]).GetValue()
            x = x1+x1
        else:
            x = inTree.GetLeaf(xvariabletoplot).GetValue()
        if yvariabletoplot.find("+")!=-1:
            print ("Splitting y varible into:"+str(yvariabletoplot.split("+")[0])+" and "+str(yvariabletoplot.split("+")[0]))
            y1 = inTree.GetLeaf(yvariabletoplot.split("+")[0]).GetValue()
            y1 = inTree.GetLeaf(yvariabletoplot.split("+")[1]).GetValue()
            y = y1+y1
        else:
            y = inTree.GetLeaf(yvariabletoplot).GetValue()
        weight = inTree.GetLeaf('mcEventWeight').GetValue()
        linCorr=((x-xmean)*(y-ymean))/(xrms*yrms)
        h_linCorr.Fill(linCorr, weight)
    h_linCorr.SetLineColor
    h_linCorr.GetXaxis().SetTitle("Linear Correlation ("+xaxislabel+'vs'+yaxislabel+")");
    h_linCorr.GetYaxis().SetTitle('Events');
    h_linCorr.SetMaximum(h_linCorr.GetMaximum()*100)
    h_linCorr.SetMarkerSize(0.000001)
    h_linCorr.Sumw2()
    return h_linCorr

    

def LinCorrelationPlot(variable1, variable2, xaxislabel, yaxislabel, xmin, xmax, xbins, ymin, ymax, ybins,selection, directory, label, signalFile, signalFile_Truth, signalFile_TruthSmeared, signalFile_reco):

    gStyle.SetPaintTextFormat("1.0f");
    gStyle.SetPalette(1)
    plots={}

    xvariabletoplot = variable1
    yvariabletoplot = variable2
    cutstouse = "mcEventWeight*"+selection

    sigFile = ROOT.TFile(signalFile)
    sigTree = sigFile.Get("CollectionTree_")
    sigPlot = getLinCorrelationPlot(variable1, variable2, xaxislabel, yaxislabel,xbins,xmin,xmax,ybins,ymin,ymax,sigTree,xvariabletoplot,yvariabletoplot, cutstouse).Clone()
    sigPlot.SetLineColor(ROOT.kMagenta)
    sigPlot.Scale(1/sigPlot.Integral())
    sigPlot.Sumw2()

    sigFile_Truth = ROOT.TFile(signalFile_Truth)
    sigTree_Truth = sigFile_Truth.Get("CollectionTree_")
    sigPlot_Truth = getLinCorrelationPlot(variable1, variable2, xaxislabel, yaxislabel,xbins,xmin,xmax,ybins,ymin,ymax,sigTree_Truth,xvariabletoplot,yvariabletoplot, cutstouse).Clone()
    sigPlot_Truth.SetLineColor(ROOT.kMagenta+2)
    sigPlot_Truth.Scale(1/sigPlot_Truth.Integral())
    sigPlot_Truth.Sumw2()

    sigFile_TruthSmeared = ROOT.TFile(signalFile_TruthSmeared)
    sigTree_TruthSmeared = sigFile_TruthSmeared.Get("CollectionTree_")
    sigPlot_TruthSmeared = getLinCorrelationPlot(variable1, variable2, xaxislabel, yaxislabel,xbins,xmin,xmax,ybins,ymin,ymax,sigTree_TruthSmeared,xvariabletoplot,yvariabletoplot, cutstouse).Clone()
    sigPlot_TruthSmeared.SetLineColor(ROOT.kMagenta+4)
    sigPlot_TruthSmeared.Scale(1/sigPlot_TruthSmeared.Integral())
    sigPlot_TruthSmeared.Sumw2()

    # sigFile_reco = ROOT.TFile(signalFile_reco)
    # sigTree_reco = sigFile_reco.Get("CollectionTree_")
    # sigPlot_reco = getLinCorrelationPlot(variable1, variable2, xaxislabel, yaxislabel,xbins,xmin,xmax,ybins,ymin,ymax,sigTree_reco,xvariabletoplot,yvariabletoplot, cutstouse).Clone()
    # sigPlot_reco.SetLineColor(ROOT.kMagenta+6)
    # sigPlot_reco.Scale(1/sigPlot_reco.Integral())
    # sigPlot_reco.Sumw2()


   #Linear Correlation
    Canvas = ROOT.TCanvas("Canvas","Canvas",0,0,900,900)

    pad1 = ROOT.TPad("pad1","pad1",0,0.30,1,1)
    pad1.SetBottomMargin(0)
    pad1.Draw()
    pad2 = ROOT.TPad("pad2","pad2",0,0.065,1,0.30)
    pad2.SetTopMargin(0)
    pad2.SetBottomMargin(0.4)
    pad2.Draw()

    pad1.cd()
    pad1.SetLogy()
    Legend = ROOT.TLegend(0.20,0.64,0.46,0.78)
    Legend.SetTextSize(0.02)
    #Legend.SetTextFont(2)
    Legend.SetFillColor(0)
    Legend.SetFillStyle(0)
    Legend.SetBorderSize(0)

    Legend.AddEntry(sigPlot,"300_150","L")
    Legend.AddEntry(sigPlot_Truth,"400_250","L")
    Legend.AddEntry(sigPlot_TruthSmeared,"ttbar","L")
#    Legend.AddEntry(sigPlot_reco,"reco","L")

    sigPlot.DrawNormalized("Hist,E")
    sigPlot_Truth.DrawNormalized("Hist,same, E")
    sigPlot_TruthSmeared.DrawNormalized("Hist,same, E")
    #sigPlot_reco.DrawNormalized("Hist,same, E")
    latex_draw(xvariabletoplot+'_'+yvariabletoplot)
    Legend.Draw()

    pad2.cd()

    sigPlot_ratio = sigPlot.Clone()
    sigPlot_Truth_ratio = sigPlot_Truth.Clone()
    sigPlot_TruthSmeared_ratio = sigPlot_TruthSmeared.Clone()
    #sigPlot_reco_ratio = sigPlot_reco.Clone()
    
    # sigPlot_ratio.Divide(sigPlot_reco)
    # sigPlot_Truth_ratio.Divide(sigPlot_reco)
    # sigPlot_TruthSmeared_ratio.Divide(sigPlot_reco)
    # sigPlot_reco_ratio.Divide(sigPlot_reco)



    sigPlot_ratio.GetYaxis().SetTitle("Normalised ratio wrt reco")
    sigPlot_ratio.SetLabelSize(0.1,"X")
    sigPlot_ratio.SetLabelSize(0.1,"Y")
    sigPlot_ratio.SetTitleSize(0.1,"X")
    sigPlot_ratio.SetTitleSize(0.1,"Y")

    sigPlot_ratio.Draw("E1, Hist")
    sigPlot_Truth_ratio.Draw("Hist same, E1")
    sigPlot_TruthSmeared_ratio.Draw("Hist same, E1")
#    sigPlot_reco_ratio.Draw("Hist same, E1")


    middleLine = ROOT.TLine()
    middleLine.SetLineColor(ROOT.kRed)
    middleLine.DrawLine(-20,1,20,1)


    


    output_dir = "/user/hteagle//SummerAnalysis/Summer_Student_Analysis/histograms/CorrelationPlots/"
   
    change_me = directory+"/"+label+"/"
    output_dir = output_dir + change_me
    print("Directory is :"+str(output_dir))
    ensure_dir(output_dir)


    Canvas.SaveAs(output_dir+variable1+"_"+variable2+"correlation.pdf")
    return
