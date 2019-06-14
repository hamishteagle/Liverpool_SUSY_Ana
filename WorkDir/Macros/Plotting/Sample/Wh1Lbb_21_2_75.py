#
# File encoding the samples for 
# <enter some info here>
#
import sys,glob,getpass
sys.path.append("..")
from Samples import Sample,Samples

username=getpass.getuser()
if username=='hteagle':
    print 'username:   hteagle'
    path="/scratch/hteagle/Wh_Liv/ntuples_21.2.75/"
    data_path=path

ptag = ""

#@ LoadSamples here
def LoadSamples(trees=['CollectionTree_']):
   
    #init a class to manage the samples
    smpls=Samples("SbottomMultiB_21_2_62_057dcf2_combi")

    smpls.Add(Sample("zJets",
                     path=path,
                     patterns=["*MC16*/zJets.root"],
                     trees=trees))
    smpls.Add(Sample("wJets",
                     path=path,
                     patterns=["*MC16*/wJets.root"],
                     trees=trees))
    smpls.Add(Sample("singleTop",
                     path=path,
                     patterns=["*MC16*/singleTop.root"],
                     trees=trees))
    smpls.Add(Sample("ttbar",
                     path=path,
                     patterns=["*MC16*/ttbar.root"],
                     trees=trees))
    smpls.Add(Sample("ttV",
                     path=path,
                     patterns=["*MC16*/ttV.root"]
    smpls.Add(Sample("diboson",
                     path=path,
                     patterns=["*MC16*/diBoson.root"],
                     trees=trees))
    smpls.Add(Sample("dijet",
                     path=path,
                     patterns=["*MC16*/diJet.root"],
                     trees=trees))

    # scan and add signal samples   
    for sample in glob.glob(path+"/*.root"):
        if "C1N2_Wh_hbb" not in sample: continue 

        name=sample.split("/")[-1].split(".")[2]
        pattern="*%s*"%(sample.split("/")[-1].split(".")[1])
       
        #make sure not doubled up
        if name in smpls: continue
        
        smpls.Add(Sample(name,
                         path=path,
                         patterns=[pattern],
                         trees=trees))

        for key in smpls.keys():
                smpls[key].SetAlias("YearWeight","year==2018 ? 58.5/139 :(year==2017 ? 44.3/139 : 36.2/139)")

    smpls.Add(Sample("Data1516",
                     path=path,
                     patterns=["*DATA15*.root","*DATA16*.root"],
                     trees=trees))
    smpls.Add(Sample("Data17",
                     path=path,
                     patterns=["*DATA17*.root"],
                     trees=trees))
    smpls.Add(Sample("Data18",
                     path=path,
                     patterns=["*DATA18*.root"],
                     trees=trees))
    smpls.Add(Sample("Data",
                     path=data_path,
                     patterns=["*DATA*.root"],
                     trees=trees))
    return smpls
