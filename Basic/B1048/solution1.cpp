#include <cstdio>

int main() {
  char a[105] = {};
  char b[105] = {};
  char d[105] = {};
  char mp[13] = {'0', '1', '2', '3', '4', '5', '6',
                 '7', '8', '9', 'J', 'Q', 'K'};
  char c;
  int d1 = 0, d2 = 0;
  scanf("%[^ ] %s", a, b);
  for (int i = 0; i < 105; ++i) {
    if (a[i] != '\0') ++d1;
    if (b[i] != '\0') ++d2;
  }
  for (int i = 0; i < d1 / 2; ++i) {
    c = a[i];
    a[i] = a[d1 - i - 1];
    a[d1 - i - 1] = c;
  }
  for (int i = 0; i < d2 / 2; ++i) {
    c = b[i];
    b[i] = b[d2 - i - 1];
    b[d2 - i - 1] = c;
  }
  if (d1 > d2) {
    for (int i = d2; i < d1; ++i) {
      b[i] = '0';
    }
  } else {
    for (int i = d1; i < d2; ++i) {
      a[i] = '0';
    }
  }
  int s = (d1 > d2) ? d1 : d2;
  int j = 0;
  for (int i = 0; i < s; ++i) {
    if ((i + 1) % 2 == 1) {
      d[j] = mp[((a[i] - 48) + (b[i] - 48)) % 13];
      ++j;
    } else {
      int m = b[i] - a[i];
      if (m < 0) m += 10;
      d[j] = m + 48;
      ++j;
    }
  }
  for (int k = j - 1; k >= 0; --k) {
    printf("%c", d[k]);
  }
  return 0;
}