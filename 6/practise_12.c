#include <stdio.h>

int main(void)
{
  int power_arr[8];
  int i;
  int j=0;
  int power=1;
  for(i=0; i<8; i++)
  {
    power_arr[i]=power;
    power*=2;
  }
  do{
    printf("%d ", power_arr[j]);
  }while(++j<8);
  
  return 0;
}