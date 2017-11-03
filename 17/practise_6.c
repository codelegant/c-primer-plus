#include <stdio.h>
#include <stdbool.h>
#define LENGTH 100

static bool BinarySearch(int arr[], int length, int target);
static bool RecursionSearch(int arr[], int start, int end, int target);

int main(int argc, char *argv[]) {
  int list[LENGTH];
  int index = 0;
  int target = atoi(argv[1]);
  while (index < LENGTH) {
    list[index] = index * 2;
    index++;
  }
  printf("The %d %s in array.\n", target, BinarySearch(list, LENGTH, target) ? "is" : "is not");
  return 0;
}

static bool BinarySearch(int arr[], int length, int target) {
  return RecursionSearch(arr, 0, length - 1, target);
}

static bool RecursionSearch(int arr[], int start, int end, int target) {
  int middle_index = (start + end) / 2;
  int middle_value = arr[middle_index];
  if(end - start ==1)
    return target == arr[end] || target == arr[start];

  if (target < middle_value) {
    return RecursionSearch(arr, start, middle_index, target);
  } else if (target > middle_value) {
    return RecursionSearch(arr, middle_index, end, target);
  } else if (target == middle_value) {
    return true;
  } 
}
