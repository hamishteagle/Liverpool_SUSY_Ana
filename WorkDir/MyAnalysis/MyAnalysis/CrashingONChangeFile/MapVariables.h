#ifndef MapVariables_h
#define MapVariables_h
#include <map>
class MapVariables

{
 public:
  MapVariables(std::string mapVarFile);
  ~MapVariables(){};
  bool finder(int &datasetID, std::map<int,double>&map);
  void clearMap();
 public:
  std::map <int, double> xSecMap;
  std::map <int, double> kFacMap;
  std::map <int, double> filterEffMap;
  std::map <int, double> relUncertMap;
  std::map <int, double> SFMap;

};
#endif
