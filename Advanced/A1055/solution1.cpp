#include <algorithm>
#include <cstdio>
#include <cstring>
struct person {
  char name[10];
  int age;
  int w;
};
bool cmp(person p1, person p2) {
  int s = strcmp(p1.name, p2.name);
  if (p1.w != p2.w)
    return p1.w > p2.w;
  else if (p1.age != p2.age)
    return p1.age < p2.age;
  else
    return s < 0;
}
int main() {
  int num1, num2;
  scanf("%d%d", &num1, &num2);
  person p[num1];
  for (int i = 0; i < num1; ++i) {
    scanf("%s", &p[i].name);
    scanf("%d", &p[i].age);
    scanf("%d", &p[i].w);
  }
  std::sort(p, p+num1, cmp);
  for (int i = 0; i < num2; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("Case #%d:\n", i + 1);
    int num = 0;
    for (int j = 0; j < num1; ++j) {
      if (p[j].age >= b && p[j].age <= c) {
        printf("%s %d %d\n", p[j].name, p[j].age, p[j].w);
        ++num;
      }
      if(num  == a){
        break;
      }
    }
    if(num == 0){
      printf("None\n");
    }
  }
  return 0;
}