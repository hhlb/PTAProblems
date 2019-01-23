#include <cstdio>

int main() {
  long long int a, b, c;
  int casenum = 1;
  int num;
  scanf("%d", &num);
  while (num--) {
    bool result;
    scanf("%lld%lld%lld", &a, &b, &c);
    long long int res = a + b;
    if (a > 0 && b > 0 && res < 0)
      result = true;
    else if (a < 0 && b < 0 && res >= 0)
      result = false;
    else
      result = (res > c);
    if (result)
      printf("Case #%d: true\n", casenum++);
    else
      printf("Case #%d: false\n", casenum++);
  }
  return 0;
}