#include <cstdio>

int main() {
  int n;
  int count[5] = {0};
  int a2 = 0, a4 = 0, a5_max = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int number;
    scanf("%d", &number);
    if (number % 10 == 0) {
      count[0] += number;
    } else if (number % 5 == 1) {
      count[1] += number * (-1) ^ a2;
      ++a2;
    } else if (number % 5 == 2) {
      ++count[2]
    } else if (number % 5 == 3) {
      count[3] += number;
      ++a4
    } else {
      if (number > a5_max) {
        a5_max = number;
      }
    }
  }
  count[3] /= a4;
  count[4] = a5_max;
  for (int i = 0; i < n; ++i) {
    if (count[i] == 0) printf("N");
    if (i != n - 1) printf(" ");
  }
  return 0;
}