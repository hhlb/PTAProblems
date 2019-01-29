#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  bool hashtable[123] = {false};
  string a, b;
  getline(cin, a);
  transform(a.begin(), a.end(), a.begin(), ::tolower);
  getline(cin, b);
  while (!a.empty()) {
    hashtable[a[0]] = true;
    if (a[0] >= 97 && a[0] <= 122) hashtable[a[0] - 32] = true;
    a.erase(a.begin());
  }
  if (hashtable[43]) {
    for (int j = 65; j <= 90; ++j) {
      hashtable[j] = true;
    }
  }
  while (!b.empty()) {
    if (!hashtable[b[0]]) {
      cout << b[0];
    }
    b.erase(b.begin());
  }
  return 0;
}
