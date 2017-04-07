#include <stdio.h>

int main(void)
{
  int total;
  int count=0;
  long long sum=0LL;
  printf("Enter the total: ");
  scanf("%d",&total);
  while(count++<total)
    sum=sum + count * count;
  printf("sum = %lld\n", sum);
  return 0;
}