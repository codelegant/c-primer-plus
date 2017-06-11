#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 512
void count_char_in_file(char *, FILE *, char);

int main(int argc, char *argv[])
{
    FILE *fp;
    if(argc < 2)
    {
        fprintf(stderr, "At least one argument.\n");
        exit(EXIT_FAILURE);
    }

    if(argc > 2)
    {
        while(--argc > 1) 
        {
            if(!(fp = fopen(argv[argc], "r"))) 
            {
                fprintf(stderr, "Can't open file %s.\n", argv[argc]);
                printf("Go to next.\n");
                continue;
            }

            count_char_in_file(argv[argc], fp, argv[1][0]);

            if(fclose(fp))
                fprintf(stderr, "Error closing file %s\n", argv[argc]);
        }
    }
    else
    {
        count_char_in_file("stdin", stdin, argv[1][0]);
    }
    return 0;
}


void count_char_in_file(char *file, FILE *fp, char ch)
{
    char temp[BUFFER_SIZE];
    char *ptr;
    int count = 0;
    while((ptr = fgets(temp, BUFFER_SIZE, fp)) && *ptr != '\n')
    {
        while(*ptr) 
        {
            *ptr == ch && count++;
            ptr++;
        }
    }
    printf("%s has %d %c\n", file, count, ch);
}
