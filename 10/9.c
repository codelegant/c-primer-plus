#include <stdio.h>

int main(void)
{
    float rootbeer[10],things[10][5],*pf,value=2.2;
    int i=3;
    float * p=rootbeer;
    float (* pp)[10]=&rootbeer;
    printf("rootbeer = %p\n",p);
    printf("&rootbeer = %p\n",pp);
    return 0;
}
