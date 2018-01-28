#ifndef _ROWCOLUMNCLASS_H_
#define _ROWCOLUMNCLASS_H_

#include <iostream>
using namespace std;

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

#endif
