#include <stdio.h>
#define SIZE 3
void add_arr(int * arr_1, int * arr_2, int * arr_3, int length);

int main(void)
{
    int arr_1[SIZE]={1,2,3};
    int arr_2[SIZE]={1,2,3};
    int arr_3[SIZE];
    add_arr(arr_1, arr_2, arr_3, SIZE);
    printf("arr_3[0] = %d\n", arr_3[0]);
    return 0;
}

void add_arr(int * arr_1, int * arr_2, int * arr_3, int length)
{
    int index;
    for(index=0; index<length; index++)
        arr_3[index]=arr_1[index]+arr_2[index];
}
