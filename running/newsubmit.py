#!/usr/bin/env python

import argparse, ROOT, os
from datetime import datetime
current_path = os.path.dirname(os.path.abspath(__file__))
class submit:

    def __init__(self):

        self.input = ''

    def main(self):
      # Parse arguments

        parser = argparse.ArgumentParser(description='Analysis submission script')
        parser.add_argument( '-i', '--input_file', dest='input_file', action = 'store', help = 'Input file/directory for EventLoop', default='/hepstore/hteagle/reco_test_files/mc16_13TeV.410470.PhPy8EG_A14_ttbar_hdamp258p75_nonallhad.deriv.DAOD_SUSY5.e6337_s3126_r9364_p3990/')
        parser.add_argument( '-s', '--submission-dir', dest = 'submission_dir', action = 'store', help = 'Submission directory for EventLoop',default=current_path+'/submitdir' )
        parser.add_argument('-l','--local', dest = 'local', type = int, default = 1)
        parser.add_argument('--type',dest = 'PhysicsName', type = str, default = 'TYPE')
        parser.add_argument('--syst', dest = 'syst', type = int, default = 0)
        parser.add_argument('--photons', dest = 'photons', type = int, default = 0)
        parser.add_argument('--events', dest = 'events', type = int, default = -1)
        parser.add_argument('--username', dest = 'username', action = 'store' , default = "hteagle")
        parser.add_argument('--doTruthJets', dest = 'doTruthJets', type = int, default= 0)
        parser.add_argument('--nFilesPerJob', dest = 'nFilesPerJob', type = str, default= "5")
        parser.add_argument('-d','--debug', dest = 'debug', action='store_true', default= False)
        parser.add_argument('--doCombiLeptons', dest = 'doCombiLeptons', action='store_true', default= True)
        parser.add_argument("--savePDFVars", dest='savePDFVars', type=int , default=0)
        args = parser.parse_args()


        # Make input file name accessible
        self.input = args.input_file
        slashes = len(self.input.split('/'))

        debug = int(args.debug)
        doSysts   = int(args.syst)
        doPhotons = int(args.photons)
        doCombiLeptons = int(args.doCombiLeptons)
        local     = int(args.local)
        PhysicsName = str(args.PhysicsName)
        doTruthJets = int(args.doTruthJets)
        savePDFVars = int(args.savePDFVars)
        #Get the release directly from asetup (you will need to change the path to the build dir)
        release_string = os.popen('(cd '+current_path.replace('running','build')+' &&  source $AtlasSetup/scripts/asetup.sh $@ --printLast)').read()
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
        ensure_dir(outdir)


        # print("doSyst:",doSysts)
        # print("doPhotons:",doPhotons)
        # print("local:",local)
        # print("events:",args.events)
        # print("username:",args.username)
        # print("release",release)
        # print("doCombiLeptons",doCombiLeptons)
        # print("debug",debug)
        command = 'testRun '
        command_attributes = 'testRun_attrs, '
        if doMultiSubmit :
            command += multi_submit
            command_attributes+="input file,             "
        else:
            command += self.input
            command_attributes+="input,                  "
        command += ' '
        command += outdir
        command_attributes+="outdir, "
        command += ' '
        command += str(doSysts)
        command_attributes+="doSysts, "
        command += ' '
        command += str(doPhotons)
        command_attributes+="doPhotons, "
        command += ' '
        command += str(local)
        command_attributes+="RunLocally, "
        command += ' '
        command += str(args.events)
        command_attributes+="nEvents, "
        command += ' '
        command += str(args.username)
        command_attributes+="username, "
        command += ' '
        command += str(release)
        command_attributes+="release, "
        command += ' '
        command += str(PhysicsName)
        command_attributes+="PhysicsName, "
        command += ' '
        command += str(doTruthJets)
        command_attributes+="doTruthJets, "
        command += ' '
        command += str(args.nFilesPerJob)
        command_attributes+="nFilesPerJob, "
        command += ' '
        command += str(debug)
        command_attributes+="debug, "
        command += ' '
        command += str(doCombiLeptons)
        command_attributes+="doCombiLeptons, "
        command += ' '
        command += str(savePDFVars)
        command_attributes+="savePDFVars, "
        print(str(command_attributes))
        print str(command)
        os.system(command)


def ensure_dir(d):
    if not os.path.isdir(d):
        os.makedirs(d)

if __name__=='__main__':
  submit().main()
