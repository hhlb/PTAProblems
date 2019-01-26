#include <iostream>
using namespace std;
string sss[10] = {"ling", "yi",  "er", "san", "si",
                  "wu",   "liu", "qi", "ba",  "jiu"};
string wei[6] = {"Shi", "Bai", "Qian", "Wan", "Yi"};
int main() {
  string s;
  cin >> s;
  int len = s.length();
  int left = 0, right = len - 1;
  if (s[0] == '-') {
    cout << "Fu";
    left++;
  }
  while (left + 4 <= right) {
    right -= 4;
  }
  while (left < len) {
    bool flag = false;
    bool havewei = false;
    while (left <= right) {
      if (left > 0 && s[left] == '0') {
        flag = true;
      } else {
        if (flag == true) {
          cout << " ling";
          flag = false;
        }
        if (left > 0) cout << " ";
        cout << sss[s[left] - '0'];
        havewei = true;
        if (left != right) {
          cout << " " << wei[right - left - 1];
        }
      }
      left++;
    }
    if (havewei == true && right != len - 1) {
      cout << " " << wei[(len - 1 - right) / 4 + 2];
    }
    right += 4;
  }
  return 0;
}