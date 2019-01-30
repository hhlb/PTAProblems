#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct cake {
  double s;
  double m;
  double price;
};
bool cmp(cake c1, cake c2) { return c1.price > c2.price; }
int main() {
  int a;
  double s;
  cin >> a >> s;
  vector<cake> c(a);
  for (int i = 0; i < a; ++i) {
    cin >> c[i].s;
  }
  for (int i = 0; i < a; ++i) {
    cin >> c[i].m;
    c[i].price = c[i].m / c[i].s;
  }
  double sum = 0;
  sort(c.begin(), c.end(), cmp);
  for (int i = 0; i < a; ++i) {
    if (c[i].s < s) {
      sum += c[i].m;
      s -= c[i].s;
    } else {
      sum += c[i].price * s;
      s = c[i].s - s;
      break;
    }
  }
  printf("%.2lf", sum);
  return 0;
}