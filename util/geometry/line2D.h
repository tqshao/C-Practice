#ifndef _LINE2D_H
#define _LINE2D_H

#include <cmath>
#include "vector2D.h"

// constexpr double kMathEpsilon = 1e-10;

class line2D{
public:
	// Empty constructor.
	line2D();

	// Constructor with start point and end point
	line2D(const vector2D& start, const vector2D& end);

	// Returns the start point of the line segment
	const vector2D& start() const { return start_; }

	// Returns the start point of the line segment
	const vector2D& end() const { return end_; }

	// Returns the unit direction vector from the start point to the end point
	const vector2D& unit_direction() const { return unit_direction_; }

	// Returns the center of the line segment
	vector2D center() const { return (start_ + end_) / 2; }

	// Returns the heading, which is the angle between unit direction and x-axis
	double heading() const { return heading_; }

	// Returns the cosin of the heading
	double cos_heading() const { return unit_direction_.x(); }

	// Returns the sine of the heading
	double sin_heading() const { return unit_direction_.y(); }

	// Returns the length of the line segment
	double length() const { return length_; };

	// Returns the squared length of the line segment
	double length_sqr() const {return length_ * length_; }

	// Output the line information
	std::string debugString() const;



protected:
	vector2D start_;
	vector2D end_;
	vector2D unit_direction_;
	double heading_ = 0;
	double length_ = 0;
};

#endif