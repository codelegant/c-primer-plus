#include <stdio.h>
#define WAGE_PER_HOUR 10.00F
#define OVERTIME_BASE 40
#define OVERTIME_RATE 1.5F
#define WAGE_BASE_1 300
#define TAX_RATE_1 0.15F
#define WAGE_BASE_2 150
#define TAX_RATE_2 0.2F
#define TAX_RATE_3 0.25F

int main(void)
{
    unsigned int hours;
    float wage;
    float taxes;

    printf("Enter work time of a week: ");
    scanf("%d", &hours);
    if(hours<=OVERTIME_BASE)
        wage=hours*WAGE_PER_HOUR;
    else
        wage=(OVERTIME_BASE+(hours-OVERTIME_BASE)*OVERTIME_RATE)*WAGE_PER_HOUR;

    if(wage<=WAGE_BASE_1)
        taxes=WAGE_BASE_1 * TAX_RATE_1;
    else if(wage>WAGE_BASE_1 && wage<=WAGE_BASE_1+WAGE_BASE_2)
        taxes=WAGE_BASE_1*TAX_RATE_1+(wage-WAGE_BASE_1)*TAX_RATE_2;
    else
        taxes=WAGE_BASE_1*TAX_RATE_1+WAGE_BASE_1*TAX_RATE_2+(wage-WAGE_BASE_1-WAGE_BASE_2)*TAX_RATE_3;


    printf("Total wage is %f, taxes is %f, pure wage is %f.\n", wage, taxes, wage-taxes);
    return 0;
}
