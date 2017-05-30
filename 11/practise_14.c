#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define SIZE 80
int power(int, int);
int atoi(char *);
int main(void)
{
    char arr[SIZE];
    char *ptr;
    printf("Enter a string, no more than %d characters: ", SIZE);
    fgets(arr, SIZE, stdin);
    ptr=arr;
    printf("The result is %d\n", atoi(ptr));
    return 0;
}

int power(int base, int index)
{
    int result=1;
    if(index==0)
        result=1;
    else if(base==0)
        result=0;
    else
    {
        while(index--)
            result*=base;
    }
    return result;
}

int atoi(char *ptr)
{
    int num_arr[SIZE]={[0]=43};
    int index=1;
    int reverse_index;
    int result=0;
    bool in_num=false;
    while(*ptr!='\0' )
    {
        if(index>0 && in_num && num_arr[index-1]>0 && !isdigit(*ptr))
            break;
        if(*ptr==45 && isdigit(*(ptr+1)))
        {
            in_num=true;
            num_arr[0]=45;
        }
        else if(isdigit(*ptr))
        {
            in_num=true;
            num_arr[index]=*ptr;
            index++;
        }
        ptr++;
    }
    reverse_index=index-1;
    while(index-->1)
    {
        result+=(num_arr[index]-48)*power(10,reverse_index-index);
    }
    if(num_arr[0]==45)
        result*=-1;
    return result;
}
