#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
struct student {
  char id[10];
  int s1, s2, s3;
};
bool cmp(student s1, student s2) {
  int s = strcmp(s1.id, s2.id);
  if (s1.s3 != s2.s3)
    return s1.s3 > s2.s3;
  else if (s1.s1 != s2.s1)
    return s1.s1 > s2.s1;
  else
    return s < 0;
}
int main() {
  int a, a1, a2;
  std::vector<student> st;
  scanf("%d%d%d", &a, &a1, &a2);
  for (int i = 0; i < a; ++i) {
    student p;
    scanf("%s", &p.id);
    scanf("%d%d", &p.s1, &p.s2);
    p.s3 = p.s1 + p.s2;
    if (p.s1 < a1 || p.s2 < a1)
      continue;
    else
      st.push_back(p);
  }
  printf("%d\n", st.size());

  std::vector<student> st0;
  for (int i = 0; i < st.size(); ++i) {
    if (st[i].s1 >= a2 && st[i].s2 >= a2) {
      st0.push_back(st[i]);
    }
  }
  std::sort(st0.begin(), st0.end(), cmp);
  for (int i = 0; i < st0.size(); ++i) {
    printf("%s %d %d\n", st0[i].id, st0[i].s1, st0[i].s2);
  }
  st0.clear();

  for (int i = 0; i < st.size(); ++i) {
    if (st[i].s1 >= a2 && st[i].s2 < a2) {
      st0.push_back(st[i]);
    }
  }
  std::sort(st0.begin(), st0.end(), cmp);
  for (int i = 0; i < st0.size(); ++i) {
    printf("%s %d %d\n", st0[i].id, st0[i].s1, st0[i].s2);
  }
  st0.clear();

  for (int i = 0; i < st.size(); ++i) {
    if (st[i].s1 < a2 && st[i].s2 < a2 && st[i].s1 >= st[i].s2) {
      st0.push_back(st[i]);
    }
  }
  std::sort(st0.begin(), st0.end(), cmp);
  for (int i = 0; i < st0.size(); ++i) {
    printf("%s %d %d\n", st0[i].id, st0[i].s1, st0[i].s2);
  }
  st0.clear();

  for (int i = 0; i < st.size(); ++i) {
    if (st[i].s1 < a2 && st[i].s1 >= a1 && st[i].s2 > st[i].s1) {
      st0.push_back(st[i]);
    }
  }
  std::sort(st0.begin(), st0.end(), cmp);
  for (int i = 0; i < st0.size(); ++i) {
    printf("%s %d %d\n", st0[i].id, st0[i].s1, st0[i].s2);
  }
  st0.clear();
  return 0;
}