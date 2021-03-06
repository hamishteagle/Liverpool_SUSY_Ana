#!/usr/bin/env python

import os,sys,subprocess,datetime,copy,math,array,shutil,ROOT,string, time
from ROOT import gROOT, TColor, TLatex, gStyle, TLegend, gPad, TAttText, TEfficiency

__author__ = "Hamish Teagle"
__doc__    = """Module to do turn-on curves from MasterPlot.py
"""

# Make sure that Path exists for output files
def ensure_dir(d):
    if not os.path.isdir(d):
        os.makedirs(d)
def latex_draw(label, triggerLabel):
    
    Tl = ROOT.TLatex()
    Tl.SetTextSize(0.035)
    Tl.SetTextAlign(13)
    Tl.SetNDC(True)
    Tl.DrawLatex(0.195, 0.87,"#sqrt{s} = 13 TeV")
    Tl.DrawLatex(0.195, 0.92,"#it{#bf{ATLAS}} Internal")
    Tl.DrawLatex(0.195, 0.82,label)
    Tl.DrawLatex(0.195, 0.76,triggerLabel+" SUSY1_noSelections")

def TurnOn(inputfile, trigger, variable, year, dateNow):
    
    
    infile = ROOT.TFile(inputfile)
    intree = infile.Get("CollectionTree_")

    xmin = 0
    xmax = 350
    numberofbins = 50
    
    passTrig = 'year == '+year+' && '+trigger
    passYear = 'year == '+year
    print("Has to pass this: "+str(passTrig))
    Variable_Raw = ROOT.TH1D("Variable_Raw","Title",numberofbins,xmin,xmax)
    Variable_Pass = ROOT.TH1D("Variable_Pass","Title",numberofbins,xmin,xmax)

    #Get the right errors
    Variable_Raw.Sumw2()
    Variable_Pass.Sumw2()


    Variable_Raw.SetLineColor(ROOT.kRed+1)
    Variable_Pass.SetLineColor(ROOT.kGreen-2)
    Variable_Raw.SetLineWidth(3)
    Variable_Pass.SetLineWidth(3)


    #Draw with and without the trigger requirements
    intree.Draw(variable+">> Variable_Raw", passYear)
    intree.Draw(variable+">> Variable_Pass", passTrig)

    #Make a clone for dividing them to get the curve
    Raw_Clone=Variable_Pass.Clone()
    #Raw_Clone.Divide(Raw_Clone, Variable_Raw,1,1, 'B')
    Raw_Clone.Divide(Variable_Raw)
    Raw_Clone.SetLineColor(ROOT.kBlack)
    Raw_Clone.SetLineWidth(3)
    Raw_Clone.GetXaxis().SetTitle(variable+"[GEV]")
    Raw_Clone.GetYaxis().SetTitle('Trigger Efficiency')
    Raw_Clone.GetYaxis().SetTitleOffset(0.5)
    Raw_Clone.SetTitleSize(0.05, 'X')
    Raw_Clone.SetTitleSize(0.05, 'Y')
    Raw_Clone.SetLabelSize(0.05, 'X')
    Raw_Clone.SetLabelSize(0.05, 'Y')
    Raw_Clone.GetYaxis().SetRangeUser(0,1.1)
    Raw_Clone.Sumw2()
    
    #Do all the actual drawing
    Canvas = ROOT.TCanvas("Canvas1","Canvas1",0,0,900,900)
    Legend = ROOT.TLegend(0.60,0.8,0.80,0.94)
    Legend.AddEntry(Variable_Raw,"No trig requirement","L")
    Legend.AddEntry(Variable_Pass,"Pass trig requirement","L")

    #Set the maximum to stay away from the latex part
    Variable_Raw.SetMaximum(Variable_Raw.GetMaximum()*100)


    #Get rid of markers 
    Variable_Raw.SetMarkerSize(0.0001)
    Variable_Pass.SetMarkerSize(0.0001)
    Raw_Clone.SetMarkerSize(0.0001)


    #Load the pads
    pad1 = ROOT.TPad("pad1","pad1",0,0.50,1,1)
    pad1.SetBottomMargin(0)
    pad1.SetLogy()
    pad1.Draw()

    pad2 = ROOT.TPad("pad2","pad2",0,0.065,1,0.50)
    pad2.SetTopMargin(0)
    pad2.SetBottomMargin(0.4)
    pad2.Draw()

    #Draw the top half
    pad1.cd()
    Variable_Raw.Draw("HIST E")
    Variable_Pass.Draw("HIST same E")
    label=variable+' trig turn-on: '+year
    if trigger.find('triggerDecisions[37]') !=-1:
        triggerLabel = 'HLT_xe110_pufit_xe70_L1XE50'
    if trigger.find('triggerDecisions[10]') !=-1 :
        triggerLabel = "1-L triggers"
    if inputfile.find('ttbar')!=-1:
        triggerLabel = triggerLabel+"_ttbar"
    if inputfile.find('data18')!=-1:
        triggerLabel = triggerLabel+"_data"

    latex_draw(label, triggerLabel)
    print (triggerLabel)
    Legend.Draw()

    #Draw the bottom
    pad2.cd()
    Raw_Clone.Draw("HIST, E")
    middleLine = ROOT.TLine()
    middleLine.SetLineColor(ROOT.kRed)
    middleLine.DrawLine(xmin,1,xmax,1)
    

    output_dir = "/user/hteagle//SummerAnalysis/Summer_Student_Analysis/histograms/TurnOnCurves/SbottomMB/21.2.60/"+dateNow+'/'
    ensure_dir(output_dir)
    Canvas.SaveAs(output_dir+variable+triggerLabel+".eps")


    return
