#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> top_k(vector<double> vec, int k){
  priority_queue<pair<double,int>> q;
  for(int i = 0; i < vec.size(); i++){
    q.push(pair<double,int>(vec[i], i));
  }
  vector<int> res;
  for(int i = 0; i < k; i++){
    res.push_back(q.top().second);
    q.pop();
  }
  return res;
}

int main(){
  vector<double> vec = {1.0, -1.2, .37, 5.6, 0};
  int k = 3;
  vector<int> res = top_k(vec, k);
  for(int i = 0; i < k; i++){
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}
