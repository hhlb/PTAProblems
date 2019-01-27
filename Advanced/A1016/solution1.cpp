#include <algorithm>
#include <cstdio>
#include <cstring>

struct Record {
  char name[25];
  int month, day, hh, mm;
  bool status;
};
bool cmp(Record a, Record b) {
  int s = strcmp(a.name, b.name);
  if (s != 0)
    return s < 0;
  else if (a.month != b.month)
    return a.month < b.month;
  else if (a.day != b.day)
    return a.day < b.day;
  else if (a.hh != b.hh)
    return a.hh < b.hh;
  else
    return a.mm < b.mm;
}
void get_ans(Record rec_on, Record rec_off, int& money, int& mm, int p[]) {
  while (cmp(rec_on, rec_off)) {
    ++rec_on.mm;
    ++mm;
    money += p[rec_on.hh];
    if (rec_on.mm == 60) {
      rec_on.mm = 0;
      ++rec_on.hh;
    }
    if (rec_on.hh == 24) {
      rec_on.hh = 0;
      ++rec_on.day;
    }
  }
}
int main() {
  int p[24];
  for (int i = 0; i < 24; ++i) scanf("%d", &p[i]);
  int num;
  scanf("%d", &num);
  Record rec[num];
  char line[10];
  for (int i = 0; i < num; ++i) {
    scanf("%s", &rec[i].name);
    scanf("%d:%d:%d:%d", &rec[i].month, &rec[i].day, &rec[i].hh, &rec[i].mm);
    scanf("%s", line);
    if (strcmp(line, "on-line") == 0)
      rec[i].status = true;
    else
      rec[i].status = false;
  }
  std::sort(rec, rec + num, cmp);
  int on = 0, off, next;
  while (on < num) {
    int needprint = 0;
    next = on;
    while (next < num && strcmp(rec[next].name, rec[on].name) == 0) {
      if (needprint == 0 && rec[next].status == true) {
        needprint = 1;
      } else if (needprint == 1 && rec[next].status == false) {
        needprint = 2;
      }
      ++next;
    }
    if (needprint < 2) {
      on = next;
      continue;
    }
    int allmoney = 0;
    printf("%s %02d\n", rec[on].name, rec[on].month);
    while (on < next - 1) {
      off = on + 1;
      int money = 0;
      int mm = 0;
      if (rec[on].status == true && rec[off].status == false) {
        printf("%02d:%02d:%02d %02d:%02d:%02d ", rec[on].day, rec[on].hh,
               rec[on].mm, rec[off].day, rec[off].hh, rec[off].mm);
        get_ans(rec[on], rec[off], money, mm, p);
        printf("%d $%.2f\n", mm, (double)money / 100);
        allmoney += money;
        on = off + 1;
      } else
        ++on;
    }
    printf("Total amount: $%.2f\n", (double)allmoney / 100);
    on = next;
  }
  getchar();
  getchar();
  return 0;
}