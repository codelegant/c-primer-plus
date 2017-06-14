#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#define COLUMN 20
#define ROW 30
void erase_spike_pulse(int, int, unsigned short [*][*]);

void main(unsigned short argc, char *argv[])
{
    unsigned short nums[COLUMN][ROW];
    char symbol[] = {' ', '.', '"', '-', '+', '*', '&', '%', '$', '#'};
    char chs[COLUMN][ROW+1];
    FILE *source_fp;
    FILE *target_fp;

    if(argc < 2)
    {
        fprintf(stderr, "At least one arguments.\n");
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
                    //printf("%d ", nums[column][row]);
                    been_assign = true;
                }
        }
        //putchar('\n');
    }

    //erase_spike_pulse(COLUMN, ROW, nums);

    for(unsigned short column = 0; column < COLUMN; column++)
    {
        for(unsigned short row = 0; row < ROW; row++)
        {
            chs[column][row] = symbol[nums[column][row]];
            //printf("%d ", nums[column][row]);
        }
        //putchar('\n');
        chs[column][30] = '\0';
        puts(chs[column]);
        fprintf(target_fp, "%s\n", chs[column]);
    }

    if(fclose(source_fp))
        fprintf(stderr, "Failed to close %s\n", argv[1]);
    if(fclose(target_fp))
        fprintf(stderr, "Failed to close img.log\n");
}

void erase_spike_pulse(int cols, int rows, unsigned short arr[cols][rows])
{
    for(int c = 0; c < cols; c++)
        for(int r = 0; r < rows; r++) 
        {
            bool top = false;
            bool right = false;
            bool bottom = false;
            bool left = false;
            int top_element = 0;
            int right_element = 0;
            int left_element = 0;
            int bottom_element = 0;
            int element_count = 0;
            int current_element = arr[c][r];

            if(r != 0)
            {
                left_element = arr[c][r - 1]; 
                left = (int)fabs(current_element - left_element) > 1;
                element_count++;
            }
            if(r != 29)
            {
                right_element = arr[c][r + 1];
                right = (int)fabs(current_element - right_element) > 1;
                element_count++;
            }
            if(c != 0)
            {
                top_element = arr[c - 1][r];
                top = (int)fabs(current_element - top_element) > 1;
                element_count++;
            }
            if(c != 19)
            {
                bottom_element = arr[c + 1][r];
                bottom = (int)fabs(current_element - bottom_element) > 1;
                element_count++;
            }

            if((int)top + (int)right + (int)bottom + (int)left == element_count)
            {
                int total = top_element + right_element + bottom_element + left_element;
                arr[c][r] = (int)(total / element_count);
            }
        }
}
