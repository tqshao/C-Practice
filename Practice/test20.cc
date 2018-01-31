#include <iostream>
#include <vector>

using namespace std;

void printCircle(int row, int column, int rowStart, vector<vector<int>> matrix){
	int colEnd = column - rowStart - 1;
	int rowEnd = row - rowStart - 1;
	for (int i = rowStart; i <= colEnd; i++){
		cout << matrix[rowStart][i] << " ";
	}
	if ( rowEnd > rowStart ){
		for (int i = rowStart + 1; i <= rowEnd; i++){
			cout << matrix[i][colEnd] << " ";
		}
	}
	if ( colEnd > rowStart ){
		for (int i = colEnd -1 ; i >= rowStart; i--){
			cout << matrix[rowEnd][i] << " ";
		}
	}
	if ( rowEnd > rowStart + 1 ){
		for (int i = rowEnd - 1 ; i > rowStart; i--){
			cout << matrix[i][rowStart] << " ";
		}
	}
}

void print(vector<vector<int>> matrix){
	int row = matrix.size();
	int column = matrix[0].size();
	cout << row << column << endl;
	int rowStart;
	cout << "The clockwise elements of the matrix are ";
	for(int i = 0; i <= (row - 1)/2; i++){
		rowStart = i;
		printCircle(row, column, rowStart, matrix);
	}
	cout << endl;
}

int main(){
	vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
	print(matrix);
	return 0;
}