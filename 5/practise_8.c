#include <stdio.h>

void Temperatures(double fahrenheit)
{
  const double F_C_FACTOR = 1.8;
  const double F_C_DIFFERENCE = 32.0;
  const double C_K_DIFFERENCE = 273.16;

  printf("Fahrenheit = %.2f\n", fahrenheit);
  printf("Celsius = %.2f\n", F_C_FACTOR * fahrenheit + F_C_DIFFERENCE);
  printf("Kelvin = %.2f\n", F_C_FACTOR * fahrenheit + F_C_DIFFERENCE + C_K_DIFFERENCE);
}

int main(void)
{
  double fahrenheit;
  int status;
  printf("Enter fahrenheit temperature: ");
  status = scanf("%lf",&fahrenheit);

  while(status == 1){
    printf("fahrenheit %.2f\n",fahrenheit);
    Temperatures(fahrenheit);
    printf("Enter fahrenheit temperature: ");
    status = scanf("%lf",&fahrenheit);
  }
  printf("Bye\n");
  return 0;
}