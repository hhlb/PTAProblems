#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  n += 1;
  vector<bool> p(n, false);
  vector<int> prime(n, -1);
  prime[0] = -1;
  int pnum = 1;
  int res = 0;
  for (int i = 2; i < n; ++i) {
    if (!p[i]) {
      prime[pnum] = i;
      if (prime[pnum] - prime[pnum - 1] == 2) {
        ++res;
      }
      ++pnum;
      for (int j = 2 * i; j < n; j += i) {
        p[j] = true;
      }
    }
  }
  printf("%d", res);
  return 0;
}
