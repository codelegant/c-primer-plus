#include <stdio.h>

int main(void)
{
  long long x=100;
  printf("dec = %d; octal = %o; hex = %X\n",x,x,x);
  printf("dec = %d; octal = %#o; hex = %#X\n",x,x,x);
  return 0;
}