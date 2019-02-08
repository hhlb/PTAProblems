#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> original;
vector<int> temparray;
vector<int> goalarray;
int n;

void showArray(vector<int> a);
bool equals(vector<int> a, vector<int> b);
bool insertSort();
void mergeSort();

bool equals(vector<int> a, vector<int> b) {
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) return false;
  }
  return true;
}

bool insertSort() {
  bool flag = false;
  for (int i = 1; i < n; ++i) {
    if (i != 1 && equals(temparray, goalarray)) {
      flag = true;
    }
    int temp = temparray[i];
    int j = i;
    while (j > 0 && temparray[j - 1] > temp) {
      temparray[j] = temparray[j - 1];
      --j;
    }
    temparray[j] = temp;
    if (flag) {
      return true;
    }
  }
  return false;
}

void mergeSort() {
  int flag = false;
  for (int step = 2; step / 2 <= n; step *= 2) {
    if (step != 2 && equals(temparray, goalarray)) {
      flag = true;
    }
    for (int i = 0; i < n; i += step) {
      sort(temparray.begin() + i, temparray.begin() + min(i + step, n));
    }
    if (flag) {
      showArray(temparray);
      return;
    }
  }
}

void showArray(vector<int> a) {
  for (int i = 0; i < a.size(); ++i) {
    printf("%d", a[i]);
    if (i < a.size() - 1) {
      printf(" ");
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int t;
    scanf("%d", &t);
    original.push_back(t);
    temparray.push_back(t);
  }
  for (int i = 0; i < n; ++i) {
    int t;
    scanf("%d", &t);
    goalarray.push_back(t);
  }
  if (insertSort()) {
    printf("Insertion Sort\n");
    showArray(temparray);
  } else {
    printf("Merge Sort\n");
    temparray = original;
    mergeSort();
  }
  return 0;
}
