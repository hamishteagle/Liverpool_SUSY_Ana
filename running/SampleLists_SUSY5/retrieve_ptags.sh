#!bin/bash
##Get all  the p-tags for the samples if theyre not already there
run="TRUE"
if [ $run == "TRUE" ]; then
    for file in mc16*/*.txt; do
	while read sample;do
	    echo Sample: $sample >>${file%.txt}_rucio.txt
	    #echo Sample: $sample
	    if [[ "$sample" == "data15"* ]]; then
		  rucio list-dids data15_13TeV:${sample::-4}* >>${file%.txt}_rucio.txt --filter type=container --short
	    elif [[ "$sample" == "data16"* ]]; then
		  rucio list-dids data16_13TeV:${sample::-4}* >>${file%.txt}_rucio.txt --filter type=container --short
	    elif [[ "$sample" == "data17"* ]]; then
		  rucio list-dids data17_13TeV:${sample::-4}* >>${file%.txt}_rucio.txt --filter type=container --short
	    elif [[ "$sample" == "data18"* ]]; then
		  rucio list-dids data18_13TeV:${sample::-4}* >>${file%.txt}_rucio.txt --filter type=container --short
	    else
		rucio list-dids mc16_13TeV:${sample::-4}* >>${file%.txt}_rucio.txt --filter type=container --short
	    fi
	    done<$file
	##Remove the *: from the front
	sed -e s/mc16_13TeV://g -i ${file%.txt}_rucio.txt
    done
fi
