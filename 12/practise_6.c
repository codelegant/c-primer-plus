#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000
#define SEED_SIZE 10
void count(int [], int);
static int count_arr[10];

int main(void)
{
    int seed[]={24, 52, 34, 23, 235, 235, 47647, 234, 346, 23};
    int arr[SIZE];
    int index_1=0;
    int index_2=0;
    while(index_1<SEED_SIZE)
    {
        srand((unsigned int)(time(NULL)+seed[index_1]));
        while(index_2<SIZE)
            arr[index_2++]=rand()%SEED_SIZE;
        count(arr, SIZE);
        index_1++;
    }

    index_1=0;
    while(index_1<SEED_SIZE)
    {
        printf("The value %d counts is: %d.\n",index_1+1,count_arr[index_1]);
        index_1++;
    }
}

void count(int arr[], int length)
{
    int index=0;
    while(index<length)
        count_arr[arr[index++]]++;
}
