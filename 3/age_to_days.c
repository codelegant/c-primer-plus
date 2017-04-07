#include <stdio.h>
#include <time.h>
int main(void)
{
  int yearAge=25;
  int bornMonth=5;
  int bornDay=27;
  int currentMonth=3;
  int currentDay=5;
  int daysOfYear=7*31+28+4*30;
  int fullDays=25*daysOfYear;
  int redundantMonth=bornMonth-currentMonth;
  int redundantDay=bornDay-currentMonth;
  int agedays=fullDays-redundantMonth*30-redundantDay;
  printf("My age of days is %d",agedays);
  return 0;
}