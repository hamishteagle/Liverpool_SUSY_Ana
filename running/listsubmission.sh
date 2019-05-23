#!bin/bash


function runmissing_a(){
    file="SampleLists_SUSY5/mc16a/missing_zJets.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t ZJets
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}
function runmissing_d(){
    file="SampleLists_SUSY5/mc16d/missing_singleTop.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t SINGLETOP
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}
function runmissing_e(){
    file="SampleLists_SUSY5/mc16e/missing_ttbar.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t TTBAR
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}

############# mc16a Samples ###############
function runttbar_a(){
    file="SampleLists_SUSY5/mc16a/ttbar.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t TTBAR
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}
function runsingleTop_a(){
    file="SampleLists_SUSY5/mc16a/singleTop.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t SINGLETOP
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}
function runwJets_a(){
    file="SampleLists_SUSY5/mc16a/wJets.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t WJETS
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}
function runzJets_a(){
    file="SampleLists_SUSY5/mc16a/zJets.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t ZJETS
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}
function rundiBoson_a(){
    file="SampleLists_SUSY5/mc16a/diBoson.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t DIBOSON
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}
function runtriBoson_a(){
    file="SampleLists_SUSY5/mc16a/triBoson.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t TRIBOSON
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}
function rundiJet_a(){
    file="SampleLists_SUSY5/mc16a/diJet.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t DIJET
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}
function runVH_a(){
    file="SampleLists_SUSY5/mc16a/VH.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t HIGGS
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}
function runttH_a(){
    file="SampleLists_SUSY5/mc16a/ttH.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t HIGGS
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}
function runttV_a(){
    file="SampleLists_SUSY5/mc16a/ttV.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t TTV
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}
function runsignal_a(){
    file="SampleLists_SUSY5/signal_mc16a.txt" 
    if [  -f $file ]; then
	python listsubmission.py -i $file -t SIGNAL 
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}
function runsignal_a_temp(){
    file="SampleLists_SUSY5/signal_mc16a_temp.txt" 
    if [  -f $file ]; then
	python listsubmission.py -i $file -t SIGNAL 
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}


############# mc16d Samples ###############
function runttbar_d(){
    file="SampleLists_SUSY5/mc16d/ttbar.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t TTBAR
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}

function runsingleTop_d(){
    file="SampleLists_SUSY5/mc16d/singleTop.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t SINGLETOP
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}
function runwJets_d(){
    file="SampleLists_SUSY5/mc16d/wJets.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t WJETS
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}
function runzJets_d(){
    file="SampleLists_SUSY5/mc16d/zJets.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t ZJETS
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}
function rundiBoson_d(){
    file="SampleLists_SUSY5/mc16d/diBoson.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t DIBOSON
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}
function runtriBoson_d(){
    file="SampleLists_SUSY5/mc16d/triBoson.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t TRIBOSON
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}
function rundiJet_d(){
    file="SampleLists_SUSY5/mc16d/diJet.txt" 
    if [  -f $file ]; then
	python listsubmission.py -i $file -t DIJET
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}
function runVH_d(){
    file="SampleLists_SUSY5/mc16d/VH.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t HIGGS
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}
function runttH_d(){
    file="SampleLists_SUSY5/mc16d/ttH.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t HIGGS
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}
function runttV_d(){
    file="SampleLists_SUSY5/mc16d/ttV.txt" 
    if [  -f $file ]; then
	python listsubmission.py -i $file -t TTV
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}
function runsignal_d(){
    file="SampleLists_SUSY5/signal_mc16d.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t SIGNAL
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}


#############  mc16e samples ################
function runttbar_e(){
    file="SampleLists_SUSY5/mc16e/ttbar.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t TTBAR
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}
function runsingleTop_e(){
    file="SampleLists_SUSY5/mc16e/singleTop.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t SINGLETOP
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}
function runwJets_e(){
    file="SampleLists_SUSY5/mc16e/wJets.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t WJETS
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}
function runzJets_e(){
    file="SampleLists_SUSY5/mc16e/zJets.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t ZJETS
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}
function rundiBoson_e(){
    file="SampleLists_SUSY5/mc16e/diBoson.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t DIBOSON
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}
function runtriBoson_e(){
    file="SampleLists_SUSY5/mc16e/triBoson.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t TRIBOSON
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}
function rundiJet_e(){
    file="SampleLists_SUSY5/mc16e/diJet.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t DIJET
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}
function runVH_e(){
    file="SampleLists_SUSY5/mc16e/VH.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t HIGGS
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}
function runttH_e(){
    file="SampleLists_SUSY5/mc16e/ttH.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t HIGGS
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}
function runttV_e(){
    file="SampleLists_SUSY5/mc16e/ttV.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t TTV
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}
function runsignal_e(){
    file="SampleLists_SUSY5/signal_mc16e.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t SIGNAL
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}



###### data full campaigns################
function rundata15(){
    file="SampleLists_SUSY5/data15.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t DATA -m True
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}
function rundata16(){
    file="SampleLists_SUSY5/data16.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t DATA -m True
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}
function rundata17(){
    file="SampleLists_SUSY5/data17.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t DATA -m True
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}
function rundata18(){
    file="SampleLists_SUSY5/data18.txt"
    if [  -f $file ]; then
	python listsubmission.py -i $file -t DATA -m True
	echo "fine"
    else 
    echo $file 'does not exist!!'
    fi
}



####### Running full campaigns ##########
function runmc16a(){
runttbar_a
wait
runsingleTop_a
wait
runwJets_a
wait
runzJets_a
wait
rundiBoson_a
wait
runtriBoson_a
wait
rundiJet_a
wait
runVH_a
wait
runttH_a
wait
runttV_a
wait
runsignal_a
wait
}
function runmc16d(){
runttbar_d
wait
runsingleTop_d
wait
runwJets_d
wait
runzJets_d
wait
rundiBoson_d
wait
runtriBoson_d
wait
rundiJet_d
wait
runVH_d
wait
runttH_d
wait
runttV_d
wait
runsignal_d
wait
}
function runmc16e(){
runttbar_e
wait
runsingleTop_e
wait
runwJets_e
wait
runzJets_e
wait
rundiBoson_e
wait
runtriBoson_e
wait
rundiJet_e
wait
runVH_e
wait
runttH_e
wait
runttV_e
wait
runsignal_e
wait
}

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

runttbar_a
wait

#runmc16a
#wait
#runmc16d
#wait 
#runmc16e
#wait
#rundata


echo "Completed all processes!"
#  LocalWords:  runttbar
