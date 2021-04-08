#!/usr/bin/env python

import argparse, io, os

class listsubmission:

    def __init__(self):

        self.input = ''

    def main(self):

        parser = argparse.ArgumentParser(description='Analysis grid submission script')
        parser.add_argument( '-i', '--input_file', dest='input_file', action = 'store', help = 'Input file for samples list')
        parser.add_argument( '-t', '--type', dest = 'PhysicsName', action = 'store', help = 'Physics sample type', default='TYPE')
        parser.add_argument( '-m', '--multi_submit', dest = 'doMultiSubmit',type = bool, default = False)
        parser.add_argument( '--syst', '--systematics', dest = 'doSystematics',type = int, default = 0)
        parser.add_argument('-d','--debug', dest = 'debug', action='store_true', default= False)
        parser.add_argument( '--nFilesPerJob', dest = 'nFilesPerJob',type = str, default = "5")
        parser.add_argument('--doCombiLeptons', dest = 'doCombiLeptons', action='store_true', default= True)
        parser.add_argument('--doTruthJets', dest = 'doTruthJets', action='store_true', default= False)
        parser.add_argument('--savePDFVars', dest = 'savePDFVars',type = int, default = 0)
        args = parser.parse_args()

        doMultiSubmit= args.doMultiSubmit
        doSystematics= args.doSystematics
        doTruthJets = args.doTruthJets
        savePDFVars = args.savePDFVars
        if args.doSystematics:
            print("True")
        if (not doMultiSubmit):
            sample_list = open(args.input_file)
            for line in sample_list:
                if "_r9364" in line:
                    MCrun = "MC16a"
                elif "_r10201" in line:
                    MCrun = "MC16d"
                elif "_r10724" in line:
                    MCrun = "MC16e"
                else:
                    exit("Something wrong with this submission name: "+line)
                line = line.strip('\n')
                if "ttbar" in line: args.nFilesPerJob="1"
                command = 'python newsubmit.py -i ' + line + ' -s ' + line.split('.')[1]+MCrun + ' -l 0' +' --type '+str(args.PhysicsName) +' --syst '+str(int(doSystematics))+' --nFilesPerJob '+args.nFilesPerJob + ' --doTruthJets '+ str(int(doTruthJets)) + ' --savePDFVars ' +str(int(savePDFVars))
                print str(command)
                os.system(command)
        else:
            command = 'python newsubmit.py -i ' + args.input_file + ' -s ' + args.input_file.split('.')[0] + ' -l 0' +' --type '+str(args.PhysicsName)+' --syst '+str(doSystematics) + ' --doTruthJets '+ str(int(doTruthJets)) + ' --savePDFVars ' +str(int(savePDFVars))
            print str(command)
            os.system(command)


if __name__=='__main__':
    listsubmission().main()
