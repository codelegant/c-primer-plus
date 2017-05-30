#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    double result;
    double base_number=atof(argv[1]);
    int index=atoi(argv[2]);
    if(index==0)
        result=1;
    else if((int)base_number==0)
        result=0;
    else
    {
        while(index)
        {
            result*=base_number;
            index--;
        }
    }
    printf("Result is %f\n", result);
    return 0;
}
