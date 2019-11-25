#!env/python
import os
from optparse import OptionParser
import glob
parser = OptionParser()
from collections import OrderedDict

def first(dict):
    return dict[next(iter(dict))]


def get_available_ptags():
    available_ptags ={}
    latest_tag_samples =[]
    with open("Rucio/full_1LeptonSampleList.txt","r") as rucio_file:
        for line in rucio_file:
            if len(line.split('_r'))>2: continue
            if "Sample" in line:
                available_ptags[line.split("Sample: ")[1].replace(".recon.AOD.","__").rstrip()]=[]
                print(line.split("Sample: ")[1].replace(".recon.AOD.","__").rstrip())
            else:
                print(line.replace(".deriv.DAOD_SUSY5.","")[:-7])
                available_ptags[line.replace(".deriv.DAOD_SUSY5.","__")[:-7]].append(int(line[-5:]))
                if "3990" in line:
                    latest_tag_samples.append(line)
    return available_ptags,latest_tag_samples

def write_out(available_ptags,latest_tag_samples):
    with open("1LeptonSampleList.txt", "w") as avaiable_list:
        for line in latest_tag_samples:
            avaiable_list.write(line)
    with open("missing_latest_ptag_1Lepton.txt","w") as missing_list:
        for sample in available_ptags:
            print(sample)
            print(available_ptags[sample])
            if 3990 not in available_ptags[sample]:
                missing_list.write(sample.replace('__',".recon.AOD.")+'\n')

available_ptags,latest_tag_samples = get_available_ptags()
write_out(available_ptags, latest_tag_samples)
