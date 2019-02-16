#include <string.h>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

const int maxn = 50;
int num = 0;
int n;

struct Node {
  int data;
  Node* lchild;
  Node* rchild;
};

int pre[maxn], in[maxn];

Node* create(int preL, int preR, int inL, int inR) {
  if (preL > preR) return NULL;
  Node* root = new Node;
  root->data = pre[preL];
  int k;
  for (k = inL; k <= inR; ++k) {
    if (in[k] == pre[preL]) break;
  }
  int leftNum = k - inL;
  root->lchild = create(preL + 1, preL + leftNum, inL, k - 1);
  root->rchild = create(preL + leftNum + 1, preR, k + 1, inR);
  return root;
}

void post(Node* root) {
  if (root == NULL) return;
  post(root->lchild);
  post(root->rchild);
  printf("%d", root->data);
  ++num;
  if (num < n) printf(" ");
}

int main() {
  scanf("%d", &n);
  stack<int> st;
  char s[5];
  int prenum = 0, innum = 0;
  int x;
  for (int i = 0; i < 2 * n; ++i) {
    scanf("%s", s);
    if (strcmp(s, "Push") == 0) {
      scanf("%d", &x);
      pre[prenum++] = x;
      st.push(x);
    } else {
      in[innum++] = st.top();
      st.pop();
    }
  }
  Node* root = create(0, n - 1, 0, n - 1);
  post(root);
  return 0;
}