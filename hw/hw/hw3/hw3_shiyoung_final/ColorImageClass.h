#ifndef _COLORIMAGECLASS_H_
#define _COLORIMAGECLASS_H_

#include <iostream>
#include <fstream>
#include "ColorClass.h"
#include "Pattern.h"
using namespace std;

class ColorImageClass {
public:
    // default constructor that does nothing
    ColorImageClass();

    // initialize all image pixels to the given color
    void initializeTo(ColorClass &inColor);

    // read image from PPM file
    bool readFromPPM(string filename);

    // annotate the image with a rectangle
    bool annotateWithRectangle();

    // annotate the image with a pattern
    bool annotateWithPattern();

    // insert anouth image to the current base image
    bool insertImage();

    // write the image to a ppm file
    bool writeImage();

    // print the width and height of the image
    void printShape();

    // get width of the image
    int getWidth() const;

    // get height of the image
    int getHeight() const;

private:
    int width;
    int height;
    ColorClass *pixels;

    // read the bounding box information from user input
    int* readbboxInfo(int selection);

    // read color from user input for some object
    ColorClass* readColor(string object);

    // read fill option from user input
    bool readFillOption();

    // helper function that convert 2d index to 1d index
    int getIndex(int row, int col);
};

#endif
