#include <cmath>
#include <string>

using namespace std;

class vector2D{
public:
	vector2D(const x,const y):x_(x), y_(y){}
	vector2D(0,0){}
	static vector2D createUnit(const double angle);
	double x() const { return x_; }
	double y() const { return y_; }
	void set_x(const double x) { x_ = x; }
	void set_y(const double y) { y_ = y; }
	double Length() const;
	double LenghtSquare() const;
	



protected:
	double x_,y_;
};

