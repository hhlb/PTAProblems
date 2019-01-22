#include <cstdio>

int main() {
  int t;
  int a = 0, b = 0;
  scanf("%d", &t);
  while (--t) {
    int a0, a1, b0, b1;
    scanf("%d%d%d%d", &a0, &a1, &b0, &b1);
    if (a0 + b0 == a1 && a0 + b0 != b1) ++b;
    if (a0 + b0 != a1 && a0 + b0 == b1) ++a;
  }
  printf("%d %d", a, b);
  return 0;
}