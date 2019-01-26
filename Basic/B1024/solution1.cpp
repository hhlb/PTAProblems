#include <cstdio>

int main() {
  char flag1;
  int a1;
  char a2[10000];
  char flag2;
  int b;
  scanf("%c%d.%[^E]E%c%d", &flag1, &a1, &a2[1], &flag2, &b);
  a2[0] = a1 + 48;
  int num = 0;
  for (int i = 0; i < 10000; ++i) {
    if (a2[i] != '\0') {
      ++num;
    } else
      break;
  }
  if(flag1 == '-'){
    printf("-");
  }
  if (flag2 == '-') {
    if (b >= 1) {
      printf("0.");
      for (int i = 0; i < b - 1; ++i) {
        printf("0");
      }
      for (int i = 0; i < num; ++i) {
        printf("%c", a2[i]);
      }
    } else {
      printf("%c.", a2[0]);
      for (int i = 1; i < num; ++i) {
        printf("%c", a2[i]);
      }
    }
  } else {
    if (b >= num - 1) {
      printf("%s", a2);
      for (int i = 0; i < b - num + 1; ++i) {
        printf("0");
      }
    } else {
      for (int i = 0; i < b + 1; ++i) {
        printf("%c", a2[i]);
      }
      printf(".");
      for (int i = b + 1; i < num; ++i) {
        printf("%c", a2[i]);
      }
    }
  }
  return 0;
}