#include<stdio.h>

void show_name(char);
int main(void)
{
    show_name('m');
    return 0;
}

void show_name(char n)
{
    putchar(n);
}
