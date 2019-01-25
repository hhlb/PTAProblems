#include <cstdio>
int main() {
  long long int a, c, d;
  int s[64];
  scanf("%lld%lld", &a, &c);
  long long int n = a;
  int i = 0;
  do {
    d = n % c;
    s[i] = d;
    n /= c;
    ++i;
  } while (n != 0);
  int center;
  if (i % 2 == 0)
    center = i / 2;
  else
    center = i / 2 - 1;
  if (center < 0) {
    printf("Yes\n");
  } else {
    bool f = true;
    for (int j = 0; j <= center; ++j) {
      if(s[j] != s[i - j - 1]){
        f = false;
        printf("No\n");
        break;
      }
    }
    if (f) printf("Yes\n");
  }

  for (int j = i - 1; j >= 0; --j) {
    printf("%d", s[j]);
    if(j != 0){
      printf(" ");
    }
  }
  return 0;
}