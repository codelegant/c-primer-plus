#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 20
char * my_strncpy(char *, char *, int);

int main(void)
{
    char target[SIZE];
    char source[SIZE];
    char * string;
    printf("Enter source string.\n");
    fgets(source, SIZE, stdin);
    printf("strlen of source is %lu\n", strlen(source));
    printf("Source string is %s", source);
    string =my_strncpy(target, source, SIZE-1);
    fputs(string,stdout);
    return 0;
}

char * my_strncpy(char * target, char * source, int size)
{
    int index=0;
    while(index<=size && source[index]!='\0') 
    {
        target[index] = source[index];
        index++;
    }
    target[index+1]='\0';
    return target;
}
