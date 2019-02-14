#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

const int maxn = 100010;

struct node {
  char data;
  int address, next;
} chain[maxn];

int main() {
  int abegin, bbegin, n;
  set<int> a;
  scanf("%d %d %d", &abegin, &bbegin, &n);
  for (int i = 0; i < n; ++i) {
    int address;
    scanf("%d ", &address);
    scanf("%c %d", &chain[address].data, &chain[address].next);
    chain[address].address = address;
  }
  int p = abegin;
  while (p != -1) {
    a.insert(p);
    p = chain[p].next;
  }
  p = bbegin;
  while (p != -1) {
    if (a.find(p) != a.end()) {
      printf("%05d", p);
      break;
    } else {
      p = chain[p].next;
    }
  }
  if (p == -1) {
    printf("-1");
  }
  return 0;
}