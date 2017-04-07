#include <stdio.h>

int main(void)
{
  const float CM_PER_FT = 30.48F;
  const float CM_PER_IN = 2.54F;
  float cm;

  printf("Enter a height in centimeters: ");
  scanf("%f",&cm);
  while(cm > 0){
    printf("%.1f cm = %.1f feet, %.1f inches\n", cm, cm/CM_PER_FT, cm/CM_PER_IN);
    printf("Enter a height in centimeters (<=0 to quit): ");
    scanf("%f",&cm);
  }
  printf("bye\n");
  return 0;
}