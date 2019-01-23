#include <math.h>
#include <cstdio>
int main() {
  int n;
  int sum = 0;
  scanf("%d", &n);
  int dis[n + 1];
  dis[0] = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    sum += a;
    dis[i + 1] = sum;
  }
  int testnum;
  scanf("%d", &testnum);
  int result[testnum];
  for (int i = 0; i < testnum; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    int sum1 = (dis[b - 1] > dis[a - 1]) ? (dis[b - 1] - dis[a - 1])
                                         : (dis[a - 1] - dis[b - 1]);
    int sum2 = sum - sum1;
    result[i] = (sum1 > sum2) ? sum2 : sum1;
  }
  for (int i = 0; i < testnum; ++i) {
    printf("%d\n", result[i]);
  }
  return 0;
}