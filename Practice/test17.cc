#include <iostream>
using namespace std;

// merge two linked lists
struct ListNode{
	int value;
	ListNode* next;
	ListNode(int x = 0): value(x), next(NULL){}
};

ListNode* merge(ListNode* node1, ListNode* node2){
	ListNode* node(0);
	ListNode* p = node;
	
	while(!node1 && !node2){
		if (node1 -> value < node2 -> value){
			node1
			node -> next = node1;
			node1 = node1 -> next;
		}
		else {
			node -> next = node2;
			node2 = node2 -> next;
		}
	}
	if(!node1){
		node -> next = node1;
	}
	if(!node2){
		node -> next = node2;  		
	}
	
	return p -> next;
}

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

void print(ListNode* node){
	cout << "The elements in the lists are ";
	while (node -> next != NULL){
		cout << node -> value << ", ";
		node = node -> next;
	} 
	cout << node -> value << endl;	
}


int main(){
	ListNode* node1 = new ListNode(1);
	//ListNode** input = *node;
	addTail(&node1, 2); 
	addTail(&node1, 3);

	ListNode* node2 = new ListNode(1);
	//ListNode** input = *node;
	addTail(&node2, 2); 
	addTail(&node2, 3);

	ListNode* node = merge(node1,node2);
	//print(node);

	return 0;
}