// If the step >= m, it can never make it.
#include <math.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int m, n;

bool isPrime(int n) {
  if (n <= 1) return false;
  int sqr = (int)sqrt((double)n);
  for (int i = 2; i <= sqr; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}

int bePrime(int a) {
  if (isPrime(a)) return a;
  while (!isPrime(a)) {
    a += 1;
  }
  return a;
}

int _hash(int key) { return key % m; }

int main() {
  scanf("%d %d", &m, &n);
  m = bePrime(m);
  vector<bool> pos(m, false);
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    int j = 0;
    while (true) {
      int p = _hash(a + j * j);
      if (!pos[p]) {
        pos[p] = true;
        printf("%d", p);
        break;
      } else {
        ++j;
      }
      if (j == m) {
        printf("-");
        break;
      }
    }
    if (i < n - 1) printf(" ");
  }
  return 0;
}