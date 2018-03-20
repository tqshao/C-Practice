// #################################
//
// Binary search function
// compare the absolute value of error
//
//###################################

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

// solve for square(num)
double square(double num){
	double error = 0.00001;
	double left = 0.0;
	double right = num;
	double middle = 0.0;
	while(fabs(middle*middle-num)>0.00001*0.00001){
		middle = (left + right) / 2;
		if(middle*middle > num) right = middle;
		else left = middle;
	}
	return middle;
}

// find the index of the upper boundary of a value in a sorted array
int upper_boundary(vector<int> v, int val){
	int left = 0;
	int right = v.size();
	int middle = 0;
	while(left < right){
		middle = (left + right + 1) / 2;
		if (v[middle] > val) right = middle - 1;
		else left = middle;
	}
	return left;
}

// find the index of the lower boundary of a value in a sorted array
int lower_boundary(vector<int> v, int val){
	int left = 0;
	int right = v.size() - 1;
	int middle = 0;
	while(left < right){
		middle = (left + right) / 2;
		if(v[middle] < val) left = middle + 1;
		else right = middle;
	}
	return left;
}

int main(){
	// cout << square(2) << endl;
	vector<int> v{1,2,2,3,4,5,7,7,7,7};
	cout << upper_boundary(v,7) << endl;
	return 0;
}
