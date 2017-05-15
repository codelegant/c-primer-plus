#include <stdio.h>
#define ROWS 2
#define COLS 5 
void copy_arr(double * source, double * target, int length);
void copy_ptr(double * source, double * target, int length);

int main(void)
{
    double source[7]={1,2,3,4,5,6,7};
    double target[3];
    copy_arr(&source[2],target,3);
    printf("target[2] = %.0f\n", target[2]);
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
