#include <cstdio>

const int N = 10000;

int main() {
  char s[N];
  scanf("%s", s);
  int num = 0;
  for (int i = 0; i < N; i++) {
    if (s[i] != '\0')
      ++num;
    else
      break;
  }
  int n = (num + 2) / 3;
  int res = num - n * 2;
  for (int i = 0; i < n; ++i) {
    if (i != n - 1) {
      printf("%c", s[i]);
      for (int j = 0; j < res; ++j) {
        printf(" ");
      }
      printf("%c\n", s[num - i - 1]);
    } else {
      for (int j = i; j < num - n + 1; ++j) {
        printf("%c", s[j]);
      }
      printf("\n");
    }
  }
  return 0;
}