#!/usr/bin/env python

import os,sys,subprocess,datetime,copy,math,array,shutil,ROOT,string, time
from ROOT import gROOT, TColor, TLatex, gStyle, TLegend, gPad, TAttText

__author__ = "John Anders"
__doc__    = """Plotting Script to plot a 2D significance plot using TTrees
"""


# Make sure that Path exists for output files
def ensure_dir(d):
    if not os.path.isdir(d):
        os.makedirs(d)



# Will read in the names of all of the Histograms in the file, and convert it to a list of strings
def GetKeyNames(infile):
    return [key.GetName() for key in infile.GetListOfKeys()]

# Draws latex on the plots
def latex_draw(option,background):
    
    Tl = ROOT.TLatex()
    Tl.SetTextSize(0.025)
    Tl.SetTextAlign(13)
    Tl.SetNDC(True)
    Tl.DrawLatex(0.4, 0.90,"#int Ldt = 36.1 fb^{-1} #sqrt{s} = 13 TeV")
    Tl.DrawLatex(0.2, 0.90,"#it{#bf{ATLAS} Internal}")
    Tl.DrawLatex(0.25, 0.75,"m(#tilde{#chi}_{1}^{0}) = 60 GeV")
    #Tl.DrawLatex(0.2, 0.7,"m_{T}^{b,min} > 160 GeV")
    #Tl.DrawLatex(0.70, 0.450,"m_{Eff} > 400 GeV")

    #Tl.DrawLatex(0.2, 0.75, option.split("_")[0]+"_"+option.split("_")[1] )
    #Tl.DrawLatex(0.2, 0.70, option.split("_")[2])
    #Tl.DrawLatex(0.2, 0.85,"S = #frac{N_{signal}}{#sqrt{N_{bkg}+(0.2BN_{bkg}+1)^{2}}}")
    #Tl.DrawLatex(0.2, 0.65,"N_{bkg} = "+ str(round(background,3)))
    #Tl.DrawLatex(0.2, 0.70,"All Decays")
    #Tl.DrawLatex(0.2, 0.60,"bb_2015_SRA250")
    #Tl.DrawLatex(0.2, 0.60,"tb_SRinA")

    
   
def main():


    test2D = ROOT.TH2F("StopNeutralinoYield","Exclusive Selection",1000,275,1275,900,175,1075)
    significance2D = ROOT.TH2F("StopNeutralinoSignificance","Exclusive Selection",1000,275,1275,900,175,1075)
    crossSection2D = ROOT.TH2F("StopNeutralinoCrossSection","Exclusive Selection",11000,0,11000,3000,0,3000)
    contamination2D = ROOT.TH2F("StopNeutralinoSignificance","Exclusive Selection",1000,275,1275,900,175,1075)

    

    # Top level output Directory
    output_dir = "SummerAnalysis/Summer_Student_Analysis/histograms/"
    
    date = time.strftime("%d")  + time.strftime("%B") + "_20" + time.strftime("%y")
    
    # This is the subdirectory where the plot will be drawn
    change_me = date+"_SignificancePlots/"
    output_dir = output_dir + change_me
    ensure_dir(output_dir)

    # We don't want to plot a variable, we just want the number of events that pass, so use "1"
    variabletoplot = '1'
    filename = ""

    preselection = "36.5*muonSF*electronSF*finalXSectScale*mcEventWeight*bJetSF*((nJets>=4) && (nBJets>=3) && (ETMiss > 250) && (nBaselineLeptons==0)  && (dPhij1MET>0.4 && dPhij2MET>0.4 && dPhij3MET>0.4 && dPhij4MET>0.4) && (pTj1>80) && ((mcID != 410000 && mcID != 410013 && mcID != 410014) || truthFilterMET < 200 ))*"


    # Change this label here, which will change what the file is called
    regionlabel = "MaxMin_Bulk"    
    # Change the cuts here, to see the significance in the m60 mass plane
    # cutstouse = "36.5*muonSF*electronSF*finalXSectScale*mcEventWeight*bJetSF*(nBaselineLeptons == 0 && passedMETTrigger  && nBJets >= 3 && ETMiss > 250 && minDPhijMET > 0.4 &&  ( (mcID != 410000 && mcID != 410013 && mcID != 410014) || truthFilterMET < 200 ) && nJets >= 4  ) "
    # cutstouse = "36.5*muonSF*electronSF*finalXSectScale*mcEventWeight*bJetSF*(nBaselineLeptons == 0 && nLeptons == 0  && nJets >= 4 && pTj1 > 50 && nBJets >= 3 && ETMiss > 250 && minDPhijMET > 0.4 && ( (mcID != 410000 && mcID != 410013 && mcID != 410014) || truthFilterMET < 200 ) && all_Meff > 800 && InvMass_Bij_minR1 < 100) "
    # cutstouse = preselection+" (nBJets>=4) && (minDR < 2) && (InvMass_Bij_minR < 145 && InvMass_Bij_minR > 95) && (nJets>=6) &&(all_Meff > 1200) && (ETMiss > 350)"
#    cutstouse = preselection+"((minDR1 < 2) && (InvMass_Bij_minR1 < 145 && InvMass_Bij_minR1 > 95) && (nBJets>=4) && (ETMiss > 300) && (m_Tbmin>120) && (all_Meff > 1200))"
#    cutstouse = preselection+"((nBJets>=4) && (minDR < 2) && (InvMass_Bij_minR < 145 && InvMass_Bij_minR > 95) && (nJets>=6) && (nBJets>=5) && (all_Meff > 800))"
    cutstouse = preselection+"((nBJets>=4) && (minDR < 2.5) && (InvMass_Bij_minR < 145 && InvMass_Bij_minR > 95))"
   



   # SMBkgFiles = ROOT.TFile('/scratch/janders/MultiB_Backgrounds_2.root')
    SMBkgFiles = ROOT.TFile('/scratch/janders/MultiB_Background_15Nov.root')
   # SignalFiles = ROOT.TFile('/scratch/janders/MultiB_mN1_60_signals.root')
    SignalFiles = ROOT.TFile('/scratch/janders/MultiB_m60_signals_28Nov.root')

    ttbarTree = SMBkgFiles.Get("ttbar_")    
    ttbarPlot = ROOT.TH1D("ttbarPlot","Title",1,0.5,1.5) 
    ttbarPlot.Sumw2()
    ttbarTree.Draw(variabletoplot+">>ttbarPlot",cutstouse)

    SingleTopTree = SMBkgFiles.Get("singleTop_")    
    SingleTopPlot = ROOT.TH1D("SingleTopPlot","Title",1,0.5,1.5) 
    SingleTopPlot.Sumw2()
    SingleTopTree.Draw(variabletoplot+">>SingleTopPlot",cutstouse)

    ZJetsTree = SMBkgFiles.Get("ZJets_")    
    ZJetsPlot = ROOT.TH1D("ZJetsPlot","Title",1,0.5,1.5) 
    ZJetsPlot.Sumw2()
    ZJetsTree.Draw(variabletoplot+">>ZJetsPlot",cutstouse)

    WJetsTree = SMBkgFiles.Get("WJets_")    
    WJetsPlot = ROOT.TH1D("WJetsPlot","Title",1,0.5,1.5) 
    WJetsPlot.Sumw2()
    WJetsTree.Draw(variabletoplot+">>WJetsPlot",cutstouse)

    ttVTree = SMBkgFiles.Get("ttV_")    
    ttVPlot = ROOT.TH1D("ttVPlot","Title",1,0.5,1.5) 
    ttVPlot.Sumw2()
    ttVTree.Draw(variabletoplot+">>ttVPlot",cutstouse)

    DiBosonTree = SMBkgFiles.Get("DiBoson_")    
    DiBosonPlot = ROOT.TH1D("DiBosonPlot","Title",1,0.5,1.5) 
    DiBosonPlot.Sumw2()
    DiBosonTree.Draw(variabletoplot+">>DiBosonPlot",cutstouse)

    SMBkgPlot = ROOT.TH1D("SMBkgPlot","Title",1,0.5,1.5 ) 
    SMBkgPlot.Sumw2()
    
    SMBkgPlot.Add(ZJetsPlot)
    SMBkgPlot.Add(ttbarPlot)
    SMBkgPlot.Add(ttVPlot)
    SMBkgPlot.Add(SingleTopPlot)
    SMBkgPlot.Add(DiBosonPlot)
    SMBkgPlot.Add(WJetsPlot)


    print 'Number of standard model events = ', SMBkgPlot.Integral()
    SMBkgNumber = SMBkgPlot.Integral()
    
    e1 = ROOT.Double()
    n1 = DiBosonPlot.IntegralAndError(0, 10000000000, e1)
    e2 = ROOT.Double()
    n2 = ttVPlot.IntegralAndError(0, 10000000000, e2)
    e3 = ROOT.Double()
    n3 = ZJetsPlot.IntegralAndError(0, 10000000000, e3)
    e4 = ROOT.Double()
    n4 = WJetsPlot.IntegralAndError(0, 10000000000, e4)
    e5 = ROOT.Double()
    n5 = ttbarPlot.IntegralAndError(0, 10000000000, e5)
    e6 = ROOT.Double()
    n6 = SingleTopPlot.IntegralAndError(0, 10000000000, e6)

    
    print 'Number of DiBoson events = ',    n1, " p/m ", e1 
    print 'Number of ttV events = ',        n2, " p/m ", e2
    print 'Number of Z events = ',          n3, " p/m ", e3
    print 'Number of W events = ',          n4, " p/m ", e4
    print 'Number of ttbar events = ',      n5, " p/m ", e5
    print 'Number of single-top events = ', n6, " p/m ", e6
    
    signals = []
#    signalList = ["directbb_300_295_60_",
#        "directbb_300_205_60_",
#        "directbb_350_345_60_",
#        "directbb_400_395_60_",
#        "directbb_400_205_60_",
#        "directbb_450_205_60_",
#        "directbb_500_300_60_",
#        "directbb_500_400_60_",
#        "directbb_550_545_60_",
#        "directbb_550_205_60_",
#        "directbb_600_400_60_",
#        "directbb_600_595_60_",
#        "directbb_700_250_60_",
#        "directbb_700_350_60_",
#        "directbb_700_450_60_",
#        "directbb_700_550_60_",
#        "directbb_700_650_60_",
#        "directbb_700_205_60_",
#        "directbb_800_250_60_",
#        "directbb_800_350_60_",
#        "directbb_800_450_60_",
#        "directbb_800_550_60_",
##        "directbb_800_650_60_",
#        "directbb_800_750_60_",
 #       "directbb_900_250_60_",
 #       "directbb_900_350_60_",
 #       "directbb_900_450_60_",
 #       "directbb_900_550_60_",
 #       "directbb_900_650_60_",
 #       "directbb_900_750_60_",
 #       "directbb_900_850_60_",
 ###       "directbb_900_205_60_",
 #       "directbb_1000_250_60_",
 #       "directbb_1000_350_60_",
 #       "directbb_1000_450_60_",
 #       "directbb_1000_550_60_",
 #       "directbb_1000_650_60_",
#        "directbb_1000_750_60_",
 #       "directbb_1000_850_60_",
 #       "directbb_1000_205_60_",
#        "directbb_700_695_60_"]





    signalList=["directbb_1000_995_60_",
               "directbb_1000_995_60_",
               "directbb_1200_450_60_",
               "directbb_1200_450_60_",
               "directbb_1300_750_60_",
               "directbb_1300_750_60_",
               "directbb_300_295_60_",
               "directbb_300_295_60_",
               "directbb_300_295_60_",
               "directbb_350_345_60_",
               "directbb_350_345_60_",
               "directbb_350_345_60_",
               "directbb_400_395_60_",
               "directbb_400_395_60_",
               "directbb_400_395_60_",
               "directbb_400_205_60_",
               "directbb_400_205_60_",
               "directbb_450_205_60_",
               "directbb_450_205_60_",
               "directbb_450_205_60_",
               "directbb_500_300_60_",
               "directbb_500_300_60_",
               "directbb_500_300_60_",
               "directbb_550_545_60_",
               "directbb_550_545_60_",
               "directbb_550_545_60_",
               "directbb_550_205_60_",
               "directbb_550_205_60_",
               "directbb_550_205_60_",
               "directbb_600_400_60_",
               "directbb_600_400_60_",
               "directbb_600_595_60_",
               "directbb_600_595_60_",
               "directbb_600_595_60_",
               "directbb_700_250_60_",
               "directbb_700_250_60_",
               "directbb_700_250_60_",
               "directbb_700_350_60_",
               "directbb_700_350_60_",
               "directbb_700_350_60_",
               "directbb_700_450_60_",
               "directbb_700_450_60_",
               "directbb_700_450_60_",
               "directbb_700_550_60_",
               "directbb_700_550_60_",
               "directbb_700_550_60_",
               "directbb_700_650_60_",
               "directbb_700_650_60_",
               "directbb_700_650_60_",
               "directbb_700_205_60_",
               "directbb_700_205_60_",
               "directbb_700_205_60_",
               "directbb_800_250_60_",
               "directbb_800_250_60_",
               "directbb_800_250_60_",
               "directbb_800_350_60_",
               "directbb_800_350_60_",
               "directbb_800_350_60_",
               "directbb_800_450_60_",
               "directbb_800_450_60_",
               "directbb_800_450_60_",
               "directbb_800_550_60_",
               "directbb_800_550_60_",
               "directbb_800_550_60_",
               "directbb_800_650_60_",
               "directbb_800_650_60_",
               "directbb_800_650_60_",
               "directbb_800_750_60_",
               "directbb_800_750_60_",
               "directbb_800_750_60_",
               "directbb_900_250_60_",
               "directbb_900_250_60_",
               "directbb_900_350_60_",
               "directbb_900_350_60_",
               "directbb_900_450_60_",
               "directbb_900_450_60_",
               "directbb_900_550_60_",
               "directbb_900_550_60_",
               "directbb_900_650_60_",
               "directbb_900_650_60_",
               "directbb_900_750_60_",
               "directbb_900_750_60_",
               "directbb_900_850_60_",
               "directbb_900_850_60_",
               "directbb_900_205_60_",
               "directbb_900_205_60_",
               "directbb_1000_250_60_",
               "directbb_1000_250_60_",
               "directbb_1000_350_60_",
               "directbb_1000_350_60_",
               "directbb_1000_350_60_",
               "directbb_1000_450_60_",
               "directbb_1000_450_60_",
               "directbb_1000_750_60_",
               "directbb_1000_750_60_",
               "directbb_1000_850_60_",
               "directbb_1000_850_60_",
               "directbb_1000_205_60_",
               "directbb_1000_205_60_",
               "directbb_700_695_60_",
               "directbb_700_695_60_",
               "directbb_700_695_60_"]



        
# make a list of the signals that exist in the signal file

    for item in signalList:
        sbottom = int(item.split("_")[1])
        neut2 = int(item.split("_")[2])
        neut1 = int(item.split("_")[3])
        print "Processing :", sbottom, neut2
        
        # fix this for the signals 
        signalTree = SignalFiles.Get(item)
        signalPlot = ROOT.TH1D("signalPlot","Title",1,0.5,1.5) 
        signalTree.Draw(variabletoplot+">>signalPlot", cutstouse)
        counts = signalPlot.Integral()
        
        temp = [sbottom,neut2,counts,"1"]
        
        signals.append(temp)




    sampleInfo = [] 
    
    for x in signals:  

        sbottomMass = x[0]
        n2Mass = x[1]
        totalNumber = x[2]
        crossSection = x[3]
        sampleInfo.append([sbottomMass, n2Mass, totalNumber, crossSection])


    print "SMBackground = ", SMBkgNumber
    for item in sampleInfo:

        #test2D.Fill(0,0,0)
        #significance = counts/math.sqrt(SMBkgNumber + (0.3 * SMBkgNumber + 1)**2)
        #significance2D.Fill(0,0,0)
        #else:
        test2D.Fill(item[0],item[1],item[2])
        significance = item[2]/math.sqrt(SMBkgNumber + (((0.2 * SMBkgNumber + 1))**2))
        significance2D.Fill(item[0],item[1],significance)
        contamination2D.Fill(item[0],item[1],100*(item[2]/SMBkgNumber))
        #crossSection2D.Fill(item[0],item[1],item[3])
        print "Sbottom", item[0], " Neut2", item[1], " counts", item[2], " Significance", significance

        #significance2D.Fill(stopMass,neut2Mass,1)


    gROOT.LoadMacro("/user2/janders/ATLAS_Style/atlasstyle-00-03-05/AtlasStyle.C")
    ROOT.SetAtlasStyle()
    gStyle.SetPalette(1);
    gStyle.SetOptTitle(0);
    gStyle.SetOptStat(0);



    Canvas = ROOT.TCanvas("Canvas1","Canvas1",0,0,900,900)
    Canvas.SetRightMargin(0.15)
    Canvas.SetLeftMargin(0.1)
    Canvas.SetBottomMargin(0.1)

    test2D.SetXTitle("m( #tilde{b} ) [GeV]")
    test2D.RebinX(50)
    test2D.RebinY(50)
    test2D.SetTitleSize(0.03,"X")
    test2D.SetLabelSize(0.03,"X")
    test2D.SetTitleOffset(1.5,"x")
    test2D.SetYTitle("m( #tilde{#chi}_{2}^{0} ) [GeV]")
    test2D.SetTitleSize(0.03,"Y")
    test2D.SetLabelSize(0.03,"Y")
    test2D.SetTitleOffset(1.5,"y")
    test2D.LabelsDeflate() 
    test2D.SetTitleOffset(1.2,"Z")
    test2D.SetZTitle("")
    test2D.SetTitleSize(0.03,"Z")
    test2D.SetLabelSize(0.03,"Z")
    gStyle.SetPalette(1)
    gStyle.SetPaintTextFormat("2.2f")
    test2D.GetZaxis().SetRangeUser(1e-10,5)
    #test2D.GetXaxis().SetRangeUser(0,800)
    #test2D.GetYaxis().SetRangeUser(0,400)

    
    #SMBkgPlot.SetMaximum(100)
    
    
    #Canvas.SetGrid()
    test2D.Draw("COLZ")
    test2D.Draw("text same")
   
 
    latex_draw(regionlabel, SMBkgNumber)
    
    #Canvas.SaveAs(output_dir + regionlabel+ "_Yield5.png")
    print "Canvas saved as", output_dir + regionlabel+ "_Yield5.png"
    #Canvas.SaveAs(output_dir + regionlabel+ "_Yield5.eps")
    print "Canvas saved as", output_dir + regionlabel+ "_Yield5.eps"


        
    CanvasSig = ROOT.TCanvas("Canvas2","Canvas2",0,0,900,900)
    #Legend = ROOT.TLegend(0.6,0.72,0.9,0.95)
    CanvasSig.SetRightMargin(0.15)
    CanvasSig.SetLeftMargin(0.1)
    CanvasSig.SetBottomMargin(0.1)


       
    # Sorts out all of the legend drawing
    

    
    # Sorts out the labels etc of the Histogram to be plotted first
    #SMBkgPlot("Single Lepton Channel (2 b-jets)")
    significance2D.SetXTitle("m( #tilde{b} ) [GeV]")
    significance2D.RebinX(50)
    significance2D.RebinY(50)
    significance2D.SetTitleSize(0.03,"X")
    significance2D.SetLabelSize(0.03,"X")
    significance2D.SetTitleOffset(1.5,"x")
    significance2D.SetYTitle("m( #tilde{#chi}_{2}^{0} ) [GeV]")
    significance2D.SetTitleSize(0.03,"Y")
    significance2D.SetLabelSize(0.03,"Y")
    significance2D.SetTitleOffset(1.5,"y")
    #significance2D.LabelsDeflate() 
    significance2D.SetTitleSize(0.03,"Z")
    significance2D.SetLabelSize(0.03,"Z")
    significance2D.SetTitleOffset(1.2,"Z")
    significance2D.SetZTitle("Significance")
    significance2D.SetTitleSize(0.03,"Z")
    significance2D.SetLabelSize(0.03,"Z")
    gStyle.SetPalette(1)
    gStyle.SetPaintTextFormat("2.2f")
    
    significance2D.GetXaxis().SetRangeUser(0,1100)
    significance2D.GetYaxis().SetRangeUser(0,1200)
    significance2D.GetZaxis().SetRangeUser(0,5)


    #SMBkgPlot.SetMaximum(100)
    
    
    #Canvas.SetGrid()
    significance2D.Draw("COLZ")
    significance2D.Draw("text same")
    
    latex_draw(regionlabel, SMBkgNumber)

    

    CanvasSig.SaveAs(output_dir + "sig_" + regionlabel + "_mN1_60.png")
    print "Canvas saved as", output_dir + regionlabel+ "_mN1_60.png"   

    CanvasSig.SaveAs(output_dir + "sig_" + regionlabel + "_mN1_60.eps")
    print "Canvas saved as", output_dir + regionlabel+ "_mN1_60.eps"      

    CanvasContam = ROOT.TCanvas("Canvas2","Canvas2",0,0,900,900)
    #Legend = ROOT.TLegend(0.6,0.72,0.9,0.95)
    CanvasContam.SetRightMargin(0.15)
    CanvasContam.SetLeftMargin(0.1)
    CanvasContam.SetBottomMargin(0.1)


       
    # Sorts out all of the legend drawing
    

    
    # Sorts out the labels etc of the Histogram to be plotted first
    #SMBkgPlot("Single Lepton Channel (2 b-jets)")
    contamination2D.SetXTitle("m( #tilde{b} ) [GeV]")
    contamination2D.RebinX(50)
    contamination2D.RebinY(50)
    contamination2D.SetTitleSize(0.03,"X")
    contamination2D.SetLabelSize(0.03,"X")
    contamination2D.SetTitleOffset(1.5,"x")
    contamination2D.SetYTitle("m( #tilde{#chi}_{2}^{0} ) [GeV]")
    contamination2D.SetTitleSize(0.03,"Y")
    contamination2D.SetLabelSize(0.03,"Y")
    contamination2D.SetTitleOffset(1.5,"y")
    #contamination2D.LabelsDeflate() 
    contamination2D.SetTitleSize(0.03,"Z")
    contamination2D.SetLabelSize(0.03,"Z")
    contamination2D.SetTitleOffset(1.2,"Z")
    contamination2D.SetZTitle("Signal Contamination [%]")
    contamination2D.SetTitleSize(0.03,"Z")
    contamination2D.SetLabelSize(0.03,"Z")
    gStyle.SetPalette(1)
    gStyle.SetPaintTextFormat("2.2f")
    
    contamination2D.GetXaxis().SetRangeUser(0,1100)
    contamination2D.GetYaxis().SetRangeUser(0,1200)
    contamination2D.GetZaxis().SetRangeUser(0,20)


    #SMBkgPlot.SetMaximum(100)
    
    
    #Canvas.SetGrid()
    contamination2D.Draw("COLZ")
    contamination2D.Draw("text same")
    
    latex_draw(regionlabel, SMBkgNumber)

    

    CanvasContam.SaveAs(output_dir + "eff_"  + regionlabel + "_mN1_60.png")
    print "Canvas saved as", output_dir + "eff_"  + regionlabel+ "_mN1_60.png"   

    CanvasContam.SaveAs(output_dir + "eff_"  + regionlabel + "_mN1_60.eps")
    print "Canvas saved as", output_dir + "eff_"  + regionlabel+ "_mN1_60.eps"      


    CanvasxSec = ROOT.TCanvas("Canvas2","Canvas2",0,0,900,900)
    #Legend = ROOT.TLegend(0.6,0.72,0.9,0.95)
    

       
    # Sorts out all of the legend drawing
    

    
    # Sorts out the labels etc of the Histogram to be plotted first
    #SMBkgPlot("Single Lepton Channel (2 b-jets)")
    crossSection2D.SetXTitle("m_{mediator}")
    #crossSection2D.RebinX(50)
    #crossSection2D.RebinY(1.5)
    crossSection2D.SetTitleSize(0.03,"X")
    crossSection2D.SetLabelSize(0.03,"X")
    crossSection2D.SetTitleOffset(1.5,"x")
    crossSection2D.SetYTitle("m_{DM}")
    crossSection2D.SetTitleSize(0.03,"Y")
    crossSection2D.SetLabelSize(0.03,"Y")
    crossSection2D.SetTitleOffset(1.5,"y")
    crossSection2D.LabelsDeflate() 
    gStyle.SetPalette(1)
    gStyle.SetPaintTextFormat("2.1f")
    crossSection2D.GetZaxis().SetRangeUser(1e-10,5)
    gStyle.SetPalette(1)
    gStyle.SetPaintTextFormat("2.1f")
    
    #crossSection2D.GetXaxis().SetRangeUser(0,800)
    #crossSection2D.GetYaxis().SetRangeUser(0,400)


    #SMBkgPlot.SetMaximum(100)
    
    if regionlabel != "HDM":
        CanvasxSec.SetLogy()
        CanvasxSec.SetLogx()

    #Canvas.SetGrid()
    crossSection2D.Draw("COLZ")
    crossSection2D.Draw("text same")
    
    latex_draw(regionlabel, SMBkgNumber)

    

    #CanvasxSec.SaveAs(output_dir + regionlabel + "_xSec.png")
    print "Canvas saved as", output_dir + regionlabel+ "_xSec.png"   

    #CanvasxSec.SaveAs(output_dir + regionlabel + "_xSec.eps")
    print "Canvas saved as", output_dir + regionlabel+ "_xSec.eps"      




    
if __name__ == '__main__':
    main()
