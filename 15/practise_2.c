#include <stdio.h>
#include <math.h>
#include <string.h>

int BinStrToInt(const char *);
char *IntToBinStr(int, char *);
void ShowBinStr(const char *);


int main(int argc, char *argv[]) {
  char bin_str[8 * sizeof(int) + 1];
  int arg_1 = BinStrToInt(argv[1]);
  int arg_2 = BinStrToInt(argv[2]);
  int and = arg_1 & arg_2;
  int or = arg_1 | arg_2;
  int xor = arg_1 ^ arg_2;
  printf("%d & %d is ", arg_1, arg_2); 
  ShowBinStr(IntToBinStr(and, bin_str));

  printf("%d | %d is ", arg_1, arg_2);
  ShowBinStr(IntToBinStr(or, bin_str));

  printf("%d ^ %d is ", arg_1, arg_2);
  ShowBinStr(IntToBinStr(xor, bin_str));

  return 0;
}

int BinStrToInt(const char *p_bin) {
  int count = 0;
  int index = 0;
  int length = strlen(p_bin);
  while (length) 
    count += (p_bin[--length] - 48) * pow(2, index++);

  return count;
}

char *IntToBinStr(int n, char *ps) {
  static int size = 8 * sizeof(int);
  
  for (int i = size - 1; i >= 0; --i, n >>= 1) 
    ps[i] = (01 & n) + '0';
  
  ps[size] = '\0';

  return ps;
}

void ShowBinStr(const char *str) {
  int i = 0;
  while (str[i]) {
    putchar(str[i]);
    if(++i % 4 == 0 && str[i])
      putchar(' ');
  }
  putchar('\n');
}
