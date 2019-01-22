#include <cstdio>

int main() {
  int n;
  int count[5] = {0};
  int a2 = 0, a4 = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int number;
    scanf("%d", &number);
    if (number % 5 == 0) {
      if (number % 2 == 0) count[0] += number;
    } else if (number % 5 == 1) {
      if (a2 % 2 == 0) 
        count[1] += number;
      else
        count[1] -= number;
      ++a2;
    } else if (number % 5 == 2) {
      ++count[2];
    } else if (number % 5 == 3) {
      count[3] += number;
      ++a4;
    } else {
      if (number > count[4]) {
        count[4] = number;
      }
    }
  }
  if (count[0] == 0)
    printf("N ");
  else
    printf("%d ", count[0]);
  if (a2 == 0)
    printf("N ");
  else
    printf("%d ", count[1]);
  if (count[2] == 0)
    printf("N ");
  else
    printf("%d ", count[2]);
  if (count[3] == 0)
    printf("N ");
  else
    printf("%.1f ", (float)count[3] / a4);
  if (count[4] == 0)
    printf("N");
  else
    printf("%d", count[4]);
  return 0;
}
