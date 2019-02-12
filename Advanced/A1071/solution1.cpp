#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

bool check(char a) {
  if (a >= '0' && a <= '9') return true;
  if (a >= 'A' && a <= 'Z') return true;
  if (a >= 'a' && a <= 'z') return true;
  return false;
}

int main() {
  string s;
  getline(cin, s);
  map<string, int> count;
  string::iterator it = s.begin();
  while (it != s.end()) {
    string word;
    while (it != s.end() && check(*it)) {
      if (*it >= 'A' && *it <= 'Z') {
        *it = *it + 32;
      }
      word += *it;
      ++it;
    }
    if (word != "") {
      if (count.find(word) == count.end())
        count[word] = 1;
      else
        ++count[word];
    }
    while (it != s.end() && !check(*it)) {
      ++it;
    }
  }
  string ans;
  int max = 0;
  for (map<string, int>::iterator it = count.begin(); it != count.end(); ++it) {
    if (it->second > max) {
      max = it->second;
      ans = it->first;
    }
  }
  cout << ans << " " << max;
  return 0;
}