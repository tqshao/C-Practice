#include "vector2D.h"
#include <iostream>
#include <cmath>
#include <cassert>

const double pi = 3.1415926;

int main(){
	vector2D a(3,4);
	vector2D b(3,4);
	vector2D c = 2 * a + b;
	vector2D::createUnitVector(90*pi/180.0);
	double res = a.crossProd(b);
	// a.normalize();
	// std::cout <<  "The test result is " << res << std::endl;
	c.debugString();
	std::cout << (a == b) << std::endl;
	return 0;
}

vector2D vector2D::createUnitVector(const double angle){
	return vector2D(sin(angle), cos(angle));
}

void vector2D::debugString() const{
	std::cout << "vec2d ( x = " << x_ << ", y = " << y_ << " )" << std::endl;
}

void vector2D::normalize(){
	const double l = length();
	if (l > kMathEpsilon){
		x_ /= l;
		y_ /= l;
	} 
}

double vector2D::distanceTo(const vector2D& other) const{
	const double dx = x_ - other.x();
	const double dy = y_ - other.y();
	return std::hypot(x_ - other.x(), y_ - other.y());
}

double vector2D::distanceSquareTo(const vector2D& other) const{
	const double dx = x_ - other.x();
	const double dy = y_ - other.y();
	return dx * dx + dy * dy;
}

double vector2D::innerProd(const vector2D& other) const{
	return x_ * other.x() + y_ * other.y();
}

double vector2D::crossProd(const vector2D& other) const{
	return x_ * other.y() - y_ * other.x();
}

vector2D vector2D::rotate(const double angle) const{
	return vector2D(x_ * cos(angle) - y_ * sin(angle),
					x_ * sin(angle) + y_ * cos(angle));
}

vector2D vector2D::operator+(const vector2D &other) const{
	return vector2D(x_ + other.x(), y_ + other.y());
}

vector2D vector2D::operator-(const vector2D &other) const{
	return vector2D(x_ - other.x(), y_ - other.y());
}

vector2D vector2D::operator*(const double ratio) const{
	return vector2D(x_ * ratio, y_ * ratio);
}

vector2D vector2D::operator/(const double ratio) const{
	assert(ratio > kMathEpsilon);
	return vector2D(x_ / ratio, y_ / ratio);
}

vector2D& vector2D::operator+=(const vector2D &other){
	x_ += other.x();
	y_ += other.y();
	return *this;
}

vector2D& vector2D::operator-=(const vector2D &other){
	x_ -= other.x();
	y_ -= other.y();
	return *this;
}

vector2D& vector2D::operator*=(const double ratio){
	x_ *= ratio;
	y_ *= ratio;
	return *this;
}

vector2D& vector2D::operator/=(const double ratio){
	assert(ratio > kMathEpsilon);
	x_ /= ratio;
	y_ /= ratio;
	return *this;
}

bool vector2D::operator==(const vector2D& other) const{
	return (std::abs(x_ - other.x()) < kMathEpsilon && 
			std::abs(y_ - other.y()) < kMathEpsilon);
}

vector2D operator*(const double ratio, const vector2D& vec){
	return vector2D(ratio * vec.x(), ratio * vec.y());
}










