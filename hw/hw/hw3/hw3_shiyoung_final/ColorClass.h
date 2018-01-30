#ifndef _COLORCLASS_H_
#define _COLORCLASS_H_

#include <iostream>
#include <fstream>
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

    // read RBG value from an input stream
    bool readColorFromStream(ifstream &inStream);

    // get red color value
    int getR() const;

    // get green color value
    int getG() const;

    // get blue color value
    int getB() const;

    // test if two colors are the same
    bool equals(ColorClass *other);

private:
    int redValue;
    int greenValue;
    int blueValue;

    // helper function that return the clipped value
    int setColor(int colorValue);

    // helper function that check whether a color value is in the allowed range
    bool isColorInBound(int colorValue);

    static const int MIN_COLOR_VALUE = 0;
    static const int MAX_COLOR_VALUE = 255;
};

#endif
