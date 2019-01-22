#include <cstdio>

const int N = 54

    int
    main() {
  char mp[5] = {'S', 'H', 'C', 'D', 'J'};
  int start[N], end[N], next[N];
  int times;
  scanf("%d", &times);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &next[i]);
  }

  for (int i = 0; i < times; ++i) {
    for (int j = 0; j < N; ++j) {
      end[next[j] - 1] = start[j];
    }
    for (int j = 0; j < N; ++j) {
      start[j] = end[j];
    }
  }
  for (int i = 0; i < N; ++i) {
    printf("%c%d", mp[end[i] / 13 - 1], end[i] % 13 + 1);
  }
  return 0;
}
