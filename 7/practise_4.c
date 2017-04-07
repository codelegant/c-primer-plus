#include <stdio.h>
#define EXCLAMATION_POINT '!'
#define PERIOD '.'
#define END '#'

int main(void)
{
    char ch;
    unsigned int period_replace_count = 0;
    unsigned int exclamation_point_replace_count = 0;
    printf("Enter anything your want,end with '#'\n");
    while((ch=getchar())!=END)
    {
        if(ch==PERIOD)
        {
            period_replace_count++;
        }
        else if(ch==EXCLAMATION_POINT)
        {
            exclamation_point_replace_count++;
        }
    }

    printf("Perion replace count is %d\n", period_replace_count);
    printf("Exclamation poing replace count is %d\n", exclamation_point_replace_count);
    return 0;
}