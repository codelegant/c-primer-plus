#include <stdio.h>
#define ROWS 2
#define COLS 5 
void copy_arr(double * source, double * target, int length);
void copy_ptr(double * source, double * target, int length);
void copy_2d_arr(int rows, int cols, double source[rows][cols], double target[rows][cols]);

int main(void)
{
    double arr_2[ROWS][COLS]={0,1,2,3,4,5,6,7,8,9};
    double targ_arr_2[ROWS][COLS];
    copy_2d_arr(ROWS, COLS, arr_2,targ_arr_2);
    printf("targ_arr_2[1][4] = %.1f\n", targ_arr_2[1][4]);
    return 0; 
}

void copy_arr(double * source, double * target, int length)
{
    int index;
    for(index=0; index<length; index++)
        target[index]=source[index];
}

void copy_ptr(double * source, double * target, int length)
{
    int index;
    for(index=0; index<length; index++)
        *(target+index)=*(source+index);
}

void copy_2d_arr(int rows, int cols, double arr[rows][cols], double targ[rows][cols])
{
    int r;
    for(r=0; r<rows; r++)
        copy_arr(arr[r], targ[r], cols);
}
