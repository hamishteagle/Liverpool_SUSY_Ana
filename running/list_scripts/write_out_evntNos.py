import ROOT

# file = "/user/hteagle/AnalysisDirectory/Rel21/Base.21.2.72/athena/Projects/running/submitdir/data-output/DAOD_SUSY5.root"
# f = ROOT.TFile(file)
# t =f.Get("CollectionTree_PFlow_")
# npass=0
# with open("evtNumLiv.txt","w") as out:
#     for event in range(t.GetEntries()):
#         t.GetEntry(event)
#         if t.GetLeaf("passedMuonClean").GetValue()>0:
#             if t.GetLeaf("nJets").GetValue()>=1:
#                 if (t.GetLeaf("nBaselineLeptons").GetValue()==1 or t.GetLeaf("nBaselineLeptons").GetValue()==2):
#                     out.write(str(t.GetLeaf("eventNumber").GetValue())+"\n")
#                     npass+=1
#
# exit()
liv =  open("evtNumLiv.txt","r")
lep1 = open("evtNumMsg.txt","r")
liv_nos=[]
lep1_nos=[]
for line in liv:
    try:
        f = float(line.rstrip("\n"))
        liv_nos.append(f)
    except:
        pass
for line in lep1:
    try:
        f= float(line.rstrip("\n"))
        lep1_nos.append(f)
    except: pass
if lep1_nos>liv_nos:
    diff= list(set(lep1_nos)-set(liv_nos))
else:
    diff= list(set(liv_nos)-set(lep1_nos))

print("Number of events different: ", len(diff))
liv.close()
lep1.close()

file = "/user/hteagle/AnalysisDirectory/Rel21/Base.21.2.72/athena/Projects/running/submitdir/data-output/DAOD_SUSY5.root"
f = ROOT.TFile(file)
t =f.Get("CollectionTree_PFlow_")
l1_f = ROOT.TFile("sample.root")
l1_t = l1_f.Get("tree_NoSys")


l1_variables = ["nLep_base"]
variables = ["nBaselineLeptons"]
#print("vars: %s : %s"%(variables[0],variables[1]))
for evnt in diff:
    l1_vars=[]
    liv_vars=[]
    for e in range(t.GetEntries()):
        t.GetEntry(e)
        if float(t.GetLeaf("eventNumber").GetValue())==evnt:
            liv_vars = [t.GetLeaf(var).GetValue() for var in variables]

    for e in range(l1_t.GetEntries()):
        l1_t.GetEntry(e)
        if float(l1_t.GetLeaf("EventNumber").GetValue())==evnt:
            l1_vars = [l1_t.GetLeaf(var).GetValue() for var in l1_variables]

    #print("l1: %s : %s"%(l1_vars[0],l1_vars[1]))
    print("liv: ",liv_vars)
    print("l1:  ",l1_vars)
