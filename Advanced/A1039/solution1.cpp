#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int M = 26 * 26 * 26 * 10 + 1;

int getID(char name[]) {
  int id = 0;
  for (int i = 0; i < 3; ++i) {
    id = id * 26 + (name[i] - 'A');
  }
  id = id * 10 + name[3] - '0';
  return id;
}

int main() {
  vector<int> courses[M];
  char name[5];
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int index, num;
    scanf("%d %d", &index, &num);
    for (int j = 0; j < num; ++j) {
      scanf("%s", name);
      courses[getID(name)].push_back(index);
    }
  }
  for (int i = 0; i < n; ++i) {
    scanf("%s", name);
    int id = getID(name);
    sort(courses[id].begin(), courses[id].end());
    printf("%s %d", name, courses[id].size());
    for (int j = 0; j < courses[id].size(); ++j) {
      printf(" %d", courses[id][j]);
    }
    printf("\n");
  }
  return 0;
}