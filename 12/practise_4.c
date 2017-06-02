#include <stdio.h>
void count_invok(void);

int main(void)
{
    int total=10;
    while(total--)
        count_invok();
    return 0;
}

void count_invok(void)
{
    static int count;
    printf("This fucntion is invoked %d times.\n", ++count);
}
