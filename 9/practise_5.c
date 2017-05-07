#include <stdio.h>

void larger_of(double *, double *);
int main(void)
{
    double x=3, y=5;
    larger_of(&x, &y);
    printf("x: %f, y: %lf",x, y);
    return 0;
}

void larger_of(double * x,double * y)
{
    if(*x<*y)
        *x=*y;
    else
        *y=*x;
}
