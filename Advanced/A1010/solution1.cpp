// This is a wrong solution(22/25)because of the radix is no more than INT_MAX
// and any violent solution would be TIME OUT
// The radix sometimes would lead to OVERFLOW and get WRONG so use long long int to handle
// all the numbers or rebegin the array
#include <math.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
long long int unr(string s, long long int r) {
  long long int num = 0;
  int a = s.length();
  bool flag = false;
  while (a--) {
    if (s[a] >= '0' && s[a] <= '9') {
      num += (s[a] - '0') * pow(r, s.length() - a - 1);
      flag = true;
    } else {
      num += (s[a] - 'a' + 10) * pow(r, s.length() - a - 1);
      flag = true;
    }
  }
  return flag ? num : -1;
}
int main() {
  string a, b;
  long long int c, d;
  cin >> a >> b >> c >> d;
  long long int num = unr(c == 1 ? a : b, d);
  string s = c == 1 ? b : a;
  long long int res = 0;
  for (int i = 0; i < 10000; ++i) {
    if (unr(s, i) == num) {
      res = i;
      break;
    }
  }
  if (res)
    cout << res;
  else
    cout << "Impossible";
  return 0;
}