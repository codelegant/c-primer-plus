#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define COLUMN 20
#define ROW 30

void main(unsigned short argc, char *argv[])
{
    unsigned short nums[COLUMN][ROW];
    char symbol[] = {' ', '.', '"', '-', '+', '*', '&', '%', '$', '#'};
    char chs[COLUMN][ROW+1];
    FILE *source_fp;
    FILE *target_fp;

    if(argc < 2)
    {
        fprintf(stderr, "At least two arguments.\n");
        exit(EXIT_FAILURE);
    }
    if(!(source_fp = fopen(argv[1], "r")))
    {
        fprintf(stderr, "Failed to open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if(!(target_fp = fopen("img.log", "w")))
    {
        fprintf(stderr, "Failed to open file img.log\n");
        exit(EXIT_FAILURE);
    }

    for(unsigned short column = 0; column < COLUMN; column++)
    {
        for(unsigned short row = 0; row < ROW; row++)
        {
            char ch;
            bool been_assign = false;
            while(!been_assign && (ch = getc(source_fp)) != EOF)
                if(isdigit(ch))
                {
                    nums[column][row] =(unsigned short)ch - 48 ;
                    been_assign = true;
                }
        }
    }

    for(unsigned short column = 0; column < COLUMN; column++)
    {
        for(unsigned short row = 0; row < ROW; row++)
            chs[column][row] = symbol[nums[column][row]];
        chs[column][30] = '\0';
        puts(chs[column]);
        fprintf(target_fp, "%s\n", chs[column]);
    }

    if(fclose(source_fp))
        fprintf(stderr, "Failed to close %s\n", argv[1]);
    if(fclose(target_fp))
        fprintf(stderr, "Failed to close img.log\n");
}
