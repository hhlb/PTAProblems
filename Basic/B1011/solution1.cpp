#include <cstdio>

int main() {
  int T;
  int num = 1;
  scanf("%d", &T);
  while (--T) {
    long long int a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    if (a + b > c) {
      printf("Case #%d: true\n", num++);
    } else {
      printf("Case #%d: true\n", num++);
    }
  }
  return 0;
}