#include <stdio.h>

double power(double, int);
int main(void)
{
    double base;
    int exponent;
    printf("Enter the base and exponent: ");
    scanf("%lf %d",&base, &exponent);
    printf("Power is:%.2lf\n",power(base,exponent));
    return 0;
}

double power(double base, int exponent)
{
    double pow;
    if(exponent<0)
    {
        if(base==0)
            pow=0;
        else
            pow=1/base*power(base,exponent+1); 
    }
    else if(exponent>0)
    {
        pow=base*power(base,exponent-1);
    }
    else
        pow=1;
    return pow;
}
