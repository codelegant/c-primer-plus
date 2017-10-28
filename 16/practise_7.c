#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void ShowArray(const double ar[], int length);
double *NewArray(int n, ...);

int main(void) {
  double *p1;
  double *p2;
  p1 = NewArray(5, 1.2, 2.3, 3.4, 4.5, 5.6);
  p2 = NewArray(4, 100.0, 20.0, 8.08, -1890.0);
  ShowArray(p1, 5);
  ShowArray(p2, 4);

  return 0;
}

void ShowArray(const double ar[], int length) {
  for (int i = 0; i < length; ++i) {
    printf("%.1f ", ar[i]);
  }
  putchar('\n');
}

double *NewArray(int n, ...) {
  va_list arguments;
  va_start(arguments, n);
  double ar[n];
  for (int i = 0; i < n; ++i) {
    ar[i] = va_arg(arguments, double);
  }
  va_end(arguments);
  return ar;
}
