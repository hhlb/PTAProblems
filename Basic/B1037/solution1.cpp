#include <cstdio>
struct money {
  int a;
  int b;
  int c;
};
bool b(money money1, money money2) {
  if (money1.a != money2.a)
    return money1.a > money2.a;
  else if (money1.b != money2.b)
    return money1.b > money2.b;
  else
    return money1.c >= money2.c;
}
money ca(money money1, money money2) {
  money res;
  res.a = money1.a - money2.a;
  res.b = money1.b - money2.b;
  res.c = money1.c - money2.c;
  if (res.c < 0) {
    --res.b;
    res.c += 29;
  }
  if (res.b < 0) {
    --res.a;
    res.b += 17;
  }
  return res;
}
int main() {
  money money1, money2;
  money res;
  scanf("%d.%d.%d %d.%d.%d", &money1.a, &money1.b, &money1.c, &money2.a, &money2.b,
        &money2.c);
  bool flag = b(money2, money1);
  if (flag) {
    res = money1;
    money1 = money2;
    money2 = res;
  }
  res = ca(money1, money2);
  if (!flag) printf("-");
  printf("%d.%d.%d", res.a, res.b, res.c);
  return 0;
}