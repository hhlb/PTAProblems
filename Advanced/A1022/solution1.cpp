#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int n, m;

map<string, set<int> > titles;
map<string, set<int> > keywords;
map<string, set<int> > authors;
map<string, set<int> > publishers;
map<string, set<int> > years;

void buildIndex(int id, string year, string title, string author,
                string publisher) {
  titles[title].insert(id);
  authors[author].insert(id);
  publishers[publisher].insert(id);
  years[year].insert(id);
}

void getkeywords(int id) {
  string a;
  getline(cin, a);
  int i = 0;
  string::iterator it = a.begin();
  while (it != a.end()) {
    string word;
    while (it != a.end() && *it != ' ') {
      word += *it;
      ++it;
    }
    keywords[word].insert(id);
    if (it != a.end() && *it == ' ') {
      ++it;
    }
  }
}

int s2int(string s) {
  int res = 0;
  for (int i = 0; i < 4; ++i) {
    res = res * 10 + s[i];
  }
  return res;
}

int main() {
  int id;
  string title, author, publisher, year;
  string keyword[5];
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &id);
    getchar();
    getline(cin, title);
    getline(cin, author);
    getkeywords(id);
    getline(cin, publisher);
    getline(cin, year);
    buildIndex(id, year, title, author, publisher);
  }
  scanf("%d", &m);
  int index;
  string s;
  for (int i = 0; i < m; ++i) {
    scanf("%d: ", &index);
    getline(cin, s);
    switch (index) {
      case 1: {
        cout << index << ": " << s << endl;
        if (titles.find(s) != titles.end()) {
          for (set<int>::iterator it = titles[s].begin(); it != titles[s].end();
               ++it) {
            printf("%07d\n", *it);
          }
        } else {
          printf("Not Found\n");
        }
        break;
      }
      case 2: {
        cout << index << ": " << s << endl;
        if (authors.find(s) != authors.end()) {
          for (set<int>::iterator it = authors[s].begin();
               it != authors[s].end(); ++it) {
            printf("%07d\n", *it);
          }
        } else {
          printf("Not Found\n");
        }
        break;
      }
      case 3: {
        cout << index << ": " << s << endl;
        if (keywords.find(s) != keywords.end()) {
          for (set<int>::iterator it = keywords[s].begin();
               it != keywords[s].end(); ++it) {
            printf("%07d\n", *it);
          }
        } else {
          printf("Not Found\n");
        }
        break;
      }
      case 4: {
        cout << index << ": " << s << endl;
        if (publishers.find(s) != publishers.end()) {
          for (set<int>::iterator it = publishers[s].begin();
               it != publishers[s].end(); ++it) {
            printf("%07d\n", *it);
          }
        } else {
          printf("Not Found\n");
        }
        break;
      }
      case 5: {
        cout << index << ": " << s << endl;
        if (years.find(s) != years.end()) {
          for (set<int>::iterator it = years[s].begin(); it != years[s].end();
               ++it) {
            printf("%07d\n", *it);
          }
        } else {
          printf("Not Found\n");
        }
        break;
      }
      default:
        break;
    }
  }
  return 0;
}
