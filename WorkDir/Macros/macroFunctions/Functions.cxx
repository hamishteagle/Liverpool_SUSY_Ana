#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "macroFunctions.h"
using namespace std;



std::vector<std::string> macroFunctions::fileReader(string inputString)    //Input file is passed to the function, i.e. "Test.txt"
{
  std::string Filename = inputString;
  std::ifstream input(Filename, std::ios::binary | ios::in);  // Open the file
  std::string line;                                           // Temp variable
  std::vector<std::string> lines;                             // Vector for holding all lines in the file
  while (std::getline(input, line))                           // Read lines as long as the file is
    {
      lines.push_back(line);                                   // Save the line in the vector
    }
  return lines;
}

double macroFunctions::length(vector <double> &a)const{
  double Length;
  for(unsigned int i=0;i<a.size();++i)
    {
      Length += a[i]*a[i];
    }
  return sqrt(Length);
}

vector<double> macroFunctions::metric(vector<double> a, vector<double> b)const{
  vector <double> Metric;
  if(a.size()==b.size)
    {
      for (unsignedint i=0;i<a.size();++i)
	{
	  Metric.push_back(a[i]-b[i]);
	 }
      return Metric;
    }
  else
    {
      cout<<"The vectors given have different sizes"<<endl;
      Metric[0]=1;
      return Metric;
    }
}
vector <double> macroFunctions::subract(const vector <double> &a, const vector <double> &b)const{
  vector <double>  result;
  if (a.size()==b.size())
    {
      for (unsigned int i=0;i<a.size();++i)
	{
	  result.push_back(a[i]-b[i]);
	}
      return result;
    }
  else
    {
      cout<<"The vectors given have different sizes"<<endl;                                                           
      result[0]=1;                                                                                                  
      return result; 
    }
}
vector <double> macroFunctions::scale(const vector <double> &a, double s){
  vector <double> result;
  for (unsigned int i=0;i<a.size()<++i)
    {
      result.push_back(s*a[i]);
    }
  return result;
}
double macroFunctions::scalarProduct(const vector <double> &a, const vector<double> &b)const;{
  double result;
if (a.size()==b.size())
    {
      for (unsigned int i=0;i<a.size();++i)
	{
	  result+=(a[i]*b[i]);
	}
      return result;
    }
  else
    {
      cout<<"The vectors given have different sizes"<<endl;                                                           
      result=1;                                                                                                  
      return result; 
    }
}
vector <double> macroFunctions::scale(vector <double> &a, double s);
{
  vector <double> result;
  for (unsigned int i=0;i<a.size();++i)
    {
      
      
    }
}
void Print(vector <double> &a){
  
  for (unsigned int i=0;i<a.size();i++)
    {
      cout<<a[i]<<","<<endl;
    }
}
