#ifndef MapVariables_h
#define MapVariables_h

class MapVariables

{
 public:
  MapVariables(std::string mapVarFile);
  double getSF(int datasetID);
  double getCrossSection(int datasetID);
  double getFilterEff(int datasetID);
  double getKFactor(int datasetID);
  double getRelUncert(int datasetID);
  bool find(int datasetID);
  
 public:
  std::map <int, double> xSecMap;
  std::map <int, double> kFacMap;
  std::map <int, double> filterEffMap;
  std::map <int, double> relUncertMap;
  std::map <int, double> SFMap;

};
#endif
