#include <iostream>
using namespace std;

class point{
public:
	point();
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
	cout << p1.get(p2) << endl;
	return 0;
}

point::point(){
	x = 0;
	y = 0;
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