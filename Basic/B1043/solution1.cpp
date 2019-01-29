#include <algorithm>
#include <iostream>
using namespace std;
bool em(int b[]) {
  return b['P'] || b['A'] || b['T'] || b['e'] || b['s'] || b['t'];
}
int main() {
  string s;
  cin >> s;
  int b[123] = {0};
  while (!s.empty()) {
    ++b[s[0]];
    s.erase(s.begin());
  }
  int map[6] = {'P', 'A', 'T', 'e', 's', 't'};
  while (em(b)) {
    for (int i = 0; i < 6; ++i) {
      if (b[map[i]]) {
        printf("%c", map[i]);
        --b[map[i]];
      }
    }
  }
  return 0;
}