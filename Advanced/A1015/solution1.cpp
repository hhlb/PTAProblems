#include <math.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n) {
  if (n <= 1) return false;
  int sqr = (int)sqrt((double)n);
  for (int i = 2; i <= sqr; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}

int main() {
  int n, radix;
  vector<int> a(110, 0);
  while (scanf("%d", &n) != EOF) {
    if (n < 0) break;
    scanf("%d", &radix);
    if (!isPrime(n))
      printf("No\n");
    else {
      int len = 0;
      do {
        a[len++] = n % radix;
        n /= radix;
      } while (n != 0);
      int sum = 0;
      for (int i = 0; i < len; ++i) {
        sum = sum * radix + a[i];  // Inverse Sequence Conversion Computation
      }
      if (isPrime(sum))
        printf("Yes\n");
      else
        printf("No\n");
    }
  }
  return 0;
}