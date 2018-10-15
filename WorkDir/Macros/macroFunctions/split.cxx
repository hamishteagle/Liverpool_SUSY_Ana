#include <sstream>
#include <string>
#include <iostream>

using namespace std;

//Function to split a string by a delimeter (and convert string pieces to double)




std::string myreplace(std::string &s,const std::string &toReplace,const std::string &replaceWith)
{
  return(s.replace(s.find(toReplace), toReplace.length(), replaceWith));
}


std::vector<std::string> split(const string& s,char* delim){

  
  istringstream ss(s);
  
  string piece;
  char deliminator=*delim;
  vector <string>pieces;
  unsigned int  skip_it=0;
  while (getline(ss, piece, deliminator)){
    skip_it++;
    if(skip_it>5 && skip_it<9)
      {
	if (piece.find(".merge.DAOD") != std::string::npos) 
	  {
	    myreplace(piece,".merge.DAOD","");
	  }
	pieces.push_back(piece);
      }
  }
  return pieces;
}
