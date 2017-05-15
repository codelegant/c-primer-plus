#include <stdio.h>
#define SIZE 5
double max_minus_min(double * arr, int length);

int main(void)
{
    double arr[SIZE]={2,43,1,34,6};
    printf("minus = %.1f\n",max_minus_min(arr,SIZE));
    return 0;
}

double max_minus_min(double * arr, int length) 
{
    int index;
    int min=0;
    int max=0;
    for(index=0;index<length;index++)
    {
        if(arr[index]>max)
            max=arr[index];
        if(arr[index]<min)
            min=arr[index];
    }
    return max-min;
}
