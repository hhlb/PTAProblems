#include <cstdio>

int main() {
  char id[18];
  int a;
  int c[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
  char m[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
  bool flag1 = true;
  scanf("%d", &a);
  while (a--) {
    bool flag = true;
    int sum = 0;
    scanf("%s", id);
    for (int i = 0; i < 17; ++i) {
      if (id[i] >= 48 && id[i] <= 57) {
        sum += (id[i] - 48) * c[i];
      } else {
        printf("%s\n", id);
        flag = false;
        flag1 = false;
        break;
      }
    }
    if (flag) {
      if (m[sum % 11] != id[17]) {
        printf("%s\n", id);
        flag = false;
        flag1 =false;
      }
    }
  }
  if(flag1){
    printf("All passed");
  }
  return 0;
}