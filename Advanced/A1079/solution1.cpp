/**
 * if we create a big array with maxn, the point 3 could be Segmentation fault.
 *
 * 1. resize the array so use vector
 * 2. control the size of Node with less data in the struct
 * 3. dfs with simple data such as index and depth instead of node
 */

#include <math.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool cmp(int i, int j) { return i < j; }

struct node {
  int nu;
  vector<int> next;
};

vector<node> nodes;

int n;
double ori, pe;
double sum = 0;

void dfs(int index, int depth) {
  if (nodes[index].next.empty()) {
    sum += pow(pe, depth) * nodes[index].nu * ori;
    return;
  }
  for (int i = 0; i < nodes[index].next.size(); ++i) {
    dfs(nodes[index].next[i], depth + 1);
  }
}

int main() {
  scanf("%d %lf %lf", &n, &ori, &pe);
  nodes.resize(n);
  pe = pe / 100 + 1.0;
  for (int i = 0; i < n; ++i) {
    int m;
    scanf("%d", &m);
    if (m == 0) {
      scanf("%d", &nodes[i].nu);
      continue;
    }
    for (int j = 0; j < m; ++j) {
      int s;
      scanf("%d", &s);
      nodes[i].next.push_back(s);
    }
  }
  dfs(0, 0);
  printf("%.1f", sum);
  return 0;
}
