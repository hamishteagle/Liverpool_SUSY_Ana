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
        args = parser.parse_args()
        
        doMultiSubmit= args.doMultiSubmit
        
        if (not doMultiSubmit):
            sample_list = open(args.input_file)
            for line in sample_list:
                line = line.strip('\n')
                command = 'python newsubmit.py -i ' + line + ' -s ' + line.split('.')[1] + ' -l 0' +' --type '+str(args.PhysicsName)
                print str(command)
                os.system(command)
        else:
            command = 'python newsubmit.py -i ' + args.input_file + ' -s ' + args.input_file.split('.')[0] + ' -l 0' +' --type '+str(args.PhysicsName)
            print str(command)
            os.system(command)
            

if __name__=='__main__':
    listsubmission().main()
