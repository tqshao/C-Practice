#include <iostream>
#include <vector>

using namespace std;

// The smallest element that is contained in v1, but not in v2
// If does not exist, return -1;
int find(vector<int> v1, vector<int> v2){
  int j = 0;
  for(int i = 0; i < v1.size(); i++){
    while(v1[i] > v2[j]) {
      j++;
    }
    if(v1[i] != v2[j]) return v1[i];
    if(j == v2.size()) return -1;

  }
  return -1;
}

int main(){
  vector<int> v1{1,3,5,7,10};
  vector<int> v2{1,2,3,5,6,7,10};
  cout << find(v1,v2) << endl;
}
