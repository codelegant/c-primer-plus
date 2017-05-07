#include <stdio.h>

void chline(char,int,int);
int main(void)
{
    chline('a',3,5);
    return 0;
}

void chline(char ch,int start,int end)
{
    int count=1;
    while(count<start)
    {
        printf("|");
        count++;
    }
    while (count<=end)
    {
        printf("%c",ch);
        count++;
    }
}
