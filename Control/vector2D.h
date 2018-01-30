#include <cmath>

constexpr double kMathEpsilon = 1e-10;

class vector2D{
public:
	vector2D(const double x, const double y) : x_(x), y_(y){}
	vector2D() : vector2D(0,0){}
	static vector2D createUnitVector(const double angle);
	double x() const { return x_; }
	double y() const { return y_; }
	double setX(const double x) { x_ = x; }
	double setY(const double y) { y_ = y; }
	double length() const { return std::hypot(x_,y_); }
	double lengthSquare() const { return x_ * x_ + y_ * y_; } 
	double angle() const { return std::atan2(y_, x_); }
	void debugString() const;

protected:
	double x_ = 0;
	double y_ = 0;
};


