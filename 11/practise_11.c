#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LIM 10
#define SIZE 80
int main(void)
{
    char input[LIM][SIZE];
    int ct=0;
    int whitespace_ct=0;
    int word_ct=0;
    int uppercase_ct=0;
    int lowercase_ct=0;
    int punct_ct=0;
    int digit_ct=0;

    printf("Enter up to %d lines: \n", LIM);
    while(ct<LIM && fgets(input[ct], SIZE, stdin)!=NULL && input[ct][0]!=EOF)
        ct++;
    while(ct--)
    {
        int length=strlen(input[ct]);
        int index=0;
        while(index<length)
        {
            char ch=input[ct][index];
            isdigit(ch) && digit_ct++;
            isupper(ch) && uppercase_ct++;
            islower(ch) && lowercase_ct++;
            ispunct(ch) && punct_ct++;
            if((ch==32 || ispunct(ch)) && index>0 && index<length-1 && !isspace(input[ct][index-1]) && !isspace(input[ct][index+1])) 
                whitespace_ct++; 
            index++;
        }
    }
    word_ct=whitespace_ct+1;
    printf("Word count: %d\n", word_ct);
    printf("Uppercase count: %d\n", uppercase_ct);
    printf("Lowercase count: %d\n", lowercase_ct);
    printf("Punt count: %d\n", punct_ct);
    printf("Digit count: %d\n", digit_ct);
    return 0;
}
