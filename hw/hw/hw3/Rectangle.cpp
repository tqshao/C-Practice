#include "Rectangle.h"

Rectangle::Rectangle() {}


void Rectangle::initialize() {
    Rectangle::initBoundary();
    Rectangle::initColor();
    Rectangle::initFillOption();
}    


void Rectangle::initBoundary() {


    int* bbox = Rectangle::initBoundaryHelper(selection);
    upperLeftPoint = new RowColumnClass(bbox[0], bbox[1]);
    lowerRightPoint = new RowColumnClass(bbox[2], bbox[3]);
}


int* Rectangle::initBoundaryHelper(int selection) {
   
    else if (selection == 2) {

    } else {
        int centerRow = 0, centerCol = 0, halfRow = 0, halfCol = 0;
        cout << "Enter rectangle center row and column: ";
        cin >> centerRow >> centerCol;
        cout << "Enter int for half number of rows: ";
        cin >> halfRow;
        cout << "Enter int for half number of columns: ";
        cin >> halfColumn;
        while (cin.fail() || centerRow 

        



// initialize with upperLeft and lowerRight points
void Rectangle::twoPointsInitializer() {
    
    

    

    // read the color of the rectangle from user input
    

    // read the fill option from user input
    
    }

// initialize with the upperLeft point and width and height value
void Rectangle::widthHeightInitializer();

// initialize with the center point and entents
void Rectangle::centerExtentInitializer();

RowColumnClass* getUpperLeftPoint();

RowColumnClass* getLowerRightPoint();

