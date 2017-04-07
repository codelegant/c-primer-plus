#include <stdio.h>

long int multi(int num);
int main(void)
{
  printf("%ld\n", multi(2));
  return 0;
}

long multi(int num)
{
  return num*num;
}
