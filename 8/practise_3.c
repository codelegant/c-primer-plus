#include<stdio.h>
#include<ctype.h>

int main(void)
{
    short ch;
    int upper_count=0;
    int lower_count=0;

    while((ch=getchar()) != EOF)
    {
        isupper(ch) && upper_count++;
        islower(ch) && lower_count++;
    }
    printf("Upper is %d\n",upper_count);
    printf("Loser is %d",lower_count);
    return 0;
}
