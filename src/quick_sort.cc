#include <iostream>
using namespace std;

void quick_sort(int array[],int begin,int end){
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
		quick_sort(array,begin,last_small-1);
		quick_sort(array,last_small+1,end);
	}

}

int main(){
	int array[] = {1,7,4,5};
	quick_sort(array,0,3);
	for(int i = 0; i<4; i++){
		cout << array[i] << " ";
	}
	cout << endl;
	return 0;
}