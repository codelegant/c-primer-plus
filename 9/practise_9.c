#include <stdio.h>
void to_base_n (unsigned long, short);

int main(void)
{
    unsigned long number;
    short base;
    printf("Enter an integer and a base (q to quit): \n");
    while(scanf("%lu %hd",&number, &base)==2)
    {
        printf("The appropriate base-%hd value is: ",base);
        to_base_n(number,base);
        putchar('\n');
        printf("Enter an integer and a base (q to quit): \n");
    }
    printf("Done.\n");
    return 0;
}

void to_base_n(unsigned long n, short base)
{
    short r;
    r=(short)n%base;
    if(n>=base)
        to_base_n(n/base,base);
    printf("%hd",r);
    return;
}
