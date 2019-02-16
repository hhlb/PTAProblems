#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, rootIndex;
vector<bool> isroot(12, true);

struct node {
  int lchild;
  int rchild;
  int index;
};

bool judge(char a) {
  if (a == '-') return false;
  isroot[a - '0'] = false;
  return true;
}

void bfs(vector<node> nodes) {
  queue<int> q;
  q.push(rootIndex);
  int i = 0;
  while (!q.empty()) {
    int j = q.front();
    q.pop();
    printf("%d", j);
    ++i;
    if (i < n) printf(" ");
    if (nodes[j].lchild != -1) q.push(nodes[j].lchild);
    if (nodes[j].rchild != -1) q.push(nodes[j].rchild);
  }
}

int num = 0;

void inorder(vector<node> nodes, int k) {
  if (k == -1) return;
  inorder(nodes, nodes[k].lchild);
  printf("%d", k);
  ++num;
  if (num < n) printf(" ");
  inorder(nodes, nodes[k].rchild);
}

int main() {
  scanf("%d", &n);
  getchar();
  char a, b;
  vector<node> nodes(n);

  for (int i = 0; i < n; ++i) {
    scanf("%c %c", &a, &b);
    getchar();
    nodes[i].index = i;
    nodes[i].rchild = judge(a) ? a - '0' : -1;
    nodes[i].lchild = judge(b) ? b - '0' : -1;
  }

  for (int i = 0; i < n; ++i) {
    if (isroot[i]) {
      rootIndex = i;
      break;
    }
  }
  bfs(nodes);
  printf("\n");
  inorder(nodes, rootIndex);
  return 0;
}