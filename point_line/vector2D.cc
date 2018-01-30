#include "point.h"
#include <cmath>

using namespace std;

double vector2D::Length() { return sqrt(x_ * x_ + y_ * y_); }

double vector2D::LengthSquare() { return x_ * x_ + y_ * y_; }


