#include <stdio.h>
#include <ctype.h>
#define SIZE 80
void get_string (char [], int);

int main(void)
{
    char arr[SIZE];
    get_string(arr,SIZE);
    fputs(arr,stdout);
    return 0;
}

void get_string(char arr[], int size)
{
    printf("Please enter word, no more than %d\n",SIZE);
    int ch;
    int index=0;
    while((ch=getchar())!=EOF && ch!='\n' && !isblank(ch) && index<size)
    {
        arr[index]=ch;
        index++;
    }
        
}
