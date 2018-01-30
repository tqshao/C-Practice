#include <iostream>
using namespace std;

int fibo(int num){
	if (num <= 2) { return 1; }
	else { return fibo(num-1) + fibo(num-2); };
}

int main(){
	cout << fibo(7) <<endl;
	return 0;
}