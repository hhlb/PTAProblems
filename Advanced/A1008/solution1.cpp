#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int now = 0;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    int s = a - now;
    if (s > 0) {
      sum += s * 6;
    } else if (s < 0) {
      sum += (-s) * 4;
    }
    sum += 5;
    now = a;
  }
  printf("%d", sum);
  return 0;
}
