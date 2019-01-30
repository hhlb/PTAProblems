#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
bool cmp(string a, string b) { return a + b < b + a; }
int main() {
  int a;
  cin >> a;
  vector<string> ans;
  for (int i = 0; i < a; ++i) {
    string b;
    cin >> b;
    ans.push_back(b);
  }
  sort(ans.begin(), ans.end(), cmp);
  string res;
  for (int i = 0; i < a; ++i) {
    res += ans[i];
  }
  while (res.size() != 0 && res[0] == '0') res.erase(res.begin());
  if (res.size() == 0)
    cout << 0;
  else
    cout << res;
  return 0;
}