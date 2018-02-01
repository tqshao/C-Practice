#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// suppose all the numbers are different
bool isOrder(vector<int> a, vector<int> b){
	stack<int> s;
	stack<int> sAssist;
	for(int i = 0; i < a.size(); i++){
		s.push(a[i]);
	}
	while(s.top() != b[0]){
		sAssist.push(s.top());
		s.pop();
		if (s.empty()) return false;
	}
	s.pop();
	int j = 1;
	while (!sAssist.empty()){
		if (sAssist.top() == b[j]){
			sAssist.pop();
			j++;
		}
		else return false;
	}
	while (!s.empty()){
		if (s.top() == b[j]){
			s.pop();
			j++;
		}
		else return false;
	}
	return true;
}

int main(){
	vector<int> a = {1,2,3,4,5};
	vector<int> b = {3,4,5,2,1};
	if (isOrder(a,b)) cout << "The order is possible." << endl;
	else cout<< "The order is not possible." << endl;
	return 0;
}
