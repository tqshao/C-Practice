#include <iostream>
#include <vector>

using namespace std;

int Min(vector<int> a){
	int begin = 0;
	int end = a.size() - 1;
	int middle = (begin + end) / 2;
	while(begin < end-1){
		if (a[middle] == a[begin]){
			while( end >= begin){
				if (a[begin] < a[middle])
					return a[begin];
				else begin++;
			}
			return a[middle];
		}
		if (a[middle] > a[begin])
			begin = middle;
		else end = middle;
		middle = (begin + end) / 2;
		cout << begin << " " << end << endl;
	}
	return a[begin] < a[end] ? a[begin] : a[end];
} 



int main(){
	vector<int> a = {1,1,0,1,1,1};
	cout << Min(a) << endl;
	return 0;
}




