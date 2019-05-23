#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

//Function to read a text file line by line 
std::vector<std::string> fileReader(const string inputString)     //Input file is passed to the function, i.e. "Test.txt"
{


  std::ifstream input;
  input.open(inputString.c_str());
  
  if(input.is_open())
    {
      std::string line;                                           // Temp variable
      std::vector<std::string> lines;                             // Vector for holding all lines in the file
      while (std::getline(input, line))                           // Read lines as long as the file is
	{
	  lines.push_back(line);                                   // Save the line in the vector
	}
      return lines;
    }
  else
    {
      std::vector<string> Null;
      Null.push_back("0");
      cout<<"Couldn't open input file"<<endl;
      //      return Null;
    }
}

