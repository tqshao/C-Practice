// #################################
//
// Binary search function
// compare the absolute value of error
// 
//###################################

#include <iostream>
#include <math.h>
using namespace std;

double binary_search(double err_lim, double num){
	double left,right,middle, err;
	left = 0;
	right = num;
	err = 100.0;
	while (fabs(left-right) > 0.0001 ){
		middle = (left + right) / 2.0;
		err = middle * middle - num;
		if (err > 0) { right = middle; }
		else { left = middle; }
		// cout<< left << " " << right << " " << err << endl;
	}
	return middle;
}

int main(){
	cout << binary_search(0.01, 2) << endl;
	return 0;
}