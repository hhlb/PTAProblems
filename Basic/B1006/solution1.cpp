#include <cstdio>

int main() {
  int input;
  char mp[3] = {' ', 'S', 'B'};
  scanf("%d", &input);
  int i = 0;
  int a[3] = {0};
  do {
    a[i] = input % 10;
    input /= 10;
    ++i;
  } while (input != 0);
  while (i--) {
    if (i != 0) {
      for (int c = 0; c < a[i]; ++c) {
        printf("%c", mp[i]);
      }
    } else {
      for (int c = 0; c < a[i]; ++c) {
        printf("%d", c + 1);
      }
    }
  }
  return 0;
}