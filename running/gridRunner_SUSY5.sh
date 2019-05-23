#!bin/bash
#PATH=/bin/
    alreadySubmitted="submittedtracker_SUSY5.txt"
function runttbarFile_a(){
    inputTxt="SampleLists_SUSY5/mc16a/ttbar.txt"
    echo Running file; $inputTxt
   while read line; do 
       echo "Running over file "$line
       trybool=0
	while read checkline; do 
	    if [ "$line" == "$checkline" ] || [ "$line" == "" ];  then 
		echo "already done" $checkline
		$trybool=1
		fi
	done <$alreadySubmitted
	if [ $trybool == 0 ] 
	then
	    if  testRun $line 
		then
		echo $line >>submittedtracker_SUSY5.txt
	    fi
	fi
   done <$inputTxt
}
function runttbarFile_e(){
    inputTxt="SampleLists_SUSY5/mc16e/ttbar.txt"
    echo Running file; $inputTxt
   while read line; do 
       echo "Running over file "$line
       trybool=0
	while read checkline; do 
	    if [ "$line" == "$checkline" ] || [ "$line" == "" ];  then 
		echo "already done" $checkline
		$trybool=1
		fi
	done <$alreadySubmitted
	if [ $trybool == 0 ] 
	then
	    if  testRun $line 
		then
		echo $line >>submittedtracker_SUSY5.txt
	    fi
	fi
   done <$inputTxt
}
function runttbarFile_d(){
    inputTxt="SampleLists_SUSY5/mc16d/ttbar.txt"
    echo Running file; $inputTxt
    while read line; do 
       echo "Running over file "$line
       trybool=0
	while read checkline; do 
	    if [ "$line" == "$checkline" ];  then 
		echo "already done" $checkline
		$trybool=1
		fi
	done <$alreadySubmitted
	if [ $trybool == 0 ] 	    
	then
	    if  testRun $line ;then  
		echo $line >>submittedtracker_SUSY5.txt
	    fi
	fi
    done <$inputTxt
}


function runsingleTopFile_a(){
    inputTxt="SampleLists_SUSY5/mc16a/singleTop.txt"
    echo Running file; $inputTxt
   while read line; do 
       echo "Running over file "$line
       trybool=0
	while read checkline; do 
	    if [ "$line" == "$checkline" ];  then 
		echo "already done" $checkline
		$trybool=1
		fi
	done <$alreadySubmitted
	if [ $trybool == 0 ] 
	then
	     if testRun $line   
	     then
		 echo $line >>submittedtracker_SUSY5.txt
	     fi
	fi
    done <$inputTxt
}
function runsingleTopFile_e(){
    inputTxt="SampleLists_SUSY5/mc16e/singleTop.txt"
    echo Running file; $inputTxt
   while read line; do 
       echo "Running over file "$line
       trybool=0
	while read checkline; do 
	    if [ "$line" == "$checkline" ];  then 
		echo "already done" $checkline
		$trybool=1
		fi
	done <$alreadySubmitted
	if [ $trybool == 0 ] 
	then
	     if testRun $line   
	     then
		 echo $line >>submittedtracker_SUSY5.txt
	     fi
	fi
    done <$inputTxt
}
function runsingleTopFile_d(){
    inputTxt="SampleLists_SUSY5/mc16d/singleTop.txt"
    echo Running file; $inputTxt
   while read line; do 
       echo "Running over file "$line
       trybool=0
	while read checkline; do 
	    if [ "$line" == "$checkline" ];  then 
		echo "already done" $checkline
		$trybool=1
		fi
	done <$alreadySubmitted
	if [ $trybool == 0 ] 
	then
	    if [ testRun $line ]  
		then
		echo $line >>submittedtracker_SUSY5.txt
	    fi
	fi
   done <$inputTxt
}

function runttVFile_e(){
    inputTxt="$1"
    inputTxt="SampleLists_SUSY5/mc16e/ttV.txt"
    echo Running file; $inputTxt
   while read line; do 
       echo "Running over file "$line
       trybool=0
	while read checkline; do 
	    if [ "$line" == "$checkline" ];  then 
		echo "already done" $checkline
		$trybool=1
		fi
	done <$alreadySubmitted
	if [ $trybool == 0 ] 
	then
	    if  testRun $line   
		then
		echo $line >>submittedtracker_SUSY5.txt
	    fi
	fi
   done <$inputTxt
}
function runttVFile_a(){
    inputTxt="$1"
    inputTxt="SampleLists_SUSY5/mc16a/ttV.txt"
    echo Running file; $inputTxt
   while read line; do 
       echo "Running over file "$line
       trybool=0
	while read checkline; do 
	    if [ "$line" == "$checkline" ];  then 
		echo "already done" $checkline
		$trybool=1
		fi
	done <$alreadySubmitted
	if [ $trybool == 0 ] 
	then
	    if  testRun $line   
		then
		echo $line >>submittedtracker_SUSY5.txt
	    fi
	fi
   done <$inputTxt
}
function runttVFile_d(){
    inputTxt="$1"
    inputTxt="SampleLists_SUSY5/mc16d/ttV.txt"
    echo Running file; $inputTxt
   while read line; do 
       echo "Running over file "$line
       trybool=0
	while read checkline; do 
	    if [ "$line" == "$checkline" ];  then 
		echo "already done" $checkline
		$trybool=1
		fi
	done <$alreadySubmitted
	if [ $trybool == 0 ] 
	then
	    if  testRun $line   
		then
		echo $line >>submittedtracker_SUSY5.txt
	    fi
	fi
    done <$inputTxt
}

function runwJetsFile_a(){
    inputTxt="$1"
    inputTxt="SampleLists_SUSY5/mc16a/wJets.txt"
    echo Running file; $inputTxt
   while read line; do 
       echo "Running over file "$line
       trybool=0
	while read checkline; do 
	    if [ "$line" == "$checkline" ];  then 
		echo "already done" $checkline
		$trybool=1
		fi
	done <$alreadySubmitted
	if [ $trybool == 0 ] 
	then
	    if  testRun $line   
	    then
		echo $line >>submittedtracker_SUSY5.txt
	    fi
	fi
    done <$inputTxt
}
function runwJetsFile_e(){
    inputTxt="$1"
    inputTxt="SampleLists_SUSY5/mc16e/wJets.txt"
    echo Running file; $inputTxt
   while read line; do 
       echo "Running over file "$line
       trybool=0
	while read checkline; do 
	    if [ "$line" == "$checkline" ];  then 
		echo "already done" $checkline
		$trybool=1
		fi
	done <$alreadySubmitted
	if [ $trybool == 0 ] 
	then
	    if  testRun $line   
	    then
		echo $line >>submittedtracker_SUSY5.txt
	    fi
	fi
    done <$inputTxt
}
function runwJetsFile_d(){
    inputTxt="$1"
    inputTxt="SampleLists_SUSY5/mc16d/wJets.txt"
    echo Running file; $inputTxt
   while read line; do 
       echo "Running over file "$line
       trybool=0
	while read checkline; do 
	    if [ "$line" == "$checkline" ];  then 
		echo "already done" $checkline
		$trybool=1
		fi
	done <$alreadySubmitted
	if [ $trybool == 0 ]
	then
	    if  testRun $line   
	    then
		echo $line >>submittedtracker_SUSY5.txt
	    fi
	fi
    done <$inputTxt
}

function runzJetsFile_e(){
    inputTxt="$1"
    #inputTxt="tempzJets.txt"
    inputTxt="SampleLists_SUSY5/mc16e/zJets.txt"
    echo Running file; $inputTxt
   while read line; do 
       echo "Running over file "$line
       trybool=0
	while read checkline; do 
	    if [ "$line" == "$checkline" ];  then 
		echo "already done" $checkline
		$trybool=1
		fi
	done <$alreadySubmitted
	if [ $trybool == 0 ] 
	then
	    if testRun $line 
	    then  
	    echo $line >>submittedtracker_SUSY5.txt
	    fi
	fi
    done <$inputTxt
}
function runzJetsFile_a(){
    inputTxt="$1"
    #inputTxt="tempzJets.txt"
    #inputTxt="SampleLists_SUSY5/mc16a/zJets.txt"
    inputTxt="SampleLists_SUSY5/mc16a/zJets_temp26.1.19.txt"
    echo Running file; $inputTxt
   while read line; do 
       echo "Running over file "$line
       trybool=0
	while read checkline; do 
	    if [ "$line" == "$checkline" ];  then 
		echo "already done" $checkline
		$trybool=1
		fi
	done <$alreadySubmitted
	if [ $trybool == 0 ] 
	then
	    if testRun $line 
	    then  
	    echo $line >>submittedtracker_SUSY5.txt
	    fi
	fi
    done <$inputTxt
}
function runzJetsFile_d(){
    inputTxt="$1"
    inputTxt="SampleLists_SUSY5/mc16d/zJets.txt"
    echo Running file; $inputTxt
   while read line; do 
       echo "Running over file "$line
       trybool=0
	while read checkline; do 
	    if [ "$line" == "$checkline" ];  then 
		echo "already done" $checkline
		$trybool=1
		fi
	done <$alreadySubmitted
	if [ $trybool == 0 ] 
	then
	    if [ testRun $line ]  
	    then
		echo $line >>submittedtracker_SUSY5.txt
	    fi
	fi
    done <$inputTxt
}

function rundiBosonFile_e(){
    inputTxt="$1"
    inputTxt="SampleLists_SUSY5/mc16e/diBoson.txt"
    echo Running file; $inputTxt
   while read line; do 
       echo "Running over file "$line
       trybool=0
	while read checkline; do 
	    if [ "$line" == "$checkline" ];  then 
		echo "already done" $checkline
		$trybool=1
		fi
	done <$alreadySubmitted
	if [ $trybool == 0 ] 
	then
	    if testRun $line 
	    then
		echo $line >>submittedtracker_SUSY5.txt
	    fi
	fi
    done <$inputTxt
}
function rundiBosonFile_a(){
    inputTxt="$1"
    inputTxt="SampleLists_SUSY5/mc16a/diBoson.txt"
    echo Running file; $inputTxt
   while read line; do 
       echo "Running over file "$line
       trybool=0
	while read checkline; do 
	    if [ "$line" == "$checkline" ];  then 
		echo "already done" $checkline
		$trybool=1
		fi
	done <$alreadySubmitted
	if [ $trybool == 0 ] 
	then
	    if testRun $line 
	    then
		echo $line >>submittedtracker_SUSY5.txt
	    fi
	fi
    done <$inputTxt
}
function rundiBosonFile_d(){
    inputTxt="$1"
    inputTxt="SampleLists_SUSY5/mc16d/diBoson.txt"
    echo Running file; $inputTxt
   while read line; do 
       echo "Running over file "$line
       trybool=0
	while read checkline; do 
	    if [ "$line" == "$checkline" ];  then 
		echo "already done" $checkline
		$trybool=1
		fi
	done <$alreadySubmitted
	if [ $trybool == 0 ] 
	then
	    if testRun $line   
	    then
		echo $line >>submittedtracker_SUSY5.txt
	    fi
	fi
    done <$inputTxt
}

function rundiJetFile_a(){
    inputTxt="$1"
    inputTxt="SampleLists_SUSY5/mc16a/diJet.txt"
    echo Running file; $inputTxt
   while read line; do 
       echo "Running over file "$line
       trybool=0
	while read checkline; do 
	    if [ "$line" == "$checkline" ];  then 
		echo "already done" $checkline
		$trybool=1
		fi
	done <$alreadySubmitted
	if [ $trybool == 0 ] 
	then
	    if testRun $line 
	    then  
		echo $line >>submittedtracker_SUSY5.txt
	    fi
	fi
    done <$inputTxt
}
function rundiJetFile_e(){
    inputTxt="$1"
    inputTxt="SampleLists_SUSY5/mc16e/diJet.txt"
    echo Running file; $inputTxt
   while read line; do 
       echo "Running over file "$line
       trybool=0
	while read checkline; do 
	    if [ "$line" == "$checkline" ];  then 
		echo "already done" $checkline
		$trybool=1
		fi
	done <$alreadySubmitted
	if [ $trybool == 0 ] 
	then
	    if testRun $line 
	    then  
		echo $line >>submittedtracker_SUSY5.txt
	    fi
	fi
    done <$inputTxt
}
function rundiJetFile_d(){
    inputTxt="$1"
    inputTxt="SampleLists_SUSY5/mc16d/diJet.txt"
    echo Running file; $inputTxt
   while read line; do 
       echo "Running over file "$line
       trybool=0
	while read checkline; do 
	    if [ "$line" == "$checkline" ];  then 
		echo "already done" $checkline
		$trybool=1
		fi
	done <$alreadySubmitted
	if [ $trybool == 0 ] 
	then
	    if testRun $line   
	    then
		echo $line >>submittedtracker_SUSY5.txt
	    fi
	fi
    done <$inputTxt
}
function runtriBosonFile_e(){
    inputTxt="$1"
    inputTxt="SampleLists_SUSY5/mc16e/triBoson.txt"
    echo Running file; $inputTxt
   while read line; do 
       echo "Running over file "$line
       trybool=0
	while read checkline; do 
	    if [ "$line" == "$checkline" ];  then 
		echo "already done" $checkline
		$trybool=1
		fi
	done <$alreadySubmitted
	if [ $trybool == 0 ] 
	then
	    if testRun $line   
	    then
		echo $line >>submittedtracker_SUSY5.txt
	    fi
	fi
    done <$inputTxt
}
function runtriBosonFile_d(){
    inputTxt="$1"
    inputTxt="SampleLists_SUSY5/mc16d/triBoson.txt"
    echo Running file; $inputTxt
   while read line; do 
       echo "Running over file "$line
       trybool=0
	while read checkline; do 
	    if [ "$line" == "$checkline" ];  then 
		echo "already done" $checkline
		$trybool=1
		fi
	done <$alreadySubmitted
	if [ $trybool == 0 ] 
	then
	    if testRun $line   
	    then
		echo $line >>submittedtracker_SUSY5.txt
	    fi
	fi
    done <$inputTxt
}
function runtriBosonFile_a(){
    inputTxt="$1"
    inputTxt="SampleLists_SUSY5/mc16a/triBoson.txt"
    echo Running file; $inputTxt
   while read line; do 
       echo "Running over file "$line
       trybool=0
	while read checkline; do 
	    if [ "$line" == "$checkline" ];  then 
		echo "already done" $checkline
		$trybool=1
		fi
	done <$alreadySubmitted
	if [ $trybool == 0 ] 
	then
	    if testRun $line   
	    then
		echo $line >>submittedtracker_SUSY5.txt
	    fi
	fi
    done <$inputTxt
}
function runttHFile_a(){
    inputTxt="$1"
    inputTxt="SampleLists_SUSY5/mc16a/ttH.txt"
    echo Running file; $inputTxt
   while read line; do 
       echo "Running over file "$line
       trybool=0
	while read checkline; do 
	    if [ "$line" == "$checkline" ];  then 
		echo "already done" $checkline
		$trybool=1
		fi
	done <$alreadySubmitted
	if [ $trybool == 0 ] 
	then
	    if testRun $line   
	    then
		echo $line >>submittedtracker_SUSY5.txt
	    fi
	fi
    done <$inputTxt
}
function runttHFile_d(){
    inputTxt="$1"
    inputTxt="SampleLists_SUSY5/mc16d/ttH.txt"
    echo Running file; $inputTxt
   while read line; do 
       echo "Running over file "$line
       trybool=0
	while read checkline; do 
	    if [ "$line" == "$checkline" ];  then 
		echo "already done" $checkline
		$trybool=1
		fi
	done <$alreadySubmitted
	if [ $trybool == 0 ] 
	then
	    if testRun $line   
	    then
		echo $line >>submittedtracker_SUSY5.txt
	    fi
	fi
    done <$inputTxt
}
function runttHFile_e(){
    inputTxt="$1"
    inputTxt="SampleLists_SUSY5/mc16e/ttH.txt"
    echo Running file; $inputTxt
   while read line; do 
       echo "Running over file "$line
       trybool=0
	while read checkline; do 
	    if [ "$line" == "$checkline" ];  then 
		echo "already done" $checkline
		$trybool=1
		fi
	done <$alreadySubmitted
	if [ $trybool == 0 ] 
	then
	    if testRun $line   
	    then
		echo $line >>submittedtracker_SUSY5.txt
	    fi
	fi
    done <$inputTxt
}
function rundata18File(){
    inputTxt="$1"
    inputTxt="SampleLists_SUSY5/data18.txt"
    echo Running file; $inputTxt
   while read line; do 
       echo "Running over file "$line
       trybool=0
	while read checkline; do 
	    if [ "$line" == "$checkline" ];  then 
		echo "already done" $checkline
		$trybool=1
		fi
	done <$alreadySubmitted
	if [ $trybool == 0 ] 
	then
	    if testRun $line   
	    then
		echo $line >>submittedtracker_SUSY5.txt
	    fi
	fi
    done <$inputTxt
}
function rundata17File(){
    inputTxt="$1"
    inputTxt="SampleLists_SUSY5/data17.txt"
    echo Running file; $inputTxt
   while read line; do 
       echo "Running over file "$line
       trybool=0
	while read checkline; do 
	    if [ "$line" == "$checkline" ];  then 
		echo "already done" $checkline
		$trybool=1
		fi
	done <$alreadySubmitted
	if [ $trybool == 0 ] 
	then
	    if testRun $line   
	    then
		echo $line >>submittedtracker_SUSY5.txt
	    fi
	fi
    done <$inputTxt
}
function rundata16File(){
    inputTxt="$1"
    inputTxt="SampleLists_SUSY5/data16.txt"
    echo Running file; $inputTxt
   while read line; do 
       echo "Running over file "$line
       trybool=0
	while read checkline; do 
	    if [ "$line" == "$checkline" ];  then 
		echo "already done" $checkline
		$trybool=1
		fi
	done <$alreadySubmitted
	if [ $trybool == 0 ] 
	then
	    if testRun $line   
	    then
		echo $line >>submittedtracker_SUSY5.txt
	    fi
	fi
    done <$inputTxt
}
function rundata15File(){
    inputTxt="$1"
    inputTxt="SampleLists_SUSY5/data15.txt"
    echo Running file; $inputTxt
   while read line; do 
       echo "Running over file "$line
       trybool=0
	while read checkline; do 
	    if [ "$line" == "$checkline" ];  then 
		echo "already done" $checkline
		$trybool=1
		fi
	done <$alreadySubmitted
	if [ $trybool == 0 ] 
	then
	    if testRun $line   
	    then
		echo $line >>submittedtracker_SUSY5.txt
	    fi
	fi
    done <$inputTxt
}
function runsignalFile_a(){
    inputTxt="$1"
    inputTxt="SampleLists_SUSY5/mc16a/signal.txt"
    echo Running file; $inputTxt
   while read line; do 
       echo "Running over file "$line
       trybool=0
	while read checkline; do 
	    if [ "$line" == "$checkline" ];  then 
		echo "already done" $checkline
		$trybool=1
		fi
	done <$alreadySubmitted
	if [ $trybool == 0 ] 
	then
	    if testRun $line   
	    then
		echo $line >>submittedtracker_SUSY5.txt
	    fi
	fi
    done <$inputTxt
}
function runsignalFile_d(){
    inputTxt="$1"
    inputTxt="SampleLists_SUSY5/mc16d/signal.txt"
    echo Running file; $inputTxt
   while read line; do 
       echo "Running over file "$line
       trybool=0
	while read checkline; do 
	    if [ "$line" == "$checkline" ];  then 
		echo "already done" $checkline
		$trybool=1
		fi
	done <$alreadySubmitted
	if [ $trybool == 0 ] 
	then
	    if testRun $line   
	    then
		echo $line >>submittedtracker_SUSY5.txt
	    fi
	fi
    done <$inputTxt
}
function runsignalFile_e(){
    inputTxt="$1"
    inputTxt="SampleLists_SUSY5/mc16e/signal.txt"
    echo Running file; $inputTxt
   while read line; do 
       echo "Running over file "$line
       trybool=0
	while read checkline; do 
	    if [ "$line" == "$checkline" ];  then 
		echo "already done" $checkline
		$trybool=1
		fi
	done <$alreadySubmitted
	if [ $trybool == 0 ] 
	then
	    if testRun $line   
	    then
		echo $line >>submittedtracker_SUSY5.txt
	    fi
	fi
    done <$inputTxt
}
function runtempFile(){
    inputTxt="$1"
    inputTxt="temp.txt"
    echo Running file; $inputTxt
   while read line; do 
       echo "Running over file "$line
       trybool=0
	while read checkline; do 
	    if [ "$line" == "$checkline" ];  then 
		echo "already done" $checkline
		$trybool=1
		fi
	done <$alreadySubmitted
	if [ $trybool == 0 ] 
	then
	    if testRun $line   
	    then
		echo $line >>submittedtracker_SUSY5.txt
	    fi
	fi
    done <$inputTxt
}




#What this actually does
#runtempFile
#runttbarFile_a
#wait
#runsingleTopFile_a
#wait
#runttVFile_a
#wait
#runwJetsFile_a
#wait
#runzJetsFile_a
#wait
#rundiBosonFile_a
#wait
runtempFile #diBoson not submitted
wait
rundiJetFile_a
wait
runtriBosonFile_a
wait
runttHFile_a
wait
#runsignalFile_a
#wait
#rundata18File
#wait
#rundata17File
#wait
#rundata16File
#wait
#rundata15File
#wait
# wait
echo Completed all Processes !!!!!!!!!
