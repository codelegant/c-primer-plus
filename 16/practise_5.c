#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
const int kLength = 10;

void ChooseAndPrint(int array[], int length, int times);

int main(void) {
  int array[kLength] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  ChooseAndPrint(array, kLength, 10);;
  return 0;
}

void ChooseAndPrint(int array[], int length, int times) {
  int index = 0;
  int value;
  bool printed_values[kLength];
  while (index < length) 
    printed_values[index++] = false;

  srand((unsigned) time(0));
  while (times) {
    index = rand() % length;
    value = array[index];
    if (!printed_values[index]) {
      printf("Array[%d] is %d\n", index, array[index]);
      printed_values[index] = true;
      --times;
    }
  }
}

