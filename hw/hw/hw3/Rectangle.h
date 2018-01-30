#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include <iostream>

class Rectangle {
public:
    // default constructor that does nothing
    Rectangle();

    // initialize with upperLeft and lowerRight points
    bool twoPointsInitializer();

    // initialize with the upperLeft point and width and height value
    bool widthHeightInitializer();

    // initialize with the center point and entents
    bool centerExtentInitializer();

    RowColumnClass* getUpperLeftPoint();

    RowColumnClass* getLowerRightPoint();

private:
    static const defaultValue = -99999;
    RowColumnClass *upperLeftPoint;
    RowColumnClass *lowerRightPoint;
    bool isfilled;
};

#endif
