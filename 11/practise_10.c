#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 80
#define LIM 10
char get_first(void);
char choice_menu(void);
void print_source(char * []);
void print_by_ascii(char * []);
void print_by_length(char * []);
void print_by_first_word_length(char * []);

int main(void)
{
    char input[LIM][SIZE];
    int ct=0;
    int index=0;

    printf("Enter up to %d lines: \n", LIM);
    while(ct<LIM && gets(input[ct])!=0 && input[ct][0]!=EOF)
        ct++;
    printf("String input end.\n");

    for(index=0; index<ct; index++)
    {
        remove_whitespace(input[index]);
        puts(input[index]);
    }
    return 0;
}

char get_first(void)
{
    int ch;
    while((ch = getchar()) && !isalpha(ch))
        continue;

    while(getchar() != '\n')
        continue;

    return tolower(ch);
}

char choice_menu(void)
{
    int ch;
    printf("���������ѡ��");
    printf("a. ���ԭʼ�ַ����б�            b. �� ASCII ˳������ַ���\n");
    printf("c. �����ȵ���˳������ַ���      d. ���ַ����е�һ�����ʵĳ�������ַ���\n");
    printf("q. �˳�\n");

}
