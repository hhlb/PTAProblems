#include <math.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 100010;
vector<int> prime(MAXN);
int pnum = 0;
struct factor {
  int f, n;
} fac[10];
void findPrime() {
  vector<bool> p(MAXN, false);
  for (int i = 2; i < MAXN; ++i) {
    if (!p[i]) {
      p[i] = true;
      prime[pnum++] = i;
      for (int j = i * 2; j < MAXN; j += i) {
        p[j] = true;
      }
    }
  }
}
int main() {
  findPrime();
  int a;
  scanf("%d", &a);
  int num = 0;
  if (a == 1)
    printf("1=1");
  else {
    printf("%d=", a);
    int sqr = (int)sqrt((double)a);
    for (int i = 0; i < pnum && prime[i] <= sqr; ++i) {
      if (a % prime[i] == 0) {
        fac[num].f = prime[i];
        fac[num].n = 0;
        while (a % prime[i] == 0) {
          ++fac[num].n;
          a /= prime[i];
        }
        ++num;
      }
      if (a == 1) break;
    }
    if (a != 1) {
      fac[num].f = a;
      fac[num].n = 1;
      ++num;
    }
    for (int i = 0; i < num; ++i) {
      if (i > 0) printf("*");
      printf("%d", fac[i].f);
      if (fac[i].n > 1) printf("^%d", fac[i].n);
    }
  }
  return 0;
}
