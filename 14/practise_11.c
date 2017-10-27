// add -lm argument when compiling
#include <stdio.h>
#include <math.h>

double pow(double, double);
void transform(double [], double [], int, double (*cb) (double, double));

int main(void) {
  const int kLength = 100;
  double source[kLength];
  double target[kLength];
  for (int index = 0; index < kLength; ++index) {
    source[index] = index + 1;
  }
  transform(source, target, kLength, pow);
  return 0;
}

void transform(double source[], double target[], int length, double (*cb)
    (double, double)) {
  for (int index = 0; index < length; ++index) {
    target[index] = (*cb)(source[index], 2);
  }
}
