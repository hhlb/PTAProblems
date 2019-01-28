//This solution sometimes have SF(Segmentation fault) 
//solution2.cpp uses vector to solve the problem
#include <algorithm>
#include <cstdio>
#include <cstring>
int a, b, c;
struct student {
  int id;
  int GE, GI, T;
  int rank;
  int school[5];
};
struct school {
  int student[40000];
  int lastrank;
  int sum;
  int f;
};
bool cmp(student st1, student st2) {
  if (st1.T != st2.T)
    return st1.T > st2.T;
  else if (st1.GE != st2.GE)
    return st1.GE > st2.GE;
  else
    return st1.id < st2.id;
}
bool cmpid(int a, int b) { return a < b; }
int main() {
  scanf("%d%d%d", &a, &b, &c);
  student st[a];
  school sc[b];
  for (int i = 0; i < b; ++i) {
    scanf("%d", &sc[i].f);
    sc[i].lastrank = 0;
    sc[i].sum = 0;
  }
  for (int i = 0; i < a; ++i) {
    scanf("%d%d", &st[i].GE, &st[i].GI);
    st[i].T = (st[i].GE + st[i].GI) / 2;
    st[i].id = i;
    st[i].rank = 1;
    for (int j = 0; j < c; ++j) {
      scanf("%d", &st[i].school[j]);
    }
  }
  std::sort(st, st + a, cmp);
  for (int i = 1; i < a; ++i) {
    if (st[i].T == st[i - 1].T && st[i].GE == st[i - 1].GE)
      st[i].rank = st[i - 1].rank;
    else
      st[i].rank = i + 1;
  }

  for (int i = 0; i < a; ++i) {
    for (int j = 0; j < c; ++j) {
      int scid = st[i].school[j];
      if (sc[scid].sum < sc[scid].f || sc[scid].lastrank == st[i].rank) {
        sc[scid].student[sc[scid].sum] = st[i].id;
        ++sc[scid].sum;
        sc[scid].lastrank = st[i].rank;
        break;
      }
    }
  }
  for (int i = 0; i < b; ++i) {
    std::sort(sc[i].student, sc[i].student + sc[i].sum, cmpid);
    for (int j = 0; j < sc[i].sum; ++j) {
      printf("%d", sc[i].student[j]);
      if (j < sc[i].sum - 1) printf(" ");
    }
    printf("\n");
  }
  getchar();
  getchar();
  return 0;
}