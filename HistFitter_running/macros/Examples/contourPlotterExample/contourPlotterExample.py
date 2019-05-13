#!/usr/bin/env python

# contourPlotterExample.py #################
#
# Example for using contourPlotter.py
#
# See README for details
#
# By: Larry Lee - Dec 2017

import ROOT

import contourPlotter

drawTheorySysts = False

plot = contourPlotter.contourPlotter("/user/hteagle/SummerAnalysis/Summer_Student_Analysis/histograms/ContourPlots/CutAndCount",800,600)

plot.processLabel = "#tilde{#chi}_{1}^{#pm}/#tilde{#chi}_{2}^{0} production, #rightarrow W hbb"
plot.lumiLabel = "#sqrt{s}=13 TeV, 139 fb^{-1}, All limits at 95% CL"

## Just open up a root file with TGraphs in it so you can hand them to the functions below!

f = ROOT.TFile("/user/hteagle/AnalysisDirectory/Rel21/Base.21.2.72/athena/Projects/HistFitter_running/outputGraphs.root")

f.ls()

## Axes

plot.drawAxes( [0,0,1000,500] )

## Other limits to draw

# plot.drawShadedRegion( externalGraphs.curve, title="ATLAS 8 TeV, 20.3 fb^{-1} (observed)" )

## Main Result

plot.drawTextFromTGraph2D( f.Get("CLsexp_gr")  , angle=30 , title = "Grey Numbers Represent Expected CLs Value")

plot.drawExpected(      f.Get("Exp_0")       )
plot.drawOneSigmaBand(  f.Get("Band_1s_0")   )
#plot.drawObserved(      f.Get("Obs_0"), title="Observed Limit (#pm1 #sigma_{theory}^{SUSY})" if drawTheorySysts else "Observed Limit")

## Draw Lines

plot.drawLine(  coordinates = [120,0,620,500], label = "Kinematically Forbidden", style = 7, angle = 60 )

## Axis Labels

plot.setYAxisLabel( "m_{#tilde{#chi}_{1}^{0}} [GeV]" )
plot.setXAxisLabel( "m_{#tilde{#chi}_{1}^{#pm}/#tilde{#chi}_{2}^{0}} [GeV]"  )

plot.createLegend(shape=(0.22,0.75,0.55,0.85) ).Draw()

if drawTheorySysts:
	plot.drawTheoryUncertaintyCurve( f.Get("Obs_0_Up") )
	plot.drawTheoryUncertaintyCurve( f.Get("Obs_0_Down") )
	# coordinate in NDC
	plot.drawTheoryLegendLines( xyCoord=(0.234,0.6625), length=0.057 )

plot.decorateCanvas( )
plot.writePlot( )




