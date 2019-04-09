#!/usr/bin/env python

import argparse, ROOT
from datetime import datetime

class submit:

    def __init__(self):

        self.input = ''

    def main(self):
      # Parse arguments

        parser = argparse.ArgumentParser(description='Analysis submission script')
        parser.add_argument( '-i', '--input_file', dest='input_file', action = 'store', help = 'Input file/directory for EventLoop', default='/hepstore/hteagle/Wh/recoSamples/Signals/mc16_13TeV.396716.MadGraphPythia8EvtGen_A14N23LO_C1N2_Wh_hbb_300p0_150p0_lep.deriv.DAOD_SUSY5.e6972_a875_r9364_p3736/')
        parser.add_argument( '-s', '--submission-dir', dest = 'submission_dir', action = 'store', help = 'Submission directory for EventLoop',default='submitdir' )
        parser.add_argument( '-g', '--grid', dest = 'grid_running', type = bool, default = False)
        parser.add_argument( '-l', '--list', dest = 'submit_together', type = bool, default = False)
        parser.add_argument( '-t', '--type', dest = 'PhysicsName', action = 'store', help = 'Physics sample type', default='TYPE')
        args = parser.parse_args()

        # Make input file name accessible

        self.input = args.input_file
        self.PhysicsName = args.PhysicsName
        # Setup ROOT

        ROOT.xAOD.Init().ignore()

        # Setup SampleHandler

        if args.grid_running is False:

            sh = ROOT.SH.SampleHandler()
            sh.setMetaString('nc_tree','CollectionTree')
            ROOT.SH.ScanDir().scan(sh, args.input_file)
            sh.printContent()

            # Create EventLoop job

            job = ROOT.EL.Job()
            job.sampleHandler( sh )
            #job.options().setDouble( ROOT.EL.Job.optMaxEvents, 500 )
            print('Running on grid? ' + str(args.grid_running))

            # Configure algorithm
            from AnaAlgorithm.DualUseConfig import createAlgorithm
            alg = createAlgorithm ('MyxAODAnalysis', 'AnalysisAlg')
            
            # Configuration

            alg.doSyst = 0
            alg.doPhotons = 0
            alg.RunningLocally = 1
            alg.inputFile = args.input_file

            # Add algorithm to job

            output = ROOT.EL.OutputStream("output")
            job.outputAdd( output )
            job.algsAdd( alg )

            # Run job

            job.options().setDouble( ROOT.EL.Job.optRemoveSubmitDir, 1 )
            driver = ROOT.EL.DirectDriver()
            driver.submit( job, args.submission_dir )

        elif args.grid_running is True:

            sh = ROOT.SH.SampleHandler()
            sh.setMetaString('nc_tree','CollectionTree')

            if args.submit_together == False:
                ROOT.SH.scanRucio(sh, args.input_file)
                sh.printContent()
            else:
                samplegrid = ROOT.SH.SampleGrid("AllTogether")
                samplegrid.meta().setString(ROOT.SH.MetaFields.gridName, args.input_file)
                samplegrid.meta().setString(ROOT.SH.MetaFields.gridFilter, ROOT.SH.MetaFields.gridFilter_default)
                sh.add(samplegrid)

            # Create EventLoop job

            job = ROOT.EL.Job()
            job.sampleHandler( sh )
            job.options().setDouble( ROOT.EL.Job.optMaxEvents, 500 )
            print('Running on grid? ' + str(args.grid_running))
        
            # Configure algorithm

            from AnaAlgorithm.DualUseConfig import createAlgorithm
            alg = createAlgorithm ('MyxAODAnalysis', 'AnalysisAlg')

            # Configuration

            alg.doSyst = 0
            alg.doPhotons = 0
            alg.RunningLocally = 0
            alg.inputFile = args.input_file
            
            # Add algorithm to job

            output = ROOT.EL.OutputStream("output")
            job.outputAdd( output )
            job.algsAdd( alg )

            # Run job

            job.options().setDouble( ROOT.EL.Job.optRemoveSubmitDir, 1 )
            driver = ROOT.EL.PrunDriver()
            driver.options().setString("nc_outputSampleName", str(self.get_name())+'_'+str(self.PhysicsName)+'_v1.%in:name[2]%.%in:name[3]%')
            #driver.options().setString( ROOT.EL.Job.optGridNFilesPerJob, "5")
            if args.submit_together == True:
                job.options().setString( ROOT.EL.Job.optSubmitFlags, "--addNthFieldOfInDSToLFN=2,3,6 --useContElementBoundary")
            driver.submitOnly( job, args.submission_dir )

            print("Job submitted")
    def get_name(self):

        Months = ["Jan","Feb","Mar","Apr","May","June","July","Aug","Sept","Oct","Nov","Dec"]
        d = datetime.now()
        name_string = 'user.hteagle.'
        name_string += str(d.day)
        name_string += str(Months[int(d.month)])
        name_string += str('_SUSY5.')
        name_string += str(self.campaign())

        return(name_string)

    def campaign(self):

        if 'TRUTH1' in self.input:
            return 'TRUTH1.'
        elif 'TRUTH3' in self.input:
            return 'TRUTH3.'
        elif 'data15' in self.input:
            return 'DATA15.'
        elif 'data16' in self.input:
            return 'DATA16.'
        elif 'data17' in self.input:
            return 'DATA17.'
        elif 'data18' in self.input:
            return 'DATA18.'
        elif 'r9364' in self.input:
            return 'MC16a.'
        elif 'r10201' in self.input:
            return 'MC16d.'
        elif 'r10724' in self.input:
            return 'MC16e.'

if __name__=='__main__':
  submit().main()
