#include <cstdio>

int main() {
  char s[80];
  char *p1, *p2, *p3;
  int num = 0;
  while ((s[num] = getchar()) != '\n') {
    ++num;
  }
  p2 = &s[num];
  for (int i = num; i >= 0; --i) {
    if (i == 0) {
      p3 = s;
      while (p3 != p2) {
        printf("%c", *p3);
        ++p3;
      }
    } else if (s[i] == ' ') {
      p1 = &s[i];
      p3 = p1;
      while (p3 != p2 - 1) {
        ++p3;
        printf("%c", *p3);
      }
      printf(" ");
      p2 = p1;
    }
  }
  return 0;
}
