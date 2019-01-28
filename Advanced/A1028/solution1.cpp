#include <algorithm>
#include <cstdio>
#include <cstring>
struct student {
  char id[10];
  char name[10];
  int s;
};
int a;
bool cmp(student s1, student s2) {
  if (a == 1) {
    int s = strcmp(s1.id, s2.id);
    return s < 0;
  } else if (a == 2) {
    int s = strcmp(s1.name, s2.name);
    if (s != 0)
      return s < 0;
    else {
      int c = strcmp(s1.id, s2.id);
      return c < 0;
    }
  } else {
    if (s1.s != s2.s)
      return s1.s < s2.s;
    else {
      int s = strcmp(s1.id, s2.id);
      return s < 0;
    }
  }
}
int main() {
  int num;
  scanf("%d%d", &num, &a);
  student st[num];
  for (int i = 0; i < num; ++i) {
    scanf("%s", &st[i].id);
    scanf("%s", &st[i].name);
    scanf("%d", &st[i].s);
  }
  std::sort(st, st + num, cmp);
  for (int i = 0; i < num; ++i) {
    printf("%s %s %d\n", st[i].id, st[i].name, st[i].s);
  }
  return 0;
}