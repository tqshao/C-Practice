#include <iostream>
#include <vector>
using namespace std;

class test{
public:
	test(int var_ = 0):var(var_){
		cout << "Constructor called" << endl;
	}

	int get(){
		return var;
	}

	~test(){
		cout << "Destructor called" << endl;
	}

private:
	int var;
};

int main(){
	test* a = new test(1);
	if(1){
		delete a;
		test* a = new test(2);	
	}

	cout << "The variable in a is " << a->get() <<endl;
	cout << "The variable in origin a is " << copy->get() <<endl;
}