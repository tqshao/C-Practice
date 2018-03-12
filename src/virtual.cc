#include <iostream>
using namespace std;

class B{
public:
	void virtual print(){
		cout << "This is base class." << endl;
	}
};

class D : public B{
public: 
	void print(){
		cout << "This is derived class." << endl;
	}
};

int main(){
	B* b;
	D d;
	b = &d;
	b->print();
	return 0;
}