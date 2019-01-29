// Using cin/cout would cause TIME OUT
#include <iostream>
using namespace std;
int main() {
  int a;
  int b[101] = {0};
  cin >> a;
  for (int i = 0; i < a; ++i) {
    int c;
    scanf("%d", &c);
    ++b[c];
  }
  int d;
  cin >> d;
  for(int i = 0; i < d; ++i){
    int c;
    scanf("%d", &c);
    printf("%d", b[c]);
    if(i != d - 1) printf(" ");
  }
  return 0;
}