#include <iostream>

using namespace std;

//0,1,1,2,3,5
int fibo_recursion(int n){
	return n < 3 ? n - 1 : fibo_recursion(n-1) + fibo_recursion(n-2);
}

int fibo_iteration(int n){
	if(n < 3) return n - 1;
	int first = 0;
	int second = 1;
	int res;
	for(int i = 0; i < n - 2; i++){
		res = first + second;
		first = second;
		second = res;
	}
	return res;
}

int main()
{
	int n;
	cout << "Type an integer: ";
	cin >> n;
	cout << "The nth element of fibo is " << fibo_iteration(n) << endl;
	return 0;
}
