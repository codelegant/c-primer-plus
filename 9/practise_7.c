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
    double pow = 1;
    int index;
    if(exponent<0)
    {
        for(index=0;index<exponent*-1;index++)
            pow*=base;
        if(base!=0)
            pow=1/pow;
    }
    else if(exponent>0)
    {
        for(index=0;index<exponent;index++)
            pow*=base;
    }
    else
        pow=1;
    return pow;
}
