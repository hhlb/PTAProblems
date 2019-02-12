#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
map<long long int, int> c;

int main() {
  int m, n;
  scanf("%d %d", &m, &n);
  int max = m * n / 2;
  map<long long int, int>::iterator it = c.begin();
  for (int i = 0; i < m * n; ++i) {
    long long int a;
    scanf("%lld", &a);
    if (c.find(a) == c.end()) {
      c.insert(make_pair(a, 1));
    } else {
      ++c[a];
    }
    if (c[a] > max) {
      it = c.find(a);
    }
  }
  printf("%lld", it->first);
  return 0;
}