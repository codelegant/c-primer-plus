#include <stdio.h>

int main(void)
{
  float value;
  for(value =36F;value>0;value/=2)
    printf("%3f\n", value);

  return 0;
}