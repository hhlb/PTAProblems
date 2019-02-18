#include <math.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct node {
  double price;
  vector<int> child;
};

vector<node> nodes;

int n;
int num = 0;
double ori, pe;
double maxp = 0.0;

void dfs(int index, int depth, double p) {
  if (depth) nodes[index].price = p * pe;
  if (nodes[index].child.empty()) {
    if (nodes[index].price > maxp) {
      maxp = nodes[index].price;
      num = 1;
    } else if (nodes[index].price == maxp) {
      ++num;
    }
    return;
  }
  for (int i = 0; i < nodes[index].child.size(); ++i) {
    dfs(nodes[index].child[i], depth + 1, nodes[index].price);
  }
}

int main() {
  scanf("%d %lf %lf", &n, &ori, &pe);
  nodes.resize(n + 1);
  pe = pe / 100 + 1;
  nodes[0].price = ori;
  for (int i = 1; i <= n; ++i) {
    int a;
    scanf("%d", &a);
    nodes[a + 1].child.push_back(i);
  }
  dfs(0, 0, ori);
  printf("%.2f %d", maxp / pe, num);
  return 0;
}
