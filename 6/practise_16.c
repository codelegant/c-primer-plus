#include <stdio.h>

int main(void)
{
    const float interest = 0.08;
  int principal = 1000000;
  float sum = principal;
  int term = 0;

  //simple interest
  do{
    term++;
    sum = sum + principal * interest - 100000;
  }while(sum>0);
  printf("Simple interest, take %d years.\n", term);

  //compound interest
  sum = principal;
  term = 0;
  do{
    term++;
    sum = sum + sum * interest - 100000;
  }while(sum>0);
  printf("Compound interest, take %d years\n", term);

  return 0;
}