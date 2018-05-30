// interpolation of segments, assume x is in ascending order.
#include <iostream>
#include <vector>

using namespace std;

double interpolation(vector<double> x, vector<double> y, double val, bool extra){
  // if val is smaller than min, use interpolation of the first two points
  int num = x.size();
  if (val < x[0]){
    return y[0] + (val - x[0]) / (x[1] - x[1]) * (y[1] - y[0]);
  }
  for (int i = 1; i < num; i++){
    if (val < x[i]){
      return y[i-1] + (val - x[i-1]) / (x[i] - x[i-1]) * (y[i] - y[i-1]);
    }
    else break;
  }
  return y[num-2] + (val - x[num-2]) / (x[num-1] - x[num-2]) * (y[num-1] - y[num-2]);
}

int main(){
  vector<double> x = {1.0, 2.0, 3.0};
  vector<double> y = {2.0, 4.0, 6.0};
  double val = 1.5;
  double res = interpolation(x, y, val, true);
  cout << "The interpolation result is " << res << endl;

  return 0;
}
