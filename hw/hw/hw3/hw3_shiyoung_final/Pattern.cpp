#include "Pattern.h"

bool Pattern::readPattern(string &filePath) {
    ifstream inFile;
    inFile.open(filePath.c_str());

    if (inFile.fail()) {
        cout << "Pattern file cannot be opened" << endl;
        inFile.close();
        return false;
    }

    inFile >> width >> height;
    if (inFile.fail() || width <= 0 || height <= 0) {
        cout << "Error found when reading the width, height of the pattern. \n";
        inFile.close();
        return false;
    }

    int size = width * height;
    mat = new bool[size];
    bool success = true;
    for (int i = 0; i < size; i++) {
        inFile >> mat[i];
        if (inFile.fail()) {
            cout << "Error found when reading the pattern" << endl;
            delete [] mat;
            inFile.close();
            return false;
        }
    }

    string _;
    inFile >> _;
    if (!inFile.eof()) {
        cout << "Error found when reading the pattern. There are more values"
            << "than expected." << endl;
        delete [] mat;
        inFile.close();
        return false;
    }

    inFile.close();
    return true;
}

bool* Pattern::getMat() const {
    return mat;
}

int Pattern::getWidth() const {
    return width;
}

int Pattern::getHeight() const {
    return height;
}
