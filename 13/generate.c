#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100
int get_rand(void);

void main(void)
{
    FILE *fp;

    if(!(fp = fopen("num_img.log", "w")))
    {
        fprintf(stderr, "Failed opening num_img.log\n");
        exit(EXIT_FAILURE);
    }
    srand((unsigned int)time(NULL));
    for(int column = 20; column; column--)
    {
        for(int row = 30; row; row--)
            fprintf(fp, "%d ", get_rand());
        fprintf(fp, "\n");
    }
}

int get_rand(void)
{
    return rand()%10;
}
