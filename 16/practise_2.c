#include <stdio.h>
#define HARMONIC_MEAN(x, y) 2/(1/x+1/y)

int main(void) {
  double x = 1;
  double y = 3;
  printf("%.4f\n", HARMONIC_MEAN(x, y));
  return 0;
}
