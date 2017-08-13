#include <stdio.h>

int min(int,int);
int main(void)
{
    printf("The minimum number is %d", (* min)(1,2));
    return 0;
}

int min(int a,int b)
{
    return a<b ? a : b;
}
