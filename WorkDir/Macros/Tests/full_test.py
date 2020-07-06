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

import logging

class Livana(unittest.TestCase):


    # maximum allowed difference between cutflows
    maxDiff = None
    t = None
    def green(self,string):
        return "\033[92m"+string+"\033[0m"
    def red(self, string):
        return "\033[91m"+string+"\033[0m"
    def blue(self, string):
        return "\033[36m"+string+"\033[0m"


    # preserve location of this script
    __location__ = os.path.realpath(os.path.join(os.getcwd(), os.path.dirname(__file__)))

    def get_messaging(self):
        self.msg=logging.getLogger("Cutflow Checker")
        if Livana.args["debug"]: debug_level="DEBUG"
        else:                    debug_level="INFO"
        logging.basicConfig(level=debug_level,
                            format='%(name)-12s :: %(levelname)-8s ::       %(message)s')

        self.msg.info("Retrieved Messaging")

    ##Helper to pring the cutflows side-by-side if they don't match
    def cutflow_mismatch(self,current_flow, test_flow, e):
        print("------------------------------INFO----------------------------------------")
        ##Check if the cuts actually match
        diff_cuts = list(set([cut for cut in test_flow]) - set([cut for cut in current_flow]))
        ##The cuts applied don't match

        if len(diff_cuts)>0:
            print("The cuts applied don't match")
            if diff_cuts[0] in current_flow: which="missing"
            else: which="new"
            print(self.red("Cut on "+str(diff_cuts)+" is "+which+" with respect to current"))
            print("------------------------------\INFO----------------------------------------")
        print(" {0:<20} | {1:^10} {2:^10}  | {3:^15} {4:>15}  ".format("Cut","Current","New","Current","New"))

        #Loop on the longest list of cuts
        if len(current_flow)>len(test_flow):cuts = current_flow
        else: cuts = test_flow
        for cut in cuts:
            ##If a cut is different wrt to the other cuts, just keep the weighted and raw cuts empty
            if cut in current_flow: tp1=current_flow[cut]
            else: tp1=["-","-"]
            if cut in test_flow: tp2=test_flow[cut]
            else: tp2=["-","-"]

            #If the values match
            if tp1==tp2:colour=self.green
            else: colour=self.red

            print(colour(" {0:<20} | {1:^10} {2:^10}  | {3:^15} {4:>15}  ".format(cut,tp1[0],tp2[0],tp1[1],tp2[1])))
        print("------------------------------\INFO----------------------------------------")
        raise Exception(e)


    #@staticmethod
    def write_cutflow(self, branch="CollectionTree_PFlow_"):
        cuts_dict = {}
        #Things are nicer if they're ordered in the json file

        try:
            self.flow_dict[branch]=collections.OrderedDict()
        except:
            self.flow_dict = collections.OrderedDict()
            self.flow_dict[branch]=collections.OrderedDict()
        SumOfWgts = self.f.Get("h_SumOfWeights").Integral()
        with open(self.weights_json,'r') as ofile:
            weights_dict = json.load(ofile, object_pairs_hook=collections.OrderedDict)#Get the cuts from the json in the correct order
        weighting="*".join(weights_dict.keys())
        weighting+="*"+"*".join([self.get_year_weight(),"xsec","filteff","kfactor","(1/"+str(SumOfWgts)+")"])

        with open(self.cuts_json,'r') as ofile:
            cuts_dict = json.load(ofile, object_pairs_hook=collections.OrderedDict)#Get the cuts from the json in the correct order
        cutnow = "1"
        for var, val in cuts_dict.items():
            cutnow += "*("+str(var)+str(val)+")" #Build the cuts iteratively
            weighted_hist = ROOT.TH1F("weighted_hist","weighted_hist",1,0.5,1.5)
            self.t.Draw("1>>weighted_hist",cutnow+"*"+weighting)
            ##Write the cutflow as a tuple of unweighted and weighted events
            self.flow_dict[branch][var] = self.t.GetEntries(str(cutnow)),weighted_hist.Integral()
            del weighted_hist
            if (self.flow_dict[branch][var][0]==0):
                raise IOError('cut of "{0:s} {1:s}" is too tight (0 events) change this cut'.format(var, val))
            else:
                if Livana.args["debug"]:
                    print(self.blue(" {0:<20} | {1:^60}  | {2:^10}  | {3:>15}  ".format(str(branch), "cut: "+str(var)+" at: "+str(cuts_dict[var])," raw: "+str(self.flow_dict[branch][var][0])," weighted: "+str(self.flow_dict[branch][var][1]))))
        ##Write out when we've reached the last branch in the list
        if branch ==self.branch_list[-1]:
            with open(self.__location__+"/default/checkout_flow.json","w") as self.check_json:
                self.msg.info("Dumping json to checkout_flow.json")
                json.dump(self.flow_dict,self.check_json, indent=3)
                ##If we don't have a current cutflow to match, just copy the one we just made (will match by definition)
            if not os.path.exists(self.__location__+"/default/current_flow.json"):
                self.msg.warn("No current_flow.json found->Overwriting with checkout_flow")
                os.system("cp "+self.__location__+"/default/checkout_flow.json "+self.__location__+"/default/current_flow.json")


    def write_weights(self,branch="CollectionTree_PFlow_"):

        if branch ==self.branch_list[0]:
            self.msg.info("Dumping json to checkout_weights")
            with open(self.__location__+"/default/checkout_weights.json","w") as self.checkout_weights_json:
                json.dump(self.weights_output_dict,self.checkout_weights_json, indent=3)
            if not os.path.exists(self.__location__+"/default/current_weights.json"):
                self.msg.warn("No current_weights.json found->Overwriting with checkout_weights")
                os.system("cp "+self.__location__+"/default/checkout_weights.json "+self.__location__+"/default/current_weights.json")

    def get_runfile(self, branch_number=0):
        #pick up the root files in the given submission dir
        default_runfile_path = glob.glob(os.path.join(Livana.args["submit_dir"],'*.root'))
        if len(default_runfile_path) >1:
            raise IOError('more than 1 root file in given dir: "{0:s}"'.format(Livana.args["submit_dir"]))
        if not os.path.isfile(default_runfile_path[0]):
            raise IOError('root file does not exist in given dir: "{0:s}"'.format(Livana.args["submit_dir"]))
        self.f = ROOT.TFile.Open(default_runfile_path[0])
        ##Get the list of branches
        self.branch_list = [key.GetName() for key in self.f.GetListOfKeys() if isinstance(key.ReadObj(),ROOT.TTree) and key.GetName()!= "CollectionTree_PFlow_"]
        self.branch_list = list(set(self.branch_list))##Remove the doubled up branch names (ROOT is stupid)
        self.branch_list.insert(0,"CollectionTree_PFlow_")
        self.t = self.f.Get(self.branch_list[branch_number])
        self.t.GetEntry(0)

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
    def get_year_weight(self):
        ##Get the year to weight a/d/e properly
        year = self.t.GetLeaf("year").GetValue()
        if year == 2015.: year_weight = "36.1/139"
        elif year == 2016.: year_weight = "36.1/139"
        elif year == 2017.: year_weight = "44.307/139"
        elif year == 2018.: year_weight = "58.4501/139"
        else:
            raise IOError("Got a weird year: %f couldn't get a year_weight"%(year))
        return year_weight

    def test_cutflow(self):
        self.get_messaging()
        self.get_runfile()
        self.get_cuts_json()
        self.get_weights_json()
        for i in range(len(self.branch_list)):
            self.msg.info("Checking cutflow for branch: "+self.branch_list[i])
            #pick up the root files in the given submission dir
            default_runfile_path = glob.glob(os.path.join(Livana.args["submit_dir"],'*.root'))
            if len(default_runfile_path) >1:
                raise IOError('more than 1 root file in given dir: "{0:s}"'.format(Livana.args["submit_dir"]))
            if not os.path.isfile(default_runfile_path[0]):
                raise IOError('root file does not exist in given dir: "{0:s}"'.format(Livana.args["submit_dir"]))
            self.get_runfile(branch_number=i)
            self.write_cutflow(branch = self.branch_list[i])
            #compare the flow we just wrote with the current one
        current_flow = collections.OrderedDict()
        test_flow    = collections.OrderedDict()
        ##Don't load the current flow if we're forcing a new one
        if not Livana.args["force"]:
            with open(self.__location__+"/default/current_flow.json",'r') as ofile:
                current_flow = json.load(ofile, object_pairs_hook=collections.OrderedDict)#Get the cuts from the json in the correct order
        with open(self.__location__+"/default/checkout_flow.json",'r') as ofile:
            test_flow = json.load(ofile, object_pairs_hook=collections.OrderedDict)#Get the cuts from the json in the correct order

        if not Livana.args["force"]:
            try:
                for branch in self.branch_list:
                    self.msg.debug("branch:"+branch)
                    self.msg.debug("current dict:"+str(current_flow[branch]))
                    self.msg.debug("test dict:"+str(test_flow[branch]))
                    self.assertDictEqual(current_flow[branch], test_flow[branch], msg="cutflows don't match!!:")
            except AssertionError as e:
                self.cutflow_mismatch(current_flow[branch], test_flow[branch], e)


        #replace the current cutflow file with the new one. Need a metod to allow small changes here
        if Livana.args["force"]:
            os.remove(self.__location__+"/default/current_flow.json")
            os.rename(self.__location__+"/default/checkout_flow.json", self.__location__+"/default/current_flow.json")

    def test_weights(self):
        self.get_messaging()
        self.weights_output_dict = collections.OrderedDict()
        self.get_weights_json()
        self.get_runfile()

        with open(self.weights_json,'r') as ofile:
            weights_dict = json.load(ofile, object_pairs_hook=collections.OrderedDict)#Get the cuts from the json in the correct order
        if not Livana.args["force"]:
            with open(self.__location__+"/default/current_weights.json",'r') as ofile:
                current_weights = json.load(ofile, object_pairs_hook=collections.OrderedDict)#Get the weights from the current weights dict
        for weight in weights_dict:
            self.weights_output_dict[weight]=collections.OrderedDict()
            nbins = int(weights_dict[weight].split(",")[0])
            xmin = float(weights_dict[weight].split(",")[1])
            xmax = float(weights_dict[weight].split(",")[2])
            c = ROOT.TCanvas("Canvas1","Canvas1",0,0,900,900)
            Legend = ROOT.TLegend(0.60,0.76,0.80,0.94)
            h = ROOT.TH1F("weight",str(weight),nbins,xmin,xmax)
            h_current = ROOT.TH1F("weight_current",str(weight),nbins,xmin,xmax)
            self.t.Draw(weight+">>weight")
            if not Livana.args["force"]:
                for bin_entry in current_weights[weight]:
                    self.msg.debug("bin:"+str(bin_entry))
                    self.msg.debug("entry:"+str(current_weights[weight][bin_entry]))
                    bin  = h_current.SetBinContent(h_current.GetBin(int(bin_entry)),float(current_weights[weight][bin_entry]))


            if not Livana.args["force"]:
                if not os.path.exists(os.path.join(Livana.__location__,"WeightPlots")):
                    os.mkdir(os.path.join(Livana.__location__,"WeightPlots"))
                saveString =  os.path.join(Livana.__location__,"WeightPlots",weight+'.pdf')
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
        self.write_weights()##Only write the weights on the nominal branch
        if not Livana.args["force"]:
            self.assertDictEqual(self.weights_output_dict,current_weights, msg="weights don't match!!")
        else:
            os.remove(self.__location__+"/default/current_weights.json")
            os.rename(self.__location__+"/default/checkout_weights.json", self.__location__+"/default/current_weights.json")






parser = argparse.ArgumentParser()
parser.add_argument('-s','--submit-dir', required=False, metavar='submit_dir', type=str, help='Submit directory location', default='submitDir')
parser.add_argument('-f','--force', action='store_true', required=False, dest='force', help='Force the submission (do not run the checks->Only run this if you want to update the nominal)', default=False)
parser.add_argument('-d','--debug', action='store_true', required=False, dest='debug', help='Verbose debugging', default=False)

Livana.args = vars(parser.parse_args())

# test the various method parts locally here
if __name__ == '__main__':
    unittest.main(argv=sys.argv[:1])
