#include <stdio.h>

void alter(int *,int *);

int main(void)
{
    int x=5,y=3;
    alter(&x,&y);
    printf("%d,%d",x,y);
    return 0;
}

void alter(int * x,int * y)
{
    int temp_x=* x,temp_y=* y;
    * x=temp_x-temp_y;
    * y=temp_x+temp_y;
}
