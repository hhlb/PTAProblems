/**
 * Print a '\n' at the end of the answers to avoid Illegal Format.
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 100010;
const int INF = 1e+9;
int main() {
  int max = 0;
  int min = INF;
  int n;
  scanf("%d", &n);
  int numbers[n];
  bool les[n];
  bool beg[n];
  for (int i = 0; i < n; ++i) {
    numbers[i] = 0;
    les[i] = true;
    beg[i] = true;
  }
  // vector<int> numbers(n, 0);
  // vector<bool> les(n, true);
  // vector<bool> beg(n, true);
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &numbers[i]);
    if (numbers[i] > max) {
      max = numbers[i];
    }
    if (numbers[i] < max) {
      les[i] = false;
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    if (numbers[i] < min) {
      min = numbers[i];
    }
    if (numbers[i] > min) {
      beg[i] = false;
    }
    if (beg[i] && les[i]) ans.push_back(numbers[i]);
  }
  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); ++i) {
    printf("%d", ans[i]);
    if (i != ans.size() - 1) printf(" ");
  }
  printf("\n");
  return 0;
}
