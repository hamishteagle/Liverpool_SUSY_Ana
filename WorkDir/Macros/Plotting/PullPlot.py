#!/usr/bin/env python                                                                                                                 
                                                                                                                                       
import os,sys,subprocess,datetime,copy,math,array,shutil,ROOT,string                                                                   
from ROOT import gROOT, TColor, TLatex, gStyle, TLegend, gPad, TAttText   

__author__ = "Hamish Teagle"
__doc__ = """Module for drawing a pull plot"""


def PullPlot(xaxislabel,SRs,SRvals,CRs,CRvals,VRs,VRvals,ymax,TotBkgError,directory,label,backgrounds):

    Datavec=[]
    ttbarvec=[]
    wjetsvec=[]
    zjetsvec=[]
    singleTopvec=[]
    Higgsvec=[]
    Dijet=[]
    ttVvec=[]
    with open('PullPlot/Data.txt', 'r') as DataIn:
        Datavec.append(DataIn.readline())
    with open('PullPlot/ttbar.txt', 'r') as ttbarIn:
        ttbarvec.append(ttbarIn.readline())
    with open('PullPlot/wjets.txt', 'r') as wjetsIn:
        wjetsvec.append(wjetsIn.readline())
    with open('PullPlot/zjets.txt', 'r') as zjetsIn:
        zjetsvec.append(zjetsIn.readline())
    with open('PullPlot/singleTop.txt', 'r') as singleTopIn:
        singleTopvec.append(singleTopIn.readline())
    with open('PullPlot/Higgs.txt', 'r') as HiggsIn:
        Higgsvec.append(HiggsIn.readline())
    with open('PullPlot/DiJet.txt', 'r') as DiJetIn:
        DiJetvec.append(DiJetIn.readline())
    with open('PullPlot/ttV.txt', 'r') as ttVIn:
        ttVvec.append(ttVIn.readline())
        







def BkgPlotter (SRs,SRvals,CRs,CRvals,VRs,VRvals,bkg):

    numberofbins=7
    Plot=ROOT.TH1D("Pull Plot","Title",numberofbins,0,numberofbins);
        

    #Filling for SRs
    num=1
    bin=1
    for i in SRs:
        Plot.SetBinLabel(num,i)
        num++
    for ival in SRvals:
        Plot.SetBinContent(bin,ival)
        bin++
    #Filling for CRs
    num=1
    for j in CRs:
        Plot.SetBinLabel(num,j)
        num++
    for jval in CRvals:
        Plot.SetBinContent(bin,jval)
        bin++
    #Filling for VRs
    num=1
    for k in VRs:
        Plot.SetBinLabel(num,k)
        num++
    for kval in VRvals:
        Plot.SetBinContent(bin,kval)
        bin++
    
    return Plot 
        

