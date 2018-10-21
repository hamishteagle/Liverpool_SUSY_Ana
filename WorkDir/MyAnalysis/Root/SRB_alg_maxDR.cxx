   //SRB alg selecting maxDR and then next maxDR
  int maxAlg_id1 =-1;
  int maxAlg_id2 =-1;
  int maxAlg_id3 =-1;
  int maxAlg_id4 =-1;
  float maxAlg_maxDR = -1;
  float maxAlg_maxDR2 = -1;
  float m_maxAlg=-1;
  float m_maxAlg1=-1;
  float m_maxAlg2=-1;
  if (nBJets>=4){  
    for (int i = 0; i<nBJets; i++){
      for (int j =0; j<nBJets; j++){
	if (i!= j){
	  float trialDR1 = fabs(Signal_BJet[i].DeltaR(Signal_BJet[j]));
	  if (trialDR1>maxAlg_maxDR){
	    maxAlg_maxDR=trialDR1;
	    maxAlg_id1 =i;
	    maxAlg_id2 =j;
	  }
	}
      }
    }
    for (int k =0; k<nBJets; ++k){
      for (int l = 0; l<nBJets; ++l){
	if (k!=l && k!=maxAlg_id1 && k!=maxAlg_id2 && l!=maxAlg_id1 && l!=maxAlg_id2){
	  float trialDR2 = fabs(Signal_BJet[k].DeltaR(Signal_BJet[l]));
	  if (trialDR2>maxAlg_maxDR2){
	    maxAlg_maxDR2 = trialDR2;	    
	    maxAlg_id3 =k;
	    maxAlg_id4 =l;
	  }
	}
      }
    }
    m_maxAlg1 = (Signal_BJet[maxAlg_id1]+Signal_BJet[maxAlg_id2]).M();
    m_maxAlg2 = (Signal_BJet[maxAlg_id3]+Signal_BJet[maxAlg_id4]).M();
    m_maxAlg = (m_maxAlg1+m_maxAlg2)/2;
  }
