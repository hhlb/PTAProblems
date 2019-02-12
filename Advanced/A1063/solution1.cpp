#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

double calSimilarity(set<int> a, set<int> b) {
  int same = 0, tu = 0;
  tu = a.size() + b.size();
  set<int>::iterator it = a.begin();
  while (it != a.end()) {
    if (b.find(*it) != b.end()) {
      ++same;
      --tu;
    }
    ++it;
  }
  return (1.0 * same) / tu;
}

int main() {
  int n, m;
  scanf("%d", &n);
  set<int> s[n + 1];
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &m);
    for (int j = 0; j < m; ++j) {
      int a;
      scanf("%d", &a);
      s[i].insert(a);
    }
  }
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    double res = calSimilarity(s[a], s[b]);
    printf("%.1f%%\n", res * 100);
  }
  return 0;
}