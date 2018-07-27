#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
#include "MyAnalysis/MapVariables.h"
//Class to convert text file in format; line by line=DSID, SF, Xsec, Kfactor, FilterEff, Rel.uncertainty 
//into maps mapping each DSID to each attribute
  using namespace std;

MapVariables::MapVariables (std::string mapVarFile) {

  
  vector<double> mapValues ={0};
  ifstream file;
  file.open(mapVarFile);
  string inputline;
  while(getline(file, inputline)){
    //  cout<<"Line = "<<inputline<<endl;
    istringstream iss(inputline);
    copy(istream_iterator<double>(iss),
	 istream_iterator<double>(),
	 back_inserter(mapValues));
    //    cout<<"mapValues= "<<mapValues[0]<<","<<mapValues[1]<<","<<mapValues[2]<<","<<endl;    

    xSecMap[mapValues[0]] = mapValues[1];
    kFacMap[mapValues[0]] = mapValues[2];
    filterEffMap[mapValues[0]] = mapValues[3];
    relUncertMap[mapValues[0]] = mapValues[4];
    mapValues.clear();
  }
}
  
  //Functions to return the attributes of each DSID
double  MapVariables::getCrossSection(int datasetID){
  //cout<<xSecMap[datasetID]<<endl;
    return xSecMap[datasetID];
  }
  
double  MapVariables::getFilterEff(int datasetID){
  // cout<<filterEffMap[datasetID]<<endl;
    return filterEffMap[datasetID];
  }
  
double  MapVariables::getKFactor(int datasetID){
  //cout<<kFacMap[datasetID]<<endl;
    return kFacMap[datasetID];
  }
double  MapVariables::getRelUncert(int datasetID){
  // cout<<relUncertMap[datasetID]<<endl;
    return relUncertMap[datasetID];
  }
  
bool MapVariables::find(int datasetID){
  std::map<int, double>::iterator it; 
  it = xSecMap.find(datasetID);
  if (it != xSecMap.end()) return true;
  else return false;
}
  


