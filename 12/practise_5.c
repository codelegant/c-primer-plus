#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
int get_rand(int);
void sort(int [], int);

void main(void)
{
    int arr[SIZE];
    int index=0;
    while(index<SIZE)
    {
        arr[index]=get_rand(index);
        index++;
    }
    sort(arr, SIZE);

    index=0;
    while(index<SIZE)
    {
        printf("arr[%d] = %d\n", index, arr[index]);
        index++;
    }
}

int get_rand(int index)
{
    unsigned int seed=(unsigned int) time(NULL) +(unsigned int) index;
    srand(seed);
    return rand()%SIZE+1;
}

void sort(int arr[], int length)
{
    int temp, top, seek;
    for(top=0; top<length-1; top++)
        for(seek=top+1; seek<length; seek++)
            if(arr[top] < arr[seek])
            {
                temp=arr[top];
                arr[top]=arr[seek];
                arr[seek]=temp;
            }
}
