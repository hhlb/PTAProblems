#include <cstdio>

int main() {
  char s1[60];
  char s2[60];
  char* d[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
  int a = 0;
  char res1, res2;
  while ((s1[a] = getchar()) != '\n') {
    ++a;
  }
  int b = 0;
  bool flag1 = false;
  bool flag2 = true;
  while ((s2[b] = getchar()) != '\n') {
    if (!flag1 && b < a && s2[b] == s1[b] && s2[b] >= 65 && s2[b] <= 71) {
      res1 = s2[b];
      flag1 = true;
      flag2 = false;
      ++b;
      continue;
    }
    if (!flag2 && b < a && s2[b] == s1[b] &&
        ((s2[b] >= 65 && s2[b] <= 78) || (s2[b] >= 48 && s2[b] <= 57))) {
      res2 = s2[b];
      flag2 = true;
      ++b;
      continue;
    }
    ++b;
  }
  int r2 = 0;
  if (res2 < 65)
    r2 = res2 - 48;
  else
    r2 = res2 - 55;
  a = b = 0;
  while ((s1[a] = getchar()) != '\n') {
    ++a;
  }
  int r3 = 0;
  while ((s2[b] = getchar()) != '\n') {
    if (b < a && s2[b] == s1[b] && ((s2[b] >= 65 && s2[b] <= 90) ||
        (s2[b] >= 97 && s2[b] <= 122))) {
      r3 = b;
      break;
    }
    ++b;
  }
  printf("%s %02d:%02d", d[res1 - 65], r2, r3);
  return 0;
}