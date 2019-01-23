#include <cstdio>

int main() {
  char mp[3] = {'W', 'T', 'L'};
  char res[3];
  float max[3] = {0};
  float n;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      scanf("%f", &n);
      if (n > max[i]) {
        max[i] = n;
        res[i] = mp[j];
      }
    }
  }
  printf("%c %c %c %.2f", res[0], res[1], res[2],
         (max[0] * max[1] * max[2] * 0.65 - 1) * 2);
  return 0;
}