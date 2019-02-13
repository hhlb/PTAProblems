#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct mouse {
  int weight, rank;
};

int main() {
  int m, n;
  queue<int> q;
  scanf("%d %d", &m, &n);
  mouse mo[m];
  for (int i = 0; i < m; ++i) {
    int w;
    scanf("%d", &w);
    mo[i].weight = w;
  }
  for (int i = 0; i < m; ++i) {
    int a;
    scanf("%d", &a);
    q.push(a);
  }
  int t = m;
  while (q.size() != 1) {
    int group = (t % n == 0) ? t / n : t / n + 1;
    for (int i = 0; i < group; ++i) {
      int maxid = q.front();
      for (int j = 0; j < n; ++j) {
        if (i * n + j >= t) break;
        if (mo[q.front()].weight > mo[maxid].weight) {
          maxid = q.front();
        }
        mo[q.front()].rank = group + 1;
        q.pop();
      }
      q.push(maxid);
    }
    t = group;
  }
  mo[q.front()].rank = 1;
  for (int i = 0; i < m; ++i) {
    printf("%d", mo[i].rank);
    if (i < m - 1) printf(" ");
  }
  return 0;
}