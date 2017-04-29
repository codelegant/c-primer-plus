#include <stdio.h>

int main(void)
{
    int count=0;
    int ch;
    while((ch=getchar())!=EOF && ch!='\n')
        count++;
    printf("%d\n",count);
    return 0;
}
