#include <cstdio>

struct student {
  char name[11];
  char gender;
  char id[11];
  int grade;
  bool flag;
} h, l;
void init() {
  h.gender = 'F';
  h.flag = false;
  h.grade = 0;
  l.gender = 'M';
  l.flag = false;
  l.grade = 100;
}
bool highest(student student1, student student2) {
  return student1.grade > student2.grade;
}

bool lowest(student student1, student student2) {
  return student1.grade < student2.grade;
}
int main() {
  init();
  int n;
  student p;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s %c %s %d", p.name, &p.gender, p.id, &p.grade);
    p.flag = true;
    if (p.gender == 'F' && highest(p, h)) h = p;
    if (p.gender == 'M' && lowest(p, l)) l = p;
  }
  if (h.flag)
    printf("%s %s", h.name, h.id);
  else
    printf("Absent");
  printf("\n");
  if (l.flag)
    printf("%s %s", l.name, l.id);
  else
    printf("Absent");
  printf("\n");
  if (h.flag && l.flag)
    printf("%d", h.grade - l.grade);
  else
    printf("NA");
  return 0;
}