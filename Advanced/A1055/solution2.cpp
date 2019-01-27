#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
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
  std::vector<person> p;
  for (int i = 0; i < num1; ++i) {
    person _p;
    scanf("%s", &_p.name);
    scanf("%d", &_p.age);
    scanf("%d", &_p.w);
    p.push_back(_p);
  }
  std::sort(p.begin(), p.end(), cmp);
  for (int i = 0; i < num2; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("Case #%d:\n", i + 1);
    int num = 0;
    for (int j = 0; j < p.size(); ++j) {
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
  getchar();
  getchar();
  return 0;
}