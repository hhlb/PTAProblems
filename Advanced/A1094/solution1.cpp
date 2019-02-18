#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node {
  int level;
  vector<int> child;
};

vector<node> p;

int n, m;
int maxnum = 0, g = 0;
int l[101] = {0};

void l_order() {
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int s = 0;
    int a = q.front();
    q.pop();
    for (int i = 0; i < p[a].child.size(); ++i) {
      p[p[a].child[i]].level = p[a].level + 1;
      ++l[p[a].level + 1];
      q.push(p[a].child[i]);
    }
  }
  for (int i = 0; i < 101; ++i) {
    if (l[i] > maxnum) {
      maxnum = l[i];
      g = i;
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  p.resize(n + 1);
  l[1] = 1;
  for (int i = 0; i < m; ++i) {
    int index, b;
    scanf("%d%d", &index, &b);
    for (int j = 0; j < b; ++j) {
      int a;
      scanf("%d", &a);
      p[index].child.push_back(a);
    }
  }
  p[1].level = 1;
  l_order();
  printf("%d %d", maxnum, g);
  return 0;
}
