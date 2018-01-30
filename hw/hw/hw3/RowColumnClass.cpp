#include "RowColumnClass.h"

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
