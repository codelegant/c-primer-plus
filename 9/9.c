#include <stdio.h>

int maximum (int,int,int);

int main(void)
{
    printf("%d",maximum(1,2,3));
    return 0;
}

int maximum(int a,int b,int c)
{
    int max=0;
    if(max<a)
        max=a;
    if(max<b)
        max=b;
    if(max<c)
        max=c;
    return max;
}
