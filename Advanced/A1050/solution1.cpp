#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  string a, b;
  bool c[256] = {false};
  getline(cin, a);
  getline(cin, b);
  while(!b.empty()){
    c[b[0]] = true;
    b.erase(b.begin());
  }
  while(!a.empty()){
    if(!c[a[0]]) cout << a[0];
    a.erase(a.begin());
  }
  return 0;
}