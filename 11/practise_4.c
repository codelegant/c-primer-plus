#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 20
char * first_fit(char *, char);

int main(void)
{
    char arr[SIZE];
    char * ptr;
    char ch;
    printf("Enter a string.\n");
    ptr=fgets(arr, SIZE, stdin);
    printf("Enter a character.\n");
    scanf("%c",&ch);
    char * position=first_fit(ptr,ch);
    printf("%c\n",*position);
    return 0;
}

char * first_fit(char * ptr, char ch)
{
    char * index="\0";
    while(*ptr)
    {
        if(*ptr==ch)
            index=ptr;
        ptr++;
    }
    return index;
}
