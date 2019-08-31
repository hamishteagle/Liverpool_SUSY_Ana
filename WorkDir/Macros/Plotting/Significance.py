#!/usr/bin/env python
import os, sys, math, ROOT, time
from ROOT import gROOT, TColor, TLatex, gStyle, TLegend, gPad, TAttText, RooStats, gPad


__author__ = "Hamish Teagle"
__doc__    = """Integrated Significance plotting and calculations"""


## Make sure that Path exists for output files
def ensure_dir(d):
    if not os.path.isdir(d):
        os.makedirs(d)

def latex_draw(label):

    Tl = ROOT.TLatex()
    Tl.SetTextSize(0.035)
    Tl.SetTextAlign(13)
    Tl.SetNDC(True)
    label=label.replace("_h","")
    if "High" in label: label = label.replace("High","HM")
    if "Med" in label: label = label.replace("Med","MM")
    if "Low" in label: label = label.replace("Low","LM")
    if "bin1" in label:    latex_label = label.replace("_bin1"," low m_{CT}")
    elif "bin2" in label:    latex_label = label.replace("_bin2"," med m_{CT}")
    elif "bin3" in label:    latex_label = label.replace("_bin3"," high m_{CT}")
    else: latex_label = label.replace("_Incl" ,"") 
    latex_label = latex_label.replace("SR_","SR-")
    yaml_label = latex_label.replace("m_{CT}","mCT")
    Tl.DrawLatex(0.15, 0.96,"#tilde{#chi}_{1}^{#pm}#tilde{#chi}_{2}^{0}, production, #tilde{#chi}_{1}^{#pm}#rightarrow W+#tilde{#chi}_{1}^{0}, #tilde{#chi}_{2}^{0}#rightarrow h+#tilde{#chi}_{1}^{0}")
    Tl.DrawLatex(0.64, 0.96,"#int L#it{dt} = 139 fb^{-1}, #sqrt{s} = 13 TeV")
    Tl.DrawLatex(0.18, 0.84,latex_label)
    Tl.SetTextSize(0.045)
    Tl.DrawLatex(0.17, 0.88,"#it{#bf{ATLAS} Simulation Internal}")
    return yaml_label
def make_yaml(label, var_map, doAccept, doEff, doStats, yaml_label):
    output_yaml_name = ".yaml"
    if doAccept:
        output_yaml_name = "Acc_" + label + ".yaml"
        header = "'Acceptance [$\\%$] "+label+"'"
    if doEff:
        output_yaml_name = "Eff_" + label + ".yaml"
        header = "'EFF', units:  '%' "

    file=open(output_yaml_name, "w+")

    file.write("dependent_variables:\n")
    file.write("- header: {name: "+header+"}\n")
    file.write("  qualifiers:\n")
    file.write("  - {name: Region, value: '"+yaml_label+"'}\n")
    file.write("  - {name: 'SQRT(S)', units: TeV, value: '13'}\n")
    file.write("  values:\n")
    #Get the content of each bin
    for i in var_map:
        if var_map[i]!=0:
            var=round(var_map[i]*1000)/1000
            file.write("  - {value: '"+str(var)+"'}\n")


    #Get the particle masses
    file.write("independent_variables:\n")
    file.write("- header: {name: M(CHARGINO1/NEUTRALINO2), units: GeV}\n")
    #file.write("- header: {name: '$m(\\tilde{\\chi}_{1}^{\\pm})', units: GeV}\n")
    file.write("  values:\n")
    #Get the masses of the N2
    for i in var_map:
        if var_map[i]!=0:
            mass = i.split('_')[0]
            CN2mass = mass.replace('p','.')
            file.write("  - {value: '"+str(CN2mass)+"'}\n")

    #Get the masses for the N1
    #file.write("- header: {name: '$m(\\tilde{\\chi}^0_1)', units: GeV}\n")
    file.write("- header: {name: M(NEUTRALINO1), units: GeV}\n")
    file.write("  values:\n")
    for i in var_map:
        if var_map[i]!=0:
            mass= i.split('_')[1]
            N1mass = mass.replace('p','.')
            file.write("  - {value: '"+str(N1mass)+"'}\n")
    file.close()

##Get the significance, Acceptance, Efficiency, truthstats or Acc x Eff for each point in the signal directory
##Pass the signal and backgrounds as strings
def Significance(cutstouse,luminosity, signalFiles,reco_signalFiles, bkgFile, label, doSignif, doAccept, doEff, doTruthStats, doRecoStats, doAccTimesEff, reco_directory, truth_directory):

    doStats=False
    if doEff:
        outputdir = "/user/hteagle//SummerAnalysis/Summer_Student_Analysis/histograms/Efficiencyplots/"
    if doAccept:
        outputdir = "/user/hteagle//SummerAnalysis/Summer_Student_Analysis/histograms/Acceptanceplots/"
    if doAccTimesEff:
        outputdir = "/user/hteagle//SummerAnalysis/Summer_Student_Analysis/histograms/AccTimesEffplots/"
    if doRecoStats or doTruthStats:
        doStats=True
    ensure_dir(outputdir)
    scaled_cutstouse = luminosity+cutstouse
    cutstouse_truth= "("+label+">0)"
    scaled_cutstouse_truth = luminosity+cutstouse_truth
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
        Significance = ROOT.TH2F("Acceptance","Put varaiable (cuts) title here",120,0,1400,240,0,650)
        Significance_for_graph = ROOT.TH2F("Acceptance","Put varaiable (cuts) title here",90,0,1150,90,-200,550)
        Significance_graph = ROOT.TGraph2D(3)
        Significance_graph.SetHistogram(Significance_for_graph)
        Significance_truth = ROOT.TH2F("Acceptance","Put varaiable (cuts) title here",30,200,1600,30,200,1600)
        Significance_reco = ROOT.TH2F("Acceptance","Put varaiable (cuts) title here",30,200,1600,30,200,1600)
        signal_Eff_map = {}
        signal_truth_map = {}
        signal_Acc_map = {}
        signal_Stat_map = {}
        signal_Stat_map_reco = {}
    print("Doing truth section")
    for files in signalFiles:
        print(files)
        signal = ROOT.TFile(directory+files+"/EwkOneLeptonTwoBjets2018.root")
        sigtree = signal.Get("CollectionTree_")
        #Set the aliases for the truth signal samples


        failedTree = False
        try:
            if doEff or doAccept or doAccTimesEff:
                sigtree.SetAlias("pileupWeight","eventWeight>-100")
                sigtree.SetAlias("jvtWeight","eventWeight>-100")
                sigtree.SetAlias("bTagWeight","eventWeight>-100")
                sigtree.SetAlias("leptonWeight","eventWeight>-100")
                sigtree.SetAlias("genWeight","(HFScale/1000)")


            sigPlot = ROOT.TH1F("sigPlot","sigPlot",1,0.5,1.5)
            sigPlot.Sumw2()
            sigtree.Draw("1>>sigPlot",cutstouse_truth)
            nSignal = sigPlot.Integral(0,100000000)
            scaled_sigPlot = ROOT.TH1F("scaled_sigPlot","scaled_sigPlot",1,0.5,1.5)
            scaled_sigPlot.Sumw2()
            sigtree.Draw("1>>scaled_sigPlot",scaled_cutstouse_truth)
            scaled_nSignal = scaled_sigPlot.Integral(0,100000000)
            #print("nSignal_truth",scaled_nSignal)
            #sigtree.GetEntry(0)
            #xsec = sigtree.GetLeaf("cross_section").GetValue()
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
            #print("nSignal: "+str(nSignal))
            #print("scaled_nSignal: "+str(scaled_nSignal))
            #Accept = (nSignal/nSum)*0.78*100
            Accept = (scaled_nSignal/(xsec*139000))*100
            Sb_mass = files.split('_')[4]
            N2_mass = files.split('_')[5]

            #print ('Sb_mass = '+str(Sb_mass)+',N2_mass = '+str(N2_mass)+", Acceptance: "+str(Accept)+",xsec :"+str(xsec))
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
            Sb_mass = files.split('_')[6].replace('p','.')
            N2_mass = files.split('_')[7].replace('p','.')
            signal_truth_map[str(Sb_mass)+'_'+str(N2_mass)]=scaled_nSignal
            signal_Stat_map[str(Sb_mass)+'_'+str(N2_mass)]=sigPlot.GetEntries()


            sigPlot.Delete()
    #Calculate the Efficiency
    if doEff or doAccTimesEff:

        for treename,reco_files in reco_signalFiles.items():

            #print(str(reco_files))
            signal_reco = ROOT.TFile(directory_reco+reco_files)
            sigtree = signal_reco.Get(treename)


            sigPlot = ROOT.TH1F("sigPlot","Title",1,0.5,1.5)
            sigPlot.Sumw2()

            failedTree = False
            ##Avoid messing up because one of the files is screwed



            sigtree.Draw("1>>sigPlot",scaled_cutstouse)
            nSignal_reco = sigPlot.Integral(0,1000000000)
            Sb_mass = treename.split('_')[3].replace('p','.')
            #print("C1_mass",Sb_mass)
            N2_mass = treename.split('_')[4].replace('p','.')
            #print("N1_mass",N2_mass)
            signal_Stat_map_reco[str(Sb_mass)+'_'+str(N2_mass)]=sigPlot.GetEntries()
            #print(signal_truth_map[str(Sb_mass)+'_'+str(N2_mass)])
            if signal_truth_map[str(Sb_mass)+'_'+str(N2_mass)]==0:
                signal_Eff_map[str(Sb_mass)+'_'+str(N2_mass)]=0
                print("THIS FILE HAS ZERO TRUTH ENTRIES")
            else:
                signal_Eff_map[str(Sb_mass)+'_'+str(N2_mass)]=((nSignal_reco/signal_truth_map[str(Sb_mass)+'_'+str(N2_mass)])*100)
                print("C1_mass:",Sb_mass)
                print("N1_mass:",N2_mass)
                print("nTruth:",signal_truth_map[str(Sb_mass)+'_'+str(N2_mass)])
                print("nReco:",nSignal_reco)
                print("First Eff: "+str((nSignal_reco/signal_truth_map[str(Sb_mass)+'_'+str(N2_mass)])*100))
                if (Sb_mass=="600.0" and N2_mass=="200.0"):
                    print(scaled_cutstouse)
                    #exit()

    #Fill the TH2 with the efficiencies
    if doEff or doAccTimesEff:
        if not doStats:
            for value,masses in enumerate(signal_Eff_map):
                sb_mass = float(masses.split('_')[0])
                n2_mass = float(masses.split('_')[1])
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
                        Significance_graph.SetPoint(value, sb_mass, n2_mass, signal_Eff_map[masses])
                    if doAccTimesEff:
                        Significance.Fill(sb_mass, n2_mass, AccXEff)

        elif doStats:
            if doTruthStats:
                for masses in signal_Stat_map:
                    sb_mass = int(masses.split('_')[0])
                    n2_mass = int(masses.split('_')[1])
                    #print ("eff plot sb_mass: "+str(sb_mass))
                    #print ("eff plot n2_mass: "+str(n2_mass))
                    #print ("stat: "+str(signal_Stat_map[masses]))
                    if signal_Stat_map[masses]==0:
                        signal_Stat_map[masses]=0.001
                    Significance.Fill(sb_mass, n2_mass, signal_Stat_map[masses])
            if doRecoStats:
                for masses in signal_Stat_map_reco:
                    sb_mass = int(masses.split('_')[0])
                    n2_mass = int(masses.split('_')[1])
                    #print ("eff plot sb_mass: "+str(sb_mass))
                    #print ("eff plot n2_mass: "+str(n2_mass))
                    #print ("stat: "+str(signal_Stat_map[masses]))
                    if signal_Stat_map_reco[masses]==0:
                        signal_Stat_map_reco[masses]=0.001
                    Significance.Fill(sb_mass, n2_mass, signal_Stat_map_reco[masses])

    Significance.SetXTitle("m( #tilde{#chi}_{2}^{0}/#tilde{#chi}_{1}^{#pm})  [GeV]")
    #Significance.RebinX(25)
    #Significance.RebinY(10)
    Significance.SetTitleSize(0.03,"X")
    Significance.SetLabelSize(0.03,"X")
    Significance.SetTitleOffset(1.5,"x")
    Significance.SetYTitle("m( #tilde{#chi}_{1}^{0} ) [GeV]")
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
        if doTruthStats:
            Significance.SetZTitle("Truth Statistics")
            Significance.GetZaxis().SetRangeUser(0,1)
        if doRecoStats:
            Significance.SetZTitle("Reco Statistics")
            Significance.GetZaxis().SetRangeUser(0,1)
    if doAccTimesEff:
        Significance.SetZTitle("Acceptance x Efficiency")
        Significance.GetZaxis().SetRangeUser(0,1500)
        Significance.SetTitleOffset(1.9,"Z")
    Significance.SetTitleSize(0.03,"Z")
    Significance.SetLabelSize(0.03,"Z")
    Significance.SetMarkerSize(0.6)
    #Significance.SetContour(1000)
    #gStyle->SetPaintTextFormat
    gStyle.SetPalette(ROOT.kBird)
    #TColor.InvertPalette()

    if  doStats:
        gStyle.SetPaintTextFormat("1.0f")
    else:
        gStyle.SetPaintTextFormat("0.0f")


    print ("Cuts used: "+str(cutstouse))

    Canvas = ROOT.TCanvas("Canvas1","Canvas1",0,0,1500,900)
    Canvas.SetRightMargin(0.15)
    Canvas.SetLeftMargin(0.15)
    Canvas.SetBottomMargin(0.15)
    Canvas.SetTopMargin(0.1)
    #Significance.Draw("COLZ")
    Significance.Draw("TEXT")
    if doEff:
        Significance_graph.SetTitle(";m_{#tilde{#chi_{1}}^{#pm}} / m_{#tilde{#chi_{2}}^{0}} [GeV]; m_{#tilde{#chi_{1}}^{0}} [GeV]      ;Efficiency %")
        Significance_graph.Draw("COLZ")
        Significance_graph.GetXaxis().SetLimits(100,1200)
        Significance_graph.GetYaxis().SetLimits(-50,600)

    Significance.Draw("TEXT45 same")



    yaml_label = latex_draw(label)
    label=label.replace("_Incl","")
    if doStats:
        if doRecoStats:
            label=label+"_reco"
            Canvas.SaveAs(outputdir + label + "_stats.pdf")
            Canvas.SaveAs(outputdir + label + "_stats.C")
    else:
        Canvas.SaveAs(outputdir +"Eff" + label + ".pdf")
        Canvas.SaveAs(outputdir +"Eff" + label + ".png")
        Canvas.SaveAs(outputdir +"Eff" + label + ".C")

    if doEff:
        make_yaml(label, signal_Eff_map , doAccept, doEff, doStats, yaml_label)
    if doAccept:
        make_yaml(label, signal_Acc_map , doAccept, doEff, doStats, yaml_label)






if __name__ == '__main__':
    main()

#  LocalWords:  SMBkgNumber
