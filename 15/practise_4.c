#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool IsTrueInSpecialIndex(int number, int index);


int main(int argc, char *argv[]) {
  int number = atoi(argv[1]);
  int index = atoi(argv[2]);
  bool result = IsTrueInSpecialIndex(number, index);
  printf("The result is %d\n", result);
  
  return 0;
}

/**
  * @param index {int} right to left, first position is 0
  */
bool IsTrueInSpecialIndex(int number, int index) {
  number >>= index;
  return (01 & number);
}
