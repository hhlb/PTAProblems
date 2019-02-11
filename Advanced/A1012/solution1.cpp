/**
 * This solution has worse performance because of the usage of loops and complex arrays.
 * The solution2 uses sort to speed up.
 */
#include <cstdio>
int main() {
  int x1, x2;
  char map[4] = {'A', 'C', 'M', 'E'};
  scanf("%d%d", &x1, &x2);
  int id[x1];
  int data[x1][4];
  int res[x1][4];
  for (int i = 0; i < x1; ++i) {
    scanf("%d%d%d%d", &id[i], &data[i][1], &data[i][2], &data[i][3]);
    data[i][0] = (data[i][1] + data[i][2] + data[i][3]) / 3;
  }
  for (int i = 0; i < x1; ++i) {
    for (int j = 0; j < 4; ++j) {
      int rank = 1;
      for (int k = 0; k < x1; ++k) {
        if (data[k][j] > data[i][j]) ++rank;
      }
      res[i][j] = rank;
    }
  }
  while (x2--) {
    int id0;
    bool flag = true;
    scanf("%d", &id0);
    for (int i = 0; i < x1; ++i) {
      if (id[i] == id0) {
        flag = false;
        int r = x1;
        int k = 0;
        for (int j = 0; j < 4; ++j) {
          if (res[i][j] < r) {
            r = res[i][j];
            k = j;
          }
        }
        printf("%d %c\n", r, map[k]);
        break;
      }
    }
    if (flag) {
      printf("N/A\n");
    }
  }
  return 0;
}