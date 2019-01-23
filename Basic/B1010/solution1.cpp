#include <cstdio>

int main() {
  int num[1010] = {0};
  int a, e, count = 0;
  while (scanf("%d%d", &a, &e) != EOF) {
    num[e] = a;
  }
  num[0] = 0;
  for (int i = 1; i <= 1000; ++i) {
    num[i - 1] = num[i] * i;
    num[i] = 0;
    if (num[i - 1] != 0) ++count;
  }
  if (count == 0)
    printf("0 0");
  else {
    for (int i = 1000; i >= 0; --i) {
      if (num[i] != 0) {
        printf("%d %d", num[i], i);
        --count;
        if (count != 0) printf(" ");
      }
    }
  }
  return 0;
}