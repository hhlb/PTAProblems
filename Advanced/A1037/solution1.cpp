#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
bool cmp1(long long int a, long long int b) { return a < b; }
bool cmp2(long long int a, long long int b) { return a > b; }
int main() {
  vector<long long int> coupon;
  vector<long long int> product;
  int a;
  cin >> a;
  for (int i = 0; i < a; ++i) {
    int b;
    cin >> b;
    coupon.push_back(b);
  }
  cin >> a;
  for (int i = 0; i < a; ++i) {
    int b;
    cin >> b;
    product.push_back(b);
  }
  sort(coupon.begin(), coupon.end(), cmp1);
  sort(product.begin(), product.end(), cmp1);
  int money = 0;
  while (coupon.size() != 0 && product.size() != 0 && coupon.back() > 0 &&
         product.back() > 0) {
    money += coupon.back() * product.back();
    coupon.pop_back();
    product.pop_back();
  }
  reverse(coupon.begin(), coupon.end());
  reverse(product.begin(), product.end());
  while (coupon.size() != 0 && product.size() != 0 && coupon.back() < 0 &&
         product.back() < 0) {
    money += coupon.back() * product.back();
    coupon.pop_back();
    product.pop_back();
  }
  cout << money;
  return 0;
}