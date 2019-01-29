#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  bool hashtable[96] = {false};
  string a, b;
  cin >> a >> b;
  transform(a.begin(), a.end(), a.begin(), ::toupper);
  transform(b.begin(), b.end(), b.begin(), ::toupper);
  while (!b.empty()) {
    if (a[0] != b[0]) {
      if (!hashtable[a[0]]) {
        hashtable[a[0]] = true;
        cout << a[0];
      }
      a.erase(a.begin());
    } else {
      a.erase(a.begin());
      b.erase(b.begin());
    }
  }
  while(!a.empty()){
    if(!hashtable[a[0]]){
      hashtable[a[0]] = true;
      cout << a[0];
    }
    a.erase(a.begin());
  }
  return 0;
}