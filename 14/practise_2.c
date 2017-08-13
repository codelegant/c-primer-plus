#include <stdio.h>
#include <string.h>
#define MONTHS 12

struct month{
  char name[10];
  char abbr[4];
  int days;
  char symbol[3];
};
void LeapMonth(int, struct month *);

int main(void) {
  struct month months[MONTHS]={
    { "January", "Jan", 31, "1" },
    { "February", "Feb", 28, "2" },
    { "March", "Mar", 31, "3" },
    { "April", "Apr", 30, "4" },
    { "May", "May", 31, "5" },
    { "June", "Jun", 30, "6" },
    { "July", "Jul", 31, "7" },
    { "Aguest", "Agu", 31, "8" },
    { "September", "Sep", 30, "9" },
    { "October", "Oct", 31, "10" },
    { "November", "Nov", 30, "11" },
    { "December", "Dec", 31, "12" }
  };
  int year;
  char month[10];
  int day;
  int days = 0;

  printf("Enter the year: ");
  scanf("%d", &year);
  printf("Enter the month: ");
  scanf("%s", month);
  printf("Enter the day: ");
  scanf("%d", &day);

  LeapMonth(year, &months[1]);
  printf("The enter year is %d, month is %s, day is %d.\n", year, month, day);

  for (int index = 0; index < MONTHS; index++ ) {
    struct month cur_month = months[index];
    if (
        // 如果字符串相同，就返回 0
        !strcmp(month, cur_month.name) ||
        !strcmp(month, cur_month.abbr) ||
        !strcmp(month, cur_month.symbol)
      ) {
      days += (day > cur_month.days ? cur_month.days : day);
      break;
    }
    days += cur_month.days;
  }

  printf("总共的天数：%d\n", days);
  return 0;
}

void LeapMonth(int year, struct month *ptr) {
  if ((year%4 == 0 && year%100 != 0) || year%400 == 0 ) {
    ptr->days = 29;
  }
}
