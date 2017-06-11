#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 512
#define NAME_SIZE 81

int main(void)
{
    FILE *source_ptr;
    FILE *target_ptr;
    char source_name[NAME_SIZE];
    char target_name[NAME_SIZE];
    size_t bytes;
    char temp[BUFFER_SIZE];

    puts("Enter the source file name: ");
    scanf("%s", source_name);
    puts("Enter the target file name: ");
    scanf("%s", target_name);

    if(!(source_ptr = fopen(source_name, "r")))
    {
        fprintf(stderr, "Can't open source file: %s\n", source_name);
        exit(EXIT_FAILURE);
    }

    if(!(target_ptr = fopen(target_name, "w")))
    {
        fprintf(stderr, "Can't open target file: %s\n", target_name);
        exit(EXIT_FAILURE);
    }

    //为原始文件建立缓冲区
    if(setvbuf(source_ptr, NULL, _IOFBF, BUFFER_SIZE))
    {
        fputs("Can't create input buffer\n", stderr);
        exit(EXIT_FAILURE);
    }

    while((bytes = fread(temp, sizeof(char), BUFFER_SIZE, source_ptr)) > 0)
        fwrite(temp, sizeof(char), bytes, target_ptr);

    if(ferror(source_ptr))
        fprintf(stderr, "Error in reading file: %s.\n", source_name);

    if(ferror(target_ptr))
        fprintf(stderr, "Error int writing file: %s.\n", target_name);

    printf("%s copy to %s.\n", source_name, target_name);

    if(fclose(source_ptr))
    {
        fprintf(stderr, "Error closing file %s\n", source_name);
        exit(EXIT_FAILURE);
    }
    if(fclose(target_ptr))
    {
        fprintf(stderr, "Error closing file %s\n", target_name);
        exit(EXIT_FAILURE);
    }
    return 0;
}
