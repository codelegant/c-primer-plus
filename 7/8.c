#include <stdio.h>

int main(void)
{
  char ch;

  while('#'!=(ch=getchar()))
  {
    if('\n'==ch)
      continue;
    printf("Step 1\n");
    if('c'==ch)
      continue;
    else if('b'==ch)
      break;
    else if('g'==ch)
      goto laststep;
    printf("Step 2\n");
    laststep:printf("Step 3\n");
  }
  printf("Done\n");
  return 0;
}