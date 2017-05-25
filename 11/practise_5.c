#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define SIZE 20
bool is_within(char *, char);

int main(void)
{
    char arr[SIZE];
    char * ptr;
    char ch;
    printf("Enter a string.\n");
    ptr=fgets(arr, SIZE, stdin);
    printf("Enter a character.\n");
    scanf("%c",&ch);
    bool result=is_within(ptr,ch);
    printf("%d\n", result);
    return 0;
}

bool is_within(char * ptr, char ch)
{
    bool within=false;
    while(*ptr)
    {
        if(*ptr==ch)
            within=true;
        ptr++;
    }
    return within;
}
