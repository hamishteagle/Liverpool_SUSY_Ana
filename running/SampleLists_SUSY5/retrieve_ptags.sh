#!bin/bash
##Get all  the p-tags for the samples if theyre not already there

while read sample; do
  echo Sample: ${sample} >>Rucio/full_1LeptonSampleList.txt
  rucio list-dids ${sample/"recon.AOD"/"deriv.DAOD_SUSY5"}"*"  >>Rucio/full_1LeptonSampleList.txt --filter type=container --short
done<full_1LeptonSampleList.txt
