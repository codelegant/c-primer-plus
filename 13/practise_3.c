#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define BUFFER_SIZE 512
#define NAME_SIZE 81

int main(void)
{
    FILE *source_ptr;
    FILE *target_ptr;
    char source_name[NAME_SIZE];
    char target_name[NAME_SIZE];
    char temp[BUFFER_SIZE];
    char *ptr;

    puts("Enter the source file name: ");
    // 如果使用 fgets() 读取文件名
    // 会在文件名后面添加回车，导致文件读取失败
    scanf("%s", source_name);
    puts("Enter the target file name: ");
    scanf("%s", target_name);

    if(!(source_ptr = fopen(source_name, "r")))
    {
        fprintf(stderr, "Can't open file: %s\n", source_name);
        exit(EXIT_FAILURE);
    }

    if(!(target_ptr = fopen(target_name, "w")))
    {
        fprintf(stderr, "Can't open file: %s\n", target_name);
        exit(EXIT_FAILURE);
    }

    if(ferror(source_ptr))
        fprintf(stderr, "Error in reading file: %s.\n", source_name);

    if(ferror(target_ptr))
        fprintf(stderr, "Erro int writing file: %s.\n", target_name);

    while(ptr = fgets(temp, BUFFER_SIZE, source_ptr))
    {
        while(*ptr)
        {
            *ptr = toupper(*ptr);
            ptr++;
        }
        fputs(temp, target_ptr);
    }

    if(fclose(source_ptr))
        fprintf(stderr, "Error closing file %s\n", source_name);
    if(fclose(target_ptr))
        fprintf(stderr, "Error closing file %s\n", target_name);
    return 0;
}
