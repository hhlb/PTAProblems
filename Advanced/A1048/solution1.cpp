/*
  There is something wrong with the description of A1048.
  Here is the original:
    Input Specification:
      Each input file contains one test case.
      For each case, the first line contains 2 positive numbers: N (≤10^5,
        the total number of coins) and M (≤10^3,
        the amount of money Eva has to pay).
      The second line contains N face values of the coins,
        which are all positive numbers no more than 500.
      All the numbers in a line are separated by a space.

  The amount of single coin is limited to 1000 instead of 500;
*/
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1001;
int main() {
  int a, b;
  cin >> a >> b;
  int c[N] = {0};
  int res1, res2;
  for (int i = 0; i < a; ++i) {
    int d;
    cin >> d;
    ++c[d];
  }
  for (int i = 1; i < N; ++i) {
    if (c[i]) {
      --c[i];
      if (b > i && c[b - i]) {
        cout << i << " " << b - i;
        return 0;
      }
      ++c[i];
    }
  }
  cout << "No Solution";
  return 0;
}