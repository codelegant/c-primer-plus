#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 80
#define LIM 10
char get_first(void);
void shallow_copy(char * [], char [][SIZE], int);
void sort_str(char * [], int);
char * get_first_word(char *);
char choice_menu(void);
void print_divided_line(char);
void print_source(char [][SIZE], int);
void print_by_ascii(char [][SIZE], int);
void print_by_length(char [][SIZE], int);
void print_by_first_word_length(char [][SIZE], int);

int main(void)
{
    char input[LIM][SIZE];
    int ct=0;
    int index=0;
    int choice;

    printf("Enter up to %d lines: \n", LIM);
    while(ct<LIM && fgets(input[ct], SIZE, stdin)!=NULL && input[ct][0]!=EOF)
        ct++;
    printf("Source string input end.\n");

    while((choice=choice_menu()) != 'q')
    {
        print_divided_line('*');
        switch(choice)
        {
            case 'a':print_source(input, ct);
                     break;
            case 'b':print_by_ascii(input, ct);
                     break;
            case 'c':print_by_length(input, ct);
                     break;
            case 'd':print_by_first_word_length(input, ct);
                     break;
            default:printf("Program error!\n");
        }
        print_divided_line('*');
    }
    printf("Bye.\n");
    return 0;
}

char get_first(void)
{
    char ch;
    while(((ch = getchar()) && !isalpha(ch)) || getchar() != '\n')
        continue;

    return tolower(ch);
}

void shallow_copy(char * source[], char target[][SIZE], int ct)
{
    int index=0; 
    while(index<ct)
    {
        source[index]=target[index];
        index++;
    }
}

char * get_first_word(char * str)
{
    char * find=strchr(str, 32);
    if(find)
        *find='\0';
    return str;
}

char choice_menu(void)
{
    char ch;
    print_divided_line('-');
    printf("Enter the letter of your choic:\n");
    printf("a. Print the source string                     b. Print the string order by ASCII\n");
    printf("c. Print the string order by string length     d. Print the string order by the first word's length of string\n");
    printf("q. Quit\n");
    print_divided_line('-'); 
    printf("Your choice is: ");
    ch=get_first();
    while((ch<'a' || ch>'d') && ch!='q')
    {
        printf("Please respond with a, b, c, d or q.\n");
        ch=get_first();
    }
    return ch;
}

void print_divided_line(char ch)
{
    int size=SIZE;
    while(size--)
        putchar(ch);
    putchar('\n');
}

void print_source(char input[][SIZE], int ct)              
{
    int index;
    for(index=0; index<ct; index++)
        fputs(input[index], stdout);
}

void print_by_ascii(char input[][SIZE], int ct)
{
    char * cache[ct];
    char * temp;
    int top, seek;
    int index=0;
    shallow_copy(cache, input, ct);

    for(top=0; top<ct-1; top++)
        for(seek=top+1; seek<ct; seek++)
            if(strcmp(cache[top], cache[seek])>0)
            {
                temp=cache[top];
                cache[top]=cache[seek];
                cache[seek]=temp;
            }

    while(index<ct)
        fputs(cache[index++], stdout);
}

void print_by_length(char input[][SIZE], int ct)
{
    char * cache[ct];
    char * temp;
    int top, seek;
    int index=0;
    shallow_copy(cache, input, ct);

    for(top=0; top<ct-1; top++)
        for(seek=top+1; seek<ct; seek++)
            if((int)strlen(cache[top])-(int)strlen(cache[seek]) > 0)
            {
                temp=cache[top];
                cache[top]=cache[seek];
                cache[seek]=temp;
            }

    while(index<ct)
        fputs(cache[index++], stdout);
}

void print_by_first_word_length(char input[][SIZE], int ct)
{
    char * cache[ct];
    char * temp;
    int top, seek;
    int index=0;
    shallow_copy(cache, input, ct);

    for(top=0; top<ct-1; top++)
        for(seek=top+1; seek<ct; seek++)
            if((int)strlen(get_first_word(cache[top]))-(int)strlen(get_first_word(cache[seek])) > 0)
            {
                temp=cache[top];
                cache[top]=cache[seek];
                cache[seek]=temp;
            }
    while(index<ct)
        fputs(cache[index++], stdout);
}
