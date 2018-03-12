#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int> &array,int begin,int end){
	if (end>begin){
		int pivot = begin;
		int last_small = begin;
		int i = end;
		while (last_small != i){
			if(array[i] <= array[pivot]){
				// exchange array[++last_small] with array[i]
				int temp = array[i];
				array[i] = array[++last_small];
				array[last_small] = temp;
			}
			else { i--; }
		}
		// exchange array[pivot] with array[last_small]
		int tmp = array[pivot];
		array[pivot] = array[last_small];	
		array[last_small] = tmp;
		quickSort(array,begin,last_small-1);
		quickSort(array,last_small+1,end);
	}

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
	vector<int> a = {1,4,3,2,1,1,3,2,3,4,4};
	// quickSort(a,0,3);
	bucketSort(a);
	print(a);
	return 0;
}

