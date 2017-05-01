#include<stdio.h>

int imax();
int main(void)
{
    printf("The maxinum of %d and %d is %d.\n",3,5,imax(3));
    printf("Them maxinum of %d and %d is %d.\n",3,5,imax(3.0,5.0));
    return 0;
}

int imax(int n,int m)
{
    int max;
    if(n>m)
        max=m;
    else
        max=m;
    return max;
}
