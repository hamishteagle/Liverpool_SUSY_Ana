  //SRB alg selecting the pair of pairs which maximised their sum (2.5 for historical reasons..change name)
  int Alg2_5_id1 =-1;
  int Alg2_5_id2 =-1;
  int Alg2_5_id3 =-1;
  int Alg2_5_id4 =-1;
  float Alg2_5_maxDR_both = -1;
  float m_Alg2_5=-1;
  float m_Alg2_51=-1;
  float m_Alg2_52=-1;
  if (nBJets>=4){  
    for (int i = 0; i<nBJets; i++){
      for (int j =0; j<nBJets; j++){
	if (i!= j){
	  float trialDR1 = fabs((Signal_BJet[i].DeltaR(Signal_BJet[j])));
	  for (int k =0; k<nBJets; ++k){
	    for (int l = 0; l<nBJets; ++l){
	      if (k!=l && k!=i && k!=j && l!=i && l!=j){
		float trialDR2 = fabs(Signal_BJet[k].DeltaR(Signal_BJet[l]));
		float trialDR_both = trialDR1+trialDR2;
		if (trialDR_both>Alg2_5_maxDR_both){
		  Alg2_5_maxDR_both = trialDR_both;
		  Alg2_5_id3 =k;
		  Alg2_5_id4 =l;
		  Alg2_5_id1 =i;
		  Alg2_5_id2 =j;
		}
	      }
	    }
	  }
	}
      }
    }
    m_Alg2_51 = (Signal_BJet[Alg2_5_id1]+Signal_BJet[Alg2_5_id2]).M();
    m_Alg2_52 = (Signal_BJet[Alg2_5_id3]+Signal_BJet[Alg2_5_id4]).M();
    m_Alg2_5 = (m_Alg2_51+m_Alg2_52)/2;
  }
