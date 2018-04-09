// Initial Selections go here

#ifndef PreliminarySel_h
#define PreliminarySel_h


#include "CalculateVariables.h"
#include <iostream>
#include <string>
class PreliminarySel


{


 public:
  PreliminarySel(CalculateVariables &objects);
  
  bool whichPreliminaryRegion(CalculateVariables &variables);


 public:

  std::string region;
  bool interestingRegion;

};
#endif
