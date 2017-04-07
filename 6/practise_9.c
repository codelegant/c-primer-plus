#include <stdio.h>

int main(void)
{
  int upper_limit;
  int lower_limit;

  printf("Enter upper limit and lower limit: ");
  scanf("%d %d",&upper_limit, &lower_limit);
  while(upper_limit>lower_limit)
  {
    int sum = 0;
    do
    {
      sum+=lower_limit*lower_limit;
    }while(lower_limit++<=upper_limit);
    printf("The sums from %d to %d is %d\n",lower_limit*lower_limit, upper_limit*upper_limit, sum);
  }

  return 0;
}