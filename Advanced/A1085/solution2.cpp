#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  int numbers[a];
  for (int i = 0; i < a; ++i) {
    scanf("%d", &numbers[i]);
  }
  sort(numbers, numbers + a);
  int max = 0;
  for (int i = 0; i < a; ++i) {
    int j = upper_bound(numbers + i + 1, numbers + a,
                        (long long int)numbers[i] * b) -
            numbers;
    if (j - i > max) max = j - i;
  }
  cout << max;
  return 0;
}