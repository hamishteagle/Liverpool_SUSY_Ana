#!bin/bash
##Get all  the p-tags for the samples if theyre not already there

while read sample; do
  echo Sample: ${sample} >>Rucio/old_data.txt
  #echo "rucio list-dids mc16_13TeV:${sample/"recon.AOD"/"deriv.DAOD_SUSY5"}"*"  >>Rucio/old_sample_list.txt --filter type=container --short"
  if [[ $sample == *r9364* ]]; then
    rucio list-dids mc16_13TeV:${sample%DAOD_SUSY5*}DAOD_SUSY5*_r9364_*  >>Rucio/old_sample_list.txt --filter type=container --short
  elif [[ $sample == *r10201* ]]; then
    rucio list-dids mc16_13TeV:${sample%DAOD_SUSY5*}DAOD_SUSY5*_r10201_p*  >>Rucio/old_sample_list.txt --filter type=container --short
  elif [[ $sample == *r10724* ]]; then
    rucio list-dids mc16_13TeV:${sample%DAOD_SUSY5*}DAOD_SUSY5*_r10724_p*  >>Rucio/old_sample_list.txt --filter type=container --short
  elif [[ $sample == *data15* ]]; then
    rucio list-dids data15_13TeV:${sample%DAOD_SUSY5*}DAOD_SUSY5*  >>Rucio/old_data.txt --filter type=container --short
  elif [[ $sample == *data16* ]]; then
    rucio list-dids data16_13TeV:${sample%DAOD_SUSY5*}DAOD_SUSY5*  >>Rucio/old_data.txt --filter type=container --short
  elif [[ $sample == *data17* ]]; then
    rucio list-dids data17_13TeV:${sample%DAOD_SUSY5*}DAOD_SUSY5*  >>Rucio/old_data.txt --filter type=container --short
  elif [[ $sample == *data18* ]]; then
    rucio list-dids data18_13TeV:${sample%DAOD_SUSY5*}DAOD_SUSY5*  >>Rucio/old_data.txt --filter type=container --short

  fi
done<old_data.txt
