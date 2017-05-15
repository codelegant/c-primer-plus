#include <stdio.h>
#define SIZE 3
void double_arr(int * arr, int length);

int main(void)
{
    int arr[SIZE]={3,5,1};
    double_arr(arr, SIZE);
    printf("arr[1] = %d\n", arr[1]);
    return 0;
}

void double_arr(int * arr, int length)
{
    int index;
    for(index=0; index<length; index++)
        arr[index]*=arr[index];
}
