#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

// implement an algorithm which has the same function as pow.
// double pow(double base, int exponent)

bool equal(double num1, double num2){
	if ( (num1 - num2 < 0.0000001) && (num2 - num1 < 0.0000001) ){
		return true;
	}
	else return false;
}

double powUnsigned(double base, int exponentAbs){
	double result = 1.0;
	for (int i = 0; i < exponentAbs; i++){
		result *= base;
	}
	return result;
}

double powUnsigned_faster(double base, int exponentAbs){
	if (exponentAbs == 0) return 1;
	if(exponentAbs == 1) return base;
	double result = powUnsigned_faster(base,exponentAbs/2);
	result *= result;
	if (exponentAbs & 0x1 == 1 ) result *= base;
	else return result;
}

double pow(double base, int exponent){
	if (equal(base,0.0) && exponent <= 0){
		cout << "Error! Stupid!" << endl;
		return 0;
	}
	int exponentAbs = abs(exponent); 
	int result = powUnsigned_faster(base, exponentAbs);
	if (exponent < 0) return 1.0/result;
	else return result;
}

int main(){
	double base;
	int exponent;
	cout << "Input the base and exponent:" << endl;
	cin >> base >> exponent;
	cout << "The result is " << pow(base,exponent) << endl;
	return 0;
}
