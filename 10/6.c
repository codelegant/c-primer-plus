#include <stdio.h>

int main(void)
{
    int ref[]={8,4,0,2};
    int *ptr;
    ptr=ref;
    int index;
    printf("ref = %p\n",ref);
    printf("ref+1 = %p\n",ref+1);
    printf("ptr = %p\n",ptr);
    printf("++ptr = %p\n",++ptr);
    printf("++ref = %p\n",++ref);
    return 0;
}
