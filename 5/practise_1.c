#include <stdio.h>

int main(void)
{
  const short M_PER_H = 60;
  long long minutes;

  printf("Enter the minutes\n");
  scanf("%lld",&minutes);

  while(minutes > 0){
    printf("%lld hours %lld minutes\n",minutes/M_PER_H,minutes%M_PER_H);
    printf("Enter then minutes\n");
    scanf("%lld",&minutes);
  }

}