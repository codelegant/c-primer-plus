#include <stdio.h>

int main(void)
{
  const short DAY_PER_WEEK=7;
  long long day;

  printf("Enter days\n");
  scanf("%lld",&day);
  while(day>0){
    printf("%lld days are %lld weeks, %lld days\n", day,day/DAY_PER_WEEK,day%DAY_PER_WEEK);
    printf("Enter days\n");
    scanf("%lld",&day);
  }

  return 0;
}