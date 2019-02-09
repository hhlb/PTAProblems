#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
const int M = 1000000007;
const int MAX = 100010;

int main() {
  char s[MAX];
  int leftP[MAX] = {0};
  scanf("%s", s);
  int length = strlen(s);
  for (int i = 0; i < length; ++i) {
    if (i != 0) leftP[i] = leftP[i - 1];
    if (s[i] == 'P') ++leftP[i];
  }
  long long int ans = 0;
  int numT = 0;
  for (int i = length - 1; i >= 0; --i) {
    if (s[i] == 'T')
      ++numT;
    else if (s[i] == 'A') {
      ans += numT * leftP[i];
    }
  }
  ans = ans % M;
  cout << ans;
  return 0;
}