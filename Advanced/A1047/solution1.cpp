#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m;

bool cmp(char* a, char* b) {
  int ca = strcmp(a, b);
  return ca < 0;
}

int main() {
  scanf("%d %d", &n, &m);
  vector<char*> course[m + 1];
  for (int i = 0; i < n; ++i) {
    char name[5];
    int w;
    scanf("%s %d", name, &w);
    for (int j = 0; j < w; ++j) {
      int a;
      char* b = new char[5];
      b = strcpy(b, name);
      scanf("%d", &a);
      course[a].push_back(b);
    }
  }
  for (int i = 1; i <= m; ++i) {
    printf("%d %d\n", i, course[i].size());
    sort(course[i].begin(), course[i].end(), cmp);
    for (int j = 0; j < course[i].size(); ++j) {
      printf("%s\n", course[i][j]);
    }
  }
  return 0;
}