#include <stdio.h>
#define GLOBAL_ARTICHOKE_PRICE 1.25F //���ʼ�
#define BEET_PRICE .65F //���
#define CARROT_PRICE .89F //���ܲ�

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
    printf("��ѡ����Ҫ����������߲����ࣺ\n");
    printf("a) ���ʼ�        b) ���\n");
    printf("c) ���ܲ�        q) �˳�����\n");
    printf("****************************\n");
    printf("��ѡ��");

    while((choose = getchar()) != 'q'){
        switch(choose){
            case 'a':
                printf("������Ҫ�������ʼ��İ�����");
                scanf("%f", &global_artichoke);
                break;
            case 'b':
                printf("������Ҫ������˵İ�����");
                scanf("%f", &beet);
                break;
            case 'c':
                printf("������Ҫ�������ܲ��İ�����");
                scanf("%f", &carrot);
                break;
        }
        if((choose = getchar())=='\n')
            printf("�����ѡ��");
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

    printf("ÿ�����ã�%.2f\n", total_price/total_pounds);
    printf("�ܰ�����%.2f\n", total_pounds);
    printf("���ʼ����ã�%.2f\n", global_artichoke_cost);
    printf("��˷��ã�%.2f\n", beet_cost);
    printf("���ܲ����ã�%.2f\n", carrot_cost);
    printf("�ܷ��ã�%.2f\n", total_price);
    printf("�ۿۣ�%.2f\n", total_discount);
    if(total_cost)
        printf("������װж����������%.2f\n", total_cost);

    return 0;
}