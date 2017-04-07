#include <stdio.h>

int main(void)
{
  float f_number;

  printf("Enter float\n");
  scanf("%f",&f_number);
  printf("The input is %.1f or %.1e\n", f_number,f_number);
  printf("The input is %+.3f or %.3E\n", f_number,f_number);

  return 0;
}