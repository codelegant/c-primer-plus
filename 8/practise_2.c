#include<stdio.h>
#include<ctype.h>

int main(void)
{
    short index = 0;
    short ch;
    while((ch=getchar()) != EOF && ++index)
    {
        if(ch == 9)
            printf(" %hd \\t",ch);
        else if(ch == 10) 
            printf(" %hd \\n",ch);
        else if(ch <= 31)
            printf(" %hd ^ %c",ch, ch+64);
        else
            printf(" %hd %c",ch,ch);
        if(index%10 == 0) 
            printf("\n");
    }
    return 0;
}
