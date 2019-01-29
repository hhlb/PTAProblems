#include <algorithm>
#include <iostream>
#include <memory.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int b[10000];
  memset(b, -1, sizeof(b));
  int max = 0, min = 100;
  for (int i = 0; i < n; ++i) {
    int c;
    cin >> c;
    if (c > max) max = c;
    if (c < min) min = c;
    if (b[c] < 0) b[c] = 0;
    if (b[c] > 0)
      continue;
    else {
      while (c != 1) {
        if (c % 2 == 0) {
          c /= 2;
          b[c] = 1;
        } else {
          c = (3 * c + 1) / 2;
          b[c] = 1;
        }
      }
    }
  }
  int num = 0;
  for(int i = 1; i <= 100; ++i){
    if(b[i]==0) ++num;
  }
  for (int i = max; i >= min; --i) {
    if (b[i] == 0) {
      cout << i;
      --num;
      if (num) cout << " ";
    }
  }
  return 0;
}