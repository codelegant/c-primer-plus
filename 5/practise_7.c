#include <stdio.h>

float cub(float num)
{
  return num * num *num;
}

int main(void)
{
  float start;
  printf("Enter a float number\n");
  scanf("%f",&start);
  printf("Result is %f\n",cub(start) );
  return 0;
}
