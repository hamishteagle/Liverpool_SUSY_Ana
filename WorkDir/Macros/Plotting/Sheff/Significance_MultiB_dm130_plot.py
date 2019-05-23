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
    Tl.DrawLatex(0.4, 0.90,"#int Ldt = 79.9 fb^{-1} #sqrt{s} = 13 TeV")
    Tl.DrawLatex(0.2, 0.90,"#it{#bf{ATLAS} Internal}")
    Tl.DrawLatex(0.25, 0.75,"#Delta m(#tilde{#chi}_{2}^{0}, #tilde{#chi}_{1}^{0}) = 130 GeV")
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


    test2D = ROOT.TH2F("StopNeutralinoYield","Exclusive Selection",725,275,1000,900,-25,875)
    significance2D = ROOT.TH2F("StopNeutralinoSignificance","Exclusive Selection",725,275,1000,900,-25,875)
    crossSection2D = ROOT.TH2F("StopNeutralinoCrossSection","Exclusive Selection",1725,0,11000,3000,0,3000)
    contamination2D = ROOT.TH2F("StopNeutralinoContamination","Exclusive Selection",725,275,1000,900,-25,875)

    

    # Output Directory
    output_dir = "SummerAnalysis/Summer_Student_Analysis/histograms/"
    
    date = time.strftime("%d")  + time.strftime("%B") + "_20" + time.strftime("%y")
    
    # Change this for different Meetings Types of file etc
    change_me = date+"_SignificancePlots/"
    output_dir = output_dir + change_me
    ensure_dir(output_dir)


    variabletoplot = '1'

    
    #preselection = "36.5*muonSF*electronSF*finalXSectScale*mcEventWeight*bJetSF*((nJets>=4) && (nBJets>=3) && (ETMiss > 250) && (nBaselineLeptons==0)  && (dPhij1MET>0.4 && dPhij2MET>0.4 && dPhij3MET>0.4 && dPhij4MET>0.4) && (pTb1>80) && ((mcID != 410000 && mcID != 410013 && mcID != 410014) || truthFilterMET < 200 ))*"
    
    luminosity = "79900*jvtweight*AnalysisWeight*pileupweight*LumiWeight*btagweight*MuonWeight*ElecWeight*isttbarMET400_OK*isWtHT500_OK*"   


#    preselection= luminosity+"(ETMiss>250 && nBJets>=4 && nBaselineLeptons==0 && pTb1>80 && (dPhij1MET>0.4 && dPhij2MET>0.4 && dPhij3MET>0.4 && dPhij4MET>0.4) && (( mcID == 410013 && truthFilterMET < 200) || (mcID == 410014 && truthFilterMET < 200) || (mcID == 410000 && truthFilterHT < 600) || (mcID == 407009 && truthFilterHT > 600 && truthFilterHT < 1000) || (truthFilterHT > 1000 && truthFilterHT < 1500 && mcID == 407010) || (mcID == 407011 && truthFilterHT > 1500) || (mcID != 410013 && mcID != 410014 && mcID != 410000 && mcID != 407009 && mcID != 407010 && mcID != 407011)))*";  
  
    preselection = "(nbaselineLep == 0 && nj_good >= 4 && pT_1bjet > 100 && num_bjets >= 3 && eT_miss > 250 && dphimin4 > 0.4 && passMETtriggers)*"

    filename = ""
    regionlabel = "SRB_Higgsino"
    
    # This is temporary
    #cutstouse = "36.5*muonSF*electronSF*finalXSectScale*mcEventWeight*bJetSF*(nBaselineLeptons == 0 && passedMETTrigger  && nBJets >= 4 && ETMiss > 250 && minDPhijMET > 0.4 &&  ( (mcID != 410000 && mcID != 410013 && mcID != 410014) || truthFilterMET < 200 ) && nJets >= 5  && m_bb > 200 && m_CT > 150 ) "
    # This is a 0-Lepton Top CR
    #cutstouse = "36.5*muonSF*electronSF*finalXSectScale*mcEventWeight*bJetSF*(nBaselineLeptons == 0 && nLeptons == 0  && nJets >= 4 && pTj1 > 50 && nBJets >= 3 && ETMiss > 250 && minDPhijMET > 0.4 && ( (mcID != 410000 && mcID != 410013 && mcID != 410014) || truthFilterMET < 200 ) && all_Meff < 800 && InvMass_Bij_minR1 < 100) "
    #cutstouse = "36.5*muonSF*electronSF*finalXSectScale*mcEventWeight*bJetSF*(nBaselineLeptons == 0 && nLeptons == 0  && nJets >= 4 && pTj1 > 50 && nBJets >= 3 && ETMiss > 250 && minDPhijMET > 0.4 && ( (mcID != 410000 && mcID != 410013 && mcID != 410014) || truthFilterMET < 200 ) && all_Meff > 800 && InvMass_Bij_minR1 < 100) "
    #    cutstouse = "36.5*muonSF*electronSF*finalXSectScale*mcEventWeight*bJetSF*(nBaselineLeptons == 0 && nJets >= 6 && pTj1 > 80 && nBJets >= 5 && ETMiss > 250 && minDPhijMET > 0.4 && passedMETTrigger && ( (mcID != 410000 && mcID != 410013 && mcID != 410014) || truthFilterMET < 200 ) && InvMass_Bij_minR1 > 100 && minDR1 < 2.0)"
#    cutstouse = preselection+"((nBJets>=4) && (minDR < 2.5) && (InvMass_Bij_minR < 145 && InvMass_Bij_minR > 95) && (nJets>=6) && (nBJets>=5) && (all_Meff > 800))"
    #cutstouse = preselection+"((nBJets>=4) && (minDR < 2.5) && (InvMass_Bij_minR < 145 && InvMass_Bij_minR > 95))"
    #cutstouse = preselection+"((nBJets>=5) && (minDR < 2.5) && (InvMass_Bij_minR < 145 && InvMass_Bij_minR > 95) && (nJets>=5) && (all_Meff > 1300))"
    #cutstouse = luminosity+preselection+"((eT_miss > 250) && (nbaselineLep==0)  && (dphimin4>0.4) && (pT_1bjet>200) && maxminDRbb<2.5 && maxDRbb>2.5 && (maxminDRmbb > 80) && (nj_good>=6) && (num_bjets>=5) && (meff > 1300))"
    #SRB_Original
 
    SignifOrig=-1
    i=0
    j=0
    while (i < 1600 and j<2000):
        
        for j in range(0,100):
            j=j*10
            print "iterator = "+str(i)
            print "iterator 2 = "+str(j)
            cutstouse = luminosity+preselection+"(num_bjets>=4 && (SRB1_DRmin<2 && SRB1_DRmin2<3.5) && (SRB1_Mh<150 && SRB1_Mh>100)&& pT_1jet>"+str(j)+" && HT>"+str(i)+")"
            
          
          
    #SRB_Higgsino
    #cutstouse =luminosity+preselection+"(num_bjets>=5 && (SRB2_minDR<2 && SRB2_maxDR<3) && (SRB2_Mh<140 && SRB2_Mh>90) && pT_1jet>300 && HT>600)"
          







            SMBkgFiles = ROOT.TFile('/hepstore/hteagle/Ntuples_12_05/MultiB_Background.root')
            SignalFiles = ROOT.TFile("/hepstore/hteagle/Ntuples_12_05/MultiB_dm130_signals_12May.root")
            
    #cutstouse = cutstouse+"*(cross_section != -1)"
        
            ttbarTree = SMBkgFiles.Get("ttbar")    
            ttbarPlot = ROOT.TH1D("ttbarPlot","Title",1,0.5,1.5) 
            ttbarPlot.Sumw2()
            ttbarTree.Draw(variabletoplot+">>ttbarPlot",cutstouse)
            
            DiJetTree = SMBkgFiles.Get("DiJet")    
            DiJetPlot = ROOT.TH1D("DiJetPlot","Title",1,0.5,1.5) 
            DiJetPlot.Sumw2()
            DiJetTree.Draw(variabletoplot+">>DiJetPlot",cutstouse)
        
        
            SingleTopTree = SMBkgFiles.Get("singleTop")    
            SingleTopPlot = ROOT.TH1D("SingleTopPlot","Title",1,0.5,1.5) 
            SingleTopPlot.Sumw2()
            SingleTopTree.Draw(variabletoplot+">>SingleTopPlot",cutstouse)
          
            ZJetsTree = SMBkgFiles.Get("ZJets")    
            ZJetsPlot = ROOT.TH1D("ZJetsPlot","Title",1,0.5,1.5) 
            ZJetsPlot.Sumw2()
            ZJetsTree.Draw(variabletoplot+">>ZJetsPlot",cutstouse)
            
            WJetsTree = SMBkgFiles.Get("WJets")    
            WJetsPlot = ROOT.TH1D("WJetsPlot","Title",1,0.5,1.5) 
            WJetsPlot.Sumw2()
            WJetsTree.Draw(variabletoplot+">>WJetsPlot",cutstouse)
        
            ttVTree = SMBkgFiles.Get("ttV")    
            ttVPlot = ROOT.TH1D("ttVPlot","Title",1,0.5,1.5) 
            ttVPlot.Sumw2()
            ttVTree.Draw(variabletoplot+">>ttVPlot",cutstouse)
        
            DiBosonTree = SMBkgFiles.Get("DiBoson")    
            DiBosonPlot = ROOT.TH1D("DiBosonPlot","Title",1,0.5,1.5) 
            DiBosonPlot.Sumw2()
            DiBosonTree.Draw(variabletoplot+">>DiBosonPlot",cutstouse)
        
            HiggsTree = SMBkgFiles.Get("Higgs")    
            HiggsPlot = ROOT.TH1D("HiggsPlot","Title",1,0.5,1.5) 
            HiggsPlot.Sumw2()
            HiggsTree.Draw(variabletoplot+">>HiggsPlot",cutstouse)

    #Pythia_DiJetTree = SMBkgFiles.Get("Pythia_DiJet")    
    #Pythia_DiJetPlot = ROOT.TH1D("Pythia_DiJetPlot","Title",1,0.5,1.5) 
    #Pythia_DiJetPlot.Sumw2()
    #Pythia_DiJetTree.Draw(variabletoplot+">>Pythia_DiJetPlot",cutstouse)
        
    #Herwigpp_DiJetTree = SMBkgFiles.Get("Herwigpp_DiJet")    
    #Herwigpp_DiJetPlot = ROOT.TH1D("Herwigpp_DiJetPlot","Title",1,0.5,1.5) 
    #Herwigpp_DiJetPlot.Sumw2()
    #Herwigpp_DiJetTree.Draw(variabletoplot+">>Herwigpp_DiJetPlot",cutstouse)
        
        
        
        
        
            SMBkgPlot = ROOT.TH1D("SMBkgPlot","Title",1,0.5,1.5 ) 
            SMBkgPlot.Sumw2()
          
            SMBkgPlot.Add(ZJetsPlot)
            SMBkgPlot.Add(ttbarPlot)
            SMBkgPlot.Add(DiJetPlot)
            SMBkgPlot.Add(ttVPlot)
            SMBkgPlot.Add(SingleTopPlot)
            SMBkgPlot.Add(DiBosonPlot)
            SMBkgPlot.Add(HiggsPlot)
    #SMBkgPlot.Add(Pythia_DiJetPlot)
    #SMBkgPlot.Add(Herwigpp_DiJetPlot)
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
            n6 = DiJetPlot.IntegralAndError(0,10000000000, e6)
            e7 = ROOT.Double()
            n7 = SingleTopPlot.IntegralAndError(0, 10000000000, e7)
            e8 = ROOT.Double()
            n8 = HiggsPlot.IntegralAndError(0, 10000000000, e8)
   # e8 = ROOT.Double()
  #  n8 = Pythia_DiJetPlot.IntegralAndError(0, 10000000000, e9)
 #   e9 = ROOT.Double()
#    n9 = Pythia_DiJetPlot.IntegralAndError(0, 10000000000, e10)



    
            print 'Number of DiBoson events = ',    n1, " p/m ", e1 
            print 'Number of ttV events = ',        n2, " p/m ", e2
            print 'Number of Z events = ',          n3, " p/m ", e3
            print 'Number of W events = ',          n4, " p/m ", e4
            print 'Number of ttbar events = ',      n5, " p/m ", e5
            print 'Number of DiJet events = ',      n6, " p/m ", e6
            print 'Number of single-top events = ', n7, " p/m ", e7
            print 'Number of Higgs events = ',n8, "p/m", e8
    #print 'Number of Pythia_DiJet events = ',n9, "p/m", e9
    #print 'Number of Herwigpp_DiJet events = ',n10, "p/m", e10
        
            signals = []
            
            signalList = ["directbb_700_380_250",	
                          "directbb_700_480_350",	
                          "directbb_700_580_450",	
                          "directbb_700_680_550",	
                          "directbb_400_280_150",	
                          "directbb_750_131_1",	
                          "directbb_400_370_240",	
                          "directbb_800_131_1",	
                          "directbb_400_390_260",	
                          "directbb_800_230_100",	
                          "directbb_500_131_1",	
                          "directbb_800_300_170",	
                          "directbb_500_180_50",	
                          "directbb_800_380_250",	
                          "directbb_500_280_150",	
                          "directbb_800_480_350",	
                          "directbb_500_380_250",	
                          "directbb_800_580_450",	
                          "directbb_500_490_360",	
                          "directbb_800_680_550",	
                          "directbb_550_131_1",	
                          "directbb_800_780_650",	
                          "directbb_550_180_50",	
                          "directbb_900_131_1",	
                          "directbb_600_131_1",	
                          "directbb_900_230_100",	
                          "directbb_600_180_50",	
                          "directbb_900_330_200",	
                          "directbb_600_280_150",	
                          "directbb_900_430_300",	
                          "directbb_600_380_250",	
                          "directbb_900_530_400",	
                          "directbb_600_480_350",	
                          "directbb_900_630_500",	
                          "directbb_600_580_450",	
                          "directbb_900_730_600",	
                          "directbb_650_131_1",	
                          "directbb_900_830_700",	
                          "directbb_700_131_1",	
                          "directbb_650_180_50",	
                          "directbb_700_230_100",	
                          "directbb_850_180_50",	
                          "directbb_700_300_170"]
            
        
# make a list of the signals that exist in the signal file
        
            for item in signalList:
                sbottom = int(item.split("_")[1])
                print sbottom
                neut2 = int(item.split("_")[2])
                neut1 = int(item.split("_")[3])
                print "Processing :", sbottom, neut2, neut1
                
                
        # fix this for the signals 
                signalTree = SignalFiles.Get(item)
                signalPlot = ROOT.TH1D("signalPlot","Title",1,0.5,1.5) 
                signalTree.Draw(variabletoplot+">>signalPlot", cutstouse)
                counts = signalPlot.Integral()
                

                temp = [sbottom,neut1,counts,"1"]
                
                signals.append(temp)
                
            
            
            
                sampleInfo = [] 
                
            for x in signals:  
                    
                sbottomMass = x[0]
                n1Mass = x[1]
                totalNumber = x[2]
                crossSection = x[3]
                sampleInfo.append([sbottomMass, n1Mass, totalNumber, -crossSection])
                    
                    
                #print "SMBackground = ", SMBkgNumber
                if (SMBkgNumber ==0):
                    SMBkgNumber = 0.0001
            for item in sampleInfo:

                test2D.Fill(item[0],item[1],item[2])
                significance = item[2]/math.sqrt(SMBkgNumber + (((0.3 * SMBkgNumber + 1))**2))
                if significance==0:
                    significance=0.001
                significance2D.Fill(item[0],item[1],significance)
                contamination=(item[2]/(SMBkgNumber))*100
                if contamination ==0:
                    contamination=0.001
                contamination2D.Fill(item[0],item[1],contamination)
        #crossSection2D.Fill(item[0],item[1],item[3])
                print "Sbottom", item[0], " Neut1", item[1], " counts", item[2], " Significance", significance

                if(item[0]==700 and item[1]==550 and significance>SignifOrig and SMBkgNumber>0.001):
                    SignifOrig=significance
                    print "Significance = "+str(significance)+"HT cut = "+str(i)+", pT cut = "+str(j)
                    finalHTCut= i
                    finalpTCut= j
    i=i+10
#significance2D.Fill(stopMass,neut2Mass,1)

    gROOT.LoadMacro("/user/hteagle/Macros/Plotting/AtlasStyle/AtlasStyle.cxx")               
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
    test2D.SetYTitle("m( #tilde{#chi}_{1}^{0} ) [GeV]")
    test2D.SetTitleSize(0.03,"Y")
    test2D.SetLabelSize(0.03,"Y")
    test2D.SetTitleOffset(1.5,"y")
    test2D.LabelsDeflate() 
    test2D.SetTitleOffset(1.2,"Z")
    test2D.SetZTitle("S")
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
    significance2D.SetYTitle("m( #tilde{#chi}_{1}^{0} ) [GeV]")
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
    
    significance2D.GetXaxis().SetRangeUser(0,1200)
    significance2D.GetYaxis().SetRangeUser(0,800)
    significance2D.GetZaxis().SetRangeUser(0,5)


    #SMBkgPlot.SetMaximum(100)
    
    
    #Canvas.SetGrid()
    significance2D.Draw("COLZ")
    significance2D.Draw("text same")
    
    latex_draw(regionlabel, SMBkgNumber)

    

    CanvasSig.SaveAs(output_dir + "sig_" + regionlabel + "_DM130.png")
    print "Canvas saved as", output_dir + regionlabel+ "_DM130.png"   

    CanvasSig.SaveAs(output_dir + "sig_" + regionlabel + "_DM130.eps")
    print "Canvas saved as", output_dir + regionlabel+ "_DM130.eps"      




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
    contamination2D.SetYTitle("m( #tilde{#chi}_{1}^{0} ) [GeV]")
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
    
    contamination2D.GetXaxis().SetRangeUser(0,900)
    contamination2D.GetYaxis().SetRangeUser(0,800)
    contamination2D.GetZaxis().SetRangeUser(0,20)


    #SMBkgPlot.SetMaximum(100)
    
    
    #Canvas.SetGrid()
    contamination2D.Draw("COLZ")
    contamination2D.Draw("text same")
    
    latex_draw(regionlabel, SMBkgNumber)

    

    CanvasContam.SaveAs(output_dir + "eff_"  + regionlabel + "_DM130.png")
    print "Canvas saved as", output_dir + "_eff_"  + regionlabel+ "_DM130.png"   

    CanvasContam.SaveAs(output_dir + "eff_"  + regionlabel + "_DM130.eps")
    print "Canvas saved as", output_dir + "_eff_"  + regionlabel+ "_DM130.eps"      




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
