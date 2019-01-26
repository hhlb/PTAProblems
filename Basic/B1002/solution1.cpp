#include <math.h>
#include <cstdio>
int main() {
  char s[100];
  char* c[10];
  c[0] = "ling";
  c[1] = "yi";
  c[2] = "er";
  c[3] = "san";
  c[4] = "si";
  c[5] = "wu";
  c[6] = "liu";
  c[7] = "qi";
  c[8] = "ba";
  c[9] = "jiu";
  int sum = 0;
  int l = 0;
  while ((s[l] = getchar()) != '\n') {
    sum += s[l] - 48;
    ++l;
  }
  int a[10] = {0};
  int i = 0;
  do {
    a[i] = sum % 10;
    sum /= 10;
    ++i;
  } while (sum != 0);
  while(i--){
    printf("%s", c[a[i]]);
    if(i!=0) printf(" ");
  }
  return 0;
}