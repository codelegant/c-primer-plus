#include <stdio.h>
#define END '#'

int main(void)
{
  char ch;
  unsigned int index = 0;

  printf("Enter anything your want, end with '#'.\n");
  while((ch=getchar())!=END)
  {
    printf("%c/%d   ", ch,ch);
    
    if(index++%8==0)
      printf("\n");
  }
  return 0;
}