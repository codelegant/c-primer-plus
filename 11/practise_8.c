#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 20
void remove_enter(char *);
char * reverse_str(const char *);
int main(void)
{
    char target[SIZE];

    printf("Enter target string: ");
    fgets(target, SIZE, stdin);
    remove_enter(target);
    char * ptr=reverse_str(target);
    puts(ptr);
    return 0;
}


void remove_enter(char * ptr)
{
    char * find=strchr(ptr, '\n');
    if(find)
        *find='\0';
}

char * reverse_str(const char * str)
{
    int length=strlen(str);
    char arr[length+1];
    arr[length]='\0';
    char * ptr;
    int index=0;
    while(str[index]!='\0')
    {
        arr[length-1-index] =str[index];
        index++;
    }
    ptr=arr;
    return ptr;
}
