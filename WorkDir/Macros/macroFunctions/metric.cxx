#include <iostream>
#include <vector>

using namespace std;

vector<double>metric(vector<double> a, vector<double> b){
  vector <double> Metric;
  if(a.size()==b.size())
    {
      for (unsigned int i=0;i<a.size();++i)
	{
	  Metric[i]=a[i]-b[i];
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
