#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 100010;

struct node {
  int address, data, next;
  int order;
  int flag;
} chain[maxn];
bool f[maxn] = {false};
bool cmp(node a, node b) {
  if (a.flag != b.flag)
    return a.flag > b.flag;
  else
    return a.order < b.order;
}

int main() {
  for (int i = 0; i < maxn; ++i) {
    chain[i].data = maxn;
    chain[i].next = -1;
    chain[i].flag = -1;
    chain[i].order = maxn;
  }
  int n, begin;
  scanf("%d %d", &begin, &n);
  for (int i = 0; i < n; ++i) {
    int address;
    scanf("%d", &address);
    scanf("%d %d", &chain[address].data, &chain[address].next);
    chain[address].address = address;
  }
  int p = begin;
  int count1 = 0, count2 = 0;
  int o = 1;
  while (p != -1) {
    if (!f[abs(chain[p].data)]) {
      chain[p].flag = 1;
      f[abs(chain[p].data)] = true;
      ++count1;
    } else {
      chain[p].flag = 0;
      ++count2;
    }
    chain[p].order = o++;
    p = chain[p].next;
  }
  sort(chain, chain + maxn, cmp);
  int i;
  for (i = 0; i < count1; ++i) {
    printf("%05d %d ", chain[i].address, chain[i].data);
    if (i < count1 - 1)
      printf("%05d\n", chain[i + 1].address);
    else
      printf("-1\n");
  }
  for (int j = i; j < count1 + count2; ++j) {
    printf("%05d %d ", chain[j].address, chain[j].data);
    if (j < count1 + count2 - 1)
      printf("%05d\n", chain[j + 1].address);
    else
      printf("-1\n");
  }
  return 0;
}