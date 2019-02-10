#include<iostream>
using namespace std;
int main(){
  int n;
  scanf("%d", &n);
  int a = 1;
  int res = 0;
  while(n / a != 0){
    int l = n / (a * 10);
    int m = n / a % 10;
    int r = n % a;
    if(m == 0) res += l * a;
    else if (m == 1) res += l * a + r + 1;
    else res += (l + 1) * a;
    a *= 10;
  }
  printf("%d", res);
  return 0;
}