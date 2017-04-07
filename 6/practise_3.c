#include <stdio.h>

int main(void)
{
  short i;
  short k;
  for(i=0; i<6; i++){
    for(k='F'; k>='F'-i; k--)
      printf("%c",k);
    printf("\n");
  }
  return 0;
}