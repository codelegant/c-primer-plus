#include <stdio.h>
#include <ctype.h>
#define SIZE 80
void get_string (char *, int);

int main(void)
{
    char * ptr;
    get_string(ptr,SIZE);
    fputs(ptr,stdout);
    return 0;
}

void get_string(char * ptr, int size)
{
    printf("Please enter word, no more than %d\n",SIZE);
    int ch;
    int index=0;
    while((ch=getchar())!=EOF && ch!='\n' && !isblank(ch) && index<size)
    {
        *ptr++=ch;
        index++;
    }
        
}
