#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  int sc[100100] = {0};
  int max = 0, maxID = 0;
  for (int i = 0; i < n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    sc[a] += b;
  }
  for (int i = 1; i < 100100; ++i) {
    if(sc[i] > max){
      max = sc[i];
      maxID = i;
    }
  }
  printf("%d %d", maxID, max);
  return 0;
}