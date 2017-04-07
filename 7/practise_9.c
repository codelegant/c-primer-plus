#include <stdio.h>
#include <stdbool.h>

int main(void)
{
  unsigned long num;
  unsigned long div;
  bool isPrime;

  printf("Please enter an integer for analysis: ");
  scanf("%lu", &num);
  do
  {
    for(div = 2, isPrime = true;(div * div) <= num;div++)
    {
      if(num % div == 0)
      {
        isPrime = false;
        break;
      }
    }
    
    if(isPrime)
      printf("%lu is prime.\n", num);
  }while(--num>=2);
  printf("Bye.\n");
  return 0;
}