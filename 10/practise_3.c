#include <stdio.h>
#define SIZE 5
int maximum_num(int * arr, int length);

int main(void)
{
    int arr[SIZE]={1,2,3,4,5};
    int maxmum=maximum_num(arr,SIZE);
    printf("maxmum = %d\n", maximum_num(arr,SIZE));
    return 0;
}

int maximum_num(int * arr, int length)
{
    int maximum=0;
    int index;
    for(index=0; index<length; index++)
    {
        if(arr[index]>maximum)
            maximum=arr[index];
    }
    return maximum;
}
