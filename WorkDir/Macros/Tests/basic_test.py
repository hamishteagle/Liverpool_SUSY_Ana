import ROOT
ROOT.PyConfig.IgnoreCommandLineOptions = True
ROOT.gROOT.SetBatch(True)
import json, collections
import os
import glob
import copy
import unittest
import argparse
import sys

class Livana(unittest.TestCase):
    # maximum allowed difference between cutflows
    maxDiff = None
    t = None
    # preserve location of this script
    __location__ = os.path.realpath(os.path.join(os.getcwd(), os.path.dirname(__file__)))
    
    #@staticmethod
    def write_cutflow(self):
        cuts_dict = {}
        #Things are nicer if they're ordered in the json file
        flow_dict = collections.OrderedDict() 
        with open(self.cuts_json,'r') as ofile:
            cuts_dict = json.load(ofile, object_pairs_hook=collections.OrderedDict)#Get the cuts from the json in the correct order
        cutnow = "1"
        for var, val in cuts_dict.items():
            cutnow += "*("+str(var)+str(val)+")" #Build the cuts iteratively 
            flow_dict[var] = self.t.GetEntries(str(cutnow))
            if (flow_dict[var]==0):
                raise IOError('cut of "{0:s} {1:s}" is too tight (0 events) change this cut'.format(var, val))
            else:
                print("cut: "+str(var)+" at: "+str(cuts_dict[var])+" events: "+str(flow_dict[var]))
            
        with open(self.__location__+"/default/checkout.json","w") as self.check_json:
            json.dump(flow_dict,self.check_json)
    
    def get_runfile(self):
        #pick up the root files in the given submission dir
        default_runfile_path = glob.glob(os.path.join(Livana.args["submit_dir"],'*.root'))
        if len(default_runfile_path) >1:
            raise IOError('more than 1 root file in given dir: "{0:s}"'.format(Livana.args["submit_dir"]))
        if not os.path.isfile(default_runfile_path[0]):
            raise IOError('root file does not exist in given dir: "{0:s}"'.format(Livana.args["submit_dir"]))
        self.f = ROOT.TFile.Open(default_runfile_path[0])
        self.t = self.f.Get('CollectionTree_')



    def get_json(self):
        default_json_path = os.path.join(Livana.__location__,'default','cutflow.json')
        if not os.path.isfile(default_json_path):
            raise IOError('json file does not exist in this running dir: "{0:s}"'.format(default_json_path))
        self.cuflow_json = default_json_path

    def get_cuts_json(self):
        default_cuts_json_path = os.path.join(Livana.__location__,'default','cuts.json')
        if not os.path.isfile(default_cuts_json_path):
            raise IOError('json file does not exist in this running dir: "{0:s}"'.format(default_cuts_json_path))
        self.cuts_json = default_cuts_json_path

    def test_cutflow(self):
        #pick up the root files in the given submission dir
        default_runfile_path = glob.glob(os.path.join(Livana.args["submit_dir"],'*.root'))
        if len(default_runfile_path) >1:
            raise IOError('more than 1 root file in given dir: "{0:s}"'.format(Livana.args["submit_dir"]))
        if not os.path.isfile(default_runfile_path[0]):
            raise IOError('root file does not exist in given dir: "{0:s}"'.format(Livana.args["submit_dir"]))
        
        self.get_runfile()
        self.get_cuts_json()
        self.write_cutflow()
        #compare the flow we just wrote with the current one
        current_flow = collections.OrderedDict()
        test_flow    = collections.OrderedDict() 
        with open(self.__location__+"/default/current_flow.json",'r') as ofile:
            current_flow = json.load(ofile, object_pairs_hook=collections.OrderedDict)#Get the cuts from the json in the correct order
        with open(self.__location__+"/default/checkout.json",'r') as ofile:
            test_flow = json.load(ofile, object_pairs_hook=collections.OrderedDict)#Get the cuts from the json in the correct order
        
        self.assertDictEqual(current_flow, test_flow, msg="cutflows don't match!!")
        #replace the current cutflow file with the new one. Need a metod to allow small changes here
        os.remove(self.__location__+"/default/current_flow.json")
        os.rename(self.__location__+"/default/checkout.json", self.__location__+"/default/current_flow.json")
        
        

parser = argparse.ArgumentParser()
parser.add_argument('-s','--submit-dir', required=False, metavar='submit_dir', type=str, help='Submit directory location', default='submitDir')    

Livana.args = vars(parser.parse_args())

# test the various method parts locally here
if __name__ == '__main__':
    unittest.main(argv=sys.argv[:1])
