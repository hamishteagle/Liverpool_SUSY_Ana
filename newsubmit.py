#!/usr/bin/env python

import argparse, ROOT, os
from datetime import datetime

class submit:

    def __init__(self):

        self.input = ''

    def main(self):
      # Parse arguments

        parser = argparse.ArgumentParser(description='Analysis submission script')
        parser.add_argument( '-i', '--input_file', dest='input_file', action = 'store', help = 'Input file/directory for EventLoop', default='/hepstore/hteagle/Wh/recoSamples/mc16_13TeV.410470.PhPy8EG_A14_ttbar_hdamp258p75_nonallhad.deriv.DAOD_SUSY5.e6337_s3126_r10724_p3652/')
        parser.add_argument( '-s', '--submission-dir', dest = 'submission_dir', action = 'store', help = 'Submission directory for EventLoop',default='submitdir' )
        parser.add_argument('--syst', dest = 'syst', type = bool, default = False)
        parser.add_argument('--photons', dest = 'photons', type = bool, default = False)
        parser.add_argument('--local', dest = 'local', type = bool, default = True)
        parser.add_argument('--events', dest = 'events', type = int, default = -1)
        args = parser.parse_args()

        # Make input file name accessible

        self.input = args.input_file
        slashes = len(self.input.split('/'))

        doSysts   = int(args.syst)
        doPhotons = int(args.photons)
        local     = int(args.local)

        outdir = args.submission_dir + '/' + self.input.split('/')[slashes - 2] + '/'

        command = 'testRun '
        command += self.input
        command += ' '
        command += outdir
        command += ' '
        command += str(doSysts)
        command += ' ' 
        command += str(doPhotons)
        command += ' '
        command += str(local)
        command += ' '
        command += str(args.events) 

        os.system(command)

if __name__=='__main__':
  submit().main()
