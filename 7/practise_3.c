#include <stdio.h>

int main(void)
{
    int number;
    int odd_sum = 0;
    int even_sum = 0;
    unsigned int odd_count = 0;
    unsigned int even_count = 0;

    printf("Enter number, end with 0.\n");
    while(scanf("%d", &number) && number)
    {
        if(number%2)
        {
            odd_count++;
            odd_sum+=number;
        }
        else
        {
            even_count++;
            even_sum+=number;
        }
    }

    printf("Total even count is %d, the average is %d\n", even_count, even_sum/even_count);
    printf("Total odd count is %d, the average is %d\n", odd_count, odd_sum/odd_count);
    return 0;
}