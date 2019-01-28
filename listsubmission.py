#!/usr/bin/env python

import argparse, io, os

class listsubmission:

    def __init__(self):

        self.input = ''

    def main(self):

        parser = argparse.ArgumentParser(description='Analysis grid submission script')
        parser.add_argument( '-i', '--input_file', dest='input_file', action = 'store', help = 'Input file for samples list')
        args = parser.parse_args()

        sample_list = open(args.input_file)
        for line in sample_list:
            line = line.strip('\n')
            command = 'python submit.py -i ' + line + ' -s /scratch/hteagle/GridSubmissions' + line.split('.')[1] + ' -g True'
            os.system(command)

if __name__=='__main__':
    listsubmission().main()
