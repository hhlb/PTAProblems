#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  int position[n];
  int left = n - 1;
  for (int i = 0; i < n; ++i) {
    int num;
    cin >> num;
    position[num] = i;
    if (num == i && num != 0) --left;
  }
  int k = 0;
  int res = 0;
  while (left) {
    if (position[0] == 0) {
      while (k < n) {
        if (position[k] != k) {
          swap(position[0], position[k]);
          ++res;
          break;
        }
        ++k;
      }
    }
    while (position[0] != 0) {
      swap(position[0],position[position[0]]);
      ++res;
      --left;
    }
  }
  cout << res;
  return 0;
}