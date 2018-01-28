#include "ColorClass.h"


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


bool ColorClass::isColorInBound(int colorValue) {
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
    return (!isColorInBound(inRed)) || (!isColorInBound(inGreen))
        || (!isColorInBound(inBlue));
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


int ColorClass::getR() const {
    return redValue;
}


int ColorClass::getG() const {
    return greenValue;
}


int ColorClass::getB() const {
    return blueValue;
}


bool ColorClass::readColorFromStream(ifstream &inStream) {
    inStream >> redValue >> greenValue >> blueValue;
    if (inStream.fail() || !isColorInBound(redValue)
            || !isColorInBound(greenValue) || !isColorInBound(blueValue)) {
        cout << "Error found when reading color value from input stream.\n";
        return false;
    }
    return true;
}


bool ColorClass::equals(ColorClass *other) {
    return redValue == other->redValue && greenValue == other->greenValue
        && blueValue == other->blueValue;
}
