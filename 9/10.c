#include <stdio.h>

int show_menu(int,int);
int main(void)
{
    int choice=show_menu(1,4);
    printf("Your choice is %d",choice);
    return 0;
}

int show_menu(int lower_limit,int upper_limit)
{
    int choice,status;
    printf("Please choose one of the following:\n");
    printf("1) copy files          2) move files\n");
    printf("3) remove files        4) quit\n");
    printf("Enter the number of your choice:\n");
    while((status=scanf("%d",&choice)) != 1 || (choice<lower_limit || choice>upper_limit))
    {
        if(status != 1)
            scanf("%*s");//路过字符串的输入
        printf("Please enter a number between %d and %d\n",lower_limit,upper_limit);
        printf("Enter the number of your choice:\n");
    }
    return choice;
}
