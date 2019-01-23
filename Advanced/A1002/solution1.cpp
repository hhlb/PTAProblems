#include <cstdio>

int main() {
  float p[1001] = {0};
  int num, e;
  float a;
  for (int j = 0; j < 2; ++j) {
    scanf("%d", &num);
    for (int i = 0; i < num; ++i) {
      scanf("%d %f", &e, &a);
      p[e] += a;
    }
  }
  int count = 0;
  for (int i = 0; i < 1001; ++i) {
    if (p[i] != 0) ++count;
  }
  printf("%d", count);
  for (int i = 1000; i >= 0; --i) {
    if (p[i] != 0) {
      printf(" %d %.1f", i, p[i]);
    }
  }
  return 0;
}