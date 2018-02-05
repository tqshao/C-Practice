#include "vector2D.h"
#include "line2D.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main(){
	/*
	vector2D a(3,4);
	vector2D b(3,4);
	vector2D c = 2 * a + b;
	vector2D::createUnitVector(90*pi/180.0);
	double res = a.crossProd(b);
	// a.normalize();
	// std::cout <<  "The test result is " << res << std::endl;
	std::cout << c.debugString() << std::endl;
	std::cout << (a == b) << std::endl;
	*/
	vector2D v1(1,1);
	vector2D v2(3,3);
	line2D l(v1,v2);
	cout << l.debugString() << endl;
	cout << l.sin_heading() << " " << l.cos_heading() << endl;
	return 0;
}