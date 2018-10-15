#!/usr/bin/env python

import os,sys,subprocess,datetime,copy,math,shutil,ROOT,string
from ROOT import gROOT, TColor, TLatex, gStyle, TLegend, gPad, TAttText
from array import array
__author__ = "John Anders"
__doc__    = """Module to do a shape plot using the MasterPlot.py script
"""

# Make sure that Path exists for output files
def ensure_dir(d):
    if not os.path.isdir(d):
        os.makedirs(d)

# Draws latex on the plots
def latex_draw(label):
    
    Tl = ROOT.TLatex()
    Tl.SetTextSize(0.035)
    Tl.SetTextAlign(13)
    Tl.SetNDC(True)
    Tl.DrawLatex(0.775, 0.715,"#splitline{#int Ldt = 36.1 fb^{-1}}{#sqrt{s} = 13 TeV}")
    Tl.DrawLatex(0.2, 0.92,"#it{#bf{ATLAS}} Internal")
    #Tl.DrawLatex(0.2, 0.82,"E_{T}^{Miss} > 150 GeV, p_{T}^{#gamma} > 130 GeV")
    
#    Tl.DrawLatex(0.60, 0.520,label)



def ShapePlot1(variable, xaxislabel, xmin, xmax, rebin, ymax, selection, directory, label, inputSample1, phiplot, etaplot,doLog):

    inSample1 = ROOT.TFile(inputSample1)
    inTree1 = inSample1.Get("CollectionTree_")

    inSample2 = ROOT.TFile(inputSample1)
    inTree2 = inSample2.Get("CollectionTree_")

    inSample3 = ROOT.TFile(inputSample1)
    inTree3 = inSample3.Get("CollectionTree_")

    inSample4 = ROOT.TFile(inputSample1)
    inTree4 = inSample4.Get("CollectionTree_")



    output_dir = "Histograms/"
   
#    change_me = directory+"/"+label+"/Loose/"
    change_me = directory+"/"+label+"/"
    output_dir = output_dir + change_me
    ensure_dir(output_dir)
    histtoplot = variable+"_"+label
    variabletoplot = variable
    minvalue = xmin
    maxvalue = xmax 
    rebinvalue = rebin

    cutstouseZ = "1"
    cutstousePhPy = "1"
    cutstousePh = "1"
    cutstouseZLO = "1"
    

    preselection = "pTj1 > 50 && pTj2 > 50 && (nJets == 2 || nJets == 3 || (nJets == 4 && pTj4 < 50)) "
    
    #cutstousejjll = "finalXSectScale*mcEventWeight*(nBaselineLeptons == 0 && nLeptons == 0 && (nMuons == 0 && nElectrons == 0)  && nBJets == 0 && (ETMiss > 250) && adjustedRatio> 0.25 && minDPhijMET> 0.4 && " + preselection  
    cutstousejjll = "finalXSectScale*mcEventWeight*(nBaselineLeptons == 0 && nLeptons == 0 && nJets >= 2 && nBJets == 0 && ETMiss > 250 && pTj1 > 130 && ratioMETmEff > 0.4 && minDPhijMET> 0.4 &&  " + preselection


    cutstousebbnunu = "finalXSectScale*mcEventWeight*(nBaselineLeptons == 0 && nLeptons == 0 && nJets >= 2 && nBJets == 2 && ETMiss > 250 && leadingbs && pTj1 > 130 && ratioMETmEff > 0.4 && minDPhijMET> 0.4 &&  " + preselection

    #cutstousebbll ="finalXSectScale*mcEventWeight*(nBaselineLeptons == 0 && nLeptons == 0 && (nMuons == 0 && nElectrons == 0) && nJets>= 2 && nBJets == 2 && (ETMiss > 250) && nBJets == 2 && leadingbs && pTj1 > 130 && adjustedRatio> 0.25 && minDPhijMET> 0.4 &&" + preselection 

    cutstousebbll = "finalXSectScale*mcEventWeight*(nBaselineLeptons == 0 && nLeptons == 0 && nJets >= 2 && nBJets == 2 && ETMiss > 250 && leadingbs && pTj1 > 130 && ratioMETmEff > 0.4 && minDPhijMET> 0.4 &&  " + preselection

    addedbit = ")"
    #addedbit = ""
    
    if "j2" in variabletoplot:
        addedbit = " && nJets >= 2)"
    if "j3" in variabletoplot:
        addedbit = " && nJets >= 3)"
    if "j4" in variabletoplot:
        addedbit = " && nJets >= 4)"
    
    if "m_bb" in variabletoplot:
        addedbit = " && nBJets == 2)"
        
        
        
    cutstousebbnunu += addedbit
    cutstousebbll += addedbit
    cutstousejjll += addedbit


    if rebinvalue > 1 and not phiplot and not etaplot:
        xaxislabel = xaxislabel+" [GeV]"
        

    numberofbins = xmax-xmin

    if rebinvalue == 1 and not phiplot and not etaplot:
        numberofbins = 20

    elif phiplot:
        numberofbins = 20

    elif etaplot:
        numberofbins = 22
        xmax = xmax + 1

    else:
        xmax = xmax



    if (variabletoplot == "m_CT"):
        xbins = array('f',[0,50,100,150,200,250,300,400,500,1000])
        inPlot1 = ROOT.TH1D("inPlot1","Title", 9, xbins )
        inTree1.Draw(variabletoplot+">>inPlot1",cutstousebbnunu)
        
    
        
        inPlot2 = ROOT.TH1D("inPlot2","Title",9, xbins  )
        inTree2.Draw(variabletoplot+">>inPlot2",cutstousebbll)
        
        inPlot3 = ROOT.TH1D("inPlot3","Title", 9, xbins  )
        inTree3.Draw(variabletoplot+">>inPlot3",cutstousejjll)
        
        inPlot4 = ROOT.TH1D("inPlot4","Title",9, xbins  )
        inTree4.Draw(variabletoplot+">>inPlot4",cutstousebbll)
        
        
    else:


    
        inPlot1 = ROOT.TH1D("inPlot1","Title",numberofbins,xmin,maxvalue )
        inTree1.Draw(variabletoplot+">>inPlot1",cutstousebbnunu)
    #ScaleF1 = 1/inPlot1.Integral()
        
        
        if (variabletoplot == "ETMiss"):
            variabletoplot = "adjustedETMiss"

        inPlot2 = ROOT.TH1D("inPlot2","Title",numberofbins,xmin,maxvalue )
        inTree2.Draw(variabletoplot+">>inPlot2",cutstousebbll)

    
        inPlot3 = ROOT.TH1D("inPlot3","Title",numberofbins,xmin,maxvalue )
        inTree3.Draw(variabletoplot+">>inPlot3",cutstousejjll)
    
    
        inPlot4 = ROOT.TH1D("inPlot4","Title",numberofbins,xmin,maxvalue )
        inTree4.Draw(variabletoplot+">>inPlot4",cutstousebbll)
    

   
        inPlot4 = ROOT.TH1D("inPlot4","Title",numberofbins,xmin,maxvalue )
        inTree4.Draw(variabletoplot+">>inPlot4",cutstousebbll)
    

    

    
    ScaleF1 = 1/inPlot1.Integral()
    inplot1Entries = inPlot1.GetEntries()
    ScaleF1 = 1
    inPlot1Division = inPlot1.Clone()
    inPlot1.Sumw2()

    inPlot2.Sumw2()
    ScaleF2 = 1/inPlot2.Integral()
    inplot2Entries = inPlot2.GetEntries()
    ScaleF2 = 1
    

    inPlot3.Sumw2()

    ScaleF3 = 1/inPlot3.Integral()
    inplot3Entries = inPlot3.GetEntries()
    ScaleF3 = 1
    
    inPlot4.Sumw2()

    inPlot4.Sumw2()
    ScaleF4 = 1/inPlot4.Integral()
    inplot4Entries = inPlot4.GetEntries()
    ScaleF4 = 1
    
    

    print "Number of entries in bbnunu: " , inplot1Entries, " in bbll: ", inplot2Entries 

    Canvas = ROOT.TCanvas("Canvas1","Canvas1",0,0,900,900)

    pad1 = ROOT.TPad("pad1","pad1",0,0.30,1,1)
    pad1.SetBottomMargin(0)
    
    if doLog:
        pad1.SetLogy()
    
    pad1.Draw()

    pad2 = ROOT.TPad("pad2","pad2",0,0.05,1,0.30)
    pad2.SetTopMargin(0)
    pad2.Draw()


    pad1.cd()


   
   
    inPlot1.GetXaxis().SetRangeUser(minvalue,maxvalue)
    inPlot2.GetXaxis().SetRangeUser(minvalue,maxvalue)
    inPlot3.GetXaxis().SetRangeUser(minvalue,maxvalue)
    inPlot4.GetXaxis().SetRangeUser(minvalue,maxvalue)
    inPlot1Division.GetXaxis().SetRangeUser(minvalue,maxvalue)
    
    if not phiplot and not etaplot:
        inPlot1.Rebin(rebinvalue)
        inPlot2.Rebin(rebinvalue)
        inPlot3.Rebin(rebinvalue)
        inPlot4.Rebin(rebinvalue)
        inPlot1Division.Rebin(rebinvalue)
    


    # Make Clones of the 2 plots here, sumw2 them, then divide by inplot1 (the Z)

    inPlot1.SetMarkerColor(ROOT.kBlack)
    inPlot1.SetMarkerStyle(2)
    inPlot1.SetMarkerSize(2)
    inPlot1.SetLineColor(ROOT.kBlack)
    inPlot1.SetLineWidth(1)

    inPlot1Division.SetMarkerColor(ROOT.kBlack)
    inPlot1Division.SetMarkerStyle(2)
    inPlot1Division.SetMarkerSize(2)
    inPlot1Division.SetLineColor(ROOT.kBlack)
    inPlot1Division.SetLineWidth(1)

    inPlot2.SetMarkerColor(ROOT.kRed)
    inPlot2.SetLineColor(ROOT.kRed)
    inPlot2.SetMarkerStyle(20)
    inPlot2.SetMarkerSize(1)

    inPlot3.SetMarkerColor(ROOT.kBlack)
    inPlot3.SetLineColor(ROOT.kBlack)
    inPlot3.SetMarkerStyle(21)
    inPlot3.SetMarkerSize(1)

    inPlot4.SetMarkerColor(ROOT.kGreen+3)
    inPlot4.SetLineColor(ROOT.kGreen+3)
    inPlot4.SetMarkerStyle(22)
    inPlot4.SetMarkerSize(1)

    ScaleF1 = 1
    ScaleF2 = 1
    ScaleF3 = 1
    ScaleF4 = 1

    inPlot1.Scale(ScaleF1)
    inPlot1Division.Scale(ScaleF1)
    inPlot2.Scale(ScaleF2)
    inPlot3.Scale(ScaleF3)
    inPlot4.Scale(ScaleF4)



    
    tempInPlot1 = inPlot1Division.Clone()
    tempInPlot1.Sumw2()
    tempInPlot1.Divide(inPlot1Division)
    tempInPlot2 = inPlot2.Clone()
    tempInPlot2.Divide(inPlot1)
    tempInPlot3 = inPlot3.Clone()
    tempInPlot3.Divide(inPlot1)
    tempInPlot4 = inPlot4.Clone()
    tempInPlot4.Divide(inPlot1)
    tempInPlot5 = inPlot3.Clone()
    tempInPlot5.Divide(inPlot2)


    Legend = ROOT.TLegend(0.66,0.72,0.97,0.92)


    Legend.AddEntry(inPlot1,"SRA Selection", "l")
    Legend.AddEntry(inPlot2,"CR2b2L Selection", "p")
    #Legend.AddEntry(inPlot3,"CR0b2L Selection", "p")
    #Legend.AddEntry(inPlot4,"#frac{bbll | jjll}{bbnunu} (Ratio)", "p")
    Legend.SetTextSize(0.03)
    Legend.SetFillColor(0)
    Legend.SetFillStyle(0)
    Legend.SetBorderSize(0) 

    inPlot1.SetXTitle(xaxislabel)
    inPlot1.SetTitleSize(0.03,"X")
    inPlot1.SetLabelSize(0.03,"X")

    if rebinvalue > 1 and not phiplot and not etaplot:
        inPlot1.SetYTitle("Events / "+str(rebinvalue)+" GeV")
    elif phiplot:
        inPlot1.SetYTitle("Events / #frac{#Pi}{10}")
    elif etaplot:
        inPlot1.SetYTitle("Events")
    else:
        inPlot1.SetYTitle("Events / "+str(rebinvalue)+" GeV^#frac{1}{2}")

    inPlot1.SetTitleSize(0.03,"Y")
    inPlot1.SetLabelSize(0.03,"Y")
    inPlot1.SetMinimum(0.02)
    inPlot1.SetMaximum(1000000)

#    inPlot1.DrawNormalized("")
#    inPlot2.DrawNormalized("same p")
#    inPlot3.DrawNormalized("same p")
    inPlot1.Draw("E1 X0")
    inPlot1Division.Draw("same")
    inPlot2.Draw("same p E1 X0")
    #inPlot3.Draw("same p E1 X0")
    #inPlot4.Draw("same p")
    
    print "1 - ", inPlot1.Integral(), " 2 - ", inPlot2.Integral(), " 3 - ", inPlot3.Integral()
    lo,hi = inPlot1.FindBin(0), inPlot1.FindBin(2500)
    print "1 - ", inPlot1.Integral(lo,hi), " 2 - ", inPlot2.Integral(lo,hi), " 3 - ", inPlot3.Integral(lo,hi)

    latex_draw(label)
    Legend.Draw()


    pad2.cd()


    for bin in range (0,tempInPlot1.GetNbinsX()+1):
        if tempInPlot1.GetBinContent(bin) == 0:
            tempInPlot1.SetBinContent(bin,1)

    tempInPlot1.GetYaxis().SetTitleOffset(0.6)
    tempInPlot1.SetTitleSize(0.07,"Y")
    tempInPlot1.SetLabelSize(0.07,"Y")
    tempInPlot1.SetMinimum(0)
    tempInPlot1.SetMaximum(1)
    tempInPlot1.SetYTitle("#frac{CR2b2L}{SRA}")

    tempInPlot1.SetTitleSize(0.07,"X")
    tempInPlot1.SetLabelSize(0.07,"X")
    tempInPlot1.SetXTitle(xaxislabel)
    tempInPlot1.GetYaxis().CenterTitle()

    tempInPlot2.SetMarkerColor(ROOT.kRed)
    tempInPlot2.SetMarkerStyle(20)
    tempInPlot2.SetMarkerSize(1)


    if (variabletoplot == "m_CT"): 


        print "Total ratio for bbnunu/jjll = ", inPlot2.Integral()/inPlot1.Integral()
        print "Total ratio for bbll/jjll = ",  inPlot3.Integral()/inPlot1.Integral()
        print "Total ratio for bbll/jjll = ", inPlot2.Integral()/inPlot3.Integral()

        e1 = ROOT.Double()
        n1 = inPlot1.IntegralAndError(0, maxvalue, e1)
        e2 = ROOT.Double()
        n2 = inPlot2.IntegralAndError(0, maxvalue, e2)
        e3 = ROOT.Double()
        n3 = inPlot3.IntegralAndError(0, maxvalue, e3)
        print "jjll Integral and Error", n1, ", " , e1
        print "bbnunu Integral and Error ", n2, ", " , e2
        print "bbll Integral and Error ", n3, ", " , e3

        

        print "Total ratio for bbnunu/jjll = ", n2/n1
        print "Total ratio for bbll/jjll = ",  n3/n1
        print "Total ratio for bbll/jjll = ", n2/n3, "Total error for bbll/jjll = ", (n2/n3)*(( (e2/n2)**2 + (e3/n3)**2 )**0.5)

        print "Total error for bbnunu/bbll = ", (n2/n1)*(( (e2/n2)**2 + (e1/n1)**2 )**0.5)
        print "Total error for bbll/jjll = ", (n3/n1)*(( (e3/n3)**2 + (e1/n1)**2 )**0.5)
        print "Total error for bbll/jjll = ", (n2/n3)*(( (e2/n2)**2 + (e3/n3)**2 )**0.5)


        
        


        print "x_low ", "x_high", "bbnunu/jjll", "jjll/bbnunu"
        for bin in range (1,tempInPlot2.GetNbinsX()+1):
            if tempInPlot2.GetBinContent(bin) != 0:
                print (bin-1)*50, bin*50, tempInPlot2.GetBinContent(bin), 1/tempInPlot2.GetBinContent(bin)
                if bin ==2:
                    print "Red content: ", inPlot2.GetBinContent(bin), inPlot2.GetBinError(bin)
                    print "black line content: ", inPlot1.GetBinContent(bin),  inPlot1.GetBinError(bin)
            else:
                print (bin-1)*50, bin*50, tempInPlot2.GetBinContent(bin) , "0"
        print "x_low ", "x_high", "bbll/jjll", "jjll/bbll"
        for bin in range (1,tempInPlot3.GetNbinsX()+1):
            if tempInPlot3.GetBinContent(bin) != 0:
                print (bin-1)*50, bin*50, tempInPlot3.GetBinContent(bin), 1/tempInPlot3.GetBinContent(bin)
            else:
                print (bin-1)*50, bin*50, tempInPlot3.GetBinContent(bin), "0"

    tempInPlot3.SetMarkerColor(ROOT.kBlack)
    tempInPlot3.SetMarkerStyle(21)
    tempInPlot3.SetMarkerSize(1)

    tempInPlot5.SetMarkerColor(ROOT.kGreen+3)
    tempInPlot5.SetMarkerStyle(22)
    tempInPlot5.SetMarkerSize(1)



    #tempInPlot2.Draw("same E1 X0")


    tempInPlot1.SetFillColor(ROOT.kGray+1)
    tempInPlot1.SetFillStyle(3004)
    #tempInPlot1.SetMarkerSize(0.00000000001)
    tempInPlot1.SetMarkerSize(0)

    middleLine = ROOT.TLine()
    middleLine.SetLineColor(ROOT.kBlack)


    #ROOT.gStyle.SetErrorX(0) 
    #tempInPlot2.Scale(inPlot1.Integral()/inPlot2.Integral())
    #tempInPlot3.Scale(inPlot1.Integral()/inPlot3.Integral())


    tempInPlot1.Draw("E2")
    tempInPlot2.Draw("same E1 X0")
    #tempInPlot3.Draw("same E1 X0")
    middleLine.DrawLine(minvalue,1,maxvalue,1)

    #tempInPlot3.Draw("same E1 X0")
    #tempInPlot5.Draw("same P")




    Canvas.SaveAs(output_dir + histtoplot +".png")
    Canvas.SaveAs(output_dir + histtoplot +".pdf")
    Canvas.SaveAs(output_dir + histtoplot +".eps")
    Canvas.SaveAs(output_dir + histtoplot +".C")

    if (variabletoplot == "m_CT"):
        outputMCTFile = ROOT.TFile("SF_mCT_bbll.root", "new")
        tempInPlot2.Write()
        outputMCTFile.Write()
        outputMCTFile.Close()
        Canvas.SaveAs(output_dir + histtoplot +".root")
        print "Histo produced",output_dir+histtoplot+".root"

    print "Histo produced",output_dir+histtoplot+".png"
    print "Histo produced",output_dir+histtoplot+".pdf"
    print "Histo produced",output_dir+histtoplot+".eps"
    print "Histo produced",output_dir+histtoplot+".C"

    return



def ShapePlot2(variable, xaxislabel, xmin, xmax, rebin, ymax, selection, directory, label, inputSample1, inputSample2, phiplot, etaplot,doLog):

    inSample1 = ROOT.TFile(inputSample1)
    inTree1 = inSample1.Get("CollectionTree_")

    inSample2 = ROOT.TFile(inputSample2)
    inTree2 = inSample2.Get("CollectionTree_")



    output_dir = "Histograms/"
   
#    change_me = directory+"/"+label+"/Loose/"
    change_me = directory+"/"+label+"/ShapePlot/"
    output_dir = output_dir + change_me
    ensure_dir(output_dir)
    histtoplot = variable+"_"+label
    variabletoplot = variable
    minvalue = xmin
    maxvalue = xmax 
    rebinvalue = rebin

    luminosity = "36.1*JVTSF*electronTriggerSF*muonSF*electronSF*puWgt*finalXSectScale*mcEventWeight*bJetSF*"

    cutstousePh = luminosity+selection
    cutstouseZ = luminosity+selection


    if rebinvalue > 1 and not phiplot and not etaplot:
        xaxislabel = xaxislabel+" [GeV]"
        

    numberofbins = xmax-xmin

    if rebinvalue == 1 and not phiplot and not etaplot:
        numberofbins = 20

    elif phiplot:
        numberofbins = 10

    elif etaplot:
        numberofbins = 22
        xmax = xmax + 1

    else:
        xmax = xmax


    

    inPlot1 = ROOT.TH1D("inPlot1","Title",numberofbins,xmin,maxvalue )
    inPlot1.Sumw2()
    inTree1.Draw(variabletoplot+">>inPlot1",cutstouseZ)

    inPlot2 = ROOT.TH1D("inPlot2","Title",numberofbins,xmin,maxvalue )
    inPlot2.Sumw2()
    inTree2.Draw(variabletoplot+">>inPlot2",cutstousePh)

    Canvas = ROOT.TCanvas("Canvas1","Canvas1",0,0,900,900)

    pad1 = ROOT.TPad("pad1","pad1",0,0.35,1,1)
    pad1.SetBottomMargin(0.1)
    
    pad1.SetLogy()
    pad1.Draw()

    pad2 = ROOT.TPad("pad2","pad2",0,0.05,1,0.35)
    pad2.SetTopMargin(0.1)
    pad2.Draw()


    pad1.cd()


   
   
    inPlot1.GetXaxis().SetRangeUser(minvalue,maxvalue)
    inPlot2.GetXaxis().SetRangeUser(minvalue,maxvalue)

    if not phiplot and not etaplot:
        inPlot1.Rebin(rebinvalue)
        inPlot2.Rebin(rebinvalue)
        


    # Make Clones of the 2 plots here, sumw2 them, then divide by inplot1 (the Z)

    #inPlot1.SetMarkerColor(ROOT.kBlue)
    #inPlot1.SetMarkerStyle(2)
    inPlot1.SetMarkerSize(0.00000001)
    #inPlot1.SetLineColor(ROOT.kBlue)
    #inPlot1.SetLineWidth(2)

    inPlot2.SetLineColor(ROOT.kRed)
    inPlot2.SetMarkerColor(ROOT.kRed)
    #inPlot2.SetMarkerStyle(2)
    #inPlot2.SetMarkerSize(2)


    tempInPlot1 = inPlot1.Clone()
    tempInPlot1.Divide(inPlot1)
    tempInPlot2 = inPlot2.Clone()
    tempInPlot2.Divide(inPlot1)

    Legend = ROOT.TLegend(0.6,0.72,0.99,0.92)


    Legend.AddEntry(inPlot1,"Powheg t#bar{t} ", "l")
    Legend.AddEntry(inPlot2,"Sherpa t#bar{t}", "l")
    Legend.SetTextSize(0.03)
    #Legend.SetTextFont(2)
    Legend.SetFillColor(0)
    Legend.SetFillStyle(0)
    Legend.SetBorderSize(0)
  

    inPlot1.SetXTitle(xaxislabel)
    inPlot1.SetTitleSize(0.03,"X")
    inPlot1.SetLabelSize(0.03,"X")

    if rebinvalue > 1 and not phiplot and not etaplot:
        inPlot1.SetYTitle("Events / "+str(rebinvalue)+" GeV")
    elif phiplot:
        inPlot1.SetYTitle("Events / #frac{#Pi}{20}")
    elif etaplot:
        inPlot1.SetYTitle("Events")
    else:
        inPlot1.SetYTitle("Events / "+str(rebinvalue)+" GeV^#frac{1}{2}")

    inPlot1.SetTitleSize(0.03,"Y")
    inPlot1.SetLabelSize(0.03,"Y")
    inPlot1.SetMinimum(0.1)
    inPlot1.SetMaximum(50000)

    temporaryHack = inPlot1.Clone()
    temporaryHack.SetFillColor(ROOT.kBlack)
    temporaryHack.SetFillStyle(3004)
    temporaryHack.SetMarkerSize(0.000000001)
    
    inPlot1.Draw("HIST")
    temporaryHack.Draw("same E2")
    inPlot2.Draw("same E1 X0")
    
    latex_draw(label)
    Legend.Draw()


    pad2.cd()


    for bin in range (0,tempInPlot1.GetNbinsX()+1):
        if tempInPlot1.GetBinContent(bin) == 0:
            tempInPlot1.SetBinContent(bin,1)

    tempInPlot1.GetYaxis().SetTitleOffset(0.6)
    tempInPlot1.SetTitleSize(0.07,"Y")
    tempInPlot1.SetLabelSize(0.07,"Y")
    tempInPlot1.SetMinimum(0.4)
    tempInPlot1.SetMaximum(1.6)
    tempInPlot1.SetYTitle("#frac{Sherpa}{Powheg}")

    tempInPlot1.SetTitleSize(0.07,"X")
    tempInPlot1.SetLabelSize(0.07,"X")
    tempInPlot1.SetXTitle(xaxislabel)

    tempInPlot1.SetFillColor(ROOT.kBlack)
    tempInPlot1.SetFillStyle(3004)


    #tempInPlot2.SetMarkerStyle(22)
    tempInPlot2.SetMarkerColor(ROOT.kRed)
    tempInPlot2.Fit("pol1")

    middleLine = ROOT.TLine()
    middleLine.SetLineColor(ROOT.kRed)
    tempInPlot1.SetMarkerSize(0.00000001)

    tempInPlot1.Draw("E2")
    tempInPlot2.Draw("P same E1 X0")

    tempInPlot2.Draw("PE same X0")
    oldSize = tempInPlot2.GetMarkerSize()
    tempInPlot2.SetMarkerSize(0)
    tempInPlot2.DrawCopy("same E0 X0")
    tempInPlot2.SetMarkerSize(oldSize)
    tempInPlot2.Draw("PE same X0")
    middleLine.DrawLine(minvalue,1,maxvalue,1)




    Canvas.SaveAs(output_dir + histtoplot +".png")
    Canvas.SaveAs(output_dir + histtoplot +".eps")
    Canvas.SaveAs(output_dir + histtoplot +".C")

    print "Histo produced",output_dir+histtoplot+".png"
    print "Histo produced",output_dir+histtoplot+".eps"
    print "Histo produced",output_dir+histtoplot+".C"

    return




def ShapePlot4(variable, xaxislabel, xmin, xmax, rebin, ymax, selection, directory, label, inputSample1, inputSample2, inputSample3, inputSample4, phiplot, etaplot,doLog):

    inSample1 = ROOT.TFile(inputSample1)
    inTree1 = inSample1.Get("CollectionTree_")

    inSample2 = ROOT.TFile(inputSample2)
    inTree2 = inSample2.Get("CollectionTree_")

    inSample3 = ROOT.TFile(inputSample3)
    inTree3 = inSample3.Get("CollectionTree_")

    inSample4 = ROOT.TFile(inputSample4)
    inTree4 = inSample4.Get("CollectionTree_")



    output_dir = "Histograms/"
   
#    change_me = directory+"/"+label+"/Loose/"
    change_me = directory+"/"+label+"/"
    output_dir = output_dir + change_me
    ensure_dir(output_dir)
    histtoplot = variable+"_"+label
    variabletoplot = variable
    minvalue = xmin
    maxvalue = xmax 
    rebinvalue = rebin

    cutstouseZ = "1"
    cutstousePhPy = "1"
    cutstousePh = "1"
    cutstouseZLO = "1"
    

    #cutstouseZ = selection+")" 
    #cutstousePh = selection+"&& nPhoton == 1 && pTgamma > 130)" 

    cutstouseZLO = "finalXSectScale*mcEventWeight*(nBaselineLeptons == 0 && nPhoton == 0 && ETMiss > 150"  
    cutstousePhPy = "mcEventWeight*(nBaselineLeptons == 0 && nPhoton == 1 && pTgamma > 130"  


    cutstouseZ = "finalXSectScale*mcEventWeight*(nBaselineLeptons == 0 && nPhoton == 0 && ETMiss > 150" 
    cutstousePh = "finalXSectScale*mcEventWeight*(nBaselineLeptons == 0 && nPhoton == 1 && pTgamma > 130 && ETMiss > 150 " 
    
    addedbit = ")"
    #addedbit = ""
    
    if "j2" in variabletoplot:
        addedbit = " && nJets >= 2)"
    if "j3" in variabletoplot:
        addedbit = " && nJets >= 3)"
    if "j4" in variabletoplot:
        addedbit = " && nJets >= 4)"
    #if "m_bb" in variabletoplot or "m_CT" in variabletoplot:
        #addedbit = " && nBJets == 2)"



    cutstouseZLO += addedbit
    cutstouseZ += addedbit
    cutstousePh += addedbit
    cutstousePhPy += addedbit

    if rebinvalue > 1 and not phiplot and not etaplot:
        xaxislabel = xaxislabel+" [GeV]"
        

    numberofbins = xmax-xmin

    if rebinvalue == 1 and not phiplot and not etaplot:
        numberofbins = 20

    elif phiplot:
        numberofbins = 20

    elif etaplot:
        numberofbins = 22
        xmax = xmax + 1

    else:
        xmax = xmax



    #tempZ = ROOT.TH1D("tempZ","Title",numberofbins,xmin,maxvalue )
    #inTree1.Draw("1>>tempZ",cutstouseZ)

    #tempgamma = ROOT.TH1D("tempgamma","Title",numberofbins,xmin,maxvalue )
    #inTree3.Draw("1>>tempgamma",cutstousePh)
    
    #print "number of scaled Z Events = ", tempZ.Integral()
    #print "number of scaled Gamma Events = ", tempgamma.Integral()
    

    inPlot1 = ROOT.TH1D("inPlot1","Title",numberofbins,xmin,maxvalue )
    inPlot1.Sumw2()
    inTree1.Draw(variabletoplot+">>inPlot1",cutstouseZ)
    
    

    inPlot1 = ROOT.TH1D("inPlot1","Title",numberofbins,xmin,maxvalue )
    inTree1.Draw(variabletoplot+">>inPlot1",cutstouseZ)
    
    #ScaleF1 = 1/inPlot1.Integral()
    inplot1Entries = inPlot1.GetEntries()
    ScaleF1 = 1
    inPlot1Division = inPlot1.Clone()
    
    inPlot2 = ROOT.TH1D("inPlot2","Title",numberofbins,xmin,maxvalue )

    inPlot2.Sumw2()
    inTree2.Draw(variabletoplot+">>inPlot2",cutstouseZLO)

    #ScaleF2 = 1/inPlot2.Integral()
    inplot2Entries = inPlot2.GetEntries()
    ScaleF2 = 1
    
    inPlot3 = ROOT.TH1D("inPlot3","Title",numberofbins,xmin,maxvalue )
    inPlot3.Sumw2()
    if variabletoplot == "pTZBoson":
        inTree3.Draw("pTgamma>>inPlot3",cutstousePh)
    else:
        inTree3.Draw(variabletoplot+">>inPlot3",cutstousePh) 

    #ScaleF3 = 1/inPlot3.Integral()
    inplot3Entries = inPlot3.GetEntries()
    ScaleF3 = 1
    
    inPlot4 = ROOT.TH1D("inPlot4","Title",numberofbins,xmin,maxvalue )
    inPlot4.Sumw2()
    inTree4.Draw(variabletoplot+">>inPlot4",cutstousePhPy)

    #ScaleF4 = 1/inPlot4.Integral()
    inplot4Entries = inPlot4.GetEntries()
    ScaleF4 = 1
    

    Canvas = ROOT.TCanvas("Canvas1","Canvas1",0,0,900,900)

    pad1 = ROOT.TPad("pad1","pad1",0,0.30,1,1)
    pad1.SetBottomMargin(0)
    doLog = True
    if doLog:
        pad1.SetLogy()
    
    pad1.Draw()

    pad2 = ROOT.TPad("pad2","pad2",0,0.05,1,0.30)
    pad2.SetTopMargin(0)
    pad2.Draw()


    pad1.cd()


   
   
    inPlot1.GetXaxis().SetRangeUser(minvalue,maxvalue)
    inPlot2.GetXaxis().SetRangeUser(minvalue,maxvalue)
    inPlot3.GetXaxis().SetRangeUser(minvalue,maxvalue)
    inPlot4.GetXaxis().SetRangeUser(minvalue,maxvalue)
    inPlot1Division.GetXaxis().SetRangeUser(minvalue,maxvalue)
    
    if not phiplot and not etaplot:
        inPlot1.Rebin(rebinvalue)
        inPlot2.Rebin(rebinvalue)
        inPlot3.Rebin(rebinvalue)
        inPlot4.Rebin(rebinvalue)
        inPlot1Division.Rebin(rebinvalue)
    


    # Make Clones of the 2 plots here, sumw2 them, then divide by inplot1 (the Z)

    inPlot1.SetMarkerColor(ROOT.kBlue)
    inPlot1.SetMarkerStyle(2)
    inPlot1.SetMarkerSize(0.0000000001)
    inPlot1.SetLineColor(ROOT.kBlue)
    inPlot1.SetLineWidth(1)

    inPlot1Division.SetMarkerColor(ROOT.kBlue)
    inPlot1Division.SetMarkerStyle(2)
    inPlot1Division.SetMarkerSize(0.0000000001)
    inPlot1Division.SetLineColor(ROOT.kBlue)
    inPlot1Division.SetLineWidth(1)

    inPlot2.SetMarkerColor(ROOT.kRed)
    inPlot2.SetLineColor(ROOT.kRed)
    inPlot2.SetMarkerStyle(20)
    inPlot2.SetMarkerSize(1)

    inPlot3.SetMarkerColor(ROOT.kBlack)
    inPlot3.SetLineColor(ROOT.kBlack)
    inPlot3.SetMarkerStyle(21)
    inPlot3.SetMarkerSize(1)

    inPlot4.SetMarkerColor(ROOT.kGreen+3)
    inPlot4.SetLineColor(ROOT.kGreen+3)
    inPlot4.SetMarkerStyle(22)
    inPlot4.SetMarkerSize(1)



    tempInPlot1 = inPlot1Division.Clone()
    tempInPlot1.Divide(inPlot1Division)
    tempInPlot2 = inPlot2.Clone()
    tempInPlot2.Divide(inPlot1)
    tempInPlot3 = inPlot3.Clone()
    tempInPlot3.Divide(inPlot1)
    tempInPlot4 = inPlot4.Clone()
    tempInPlot4.Divide(inPlot1)
    tempInPlot5 = inPlot3.Clone()
    tempInPlot5.Divide(inPlot2)

    Legend = ROOT.TLegend(0.66,0.72,0.97,0.92)


    Legend.AddEntry(inPlot1,"Z+Jets NLO (Sherpa)", "l")
    Legend.AddEntry(inPlot2,"Z+Jets LO (Sherpa)", "p")
    Legend.AddEntry(inPlot3,"#gamma+Jets LO (Sherpa)", "p")
    Legend.AddEntry(inPlot4,"#frac{#gamma+Jets LO}{Z+Jets LO} (Ratio)", "p")
    Legend.SetTextSize(0.03)
    Legend.SetFillColor(0)
    Legend.SetFillStyle(0)
    Legend.SetBorderSize(0) 

    inPlot1.SetXTitle(xaxislabel)
    inPlot1.SetTitleSize(0.03,"X")
    inPlot1.SetLabelSize(0.03,"X")

    if rebinvalue > 1 and not phiplot and not etaplot:
        inPlot1.SetYTitle("Events / "+str(rebinvalue)+" GeV")
    elif phiplot:
        inPlot1.SetYTitle("Events / #frac{#Pi}{10}")
    elif etaplot:
        inPlot1.SetYTitle("Events")
    else:
        inPlot1.SetYTitle("Events / "+str(rebinvalue)+" GeV^#frac{1}{2}")

    inPlot1.SetTitleSize(0.03,"Y")
    inPlot1.SetLabelSize(0.03,"Y")
    inPlot1.SetMinimum(0.0002)
    inPlot1.SetMaximum(1000000)

    ScaleFactorNew = (inPlot1.Integral())/(inPlot3.Integral())

#    inPlot1.DrawNormalized("")
#    inPlot2.DrawNormalized("same p")
#    inPlot3.DrawNormalized("same p")
    inPlot1.Draw("E1 X0 h")
    #inPlot1Division.Draw("same")
    inPlot2.Draw("same p E1 X0")
    inPlot3.Draw("same p E1 X0")
    #inPlot4.Draw("same p")
    
    #print "1 - ", inPlot1.Integral(), " 2 - ", inPlot2.Integral(), " 3 - ", inPlot3.Integral()
    #lo,hi = inPlot1.FindBin(0), inPlot1.FindBin(2500)
    #print "1 - ", inPlot1.Integral(lo,hi), " 2 - ", inPlot2.Integral(lo,hi), " 3 - ", inPlot3.Integral(lo,hi)

    latex_draw(label)
    Legend.Draw()


    pad2.cd()


    for bin in range (0,tempInPlot1.GetNbinsX()+1):
        if tempInPlot1.GetBinContent(bin) == 0:
            tempInPlot1.SetBinContent(bin,1)

    tempInPlot1.GetYaxis().SetTitleOffset(0.6)
    tempInPlot1.SetTitleSize(0.07,"Y")
    tempInPlot1.SetLabelSize(0.07,"Y")
    tempInPlot1.SetMinimum(0.01)
    tempInPlot1.SetMaximum(2)
    tempInPlot1.SetYTitle("#frac{#gamma+Jets LO}{Z+Jets NLO}")

    tempInPlot1.SetTitleSize(0.07,"X")
    tempInPlot1.SetLabelSize(0.07,"X")
    tempInPlot1.SetXTitle(xaxislabel)
    tempInPlot1.GetYaxis().CenterTitle()

    tempInPlot2.SetMarkerColor(ROOT.kRed)
    tempInPlot2.SetMarkerStyle(20)
    tempInPlot2.SetMarkerSize(1)

    tempInPlot3.SetMarkerColor(ROOT.kBlack)
    tempInPlot3.SetMarkerStyle(21)
    tempInPlot3.SetMarkerSize(1)

    tempInPlot5.SetMarkerColor(ROOT.kGreen+3)
    tempInPlot5.SetMarkerStyle(22)
    tempInPlot5.SetMarkerSize(1)



    #tempInPlot2.Draw("same E1 X0")

    if (variabletoplot == "m_CT"):
        print "x_low ", "x_high", "GammaJets/ZJets", "ZJets/GammaJets"
        
        for bin in range (1,tempInPlot2.GetNbinsX()+1):
            print (bin-1)*50, bin*50, tempInPlot3.GetBinContent(bin), 1/tempInPlot3.GetBinContent(bin)


    
    #print "New Scale Factor = ", ScaleFactorNew
    #tempInPlot3.Scale(ScaleFactorNew)
    #tempInPlot5.Scale(ScaleFactorNew)


    
    ROOT.gStyle.SetErrorX(0) 
    tempInPlot1.Draw("")
    tempInPlot2.Draw("same E1 X0")
    tempInPlot3.Draw("same E1 X0")
    tempInPlot5.Draw("same P")



    if (variabletoplot == "m_CT"):
        outputMCTFile = ROOT.TFile("SF_mCT_ZGamma.root", "new")
        tempInPlot3.Write()
        outputMCTFile.Write()
        outputMCTFile.Close()
        Canvas.SaveAs(output_dir + histtoplot +".root")
        print "Histo produced",output_dir+histtoplot+".root"

    Canvas.SaveAs(output_dir + histtoplot +".png")
    Canvas.SaveAs(output_dir + histtoplot +".pdf")
    Canvas.SaveAs(output_dir + histtoplot +".eps")
    Canvas.SaveAs(output_dir + histtoplot +".C")

    print "Histo produced",output_dir+histtoplot+".png"
    print "Histo produced",output_dir+histtoplot+".pdf"
    print "Histo produced",output_dir+histtoplot+".eps"
    print "Histo produced",output_dir+histtoplot+".C"

    return
