#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;
struct frac {
  long long int up, down;
};

long long int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

frac reduction(frac a) {
  if (a.down < 0) {
    a.up = -a.up;
    a.down = -a.down;
  }
  if (a.up == 0) {
    a.down = 1;
  } else {
    long long int d = gcd(abs(a.up), abs(a.down));
    a.up /= d;
    a.down /= d;
  }
  return a;
}

void printFracRes(frac a) {
  if (a.down == 1)
    printf("%lld", a.up);
  else if (abs(a.up) > abs(a.down))
    printf("%lld %lld/%lld", a.up / a.down, abs(a.up) % abs(a.down), a.down);
  else
    printf("%lld/%lld", a.up, a.down);
}

frac fracSum(frac a, frac b) {
  frac r;
  r.up = a.up * b.down + a.down * b.up;
  r.down = a.down * b.down;
  return reduction(r);
}

int main() {
  int n;
  scanf("%d", &n);
  if (n == 0) {
    printf("0/1");
    return 0;
  }
  frac r, c;
  r.up = 0;
  r.down = 1;
  for (int i = 0; i < n; ++i) {
    scanf("%lld/%lld", &c.up, &c.down);
    r = fracSum(r, c);
  }
  printFracRes(reduction(r));
  return 0;
}
