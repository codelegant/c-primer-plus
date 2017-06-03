#include <stdio.h>
#include <stdlib.h>
int * make_array(int ele, int val);
void show_array(const int arr[], int n);

int main(void)
{
    int * pa;
    int size;
    int value;
    
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    while(size > 0)
    {
        printf("Enter the initialization value: ");
        scanf("%d", &value);
        pa = make_array(size, value);
        if (pa)
        {
            show_array(pa, size);
            free(pa);
        }
        printf("Enter the number of elements (<1 to quit): ");
        scanf("%d", &size);
    }
    printf("Done.\n");
    return 0;
}

int * make_array(int ele, int val)
{
    int * ptr;
    int index=0;
    ptr = (int *)malloc(ele * sizeof(int));
    while(index < ele)
        ptr[index++] = val;
    return ptr;
}

void show_array(const int arr[], int n)
{
   int index=0; 
   while(index < n)
   {
       printf("%4d", arr[index]);
       if(index % 8 == 7)
           printf("\n");
       index++;
   }
   printf("\n");
}
