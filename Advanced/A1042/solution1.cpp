#include <cstdio>

const int N = 54;

int main() {
  char mp[5] = {'S', 'H', 'C', 'D', 'J'};
  int start[N + 1], end[N + 1], next[N + 1];
  int times;
  scanf("%d", &times);
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &next[i]);
    start[i] = i;
  }

  for (int i = 0; i < times; ++i) {
    for (int j = 1; j <= N; ++j) {
      end[next[j]] = start[j];
    }
    for (int j = 1; j <= N; ++j) {
      start[j] = end[j];
    }
  }
  for (int i = 1; i <= N; ++i) {
    --end[i];
    printf("%c%d", mp[end[i] / 13], end[i] % 13 + 1);
    if (i != N) printf(" ");
  }
  return 0;
}