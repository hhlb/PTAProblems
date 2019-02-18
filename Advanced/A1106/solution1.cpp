#include <math.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool cmp(int i, int j) { return i < j; }

struct node {
  vector<int> next;
};

vector<node> nodes;

int n;
int num = 0;
double ori, pe;
double minp = 1e+7;

void dfs(int index, int depth) {
  if (nodes[index].next.empty()) {
    double price = ori * pow(pe, depth);
    if (price < minp) {
      minp = price;
      num = 1;
    } else if ((price - minp) < 1e-5) {
      ++num;
    }
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
    for (int j = 0; j < m; ++j) {
      int s;
      scanf("%d", &s);
      nodes[i].next.push_back(s);
    }
  }
  dfs(0, 0);
  printf("%.4f %d", minp, num);
  return 0;
}
