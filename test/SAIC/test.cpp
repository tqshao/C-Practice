#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Tree{
  int val;
  Tree* left;
  Tree* right;
  Tree(int n): val(n), left(NULL), right(NULL){}
};

int visibleNodes(Tree* node, int maxVal){
  if(node == NULL) return 0;
  int count = 0;
  if(maxVal <= node->val){
    count = 1;
    maxVal = node->val;
  }
  return count + visibleNodes(node->left, maxVal)
               + visibleNodes(node->right, maxVal);
}

int main(){
  Tree* root = new Tree(3);
  Tree* n1 = new Tree(2);
  Tree* n2 = new Tree(3);
  root->left =  n1;
  root->right = n2;
  int count = visibleNodes(root, INT_MIN);
  cout << "The result is " << count << endl;
  return 0;

}
