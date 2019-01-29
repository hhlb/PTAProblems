#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int a[123] = {0};
  int b[123] = {0};
  string c, d;
  cin >> c >> d;
  while (!c.empty()) {
    ++a[c[0]];
    c.erase(c.begin());
  }
  while (!d.empty()) {
    ++b[d[0]];
    d.erase(d.begin());
  }
  int sum1 = 0;
  int sum2 = 0;
  bool flag = true;
  for (int i = 48; i <= 122; ++i) {
    if (b[i] > a[i]) {
      flag = false;
      sum2 += b[i] - a[i];
    }else {
      sum1 += a[i] - b[i];
    }
  }
  if (flag)
    cout << "Yes " << sum1;
  else
    cout << "No " << sum2;
  return 0;
}