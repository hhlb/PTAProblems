#include <cstdio>

int main() {
  int a0, b0, c0, a1, b1, c1;
  long long int k0, k1, m0, m1;
  scanf("%d.%d.%d %d.%d.%d", &a0, &b0, &c0, &a1, &b1, &c1);
  m0 = (c0 + c1) / 29;
  m1 = (c0 + c1) % 29;
  k0 = (b0 + b1 + m0) / 17;
  k1 = (b0 + b1 + m0) % 17;
  printf("%lld.%lld.%lld", a0 + a1 + k0, k1, m1);
  return 0;
}