#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  string a;
  getline(cin, a);
  transform(a.begin(), a.end(), a.begin(), ::tolower);
  int b[256] = {0};
  int maxid = 122, maxt = 0;
  while (!a.empty()) {
    ++b[a[0]];
    if (a[0] >= 'a' && a[0] <= 'z' && b[a[0]] >= maxt) {
      if (b[a[0]] == maxt) {
        maxid = (a[0] < maxid) ? a[0] : maxid;
      } else {
        maxt = b[a[0]];
        maxid = a[0];
      }
    }
    a.erase(a.begin());
  }
  printf("%c %d", maxid, maxt);
  return 0;
}