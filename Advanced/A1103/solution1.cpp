#include <math.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> fac, ans, temp;
int maxfacsum = -1;
int n, m, p;
void init() {
  int i = 0, t = 0;
  while(t <= n){
    fac.push_back(t);
    t = (int)pow(++i, p);
  }
}
void DFS(int index, int sum, int len, int facsum) {
  if (sum == n && len == m) {
    if (facsum > maxfacsum) {
      maxfacsum = facsum;
      ans = temp;
    }
    return;
  }
  if (sum > n || len > m) return;
  if (index - 1 >= 0) {
    temp.push_back(index);
    DFS(index, sum + fac[index], len + 1, facsum + index);
    temp.pop_back();
    DFS(index - 1, sum, len, facsum);
  }
}

int main() {
  scanf("%d%d%d", &n, &m, &p);
  init();
  DFS(fac.size() - 1, 0, 0, 0);
  if (maxfacsum == -1)
    printf("Impossible");
  else {
    printf("%d = %d^%d", n, ans[0], p);
    for (int i = 1; i < ans.size(); ++i) {
      printf(" + %d^%d", ans[i], p);
    }
  }
  return 0;
}