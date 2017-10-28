#include <stdio.h>
#include <time.h>

void Timer(double time);

int main(void) {
  Timer(10);
  return 0;
}

void Timer(double time) {
  double count = 0;
  double pre = (double) clock();
  double current;

  while (count < time) {
    current = (double) clock();
    count += (current - pre) / CLOCKS_PER_SEC;
    pre = current;
  }
  printf("Time is %.6f\n", time);
  printf("Count is %.6f\n", count);
}
