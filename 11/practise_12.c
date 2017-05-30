#include <stdio.h>
int main(int argc, char *agrv[])
{
    while(argc-->1)
        printf("%s ", agrv[argc]);
    printf("\n");
   return 0; 
}
