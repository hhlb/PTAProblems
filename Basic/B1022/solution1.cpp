#include <cstdio>
int main() {
  long long int a, b, c, d;
  int s[64];
  scanf("%lld%lld%lld", &a, &b, &c);
  long long int n = a + b;
  int i = 0;
  do {
    d = n % c;
    s[i] = d;
    n /= c;
    ++i;
  } while (n != 0);
  for (int j = i - 1; j >= 0; --j) {
    printf("%d", s[j]);
  }
  return 0;
}