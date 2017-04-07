#include <stdio.h>

int main(void)
{
  unsigned long long times;
  float a=1.0;
  float b=1.0;
  unsigned long long i = 1;
  unsigned long long j = 1;
  short mark=1;
  printf("Enter times:");
  scanf("%lld", &times);

  while(i++<times)
  {
    a += 1/(float)i;
  }

  while(j++<times)
  {
    mark *=-1;
    b += mark/(float)j;
  }

  printf("a: %f\n", a);
  printf("b: %f\n", b);

  return 0;
}