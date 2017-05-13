#include <stdio.h>
#define SIZE 10
int sum (int arr[],int n);

int main(void)
{
    int marbles[SIZE]={23,45,2,4,6,73,46,7,4,4};
    long answer;
    answer=sum(marbles,SIZE);
    printf("The total number of marbles is %ld .\n",answer);
    printf("The size of marbles is %zd bytes.\n",sizeof marbles);
    return 0;
}

int sum(int arr[],int n)
{
    int i;
    int total=0;
    for(i=0;i<n;i++)
        total+=arr[i];
    printf("The size of arr is %zd bytes,\n",sizeof arr);
    return total;
}
