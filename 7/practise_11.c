#include <stdio.h>
#define GLOBAL_ARTICHOKE_PRICE 1.25F //朝鲜蓟
#define BEET_PRICE .65F //甜菜
#define CARROT_PRICE .89F //胡萝卜

int main(void)
{
    float global_artichoke = 0;
    float beet = 0;
    float carrot = 0;
    char choose;
    float const_per_pound = 0;
    float total_pounds = 0;
    float global_artichoke_cost = 0;
    float beet_cost = 0;
    float carrot_cost = 0;
    float total_price = 0;
    float total_discount = 0;
    float total_cost = 0;

    printf("****************************\n");
    printf("请选择你要输入磅数的蔬菜种类：\n");
    printf("a) 朝鲜蓟        b) 甜菜\n");
    printf("c) 胡萝卜        q) 退出定购\n");
    printf("****************************\n");
    printf("请选择：");

    while((choose = getchar()) != 'q'){
        switch(choose){
            case 'a':
                printf("请输入要定购朝鲜蓟的磅数：");
                scanf("%f", &global_artichoke);
                break;
            case 'b':
                printf("请输入要定购甜菜的磅数：");
                scanf("%f", &beet);
                break;
            case 'c':
                printf("请输入要定购胡萝卜的磅数：");
                scanf("%f", &carrot);
                break;
        }
        if((choose = getchar())=='\n')
            printf("请继续选择：");
    }

    total_pounds = global_artichoke + beet + carrot;
    global_artichoke_cost = global_artichoke * GLOBAL_ARTICHOKE_PRICE;
    beet_cost = beet * BEET_PRICE;
    carrot_cost = carrot * CARROT_PRICE;
    total_price = global_artichoke_cost + beet_cost + carrot_cost;

    if(total_price>100)
    {
        total_discount = total_price * .05;
        total_price -= total_discount;
    }

    if(total_pounds<=5)
    {
        total_cost = 3.5;
        total_price += total_cost;
    }
    else if(total_pounds>5 && total_pounds<20)
    {
        total_cost = 10;
        total_price += total_cost;
    }
    else{
        total_cost = 8 + total_pounds * .1;
        total_price += total_cost;
    }

    printf("每磅费用：%.2f\n", total_price/total_pounds);
    printf("总磅数：%.2f\n", total_pounds);
    printf("朝鲜蓟费用：%.2f\n", global_artichoke_cost);
    printf("甜菜费用：%.2f\n", beet_cost);
    printf("胡萝卜费用：%.2f\n", carrot_cost);
    printf("总费用：%.2f\n", total_price);
    printf("折扣：%.2f\n", total_discount);
    if(total_cost)
        printf("运输与装卸费用总数：%.2f\n", total_cost);

    return 0;
}