import argparse
import matplotlib.pyplot as plt
import math
from matplotlib import gridspec
import numpy as np
import ROOT as R
from ROOT import TFile, TTree, TH1D, TPad, RooStats, TCanvas, TH1F, THStack




def ShapeFit(input_sig_str, input_bkg_str, variable, uncert, direct):

    # Load ROOT files
    input_sig = TFile(input_sig_str)
    input_bkg = TFile(input_bkg_str)
    sig_tree  = input_sig.Get('ntuple')
    bkg_tree  = input_bkg.Get('ntuple')
    # Check variable exists!
    if variable not in sig_tree.GetListOfBranches() and variable not in bkg_tree.GetListOfBranches():
        print('Variable not found in TTrees, quitting.')
        quit()
    # Get NN/BDT distributions
    sig_events  = []
    sig_weights = []
    bkg_events  = []
    bkg_weights = []
    for entry in range(sig_tree.GetEntries()):
        sig_tree.GetEntry(entry)
        sig_events.append(sig_tree.GetLeaf(variable).GetValue())
        sig_weights.append(150.*sig_tree.eventWeight*sig_tree.HFScale)
    for entry in range(bkg_tree.GetEntries()):
        bkg_tree.GetEntry(entry)
        bkg_events.append(bkg_tree.GetLeaf(variable).GetValue())
        bkg_weights.append(150.*bkg_tree.eventWeight*bkg_tree.HFScale)
    # Sort bins
    nbins = 50
    thebins = np.linspace(0,1,nbins+1)
    binspacing = thebins[1] - thebins[0]
    # Define layout
    fig = plt.figure(figsize=(8,6))
    gs = gridspec.GridSpec(2, 1, height_ratios=[3, 1], hspace=0.0)
    #plt.rc('text', usetex=True)
    # Do histogram plot first
    plt1 = plt.subplot(gs[0])
    sig_tuple = plt.hist(sig_events, log=True, bins=thebins, alpha = 0.5, weights=sig_weights, label=str(sig_tree.C1N2_mass)+', '+str(sig_tree.N1_mass))
    bkg_tuple = plt.hist(bkg_events, log=True, bins=thebins, alpha = 0.5, weights=bkg_weights, label='ttbar')
    plt.legend(loc='upper right')
    plt.ylabel('Events / ' + str(binspacing))
    plt.ylim(1, 100000)
    #plt.text(-0.8, 10000, r'ATLAS \textit{Internal}', {'fontsize': 30}, family='sans-serif')
    # Now do significance plot
    plt2 = plt.subplot(gs[1], sharex=plt1)
    signif = []
    bin_x  = []
    for i in range(int(nbins)):
        bin_x.append(0+(i*binspacing))
        sig_yield = 0.
        bkg_yield = 0.
        for j in range(i, int(nbins)):
            sig_yield+=sig_tuple[0][j]
            bkg_yield+=bkg_tuple[0][j]
        signif.append(RooStats.NumberCountingUtils.BinomialExpZ(sig_yield, bkg_yield, uncert))
    print(len(bin_x), len(signif))
    plt.scatter(bin_x, signif)
    plt.xlim(-0.05,1.05)
    plt.xlabel('Response')
    plt.ylabel('Zn @ 30% unc.')
    plt.setp(plt1.get_xticklabels(), visible=False)
    # Remove space between plots
    plt.tight_layout()
    # Save figure
    print ("SaveAs", direct+variable+"_"+str(uncert)+'_'+str(sig_tree.C1N2_mass)+'_'+str(sig_tree.N1_mass)+'.pdf')
    plt.savefig(direct+variable+"_"+str(uncert)+'_'+str(sig_tree.C1N2_mass)+'_'+str(sig_tree.N1_mass)+'.pdf')
    return signif

def multiFit(signal_list, background, variable, uncert, direct):

    significances = {}
    significance_hists = {}
    #These need to be the same as above
    nbins = 50
    xmin = 0
    xmax = 1
    Canvas = TCanvas("Canvas","Canvas",0,0,900,900)
    Legend = R.TLegend(0.30,0.76,0.45,0.94)
    j=0
    save_string = ""
    for signal in signal_list:
        significances[signal]=ShapeFit(signal, background, variable, uncert, direct)
        Significance_Full = TH1F("Significance_Full","Significance vs Variable cut",nbins,xmin,xmax)
        i=1
        for z in significances[signal]:
            print (z)
            #Significance_Full.Fill(i,z)
            if z >1000000:
                z=0
            Significance_Full.SetBinContent(i,z)
            i+=1
        significance_hists[signal] = Significance_Full
        print('Integral',Significance_Full.Integral())
        
        Significance_Full.SetLineColor(R.kRed+j)
        Significance_Full.GetXaxis().SetRangeUser(0.15,0.4)
        Significance_Full.GetYaxis().SetTitle("Zn")
        Significance_Full.GetXaxis().SetTitle("Variable Cut")
        Significance_Full.SetMinimum(0.)
        Significance_Full.SetMaximum(Significance_Full.GetMaximum()*1.5)
        pre_string = signal.split("Wh_hall")[1]
        string = pre_string.split('__')[0]
        save_string += string
        Legend.AddEntry(Significance_Full,string,"L")

        if signal == signal_list[0]:
            Significance_Full.Draw("HIST")
        else:
            Significance_Full.Draw("HIST same")
        j+=1
    Legend.Draw()
    Canvas.SaveAs(direct+variable+save_string+'_multiSig.pdf')
