// replace the space in the string with "%20"

#include <iostream>
#include <string>
#include <unordered_map>
#include <limits.h>
#include <algorithm>

using namespace std;

void replace(char s[], int length){
	int numBlank = 0;
	for (int i = 0; i < length; i++){
		if (s[i] == ' '){
			numBlank++;
		}
	}
	int end = length;
	int newEnd = numBlank*2 + end;
	while (end >= 0){
		if (s[end] != ' ') { s[newEnd] = s[end]; }
		else {
			s[newEnd] = '0';
			s[--newEnd] = '2';
			s[--newEnd] = '%';
		}
		end--;
		newEnd--;
	}
}

int main(){
	char s[] = "I am happy!";
	int length = sizeof(s)/sizeof(s[0]);
	// cout << length << endl;
	replace(s,length);
	cout << s << endl;




	return 0;
}