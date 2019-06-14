#!/usr/bin/env python 
import os,sys,subprocess,datetime,copy,math,array,shutil,ROOT,string
from ROOT import gROOT, TColor, TLatex, gStyle, TLegend, gPad, TAttText
__author__ = "Hamish Teagle"
__doc__    = """Module to do a Ratio plot using the MasterPlot.py script
"""
global samples

import Samples.Wh1Lbb_21_2_75 as samples_class

#load the actual samples
samples=sample_class.LoadSamples()

# Make sure that Path exists for output files
def ensure_dir(d):
    if not os.path.isdir(d):
        os.makedirs(d)




def NewRatioPlot:
    
        
    



