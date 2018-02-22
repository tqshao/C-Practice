/*
for test confilct issues
*/
#include <iostream>
#include <cstring>
using namespace std;



class MyString{
public:
	MyString(char* pData_ = NULL){
		pData = new char[strlen(pData_) + 1];
		strcpy(pData,pData_);
		}

	MyString(const MyString& str){
		pData = new char[strlen(str.pData) + 1];
		strcpy(pData,str.pData);
		}

	~MyString(void){
		delete[] pData;
	}

	void print_length(){
		cout << "The length of " << pData << " is " << strlen(pData) << endl;
	}

	void print(){
		cout << pData << endl;
	}
	MyString& operator=(const MyString& str){
		if (this == &str) { return *this; }
		delete[] pData;
		// pData = NULL;
		pData = new char[strlen(str.pData) + 1];
		strcpy(pData,str.pData);
		return *this;
	} 
private:
	char* pData;
};

int main(){
	MyString a("First");
	MyString b("Second");
	b.print();
	b.print_length();
	b = a;
	b.print();
	return 0;
}
