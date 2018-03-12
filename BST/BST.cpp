#include <iostream>
#include <cstdlib>

#include "BST.h"

using namespace std;

BST::BST(){
	root = NULL;
}

BST::node* BST::createLeaf(int key){
	node* n = new node;
	n->key = key;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void BST::addLeaf(int key){
	addLeafPrivate(key, root);
}

void BST::addLeafPrivate(int key, node* Ptr){
	if(root ==NULL){
		root = createLeaf(key);
	}
	else if(key < Ptr->key){
		if(Ptr->left != NULL){
			addLeafPrivate(key, Ptr->left);
		}
		else{
			Ptr->left = createLeaf(key);
		}
	}
	else if(key > Ptr->key){
		if(Ptr->right != NULL){
			addLeafPrivate(key, Ptr->right);
		}
		else{
			Ptr->right = createLeaf(key);
		}
	// cout << "The key " << "has already been added to the tree\n";
}
}


void BST::printInOrder(){
	printInOrderPrivate(root);
}

void BST::printInOrderPrivate(node* Ptr){
	if(root != NULL){
		if(Ptr->left != NULL){
			printInOrderPrivate(Ptr->left);
		}
		cout << Ptr->key << " ";
		if(Ptr->right != NULL){
			printInOrderPrivate(Ptr->right);
		}
	}
	else{
		cout << "The train is empty\n";
	}
}

BST::node* BST::returnNode(int key){
	return returnNodePrivate(key, root);
}

BST::node* BST::returnNodePrivate(int key, node* Ptr){
	if(Ptr != NULL){
		if(Ptr->key ==key){
			return Ptr;
		}
		else{
			if(key < Ptr->key){
				return returnNodePrivate(key, Ptr->left);
			}
			else{
				return returnNodePrivate(key, Ptr->right);
			}
		}
	}
	else{
		return NULL;
	}
}

int BST::returnRootKey(){
	if(root != NULL){
		return root->key;
	}
	else{
		// the number in the binary search tree should all be ppositive integers
		return -1000;
	}
}

void BST::printChildren(int key){
	node* Ptr = returnNode(key);
	if(Ptr != NULL){
		cout << "Parent Node = " << Ptr->key << endl;
		Ptr->left == NULL?
		cout << "Left Child = NULL\n":
		cout << "Left Child = "<< Ptr->left->key << endl;
		Ptr->right == NULL?
		cout << "Right Child = NULL\n":
		cout << "Right Child = "<< Ptr->right->key << endl;
	}

	else{
		cout << "Key " << key << " is not in the tree.\n";
	}
}

int BST::findSmallest(){
	findSmallestPrivate(root);
}

int BST::findSmallestPrivate(node* Ptr){
	if(root == NULL){
		cout << "The tree is empty\n";
		return -1000;
	}
	else{
		if(Ptr->left != NULL){
			return findSmallestPrivate(Ptr->left);
		}
		else{
			return Ptr->key;
		}
	}
}

void BST::removeNode(int key){
	removeNodePrivate(key, root);
}

void BST::removeNodePrivate(int key, node* parent){
	if(root != NULL){
		if(root->key == key){
			removeRootMatch();
		}
		else{
			if(key < parent->key && parent->left != NULL){
				parent->left->key == key ? 
				removeMatch(parent, parent->left, true) : 
				removeNodePrivate(key, parent->left);
			}
			else if(key > parent->key && parent->right != NULL){
				parent->right->key == key ? 
				removeMatch(parent, parent->right, false) : 
				removeNodePrivate(key, parent->right);
			}
			else{
				cout << "The key " << key << " was not found in the tree.\n";
			}
		}
	}
	else{
		cout << "The tree is empty.\n";
	}
}

void BST::removeRootMatch(){
	if(root != NULL){
		node* delPtr = root;
		int rootKey = root->key;
		int smallestInRightSubtree;
		// CASE 0 - 0 children
		if(root->left == NULL && root->right ==NULL){
			root = NULL;
			delete delPtr;
		}
		// CASE 1 - 1 child
		else if (root -> left == NULL && root->right != NULL){
			root = root->right;
			delPtr->right = NULL;
			delete delPtr;
			cout<< "The root node with key " << rootKey << " was deleted." << 
			"THe new root contains key " << root->key << endl;
		}
		else if (root -> left != NULL && root->right == NULL){
			root = root->left;
			delPtr->left = NULL;
			delete delPtr;
			cout<< "The root node with key " << rootKey << " was deleted." << 
			"THe new root contains key " << root->key << endl;
		}
		// CASE 2 - 2 children
		else {
			smallestInRightSubtree = findSmallestPrivate(root->right);
			removeNodePrivate(smallestInRightSubtree, root);
			root->key = smallestInRightSubtree;
			cout << "The root key containing key " << rootKey << 
			" was overwritten with key " << root->key << endl;
		} 
	}
	else{
		cout << "Cannot remove root. The tree is empty.\n";
	}
}

void BST::removeMatch(node* parent, node* match, bool left){
	if(root != NULL){
		node* delPtr;
		int matchKey = match->key;
		int smallestInRightSubtree;
		// CASE 0 - 0 Children
		if(match->left == NULL && match->right == NULL){
			delPtr = match;
			left == true ? parent->left = NULL : parent->right = NULL;
			delete delPtr;
			cout << "The node containing key " << matchKey << " was removed\n";
		}
		// CASE 1 - 1 Child
		else if (match->left == NULL && match->right != NULL){
			left == true ? parent->left = match->right : parent->right = match->right;
			match->right = NULL;
			delPtr = match;
			delete delPtr;
			cout << "The node containing key " << matchKey << " was removed\n";
		}
		else if (match->left != NULL && match->right == NULL){
			left == true ? parent->left = match->left : parent->right = match->left;
			match->left = NULL;
			delPtr = match;
			delete delPtr;
			cout << "The node containing key " << matchKey << " was removed\n";
		}

		// CASE 2 - 2 Children
		else{
			smallestInRightSubtree = findSmallestPrivate(match->right);
			removeNodePrivate(smallestInRightSubtree,match);
			match->key = smallestInRightSubtree;
		}
	}
	else{
		cout <<"Cannot remove match. The tree is empty\n";
	}
}









