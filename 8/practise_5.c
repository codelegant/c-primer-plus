#include <stdio.h>

int main(void)
{
    int guess=50;
    short min=0;
    short max=100;
    char response;
    printf("Pick an integer form 1 to 100.I will try to guess ");
    printf("it.\n Respond with a y if my guess is right and with");
    printf("\nan g if it is great and with");
    printf("\nan l if it is less.\n");
    printf("Uh...is your number %d?\n", (min+max)/2);
    while((response = getchar()) != 'y')
    {
        if(response == 'g') 
        {
            min=(min+max)/2;
            printf("Well,then,it is %d?\n", (min+max)/2);
        }
        else if(response == 'l')
        {
            max=(min+max)/2;
            printf("Well,then,it is %d?\n", (min+max)/2);
        }
        else
            printf("Sorry,I understand only y,g or l.\n");
        while(getchar() != '\n')
            continue;
    }
    printf("I knew I could do it!\n");
    return 0;
}
