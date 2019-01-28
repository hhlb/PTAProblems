#include <algorithm>
#include <cstdio>
#include <cstring>
struct student {
  char id[14];
  int s;
  int fr, lr, l;
};
bool cmp(student s1, student s2) {
  int s = strcmp(s1.id, s2.id);
  if (s1.s != s2.s)
    return s1.s > s2.s;
  else if (s != 0)
    return s < 0;
}
int main() {
  int a;
  student s[30000];
  scanf("%d", &a);
  int num = 0;
  int t = 0;
  for (int i = 0; i < a; ++i) {
    int b;
    scanf("%d", &b);
    t += b;
    for (int j = 0; j < b; ++j) {
      scanf("%s", &s[num].id);
      scanf("%d", &s[num].s);
      s[num].l = i + 1;
      ++num;
    }
    std::sort(s + num - b, s + num, cmp);
    s[num - b].lr = 1;
    for (int j = num - b + 1; j < num; ++j) {
      if (s[j].s == s[j - 1].s)
        s[j].lr = s[j - 1].lr;
      else
        s[j].lr = j - num + b + 1;
    }
  }
  std::sort(s, s + t, cmp);
  s[0].fr = 1;
  for (int i = 1; i < t; ++i) {
    if (s[i].s == s[i - 1].s)
      s[i].fr = s[i - 1].fr;
    else
      s[i].fr = i + 1;
  }
  printf("%d\n", t);
  for (int i = 0; i < t; ++i) {
    printf("%s %d %d %d\n", s[i].id, s[i].fr,s[i].l,s[i].lr);
  }
  return 0;
}