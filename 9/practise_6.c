#include <stdio.h>

int is_letter(char);
int main(void)
{
    char ch;
    printf("Enter: \n");
    while((ch=getchar()) != EOF)
    {
        int letter_position;
        if((letter_position=is_letter(ch))!=-1)
            printf("Position of letter %c is: %d\n",ch,letter_position+1);
    }
    printf("Done!");
    return 0;
}

int is_letter(char ch)
{
    int position = -1;
    if(ch>=65 && ch<=90)
        position=ch%65;
    else if(ch>=97 && ch<=122)
        position=ch%97;
    return position;
}
