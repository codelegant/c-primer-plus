
/* addaword.c -- uses fprintf(), fscanf(), and rewind() */
#include <stdio.h>
#include <stdlib.h>
#define MAX 40

int main(void)
{
    FILE *fp;
    int count;
    char words[MAX];

    if (!(fp = fopen("words", "a+")))
    {
        fprintf(stdout,"Can't open \"words\" file.\n");
        exit(1);
    }

    while (fgets(words, MAX, fp))
    {
        if(words[0] == '\n')
            continue;
        count++;
    }
    printf("The number of word is %d\n", count);
    puts("Enter words to add to the file; press the Enter");
    puts("key at the beginning of a line to terminate.");
    while (fgets(words, MAX, stdin) && words[0] != '\n')
    {
        if(words[0] == '\n')
            continue;
        fprintf(fp, "%d -> %s", ++count, words);
    }

    puts("File contents:");
    rewind(fp);           /* go back to beginning of file */
    while (fgets(words, MAX, fp))
        fputs(words, stdout);

    if (fclose(fp))
        fprintf(stderr,"Error closing file\n");

    return 0;
}

