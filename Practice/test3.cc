// find the first non-repeating character in an string

#include <iostream>
#include <string>
#include <unordered_map>
#include <limits.h>
#include <algorithm>

using namespace std;

// search from top-right 
bool find(int* matrix, int& row,int& col, int rows, int cols, int val){
	row = 1;
	col = cols;
	while(row <= rows && col > 0){
		if (*(matrix + cols*(row-1) + col-1)  > val ) { col--; }
		else if (*(matrix + cols*(row-1) + col-1)  < val) { row++; }
		else { return true; }
	}
	return false;
}

int main(){
	int m[3][3] = {{1,2,8},{2,4,9},{4,7,10}};
	int rows = 3;
	int cols = 3;
	int row = 0;
	int col = 0;
	if(find((int *)m,row,col,rows,cols,4)){
		cout << "The index of the value is " << row << ", " << col << endl;
	}
	else { cout << "Didn't find the value." << endl; }
	return 0;
}

