#include "line2D.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

line2D::line2D(const vector2D& start, const vector2D& end)
	:start_(start), end_(end) {
		const double dx = end_.x() - start_.x();
		const double dy = end_.y() - start_.y();
		length_ = hypot(dx, dy);
		unit_direction_ = (length_ <= kMathEpsilon ? vector2D(0,0)
		: vector2D(dx / length_, dy / length_));
		heading_ = unit_direction_.angle();
	}


std::string line2D::debugString() const{
	const vector2D startS = this -> start();
	std::string s = "line2D ( start = " + startS.debugString()
				           + ", end = " + end_.debugString() + " )";
	return s;
}

