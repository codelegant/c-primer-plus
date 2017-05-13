#include <stdio.h>
int main(void)
{
    int * ptr;
    int torf[2][2]={{12},{14,16}};
    ptr=torf[0];
    printf("*ptr = %d\n",*ptr);
    printf("torf[0][0] = %d\n",torf[0][0]);
    printf("*(ptr+2) = %d\n",*(ptr+2));
    printf("torf[1][0] = %d\n",torf[1][0]);

    return 0;
}
