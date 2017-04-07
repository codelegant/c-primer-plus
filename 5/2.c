#include <stdio.h>

int main(void)
{
  const float CROP = 1E15;
  const unsigned short SQUARES = 64;

  double current;
  double total;
  short count = 1;

  printf("square   grains total ");
  printf("fraction     of ");
  printf("     added       grain     ");
  printf("US total\n");

  total = current = 1.0;
  printf("%4d %13.2e %12e %12.2e\n",count, current, total, total/CROP);
  while(count < SQUARES)
  {
    count=count + 1;
    current = 2.0 * current;
    total=total + current;
    printf("%4d %13.2e %12e %12.2e\n",count, current, total, total/CROP);
  }
  printf("That's all.\n");
  return 0;
}