#include <stdio.h>
#define SPACE ' '
#define ENTER '\n'
#define END '#'

int main(void)
{
    unsigned int space_count = 0;
    unsigned int enter_count = 0;
    unsigned int other_count = 0;
    char ch;

    printf("Enter anything your want, end with '#'.\n");
    while((ch = getchar()) != END)
    {
        if(ch == SPACE)
            space_count++;
        else if(ch == ENTER)
            enter_count++;
        else
            other_count++;
    }
    printf("Total space %d.\n", space_count);
    printf("Total enter %d.\n", enter_count);
    printf("Other characters %d.\n", other_count);
    return 0;
}
