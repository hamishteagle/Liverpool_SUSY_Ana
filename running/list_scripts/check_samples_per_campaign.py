import sys,os
import argparse
dir_path=os.path.abspath(os.path.join(os.path.dirname(__file__),'..'))
sys.path.append(dir_path)
parser = argparse.ArgumentParser()
parser.add_argument("-i", dest="infile", help="The file to check", action="store")
args = parser.parse_args()

with open(args.infile, 'r') as infile:
    dsid_campaign_map = {}
    for line in infile:
        dsid = line.split(".deriv")[0]
        if dsid not in dsid_campaign_map:
            dsid_campaign_map[dsid]=[]
        if "r9364"  in line: dsid_campaign_map[dsid].append("a")
        elif "r10201" in line: dsid_campaign_map[dsid].append("d")
        elif "r10724" in line: dsid_campaign_map[dsid].append("e")
        else:
            exit("This line has no campaign tag: "+line)

with open("full_1LeptonSampleList.txt") as running:
    dsid_campaign_map_2 ={}
    for line in running:
        dsid = line.split(".recon")[0]
        if dsid not in dsid_campaign_map_2:
            dsid_campaign_map_2[dsid]=[]
        if "r9364"  in line: dsid_campaign_map_2[dsid].append("a")
        elif "r10201" in line: dsid_campaign_map_2[dsid].append("d")
        elif "r10724" in line: dsid_campaign_map_2[dsid].append("e")
        else:
            exit("This line has no campaign tag: "+line)


missing_a=[]
missing_d=[]
missing_e=[]
running_a=[]
running_d=[]
running_e=[]
##Check the files missing from submission
re_submit_list = []
for dsid, values in dsid_campaign_map_2.items():
    if not all(camp in values for camp in ["a","d","e"]):
        print("This dsid has no period a: "+str(dsid)+" but it's still running")
        #Save the line with the correct r-tag
        with open("full_1LeptonSampleList.txt") as sub_file:
            for line in sub_file:
                if dsid in line:
                    if "a" not in values:
                        re_submit_list.append(line.split("_r")[0]+"_r9364")
                    if "d" not in values:
                        re_submit_list.append(line.split("_r")[0]+"_r10201")
                    if "e" not in values:
                        re_submit_list.append(line.split("_r")[0]+"_r10724")
##Write out the missing files
#remove duplicates
re_submit_list = set(re_submit_list)
with open("missing_submission.txt","w") as out:
    for line in re_submit_list:
        out.write(line+"\n")


#Cross check whether missing samples from the submission list are missing because they are still running or didn't get submitted at all
for dsid,values in dsid_campaign_map.items():
    if not all(camp in values for camp in ["a","d","e"]):
        if all(camp in dsid_campaign_map_2[dsid] for camp in ["a","d","e"]):
            if "a" not in values:
                print("This dsid has no period a: "+str(dsid)+" but it's still running")
                running_a.append(dsid)
            if "d" not in values:
                print("This dsid has no period d: "+str(dsid)+" but it's still running")
                running_d.append(dsid)
            if "e" not in values:
                print("This dsid has no period e: "+str(dsid)+" but it's still running")
                running_e.append(dsid)

        else:
            if "a" not in values:
                print("This dsid has no period a: "+str(dsid))
                missing_a.append(dsid)
            if "d" not in values:
                print("This dsid has no period d: "+str(dsid))
                missing_d.append(dsid)
            if "e" not in values:
                print("This dsid has no period e: "+str(dsid))
                missing_e.append(dsid)

print("Missing still running: "+str(len(running_a)+len(running_d)+len(running_e)))
print("Missing and not submitted: "+str(len(missing_a)+len(missing_d)+len(missing_e)))
