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
        args = parser.parse_args()

        doMultiSubmit= args.doMultiSubmit
        doSystematics= args.doSystematics
        if args.doSystematics:
            print("True")
        if (not doMultiSubmit):
            sample_list = open(args.input_file)
            for line in sample_list:
                line = line.strip('\n')
                if "ttbar" in line: args.nFilesPerJob="1"
                command = 'python newsubmit.py -i ' + line + ' -s ' + line.split('.')[1] + ' -l 0' +' --type '+str(args.PhysicsName) +' --syst '+str(int(doSystematics))+' --nFilesPerJob '+args.nFilesPerJob
                print str(command)
                os.system(command)
        else:
            command = 'python newsubmit.py -i ' + args.input_file + ' -s ' + args.input_file.split('.')[0] + ' -l 0' +' --type '+str(args.PhysicsName)+' --syst '+str(doSystematics)
            print str(command)
            os.system(command)


if __name__=='__main__':
    listsubmission().main()
