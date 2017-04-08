#include <stdio.h>

int main(void)
{
    int ch;
    while((ch=getchar())!=EOF)
        putchar(ch);
    printf("\n");
    return 0;
}
