#include <iostream>
using namespace std;

#define MAX 1000
#define MIN 0

class ColorClass{
public:
	ColorClass(int Red = MAX, int Green = MAX, int Blue = MAX):
	inRed(Red), inGreen(Green), inBlue(Blue){}
	void setToBlack();
	void setToRed();
	void setToGreen();
	void setToBlue();
	void setToWhite();
	bool setTo(int inRed, int inGreen, int inBlue);
	bool setTo(ColorClass &inColor);
	bool addColor(ColorClass &rhs);
	bool subtractColor(ColorClass &rhs);
	bool adjustBrightness(double adjFactor);
	void printComponentValues();

private:
	int inRed, inGreen, inBlue;
};

class RowColumnClass{
public:
	RowColumnClass(int Row = -99999, int Col = -99999):
				   inRow(Row),inCol(Col){}
	void setRowCol(int inRow, int inCol);
	void setRow(int inRow);
	void setCol(int inCol);
	int getRow();
	int getCol();
	void addRowColTo(RowColumnClass &inRowCol);
	void printRowCol();
private:	
	int inRow, inCol;
};

class ColorImageClass{
public:
	ColorImageClass();
	void initializeTo(ColorClass &inCol);
	bool addImageTo(ColorImageClass &rhsImg);
	bool addImages(int numImgsToAdd,ColorImageClass imagesToAdd []);
	bool setColorAtLocation(RowColumnClass &inRowCol, ColorClass &inColor);
	bool getColorGetLocation(RowColumnClass &inRowCol, ColorClass &outColor);
	void printImage();

private:
	static const int DEFAULT_ROW = 3;
	static const int DEFAULT_COL = 2;
	ColorClass pixels[DEFAULT_ROW][DEFAULT_COL];
};

#ifdef ANDREW_TEST
#include "andrewTest.h"
#else
int main(){
	// RowColumnClass testCol_1;
	// RowColumnClass testCol_2;
	// testCol_1.setRowCol(10,2);
	// testCol_2.setRowCol(10,3);
	// testCol_2.addRowColTo(testCol_1);
	// testCol_1.printRowCol();

	ColorClass testColor;
	ColorClass copyColor;
	ColorClass Green, Blue;
	ColorClass rhs;
	rhs.setToRed();
	Green.setToGreen();
	Blue.setToBlue();
	copyColor.setTo(200, 100, 100);
	testColor.setTo(copyColor);
	//testColor.subtractColor(rhs);
	Green.adjustBrightness(0.5);
	Blue.adjustBrightness(0.5);
	testColor.printComponentValues();
	cout << endl;
	ColorImageClass testImage;
	int numSets = 2;
	ColorImageClass testSets[numSets];
	testImage.initializeTo(testColor);
	testSets[0].initializeTo(Green);
	testSets[1].initializeTo(Blue);
	testImage.addImages(numSets,testSets);

	// modify a pixel value at a certain location
	RowColumnClass location(0,0);
	testImage.setColorAtLocation(location,Green);
	testImage.printImage();
	ColorClass outColor;
	testImage.getColorGetLocation(location,outColor);
	outColor.printComponentValues();
	return 0;
}
#endif

void ColorClass::setToBlack(){
	inRed = MIN;
	inGreen = MIN;
	inBlue = MIN;
}

void ColorClass::setToRed(){
	inRed = MAX;
	inGreen = MIN;
	inBlue = MIN;
}

void ColorClass::setToGreen(){
	inRed = MIN;
	inGreen = MAX;
	inBlue = MIN;
}

void ColorClass::setToBlue(){
	inRed = MIN;
	inGreen = MIN;
	inBlue = MAX;
}

void ColorClass::setToWhite(){
	inRed = MAX;
	inGreen = MAX;
	inBlue = MAX;
}

void ColorClass::printComponentValues(){
	cout << "R: " << inRed << "   G: " << inGreen << "  B: " << inBlue;
}

bool clipping(int &inColor){
	bool ifClipping = false;
	if (inColor > MAX) {
		inColor = MAX;
		ifClipping = true;
	}
	if (inColor < MIN) {
		inColor = MIN;
		ifClipping = true;
	}
	return ifClipping;
}

bool ColorClass::setTo(int Red, int Green, int Blue){
	clipping(Red);
	clipping(Green);
	clipping(Blue);
	inRed = Red;
	inGreen = Green;
	inBlue = Blue;
	return (clipping(Red) || clipping(Green) || clipping(Blue));
}

bool ColorClass::setTo(ColorClass &inColor){
	return setTo(inColor.inRed, inColor.inGreen, inColor.inBlue);
}

bool ColorClass::addColor(ColorClass &rhs){
	return setTo(inRed + rhs.inRed, inGreen + rhs.inGreen, inBlue + rhs.inBlue);
}

bool ColorClass::subtractColor(ColorClass &rhs){
	return setTo(inRed - rhs.inRed, inGreen - rhs.inGreen, inBlue - rhs.inBlue);
}

bool ColorClass::adjustBrightness(double adjFactor){
	return setTo(static_cast<int>(inRed * adjFactor),
				 static_cast<int>(inGreen * adjFactor),
				 static_cast<int>(inBlue * adjFactor));
}

void RowColumnClass::setRow(int Row){
	inRow = Row;
}

void RowColumnClass::setCol(int Col){
	inCol = Col;
}

void RowColumnClass::setRowCol(int Row, int Col){
	setCol(Col);
	setRow(Row);
}

int RowColumnClass::getRow(){
	return inRow;
}

int RowColumnClass::getCol(){
	return inCol;
}

void RowColumnClass::addRowColTo(RowColumnClass &inRowCol){
	inRowCol.setCol(inRowCol.getCol() + inCol);
	inRowCol.setRow(inRowCol.getRow() + inRow);	
}

void RowColumnClass::printRowCol(){
	cout << "There are " << inRow << " rows." <<endl;
	cout << "There are " << inCol << " columns." << endl;
}

ColorImageClass::ColorImageClass(){
	for (int i = 0; i < DEFAULT_ROW; ++i){
		for (int j = 0; j <DEFAULT_COL; ++j){
			pixels[i][j].setToBlack();
		}
	}
}

void ColorImageClass::initializeTo(ColorClass &inColor){
	bool if_clipping = false;
	for (int i = 0; i < DEFAULT_ROW; ++i){
		for (int j = 0; j <DEFAULT_COL; ++j){
			if_clipping = pixels[i][j].setTo(inColor);
		}
	}
}


bool ColorImageClass::addImageTo(ColorImageClass &rhsImg){
	bool result = false;
	for (int i = 0; i < DEFAULT_ROW; ++i){
		for (int j = 0; j <DEFAULT_COL; ++j){
			bool if_clipping = pixels[i][j].addColor(rhsImg.pixels[i][j]);
			result = result || if_clipping;
		}
	}
	return result;
}

bool ColorImageClass::addImages(int numImgsToAdd,ColorImageClass imagesToAdd []){
	bool result = false;
	for (int i = 0; i < numImgsToAdd; ++i){
		bool if_clipping = this->addImageTo(imagesToAdd[i]);
		result = result || if_clipping;
	}
	return result;
}

bool ColorImageClass::setColorAtLocation(RowColumnClass &inRowCol, ColorClass &inColor){
	int row = inRowCol.getRow();
	int col = inRowCol.getCol();
	if (row <= DEFAULT_COL && col <= DEFAULT_ROW){
		pixels[row][col].setTo(inColor);
		return true;
	}
	else {
		return false;
	}
}

bool ColorImageClass::getColorGetLocation(RowColumnClass &inRowCol, ColorClass &outColor){
	int row = inRowCol.getRow();
	int col = inRowCol.getCol();
	if (row <= DEFAULT_COL && col <= DEFAULT_ROW){
		outColor.setTo(pixels[row][col]);
		return true;
	}
	else {
		return false;
	}
}

void ColorImageClass::printImage(){
	for (int i = 0; i < DEFAULT_ROW; ++i){
		for (int j = 0; j < DEFAULT_COL; ++j){
			pixels[i][j].printComponentValues();
			cout << " -- ";
		}
		cout << endl;
	}
	cout << endl;
}


