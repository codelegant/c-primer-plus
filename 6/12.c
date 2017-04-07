#include <stdio.h>

int main(void)
{
  const short SIZE = 8;
  int by_twos[SIZE];
  short index_1;
  short index_2;
  for(index_1 = 0; index_1<SIZE; index_1++)
    by_twos[index_1] = 2 * (index_1+1);

  for(index_2 = 0; index_2<SIZE; index_2++)
    printf("%d ", by_twos[index_2]);

  return 0;
}