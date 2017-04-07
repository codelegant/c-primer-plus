#include <stdio.h>

int main(void)
{
  printf("Type int has a size of %u bytes.\n",sizeof(int));
  printf("Type int has a size of %u bytes.\n",sizeof(char));
  printf("Type int has a size of %u bytes.\n",sizeof(long));
  printf("Type int has a size of %u bytes.\n",sizeof(double));
  return 0;
}