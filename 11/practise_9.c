#include <stdio.h>
#include <string.h>
#define SIZE 80
#define LIM 100
void remove_whitespace(char *);

int main(void)
{
    char input[LIM][SIZE];
    int ct=0;
    int index=0;

    printf("Enter up to %d lines: \n", LIM);
    while(ct<LIM && gets(input[ct])!=0 && input[ct][0]!='\0' && input[ct][0]!=EOF)
        ct++;
    printf("Input end\n");
    for(index=0; index<ct; index++)
    {
        remove_whitespace(input[index]);
        puts(input[index]);
    }
    return 0;
}

void remove_whitespace(char * ptr)
{
    char * find;
    while(find=strchr(ptr,32))
    {
        while(*find!='\0')
        {
            *find=*(find+1);
            find++;
        }
    }
}
