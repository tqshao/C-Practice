#include <iostream>
#include <stack>
using namespace std;

struct ListNode{
	int value;
	ListNode* next;
	ListNode(int x = 0): value(x), next(NULL){}
};

// add a node to the end of the list
void addTail(ListNode** pHead, int val){
	ListNode* pNew = new ListNode(val);
	// pNew -> value = val;
	// pNew -> next = NULL;

	if (*pHead == NULL) { *pHead = pNew; }
	else{
		ListNode* pNode = *pHead; 
		while(pNode -> next != NULL) {
			pNode = pNode -> next;
		}
		pNode -> next = pNew;
	} 
}

// delete the node which contains certain value
void deleteNode(ListNode** pHead, ListNode* node){
	if (!*pHead || ! node) { return; } 
	// If the node to be delted is the first one, and the only one.
	if (pHead -> next == NULL) {
		delete pHead;
		pHead = NULL;
		return;
	}
	// If the node to be deleted is the last one, traverse the list
	if (node -> next == NULL){
		ListNode* iter = *pHead;
		while(iter -> next != node){
			iter = iter -> next;
		}
		iter -> next = NULL;
		delete node;
		node = NULL;
		return;
	}
	ListNode* nextOne = node -> next;
	node -> value = nextOne -> value;
	node -> next = nextOne -> next;
	delete nextOne;
	nextOne = NULL;
}

void print(ListNode* node){
	cout << "The elements in the lists are ";
	while (node -> next != NULL){
		cout << node -> value << ", ";
		node = node -> next;
	} 
	cout << node -> value << endl;	
}

int main(){
	ListNode* node = new ListNode(1);
	//ListNode** input = *node;
	addTail(&node, 2); 
	addTail(&node, 3);
	print(add);
	// deleteNode(&node,4);
	// print(node);
	// recursive(node);
	return 0;
}