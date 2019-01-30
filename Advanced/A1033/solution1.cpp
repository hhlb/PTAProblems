#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct station {
  double price;
  double dis;
};
bool cmp(station a, station b) {
  if (a.dis != b.dis)
    return a.dis < b.dis;
  else
    return a.price < b.price;
}
int main() {
  double a, b, c, d;
  vector<station> s;
  cin >> a >> b >> c >> d;
  double max_length = a * c;
  for (int i = 0; i < d; ++i) {
    station s0;
    cin >> s0.price >> s0.dis;
    s.push_back(s0);
  }
  station s0;
  s0.price = 0;
  s0.dis = b;
  s.push_back(s0);
  sort(s.begin(), s.end(), cmp);
  double money = 0;
  if (s[0].dis != 0) {
    cout << "The maximum travel distance = 0.00";
  } else {
    int now = 0;
    double nowtank = 0;
    while (now < d) {
      int min_price_station = -1;
      double min_price = 10000000;
      for (int i = now + 1; i <= d && s[i].dis - s[now].dis <= max_length;
           ++i) {
        if (s[i].price < min_price) {
          min_price = s[i].price;
          min_price_station = i;
          if (min_price < s[now].price) {
            break;
          }
        }
      }
      if (min_price_station == -1) break;
      double need = (s[min_price_station].dis - s[now].dis) / c;
      if (min_price < s[now].price) {
        if (nowtank < need) {
          money += (need - nowtank) * s[now].price;
          nowtank = 0;
        } else {
          nowtank -= need;
        }
      } else {
        money += (a - nowtank) * s[now].price;
        nowtank = a - need;
      }
      now = min_price_station;
    }
    if (now == d) {
      printf("%.2lf", money);
    } else {
      printf("The maximum travel distance = %.2lf", max_length + s[now].dis);
    }
  }
  return 0;
}