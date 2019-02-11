#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1000001;
vector<int> prime(MAXN);
vector<bool> p(MAXN);

void findPrime(int n) {
  int num = 0;
  for (int i = 2; i < MAXN; ++i) {
    if (!p[i]) {
      prime[num++] = i;
      if (num >= n) break;
      for (int j = 2 * i; j < MAXN; j += i) {
        p[j] = true;
      }
    }
  }
}

int main() {
  int m, n, count;
  scanf("%d%d", &m, &n);
  count = 0;
  findPrime(n);
  for (int i = m; i <= n; ++i) {
    printf("%d", prime[i - 1]);
    ++count;
    if (count % 10 != 0 && i < n) {
      printf(" ");
    } else {
      count = 0;
      printf("\n");
    }
  }
  return 0;
}