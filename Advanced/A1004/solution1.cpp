#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node {
  int level;
  vector<int> child;
};

int n, m;

vector<node> nodes;
int l[101] = {0};
int maxlevel = 0;

void l_order() {
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int a = q.front();
    q.pop();
    if (nodes[a].level > maxlevel) {
      maxlevel = nodes[a].level;
    }
    if (nodes[a].child.empty()) {
      ++l[nodes[a].level];
      continue;
    }
    for (int i = 0; i < nodes[a].child.size(); ++i) {
      nodes[nodes[a].child[i]].level = nodes[a].level + 1;
      q.push(nodes[a].child[i]);
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  if (n == 0) return 0;
  nodes.resize(n + 1);
  nodes[1].level = 1;
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    for (int j = 0; j < b; ++j) {
      int c;
      scanf("%d", &c);
      nodes[a].child.push_back(c);
    }
  }
  l_order();
  for (int i = 1; i <= maxlevel; ++i) {
    printf("%d", l[i]);
    if (i != maxlevel) printf(" ");
  }
  return 0;
}
