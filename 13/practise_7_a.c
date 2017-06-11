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
    char *fgets_result1 = fgets(temp1, BUFFER_SIZE, fp1);
    char *fgets_result2 = fgets(temp2, BUFFER_SIZE, fp2);

    while(fgets_result1 || fgets_result2)
    {
        if(fgets_result1)
            fputs(fgets_result1, stdout);
        if(fgets_result2)
            fputs(fgets_result2, stdout);

        fgets_result1 = fgets(temp1, BUFFER_SIZE, fp1);
        fgets_result2 = fgets(temp2, BUFFER_SIZE, fp2);
    }
}
