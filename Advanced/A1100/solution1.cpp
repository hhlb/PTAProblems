#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

string ud[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun",
                 "jly",  "aug", "sep", "oct", "nov", "dec"};

string td[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes",
                 "hei",  "elo", "syy", "lok", "mer", "jou"};

string num2str[170];
map<string, int> str2num;

void init() {
  for (int i = 0; i < 13; ++i) {
    num2str[i] = ud[i];
    str2num[ud[i]] = i;
    num2str[i * 13] = td[i];
    str2num[td[i]] = i * 13;
  }
  for (int i = 1; i < 13; ++i) {
    for (int j = 1; j < 13; ++j) {
      string str = td[i] + " " + ud[j];
      num2str[i * 13 + j] = str;
      str2num[str] = i * 13 + j;
    }
  }
}

int main() {
  string s;
  int n = 0;
  scanf("%d%*c", &n);  // clear the '\n'
  init();
  for (int i = 0; i < n; ++i) {
    getline(cin, s);
    if (s[0] >= '0' && s[0] <= '9') {
      int num = 0;
      for (int j = 0; j < s.length(); ++j) {
        num = num * 10 + s[j] - '0';
      }
      cout << num2str[num] << endl;
    } else {
      cout << str2num[s] << endl;
    }
  }
  return 0;
}