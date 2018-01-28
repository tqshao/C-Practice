#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

class point{
public:
	point() = default;
	point(int x, int y):x(x),y(y){}
	int getX();
	int get(point p1);
	void setX(int p);
private:
	int x,y;
};

int main(){
	point p1;
	point p2(2,2);
	int a = 2;
	// auto p(a);
	string binary = bitset<8>(-12).to_string();
	 cout << p1.getX() << endl;
	// cout << binary <<endl;
	// cout << p.getX() << endl;
	return 0;
}

int point::getX(){
	return x;
}

int point::get(point p1){
	return p1.x;
}

void point::setX(int p){
	x = p;
}