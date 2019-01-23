#include <cstdio>

int main() {
  float p[1001] = {0};
  float p1[1001] = {0};
  float r[2010] = {0};
  int num1, num2, e;
  float a;

  scanf("%d", &num1);
  for (int i = 0; i < num1; ++i) {
    scanf("%d %f", &e, &a);
    p[e] = a;
  }
  scanf("%d", &num2);
  for (int i = 0; i < num2; ++i) {
    scanf("%d %f", &e, &a);
    p1[e] = a;
  }

  for (int i = 0; i < 1001; ++i) {
    for (int j = 0; j < 1001; ++j) {
      r[i + j] += p[i] * p1[j];
    }
  }

  int count = 0;
  for (int i = 0; i < 2010; ++i) {
    if (r[i] != 0) ++count;
  }
  printf("%d", count);
  for (int i = 2000; i >= 0; --i) {
    if (r[i] != 0) {
      printf(" %d %.1f", i, r[i]);
    }
  }
  return 0;
}