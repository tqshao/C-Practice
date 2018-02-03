#ifndef _VECTOR2D_H
#define _VECTOR2D_H

#include <cmath>
#include <string>

constexpr double kMathEpsilon = 1e-10;

class vector2D{
public:
	// Constructor which takes x and y coordinates
	vector2D(const double x, const double y) : x_(x), y_(y){}
	
	// Constructor returning the zero vector
	vector2D() : vector2D(0,0){}

	// Creates a unit-vector with a given angle to the positive x semi-axis
	static vector2D createUnitVector(const double angle);
	
	// Returns the x coordinate
	double x() const { return x_; }

	// Returns the y coordinate
	double y() const { return y_; }

	// Sets x coordinate
	void setX(const double x) { x_ = x; }

	// Sets y coordinate
	void setY(const double y) { y_ = y; }

	// Returns the length of the vector
	double length() const { return std::hypot(x_,y_); }

	// Returns the squared length of the vector
	double lengthSquare() const { return x_ * x_ + y_ * y_; }

	// Returns the angle between the vector and the positive x semi-axis 
	double angle() const { return std::atan2(y_, x_); }

	// Normalize the vector 
	void normalize();

	// Output the vector information
	std::string debugString() const;

	// Returns the distance to a given vector
	double distanceTo(const vector2D& other) const;

	// Returns the squared distance to a given vector
	double distanceSquareTo(const vector2D& other) const;

	// Returns the inner product between the two vectors
	double innerProd(const vector2D& other) const;

	// Returns the cross product between the two vectors
	double crossProd(const vector2D& other) const;

	// Rotates the vector counter clockwisely by angle
	vector2D rotate(const double angle) const;	

	// Sum two vectors
	vector2D operator+(const vector2D &other) const;

	// Suvtracts two vectors
	vector2D operator-(const vector2D &other) const;

	// Multiplies this vector by a scaler
	vector2D operator*(const double ratio) const;

	// Divides this vector by a scalar
	vector2D operator/(const double ratio) const;

	// Sums another vector to this vector
	vector2D& operator+=(const vector2D &other);

	// Subtracts another vector to this vector
	vector2D& operator-=(const vector2D &other);

	// Multiplies this vector by a scalar
	vector2D& operator*=(const double ratio);

	// Divides this vector by a scalar
	vector2D& operator/=(const double ratio);

	// Compare two vectors
	bool operator==(const vector2D& other) const;

protected:
	double x_ = 0;
	double y_ = 0;
};

// Multiplies the given vector2D by a given scalar
vector2D operator*(const double ratio, const vector2D& vec);

#endif
