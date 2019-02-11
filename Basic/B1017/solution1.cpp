#include <memory.h>
#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 1010;

struct bigint {
  int d[maxn];
  int length;
  bigint() {
    memset(d, 0, sizeof(d));
    length = 0;
  }
};

bigint s2bigint(char s[]) {
  bigint res;
  int len = strlen(s);
  for (int i = 0; i < len; ++i) {
    res.d[i] = s[i] - '0';
  }
  res.length = len;
  return res;
}

bigint devBigInt(bigint a, int b, int &c) {
  int len = a.length;
  int r = 0;
  bigint result;
  result.length = len;
  for (int i = 0; i < len; ++i) {
    r = r * 10 + a.d[i];
    if (r < b)
      result.d[i] = 0;
    else {
      result.d[i] = r / b;
      r = r % b;
    }
  }
  c = r;
  return result;
}

int main() {
  char s[maxn];
  int b;
  scanf("%s %d", s, &b);
  bigint a = s2bigint(s);
  int c = 0, num = 0;
  bigint d = devBigInt(a, b, c);
  int j = 0;
  for (int i = 0; i < d.length; ++i) {
    j = i;
    if (d.d[i] != 0) break;
  }
  for (int i = j; i < d.length; ++i) {
    printf("%d", d.d[i]);
  }
  printf(" %d", c);
  return 0;
}