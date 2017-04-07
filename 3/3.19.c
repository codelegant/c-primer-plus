#include <stdio.h>

int main(void)
{
  float fUnitMass=3e-23;
  unsigned short iQuartMass=950;
  unsigned long long iQuart;
  printf("Enter the quart of water: ");
  scanf("%llu",&iQuart);
  printf("The count of hydrone in %llu quart water is %llu\n",iQuart,iQuart*iQuartMass/fUnitMass);
  system("PAUSE");
}