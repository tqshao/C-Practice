#include <iostream>
#include <vector>

using namespace std;

vector<int> toBinary(int num){
  vector<int> res;
  while(num > 1){
    res.insert(res.begin(),num%2);
    num = num / 2;
  }
  if(num == 1) res.insert(res.begin(),1);
  return res;
}

ostream & operator << (ostream &out, vector<int> &v){
  for(int i = 0; i < v.size(); i++){
    out << v[i];
  }
  return out;
}
void print(vector<int> v){
  for(int i = 0; i < v.size(); i++){
    cout << v[i];
  }
  cout << endl;
}

int main(){
  int num;
  cout << "Input a number: " ;
  cin >> num;
  vector<int> v = toBinary(num);
  cout << "The binary representation of " << num << " is " << v << endl;
  return 0;
}
