#include <stdio.h>

int main(void)
{
  double fInput;
  printf("Please enter a float:");
  scanf("%f",&fInput);
  printf("The decimals form of the float is: %f, the exponentia form of the float is: %e\n",fInput,fInput);
  system("PAUSE");
  return 0;
}