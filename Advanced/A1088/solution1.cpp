/**
 * Fuck prints.
 */
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;
struct frac {
  long long int up, down;
};

frac a, b, sumRes, decRes, mulRes, devRes;

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
  if (a.down == 0) {
    printf("Inf");
  } else if (a.up < 0) {
    if (a.down == 1)
      printf("(%lld)", a.up);
    else if (abs(a.up) > abs(a.down))
      printf("(%lld %lld/%lld)", a.up / a.down, abs(a.up) % abs(a.down),
             a.down);
    else
      printf("(%lld/%lld)", a.up, a.down);
  } else if (a.up >= 0) {
    if (a.down == 1)
      printf("%lld", a.up);
    else if (abs(a.up) > abs(a.down))
      printf("%lld %lld/%lld", a.up / a.down, abs(a.up) % abs(a.down), a.down);
    else
      printf("%lld/%lld", a.up, a.down);
  }
}

frac fracSum(frac a, frac b) {
  frac r;
  r.up = a.up * b.down + a.down * b.up;
  r.down = a.down * b.down;
  return reduction(r);
}

frac fracDec(frac a, frac b) {
  frac r;
  r.up = a.up * b.down - a.down * b.up;
  r.down = a.down * b.down;
  return reduction(r);
}

frac fracMul(frac a, frac b) {
  frac r;
  r.up = a.up * b.up;
  r.down = a.down * b.down;
  return reduction(r);
}

frac fracDev(frac a, frac b) {
  frac r;
  r.up = a.up * b.down;
  r.down = a.down * b.up;
  return reduction(r);
}

void print(){
  printFracRes(a);
  printf(" + ");
  printFracRes(b);
  printf(" = ");
  printFracRes(sumRes);
  printf("\n");

  printFracRes(a);
  printf(" - ");
  printFracRes(b);
  printf(" = ");
  printFracRes(decRes);
  printf("\n");

  printFracRes(a);
  printf(" * ");
  printFracRes(b);
  printf(" = ");
  printFracRes(mulRes);
  printf("\n");

  printFracRes(a);
  printf(" / ");
  printFracRes(b);
  printf(" = ");
  printFracRes(devRes);
  printf("\n");
}

int main() {
  scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
  a = reduction(a);
  b = reduction(b);
  sumRes = fracSum(a, b);
  decRes = fracDec(a, b);
  mulRes = fracMul(a, b);
  devRes = fracDev(a, b);
  print();
  return 0;
}
