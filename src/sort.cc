#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &arr){
	int size = arr.size();
	for(int i = 0; i < size - 1; i++){
		for(int j = i + 1; j < size; j++){
			if(arr[i] > arr[j]){
				int tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
	}
}

void quickSort(vector<int> &arr,int begin,int end){
	if(end > begin){
		int pivot = begin;
		int change = begin;
		int i = end;
		while(change < i){
			if(arr[i] >= arr[pivot]) i--;
			else{
				change++;
				// exchange [change] with [end]
				int tmp = arr[change];
				arr[change] = arr[i];
				arr[i] = tmp;
			}
		}
		// exchange [pivot] with [change]
		int tmp = arr[pivot];
		arr[pivot] = arr[change];
		arr[change] = tmp;
		quickSort(arr, begin, change - 1);
		quickSort(arr, change + 1, end);
	}
	return;
}

void bucketSort(vector<int> &array){
	vector<int> bucket(10);
	for (int i = 0; i<array.size(); i++){
		bucket[array[i]] = bucket[array[i]]+1;
	}
	int index = 0;
	for (int i = 0; i<bucket.size(); i++){
		for (int j = 0; j<bucket[i]; j++){
			array[index++] = i;
		}
	}
}

 void print(vector<int> a){
	for (int i = 0; i < a.size(); i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

int main(){
	vector<int> a = {1,4,3,2,1,5,1,3,2,3,4,4};
	// quickSort(a,0,3);
	// quickSort(a,0, a.size() - 1);
	bubbleSort(a);
	print(a);
	return 0;
}
