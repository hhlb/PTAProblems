#include <iostream>
int M, N, dominant, freq = 0, temp;
int main() {
  scanf("%d%d", &M, &N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &temp);
      if (freq == 0) {
        dominant = temp;
        freq = 1;
      } else {
        if (dominant == temp)
          freq++;
        else
          freq--;
      }
    }
  }
  printf("%d", dominant);
  return 0;
}
