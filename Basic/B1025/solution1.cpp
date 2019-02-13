#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 100010;

struct node {
  int address, data, next;
  int order;
} chain[maxn];

bool cmp(node a, node b) { return a.order < b.order; }

int main() {
  for (int i = 0; i < maxn; ++i) {
    chain[i].order = maxn;
  }
  int begin, n, m;
  scanf("%d %d %d", &begin, &n, &m);
  for (int i = 0; i < n; ++i) {
    int address;
    scanf("%d", &address);
    scanf("%d %d", &chain[address].data, &chain[address].next);
    chain[address].address = address;
  }
  int p = begin;
  int count = 0;
  while (p != -1) {
    chain[p].order = count++;
    p = chain[p].next;
  }
  sort(chain, chain + maxn, cmp);
  n = count;
  for (int i = 0; i < n / m; ++i) {
    for (int j = (i + 1) * m - 1; j > i * m; --j) {
      printf("%05d %d %05d\n", chain[j].address, chain[j].data,
             chain[j - 1].address);
    }
    printf("%05d %d ", chain[i * m].address, chain[i * m].data);
    if (i < n / m - 1) {
      printf("%05d\n", chain[(i + 2) * m - 1].address);
    } else {
      if (n % m == 0) {
        printf("-1\n");
      } else {
        printf("%05d\n", chain[(i + 1) * m].address);
        for (int k = (i + 1) * m; k < n; ++k) {
          printf("%05d %d ", chain[k].address, chain[k].data);
          if (k < n - 1) {
            printf("%05d\n", chain[k + 1].address);
          } else {
            printf("-1\n");
          }
        }
      }
    }
  }
  return 0;
}
