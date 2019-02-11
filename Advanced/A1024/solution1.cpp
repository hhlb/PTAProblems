#include <memory.h>
#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 110;

struct bigint {
  int d[maxn];
  int length;
  bigint() {
    memset(d, 0, sizeof(d));
    length = maxn;
  }
};

bigint s2bigint(char s[]) {
  bigint res;
  int len = strlen(s);
  for (int i = 0; i < len; ++i) {
    res.d[i] = s[len - i - 1] - '0';
  }
  res.length = len;
  return res;
}

bool isPalindromicNumber(bigint a) {
  int len = a.length;
  for (int i = 0; i < len / 2; ++i) {
    if (a.d[i] != a.d[len - i - 1]) return false;
  }
  return true;
}

bigint reverseBigInt(bigint a){
  bigint d = a;
  for(int i = 0; i < d.length; ++i){
    d.d[i] = a.d[d.length - i - 1];
  }
  return d;
}

bigint addBigInt(bigint a, bigint b) {
  bigint res;
  res.length = maxn;
  int r = 0;
  for (int i = 0; i < maxn; ++i) {
    r += a.d[i] + b.d[i];
    res.d[i] = r % 10;
    r /= 10;
  }
  while (res.length >= 1 && res.d[res.length - 1] == 0) {
    --res.length;
  }
  return res;
}

int main(){
  char s[maxn];
  int d;
  scanf("%s %d", s, &d);
  int step = 0;
  bigint a = s2bigint(s);
  while(!isPalindromicNumber(a)){
    bigint b = reverseBigInt(a);
    a = addBigInt(a, b);
    ++step;
    if(step == d) break;
  }
  for(int i = 0; i < a.length; ++i){
    printf("%d", a.d[a.length - i - 1]);
  }
  printf("\n%d", step);
  return 0;
}