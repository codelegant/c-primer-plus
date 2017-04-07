#include <stdio.h>

int main(void)
{
  const float principal = 100;
  const float simple_interest = 0.1;
  const float compound_interest = 0.05;
  short term = 0;
  float daphne_sum = 100;
  float deirdre_sum = 100;

  do{
    term++;
    daphne_sum += (principal * simple_interest);
    deirdre_sum += (deirdre_sum * compound_interest);
  }while(daphne_sum >= deirdre_sum);

  printf("Use years: %ld\n", term);
  printf("Daphne total: %f\n", daphne_sum);
  printf("Deirdre total: %f\n", deirdre_sum);

  return 0;
}