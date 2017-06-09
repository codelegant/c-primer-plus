/* count.c -- using standard I/O */
#include <stdio.h>
#define BUF 256

#include <stdlib.h> // ANSI C exit() prototype
int main(void)
{
    int ch;         // place to store each character as read
    FILE *fp;       // "file pointer" 
    char file_name[BUF];
    long count = 0;

    printf("Enter filenam: ");
    scanf("%s", file_name);
    if ((fp = fopen(file_name, "r")) == NULL)
    {
        printf("Can't open %s\n", file_name);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) != EOF)
    {
       putc(ch, stderr);  // same as putchar(ch);
       count++;
    }
    fclose(fp);
    printf("File %s has %ld characters\n", file_name, count);
    
    return 0;
}
