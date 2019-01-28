#include <cstdio>

int main() {
  int a, b, t;
  scanf("%d%d", &a, &b);
  t = b - a;
  if (t % 100 >= 50) {
    t = t / 100 + 1;
  } else {
    t /= 100;
  }
  printf("%02d:%02d:%02d", t / 3600, t % 3600 / 60, t % 60);
  return 0;
}