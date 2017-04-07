#include <stdio.h>

int main(void)
{
  int upper_limit;
  int lower_limit;

  printf("Enter the upper limit and lower limit: "); 
  scanf("%d %d",&upper_limit, &lower_limit);

  while(lower_limit<=upper_limit)
  {
    printf("%d %d %d\n",lower_limit,lower_limit*lower_limit,lower_limit*lower_limit*lower_limit );
    lower_limit++;
  }

  return 0;
}