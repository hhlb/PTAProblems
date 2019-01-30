#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
bool cmp(int a, int b) { return a < b; }
int main() {
  vector<int> r;
  for (int i = 0; i < 10; ++i) {
    int a;
    cin >> a;
    for (int j = 0; j < a; ++j) {
      r.push_back(i);
    }
  }
  sort(r.begin(), r.end(), cmp);
  int id;
  for (int i = 1; i < r.size(); ++i) {
    if (r[i - 1] == 0 && r[i] > r[i - 1]) {
      id = i;
      cout << r[i];
    }
  }
  for (int i = 0; i < r.size(); ++i) {
    if (i != id) cout << r[i];
  }
  return 0;
}