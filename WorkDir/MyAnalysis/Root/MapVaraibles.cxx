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

    xSecMap[mapValues[0]] = mapValues[1];
    kFacMap[mapValues[0]] = mapValues[2];
    filterEffMap[mapValues[0]] = mapValues[3];
    relUncertMap[mapValues[0]] = mapValues[4];
    mapValues.clear();
  }
}

bool MapVariables::finder(int &datasetID, map<int,double>&map){
  std::map<int, double>::iterator it; 
  it = map.find(datasetID);
  if (it != map.end()) return true;
  else return false;
}

void MapVariables::clearMap(){
  xSecMap.clear();
  filterEffMap.clear();
  kFacMap.clear();
  relUncertMap.clear();
}

