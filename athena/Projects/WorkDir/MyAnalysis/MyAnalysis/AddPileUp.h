// Initial Selections go here

#ifndef AddPileUp_h
#define AddPileUp_h

#include <string>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>

class AddPileUp{

    
  public:
  AddPileUp();
  
  void ReturnPileUpFilesVector(std::string dir, std::vector<std::string> &files);
    
  };

#endif
