#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> twoSum(vector<int> arr, int val){
	map<int,int> map_sum;
	vector<int> sum;
	for (int i = 0; i<arr.size(); ++i){
		map_sum[arr[i]] = i;
		if( i>0 && map_sum.find(val-arr[i])!=map_sum.end() ){
			//cout << map_sum.find(val-arr[i]) << endl;
			sum.push_back(arr[i]);
			sum.push_back(val - arr[i]);
			return sum;
		}
	}
}

int main(){
	int arr[] = {1,2,3,4,15,6,7};
	vector<int> a(arr,arr + sizeof(arr)/sizeof(int));
	vector<int> sum = twoSum(a,22);
	cout<< sum[0] << " and " << sum[1] << endl;	
	return 0;
}