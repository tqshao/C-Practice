#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

// reverse the string in the parenthesis and delete the parenthesis

void invert(string &s){
  string::iterator start;
  string::iterator end;
  for(auto it = s.begin(); it < s.end(); ++it){
    if(*it == '(') {
      start = it;
      s.erase(start);
    }
    if(*it == ')'){
      end = it;
      s.erase(end);
      end--;
      while(start < end){
        char tmp = *start;
        *start = *end;
        *end = tmp;
        start++;
        end--;
      }
    }
  }
}

int main(){
  string s = "abc (oxox) fg (123)";
  invert(s);
  cout << "The partial inversion is " << s << endl;
  return 0;
}
