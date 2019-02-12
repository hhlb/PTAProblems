#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

string findStr(string s, int n, int& e) {
  int a = 0;
  int j = 0;
  while (s.length() > 0 && s[0] == '0') {
    s.erase(s.begin());
  }
  if (s[0] == '.') {
    s.erase(s.begin());
    while (s.length() > 0 && s[0] == '0') {
      s.erase(s.begin());
      --a;
    }
  } else {
    while (j < s.length() && s[j] != '.') {
      ++j;
      ++a;
    }
    if (j < s.length()) {
      s.erase(s.begin() + j);
    }
  }
  if (s.length() == 0) {
    a = 0;
  }
  int num = 0;
  j = 0;
  string res;
  while (num < n) {
    if (j < s.length())
      res += s[j++];
    else
      res += '0';
    ++num;
  }
  e = a;
  return res;
}

int main() {
  int a;
  string s1, s2;
  cin >> a >> s1 >> s2;
  string s3, s4;
  int e1, e2;
  s3 = findStr(s1, a, e1);
  s4 = findStr(s2, a, e2);
  if (s3 == s4 && e1 == e2) {
    cout << "YES 0." << s3 << "*10^" << e1;
  } else {
    cout << "NO 0." << s3 << "*10^" << e1 << " 0." << s4 << "*10^" << e2;
  }
  return 0;
}