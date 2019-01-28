#include <cstdio>

int main() {
  int c;
  char b;
  scanf("%d %c", &c, &b);
  int a = c;
  a *= 5;
  if (a % 10 >= 5)
    a = a / 10 + 1;
  else
    a /= 10;
  for (int i = 0; i < c; ++i) {
    printf("%c", b);
  }
  printf("\n");
  for (int i = 0; i < a - 2; ++i) {
    printf("%c", b);
    for (int j = 0; j < c - 2; ++j) {
      printf(" ");
    }
    printf("%c\n", b);
  }
  for (int i = 0; i < c; ++i) {
    printf("%c", b);
  }
  return 0;
}