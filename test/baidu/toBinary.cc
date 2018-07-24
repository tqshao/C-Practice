#include <iostream>

using namespace std;

string toBinary(int val){
  string res;
  while(val){
    res = static_cast<char>(val%2 + '0') + res;
    val /= 2;
  }
  return res;
}

int main(){
  int val = 8;
  string s = toBinary(val);
  cout << "The binary representaion of " << val << " is: " << s << endl;
  return 0;
}
