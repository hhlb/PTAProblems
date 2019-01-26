#include <cstdio>

int main() {
  int a, b, c;
  scanf("%d%d", &a, &b);
  c = a + b;
  char flag;
  char res[12] = {};
  if (c < 0) {
    flag = '-';
    c = -c;
  } else
    flag = '+';
  int i = 11;
  int k = 0;
  do {
    res[i] = c % 10 + 48;
    c /= 10;
    --i;
    ++k;
    if (c != 0 && k == 3) {
      res[i] = ',';
      --i;
      k = 0;
    }
  } while (c != 0);
  if (flag == '-') {
    printf("-");
  }
  for (int j = 0; j < 12; ++j) {
    if (res[j] != '\0') {
      printf("%c", res[j]);
    }
  }
  return 0;
}