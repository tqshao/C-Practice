#include <iostream>

using namespace std;

//0,1,1,2,3
int fibo(int n){
	if(n<=0) return 0;
	else if(n == 2) return 1;
	else{
		int fibo;
		int first = 1;
		int second = 0;
		for (int i = 0; i < n-2; i++){
			fibo = first + second;
			second = first;
			first = fibo;
		}
		return fibo;
	}
}

int main()
{
	int n;
	cin >> n;
	cout << "The nth element of fibo is " << fibo(n) << endl;
	return 0;
}