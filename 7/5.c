#include <stdio.h>

int main(void)
{
    int weight, height;
    printf("Enter the weight and height: \n");
    scanf("%d %d", &weight, &height);

    if(weight<100)
        if(height>64 && height<72)
            printf("You are tall for your weight.\n");
        else if(height >= 72)
            printf("Your are very tall for your weight.\n");    
    else if(weight>300)
        if(height<48)
            printf("Your are quite short for your weight.\n");
    else
        printf("Your weight is ideal.\n");
    
    return 0;
}