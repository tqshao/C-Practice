// find the first non-repeating character in an string

#include <iostream>
#include <string>
#include <unordered_map>
#include <limits.h>
#include <algorithm>

using namespace std;

int nonRepeat(string s){
	unordered_map<char,int> m;
	for (auto str:s){
		// m[s] is initialized to 0 at the beginning.
		m[str]++;
	}
	for (int i = 0; i < s.length(); i++){
		if (m[s[i]] == 1) { return i; }
	}
}

// if the string is very long, use the following function
int nonRepeat_long(string s){
	unordered_map<char,int> m;
	for (int i = 0; i < s.length(); ++i){
		if (m.find(s[i]) == m.end()) { m[s[i]] = i; }
		else {m[s[i]] = INT_MAX; }
	}
	int ans = INT_MAX;
	for (auto& index : m){
		// ans = index.second > ans ? ans:index.second;
		ans = min(index.second,ans);
	}
	return ans == INT_MAX ? -1 : ans;
}

int main(){
	string s;
	cin >> s;
	if (nonRepeat_long(s) == -1) { cout << "No non-repeating character!" << endl; }
	else { cout << "The first non-repeating character is " <<s[nonRepeat_long(s)] << endl; }
	return 0;
}

