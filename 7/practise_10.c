#include <stdio.h>
#include <windows.h>
#define RATE_1 .15F
#define RATE_2 .28F
#define PAY_1 17850
#define PAY_2 23900
#define PAY_3 29750
#define PAY_4 14875

int main(void)
{
    unsigned short choose;
    float pay_base;
    float pay;
    float taxes;

    printf("********************************************\n");
    printf("请选择你的税金种类，输入对应的数字编码：\n");
    printf("1) 单身                        2）户主\n");
    printf("3) 已婚，共有                  4）已婚，离异\n");
    printf("5) 退出\n");
    printf("********************************************\n");
    printf("你的选择是：");
    
    while(scanf("%hd",&choose) && choose !=5){
        if(choose<1||choose>5){
            printf("请输入1-5之间的数字：\n");
            printf("你的选择是：");
            continue;
        }

        switch(choose){
            case 1:
                pay_base = PAY_1;
                break;
            case 2:
                pay_base = PAY_2;
                break;
            case 3:
                pay_base = PAY_3;
                break;
            case 4:
                pay_base = PAY_4;
                break;
        }
        printf("你的收入基准是：%.0f\n", pay_base);
        printf("请输入你的应征税收入：");
        scanf("%f",&pay);
        if(pay<=pay_base)
        {
            taxes = pay*RATE_1;
        }
        else{
            taxes = pay_base*RATE_1+(pay-pay_base)*RATE_2;
        }
        printf("应该交纳的税金是：%.2f\n", taxes);
    }
    printf("你退出了程序：\n");

    return 0;
}