#ifndef _PATTERN_H_
#define _PATTERN_H_

#include <iostream>
#include <fstream>
using namespace std;

class Pattern {
public:
    // read Pattern from file
    bool readPattern(string &filePath);

    // getter of the pattern (1d-matrix)
    bool* getMat() const;

    // getter of the width of pattern
    int getWidth() const;

    // getter of the height of the pattern
    int getHeight() const;

private:
    int width;
    int height;
    bool *mat;
};

#endif
