#!bin/bash

function runtemp(){
    file="SampleLists_SUSY5/temp.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t MC
	echo "fine"
    else
    echo $file 'does not exist!!'
    fi
}
function runMC(){
    file="SampleLists_SUSY5/current_sample_list.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t MC
	echo "fine"
    else
    echo $file 'does not exist!!'
    fi
}

###### data full campaigns################
function rundata15(){
    file="SampleLists_SUSY5/data/data15.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t DATA -m True
	echo "fine"
    else
    echo $file 'does not exist!!'
    fi
}
function rundata16(){
    file="SampleLists_SUSY5/data/data16.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t DATA -m True
	echo "fine"
    else
    echo $file 'does not exist!!'
    fi
}
function rundata17(){
    file="SampleLists_SUSY5/data/data17.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t DATA -m True
	echo "fine"
    else
    echo $file 'does not exist!!'
    fi
}
function rundata18(){
    file="SampleLists_SUSY5/data/data18.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t DATA -m True
	echo "fine"
    else
    echo $file 'does not exist!!'
    fi
}



####### Running full campaigns ##########
function rundata(){
rundata15
wait
rundata16
wait
rundata17
wait
rundata18
wait
}

runtemp
runMC
wait
rundata
wait
# runalternatives
# wait
echo "Completed all processes!"
#  LocalWords:  runttbar
