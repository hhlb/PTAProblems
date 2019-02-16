#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

const int maxn = 50;
struct Node {
  Node *lchild, *rchild;
  int data;
};

int n;
int post[maxn], in[maxn];

Node* create(int postL, int postR, int inL, int inR) {
  if (postL > postR) return NULL;
  Node* root = new Node;
  root->data = post[postR];
  int k;
  for (k = inL; k <= inR; ++k) {
    if (in[k] == post[postR]) break;
  }
  int numLeft = k - inL;
  root->lchild = create(postL, postL + numLeft - 1, inL, k - 1);
  root->rchild = create(postL + numLeft, postR - 1, k + 1, inR);
  return root;
}

void bfs(Node* node) {
  queue<Node*> q;
  q.push(node);
  int i = 0;
  while (!q.empty()) {
    Node* no = q.front();
    printf("%d", no->data);
    ++i;
    if (i != n) printf(" ");
    if (no->lchild != NULL) {
      q.push(no->lchild);
    }
    if (no->rchild != NULL) {
      q.push(no->rchild);
    }
    q.pop();
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &post[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &in[i]);
  }
  Node* root = create(0, n - 1, 0, n - 1);
  bfs(root);
  return 0;
}