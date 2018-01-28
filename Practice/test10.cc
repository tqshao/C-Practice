#include <iostream>

using namespace std;

// Do not move n directly because if n is a negative number,
// then if the first bit will always be 1 despite the >> operation.  
int NumOf1(int n){
	int comp = 1;
	int count = 0;
	while(comp){
		if (n & comp) { count++; }
		comp <<= 1;
	}
	return count;
}

int NumOf1_faster(int n){
	int count = 0;
	while (n){
		n = n & (n-1);
		count++;
	}
	return count;
}

int main(){
	int a;
	cin >> a;
	cout << NumOf1_faster(a) << endl;
}