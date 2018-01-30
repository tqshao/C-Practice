#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// put all the odd numbers before the even numbers
void adjustOdd(vector<int> &a, bool (*func)(int)){
	// sort(a.begin(),a.end());
	int begin = 0;
	int end = a.size() - 1;
	while(begin < end){
		if ( func(a[begin]) ) begin++;
		else{
			int tmp = a[begin];
			a[begin] = a[end];
			a[end] = tmp;
			end--;
		}
	}
}

bool func(int num) { return (num % 2 == 1) ? true : false; }

void print(vector<int> a){
	if (a.size() == 0) {
		cout << "The vector is empty!" << endl;
		return;
	}
	for(int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << endl;
}

int main(){
	vector<int> a = {2,1,3,4,6,8,5,9};
	// vector<int> a = {};
	adjustOdd(a,func);
	print(a);

}