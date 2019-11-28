#!bin/bash
while read sample; do
  #echo Sample: ${sample} >>Rucio/missing_submission.txt
  rucio list-dids ${sample} >>Rucio/missing_submission.txt --filter type=container --short
done<missing_submission.txt
