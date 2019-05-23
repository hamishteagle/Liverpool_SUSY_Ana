include <vector>

using namespace std;


vector <double> subract(const vector <double> &a, const vector <double> &b){
  vector <double>  result;
  for (unsigned int i=0;i<a.size();++i)
    {
      result.push_back(a[i]-b[i]);
    }
  return result;

}
  
