#include "ColorImageClass.h"


ColorImageClass::ColorImageClass() {}


void ColorImageClass::initializeTo(ColorClass &inColor) {
    for (int i = 0; i < width * height; i++) {
        pixels[i].setTo(inColor);
    }
}


bool ColorImageClass::readFromPPM(string filename) {
    ifstream inFile;
    inFile.open(filename.c_str());

    if (inFile.fail()) {
        cout << "Image cannot be opened" << endl;
        return false;
    }

    string magicNumber;
    inFile >> magicNumber;
    if (inFile.fail() || magicNumber != "P3") {
        cout << "Error found when reading the magic number, expected " <<
           "magic number is 'P3'" << endl; 
        return false;
    }

    int maxColorValue;
    inFile >> width >> height >> maxColorValue;

    if (inFile.fail() || width <= 0 || height <= 0 || maxColorValue != 255) {
        cout << "Error found when reading the width, height and "
            << "maxColorValue of the PPM image" << endl;
        return false;
    }

    int size = width * height;
    pixels = new ColorClass[size];
    for (int i = 0; i < size; i++) {
        bool success = pixels[i].readColorFromStream(inFile);
        if (!success) {
            delete [] pixels;
            return false;
        }
    }

    string _;
    inFile >> _;
    if (!inFile.eof()) {
        cout << "Error found when reading pixel color values from PPM image. " 
            << "There are more pixels than expected." << endl;
        return false;
    }

    inFile.close();
    return true;
}


bool ColorImageClass::annotateWithRectangle() {
    cout << "1. Specify upper left and lower right corners of rectangle \n";
    cout << "2. Specify upper left corner and dimensions of rectangle" << endl;
    cout << "3. Specify extent from center of rectangle" << endl;
    cout << "Enter int for rectangle specification method: ";
            
    int selection;
    cin >> selection;
    while (cin.fail() || selection < 1 || selection > 3) {
        cin.clear();
        cin.ignore(200, '\n');
        cout << "Error. Your selection must be 1, 2 or 3" << endl;
        cout << "Please select again :";
        cin >> selection;
    }
    
    int *bbox = ColorImageClass::readbboxInfo(selection);
    if (bbox[0] < 0 || bbox[1] < 0 || bbox[2] > height || bbox[3] > width) {
        cout << "Error occurred when annotating the image with a rectangle."
            << "The rectangle is out of bounds." << endl;
        return false;
    }

    string obj = "rectangle";
    ColorClass *color = ColorImageClass::readColor(obj);
    bool isFilled = ColorImageClass::readFillOption();
    
    if (isFilled) {
        for (int i = bbox[0]; i <= bbox[2]; i++) {
            for (int j = bbox[1]; j <= bbox[3]; j++) {
                pixels[getIndex(i, j)].setTo(*color);
            }
        }
    } else {
        for (int i = bbox[0]; i <= bbox[2]; i++) {
            pixels[getIndex(i, bbox[1])].setTo(*color);
            pixels[getIndex(i, bbox[3])].setTo(*color);
        }
        for (int j = bbox[1]; j <= bbox[3]; j++) {
            pixels[getIndex(bbox[0], j)].setTo(*color);
            pixels[getIndex(bbox[2], j)].setTo(*color);
        }
    }

    delete color;
    delete [] bbox;
    return true;
}


int* ColorImageClass::readbboxInfo(int selection) {
    int leftRow = 0, leftCol = 0, rightRow = 0, rightCol = 0;

    if (selection == 1) {
        cout << "Enter upper left corner row and column: ";
        cin >> leftRow >> leftCol;
        cout << "Enter lower right corner row and column: ";
        cin >> rightRow >> rightCol;
        while (cin.fail() || leftRow < 0 || leftCol < 0 || rightRow <= leftRow
                || rightCol <= leftCol) {
            cin.clear();
            cin.ignore(200, '\n');
            cout << "Error occurred when reading bounding box information. "
                << "Make sure they are positive numbers and order of them are "
                << "correct. Please try again." << endl;
            cout << "Enter upper left corner row and column: ";
            cin >> leftRow >> leftCol;
            cout << "Enter lower right corner row and column: ";
            cin >> rightRow >> rightCol;
        }

    } else if (selection == 2) {
        int numRows = 0, numCols = 0;
        cout << "Enter upper left corner row and column: ";
        cin >> leftRow >> leftCol;
        cout << "Enter int for number of rows: ";
        cin >> numRows;
        cout << "Enter int for number of columns: ";
        cin >> numCols;
        while (cin.fail() || leftRow < 0 || leftCol < 0 || numRows <= 1
                || numCols <= 1) {
            cin.clear();
            cin.ignore(200, '\n');
            cout << "Error occurred when reading bounding box information. "
                << "Make sure they are positive numbers and order of them are "
                << "correct. Please try again." << endl;
            cout << "Enter upper left corner row and column: ";
            cin >> leftRow >> leftCol;
            cout << "Enter int for number of rows: ";
            cin >> numRows;
            cout << "Enter int for number of columns: ";
            cin >> numCols;
        }
        rightRow = leftRow + numRows - 1;
        rightCol = leftCol + numCols - 1;

    } else {
        int centerRow = 0, centerCol = 0, halfRow = 0, halfCol = 0;
        cout << "Enter rectangle center row and column: ";
        cin >> centerRow >> centerCol;
        cout << "Enter int for half number of rows: ";
        cin >> halfRow;
        cout << "Enter int for half number of columns: ";
        cin >> halfCol;
        while (cin.fail() || centerRow < 0 || centerCol < 0 || halfRow <= 1
                || halfCol <= 1) {
            cout << "Error occurred when reading bounding box information. "
                << "Make sure they are positive numbers and order of them are "
                << "correct. Please try again." << endl;
            cout << "Enter rectangle center row and column: ";
            cin >> centerRow >> centerCol;
            cout << "Enter int for half number of rows: ";
            cin >> halfRow;
            cout << "Enter int for half number of columns: ";
            cin >> halfCol;
        }
        leftRow = centerRow - halfRow;
        leftCol = centerCol - halfCol;
        rightRow = centerRow + halfRow;
        rightCol = centerCol + halfCol;
    }

    int *bbox = new int[4];
    bbox[0] = leftRow;
    bbox[1] = leftCol;
    bbox[2] = rightRow;
    bbox[3] = rightCol;

    return bbox;
}


ColorClass* ColorImageClass::readColor(string object) {
    int colorNum = 0;
    cout << "1. Red" << endl;
    cout << "2. Green" << endl;
    cout << "3. Blue" << endl;
    cout << "4. Black" << endl;
    cout << "5. White" << endl;
    cout << "Enter int for " << object << " color: ";

    cin >> colorNum;
    while (cin.fail() || colorNum < 1 || colorNum > 5) {
        cin.clear();
        cin.ignore(200, '\n');
        cout << "Error occurred when reading the color. The color number "
            << "should be betweem 1 to 5. Please try again: ";
        cout << "Enter int for " << object << " color: ";
        cin >> colorNum;
    }

    ColorClass *color = new ColorClass;
    if (colorNum == 1) {
        color->setToRed();
    } else if (colorNum == 2) {
        color->setToGreen();
    } else if (colorNum == 3) {
        color->setToBlue();
    } else if (colorNum == 4) {
        color->setToBlack();
    } else {
        color->setToWhite();
    }

    return color;
}


bool ColorImageClass::readFillOption() {
    int isFilled = 0;
    cout << "1. No" << endl;
    cout << "2. Yes" << endl;
    cout << "Enter int for rectangle fill option: ";

    cin >> isFilled;
    while (cin.fail() || isFilled < 1 || isFilled > 2) {
        cin.clear();
        cin.ignore(200, '\n');
        cout << "Error occurred when reading the fill option. It should be an "
            << "integer 1 (not fill) or 2 (fill). Please try again" << endl;
        cout << "Enter int for rectangle fill option: ";
        cin >> isFilled;
    }
    return isFilled == 1 ? false : true;
}


bool ColorImageClass::annotateWithPattern() {
    string patternFile;
    cout << "Enter string for file name containing pattern: ";
    cin >> patternFile;

    Pattern *pat = new Pattern;
    bool success = pat->readPattern(patternFile);
    if (!success) {
        delete pat;
        return false;
    }

    int leftRow, leftCol;
    cout << "Enter upper left corner of pattern row and column: ";
    cin >> leftRow >> leftCol;
    while (cin.fail() || leftRow < 0 || leftCol < 0) {
        cin.clear();
        cin.ignore(200, '\n');
        cout << "Error occurred when reading row and column of upper left "
            << "corner. The row and col must be greater than 0." << endl; 
        cout << "Please try again." << endl;
        cout << "Enter upper left corner of pattern row and column: ";
        cin >> leftRow >> leftCol;
    }
        
    if (pat->getWidth() + leftCol >= width 
            || pat->getHeight() + leftRow >= height) {
        cout << "Error occurred when try to annotate the image with the given "
            << "pattern. The pattern is out of bounds." << endl;
        return false;
    }
    
    string obj = "pattern";
    ColorClass *color = ColorImageClass::readColor(obj);
    bool *mat = pat->getMat();
    int matIndex = 0;
    for (int i = leftRow; i < leftRow + pat->getHeight(); i++) {
        for (int j = leftCol; j < leftCol + pat->getWidth(); j++) {
            if (mat[matIndex++]) {
                pixels[getIndex(i, j)].setTo(*color);
            }
        }
    }

    return true;
}


bool ColorImageClass::insertImage() {
    string imagePath;
    cout << "Enter string for file name of PPM image to insert: ";
    cin >> imagePath;

    ColorImageClass *imgToInsert = new ColorImageClass;
    bool success = imgToInsert->readFromPPM(imagePath);
    if (!success) {
        delete imgToInsert;
        return false;
    }

    int leftRow, leftCol;
    cout << "Enter upper left corner to insert image row and column: ";
    cin >> leftRow >> leftCol;
    while (cin.fail() || leftRow < 0 || leftCol < 0) {
        cin.clear();
        cin.ignore(200, '\n');
        cout << "Error occurred when reading row and column of upper left "
            << "corner. The row and col must be greater than 0." << endl; 
        cout << "Please try again." << endl;
        cout << "Enter upper left corner to insert image row and column: ";
        cin >> leftRow >> leftCol;
    }

    if (imgToInsert->getWidth() + leftCol >= width 
            || imgToInsert->getHeight() + leftRow >= height) {
        cout << "Error occurred when try to insert an image. The pattern is "
            << "out of bounds." << endl;
        return false;
    }

    string obj = "transparecy";
    ColorClass *color = ColorImageClass::readColor(obj);
    
    int index = 0;
    for (int i = leftRow; i < leftRow + imgToInsert->getHeight(); i++) {
        for (int j = leftCol; j < leftCol + imgToInsert->getWidth(); j++) {
            if (imgToInsert->pixels[index].equals(color)) {
                index++;
                continue;
            }
            pixels[getIndex(i, j)].setTo(imgToInsert->pixels[index++]);
        }
    }

    return true;
}


bool ColorImageClass::writeImage() {
    string outputFileName;
    cout << "Enter string for PPM file name to output: ";
    cin >> outputFileName;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(200, '\n');
        cout << "Error occurred when reading the name of the output image."
            << "Please check the file is writable and try again." << endl;
        cin >> outputFileName;
    }

    ofstream outFile;
    outFile.open(outputFileName.c_str());
    if (outFile.fail()) {
        cout << "Error occurred when openning the output file" << endl;
        return false;
    }

    outFile << "P3" << endl;
    outFile << width << " " << height << endl;
    outFile << 255 << endl;

    for (int i = 0; i < width * height; i++) {
        ColorClass pixel = pixels[i];
        outFile << pixel.getR() << " " << pixel.getG() << " " << pixel.getB();
        if (i % width != width - 1) {
            outFile << " ";
        } else {
            outFile << endl;
        }
    }

    outFile.close();
    return true;
}


void ColorImageClass::printShape() {
    cout << "Image width: " << width << endl;
    cout << "Image height: " << height << endl;
}


int ColorImageClass::getWidth() const {
    return width;
}


int ColorImageClass::getHeight() const {
    return height;
}


int ColorImageClass::getIndex(int row, int col) {
    return row * width + col;
}
