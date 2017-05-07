#include <stdio.h>

double harmmean (double, double);
int main(void)
{
    printf("Harmmean is %f\n", harmmean(2,4));
    return 0;
}

double harmmean(double a, double b)
{
    double inverse_avergae=(1/a+1/b)/2;
    return 1/inverse_avergae;
}
