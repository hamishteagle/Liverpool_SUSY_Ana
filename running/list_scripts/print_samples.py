import os
samples =[]
with open("/user/hteagle/AnalysisDirectory/Rel21/Base.21.2.72/athena/Projects/running/list_scripts/my_W.txt","r") as wjets:

    for line in wjets:
        if "Sherpa_221_NNPDF30NNLO_W" in line and "MAXHTPTV" in line:
            samples.append(line.split(".")[6])
samples_twiki =[]
with open("/user/hteagle/AnalysisDirectory/Rel21/Base.21.2.72/athena/Projects/running/list_scripts/wjets_from_twiki.txt","r") as wjets:
    for line in wjets:
        samples_twiki.append(line.split(".")[1])
missing =set(samples_twiki)-set(samples)
extra  =set(samples)-set(samples_twiki)

for miss in missing:
    print("Missing: "+str(miss))
for ex in extra:
    print("Extra: "+str(ex))
