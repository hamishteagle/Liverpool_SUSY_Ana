#!/usr/bin/env python
"""@package docstring
A script for checking an input AOD lists before SUSY derivation requests.
It ensures that
1. All input AOD containers exist and are valid
2. No output DAOD containers already exist for this ptag
3. Provides a list of samples with older ptags that will be obsoleted by this request.

Please attached the output JIRArequest.txt and JIRAobsoletion.txt to the SUSYDPD JIRA request.
For more info or assistance, contact Alvaro Solis and Jeff Dandoy
"""
version = 1.0

import os
import argparse
import rucio.client
rucio_client = rucio.client.didclient.DIDClient()

parser=argparse.ArgumentParser("Script to check if samples are already available.")

parser.add_argument("-c","--reductionConf",dest="reductionConf",help="Reduction conf to check : TRUTH3, SUSY4, etc.")
parser.add_argument("-l","--listSamples",dest="list",help="List of samples to request. Please note that if reductionConf is TRUTH, samples must be EVNT; if it is SUSY*, th must be recon.AOD.")
parser.add_argument("-p","--ptag",dest="ptag",help="ptag of this request.")
parser.add_argument("--allowOldTag",dest="allowOldTag", action='store_true', default=False, help="Allow request to include samples that already exist in a newer ptag than the one requested.")

args=parser.parse_args()

samples_with_current_DAOD, samples_with_previous_DAOD, samples_for_JIRA, samples_no_AOD = [], [], [], []

ptag_int = int(args.ptag.replace('p',''))
args.ptag = 'p'+str(ptag_int) #Must start with p

#Only prepared for TRUTH or SUSY
if not 'TRUTH' in args.reductionConf and not 'SUSY' in args.reductionConf:
  raise ValueError("Unrecognized reductionConf {0}".format(args.reductionConf))


#Can't find input list (should be a text file)
if not os.path.isfile(args.list):
  raise ValueError("The provided list doesn't exist. Please, provide a valid list of samples.")

#Loop over every line in the list
for inFile in open(args.list,'r'):

    #Reformat line and ignore ones commented out
    filename=inFile.rstrip('\n').rstrip(' ')
    if filename.startswith('#') or filename == "":
      continue

    #Make sure it starts with a scope
    if (filename.count(':') == 0):
      filename = filename.split('.')[0]+':'+filename

    tag_list = filename.split('.')[-1].split("_")
    #Make sure types of file and tags are correct for truth/reco/DAOD_RPVLL samples
    if( 'TRUTH' in args.reductionConf ):
      truth_error_message  = "For the bookeeping is dark and full of terrors, TRUTH derivations can only be requested for mc15_13TeV evgen.EVNT samples with a single e-tag.\n"
      truth_error_message += "You can take a look at https://twiki.cern.ch/twiki/bin/viewauth/AtlasProtected/SUSYxAODDerivationsr21#Request_MC_derivations.\n"
      truth_error_message += "{0}\n".format(filename)
      if len(tag_list) != 1 or not "e" in tag_list[0]:
        raise ValueError(truth_error_message)
      if not "evgen.EVNT" in filename or not "mc15_13TeV" in filename:
        raise ValueError(truth_error_message)

      #Prepare name of derivation container
      outFile="%s_*p%s"%(filename.replace("evgen.EVNT.","deriv.DAOD_"+args.reductionConf+".").replace("merged.EVNT.","deriv.DAOD_"+args.reductionConf+"."),args.ptag.replace("p",""))
    elif( 'SUSY' in args.reductionConf ):
      tag_list = filename.split('.')[-1].split("_")
      if len(tag_list) != 3 or not "e" in tag_list[0] or not ("a" in tag_list[1] or "s" in tag_list[1]) or not "r" in tag_list[2]:
        raise ValueError("For the bookeeping is dark and full of terrors, DAOD_SUSYX derivations can only be requested for recon.AOD samples with three tags (recon.AOD.eXXXX_a/sXXXX_rXXXX), but you requested {0}\n. You can take a look at https://twiki.cern.ch/twiki/bin/viewauth/AtlasProtected/SUSYxAODDerivationsr21#Request_MC_derivations \n".format(filename))
      if (not "mc16_13TeV" in filename) or not ("recon.AOD" in filename or "deriv.DAOD_RPVLL" in filename):
        raise ValueError("For the bookeeping is dark and full of terrors, DAOD_SUSYX derivations can only be requested for recon.AOD samples with three tags (recon.AOD.eXXXX_a/sXXXX_rXXXX), but you requested {0}\n. You can take a look at https://twiki.cern.ch/twiki/bin/viewauth/AtlasProtected/SUSYxAODDerivationsr21#Request_MC_derivations \n".format(filename))

      #Prepare name of derivation container
      outFile="%s_p%s"%(filename.replace("recon.AOD.","deriv.DAOD_"+args.reductionConf+"."),args.ptag.replace("p",""))

    ## Check Rucio to make sure AOD container does exist ##
    scope = filename.split(':')[0]
    name = filename.split(':')[1]
    name_filter = {'name' : name}
    input_containers = list(rucio_client.list_dids( scope, name_filter ))
    if len(input_containers) != 1:
      print "Error, did not receive 1 container for {0}, but received {1}".format(filename,input_containers)
      samples_no_AOD.append(filename)
      continue

    #Make sure AOD container status is AVAILABLE
    try:
      ret = rucio_client.get_metadata(scope, name)
    except Exception as e:
      #print "Issue with sample {0}".format(filename)
      samples_no_AOD.append(filename)
      continue

    #Ensure that each input container has an AVAILABLE status
    if( ret['availability'] != 'AVAILABLE'):
      #print "Sample not available {0}".format(filename)
      samples_no_AOD.append(filename)
      continue

    #Make sure AOD container is not empty
    list_files=list(rucio_client.list_files(scope,name))
    if( len(list_files) == 0 ):
      samples_no_AOD.append(filename)
      print "Error: Container {0} is available but it is empty.".format(filename)
      continue


    ## Check Rucio to make sure DAOD container does NOT already exist ##
    scope = outFile.split(':')[0]
    name  = outFile.split(':')[1].replace(args.ptag,'p*')
    name_filter = {'name' : name}
    output_containers = list(rucio_client.list_dids( scope, name_filter ))

    if( any(args.ptag in this_DAOD for this_DAOD in output_containers) ):
      #print "Error, sample already has a DAOD container with ptag {1}, the corresponding AOD will be excluded".format(args.ptag)
      samples_with_current_DAOD.append(outFile)
    else:
      samples_for_JIRA.append(filename)

      #If DAODs exist with other ptags, add them to the obsoletion list
      if len(output_containers) > 0:

        #Check that there are not newer ptags
        this_ptag_int = int(output_containers[-1].split('_')[-1].replace('p',''))
        if(ptag_int < this_ptag_int and not args.allowOldTag):
          print "Warning, you're requesting sample {0} with ptag {1}, but a newer ptag {2} already exists!  Rerun with the '--allowOldTag' option if you want these samples in this ptag, but know that they will be quickly obsoleted".format(filename, ptag_int, this_ptag_int)
          samples_with_current_DAOD.append(outFile)
          samples_for_JIRA.pop()

        #Otherwise, add the latest ptag to the obsoletion list
        else:
          samples_with_previous_DAOD.append(output_containers[-1])


#Write out the list of valid AODs to txt file
fout_JIRArequest=open("JIRArequest.txt",'w')
for reco in samples_for_JIRA:
  fout_JIRArequest.write(reco+"\n")
fout_JIRArequest.close()

#Write out the list of DAODs that will be obsoleted with this request
fout_JIRAobsoletion=open("JIRAobsoletion.txt",'w')
fout_JIRAobsoletion.write("Script version {0}.  Samples that will be obsoleted:\n".format(version))
for reco in samples_with_previous_DAOD:
  fout_JIRAobsoletion.write(reco+"\n")
fout_JIRAobsoletion.close()

#Print to screen the list of skipped AODs for reference:
if len(samples_with_current_DAOD) > 0:
  print "List of samples that already have a DAOD for this ptag (or older):"
  for sample in samples_with_current_DAOD:
    print " ", sample

if len(samples_no_AOD) > 0:
  print "List of samples that do not have an AOD on rucio:"
  for sample in samples_no_AOD:
    print " ", sample

if len(samples_no_AOD) == 0 and len(samples_with_current_DAOD) == 0:
  print "All {0} samples are fine for processing.  Please attach JIRArequest.txt and JIRAobsoletion.txt (even if empty) to the JIRA ticket for your derivation request.  Please only attach one file of each type (i.e. do not seperate files by mc campaign).".format(len(samples_for_JIRA))
else:
  print "There was an issue with the request, please check it carefully!"
