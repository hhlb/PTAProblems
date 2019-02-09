/**
 * ## The data type for A1104/B1049 is significant

 * - [The effect of computing order on data types](#the-effect-of-computing-order-on-data-types)
 * - [The input method for doubles](#the-input-method-for-doubles)
 *
 * ### The effect of computing order on data types
 * For instance 
 * ```c++
 * //double sum, int i, int n, int a
 * //1
 * sum += a * i * (n + 1 - i);
 * //2
 * sum += i * (n + 1 - i) * a;
 * ```
 * The result is different and the second can not guarantee the precision.
 * The data type would change when it is calculating.
 * 
 * ### The input method for doubles
 * Use `cin` or `printf("%lf")` to input doubles because the `%lf` and `%f` are different for `scanf()`.
 * And use `cout` or `printf("%f")` to output that.
 * **For C++, `printf("%f")` and `printf("%lf")` have no differences and even the %lf is wrong.
 * *The system will fix that when the executing task begins*.**
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
