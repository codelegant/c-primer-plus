#include <stdio.h>
#define MONTHS 12
struct month{
  char name[9];
  char abbr[3];
  int days;
  int symbol;
};

int main(void){
  struct month year[MONTHS]={
    { "January", "Jan", 31, 1 },
    { "February", "Feb", 28, 2 },
    { "March", "Mar", 31, 3 },
    { "April", "Apr", 30, 4 },
    { "May", "May", 31, 5 },
    { "June", "Jun", 30, 6 },
    { "July", "Jul", 31, 7 },
    { "Aguest", "Agu", 31, 8 },
    { "September", "Sep", 30, 9 },
    { "October", "Oct", 31, 10 },
    { "November", "Nov", 30, 11 },
    { "December", "Dec", 31, 12 }
  };
  int monthSymbol;
  int days = 0;
  printf("输入代表月份数字：");
  scanf("%d", &monthSymbol);
  for(int index = 0; index < monthSymbol; index++ ){
    days += year[index].days;
  }
  printf("总共的天数：%d\n", days);
  return 0;
}
