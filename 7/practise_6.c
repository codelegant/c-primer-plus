#include <stdio.h>
#define END '#'

int main(void)
{
    char prev_ch = 0;
    char current_ch;
    unsigned int count = 0;
    printf("Enter anything your want, end with '#'.\n");
    while((current_ch=getchar())&&current_ch!=END)
    {
        if(prev_ch=='e'&&current_ch=='i')
            count++;
        prev_ch = current_ch;
    }

    printf("Count is %d.", count);
    return 0;
}