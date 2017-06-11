#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 512
void print_by_column(FILE *, FILE *);

int main(int argc, char *argv[])
{
    FILE *file1;
    FILE *file2;
    if(argc < 3)
    {
        fprintf(stderr, "At least two arguments.\n");
        exit(EXIT_FAILURE);
    }

    if(!(file1 = fopen(argv[1], "r")))
    {
        fprintf(stderr, "Failed to opent %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if(!(file2 = fopen(argv[2], "r")))
    {
        fprintf(stderr, "Failed to opent %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    print_by_column(file1,file2);

    if(fclose(file1))
        fprintf(stderr, "Error closing file %s\n", argv[1]);
    if(fclose(file2))
        fprintf(stderr, "Error closing file %s\n", argv[2]);
    return 0;
}

void print_by_column(FILE *fp1, FILE *fp2)
{
    char temp1[BUFFER_SIZE];
    char temp2[BUFFER_SIZE];
    int fgets_result1 = fscanf(fp1, "%s", temp1);
    int fgets_result2 = fscanf(fp2, "%s", temp2);

    while(fgets_result1 == 1 || fgets_result2 == 1)
    {
        if(fgets_result1 == 1)
            fputs(temp1, stdout);
        if(fgets_result2 == 1)
            puts(temp2);

    fgets_result1 = fscanf(fp1, "%s", temp1);
    fgets_result2 = fscanf(fp2, "%s", temp2);
    }
}
