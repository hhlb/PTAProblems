#include <cstdio>

int main() {
  bool flag = false;
  bool flag0 = false;
  int n;
  int num = 0;
  scanf("%d", &n);
  getchar();
  char a[n][11], b[n][11];
  int res[n];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 11; ++j) {
      a[i][j] = '\0';
      b[i][j] = '\0';
    }
    res[i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%[^ ] %s", &a[i][0], &b[i][0]);
    getchar();
  }
  for (int i = 0; i < n; ++i) {
    flag = false;
    for (int j = 0; j < 11; ++j) {
      if (b[i][j] == '1') {
        b[i][j] = '@';
        flag = true;
        res[i] = 1;
      } else if (b[i][j] == '0') {
        b[i][j] = '%';
        flag = true;
        res[i] = 1;
      } else if (b[i][j] == 'l') {
        b[i][j] = 'L';
        flag = true;
        res[i] = 1;
      } else if (b[i][j] == 'O') {
        b[i][j] = 'o';
        flag = true;
        res[i] = 1;
      }
    }
    if (flag) {
      ++num;
      flag0 = true;
    }
  }
  if (!flag0) {
    if (n == 1)
      printf("There is 1 account and no account is modified");
    else
      printf("There are %d accounts and no account is modified", n);
  } else {
    if (n == 1)
      printf("There are 1 account and no account is modified");
    else {
      printf("%d\n", num);
      for (int i = 0; i < n; ++i) {
        if (res[i] == 1) {
          for (int j = 0; j < 11; ++j) {
            if (a[i][j] != '\0') printf("%c", a[i][j]);
          }
          printf(" ");
          for (int j = 0; j < 11; ++j) {
            if (b[i][j] != '\0') printf("%c", b[i][j]);
          }
          printf("\n");
        }
      }
      if (n == 1) printf("There is 1 account and no account is modified");
    }
  }
  return 0;
}