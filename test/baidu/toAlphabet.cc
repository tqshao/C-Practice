#include <iostream>

using namespace std;

string toAlphabet(int val){
  string res;
  while(val){
    val--;
    res = static_cast<char>(val%26 + 'A') + res;
    val/=26;
  }
  return res;
}

int main(){
  int val = 28;
  string s = toAlphabet(val);
  cout << "The alphabet representation of " << val <<
   " is: " << s << endl;
  return 0;
}
