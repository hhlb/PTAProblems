#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> num(n, 0);
  m = m % n;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &num[i]);
  }
  int temp, pos, next;
  if (m) {
    int d = gcd(m, n);
    for (int i = n - m; i < n - m + d; ++i) {
      temp = num[i];
      pos = i;
      do {
        next = (pos - m + n) % n;
        if (next != i)
          num[pos] = num[next];
        else
          num[pos] = temp;
        pos = next;
      } while (pos != i);
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%d", num[i]);
    if (i != n - 1) printf(" ");
  }
  return 0;
}
