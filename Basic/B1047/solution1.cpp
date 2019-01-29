#include<algorithm>
#include<iostream>
using namespace std;
int main(){
  int a;
  int b[1001] = {0};
  cin >> a;
  int maxid = 0, maxt = 0;
  for(int i = 0; i < a; ++i){
    int a1,a2,a3;
    scanf("%d-%d %d", &a1, &a2, &a3);
    b[a1] += a3;
    if(b[a1] > maxt){
      maxid = a1;
      maxt = b[a1];
    }
  }
  printf("%d %d", maxid, maxt);
  return 0;
}