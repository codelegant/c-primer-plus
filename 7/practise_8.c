#include <stdio.h>
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
    float pay_rate;
    int pay_rate_selection;

    printf("****************************************************************\n");
    printf("Enter the number corresponding to the desired pay rate or acton:\n");
    printf("1) $8.75/hr                     2) $9.33/hr\n");
    printf("3) $10.75/hr                    4) $11.20/hr\n");
    printf("5) quit\n");
    printf("****************************************************************\n");
    printf("Chose a number: ");

    while(scanf("%d",&pay_rate_selection) && pay_rate_selection!=5){
        if(pay_rate_selection<1 || pay_rate_selection>5){
            printf("The number should between 1 and 5\n");
            printf("Chose a number: ");
            continue;
        }
        switch(pay_rate_selection){
            case 1:
                pay_rate = 8.75F;
                break;
            case 2:
                pay_rate = 9.33F;
                break;
            case 3:
                pay_rate = 10.75F;
                break;
            case 4:
                pay_rate = 11.20F;
                break;
        }

        printf("Your pay rate is: $%.2f.\n",pay_rate);
        printf("Enter work time of a week: ");
        scanf("%d", &hours);

        if(hours<=OVERTIME_BASE)
            wage=hours*pay_rate;
        else
            wage=(OVERTIME_BASE+(hours-OVERTIME_BASE)*OVERTIME_RATE)*pay_rate;

        if(wage<=WAGE_BASE_1)
            taxes=WAGE_BASE_1 * TAX_RATE_1;
        else if(wage>WAGE_BASE_1 && wage<=WAGE_BASE_1+WAGE_BASE_2)
            taxes=WAGE_BASE_1*TAX_RATE_1+(wage-WAGE_BASE_1)*TAX_RATE_2;
        else
            taxes=WAGE_BASE_1*TAX_RATE_1+WAGE_BASE_1*TAX_RATE_2+(wage-WAGE_BASE_1-WAGE_BASE_2)*TAX_RATE_3;


        printf("Total wage is $%.2f, taxes is $%.2f, pure wage is $%.2f.\n", wage, taxes, wage-taxes);
        printf("Chose a number: ");
    }

    printf("Your quit!\n");
    return 0;
}
