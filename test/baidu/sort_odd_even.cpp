// Put all even numbers before odd numbers in the array
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sort(vector<int> &vec){
  int pivot = 0;
  int num = vec.size();
  int tmp;
  for(int i = 0; i < num; i++){
    if(vec[i]%2 == 0){
      tmp = vec[i];
      vec[i] = vec[pivot];
      vec[pivot] = tmp;
      pivot++;
    }
  }
}

void sort_2(vector<int> &vec){
  int start = 0;
  int end = vec.size() - 1;
  while(start < end){
    if(vec[start]%2 == 1){
      int tmp = vec[start];
      vec[start] = vec[end];
      vec[end] = tmp;
      end--;
    }
    else start++;
  }
}


int main(){
  vector<int> vec = {1,2,3,4,8,12,7,5,9,35,88,6};
  sort_2(vec);
  for(int i = 0; i < vec.size(); i++){
    cout << vec[i] << " ";
  }
  cout << endl;
  return 0;
}
