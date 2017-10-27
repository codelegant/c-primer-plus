#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int count = 0;
  static int size = 8 * sizeof(int);
  int number = atoi(argv[1]);
  
  for (int i = size - 1; i >= 0; --i, number >>= 1) 
    (01 & number) && ++count;
  printf("Count is %d\n", count);
  
  return 0;
}
