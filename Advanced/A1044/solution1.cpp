/**
 * Although the time is limited to 300ms.
 * It would use about 220ms when use cin/cout, 
 * but the better performance is 48ms.
 * So can it cut time to 100ms or less.
 * If there is nothing with string please 
 * use cstdio(scanf/printf) to save time.
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> sum, ans;
int n, m;
void binarySearch(int i, int& j, int& a) {
  int left = i;
  int right = n;
  while (left < right) {
    int mid = (left + right) / 2;
    if (sum[mid] - sum[i - 1] >= m) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  j = right;
  a = sum[j] - sum[i - 1];
}
int main() {
  scanf("%d %d", &n, &m);
  sum.resize(n + 1);
  sum[0] = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d",&sum[i]);
    sum[i] += sum[i - 1];
  }
  int min = sum[n];
  for (int i = 1; i <= n; ++i) {
    int j, temp;
    binarySearch(i, j, temp);
    if (temp > min) continue;
    if (temp >= m) {
      if (temp < min) {
        ans.clear();
        min = temp;
      }
      ans.push_back(i);
      ans.push_back(j);
    }
  }
  for (int i = 0; i < ans.size(); i += 2) {
    printf("%d-%d\n", ans[i], ans[i+1]);
  }
  return 0;
}