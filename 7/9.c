#include <stdio.h>

int main(void)
{
  char ch;

  while('#'!=(ch=getchar()))
    {
        if('\n'!=ch){
            printf("Step 1\n");
            if('c'!=ch)
            {
                if('b'==ch)
                    break;
                else if('g'!=ch)
                    printf("Step 2\n");    
                printf("Step 3\n");
            }
        }
    }
  printf("Done\n");
  return 0;
}