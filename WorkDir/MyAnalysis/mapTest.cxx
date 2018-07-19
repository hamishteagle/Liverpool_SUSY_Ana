#include <iostream>

double getCrossSection(int datasetID){
  std::map<int, double> myMap;
  myMap[300000] = 1.4;
  myMap[300001] = 1.5;

  return myMap[datasetID];
}

double getFilterEff(int datasetID){
  std::map<int, double> myMap;
  myMap[300000] = 0.2;
  myMap[300001] = 0.1;

  return myMap[datasetID];
}

double getKFactor(int datasetID){
  std::map<int, double> myMap;
  myMap[300000] = 0.8;
  myMap[300001] = 0.9;

  return myMap[datasetID];
}

int mapTest(){

  int datasetID = 300000;

  double xSec = getCrossSection(datasetID);
  double filterEff = getFilterEff(datasetID);
  double kFactor = getKFactor(datasetID);

  std::cout << xSec << ", " << filterEff << ", " << kFactor << std::endl; 

  return 0;
}
