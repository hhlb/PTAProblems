#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 100010;

struct node {
  int address, data, next;
  int order;
  bool flag;
} chain[maxn];

bool cmp(node a, node b) {
  if (a.flag != b.flag) {
    return a.flag > b.flag;
  } else
    return a.data < b.data;
}

int main() {
  for (int i = 0; i < maxn; ++i) {
    chain[i].data = maxn;
    chain[i].next = -1;
    chain[i].flag = false;
  }
  int n, begin;
  scanf("%d %d", &n, &begin);
  for (int i = 0; i < n; ++i) {
    int address;
    scanf("%d", &address);
    scanf("%d %d", &chain[address].data, &chain[address].next);
    chain[address].address = address;
  }
  int p = begin;
  int count = 0;
  while (p != -1) {
    chain[p].flag = true;
    p = chain[p].next;
    ++count;
  }
  sort(chain, chain + maxn, cmp);
  n = count;
  if (count == 0) {
    printf("0 -1\n");
    return 0;
  }
  printf("%d %05d\n", n, chain[0].address);
  for (int i = 0; i < n; ++i) {
    printf("%05d %d ", chain[i].address, chain[i].data);
    if (i < n - 1)
      printf("%05d\n", chain[i + 1].address);
    else
      printf("-1\n");
  }
  return 0;
}