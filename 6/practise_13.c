#include <stdio.h>

int main(void)
{
  const short LENGTH=8;
  double arr_1[LENGTH];
  double arr_2[LENGTH];
  short i;
  double sum=0;

  printf("Enter eight double num:\n");
  i=0;
  do{
    scanf("%lf",&arr_1[i]);
  }while(++i<LENGTH);

  i=0;
  do{
    sum+=arr_1[i];
    arr_2[i]=sum;
  }while(++i<LENGTH);

  i=0;
  do{
    printf("%10lf",arr_1[i]);
  }while(++i<LENGTH);

  printf("\n");
  i=0;
  do{
    printf("%10lf",arr_2[i]);
  }while(++i<LENGTH);

  return 0;
}