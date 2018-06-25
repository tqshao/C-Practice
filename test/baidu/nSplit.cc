#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

double length(pair<double,double> v1,
              pair<double,double> v2){
  double dx = v1.first - v2.first;
  double dy = v1.second - v2.second;
  return sqrt(dx*dx + dy*dy);
}

vector<pair<double,double>> nSplit(vector<pair<double,double>> v, int n){
  vector<pair<double,double>> res;
  int num = v.size();
  vector<double> segmentLen;
  for(int i = 0; i < num - 1; i++){
    segmentLen.push_back(length(v[i], v[i+1]));
  }
  double sum = 0;
  for(int i = 0; i < segmentLen.size(); i++){
    sum += segmentLen[i];
  }
  int j = 0;
  double accLen = 0;
  for(int i = 1; i < n; i++){
    double targetLen = sum/n*i;
    while(accLen < targetLen){
      accLen += length(v[j], v[j+1]);
      j++;
    //  cout << "target: " <<  targetLen << " " << accLen << endl;
    }
    double ratio = (accLen - targetLen)/length(v[j], v[j-1]); // back to front
    double x = v[j].first - ratio * (v[j].first - v[j-1].first);
    double y = v[j].second - ratio * (v[j].second - v[j-1].second);
    pair<double,double> point(x,y);
    res.push_back(point);
  }
  return res;
}

void print(vector<pair<double,double>> v){
  for(int i = 0; i< v.size(); i++){
    cout << v[i].first << " " << v[i].second << endl;
  }
}

int main(){
  vector<pair<double,double>> v = {pair<double, double>(1.0, 2.0),
                                   pair<double, double>(1.0, 7.0),
                                   pair<double, double>(4.0, 7.0)};
  cout << "Original points: " << endl;
  print(v);
  int n = 3;
  vector<pair<double,double>> res = nSplit(v,n);
  cout << "Points after ""n splits: " << endl;
  print(res);
  // cout << length(v[0], v[1]) << endl;
  return 0;
}
