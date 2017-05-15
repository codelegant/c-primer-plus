#include <stdio.h>
#define SIZE 5
int maximum_index(int * arr, int length);

int main(void)
{
    int arr[SIZE]={100,20,3,4,5};
    int maxmum=maximum_index(arr,SIZE);
    printf("maxmum_index = %d\n", maximum_index(arr,SIZE));
    return 0;
}

int maximum_index(int * arr, int length)
{
    int maximum_index=0;
    int maximum_num=0;
    int index;
    for(index=0; index<length; index++)
    {
        if(arr[index]>maximum_num)
        {
            maximum_num=arr[index];
            maximum_index=index;
        }
    }
    return maximum_index;
}
