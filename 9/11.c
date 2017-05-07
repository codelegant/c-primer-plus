#include <stdio.h>

int filter_num(int,int);
int main(void)
{
    int num=filter_num(0,5);
    printf("Your choice is %d",num);
    return 0;
}

int filter_num(int lower_limit,int upper_limit)
{
    int num,status;
    printf("Please enter a number between %d and %d\n",lower_limit,upper_limit);
    while((status=scanf("%d",&num)) != 1 || (num<lower_limit || num>upper_limit))
    {
        if(status != 1)
            scanf("%*s");//路过字符串的输入
        printf("Please enter a number between %d and %d\n",lower_limit,upper_limit);
    }

    return num;
}
