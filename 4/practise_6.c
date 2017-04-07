#include <stdio.h>
#include <float.h>

int main(void)
{
  double d_number=1.0/3.0;
  float f_number=1.0/3.0;

  printf("%.3f\n", d_number);
  printf("%.12f\n", d_number);
  printf("%.16f\n", d_number);

  printf("%.3f\n", f_number);
  printf("%.12f\n", f_number);
  printf("%.16f\n", f_number);

  printf("FLT_DIG = %hd\n",FLT_DIG);
  printf("DBL_DIG = %hd\n", DBL_DIG);

  return 0;
}