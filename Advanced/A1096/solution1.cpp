#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;

long long int sqrtInt(long long int a) { return (long long int)sqrt(1.0 * a); }

int main() {
  long long int n;
  scanf("%lld", &n);
  long long int sqr = sqrtInt(n);
  int ansBegin = 0;
  int ansLength = 0;
  for (long long int i = 2; i <= sqr; ++i) {
    long long int j = i;
    long long int temp = 1;
    while (true) {
      temp *= j;
      if (n % temp != 0) break;
      if (j - i + 1 > ansLength) {
        ansLength = j - i + 1;
        ansBegin = i;
      }
      ++j;
    }
  }
  if (ansLength == 0) {
    printf("1\n%lld", n);
    return 0;
  } else {
    printf("%d\n", ansLength);
    for (long long int i = 0; i < ansLength; ++i) {
      printf("%lld", ansBegin + i);
      if (i < ansLength - 1) printf("*");
    }
  }
  return 0;
}