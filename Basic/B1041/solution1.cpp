#include <cstdio>

const int maxn = 1010;
struct student {
  long long id;
  int examseat;
} testSeat[maxn];
int main() {
  int m, n, seat, examseat;
  long long id;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld%d%d", &id, &seat, &examseat);
    testSeat[seat].id = id;
    testSeat[seat].examseat = examseat;
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", &seat);
    printf("%lld %d\n", testSeat[seat].id, testSeat[seat].examseat);
  }
  return 0;
}