#include <math.h>
#include <cstdio>
int main() {
  char s[100];
  char* c[10] = {"ling", "yi",  "er", "san", "si",
                 "wu",   "liu", "qi", "ba",  "jiu"};
  int sum = 0;
  int l = 0;
  while ((s[l] = getchar()) != '\n') {
    sum += s[l] - 48;
    ++l;
  }
  int a[10] = {0};
  int i = 0;
  do {
    a[i] = sum % 10;
    sum /= 10;
    ++i;
  } while (sum != 0);
  while (i--) {
    printf("%s", c[a[i]]);
    if (i != 0) printf(" ");
  }
  return 0;
}