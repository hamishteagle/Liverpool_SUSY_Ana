from collections import OrderedDict
import ROOT
import logging
debug_level=logging.INFO


#managing the samples together
class Samples:
    allSamples=None
    def __init__(self,name=""):
        self.allSamples=OrderedDict()
        self.name=name
        
    def setAlias(self,name,expression):
        for sample in self.allSamples:
            self.allSamples[sample].setAlias(name,expression)

    def Add(self,sample):
        msg.debug("Adding in a new samples %s"%(sample.name))
        #set a scale for the sample
        self.allSamples[sample.name]=sample

    def printChains(self):
        msg.info(self.name)
        for key,item in self.nom_chain.items():
            msg.info("-------- tree=%s entries=%i "%(key,item.GetEntries()))

    def getListOfFiles(self,key):
        return [x.GetTitle() for x in self.allSamples[key][self.allSamples[key].keys()[0]].GetListOfFiles ()]

    
#managing a sample
class Sample:                 
    nom_chain = None
    name      = None
    path      = None
    pattern   = None
    def __init__(self,name,path="",pattern):
        self.name=name
        msg.debug("Initiated sample with name: %s, and path %s"%(name,path))
        

                #loop over the trees
        for tree in trees:
            #loop over the patterns
            nom_chain=ROOT.TChain(tree)
            msg.info("")
            msg.info("Looking in path=%s"%(path))
            msg.info("Setup a TChain for sample=%s with treename=%s"%(name,tree))
            for pattern in patterns:
                msg.info("Adding sample to %s/%s with pattern=%s"%(name,tree,pattern))
                for item in glob.glob(path+pattern):
                    msg.debug("    ADDDING %s"%(item))
                        ch.Add(item)


    def getNominalTree(self):
        return self.nom_chain.keys()[0]
