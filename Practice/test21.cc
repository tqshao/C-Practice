#include <iostream>
#include <stack>
#include <cassert>

using namespace std;

template <typename T> class stackMin{
public:
	void push(T value);
	T pop();
	T min();
	bool empty();
private:
	stack<T> sData;
	stack<T> sMin;
};

int main(){
	stackMin<int> s;
	s.push(2.5);
	s.push(3);
	s.push(1.4);
	cout << "The min number in the stack is "  << s.min() << endl;
	s.pop();
	cout << "The min number in the stack is "  << s.min() << endl;	
	return 0;
}

template <typename T> bool stackMin<T>::empty(){
	return sData.empty();
}

template <typename T> T stackMin<T>::min(){
		assert(!sData.empty());
		return sMin.top();
}

template <typename T> void stackMin<T>::push(T value){
	if (sMin.empty()) { sMin.push(value); }
	else if (value < sMin.top()) { sMin.push(value); }
	else { sMin.push(sMin.top()); }
	sData.push(value);
}

template <typename T> T stackMin<T>::pop(){
	if (sData.empty())
		cout << "The stack is empty!" << endl;
	else{
		sData.pop();
		sMin.pop();
	}
}