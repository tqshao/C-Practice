// find the common elements in K sorted arrays
#include<iostream>
#include<vector>

using namespace std;

void print(vector<int> v){
  cout << "The result is ";
  for(int i = 0; i < v.size(); i++){
    cout << v[i] << " ";
  }
  cout << endl;
}

// find the common elements in two sorted arrays
vector<int> helper(vector<int> arr1, vector<int> arr2){
  vector<int> res;
  int i = 0;
  int j = 0;
  while(i < arr1.size() && j < arr2.size()){
    if(arr1[i] == arr2[j]){
      res.push_back(arr1[i]);
      i++;
      j++;
    }
    while(arr1[i] < arr2[j]) i++;
    while(arr1[i] > arr2[j]) j++;
  }
  return res;
}

vector<int> findCommon(vector<vector<int>> arr){
  vector<int> res = arr[0];
  for(int i = 1; i < arr.size(); i++){
    res = helper(arr[i], res);
  }
  return res;
}


int main(){
  vector<vector<int>> arr = {{1,3,4,5,7,9,12},
                     {2,3,5,6,8,9,100000},
                     {2,3,4,5,6,7,8,9}};
  cout << "Start computing..." << endl;
  vector<int> res = findCommon(arr);
  print(res);
  return 0;
}
