#include <algorithm>
#include <cstdio>
#include <cstring>
struct student {
  int id;
  int p[5];
  int perfect_solved;
  int total;
  int rank;
  bool flag;
};
bool cmp(student s1, student s2) {
  if (s1.flag != s2.flag)
    return s1.flag > s2.flag;
  else if (s1.total != s2.total)
    return s1.total > s2.total;
  else if (s1.perfect_solved != s2.perfect_solved)
    return s1.perfect_solved > s2.perfect_solved;
  else {
    return s1.id < s2.id;
  }
}
int main() {
  int num, pl, n;
  scanf("%d%d%d", &num, &pl, &n);
  student st[num];
  for (int i = 0; i < num; ++i) {
    st[i].id = i + 1;
    st[i].flag = false;
    st[i].perfect_solved = 0;
    st[i].rank = 1;
    st[i].total = 0;
    for (int j = 0; j < 5; ++j) st[i].p[j] = -1;
  }
  int p[pl];
  for (int i = 0; i < pl; ++i) scanf("%d", &p[i]);
  for (int i = 0; i < n; ++i) {
    int id, problem, score;
    scanf("%d%d%d", &id, &problem, &score);

    if (score > st[id - 1].p[problem - 1]) {
      st[id - 1].p[problem - 1] = score;
      if (score == p[problem - 1]) ++st[id - 1].perfect_solved;
      st[id - 1].total = 0;
      st[id - 1].flag = true;
      for (int k = 0; k < pl; ++k) {
        if (st[id - 1].p[k] >= 0) st[id - 1].total += st[id - 1].p[k];
      }
    } else if (score < 0 && st[id - 1].p[problem - 1] < 0)
      st[id - 1].p[problem - 1] = 0;
  }
  std::sort(st, st + num, cmp);
  int su = 1;
  for (int i = 1; i < num; ++i) {
    if (st[i].flag) {
      ++su;
      if (st[i].total == st[i - 1].total)
        st[i].rank = st[i - 1].rank;
      else
        st[i].rank = i + 1;
    }
  }
  for (int i = 0; i < su; ++i) {
    printf("%d %05d %d ", st[i].rank, st[i].id, st[i].total);
    for (int j = 0; j < pl; ++j) {
      if (st[i].p[j] >= 0)
        printf("%d", st[i].p[j]);
      else
        printf("-");
      if (j != pl - 1) printf(" ");
    }
    printf("\n");
  }
  return 0;
}