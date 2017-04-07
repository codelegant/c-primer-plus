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
    printf("��ѡ�����˰�����࣬�����Ӧ�����ֱ��룺\n");
    printf("1) ����                        2������\n");
    printf("3) �ѻ飬����                  4���ѻ飬����\n");
    printf("5) �˳�\n");
    printf("********************************************\n");
    printf("���ѡ���ǣ�");
    
    while(scanf("%hd",&choose) && choose !=5){
        if(choose<1||choose>5){
            printf("������1-5֮������֣�\n");
            printf("���ѡ���ǣ�");
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
        printf("��������׼�ǣ�%.0f\n", pay_base);
        printf("���������Ӧ��˰���룺");
        scanf("%f",&pay);
        if(pay<=pay_base)
        {
            taxes = pay*RATE_1;
        }
        else{
            taxes = pay_base*RATE_1+(pay-pay_base)*RATE_2;
        }
        printf("Ӧ�ý��ɵ�˰���ǣ�%.2f\n", taxes);
    }
    printf("���˳��˳���\n");

    return 0;
}