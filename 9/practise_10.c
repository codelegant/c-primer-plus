#include <stdio.h>
unsigned long long Fibonacci(unsigned int);

int main(void)
{
    unsigned int upper_limit;
    printf("Enter upper limit: \n");
    scanf("%u",&upper_limit);
    printf("The Fibonacci result is %llu\n",Fibonacci(upper_limit));
    return 0;
}

unsigned long long Fibonacci(unsigned int n)
{
    unsigned long long res;
    unsigned long long res_1=1;
    unsigned long long res_2=1;
    unsigned int index=3;
    if(n<=2)
        res=1;
    else
    {
        for(;index<=n;index++)
        {
            res=res_1+res_2;
            res_1=res_2;
            res_2=res;
        }
    }
    return res;
}
