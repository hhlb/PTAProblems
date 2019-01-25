#include <cstdio>
int main() {
  int a[3];
  for (int i = 0; i < 3; ++i) scanf("%d", &a[i]);
  int o[6];
  int j = 0;
  for (int i = 0; i < 3; ++i) {
    do {
      o[j] = a[i] % 13;
      a[i] /= 13;
      o[j + 1] = a[i] % 13;
      a[i] /= 13;
      j += 2;
    } while (a[i] != 0);
  }
  printf("#");
  for (int i = 0; i < 6; i += 2) {
    if (o[i + 1] >= 10)
      printf("%c", o[i + 1] + 55);
    else
      printf("%d", o[i + 1]);
    if (o[i] >= 10)
      printf("%c", o[i] + 55);
    else
      printf("%d", o[i]);
  }
  return 0;
}