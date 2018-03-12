#include <iostream>
#include <cstdlib>

#include "BST.cpp"

using namespace std;

int main(){

	int treeKeys[10] = {50, 76, 21, 4, 32,64, 15, 52, 14, 1};
	BST myTree;
	cout << "Printing the tree in order before adding numbers:\n";
	myTree.printInOrder();
	for(int i = 0; i < sizeof(treeKeys)/sizeof(treeKeys[0]); i++){
		myTree.addLeaf(treeKeys[i]);
	}
	cout << "Printing the tree in order after adding numbers:\n";
	myTree.printInOrder();
	cout << endl;
	myTree.printChildren(myTree.returnRootKey());
	/*
	for(int i = 0; i < sizeof(treeKeys)/sizeof(treeKeys[0]); i++){
		myTree.printChildren(treeKeys[i]);
		cout << endl;
	}
	*/
	cout << "The smallest value in the tree is " << myTree.findSmallest() << endl;

	return 0;
}