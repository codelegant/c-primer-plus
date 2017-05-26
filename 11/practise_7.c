#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 20
char * my_strchr(char *, char);
void remove_enter(char *);
char * string_in(char *, char *);

int main(void)
{
    char target[SIZE];
    char source[SIZE];
    char * find_enter;

    printf("Enter target string: ");
    fgets(target, SIZE, stdin);
    remove_enter(target);

    printf("Enter source string: ");
    fgets(source, SIZE, stdin);
    remove_enter(source);
    
    char * string = string_in(target, source);
    if(string)
    {
        printf("This match address is: %p\n", string);
        printf("This match string is: %s\n", string);
    }
    else
    {
        printf("Sorry, there is no match string.\n");
    }
    return 0;
}

char * my_strchr(char * target, char ch)
{
    char * match_ptr=NULL;
    while(*target!='\0')
    {
        if(*target==ch)
        {
            match_ptr=target;
            break;
        }
        target++;
    }
    return match_ptr;
}

void remove_enter(char * ptr)
{
    char * find=strchr(ptr, '\n');
    if(find)
        *find='\0';
}

char * string_in(char * target, char * source)
{
    int length=strlen(source);
    int _length=length;
    char * arr[length];
    int index=0;
    bool is_in=true;

    while(length--)
        arr[length]=NULL;

    while(*source!='\0')
    {
        char * _source=my_strchr(target, *source);
        if(_source)
            arr[index]=_source;
        index++;
        source++;
    }

    index=1;
    length=_length;
    printf("length = %d\n", length);
    while(index<length)
    {
        is_in&=arr[index]-arr[index-1]==sizeof(char);
        index++;
    }
    return is_in ? arr[0] : NULL;
}
