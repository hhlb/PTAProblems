#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  int m, n, k;
  scanf("%d %d %d", &m, &n, &k);
  vector<int> num(n, 0);
  for (int i = 0; i < k; ++i) {
    stack<int> a;
    for (int j = 0; j < n; ++j) {
      scanf("%d", &num[j]);
    }
    int j = 0;
    int now = 2;
    a.push(1);
    while (true) {
      while (a.size() <= m && a.top() != num[j]) {
        a.push(now);
        ++now;
      }
      if (a.size() > m) {
        printf("NO\n");
        break;
      }
      while (!a.empty() && a.top() == num[j]) {
        a.pop();
        ++j;
      }
      if (a.empty()) {
        a.push(now);
        ++now;
      }
      if(j == n){
        printf("YES\n");
        break;
      }
    }
  }
  return 0;
}