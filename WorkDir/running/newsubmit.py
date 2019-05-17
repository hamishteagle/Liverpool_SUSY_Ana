#!/usr/bin/env python

import argparse, ROOT, os
from datetime import datetime

class submit:

    def __init__(self):

        self.input = ''

    def main(self):
      # Parse arguments

        parser = argparse.ArgumentParser(description='Analysis submission script')
        parser.add_argument( '-i', '--input_file', dest='input_file', action = 'store', help = 'Input file/directory for EventLoop', default='/hepstore/hteagle/Wh/recoSamples/ttbar_checkfile/mc16_13TeV/')
        parser.add_argument( '-s', '--submission-dir', dest = 'submission_dir', action = 'store', help = 'Submission directory for EventLoop',default='/user/hteagle/AnalysisDirectory/Rel21/Base.21.2.72/run/submitdir_ttbarCheck' )
        parser.add_argument('-l','--local', dest = 'local', type = int, default = True)
        parser.add_argument('--type',dest = 'PhysicsName', type = str, default = 'TYPE')
        parser.add_argument('--syst', dest = 'syst', type = bool, default = False)
        parser.add_argument('--photons', dest = 'photons', type = bool, default = False)
        parser.add_argument('--events', dest = 'events', type = int, default = -1)
        parser.add_argument('--username', dest = 'username', action = 'store' , default = "hteagle")
        parser.add_argument('--doTruthJets', dest = 'doTruthJets', type = int, default= 0)
        args = parser.parse_args()

        # Make input file name accessible

        self.input = args.input_file
        slashes = len(self.input.split('/'))

        doSysts   = int(args.syst)
        doPhotons = int(args.photons)
        print ('local : '+str(args.local))
        local     = int(args.local)
        PhysicsName = str(args.PhysicsName)
        doTruthJets = int(args.doTruthJets)
        #Get the release directly from asetup (you will need to change the path to the build dir)
        release_string = os.popen('(cd /user/hteagle/AnalysisDirectory/Rel21/Base.21.2.72/build/ &&  source $AtlasSetup/scripts/asetup.sh $@ --printLast)').read()
        pos=release_string.find('Base/')
        release = release_string[pos+5:pos+5+8]

        doMultiSubmit= False
        multi_submit = '\"'
        if ('.txt' in self.input):
            doMultiSubmit =True
            for line in open(args.input_file):
                multi_submit += line.replace('\n',',')
        multi_submit = multi_submit.rstrip(',')
        multi_submit += '\"'
        
        outdir = args.submission_dir


        command = 'testRun '
        if doMultiSubmit :
            command += multi_submit
        else:
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
        command += ' '
        command += str(args.username)
        command += ' '
        command += str(release)
        command += ' '
        command += str(PhysicsName)
        command += ' '
        command += str(doTruthJets)
        print str(command)
        os.system(command)

if __name__=='__main__':
  submit().main()
