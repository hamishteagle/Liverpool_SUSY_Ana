#!/usr/bin/env python 
import os, sys, math, ROOT, time
from ROOT import gROOT, TColor, TLatex, gStyle, TLegend, gPad, TAttText, RooStats


__author__ = "Hamish Teagle"
__doc__    = """Integrated Significance plotting and calculations"""


## Make sure that Path exists for output files
def ensure_dir(d):
    if not os.path.isdir(d):
        os.makedirs(d)

def latex_draw(label):
    
    Tl = ROOT.TLatex()
    Tl.SetTextSize(0.020)
    Tl.SetTextAlign(13)
    Tl.SetNDC(True)
    #Tl.DrawLatex(0.15, 0.94,"#tilde{b}#tilde{b} production, #tilde{b}#rightarrow b+#tilde{#chi}_{2}^{0}, #tilde{#chi}_{2}^{0}#rightarrow h+#tilde{#chi}_{1}^{0}, #Deltam(#tilde{#chi}_{2}^{0},#tilde{#chi}_{1}^{0})=130GeV")
    Tl.DrawLatex(0.15, 0.94,"#tilde{b}#tilde{b} production, #tilde{b}#rightarrow b+#tilde{#chi}_{2}^{0}, #tilde{#chi}_{2}^{0}#rightarrow h+#tilde{#chi}_{1}^{0}, m(#tilde{#chi}_{1}^{0})=60GeV")
    Tl.DrawLatex(0.64, 0.94,"#int L#it{dt} = 139 fb^{-1}, #sqrt{s} = 13 TeV")
    Tl.DrawLatex(0.17, 0.84,"Region: #bf{"+label+"}")
    Tl.SetTextSize(0.045)
    Tl.DrawLatex(0.17, 0.88,"#it{#bf{ATLAS} Simulation}")



##Pass the signal and backgrounds as strings 
def Significance(cutstouse,luminosity, signalFiles,reco_signalFiles, bkgFile, label, doSignif, doAccept, doEff):
    
    if doEff:
        outputdir = "/user/hteagle//SummerAnalysis/Summer_Student_Analysis/histograms/Efficiencyplots/"   
    if doAccept:
        outputdir = "/user/hteagle//SummerAnalysis/Summer_Student_Analysis/histograms/Acceptanceplots/"   
    
    ensure_dir(outputdir)
    if doSignif or doEff:
        cutstouse = luminosity+cutstouse
        
    ## Set Styles
    gStyle.SetPalette(1);
    gStyle.SetOptTitle(0);
    gStyle.SetOptStat(0);

    if doSignif:
        #Open all background files individually (helps with compositions)
        bkg = ROOT.TFile.Open(bkgFile)
        bkgTree = bkg.Get("CollectionTree_")
        bkgPlot = ROOT.TH1F("bkgPlot","Title",1,0.5,1.5) 
        bkgPlot.Sumw2()
        
        bkgTree.Draw("1>>bkgPlot",cutstouse)

        # singleTop = TFile.Open(singleTopFile)
        # singleTopTree = singleTop.Get("ntuple")    
        # singleTopPlot = ROOT.TH1F("SingleTopPlot","Title",1,0.5,1.5) 
        # singleTopPlot.Sumw2()
        # singleTopTree.Draw(variabletoplot+">>SingleTopPlot",cutstouse)
        
        # wJet = TFile.Open(wJetFile)
        # wJetTree = wJet.Get("ntuple")    
        # wJetPlot = ROOT.TH1F("SingleTopPlot","Title",1,0.5,1.5) 
        # wJetPlot.Sumw2()
        # wJetTree.Draw(variabletoplot+">>SingleTopPlot",cutstouse)
        
        # ttV = TFile.Open(ttVFile)
        # ttVTree = ttV.Get("ntuple")    
        # ttVPlot = ROOT.TH1F("SingleTopPlot","Title",1,0.5,1.5) 
        # ttVPlot.Sumw2()
        # ttVTree.Draw(variabletoplot+">>SingleTopPlot",cutstouse)
        
        # DiBoson = TFile.Open(DiBosonFile)
        # DiBosonTree = DiBoson.Get("ntuple")    
        # DiBosonPlot = ROOT.TH1F("SingleTopPlot","Title",1,0.5,1.5) 
        # DiBosonPlot.Sumw2()
        # DiBosonTree.Draw(variabletoplot+">>SingleTopPlot",cutstouse)
        
        # Higgs = TFile.Open(HiggsFile)
        # HiggsTree = Higgs.Get("ntuple")    
        # HiggsPlot = ROOT.TH1F("SingleTopPlot","Title",1,0.5,1.5) 
        # HiggsPlot.Sumw2()
        # HiggsTree.Draw(variabletoplot+">>SingleTopPlot",cutstouse)
        
        # zJet = TFile.Open(zJetFile)
        # zJetTree = zJet.Get("ntuple")    
        # zJetPlot = ROOT.TH1F("SingleTopPlot","Title",1,0.5,1.5) 
        # zJetPlot.Sumw2()
        # zJetTree.Draw(variabletoplot+">>SingleTopPlot",cutstouse)
        
        # DiJet = TFile.Open(DiJetFile)
        # DiJetTree = DiJet.Get("ntuple")    
        # DiJetPlot = ROOT.TH1F("SingleTopPlot","Title",1,0.5,1.5) 
        # DiJetPlot.Sumw2()
        # DiJetTree.Draw(variabletoplot+">>SingleTopPlot",cutstouse)
    

        ##Add all backgrounds to SMBkgPlot
        SMBkgPlot = ROOT.TH1F("SMBkgPlot","Title",1,0.5,1.5 ) 
        SMBkgPlot.Sumw2()
        SMBkgPlot.Add(bkgPlot)
        # SMBKgPlot.Add(singleTopPlot)
        # SMBKgPlot.Add(wJetPlot)
        # SMBKgPlot.Add(ttVPlot)
        # SMBKgPlot.Add(DiBosonPlot)
        # SMBKgPlot.Add(HiggsPlot)    
        # SMBKgPlot.Add(zJetPlot)
        # SMBKgPlot.Add(DiJetPlot)
    
        SMBkgNumber = SMBkgPlot.Integral(0,1000000000000)


        #Calculate the significance with signal files
        Significance = ROOT.TH2F("Siginificance","Put varaiable (cuts) title here",400,125,525,200,0,200)
        
    directory = "/hepstore/hteagle/Wh/ntuples_simpleAnalysis/SbMB/dm130/"
    directory_reco = "/scratch/hteagle/SbMB/Sheff_ntuples_21_2_62/dm130/"
    if doAccept or doEff:
        Significance = ROOT.TH2F("Acceptance","Put varaiable (cuts) title here",28,0,1400,28,0,1400)
        if doEff:
            Significance_truth = ROOT.TH2F("Acceptance","Put varaiable (cuts) title here",30,200,1600,30,200,1600)
            Significance_reco = ROOT.TH2F("Acceptance","Put varaiable (cuts) title here",30,200,1600,30,200,1600)
        signal_Eff_map = {}
        signal_truth_map = {}
    for files in signalFiles:
        print(files)
        signal = ROOT.TFile(directory+files)
        sigtree = signal.Get("ntuple")
        #Set the aliases for the truth signal samples

        sigPlot = ROOT.TH1F("sigPlot","Title",1,0.5,1.5) 
        sigPlot.Sumw2()

        failedTree = False
        try:
            if doEff:
                sigtree.SetAlias("YearWeight","eventWeight>-100")
                sigtree.SetAlias("pileupweight","eventWeight>-100")
                sigtree.SetAlias("jvtweight","eventWeight>-100")
                sigtree.SetAlias("btagweight","eventWeight>-100")
                sigtree.SetAlias("AnalysisWeight","eventWeight")
                sigtree.SetAlias("LumiWeight","(HFScale/1000)")
                
                sigtree.SetAlias("passMETtriggers","eventWeight>-100")
                sigtree.SetAlias("nbaselineLep","nBaselineLeptons")
                sigtree.SetAlias("dphimin4_orig","minDPhiJMET_4")
                sigtree.SetAlias("nj_good","nJets")
                sigtree.SetAlias("num_bjets","nBJets")
                sigtree.SetAlias("eT_miss","ETMiss")                        
                sigtree.SetAlias("metsigHT","metsig_HT")
                sigtree.SetAlias("maxDRbb","maxDR")
                sigtree.SetAlias("maxminDRbb","maxminDR")
                sigtree.SetAlias("leadB","nonBLead=1")
                sigtree.SetAlias("SRB3_mbb_avg","max_avg_M")
                sigtree.SetAlias("dPhi_1jet","DPhiJMET_1")
                sigtree.SetAlias("maxminDRmbb","maxmin_M")
                sigtree.SetAlias("pT_1bjet","pTb1")
            print ("Cuts used: "+str(cutstouse))
            sigtree.Draw("1>>sigPlot",cutstouse)
            nSignal = sigPlot.Integral(0,100000000)
        except:
            print(str(files)+"does not have a valid tree")
            nSignal = 1
            failedTree = True





        if doSignif:
            significance = RooStats.NumberCountingUtils.BinomialExpZ(nSignal, SMBkgNumber, 0.3)
            
            if significance > 9.99:
                significance=9.99
            if significance <=0 :
                significance = 0.0001

                sigtree.GetEntry(0)
                try:
                    print ("C1N2: "+str(sigtree.C1N2_mass_real)+" N1:"+str(sigtree.N1_mass_real)+" Significance: "+str(significance)+", NSig; "+str(nSignal)+", Nbkg; "+str(SMBkgNumber))
                    Significance.Fill(sigtree.C1N2_mass_real, sigtree.N1_mass_real, significance)
                except:
                    print ("C1N2: "+str(sigtree.C1N2_mass)+" N1:"+str(sigtree.N1_mass)+" Significance: "+str(significance)+", NSig; "+str(nSignal)+", Nbkg; "+str(SMBkgNumber))
                Significance.Fill(sigtree.C1N2_mass, sigtree.N1_mass, significance)

        #Fill the acceptance plot
        if doAccept and not failedTree:
            h_SumOfWeights = signal.Get("h_SumOfWeights")
            nSum = h_SumOfWeights.Integral(0,1000000)
            Accept = (nSignal/nSum)*100
            print ("Acceptance: "+str(Accept))
            Sb_mass = files.split('_')[4]
            N2_mass = files.split('_')[5]
            print ('Sb_mass = '+str(Sb_mass))
            print ('N2_mass = '+str(N2_mass))
            Significance.Fill(int(Sb_mass), int(N2_mass), Accept)

        if doEff and not failedTree:
            Sb_mass = files.split('_')[4]
            N2_mass = files.split('_')[5]
            print ('Sb_mass truth = '+str(Sb_mass))
            print ('N2_mass truth = '+str(N2_mass))
            print ('nSignal_truth = '+str(nSignal))
            print ('nSignal_raw truth ='+str(sigPlot.GetEntries()))
            signal_truth_map[str(Sb_mass)+'_'+str(N2_mass)]=nSignal
            Significance_truth.Fill(int(Sb_mass), int(N2_mass), nSignal)
            sigPlot.Delete()
    if doEff:
        for reco_files in reco_signalFiles:
            print(str(reco_files))
            signal_reco = ROOT.TFile(directory_reco+reco_files)
            sigtree = signal_reco.Get("NominalFixed")

                
            sigPlot = ROOT.TH1F("sigPlot","Title",1,0.5,1.5) 
            sigPlot.Sumw2()

            failedTree = False
            ##Avoid messing up because one of the files is screwed
            try:
                sigtree.SetAlias("year","treatAsYear")
                if reco_files.find('0_a.root')!=-1 or reco_files.find('0_d.root')!=-1 or reco_files.find('0_e.root')!=-1 :
                    sigtree.SetAlias("YearWeight","AnalysisWeight>-100")                    
                    print("Scale by 1 year")
                elif reco_files.find('_a_d.root')!=-1:
                    sigtree.SetAlias("YearWeight","year==2017 ? 44.3/79.5 : 36.2/79.5") 
                elif reco_files.find('_d_e.root')!=-1:
                    sigtree.SetAlias("YearWeight","year==2018 ? 58.5/79.5 : 44.3/102.8") 
                elif reco_files.find('_a_e.root')!=-1:
                    sigtree.SetAlias("YearWeight","year==2018 ? 58.5/94.7 : 36.2/94.7") 
                elif reco_files.find('_a_d_e.root')!=-1:
                    sigtree.SetAlias("YearWeight","year==2018 ? 59.9/139 :(year==2017 ? 44.3/139 : 36.2/139)")                    
                sigtree.Draw("1>>sigPlot",cutstouse)
                nSignal_reco = sigPlot.Integral(0,1000000000)
                Sb_mass = reco_files.split('_')[5]
                N2_mass = reco_files.split('_')[6]
                print ('Sb_mass reco = '+str(Sb_mass))
                print ('N2_mass reco = '+str(N2_mass))
                print ('nSignal_reco = '+str(nSignal_reco))
                print ('nSignal_raw reco = '+str(sigPlot.GetEntries()))
                if signal_truth_map[str(Sb_mass)+'_'+str(N2_mass)] ==0:
                    signal_Eff_map[str(Sb_mass)+'_'+str(N2_mass)]=0.001
                else:
                    signal_Eff_map[str(Sb_mass)+'_'+str(N2_mass)]=nSignal_reco/signal_truth_map[str(Sb_mass)+'_'+str(N2_mass)]
                Significance_reco.Fill(int(Sb_mass), int(N2_mass), nSignal)

            except:
                print(str(reco_files)+"does not have a valid tree")
                nSignal_reco = -1
                failedTree = True
                
                
    if doEff:
        for masses in signal_Eff_map:
            sb_mass = int(masses.split('_')[0])
            n2_mass = int(masses.split('_')[1])
            print ("eff plot sb_mass: "+str(sb_mass))
            print ("eff plot n2_mass: "+str(n2_mass))
            print ("eff: "+str(signal_Eff_map[masses]))
            if signal_Eff_map[masses]==0:
                signal_Eff_map[masses]=0.001
            Significance.Fill(sb_mass, n2_mass, signal_Eff_map[masses])

    Significance.SetXTitle("m(#tilde{b}) [GeV]")
    #Significance.RebinX(25)
    #Significance.RebinY(10)
    Significance.SetTitleSize(0.03,"X")
    Significance.SetLabelSize(0.03,"X")
    Significance.SetTitleOffset(1.5,"x")
    Significance.SetYTitle("m( #tilde{#chi}_{2}^{0} ) [GeV]")
    Significance.SetTitleSize(0.03,"Y")
    Significance.SetLabelSize(0.03,"Y")
    Significance.SetTitleOffset(1.9,"y")
    Significance.LabelsDeflate() 
    Significance.SetTitleOffset(1.5,"Z")
    if doSignif:
        Significance.SetZTitle("Zn")
        Significance.GetZaxis().SetRangeUser(0,10)
    if doAccept:
        Significance.SetZTitle("Acceptance [%]")
        Significance.GetZaxis().SetRangeUser(0,20)
    if doEff:
        Significance.SetZTitle("Efficiency")
        Significance.GetZaxis().SetRangeUser(0,1)
    Significance.SetTitleSize(0.03,"Z")
    Significance.SetLabelSize(0.03,"Z")
    Significance.SetMarkerSize(0.7)
    #Significance.SetContour(1000)
    #gStyle->SetPaintTextFormat
    gStyle.SetPalette(ROOT.kBird)
    TColor.InvertPalette()
    
    gStyle.SetPaintTextFormat("1.2f")
    #gStyle.SetTextSize(size=0.025)

    
    print ("Cuts used: "+str(cutstouse))

    Canvas = ROOT.TCanvas("Canvas1","Canvas1",0,0,900,900)
    Canvas.SetRightMargin(0.15)
    Canvas.SetLeftMargin(0.15)
    Canvas.SetBottomMargin(0.1)
    Canvas.SetTopMargin(0.1)
    Significance.Draw("COLZ")
    Significance.Draw("TEXT45 same ")

    latex_draw(label)
    Canvas.SaveAs(outputdir + "sig_" + label + ".pdf")







if __name__ == '__main__':
    main()

#  LocalWords:  SMBkgNumber
