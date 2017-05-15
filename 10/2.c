#include <stdio.h>
#define SIZE 4

int main(void)
{
    short dates [SIZE];
    short * pti;
    short index;
    double bills[SIZE];
    double * ptf;
    pti=dates;
    ptf=bills;
    printf("The size of short is %lu bytes.\n",sizeof(short));
    printf("The size of double is %lu bytes.\n",sizeof(double));
    printf("%28s %10s\n","short","double");
    for(index=0;index<SIZE;index++)
    {
        printf("pointers + %d: %10p %10p\n", index, pti+index, ptf+index);
    }
    return 0;
}
