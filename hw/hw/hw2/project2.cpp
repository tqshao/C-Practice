// Student: Shiyang Lu
// Email: shiyoung@umich.edu
// Last modified date: 10/15/2017
// Overview: This is the second project of EECS402. In this project, three 
// major classes are designed(ColorClass, RowColumnClass and ColorImageClass).
// The purpose of this project is to make us have a taste of OOP.

#include <iostream>
using namespace std;

class ColorClass {
public:
    // default constructor that set the color to full white
    ColorClass();

    // value constructor that set the color to provided RGB values
    ColorClass(int inRed, int inGreen, int inBlue);

    // set the color to black(i.e. min, min, min)
    void setToBlack();

    // set the color to red(i.e. max, max, max)
    void setToRed();

    // set the color to green(i.e. min, max, min)
    void setToGreen();

    // set the color to blue(i.e. min, min, max)
    void setToBlue();

    // set the color to white(i.e. max, max, max)
    void setToWhite();

    // set the color to the provided RGB values. If need clipping, return true
    bool setTo(int inRed, int inGreen, int inBlue);

    // set the color to the given color. If need clipping, return true
    bool setTo(ColorClass &inColor);

    // add the rhs's RGB value to the current color object, the added value 
    // should still be in the allowed range. If need clipping return true
    bool addColor(ColorClass &rhs);

    // deduct the rhs's RGB value from the current color object, the deducted 
    // value should still be in the allowed range. If need clipping return true
    bool subtractColor(ColorClass &rhs);

    // adjust brightness of the color by a factor. If need clipping return true
    bool adjustBrightness(double adjFactor);

    // print the color in the following format: "R: <red> G: <green> B: <blue>"
    void printComponentValues();

private:
    int redValue;
    int greenValue;
    int blueValue;

    // helper function that return the clipped value
    int setColor(int colorValue);

    // helper function that check whether a color value is in the allowed range
    bool colorInBound(int colorValue);

    static const int MIN_COLOR_VALUE = 0;
    static const int MAX_COLOR_VALUE = 1000;
};


class RowColumnClass {
public:
    // default constructor that set row and column attributes to DEFAULT_VALUE
    RowColumnClass();

    // value constructor that set row and column attributes to given value
    RowColumnClass(int inRow, int inCol);

    // set row and column attributes with the provided value
    void setRowCol(int inRow, int inCol);

    // set the row attribute to the given value
    void setRow(int inRow);

    // set the column attributes to the given value
    void setCol(int inCol);

    // get the row attribute
    int getRow();

    // get the column attribute
    int getCol();

    // adds the row and column index values in the input parameter to the row 
    // and column index of the object the function is called on
    void addRowColTo(RowColumnClass &inRowCol);

    // print the attributes of the object in the format of "[<row>,<col>]"
    void printRowCol();

private:
    int row;
    int col;
    static const int DEFAULT_VALUE = -99999;
};


class ColorImageClass {
public:
    // default constructor creates a 2d array of ColorClass object with default 
    // row and column size, and sets all pixels in the image to full black
    ColorImageClass();

    // initialize all image pixels to the given color
    void initializeTo(ColorClass &inColor);

    // add color value of each pixel in the input image to the corresponding
    // pixels of the current image. If need clipping, return true
    bool addImageTo(ColorImageClass &rhsImg);

    // add up all the color value of each pixel in the input images and assign
    // the value to the corresponding pixel in the current object. If need 
    // clipping, return true
    bool addImages(int numImgsToAdd, ColorImageClass imagesToAdd[]);

    // set the pixel at the given row and column to the input color. If the
    // input row and column is out of bounds, return false
    bool setColorAtLocation(RowColumnClass &inRowCol, ColorClass &inColor);

    // If the row/column provided is a valid row/column for the image, this 
    // function returns true and the output parameter "outColor" is assigned 
    // to the color of the image pixel at that location.
    bool getColorAtLocation(RowColumnClass &inRowCol, ColorClass &outColor);

    // The image is printed one row of pixels per line. Between each pixel in a
    // row, two dashes are printed (i.e. ¡°--") in order to separate the values
    // visually for easier understanding by the end user.
    void printImage();

private:
    static const int DEFAULT_ROW_LEN = 10;
    static const int DEFAULT_COL_LEN = 18;
    ColorClass pixels[DEFAULT_ROW_LEN][DEFAULT_COL_LEN];

    // check if the row and column is out of bound, return true if out of bound
    bool outOfBounds(RowColumnClass &inRowCol);
};


#ifdef ANDREW_TEST
#include "andrewTest.h"
#else
int main() {
    ColorClass testColor;
    RowColumnClass testRowCol;
    RowColumnClass testRowColOther(111, 222);
    ColorImageClass testImage;
    ColorImageClass testImages[3];
  
    //Test some basic ColorClass operations...
    cout << "Initial: ";
    testColor.printComponentValues();
    cout << endl;
  
    testColor.setToBlack();
    cout << "Black: ";
    testColor.printComponentValues();
    cout << endl;
  
    testColor.setToGreen();
    cout << "Green: ";
    testColor.printComponentValues();
    cout << endl;
  
    testColor.adjustBrightness(0.5);
    cout << "Dimmer Green: ";
    testColor.printComponentValues();
    cout << endl;
  
    //Test some basic RowColumnClass operations...
    cout << "Want defaults: ";
    testRowCol.printRowCol();
    cout << endl;
  
    testRowCol.setRowCol(2, 8);
    cout << "Want 2,8: ";
    testRowCol.printRowCol();
    cout << endl;
  
    cout << "Want 111, 222: ";
    testRowColOther.printRowCol();
    cout << endl;
  
    testRowColOther.setRowCol(4, 2);
    testRowCol.addRowColTo(testRowColOther);
    cout << "Want 6,10: ";
    testRowCol.printRowCol();
    cout << endl;
  
    //Test some basic ColorImageClass operations...
    testColor.setToRed();
    testImage.initializeTo(testColor);
  
    testRowCol.setRowCol(555, 5);
    cout << "Want: Color at [555,5]: Invalid Index!" << endl;
    cout << "Color at ";
    testRowCol.printRowCol();
    cout << ": ";
    if (testImage.getColorAtLocation(testRowCol, testColor)) {
        testColor.printComponentValues();
    } else {
        cout << "Invalid Index!";
    }
    cout << endl;
  
    testRowCol.setRow(4);
    cout << "Want: Color at [4,5]: R: 1000 G: 0 B: 0" << endl;
    cout << "Color at ";
    testRowCol.printRowCol();
    cout << ": ";
    if (testImage.getColorAtLocation(testRowCol, testColor)) {
        testColor.printComponentValues();
    } else {
        cout << "Invalid Index!";
    }
    cout << endl;
  
    //Set up an array of images of different colors
    testColor.setToRed();
    testColor.adjustBrightness(0.25);
    testImages[0].initializeTo(testColor);
    testColor.setToBlue();
    testColor.adjustBrightness(0.75);
    testImages[1].initializeTo(testColor);
    testColor.setToGreen();
    testImages[2].initializeTo(testColor);
  
    //Modify a few individual pixel colors
    testRowCol.setRowCol(4, 2);
    testColor.setToWhite();
    testImages[1].setColorAtLocation(testRowCol, testColor);
  
    testRowCol.setRowCol(2, 4);
    testColor.setToBlack();
    testImages[2].setColorAtLocation(testRowCol, testColor);
  
    //Add up all images in testImages array and assign result
    //to the testImage image
    testImage.addImages(3, testImages); // 250, 1000, 750
    
    //Check some certain values
    cout << "Added values:" << endl;
    for (int colInd = 0; colInd < 8; colInd += 2) {
        testRowCol.setRowCol(4, colInd);
        cout << "Color at ";
        testRowCol.printRowCol();
        cout << ": ";
        if (testImage.getColorAtLocation(testRowCol, testColor)) {
            testColor.printComponentValues();
        } else {
            cout << "Invalid Index!";
        }
        cout << endl;
    }
    
    for (int rowInd = 0; rowInd < 8; rowInd += 2) {
        testRowCol.setRowCol(rowInd, 4);
        cout << "Color at ";
        testRowCol.printRowCol();
        cout << ": ";
        if (testImage.getColorAtLocation(testRowCol, testColor)) {
            testColor.printComponentValues();
        } else {
            cout << "Invalid Index!";
        }
        cout << endl;
    }
    
    cout << "Printing entire test image:" << endl;
    testImage.printImage();
    
    int k;
    cin >> k; 
    return 0;
}
#endif

ColorClass::ColorClass() {
    setToWhite();
}

ColorClass::ColorClass(int inRed, int inGreen, int inBlue) {
    redValue = setColor(inRed);
    greenValue = setColor(inGreen);
    blueValue = setColor(inBlue);
}

int ColorClass::setColor(int colorValue) {
    if (colorValue < MIN_COLOR_VALUE) {
        return MIN_COLOR_VALUE;
    }
    if (colorValue > MAX_COLOR_VALUE) {
        return MAX_COLOR_VALUE;
    }
    return colorValue;
}

bool ColorClass::colorInBound(int colorValue) {
    return colorValue >= MIN_COLOR_VALUE && colorValue <= MAX_COLOR_VALUE;
}

void ColorClass::setToBlack() {
    redValue = MIN_COLOR_VALUE;
    blueValue = MIN_COLOR_VALUE;
    greenValue = MIN_COLOR_VALUE;
}

void ColorClass::setToRed() {
    redValue = MAX_COLOR_VALUE;
    blueValue = MIN_COLOR_VALUE;
    greenValue = MIN_COLOR_VALUE;
}

void ColorClass::setToGreen() {
    redValue = MIN_COLOR_VALUE;
    blueValue = MIN_COLOR_VALUE;
    greenValue = MAX_COLOR_VALUE;
}

void ColorClass::setToBlue() {
    redValue = MIN_COLOR_VALUE;
    blueValue = MAX_COLOR_VALUE;
    greenValue = MIN_COLOR_VALUE;
}

void ColorClass::setToWhite() {
    redValue = MAX_COLOR_VALUE;
    blueValue = MAX_COLOR_VALUE;
    greenValue = MAX_COLOR_VALUE;
}

bool ColorClass::setTo(int inRed, int inGreen, int inBlue) {
    redValue = setColor(inRed);
    greenValue = setColor(inGreen);
    blueValue = setColor(inBlue);
    return (!colorInBound(inRed)) || (!colorInBound(inGreen))
             || (!colorInBound(inBlue));
}

bool ColorClass::setTo(ColorClass &inColor) {
    return setTo(inColor.redValue, inColor.greenValue, inColor.blueValue);
}

bool ColorClass::addColor(ColorClass &rhs) {
    return setTo(redValue + rhs.redValue, greenValue + rhs.greenValue,
                 blueValue + rhs.blueValue);
}

bool ColorClass::subtractColor(ColorClass &rhs) {
    return setTo(redValue - rhs.redValue, greenValue - rhs.greenValue,
                 blueValue - rhs.blueValue);
}

bool ColorClass::adjustBrightness(double adjFactor) {
    return setTo((int)(adjFactor * redValue), (int)(adjFactor * greenValue),
                 (int)(adjFactor * blueValue));
}

void ColorClass::printComponentValues() {
    cout << "R: " << redValue << " G: " << greenValue << " B: " << blueValue;
}

RowColumnClass::RowColumnClass() {
    row = DEFAULT_VALUE;
    col = DEFAULT_VALUE;
}

RowColumnClass::RowColumnClass(int inRow, int inCol) {
    row = inRow;
    col = inCol;
}

void RowColumnClass::setRowCol(int inRow, int inCol) {
    setRow(inRow);
    setCol(inCol);
}

void RowColumnClass::setRow(int inRow) {
    row = inRow;
}

void RowColumnClass::setCol(int inCol) {
    col = inCol;
}

int RowColumnClass::getRow() {
    return row;
}

int RowColumnClass::getCol() {
    return col;
}

void RowColumnClass::addRowColTo(RowColumnClass &inRowCol) {
    setRowCol(row + inRowCol.row, col + inRowCol.col);
}

void RowColumnClass::printRowCol() {
    cout << "[" << row << "," << col << "]";
}

ColorImageClass::ColorImageClass() {
    for (int i = 0; i < DEFAULT_ROW_LEN; i++) {
        for (int j = 0; j < DEFAULT_COL_LEN; j++) {
            pixels[i][j].setToBlack();
        }
    }
}

void ColorImageClass::initializeTo(ColorClass &inColor) {
    for (int i = 0; i < DEFAULT_ROW_LEN; i++) {
        for (int j = 0; j < DEFAULT_COL_LEN; j++) {
            pixels[i][j].setTo(inColor);
        }
    }
}

bool ColorImageClass::addImageTo(ColorImageClass &rhsImg) {
    bool result = false;
    for (int i = 0; i < DEFAULT_ROW_LEN; i++) {
        for (int j = 0; j < DEFAULT_COL_LEN; j++) {
            bool success = pixels[i][j].addColor(rhsImg.pixels[i][j]);
            result = result || success;
        }
    }
    return result;
}

bool ColorImageClass::addImages(int numImgsToAdd,
                                ColorImageClass imagesToAdd[]) {
    bool result = false;
    ColorImageClass imageSum;
    for (int i = 0; i < numImgsToAdd; i++) {
        bool clip = imageSum.addImageTo(imagesToAdd[i]);
        result = result || clip; // if any pixel needs clipping, return true
    }
    for (int i = 0; i < DEFAULT_ROW_LEN; i++) {
        for (int j = 0; j < DEFAULT_COL_LEN; j++) {
            pixels[i][j].setTo(imageSum.pixels[i][j]);
        }
    }
    return result;
}

bool ColorImageClass::outOfBounds(RowColumnClass &inRowCol) {
    if (inRowCol.getRow() < 0 || inRowCol.getRow() > DEFAULT_ROW_LEN) {
        return true;
    }
    if (inRowCol.getCol() < 0 || inRowCol.getCol() > DEFAULT_COL_LEN) {
        return true;
    }
    return false;
}

bool ColorImageClass::setColorAtLocation(RowColumnClass &inRowCol,
                                         ColorClass &inColor) {
    if (outOfBounds(inRowCol)) {
        return false;
    }
    pixels[inRowCol.getRow()][inRowCol.getCol()].setTo(inColor);
    return true;
}

bool ColorImageClass::getColorAtLocation(RowColumnClass &inRowCol,
                                         ColorClass &outColor) {
    if (outOfBounds(inRowCol)) {
        return false;
    }
    outColor.setTo(pixels[inRowCol.getRow()][inRowCol.getCol()]);
    return true;
}

void ColorImageClass::printImage() {
    for (int i = 0; i < DEFAULT_ROW_LEN; i++) {
        pixels[i][0].printComponentValues();
        for (int j = 1; j < DEFAULT_COL_LEN; j++) {
            cout << "--";
            pixels[i][j].printComponentValues();
        }
        cout << endl;
    }
}
