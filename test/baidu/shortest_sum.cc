/*
Find the Vector containing the fewest elements,
such that their sum is at least p.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print(vector<int> v){
  cout << "The result is ";
  for(int i = 0; i < v.size(); i++){
    cout << v[i] << " ";
  }
  cout << endl;
}

// max_heap: the maximum element is the root
// heap sort complexity(if know all elements) O(n)
vector<int> leastSum(vector<int> arr, int target){
  int sum = 0;
  vector<int> res;
  make_heap(arr.begin(), arr.end());
  while(sum < target){
    // cout << arr.front() << endl;
    sum += arr.front();
    res.push_back(arr.front());
    // pop_heap moves the first element in the container to the end
    pop_heap(arr.begin(), arr.end());
    arr.pop_back();
  }
  return res;
}

int main(){
  vector<int> arr = {7,14,7,3,2,5,1,4,5};
  vector<int> res = leastSum(arr, 47);
  print(res);
  return 0;
}
