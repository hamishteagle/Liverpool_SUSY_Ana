#include <vector>


double length(vector <double> &a){
  double Length;
  for(unsigned int i=0;i<a.size();++i)
    {
      Length += a[i]*a[i];
    }
  return sqrt(Length);
}
