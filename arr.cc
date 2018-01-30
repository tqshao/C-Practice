#include <iostream>
#include <string.h>

using namespace std;

int main(){
	char *a = "hello";

	int b[] = {1,2,3};
	int* p = b;
	p++;

	cout << strlen(a) << endl;

	return 0;
}