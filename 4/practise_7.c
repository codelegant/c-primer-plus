#include <stdio.h>
#define GALLON_TO_LITRE 3.785F
#define MILE_TO_KM 1.609F

int main(void)
{
  float f_mile;
  float f_gallon;

  printf("Enter drive miles and coast gallons gasoline\n");
  scanf("%f %f",&f_mile,&f_gallon);

  printf("Drive %.1f miles per gallon gasoline.\n",f_mile/f_gallon);
  printf("Drive 100 km. coast %.1f litre gasoline.\n",(f_gallon*GALLON_TO_LITRE)/(f_mile*MILE_TO_KM)*100);

  return 0;
}