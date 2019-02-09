#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 110;
int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    int la = 0, ma = 0, ra = 0;
    char s[N] = {'\0'};
    scanf("%s", s);
    int locP = 0, locT = 0;
    int np = 0, nt = 0, ot = 0;
    int length = strlen(s);
    for (int i = 0; i < length; ++i) {
      if (s[i] == 'P') {
        ++np;
        locP = i;
      } else if (s[i] == 'T') {
        ++nt;
        locT = i;
      } else if (s[i] != 'A') {
        ++ot;
      }
    }
    if (np != 1 || nt != 1 || ot || locT - locP <= 1) {
      printf("NO\n");
      continue;
    }
    la = locP;
    ma = locT - locP - 1;
    ra = length - locT - 1;
    if (ra - la * (ma - 1) == la) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
