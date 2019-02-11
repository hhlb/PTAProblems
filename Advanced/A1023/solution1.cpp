#include <memory.h>
#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 50;

struct bigint {
  int d[maxn];
  int length;
  bigint() {
    memset(d, 0, sizeof(d));
    length = 0;
  }
};

void coll(bigint a, int b[]) {
  for (int i = 0; i < a.length; ++i) {
    ++b[a.d[i]];
  }
}

bool equal(int a[], int b[]) {
  for (int i = 0; i < 9; ++i) {
    if (a[i] != b[i]) return false;
  }
  return true;
}

bigint s2bigint(char s[]) {
  bigint res;
  int len = strlen(s);
  for (int i = 0; i < len; ++i) {
    res.d[i] = s[len - i - 1] - '0';
  }
  res.length = len;
  return res;
}

bigint mulBigint(bigint a) {
  bigint res;
  res.length = a.length + 1;
  int r = 0;
  for (int i = 0; i < res.length; ++i) {
    r += 2 * a.d[i];
    res.d[i] = r % 10;
    r /= 10;
  }
  while (res.length >= 1 && res.d[res.length - 1] == 0) {
    --res.length;
  }
  return res;
}

int main() {
  bigint a;
  char s[maxn];
  scanf("%s", s);
  a = s2bigint(s);
  int num1[10] = {0};
  int num2[10] = {0};
  coll(a, num1);
  bigint b = mulBigint(a);
  coll(b, num2);
  printf("%s", equal(num1, num2) ? "Yes\n" : "No\n");
  for (int i = b.length - 1; i >= 0; --i) {
    printf("%d", b.d[i]);
  }
  return 0;
}