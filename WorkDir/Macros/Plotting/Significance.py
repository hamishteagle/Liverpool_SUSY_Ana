#!/usr/bin/env python 
import os, sys, math, ROOT, time
from ROOT import gROOT, TColor, TLatex, gStyle, TLegend, gPad, TAttText, RooStats


__author__ = "Hamish Teagle"
__doc__    = """Integrated Significance plotting and calculations"""


## Make sure that Path exists for output files
def ensure_dir(d):
    if not os.path.isdir(d):
        os.makedirs(d)

def latex_draw(label, dom60):
    
    Tl = ROOT.TLatex()
    Tl.SetTextSize(0.020)
    Tl.SetTextAlign(13)
    Tl.SetNDC(True)

    if dom60:
        Tl.DrawLatex(0.15, 0.94,"#tilde{b}#tilde{b} production, #tilde{b}#rightarrow b+#tilde{#chi}_{2}^{0}, #tilde{#chi}_{2}^{0}#rightarrow h+#tilde{#chi}_{1}^{0}, m(#tilde{#chi}_{1}^{0})=60GeV")
    else:
        Tl.DrawLatex(0.15, 0.94,"#tilde{b}#tilde{b} production, #tilde{b}#rightarrow b+#tilde{#chi}_{2}^{0}, #tilde{#chi}_{2}^{0}#rightarrow h+#tilde{#chi}_{1}^{0}, #Deltam(#tilde{#chi}_{2}^{0},#tilde{#chi}_{1}^{0})=130GeV")
    Tl.DrawLatex(0.64, 0.94,"#int L#it{dt} = 139 fb^{-1}, #sqrt{s} = 13 TeV")
    Tl.DrawLatex(0.17, 0.84,"Region: #bf{"+label+"}")
    Tl.SetTextSize(0.045)
    Tl.DrawLatex(0.17, 0.88,"#it{#bf{ATLAS} Simulation}")

def make_yaml(label, var_map, doAccept, doEff, doStats, dom60):
    output_yaml_name = ".yaml"
    if doAccept:
        output_yaml_name = "Acc_" + label + ".yaml"
        header = "'Acceptance [$\\%$] "+label+"'"
        if label.find("SRA")!=-1 and dom60:
            output_yaml_name = "Acc_" + label + "_m60.yaml"
    if doEff:
        output_yaml_name = "Eff_" + label + ".yaml"
        header = "Efficiency [$\\%$] "+label+"'"
        if label.find("SRA")!=-1 and dom60:
            output_yaml_name = "Acc_" + label + "_m60.yaml"
        

        
    file=open(output_yaml_name, "w+")

    file.write("dependent_variables:\n")
    file.write("- header:{name: "+header+"}\n") 
    file.write("  qualifiers:\n")
    file.write("  - {name: '$\sqrt{s}$', units: GeV, value: '13000.0'}\n")
    file.write("  - {name: . , value: '"+label+"'}\n")
    file.write("  values:\n")
    #Get the content of each bin 
    for i in var_map:
        if var_map[i]!=0:
            var=round(var_map[i]*100)/100
            file.write("  -{value: '"+str(var)+"'}\n")
            

    #Get the particle masses
    file.write("independent_variables:\n")
    file.write("- header: {name: '$m(\\tilde{\\chi}^0_2, \\tilde{\\chi}^{+/-}_1)', units: GeV}\n")
    file.write("  values:\n")
    #Get the masses of the C1/N2
    for i in var_map:
        mass = i.split('_')[0]
        CN2mass = mass.replace('p','.')
        file.write("  - {value: '"+str(CN2mass)+"'}\n")
    
    #Get the masses for the N1 
    file.write("- header: {name: '$m(\\tilde{\\chi}^0_1)', units: GeV}\n")
    file.write("  values:\n")
    for i in var_map:
        mass= i.split('_')[1]
        N1mass = mass.replace('p','.')
        file.write("  - {value: '"+str(N1mass)+"'}\n")
    file.close()

##Get the significance, Acceptance, Efficiency, truthstats or Acc x Eff for each point in the signal directory
##Pass the signal and backgrounds as strings 
def Significance(cutstouse,luminosity, signalFiles,reco_signalFiles, bkgFile, label, doSignif, doAccept, doEff, doStats, doAccTimesEff, reco_directory, truth_directory):
    
    if doEff:
        outputdir = "/user/hteagle//SummerAnalysis/Summer_Student_Analysis/histograms/Efficiencyplots/"   
    if doAccept:
        outputdir = "/user/hteagle//SummerAnalysis/Summer_Student_Analysis/histograms/Acceptanceplots/"   
    if doAccTimesEff:
        outputdir = "/user/hteagle//SummerAnalysis/Summer_Student_Analysis/histograms/AccTimesEffplots/"
    
    ensure_dir(outputdir)
    scaled_cutstouse = luminosity+cutstouse
        
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
        
    directory = truth_directory
    directory_reco = reco_directory
    if doAccept or doEff or doAccTimesEff:
        dom60 = False
        dodm130 = False
        if directory.find("m60")!=-1:
            dom60= True
            Significance = ROOT.TH2F("Acceptance","Put varaiable (cuts) title here",30,200,1700,60,200,1700)
        else:
            dodm130=True
            Significance = ROOT.TH2F("Acceptance","Put varaiable (cuts) title here",24,300,1500,30,0,1500)

        Significance_truth = ROOT.TH2F("Acceptance","Put varaiable (cuts) title here",30,200,1600,30,200,1600)
        Significance_reco = ROOT.TH2F("Acceptance","Put varaiable (cuts) title here",30,200,1600,30,200,1600)
        signal_Eff_map = {}
        signal_truth_map = {}
        signal_Acc_map = {}
        signal_Stat_map = {}
    for files in signalFiles:
        #print(files)
        signal = ROOT.TFile(directory+files)
        sigtree = signal.Get("ntuple")
        #Set the aliases for the truth signal samples


        failedTree = False
        try:
            if doEff or doAccept or doAccTimesEff:
                sigtree.SetAlias("YearWeight","eventWeight>-100")
                sigtree.SetAlias("pileupweight","eventWeight>-100")
                sigtree.SetAlias("jvtweight","eventWeight>-100")
                sigtree.SetAlias("btagweight","eventWeight>-100")
                sigtree.SetAlias("AnalysisWeight","eventWeight")
                sigtree.SetAlias("LumiWeight","(HFScale/1000)")
                
                sigtree.SetAlias("passMETtriggers","eventWeight>-100")
                sigtree.SetAlias("passtauveto","eventWeight>-100")
                sigtree.SetAlias("nbaselineLep","nBaselineLeptons")
                sigtree.SetAlias("dphimin4_orig","minDPhiJMET_4")
                sigtree.SetAlias("nj_good","nJets")
                sigtree.SetAlias("num_bjets","nBJets")
                sigtree.SetAlias("eT_miss_orig","ETMiss")                        
                sigtree.SetAlias("metsigHT","metsig_HT")
                sigtree.SetAlias("maxDRbb","maxDR")
                sigtree.SetAlias("maxminDRbb","maxminDR")
                sigtree.SetAlias("leadb1","(pTj1==pTb1)")
                sigtree.SetAlias("SRB3_mbb_avg","max_avg_M")
                sigtree.SetAlias("dPhi_1jet","DPhiJMET_1")
                sigtree.SetAlias("maxminDRmbb","maxmin_M")
                sigtree.SetAlias("pT_1jet","pTj1")
                sigtree.SetAlias("pT_1bjet","pTb1")
            sigPlot = ROOT.TH1F("sigPlot","sigPlot",1,0.5,1.5) 
            sigPlot.Sumw2()
            sigtree.Draw("1>>sigPlot",cutstouse)
            nSignal = sigPlot.Integral(0,100000000)

            scaled_sigPlot = ROOT.TH1F("scaled_sigPlot","scaled_sigPlot",1,0.5,1.5) 
            scaled_sigPlot.Sumw2()
            sigtree.Draw("1>>scaled_sigPlot",scaled_cutstouse)
            scaled_nSignal = scaled_sigPlot.Integral(0,100000000)

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
        if (doAccept and not failedTree) or (doAccTimesEff and not failedTree):
            h_SumOfWeights = signal.Get("h_SumOfWeights")
            nSum = h_SumOfWeights.Integral(0,1000000)
            print("nSignal: "+str(nSignal))
            print("scaled_nSignal: "+str(scaled_nSignal))
            Accept = (nSignal/nSum)*0.78*100
            Sb_mass = files.split('_')[4]
            N2_mass = files.split('_')[5]
            
            print ('Sb_mass = '+str(Sb_mass)+',N2_mass = '+str(N2_mass)+", Acceptance: "+str(Accept))
            binx = Significance.GetXaxis().FindBin(int(Sb_mass))
            biny = Significance.GetYaxis().FindBin(int(N2_mass))
            if doAccTimesEff:
                signal_Acc_map[str(Sb_mass)+'_'+str(N2_mass)] = Accept
            if doAccept:
                signal_Acc_map[str(Sb_mass)+'_'+str(N2_mass)] = Accept
                if Significance.GetBinContent(binx,biny)>0:
                    print ("This bin already has content!!")
                    Significance.SetBinContent(binx,biny, (Significance.GetBinContent(binx,biny)+Accept)/2)
                else :
                    Significance.Fill(int(Sb_mass), int(N2_mass), Accept)

        if (doEff or doAccTimesEff) and not failedTree:
            Sb_mass = files.split('_')[4]
            N2_mass = files.split('_')[5]
            signal_truth_map[str(Sb_mass)+'_'+str(N2_mass)]=scaled_nSignal
            signal_Stat_map[str(Sb_mass)+'_'+str(N2_mass)]=sigPlot.GetEntries()
            sigPlot.Delete()
    #Calculate the Efficiency
    if doEff or doAccTimesEff:
        for reco_files in reco_signalFiles:

            #print(str(reco_files))
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
                if reco_files.find('_a_d_e.root')!=-1:
                    sigtree.SetAlias("YearWeight","year==2018 ? 58.5/139 :(year==2017 ? 44.3/139 : 36.2/139)")                    
                elif reco_files.find('_a_d.root')!=-1:
                    sigtree.SetAlias("YearWeight","year==2017 ? 44.3/79.5 : 36.2/79.5") 
                elif reco_files.find('_d_e.root')!=-1:
                    sigtree.SetAlias("YearWeight","year==2018 ? 58.5/79.5 : 44.3/102.8") 
                elif reco_files.find('_a_e.root')!=-1:
                    sigtree.SetAlias("YearWeight","year==2018 ? 58.5/94.7 : 36.2/94.7") 
                sigtree.Draw("1>>sigPlot",scaled_cutstouse)
                nSignal_reco = sigPlot.Integral(0,1000000000)
                Sb_mass = reco_files.split('_')[5]
                N2_mass = reco_files.split('_')[6]
                if signal_truth_map[str(Sb_mass)+'_'+str(N2_mass)] ==0 or nSignal_reco==0:
                    signal_Eff_map[str(Sb_mass)+'_'+str(N2_mass)]=0
                else:
                    
                    signal_Eff_map[str(Sb_mass)+'_'+str(N2_mass)]=(nSignal_reco/signal_truth_map[str(Sb_mass)+'_'+str(N2_mass)])*100
                print("First Eff: "+str((nSignal_reco/signal_truth_map[str(Sb_mass)+'_'+str(N2_mass)])*100))
            except:
                print(str(reco_files)+"does not have a valid tree")
                nSignal_reco = -1
                failedTree = True
                
    #Fill the TH2 with the efficiencies
    if doEff or doAccTimesEff:
        if not doStats:
            for masses in signal_Eff_map:
                sb_mass = int(masses.split('_')[0])
                n2_mass = int(masses.split('_')[1])
                if doAccTimesEff:
                    AccXEff = signal_Acc_map[masses]*signal_Eff_map[masses]
                    print ("sb_mass: "+str(sb_mass)+", n2_mass: "+str(n2_mass)+", eff: "+str(signal_Eff_map[masses])+", AccXeff: "+str(AccXEff))
                else:
                    print ("sb_mass: "+str(sb_mass)+", n2_mass: "+str(n2_mass)+", eff: "+str(signal_Eff_map[masses]))
                #average for bins too close:
                binx = Significance.GetXaxis().FindBin(sb_mass)
                biny = Significance.GetYaxis().FindBin(n2_mass)
                if Significance.GetBinContent(binx,biny)>0:
                    print ("This bin already has content!!")
                    if doEff:
                        Significance.SetBinContent(binx,biny, (Significance.GetBinContent(binx,biny)+signal_Eff_map[masses])/2)
                    if doAccTimesEff:
                        Significance.SetBinContent(binx,biny, (Significance.GetBinContent(binx,biny)+AccXEff)/2)
                else :
                    if doEff:
                        Significance.Fill(sb_mass, n2_mass, signal_Eff_map[masses])
                    if doAccTimesEff:
                        Significance.Fill(sb_mass, n2_mass, AccXEff)
                    
        elif doStats:
            for masses in signal_Stat_map:
                sb_mass = int(masses.split('_')[0])
                n2_mass = int(masses.split('_')[1])
                print ("eff plot sb_mass: "+str(sb_mass))
                print ("eff plot n2_mass: "+str(n2_mass))
                print ("stat: "+str(signal_Stat_map[masses]))
                if signal_Stat_map[masses]==0:
                    signal_Stat_map[masses]=0.001
                Significance.Fill(sb_mass, n2_mass, signal_Stat_map[masses])
            
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
    #Significance.LabelsDeflate() 
    Significance.SetTitleOffset(1.5,"Z")
    if doSignif:
        Significance.SetZTitle("Zn")
        Significance.GetZaxis().SetRangeUser(0,10)
    if doAccept:
        Significance.SetZTitle("Acceptance [%]")
        Significance.GetZaxis().SetRangeUser(0,10)
    if doEff and not doStats:
        Significance.SetZTitle("Efficiency [%]")
        Significance.GetZaxis().SetRangeUser(0,100)
    if doStats:
        Significance.SetZTitle("Truth Statistics")
        Significance.GetZaxis().SetRangeUser(0,1)
    if doAccTimesEff:
        Significance.SetZTitle("Acceptance x Efficiency")
        Significance.GetZaxis().SetRangeUser(0,1500)
        Significance.SetTitleOffset(1.9,"Z")
    Significance.SetTitleSize(0.03,"Z")
    Significance.SetLabelSize(0.03,"Z")
    Significance.SetMarkerSize(0.5)
    #Significance.SetContour(1000)
    #gStyle->SetPaintTextFormat
    gStyle.SetPalette(ROOT.kBird)
    TColor.InvertPalette()
    
    if  doStats:
        gStyle.SetPaintTextFormat("1.0f")
    else:
        gStyle.SetPaintTextFormat("1.2f")
    #gStyle.SetTextSize(size=0.025)

    
    print ("Cuts used: "+str(cutstouse))

    Canvas = ROOT.TCanvas("Canvas1","Canvas1",0,0,900,900)
    Canvas.SetRightMargin(0.15)
    Canvas.SetLeftMargin(0.15)
    Canvas.SetBottomMargin(0.1)
    Canvas.SetTopMargin(0.1)
    Significance.Draw("COLZ")
    if dom60:
        Significance.Draw("TEXT same ")
    else:
        Significance.Draw("TEXT45 same ")

    latex_draw(label, dom60)
    if doStats:
        if dom60 and label.find("SRA") !=-1:
            Canvas.SaveAs(outputdir + "sig_" + label + "_stats_m60.pdf")        
        else: 
            Canvas.SaveAs(outputdir + "sig_" + label + "_stats.pdf")        
    else:
        if dom60 and label.find("SRA") !=-1:
            Canvas.SaveAs(outputdir + "sig_" + label + "_m60.pdf")        
        else: 
            Canvas.SaveAs(outputdir + "sig_" + label + ".pdf")        
            
    if doEff:
        make_yaml(label, signal_Eff_map , doAccept, doEff, doStats, dom60)
    if doAccept:
        make_yaml(label, signal_Acc_map , doAccept, doEff, doStats, dom60)
                   





if __name__ == '__main__':
    main()

#  LocalWords:  SMBkgNumber
