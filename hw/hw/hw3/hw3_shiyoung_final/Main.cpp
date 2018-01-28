// EECS402
// Project 3
// Shiyang Lu (shiyoung@umich.edu)
// Last modified date: 11/2/2017
// Overview: This application allows the user to read a ppm image from file, and
// modify the image. Three major functions are annotate image with a rectangle,
// annotate image with a pattern and insert another ppm image to the base image.
// Besides, it can allow user to save the modified image to a ppm file.
#include <iostream>
#include <fstream>
#include "ColorClass.h"
#include "ColorImageClass.h"
#include "Pattern.h"
using namespace std;


int main() {
    string filename;
    cout << "Enter string for PPM image file name to load: ";
    cin >> filename;
    
    ColorImageClass *baseImage = new ColorImageClass;
    bool success = baseImage->readFromPPM(filename);
    if (!success) {
        delete baseImage;
        return 1;
    }

    while (true) {
        cout << "1. Annotate image with rectangle" << endl;
        cout << "2. Annotate image with pattern from file" << endl;
        cout << "3. Insert another image" << endl;
        cout << "4. Write out current image" << endl;
        cout << "5. Exit the program" << endl;
        cout << "Enter int for main menu choice: ";

        int selection;
        cin >> selection;
        if (cin.fail() || selection < 1 || selection > 5) {
            cin.clear();
            cin.ignore(200, '\n');
            cout << "Please select a number from 1 to 5." << endl;
            continue;
        }

        if (selection == 1) {
            baseImage->annotateWithRectangle();
        } else if (selection == 2) {
            baseImage->annotateWithPattern();
        } else if (selection == 3) {
            baseImage->insertImage();
        } else if (selection == 4) {         
            baseImage->writeImage();
        } else {
            break;
        }
    }

    delete baseImage;
    return 0;
}
