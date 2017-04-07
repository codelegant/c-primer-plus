#include <stdio.h>

int main(void)
{
  short a;
  float b_1;
  float b_2;
  char c[8];
  char d[8];
  short d_2;
  short e;

  printf("Enter 101\n");
  scanf("%hd",&a);

  printf("Enter 22.32 8.34E-09\n");
  scanf("%f %E",&b_1,&b_2);

  printf("Enter linguini\n");
  scanf("%s",c);

  printf("Enter catch 22\n");
  scanf("%s %hd",d, &d_2);

  printf("Enter catch 22 again.\n");
  scanf("%*s %hd",&e);

  printf("a = %hd\n", a);
  printf("b_1 = %4.2f\n", b_1);
  printf("b_2 = %3.2E\n", b_2);
  printf("c[8] = %s\n", c);
  printf("d[8] = %s %hd\n", d, d_2);
  printf("e = %hd\n", e);

  return 0;
}