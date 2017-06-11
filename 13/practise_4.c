#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 512 
void print_file(FILE *);

int main(int argc, char *argv[])
{
    int index=0;
    FILE *fp;
    if(argc < 2) 
        fprintf(stderr, "Please enter at least one file\n");
    while(index < argc - 1)
    {
        if(!(fp = fopen(argv[index+1], "r")))
        {
            fprintf(stderr, "Can't open file: %s\n", argv[index+1]);
            exit(EXIT_FAILURE);
        }

        print_file(fp);

        if(fclose(fp))
            fprintf(stderr, "Error closing file %s\n", argv[index+1]);

        ++index;
    }
    return 0;
}

void print_file(FILE *file_name)
{
    char temp[BUFFER_SIZE];
    while(fgets(temp, BUFFER_SIZE, file_name))
        fputs(temp, stdout);
}
