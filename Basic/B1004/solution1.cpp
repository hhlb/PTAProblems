#include <memory.h>
#include <cstdio>
int main() {
  int num;
  int max = 0, min = 0, maxS = 0, minS = 100;
  scanf("%d", &num);
  char s[num][22];
  memset(s, '\0', sizeof(s));
  int sc[num];
  for (int i = 0; i < num; ++i) {
    scanf("%s", &s[i][0]);
    scanf("%s", &s[i][11]);
    scanf("%d", &sc[i]);
    if (sc[i] > maxS) {
      maxS = sc[i];
      max = i;
    }
    if (sc[i] < minS) {
      minS = sc[i];
      min = i;
    }
  }
  int flag = 0;
  for (int i = 0; i < 22; ++i) {
    if (s[max][i] != '\0') printf("%c", s[max][i]);
    else if(s[max][i] == '\0' && flag == 0){
      flag = 1;
      printf(" ");
    }
  }
  printf("\n");
  flag = 0;
  for (int i = 0; i < 22; ++i) {
    if (s[min][i] != '\0') printf("%c", s[min][i]);
    else if(s[min][i] == '\0' && flag == 0){
      flag = 1;
      printf(" ");
    }
  }
  return 0;
}