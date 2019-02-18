#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int maxn = 101;
int n, k, w;
int path[maxn] = {0};
struct node {
  int weight;
  vector<int> child;
} nodes[maxn];

bool cmp(int a, int b) { return nodes[a].weight > nodes[b].weight; }

void dfs(int index, int num, int sum) {
  if (sum > w) return;
  if (sum == w) {
    if (nodes[index].child.size() != 0) return;
    for (int i = 0; i < num; ++i) {
      printf("%d", nodes[path[i]].weight);
      if (i < num - 1)
        printf(" ");
      else
        printf("\n");
    }
    return;
  }
  for (int i = 0; i < nodes[index].child.size(); ++i) {
    int child = nodes[index].child[i];
    path[num] = child;
    dfs(child, num + 1, sum + nodes[child].weight);
  }
}

int main() {
  scanf("%d%d%d", &n, &k, &w);
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    nodes[i].weight = a;
  }
  for (int i = 0; i < k; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    for (int j = 0; j < b; ++j) {
      int c;
      scanf("%d", &c);
      nodes[a].child.push_back(c);
    }
    sort(nodes[a].child.begin(), nodes[a].child.end(), cmp);
  }
  dfs(0, 1, nodes[0].weight);
  return 0;
}
