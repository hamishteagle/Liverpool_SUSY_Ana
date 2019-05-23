#include <vector>
#include <string>

using namespace std;


class macroFunctions {
 private:

 public:
  vector <double> metric(const vector<double> &a, const vector<double> &b) const;
  vector <double> subtract(const vector<double> &a, const vector<double> &b) const;
  double length(const vector<double> &a)const;
  vector <double> scale(const vector <double> &a, double s)const;
  void Print(const vector <double> &a);
  vector <string> fileReader(string inputstring);
};
  
