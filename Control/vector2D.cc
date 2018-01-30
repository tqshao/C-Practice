#include "vector2D.h"
#include <iostream>
#include <cmath>

const double pi = 3.1415926;

int main(){
	vector2D a(3,4);
	vector2D::createUnitVector(90*pi/180.0);
	a.debugString();
	std::cout << a.angle() * 180 / pi << std::endl;
	return 0;
}

vector2D vector2D::createUnitVector(const double angle){
	return vector2D(sin(angle), cos(angle));
}

void vector2D::debugString() const{
	std::cout << "vec2d ( x = " << x_ << ", y = " << y_ << " )" << std::endl;
}

