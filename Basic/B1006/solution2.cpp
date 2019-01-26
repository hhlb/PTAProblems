#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  if ((n / 100) != 0)
    for (int i = n / 100; i > 0; i--) cout << 'B';
  if (((n / 10) % 10) != 0)
    for (int j = (n / 10) % 10; j > 0; j--) cout << 'S';
  for (int k = 1; k < n % 10 + 1; k++) cout << k;
  return 0;
}