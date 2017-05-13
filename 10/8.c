#include <stdio.h>

int main(void)
{
    int (*ptr)[2];
    int torf[2][2]={12,14,16};
    ptr=torf;
    printf("**ptr = %d",**ptr);
    printf("**(ptr+1) = %d",**(ptr+1));
    return 0;
}
