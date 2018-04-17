#include <string>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include "MyAnalysis/AddPileUp.h"

AddPileUp::AddPileUp(){}


void AddPileUp::ReturnPileUpFilesVector(std::string dir, std::vector<std::string> &files ){
  
  
  DIR *dp;
  struct dirent *dirp;
  if((dp  = opendir(dir.c_str())) == NULL) {
    std::cout << "Error(" << errno << ") opening " << dir << std::endl;
    return;
  }
  
  while ((dirp = readdir(dp)) != NULL) {
    //std::cout << "Adding pile up file: " << std::string(dirp->d_name)<< std::endl;
    if (std::string(dirp->d_name) == "." || std::string(dirp->d_name) == ".." || std::string(dirp->d_name) == "361060.root" || std::string(dirp->d_name) == "361059.root" || std::string(dirp->d_name) == "361078.root" || std::string(dirp->d_name) == "361079.root" || std::string(dirp->d_name) == "361080.root"){
      std::cout << "Don't add  " << std::string(dirp->d_name)<< " to the pile up reweighting" <<std::endl;
    }
    else{
      files.push_back(dir + std::string(dirp->d_name));
  
    }
  }
  closedir(dp);
  return ;
}

