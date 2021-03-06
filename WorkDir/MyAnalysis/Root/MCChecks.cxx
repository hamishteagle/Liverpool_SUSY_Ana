// source file for the MC checks takes the m_event object to do some quick checks for the MC
// can also use this to include SUSYTools crosssection if desired

#include "MyAnalysis/MCChecks.h"
#include <TLorentzVector.h>
#include <TVector2.h>
#include "xAODTruth/TruthEventContainer.h"
#include "xAODTruth/TruthEvent.h"
#include "MCTruthClassifier/MCTruthClassifier.h"

MCChecks::MCChecks(){

  pTZBoson = 0;
  phiZBoson = 0;
  etaZBoson = 0;
  Zll = false;
  Zqq = false;

  truthFilterMET = 0;
  jetFilterno = 0;
  jetFilterno_prompt = 0;

  pTt1 = 0;
  phit1 = 0;
  etat1 = 0;
  pTt2 = 0;
  phit2 = 0;
  etat2 = 0;
  pTttbar = 0;
  phittbar = 0;
  etattbar = 0;

  ttbar_W1_decay = -1;
  ttbar_tau1_decay = -1;
  ttbar_W2_decay = -1;
  ttbar_tau2_decay = -1;



  arbitraryDuplicateCheck = 0;

  Weight = 1;
  MEWeight = 1;
  WeightNormalisation = 1;
  NTrials = 1;
  MUR0p5_MUF0p5_PDF261000 = 1;
  MUR0p5_MUF1_PDF261000 = 1;
  MUR1_MUF0p5_PDF261000 = 1;
  MUR1_MUF1_PDF261000 = 1;
  MUR1_MUF2_PDF261000 = 1;
  MUR2_MUF1_PDF261000 = 1;
  MUR2_MUF2_PDF261000 = 1;
  MUR1_MUF1_PDF261001 = 1;
  MUR1_MUF1_PDF261002 = 1;

  tau_1_prongs = 0;
  tau_2_prongs = 0;


  TruthTau.clear();

  variationweights.push_back(0);

}

bool MCChecks::RetrieveWeights(asg::SgTEvent* event) {

 const xAOD::TruthEventContainer* truthevents = 0;
 if ((event->retrieve( truthevents, "TruthEvents" )).isSuccess()) {
  if (truthevents->size() > 0) {
   const xAOD::TruthEvent *truthevent = (*truthevents)[0];
   variationweights = truthevent->weights();
  }
 }
 return true;
}

bool MCChecks::SherpaUncertaintyWeights(asg::SgTEvent* event){

  const xAOD::TruthEventContainer* truthevents = 0;

  if ( !( (event->retrieve( truthevents, "TruthEvents" )).isSuccess()) )
    {
      std::cout << "Can't retrieve TruthEvents " << std::endl;
    }


  if (truthevents->size()>0)
    {
      const xAOD::TruthEvent *truthevent = (*truthevents)[0];

      variationweights = truthevent->weights();


      if (variationweights.size()>=11)
	{

	  Weight = variationweights[0];
	  MEWeight = variationweights[1];
	  WeightNormalisation = variationweights[2];
	  NTrials = variationweights[3];
	  MUR0p5_MUF0p5_PDF261000 = variationweights[4];
	  MUR0p5_MUF1_PDF261000 = variationweights[5];
	  MUR1_MUF0p5_PDF261000 = variationweights[6];
	  MUR1_MUF1_PDF261000 = variationweights[7] ;
	  MUR1_MUF2_PDF261000 = variationweights[8];
	  MUR2_MUF1_PDF261000 = variationweights[9];
	  MUR2_MUF2_PDF261000 = variationweights[10];


	}

    }


  return true;
}

bool MCChecks::VariableForDuplicates(asg::SgTEvent* event)
{

  const xAOD::TruthParticleContainer* truthP = 0;
  event->retrieve( truthP, "TruthParticles" );

  for (unsigned int j = 0; j < truthP->size(); ++j){
    if ( (*truthP)[j]->pt() > 0){
      arbitraryDuplicateCheck = (*truthP)[j]->pt();
      return true;
    }
  }
  return false;
}




bool MCChecks::SherpaWOR(asg::SgTEvent* event, double ptThreshold) // threshold in GeV
{
  TLorentzVector V;

  TLorentzVector l1;
  TLorentzVector l2;

  bool foundFirst = false;
  bool foundSecond = false;



  const xAOD::TruthParticleContainer* truthP = 0;
  event->retrieve( truthP, "TruthParticles" );

  for (unsigned int j = 0; j < truthP->size(); ++j){

    // if ((*m_tree->mc_status)[j] == 3 && fabs((*m_tree->mc_pdgId)[j]) >= 11 && fabs((*m_tree->mc_pdgId)[j]) <= 16){

    if ( ( (*truthP)[j]->status() == 3 ) && fabs((*truthP)[j]->pdgId())>=11 && fabs((*truthP)[j]->pdgId())<=16 ) {

      if (!foundFirst){
	// l1.SetPtEtaPhiM((*m_tree->mc_pt)[j],(*m_tree->mc_eta)[j], (*m_tree->mc_phi)[j], (*m_tree->mc_m)[j]);
	l1 = (*truthP)[j]->p4();
	foundFirst = true;
      } else if(!foundSecond){
	// l2.SetPtEtaPhiM((*m_tree->mc_pt)[j],(*m_tree->mc_eta)[j], (*m_tree->mc_phi)[j], (*m_tree->mc_m)[j]);
	l2 = (*truthP)[j]->p4();
	foundSecond = true;
      } else {
	//std::cout << "Error! More than 2 leptons?" << std::endl;
      }
    }
  }
  bool res = false;
  if (!foundSecond) std::cout << "Unable to find 2 leptons" << std::endl;
  else {
    V = l1 + l2;
    // cout << " pt of the W/Z is " << V.Pt() << endl;
    if (V.Pt()>(ptThreshold*1000.0))
      {
	res = true;
      }
  }
  return res;
}

bool MCChecks::DiBosonOR(asg::SgTEvent* event)
{
  bool result = false;

  const xAOD::TruthParticleContainer* truthP = 0;
  event->retrieve( truthP, "TruthParticle" );

  for (unsigned int j = 0; j < truthP->size(); ++j)
    {
      if ( ( (*truthP)[j]->status() == 3 ) && fabs((*truthP)[j]->pdgId())==5 )
        result = true;
    }

  return result;

}

double MCChecks::OverlappingMETSlices(asg::SgTEvent* event)
{


  double sumx = 0;
  double sumy = 0;


  const xAOD::TruthParticleContainer* truthP = 0;
  event->retrieve( truthP, "TruthParticles" );

  for(const auto& particle : *truthP) {
    // find all status=1 neutrinos
    bool addpart = false;
    if (particle->status() != 1)
      continue;
    if (!particle->isNeutrino())
      continue;

    // loop through the parents and see if its from a W, Z or |pdg|<9
    const xAOD::TruthParticle* par = particle->parent(0);
    while ( par ) {
      // when there is a hadron somewhere we are not interested
      if (par->isHadron() )
        break;

      if ( (par->isW() || par->isZ() || abs(par->pdgId())<9) ) {
        addpart = true;
        break;
      }

      par = par->parent(0);
    }

    if (addpart) {
      sumx += particle->p4().Px();
      sumy += particle->p4().Py();
    }
  }
  double truthFilterMET = sqrt(sumx*sumx + sumy*sumy)*0.001;


  return truthFilterMET;
}




bool MCChecks::ZpT(asg::SgTEvent* event) // threshold in GeV
{
  TLorentzVector V;

  TLorentzVector l1;
  TLorentzVector l2;

  bool foundFirst = false;
  bool foundSecond = false;


  const xAOD::TruthParticleContainer* truthP = 0;
  event->retrieve( truthP, "TruthParticles" );

  // for (unsigned int j = 0; j < truthP->size(); ++j){


  //   if ( ( ((*truthP)[j]->status() == 3) )) {


  //     // the above assumes we've found a Z-Boson here. Loop over it's children, set the pT of the Z:
  //     for (int i = 0; i < (*truthP)[j]->nChildren(); i++ ){

  // 	auto kid = (*truthP)[j]->child(i);

  // 	if ( fabs(kid->pdgId()) >= 12 && fabs(kid->pdgId()) <= 16){
  // 	  //std::cout << "Found neutrino" << std::endl;
  // 	  if (!foundFirst) {
  // 	    //std::cout << "Found first Neutrino" << std::endl;
  // 	    foundFirst = true;
  // 	    l1 = kid->p4();
  // 	    //std::cout << l1.Pt() << std::endl;
  // 	  }
  // 	  else if (!foundSecond && foundFirst){
  // 	    //std::cout << "Found Second Neutrino" << std::endl;
  // 	    foundSecond = true;
  // 	    l2 = kid->p4();
  // 	    //std::cout << l2.Pt() << std::endl;
  // 	  }

  // 	  if (foundSecond && foundFirst) {
  // 	    V = l1+l2;
  // 	    //std::cout << "Z pT: " << V.Pt()*0.001 << std::endl;
  // 	    //std::cout << "Z phi: " << V.Phi() << std::endl;
  // 	    //std::cout << "Z eta: " << V.Eta() << std::endl;

  // 	    pTZBoson = V.Pt()*0.001;
  // 	    phiZBoson = TVector2::Phi_mpi_pi(V.Phi());
  // 	    etaZBoson = V.Eta();
  // 	    Zll = true;

  // 	    break;
  // 	  }
  // 	}


  // 	if ( fabs(kid->pdgId()) >= 1 && fabs(kid->pdgId()) <= 6){
  // 	  if (!foundFirst) {
  // 	    //std::cout << "Found first Neutrino" << std::endl;
  // 	    foundFirst = true;
  // 	    l1 = kid->p4();
  // 	    //std::cout << l1.Pt() << std::endl;
  // 	  }
  // 	  else if (!foundSecond && foundFirst){
  // 	    //std::cout << "Found Second Neutrino" << std::endl;
  // 	    foundSecond = true;
  // 	    l2 = kid->p4();
  // 	    //std::cout << l2.Pt() << std::endl;
  // 	  }

  // 	  if (foundSecond && foundFirst) {
  // 	    V = l1+l2;
  // 	    //std::cout << "Z pT: " << V.Pt()*0.001 << std::endl;
  // 	    //std::cout << "Z phi: " << V.Phi() << std::endl;
  // 	    //std::cout << "Z eta: " << V.Eta() << std::endl;

  // 	    pTZBoson = V.Pt()*0.001;
  // 	    phiZBoson = TVector2::Phi_mpi_pi(V.Phi());
  // 	    etaZBoson = V.Eta();
  // 	    Zqq = true;

  // 	    break;
  // 	  }
  // 	}


  //     }
  //    }
  // }

  if (foundSecond) return true;
  else return false;

}

bool MCChecks::SherpaZpT(asg::SgTEvent* event) // threshold in GeV
{
  TLorentzVector V;

  TLorentzVector l1;
  TLorentzVector l2;

  double Charge1;
  double Charge2;

  int ID1;
  int ID2;

  bool foundFirst = false;
  bool foundSecond = false;


  const xAOD::TruthParticleContainer* truthP = 0;
  event->retrieve( truthP, "TruthParticles" );

  for (unsigned int j = 0; j < truthP->size(); ++j){
    //std::cout << "Particle status code: " << (*truthP)[j]->status() << std::endl;
    if ( ( ((*truthP)[j]->status() == 3))) {
      //std::cout << "Retrieved Truth Particles with status 3. Passed status code" << std::endl;
      auto kid = ((*truthP)[j]);


      //std::cout << "Particle is: " << fabs(kid->pdgId())  <<std::endl;


      if ( fabs(kid->pdgId()) >= 11 && fabs(kid->pdgId()) <= 16){
	//std::cout << "Found lepton" << std::endl;
	if (!foundFirst) {
	  //std::cout << "Found first Neutrino" << std::endl;
	  foundFirst = true;
	  Charge1 = kid->charge();
	  ID1 = fabs(kid->pdgId());
	  l1 = kid->p4();
	  //std::cout << l1.Pt() << std::endl;
	}
	else if (!foundSecond && foundFirst ){
	  //std::cout << "Found Second Neutrino" << std::endl;
	  foundSecond = true;
	  Charge2 = kid->charge();
	  ID2 = fabs(kid->pdgId());
	  l2 = kid->p4();
	  //std::cout << l2.Pt() << std::endl;
	}

	if (foundSecond && foundFirst) {
	  V = l1+l2;
	  //std::cout << "Z pT: " << V.Pt()*0.001 << std::endl;
	  //std::cout << "Z phi: " << V.Phi() << std::endl;
	  //std::cout << "Z eta: " << V.Eta() << std::endl;

	  pTZBoson_Sherpa = V.Pt()*0.001;
	  phiZBoson_Sherpa = TVector2::Phi_mpi_pi(V.Phi());
	  etaZBoson_Sherpa = V.Eta();


	  break;
	}
      }

    }
  }


  if (foundSecond) return true;
  else return false;

}

bool MCChecks::ttbar_decay(asg::SgTEvent* event) // threshold in GeV
{
  TLorentzVector ttbar;
  TLorentzVector t1;
  TLorentzVector t2;

  bool foundFirst = false;
  bool foundSecond = false;


  //std::cout << "Event" << std::endl;


  const xAOD::TruthParticleContainer* truthTaus = 0;
  event->retrieve( truthTaus, "TruthTaus" );
  bool tau1 = false;
  bool tau2 = false;

  for (unsigned int j = 0; j < truthTaus->size(); ++j){
    //std::cout << "There are: " << truthTaus->size() << " taus in the event" << std::endl;
    //std::cout << "status code for tau " << j << " = " << (*truthTaus)[j]->status() << std::endl;
    if (tau1 == false){
      //std::cout << "status code = " << (*truthTaus)[j]->status() << std::endl;
      tau1 = true;
      for (int i = 0; i < (*truthTaus)[j]->nChildren(); i++ ){
      	auto kid = (*truthTaus)[j]->child(i);
	//std::cout << "First tau decays into: "<< fabs(kid->pdgId()) << std::endl;
	if (fabs(kid->pdgId()) == 11){
	  //std::cout << "First tau decays via an electron" << std::endl;
	    ttbar_tau1_decay = 11;
	    break;
	}
	else if (fabs(kid->pdgId()) == 13){
	  //std::cout << "First tau decays via a muon" << std::endl;
	  ttbar_tau1_decay = 13;
	  break;
	}
	else if (fabs(kid->pdgId()) == 16){
	  //std::cout << "This is the tau decaying to a neutrino" << std::endl;
	  tau1 = true;
	  //break;
	}
	else {
	  //std::cout << "First tau decays hadronically" << std::endl;
	  if (kid->charge() != 0){
	    tau_1_prongs++;
	  }
	  ttbar_tau1_decay = 0;
	}
      }
    }
    else if (tau2 == false){
      //std::cout << "status code = " << (*truthTaus)[j]->status() << std::endl;
      tau2 = true;
      for (int i = 0; i < (*truthTaus)[j]->nChildren(); i++ ){
	auto kid = (*truthTaus)[j]->child(i);
	//std::cout << "Second tau decays into: "<< fabs(kid->pdgId()) << std::endl;
	if (fabs(kid->pdgId()) == 11){
	  //std::cout << "Second tau decays via an electron" << std::endl;
	  ttbar_tau2_decay = 11;
	  break;
	}
	else if (fabs(kid->pdgId()) == 13){
	  //std::cout << "Second tau decays via a muon" << std::endl;
	  ttbar_tau2_decay = 13;
	  break;
	}
	else if (fabs(kid->pdgId()) == 16){
	  //std::cout << "This is the tau decaying to a neutrino" << std::endl;
	  tau2 = true;
	  //break;
	}
	else {
	  //std::cout << "Second tau decays hadronically" << std::endl;
	  if (kid->charge() != 0){
	    tau_2_prongs++;
	  }
	  ttbar_tau2_decay = 0;
	}
      }
    }
  }

  //std::cout << "Number of prongs for tau one:" << tau_1_prongs << std::endl;
  //std::cout << "Number of prongs for tau two:" << tau_2_prongs << std::endl;

  const xAOD::TruthParticleContainer* truthP = 0;
  event->retrieve( truthP, "TruthParticles" );

  for (unsigned int j = 0; j < truthP->size(); ++j){


    // if ((*m_tree->mc_status)[j] == 3 && fabs((*m_tree->mc_pdgId)[j]) >= 11 && fabs((*m_tree->mc_pdgId)[j]) <= 16){

    if ( ( ((*truthP)[j]->status() == 62)  || ((*truthP)[j]->status() == 3) ) && fabs((*truthP)[j]->pdgId())== 6 ) {
      auto top = (*truthP)[j];
      if (!foundFirst) {
	//std::cout << "Found first top" << std::endl;
	foundFirst = true;
	t1 = top->p4();
	pTt1 = t1.Pt()*0.001;
	phit1 = TVector2::Phi_mpi_pi(t1.Phi());
	etat1 = t1.Eta();
	//std::cout << t1.Pt()*0.001 << std::endl;
	for (int i = 0; i < (*truthP)[j]->nChildren(); i++ ){
	  auto kid = (*truthP)[j]->child(i);

	  if ( fabs(kid->pdgId()) == 24) {
	    //std::cout << "Found first W" << std::endl;
	    for (int k = 0; k < kid->nChildren(); k++ ){
	      auto kid_A = kid->child(i);
	      if (fabs(kid_A->pdgId()) == 11 ){
		//std::cout << "First W decays via an electron" << std::endl;
		ttbar_W1_decay = 11;
  		break;
	      }
	      else if (fabs(kid_A->pdgId()) == 13 ){
		//std::cout << "First W decays via a muon" << std::endl;
		ttbar_W1_decay = 13;
		break;
	      }
	      else if (fabs(kid_A->pdgId()) == 15  ){
		//std::cout << "First W decays via a tau" << std::endl;
		ttbar_W1_decay = 15;
		break;
	      }
	      else{
		//std::cout << "First W decays hadronically" << std::endl;
		ttbar_W1_decay = 0;
		break;
	      }
	    }
	  }
	}
      }
      else if (!foundSecond && foundFirst){
	//std::cout << "Found Second top" << std::endl;
	foundSecond = true;
	t2 = top->p4();
	pTt2 = t2.Pt()*0.001;
	phit2 = TVector2::Phi_mpi_pi(t2.Phi());
	etat2 = t2.Eta();

	//std::cout << t2.Pt()*0.001 << std::endl;
	for (int i = 0; i < (*truthP)[j]->nChildren(); i++ ){
	  auto kid = (*truthP)[j]->child(i);

	  if ( fabs(kid->pdgId()) == 24) {
	    //std::cout << "Found second W" << std::endl;
	    for (int k = 0; k < kid->nChildren(); k++ ){
	      auto kid_A = kid->child(i);
	      if (fabs(kid_A->pdgId()) == 11 ){
		//std::cout << "Second W decays via an electron" << std::endl;
		ttbar_W2_decay = 11;
  		break;
	      }
	      else if (fabs(kid_A->pdgId()) == 13 ){
		//std::cout << "Second W decays via a muon" << std::endl;
		ttbar_W2_decay = 13;
		break;
	      }
	      else if ( fabs(kid_A->pdgId()) == 15 ){
		//std::cout << "Second W decays via a tau" << std::endl;
		ttbar_W2_decay = 15;
		break;
	      }
	      else{
		//std::cout << "Second W decays hadronically" << std::endl;
		ttbar_W2_decay = 0;
		break;
	      }
	    }
	  }
	}


      }

      if (foundSecond && foundFirst) {
	ttbar = t1+t2;
	//std::cout << "ttbar pT: " << ttbar.Pt()*0.001 << std::endl;
	//std::cout << "ttbar phi: " << ttbar.Phi() << std::endl;
	//std::cout << "ttbar eta: " << ttbar.Eta() << std::endl;

	pTttbar = ttbar.Pt()*0.001;
	phittbar = TVector2::Phi_mpi_pi(ttbar.Phi());
	etattbar = ttbar.Eta();


	//break;
      }
    }


    //}
    //if ( ( ((*truthP)[j]->status() == 62)  || ((*truthP)[j]->status() == 3) ) && fabs((*truthP)[j]->pdgId())== 13 ) {
    //  auto muon = (*truthP)[j];
    //  auto muon_parent = muon->parent(0);
    //  std::cout << "muon parent is:" << fabs(muon_parent->pdgId()) << std::endl;

    //}
  }


  if (foundSecond) return true;
  else return false;

}


bool MCChecks::ttbarpT(asg::SgTEvent* event) // threshold in GeV
{
  TLorentzVector ttbar;
  TLorentzVector t1;
  TLorentzVector t2;

  bool foundFirst = false;
  bool foundSecond = false;


  const xAOD::TruthParticleContainer* truthP = 0;
  event->retrieve( truthP, "TruthParticles" );

  for (unsigned int j = 0; j < truthP->size(); ++j){

    // if ((*m_tree->mc_status)[j] == 3 && fabs((*m_tree->mc_pdgId)[j]) >= 11 && fabs((*m_tree->mc_pdgId)[j]) <= 16){

    if ( ( ((*truthP)[j]->status() == 62)  || ((*truthP)[j]->status() == 3) ) && fabs((*truthP)[j]->pdgId())== 6 ) {
      //std::cout << "Found a top" << std::endl;
      auto top = (*truthP)[j];
      if (!foundFirst) {
	//std::cout << "Found first top" << std::endl;
	foundFirst = true;
	t1 = top->p4();
	pTt1 = t1.Pt()*0.001;
	phit1 = TVector2::Phi_mpi_pi(t1.Phi());
	etat1 = t1.Eta();
	//std::cout << t1.Pt()*0.001 << std::endl;
      }
      else if (!foundSecond && foundFirst){
	//std::cout << "Found Second Neutrino" << std::endl;
	foundSecond = true;
	t2 = top->p4();
	pTt2 = t2.Pt()*0.001;
	phit2 = TVector2::Phi_mpi_pi(t2.Phi());
	etat2 = t2.Eta();

	//std::cout << t2.Pt()*0.001 << std::endl;
      }

      if (foundSecond && foundFirst) {
	ttbar = t1+t2;
	//std::cout << "ttbar pT: " << ttbar.Pt()*0.001 << std::endl;
	//std::cout << "ttbar phi: " << ttbar.Phi() << std::endl;
	//std::cout << "ttbar eta: " << ttbar.Eta() << std::endl;

	pTttbar = ttbar.Pt()*0.001;
	phittbar = TVector2::Phi_mpi_pi(ttbar.Phi());
	etattbar = ttbar.Eta();


	break;
      }
    }

  }


  if (foundSecond) return true;
  else return false;

}

int MCChecks::HeavyFlavourFilter_countJets(asg::SgTEvent* event, bool doPrompt){

  ///count how many hadrons are in a jet///
  // check that this is a sample that we need to do the HF filter on first



  const xAOD::JetContainer* truthJets(nullptr);
  if(!event->retrieve(truthJets,"AntiKt4TruthJets").isSuccess()){
    return 0;
  }


  int jet_n=truthJets->size();

  ///initialization of data members///

  m_jet_trueflav.clear();
  m_jet_count.clear();
  m_jet_id.clear();
  m_jet_pt.clear();
  m_jet_eta.clear();
  m_jet_phi.clear();
  m_jet_m.clear();
  m_jet_trueflav.resize(jet_n,0);
  m_jet_count.resize(jet_n,0);
  m_jet_id.resize(jet_n,0);
  m_jet_TruthID.clear();
  for(auto jptr : *truthJets){

    m_jet_pt.push_back(jptr->pt());
    m_jet_eta.push_back(jptr->eta());
    m_jet_phi.push_back(jptr->phi());
    m_jet_m.push_back(jptr->m());
    int truth_flavour = -1;
    jptr->getAttribute("HadronConeExclTruthLabelID",truth_flavour);
    m_jet_TruthID.push_back(truth_flavour);
  }



  const xAOD::TruthParticleContainer* truth_particles(0);
  if(!event->retrieve(truth_particles,"TruthParticles").isSuccess()){
    return 0;
  }

  m_FinalHadrons.clear();
  m_HadronJets.clear();


  int flav;

  double HADPTCUT = 5000;
  double DRCONE = 0.4;



  for(const xAOD::TruthParticle* part: *truth_particles) {//loop truth

    int OriginFlag = part->isAvailable<int>("TopHadronOriginFlag")?part->auxdata< int >("TopHadronOriginFlag"):-1;

    if( OriginFlag==6 ) continue; //only hadrons flagged with origin at derivation level


    m_FinalHadrons[ part->index() ]=OriginFlag;

    int rest1(abs(part->pdgId()%1000));
    int rest2(abs(part->pdgId()%10000));

    if ( rest2 >= 5000 && rest2 < 6000 ) flav = 5;
    else if( rest1 >= 500 && rest1 < 600 ) flav = 5;
    else if ( rest2 >= 4000 && rest2 < 5000 ) flav = 4;
    else if( rest1 >= 400 && rest1 < 500 ) flav = 4;
    else flav = 0;


    TVector3 hadron, jet;
    hadron.SetPtEtaPhi(part->pt(),part->eta(),part->phi());

    float mindr=99;
    int bestjet=-1;
    //match closest jet in DR


    for(uint jcount=0;jcount<m_jet_pt.size();jcount++){

      jet.SetPtEtaPhi(m_jet_pt.at(jcount),m_jet_eta.at(jcount),m_jet_phi.at(jcount));

      if(jet.DeltaR(hadron) < DRCONE && jet.DeltaR(hadron) < mindr ){
	mindr = jet.DeltaR(hadron);
	bestjet = jcount;
      }

    }//loop over jets



    if(bestjet!=-1){

      m_HadronJets[ part->index() ]=bestjet;

      if((m_jet_id.at(bestjet)==0 || (OriginFlag>0 && OriginFlag>m_jet_id.at(bestjet)) || (OriginFlag<0 && m_jet_id.at(bestjet)<0 && OriginFlag<m_jet_id.at(bestjet)) ) ){

	m_jet_id.at(bestjet) = OriginFlag;

      }

      if(flav > m_jet_trueflav.at(bestjet) && part->pt() >= HADPTCUT){

	m_jet_trueflav.at(bestjet) = flav;
	m_jet_count.at(bestjet) = 1;

      }
      else if(flav == m_jet_trueflav.at(bestjet)){

	m_jet_count.at(bestjet) += 1;
      }

    }//jet chosen
  }//loop over hadrons



  double jet_ptCut =  15000;
  double jet_etaCut = 2.5;


  int b=0, B=0, c=0, C=0;
  int b_prompt=0, B_prompt=0, c_prompt=0, C_prompt=0;


  for(unsigned int i=0;i<m_jet_id.size();i++){
    if(m_jet_pt.at(i) < jet_ptCut || fabs(m_jet_eta.at(i)) > jet_etaCut) continue;
    ///count just additional HF for btype <3 while for c-type <1 and >-3///
    if(m_jet_trueflav.at(i)==5 && m_jet_id.at(i) < 3){
	if(m_jet_count.at(i) > 1){
	  B++;
	}
	else{
	  b++;
	}
      }
      if(m_jet_trueflav.at(i)==4 && (m_jet_id.at(i)==0 || m_jet_id.at(i)==-1 || m_jet_id.at(i)==-2)){
	if(m_jet_count.at(i) > 1){
	  C++;
	}
	else{
	  c++;
	}
      }

      if(m_jet_trueflav.at(i)==5 && m_jet_id.at(i)==0){

	if(m_jet_count.at(i) > 1){
	  B_prompt++;
	}
	else{
	  b_prompt++;
	}
      }
      if(m_jet_trueflav.at(i)==4 && m_jet_id.at(i)==0){
	if(m_jet_count.at(i) > 1){
	  C_prompt++;
	}
	else{
	  c_prompt++;
	}
      }


    }

    int ext_code = 1000*b+100*B+10*c+1*C;

    int prompt_code=1000*b_prompt+100*B_prompt+10*c_prompt+1*C_prompt;

    if(fabs(ext_code)==0){
      jetFilterno = -100;
    }
    if(fabs(prompt_code)==0){
      jetFilterno_prompt = -100;
    }



    ///MPI and FSR categories///

    if(prompt_code==0 && ext_code!=0){
      ext_code=0;
      for(uint ii=0; ii< m_jet_id.size(); ii++){
	if(m_jet_pt.at(ii) < jet_ptCut || fabs(m_jet_eta.at(ii)) > jet_etaCut) continue;
	if(m_jet_id.at(ii)==1 && m_jet_trueflav.at(ii)==5){ //b MPI
	  ext_code -= 1000;
	} else if(m_jet_id.at(ii)==2 && m_jet_trueflav.at(ii)==5){ //b FSR
	  ext_code -= 100;
	} else if(m_jet_id.at(ii)==-1 && m_jet_trueflav.at(ii)==4){ //c MPI
	  ext_code -= 10;
	} else if(m_jet_id.at(ii)==-2 && m_jet_trueflav.at(ii)==4) { //c FSR
	  ext_code -= 1;
	}
      }
    }


    if(fabs(ext_code)>=100){
      jetFilterno = 1;
    }
    else if(fabs(ext_code)==0){
      jetFilterno = 0;
    }
    else{
      jetFilterno =-1;
    }


    if(fabs(prompt_code)>=100){
      jetFilterno_prompt = 1;
    }
    else if(fabs(prompt_code)==0){
      jetFilterno_prompt = 0;
    }
    else{
      jetFilterno_prompt =-1;
    }




    if(doPrompt==false){ return jetFilterno;}
    if(doPrompt==true){ return jetFilterno_prompt;}


    return 0;
}


bool MCChecks::TruthTaus(asg::SgTEvent* event) // threshold in GeV
{

  bool foundFirst = false;
  bool foundSecond = false;


  const xAOD::TruthParticleContainer* truthTaus = 0;
  event->retrieve( truthTaus, "TruthTaus" );
  bool tau1 = false;
  bool tau2 = false;
  int truthpasstau = 0;
  for (unsigned int j = 0; j < truthTaus->size(); ++j){
    if ((10 == (*truthTaus)[j]->auxdata<unsigned int>("classifierParticleType"))){
      TruthTau.push_back((*truthTaus)[j]->p4()*0.001);
    }

  }
  if (foundSecond) return true;// These two lines were added to solve compilation error, not sure if they are correct.
  else return false;
}
