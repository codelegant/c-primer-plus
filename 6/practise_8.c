#include <stdio.h>

float compute(float num_1, float num_2);

int main(void)
{
  float num_1;
  float num_2;

  printf("Enter two numbers: ");
  while(scanf("%f %f",&num_1,&num_2)==2)
  {
    printf("%f\n", compute(num_1, num_2));
  }

  return 0;
}

float compute(float num_1, float num_2)
{
  return (num_1-num_2)/num_1*num_2;
}