#include <iostream>
#include <stack>
#include <stdexcept>

using namespace std;

template <typename T> class CQueue{
public:
	// CQueue();
	// ~CQueue();

	void appendTail(const T& node){
		stack1.push(node);
	}

	T deleteHead(){
		oldest();
		
		if(stack2.empty()){
			throw runtime_error("queque is empty!"); 
		}
		stack2.pop();
	}

	int oldest(){
		if (stack2.empty()){
			while (!stack1.empty()){
				stack2.push(stack1.top());
				stack1.pop();
				// cout << "move " << endl;
			}
		}

	}

	void print(){
		oldest();
		if(stack2.empty()){
			throw runtime_error("queque is empty!"); 
		}
		cout << "The oldest element of the queue is "
		<< stack2.top() << endl;
	}

private:
	stack<T> stack1;
	stack<T> stack2;
	int topNum;
};

int main(){
	CQueue<int> a;
	a.appendTail(1);
	a.appendTail(2);
	a.appendTail(3);
	a.appendTail(4);
	a.deleteHead();
	a.print();
	return 0;
}




