import ROOT
ROOT.PyConfig.IgnoreCommandLineOptions = True
ROOT.gROOT.SetBatch(True)
ROOT.gStyle.SetOptStat(0)
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
        weighted_flow_dict = collections.OrderedDict()
        SumOfWgts = self.f.Get("h_SumOfWeights").Integral()
        with open(self.weights_json,'r') as ofile:
            weights_dict = json.load(ofile, object_pairs_hook=collections.OrderedDict)#Get the cuts from the json in the correct order
        weighting="*".join(weights_dict.keys())+"*"
        weighting+="*".join(["36.1/139","xsec","filteff","kfactor","(1/"+str(SumOfWgts)+")"])
        print(weighting)

        with open(self.cuts_json,'r') as ofile:
            cuts_dict = json.load(ofile, object_pairs_hook=collections.OrderedDict)#Get the cuts from the json in the correct order
        cutnow = "1"
        for var, val in cuts_dict.items():
            cutnow += "*("+str(var)+str(val)+")" #Build the cuts iteratively
            flow_dict[var] = self.t.GetEntries(str(cutnow))
            weighted_hist = ROOT.TH1F("weighted_hist","weighted_hist",1,0.5,1.5)
            self.t.Draw("1>>weighted_hist",cutnow+"*"+weighting)
            weighted_flow_dict[var]=weighted_hist.Integral()
            del weighted_hist
            if (flow_dict[var]==0):
                raise IOError('cut of "{0:s} {1:s}" is too tight (0 events) change this cut'.format(var, val))
            else:
                print("cut: "+str(var)+" at: "+str(cuts_dict[var])+" raw: "+str(flow_dict[var])+" weighted: "+str(weighted_flow_dict[var]))

        with open(self.__location__+"/default/checkout_flow.json","w") as self.check_json:
            json.dump(flow_dict,self.check_json)
        if not os.path.exists(self.__location__+"/default/current_flow.json"):
            os.system("cp "+self.__location__+"/default/checkout_flow.json "+self.__location__+"/default/current_flow.json")


    def write_weights(self):
        with open(self.__location__+"/default/checkout_weights.json","w") as self.checkout_weights_json:
            json.dump(self.weights_output_dict,self.checkout_weights_json)
        if not os.path.exists(self.__location__+"/default/current_weights.json"):
            os.system("cp "+self.__location__+"/default/checkout_weights.json "+self.__location__+"/default/current_weights.json")

    def get_runfile(self):
        #pick up the root files in the given submission dir
        default_runfile_path = glob.glob(os.path.join(Livana.args["submit_dir"],'*.root'))
        if len(default_runfile_path) >1:
            raise IOError('more than 1 root file in given dir: "{0:s}"'.format(Livana.args["submit_dir"]))
        if not os.path.isfile(default_runfile_path[0]):
            raise IOError('root file does not exist in given dir: "{0:s}"'.format(Livana.args["submit_dir"]))
        self.f = ROOT.TFile.Open(default_runfile_path[0])
        self.t = self.f.Get('CollectionTree_PFlow_')

    def get_cuts_json(self):
        default_cuts_json_path = os.path.join(Livana.__location__,'default','cuts.json')
        if not os.path.isfile(default_cuts_json_path):
            raise IOError('json file does not exist in this running dir: "{0:s}"'.format(default_cuts_json_path))
        self.cuts_json = default_cuts_json_path

    def get_weights_json(self):
        default_weights_json_path = os.path.join(Livana.__location__,'default','weights.json')
        if not os.path.isfile(default_weights_json_path):
            raise IOError('json file does not exist in this running dir: "{0:s}"'.format(default_weights_json_path))
        self.weights_json = default_weights_json_path

    def test_weights(self):
        self.weights_output_dict = collections.OrderedDict()
        self.get_runfile()
        self.get_weights_json()
        with open(self.weights_json,'r') as ofile:
            weights_dict = json.load(ofile, object_pairs_hook=collections.OrderedDict)#Get the cuts from the json in the correct order
        with open(self.__location__+"/default/current_weights.json",'r') as ofile:
            current_weights = json.load(ofile, object_pairs_hook=collections.OrderedDict)#Get the weights from the current weights dict
        for weight in weights_dict:
            self.weights_output_dict[weight]=collections.OrderedDict()
            nbins = int(weights_dict[weight].split(",")[0])
            xmin = float(weights_dict[weight].split(",")[1])
            xmax = float(weights_dict[weight].split(",")[2])
            h = ROOT.TH1F("weight",str(weight),nbins,xmin,xmax)
            h_current = ROOT.TH1F("weight_current",str(weight),nbins,xmin,xmax)
            for bin_entry in current_weights[weight]:
                bin  = h_current.SetBinContent(h_current.GetBin(int(bin_entry)),float(current_weights[weight][bin_entry]))
            self.t.Draw(weight+">>weight")


            c = ROOT.TCanvas("Canvas1","Canvas1",0,0,900,900)
            Legend = ROOT.TLegend(0.60,0.76,0.80,0.94)

            saveString =  os.path.join(Livana.__location__,'default',weight+'.pdf')
            h_current.SetLineColor(ROOT.kGreen)
            h_current.SetLineWidth(5)
            h.SetLineColor(ROOT.kRed)
            h_current.Draw("hist")
            h.Draw("hist,same")
            Legend.AddEntry(h_current,"Current","l")
            Legend.AddEntry(h,"Commit","l")
            Legend.Draw()
            c.SaveAs(saveString)
            #Write the bins to the output dictionary
            for bin in range(nbins+1):
                self.weights_output_dict[weight][str(bin)] = h.GetBinContent(bin)
            del h
            del h_current
            del c
        self.write_weights()
        if not Livana.args["force"]:
            self.assertDictEqual(self.weights_output_dict,current_weights, msg="weights don't match!!")
        os.remove(self.__location__+"/default/current_weights.json")
        os.rename(self.__location__+"/default/checkout_weights.json", self.__location__+"/default/current_weights.json")


    def test_cutflow(self):
        #pick up the root files in the given submission dir
        default_runfile_path = glob.glob(os.path.join(Livana.args["submit_dir"],'*.root'))
        if len(default_runfile_path) >1:
            raise IOError('more than 1 root file in given dir: "{0:s}"'.format(Livana.args["submit_dir"]))
        if not os.path.isfile(default_runfile_path[0]):
            raise IOError('root file does not exist in given dir: "{0:s}"'.format(Livana.args["submit_dir"]))

        self.get_runfile()
        self.get_cuts_json()
        self.get_weights_json()
        self.write_cutflow()
        #compare the flow we just wrote with the current one
        current_flow = collections.OrderedDict()
        test_flow    = collections.OrderedDict()
        with open(self.__location__+"/default/current_flow.json",'r') as ofile:
            current_flow = json.load(ofile, object_pairs_hook=collections.OrderedDict)#Get the cuts from the json in the correct order
        with open(self.__location__+"/default/checkout_flow.json",'r') as ofile:
            test_flow = json.load(ofile, object_pairs_hook=collections.OrderedDict)#Get the cuts from the json in the correct order

        if not Livana.args["force"]:
            self.assertDictEqual(current_flow, test_flow, msg="cutflows don't match!!:"+str(current_flow))
        #replace the current cutflow file with the new one. Need a metod to allow small changes here
        os.remove(self.__location__+"/default/current_flow.json")
        os.rename(self.__location__+"/default/checkout_flow.json", self.__location__+"/default/current_flow.json")



parser = argparse.ArgumentParser()
parser.add_argument('-s','--submit-dir', required=False, metavar='submit_dir', type=str, help='Submit directory location', default='submitDir')
parser.add_argument('-f','--force', required=False, metavar='force', help='Force the submission (do not run the checks->Only run this if you want to update the nominal)', default=False)

Livana.args = vars(parser.parse_args())

# test the various method parts locally here
if __name__ == '__main__':
    unittest.main(argv=sys.argv[:1])
