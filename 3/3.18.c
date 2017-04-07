#include <stdio.h>

int main(void)
{
  float fSecondsOfYear=3.156e+7;
  unsigned short age;
  printf("Please enter your age: ");
  scanf("%hu",&age);
  printf("The seconds of your age is: %f\n",fSecondsOfYear*age);
  system("PAUSE");
  return 0;
}