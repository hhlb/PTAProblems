// CORRECT but TIME OUT
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int u(int l, long long int x, int n, vector<long long int> s) {
  int left = l + 1;
  int right = n - 1;
  if (s[n - 1] <= x) return n;
  while (left < right) {
    int mid = (left + right) / 2;
    if (s[mid] > x)
      right = mid;
    else
      left = mid + 1;
  }
  return left;
}
int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  vector<long long int> numbers(a);
  for (int i = 0; i < a; ++i) {
    scanf("%lld", &numbers[i]);
  }
  sort(numbers.begin(), numbers.end());
  int max = 0;
  for (int i = 0; i < a; ++i) {
    int j = u(i, numbers[i] * b, a, numbers);
    if (j - i > max) max = j - i;
  }
  cout << max;
  return 0;
}