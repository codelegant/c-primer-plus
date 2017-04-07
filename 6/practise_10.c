#include <stdio.h>

int main(void)
{
  int nums[8];
  int i = 0;
  int j = 7;
  printf("Etner 8 num, sperate by space: ");
  do{
    scanf("%d", &nums[i]);
  }while(++i<8);

  do{
    printf("%d",nums[j]);
  }while(j-->0);

  return 0;
}