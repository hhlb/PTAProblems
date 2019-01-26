#include <cstdio>

int main() {
  char a[1000]={'\0'};
  int d[10] = {0};
  scanf("%s", a);
  int b;
  for(int i = 0; i < 1000;++i){
    if(a[i]!='\0'){
      ++d[a[i] - 48];
    }else break;
  }
  for (int i = 0; i < 10; ++i) {
    if (d[i] != 0) {
      printf("%d:%d\n", i, d[i]);
    }
  }
  return 0;
}