#include<stdio.h>
#include<ctype.h>

int main(void)
{
    short ch;
    short ch_sum=0;
    short ch_count=0;
    short word_count=0;

    while((ch=getchar()) != '\n')
    {
        if(isalpha(ch))
        {
            ch_sum+=ch;
            ch_count++;
        }
        else if(isspace(ch) && ch_sum && ch_count)
        {
            word_count++;
            printf("Avarge of word %hd is %hd\n",word_count,ch_sum/ch_count);
            ch_sum=0;
            ch_count=0;
        }

    }
    return 0;
}
