#include <cstdio>

int main() {
  int n;
  char b;
  scanf("%d %c", &n, &b);
  int c, res;
  if (n > 0) {
    for (int i = 1; i < 24; ++i) {
      if (2 * i * i - 1 > n) {
        c = i - 1;
        break;
      }
    }
    res = n - 2 * c * c + 1;
  } else
    res = 0;
  for (int i = 0; i < c; ++i) {
    for (int j = 0; j < i; ++j) {
      printf(" ");
    }
    for (int j = 0; j < c * 2 - 1 - i * 2; ++j) {
      printf("%c", b);
    }
    // for (int j = 0; j < i; ++j) {
    //   printf(" ");
    // }
    printf("\n");
  }
  for (int i = 1; i < c; ++i) {
    for (int j = 0; j < c - i - 1; ++j) {
      printf(" ");
    }
    for (int j = 0; j < i * 2 + 1; ++j) {
      printf("%c", b);
    }
    // for (int j = 0; j < c - i - 1; ++j) {
    //   printf(" ");
    // }
    printf("\n");
  }
  printf("%d", res);
  return 0;
}