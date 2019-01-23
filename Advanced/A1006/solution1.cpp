#include <cstdio>

struct person {
  char id[15];
  int a1, a2, a3;
  int b1, b2, b3;
} e, l;

void init() {
  e.a1 = 23;
  e.a2 = 59;
  e.a3 = 59;
  e.b1 = 0;
  e.b2 = 0;
  e.b3 = 0;
  l.b1 = 0;
  l.b2 = 0;
  l.b3 = 0;
  l.a1 = 0;
  l.a2 = 0;
  l.a3 = 0;
}
bool ear(person person1, person person2) {
  if (person1.a1 != person2.a1)
    return person1.a1 < person2.a1;
  else if (person1.a2 != person2.a2)
    return person1.a2 < person2.a2;
  else
    return person1.a3 <= person2.a3;
}
bool lat(person person1, person person2) {
  if (person1.b1 != person2.b1)
    return person1.b1 > person2.b1;
  else if (person1.b2 != person2.b2)
    return person1.b2 > person2.b2;
  else
    return person1.b3 >= person2.b3;
}
int main() {
  init();
  int n;
  person p;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s %d:%d:%d %d:%d:%d", p.id, &p.a1, &p.a2, &p.a3, &p.b1, &p.b2,
          &p.b3);
    if (ear(p, e)) e = p;
    if (lat(p, l)) l = p;
  }
  printf("%s %s", e.id, l.id);
  return 0;
}