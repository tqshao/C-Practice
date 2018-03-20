#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// hash table
vector<int> twoSum_map(vector<int> arr, int val){
	unordered_map<int,int> map;
	vector<int> res;
	for(int i = 0; i < arr.size(); i++){
		if(map.find(val - arr[i]) != map.end()){
			res.push_back(map[val-arr[i]]);
			res.push_back(i);
		}
		map[arr[i]] = i;
	}
	return res;
}

// brutal force
vector<int> twoSum_brutal(vector<int> arr, int val){
	for(int i = 0; i < arr.size() - 1; i++){
		for(int j = i + 1; j < arr.size(); j++){
			if(arr[i] + arr[j] == val)
				return vector<int>{i,j};
		}
	}
}

// if the array is sorted
vector<int> twoSum_pointer(vector<int> arr, int val){
	int start = 0;
	int end = arr.size() - 1;
	int sum;
	sort(arr.begin(),arr.end());
	while(start < end){
		int sum = arr[start] + arr[end];
		if(sum == val) return vector<int>{start,end};
		else if(sum > val) end--;
		else start++;
	}
	return vector<int>();
}

int main(){
	int arr[] = {1,2,3,15,4,6,7};
	vector<int> a(arr,arr + sizeof(arr)/sizeof(int));
	vector<int> sum = twoSum_brutal(a,16);
	cout<< sum[0] << " and " << sum[1] << endl;
	return 0;
}
