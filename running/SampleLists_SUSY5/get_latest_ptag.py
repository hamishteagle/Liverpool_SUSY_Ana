#!env/python
import os
from optparse import OptionParser
import glob
parser = OptionParser()
from collections import OrderedDict

def first(dict):
    return dict[next(iter(dict))]


def get_available_ptag_map():
    global_ptag_map = {}
    for in_file in glob.glob('Rucio/data/*_rucio.txt'):
        local_ptag_map = {}
        with  open(in_file, 'r') as file:
            name = in_file.replace("_rucio.txt","")
            if 'data' in name:
                name = in_file.replace("_rucio.txt","")[:-2]
            for line in file:
                dsid = line.split('.')[1]
                ptag = int(line[-5:])
                if "Sample" in line: local_ptag_map[dsid]=[]#define a new list of available ptags
                if "Sample" not in line: local_ptag_map[dsid].append(ptag)#append each ptag to the dsid list
            global_ptag_map[name]=local_ptag_map
    #print(global_ptag_map)
    return global_ptag_map

def write_out_latest(name_latest_map):
    for in_file in glob.glob('Rucio/data/*_rucio.txt'):
        lines_to_write=[]
        name = in_file.replace("_rucio.txt","")
        if 'data' in name:
            name = in_file.replace("_rucio.txt","")[:-2]
        if name in name_latest_map:
            ptag = name_latest_map[name]
        else :
            lines_to_write.append("Unkown")
            ptag = "0"
        with open(in_file,'r') as file:
            for line in file:
                #print(line[-5:].rstrip())
                if ptag == int(line[-5:]) and "Sample" not in line:
                    lines_to_write.append(line)
        file.close()
        with open(in_file.replace('_rucio','_new').replace("Rucio/",""),'w') as new_file:
            for line in lines_to_write:
                #print("Writing: "+str(line))
                new_file.write(line)



##Get the list of ptags
dsid_ptag_map = get_available_ptag_map()
name_latest_map = {}
for name in dsid_ptag_map:
    #print(name)
    #if not name == "mc16a/zJets": continue
    ##sort the ptags into the correct order
    for dsid in dsid_ptag_map[name]:
        dsid_ptag_map[name][dsid] = sorted(dsid_ptag_map[name][dsid],reverse=True)
    #check for the latest available ptag
    ptag_list = first(dsid_ptag_map[name])
    for ptag in ptag_list:
        if int(ptag)>3954: continue
        #print("Checking for ptag: "+str(ptag))
        if all(ptag in ptags for dsid,ptags in dsid_ptag_map[name].items()):
            print("Current latest ptag for "+name+" is :"+str(ptag))
            name_latest_map[name]=ptag
            break
        elif ptag == ptag_list[-1]:
            print("Found no common ptag for sample: "+str(name)+", options are: ")
            ##Load the full ptag list
            full_ptag_list = []
            for dsid,ptags in dsid_ptag_map[name].items():
                for p in ptags:
                    if int(p)>3954: continue
                    if p not in full_ptag_list: full_ptag_list.append(p)
            print("Full ptag list: "+str(full_ptag_list))
            for ptag_opt in sorted(full_ptag_list, reverse=True):
                print(ptag_opt)
                for dsid,ptags in dsid_ptag_map[name].items():
                    if ptag_opt not in ptags:
                        print("Missing for: "+str(dsid)+"::"+str(ptags))
                        pass
            break
write_out_latest(name_latest_map)
