import ROOT
from ROOT import TCanvas ,TFile, TTree, TH1F, gStyle

 f1=TFile.Open("/hepstore/hteagle/OutputTreeTrial/data-output/DAOD_TRUTH1.root")
if f1==0:
   print("file not found")
   raw_input('Press <ret> to end -> ')

gStyle.SetOptStat(0);

Scaling =f1.Get("h_sherpaWeights");
rawEvents = Scaling.Integral();
print "rawEvents is of type",type(rawEvents),"rawEvents= ",rawEvents
xSect = 8.5*1000 #in femtobarns
FilterEff = 0.204675
EffectiveLumi = rawEvents/(xSect*FilterEff)
ScalingFactor = 36.5/EffectiveLumi #Scaled to 36.5 fb^-1
print "ScalingFactor= ",ScalingFactor 
 
CollectionTree=f1.Get("CollectionTree_")

c1 = TCanvas("c1","c1",900,900)
c1.cd()
h1 = TH1F("h1","h1",10,95,145)
h1.SetTitle("Invariant Mass of final b-jet pairs:MaxMin Analysis;Invariant Mass (GeV)")
CollectionTree.Draw("InvMass_Bij_minR>>h1" , "ETMiss>200 && pTj1>80 && minDPhi>0.4 && nBJets>=4 && minDR<2.5 && InvMass_Bij_minR>95 && InvMass_Bij_minR<145")
c1.SaveAs("SummerAnalysis/Summer_Student_Analysis/histograms/TreeTrials/Python/300_295/InvMass_Bij_minR"
)

c2 = TCanvas("c2","c2",900,900)
c2.cd()
h2 = TH1F("h2","h2",10,95,145)
h2.SetTitle("Invariant Mass of final b-jet pairs:Min Ananlysis with nBJets>=4; Invariant Mass (GeV)")
CollectionTree.Draw("InvMass_Bij_minR1>>h2" , "ETMiss>200 && pTj1>80 && minDPhi>0.4 && nBJets>=4 && minDR1<2.5 && InvMass_Bij_minR1>95 && InvMass_Bij_minR1<145")

c2.SaveAs("SummerAnalysis/Summer_Student_Analysis/histograms/TreeTrials/Python/300_295/InvMass_Bij_minR1")




print "MaxMin Analysis method cutflow"
NoCuts = CollectionTree.Draw("1","","goff")
print "Number of entries; (no cuts)= ",NoCuts*ScalingFactor
Cut1 = CollectionTree.Draw("1","ETMiss>200","goff")
print "Number of entries; MET>200= ",Cut1*ScalingFactor
Cut2 = CollectionTree.Draw("1","ETMiss>200 && pTj1>80","goff")
print "Number of entries; MET>200, pTj1>80= ",Cut2*ScalingFactor
Cut3 = CollectionTree.Draw("1","ETMiss>200 && pTj1>80 && minDPhi>0.4","goff")
print "Number of entries; MET>200, pTj1>80, minDPhi>0.4= ",Cut3*ScalingFactor
Cut4 = CollectionTree.Draw("1","ETMiss>200 && pTj1>80 && minDPhi>0.4 && nBJets>=4","goff")
print "Number of entries; MET>200, pTj1>80, minDPhi>0.4, nBJets>=4= ",Cut4*ScalingFactor
Cut5 = CollectionTree.Draw("1","ETMiss>200 && pTj1>80 && minDPhi>0.4 && nBJets>=4 && minDR<2.5","goff")
print "Number of entries; MET>200, pTj1>80, minDPhi>0.4, nBJets>=4, minDR<2.5= ",Cut5*ScalingFactor
Cut6 = CollectionTree.Draw("1","ETMiss>200 && pTj1>80 && minDPhi>0.4 && nBJets>=4 && minDR<2.5 && InvMass_Bij_minR<145 && InvMass_Bij_minR>95 ","goff")
print "Number of entries;  MET>200, pTj1>80, minDPhi>0.4, nBJets>=4, minDR<2.5, 95<InvMass<145= ",Cut6*ScalingFactor



print "MaxMin Analysis method cutflow"
NominCuts = CollectionTree.Draw("1","","goff")
print "Number of entries; (no cuts)= ",NominCuts*ScalingFactor
minCut1 = CollectionTree.Draw("1","ETMiss>200","goff")
print "Number of entries; MET>200= ",minCut1*ScalingFactor
minCut2 = CollectionTree.Draw("1","ETMiss>200 && pTj1>80","goff")
print "Number of entries; MET>200, pTj1>80= ",minCut2*ScalingFactor
minCut3 = CollectionTree.Draw("1","ETMiss>200 && pTj1>80 && minDPhi>0.4","goff")
print "Number of entries; MET>200, pTj1>80, minDPhi>0.4= ",minCut3*ScalingFactor
minCut4 = CollectionTree.Draw("1","ETMiss>200 && pTj1>80 && minDPhi>0.4 && nBJets>=4","goff")
print "Number of entries; MET>200, pTj1>80, minDPhi>0.4, nBJets>=4= ",minCut4*ScalingFactor
minCut5 = CollectionTree.Draw("1","ETMiss>200 && pTj1>80 && minDPhi>0.4 && nBJets>=4 && minDR1<2.5","goff")
print "Number of entries; MET>200, pTj1>80, minDPhi>0.4, nBJets>=4, minDR1<2.5= ",minCut5*ScalingFactor
minCut6 = CollectionTree.Draw("1","ETMiss>200 && pTj1>80 && minDPhi>0.4 && nBJets>=4 && minDR1<2.5 && InvMass_Bij_minR1<145 && InvMass_Bij_minR1>95 ","goff")
print "Number of entries;  MET>200, pTj1>80, minDPhi>0.4, nBJets>=4, minDR1<2.5, 95<InvMass1<145= ",minCut6*ScalingFactor






raw_input('Press <ret> to end -> ')
