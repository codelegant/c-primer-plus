#include <stdio.h>

short get_int(void);
int main(void)
{
    short input=get_int(); 
    printf("%hd",input);
    return 0;
}

short get_int(void)
{
    short input;
    char ch;

    while(scanf("%hd",&input) != 1)
    {
        while((ch=getchar()) != '\n')
            putchar(ch);
        printf(" is not an interger.\nPlease enter an "
                "integer value, such as 25, -178, or 3: ");
    }
    return input;
}
