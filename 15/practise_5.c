#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

static int length = 8 * sizeof(int) + 1;

unsigned Rotate(unsigned number, int index);
unsigned BinStrToInt(const char *bin_str);
char *IntToBinStr(unsigned, char *bin_str);
void ShowBinStr(const char *bin_str);


int main(int argc, char *argv[]) {
  char bin_str[length];
  unsigned number = (unsigned)atoi(argv[1]);
  int index = atoi(argv[2]);

  IntToBinStr(number, bin_str);
  printf("Origin is %s\n", bin_str);

  number = Rotate(number, index);
  IntToBinStr(number, bin_str);
  printf("Result is %s\n", bin_str);

  return 0;
}

unsigned Rotate(unsigned number, int index) {
  char bin_str[length];
  char left_str[index+1];
  IntToBinStr(number, bin_str);
  strncpy(left_str, bin_str, index);
  left_str[index] = '\0';
  unsigned left_number = BinStrToInt(left_str);
  return (number << index) + left_number;
}

unsigned BinStrToInt(const char *bin_str) {
  unsigned count = 0;
  int index = 0;
  int length = strlen(bin_str);
  while (length) 
    count += (bin_str[--length] - 48) * pow(2, index++);

  return count;
}

char *IntToBinStr(unsigned n, char *bin_str) {
  static int size = 8 * sizeof(int);
  
  for (int i = size - 1; i >= 0; --i, n >>= 1) 
    bin_str[i] = (01 & n) + '0';
  
  bin_str[size] = '\0';

  return bin_str;
}

void ShowBinStr(const char *bin_str) {
  int i = 0;
  while (bin_str[i]) {
    putchar(bin_str[i]);
    if(++i % 4 == 0 && bin_str[i])
      putchar(' ');
  }
  putchar('\n');
}
