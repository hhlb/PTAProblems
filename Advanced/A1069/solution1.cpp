/**
 * Remember that N is (0, 1e+4) so when the input string is "12",
 * we need to fix it to "1200".
 */
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;
bool cmp(char a, char b) { return a > b; }
int s2int(char s[]) {
  int res = 0;
  int u = 1000;
  for (int i = 0; i < 4; ++i) {
    res += (s[i] - '0') * u;
    u /= 10;
  }
  return res;
}
int rs2int(char s[]) {
  int res = 0;
  int u = 1;
  for (int i = 0; i < 4; ++i) {
    res += (s[i] - '0') * u;
    u *= 10;
  }
  return res;
}
void int2s(int a, char s[]) {
  s[0] = a / 1000 + '0';
  s[1] = a % 1000 / 100 + '0';
  s[2] = a % 100 / 10 + '0';
  s[3] = a % 10 + '0';
  s[4] = '\0';
}
void print(int a, char s[]) {
  printf("%s - ", s);
  for (int i = 3; i >= 0; --i) {
    printf("%c", s[i]);
  }
  printf(" = %04d\n", a);
}
int main() {
  char s[5] = {'\0'};
  scanf("%s", s);
  for (int i = 0; i < 4; ++i) {
    if (s[i] == '\0') s[i] = '0';
  }
  if (s[0] == s[1] && s[0] == s[2] && s[0] == s[3]) {
    printf("%s - %s = 0000", s, s);
    return 0;
  }
  int res = 0;
  while (res != 6174) {
    sort(s, s + 4, cmp);
    int r1 = s2int(s);
    int r2 = rs2int(s);
    res = r1 - r2;
    print(res, s);
    int2s(res, s);
  }
  return 0;
}
