#include<stdio.h>

char get_choice(void);
int get_first(void);
float get_float(void);
int main(void)
{
    short choice;
    float first_num;
    float second_num;
    choice=get_choice();
    while(choice != 'q')    
    {
        printf("Enter first number: ");
        first_num=get_float();
        printf("Enter second number: ");
        second_num=get_float();

        switch(choice)
        {
            case 'a':
                printf("%f + %f = %f\n",first_num,second_num,first_num+second_num);
                break;
            case 's':
                printf("%f * %f = %f\n",first_num,second_num,first_num*second_num);
                break;
            case 'm':
                printf("%f - %f = %f\n",first_num,second_num,first_num*second_num);
                break;
            case 'd':
                if(second_num==0)
                {
                    printf("Enter a number other than 0: ");
                    while((second_num=get_float()) == 0)
                    {
                        printf("Enter a number other than 0: ");
                        continue;
                    }
                }
                printf("%f / %f = %f\n",first_num,second_num,first_num/second_num);
        }
        choice=get_choice();
    }
}

char get_choice(void)
{
    char choice;
    printf("Enter the operation of your choice:\n");
    printf("a. add                      s. subtract\n");
    printf("m. multiply                 d. divide\n");
    printf("q. quit\n");
    choice=get_first();

    while(choice =='a' && choice=='s' && choice=='m'&& choice!='d' && choice!='q')    
    {
        printf("The operation must be a, s, m or d.\n");
        printf("Enter the operation of your choice: ");
        choice=get_first();
        continue;
    }
    return choice;
}

int get_first(void)
{
    int ch;
    while((ch = getchar()) && (ch = tolower(ch)) && !islower(ch))
        continue;

    while(getchar() != '\n')
        continue;

    return ch;
}

float get_float(void)
{
    float input;
    char ch;
    while(scanf("%f",&input) != 1)
    {
        while((ch=getchar()) != '\n')
            putchar(ch);
        printf("is not a number.\n");
        printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
    }
    return input;
}
