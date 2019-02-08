/**
 * This is a bad solution because of the MEMORY limit.
 * You need to read the second array and sort at the same time.
 * do not have vector or array to save the second array.
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n1, n2;
int main() {
  scanf("%d", &n1);
  int a[n1];
  for (int i = 0; i < n1; ++i) {
    scanf("%d", &a[i]);
  }
  scanf("%d", &n2);
  int b[n2];
  for (int i = 0; i < n2; ++i) {
    scanf("%d", &b[i]);
  }
  int mid = (n1 + n2) % 2 == 0 ? (n1 + n2) / 2 - 1 : (n1 + n2) / 2;
  int i = 0, j = 0;
  int count = -1;
  bool arrayflag;
  while (i < n1 && j < n2) {
    if (a[i] > b[j]) {
      ++j;
      ++count;
      arrayflag = false;
    } else {
      ++i;
      ++count;
      arrayflag = true;
    }
    if (count == mid) {
      printf("%d", arrayflag ? a[i - 1] : b[j - 1]);
      return 0;
    }
  }
  if (count < mid) {
    if (i < n1) {
      while (i < n1) {
        ++i;
        ++count;
        if (count == mid) {
          printf("%d", a[i - 1]);
          return 0;
        }
      }
    } else if (j < n2) {
      while (j < n1) {
        ++j;
        ++count;
        if (count == mid) {
          printf("%d", b[j - 1]);
          return 0;
        }
      }
    }
  }
}