// same as leetcode 155
#include<iostream>
#include<vector>

using namespace std;

class minStack{
public:
  minStack();
  void push(int val);
  void pop(int val);
  int top();
  int min();

private:
  stack<int> s;
  stack<int> min;
}

void minStack::push(int val){
  s.push(val);
  if(min.empty()) min.push(val);

}
