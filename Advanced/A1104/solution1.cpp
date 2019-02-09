/**
 * The type of data is significant for this problem.
 * 1) at line 12 (i * (n + 1 - i) * a) is wrong
 *    because the first two ops make the sum have wrong precision,
 *    the sum would has the size of int or float instead of double.
 *    make (a * ...) become the first op to guarantee the precision.
 * 2) the input/output of double data
 *    use cin or scanf("%lf") because the %lf and %f are different for scanf
 *    but you'd better use %f for printf.
 *    For C++, printf("%f") and printf("%lf") have no differences and even the %lf is wrong.
 *    The system will fix that when the executing task begins.
 */
#include <iostream>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  double a = 0, sum = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%lf", &a);
    sum += a * i * (n + 1 - i);
  }
  printf("%.2f", sum);
  return 0;
}
