#include <cstdio>

int main() {
  char* map[10] = {"zero", "one", "two",   "three", "four",
                   "five", "six", "seven", "eight", "nine"};
  char s[105] = {};
  int sum = 0;
  int l = 0;
  while ((s[l] = getchar()) != '\n') {
    sum += s[l] - 48;
    ++l;
  }
  int a[30] = {0};
  int i = 0;
  do {
    a[i] = sum % 10;
    sum /= 10;
    ++i;
  } while (sum != 0);
  while (i--) {
    printf("%s", map[a[i]]);
    if (i != 0) printf(" ");
  }
  return 0;
}