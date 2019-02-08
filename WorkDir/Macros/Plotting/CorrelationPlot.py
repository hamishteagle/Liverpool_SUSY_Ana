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
    Tl.DrawLatex(0.49, 0.89,"#sqrt{s} = 13 TeV, 3.2 fb^{-1}")
    Tl.DrawLatex(0.55, 0.94,"#it{#bf{ATLAS}} Internal")
    Tl.DrawLatex(0.35, 0.84,label)
   
def CorrelationPlot(variable1, variable2, xaxislabel, yaxislabel, xmin, xmax, xbins, ymin, ymax, ybins,selection, directory, label, inputFile1, inputFile2):

    inFile1 = ROOT.TFile(inputFile1)
    inTree1 = inFile1.Get("CollectionTree_")
    inFile2 = ROOT.TFile(inputFile2)
    inTree2 = inFile2.Get("CollectionTree_")


    

    print ("input files read in")



    xvariabletoplot = variable1
    xminvalue = xmin
    xmaxvalue = xmax
    xnbins = xbins

    yvariabletoplot = variable2
    yminvalue = ymin
    ymaxvalue = ymax
    ynbins = ybins
    cutstouse = selection

    gStyle.SetPaintTextFormat("1.0f");

    scatterPlot1 = ROOT.TH2F("scatterPlot1","scatterPlot1" , xnbins, xmin, xmax, ynbins, ymin, ymax)
    scatterPlot2 = ROOT.TH2F("scatterPlot2","scatterPlot2" , xnbins, xmin, xmax, ynbins, ymin, ymax)

    inTree1.Draw(yvariabletoplot+":"+xvariabletoplot+">>scatterPlot1", cutstouse)
    inTree2.Draw(yvariabletoplot+":"+xvariabletoplot+">>scatterPlot2", cutstouse)


#    gROOT.LoadMacro("../ATLAS_Style/atlasstyle-00-03-05/AtlasStyle.C")
#    ROOT.SetAtlasStyle()
    gStyle.SetPalette(1)
    




    Canvas = ROOT.TCanvas("Canvas1","Canvas1",0,0,900,900)
    
    Canvas.SetRightMargin(0.2)
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
    latex_draw("Reco_Signal")
    
    Canvas2 = ROOT.TCanvas("Canvas2","Canvas2",0,0,900,900)
    
    Canvas2.SetRightMargin(0.15)
    
    scatterPlot2.GetXaxis().SetTitle(xaxislabel);
    scatterPlot2.GetYaxis().SetTitle(yaxislabel);
    scatterPlot2.GetYaxis().SetLabelOffset(0.012)
    scatterPlot2.SetMarkerColor(ROOT.kGray+1)
    scatterPlot2.Draw("colz")
    latex_draw("TRUTHSmeared_Signal")





    output_dir = "/user/hteagle//SummerAnalysis/Summer_Student_Analysis/histograms/CorrelationPlots/"
   
    change_me = directory+"/"+label+"/"
    output_dir = output_dir + change_me
    print("Directory is :"+str(output_dir))
    ensure_dir(output_dir)




    Canvas.SaveAs(output_dir+"_"+variable1+"_"+variable2+"reco.eps")
    Canvas2.SaveAs(output_dir+"_"+variable1+"_"+variable2+"truth.eps")




    return
