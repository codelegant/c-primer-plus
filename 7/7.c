#include <stdio.h>

int main(void)
{
    int age = 20;
    while (age++ <= 65)
    {
        if(0 == (age % 20))
            printf("You are %d. Here is a raise.\n", age);
        if(65 == age)
            printf("You are %d. Here is your gold watch.\n", age);
    }
    return 0;
}