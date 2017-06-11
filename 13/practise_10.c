#include <stdio.h>
#include <stdlib.h>
#define NAME_SIZE 128

int main(void)
{
    long pos = 0;
    char filename[NAME_SIZE];
    FILE *fp;
    char ch;
    int last_pos;
    printf("Enter the file name: ");
    scanf("%s", filename);
    if(!(fp = fopen(filename, "r")))
    {
        fprintf(stderr, "Failed to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    printf("Enter a position of the file: ");
    while(scanf("%ld", &pos) == 1)
    {
        fseek(fp, 0L, SEEK_END);
        last_pos = ftell(fp);
        if(pos > last_pos)
        {
            printf("Enter a position of the file: ");
            continue;
        }
        for(long count = pos; count < last_pos; count++)
        {
            fseek(fp, count, SEEK_SET);
            if((ch = getc(fp)) == '\n')
                break;
            putchar(ch);
        }
        putchar('\n');
        printf("Enter a position of the file: ");
    }
    printf("Your leave the program\n");
    return 0;
}
