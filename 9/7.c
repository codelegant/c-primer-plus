#include <stdio.h>

int plus(int,int);

int main(void)
{
    int a,b;
    printf("Enter two integer number.\n");
    scanf("%d %d",&a,&b);
    printf("%d",plus(a,b));
    return 0;
}

int plus(int a,int b)
{
    return a+b;
}
